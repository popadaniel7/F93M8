#include "Dcm.h"
#include "DiagMaster.h"
#include "ComMaster.h"
#include "string.h"
#include "EncCal.h"
#include "McuSm.h"
#include "Dem.h"
#include "DcyHandler.h"
#include "Nvm.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

void Dcm_MainFunction(void);
void Dcm_DSC_DefaultSession(uint8* data);
void Dcm_DSC_ProgrammingSession(uint8* data);
void Dcm_DSC_ExtendedSession(uint8* data);
void Dcm_DSC_CodingSession(uint8* data);
void Dcm_DSC_CalibrationSession(uint8* data);
void Dcm_ER_HardReset(uint8* data);
void Dcm_ER_SoftReset(uint8* data);
void Dcm_TP_TesterPresent(uint8* data);
void Dcm_RDTCI_ReadSupportDTCInformation(uint8* data);
void Dcm_CDTCI_ClearDTCInformation(uint8* data);
void Dcm_CC_CommunicationControl(uint8* data);
void Dcm_CDTCS_ControlDTCSetting(uint8* data);
void Dcm_RC_WriteCoding(uint8* data);
void Dcm_RC_ReadCoding(uint8* data);
void Dcm_RC_WriteCalibration(uint8* data);
void Dcm_RC_ReadCalibration(uint8* data);
void Dcm_RC_WriteVOData(uint8* data);
void Dcm_RC_ReadVOData(uint8* data);
void Dcm_RC_RequestDiagnosticModeActive(uint8* data);
void Dcm_RDBI_AliveTime(uint8* data);
void Dcm_RDBI_SWVersion(uint8* data);
void Dcm_RDBI_ActiveDiagnosticSession(uint8* data);
void Dcm_RC_Request701Active(uint8* data);
void Dcm_RC_Request703Active(uint8* data);
void Dcm_RC_RequestMasterActive(uint8* data);
void Dcm_RC_ResetDcy(uint8* data);
void Dcm_ProcessDiagnosticRequest(const uint8 *data, uint16 length);

typedef struct
{
        Can_RxMsg_t diagnosticMessage;
        uint8 isAllowed;
        uint8 msgType;
        uint8 masterDiagReqId;
}Dcm_DiagReq_t;

typedef void (*FuncPtr_t)(uint8*);

uint32 Dcm_Rx_DiagBufCnt = 0u;
uint32 Dcm_MainCounter = 0u;
Dcm_DiagReq_t Dcm_Receive_DiagnosticMessageBuffer[50u];
uint16 respLen_read = 0u;
uint8 Dcm_SwitchTxOff = 0u;
uint8 response_write[4u] = {0u};
uint8 response_dtc[2u + DEM_NUMBER_OF_DTCS];
uint8 response_read[sizeof(EncCal_VODataComplete) + 4u] = {0u};
uint8 Dcm_SwVersion[4u] =
{
        2u, // FLASH BOOTLOADER
        2u, // APPLICATION
        2u, // CODING
        2u  // CALIBRATION
};

extern uint8 storedData_04[ENCCAL_CODING_SIZE];
extern uint8 storedData_05[ENCCAL_CALIBRATION_SIZE];
extern uint8 storedData_06[sizeof(EncCal_VODataComplete)];

FuncPtr_t Dcm_FuncPtr[26u] =
{
        Dcm_DSC_DefaultSession,
        Dcm_DSC_ProgrammingSession,
        Dcm_DSC_ExtendedSession,
        Dcm_DSC_CodingSession,
        Dcm_DSC_CalibrationSession,
        Dcm_ER_HardReset,
        Dcm_ER_SoftReset,
        Dcm_TP_TesterPresent,
        Dcm_RDTCI_ReadSupportDTCInformation,
        Dcm_CDTCI_ClearDTCInformation,
        Dcm_CC_CommunicationControl,
        Dcm_CDTCS_ControlDTCSetting,
        Dcm_RC_WriteCoding,
        Dcm_RC_ReadCoding,
        Dcm_RC_WriteCalibration,
        Dcm_RC_ReadCalibration,
        Dcm_RC_WriteVOData,
        Dcm_RC_ReadVOData,
        Dcm_RC_RequestDiagnosticModeActive,
        Dcm_RDBI_SWVersion,
        Dcm_RDBI_ActiveDiagnosticSession,
        Dcm_RDBI_AliveTime,
        Dcm_RC_Request701Active,
        Dcm_RC_Request703Active,
        Dcm_RC_RequestMasterActive,
        Dcm_RC_ResetDcy
};

