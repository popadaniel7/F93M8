/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
/* INCLUDE END */
/* DEFINE START */
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
/* Calibration values array. */
extern uint16 Param_Input_Calibration[4];
/* Vehicle speed signal status. */
extern uint8 VehicleSpeed_VehicleState;
/* Wiper stock signal status. */
extern uint8 WiperStock_VehicleState;
/* Input value array. */
extern uint32 StatusList_InputValue[5];
/* Input status array. */
extern InStat StatusList_InputStatus[5];
/* Processed output values array. */
extern uint32 StatusList_OutputValue[5];
/* Processed CAN output values array. */
extern uint8 StatusList_ComOutValue[5];
/* Processed raw output values array. */
extern uint8 StatusList_RawValue[5];
/* Input coding data. */
extern uint32 InputCtrl_CodingData[4];
/* VARIABLES STOP */
/* FUNCTIONS START */
extern void InputCtrl_MainFunction(void);
/* FUNCTIONS STOP */
/* STOP OF FILE */
