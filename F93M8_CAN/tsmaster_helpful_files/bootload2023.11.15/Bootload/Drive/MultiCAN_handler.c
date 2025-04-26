/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "tle_device.h"
#include  "MultiCAN_handler.h"
#include  "int.h"

/*******************************************************************************
**                        Global Constant Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                          Global Type Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/
static uint32 MO_7_DATA_HIGH;
static uint32 MO_7_DATA_LOW;

/* NVIC */
void NVIC_IRQ26_Handler(void); 
void NVIC_IRQ27_Handler(void);
void NVIC_IRQ28_Handler(void);

/* interrupt service */
//void CANRX_ISR(void);

/* init */
void MultiCAN_init(void);

/* transmit request MO_0 */
bool CAN_TransmitReqMsgObj0(uint32 highdata, uint32 lowdata);
/* transmit request MO_1 */
bool CAN_TransmitReqMsgObj1(uint32 highdata, uint32 lowdata);
/* transmit request MO_2 */
bool CAN_TransmitReqMsgObj2(uint32 highdata, uint32 lowdata);
/* transmit request MO_3 */
bool CAN_TransmitReqMsgObj3(uint32 data3, uint32 data2, uint32 data1, uint32 data0);
bool CAN_TransmitReqMsgObj3_data(uint32 *data,uint32 DLC,uint32 ID);
/*******************************************************************************
**                     Global Inline Function Definitions                     **
*******************************************************************************/

volatile uint32_t can_receive_counter=0;

