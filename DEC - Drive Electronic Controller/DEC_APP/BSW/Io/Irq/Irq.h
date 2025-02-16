#include "Ifx_Types.h"
#include "IfxCpu_Irq.h"

#define IRQ_ISR_PRIORITY_DMA        20U           /* Priority for interrupt after DMA transfer done                               */
#define IRQ_DMA_CHANNEL             0U           /* DMA Channel used in this example (0 lowest priority - 127 highest priority)  */
#define IRQ_CANRX_CHANNEL           4U           /* Interrupt priority number                                                    */
#define IRQ_CANTX_CHANNEL           5U           /* Interrupt priority number                                                    */
#define ISR_PRIORITY_DTS            8U           /* Priority for DTS interrupt           */
#define ISR_PRIORITY_SMU_INT0       9U           /* Define the SMU Service Request 0 interrupt priority  */
#define ISR_PRIORITY_CAN_ALRT       14u
#define ISR_PRIORITY_CAN_MOER       15u
#define ISR_PRIORITY_CAN_BOFF       16u
#define ISR_PRIORITY_CAN_LOI        17u

IFX_INTERRUPT(ISR_DMA1_Transfer, 0, IRQ_ISR_PRIORITY_DMA);
IFX_INTERRUPT(ISR_CanTx, 0, IRQ_CANTX_CHANNEL);
IFX_INTERRUPT(ISR_CanRx, 0, IRQ_CANRX_CHANNEL);
IFX_INTERRUPT(ISR_DTS, 0, ISR_PRIORITY_DTS);
IFX_INTERRUPT(ISR_CanMoer, 0, ISR_PRIORITY_CAN_ALRT);
IFX_INTERRUPT(ISR_CanBoff, 0, ISR_PRIORITY_CAN_BOFF);
IFX_INTERRUPT(ISR_CanLoi, 0, ISR_PRIORITY_CAN_LOI);
