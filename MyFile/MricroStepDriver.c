#include "MricroStepDriver.h"
u8 rcr_remainder;   //重复计数余数部分
u8 is_rcr_finish=1; //重复计数器是否设置完成
long rcr_integer;	//重复计数整数部分
long target_pos=0;  //有符号方向
long current_pos=0; //有符号方向
DIR_Type motor_dir=CW;//顺时针
int PWM_Count_Set;
int flag = 0;// 0 OR 1
int mode = 0;// 0 OR 1
extern int stop;

/***************************************************
Name: TIM2_Startup
Tips:Double modes
***************************************************/
void TIM2_Startup(u32 frequency)   //启动定时器8
{
	if(mode == 1)
	{
		if(frequency <=1)
		{
			HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
		}
		else
		{
			flag = 1;
			u16 temp_arr=1000000/frequency-1;
			if(stop == 0)
			HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
			htim2.Instance->ARR = temp_arr;
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,temp_arr/2);
				if(stop == 0)
			HAL_TIM_Base_Start_IT(&htim2);
		}		
	}
	else if( mode == 0)
	{
		if(frequency <=1)
		{
			HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
		}
		else
		{
			u16 temp_arr=1000000/frequency-1;
			HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
			htim2.Instance->ARR = temp_arr;
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,temp_arr/2);
		}		
	}
}

/***************************************************
Name: Motor Run Cycle
Tips:Stop it by setting 0 frequency
***************************************************/
void Locate_Run(DIR_Type dir,u32 frequency)
{
	mode=0;
	if(dir == 1)//顺时针
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_RESET);
	else if(dir==0)//逆时针
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_SET);
	TIM2_Startup(frequency);	
}

/***************************************************
Name: Motor Run By Step
Tips:Before using again you have to set stop to 0
***************************************************/
void Locate_RunStep(DIR_Type dir,int times,u32 frequency)
{
	mode = 1;
	if(dir == 1)//顺时针
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_RESET);
	else if(dir==0)//逆时针
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,GPIO_PIN_SET);
	PWM_Count_Set = times;
	if(flag == 0 && stop == 0)
	{
		TIM2_Startup(frequency);	
	}
}




//void Locate_Rle(long num,u32 frequency,DIR_Type dir) //相对定位函数
//{
//	if(num<=0) //数值小等于0 则直接返回
//	{
//		printf("\r\nThe num should be greater than zero!!\r\n");
//		return;
//	}
//	if(TIM2->CR1&0x01)//上一次脉冲还未发送完成  直接返回
//	{
//		printf("\r\nThe last time pulses is not send finished,wait please!\r\n");
//		return;
//	}
//	if((frequency<20)||(frequency>100000))//脉冲频率不在范围内 直接返回
//	{
//		printf("\r\nThe frequency is out of range! please reset it!!(range:20Hz~100KHz)\r\n");
//		return;
//	}
//	motor_dir=dir;//得到方向	
//	DRIVER_DIR=motor_dir;//设置方向
//	
//	if(motor_dir==CW)//顺时针
//		target_pos=current_pos+num;//目标位置
//	else if(motor_dir==CCW)//逆时针
//		target_pos=current_pos-num;//目标位置
//	
//	rcr_integer=num/(RCR_VAL+1);//重复计数整数部分
//	rcr_remainder=num%(RCR_VAL+1);//重复计数余数部分
//	is_rcr_finish=0;//重复计数器未设置完成
//	TIM2_Startup(frequency);// 开启TIM2
//}
///********************************************
////绝对定位函数 
////num   -2147483648～2147483647
////frequency: 20Hz~100KHz
//*********************************************/
//void Locate_Abs(long num,u32 frequency)//绝对定位函数
//{
//	if(TIM2->CR1&0x01)//上一次脉冲还未发送完成 直接返回
//	{
//		printf("\r\nThe last time pulses is not send finished,wait please!\r\n");
//		return;
//	}
//	if((frequency<20)||(frequency>100000))//脉冲频率不在范围内 直接返回
//	{
//		printf("\r\nThe frequency is out of range! please reset it!!(range:20Hz~100KHz)\r\n");
//		return;
//	}
//	target_pos=num;//设置目标位置
//	if(target_pos!=current_pos)//目标和当前位置不同
//	{
//		if(target_pos>current_pos)
//			motor_dir=CW;//顺时针
//		else
//			motor_dir=CCW;//逆时针
//		DRIVER_DIR=motor_dir;//设置方向
//		
//		rcr_integer=abs(target_pos-current_pos)/(RCR_VAL+1);//重复计数整数部分
//		rcr_remainder=abs(target_pos-current_pos)%(RCR_VAL+1);//重复计数余数部分
//		is_rcr_finish=0;//重复计数器未设置完成
//		TIM2_Startup(frequency);//开启TIM2
//	}
//}
