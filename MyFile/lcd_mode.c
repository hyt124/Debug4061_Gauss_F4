#include "lcd_mode.h"
#include "KeyPad.h"
#include "GaussGun.h"

uint8_t distance[] = {""};
uint32_t aim = 0;
uint8_t angle[] = {""};
uint32_t aim_ang = 0;                      //1: zheng  2 : fu
uint16_t lcd_flag = 0;
uint16_t dis_flag = 0;
uint16_t ang_flag = 0;
uint16_t cnt = 0; 

void mode_init(void)
{
	LCD_Display_Dir(0);
	POINT_COLOR=BLACK; 
	LCD_Clear(WHITE);
}

void mode_display(void)
{
	//LCD_DrawLine(0,13,240,13);
	LCD_DrawLine(0,310,240,310);
	LCD_ShowString(50,5,200,16,16,"<Beef Cake System>");
	LCD_ShowString(15,270,200,16,16,"Cur_dis:");
	
	LCD_ShowString(15, 25, 200, 16, 16, "1: shoot");
	LCD_ShowString(15, 43, 200, 16, 16, "2: distance");
	LCD_ShowString(15, 61, 200, 16, 16, "3: ang & dis");
	LCD_ShowString(15, 79, 200, 16, 16, "4: ser & shoot");
	LCD_ShowString(15, 97, 200, 16, 16, "5: auto-shoot");
	lcd_flag = 1;
}

void mode1(void)
{
	LCD_ShowString(15,270,200,16,16,"Cur_dis:");
	LCD_ShowString(15, 100, 200, 16, 16, "fire");
	GaussGun_Fire(5000);
	HAL_Delay(2000);
	lcd_flag = 1;
}

void mode2(void)
{
	sprintf(distance, "%d",aim);
	
	if(lcd_flag == 0)
	{
		LCD_Clear(WHITE);
		LCD_ShowString(15,270,200,16,16,"Cur_dis:");
		LCD_ShowString(15, 25, 200, 16, 16, "Aim_dis: ");
		LCD_ShowString(90, 25, 200, 16, 16, distance);
		lcd_flag = 1;
	}
	else
	{
		if(Key_scan() < 10)
		{
			if (aim == 0)
			{
				aim = 100 * (Key_scan());
				dis_flag = 1;
				lcd_flag = 0;
			}
			else if (dis_flag == 1)
			{
				aim = aim + (Key_scan()) * 10;
				dis_flag = 2;
				lcd_flag = 0;
			}
			else if (dis_flag == 2)
			{
				aim	= aim + Key_scan();
				dis_flag = 3;
				lcd_flag = 0;
			}
		}
	}
	
	if(dis_flag == 3 && Key_scan() == 15)
	{
		LCD_Clear(WHITE);
		LCD_ShowString(15, 100, 200, 16, 16, "fire");
	}
}

void mode3(void)
{
	sprintf(distance, "%d",aim);
	sprintf(angle, "%d",aim_ang);
	
	if(lcd_flag == 0)
	{
		LCD_Clear(WHITE);
		LCD_ShowString(15, 25, 200, 16, 16, "Aim_dis: ");
		LCD_ShowString(90, 25, 200, 16, 16, distance);
		LCD_ShowString(15, 43, 200, 16, 16, "Aim_ang: ");
		LCD_ShowString(90, 43, 200, 16, 16, angle);
		lcd_flag = 1;
	}
	else
	{
		if(Key_scan() < 10)
		{
			if (aim == 0)
			{
				aim = 100 * (Key_scan());
				dis_flag = 1;
				lcd_flag = 0;
				
			}
			else if (dis_flag == 1)
			{
				aim = aim + (Key_scan()) * 10;
				dis_flag = 2;
				lcd_flag = 0;
			}
			else if (dis_flag == 2)
			{
				aim	= aim + Key_scan();
				dis_flag = 3;
				lcd_flag = 0;
			}
			else if(dis_flag == 3)
			{
				aim_ang = 10 * (Key_scan());
				ang_flag = 1;
				lcd_flag = 0;
			}
			else if(ang_flag == 1)
			{
				aim_ang	= aim_ang + Key_scan();
				ang_flag = 2;
				lcd_flag = 0;
			}			
		}
	}
	
	if(ang_flag == 2 && Key_scan() == 15)
	{
		LCD_Clear(WHITE);
		LCD_ShowString(15, 100, 200, 16, 16, "fire");
	}
} 

void mode4(void)
{
	LCD_ShowString(15,270,200,16,16,"Cur_dis:");
	LCD_ShowString(15, 100, 200, 16, 16, "fire");
	lcd_flag = 1;
}
void mode5(void)
{
	LCD_ShowString(15,270,200,16,16,"Cur_dis:");
	LCD_ShowString(15, 100, 200, 16, 16, "fire");
	lcd_flag = 1;
}

