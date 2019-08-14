#include "Timer.h"

int PWM_Count = 0;
extern int PWM_Count_Set;
int stop = 0;
int flag_dir = 0;
//uint8_t a[] = {"distance"};
//uint8_t x[] = {"x val"};
//uint8_t y[] = {"y val"};
//uint16_t xval;
//uint16_t yval;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if( htim == (&htim2) )
  {
    PWM_Count++;
		if(PWM_Count  == PWM_Count_Set && PWM_Count != 0 && PWM_Count_Set != 0 )
		{
			HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);

			flag = 0;
			stop = 1;
			
			if(flag_dir == 1)
				flag_dir = 0;
			else
				flag_dir = 1;
			
			PWM_Count = 0;
			HAL_TIM_Base_Stop_IT(&htim2);
		}
  }
}

