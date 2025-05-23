#include "DiagMaster.h"
#include "Dcm.h"

DiagMaster_DiagReq_t DiagMaster_Receive_DiagnosticMessageBuffer[50u];
DiagMaster_DiagReq_t DiagMaster_Transmit_DiagnosticMessageBuffer[50u];
uint8 DiagMaster_701SessionState = 1u;
uint8 DiagMaster_703SessionState = 1u;
uint16 DiagMaster_Is701Active = 0u;
uint16 DiagMaster_Is703Active = 0u;
uint16 DiagMaster_IsMasterActive = 1u;
uint16 DiagMaster_ActiveId = 0u;
uint8 DiagMaster_DiagnosticModeActivated = 0u;
uint8 DiagMaster_TesterPresentActive = 0u;
uint8 DiagMaster_RequestDiagnosticMode = 0u;
uint8 DiagMaster_GearboxStatus = 0u;
uint8 DiagMaster_VehicleSpeed = 0u;
uint32 DiagMaster_Rx_DiagBufCnt = 0u;
uint8 DiagMaster_ResetDcy = 0u;
extern uint32 DiagMaster_AliveTime;
extern uint8 DiagMaster_ActiveSessionState;
extern uint32 Dcm_Rx_DiagBufCnt;
static uint32 DiagMaster_MainCounter = 0u;

void DiagMaster_MainFunction(void);

