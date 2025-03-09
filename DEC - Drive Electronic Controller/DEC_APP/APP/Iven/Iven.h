#include "Ifx_Types.h"

#define IVEN_ICM_NUMBER_OF_MESSAGES 9U
#define IVEN_ICMID1     0U
#define IVEN_ICMID2     1U
#define IVEN_ICMID28    2U
#define IVEN_ICMID32    3U
#define IVEN_ICMID33    4U
#define IVEN_ICMID34    5U
#define IVEN_ICMID35    6U
#define IVEN_ICMID37    7U
#define IVEN_ICMID41    8U

typedef struct
{
        uint8 messageStatus;
        uint8 messageCount;
        uint8 padding1;
        uint8 padding2;
}Iven_IcmTable_t;

extern Iven_IcmTable_t Iven_IcmLookupTable[IVEN_ICM_NUMBER_OF_MESSAGES];
extern uint8 Iven_CanTx_IcmId;
extern uint8 Iven_StatusDriveControlMessageState;
extern uint8 Iven_StatusActuatorMessageState;
extern uint8 Iven_CanRx_StatusDoorLeft;
extern uint8 Iven_CanRx_StatusDoorRight;
extern uint8 Iven_CanRx_GearboxControl;
extern uint8 Iven_CanRx_IgnitionControl;
extern uint8 Iven_CanTx_IrSenStat;
extern uint8 Iven_CanRx_ErrorDetectedCbm;
extern uint8 Iven_CanTx_InVehicleSafetyError;
extern uint8 Iven_CanTx_DecMcuError;
extern uint8 Iven_CanTx_DiagnosticMode;
extern uint8 Iven_CanRx_SafeDriveTrainStatusMessageState;
extern uint8 Iven_CanRx_SdtsDriveTrainStatus;

extern void Iven_MainFunction(void);
