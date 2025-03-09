#include "Ifx_Types.h"
#include "Can.h"

#define DIAGMASTER_REQUEST_TYPE 0x01u
#define DIAGMASTER_RESPONSE_TYPE 0x02u
#define DIAGMASTER_ISOTPRXTX_TYPE 0x03u
#define DIAGMASTER_x70xDEFAULT 1u
#define DIAGMASTER_x70xPROGRAMMING 2u
#define DIAGMASTER_x70xEXTENDED 3u
#define DIAGMASTER_x70xCODING 4u
#define DIAGMASTER_x70xCALIBRATION 5u

typedef struct
{
        Can_RxMsg_t diagnosticMessage;
        uint8 isAllowed;
        uint8 msgType;
        uint8 masterDiagReqId;
}DiagMaster_DiagReq_t;

extern DiagMaster_DiagReq_t DiagMaster_Receive_DiagnosticMessageBuffer[50u];
extern DiagMaster_DiagReq_t DiagMaster_Transmit_DiagnosticMessageBuffer[50u];
extern uint8 DiagMaster_701SessionState;
extern uint8 DiagMaster_703SessionState;
extern uint8 DiagMaster_705SessionState;
extern uint16 DiagMaster_Is701Active;
extern uint16 DiagMaster_Is703Active;
extern uint16 DiagMaster_Is705Active;
extern uint16 DiagMaster_IsMasterActive;
extern uint16 DiagMaster_ActiveId;
extern uint8 DiagMaster_DiagnosticModeActivated;
extern uint8 DiagMaster_TesterPresentActive;
extern uint8 DiagMaster_RequestDiagnosticMode;
extern uint8 DiagMaster_GearboxStatus;
extern uint8 DiagMaster_VehicleSpeed;
extern uint32 DiagMaster_Rx_DiagBufCnt;
extern uint8 DiagMaster_ActiveSessionState;
extern uint32 DiagMaster_AliveTime;
extern uint8 DiagMaster_ResetDcy;

extern void DiagMaster_MainFunction(void);
