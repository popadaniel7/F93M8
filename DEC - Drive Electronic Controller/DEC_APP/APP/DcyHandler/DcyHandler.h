#include "Ifx_Types.h"

typedef enum
{
    DCY_INIT = 255U,
    DCY_ERROR = 254U,
    DCY_NOTSTARTED = 1U,
    DCY_START = 2U,
    DCY_END = 3U
}DcyHandler_DcyStatus_t;

typedef enum
{
    VEHSTATE_INIT = 255U,
    VEHSTATE_ERROR = 254U,
    VEHSTATE_PARK_IGNITION_OFF = 1U,
    VEHSTATE_PARK_INGITION_ON = 2U,
    VEHSTATE_STANDING = 3U,
    VEHSTATE_PRE_DRIVE_CHECK = 4U,
    VEHSTATE_DRIVING = 5U,
    VEHSTATE_VEHICLE_ERROR = 6U,
    VEHSTATE_VEHICLE_DIAGNOSIS = 8U
}DcyHandler_VehicleState_t;

extern uint8 DcyHandler_CanRx_IgnitionState;
extern uint8 DcyHandler_CanRx_ResetDcy;
extern uint8 DcyHandler_CanRx_GearboxState;
extern uint8 DcyHandler_CanRx_VehicleSpeed;
extern uint8 DcyHandler_CanTx_InVehicleSafetyErrorFlag;
extern uint8 DcyHandler_CanRx_TesterPresentStatus;
extern uint8 DcyHandler_CanRx_RequestDiagnosisMode;
extern DcyHandler_DcyStatus_t DcyHandler_CanTx_DcyStatus;
extern DcyHandler_VehicleState_t DcyHandler_CanTx_VehicleState;

extern void DcyHandler_MainFunction(void);
