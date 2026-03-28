#include "tim.h"
#include "bsp_tim.h"


void bsp_tim_init() {
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start_IT(&htim4);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    
}
