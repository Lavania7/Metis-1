/**
 * @file motor_obj.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-24
 * 
 * 
 */

/* C Standard Library Includes -----------------------------------*/

/* HAL Includes --------------------------------------------------*/

/* Private Includes ----------------------------------------------*/
#include "motor_obj.h"
/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Variables ----------------------------------------------*/

/* Objects ------------------------------------------------*/

/* =============================================================== */

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

/**
 * @brief 编码器更新（生成连续虚拟位置）
 * 
 * @param enc 编码器对象
 * @param new_value 本周期采样值（0 ~ mod-1）
 * @param mod 编码器周期（如 8192）
 */
void encoder_update(encoder_DeviceTypedef *enc, float new_value, float mod) {
    enc->curr = new_value;

    float delta = wrap_delta(enc->curr, enc->prev, mod);

    enc->pos += delta;
    enc->prev = enc->curr;
}

/* Test -----------------------------------------------------------*/
