#include "UserMain.h"

uint16_t KEY = 0;
uint16_t Cur_mode = 0;
uint16_t modeflag = 0;
extern int stop;
extern float  _GetDistantResults;
extern int16_t Coordinate1_One;
//extern int16_t Coordinate1_Two;
//uint8_t a[] = {"distance"};
//uint8_t x[] = {"x val"};
//uint8_t y[] = {"y val"};
//uint16_t xval;
//uint16_t yval;
uint8_t data[]={};
uint8_t angle_set = 00;
void User_Main(void)
{
	User_GetErrorUart_Init();
	User_DebugUart_Init();
	User_DistantUart_Init();
	TFTLCD_Init();
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
//	HAL_TIM_Base_Start_IT(&htim3);
//	UpdateMotorState(MOTOR_FRONT);
	LCD_Display_Dir(0);
	POINT_COLOR=BLACK;
	HAL_Delay(2000);
//	LCD_DrawLine(0,13,240,13);
//	LCD_DrawLine(0,310,240,310);
//	LCD_ShowString(50,5,200,16,16,"<Beef Cake System>");
//	LCD_ShowString(30,70,200,16,16,"Dis:");
	//mode_init();
//	angle_set = 180;
//	HAL_UART_Transmit(&huart4,&angle_set,1,10);	
//	printf("\n");
//	HAL_Delay(2000);	
	while(1)
	{
//		sprintf(data, "%.3f", _GetDistantResults);
//			//LCD_Clear(WHITE);
//		LCD_ShowString(90,270,200,16,16,data);
//Locate_FindCycleOnce(1,800,100,340,350);	
		Check();
//		
////angle_set = 90;
////HAL_UART_Transmit(&huart4,&angle_set,1,10);
//////HAL_Delay(2000);
////printf("\n");
////HAL_Delay(2000);	
////		KEY = Key_scan();
////    if(KEY == 16 )
////		{
////		GaussGun_Fire(5000);
////		HAL_Delay(2000);
////		}
//////	}
//		
////		stop = 0;
////		Locate_RunAngle(1,90,500);
////		HAL_Delay(3000);
////		stop = 0;
////		Locate_RunAngle(0,90,500);
////		HAL_Delay(3000);

////		stop = 0;
////		Locate_RunStep(1,940,500);
////		HAL_Delay(3000);
////		stop = 0;
////		Locate_RunStep(0,800,100);
////		HAL_Delay(3000);


//    if (modeflag == 0)
//		{
//			if(Key_scan() == 10)
//			{
//				lcd_flag = 0;
//				LCD_Clear(WHITE);
//				Cur_mode = 10; modeflag = 1;
//			}
//		}
//		
//		if(Cur_mode == 0)
//		{
//			mode_display();
//		}
//		else if(Cur_mode == 10)
//		{
//			mode1();
//		}
//		
////		
////		if (modeflag == 0)
////		{
////			if(Key_scan() == 10)
////			{
////				lcd_flag = 0;
////				LCD_Clear(WHITE);
////				Cur_mode = 10; modeflag = 1;
////			}
////			else if(Key_scan() == 11)
////			{
////				LCD_Clear(WHITE);
////				lcd_flag = 0;
////				Cur_mode =11; modeflag = 1;
////			}
////			else if(Key_scan() == 12)
////			{
////				lcd_flag = 0;
////				LCD_Clear(WHITE);
////				Cur_mode =12; modeflag = 1;
////			}
////			else if(Key_scan() == 13)
////			{
////				lcd_flag = 0;
////				LCD_Clear(WHITE);
////				Cur_mode =13; modeflag = 1;
////			}
////			else if(Key_scan() == 14)
////			{
////				lcd_flag = 0;
////				LCD_Clear(WHITE);
////				Cur_mode =14; modeflag = 1;
////			}
////		}
//		
//		if(Cur_mode == 0)
//		{
//			mode_display();
//		}
//		else if(Cur_mode == 10)
//		{
//			mode1();
//		}
//		else if(Cur_mode == 11)
//		{
//			mode2();
//		}
//		else if(Cur_mode == 12)
//		{
//			mode3();
//		}
//		else if(Cur_mode == 13)
//		{
//			mode4();
//		}
//		else if(Cur_mode == 14)
//		{
//			mode5();
//		}		
	
	}
		
}