void Dcm_MainFunction(void)
{
    static uint8 localData = 0u;
    /* Copy data in exclusive area. */
    IfxCpu_disableInterrupts();
    memcpy(&Dcm_Receive_DiagnosticMessageBuffer,
            &DiagMaster_Transmit_DiagnosticMessageBuffer,
            sizeof(DiagMaster_Transmit_DiagnosticMessageBuffer));
    memset(&DiagMaster_Transmit_DiagnosticMessageBuffer,
            0u,
            sizeof(DiagMaster_Transmit_DiagnosticMessageBuffer));
    IfxCpu_enableInterrupts();
    /* Process the queue. */
    for(uint8 i = 0u; i < Dcm_Rx_DiagBufCnt; i++)
    {
        /* Check if the request is for master only. */
        if(0x6FFu == DiagMaster_ActiveId)
        {
            /* Process master response. */
            if(1u == Dcm_Receive_DiagnosticMessageBuffer[i].isAllowed)
            {
                Dcm_FuncPtr[Dcm_Receive_DiagnosticMessageBuffer[i].masterDiagReqId]((uint8*)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData);
                Can_IsoTp_SendFrame((uint16)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId,
                        (uint8*)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData,
                        ((Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u] & 0x0Fu) + 1u));                
            }
            else
            {
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u] = 0x03u;
                localData = (uint8)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u];
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u] = 0x7Fu;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] = localData;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[3u] = 0x22u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[4u] = 0u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[5u] = 0u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[6u] = 0u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[7u] = 0u;

                Can_IsoTp_SendFrame((uint16)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId,
                        (uint8*)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData,
                        ((Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u] & 0x0Fu) + 1u));
            }
        }
        else
        {
            /* Check if we are allowed to respond to the tester. */
            if(1u == Dcm_Receive_DiagnosticMessageBuffer[i].isAllowed)
            {
                Can_IsoTp_SendFrame((uint16)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId,
                        (uint8*)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData,
                        ((Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u] & 0x0Fu) + 1u));
            }
            else
            {
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u] = 0x03u;
                localData = (uint8)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u];
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[1u] = 0x7Fu;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[2u] = localData;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[3u] = 0u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[4u] = 0u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[5u] = 0u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[6u] = 0u;
                Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[7u] = 0u;

                Can_IsoTp_SendFrame((uint16)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxMsg.messageId,
                        (uint8*)Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData,
                        ((Dcm_Receive_DiagnosticMessageBuffer[i].diagnosticMessage.rxData[0u] & 0x0Fu) + 1u));
            }
        }
        localData = 0u;
    }
    memset(&Dcm_Receive_DiagnosticMessageBuffer, 0u, sizeof(Dcm_Receive_DiagnosticMessageBuffer));
    Dcm_MainCounter++;
}

void Dcm_DSC_DefaultSession(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    DiagMaster_ActiveSessionState = 1u;
}

void Dcm_DSC_ProgrammingSession(uint8* data)
{
    (void)data;
    DiagMaster_ActiveSessionState = 2u;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.dataLengthCode = IfxCan_DataLengthCode_3;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.messageId = 0x6FFU;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[0u] = 0x02u;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[1u] = 0x50u;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[2u] = 0x02u;
    Can_IsoTp_SendFrame((uint16)Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.messageId,
            (uint8*)Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData,
            ((Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[0u] & 0x0Fu) + 1u));
    Nvm_WriteAll();
    McuSm_PerformResetHook(0xDFDFu, 0u);
}

void Dcm_DSC_ExtendedSession(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    DiagMaster_ActiveSessionState = 3u;
}
void Dcm_DSC_CodingSession(uint8* data){/*empty*/}
void Dcm_DSC_CalibrationSession(uint8* data){/*empty*/}
void Dcm_ER_HardReset(uint8* data)
{
    (void)data;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.dataLengthCode = IfxCan_DataLengthCode_3;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.messageId = 0x6FFU;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[0u] = 0x02u;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[1u] = 0x51u;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[2u] = 0x01u;
    Can_IsoTp_SendFrame((uint16)Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.messageId,
            (uint8*)Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData,
            ((Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[0u] & 0x0Fu) + 1u));
    Nvm_WriteAll();
    McuSm_PerformResetHook(0xDFDFu, 0u);
}

