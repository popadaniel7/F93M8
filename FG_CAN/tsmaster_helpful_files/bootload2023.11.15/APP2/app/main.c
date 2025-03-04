/* It is important to note that when operating flash, it will not produce 
1ms systick interrupt,which will lead to system time confusion, unable to 
properly feed the watchdog and cause the system reset.                 */

#include "main.h"

static uint32 sclock_count=0;//System clock count
int main(void)
{
	/* The bootload jumps to the APP reply data for the 11 service */
	static const uint8_t Bootload_jump_APP_response[1]={0x51};
	
	/* Clear watchdog fail status */
  PMU_clrFailSafeWatchdogFailSts();
  
	/* APP state*/
	APP_BOOT_RESET=APP_EQUAL_BB;//default value

	/* Initializing hardware */
  TLE_init();	
	CCU7_startT16();

  /*  Initialization of module 'MultiCAN Controller' */
  MultiCAN_init();
	/* can be removed if CANTRX init in CfgWiz */
	CANTRX->CTRL.reg = 0x0307; /* enable, normal mode */	

	/* link tp structure pointer passing */
	LinkTxPoint =&link_tp;
	LinkRxPoint =&link_tp;
	ServerLinkPoint =&link_tp;
	
	/* TP layer parameters are initialized */
	init_for_all_links();
	
	/* TP layer channel creation */
	iso_can_tp_create(&link_tp, &init_tp);
	
	/* The bootload jumps to the APP reply data for the 11 service */
  iso_can_tp_N_USData_request(ServerLinkPoint,0,&Bootload_jump_APP_response[0],1);
	
	/* Enable all interrupts  */
  __enable_irq();
	
  /*****************************************************************************
  ** Main endless loop                                                        **
  *****************************************************************************/
	
  while(1)
  {
	
		/* Main watchdog service */
			(void) PMU_serviceFailSafeWatchdog();
		
		/* The TP layer gets the current clock */
		iso_can_tp_poll(&link_tp,sclock_count);
  }
}


void Systick_ISR(void)
{
	static int LED_time=0;
	LED_time++;
	
	/* LED13 5000ms flicker */
	if(LED_time==5000)
	{
		LED_time=0;
		GPIO_setP13State(GPIO_STATE_TOGGLE);
		GPIO_setP14State(GPIO_STATE_TOGGLE);
	}
	
	/* System time */
	sclock_count++;
	
	/* UDS layer time pull */
	UDS_layer_pull();
}

