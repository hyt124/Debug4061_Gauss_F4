/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define KEYy3_Pin GPIO_PIN_0
#define KEYy3_GPIO_Port GPIOC
#define KEYy2_Pin GPIO_PIN_1
#define KEYy2_GPIO_Port GPIOC
#define KEYy1_Pin GPIO_PIN_2
#define KEYy1_GPIO_Port GPIOC
#define KEYy0_Pin GPIO_PIN_3
#define KEYy0_GPIO_Port GPIOC
#define KEYx0_Pin GPIO_PIN_4
#define KEYx0_GPIO_Port GPIOC
#define KEYx1_Pin GPIO_PIN_5
#define KEYx1_GPIO_Port GPIOC
#define FIRE_Pin GPIO_PIN_15
#define FIRE_GPIO_Port GPIOB
#define KEYx2_Pin GPIO_PIN_6
#define KEYx2_GPIO_Port GPIOC
#define KEYx3_Pin GPIO_PIN_7
#define KEYx3_GPIO_Port GPIOC
#define DIR__Pin GPIO_PIN_0
#define DIR__GPIO_Port GPIOE
#define EN__Pin GPIO_PIN_1
#define EN__GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