void MultiCAN_init(void)
{
  /* Load global MultiCAN+ registers */
 /* enable CANCONTR module */
 CANNODE-> CLC.reg = 0; 
 
 /* configure fractional divider fcan = fa */	
 CANNODE->FDR.bit.STEP = 0x3FF; 
 CANNODE->FDR.bit.DM= 0x01;
 
 /* select clock for fa = CLKINB (from PLL1)  */
 /* CLKSEL =2 */ 	
 CANNODE->MCR.bit.CLKSEL = 0x02;

 /* init CAN node 0 */
 /* CCE=1,INIT=1 */	
 CANNODE->CAN_NCR0.bit.CCE = 1;
 CANNODE->CAN_NCR0.bit.INIT = 1;

	/* CAN-FD enabled */	
 CANNODE->CAN_NCR0.bit.FDEN = 1; 	
	
 /* MultiCAN input select */
 /* CANTRX.RXD --> MultiCAN.RXDCA  */
 CANNODE->CAN_NPCR0.bit.RXSEL = 0x00; 

if (CANNODE->CAN_NCR0.bit.FDEN == 0)
{	
 /* set normal node bit timing FDEN=0 - 1 MBit*/
 /* fcan=80MHz, tq=50ns, TSEG1=750ns, TSEG2=200ns */
 CANNODE->CAN_NBTR0.bit.BRP = 0x03; 
 CANNODE->CAN_NBTR0.bit.SJW = 0x3;
 CANNODE->CAN_NBTR0.bit.TSEG1 = 0xE;
 CANNODE->CAN_NBTR0.bit.TSEG2 = 0x3;
 CANNODE->CAN_NBTR0.bit.DIV8 = 0;
}
else 
{	
 /* set normal node bit timing with FDEN=1 - 1 MBit*/
 /* fcan=80MHz, tq=50ns, TSEG1=750ns, TSEG2=200ns */
 CANNODEFD->CAN_NBTEVR0.bit.BRP = 0x03; 
 CANNODEFD->CAN_NBTEVR0.bit.SJW = 0x3;
 CANNODEFD->CAN_NBTEVR0.bit.TSEG1 = 0xE;
 CANNODEFD->CAN_NBTEVR0.bit.TSEG2 = 0x3;
 CANNODEFD->CAN_NBTEVR0.bit.DIV8 = 0;

 /* set fast node bit timing with FDEN=1 - 2 MBit*/
 CANNODEFD->CAN_FNBTR0.bit.FBRP = 0x01;
 CANNODEFD->CAN_FNBTR0.bit.FSJW = 0x3;
 CANNODEFD->CAN_FNBTR0.bit.FTSEG1 = 0xD;
 CANNODEFD->CAN_FNBTR0.bit.FTSEG2 = 0x4;
}
 
	/* Allocate message objects to CAN nodes */
	/* note: list 1 is assigned to node 0 in MulitCAN */
  /* wait until PANCTR is not busy */
	while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY));
	/* map MO_0 to 1ist 1, static allocation */
	CANNODE->PANCTR.bit.PANAR1 = 0;
	CANNODE->PANCTR.bit.PANAR2 = 1;
	CANNODE->PANCTR.bit.PANCMD = 0x02; 
  /* wait until PANCTR is not busy */
  while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_1 to 1ist 1, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 1; 
	CANNODE->PANCTR.bit.PANAR2 = 1;
	CANNODE->PANCTR.bit.PANCMD = 0x02; 
  while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_2 to 1ist 1, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 2; 
	CANNODE->PANCTR.bit.PANAR2 = 1;
	CANNODE->PANCTR.bit.PANCMD = 0x02; 
  while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_3 (base object) to 1ist 1, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 3; 
	CANNODE->PANCTR.bit.PANAR2 = 1;
	CANNODE->PANCTR.bit.PANCMD = 0x02; 
  while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_4 (slave object) to 1ist 2, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 4; 
	CANNODE->PANCTR.bit.PANAR2 = 2;
	CANNODE->PANCTR.bit.PANCMD = 0x02; 
	 while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_5 (slave object) to 1ist 2, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 5; 
	CANNODE->PANCTR.bit.PANAR2 = 2;
	CANNODE->PANCTR.bit.PANCMD = 0x02; 
  while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY));
	/* map MO_7 to 1ist 1, static allocation */
	CANNODE->PANCTR.bit.PANAR1 = 7;
	CANNODE->PANCTR.bit.PANAR2 = 1;
	CANNODE->PANCTR.bit.PANCMD = 0x02; 
  /* wait until PANCTR is not busy */
  while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_8 to 1ist 1, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 8; 
	CANNODE->PANCTR.bit.PANAR2 = 1;
	CANNODE->PANCTR.bit.PANCMD = 0x02;
	 while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_9 to 1ist 1, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 9; 
	CANNODE->PANCTR.bit.PANAR2 = 1;
	CANNODE->PANCTR.bit.PANCMD = 0x02;
	 while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_10 to 1ist 2, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 10; 
	CANNODE->PANCTR.bit.PANAR2 = 2;
	CANNODE->PANCTR.bit.PANCMD = 0x02;
	 while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_11 to 1ist 2, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 11; 
	CANNODE->PANCTR.bit.PANAR2 = 2;
	CANNODE->PANCTR.bit.PANCMD = 0x02;
	
	while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_12 to 1ist 2, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 12; 
	CANNODE->PANCTR.bit.PANAR2 = 2;
	CANNODE->PANCTR.bit.PANCMD = 0x02;
		while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_12 to 1ist 2, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 13; 
	CANNODE->PANCTR.bit.PANAR2 = 2;
	CANNODE->PANCTR.bit.PANCMD = 0x02;
		while ((CANNODE->PANCTR.bit.BUSY)||(CANNODE->PANCTR.bit.RBUSY))	;
	/* map MO_12 to 1ist 2, static allocation */
  CANNODE->PANCTR.bit.PANAR1 = 14; 
	CANNODE->PANCTR.bit.PANAR2 = 2;
	CANNODE->PANCTR.bit.PANCMD = 0x02;

 /* init transmit message object MO_0 */
 /* M0_0 function: CAN classic, standard MO, data length DLC=8 */
 CANMSGOBJ0->CAN_MOFCR0.bit.DLC = 8;
 /* M0_0 function: Transmit interrupt enabled */
 CANMSGOBJ0->CAN_MOFCR0.bit.TXIE = 1;	
 /* M0_0 mode: SETDIR=1, SETTXEN1=1, SETTXEN0=1 */	
 CANMSGOBJ0->OBJ0.CAN_MOCTR0.reg =(1<<27)|(1<<26)|(1<<25);
 /* M0_0 arbitration: PRI=1 (acc to list), IDE=0 (11 bit), ID=0x07AA */   
 CANMSGOBJ0->CAN_MOAR0.reg = ((0x00000001<<30)|(0x000007AA<<18));  
 /* M0_0 interrupt: select INT_O0, set MPN bitpos to 0 */
 CANMSGOBJ0->CAN_MOIPR0.bit.MPN = 0x0;
 CANMSGOBJ0->CAN_MOIPR0.bit.TXINP = 0x0; 	
 
 /* init transmit message object MO_1 */
 /* M0_1 function: CAN classic, standard MO, data length DLC=8 */
 CANMSGOBJ0->CAN_MOFCR1.bit.DLC = 8;
 /* M0_1 function: Transmit interrupt enabled */
 CANMSGOBJ0->CAN_MOFCR1.bit.TXIE = 1;	
 /* M0_0 mode: SETDIR=1, SETTXEN1=1, SETTXEN0=1 */	
 CANMSGOBJ0->OBJ1.CAN_MOCTR1.reg =(1<<27)|(1<<26)|(1<<25);
 /* M0_1 arbitration: PRI=1 (acc to list), IDE=0 (11 bit), ID=0x07BB */   
 CANMSGOBJ0->CAN_MOAR1.reg = ((0x00000001<<30)|(0x000007BB<<18));  
 /* M0_1 interrupt: select INT_O0, set MPN bitpos to  1 		*/
  CANMSGOBJ0->CAN_MOIPR1.bit.MPN = 0x1;
 CANMSGOBJ0->CAN_MOIPR1.bit.TXINP = 0x0; 
 
 /* init transmit message object MO_2 */
 /* M0_2 function: MMC=CAN-FD, BRS=1, FDF=1, DLC=8 byte */
 CANMSGOBJ0->CAN_MOFCR2.bit.DLC = 0x8;
 CANMSGOBJ0->CAN_MOFCR2.bit.FDF = 1;
 CANMSGOBJ0->CAN_MOFCR2.bit.BRS = 1;
 /* M0_2 function: Transmit interrupt enabled */
 CANMSGOBJ0->CAN_MOFCR2.bit.TXIE = 1;	
 /* M0_2 mode: SETDIR=1, SETTXEN1=1, SETTXEN0=1 */	
 CANMSGOBJ0->OBJ2.CAN_MOCTR2.reg =(1<<27)|(1<<26)|(1<<25);
 /* M0_2 arbitration: PRI=1 (acc to list), IDE=0 (11 bit), ID=0x07EE */   
 CANMSGOBJ0->CAN_MOAR2.reg = ((0x00000001<<30)|(0x000007EE<<18));  
 /* M0_2 interrupt: select INT_O0, set MPN bitpos to 2 		*/
 CANMSGOBJ0->CAN_MOIPR2.bit.MPN = 0x2;
 CANMSGOBJ0->CAN_MOIPR2.bit.TXINP = 0x0; 

 /* init transmit message object MO_3 */
 /* MO_3 baseobj  CUR (d=0-7)					*/
 /* MO_4 slaveobj BOT (d=8-35)				*/
 /* MO_5 slaveobj TOP (d=36-63) 			*/
 /* M0_3 function: MMC=CAN-FD, BRS=1, FDF=1, DLC=16 byte */
 CANMSGOBJ0->CAN_MOFCR3.bit.MMC = 0x5;
 CANMSGOBJ0->CAN_MOFCR3.bit.DLC = 15;
 CANMSGOBJ0->CAN_MOFCR3.bit.FDF = 1;
 CANMSGOBJ0->CAN_MOFCR3.bit.BRS = 1;
 /* M0_3 function: Transmit interrupt enabled */
 CANMSGOBJ0->CAN_MOFCR3.bit.TXIE = 1;	
 /* M0_3 FIFO pointer MO_3 -> MO_4 -> MO_5  */
 CANMSGOBJ0->CAN_MOFGPR3.bit.BOT =  0x04; // MO_4
 CANMSGOBJ0->CAN_MOFGPR3.bit.CUR =  0x03; // MO_3
 CANMSGOBJ0->CAN_MOFGPR3.bit.TOP =  0x05; // MO_5	
  /* M0_3 mode: SETDIR=1, SETTXEN1=1, SETTXEN0=1 */	
 CANMSGOBJ0->OBJ3.CAN_MOCTR3.reg =(1<<27)|(1<<26)|(1<<25);
 /* M0_3 arbitration: PRI=1 (acc to list), IDE=0 (11 bit), ID=0x07FF */   
 CANMSGOBJ0->CAN_MOAR3.reg = ((0x00000001<<30)|(0x000007FF<<18));  
 /* M0_3 interrupt: select INT_O0, set MPN bitpos to 3 		*/
 CANMSGOBJ0->CAN_MOIPR3.bit.MPN = 0x3;
 CANMSGOBJ0->CAN_MOIPR3.bit.TXINP = 0x0; 


 /* init receive message object MO_7 */
 /* MO_7 function: receive interrupt enabled */
 CANMSGOBJ0->CAN_MOFCR7.bit.RXIE = 1;
 /* MO_7 mode:  SETRXEN=1, SETMSGVAL=1*/
 CANMSGOBJ0->OBJ7.CAN_MOCTR7.reg = (1<<23)|(1<<21);
 /* MO_7 arbitration: PRI=1 (acc to list), IDE=0 (11 bit), ID=0x07CC  */ 
 CANMSGOBJ0->CAN_MOAR7.reg = ((0x00000001<<30)|(0x000007CC<<18));  
 /* MO_7 interrupt: select INT_01, set MPN bitpos to 7  */
 CANMSGOBJ0->CAN_MOIPR7.bit.MPN = 0x7; 
 CANMSGOBJ0->CAN_MOIPR7.bit.RXINP = 0x1;
 
  /* init receive message object MO_8 */
	
	  CANMSGOBJ0->CAN_MOFCR8.bit.GDFS=0;
 CANMSGOBJ0->CAN_MOFCR8.bit.IDC=0;
 CANMSGOBJ0->CAN_MOFCR8.bit.DLCC=0;
 CANMSGOBJ0->CAN_MOFCR8.bit.DATC=0;
 CANMSGOBJ0->CAN_MOFCR8.bit.MMC = 5;
 CANMSGOBJ0->CAN_MOFCR8.bit.FDF = 1;
 CANMSGOBJ0->CAN_MOFCR8.bit.BRS = 1;
 CANMSGOBJ0->CAN_MOFCR8.bit.DLC = 15; 
 CANMSGOBJ0->CAN_MOFCR8.bit.RXIE = 1;
 
  CANMSGOBJ0->CAN_MOFGPR8.bit.BOT =  12; // MO_10
 CANMSGOBJ0->CAN_MOFGPR8.bit.CUR =  8;  // MO_9
 CANMSGOBJ0->CAN_MOFGPR8.bit.TOP =  13; // MO_11
 /* MO_8 mode:  SETRXEN=1, SETMSGVAL=1*/
 CANMSGOBJ0->OBJ8.CAN_MOCTR8.reg = (1<<23)|(1<<21);
 /* MO_8 arbitration: PRI=1 (acc to list), IDE=0 (11 bit), ID=0x0755  */ 
  CANMSGOBJ0->CAN_MOAR8.reg = ((0x00000001<<30)|(0x000007DD<<18));  
 /* MO_8 interrupt: select INT_01, set MPN bitpos to 9  */
 CANMSGOBJ0->CAN_MOIPR8.bit.MPN = 0x8; 
 CANMSGOBJ0->CAN_MOIPR8.bit.RXINP = 0x1;
 /* MO_8 function: receive interrupt enabled */
 CANMSGOBJ0->CAN_MOFCR8.bit.RXIE = 1;

 
 /* init receive message object MO_9 */
 /* MO_9 function: CAN-FD long MO, fast br, DLC = 20 bytes, rec int ena */
 /* MO_9 baseobj  CUR (d=0-7)					*/
 /* MO_10 slaveobj BOT (d=8-35)				*/
 /* MO_11 slaveobj TOP (d=36-63) 			*/ 
 

 
 CANMSGOBJ0->CAN_MOFCR9.bit.GDFS=0;
 CANMSGOBJ0->CAN_MOFCR9.bit.IDC=0;
 CANMSGOBJ0->CAN_MOFCR9.bit.DLCC=0;
 CANMSGOBJ0->CAN_MOFCR9.bit.DATC=0;
 CANMSGOBJ0->CAN_MOFCR9.bit.MMC = 5;
 CANMSGOBJ0->CAN_MOFCR9.bit.FDF = 1;
 CANMSGOBJ0->CAN_MOFCR9.bit.BRS = 1;
 CANMSGOBJ0->CAN_MOFCR9.bit.DLC = 15; 
 CANMSGOBJ0->CAN_MOFCR9.bit.RXIE = 1;
 /* MO_9 FIFO pointer: MO_9 -> MO_10 -> MO_11  */
 CANMSGOBJ0->CAN_MOFGPR9.bit.BOT =  10; // MO_10
 CANMSGOBJ0->CAN_MOFGPR9.bit.CUR =  9;  // MO_9
 CANMSGOBJ0->CAN_MOFGPR9.bit.TOP =  11; // MO_11
 /* MO_9 mode:  SETRXEN=1, SETMSGVAL=1*/
 CANMSGOBJ0->OBJ9.CAN_MOCTR9.reg = (1<<23)|(1<<21);
 /* MO_9 arbitration: PRI=1 (acc to list), IDE=0 (11 bit), ID=0x0755  */ 
   CANMSGOBJ0->CAN_MOAR9.reg = ((0x00000001<<30)|(0x00000755<<18));  
 /* MO_9 interrupt: select INT_01, set MPN bitpos to 9  */
 CANMSGOBJ0->CAN_MOIPR9.bit.MPN = 0x9; 
 CANMSGOBJ0->CAN_MOIPR9.bit.RXINP = 0x1;
 

 
 /* MultiCAN errors interrupt enable */
 /* ALINP=2, LCINP =2 --> INT_O2 */
 CANNODE->CAN_NIPR0.reg = (2<<0)|(2<<4);
 /* ALIE=1, LCIE =1  */
 CANNODE->CAN_NCR0.reg |= (1<<2)|(1<<3);
    
 /* NVIC MultiCAN node interrupt enable (transmit) */
 CPU->NVIC_ISER.bit.IRQEN26 =1;	
 /* NVIC MultiCAN node interrupt enable (receive)*/
 CPU->NVIC_ISER.bit.IRQEN27 =1;
 /* NVIC MultiCAN node interrupt enable (error)*/
 CPU->NVIC_ISER.bit.IRQEN28 =1;
 
 /* node init finished */
 /* CCE=0,INIT=0 */	
 CANNODE->CAN_NCR0.bit.CCE = 0;
 CANNODE->CAN_NCR0.bit.INIT = 0;  

}	

