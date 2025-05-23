/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
/* INCLUDE END */
/* DEFINE START */
/* DEFINE STOP */
/* TYPEDEF START */
typedef enum
{
	STARTUP = 0x00,
	INIT_SEQ = 0x01,
	RUN = 0x02,
	POSTRUN = 0x03,
	PRESLEEP = 0x04
}EcuMStates_t;
typedef enum
{
	NO_RESET = 0x00,
	MALLOC_RESET = 0x22,
	STACKOVERFLOW_RESET = 0x23,
	NMI_RESET = 0x24,
	HARDFAULT_RESET = 0x25,
	MEMMANAGE_RESET = 0x26,
	BUSFAULT_RESET = 0x27,
	USAGEFAULT_RESET = 0x28,
	FPU_RESET = 0x29,
	ERRORHANDLER_RESET = 0x2A,
	OSFAIL_RESET = 0x2B,
	UNDERVOLTAGE_RESET = 0x2C
}EcuMReset_t;
/* TYPEDEF END */
/* VARIABLES START */
extern EcuMStates_t EcuM_State;
extern uint8 EcuM_SleepModeState;
/* VARIABLES END */
/* FUNCTIONS START */
extern void EcuM_MainFunction(void);
extern void EcuM_PerformReset(EcuMReset_t param);
extern void EcuM_ProcessTimerInterrupt(void);
/* FUNCTIONS END */
/* STOP OF FILE */
