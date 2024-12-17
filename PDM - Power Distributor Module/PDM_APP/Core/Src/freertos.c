/* USER CODE BEGIN Header */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LoadCtrl.h"
#include "CanH.h"
#include "Ain.h"
#include "EcuM.h"
#include "Nvm.h"
#include "Dcm.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8 OS_IdleIndex = 0;
uint8 OS_XCP_CpuLoad = 0;
float OS_IdleRunTime = 0;
float OS_DeltaIdleRunTime = 0;
float OS_CpuLoad = 0;
TaskStatus_t xTaskStatusArray[5] = {0};
UBaseType_t uxArraySize = {0};
uint32 OS_AverageCpuLoad = 0;
uint32 ulTotalRunTime = {0};
uint32 localTaskCounter = 0;
long long OS_Counter = 0;
long long IDLE_Counter = 0;
volatile unsigned long ulHighFrequencyTimerTicks;
extern uint8 EcuM_State;
extern TIM_HandleTypeDef htim3;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
/* USER CODE END Variables */
/* Definitions for QM_BSW_OS_TASK */
osThreadId_t QM_BSW_OS_TASKHandle;
const osThreadAttr_t QM_BSW_OS_TASK_attributes = {
  .name = "QM_BSW_OS_TASK",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityRealtime5,
};
/* Definitions for QM_APPL_OS_TASK */
osThreadId_t QM_APPL_OS_TASKHandle;
const osThreadAttr_t QM_APPL_OS_TASK_attributes = {
  .name = "QM_APPL_OS_TASK",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityRealtime4,
};
/* Definitions for CPULOAD_OS_TASK */
osThreadId_t CPULOAD_OS_TASKHandle;
const osThreadAttr_t CPULOAD_OS_TASK_attributes = {
  .name = "CPULOAD_OS_TASK",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Alarm5ms */
osTimerId_t Alarm5msHandle;
const osTimerAttr_t Alarm5ms_attributes = {
  .name = "Alarm5ms"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
/* USER CODE END FunctionPrototypes */

void QM_BSW(void *argument);
void QM_APPL(void *argument);
void CPULOAD(void *argument);
void Alarm5ms_Callback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 1 */
void configureTimerForRunTimeStats(void)
{
	ulHighFrequencyTimerTicks = 0;
	HAL_TIM_Base_Start_IT(&htim3);
}
unsigned long getRunTimeCounterValue(void)
{
	return ulHighFrequencyTimerTicks;
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
	IDLE_Counter++;
	uxArraySize = uxTaskGetSystemState(xTaskStatusArray, 5, &ulTotalRunTime);
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
void vApplicationTickHook( void )
{
	OS_Counter++;
}
/* USER CODE END 3 */

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
	EcuM_PerformReset(12);
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
	EcuM_PerformReset(11);
}
/* USER CODE END 5 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of Alarm5ms */
  Alarm5msHandle = osTimerNew(Alarm5ms_Callback, osTimerPeriodic, NULL, &Alarm5ms_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of QM_BSW_OS_TASK */
  QM_BSW_OS_TASKHandle = osThreadNew(QM_BSW, NULL, &QM_BSW_OS_TASK_attributes);

  /* creation of QM_APPL_OS_TASK */
  QM_APPL_OS_TASKHandle = osThreadNew(QM_APPL, NULL, &QM_APPL_OS_TASK_attributes);

  /* creation of CPULOAD_OS_TASK */
  CPULOAD_OS_TASKHandle = osThreadNew(CPULOAD, NULL, &CPULOAD_OS_TASK_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	osTimerStart(Alarm5msHandle, 5);
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_QM_BSW */
/* USER CODE END Header_QM_BSW */
void QM_BSW(void *argument)
{
  /* USER CODE BEGIN QM_BSW */
	for(;;)
	{
		NvM_MainFunction();
		CanH_MainFunction();
		Dcm_MainFunction();
		Ain_MainFunction();
		EcuM_MainFunction();
		vTaskSuspend(NULL); /* suspend task; will be re-activated in OS timer callback. */
	}
  /* USER CODE END QM_BSW */
}

/* USER CODE BEGIN Header_QM_APPL */
/* USER CODE END Header_QM_APPL */
void QM_APPL(void *argument)
{
  /* USER CODE BEGIN QM_APPL */
	for(;;)
	{
		if(EcuM_State == 1) LoadCtrl_MainFunction(); /* Execute load control only in SW RUN. */
		else
		{
			/* Do nothing. */
		}
		vTaskSuspend(NULL);
	}
  /* USER CODE END QM_APPL */
}

/* USER CODE BEGIN Header_CPULOAD */
/* USER CODE END Header_CPULOAD */
void CPULOAD(void *argument)
{
  /* USER CODE BEGIN CPULOAD */
	for(;;)
	{
		localTaskCounter++;
		OS_DeltaIdleRunTime = xTaskStatusArray[OS_IdleIndex].ulRunTimeCounter - OS_IdleRunTime;
		if(0 != ulHighFrequencyTimerTicks)
		{
			OS_CpuLoad = 100 - (OS_DeltaIdleRunTime / ulHighFrequencyTimerTicks) * 100;
		}
		else
		{
			/* Do nothing. */
		}
		OS_AverageCpuLoad += OS_CpuLoad;
		ulHighFrequencyTimerTicks = 0;
		OS_IdleRunTime = xTaskStatusArray[OS_IdleIndex].ulRunTimeCounter;
		if(localTaskCounter % 12 == 0)
		{
			OS_XCP_CpuLoad = OS_AverageCpuLoad / 12; /* Calculate CPU load value every 480 milliseconds. */
			OS_AverageCpuLoad = 0;
		}
		else
		{
			/* Do nothing. */
		}
		vTaskSuspend(NULL);
	}
  /* USER CODE END CPULOAD */
}

/* Alarm5ms_Callback function */
void Alarm5ms_Callback(void *argument)
{
  /* USER CODE BEGIN Alarm5ms_Callback */
	static uint32 counter = 0;
	counter++;
	vTaskResume(QM_APPL_OS_TASKHandle);
	vTaskResume(QM_BSW_OS_TASKHandle); /* I could have used event functionality of FreeRTOS to re-activate tasks. I did that on DMU, but here
	it was not possible, RAM and ROM were scarce (close to 100%). */
	if(counter % 8 == 0 && counter != 0) vTaskResume(CPULOAD_OS_TASKHandle); /* Resources are scarce, must use this approach instead of another OS timer that expires every 40 milliseconds. */
	else
	{
		/* Do nothing. */
	}
  /* USER CODE END Alarm5ms_Callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* USER CODE END Application */

