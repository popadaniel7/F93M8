#include "Ifx_Types.h"
#include "IfxCpu_reg.h"
#include "IfxMtu.h"
#include "IfxScuRcu.h"
#include "Ifx_Cfg_Trap.h"
#include "IfxDts_Dts.h"

typedef struct
{
        uint32 reason;
        uint32 information;
}McuSm_ResetHistory_t;

extern uint32 McuSm_LastResetReason;
extern uint32 McuSm_LastResetInformation;
extern uint32 McuSm_IndexResetHistory;
extern McuSm_ResetHistory_t McuSm_ResetHistory[20u];

extern void McuSm_InitializeBusMpu(void);
extern void McuSm_PerformResetHook(uint32 resetReason, uint32 resetInformation);
extern void McuSm_TRAP1(IfxCpu_Trap trapInfo);
extern void McuSm_TRAP2(IfxCpu_Trap trapInfo);
extern void McuSm_TRAP3(IfxCpu_Trap trapInfo);
extern void McuSm_TRAP4(IfxCpu_Trap trapInfo);
extern void McuSm_TRAP7(IfxCpu_Trap trapInfo);
