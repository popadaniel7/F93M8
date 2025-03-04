;**********************************************************************************************************************
;
; @file     startup_tle989x.s
; @brief    CMSIS Core Device Startup File for
;           Infineon TLE988x and TLE989x Device Series
; @version  V0.4.0
; @date     11. Nov 2021
;
; Copyright (c) Infineon Technologies AG
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
; following conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
;   disclaimer.
;
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
;   following disclaimer in the documentation and/or other materials provided with the distribution.
;
;   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
;   products derived from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
; INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
; WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
; USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;*********************************************************************************************************************/

;*******************************************************************************
;                       Author(s) Identity                                    **
;*******************************************************************************
;  Initials     Name                                                          **
;  ---------------------------------------------------------------------------**
;  DM           Daniel Mysliwitz                                              **
;  BG           Blandine Guillot                                              **
;  JO           Julia Ott                                                     **
;******************************************************************************/

;*******************************************************************************
;                       Revision Control History                              **
;*******************************************************************************
;  V0.1.0: 2020-03-03, JO:   Initial version                                  **
;  V0.1.1: 2020-08-25, JO:   Renamed SystemInit to System_init                **
;                            Corrected name of NVIC_IRQx_Handler (0-31)       **
;  V0.1.2: 2020-09-11, DM:   Added NAC/NAD and SECBOOT_KEY                    **
;  V0.1.3: 2020-10-09, JO:   Corrected Offset of Vector Table                 **
;  V0.2.0: 2020-10-15, JO:   EP-525: Moved vector table to address 0x11000100,**
;                            keep __initial_sp and Reset_Handler also at the  **
;                            original addresses (Offset 0x80) for the BootROM **
;  V0.2.1: 2020-11-11, JO:   EP-582: Renamed System_init to SystemInit        **
;  V0.3.0: 2021-04-09, JO:   EP-753: Applied FLASH1_CACHE_EN setting from     **
;                            Config Wizard                                    **
;  V0.3.1: 2021-06-25, JO:   EP-851: Updated code to apply Cache En/Dis       **
;                            setting to remove faulty behavior with           **
;                            J-Link Debugger                                  **
;  V0.3.2: 2021-07-12, BG:   EP-716: Updated .inc filename                    **
;  V0.3.3: 2021-11-11, JO:   EP-937: Updated copyright and branding           **
;  V0.4.0: 2021-11-11, JO:   EP-977: Added checks to apply CACHE_EN setting   **
;                            only when PC (MSP/PSP) doesn't point to Flash1   **
;******************************************************************************/

Stack_Size      EQU     0x200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp

; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                THUMB
                PRESERVE8

                
;*******************************************************************************
; Fill-up the Vector Table entries with the exceptions ISR address
;*******************************************************************************
                AREA    RESET, DATA, READONLY
                INCLUDE bsl_defines_ARM.inc
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

                ; First page
                DCD     BSL_NAD_NAC                ; 0x11000000: NAC_NAD
                DCD     0                          ; 0x11000004
                DCD     0                          ; 0x11000008: Secure Boot Hash0
                DCD     0                          ; 0x1100000C: Secure Boot Hash0
                DCD     0                          ; 0x11000010: Secure Boot Hash0
                DCD     0                          ; 0x11000014: Secure Boot Hash0
                DCD     0                          ; 0x11000018: Secure Boot Size
                DCD     SECBOOT_KEY                ; 0x1100001C: Secure Boot Key
                DCD     0                          ; 0x11000020
                DCD     0                          ; 0x11000024
                DCD     0                          ; 0x11000028
                DCD     0                          ; 0x1100002C
                DCD     0                          ; 0x11000030
                DCD     0                          ; 0x11000034
                DCD     0                          ; 0x11000038
                DCD     0                          ; 0x1100003C
                DCD     0                          ; 0x11000040
                DCD     0                          ; 0x11000044
                DCD     0                          ; 0x11000048
                DCD     0                          ; 0x1100004C
                DCD     0                          ; 0x11000050
                DCD     0                          ; 0x11000054
                DCD     0                          ; 0x11000058
                DCD     0                          ; 0x1100005C
                DCD     0                          ; 0x11000060
                DCD     0                          ; 0x11000064
                DCD     0                          ; 0x11000068
                DCD     0                          ; 0x1100006C
                DCD     0                          ; 0x11000070
                DCD     0                          ; 0x11000074
                DCD     0                          ; 0x11000078
                DCD     0                          ; 0x1100007C

                ; Second page
                DCD     __initial_sp               ; 0x11000080
                DCD     Reset_Handler              ; 0x11000084
                DCD     0                          ; 0x11000088
                DCD     0                          ; 0x1100008C
                DCD     0                          ; 0x11000090
                DCD     0                          ; 0x11000094
                DCD     0                          ; 0x11000098
                DCD     0                          ; 0x1100009C
                DCD     0                          ; 0x110000A0
                DCD     0                          ; 0x110000A4
                DCD     0                          ; 0x110000A8
                DCD     0                          ; 0x110000AC
                DCD     0                          ; 0x110000B0
                DCD     0                          ; 0x110000B4
                DCD     0                          ; 0x110000B8
                DCD     0                          ; 0x110000BC
                DCD     0                          ; 0x110000C0
                DCD     0                          ; 0x110000C4
                DCD     0                          ; 0x110000C8
                DCD     0                          ; 0x110000CC
                DCD     0                          ; 0x110000D0
                DCD     0                          ; 0x110000D4
                DCD     0                          ; 0x110000D8
                DCD     0                          ; 0x110000DC
                DCD     0                          ; 0x110000E0
                DCD     0                          ; 0x110000E4
                DCD     0                          ; 0x110000E8
                DCD     0                          ; 0x110000EC
                DCD     0                          ; 0x110000F0
                DCD     0                          ; 0x110000F4
                DCD     0                          ; 0x110000F8
                DCD     0                          ; 0x110000FC


                ; Third page, starts at 0x11000100: Vector table
