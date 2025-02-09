;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.2.2 #13448 (MINGW32)
;--------------------------------------------------------
	.file	"main.c"
;	.optsdcc -mmcs51
	; --model-large

	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl	_main
	.globl	_Scr_WCAN_Interrupt
	.globl	_Scr_NMIECC_Interrupt
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.section .bdata.i51,"aw" ;reg_name ;area
_SCR_P00_IOCR4	=	0x0094
_SCR_P01_IOCR1	=	0x0099
_SCR_P01_IOCR3	=	0x009b
_SCR_P01_OUT	=	0x0098
_SCR_P01_PDISC	=	0x009d
_SCR_P01_IN	=	0x0099
_SCR_SCU_SR	=	0x00f9
_SCR_P01_IOCR2	=	0x009a
_SCR_IRCON1	=	0x00f3
_SCR_MODPISEL0	=	0x00f2
_SCR_WCAN_CFG	=	0x00b0
_SCR_WCAN_INTMRSLT	=	0x00b1
_SCR_WCAN_INTESTAT0	=	0x00b0
_SCR_WCAN_INTESTAT1	=	0x00b1
_SCR_WCAN_PAGE	=	0x00b8
_SCR_SYSCON0	=	0x0088
_SCR_SCU_PAGE	=	0x00f1
_SCR_SCRINTEXCHG	=	0x00f5
_SCR_TCINTEXCHG	=	0x00f6
_SCR_STDBYWKP	=	0x00fc
_SCR_CMCON	=	0x00fa
_SCR_PMCON1	=	0x00fb
_SCR_PASSWD	=	0x0086
_SCR_RTC_RTCON	=	0x00e1
_SCR_RTC_CNT0	=	0x00e2
_SCR_RTC_CNT1	=	0x00e3
_SCR_RTC_CNT2	=	0x00e4
_SCR_RTC_CNT3	=	0x00e5
_SCR_RTC_RTCCR0	=	0x00e6
_SCR_RTC_RTCCR1	=	0x00e7
_SCR_RTC_RTCCR2	=	0x00e8
_SCR_RTC_RTCCR3	=	0x00e9
_SCR_IO_PAGE	=	0x008f
_SCR_P00_IOCR5	=	0x0095
_SCR_P00_OUT	=	0x0090
_SCR_P00_PDISC	=	0x0095
_SCR_P00_OMTR	=	0x0094
_SCR_SCU_STDBYWKP	=	0x00fc
_SCR_IEN0	=	0x00d8
_SCR_IEN1	=	0x00d1
_SCR_NMICON	=	0x00f3
_SCR_NMISR	=	0x00f2
_SCR_IRCON0	=	0x00f2
;--------------------------------------------------------
; uninitialized external ram data
;--------------------------------------------------------
	.section .xdata.i51,"aw" ;xdata_name ;area
_Scr_WakeupReason	=	0x1600
_Scr_Counter	=	0x1601
_Scr_IsrCounter1	=	0x1602
_Scr_IsrCounter2	=	0x1603
;--------------------------------------------------------
; interrupt vector
;--------------------------------------------------------
	.globl _Scr_WCAN_Interrupt 
	.section .isr01, "ax"
	ljmp	_Scr_WCAN_Interrupt
	.globl _Scr_NMIECC_Interrupt 
	.section .isr02, "ax"
	ljmp	_Scr_NMIECC_Interrupt
;--------------------------------------------------------
; code
;--------------------------------------------------------
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;	../SCR/main.c:14: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
	.section .text.code.main,"ax" ;code for function main
	.type   main, @function
_main:
	.using 0
;	../SCR/main.c:16: SCR_SCU_PAGE = 0x01u;                   // switch to page 1
	mov	_SCR_SCU_PAGE,#0x01
;	../SCR/main.c:17: SCR_PMCON1 = 0x49u;                     // switch OCDS
	mov	_SCR_PMCON1,#0x49
;	../SCR/main.c:18: SCR_SCU_PAGE = 0x00u;                   // switch to page 0
	mov	_SCR_SCU_PAGE,#0x00
;	../SCR/main.c:19: SCR_IO_PAGE = 0x02u;                    // switch to IO Page 2
	mov	_SCR_IO_PAGE,#0x02
;	../SCR/main.c:20: SCR_P01_PDISC = 0x00;                   // enable all P01 pins
	mov	_SCR_P01_PDISC,#0x00
;	../SCR/main.c:21: SCR_MODPISEL0 = 0x00;                   // select WCANRXDA
	mov	_SCR_MODPISEL0,#0x00
;	../SCR/main.c:22: SCR_IEN1 = 0x01u;                       // select EWCAN interrupt
	mov	_SCR_IEN1,#0x01
;	../SCR/main.c:23: SCR_NMICON = 0x01u;                     // select NMI ECC interrupt
	mov	_SCR_NMICON,#0x01
;	../SCR/main.c:24: SCR_IO_PAGE = 0x01u;                    // switch to IO Page 1
	mov	_SCR_IO_PAGE,#0x01
;	../SCR/main.c:25: SCR_P01_IOCR2 = 0x20u;                  // configure P33.10 / P01.2 as input pull-up
	mov	_SCR_P01_IOCR2,#0x20
;	../SCR/main.c:26: SCR_WCAN_PAGE = 0x00u;                  // switch to WCAN Page 0
	mov	_SCR_WCAN_PAGE,#0x00
