#include "User_Uart.h"
#include "User_PID.h"

//公有变量

//私有变量
static uint8_t _GetErrorRXBuffer[7] = {0};
static uint8_t _GetCommandRXBuffer[1] = {0};
static uint8_t _GetDistantRxBuffer[12] = {0};
static uint8_t _GetDistantRxVal = 0;
static uint8_t _GetDistantStatus = 0;
 float   _GetDistantResults = 0.0; 
static uint8_t _GetDistantUpdateStatus = 0;
static int16_t Coordinate1_One = 0 , Coordinate1_Two = 0;
static uint8_t CommandUpdateStatus = 0;

uint8_t _DebugCommand = 0;


/* 查询命令是否更新函数 */
uint8_t Is_CommandUpdate(void)
{
	return CommandUpdateStatus;
}

/* 清除命令更新标志位函数 */
void Clear_CommandUpdateStatus(void)
{
	CommandUpdateStatus = 0;
}

/* 获取X(或者是Y明天决定)轴坐标结果 */
int16_t Get_CoordinateXResult(void)
{
	return Coordinate1_One;
}

/* 获取Y(或者是X明天决定)轴坐标结果 */
int16_t Get_CoordinateYResult(void)
{
	return Coordinate1_Two;
}




/* 误差获取串口 串口1 HC12串口 初始化 */
void User_GetErrorUart_Init(void)
{
	HAL_UART_Receive_IT(&huart1,_GetErrorRXBuffer,7);
}

/* 调试信息输出串口 DAP调试器虚拟串口 串口3 */
void User_DebugUart_Init(void)
{
	HAL_UART_Receive_IT(&huart3,_GetCommandRXBuffer,1);
}


/* 距离信息获取串口初始化 接激光传感器 */
void User_DistantUart_Init(void)
{
	//等待激光传感器上电发送 "OK\r\n"
	HAL_Delay(1000);
	HAL_UART_Transmit(&huart2,(uint8_t*)"iFACM\r\n",sizeof("iFACM\r\n"),100);
	HAL_UART_Receive_IT(&huart2,&_GetDistantRxVal,1);
}

/* 误差获取串口 UART1 HC12 OPENMV 串口 回调函数(中断处理函数) */
void _GetErrorUartCallBack(void)
{
	uint8_t Coordinate1[3] ={0} ,Coordinate2[3] = {0};
	uint8_t temp = 0 , temp2 = 0;
	uint8_t* p = NULL;
	
	//把/n作为断帧符
	if(_GetErrorRXBuffer[6] != '\n')
	{
		//收不到正确的信息就想办法寻找正确的尾帧 '\n' 然后恢复数据
		//printf("F**k\n");
		for(temp = 0;temp < 7;temp ++)
		{
			temp2 ++;
			if(_GetErrorRXBuffer[temp] == '\n')
			{
 				memset(_GetErrorRXBuffer,0x00,(temp + 1));
				for(;(temp + 1) < 7;temp ++ )
				{
					p = &_GetErrorRXBuffer[temp + 1];
					p -= temp;
					*p = _GetErrorRXBuffer[temp + 1];
				}
				
				HAL_UART_Receive_IT(&huart1,&_GetErrorRXBuffer[temp2 +1],(6 - temp2));
				
				return;
			}
		}
	
		HAL_UART_Receive_IT(&huart1,_GetErrorRXBuffer,7);
		
	}
	else
	{
		//拷贝前三个ASCII字符到坐标一字符串 后三个到坐标二字符串
		memcpy(Coordinate1,_GetErrorRXBuffer,3);
		memcpy(Coordinate2,&_GetErrorRXBuffer[3],3);
		//转换字符串到整数
		Coordinate1_One = atoi((const char*)Coordinate1);
		Coordinate1_Two = atoi((const char*)Coordinate2);
		//重新开启接收中断 等待下一次过程
		HAL_UART_Receive_IT(&huart1,_GetErrorRXBuffer,7);
		//指示收到新的指令
		CommandUpdateStatus = 1;
		//收到新指令立即执行PID
		//PIDOut();
	}
	
}


/* 命令获取串口的中断服务函数 */
void _GetCommandUartCallBack(void)
{
	_DebugCommand = _GetCommandRXBuffer[0];
	HAL_UART_Receive_IT(&huart3,_GetCommandRXBuffer,1);
}


/* 距离信息获取串口的中断服务函数 */
void _GetDistantUartCallBack(void)
{
	static uint8_t RxCount = 0;
	uint8_t DecodeTable[6] = {0};
	
	_GetDistantRxBuffer[RxCount] = _GetDistantRxVal;
	RxCount ++;
	/* 一帧结束 */
	if(_GetDistantRxVal == '\n')
	{
		/* 第一个字符是E就是错误 */
		if(_GetDistantRxBuffer[0] == 'E')
		{
			//错误处理部分
			memset(_GetDistantRxBuffer,0x00,12);
			RxCount = 0;
			//出现错误将此位拉高
			_GetDistantStatus = 1;
			_GetDistantResults = 10.0;
			HAL_UART_Receive_IT(&huart2,&_GetDistantRxVal,1);
			return;
		}
		else
		{
			//字符串分割
			memset(_GetDistantRxBuffer,0x00,2);
			memset(&_GetDistantRxBuffer[7],0x00,3);
			//内存拷贝
			memcpy(DecodeTable,&_GetDistantRxBuffer[2],5);
			//字符串转浮点数
			_GetDistantResults = (float)atof((const char*)DecodeTable);
			//重置计数 重新开启中断
			memset(_GetDistantRxBuffer,0x00,12);
			RxCount = 0;
			_GetDistantUpdateStatus = 1;
			HAL_UART_Receive_IT(&huart2,&_GetDistantRxVal,1);
			return;
		}
		
	}
	
	HAL_UART_Receive_IT(&huart2,&_GetDistantRxVal,1);
	
}



/* 命令查询函数 返回当前调试串口的指令 */
uint8_t Get_DebugCommand(void)
{
	return _DebugCommand;
}



/* Retargeting printf() output to Usart3 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif 

int fputc(int ch,FILE *f)
{
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart3,temp,1,10);        //UartHandle是串口的句柄
		return ch;
}


PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart3,(uint8_t*)&ch,1,10);
	return ch;
}