void Dcm_ER_SoftReset(uint8* data)
{
    (void)data;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.dataLengthCode = IfxCan_DataLengthCode_3;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.messageId = 0x6FFU;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[0u] = 0x02u;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[1u] = 0x51u;
    Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[2u] = 0x03u;
    Can_IsoTp_SendFrame((uint16)Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxMsg.messageId,
            (uint8*)Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData,
            ((Dcm_Receive_DiagnosticMessageBuffer[0u].diagnosticMessage.rxData[0u] & 0x0Fu) + 1u));
    Nvm_WriteAll();
    McuSm_PerformResetHook(0xDFDFu, 0u);
}

void Dcm_TP_TesterPresent(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    DiagMaster_TesterPresentActive = 1u;
}
void Dcm_RDTCI_ReadSupportDTCInformation(uint8* data){/*empty*/}
void Dcm_CDTCI_ClearDTCInformation(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    Dem_ClearDtc();
}

void Dcm_CC_CommunicationControl(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    if(1u == data[2u])
    {
        Dcm_SwitchTxOff = 0u;
    }
    else if(0u == data[2u])
    {
        Dcm_SwitchTxOff = 1u;
    }
    else
    {
        /* Do nothing. */
    }
}

void Dcm_CDTCS_ControlDTCSetting(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    if(1u == data[2u])
    {
        Dem_ControlDtcSetting = 1u;
    }
    else if(2u == data[2u])
    {
        Dem_ControlDtcSetting = 0u;
    }
    else
    {
        /* Do nothing. */
    }
}
void Dcm_RC_WriteCoding(uint8* data){/*empty*/}
void Dcm_RC_ReadCoding(uint8* data){/*empty*/}
void Dcm_RC_WriteCalibration(uint8* data){/*empty*/}
void Dcm_RC_ReadCalibration(uint8* data){/*empty*/}
void Dcm_RC_WriteVOData(uint8* data){/*empty*/}
void Dcm_RC_ReadVOData(uint8* data){/*empty*/}
void Dcm_RC_RequestDiagnosticModeActive(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    if(data[5u] == 1u)
    {
        DiagMaster_RequestDiagnosticMode = 0u;
    }
    else
    {
        DiagMaster_RequestDiagnosticMode = 1u;
    }
}

void Dcm_RDBI_AliveTime(uint8* data)
{
    data[0u] = data[0u] + 0x04u;
    data[1u] = data[1u] + 0x40u;
    data[4u] = (uint8)(DiagMaster_AliveTime >> 24u);
    data[5u] = (uint8)(DiagMaster_AliveTime >> 16u);
    data[6u] = (uint8)(DiagMaster_AliveTime >> 8u);
    data[7u] = (uint8)DiagMaster_AliveTime;
}

void Dcm_RDBI_SWVersion(uint8* data)
{
    data[0u] = data[0u] + 0x04u;
    data[1u] = data[1u] + 0x40u;
    data[4u] = Dcm_SwVersion[0u];
    data[5u] = Dcm_SwVersion[1u];
    data[6u] = Dcm_SwVersion[2u];
    data[7u] = Dcm_SwVersion[3u];
}

void Dcm_RDBI_ActiveDiagnosticSession(uint8* data)
{
    data[0u] = data[0u] + 0x01u;
    data[1u] = data[1u] + 0x40u;
    data[4u] = DiagMaster_ActiveSessionState;
}

void Dcm_RC_Request701Active(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    DiagMaster_Is701Active = 1u;
    DiagMaster_Is703Active = 0u;
    DiagMaster_IsMasterActive = 0u;
}

void Dcm_RC_Request703Active(uint8* data)
{
    data[1u] = data[1u] + 0x40u;
    DiagMaster_Is701Active = 0u;
    DiagMaster_Is703Active = 1u;
    DiagMaster_IsMasterActive = 0u;
}

void Dcm_RC_RequestMasterActive(uint8* data)
{
    data[1] = data[1] + 0x40u;
    DiagMaster_Is701Active = 0u;
    DiagMaster_Is703Active = 0u;
    DiagMaster_IsMasterActive = 1u;
}

