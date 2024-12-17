#include "Std_Types.h"

typedef enum
{
	INIT = 0x00U,
	NO_COMMUNICATION = 0x01U,
	FULL_COMMUNICATION = 0x02U,
	PARTIAL_COMMUNICATION = 0x03U,
	CC_ACTIVE = 0x04U
}CanH_ComStat_t;

extern void CanH_MainFunction(void);
