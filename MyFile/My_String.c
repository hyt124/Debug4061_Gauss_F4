#include "My_String.h"
char a1[] = {"Now error:"};
char a2[] = {"Now distant:"};
uint8_t a3[] = {"FIRE!!!"};
uint8_t a4[] = {"Type  Horizontal Angle:"};
char a5[] = {"Horizontal angle is"};
uint8_t a6[] = {"Type Distant:"};
char a7[] = {"Pitch angle is"};
uint8_t a8[]={"Wrong angle,Type again"};
uint8_t a9[]={"Wrong distant,Type again"};
uint8_t a10[]={"(1):Push Shoot"};
uint8_t a11[]={"(2):Distant"};
uint8_t a12[]={"(3):Angle and Distant"};
uint8_t a13[]={"(4):Auto shoot"};
uint8_t a14[]={"(5):No Distant Auto Shoot"};
uint8_t a15[]={"(5):Debug mode"};
uint8_t a16[]={"Push key 1 to fire!"};
uint8_t a17[]={"Auto shoot begin"};
uint8_t a18[]={"Debug mode begin,type 16 quit"};
extern uint32_t Count;
extern int Coordinate1_One;
extern uint16_t Key_val;
int HorizontalAngle = 0;
int Distant = 0;
void ShowError()
{
    //Gui_DrawFont_GBK16(20,20,BLACK,WHITE,a1);
    LCD_OUTPUT_Float(20, 40, a1, 300 - Get_CoordinateXResult());
    //Gui_DrawFont_GBK16()
}
void ShowDistant()
{
    LCD_OUTPUT_Float(20, 60, a2, Get_CoordinateDistant());
}

