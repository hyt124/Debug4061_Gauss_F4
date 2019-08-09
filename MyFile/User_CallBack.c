#include "User_CallBack.h"


//私有函数申明


//公有远程变量申明
extern uint8_t _GetErrorRXBuffer[7];



/* 串口总回调函数 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	
	/* 串口3中断部分 */
	if(huart->Instance == USART3)
	{
		_GetCommandUartCallBack();
	}
	
	/* 串口1中断部分 */
	if(huart->Instance == USART1)
	{
		_GetErrorUartCallBack();
	}
	
	/* 串口2中断部分 */
	if(huart->Instance == USART2)
	{
		_GetDistantUartCallBack();
	}

	
}



