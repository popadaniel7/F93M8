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
_SCR_WCAN_BTL1_CTRL	=	0x00b5
_SCR_WCAN_BTL2_CTRL	=	0x00b6
_SCR_WCAN_DLC_CTRL	=	0x00b7
_SCR_WCAN_DATA0_CTRL	=	0x00b0
_SCR_WCAN_DATA1_CTRL	=	0x00b1
_SCR_WCAN_DATA2_CTRL	=	0x00b2
_SCR_WCAN_DATA3_CTRL	=	0x00b3
_SCR_WCAN_DATA4_CTRL	=	0x00b4
_SCR_WCAN_DATA5_CTRL	=	0x00b5
_SCR_WCAN_DATA6_CTRL	=	0x00b6
_SCR_WCAN_DATA7_CTRL	=	0x00b7
_SCR_WCAN_ID0_CTRL	=	0x00b0
_SCR_WCAN_ID1_CTRL	=	0x00b1
_SCR_WCAN_ID2_CTRL	=	0x00b2
_SCR_WCAN_ID3_CTRL	=	0x00b3
_SCR_WCAN_MASK_ID0_CTRL	=	0x00b4
_SCR_WCAN_MASK_ID1_CTRL	=	0x00b5
_SCR_WCAN_MASK_ID2_CTRL	=	0x00b6
_SCR_WCAN_MASK_ID3_CTRL	=	0x00b7
_SCR_SCU_RSTCON	=	0x00f9
_SCR_P00_IOCR2	=	0x0092
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
;	../SCR/main.c:16: Scr_Counter++;
	mov	dptr,#_Scr_Counter
	movx	a,@dptr
	inc	a
	movx	@dptr,a
;	../SCR/main.c:22: SCR_IO_PAGE = 0x1;
	mov	_SCR_IO_PAGE,#0x01
;	../SCR/main.c:24: SCR_P00_IOCR2 = 0x20 ; // WCANRXDG(P33.02)
	mov	_SCR_P00_IOCR2,#0x20
;	../SCR/main.c:25: SCR_IO_PAGE = 0x2;
	mov	_SCR_IO_PAGE,#0x02
;	../SCR/main.c:26: SCR_P00_PDISC = 0x04 ; // WCANRXDG(P33.02)
	mov	_SCR_P00_PDISC,#0x04
;	../SCR/main.c:27: SCR_SCU_PAGE = 0x1;
	mov	_SCR_SCU_PAGE,#0x01
;	../SCR/main.c:28: SCR_SCU_RSTCON = 0x1 ; // Disable WDT and ECC reset
	mov	_SCR_SCU_RSTCON,#0x01
;	../SCR/main.c:29: SCR_SCU_STDBYWKP = 0x4; // Select WCAN as wakeup source
	mov	_SCR_SCU_STDBYWKP,#0x04
;	../SCR/main.c:45: SCR_SCU_PAGE = 1;
	mov	_SCR_SCU_PAGE,#0x01
;	../SCR/main.c:46: SCR_PMCON1 &= ~(1<< 3); // enable WCAN clock (bit_3), default: WCAN is disabled
	anl	_SCR_PMCON1,#0xF7
;	../SCR/main.c:47: SCR_SCU_PAGE = 0x2;
	mov	_SCR_SCU_PAGE,#0x02
;	../SCR/main.c:48: SCR_MODPISEL0 = 16;
	mov	_SCR_MODPISEL0,#0x10
;	../SCR/main.c:49: SCR_WCAN_PAGE = 0x0 ;
	mov	_SCR_WCAN_PAGE,#0x00
;	../SCR/main.c:50: SCR_WCAN_CFG = (1<<3)|(0<<2)|(1<<0) ; // CCE=1, SELWK_EN=0, WCAN_EN=1 --> according to UM
	mov	_SCR_WCAN_CFG,#0x09
;	../SCR/main.c:51: SCR_WCAN_INTMRSLT = (0<<3)|(1<<2)|(0<<1)|(0<<0); // WUP=0, WUF=1, ERR=0, CANTO=0 --> enable WUF interrupt
	mov	_SCR_WCAN_INTMRSLT,#0x04
;	../SCR/main.c:55: SCR_WCAN_PAGE = 0x1;
	mov	_SCR_WCAN_PAGE,#0x01
;	../SCR/main.c:56: SCR_WCAN_DLC_CTRL = 0x8 ; // 8 bytes of data
	mov	_SCR_WCAN_DLC_CTRL,#0x08
;	../SCR/main.c:57: SCR_WCAN_BTL1_CTRL = 0x64 ; // Configure Baud Rate of 500 kbits/s (see table 747 and register WCAN_BTL2_CTRL)
	mov	_SCR_WCAN_BTL1_CTRL,#0x64
;	../SCR/main.c:58: SCR_WCAN_BTL2_CTRL = (1<<6) | (0x33<<0) ; // BRP=01(Divide by 2) and SP=0x33 represents ~80%SP
	mov	_SCR_WCAN_BTL2_CTRL,#0x73
;	../SCR/main.c:63: SCR_WCAN_PAGE = 0x0 ;
	mov	_SCR_WCAN_PAGE,#0x00
;	../SCR/main.c:64: SCR_WCAN_CFG &= ~((1<<3)|(1<<2)|(0<<0)); // reset CCE=1, SELWK_EN=1, WCAN_EN=0 according to UM
	anl	_SCR_WCAN_CFG,#0xF3
;	../SCR/main.c:68: SCR_WCAN_PAGE = 0x2 ;
	mov	_SCR_WCAN_PAGE,#0x02
;	../SCR/main.c:69: SCR_WCAN_ID0_CTRL = 0x00;
	mov	_SCR_WCAN_ID0_CTRL,#0x00