void OpenFire()
{
    Lcd_Clear(WHITE);
    Gui_DrawFont_GBK16(50, 50, RED, WHITE, a3);
    GaussGun_Fire(5000);
    //OpenFire();
    HAL_Delay(2000);
}
void LCDShowRefresh()
{
	Gui_DrawFont_GBK16(5, 20, BLACK, WHITE, a10);
	Gui_DrawFont_GBK16(5, 40, BLACK, WHITE, a11);
	Gui_DrawFont_GBK16(5, 60, BLACK, WHITE, a12);
	Gui_DrawFont_GBK16(5, 80, BLACK, WHITE, a13);
	Gui_DrawFont_GBK16(5, 100, BLACK, WHITE, a14);
	Gui_DrawFont_GBK16(5, 120, BLACK, WHITE, a15);
//    ShowError();
//    ShowDistant();
//    if(Key_scan() == 13)
//    {
//        Lcd_Clear(WHITE);
//        OpenFire();
//        HAL_Delay(500);
//        Lcd_Clear(WHITE);
//    }
//    else if(Key_scan() == 16)
//    {
//        Lcd_Clear(WHITE);
//        LCDType();
//    }
	if(Key_scan() == 1)
	{
		Q1();
	}
	else if(Key_scan() == 2)
	{
		
		Q2();
	}
		else if(Key_scan() == 3)
	{
		Q3();
	}
		else if(Key_scan() == 4)
	{
		Q4();
	}
		else if(Key_scan() == 5)
	{
		Q5();
	}
}
void Q1()
{
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(5, 20, BLACK, WHITE, a16);
	while(Key_scan()!=1)
	{}
  Lcd_Clear(WHITE);
	OpenFire();
  HAL_Delay(500);
  Lcd_Clear(WHITE);
}
void Q2()
{
	  int temp1=0, temp2=0,temp3=0,temp4=0,temp5=0;
    uint16_t ctimh = 0, ctimp = 0;
	Lcd_Clear(WHITE);
	 Gui_DrawFont_GBK16(5, 20, BLACK, WHITE, a6);
	
	while(Key_scan() != 16)
	{
						if(ctimp == 0)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp3 = 1;
                ctimp++;
            }
            break;
            case 2:
            {
                temp3 = 2;
                ctimp++;
            }
            break;
            case 3:
            {
                temp3 = 3;
                ctimp++;
            }
            break;
            case 4:
            {
                temp3 = 4;
                ctimp++;
            }
            break;
            case 5:
            {
                temp3 = 5;
                ctimp++;
            }
            break;
            case 6:
            {
                temp3 = 6;
                ctimp++;
            }
            break;
            case 7:
            {
                temp3 = 7;
                ctimp++;
            }
            break;
            case 8:
            {
                temp3 = 8;
                ctimp++;
            }
            break;
            case 9:
            {
                temp3 = 9;
                ctimp++;
            }
            break;
            case 10:
            {
                temp3 = 0;
                ctimp++;
            }
            break;
            default:
                break;
            }
						HAL_Delay(200);
        }
        else if(ctimp == 1)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp4 = 1;
                ctimp++;
            }
            break;
            case 2:
            {
                temp4 = 2;
                ctimp++;
            }
            break;
            case 3:
            {
                temp4 = 3;
                ctimp++;
            }
            break;
            case 4:
            {
                temp4 = 4;
                ctimp++;
            }
            break;
            case 5:
            {
                temp4 = 5;
                ctimp++;
            }
            break;
            case 6:
            {
                temp4 = 6;
                ctimp++;
            }
            break;
            case 7:
            {
                temp4 = 7;
                ctimp++;
            }
            break;
            case 8:
            {
                temp4 = 8;
                ctimp++;
            }
            break;
            case 9:
            {
                temp4 = 9;
                ctimp++;
            }
            break;
            case 10:
            {
                temp4 = 0;
                ctimp++;
            }
            break;
            default:
                break;
            }
						HAL_Delay(200);
        }
				else if(ctimp == 2)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp5 = 1;
                ctimp++;
            }
            break;
            case 2:
            {
                temp5 = 2;
                ctimp++;
            }
            break;
            case 3:
            {
                temp5 = 3;
                ctimp++;
            }
            break;
            case 4:
            {
                temp5 = 4;
                ctimp++;
            }
            break;
            case 5:
            {
                temp5 = 5;
                ctimp++;
            }
            break;
            case 6:
            {
                temp5 = 6;
                ctimp++;
            }
            break;
            case 7:
            {
                temp5 = 7;
                ctimp++;
            }
            break;
            case 8:
            {
                temp5 = 8;
                ctimp++;
            }
            break;
            case 9:
            {
                temp5 = 9;
                ctimp++;
            }
            break;
            case 10:
            {
                temp5 = 0;
                ctimp++;
            }
            break;
            default:
                break;
            }
        }
        else if(ctimp == 3)
        {
            Distant = 100 * temp3 + 10*temp4+temp5;
            LCD_OUTPUT_Float(20, 110, a5, Distant );
				if(Distant>=200&&Distant<=300)
					{
						ctimp++;
					}
					else
					{
						Lcd_Clear(WHITE);
						Gui_DrawFont_GBK16(20, 40, BLACK, WHITE, a9);
						HAL_Delay(2000);
						ctimp=0;
						
					}
            //Gui_DrawFont_GBK16(20, 130, BLACK, WHITE, a6);
        }
				
	}
	Lcd_Clear(WHITE);
}
void Q3()
{
	LCDType();
}
void Q4()
{
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(5,20,BLACK,WHITE,a17);
	while(1);
}
void Q5()
{
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(5,20,BLACK,WHITE,a18);
	while(Key_scan()!=16)
	{
    ShowError();
    ShowDistant();
    if(Key_scan() == 1)
    {
        Lcd_Clear(WHITE);
        OpenFire();
        HAL_Delay(500);
        Lcd_Clear(WHITE);
    }
	}
}
void LCDType()
{
    int temp1=0, temp2=0,temp3=0,temp4=0,temp5=0;
    uint16_t ctimh = 0, ctimp = 0;
    Gui_DrawFont_GBK16(50, 50, BLACK, WHITE, a4);
    while(Key_scan() != 16)
    {
        if(ctimh == 0)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp1 = 1;
                ctimh++;
            }
            break;
            case 2:
            {
                temp1 = 2;
                ctimh++;
            }
            break;
            case 3:
            {
                temp1 = 3;
                ctimh++;
            }
            break;
            case 4:
            {
                temp1 = 4;
                ctimh++;
            }
            break;
            case 5:
            {
                temp1 = 5;
                ctimh++;
            }
            break;
            case 6:
            {
                temp1 = 6;
                ctimh++;
            }
            break;
            case 7:
            {
                temp1 = 7;
                ctimh++;
            }
            break;
            case 8:
            {
                temp1 = 8;
                ctimh++;
            }
            break;
            case 9:
            {
                temp1 = 9;
                ctimh++;
            }
            break;
            case 10:
            {
                temp1 = 0;
                ctimh++;
            }
            break;
            default:
                break;
            }
						HAL_Delay(200);
        }
        else if(ctimh == 1)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp2 = 1;
                ctimh++;
            }
            break;
            case 2:
            {
                temp2 = 2;
                ctimh++;
            }
            break;
            case 3:
            {
                temp2 = 3;
                ctimh++;
            }
            break;
            case 4:
            {
                temp2 = 4;
                ctimh++;
            }
            break;
            case 5:
            {
                temp2 = 5;
                ctimh++;
            }
            break;
            case 6:
            {
                temp2 = 6;
                ctimh++;
            }
            break;
            case 7:
            {
                temp2 = 7;
                ctimh++;
            }
            break;
            case 8:
            {
                temp2 = 8;
                ctimh++;
            }
            break;
            case 9:
            {
                temp2 = 9;
                ctimh++;
            }
            break;
            case 10:
            {
                temp2 = 0;
                ctimh++;
            }
            break;
            default:
                break;
            }
        }
        else if(ctimh == 2)
        {
            HorizontalAngle = 10 * temp1 + temp2;
            LCD_OUTPUT_Float(20, 70, a5, HorizontalAngle );
            Gui_DrawFont_GBK16(20, 90, BLACK, WHITE, a6);
					if(HorizontalAngle>=0&&HorizontalAngle<=60)
					{
						ctimh++;
					}
					else
					{
						Lcd_Clear(WHITE);
						Gui_DrawFont_GBK16(20, 20, BLACK, WHITE, a8);
						HAL_Delay(2000);
						ctimh=0;
						
					}
					
        }       
				else if(ctimh == 3)
				{
				if(ctimp == 0)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp3 = 1;
                ctimp++;
            }
            break;
            case 2:
            {
                temp3 = 2;
                ctimp++;
            }
            break;
            case 3:
            {
                temp3 = 3;
                ctimp++;
            }
            break;
            case 4:
            {
                temp3 = 4;
                ctimp++;
            }
            break;
            case 5:
            {
                temp3 = 5;
                ctimp++;
            }
            break;
            case 6:
            {
                temp3 = 6;
                ctimp++;
            }
            break;
            case 7:
            {
                temp3 = 7;
                ctimp++;
            }
            break;
            case 8:
            {
                temp3 = 8;
                ctimp++;
            }
            break;
            case 9:
            {
                temp3 = 9;
                ctimp++;
            }
            break;
            case 10:
            {
                temp3 = 0;
                ctimp++;
            }
            break;
            default:
                break;
            }
						HAL_Delay(200);
        }
        else if(ctimp == 1)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp4 = 1;
                ctimp++;
            }
            break;
            case 2:
            {
                temp4 = 2;
                ctimp++;
            }
            break;
            case 3:
            {
                temp4 = 3;
                ctimp++;
            }
            break;
            case 4:
            {
                temp4 = 4;
                ctimp++;
            }
            break;
            case 5:
            {
                temp4 = 5;
                ctimp++;
            }
            break;
            case 6:
            {
                temp4 = 6;
                ctimp++;
            }
            break;
            case 7:
            {
                temp4 = 7;
                ctimp++;
            }
            break;
            case 8:
            {
                temp4 = 8;
                ctimp++;
            }
            break;
            case 9:
            {
                temp4 = 9;
                ctimp++;
            }
            break;
            case 10:
            {
                temp4 = 0;
                ctimp++;
            }
            break;
            default:
                break;
            }
						HAL_Delay(200);
        }
				else if(ctimp == 2)
        {
            switch(Key_scan())
            {
            case 1:
            {
                temp5 = 1;
                ctimp++;
            }
            break;
            case 2:
            {
                temp5 = 2;
                ctimp++;
            }
            break;
            case 3:
            {
                temp5 = 3;
                ctimp++;
            }
            break;
            case 4:
            {
                temp5 = 4;
                ctimp++;
            }
            break;
            case 5:
            {
                temp5 = 5;
                ctimp++;
            }
            break;
            case 6:
            {
                temp5 = 6;
                ctimp++;
            }
            break;
            case 7:
            {
                temp5 = 7;
                ctimp++;
            }
            break;
            case 8:
            {
                temp5 = 8;
                ctimp++;
            }
            break;
            case 9:
            {
                temp5 = 9;
                ctimp++;
            }
            break;
            case 10:
            {
                temp5 = 0;
                ctimp++;
            }
            break;
            default:
                break;
            }
        }
        else if(ctimp == 3)
        {
            Distant = 100 * temp3 + 10*temp4+temp5;
            LCD_OUTPUT_Float(20, 110, a5, Distant );
				if(Distant>=200&&Distant<=300)
					{
						ctimp++;
					}
					else
					{
						Lcd_Clear(WHITE);
						Gui_DrawFont_GBK16(20, 40, BLACK, WHITE, a9);
						HAL_Delay(2000);
						ctimp=0;
						
					}
            //Gui_DrawFont_GBK16(20, 130, BLACK, WHITE, a6);
        }
			}
    }
		Lcd_Clear(WHITE);
}