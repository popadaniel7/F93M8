/* START OF FILE */
/* INCLUDE START */
#include "TimH.h"
#include "tim.h"
/* INCLUDE END */
/* VARIABLES START */
uint32 Tim_ErrorStatus[4] = {0};
extern TIM_HandleTypeDef htim5;
/* VARIABLES END */
/* FUNCTIONS START */
void TimH_MainFunction(void);
/* FUNCTIONS END */
/* FUNCTIONS START */
void TimH_MainFunction(void)
{
	/* Main counter. */
	static uint32 TimH_MainCounter = 0;
	/* Initialize the timers. */
	if(TimH_MainCounter == 0)
	{
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
		htim2.Instance->CCR1 = 0;
		htim3.Instance->CCR1 = 0;
		htim3.Instance->CCR2 = 0;
		htim3.Instance->CCR3 = 0;
		htim3.Instance->CCR4 = 0;
	}
	else
	{
		/* Do nothing. */
	}
	/* Error checking. */
	if(HAL_TIM_Base_GetState(&htim2) == HAL_TIM_STATE_ERROR) Tim_ErrorStatus[0]++;
	else Tim_ErrorStatus[0] = 0;
	/* Error checking. */
	if(HAL_TIM_Base_GetState(&htim3) == HAL_TIM_STATE_ERROR) Tim_ErrorStatus[1]++;
	else Tim_ErrorStatus[1] = 0;
	/* Error checking. */
	if(HAL_TIM_Base_GetState(&htim4) == HAL_TIM_STATE_ERROR) Tim_ErrorStatus[2]++;
	else Tim_ErrorStatus[2] = 0;
	/* Error checking. */
	if(HAL_TIM_Base_GetState(&htim5) == HAL_TIM_STATE_ERROR) Tim_ErrorStatus[3]++;
	else Tim_ErrorStatus[3] = 0;
	/* Increment the counter. */
	TimH_MainCounter++;
}
/* FUNCTIONS END */
/* STOP OF FILE */
