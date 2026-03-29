/**
 * @file math_utils.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-24
 * 
 * 
 */

#ifndef MATH_UTILS_H 
#define MATH_UTILS_H

/* =============================================================== */

/* C Standard Library Includes -----------------------------------*/
#include "math.h"
/* HAL Includes --------------------------------------------------*/
#include "main.h"
/* Private Includes ----------------------------------------------*/


#ifdef __cplusplus
extern "C"{
#endif

/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Enums --------------------------------------------------*/

/* sTypedefs ----------------------------------------------*/

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

float clamp(float x, float limit);
float wrap_delta(float x, float y, float mod);
/* Extern Varibles & Objects --------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif	/* MATH_UTILS_H */
