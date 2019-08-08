#ifndef User_PWM_H_
#define User_PWM_H_

//库文件引用
#include "stm32f4xx_hal.h"
#include "stdio.h"

//自动生成文件引用
#include "tim.h"

//用户头文件引用


//公有函数申明

/* 设置通道一的位置 */
void ChannelOne_SetPositon(float Position);
/* 设置通道二的位置 */
void ChannelTwo_SetPositon(float Position);


#endif
