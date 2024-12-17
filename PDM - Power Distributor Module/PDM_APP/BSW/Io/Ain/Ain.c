#include "Ain.h"
#include "adc.h"
#include "Dem.h"

uint32 Ain_MainCounter = 0;
uint32 Ain_Buffer[4] = {0};
uint32 aux1 = 0;
uint32 aux2 = 0;
uint32 aux3 = 0;
uint32 sum1 = 0;
uint32 sum2 = 0;
uint32 sum3 = 0;
uint8 counter = 0;
extern uint16 LoadCtrl_AnalogVoltValue;
extern uint16 LoadCtrl_AnalogCurrentValue;
extern uint16 LoadCtrl_VrefInt;

void Ain_MainFunction(void);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	aux1 = Ain_Buffer[0];
	aux2 = Ain_Buffer[1];
	aux3 = Ain_Buffer[3];
	counter++;
	sum1 += aux1;
	sum2 += aux2;
	sum3 += aux3;

	if(counter % 100 == 0 && counter != 0)
	{
		counter = 0;
		sum1 /= 100;
		sum2 /= 100;
		sum3 /= 100;
		LoadCtrl_AnalogCurrentValue = sum1;
		LoadCtrl_AnalogVoltValue = sum2;
		LoadCtrl_VrefInt = sum3;
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
	}
	else
	{
		/* Do nothing. */
	}
}
void Ain_MainFunction(void)
{
	if(0 == Ain_MainCounter) HAL_ADCEx_Calibration_Start(&hadc1);
	else if(1 == Ain_MainCounter) HAL_ADC_Start_DMA(&hadc1, Ain_Buffer, 4);
	else
	{
		/* Do nothing. */
	}
	Ain_MainCounter++;
}