bool CAN_TransmitReqMsgObj0(uint32 highdata, uint32 lowdata)
{
 /* set transmit request for MO_0 */
	if (!(CANMSGOBJ0->OBJ0.CAN_MOSTAT0.reg & 0x02u))			/* check if MO's TXPND is not set */ 	 
	{
	 /* load transmit data for MO_0 */
	 CANMSGOBJ0->CAN_MODATAL0.reg = lowdata; 
	 CANMSGOBJ0->CAN_MODATAH0.reg = highdata;		 
	 /* MO_0 mode: SETTXRQ=1, SETMSGVAL=1, SETNEWDAT=1 */
	 CANMSGOBJ0->OBJ0.CAN_MOCTR0.reg = (1<<24)|(1<<21)|(1<<19);	 		
	 return (0);	 	
	}
	else/* dont transmit, clear TXPND in transmit interrupt first */
	{
		return (1);																		
	} 
}

bool CAN_TransmitReqMsgObj1(uint32 highdata, uint32 lowdata)
{
 /* set transmit request for MO_1 */
	if (!(CANMSGOBJ0->OBJ1.CAN_MOSTAT1.reg & 0x02u))			/* check if MO's TXPND is not set */ 	 
	{
	 /* load transmit data for MO_1 */
	 CANMSGOBJ0->CAN_MODATAL1.reg = lowdata; 
	 CANMSGOBJ0->CAN_MODATAH1.reg = highdata;		 
	 /* MO_1 mode: SETTXRQ=1, SETMSGVAL=1, SETNEWDAT=1 */
	 CANMSGOBJ0->OBJ1.CAN_MOCTR1.reg = (1<<24)|(1<<21)|(1<<19);	 
	 return (0);	 	
	}
	else/* dont transmit, clear TXPND in transmit interrupt first */
	{
		return (1);																				
	} 
}

