#include "Irq.h"
#include "Can.h"
#include "Crc.h"
#include "McuSm.h"
#include "Ain.h"
#include "IfxStm.h"

void ISR_CanAlrt(void)
{
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_errorPassive);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_messageRAMAccessFailure);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_timeoutOccurred);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_bitErrorCorrected);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_bitErrorUncorrected);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_warningStatus);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_protocolErrorArbitration);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_protocolErrorData);
    Can_Alrt_Flag++;
}

void ISR_CanMoer(void)
{
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_errorPassive);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_messageRAMAccessFailure);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_timeoutOccurred);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_bitErrorCorrected);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_bitErrorUncorrected);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_warningStatus);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_protocolErrorArbitration);
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_protocolErrorData);
    Can_Moer_Flag++;
}
void ISR_CanBoff(void)
{
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_busOffStatus);
    Can_BusOff_Flag++;
}
void ISR_CanLoi(void)
{
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_errorLoggingOverflow);
    Can_Loi_Flag++;
}
/* Interrupt Service Routine (ISR) called once the RX interrupt has been generated.
 * Compares the content of the received CAN message with the content of the transmitted CAN message. */
void ISR_CanRx(void)
{
    Can_DedBuff = 1u;
    Can_Rx();
}
