#include "User_PWM.h"


/* 设置通道一的位置 */
void ChannelOne_SetPositon(float Position)
{
	float temp = 1500;
	
	if(Position > 5000)
	{
		Position = 5000;
	}

	if(Position < -5000)
	{
		Position = -5000;
	}	
	
	temp += Position *0.2;
	
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,(uint16_t)temp);
	
}
/* 设置通道二的位置 */
void ChannelTwo_SetPositon(float Position)
{
	float temp = 1500;
	
	if(Position > 5000)
	{
		Position = 5000;
	}

	if(Position < -5000)
	{
		Position = -5000;
	}	
	
	temp += Position *0.2;
  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,(uint16_t)temp);	
}

