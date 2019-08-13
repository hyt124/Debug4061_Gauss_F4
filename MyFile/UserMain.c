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
	LCD_Display_Dir(0);
	POINT_COLOR=BLACK;
	HAL_Delay(2000);
	LCD_DrawLine(0,13,240,13);
	LCD_DrawLine(0,310,240,310);
	LCD_ShowString(50,5,200,16,16,"<Beef Cake System>");
//	LCD_ShowString(30,70,200,16,16,"Dis:");
//  mode_init();
//	angle_set = 180;
//	HAL_UART_Transmit(&huart4,&angle_set,1,10);	
//	printf("\n");
//	HAL_Delay(2000);	
	while(1)
	{
//	sprintf(data, "%.3f", _GetDistantResults);
//  LCD_Clear(WHITE);
//	LCD_ShowString(90,270,200,16,16,data);
		Check();
	}
		
}