/* USER CODE BEGIN Header */
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
#define BUZOUT_Pin GPIO_PIN_0
#define BUZOUT_GPIO_Port GPIOC
#define DIGITALCLUSTER_BACKLIGHT_Pin GPIO_PIN_1
#define DIGITALCLUSTER_BACKLIGHT_GPIO_Port GPIOB
#define REVERSECAMERA_RESET_Pin GPIO_PIN_11
#define REVERSECAMERA_RESET_GPIO_Port GPIOD
#define REVERSECAMERA_POWERDOWN_Pin GPIO_PIN_12
#define REVERSECAMERA_POWERDOWN_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
