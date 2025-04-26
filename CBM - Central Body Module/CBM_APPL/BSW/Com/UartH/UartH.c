/* START OF FILE */
/* INCLUDE START */
#include "UartH.h"
#include "InputCtrl.h"
#include "stdlib.h"
#include "main.h"
#include "EcuM.h"
#include <string.h>
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
/* INCLUDE END */
/* VARIABLES START */
uint32 UartH_ErrorArr[5];
uint32 Uart_BswState = 0;
uint8 UartH_BtcRxData = 0;
uint8 UartH_BtcDataBuffer[4] = {0};
uint8 UartH_BtcProcessedData = 0;
uint8 UartCounter_BtcRxCount = 0;
uint32 UartH_MainCounter = 0;
/* VARIABLES STOP */
/* FUNCTIONS START */
void UartH_MainFunction(void);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
/* FUNCTIONS STOP */
/* FUNCTIONS START */
void UartH_MainFunction(void)
{
	/* Variable declaration. */
	static uint32 localState = 0;
	/* Get UART state. */
	localState = HAL_UART_GetState(&huart1);
	/* Store the BT processed data. */
	if(UartH_BtcProcessedData != 0)
	{
		StatusList_InputValue[4] = UartH_BtcProcessedData;
		UartH_BtcProcessedData = 0;
	}
	else
	{
		/* Do nothing. */
	}
	if(0 == huart1.ErrorCode) for(uint8 i = 0; i < 5; i++) UartH_ErrorArr[i] = 0;
	else
	{
		/* Do nothing. */
	}
	switch(localState)
	{
	case HAL_UART_STATE_RESET:
		Uart_BswState = localState;
		break;
	case HAL_UART_STATE_READY:
		HAL_UART_Receive_IT(&huart1, &UartH_BtcRxData, 1);
		Uart_BswState = localState;
		break;
	case HAL_UART_STATE_BUSY:
		Uart_BswState = localState;
		break;
	case HAL_UART_STATE_BUSY_TX:
		Uart_BswState = localState;
		break;
	case HAL_UART_STATE_BUSY_RX:
		Uart_BswState = localState;
		break;
	case HAL_UART_STATE_BUSY_TX_RX:
		Uart_BswState = localState;
		break;
	case HAL_UART_STATE_TIMEOUT:
		Uart_BswState = localState;
		HAL_UART_ErrorCallback(&huart1);
		break;
	case HAL_UART_STATE_ERROR:
		Uart_BswState = localState;
		HAL_UART_ErrorCallback(&huart1);
		break;
	default:
		break;
	}
	UartH_MainCounter++;
}
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	uint32 receivedValue = HAL_UART_GetError(huart);
	switch(receivedValue)
	{
	case HAL_UART_ERROR_NONE:
		break;
	case HAL_UART_ERROR_PE:
		UartH_ErrorArr[0]++;
		break;
	case HAL_UART_ERROR_NE:
		UartH_ErrorArr[1]++;
		break;
	case HAL_UART_ERROR_FE:
		UartH_ErrorArr[2]++;
		break;
	case HAL_UART_ERROR_ORE:
		UartH_ErrorArr[3]++;
		break;
	case HAL_UART_ERROR_DMA:
		UartH_ErrorArr[4]++;
		break;
	default:
		break;
	}
}
/* Process BT received data. */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{
		if(UartH_BtcRxData == '\n')
		{
			if(UartCounter_BtcRxCount <= 3) UartH_BtcProcessedData = atoi((char*)UartH_BtcDataBuffer);
			else
			{
				/* Do nothing. */
			}
			UartCounter_BtcRxCount = 0;
		}
		else if(UartCounter_BtcRxCount < 3)
		{
			UartH_BtcDataBuffer[UartCounter_BtcRxCount] = UartH_BtcRxData;
			UartCounter_BtcRxCount++;
		}
		else UartCounter_BtcRxCount = 0;
		HAL_UART_Receive_IT(huart, &UartH_BtcRxData, 1);
	}
	else
	{
		/* do nothing */
	}
}
/* FUNCTIONS STOP */
/* STOP OF FILE */
