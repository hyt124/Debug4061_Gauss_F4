#include "User_Check.h"
#include "ILI93xx.h"
#include "KeyPad.h"
#include "GaussGun.h"
#include "MricroStepDriver.h"
#include "usart.h"

#include "tim.h"

extern const uint8_t Basic1Table[];
extern const uint8_t Basic2Table[];
extern const uint8_t Basic3Table[];
extern const uint8_t Advance1Table[];
extern const uint8_t Advance2Table[];
extern const uint8_t ModeSetTable[];
extern const uint8_t Basic1FireTable[];
extern const uint8_t Basic2PleaseInputTable[];
extern const uint8_t Basic2DistantDisplay[];
extern int stop_flag_FindCycleOnce; //FindCycleOnce

uint8_t dis[] = {""};
uint8_t ang[] = {""};
uint8_t rec_flag = 0;
uint8_t Distance = 0;
void DistantFire(uint16_t distant_cm);
void AutoDisFire(float dist);

void DealBasic1(void);
void DealBasic2(void);
void DealBasic3(void);

void DealAdvance1(void);
void DealAdvance2(void);

uint8_t DigitDialIn(void);

void Check(void)
{
	uint16_t KeyPressVal = 0;
	
	
	//LCD_WriteLine((uint8_t*)ModeSetTable,20,0,0);
	//有按键按下
	if(Key_scan() != 0x00)
	{
		//消抖
		HAL_Delay(100);
		if(Key_scan() != 0x00)
		{
			KeyPressVal = Key_scan();
			
			if(KeyPressVal == 1)
			{
				DealBasic1();
			}
			else if(KeyPressVal == 2)
			{
				DealBasic2();
			}
			else if(KeyPressVal == 3)
			{
				DealBasic3();
			}
			else if(KeyPressVal == 4)
			{
			  DealAdvance1();
			}
			else if(KeyPressVal == 5)
			{
				DealAdvance2();
			}
		}
	}
	
}


void DealBasic1(void)
{
	LCD_Clear(WHITE);
	HAL_Delay(10);
//	LCD_WriteLine((uint8_t*)Basic1Table,12,0,0);
//	LCD_WriteLine((uint8_t*)Basic1FireTable,21,1,0);
	while(Key_scan() != 0);	
	while(Key_scan() == 0);
	GaussGun_Fire(4900);//4350
	HAL_Delay(2000);
	LCD_Clear(WHITE);
}

void DealBasic2(void)
{
	volatile uint16_t Distant = 0; 
	
	LCD_Clear(WHITE);
	HAL_Delay(10);
//	LCD_WriteLine((uint8_t*)Basic2Table,15,0,0);
//	LCD_WriteLine((uint8_t*)Basic2PleaseInputTable,30,1,0);
	
	
	Distant += DigitDialIn() * 100;
	Distant += DigitDialIn() * 10;
	Distant += DigitDialIn();
	
//	LCD_WriteLine((uint8_t*)Basic2DistantDisplay,10,2,0);
	
	while(Key_scan() != 0);	
	while(Key_scan() == 0);
	sprintf(dis,"%d",Distant);
	LCD_ShowString(15, 25, 200, 16, 16, "Aim_dis: ");
	LCD_ShowString(90, 25, 200, 16, 16, dis);
	DistantFire(Distant);
	
	LCD_Clear(WHITE);
	HAL_Delay(2000);
	
	
}


void DealBasic3(void)
{
	volatile uint16_t Distant = 0;
	volatile int16_t Angle = 0;
	volatile uint8_t KeyVal_Pos_Or_Neg = 0;
	volatile uint8_t KeyVal = 0;
	LCD_Clear(WHITE);
	HAL_Delay(10);
//	LCD_WriteLine((uint8_t*)Basic3Table,23,0,0);
//	LCD_WriteLine((uint8_t*)Basic3InputAngleTable,20,1,0);
	
	Angle += DigitDialIn() * 100;
	Angle += DigitDialIn() * 10;
	Angle += DigitDialIn();
	
	while(Key_scan() != 0);
	while(Key_scan() == 0);	
	
	sprintf(ang,"%d",Angle);
	LCD_ShowString(15, 25, 200, 16, 16, "Aim_ang: ");
	LCD_ShowString(90, 25, 200, 16, 16, ang);

//	LCD_WriteLine((uint8_t*)Basic3InputDistantTable,22,2,0);
	Distant += DigitDialIn() * 100;
	Distant += DigitDialIn() * 10;
	Distant += DigitDialIn();
	
	while(Key_scan() != 0);	
	while(Key_scan() == 0);
	sprintf(dis,"%d",Distant);
	LCD_ShowString(15, 50, 200, 16, 16, "Aim_dis: ");
	LCD_ShowString(90, 50, 200, 16, 16, dis);
	stop =0;
	Locate_RunAngle(1,Angle,500);
	HAL_Delay(1000);
	DistantFire(Distant);
}


void DealAdvance1(void)
{
	LCD_Clear(WHITE);
	while(Key_scan() != 0);	
	while(Key_scan() == 0);
	
	LCD_ShowString(15, 50, 200, 16, 16, "Auto Shoot Once");
	while(stop_flag_FindCycleOnce == 0)
	{
		Locate_FindCycleOnce(1,800,100,330,340);
	}	
	
	HAL_Delay(500);
	if(rec_flag == 0)
	{
		Distance = _GetDistantResults * 100;
		rec_flag = 1;
	}
	AutoDisFire(Distance);	
}


void DealAdvance2(void)
{
	
}


uint8_t DigitDialIn(void)
{
	int16_t Digit = 0;
	
	while(Key_scan() != 0);
	while(Key_scan() == 0);
	
	Digit = Key_scan();
	
	if(Digit == 1)
	{
		HAL_Delay(500);
		return 1;
	}
	else if(Digit == 2)
	{
		HAL_Delay(500);
		return 2;
	}
	else if(Digit == 3)
	{
		HAL_Delay(500);
		return 3;
	}
	else if(Digit == 5)
	{
		HAL_Delay(500);
		return 4;
	}
	else if(Digit == 6)
	{
		HAL_Delay(500);
		return 5;
	}
	else if(Digit == 7)
	{
		HAL_Delay(500);
		return 6;
	}
	else if(Digit == 9)
	{
		HAL_Delay(500);
		return 7;
	}
	else if(Digit == 10)
	{
		HAL_Delay(500);
		return 8;
	}
	else if(Digit == 11)
	{
		HAL_Delay(500);
		return 9;
	}
	else if(Digit == 14)
	{
		HAL_Delay(500);
		return 0;
	}

	HAL_Delay(500);
	return 0;
	
}

void DistantFire(uint16_t distant_cm)
{
	volatile uint16_t Set_Angle = 0;
	
	if(distant_cm > 300)
	{
		distant_cm = 300;
	}
	if(distant_cm < 200)
	{
		distant_cm = 200;
	}
	
	Set_Angle = (uint16_t)(0.6644*distant_cm - 68.487);
	HAL_UART_Transmit(&huart4,&Set_Angle,1,10);	
	printf("\n");
	HAL_Delay(2000);	
	GaussGun_Fire(4900);
	
}

void AutoDisFire(float dist)
{
	volatile uint8_t Set_Angle = 0;
	
	if(dist > 300)
	{
		dist = 300;
	}
	if(dist < 200)
	{
		dist = 200;
	}
	
	Set_Angle = (uint8_t)(0.6644*dist - 68.487);
	HAL_UART_Transmit(&huart4,&Set_Angle,1,10);	
	printf("\n");
	HAL_Delay(2000);	
	GaussGun_Fire(4900);
	
}

