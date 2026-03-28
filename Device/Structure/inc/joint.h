/**
 * @file joint.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-28
 * 
 * 
 */

#ifndef JOINT_H 
#define JOINT_H

/* =============================================================== */

/* C Standard Library Includes -----------------------------------*/

/* HAL Includes --------------------------------------------------*/

/* Private Includes ----------------------------------------------*/
#include "motor_obj.h"

#ifdef __cplusplus
extern "C"{
#endif

/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Enums --------------------------------------------------*/

/* sTypedefs ----------------------------------------------*/

typedef struct __joint_deviceTypedef
{
    motor_DeviceTypedef mjoint;

}joint_deviceTypedef;

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

/* Extern Varibles & Objects --------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif	/* JOINT_H */
