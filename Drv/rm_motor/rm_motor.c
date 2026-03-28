 /**
  ******************************************************************************
  * @file    rm_motor.c
  * @author  Jingqiao
  * @brief   RM motor driver.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 BNGU.
  * All rights reserved.
  *
	******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rm_motor.h"
#include "can.h"
#include "string.h"

void rm_motor_init(rm_motor_groupTypeDef* hrm_motor_group, uint16_t group_id,	CAN_HandleTypeDef *hcan)
{
	hrm_motor_group->group_id = group_id;
	hrm_motor_group->hcan = hcan;
}

void rm_motor_cmd_max_config(rm_motor_groupTypeDef* hrm_motor_group, int16_t cmd_1, uint16_t cmd_2, int16_t cmd_3, uint16_t cmd_4)
{
	hrm_motor_group->cmd_max[0] = cmd_1;
	hrm_motor_group->cmd_max[1] = cmd_2;
	hrm_motor_group->cmd_max[2] = cmd_3;
	hrm_motor_group->cmd_max[3] = cmd_4;
}

void rm_motor_cmd_refresh(rm_motor_groupTypeDef* hrm_motor_group, float cmd_1, float cmd_2, float cmd_3, float cmd_4)
{
	float cmd_data[4] = {cmd_1, cmd_2, cmd_3, cmd_4};
	for(int i = 0; i < 4; i++)
	{
		if(cmd_data[i] > (float)hrm_motor_group->cmd_max[i])
			cmd_data[i] = hrm_motor_group->cmd_max[i];
		else if(cmd_data[i] < - (float)hrm_motor_group->cmd_max[i])
			cmd_data[i] = - hrm_motor_group->cmd_max[i];
		hrm_motor_group->cmd[i] = cmd_data[i];
	}
}

uint8_t rm_motor_send_msg(rm_motor_groupTypeDef* hrm_motor_group)
{
	uint8_t mode = 1;
	uint8_t data[8] = {0};
	data[0] = hrm_motor_group->cmd[0] >> 8;
	data[1] = hrm_motor_group->cmd[0];
	data[2] = hrm_motor_group->cmd[1] >> 8;
	data[3] = hrm_motor_group->cmd[1];
	data[4] = hrm_motor_group->cmd[2] >> 8;
	data[5] = hrm_motor_group->cmd[2];
	data[6] = hrm_motor_group->cmd[3] >> 8;
	data[7] = hrm_motor_group->cmd[3];
	
	uint32_t CAN_TX_BOX0;
	CAN_TxHeaderTypeDef tx_header;
	tx_header.StdId = hrm_motor_group->group_id;
	tx_header.IDE = CAN_ID_STD;
	tx_header.RTR = CAN_RTR_DATA;
	tx_header.DLC = 8;
	tx_header.TransmitGlobalTime = DISABLE;
	mode = HAL_CAN_AddTxMessage(hrm_motor_group -> hcan, &tx_header, data, &CAN_TX_BOX0);

	return mode;

}

void rm_motor_receive_msg(rm_motor_groupTypeDef* rm_motor_group, CAN_RxHeaderTypeDef* rx_header, uint8_t* data)
{
	uint8_t motor_index = 0;
	if(rm_motor_group->group_id == 0x200)
		motor_index = rx_header->StdId - 0x201;
	else if(rm_motor_group->group_id == 0x1ff || rm_motor_group->group_id == 0x1fe)
		motor_index = rx_header->StdId - 0x205;
	else if(rm_motor_group->group_id == 0x2ff || rm_motor_group->group_id == 0x2fe)
		motor_index = rx_header->StdId - 0x209;
	rm_motor_group->motor_data[motor_index].angle = (data[0] << 8) | data[1];
	rm_motor_group->motor_data[motor_index].speed = (data[2] << 8) | data[3];
	rm_motor_group->motor_data[motor_index].current = (data[4] << 8) | data[5];
	rm_motor_group->motor_data[motor_index].temperature = data[6];
}
