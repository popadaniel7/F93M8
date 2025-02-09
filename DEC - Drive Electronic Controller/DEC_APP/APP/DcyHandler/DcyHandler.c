#include "DcyHandler.h"

static uint32 DcyHandler_MainCounter = 0u;
uint8 DcyHandler_CanRx_IgnitionState = 255u;
uint8 DcyHandler_CanRx_ResetDcy = 255u;
uint8 DcyHandler_CanRx_GearboxState = 255u;
uint8 DcyHandler_CanRx_VehicleSpeed = 255u;
uint8 DcyHandler_CanTx_InVehicleSafetyErrorFlag = 255u;
uint8 DcyHandler_CanRx_TesterPresentStatus = 255u;
uint8 DcyHandler_CanRx_RequestDiagnosisMode = 255u;
DcyHandler_DcyStatus_t DcyHandler_CanTx_DcyStatus = DCY_INIT;
DcyHandler_VehicleState_t DcyHandler_CanTx_VehicleState = VEHSTATE_INIT;

void DcyHandler_MainFunction(void);

void DcyHandler_MainFunction(void)
{
    if(0u == DcyHandler_CanTx_InVehicleSafetyErrorFlag)
    {
        switch(DcyHandler_CanRx_IgnitionState)
        {
            case 255u:
                /* initial value, DCY cannot be processed. */
                DcyHandler_CanTx_DcyStatus = DCY_INIT;
                DcyHandler_CanTx_VehicleState = VEHSTATE_INIT;
                break;
            case 254u:
                /* error value, DCY cannot be processed. */
                DcyHandler_CanTx_DcyStatus = DCY_ERROR;
                DcyHandler_CanTx_VehicleState = VEHSTATE_ERROR;
                break;
            case 0u:
                /* Ignition off. */
                DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
                DcyHandler_CanTx_VehicleState = VEHSTATE_PARK_IGNITION_OFF;
                break;
            case 1u:
                /* Ignition on. */
                DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
                DcyHandler_CanTx_VehicleState = VEHSTATE_PARK_INGITION_ON;
                break;
            case 2u:
            {
                /* Ignition on. */
                switch(DcyHandler_CanRx_GearboxState)
                {
                    case 255u:
                        break;
                    case 254u:
                        break;
                    case 0u:
                        DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
                        DcyHandler_CanTx_VehicleState = VEHSTATE_PRE_DRIVE_CHECK;
                        break;
                    case 1u:
                        DcyHandler_CanTx_DcyStatus = DCY_START;
                        if(1u <= DcyHandler_CanRx_VehicleSpeed)
                        {
                            DcyHandler_CanTx_VehicleState = VEHSTATE_DRIVING;
                        }
                        else
                        {
                            DcyHandler_CanTx_VehicleState = VEHSTATE_STANDING;
                        }
                        break;
                    case 2u:
                        DcyHandler_CanTx_DcyStatus = DCY_START;
                        if(1u <= DcyHandler_CanRx_VehicleSpeed)
                        {
                            DcyHandler_CanTx_VehicleState = VEHSTATE_DRIVING;
                        }
                        else
                        {
                            DcyHandler_CanTx_VehicleState = VEHSTATE_STANDING;
                        }
                        break;
                    default:
                        break;
                }
                break;
            }
            case 3u:
                DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
                DcyHandler_CanTx_VehicleState = VEHSTATE_POST_DRIVE_CHECK;
                break;
            default:
                break;
        }
    }
    else
    {
        DcyHandler_CanTx_VehicleState = VEHSTATE_VEHICLE_ERROR;
    }

    if(1u == DcyHandler_CanRx_RequestDiagnosisMode)
    {
        DcyHandler_CanTx_VehicleState = VEHSTATE_VEHICLE_DIAGNOSIS;
        DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
    }
    else
    {
        /* Do nothing. */
    }

    if(1u == DcyHandler_CanRx_ResetDcy)
    {
        DcyHandler_CanTx_DcyStatus = DCY_END;
    }
    else
    {
        /* Do nothing. */
    }

    DcyHandler_MainCounter++;
}
