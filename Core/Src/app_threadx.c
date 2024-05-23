/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    app_threadx.c
 * @author  MCD Application Team
 * @brief   ThreadX applicative file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_threadx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define THREAD_STACK_SIZE 400
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
TX_THREAD thread1;
TX_THREAD thread2;
ULONG thread1_stack[THREAD_STACK_SIZE];
ULONG thread2_stack[THREAD_STACK_SIZE];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void LedThread1_entry(ULONG thread_input);
void LedThread2_entry(ULONG thread_input);
//void fade_in_out(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint32_t delay);
/* USER CODE END PFP */

/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;

  /* USER CODE BEGIN App_ThreadX_MEM_POOL */
	(void) byte_pool;
  /* USER CODE END App_ThreadX_MEM_POOL */

  /* USER CODE BEGIN App_ThreadX_Init */
	tx_thread_create(&thread1, "LED Thread 1", LedThread1_entry, 0,
			thread1_stack, THREAD_STACK_SIZE, 15, 15,
			0, TX_AUTO_START);

	tx_thread_create(&thread2, "LED Thread 2", LedThread2_entry, 0,
			thread2_stack, THREAD_STACK_SIZE, 14, 14,
			0, TX_AUTO_START);
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

/**
  * @brief  MX_ThreadX_Init
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */

  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 1 */
void LedThread1_entry(ULONG thread_input) {
	while (1) {
		HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
		tx_thread_sleep(10);
//		for (int i = 0; i < 255; i++) {
//			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, i);
//			tx_thread_sleep(1);
//		}
//		for (int i = 255; i > 0; i--) {
//			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, i);
//			tx_thread_sleep(1);
//		}
	}
}

void LedThread2_entry(ULONG thread_input) {
	while (1) {
		HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
		tx_thread_sleep(100);
//		for (int i = 0; i < 255; i++) {
//			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, i);

//			tx_thread_sleep(2);
//		}
//		for (int i = 255; i > 0; i--) {
//			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, i);
//			tx_thread_sleep(2);
//		}

	}
}

/* USER CODE END 1 */