;	../SCR/main.c:27: SCR_WCAN_CFG = 0x09u;                   // set WCAN_EN to 1, SELWK_EN to 0, CCE to 1
	mov	_SCR_WCAN_CFG,#0x09
;	../SCR/main.c:28: SCR_WCAN_CFG = 0x01u;                   // set WCAN_EN to 1, SELWK_EN to 0, CCE to 0
	mov	_SCR_WCAN_CFG,#0x01
;	../SCR/main.c:29: SCR_WCAN_INTMRSLT = 0x0CU;              // set WUFMASK to 1, WUPMASK to 1
	mov	_SCR_WCAN_INTMRSLT,#0x0C
;	../SCR/main.c:30: SCR_WCAN_CFG = 0x07u;                   // set WCAN_EN to 1, SELWK_EN to 3, CCE to 0
	mov	_SCR_WCAN_CFG,#0x07
;	../SCR/main.c:31: SCR_WCAN_PAGE = 0x01u;                  // switch to WCAN Page 1
	mov	_SCR_WCAN_PAGE,#0x01
;	../SCR/main.c:32: while(SCR_WCAN_INTESTAT0 != 0x01u);     // check if configuration is fine
.00101:
	mov	a,#0x01
	cjne	a,_SCR_WCAN_INTESTAT0,.00124
	sjmp	.00125
.00124:
	sjmp	.00101
.00125:
;	../SCR/main.c:33: while(SCR_WCAN_INTESTAT1 != 0x04u);     // check if configuration is fine
.00104:
	mov	a,#0x04
	cjne	a,_SCR_WCAN_INTESTAT1,.00126
	sjmp	.00127
.00126:
	sjmp	.00104
.00127:
;	../SCR/main.c:35: while(1)
.00108:
;	../SCR/main.c:37: Scr_Counter++;
	mov	dptr,#_Scr_Counter
	movx	a,@dptr
	inc	a
	movx	@dptr,a
	sjmp	.00108
.00110:
;	../SCR/main.c:39: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Scr_WCAN_Interrupt'
;------------------------------------------------------------
;	../SCR/main.c:41: void Scr_WCAN_Interrupt(void) __interrupt (ECAN)
;	-----------------------------------------
;	 function Scr_WCAN_Interrupt
;	-----------------------------------------
	.section .text.code.Scr_WCAN_Interrupt,"ax" ;code for function Scr_WCAN_Interrupt
	.type   Scr_WCAN_Interrupt, @function
_Scr_WCAN_Interrupt:
	.using 0
	push	acc
	push	dpl
	push	dph
;	../SCR/main.c:43: Scr_IsrCounter1++;
	mov	dptr,#_Scr_IsrCounter1
	movx	a,@dptr
	inc	a
	movx	@dptr,a
;	../SCR/main.c:44: Scr_WakeupReason = 0x01u;
	mov	dptr,#_Scr_WakeupReason
	mov	a,#0x01
	movx	@dptr,a
;	../SCR/main.c:45: SCR_SCU_PAGE = 0x01u;           // set SCU PAGE to 1
;	1-genFromRTrack replaced	mov	_SCR_SCU_PAGE,#0x01
	mov	_SCR_SCU_PAGE,a
;	../SCR/main.c:46: SCR_SCU_STDBYWKP = 0x11u;       // request SCRWKP and ECCWKSEL
	mov	_SCR_SCU_STDBYWKP,#0x11
.00128:
;	../SCR/main.c:47: }
	pop	dph
	pop	dpl
	pop	acc
	reti
;	eliminated unneeded mov psw,# (no regs used in bank)
;	eliminated unneeded push/pop not_psw
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function 'Scr_NMIECC_Interrupt'
;------------------------------------------------------------
;	../SCR/main.c:49: void Scr_NMIECC_Interrupt(void) __interrupt (NMIRAMECC)
;	-----------------------------------------
;	 function Scr_NMIECC_Interrupt
;	-----------------------------------------
	.section .text.code.Scr_NMIECC_Interrupt,"ax" ;code for function Scr_NMIECC_Interrupt
	.type   Scr_NMIECC_Interrupt, @function
_Scr_NMIECC_Interrupt:
	.using 0
	push	acc
	push	dpl
	push	dph
;	../SCR/main.c:51: Scr_IsrCounter2++;
	mov	dptr,#_Scr_IsrCounter2
	movx	a,@dptr
	inc	a
	movx	@dptr,a
;	../SCR/main.c:52: Scr_WakeupReason = 0x02u;
	mov	dptr,#_Scr_WakeupReason
	mov	a,#0x02
	movx	@dptr,a
;	../SCR/main.c:53: SCR_SCU_PAGE = 0x01u;           // set SCU PAGE to 1
	mov	_SCR_SCU_PAGE,#0x01
;	../SCR/main.c:54: SCR_SCU_STDBYWKP = 0x05u;       // request SCRWKP and WCANWKSEL
	mov	_SCR_SCU_STDBYWKP,#0x05
.00130:
;	../SCR/main.c:55: }
	pop	dph
	pop	dpl
	pop	acc
	reti
;	eliminated unneeded mov psw,# (no regs used in bank)
;	eliminated unneeded push/pop not_psw
;	eliminated unneeded push/pop b
