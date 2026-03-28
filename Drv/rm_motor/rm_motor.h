/**
  ******************************************************************************
  * @file    rm_motor.h
  * @author  Jingqiao
  * @brief   Header file of RM motor driver.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 BNGU.
  * All rights reserved.
  *
	******************************************************************************
  */
#ifndef __RM_MOTOR_H__
#define __RM_MOTOR_H__

/* Includes ------------------------------------------------------------------*/
#include "main.h"
typedef struct __rm_motor_dataTypeDef
{
  uint16_t angle;
	int16_t speed;
	int16_t current;
	uint8_t temperature;
}rm_motor_dataTypeDef;

typedef struct __rm_motor_groupTypeDef
{
	uint16_t group_id;// ESC receive id
	CAN_HandleTypeDef *hcan;// The hcan used
	int16_t cmd[4];
	int16_t cmd_max[4];
	rm_motor_dataTypeDef motor_data[4];
}rm_motor_groupTypeDef;

void rm_motor_init(rm_motor_groupTypeDef* hrm_motor_group, uint16_t group_id,	CAN_HandleTypeDef *hcan);
void rm_motor_cmd_max_config(rm_motor_groupTypeDef* hrm_motor_group, int16_t cmd_1, uint16_t cmd_2, int16_t cmd_3, uint16_t cmd_4);
void rm_motor_cmd_refresh(rm_motor_groupTypeDef* hrm_motor_group, float cmd_1, float cmd_2, float cmd_3, float cmd_4);
uint8_t rm_motor_send_msg(rm_motor_groupTypeDef* hrm_motor_group);
void rm_motor_receive_msg(rm_motor_groupTypeDef* rm_motor_group, CAN_RxHeaderTypeDef* rx_header, uint8_t* data);


#endif
