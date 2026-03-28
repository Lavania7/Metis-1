#include "can.h"
#include "bsp_can.h"
#include "rm_motor.h"


void bsp_can_init(void)
{
    static CAN_FilterTypeDef filter;
	filter.FilterBank=1;
	filter.FilterMode=CAN_FILTERMODE_IDMASK;
	filter.FilterScale=CAN_FILTERSCALE_16BIT;
	filter.FilterIdHigh=0x0000;
	filter.FilterIdLow=0x0000;
	filter.FilterMaskIdHigh=0x00;//0xFC00;
	filter.FilterMaskIdLow=0x00;//0xFFFF;
	filter.FilterFIFOAssignment=CAN_FILTER_FIFO0;
	filter.FilterActivation=ENABLE;
	
	HAL_CAN_ConfigFilter(&hcan1, &filter);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
	HAL_CAN_Start(&hcan1);

	filter.FilterBank=14;
	filter.FilterMode=CAN_FILTERMODE_IDMASK;
	filter.FilterScale=CAN_FILTERSCALE_16BIT;
	filter.FilterIdHigh=0x0000;
	filter.FilterIdLow=0x0000;
	filter.FilterMaskIdHigh=0x00;   //0xFC00;
	filter.FilterMaskIdLow=0x00;    //0xFFFF;
	filter.FilterFIFOAssignment=CAN_FILTER_FIFO0;
	filter.FilterActivation=ENABLE;
	
	HAL_CAN_ConfigFilter(&hcan2, &filter);
	HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);
	HAL_CAN_Start(&hcan2);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	uint8_t data[8] = {0};
	CAN_RxHeaderTypeDef rx_header;
	if(hcan == &hcan1)
	{
	    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, data);
        /* rm_motor_receive_msg() */
		/* code */
	}
	if(hcan == &hcan2)
	{
	    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, data);
		/* code */
	}
}


