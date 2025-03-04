

#include "tle989x.h"
#include "system_tle989x.h"
#include "scu.h"
#include "pmu.h"
#include "tle_variants.h"
#include "gpio.h"
#include "systick.h"

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize the system
 */
void SYS_Init(void)
{
	 //Scu sys clock;
  SCU_initClk();   
  // 40 M SYSTICK/
  SCU_initSysTick(40000);  //40M
  /*  1ms sisttick */
  SCU_initSysTick(40000);   // 40M/40000=1k;1/1k=1ms
	PMU_initFailSafeWatchdog();

}

