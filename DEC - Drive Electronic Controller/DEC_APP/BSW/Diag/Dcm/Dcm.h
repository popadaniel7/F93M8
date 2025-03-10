#include "Ifx_Types.h"

// Called when a complete ISO-TP diagnostic message has been reassembled.
extern void Dcm_ProcessDiagnosticRequest(const uint8 *data, uint16 length);
extern void Dcm_MainFunction(void);
