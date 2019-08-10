#ifndef User_Uart_H_
#define User_Uart_H_

//库头文件
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//用户头文件
#include "usart.h"


//公有函数

/* 误差获取串口 串口1 HC12串口 初始化 */
void User_GetErrorUart_Init(void);

/* 调试信息输出串口 DAP调试器虚拟串口 串口3 PB10 PB11 */
void User_DebugUart_Init(void);

/* 距离信息获取串口初始化 接激光传感器 */
void User_DistantUart_Init(void);

/* 误差获取串口的中断服务函数 */
void _GetErrorUartCallBack(void);

/* 命令获取串口的中断服务函数 */
void _GetCommandUartCallBack(void);

/* 距离信息获取串口的中断服务函数 */
void _GetDistantUartCallBack(void);

/* 查询命令是否更新函数 */
uint8_t Is_CommandUpdate(void);

/* 清除命令更新标志位函数 */
void Clear_CommandUpdateStatus(void);

/* 获取X(或者是Y明天决定)轴坐标结果 */
int16_t Get_CoordinateXResult(void);

/* 获取Y(或者是X明天决定)轴坐标结果 */
int16_t Get_CoordinateYResult(void);

/* 命令查询函数 返回当前调试串口的指令 */
uint8_t Get_DebugCommand(void);

#endif