bool CAN_TransmitReqMsgObj2(uint32 highdata, uint32 lowdata)
{
 /* set transmit request for MO_2 */
	if (!(CANMSGOBJ0->OBJ2.CAN_MOSTAT2.reg & 0x02u))			/* check if MO's TXPND is not set */ 	 
	{
	 /* load transmit data for MO_2 */
	 CANMSGOBJ0->CAN_MODATAL2.reg = lowdata; 
	 CANMSGOBJ0->CAN_MODATAH2.reg = highdata;		 
	 /* MO_1 mode: SETTXRQ=1, SETMSGVAL=1, SETNEWDAT=1 */
	 CANMSGOBJ0->OBJ2.CAN_MOCTR2.reg = (1<<24)|(1<<21)|(1<<19);	 
	 return (0);	 	
	}
	else/* dont transmit, clear TXPND in transmit interrupt first */
	{
		return (1);																				
	} 
}

bool CAN_TransmitReqMsgObj3(uint32 data3, uint32 data2, uint32 data1, uint32 data0)
{
 /* set transmit request for MO_3 */
	if (!(CANMSGOBJ0->OBJ3.CAN_MOSTAT3.reg & 0x02u))			/* check if MO's TXPND is not set */ 	 
	{
	 /* load transmit data for MO_3 */
	 /* MO_3 is slaveobj with data2/3 in EMO4DATA0/1 */
	 CANMSGOBJ0->CAN_MODATAL3.reg = data0; 
	 CANMSGOBJ0->CAN_MODATAH3.reg = data1;		 
	 CANMSGOBJ1->CAN_EMO4DATA0.reg = data2;
	 CANMSGOBJ1->CAN_EMO4DATA1.reg = data3;
		/* MO_3 mode: SETTXRQ=1, SETMSGVAL=1, SETNEWDAT=1 */
	 CANMSGOBJ0->OBJ3.CAN_MOCTR3.reg = (1<<24)|(1<<21)|(1<<19);	 
	 return (0);	 	
	}
	else		/* dont transmit, clear TXPND in transmit interrupt first */
	{
		return (1);																				
	} 
}

