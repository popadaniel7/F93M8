#include "main.h"

/* System clock count 1ms */
static uint32 sclock_count=0;

/* Enter 120ms to generate a systick interrupt mode */
uint8_t enter_120_mode = 0;

/**
 * @brief  main
 * @param  None.
 * @return 
 * @private
 */

int main(void)
{	  
		/* Provides the variables needed for the millisecond count */
	  uint32 last_sys_tick;
		uint32 tick_diff;
		uint32 tick_now;
	
		/* The APP jumps to the bootload reply data for the 10 03 service */
	  uint8_t APP_jump_Bootload_response[7]={0x00,0x50,0x03,0x01,0xF4,0x01,0xF4};
	  	
		/* APP jumps to Bootload */
		if(APP_BOOT_RESET==APP_BOOT_RESET_EQUAL_EE)
		{
			/* Open the watch dog */
			PMU->WD_CTRL.bit.EN=1;
			
			APP_jump_Bootload_response[0]=0x01;
			
			/* Initialization of the UDS layer */
			UDS_init();
		}
		else//Bootload jumps to APP
		{	
			/* Verify that the APP exists and jump */
			if(BOOT_APP_RESET==BOOT_APP_RESET_EQUAL_DD)
			{
			   
#if CRC  //CRC checks are applied before jumping to the APP
				if((BOOTLOAD_INFORMATION==APP_EXISTS)&&(CHECKSUM_R==crc32((uint8_t *)(CODE_BEGAINADD),CODE_SIZE)))
				{
					BOOT_APP_RESET=APP_EQUAL_BB;	
					app_jump(APP_EQUAL_BB);
				}
				else /* The validation fails to enter bootload mode */
				{
					PMU->WD_CTRL.bit.EN=1;
					GPIO_setP13State(GPIO_STATE_LOW);
					BOOT_APP_RESET=BOOT_EQUAL_CC;
				}
			
#else   //No CRC check before jumping to APP
			
				BOOT_APP_RESET=APP_EQUAL_BB;	
			  app_jump(APP_EQUAL_BB); 
			
#endif
			
			}	
      else /* Enter bootload mode */
      {
				
			}					
		}
				
		/* Initialize Fail safe Watchdog */
    PMU_initFailSafeWatchdog();
		
		/* clear Watchdog fail status */
    PMU_clrFailSafeWatchdogFailSts();
		
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
		
		/* The APP jumps to the bootload reply data for the 10 03 service */
		if (APP_jump_Bootload_response[0]==0x01)
		{
			APP_jump_Bootload_response[0]=0x00;	
			iso_can_tp_N_USData_request(ServerLinkPoint,0,&APP_jump_Bootload_response[1],6);
		}
		
		/* !!!!!This is the bootload station test light, in the process of using to delete the code!!!!! */
		GPIO_setP13State(GPIO_STATE_LOW);
		
		/*****************************************************************************
		** Main endless loop                                                        **
		*****************************************************************************/
		
		/* Because the operation of flash will not produce 1ms systick interrupt, which will
		cause system clock confusion, feeding watchdog failure, and lead to bootload system 
		downtime, so it is changed to 120ms systick interrupt, and a clock accurate to 1ms
		is required. The following code is used to process the generation of an sclock_count
		with a precision of 1ms. 
		The systic interrupt is switched by 1ms and set to 120ms once.                   */
		enter_120_mode=1;
		
		/* BEGAIN***** Since a clock of 1ms needs to be provided, the clock count is processed. 
		Provides a clock count of 1ms, sclock_count.                            *****BEGAIN  */
	  last_sys_tick = SCU_getSysTickCntVal();
		
		while(1)
		{
			tick_now = SCU_getSysTickCntVal();
			
			if(tick_now <= last_sys_tick)
			{
				tick_diff = last_sys_tick - tick_now;
			}
			else
			{
				tick_diff = last_sys_tick + 120*FREQUENCY_60HZ_1MS - tick_now;
			}
			
			if(tick_diff > FREQUENCY_60HZ_1MS)
			{
				uint32 ms_add = tick_diff/FREQUENCY_60HZ_1MS;
				
		    /* sclock count is a system count of 1ms */
				sclock_count += ms_add;
				
				/* Systick_ISR */
				UDS_server_poll((int32_t)ms_add);
				
				if(last_sys_tick<ms_add*FREQUENCY_60HZ_1MS)
				{
					last_sys_tick =last_sys_tick+120*FREQUENCY_60HZ_1MS-ms_add*FREQUENCY_60HZ_1MS;
				}
				else
				{
					last_sys_tick -=ms_add*FREQUENCY_60HZ_1MS;
				}
		  }
			else
			{
			}
		
		/* END***** Since a clock of 1ms needs to be provided, the clock count is processed. 
		Provides a clock count of 1ms, sclock_count.                            *****END  */	
			
			/* The light flashes once in 500ms */	
			if((sclock_count%1000) <= 500)
			{
				GPIO_setP13State(GPIO_STATE_HIGH);
			}
			else
			{
				GPIO_setP13State(GPIO_STATE_LOW);
		  }

			/* CANFD receives the data and processes it. */	
			if(msg_Rx_exit==0x55)
			{
				msg_Rx_exit=0;
				iso_can_tp_L_Data_indication(LinkRxPoint,&msg_Rx);
			}
			else
			{
			
			}
			
			/* CANFD drives the completion of sending data, telling the TP 
			layer that it can continue to send the next frame of data. */	
			if(msgPublic_ok==0x55)
			{
				msgPublic_ok=0;
				iso_can_tp_L_Data_confirm(LinkTxPoint,&msgPublic, 0);
			}
			else
			{
			
			}
			
			
			/* Main watchdog service */
			(void) PMU_serviceFailSafeWatchdog();

			/* The TP layer gets the current clock */
			iso_can_tp_poll(&link_tp,sclock_count);
			
			/* Power on to jump APP */
			if((BOOT_APP_RESET!=BOOT_EQUAL_CC)&&(sclock_count>=P0WER_ON_JUMP_APP_DELAY)&&(can_receive_counter==0))
			{
				BOOT_APP_RESET=BOOT_APP_RESET_EQUAL_DD;		
				__NVIC_SystemReset();
			}
			else
			{
			}		
		
		UDS27_RN++;	//Simulate random numbers	
		}
}


void Systick_ISR(void)
{
	 
}


