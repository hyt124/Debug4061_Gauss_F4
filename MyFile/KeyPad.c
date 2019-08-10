#include "keypad.h"
// = 100; 
uint16_t Key_scan(void)
{
	uint16_t Key_val = 0;          
	                                
	uint16_t temp;
    

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET); 
	
	/*----------------------------Scan the 1st ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_SET);  
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(10);  
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{                                                                       
			temp = (GPIOC->IDR & 0xF7);                                 
			switch(temp)                                                       
			{
				case 0xE7 : Key_val = 1;
				break;

				case 0xD7 : Key_val = 2;
				break;

				case 0xB7 : Key_val = 3;
				break;

				case 0x77 : Key_val = 4;
				break;

				default  : Key_val =0; break;

			}
		}
    }
	
	
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
	/*----------------------------Scan the 2nd ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3, GPIO_PIN_SET);   
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(10);   // 10ms
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{
			temp = (GPIOC->IDR & 0xFB);
			switch(temp)
			{
				case 0xEB : Key_val = 5;
				break;

				case 0xDB : Key_val = 6;
				break;

				case 0xBB : Key_val = 7;
				break;

				case 0x7B : Key_val = 8;
				break;

				default  : Key_val = 0; break;

			}
		}
    }
	
	
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
	/*----------------------------Scan the 3rd ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);   
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(10);   // 10ms????
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{
			temp = (GPIOC->IDR & 0xFD);
			switch(temp)
			{
				case 0xED : Key_val = 9;
				break;

				case 0xDD : Key_val = 10;
				break;

				case 0xBD : Key_val = 11;
				break;

				case 0x7D : Key_val = 12;
				break;

				default   : Key_val = 0; break;

			}
		}
    }
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
	/*----------------------------Scan the 4th ROW----------------------------*/
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);   
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);                       
	
    if((GPIOC->IDR & 0xF0) != 0xF0)
    {
		HAL_Delay(10);   // 10ms????
		if((GPIOC->IDR & 0xF0) != 0xF0)
		{
			temp = (GPIOC->IDR & 0xFE);
			switch(temp)
			{
				case 0xEE : Key_val = 13;
				break;

				case 0xDE : Key_val = 14;
				break;

				case 0xBE : Key_val = 15;
				break;

				case 0X7E : Key_val = 16;
				break;

				default  : Key_val = 0; break;

			}
		}
    }
	
	return Key_val;
}