bool CAN_TransmitReqMsgObj3_data(uint32 *data,uint32 DLC,uint32 ID)
{
 
 /* set transmit request for MO_3 */
	if (!(CANMSGOBJ0->OBJ3.CAN_MOSTAT3.reg & 0x02u))			/* check if MO's TXPND is not set */ 	 
	{
	 /* load transmit data for MO_3 */
	 /* MO_3 is slaveobj with data2/3 in EMO4DATA0/1 */

		CANMSGOBJ0->CAN_MOFCR3.bit.DLC =DLC; //	
		CANMSGOBJ0->CAN_MOAR3.bit.ID =(ID<<18);
		CANMSGOBJ0->CAN_MODATAL3.reg = data[0]; //4byte
		CANMSGOBJ0->CAN_MODATAH3.reg = data[1];		 
		CANMSGOBJ1->CAN_EMO4DATA0.reg = data[2];
		CANMSGOBJ1->CAN_EMO4DATA1.reg = data[3];
		CANMSGOBJ1->CAN_EMO4DATA2.reg = data[4];
		CANMSGOBJ1->CAN_EMO4DATA3.reg = data[5];
		CANMSGOBJ1->CAN_EMO4DATA4.reg = data[6];
		CANMSGOBJ1->CAN_EMO4DATA5.reg = data[7];
		CANMSGOBJ1->CAN_EMO4DATA6.reg = data[8];
		CANMSGOBJ1->CAN_EMO5DATA0.reg = data[9];
		CANMSGOBJ1->CAN_EMO5DATA1.reg = data[10];
		CANMSGOBJ1->CAN_EMO5DATA2.reg = data[11];
		CANMSGOBJ1->CAN_EMO5DATA3.reg = data[12];
		CANMSGOBJ1->CAN_EMO5DATA4.reg = data[13];
		CANMSGOBJ1->CAN_EMO5DATA5.reg = data[14];
		CANMSGOBJ1->CAN_EMO5DATA6.reg = data[15];
		CANMSGOBJ0->OBJ3.CAN_MOCTR3.reg = (1<<24)|(1<<21)|(1<<19);	 

	 return (0);	 	
	}
	else/* dont transmit, clear TXPND in transmit interrupt first */
	{
	 //CANMSGOBJ0->OBJ3.CAN_MOCTR3.bit.SETTXPND=0;
		return (1);																				
	} 
}

