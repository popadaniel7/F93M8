#include "Ifx_Types.h"

#define ENCCAL_CODING_SIZE      8U
#define ENCCAL_CALIBRATION_SIZE 8U

extern uint8 EncCal_VODataComplete_Default[80u];
extern uint8 EncCal_VODataComplete[80u];
extern uint8 EncCal_Calibration_Buffer[ENCCAL_CALIBRATION_SIZE];
extern uint8 EncCal_Calibration_DefaultBuffer[ENCCAL_CALIBRATION_SIZE];
extern uint8 EncCal_Calibration_ColDet_StableDistanceCm;
extern uint8 EncCal_Calibration_ColDet_TtcWarn;
extern uint8 EncCal_Calibration_ColDet_TtcBrake;
extern uint8 EncCal_Calibration_ColDet_MinDist;
extern uint8 EncCal_Calibration_ColDet_MaxDist;
extern uint8 EncCal_Calibration_ColDet_InvalidDist;
extern uint8 EncCal_Coding_DefaultBuffer[ENCCAL_CODING_SIZE];
extern uint8 EncCal_Coding_Buffer[ENCCAL_CODING_SIZE];
extern uint8 EncCal_Coding_Hc05;
extern uint8 EncCal_Coding_Hc05Vent;
extern uint8 EncCal_Coding_Lsen;
extern uint8 EncCal_CodingValidResult;
extern uint8 EncCal_CalibrationValidResult;
extern uint8 EncCal_CheckResult_Coding;
extern uint8 EncCal_CheckResult_Calibration;
extern uint8 EncCal_CheckResult_VoData;
extern uint8 EncCal_IsVoDataValid;

extern void EncCal_InitVoData(void);
extern void EncCal_InitCalibration(void);
extern void EncCal_InitCoding(void);
extern uint8 EncCal_CodingValidity(void);
extern uint8 EncCal_CalibrationValidity(void);
extern void EncCal_MainFunction(void);
