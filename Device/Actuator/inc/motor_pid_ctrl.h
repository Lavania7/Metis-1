/**
 * @file motor_pid_ctrl.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-28
 * 
 * 
 */

#ifndef MOTOR_PID_CTRL_H 
#define MOTOR_PID_CTRL_H

/* =============================================================== */

/* C Standard Library Includes -----------------------------------*/

/* HAL Includes --------------------------------------------------*/

/* Private Includes ----------------------------------------------*/
#include "pid.h"

#ifdef __cplusplus
extern "C"{
#endif

/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Enums --------------------------------------------------*/

/* sTypedefs ----------------------------------------------*/

typedef struct pid_ctrlTypedef
{
    pid_AlgoTypeDef pid[4];
};

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

/* Extern Varibles & Objects --------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif	/* MOTOR_PID_CTRL_H */