/* MultiCAN transmit interrupt handler */ 
struct CAN_msg msgPublic={0};
can_iso_tp_link_t_p LinkTxPoint=0;
uint8_t msgPublic_ok=0;
void NVIC_IRQ26_Handler(void)
{		
	 if (CANNODE->MSPND0.reg & 0x01u)					/* check if MO_0 pending ? */ 
	 { 
 	 	 CANNODE->MSPND0.reg = ~(0x01u);					/* clr MO_0 msg pending bit */ 
		 CANMSGOBJ0->OBJ0.CAN_MOCTR0.reg = 0x02u; /* clr MO_0 TXPND - TXPND indicates a successful transmitted msgobj */
	 }
	 if (CANNODE->MSPND0.reg & 0x02u)					/* check if MO_1 pending ? */ 
	 { 
	 	 CANNODE->MSPND0.reg = ~(0x02u);					/* clr MO_1 msg pending bit */ 
		 CANMSGOBJ0->OBJ1.CAN_MOCTR1.reg = 0x02u; /* clr MO_1 TXPND - TXPND indicates a successful transmitted msgobj */
	 } 
	 if (CANNODE->MSPND0.reg & 0x04u)					/* check if MO_2 pending ? */ 
	 { 
	 	 CANNODE->MSPND0.reg = ~(0x04u);					/* clr MO_2 msg pending bit */ 
		 CANMSGOBJ0->OBJ2.CAN_MOCTR2.reg = 0x02u; /* clr MO_2 TXPND - TXPND indicates a successful transmitted msgobj */
		 
	 } 
	 if (CANNODE->MSPND0.reg & 0x08u)					/* check if MO_3 pending ? */ 
	 { 
	 	 CANNODE->MSPND0.reg = ~(0x08u);					/* clr MO_3 msg pending bit */ 
		 CANMSGOBJ0->OBJ3.CAN_MOCTR3.reg = 0x02u; /* clr MO_3 TXPND - TXPND indicates a successful transmitted msgobj */
		 msgPublic_ok=0x55;
	 } 
	

}	

/* MultiCAN receive interrupt handler */ 
can_iso_tp_link_t_p LinkRxPoint=0;
uint8_t msg_Rx_exit=0;
struct CAN_msg msg_Rx={0};

