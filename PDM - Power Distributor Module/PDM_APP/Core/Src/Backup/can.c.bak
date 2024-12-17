/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

CAN_HandleTypeDef hcan;

/* CAN init function */
void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */
  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */
  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 9;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_5TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan.Init.TimeTriggeredMode = ENABLE;
  hcan.Init.AutoBusOff = ENABLE;
  hcan.Init.AutoWakeUp = ENABLE;
  hcan.Init.AutoRetransmission = ENABLE;
  hcan.Init.ReceiveFifoLocked = ENABLE;
  hcan.Init.TransmitFifoPriority = ENABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */
	CAN_FilterTypeDef filterConfig;
	filterConfig.FilterBank = 13;
	filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	filterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	filterConfig.FilterActivation = ENABLE;
	filterConfig.FilterIdHigh = (0x702 << 5) & 0xFFFF;
	filterConfig.FilterIdLow = 0x0000;
	filterConfig.FilterMaskIdHigh = (0x7FF << 5);
	filterConfig.FilterMaskIdLow = 0x0000;
	HAL_CAN_ConfigFilter(&hcan, &filterConfig);

	filterConfig.FilterBank = 12;
	filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	filterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	filterConfig.FilterActivation = ENABLE;
	filterConfig.FilterIdHigh = (0x602 << 5) & 0xFFFF;
	filterConfig.FilterIdLow = 0x0000;
	filterConfig.FilterMaskIdHigh = (0x7FF << 5);
	filterConfig.FilterMaskIdLow = 0x0000;
	HAL_CAN_ConfigFilter(&hcan, &filterConfig);

	filterConfig.FilterBank = 11;
	filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	filterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	filterConfig.FilterActivation = ENABLE;
	filterConfig.FilterIdHigh = (0x510 << 5) & 0xFFFF;
	filterConfig.FilterIdLow = 0x0000;
	filterConfig.FilterMaskIdHigh = (0x7FF << 5);
	filterConfig.FilterMaskIdLow = 0x0000;
	HAL_CAN_ConfigFilter(&hcan, &filterConfig);

	filterConfig.FilterBank = 10;
	filterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	filterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	filterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	filterConfig.FilterActivation = ENABLE;
	filterConfig.FilterIdHigh = (0x10E << 5) & 0xFFFF;
	filterConfig.FilterIdLow = 0x0000;
	filterConfig.FilterMaskIdHigh = (0x7FF << 5);
	filterConfig.FilterMaskIdLow = 0x0000;
	HAL_CAN_ConfigFilter(&hcan, &filterConfig);

	static uint32_t notificationLocal = 0;
	HAL_CAN_Start(&hcan);
	notificationLocal = CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_RX_FIFO0_FULL;
	HAL_CAN_ActivateNotification(&hcan, notificationLocal);
  /* USER CODE END CAN_Init 2 */

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */
  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN GPIO Configuration
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN CAN1_MspInit 1 */
  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */
  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();

    /**CAN GPIO Configuration
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USB_HP_CAN1_TX_IRQn);
    HAL_NVIC_DisableIRQ(USB_LP_CAN1_RX0_IRQn);
    HAL_NVIC_DisableIRQ(CAN1_RX1_IRQn);
    HAL_NVIC_DisableIRQ(CAN1_SCE_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */
  /* USER CODE END CAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/* USER CODE END 1 */
