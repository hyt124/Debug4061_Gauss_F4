#include "keypad.h"
#include "ILI93xx.h"
#include "stdint.h"
#include "stm32f4xx_hal.h"

uint16_t Key_scan(void)
{
	uint16_t Key_val = 16;          
	                                
	uint16_t temp;
    

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET); 
	
	/*----------------------------Scan the 1st ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_SET);  
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(50);  
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{                                                                       
			temp = (GPIOC->IDR & 0xF7);                                 
			switch(temp)                                                       
			{
				case 0xE7 : Key_val = 0;
				break;

				case 0xD7 : Key_val = 1;
				break;

				case 0xB7 : Key_val = 2;
				break;

				case 0x77 : Key_val = 3;
				break;

				default  : Key_val = 16; break;

			}
		}
    }
	
	
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
	/*----------------------------Scan the 2nd ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3, GPIO_PIN_SET);   
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(50);   // 10ms
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{
			temp = (GPIOC->IDR & 0xFB);
			switch(temp)
			{
				case 0xEB : Key_val = 4;
				break;

				case 0xDB : Key_val = 5;
				break;

				case 0xBB : Key_val = 6;
				break;

				case 0x7B : Key_val = 7;
				break;

				default  : Key_val = 16; break;

			}
		}
    }
	
	
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
	/*----------------------------Scan the 3rd ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);   
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(50);   // 10ms????
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{
			temp = (GPIOC->IDR & 0xFD);
			switch(temp)
			{
				case 0xED : Key_val = 8;
				break;

				case 0xDD : Key_val = 9;
				break;

				case 0xBD : Key_val = 10;
				break;

				case 0x7D : Key_val = 11;
				break;

				default   : Key_val = 16; break;

			}
		}
    }
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
	/*----------------------------Scan the 4th ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);   
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(50);   // 10ms????
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{
			temp = (GPIOC->IDR & 0xFE);
			switch(temp)
			{
				case 0xEE : Key_val = 12;
				break;

				case 0xDE : Key_val = 13;
				break;

				case 0xBE : Key_val = 14;
				break;

				case 0X7E : Key_val = 15;
				break;

				default  : Key_val = 18; break;

			}
		}
    }
	
	return Key_val;
}

void KeyShow_LCD(void)
{
	if(Key_scan() == 1)
	{
		LCD_ShowString(15,290,200,16,16,"key_0");
	}
	else if(Key_scan() == 2)
	{
		LCD_ShowString(15,290,200,16,16,"key_1");
	}
		else if(Key_scan() == 3)
	{
		LCD_ShowString(15,290,200,16,16,"key_2");
	}
		else if(Key_scan() == 4)
	{
		LCD_ShowString(15,290,200,16,16,"key_3");
	}
		else if(Key_scan() == 5)
	{
		LCD_ShowString(15,290,200,16,16,"key_4");
	}
		else if(Key_scan() == 6)
	{
		LCD_ShowString(15,290,200,16,16,"key_5");
	}
		else if(Key_scan() == 7)
	{
		LCD_ShowString(15,290,200,16,16,"key_6");
	}
		else if(Key_scan() == 8)
	{
		LCD_ShowString(15,290,200,16,16,"key_7");
	}
		else if(Key_scan() == 9)
	{
		LCD_ShowString(15,290,200,16,16,"key_8");
	}
		else if(Key_scan() == 10)
	{
		LCD_ShowString(15,290,200,16,16,"key_9");
	}
		else if(Key_scan() == 11)
	{
		LCD_ShowString(15,290,200,16,16,"key_A");
	}
		else if(Key_scan() == 12)
	{
		LCD_ShowString(15,290,200,16,16,"key_B");
	}
		else if(Key_scan() == 13)
	{
		LCD_ShowString(15,290,200,16,16,"key_C");
	}
		else if(Key_scan() == 14)
	{
		LCD_ShowString(15,290,200,16,16,"key_D");
	}
		else if(Key_scan() == 15)
	{
		LCD_ShowString(15,290,200,16,16,"key_E");
	}
		else if(Key_scan() == 16)
	{
		LCD_ShowString(15,290,200,16,16,"key_F");
	}
}
