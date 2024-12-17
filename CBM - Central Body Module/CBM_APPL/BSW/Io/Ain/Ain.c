/* START OF FILE */
/* INCLUDE START */
#include "Ain.h"
#include "InputCtrl.h"
#include "adc.h"
#include "main.h"
#include <math.h>
#include <stdlib.h>
/* INCLUDE END */
/* DEFINE START */
#define IGNPOT_POS 0
#define ACCPOT_POS 1
#define BRPOT_POS 2
#define AQS_POS 3
#define RS_POS 4
#define PSPOT_POS 6
#define GBPOT_POS 7
#define LS_POS 8
#define GS_POS 9
#define ADC_NUMBER_OF_ERRORS 3
#define ADCMUX_NUMBER_OF_INPUTS 10
/* DEFINE STOP */
/* VARIABLES START */
static uint8 Ain_ConversionComplete = 0;
uint16 Ain_Mux[ADCMUX_NUMBER_OF_INPUTS] = {0};
uint32 Adc_Error[ADC_NUMBER_OF_ERRORS];
/* VARIABLES END */
/* FUNCTIONS START */
extern void Dem_SaveDtc(uint8 index, uint8 status);
void Ain_MainFunction(void);
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
/* FUNCTIONS END */
/* FUNCTIONS START */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	Ain_ConversionComplete = 1;
}
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
	static uint32 status = 0;
	status = HAL_ADC_GetError(&hadc1);
	switch(status)
	{
	case HAL_ADC_ERROR_INTERNAL:
		Adc_Error[0]++;
		break;
	case HAL_ADC_ERROR_OVR:
		Adc_Error[1]++;
		break;
	case HAL_ADC_ERROR_DMA:
		Adc_Error[2]++;
		break;
	}
}
void Ain_MainFunction(void)
{
	/* Status variable. */
	static uint32 status = 0;
	static uint32 counter = 0;
	/* Main counter. */
	static uint32 Ain_MainCounter = 0;
	/* Muxer pin iterator. */
	static uint8 Ain_CounterMux = 0;
	/* Check for error. */
	status = HAL_ADC_GetError(&hadc1);
	/* Call the error callback in case of error. */
	if(status) HAL_ADC_ErrorCallback(&hadc1);
	else for(uint8 i = 0; i < 3; i++) Adc_Error[i] = 0;
	{

	}
	/* Process the analog inputs coming from the muxer. */
	while(Ain_CounterMux < ADCMUX_NUMBER_OF_INPUTS)
	{
		switch(Ain_CounterMux)
		{
		case 0:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 0);
			break;
		case 1:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 1);
			break;
		case 9:
			HAL_GPIO_WritePin(SIG0_ADCMUX_GPIO_Port, SIG0_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG1_ADCMUX_GPIO_Port, SIG1_ADCMUX_Pin, 1);
			HAL_GPIO_WritePin(SIG2_ADCMUX_GPIO_Port, SIG2_ADCMUX_Pin, 0);
			HAL_GPIO_WritePin(SIG3_ADCMUX_GPIO_Port, SIG3_ADCMUX_Pin, 1);
			break;
		default:
			break;
		}
		/* Start the measurement. */
		HAL_ADC_Start_IT(&hadc1);
		/* Refresh the end-of-conversion variable. */
		Ain_ConversionComplete = 0;
		/* Wait for conversion. */
		while(Ain_ConversionComplete == 0 && counter < 20000) counter++;
		if(20000 == counter) Dem_SaveDtc(10, 0xE);
		else
		{
			/* Do nothing. */
		}
		counter = 0;
		/* Get the measured value. */
		Ain_Mux[Ain_CounterMux] = HAL_ADC_GetValue(&hadc1);
		/* Stop the measurement. */
		HAL_ADC_Stop_IT(&hadc1);
		/* Get the next value in the muxer. */
		Ain_CounterMux++;
	}
	/* Reset the muxer counter.  */
	if(Ain_CounterMux == ADCMUX_NUMBER_OF_INPUTS) Ain_CounterMux = 0;
	else
	{
		/* Do nothing. */
	}
	/* Store the measured values. */
	StatusList_InputValue[IGN_ARRPOS] = Ain_Mux[IGNPOT_POS];
	StatusList_InputValue[ACC_ARRPOS] = Ain_Mux[ACCPOT_POS];
	StatusList_InputValue[BR_ARRPOS] = Ain_Mux[BRPOT_POS];
	StatusList_InputValue[PS_ARRPOS] = Ain_Mux[PSPOT_POS];
	StatusList_InputValue[GB_ARRPOS] = Ain_Mux[GBPOT_POS];
	StatusList_InputValue[LSNS_ARRPOS] = Ain_Mux[LS_POS];
	StatusList_InputValue[RSNS_ARRPOS] = Ain_Mux[RS_POS];
	StatusList_InputValue[AQSNS_ARRPOS] = Ain_Mux[AQS_POS];
	StatusList_InputValue[GSNS_ARRPOS] = Ain_Mux[GS_POS];
	/* Increment the counter. */
	Ain_MainCounter++;
}
/* FUNCTIONS END */
/* STOP OF FILE */
