#include "Gtm_Atom.h"
#include "Irq.h"

#define ATOM_FREQ           1000.0f                 /* ATOM frequency                                               */
#define CMU_FREQ            1000000.0f              /* CMU clock frequency                                          */

IfxGtm_Atom_Timer           g_timerDriver;   /* ATOM driver */

/* This function initializes the ATOM */
void Gtm_Atom_Init(void)
{
    IfxGtm_enable(&MODULE_GTM);                                                 /* Enable GTM                       */
    IfxGtm_Atom_Timer_Config timerConfig;                                       /* Timer configuration structure    */
    IfxGtm_Atom_Timer_initConfig(&timerConfig, &MODULE_GTM);                    /* Initialize default parameters    */
    timerConfig.atom = IfxGtm_Atom_0;                                           /* Select the ATOM_0                */
    timerConfig.timerChannel = IfxGtm_Atom_Ch_0;                                /* Select channel 0                 */
    timerConfig.clock = IfxGtm_Cmu_Clk_0;                                       /* Select the CMU clock 0           */
    timerConfig.base.frequency = ATOM_FREQ;                                     /* Set timer frequency              */
    timerConfig.base.isrPriority = IRQ_ISR_PRIORITY_ATOM;                       /* Set interrupt priority           */
    timerConfig.base.isrProvider = IfxSrc_Tos_cpu0;                             /* Set interrupt provider           */
    IfxGtm_Cmu_setClkFrequency(&MODULE_GTM, IfxGtm_Cmu_Clk_0, CMU_FREQ);        /* Set the clock frequency          */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_CLK0);                /* Enable the CMU clock 0           */
    IfxGtm_Atom_Timer_init(&g_timerDriver, &timerConfig);                       /* Initialize the ATOM              */
    IfxGtm_Atom_Timer_run(&g_timerDriver);                                      /* Start the ATOM                   */
}