void DiagMaster_MainFunction(void)
{
    DiagMaster_AliveTime++;

    if(0u == DiagMaster_MainCounter)
    {
        DiagMaster_ActiveSessionState = 1u;
    }
    else
    {
        /* Do nothing. */
    }

    if((6u > DiagMaster_VehicleSpeed)
            && (1u == DiagMaster_RequestDiagnosticMode)
            && (0u == DiagMaster_GearboxStatus || 1u == DiagMaster_GearboxStatus)
            && (1u == DiagMaster_TesterPresentActive)
            && (3u == DiagMaster_ActiveSessionState))
    {
        DiagMaster_DiagnosticModeActivated = 2u;
    }
    else  if((1u == DiagMaster_RequestDiagnosticMode)
            && (1u == DiagMaster_TesterPresentActive)
            && (3u == DiagMaster_ActiveSessionState))
    {
        DiagMaster_DiagnosticModeActivated = 1u;
    }
    else
    {
        DiagMaster_DiagnosticModeActivated = 0u;
    }

    if(1u == DiagMaster_Is701Active)
    {
        DiagMaster_ActiveId = 0x701u;
    }
    else
    {
        /* Do nothing. */
    }

    if(1u == DiagMaster_Is703Active)
    {
        DiagMaster_ActiveId = 0x703u;
    }
    else
    {
        /* Do nothing. */
    }

    if(1u == DiagMaster_IsMasterActive)
    {
        DiagMaster_ActiveId = 0x6FFu;
    }
    else
    {
        /* Do nothing. */
    }

    for(uint8 i = 0u; i < DiagMaster_Rx_DiagBufCnt; i++)
    {
        if(0x6FEU == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
        {
            if((0x03u <= DiagMaster_ActiveSessionState) && (0x01u <= DiagMaster_DiagnosticModeActivated))
            {
                if(0x04u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u] &&
                        0x31 == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u] &&
                        0x22 == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[4u])
                {
                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 24u;
                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                    DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_REQUEST_TYPE;
                    DiagMaster_ActiveId = 0x6FFU;
                    DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x6FFu;
                    break;
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else
            {
                /* Do nothing. */
            }

            DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_REQUEST_TYPE;
        }
        else
        {
            /* Do nothing. */
        }

        /* Request for master */
        if(0x6FFu == DiagMaster_ActiveId)
        {
            /* Request for master, no master processing required for slave ECUs. */
            DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x6FFu;

            if(0x10u <= DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u])
            {
                DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_ISOTPRXTX_TYPE;
            }
            else
            {
                switch(DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u])
                {
                    case 0x10u:
                    {
                        switch(DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                        {
                            case 0x01u:
                            case 0x03u:
                                DiagMaster_ActiveSessionState = (uint8)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId =
                                        (uint8)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] - 1u;
                                break;
                            case 0x02u:
                            case 0x04u:
                            case 0x05u:
                                if(0x03u == DiagMaster_ActiveSessionState && 0x01u <= DiagMaster_DiagnosticModeActivated)
                                {
                                    DiagMaster_ActiveSessionState = (uint8)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId =
                                            (uint8)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] - 1u;
                                }
                                else
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    }
                    case 0x11u:
                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                        if(0x01u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 0x05u;
                        }
                        else if(0x03 == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 0x06u;
                        }
                        else
                        {
                            /* Do nothing. */
                        }
                        break;
                    case 0x14u:
                        if((0x01u == DiagMaster_DiagnosticModeActivated) || (0x02u == DiagMaster_DiagnosticModeActivated))
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 9u;
                        }
                        else
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                        }
                        break;
                    case 0x19u:
                        if((0x01u == DiagMaster_DiagnosticModeActivated) || (0x02u == DiagMaster_DiagnosticModeActivated))
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 8u;
                        }
                        else
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                        }
                        break;
                    case 0x3eu:
                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                        DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 7u;
                        break;
                    case 0x28u:
                        if((0x03u == DiagMaster_ActiveSessionState) && ((0x01u == DiagMaster_DiagnosticModeActivated) || (0x02u == DiagMaster_DiagnosticModeActivated)))
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 10u;
                        }
                        else
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                        }
                        break;
                    case 0x85u:
                        if((0x03u == DiagMaster_ActiveSessionState) && ((0x01u == DiagMaster_DiagnosticModeActivated) || (0x02u == DiagMaster_DiagnosticModeActivated)))
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 11u;
                        }
                        else
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                        }
                        break;
                    case 0x22u:
                    {
                        switch(DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[3u])
                        {
                            case 0x05u:
                            {
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 21u;
                                break;
                            }
                            case 0x80u:
                            {
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 19u;
                                break;
                            }
                            case 0x86u:
                            {
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId  = 20u;
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    }
                    case 0x2A:
                        if((0x03u == DiagMaster_ActiveSessionState) && ((0x01u == DiagMaster_DiagnosticModeActivated) || (0x02u == DiagMaster_DiagnosticModeActivated)))
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                        }
                        else
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                        }
                        break;
                    case 0x2E:
                        if((0x03u == DiagMaster_ActiveSessionState) && ((0x01u == DiagMaster_DiagnosticModeActivated) || (0x02u == DiagMaster_DiagnosticModeActivated)))
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                        }
                        else
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                        }
                        break;
                    case 0x31:
                        if((0x03u <= DiagMaster_ActiveSessionState) && ((0x01u == DiagMaster_DiagnosticModeActivated) || (0x02u == DiagMaster_DiagnosticModeActivated)))
                        {
                            switch(DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[4u])
                            {
                                case 0x04u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 13u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x14u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 13u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x05u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 14u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x15u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 15u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x06u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 16u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x16u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 17u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x20u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 22u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x21u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 23u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x22u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 24u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                case 0x23u:
                                {
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 25u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                }
                                default:
                                    break;
                            }
                        }
                        else
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                        }

                        if(DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[4u] == 0x99u)
                        {
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                            DiagMaster_Receive_DiagnosticMessageBuffer[i].masterDiagReqId = 18u;
                        }
                        else
                        {
                            /* Do nothing. */
                        }
                        break;
                    default:
                        break;
                }

                DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_REQUEST_TYPE;
            }
        }
        else
        {
            if(1u <= DiagMaster_DiagnosticModeActivated)
            {
                if(0x10u <= DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u])
                {
                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                    DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_ISOTPRXTX_TYPE;

                    switch(DiagMaster_ActiveId)
                    {
                        case 0x701u:
                            if(0x6FEu == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Tester requests via Master the 0x701 slave. */
                                /* Content of the UDS pay-load is decided by the tester. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x700u;
                            }
                            else if(0x701u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Slave 0x701 responded to the tester request via Master. */
                                /* Content of the UDS pay-load is decided by the slave. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x6FFu;
                            }
                            else
                            {
                                /* Do nothing. */
                            }
                            break;
                        case 0x703:
                            if(0x6FEu == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Tester requests via Master the 0x703 slave. */
                                /* Content of the UDS pay-load is decided by the tester. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x702u;
                            }
                            else if(0x703u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Slave 0x703 responded to the tester request via Master. */
                                /* Content of the UDS pay-load is decided by the slave. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x6FFu;
                            }
                            else
                            {
                                /* Do nothing. */
                            }
                            break;
                        default:
                            break;
                    }
                }
                else
                {
                    switch(DiagMaster_ActiveId)
                    {
                        case 0x701u:
                        {
                            if(0x6FEu == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Tester requests via Master the 0x701 slave. */
                                /* Content of the UDS pay-load is decided by the tester. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x700u;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_SENDASIS_TYPE;
                            }
                            else if(0x701u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Slave 0x701 responded to the tester request via Master. */
                                /* Content of the UDS pay-load is decided by the slave. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x6FFU;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_SENDASIS_TYPE;
                            }
                            else
                            {
                                /* Do nothing. */
                            }

                            switch(DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u])
                            {
                                case 0x10u:
                                    if(0x01u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x03u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        DiagMaster_701SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else if(0x02u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x04u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x05u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        if((0x01u != DiagMaster_701SessionState) && (0x00u != DiagMaster_701SessionState))
                                        {
                                            DiagMaster_701SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                        }
                                        else
                                        {
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                        }
                                    }
                                    else
                                    {
                                        /* Do nothing. */
                                    }
                                    break;
                                case 0x11u:
                                    DiagMaster_701SessionState = 0x01u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x28u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x3E:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x85u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x22u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x2Au:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x2Eu:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x14u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x19u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x31u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x34u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x36u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x37u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x50u:
                                    if(0x01u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x03u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        DiagMaster_701SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else if(0x02 == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x04 == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x05 == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        if((0x01u != DiagMaster_701SessionState) && (0x00u != DiagMaster_701SessionState))
                                        {
                                            DiagMaster_701SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                        }
                                        else
                                        {
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                        }
                                    }
                                    else
                                    {
                                        /* Do nothing. */
                                    }
                                    break;
                                case 0x51u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    DiagMaster_701SessionState = 1u;
                                    break;
                                case 0x68u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x7Eu:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0xc5u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x62u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x6Au:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x6Eu:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x54u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x59u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x71u:
                                    if(2u <= DiagMaster_701SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x74u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x76u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x77u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                default:
                                    break;
                            }
                            break;
                        }
                        case 0x703:
                        {
                            if(0x6FEu == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Tester requests via Master the 0x701 slave. */
                                /* Content of the UDS pay-load is decided by the tester. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x702u;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_SENDASIS_TYPE;
                            }
                            else if(0x703u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId)
                            {
                                /* Slave 0x701 responded to the tester request via Master. */
                                /* Content of the UDS pay-load is decided by the slave. Master only forwards the request according to rules. */
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId = 0x6FFU;
                                DiagMaster_Receive_DiagnosticMessageBuffer[i].msgType = DIAGMASTER_SENDASIS_TYPE;
                            }
                            else
                            {
                                /* Do nothing. */
                            }

                            switch(DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u])
                            {
                                case 0x10u:
                                    if(0x01u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x03u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        DiagMaster_703SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else if(0x02u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x04u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x05u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        if((0x01u != DiagMaster_703SessionState) && (0x00u != DiagMaster_703SessionState))
                                        {
                                            DiagMaster_703SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                        }
                                        else
                                        {
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                        }
                                    }
                                    else
                                    {
                                        /* Do nothing. */
                                    }
                                    break;
                                case 0x11u:
                                    DiagMaster_703SessionState = 0x01u;
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x28u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x3E:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x85u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x22u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x2Au:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x2Eu:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x14u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x19u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x31u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x34u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x36u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x37u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x50u:
                                    if(0x01u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x03u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        DiagMaster_703SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else if(0x02u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x04u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] ||
                                            0x05u == DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u])
                                    {
                                        if((0x01u != DiagMaster_703SessionState) && (0x00u != DiagMaster_703SessionState))
                                        {
                                            DiagMaster_703SessionState = (uint16)DiagMaster_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u];
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                        }
                                        else
                                        {
                                            DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                        }
                                    }
                                    else
                                    {
                                        /* Do nothing. */
                                    }
                                    break;
                                case 0x51u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    DiagMaster_703SessionState = 1u;
                                    break;
                                case 0x68u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x7Eu:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0xc5u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x62u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x6Au:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x6Eu:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x54u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x59u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x71u:
                                    if(2u <= DiagMaster_703SessionState)
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    }
                                    else
                                    {
                                        DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
                                    }
                                    break;
                                case 0x74u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x76u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                case 0x77u:
                                    DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 1u;
                                    break;
                                default:
                                    break;
                            }
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                DiagMaster_Receive_DiagnosticMessageBuffer[i].isAllowed = 0u;
            }
        }
    }

    IfxCpu_disableInterrupts();
    memcpy(&DiagMaster_Transmit_DiagnosticMessageBuffer,
            &DiagMaster_Receive_DiagnosticMessageBuffer,
            sizeof(DiagMaster_Receive_DiagnosticMessageBuffer));
    memset(&DiagMaster_Receive_DiagnosticMessageBuffer,
            0u,
            sizeof(DiagMaster_Receive_DiagnosticMessageBuffer));
    Dcm_Rx_DiagBufCnt = DiagMaster_Rx_DiagBufCnt;
    DiagMaster_Rx_DiagBufCnt = 0u;
    IfxCpu_enableInterrupts();

    DiagMaster_MainCounter++;
}
