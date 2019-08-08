#ifndef STEP_HH
#define STEP_HH
#include "sys.h"
#include "stdlib.h"	
#include <stdio.h>
#include "tim.h"
#include "Timer.h"
#include "gpio.h"
/********** 驱动器 端口定义 **************
//DRIVER_DIR   PE0 
//DRIVER_OE    PE1 
//STEP_PULSE   PA5
(TIM2_CH2,LCD_RW)
******************************************/
#define DRIVER_DIR   PCout(0) // 旋转方向 
#define DRIVER_OE    PCout(2) // 使能脚 低电平有效
#define RCR_VAL    255  //每计数（RCR_VAL+1）次，中断一次，这个值（0~255）设置大一些可以降低中断频率

typedef enum
{
	CW = 1,//高电平顺时针
	CCW = 0,//低电平逆时针
}DIR_Type;//运行方向

extern long target_pos;//有符号方向
extern long current_pos;//有符号方向
extern int PWM_Count_Set;
extern int flag;
extern int stop;

void Driver_Init(void);//驱动器初始化
void TIM2_OPM_RCR_Init(u16 arr,u16 psc);//TIM2_CH2 单脉冲输出+重复计数功能初始化
void TIM2_Startup(u32 frequency);   //启动定时器8
void Locate_Rle(long num,u32 frequency,DIR_Type dir); //相对定位函数
void Locate_Abs(long num,u32 frequency);//绝对定位函数
void Locate_run(DIR_Type dir,int times,u32 frequency);//Run_Step
void Locate_Run(DIR_Type dir,u32 frequency);//Run
#endif