void Dcm_RC_ResetDcy(uint8* data)
{
    data[1] = data[1] + 0x40u;
    DiagMaster_ResetDcy = 1u;
}

void Dcm_ProcessDiagnosticRequest(const uint8 *data, uint16 length)
{
    uint8 serviceId = data[0u];

    if(1u > length)
    {
        return;
    }
    else
    {
        /* Do nothing. */
    }

    if(0x19u == serviceId)
    {
        if(2u <= length && 0x0Au == data[1u])
        {
            response_dtc[0u] = 0x59;
            response_dtc[1u] = 0x0Au;

            for(uint8 i = 0u; i < DEM_NUMBER_OF_DTCS; i++)
            {
                response_dtc[2u + i] = Dem_DtcArray[i];
            }

            Can_IsoTpTransmit(0x6FFu, response_dtc, sizeof(response_dtc));
        }
        else
        {
            /* Do nothing. */
        }
    }
    else if(0x31u == serviceId)
    {
        uint8 subFunction = data[3u];

        if(4u > length)
        {
            return;
        }
        else
        {
            /* Do nothing. */
        }

        if(0x15u == subFunction || 0x16u == subFunction || 0x17u == subFunction)
        {
            response_read[0u] = 0x71u;
            response_read[3u] = subFunction;

            if(0x15u == subFunction)
            {
                respLen_read = 4u + ENCCAL_CODING_SIZE;

                for(uint8 i = 0u; i < ENCCAL_CODING_SIZE; i++)
                {
                    response_read[4u + i] = EncCal_Coding_Buffer[i];
                }
            }
            else if(0x16u == subFunction)
            {
                respLen_read = 4u + ENCCAL_CALIBRATION_SIZE;

                for(uint8 i = 0u; i < ENCCAL_CALIBRATION_SIZE; i++)
                {
                    response_read[4u + i] = EncCal_Calibration_Buffer[i];
                }
            }
            else if(0x17u == subFunction)
            {
                respLen_read = 4u + sizeof(EncCal_VODataComplete);

                for(uint8 i = 0; i < sizeof(EncCal_VODataComplete); i++)
                {
                    response_read[4u + i] = EncCal_VODataComplete[i];
                }
            }
            else
            {
                /* Do nothing. */
            }

            Can_IsoTpTransmit(0x6FFu, response_read, respLen_read);
        }
        else if(0x04u == subFunction || 0x05u == subFunction || 0x06u == subFunction)
        {
            uint16 payloadLen = (length > 4u) ? (length - 4u) : 0u;

            if(0x04u == subFunction)
            {
                if(payloadLen > sizeof(storedData_04))
                {
                    payloadLen = sizeof(storedData_04);
                }
                else
                {
                    /* Do nothing. */
                }

                memcpy(storedData_04, &data[4], payloadLen);
                memcpy(&EncCal_Coding_Buffer, &storedData_04, sizeof(storedData_04));
                Nvm_WriteBlock(2u, (uint32*)&EncCal_Coding_Buffer[0u]);
            }
            else if(0x05u == subFunction)
            {
                if(payloadLen > sizeof(storedData_05))
                {
                    payloadLen = sizeof(storedData_05);
                }
                else
                {
                    /* Do nothing. */
                }

                memcpy(storedData_05, &data[4u], payloadLen);
                memcpy(&EncCal_Calibration_Buffer, &storedData_05, sizeof(storedData_05));
                Nvm_WriteBlock(1u, (uint32*)&EncCal_Calibration_Buffer[0u]);
            }
            else if(0x06u == subFunction)
            {
                if(payloadLen > sizeof(storedData_06))
                {
                    payloadLen = sizeof(storedData_06);
                }
                else
                {
                    /* Do nothing. */
                }

                memcpy(storedData_06, &data[4u], payloadLen);
                memcpy(&EncCal_VODataComplete, &storedData_06, sizeof(storedData_06));
                Nvm_WriteBlock(3u, (uint32*)&EncCal_VODataComplete[0u]);
            }
            else
            {
                /* Do nothing. */
            }

            response_write[0u] = 0x71u;
            response_write[1u] = data[1u];
            response_write[2u] = data[2u];
            response_write[3u] = subFunction;

            Can_IsoTpTransmit(0x6FFu, response_write, sizeof(response_write));
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
}
