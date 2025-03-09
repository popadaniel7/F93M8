#include "IfxFce_Crc.h"
#include "Ifx_Types.h"

typedef struct
{
    IfxFce_Crc      fce;
    IfxFce_Crc_Crc  fceCrc;
    uint32          crc_result;
} fceCrc;

extern fceCrc g_fceCrc2; /* Structure to store information */

extern void Crc_Init(void);
extern uint32 Crc_Calculate(uint32 *crcData, uint16 crcDataLength, uint32 crcStartValue);
extern uint32 Crc_CalculateFCECRC(const uint32 *crcData, uint16 crcDataLength, uint32 crcStartValue);
