#include "Ifx_Types.h"

#define IVEN_ICM_NUMBER_OF_MESSAGES 17U
#define IVEN_ICMID1     0U
#define IVEN_ICMID2     1U
#define IVEN_ICMID13    2U
#define IVEN_ICMID25    3U
#define IVEN_ICMID26    4U
#define IVEN_ICMID27    5U
#define IVEN_ICMID28    6U
#define IVEN_ICMID29    7U
#define IVEN_ICMID30    8U
#define IVEN_ICMID31    9U
#define IVEN_ICMID32    10U
#define IVEN_ICMID33    11U
#define IVEN_ICMID34    12U
#define IVEN_ICMID35    13U
#define IVEN_ICMID37    14U
#define IVEN_ICMID40    15U
#define IVEN_ICMID41    16U

typedef struct
{
        uint8 messageStatus;
        uint8 messageCount;
}Iven_IcmTable_t;

extern Iven_IcmTable_t Iven_IcmLookupTable[IVEN_ICM_NUMBER_OF_MESSAGES];
extern uint8 Iven_CanTx_IcmId;
extern uint8 Iven_StatusDriveControlMessageState;
extern uint8 Iven_StatusLoadListMessageState;
extern uint8 Iven_StatusPowerSupplyNetworkMessageState;
extern uint8 Iven_CanRx_PSNWarn;
extern uint8 Iven_CanRx_CurrentConsumption;
extern uint8 Iven_CanRx_CurrentConsumption2;
extern uint8 Iven_CanRx_MeasuredVoltageSupply;
extern uint8 Iven_StatusActuatorMessageState;
extern uint8 Iven_CanRx_StatusDoorLeft;
extern uint8 Iven_CanRx_StatusDoorRight;
extern uint8 Iven_CanRx_PowerSteeringControl;
extern uint8 Iven_CanRx_GearboxControl;
extern uint8 Iven_CanRx_AccelerationControl;
extern uint8 Iven_CanRx_BrakeControl;
extern uint8 Iven_CanRx_IgnitionControl;
extern uint8 Iven_CanTx_PowerSteeringStatus;
extern uint8 Iven_CanTx_IrSenStat;
extern uint8 Iven_CanTx_PowerSteeringFanStatus;
extern uint8 Iven_CanTx_EMotorStatus;
extern uint8 Iven_CanTx_SpeedSensorStatus;
extern uint8 Iven_CanTx_TempSenPSteering;
extern uint8 Iven_CanRx_ErrorDetectedCbm;
extern uint8 Iven_CanRx_ErrorDetectedPdm;
extern uint8 Iven_CanTx_InVehicleSafetyError;
extern uint8 Iven_CanTx_DecMcuError;
extern uint8 Iven_CanTx_DiagnosticMode;

extern void Iven_MainFunction(void);
