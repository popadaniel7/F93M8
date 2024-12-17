/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define HC05_STATE_Pin GPIO_PIN_0
#define HC05_STATE_GPIO_Port GPIOA
#define SIGADCMUX_Pin GPIO_PIN_4
#define SIGADCMUX_GPIO_Port GPIOA
#define MCP_SCK_Pin GPIO_PIN_5
#define MCP_SCK_GPIO_Port GPIOA
#define MCP_MISO_Pin GPIO_PIN_6
#define MCP_MISO_GPIO_Port GPIOA
#define MCP_MOSI_Pin GPIO_PIN_7
#define MCP_MOSI_GPIO_Port GPIOA
#define MCP_CS_Pin GPIO_PIN_4
#define MCP_CS_GPIO_Port GPIOC
#define PWM_WWL_Pin GPIO_PIN_0
#define PWM_WWL_GPIO_Port GPIOB
#define PWM_WWR_Pin GPIO_PIN_1
#define PWM_WWR_GPIO_Port GPIOB
#define SIG1_ADCMUX_Pin GPIO_PIN_10
#define SIG1_ADCMUX_GPIO_Port GPIOB
#define PWM_DLR_Pin GPIO_PIN_6
#define PWM_DLR_GPIO_Port GPIOC
#define PWM_DLL_Pin GPIO_PIN_7
#define PWM_DLL_GPIO_Port GPIOC
#define SIG0_ADCMUX_Pin GPIO_PIN_8
#define SIG0_ADCMUX_GPIO_Port GPIOA
#define NUCLEO_RX_UNUSED_Pin GPIO_PIN_9
#define NUCLEO_RX_UNUSED_GPIO_Port GPIOA
#define TX_HC05_Pin GPIO_PIN_10
#define TX_HC05_GPIO_Port GPIOA
#define PWM_CLIMAFAN_Pin GPIO_PIN_15
#define PWM_CLIMAFAN_GPIO_Port GPIOA
#define SIG2_ADCMUX_Pin GPIO_PIN_4
#define SIG2_ADCMUX_GPIO_Port GPIOB
#define SIG3_ADCMUX_Pin GPIO_PIN_5
#define SIG3_ADCMUX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