void NVIC_IRQ27_Handler(void)
 {	
	 
 	 static uint32_t rxbuffer[16]={0}; 
 	 uint32_t *p=rxbuffer;
	 
			can_receive_counter++;
		if(can_receive_counter==0xEFFFFFFF)	//Receive INT Counter
		{
			can_receive_counter=0;
		}		 
	 /* check which MO has been received */ 
	 if (CANNODE->MSPND0.reg & 0x80u)					/* check if MO_7 pending ? */ 
	 { 
	 	 CANNODE->MSPND0.reg = ~(0x80u);				/* clr MO_7 msg pending bit */ 
		 /* reset MO_7 RXPND and NEWDAT */
  		 CANMSGOBJ0->OBJ7.CAN_MOCTR7.reg = (1<<3)|(1<<0);   
		 /* read receive data of MO_7 */
		 MO_7_DATA_LOW = CANMSGOBJ0->CAN_MODATAL7.reg; 
		 MO_7_DATA_HIGH = CANMSGOBJ0->CAN_MODATAH7.reg;
		 
		 CAN_TransmitReqMsgObj0(MO_7_DATA_HIGH, MO_7_DATA_LOW);//1 transfer
		 
		 /* check for data consistency */
		 if ((CANMSGOBJ0->OBJ7.CAN_MOSTAT7.bit.MSGLST == 1)|(CANMSGOBJ0->OBJ7.CAN_MOSTAT7.bit.NEWDAT == 1)) 
		 {
				/* data are lost - MO has been overwritten by new msg but not read */
			  /* reset MO_7 MSGLST  */
				CANMSGOBJ0->OBJ7.CAN_MOCTR7.reg = (1<<4); 
				/* do message lost handling accordingly */
		 }
	 }

	 /* check which MO has been received */	
 	 if (CANNODE->MSPND0.reg & 0x100u)					/* check if MO_8 pending ? */ 
	 { 
	 	 CANNODE->MSPND0.reg = ~(0x100u);					/* clr M0_8 msg pending bit */
		 /* reset MO_8 RXPND and NEWDAT */
		 CANMSGOBJ0->OBJ8.CAN_MOCTR8.reg = (1<<3)|(1<<0);   
		 /* read receive data of MO_8 */
	
		 *p++= 	CANMSGOBJ0->CAN_MODATAL8.reg;
		 *p++ = CANMSGOBJ0->CAN_MODATAH8.reg;
		 *p++ = CANMSGOBJ1->CAN_EMO12DATA0.reg;
		 *p++ = CANMSGOBJ1->CAN_EMO12DATA1.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO12DATA2.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO12DATA3.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO12DATA4.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO12DATA5.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO12DATA6.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO13DATA0.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO13DATA1.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO13DATA2.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO13DATA3.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO13DATA4.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO13DATA5.reg ;
		 *p= 		CANMSGOBJ1->CAN_EMO13DATA6.reg ;
		 
		 msg_Rx.id.id=(CANMSGOBJ0-> CAN_MOAR8.bit.ID>>18);
		 msg_Rx.dlc=CANMSGOBJ0->CAN_MOFCR8.bit.DLC;
     msg_Rx.id.isCANFD=1;
		 msg_Rx.id.isExt=0;
		 msg_Rx.id.isRemote=0;
		 
		 for (int i=0;i<16;i++)
	  {
	     msg_Rx.data[4*i]=(*(rxbuffer+i)&0xff);
		   msg_Rx.data[4*i+1]=((*(rxbuffer+i)>>8)&0xff);
		   msg_Rx.data[4*i+2]=((*(rxbuffer+i)>>16)&0xff);
		   msg_Rx.data[4*i+3]=((*(rxbuffer+i)>>24)&0xff);
	  }
	  msg_Rx_exit=0x55;
		 /* check for data consistency */
		 if ((CANMSGOBJ0->OBJ8.CAN_MOSTAT8.bit.MSGLST == 1)|(CANMSGOBJ0->OBJ7.CAN_MOSTAT7.bit.NEWDAT == 1)) 
		 {
				/* data are lost - MO has been overwritten by new msg but not read */
			  /* reset MO_8 MSGLST */
			  CANMSGOBJ0->OBJ8.CAN_MOCTR8.reg = (1<<4);
				/* do message lost handling accordingly */
		 }	 
	 } 
	 
	 /* check which MO has been received */	
 	 if (CANNODE->MSPND0.reg & 0x200u)					/* check if MO_9 pending ? */ 
	 { 
	 	 CANNODE->MSPND0.reg = ~(0x200u);					/* clr MO_9 msg pending bit */
		 /* reset MO_9 RXPND and NEWDAT */
		 CANMSGOBJ0->OBJ9.CAN_MOCTR9.reg = (1<<3)|(1<<0); 

		 *p++= 	CANMSGOBJ0->CAN_MODATAL9.reg;
		 *p++ = CANMSGOBJ0->CAN_MODATAH9.reg;
		 *p++ = CANMSGOBJ1->CAN_EMO10DATA0.reg;
		 *p++ = CANMSGOBJ1->CAN_EMO10DATA1.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO10DATA2.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO10DATA3.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO10DATA4.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO10DATA5.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO10DATA6.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO11DATA0.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO11DATA1.reg ;
		 *p++ =	CANMSGOBJ1->CAN_EMO11DATA2.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO11DATA3.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO11DATA4.reg ;
		 *p++ = CANMSGOBJ1->CAN_EMO11DATA5.reg ;
		 *p= 		CANMSGOBJ1->CAN_EMO11DATA6.reg ;

	   msg_Rx.id.id=(CANMSGOBJ0-> CAN_MOAR9.bit.ID>>18); 
		 msg_Rx.dlc=CANMSGOBJ0->CAN_MOFCR9.bit.DLC;
     msg_Rx.id.isCANFD=1;
		 msg_Rx.id.isExt=0;
		 msg_Rx.id.isRemote=0;
		 
		 for (int i=0;i<16;i++)
	  {
	     msg_Rx.data[4*i]=(*(rxbuffer+i)&0xff);
		   msg_Rx.data[4*i+1]=((*(rxbuffer+i)>>8)&0xff);
		   msg_Rx.data[4*i+2]=((*(rxbuffer+i)>>16)&0xff);
		   msg_Rx.data[4*i+3]=((*(rxbuffer+i)>>24)&0xff);
	  }
	  msg_Rx_exit=0x55;
		 /* check for data consistency */
		 if ((CANMSGOBJ0->OBJ9.CAN_MOSTAT9.bit.MSGLST == 1)|(CANMSGOBJ0->OBJ9.CAN_MOSTAT9.bit.NEWDAT == 1)) 
		 {
				/* data are lost - MO has been overwritten by new msg but not read */
			  /* reset MO_ MSGLST */
			  CANMSGOBJ0->OBJ9.CAN_MOCTR9.reg = (1<<4);
				/* do message lost handling accordingly */
		 }	 
	 
 }	
	 
 
  	
}

