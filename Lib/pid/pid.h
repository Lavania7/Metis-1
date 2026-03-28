/**
 * @file pid.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-24
 * 
 * 
 */

#ifndef PID_H 
#define PID_H

/* =============================================================== */

/* C Standard Library Includes -----------------------------------*/

/* HAL Includes --------------------------------------------------*/

/* Private Includes ----------------------------------------------*/


#ifdef __cplusplus
extern "C"{
#endif

/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Enums --------------------------------------------------*/

/* sTypedefs ----------------------------------------------*/
typedef struct __pid_AlgoTypeDef
{
	float kp;
	float ki;
	float kd;

	float freq;	// dt=1/freq,用于积分和微分运算

	float last_err;
	float this_err; // this_err-last_err 得到微分、积分项
	float integral;
	float integral_max;

	float output_max;
	float output;
// 	float last_output;
}pid_AlgoTypeDef;

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

void pid_init(pid_AlgoTypeDef *hpid, float kp, float ki, float kd, float freq, float integral_max, float output_max);
void pid_reset(pid_AlgoTypeDef *hpid);

void pid_calc(pid_AlgoTypeDef *hpid, float err);
float pid_output(pid_AlgoTypeDef *hpid);

float pid_step(pid_AlgoTypeDef *hpid, float err);

/* Extern Varibles & Objects --------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif	/* PID_H */