__Vectors       DCD     __initial_sp
                DCD     Reset_Handler
                DCD     NMI_Handler                ; NMI Handler
                DCD     HardFault_Handler          ; Hard Fault Handler
                DCD     MemManage_Handler          ; MPU Fault Handler
                DCD     BusFault_Handler           ; Bus Fault Handler
                DCD     UsageFault_Handler         ; Usage Fault Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     SVC_Handler                ; SVCall Handler
                DCD     DebugMon_Handler           ; Debug Monitor Handler
                DCD     0                          ; Reserved
                DCD     PendSV_Handler             ; PendSV Handler
                DCD     SysTick_Handler            ; SysTick Handler

                ; External Interrupts
                DCD     NVIC_IRQ0_Handler         ; 0: PMU, BDRV, CSC, ARVG
                DCD     NVIC_IRQ1_Handler         ; 1: PMU, BDRV, CSC, ARVG
                DCD     NVIC_IRQ2_Handler         ; 2: CCU7
                DCD     NVIC_IRQ3_Handler         ; 3: CCU7
                DCD     NVIC_IRQ4_Handler         ; 4: CCU7
                DCD     NVIC_IRQ5_Handler         ; 5: CCU7
                DCD     0x000000c1                ; 6: MEMCTRL
                DCD     NVIC_IRQ7_Handler         ; 7: GPT12E
                DCD     NVIC_IRQ8_Handler         ; 8: GPT12E
                DCD     NVIC_IRQ9_Handler         ; 9: Timer2
                DCD     NVIC_IRQ10_Handler        ; 10: ADC2
                DCD     NVIC_IRQ11_Handler        ; 11: ADC2
                DCD     NVIC_IRQ12_Handler        ; 12: MON
                DCD     NVIC_IRQ13_Handler        ; 13: MON
                DCD     NVIC_IRQ14_Handler        ; 14: ADC1
                DCD     NVIC_IRQ15_Handler        ; 15: ADC1
                DCD     NVIC_IRQ16_Handler        ; 16: ADC1
                DCD     NVIC_IRQ17_Handler        ; 17: ADC1
                DCD     NVIC_IRQ18_Handler        ; 18: BEMF, SDADC
                DCD     NVIC_IRQ19_Handler        ; 19: BEMF, SDADC
                DCD     NVIC_IRQ20_Handler        ; 20: EXTINT
                DCD     NVIC_IRQ21_Handler        ; 21: EXTINT
                DCD     NVIC_IRQ22_Handler        ; 22: UART0/1, LIN
                DCD     NVIC_IRQ23_Handler        ; 23: UART0/1, LIN
                DCD     NVIC_IRQ24_Handler        ; 24: SSC0/1
                DCD     NVIC_IRQ25_Handler        ; 25: SSC0/1
                DCD     NVIC_IRQ26_Handler        ; 26: MultiCAN
                DCD     NVIC_IRQ27_Handler        ; 27: MultiCAN
                DCD     NVIC_IRQ28_Handler        ; 28: MultiCAN
                DCD     NVIC_IRQ29_Handler        ; 29: DMA
                DCD     NVIC_IRQ30_Handler        ; 30: DMA
                DCD     NVIC_IRQ31_Handler        ; 31: Timer21


__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

;-------------------------------------------------------------------------------
; Reset Handler
;
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

; CACHE_EN must not be applied when PC is in Flash 1. Load PC to R2 for checking
				MOV     R2,PC
; compare the PC value with FLASH1 range
FLASH1_BEGIN EQU 0x12002000
FLASH1_END EQU 0x1203FFFF
				; PC <  FLASH1_BEGIN --> for sure not in FLASH1 --> apply_cache_en_setting
				LDR     R3, =FLASH1_BEGIN
                CMP 	R2, R3
                BLT     apply_cache_en_setting
				; else PC <  FLASH1_END --> in range of FLASH1 --> continue_with_systeminit
				LDR     R3, =FLASH1_END
                CMP 	R2, R3
                BLT     continue_with_systeminit