/* MultiCAN error interrupt handler */ 
void NVIC_IRQ28_Handler(void)
{
	/* check erros*/
	if ((CANNODE->CAN_NSR0.bit.LEC) != 0 ) /* LEC */
	{			
			/*  Bus exception recovery. If the bus error occurs, delay 500ms to reinitialize 
			the bus to avoid the bus error affecting the bus for a long time.             */
			if(CANNODE->CAN_NSR0.bit. LEC==0X05||(CANNODE->CAN_NCR0.bit.INIT==1))
				{
					SCU_delay_us(500000);//500ms
					if(CANNODE->CAN_NSR0.bit.LEC==0X05||(CANNODE->CAN_NCR0.bit.INIT==1))
					{					
						CANNODE->CAN_NCR0.bit.INIT = 1; 
						CANNODE->CAN_NCR0.bit.CCE = 1;
						CANNODE->CLC.bit.EDIS=0;
						CANNODE->CAN_NECNT0.reg&=((uint32_t)(~0xffff));				
						MultiCAN_init();
						CAN_TransmitReqMsgObj1(0xAAAAAAAA,0xBBBBBBBB);
						 if (CANNODE->MSPND0.reg & 0x01u)					
						{ 
							CANNODE->MSPND0.reg = ~(0x01u);					
							CANMSGOBJ0->OBJ0.CAN_MOCTR0.reg = 0x02u; 
													
						}										
					}				
				}			
	}		
	if ((CANNODE->CAN_NSR0.bit.ALERT) == 1 ) /* ALERT */
	{
		/* do something */
		CANNODE->CAN_NSR0.bit.ALERT = 0; /* clear ALERT */
	}
	if ((CANNODE->CAN_NSR0.bit.EWRN) == 1 ) /* EWRN */
	{
		/* do something */
	}
	if ((CANNODE->CAN_NSR0.bit.BOFF) == 1 ) /* BOFF */
	{
		/* do something */
	}
  if ((CANNODE->CAN_NSR0.bit.LLE) == 1 ) /* LLE*/
	{
		/* do something */
	}
  if ((CANNODE->CAN_NSR0.bit.LOE) == 1 ) /* LOE*/
	{
		/* do something */
	}
	if ((CANNODE->CAN_NSR0.bit.RESI) == 1 ) /* RESI*/
	{
		/* do something */
	}
	if ((CANNODE->CAN_NSR0.bit.FLEC) != 1 ) /* FLEC*/
	{
		/* do something */
	}
}	
void T16_ISR(void)
{

}
