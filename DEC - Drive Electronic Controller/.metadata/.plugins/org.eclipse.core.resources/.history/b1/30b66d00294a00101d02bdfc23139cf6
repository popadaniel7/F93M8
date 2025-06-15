#include "DcyHandler.h"

static uint32 DcyHandler_MainCounter = 0u;
uint8 DcyHandler_CanRx_IgnitionState = 254u;
uint8 DcyHandler_CanRx_ResetDcy = 0u;
uint8 DcyHandler_CanRx_GearboxState = 0u;
uint8 DcyHandler_CanRx_VehicleSpeed = 0u;
uint8 DcyHandler_CanTx_InVehicleSafetyErrorFlag = 254u;
uint8 DcyHandler_CanRx_RequestDiagnosisMode = 0u;
uint8 DcyHandler_CanRx_StatusDoorLeft = 0u;
uint8 DcyHandler_CanRx_StatusDoorRight = 0u;
DcyHandler_DcyStatus_t DcyHandler_CanTx_DcyStatus = DCY_INIT;
DcyHandler_VehicleState_t DcyHandler_CanTx_VehicleState = VEHSTATE_INIT;

extern uint8 DiagMaster_ResetDcy;

void DcyHandler_MainFunction(void);

void DcyHandler_MainFunction(void)
{
    static uint32 localTimestamp = 0u;

    if(0u == DcyHandler_CanTx_InVehicleSafetyErrorFlag)
    {
        switch(DcyHandler_CanRx_IgnitionState)
        {
            case 0u:
            case 253u:
            case 254u:
                /* Ignition off. */
                if(0u == DcyHandler_CanRx_StatusDoorLeft || 0u == DcyHandler_CanRx_StatusDoorRight)
                {
                    DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
                    DcyHandler_CanTx_VehicleState = VEHSTATE_PARK_IGNITION_OFF;
                }
                else
                {
                    /* Do nothing. */
                }
                break;
            case 1u:
                /* Ignition on. */
                if(0u != DcyHandler_CanRx_StatusDoorLeft || 0u != DcyHandler_CanRx_StatusDoorRight)
                {
                    DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
                    DcyHandler_CanTx_VehicleState = VEHSTATE_PARK_INGITION_ON;
                }
                else
                {
                    /* Do nothing. */
                }
                break;
            case 2u:
            {
                /* Ignition on. */
                switch(DcyHandler_CanRx_GearboxState)
                {
                    case 0u:
                    case 1u:
                        DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
                        DcyHandler_CanTx_VehicleState = VEHSTATE_STANDING;
                        break;
                    case 2u:
                    case 3u:
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
            default:
                break;
        }
    }
    else
    {
        DcyHandler_CanTx_VehicleState = VEHSTATE_VEHICLE_ERROR;
    }

    if(1u <= DcyHandler_CanRx_RequestDiagnosisMode)
    {
        DcyHandler_CanTx_VehicleState = VEHSTATE_VEHICLE_DIAGNOSIS;
        DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
    }
    else
    {
        DcyHandler_CanTx_DcyStatus = DCY_NOTSTARTED;
        DcyHandler_CanTx_VehicleState = VEHSTATE_PARK_INGITION_ON;
    }

    if(1u == DcyHandler_CanRx_ResetDcy)
    {
        DcyHandler_CanTx_DcyStatus = DCY_END;

        if(0u == localTimestamp)
        {
            localTimestamp = DcyHandler_MainCounter;
        }
        else
        {
            if(800u < DcyHandler_MainCounter - localTimestamp)
            {
                DcyHandler_CanRx_ResetDcy = 0u;
                DcyHandler_CanTx_DcyStatus = DCY_INIT;
                DiagMaster_ResetDcy = 0u;
                localTimestamp = 0u;
            }
            else
            {
                /* Do nothing. */
            }
        }
    }
    else
    {
        /* Do nothing. */
    }

    DcyHandler_MainCounter++;
}
