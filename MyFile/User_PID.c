#include "User_PID.h"
#include "math.h"
static uint16_t x = 0; //74
static uint16_t y = 300; //64
float sx = 0, sy = 0;;
float PID_valueX=0;
float previous_errorX, previous_errorY,LastOut,diff;
int value =0;
int i=0;
int GetErrorX(void)
{
    return  Get_CoordinateXResult()-x;
}
void PIDOut(void)
{
    float KpX =1.9, KiX = 0.002, KdX = 0.01;
    float errorX = 0, errorY = 0, PX = 0, IX = 0., DX = 0;
    errorX = GetErrorX();
    PX = errorX;
    IX = IX + errorX;
    DX = errorX - previous_errorX;
    PID_valueX = (KpX * PX) + (KiX * IX) + (KdX * DX);

    previous_errorX = errorX;
//		if(PID_valueX>1000)
//			PID_valueX=1000;
//				if(PID_valueX<=-1000)
//			PID_valueX=-1000;
    //printf("X=%f\n",errorX);
		LastOut=PID_valueX;
		diff=PID_valueX-LastOut;
				
//	printf("x=%d,y=%d\n",Get_CoordinateXResult(),Get_CoordinateYResult());
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,LastOut+diff);
        //ChannelOne_SetPositon(LastOut+diff);
printf("X=%f\n",LastOut+diff);
//    ChannelOne_SetPositon(0);
//    ChannelTwo_SetPositon(0);


}
void turn(void)
{
	value=Get_CoordinateXResult();
	//printf("%d\n",value);
	if(value < 290||value>310)
	{
		for(i = 0;i < 1600;i++)
	{
		ChannelOne_SetPositon(i);
		HAL_Delay(1);
	}
	}
	else
	{
		ChannelOne_SetPositon(i);
	}
}

