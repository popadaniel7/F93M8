#include "Std_Types.h"

typedef enum
{
	STARTUP  = 0,
	RUN = 1,
	POSTRUN = 2,
	SLEEP = 3
}EcuM_State_t;

extern EcuM_State_t EcuM_State;

extern void EcuM_PerformReset(uint8 param);
extern void EcuM_MainFunction(void);