;	../SCR/main.c:70: SCR_WCAN_ID1_CTRL = 0x00;
	mov	_SCR_WCAN_ID1_CTRL,#0x00
;	../SCR/main.c:71: SCR_WCAN_ID2_CTRL = 0x00;//0x6f ;
	mov	_SCR_WCAN_ID2_CTRL,#0x00
;	../SCR/main.c:72: SCR_WCAN_ID3_CTRL = 0x00;//0x6f ; // RTR=0 ; IDE = 0
	mov	_SCR_WCAN_ID3_CTRL,#0x00
;	../SCR/main.c:73: SCR_WCAN_MASK_ID0_CTRL = 0xFF ;
	mov	_SCR_WCAN_MASK_ID0_CTRL,#0xFF
;	../SCR/main.c:74: SCR_WCAN_MASK_ID1_CTRL = 0xFF ;
	mov	_SCR_WCAN_MASK_ID1_CTRL,#0xFF
;	../SCR/main.c:75: SCR_WCAN_MASK_ID2_CTRL = 0xFF ;
	mov	_SCR_WCAN_MASK_ID2_CTRL,#0xFF
;	../SCR/main.c:76: SCR_WCAN_MASK_ID3_CTRL = 0xFF ;
	mov	_SCR_WCAN_MASK_ID3_CTRL,#0xFF
;	../SCR/main.c:77: SCR_WCAN_PAGE = 0x3 ;
	mov	_SCR_WCAN_PAGE,#0x03
;	../SCR/main.c:78: SCR_WCAN_DATA7_CTRL = 0 ; // Data Frame = 0x01 23 45 67 89 ab cd ef (byte8...byte1)
	mov	_SCR_WCAN_DATA7_CTRL,#0x00
;	../SCR/main.c:79: SCR_WCAN_DATA6_CTRL = 0 ;
	mov	_SCR_WCAN_DATA6_CTRL,#0x00
;	../SCR/main.c:80: SCR_WCAN_DATA5_CTRL = 0 ;
	mov	_SCR_WCAN_DATA5_CTRL,#0x00
;	../SCR/main.c:81: SCR_WCAN_DATA4_CTRL = 0 ;
	mov	_SCR_WCAN_DATA4_CTRL,#0x00
;	../SCR/main.c:82: SCR_WCAN_DATA3_CTRL = 0 ;
	mov	_SCR_WCAN_DATA3_CTRL,#0x00
;	../SCR/main.c:83: SCR_WCAN_DATA2_CTRL = 0 ;
	mov	_SCR_WCAN_DATA2_CTRL,#0x00
;	../SCR/main.c:84: SCR_WCAN_DATA1_CTRL = 0 ;
	mov	_SCR_WCAN_DATA1_CTRL,#0x00
;	../SCR/main.c:85: SCR_WCAN_DATA0_CTRL = 0 ;
	mov	_SCR_WCAN_DATA0_CTRL,#0x00
;	../SCR/main.c:89: SCR_WCAN_PAGE = 0x0 ;
	mov	_SCR_WCAN_PAGE,#0x00
;	../SCR/main.c:90: SCR_WCAN_CFG |= ((0<<3)|(1<<2)|(0<<0)); //set CCE=0, SELWK_EN=1, WCAN_EN=0
	orl	_SCR_WCAN_CFG,#0x04
;	../SCR/main.c:91: Scr_Counter++;
	mov	dptr,#_Scr_Counter
	movx	a,@dptr
	inc	a
	movx	@dptr,a
;	../SCR/main.c:95: SCR_WCAN_PAGE = 0x1 ;
	mov	_SCR_WCAN_PAGE,#0x01
;	../SCR/main.c:96: while ((SCR_WCAN_INTESTAT0 & 0x1) != 0x1) {Scr_Counter++; } ; // selective wake up enable protocol handle is activated
.00101:
	mov	r6,_SCR_WCAN_INTESTAT0
	anl	ar6,#0x01
	mov	r7,#0x00
	cjne	r6,#0x01,.00121
	cjne	r7,#0x00,.00121
	sjmp	.00105
.00121:
	mov	dptr,#_Scr_Counter
	movx	a,@dptr
	inc	a
	movx	@dptr,a
;	../SCR/main.c:98: while(1)
	sjmp	.00101
.00105:
	sjmp	.00105
.00107:
;	../SCR/main.c:102: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Scr_WCAN_Interrupt'
;------------------------------------------------------------
;	../SCR/main.c:104: void Scr_WCAN_Interrupt(void) __interrupt (ECAN)
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
;	../SCR/main.c:106: Scr_IsrCounter1++;
	mov	dptr,#_Scr_IsrCounter1
	movx	a,@dptr
	inc	a
	movx	@dptr,a
;	../SCR/main.c:107: Scr_WakeupReason = 0x01u;
	mov	dptr,#_Scr_WakeupReason
	mov	a,#0x01
	movx	@dptr,a
.00122:
;	../SCR/main.c:108: }
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
;	../SCR/main.c:110: void Scr_NMIECC_Interrupt(void) __interrupt (NMIRAMECC)
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
;	../SCR/main.c:112: Scr_IsrCounter2++;
	mov	dptr,#_Scr_IsrCounter2
	movx	a,@dptr
	inc	a
	movx	@dptr,a
;	../SCR/main.c:113: Scr_WakeupReason = 0x02u;
	mov	dptr,#_Scr_WakeupReason
	mov	a,#0x02
	movx	@dptr,a
.00124:
;	../SCR/main.c:114: }
	pop	dph
	pop	dpl
	pop	acc
	reti
;	eliminated unneeded mov psw,# (no regs used in bank)
;	eliminated unneeded push/pop not_psw
;	eliminated unneeded push/pop b