; Apply Cache en/dis setting 
apply_cache_en_setting
; address of MEMCTRL->MEMCONTROL.reg is 0x48044040
STARTUP_MEMCTRL_MEMCONTROL_ADDR EQU 0x48044040
                LDR     R0, =STARTUP_MEMCTRL_MEMCONTROL_ADDR
                LDR     R1, [R0, #0x00]
                ORR     R1, R1, #FLASH1_CACHE_EN
                STR     R1, [R0, #0x00]
				
; default reset handler content: call SystemInit and __main
continue_with_systeminit
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP

;-------------------------------------------------------------------------------
; Dummy Exception Handlers (infinite loops which can be modified)                
;
SVC_Handler_main\
                PROC                              
                EXPORT  SVC_Handler_main            [WEAK]
                B       .
                ENDP
NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                MOVS    R0, #4
                MOV     R1, LR
                TST     R0, R1
                BEQ     stacking_used_MSP
                MRS     R0, PSP ; first parameter - stacking was using PSP
                LDR     R1, =SVC_Handler_main
                BX      R1
stacking_used_MSP
                MRS     R0, MSP ; first parameter - stacking was using MSP
                LDR     R1, =SVC_Handler_main
                BX      R1
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT  NVIC_IRQ0_Handler            [WEAK]
                EXPORT  NVIC_IRQ1_Handler            [WEAK]
                EXPORT  NVIC_IRQ2_Handler            [WEAK]
                EXPORT  NVIC_IRQ3_Handler            [WEAK]
                EXPORT  NVIC_IRQ4_Handler            [WEAK]
                EXPORT  NVIC_IRQ5_Handler            [WEAK]
                EXPORT  NVIC_IRQ6_Handler            [WEAK]
                EXPORT  NVIC_IRQ7_Handler            [WEAK]
                EXPORT  NVIC_IRQ8_Handler            [WEAK]
                EXPORT  NVIC_IRQ9_Handler            [WEAK]
                EXPORT  NVIC_IRQ10_Handler           [WEAK]
                EXPORT  NVIC_IRQ11_Handler           [WEAK]
                EXPORT  NVIC_IRQ12_Handler           [WEAK]
                EXPORT  NVIC_IRQ13_Handler           [WEAK]
                EXPORT  NVIC_IRQ14_Handler           [WEAK]
                EXPORT  NVIC_IRQ15_Handler           [WEAK]
                EXPORT  NVIC_IRQ16_Handler           [WEAK]
                EXPORT  NVIC_IRQ17_Handler           [WEAK]
                EXPORT  NVIC_IRQ18_Handler           [WEAK]
                EXPORT  NVIC_IRQ19_Handler           [WEAK]
                EXPORT  NVIC_IRQ20_Handler           [WEAK]
                EXPORT  NVIC_IRQ21_Handler           [WEAK]
                EXPORT  NVIC_IRQ22_Handler           [WEAK]
                EXPORT  NVIC_IRQ23_Handler           [WEAK]
                EXPORT  NVIC_IRQ24_Handler           [WEAK]
                EXPORT  NVIC_IRQ25_Handler           [WEAK]
                EXPORT  NVIC_IRQ26_Handler           [WEAK]
                EXPORT  NVIC_IRQ27_Handler           [WEAK]
                EXPORT  NVIC_IRQ28_Handler           [WEAK]
                EXPORT  NVIC_IRQ29_Handler           [WEAK]
                EXPORT  NVIC_IRQ30_Handler           [WEAK]
                EXPORT  NVIC_IRQ31_Handler           [WEAK]

NVIC_IRQ0_Handler 
NVIC_IRQ1_Handler 
NVIC_IRQ2_Handler 
NVIC_IRQ3_Handler 
NVIC_IRQ4_Handler 
NVIC_IRQ5_Handler 
NVIC_IRQ6_Handler 
NVIC_IRQ7_Handler 
NVIC_IRQ8_Handler 
NVIC_IRQ9_Handler 
NVIC_IRQ10_Handler
NVIC_IRQ11_Handler
NVIC_IRQ12_Handler
NVIC_IRQ13_Handler
NVIC_IRQ14_Handler
NVIC_IRQ15_Handler
NVIC_IRQ16_Handler
NVIC_IRQ17_Handler
NVIC_IRQ18_Handler
NVIC_IRQ19_Handler
NVIC_IRQ20_Handler
NVIC_IRQ21_Handler
NVIC_IRQ22_Handler
NVIC_IRQ23_Handler
NVIC_IRQ24_Handler
NVIC_IRQ25_Handler
NVIC_IRQ26_Handler
NVIC_IRQ27_Handler
NVIC_IRQ28_Handler
NVIC_IRQ29_Handler
NVIC_IRQ30_Handler
NVIC_IRQ31_Handler
                B       .
                ENDP

;-------------------------------------------------------------------------------
; User Initial Stack & Heap
;
                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF

                END

