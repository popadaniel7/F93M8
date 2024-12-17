/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
/* INCLUDE END */
/* DEFINE START */
/* ACTUATORS NUMBER */
#define ACT_NO 5
/* WINDSHIELD WIPER RIGHT ARRAY POSITION */
#define WWR_ARRPOS 0
/* WINDSHIELD WIPER LEFT ARRAY POSITION */
#define WWL_ARRPOS 1
/* DOOR LOCK LEFT ARRAY POSITION */
#define DLL_ARRPOS 2
/* DOOR LOCK RIGHT ARRAY POSITION */
#define DLR_ARRPOS 3
/* CLIMATE FAN ARRAY POSITION */
#define CLIMA_ARRPOS 4
/* DEFINE STOP */
/* VARIABLES START */
extern uint8 Param_DoorLockPwmIncrement;
/* Variable used as coding option for how long to wash the windshield. */
extern uint8 WindshieldWashing_CodingData;
extern uint8 WashingWipingCounter_CodingData;
/* Variable used as coefficient when changing wiper PWM for slow mode. */
extern uint8 Param_WindshieldWiperSlow_Calibration;
/* Variable used as coefficient when changing wiper PWM for fast mode. */
extern uint8 Param_WindshieldWiperFast_Calibration;
/* Variable used to determine the time period of wiper interval. */
extern uint16 WiperDelay_Vector[2][6][1];
/* Variable used for speed intervals based on which the wiper actuate. */
extern uint8 WiperSpeed_Vector[5];
/* Variable used to store PWM value of actuators. */
extern uint8 CmdList_RawValue[ACT_NO];
/* Variable used to send on CAN the status of actuators. */
extern uint8 CmdList_ActualValue[ACT_NO];
/* VARIABLES END */
/* FUNCTIONS START */
extern void ActCtrl_MainFunction(void);
/* FUNCTIONS END */
/* STOP OF FILE */
