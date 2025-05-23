/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
/* INCLUDE END */
/* TYPEDEF START */
/* VERSION DATA TYPE */
typedef struct
{
	uint8 SoftwareVersion;
	uint8 FlashBootLoaderVersion;
	uint8 CodingVersion;
	uint8 CalibrationVersion;
}SWV;
/* DIAGNOSTIC SESSION DATA TYPE */
typedef enum
{
	DEFAULT = 0U,
	EXTENDED = 1U,
	PROGRAMMING = 2U,
	CODING = 3U,
	CALIBRATION = 4U,
	HARDRESET = 5U,
	SOFTRESET = 6U,
	JUMPTOAPPL = 7U
}DiagState;
/* Function pointer typedef */
typedef void (*Dcm_FuncPtr)();
/* RDBPI data type. */
typedef struct
{
	Dcm_FuncPtr FuncPtr;
}Dcm_RDBPI_Table_t;
/* TYPEDEF STOP */
/* VARIABLES START */
/* Diagnostic session state. */
extern DiagState DiagnosticSession __attribute__((section(".ncr")));
/* VARIABLES STOP */
/* FUNCTIONS START */
extern void Dcm_MainFunction(void);
/* FUNCTIONS STOP */
/* STOP OF FILE */
