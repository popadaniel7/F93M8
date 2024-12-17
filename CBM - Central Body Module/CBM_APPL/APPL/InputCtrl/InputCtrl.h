/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
/* INCLUDE END */
/* DEFINE START */
/* IGNITION ARRAY POSITION */
#define IGN_ARRPOS 0
/* ACCELERATION ARRAY POSITION */
#define ACC_ARRPOS 1
/* BRAKE ARRAY POSITION */
#define BR_ARRPOS 2
/* POWER STEERING ARRAY POSITION */
#define PS_ARRPOS 3
/* GEARBOX ARRAY POSITION */
#define GB_ARRPOS 4
/* LIGHT SENSOR ARRAY POSITION */
#define LSNS_ARRPOS 5
/* RAIN SENSOR ARRAY POSITION */
#define RSNS_ARRPOS 6
/* AIR QUALITY SENSOR ARRAY POSITION */
#define AQSNS_ARRPOS 7
/* GAS SENSOR ARRAY POSITION */
#define GSNS_ARRPOS 8
/* HC05 ARRAY POSITION */
#define HC05_ARRPOS 9
/* IGNITION ARRAY POSITION */
#define STATUS_IGN_ARRPOS 0
/* ACCELERATION ARRAY POSITION */
#define STATUS_ACC_ARRPOS 1
/* BRAKE ARRAY POSITION */
#define STATUS_BR_ARRPOS 2
/* POWER STEERING ARRAY POSITION */
#define STATUS_PS_ARRPOS 3
/* GEARBOX ARRAY POSITION */
#define STATUS_GB_ARRPOS 4
/* LIGHT SENSOR ARRAY POSITION */
#define STATUS_LSNS_ARRPOS 5
/* RAIN SENSOR ARRAY POSITION */
#define STATUS_RSNS_ARRPOS 6
/* AIR QUALITY SENSOR ARRAY POSITION */
#define STATUS_AQSNS_ARRPOS 7
/* GAS SENSOR ARRAY POSITION */
#define STATUS_GSNS_ARRPOS 8
/* HC05 ARRAY POSITION */
#define STATUS_HC05_ARRPOS 9
/* INPUTS NUMBER */
#define INPUT_NUMBER 11
/* INPUTS NUMBER */
#define STATUS_NUMBER 11
/* RAW NUMBER */
#define RAW_INPUTS 9
/* UNDERVOLTAGE CODE */
#define UV_ERRCODE 0x10
/* OUT OF BOUNDS CODE */
#define OOB_ERRCODE 0x20
/* DEFINE STOP */
/* TYPEDEF START */
/* INPUT STATUS STRUCT */
typedef struct
{
	uint8 errorStatus;
	uint8 DCYStatus;
	uint32 debounceTimer_undervoltage;
	uint32 debounceTimer_outofbound;
}InStat;
/* TYPEDEF STOP */
/* VARIABLES START */
/* Under-voltage de-bounce parameterizable variable. */
extern uint8 Param_UndervoltageThreshold_Calibration;
/* De-bounce time parameterizable variable. */
extern uint8 Param_ErrorSettingDebouceThreshold_Calibration;
/* Out of bound value parameterizable variable. */
extern uint16 Param_OutofboundThreshold_Calibration;
/* De-bounce previous state time value parameterizable variable. */
extern uint16 Param_DebouncePreviouState_Calibration;
/* Calibration values array. */
extern uint16 Param_Input_Calibration[INPUT_NUMBER];
/* Lock state signal status. */
extern uint8 LockState_VehicleState;
/* Vehicle speed signal status. */
extern uint8 VehicleSpeed_VehicleState;
/* Wiper stock signal status. */
extern uint8 WiperStock_VehicleState;
/* Input value array. */
extern uint32 StatusList_InputValue[INPUT_NUMBER];
/* Input status array. */
extern InStat StatusList_InputStatus[STATUS_NUMBER];
/* Processed output values array. */
extern uint32 StatusList_OutputValue[INPUT_NUMBER];
/* Processed CAN output values array. */
extern uint8 StatusList_ComOutValue[INPUT_NUMBER];
/* Processed raw output values array. */
extern uint8 StatusList_RawValue[RAW_INPUTS];
/* Input coding data. */
extern uint32 InputCtrl_CodingData[INPUT_NUMBER - 2];
/* VARIABLES STOP */
/* FUNCTIONS START */
extern void InputCtrl_MainFunction(void);
/* FUNCTIONS STOP */
/* STOP OF FILE */
