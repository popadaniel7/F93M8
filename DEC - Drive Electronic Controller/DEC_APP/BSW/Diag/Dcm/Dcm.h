#include "Ifx_Types.h"

extern uint8 Dcm_SwitchTxOff;
// Called when a complete ISO-TP diagnostic message has been reassembled.
extern void Dcm_ProcessDiagnosticRequest(const uint8 *data, uint16 length);
extern void Dcm_MainFunction(void);
