/**
 * @file pid.c
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
#include "pid.h"
#include "math_utils.h"
/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Variables ----------------------------------------------*/

/* Objects ------------------------------------------------*/

/* =============================================================== */

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

void pid_init(pid_AlgoTypeDef *hpid, float kp, float ki, float kd, float freq, float integral_max, float output_max) {
    hpid->kp = kp;
    hpid->ki = ki;
    hpid->kd = kd;
    hpid->freq = freq;

    hpid->integral_max = integral_max;
    hpid->output_max = output_max;
}

void pid_calc(pid_AlgoTypeDef *hpid, float err) {
    float P,D = 0;

    hpid->this_err = err;

    P = hpid->kp * hpid->this_err;
    D = hpid->kd * (hpid->this_err - hpid->last_err) * hpid->freq;
    hpid->integral +=hpid->ki * hpid->this_err;
    hpid->integral = clamp(hpid->integral, hpid->integral_max);

    hpid->last_err = hpid->this_err;

    float sum = 0;
    sum = P + hpid->integral + D;
    hpid->output = clamp(sum, hpid->output_max);
}

void pid_reset(pid_AlgoTypeDef *hpid) {
    hpid->last_err = 0;
    hpid->this_err = 0;
    hpid->integral = 0;
    hpid->output = 0;
}

float pid_output(pid_AlgoTypeDef *hpid) {
    return hpid->output;
}

float pid_step(pid_AlgoTypeDef *hpid, float err) {
    float P, D;

    hpid->this_err = err;

    P = hpid->kp * hpid->this_err;
    D = hpid->kd * (hpid->this_err - hpid->last_err) * hpid->freq;

    hpid->integral += hpid->ki * hpid->this_err;
    hpid->integral = clamp(hpid->integral, hpid->integral_max);

    hpid->last_err = hpid->this_err;

    float sum = P + hpid->integral + D;
    hpid->output = clamp(sum, hpid->output_max);

    return hpid->output;
}

/* Test -----------------------------------------------------------*/
