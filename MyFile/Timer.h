#ifndef Timer_H
#define Timer_H

#include "gpio.h"
#include "stm32f4xx_hal.h"
#include "MricroStepDriver.h"
#include "tim.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif