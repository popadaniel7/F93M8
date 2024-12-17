#include "EcuM.h"
#include "adc.h"
#include "Ain.h"
#include "Nvm.h"
#include "Dem.h"
#include "gpio.h"

__attribute__((section(".ncr"))) uint32 EcuM_ResetCounter[13];
__attribute__((section(".ncr"))) uint32 EcuM_ResetFlag[13];
EcuM_State_t EcuM_State = 0;
uint32 EcuM_MainCounter = 0;
extern uint8 CanH_RequestBusSleep;
extern uint8 Nvm_WriteAllPending;
extern uint8 Nvm_ReadAllPending;
extern uint8 CanH_TxSig_PowerSupplyNetworkWarning;
__attribute__((section(".ncr"))) extern uint32 Dcm_AliveCounter;

void EcuM_MainFunction(void);
void EcuM_PerformReset(uint8 param);
extern void Dem_SetDtc(uint8 IDPrimary, uint32 Reason, uint8 Status);

void EcuM_PerformReset(uint8 param)
{
	__disable_irq();

	Dcm_AliveCounter = 0;

	if(0 != param)
	{
		EcuM_ResetCounter[param]++;
		EcuM_ResetFlag[param] = 1;
	}
	else
	{
		/* Do nothing. */
	}
	__NVIC_SystemReset();
}

void EcuM_MainFunction(void)
{
	if(0 == EcuM_MainCounter)
	{
		for(uint8 i = 0; i < 13; i++)
		{
			if(0 != EcuM_ResetFlag[i])
			{
				Dem_SetDtc(18, i, 1);
				EcuM_ResetFlag[i] = 0;
				break;
			}
			else
			{
				/* Do nothing. */
			}
		}
	}
	else
	{
		/* Do nothing. */
	}
	/* Keep the SW in RUN for at least 10 seconds. */
	if(2000 > EcuM_MainCounter) EcuM_State = 1;
	else
	{
		/* If CAN is in SLEEP, no problem with the supply is reported, and wake-up line is 0. */
		if(1 == CanH_RequestBusSleep && 0 == CanH_TxSig_PowerSupplyNetworkWarning && 0 == HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0))
		{
			/* goto POSTRUN. */
			EcuM_State = 2;
			if(0 == Nvm_WriteAllPending) Nvm_WriteAllPending = 1;
			else
			{
				/* Do nothing. */
			}
		}
		else EcuM_State = 1; /* return to RUN. */
		/* goto SLEEP if POSTRUN and WRITE ALL done. */
		if(2 == EcuM_State && 2 == Nvm_WriteAllPending) EcuM_State = 3;
		else
		{
			/* Do nothing. */
		}
		/* Enter STANDBY. */
		if(3 == EcuM_State)
		{
			__disable_irq();
			HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
			HAL_PWR_EnterSTANDBYMode();
		}
		else
		{
			/* Do nothing. */
		}
	}
	EcuM_MainCounter++;
}
