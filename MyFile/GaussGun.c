#include "GaussGun.h"
#include "tim.h"
#include "main.h"

void GaussGun_Fire(uint16_t FireTime_us)
{
	//停止定时器5 并重新启动定时器5
	HAL_TIM_Base_Stop(&htim5);
	HAL_TIM_Base_Init(&htim5);
	HAL_TIM_Base_Start(&htim5);
	
	//非法输入将导致函数直接返回
	if(FireTime_us > 50000)
	{
		return;
	}
	
	//清空定时器5计数值 设置开火引脚为低电平以开火
	htim5.Instance->CNT = 0;
	HAL_GPIO_WritePin(FIRE_GPIO_Port,FIRE_Pin,GPIO_PIN_RESET);
	while(htim5.Instance->CNT < FireTime_us)
	{
	}
	
	HAL_GPIO_WritePin(FIRE_GPIO_Port,FIRE_Pin,GPIO_PIN_SET);
}
