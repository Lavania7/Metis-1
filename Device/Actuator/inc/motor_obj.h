/**
 * @file motor_obj.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-24
 * 
 * 
 */

#ifndef MOTOR_OBJ_H 
#define MOTOR_OBJ_H

/* =============================================================== */

/* C Standard Library Includes -----------------------------------*/

/* HAL Includes --------------------------------------------------*/
#include "main.h"
/* Private Includes ----------------------------------------------*/
#include "rm_motor.h"
#include "math_utils.h"

#ifdef __cplusplus
extern "C"{
#endif

/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Enums --------------------------------------------------*/

/* sTypedefs ----------------------------------------------*/

typedef struct __encoder_DeviceTypedef
{
    float curr; // 当前原始编码器值（0 ~ mod-1）
    float prev; // 上一周期值
    float position; // 展开后的连续位置
}encoder_DeviceTypedef;


typedef struct __motor_DeviceTypedef
{
    CAN_HandleTypeDef *hcan;
    float stdid;

    float spd[4];
    float pos[4];
    float temperature[4];
    float current[4];
    float tor[4];

}motor_DeviceTypedef;

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

void dji_motor_update_device(rm_motor_groupTypeDef* hrm, motor_DeviceTypedef* hdev);
void dji_motor_apply_cmd(rm_motor_groupTypeDef* hrm, motor_DeviceTypedef* hdev);
void dji_motor_send_cmd(rm_motor_groupTypeDef* hrm, motor_DeviceTypedef* hdev);

void dm_motor_update_device();
void dm_motor_apply_cmd();
void dm_motor_send_cmd();

void utree_motor_update_device();
void utree_motor_apply_cmd();
void utree_motor_send_cmd();

// void custom_motor_update_device();
// void custom_motor_apply_cmd();
// void custom_motor_send_cmd();

void encoder_update(encoder_DeviceTypedef *enc, float new_value, float mod);

/* Extern Varibles & Objects --------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif	/* MOTOR_OBJ_H */
