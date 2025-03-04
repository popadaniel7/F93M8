# 1 "RTE/Device/TLE9893_2QKW62S/isr_nvic_irq7_handler.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "RTE/Device/TLE9893_2QKW62S/isr_nvic_irq7_handler.c" 2
# 33 "RTE/Device/TLE9893_2QKW62S/isr_nvic_irq7_handler.c"
# 1 "./RTE/Device/TLE9893_2QKW62S/tle989x.h" 1
# 114 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef enum {

  Reset_IRQn = -15,
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  MemoryManagement_IRQn = -12,

  BusFault_IRQn = -11,

  UsageFault_IRQn = -10,
  SVCall_IRQn = -5,
  DebugMonitor_IRQn = -4,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,

  WARN_INP0_NVIC_IRQn = 0,
  WARN_INP1_NVIC_IRQn = 1,
  CCU7_INP0_NVIC_IRQn = 2,
  CCU7_INP1_NVIC_IRQn = 3,
  CCU7_INP2_NVIC_IRQn = 4,
  CCU7_INP3_NVIC_IRQn = 5,
  NVM_INP0_NVIC_IRQn = 6,
  GPT_INP0_NVIC_IRQn = 7,
  GPT_INP1_NVIC_IRQn = 8,
  T20_INP0_NVIC_IRQn = 9,
  ADC2_INP0_NVIC_IRQn = 10,
  ADC2_INP1_NVIC_IRQn = 11,
  MON_INP0_NVIC_IRQn = 12,
  MON_INP1_NVIC_IRQn = 13,
  ADC1_INP0_NVIC_IRQn = 14,
  ADC1_INP1_NVIC_IRQn = 15,
  ADC1_INP2_NVIC_IRQn = 16,
  ADC1_INP3_NVIC_IRQn = 17,
  BEMF_SDADC_INP0_NVIC_IRQn = 18,
  BEMF_SDADC_INP1_NVIC_IRQn = 19,
  EXT_INP0_NVIC_IRQn = 20,
  EXT_INP1_NVIC_IRQn = 21,
  UART_INP0_NVIC_IRQn = 22,
  UART_INP1_NVIC_IRQn = 23,
  SSC_INP0_NVIC_IRQn = 24,
  SSC_INP1_NVIC_IRQn = 25,
  MCAN_INP0_NVIC_IRQn = 26,
  MCAN_INP1_NVIC_IRQn = 27,
  MCAN_INP2_NVIC_IRQn = 28,
  DMA_INP0_NVIC_IRQn = 29,
  DMA_INP1_NVIC_IRQn = 30,
  T21_INP0_NVIC_IRQn = 31
} IRQn_Type;
# 179 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
# 1 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 1
# 29 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3





# 1 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\stdint.h" 1 3
# 56 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\stdint.h" 3
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;
typedef signed long long int int64_t;


typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;





typedef signed char int_least8_t;
typedef signed short int int_least16_t;
typedef signed int int_least32_t;
typedef signed long long int int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long long int uint_least64_t;




typedef signed int int_fast8_t;
typedef signed int int_fast16_t;
typedef signed int int_fast32_t;
typedef signed long long int int_fast64_t;


typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef unsigned long long int uint_fast64_t;






typedef signed int intptr_t;
typedef unsigned int uintptr_t;



typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
# 35 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 2 3
# 63 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
# 1 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_version.h" 1 3
# 29 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_version.h" 3
# 64 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 2 3
# 115 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
# 1 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_compiler.h" 1 3
# 47 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_compiler.h" 3
# 1 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 1 3
# 31 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
# 64 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpacked"

  struct __attribute__((packed)) T_UINT32 { uint32_t v; };
#pragma clang diagnostic pop



#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpacked"

  struct __attribute__((packed, aligned(1))) T_UINT16_WRITE { uint16_t v; };
#pragma clang diagnostic pop



#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpacked"

  struct __attribute__((packed, aligned(1))) T_UINT16_READ { uint16_t v; };
#pragma clang diagnostic pop



#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpacked"

  struct __attribute__((packed, aligned(1))) T_UINT32_WRITE { uint32_t v; };
#pragma clang diagnostic pop



#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpacked"

  struct __attribute__((packed, aligned(1))) T_UINT32_READ { uint32_t v; };
#pragma clang diagnostic pop
# 260 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 295 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint8_t __CLZ(uint32_t value)
{
# 306 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}
# 425 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __RRX(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 440 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint8_t __LDRBT(volatile uint8_t *ptr)
{
  uint32_t result;

  __asm volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*ptr) );
  return ((uint8_t) result);
}
# 455 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint16_t __LDRHT(volatile uint16_t *ptr)
{
  uint32_t result;

  __asm volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*ptr) );
  return ((uint16_t) result);
}
# 470 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __LDRT(volatile uint32_t *ptr)
{
  uint32_t result;

  __asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
  return(result);
}
# 485 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __STRBT(uint8_t value, volatile uint8_t *ptr)
{
  __asm volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 497 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __STRHT(uint16_t value, volatile uint16_t *ptr)
{
  __asm volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 509 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __STRT(uint32_t value, volatile uint32_t *ptr)
{
  __asm volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
# 737 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}
# 750 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}
# 762 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 792 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
  __builtin_arm_isb(0xF);
}
# 818 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static __inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static __inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static __inline uint32_t __get_PSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, psp" : "=r" (result) );
  return(result);
}
# 890 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : );
}
# 914 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __get_MSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 944 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}
# 995 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
# 1025 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 1053 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __enable_fault_irq(void)
{
  __asm volatile ("cpsie f" : : : "memory");
}







__attribute__((always_inline)) static __inline void __disable_fault_irq(void)
{
  __asm volatile ("cpsid f" : : : "memory");
}







__attribute__((always_inline)) static __inline uint32_t __get_BASEPRI(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, basepri" : "=r" (result) );
  return(result);
}
# 1105 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_BASEPRI(uint32_t basePri)
{
  __asm volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}
# 1130 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  __asm volatile ("MSR basepri_max, %0" : : "r" (basePri) : "memory");
}







__attribute__((always_inline)) static __inline uint32_t __get_FAULTMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}
# 1171 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 48 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/cmsis_compiler.h" 2 3
# 116 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 2 3
# 211 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef union
{
  struct
  {
    uint32_t _reserved0:27;
    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} APSR_Type;
# 245 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:23;
  } b;
  uint32_t w;
} IPSR_Type;
# 263 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:1;
    uint32_t ICI_IT_1:6;
    uint32_t _reserved1:8;
    uint32_t T:1;
    uint32_t ICI_IT_2:2;
    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} xPSR_Type;
# 314 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef union
{
  struct
  {
    uint32_t nPRIV:1;
    uint32_t SPSEL:1;
    uint32_t _reserved1:30;
  } b;
  uint32_t w;
} CONTROL_Type;
# 345 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
  volatile uint32_t ISER[8U];
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];
        uint32_t RESERVED1[24U];
  volatile uint32_t ISPR[8U];
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];
        uint32_t RESERVED4[56U];
  volatile uint8_t IP[240U];
        uint32_t RESERVED5[644U];
  volatile uint32_t STIR;
} NVIC_Type;
# 379 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
  volatile const uint32_t CPUID;
  volatile uint32_t ICSR;
  volatile uint32_t VTOR;
  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
  volatile uint8_t SHP[12U];
  volatile uint32_t SHCSR;
  volatile uint32_t CFSR;
  volatile uint32_t HFSR;
  volatile uint32_t DFSR;
  volatile uint32_t MMFAR;
  volatile uint32_t BFAR;
  volatile uint32_t AFSR;
  volatile const uint32_t PFR[2U];
  volatile const uint32_t DFR;
  volatile const uint32_t ADR;
  volatile const uint32_t MMFR[4U];
  volatile const uint32_t ISAR[5U];
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;
} SCB_Type;
# 660 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const uint32_t ICTR;

  volatile uint32_t ACTLR;



} SCnSCB_Type;
# 706 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile const uint32_t CALIB;
} SysTick_Type;
# 758 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
  volatile union
  {
    volatile uint8_t u8;
    volatile uint16_t u16;
    volatile uint32_t u32;
  } PORT [32U];
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;
        uint32_t RESERVED3[32U];
        uint32_t RESERVED4[43U];
  volatile uint32_t LAR;
  volatile const uint32_t LSR;
        uint32_t RESERVED5[6U];
  volatile const uint32_t PID4;
  volatile const uint32_t PID5;
  volatile const uint32_t PID6;
  volatile const uint32_t PID7;
  volatile const uint32_t PID0;
  volatile const uint32_t PID1;
  volatile const uint32_t PID2;
  volatile const uint32_t PID3;
  volatile const uint32_t CID0;
  volatile const uint32_t CID1;
  volatile const uint32_t CID2;
  volatile const uint32_t CID3;
} ITM_Type;
# 846 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t CYCCNT;
  volatile uint32_t CPICNT;
  volatile uint32_t EXCCNT;
  volatile uint32_t SLEEPCNT;
  volatile uint32_t LSUCNT;
  volatile uint32_t FOLDCNT;
  volatile const uint32_t PCSR;
  volatile uint32_t COMP0;
  volatile uint32_t MASK0;
  volatile uint32_t FUNCTION0;
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;
  volatile uint32_t MASK1;
  volatile uint32_t FUNCTION1;
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;
  volatile uint32_t MASK2;
  volatile uint32_t FUNCTION2;
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;
  volatile uint32_t MASK3;
  volatile uint32_t FUNCTION3;
} DWT_Type;
# 993 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
  volatile const uint32_t SSPSR;
  volatile uint32_t CSPSR;
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;
        uint32_t RESERVED2[131U];
  volatile const uint32_t FFSR;
  volatile uint32_t FFCR;
  volatile const uint32_t FSCR;
        uint32_t RESERVED3[759U];
  volatile const uint32_t TRIGGER;
  volatile const uint32_t FIFO0;
  volatile const uint32_t ITATBCTR2;
        uint32_t RESERVED4[1U];
  volatile const uint32_t ITATBCTR0;
  volatile const uint32_t FIFO1;
  volatile uint32_t ITCTRL;
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;
  volatile uint32_t CLAIMCLR;
        uint32_t RESERVED7[8U];
  volatile const uint32_t DEVID;
  volatile const uint32_t DEVTYPE;
} TPI_Type;
# 1251 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
typedef struct
{
  volatile uint32_t DHCSR;
  volatile uint32_t DCRSR;
  volatile uint32_t DCRDR;
  volatile uint32_t DEMCR;
} CoreDebug_Type;
# 1477 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);

  reg_value = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));
  reg_value = (reg_value |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U) );
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = reg_value;
}







static __inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}
# 1508 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    __asm volatile("":::"memory");
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __asm volatile("":::"memory");
  }
}
# 1527 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 1546 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __builtin_arm_dsb(0xF);
    __builtin_arm_isb(0xF);
  }
}
# 1565 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 1584 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
# 1599 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
# 1616 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 1638 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)] = (uint8_t)((priority << (8U - 5)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 5)) & (uint32_t)0xFFUL);
  }
}
# 1660 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)] >> (8U - 5)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] >> (8U - 5)));
  }
}
# 1685 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(5)) ? (uint32_t)(5) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(5)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(5));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority & (uint32_t)((1UL << (SubPriorityBits )) - 1UL)))
         );
}
# 1712 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(5)) ? (uint32_t)(5) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(5)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(5));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority = (Priority ) & (uint32_t)((1UL << (SubPriorityBits )) - 1UL);
}
# 1735 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;

}
# 1751 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];
}






__attribute__((__noreturn__)) static __inline void __NVIC_SystemReset(void)
{
  __builtin_arm_dsb(0xF);

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = (uint32_t)((0x5FAUL << 16U) |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U) );
  __builtin_arm_dsb(0xF);

  for(;;)
  {
    __builtin_arm_nop();
  }
}
# 1805 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t SCB_GetFPUType(void)
{
    return 0U;
}
# 1836 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (uint32_t)(ticks - 1UL);
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 5) - 1UL);
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL = 0UL;
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) |
                   (1UL << 1U) |
                   (1UL );
  return (0UL);
}
# 1866 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
extern volatile int32_t ITM_RxBuffer;
# 1878 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL ) != 0UL) )
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __builtin_arm_nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}
# 1899 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);
  }

  return (ch);
}
# 1919 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);
  }
  else
  {
    return (1);
  }
}
# 180 "./RTE/Device/TLE9893_2QKW62S/tle989x.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/system_tle989x.h" 1
# 85 "./RTE/Device/TLE9893_2QKW62S/system_tle989x.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/types.h" 1
# 99 "./RTE/Device/TLE9893_2QKW62S/types.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/error_codes.h" 1
# 61 "./RTE/Device/TLE9893_2QKW62S/error_codes.h"
# 1 "./RTE/_APP2\\RTE_Components.h" 1
# 62 "./RTE/Device/TLE9893_2QKW62S/error_codes.h" 2
# 100 "./RTE/Device/TLE9893_2QKW62S/types.h" 2
# 122 "./RTE/Device/TLE9893_2QKW62S/types.h"
# 1 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\stdbool.h" 1 3
# 123 "./RTE/Device/TLE9893_2QKW62S/types.h" 2
# 220 "./RTE/Device/TLE9893_2QKW62S/types.h"
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

typedef float float32;
typedef double float64;

typedef short FixPoint16;
typedef long FixPoint32;





  typedef FixPoint16 TStdReal;
  typedef FixPoint32 TLongStdReal;
# 253 "./RTE/Device/TLE9893_2QKW62S/types.h"
typedef struct StdRealComplex
{
  TStdReal imag;
  TStdReal real;
} TStdRealComplex;



typedef struct
{
  sint16 Real;
  sint16 Imag;
} TComplex;



typedef struct
{
  sint16 A;
  sint16 B;
} TPhaseCurr;
# 86 "./RTE/Device/TLE9893_2QKW62S/system_tle989x.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/cmsis_misra.h" 1
# 71 "./RTE/Device/TLE9893_2QKW62S/cmsis_misra.h"
# 1 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 1
# 29 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\core_cm3.h" 3
# 72 "./RTE/Device/TLE9893_2QKW62S/cmsis_misra.h" 2
# 94 "./RTE/Device/TLE9893_2QKW62S/cmsis_misra.h"
static __inline sint32 CMSIS_Irq_Dis(void);




static __inline void CMSIS_Irq_En(void);




static __inline void CMSIS_NOP(void);




static __inline void CMSIS_WFE(void);




static __inline void CMSIS_SEV(void);






static __inline sint32 CMSIS_Irq_Dis(void)
{


  __disable_irq();
  return 0;
}

static __inline void CMSIS_Irq_En(void)
{


  __enable_irq();
}

static __inline void CMSIS_NOP(void)
{


  __builtin_arm_nop();
}

static __inline void CMSIS_WFE(void)
{


  __builtin_arm_wfe();
}

static __inline void CMSIS_SEV(void)
{


  __builtin_arm_sev();
}
# 87 "./RTE/Device/TLE9893_2QKW62S/system_tle989x.h" 2
# 101 "./RTE/Device/TLE9893_2QKW62S/system_tle989x.h"
void SystemInit(void);
# 181 "./RTE/Device/TLE9893_2QKW62S/tle989x.h" 2
# 204 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#pragma clang diagnostic ignored "-Wnested-anon-types"
# 243 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
            uint32_t : 4;
      volatile uint32_t ISTE : 1;
            uint32_t : 26;
    } bit;
  } GLOBCONF;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CLKDIV : 4;
            uint32_t : 28;
    } bit;
  } CLKCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SUSEN : 1;
      volatile uint32_t SUSMOD : 1;
            uint32_t : 30;
    } bit;
  } SUSCTR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t STAT : 1;
      volatile const uint32_t READY : 1;
            uint32_t : 30;
    } bit;
  } SUSSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
      volatile uint32_t COLLCFG : 1;
      volatile uint32_t WFRCFG : 1;
      volatile uint32_t TRGSEL : 4;
      volatile uint32_t GTSEL : 2;
      volatile uint32_t TRGSW : 1;
      volatile uint32_t GTSW : 1;
            uint32_t : 16;
    } bit;
  } SQCFG0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL1 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL2 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL3 : 5;
            uint32_t : 3;
    } bit;
  } SQSLOT0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
      volatile uint32_t COLLCFG : 1;
      volatile uint32_t WFRCFG : 1;
      volatile uint32_t TRGSEL : 4;
      volatile uint32_t GTSEL : 2;
      volatile uint32_t TRGSW : 1;
      volatile uint32_t GTSW : 1;
            uint32_t : 16;
    } bit;
  } SQCFG1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL1 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL2 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL3 : 5;
            uint32_t : 3;
    } bit;
  } SQSLOT1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
      volatile uint32_t COLLCFG : 1;
      volatile uint32_t WFRCFG : 1;
      volatile uint32_t TRGSEL : 4;
      volatile uint32_t GTSEL : 2;
      volatile uint32_t TRGSW : 1;
      volatile uint32_t GTSW : 1;
            uint32_t : 16;
    } bit;
  } SQCFG2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL1 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL2 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL3 : 5;
            uint32_t : 3;
    } bit;
  } SQSLOT2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
      volatile uint32_t COLLCFG : 1;
      volatile uint32_t WFRCFG : 1;
      volatile uint32_t TRGSEL : 4;
      volatile uint32_t GTSEL : 2;
      volatile uint32_t TRGSW : 1;
      volatile uint32_t GTSW : 1;
            uint32_t : 16;
    } bit;
  } SQCFG3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL1 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL2 : 5;
            uint32_t : 3;
      volatile uint32_t CHSEL3 : 5;
            uint32_t : 3;
    } bit;
  } SQSLOT3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SQ0 : 1;
      volatile uint32_t SQ1 : 1;
      volatile uint32_t SQ2 : 1;
      volatile uint32_t SQ3 : 1;
      volatile uint32_t WFR0 : 1;
      volatile uint32_t WFR1 : 1;
      volatile uint32_t WFR2 : 1;
      volatile uint32_t WFR3 : 1;
      volatile uint32_t COLL0 : 1;
      volatile uint32_t COLL1 : 1;
      volatile uint32_t COLL2 : 1;
      volatile uint32_t COLL3 : 1;
            uint32_t : 4;
      volatile uint32_t SQNUM : 3;
            uint32_t : 13;
    } bit;
  } SQSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SQ0CLR : 1;
      volatile uint32_t SQ1CLR : 1;
      volatile uint32_t SQ2CLR : 1;
      volatile uint32_t SQ3CLR : 1;
      volatile uint32_t WFR0CLR : 1;
      volatile uint32_t WFR1CLR : 1;
      volatile uint32_t WFR2CLR : 1;
      volatile uint32_t WFR3CLR : 1;
      volatile uint32_t COLL0CLR : 1;
      volatile uint32_t COLL1CLR : 1;
      volatile uint32_t COLL2CLR : 1;
      volatile uint32_t COLL3CLR : 1;
            uint32_t : 20;
    } bit;
  } SQSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SQ0SET : 1;
      volatile uint32_t SQ1SET : 1;
      volatile uint32_t SQ2SET : 1;
      volatile uint32_t SQ3SET : 1;
      volatile uint32_t WFR0SET : 1;
      volatile uint32_t WFR1SET : 1;
      volatile uint32_t WFR2SET : 1;
      volatile uint32_t WFR3SET : 1;
      volatile uint32_t COLL0SET : 1;
      volatile uint32_t COLL1SET : 1;
      volatile uint32_t COLL2SET : 1;
      volatile uint32_t COLL3SET : 1;
            uint32_t : 20;
    } bit;
  } SQSTATSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INSEL : 5;
            uint32_t : 3;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 3;
      volatile uint32_t CMPSEL : 3;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 8;
    } bit;
  } CHCFG19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CH0 : 1;
      volatile uint32_t CH1 : 1;
      volatile uint32_t CH2 : 1;
      volatile uint32_t CH3 : 1;
      volatile uint32_t CH4 : 1;
      volatile uint32_t CH5 : 1;
      volatile uint32_t CH6 : 1;
      volatile uint32_t CH7 : 1;
      volatile uint32_t CH8 : 1;
      volatile uint32_t CH9 : 1;
      volatile uint32_t CH10 : 1;
      volatile uint32_t CH11 : 1;
      volatile uint32_t CH12 : 1;
      volatile uint32_t CH13 : 1;
      volatile uint32_t CH14 : 1;
      volatile uint32_t CH15 : 1;
      volatile uint32_t CH16 : 1;
      volatile uint32_t CH17 : 1;
      volatile uint32_t CH18 : 1;
      volatile uint32_t CH19 : 1;
            uint32_t : 4;
      volatile uint32_t CHNUM : 5;
            uint32_t : 3;
    } bit;
  } CHSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CH0CLR : 1;
      volatile uint32_t CH1CLR : 1;
      volatile uint32_t CH2CLR : 1;
      volatile uint32_t CH3CLR : 1;
      volatile uint32_t CH4CLR : 1;
      volatile uint32_t CH5CLR : 1;
      volatile uint32_t CH6CLR : 1;
      volatile uint32_t CH7CLR : 1;
      volatile uint32_t CH8CLR : 1;
      volatile uint32_t CH9CLR : 1;
      volatile uint32_t CH10CLR : 1;
      volatile uint32_t CH11CLR : 1;
      volatile uint32_t CH12CLR : 1;
      volatile uint32_t CH13CLR : 1;
      volatile uint32_t CH14CLR : 1;
      volatile uint32_t CH15CLR : 1;
      volatile uint32_t CH16CLR : 1;
      volatile uint32_t CH17CLR : 1;
      volatile uint32_t CH18CLR : 1;
      volatile uint32_t CH19CLR : 1;
            uint32_t : 12;
    } bit;
  } CHSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CH0SET : 1;
      volatile uint32_t CH1SET : 1;
      volatile uint32_t CH2SET : 1;
      volatile uint32_t CH3SET : 1;
      volatile uint32_t CH4SET : 1;
      volatile uint32_t CH5SET : 1;
      volatile uint32_t CH6SET : 1;
      volatile uint32_t CH7SET : 1;
      volatile uint32_t CH8SET : 1;
      volatile uint32_t CH9SET : 1;
      volatile uint32_t CH10SET : 1;
      volatile uint32_t CH11SET : 1;
      volatile uint32_t CH12SET : 1;
      volatile uint32_t CH13SET : 1;
      volatile uint32_t CH14SET : 1;
      volatile uint32_t CH15SET : 1;
      volatile uint32_t CH16SET : 1;
      volatile uint32_t CH17SET : 1;
      volatile uint32_t CH18SET : 1;
      volatile uint32_t CH19SET : 1;
            uint32_t : 12;
    } bit;
  } CHSTATSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TCONF : 2;
      volatile uint32_t OVERS : 2;
      volatile uint32_t STC : 4;
      volatile uint32_t SESP : 1;
            uint32_t : 1;
      volatile uint32_t MSBD : 1;
      volatile uint32_t PCAL : 1;
      volatile uint32_t BWD : 2;
      volatile uint32_t BWD_HI_CUR : 1;
            uint32_t : 17;
    } bit;
  } CONVCFG0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TCONF : 2;
      volatile uint32_t OVERS : 2;
      volatile uint32_t STC : 4;
      volatile uint32_t SESP : 1;
            uint32_t : 1;
      volatile uint32_t MSBD : 1;
      volatile uint32_t PCAL : 1;
      volatile uint32_t BWD : 2;
      volatile uint32_t BWD_HI_CUR : 1;
            uint32_t : 17;
    } bit;
  } CONVCFG1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TCONF : 2;
      volatile uint32_t OVERS : 2;
      volatile uint32_t STC : 4;
      volatile uint32_t SESP : 1;
            uint32_t : 1;
      volatile uint32_t MSBD : 1;
      volatile uint32_t PCAL : 1;
      volatile uint32_t BWD : 2;
      volatile uint32_t BWD_HI_CUR : 1;
            uint32_t : 17;
    } bit;
  } CONVCFG2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TCONF : 2;
      volatile uint32_t OVERS : 2;
      volatile uint32_t STC : 4;
      volatile uint32_t SESP : 1;
            uint32_t : 1;
      volatile uint32_t MSBD : 1;
      volatile uint32_t PCAL : 1;
      volatile uint32_t BWD : 2;
      volatile uint32_t BWD_HI_CUR : 1;
            uint32_t : 17;
    } bit;
  } CONVCFG3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALEN0 : 1;
      volatile uint32_t CALEN1 : 1;
      volatile uint32_t CALEN2 : 1;
      volatile uint32_t CALEN3 : 1;
      volatile uint32_t CALEN4 : 1;
      volatile uint32_t CALEN5 : 1;
      volatile uint32_t CALEN6 : 1;
      volatile uint32_t CALEN7 : 1;
      volatile uint32_t CALEN8 : 1;
      volatile uint32_t CALEN9 : 1;
      volatile uint32_t CALEN10 : 1;
      volatile uint32_t CALEN11 : 1;
      volatile uint32_t CALEN12 : 1;
      volatile uint32_t CALEN13 : 1;
      volatile uint32_t CALEN14 : 1;
      volatile uint32_t CALEN15 : 1;
      volatile uint32_t CALEN16 : 1;
      volatile uint32_t CALEN17 : 1;
      volatile uint32_t CALEN18 : 1;
      volatile uint32_t CALEN19 : 1;
      volatile uint32_t CALEN20 : 1;
      volatile uint32_t CALEN21 : 1;
      volatile uint32_t CALEN22 : 1;
      volatile uint32_t CALEN23 : 1;
      volatile uint32_t CALEN24 : 1;
      volatile uint32_t CALEN25 : 1;
      volatile uint32_t CALEN26 : 1;
            uint32_t : 5;
    } bit;
  } CALEN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALPEN0 : 1;
      volatile uint32_t CALPEN1 : 1;
      volatile uint32_t CALPEN2 : 1;
      volatile uint32_t CALPEN3 : 1;
      volatile uint32_t CALPEN4 : 1;
      volatile uint32_t CALPEN5 : 1;
      volatile uint32_t CALPEN6 : 1;
      volatile uint32_t CALPEN7 : 1;
      volatile uint32_t CALPEN8 : 1;
      volatile uint32_t CALPEN9 : 1;
      volatile uint32_t CALPEN10 : 1;
      volatile uint32_t CALPEN11 : 1;
      volatile uint32_t CALPEN12 : 1;
      volatile uint32_t CALPEN13 : 1;
      volatile uint32_t CALPEN14 : 1;
      volatile uint32_t CALPEN15 : 1;
      volatile uint32_t CALPEN16 : 1;
      volatile uint32_t CALPEN17 : 1;
      volatile uint32_t CALPEN18 : 1;
      volatile uint32_t CALPEN19 : 1;
      volatile uint32_t CALPEN20 : 1;
      volatile uint32_t CALPEN21 : 1;
      volatile uint32_t CALPEN22 : 1;
      volatile uint32_t CALPEN23 : 1;
      volatile uint32_t CALPEN24 : 1;
      volatile uint32_t CALPEN25 : 1;
      volatile uint32_t CALPEN26 : 1;
            uint32_t : 5;
    } bit;
  } CALPEN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t COEF_A0 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A1 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A2 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A3 : 2;
            uint32_t : 18;
    } bit;
  } FILTCFG;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 16;
            uint32_t : 16;
    } bit;
  } FIL0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 16;
            uint32_t : 16;
    } bit;
  } FIL1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 16;
            uint32_t : 16;
    } bit;
  } FIL2;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 16;
            uint32_t : 16;
    } bit;
  } FIL3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FIL0 : 1;
      volatile uint32_t FIL1 : 1;
      volatile uint32_t FIL2 : 1;
      volatile uint32_t FIL3 : 1;
            uint32_t : 28;
    } bit;
  } FILSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FIL0CLR : 1;
      volatile uint32_t FIL1CLR : 1;
      volatile uint32_t FIL2CLR : 1;
      volatile uint32_t FIL3CLR : 1;
            uint32_t : 28;
    } bit;
  } FILSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FIL0SET : 1;
      volatile uint32_t FIL1SET : 1;
      volatile uint32_t FIL2SET : 1;
      volatile uint32_t FIL3SET : 1;
            uint32_t : 28;
    } bit;
  } FILSTATSET;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES2;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES3;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES4;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES5;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES6;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES7;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES8;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES9;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES10;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES11;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES12;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES13;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES14;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES15;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES16;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES17;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES18;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 14;
            uint32_t : 1;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CMP_LO0_STS : 1;
      volatile uint32_t CMP_LO1_STS : 1;
      volatile uint32_t CMP_LO2_STS : 1;
      volatile uint32_t CMP_LO3_STS : 1;
      volatile uint32_t CMP_LO0_IS : 1;
      volatile uint32_t CMP_LO1_IS : 1;
      volatile uint32_t CMP_LO2_IS : 1;
      volatile uint32_t CMP_LO3_IS : 1;
      volatile const uint32_t CMP_LO : 4;
            uint32_t : 4;
      volatile uint32_t CMP_UP0_STS : 1;
      volatile uint32_t CMP_UP1_STS : 1;
      volatile uint32_t CMP_UP2_STS : 1;
      volatile uint32_t CMP_UP3_STS : 1;
      volatile uint32_t CMP_UP0_IS : 1;
      volatile uint32_t CMP_UP1_IS : 1;
      volatile uint32_t CMP_UP2_IS : 1;
      volatile uint32_t CMP_UP3_IS : 1;
      volatile const uint32_t CMP_UP : 4;
            uint32_t : 4;
    } bit;
  } CMPSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CMP_LO0_STSCLR : 1;
      volatile uint32_t CMP_LO1_STSCLR : 1;
      volatile uint32_t CMP_LO2_STSCLR : 1;
      volatile uint32_t CMP_LO3_STSCLR : 1;
      volatile uint32_t CMP_LO0_ISCLR : 1;
      volatile uint32_t CMP_LO1_ISCLR : 1;
      volatile uint32_t CMP_LO2_ISCLR : 1;
      volatile uint32_t CMP_LO3_ISCLR : 1;
            uint32_t : 8;
      volatile uint32_t CMP_UP0_STSCLR : 1;
      volatile uint32_t CMP_UP1_STSCLR : 1;
      volatile uint32_t CMP_UP2_STSCLR : 1;
      volatile uint32_t CMP_UP3_STSCLR : 1;
      volatile uint32_t CMP_UP0_ISCLR : 1;
      volatile uint32_t CMP_UP1_ISCLR : 1;
      volatile uint32_t CMP_UP2_ISCLR : 1;
      volatile uint32_t CMP_UP3_ISCLR : 1;
            uint32_t : 8;
    } bit;
  } CMPSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CMP_LO0_STSSET : 1;
      volatile uint32_t CMP_LO1_STSSET : 1;
      volatile uint32_t CMP_LO2_STSSET : 1;
      volatile uint32_t CMP_LO3_STSSET : 1;
      volatile uint32_t CMP_LO0_ISSET : 1;
      volatile uint32_t CMP_LO1_ISSET : 1;
      volatile uint32_t CMP_LO2_ISSET : 1;
      volatile uint32_t CMP_LO3_ISSET : 1;
            uint32_t : 8;
      volatile uint32_t CMP_UP0_STSSET : 1;
      volatile uint32_t CMP_UP1_STSSET : 1;
      volatile uint32_t CMP_UP2_STSSET : 1;
      volatile uint32_t CMP_UP3_STSSET : 1;
      volatile uint32_t CMP_UP0_ISSET : 1;
      volatile uint32_t CMP_UP1_ISSET : 1;
      volatile uint32_t CMP_UP2_ISSET : 1;
      volatile uint32_t CMP_UP3_ISSET : 1;
            uint32_t : 8;
    } bit;
  } CMPSTATSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IEN_CH0 : 1;
      volatile uint32_t IEN_CH1 : 1;
      volatile uint32_t IEN_CH2 : 1;
      volatile uint32_t IEN_CH3 : 1;
      volatile uint32_t IEN_CH4 : 1;
      volatile uint32_t IEN_CH5 : 1;
      volatile uint32_t IEN_CH6 : 1;
      volatile uint32_t IEN_CH7 : 1;
      volatile uint32_t IEN_CH8 : 1;
      volatile uint32_t IEN_CH9 : 1;
      volatile uint32_t IEN_CH10 : 1;
      volatile uint32_t IEN_CH11 : 1;
      volatile uint32_t IEN_CH12 : 1;
      volatile uint32_t IEN_CH13 : 1;
      volatile uint32_t IEN_CH14 : 1;
      volatile uint32_t IEN_CH15 : 1;
      volatile uint32_t IEN_CH16 : 1;
      volatile uint32_t IEN_CH17 : 1;
      volatile uint32_t IEN_CH18 : 1;
      volatile uint32_t IEN_CH19 : 1;
      volatile uint32_t IEN_SQ0 : 1;
      volatile uint32_t IEN_SQ1 : 1;
      volatile uint32_t IEN_SQ2 : 1;
      volatile uint32_t IEN_SQ3 : 1;
      volatile uint32_t IEN_LO0 : 1;
      volatile uint32_t IEN_LO1 : 1;
      volatile uint32_t IEN_LO2 : 1;
      volatile uint32_t IEN_LO3 : 1;
      volatile uint32_t IEN_UP0 : 1;
      volatile uint32_t IEN_UP1 : 1;
      volatile uint32_t IEN_UP2 : 1;
      volatile uint32_t IEN_UP3 : 1;
    } bit;
  } IEN0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IEN_COLL0 : 1;
      volatile uint32_t IEN_COLL1 : 1;
      volatile uint32_t IEN_COLL2 : 1;
      volatile uint32_t IEN_COLL3 : 1;
      volatile uint32_t IEN_WFR0 : 1;
      volatile uint32_t IEN_WFR1 : 1;
      volatile uint32_t IEN_WFR2 : 1;
      volatile uint32_t IEN_WFR3 : 1;
            uint32_t : 24;
    } bit;
  } IEN1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_CH0 : 2;
      volatile uint32_t INP_CH1 : 2;
      volatile uint32_t INP_CH2 : 2;
      volatile uint32_t INP_CH3 : 2;
      volatile uint32_t INP_CH4 : 2;
      volatile uint32_t INP_CH5 : 2;
      volatile uint32_t INP_CH6 : 2;
      volatile uint32_t INP_CH7 : 2;
      volatile uint32_t INP_CH8 : 2;
      volatile uint32_t INP_CH9 : 2;
      volatile uint32_t INP_CH10 : 2;
      volatile uint32_t INP_CH11 : 2;
      volatile uint32_t INP_CH12 : 2;
      volatile uint32_t INP_CH13 : 2;
      volatile uint32_t INP_CH14 : 2;
      volatile uint32_t INP_CH15 : 2;
    } bit;
  } INP0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_CH16 : 2;
      volatile uint32_t INP_CH17 : 2;
      volatile uint32_t INP_CH18 : 2;
      volatile uint32_t INP_CH19 : 2;
            uint32_t : 24;
    } bit;
  } INP1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_CMP_LO0 : 2;
      volatile uint32_t INP_CMP_LO1 : 2;
      volatile uint32_t INP_CMP_LO2 : 2;
      volatile uint32_t INP_CMP_LO3 : 2;
      volatile uint32_t INP_CMP_UP0 : 2;
      volatile uint32_t INP_CMP_UP1 : 2;
      volatile uint32_t INP_CMP_UP2 : 2;
      volatile uint32_t INP_CMP_UP3 : 2;
            uint32_t : 16;
    } bit;
  } INP2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_SQ0 : 2;
      volatile uint32_t INP_SQ1 : 2;
      volatile uint32_t INP_SQ2 : 2;
      volatile uint32_t INP_SQ3 : 2;
      volatile uint32_t INP_COLL0 : 2;
      volatile uint32_t INP_COLL1 : 2;
      volatile uint32_t INP_COLL2 : 2;
      volatile uint32_t INP_COLL3 : 2;
      volatile uint32_t INP_WFR0 : 2;
      volatile uint32_t INP_WFR1 : 2;
      volatile uint32_t INP_WFR2 : 2;
      volatile uint32_t INP_WFR3 : 2;
            uint32_t : 8;
    } bit;
  } INP3;
  volatile const uint32_t RESERVED[4];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ST_SQSEL : 3;
            uint32_t : 1;
      volatile uint32_t ST_TRGSEL : 3;
            uint32_t : 1;
      volatile uint32_t ST_GTGSEL : 3;
            uint32_t : 1;
      volatile uint32_t STE_SQSEL : 1;
      volatile uint32_t STE_TRGSEL : 1;
      volatile uint32_t STE_GTGSEL : 1;
            uint32_t : 1;
      volatile uint32_t ST_SQSW : 1;
      volatile uint32_t ST_TRGSW : 1;
      volatile uint32_t ST_GTGSW : 1;
            uint32_t : 1;
      volatile uint32_t STE_SQ : 1;
      volatile uint32_t STE_TRG : 1;
      volatile uint32_t STE_GTG : 1;
            uint32_t : 9;
    } bit;
  } SHDCTR;
  volatile const uint32_t RESERVED1[4];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 6;
            uint32_t : 10;
      volatile uint32_t CALGAIN : 10;
            uint32_t : 6;
    } bit;
  } CALAI26;
} ADC1_Type;
# 1825 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
            uint32_t : 1;
      volatile uint32_t ISTE : 1;
            uint32_t : 29;
    } bit;
  } GLOBCONF;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CLKDIV : 4;
            uint32_t : 28;
    } bit;
  } CLKCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SUSEN : 1;
      volatile uint32_t SUSMOD : 1;
            uint32_t : 30;
    } bit;
  } SUSCTR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t STAT : 1;
            uint32_t : 31;
    } bit;
  } SUSSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SQ0 : 1;
      volatile uint32_t SQ1 : 1;
      volatile uint32_t SQ2 : 1;
      volatile uint32_t SQ3 : 1;
            uint32_t : 4;
      volatile uint32_t COLL0 : 1;
      volatile uint32_t COLL1 : 1;
      volatile uint32_t COLL2 : 1;
      volatile uint32_t COLL3 : 1;
            uint32_t : 4;
      volatile uint32_t SQNUM : 3;
            uint32_t : 13;
    } bit;
  } SQSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SQ0CLR : 1;
      volatile uint32_t SQ1CLR : 1;
      volatile uint32_t SQ2CLR : 1;
      volatile uint32_t SQ3CLR : 1;
            uint32_t : 4;
      volatile uint32_t COLL0CLR : 1;
      volatile uint32_t COLL1CLR : 1;
      volatile uint32_t COLL2CLR : 1;
      volatile uint32_t COLL3CLR : 1;
            uint32_t : 20;
    } bit;
  } SQSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SQ0SET : 1;
      volatile uint32_t SQ1SET : 1;
      volatile uint32_t SQ2SET : 1;
      volatile uint32_t SQ3SET : 1;
            uint32_t : 4;
      volatile uint32_t COLL0SET : 1;
      volatile uint32_t COLL1SET : 1;
      volatile uint32_t COLL2SET : 1;
      volatile uint32_t COLL3SET : 1;
            uint32_t : 20;
    } bit;
  } SQSTATSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CH0 : 1;
      volatile uint32_t CH1 : 1;
      volatile uint32_t CH2 : 1;
      volatile uint32_t CH3 : 1;
      volatile uint32_t CH4 : 1;
      volatile uint32_t CH5 : 1;
      volatile uint32_t CH6 : 1;
      volatile uint32_t CH7 : 1;
      volatile uint32_t CH8 : 1;
      volatile uint32_t CH9 : 1;
      volatile uint32_t CH10 : 1;
      volatile uint32_t CH11 : 1;
      volatile uint32_t CH12 : 1;
      volatile uint32_t CH13 : 1;
      volatile uint32_t CH14 : 1;
            uint32_t : 9;
      volatile uint32_t CHNUM : 4;
            uint32_t : 4;
    } bit;
  } CHSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CH0CLR : 1;
      volatile uint32_t CH1CLR : 1;
      volatile uint32_t CH2CLR : 1;
      volatile uint32_t CH3CLR : 1;
      volatile uint32_t CH4CLR : 1;
      volatile uint32_t CH5CLR : 1;
      volatile uint32_t CH6CLR : 1;
      volatile uint32_t CH7CLR : 1;
      volatile uint32_t CH8CLR : 1;
      volatile uint32_t CH9CLR : 1;
      volatile uint32_t CH10CLR : 1;
      volatile uint32_t CH11CLR : 1;
      volatile uint32_t CH12CLR : 1;
      volatile uint32_t CH13CLR : 1;
      volatile uint32_t CH14CLR : 1;
            uint32_t : 17;
    } bit;
  } CHSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CH0SET : 1;
      volatile uint32_t CH1SET : 1;
      volatile uint32_t CH2SET : 1;
      volatile uint32_t CH3SET : 1;
      volatile uint32_t CH4SET : 1;
      volatile uint32_t CH5SET : 1;
      volatile uint32_t CH6SET : 1;
      volatile uint32_t CH7SET : 1;
      volatile uint32_t CH8SET : 1;
      volatile uint32_t CH9SET : 1;
      volatile uint32_t CH10SET : 1;
      volatile uint32_t CH11SET : 1;
      volatile uint32_t CH12SET : 1;
      volatile uint32_t CH13SET : 1;
      volatile uint32_t CH14SET : 1;
            uint32_t : 17;
    } bit;
  } CHSTATSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALEN0 : 1;
      volatile uint32_t CALEN1 : 1;
      volatile uint32_t CALEN2 : 1;
      volatile uint32_t CALEN3 : 1;
      volatile uint32_t CALEN4 : 1;
      volatile uint32_t CALEN5 : 1;
      volatile uint32_t CALEN6 : 1;
      volatile uint32_t CALEN7 : 1;
      volatile uint32_t CALEN8 : 1;
      volatile uint32_t CALEN9 : 1;
      volatile uint32_t CALEN10 : 1;
      volatile uint32_t CALEN11 : 1;
      volatile uint32_t CALEN12 : 1;
      volatile uint32_t CALEN13 : 1;
      volatile uint32_t CALEN14 : 1;
            uint32_t : 17;
    } bit;
  } CALEN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALPEN0 : 1;
      volatile uint32_t CALPEN1 : 1;
      volatile uint32_t CALPEN2 : 1;
      volatile uint32_t CALPEN3 : 1;
      volatile uint32_t CALPEN4 : 1;
      volatile uint32_t CALPEN5 : 1;
      volatile uint32_t CALPEN6 : 1;
      volatile uint32_t CALPEN7 : 1;
      volatile uint32_t CALPEN8 : 1;
      volatile uint32_t CALPEN9 : 1;
      volatile uint32_t CALPEN10 : 1;
      volatile uint32_t CALPEN11 : 1;
      volatile uint32_t CALPEN12 : 1;
      volatile uint32_t CALPEN13 : 1;
      volatile uint32_t CALPEN14 : 1;
            uint32_t : 17;
    } bit;
  } CALPEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL2;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL3;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL4;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL5;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL6;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t FILRESULT : 14;
            uint32_t : 18;
    } bit;
  } FIL7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FIL0 : 1;
      volatile uint32_t FIL1 : 1;
      volatile uint32_t FIL2 : 1;
      volatile uint32_t FIL3 : 1;
      volatile uint32_t FIL4 : 1;
      volatile uint32_t FIL5 : 1;
      volatile uint32_t FIL6 : 1;
      volatile uint32_t FIL7 : 1;
            uint32_t : 24;
    } bit;
  } FILSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FIL0CLR : 1;
      volatile uint32_t FIL1CLR : 1;
      volatile uint32_t FIL2CLR : 1;
      volatile uint32_t FIL3CLR : 1;
      volatile uint32_t FIL4CLR : 1;
      volatile uint32_t FIL5CLR : 1;
      volatile uint32_t FIL6CLR : 1;
      volatile uint32_t FIL7CLR : 1;
            uint32_t : 24;
    } bit;
  } FILSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FIL0SET : 1;
      volatile uint32_t FIL1SET : 1;
      volatile uint32_t FIL2SET : 1;
      volatile uint32_t FIL3SET : 1;
      volatile uint32_t FIL4SET : 1;
      volatile uint32_t FIL5SET : 1;
      volatile uint32_t FIL6SET : 1;
      volatile uint32_t FIL7SET : 1;
            uint32_t : 24;
    } bit;
  } FILSTATSET;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES2;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES3;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES4;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES5;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES6;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES7;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES8;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES9;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES10;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES11;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES12;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES13;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 12;
            uint32_t : 3;
      volatile const uint32_t VALID : 1;
            uint32_t : 16;
    } bit;
  } RES14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CMP_LO0_STS : 1;
      volatile uint32_t CMP_LO1_STS : 1;
      volatile uint32_t CMP_LO2_STS : 1;
      volatile uint32_t CMP_LO3_STS : 1;
      volatile uint32_t CMP_LO4_STS : 1;
      volatile uint32_t CMP_LO5_STS : 1;
      volatile uint32_t CMP_LO6_STS : 1;
      volatile uint32_t CMP_LO7_STS : 1;
      volatile uint32_t CMP_LO0_IS : 1;
      volatile uint32_t CMP_LO1_IS : 1;
      volatile uint32_t CMP_LO2_IS : 1;
      volatile uint32_t CMP_LO3_IS : 1;
      volatile uint32_t CMP_LO4_IS : 1;
      volatile uint32_t CMP_LO5_IS : 1;
      volatile uint32_t CMP_LO6_IS : 1;
      volatile uint32_t CMP_LO7_IS : 1;
      volatile uint32_t CMP_UP0_STS : 1;
      volatile uint32_t CMP_UP1_STS : 1;
      volatile uint32_t CMP_UP2_STS : 1;
      volatile uint32_t CMP_UP3_STS : 1;
      volatile uint32_t CMP_UP4_STS : 1;
      volatile uint32_t CMP_UP5_STS : 1;
      volatile uint32_t CMP_UP6_STS : 1;
      volatile uint32_t CMP_UP7_STS : 1;
      volatile uint32_t CMP_UP0_IS : 1;
      volatile uint32_t CMP_UP1_IS : 1;
      volatile uint32_t CMP_UP2_IS : 1;
      volatile uint32_t CMP_UP3_IS : 1;
      volatile uint32_t CMP_UP4_IS : 1;
      volatile uint32_t CMP_UP5_IS : 1;
      volatile uint32_t CMP_UP6_IS : 1;
      volatile uint32_t CMP_UP7_IS : 1;
    } bit;
  } CMPSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CMP_LO0_STSCLR : 1;
      volatile uint32_t CMP_LO1_STSCLR : 1;
      volatile uint32_t CMP_LO2_STSCLR : 1;
      volatile uint32_t CMP_LO3_STSCLR : 1;
      volatile uint32_t CMP_LO4_STSCLR : 1;
      volatile uint32_t CMP_LO5_STSCLR : 1;
      volatile uint32_t CMP_LO6_STSCLR : 1;
      volatile uint32_t CMP_LO7_STSCLR : 1;
      volatile uint32_t CMP_LO0_ISCLR : 1;
      volatile uint32_t CMP_LO1_ISCLR : 1;
      volatile uint32_t CMP_LO2_ISCLR : 1;
      volatile uint32_t CMP_LO3_ISCLR : 1;
      volatile uint32_t CMP_LO4_ISCLR : 1;
      volatile uint32_t CMP_LO5_ISCLR : 1;
      volatile uint32_t CMP_LO6_ISCLR : 1;
      volatile uint32_t CMP_LO7_ISCLR : 1;
      volatile uint32_t CMP_UP0_STSCLR : 1;
      volatile uint32_t CMP_UP1_STSCLR : 1;
      volatile uint32_t CMP_UP2_STSCLR : 1;
      volatile uint32_t CMP_UP3_STSCLR : 1;
      volatile uint32_t CMP_UP4_STSCLR : 1;
      volatile uint32_t CMP_UP5_STSCLR : 1;
      volatile uint32_t CMP_UP6_STSCLR : 1;
      volatile uint32_t CMP_UP7_STSCLR : 1;
      volatile uint32_t CMP_UP0_ISCLR : 1;
      volatile uint32_t CMP_UP1_ISCLR : 1;
      volatile uint32_t CMP_UP2_ISCLR : 1;
      volatile uint32_t CMP_UP3_ISCLR : 1;
      volatile uint32_t CMP_UP4_ISCLR : 1;
      volatile uint32_t CMP_UP5_ISCLR : 1;
      volatile uint32_t CMP_UP6_ISCLR : 1;
      volatile uint32_t CMP_UP7_ISCLR : 1;
    } bit;
  } CMPSTATCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CMP_LO0_STSSET : 1;
      volatile uint32_t CMP_LO1_STSSET : 1;
      volatile uint32_t CMP_LO2_STSSET : 1;
      volatile uint32_t CMP_LO3_STSSET : 1;
      volatile uint32_t CMP_LO4_STSSET : 1;
      volatile uint32_t CMP_LO5_STSSET : 1;
      volatile uint32_t CMP_LO6_STSSET : 1;
      volatile uint32_t CMP_LO7_STSSET : 1;
      volatile uint32_t CMP_LO0_ISSET : 1;
      volatile uint32_t CMP_LO1_ISSET : 1;
      volatile uint32_t CMP_LO2_ISSET : 1;
      volatile uint32_t CMP_LO3_ISSET : 1;
      volatile uint32_t CMP_LO4_ISSET : 1;
      volatile uint32_t CMP_LO5_ISSET : 1;
      volatile uint32_t CMP_LO6_ISSET : 1;
      volatile uint32_t CMP_LO7_ISSET : 1;
      volatile uint32_t CMP_UP0_STSSET : 1;
      volatile uint32_t CMP_UP1_STSSET : 1;
      volatile uint32_t CMP_UP2_STSSET : 1;
      volatile uint32_t CMP_UP3_STSSET : 1;
      volatile uint32_t CMP_UP4_STSSET : 1;
      volatile uint32_t CMP_UP5_STSSET : 1;
      volatile uint32_t CMP_UP6_STSSET : 1;
      volatile uint32_t CMP_UP7_STSSET : 1;
      volatile uint32_t CMP_UP0_ISSET : 1;
      volatile uint32_t CMP_UP1_ISSET : 1;
      volatile uint32_t CMP_UP2_ISSET : 1;
      volatile uint32_t CMP_UP3_ISSET : 1;
      volatile uint32_t CMP_UP4_ISSET : 1;
      volatile uint32_t CMP_UP5_ISSET : 1;
      volatile uint32_t CMP_UP6_ISSET : 1;
      volatile uint32_t CMP_UP7_ISSET : 1;
    } bit;
  } CMPSTATSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IEN_CH0 : 1;
      volatile uint32_t IEN_CH1 : 1;
      volatile uint32_t IEN_CH2 : 1;
      volatile uint32_t IEN_CH3 : 1;
      volatile uint32_t IEN_CH4 : 1;
      volatile uint32_t IEN_CH5 : 1;
      volatile uint32_t IEN_CH6 : 1;
      volatile uint32_t IEN_CH7 : 1;
      volatile uint32_t IEN_CH8 : 1;
      volatile uint32_t IEN_CH9 : 1;
      volatile uint32_t IEN_CH10 : 1;
      volatile uint32_t IEN_CH11 : 1;
      volatile uint32_t IEN_CH12 : 1;
      volatile uint32_t IEN_CH13 : 1;
      volatile uint32_t IEN_CH14 : 1;
            uint32_t : 17;
    } bit;
  } IEN0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IEN_SQ0 : 1;
      volatile uint32_t IEN_SQ1 : 1;
      volatile uint32_t IEN_SQ2 : 1;
      volatile uint32_t IEN_SQ3 : 1;
      volatile uint32_t IEN_COLL0 : 1;
      volatile uint32_t IEN_COLL1 : 1;
      volatile uint32_t IEN_COLL2 : 1;
      volatile uint32_t IEN_COLL3 : 1;
            uint32_t : 8;
      volatile uint32_t IEN_LO0 : 1;
      volatile uint32_t IEN_LO1 : 1;
      volatile uint32_t IEN_LO2 : 1;
      volatile uint32_t IEN_LO3 : 1;
      volatile uint32_t IEN_LO4 : 1;
      volatile uint32_t IEN_LO5 : 1;
      volatile uint32_t IEN_LO6 : 1;
      volatile uint32_t IEN_LO7 : 1;
      volatile uint32_t IEN_UP0 : 1;
      volatile uint32_t IEN_UP1 : 1;
      volatile uint32_t IEN_UP2 : 1;
      volatile uint32_t IEN_UP3 : 1;
      volatile uint32_t IEN_UP4 : 1;
      volatile uint32_t IEN_UP5 : 1;
      volatile uint32_t IEN_UP6 : 1;
      volatile uint32_t IEN_UP7 : 1;
    } bit;
  } IEN1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_CH0 : 2;
      volatile uint32_t INP_CH1 : 2;
      volatile uint32_t INP_CH2 : 2;
      volatile uint32_t INP_CH3 : 2;
      volatile uint32_t INP_CH4 : 2;
      volatile uint32_t INP_CH5 : 2;
      volatile uint32_t INP_CH6 : 2;
      volatile uint32_t INP_CH7 : 2;
      volatile uint32_t INP_CH8 : 2;
      volatile uint32_t INP_CH9 : 2;
      volatile uint32_t INP_CH10 : 2;
      volatile uint32_t INP_CH11 : 2;
      volatile uint32_t INP_CH12 : 2;
      volatile uint32_t INP_CH13 : 2;
      volatile uint32_t INP_CH14 : 2;
            uint32_t : 2;
    } bit;
  } INP0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_CMP_LO0 : 2;
      volatile uint32_t INP_CMP_LO1 : 2;
      volatile uint32_t INP_CMP_LO2 : 2;
      volatile uint32_t INP_CMP_LO3 : 2;
      volatile uint32_t INP_CMP_LO4 : 2;
      volatile uint32_t INP_CMP_LO5 : 2;
      volatile uint32_t INP_CMP_LO6 : 2;
      volatile uint32_t INP_CMP_LO7 : 2;
      volatile uint32_t INP_CMP_UP0 : 2;
      volatile uint32_t INP_CMP_UP1 : 2;
      volatile uint32_t INP_CMP_UP2 : 2;
      volatile uint32_t INP_CMP_UP3 : 2;
      volatile uint32_t INP_CMP_UP4 : 2;
      volatile uint32_t INP_CMP_UP5 : 2;
      volatile uint32_t INP_CMP_UP6 : 2;
      volatile uint32_t INP_CMP_UP7 : 2;
    } bit;
  } INP2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_SQ0 : 2;
      volatile uint32_t INP_SQ1 : 2;
      volatile uint32_t INP_SQ2 : 2;
      volatile uint32_t INP_SQ3 : 2;
      volatile uint32_t INP_COLL0 : 2;
      volatile uint32_t INP_COLL1 : 2;
      volatile uint32_t INP_COLL2 : 2;
      volatile uint32_t INP_COLL3 : 2;
            uint32_t : 16;
    } bit;
  } INP3;
  volatile const uint32_t RESERVED[4];

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t LOW_VOLT_STS : 1;
            uint32_t : 31;
    } bit;
  } INTSTAT;
  volatile const uint32_t RESERVED1[3];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
            uint32_t : 2;
      volatile uint32_t TRGSEL : 2;
            uint32_t : 4;
      volatile uint32_t TRGSW : 1;
            uint32_t : 17;
    } bit;
  } SQCFG0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
            uint32_t : 2;
      volatile uint32_t TRGSEL : 2;
            uint32_t : 4;
      volatile uint32_t TRGSW : 1;
            uint32_t : 17;
    } bit;
  } SQCFG1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
            uint32_t : 2;
      volatile uint32_t TRGSEL : 2;
            uint32_t : 4;
      volatile uint32_t TRGSW : 1;
            uint32_t : 17;
    } bit;
  } SQCFG2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SLOTS : 3;
            uint32_t : 1;
      volatile uint32_t SQREP : 2;
            uint32_t : 2;
      volatile uint32_t TRGSEL : 2;
            uint32_t : 4;
      volatile uint32_t TRGSW : 1;
            uint32_t : 17;
    } bit;
  } SQCFG3;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG0;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG1;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG2;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG3;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG4;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG5;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG6;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG7;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG8;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG9;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG10;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG11;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG12;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG13;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CHREP : 4;
            uint32_t : 4;
      volatile uint32_t FILSEL : 4;
      volatile uint32_t CMPSEL : 4;
      volatile uint32_t CLASSEL : 2;
            uint32_t : 6;
    } bit;
  } CHCFG14;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CMP_LO : 8;
            uint32_t : 8;
      volatile const uint32_t CMP_UP : 8;
            uint32_t : 8;
    } bit;
  } CMPSTAT2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CALOFFS : 5;
            uint32_t : 11;
      volatile uint32_t CALGAIN : 8;
            uint32_t : 8;
    } bit;
  } CALAI14;
  volatile const uint32_t RESERVED2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL1 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL2 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL3 : 4;
            uint32_t : 4;
    } bit;
  } SQSLOT0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL1 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL2 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL3 : 4;
            uint32_t : 4;
    } bit;
  } SQSLOT1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL1 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL2 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL3 : 4;
            uint32_t : 4;
    } bit;
  } SQSLOT2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHSEL0 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL1 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL2 : 4;
            uint32_t : 4;
      volatile uint32_t CHSEL3 : 4;
            uint32_t : 4;
    } bit;
  } SQSLOT3;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 4;
      volatile uint32_t STC : 4;
            uint32_t : 24;
    } bit;
  } CONVCFG0;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 4;
      volatile uint32_t STC : 4;
            uint32_t : 24;
    } bit;
  } CONVCFG1;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 4;
      volatile uint32_t STC : 4;
            uint32_t : 24;
    } bit;
  } CONVCFG2;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 4;
      volatile uint32_t STC : 4;
            uint32_t : 24;
    } bit;
  } CONVCFG3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 8;
      volatile uint32_t INP_SEL : 1;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;
            uint32_t : 2;
      volatile uint32_t UPPER : 8;
      volatile uint32_t BLANK_TIME : 3;
      volatile uint32_t RST_BLANK_TIME : 1;
      volatile uint32_t HYST_UP : 2;
      volatile uint32_t MODE : 2;
    } bit;
  } CMPCFG7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t COEF_A0 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A1 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A2 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A3 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A4 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A5 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A6 : 2;
            uint32_t : 2;
      volatile uint32_t COEF_A7 : 2;
            uint32_t : 2;
    } bit;
  } FILTCFG;
} ADC2_Type;
# 3284 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t VREF1V2_UP : 1;
            uint32_t : 31;
    } bit;
  } CFU_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t OC_IS : 1;
            uint32_t : 15;
      volatile uint32_t OC_STS : 1;

            uint32_t : 15;
    } bit;
  } VAREF_IRQ;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t OC_IS_SET : 1;
            uint32_t : 15;
      volatile uint32_t OC_STS_SET : 1;

            uint32_t : 15;
    } bit;
  } VAREF_IRQ_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t OC_IS_CLR : 1;
            uint32_t : 15;
      volatile uint32_t OC_STS_CLR : 1;
            uint32_t : 15;
    } bit;
  } VAREF_IRQ_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t OC_IEN : 1;
            uint32_t : 31;
    } bit;
  } VAREF_IEN;
  volatile const uint32_t RESERVED;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
            uint32_t : 31;
    } bit;
  } VAREF_CTRL;
} ARVG_Type;
# 3361 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB1_EN : 1;
      volatile uint32_t LS1_PWM : 1;
      volatile uint32_t LS1_ON : 1;
      volatile uint32_t LS1_OC_SEL : 1;
            uint32_t : 1;
      volatile uint32_t HS1_PWM : 1;
      volatile uint32_t HS1_ON : 1;
      volatile uint32_t HS1_OC_SEL : 1;
      volatile uint32_t HB2_EN : 1;
      volatile uint32_t LS2_PWM : 1;
      volatile uint32_t LS2_ON : 1;
      volatile uint32_t LS2_OC_SEL : 1;
            uint32_t : 1;
      volatile uint32_t HS2_PWM : 1;
      volatile uint32_t HS2_ON : 1;
      volatile uint32_t HS2_OC_SEL : 1;
      volatile uint32_t HB3_EN : 1;
      volatile uint32_t LS3_PWM : 1;
      volatile uint32_t LS3_ON : 1;
      volatile uint32_t LS3_OC_SEL : 1;
            uint32_t : 1;
      volatile uint32_t HS3_PWM : 1;
      volatile uint32_t HS3_ON : 1;
      volatile uint32_t HS3_OC_SEL : 1;
      volatile uint32_t HS1_DCS_EN : 1;
      volatile uint32_t HS2_DCS_EN : 1;
      volatile uint32_t HS3_DCS_EN : 1;
            uint32_t : 1;
      volatile const uint32_t SUPERR_STS : 1;
            uint32_t : 3;
    } bit;
  } CTRL1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB1ONSEQCNF : 1;
      volatile uint32_t HB1OFFSEQCNF : 1;
            uint32_t : 2;
      volatile uint32_t HB2ONSEQCNF : 1;
      volatile uint32_t HB2OFFSEQCNF : 1;
            uint32_t : 2;
      volatile uint32_t HB3ONSEQCNF : 1;
      volatile uint32_t HB3OFFSEQCNF : 1;
            uint32_t : 2;
      volatile uint32_t ACTDRV_DET_EN : 1;
            uint32_t : 3;
      volatile uint32_t DSMONVTH : 3;

            uint32_t : 1;
      volatile uint32_t LSDRV_DS_TFILT_SEL : 2;

      volatile uint32_t HSDRV_DS_TFILT_SEL : 2;

      volatile uint32_t LS_HS_BT_TFILT_SEL : 2;

            uint32_t : 2;
      volatile uint32_t DRV_CCP_TIMSEL : 3;
      volatile uint32_t DRV_CCP_DIS : 1;
    } bit;
  } CTRL2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_SRC_SEL : 3;
            uint32_t : 1;
      volatile uint32_t HS1_SRC_SEL : 3;
            uint32_t : 1;
      volatile uint32_t LS2_SRC_SEL : 3;
            uint32_t : 1;
      volatile uint32_t HS2_SRC_SEL : 3;
            uint32_t : 1;
      volatile uint32_t LS3_SRC_SEL : 3;
            uint32_t : 1;
      volatile uint32_t HS3_SRC_SEL : 3;
            uint32_t : 9;
    } bit;
  } PWMSRCSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB1_SEQMAP : 1;
      volatile const uint32_t HB1_ACTDRV : 1;
            uint32_t : 6;
      volatile uint32_t HB2_SEQMAP : 1;
      volatile const uint32_t HB2_ACTDRV : 1;
            uint32_t : 6;
      volatile uint32_t HB3_SEQMAP : 1;
      volatile const uint32_t HB3_ACTDRV : 1;
            uint32_t : 14;
    } bit;
  } SEQMAP;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t DLY_DIAG_TIM : 10;
            uint32_t : 6;
      volatile uint32_t DLY_DIAG_CHSEL : 3;

      volatile uint32_t DLY_DIAG_DIRSEL : 1;
            uint32_t : 4;
      volatile const uint32_t DLY_DIAG_STS : 1;
      volatile uint32_t DLY_DIAG_SCLR : 1;

      volatile uint32_t DLY_DIAG_SSET : 1;

            uint32_t : 5;
    } bit;
  } DLY_DIAG;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CP_EN : 1;
            uint32_t : 1;
      volatile uint32_t CP_RDY_EN : 1;
            uint32_t : 5;
      volatile uint32_t VCP_LOWTH2 : 1;
      volatile uint32_t VCP_LOWSRC_SEL : 1;
      volatile uint32_t CPLOW_TFILT_SEL : 2;
            uint32_t : 4;
      volatile uint32_t CP_1STAGE : 1;
      volatile uint32_t CP_STG_AUTO : 1;

            uint32_t : 14;
    } bit;
  } CP_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DITH_LOWER : 5;

            uint32_t : 3;
      volatile uint32_t DITH_UPPER : 5;

      volatile uint32_t F_CP : 2;
            uint32_t : 1;
      volatile uint32_t CPCLK_EN : 1;
      volatile uint32_t CPCLKDIS_SET : 1;
            uint32_t : 14;
    } bit;
  } CP_CLK_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1DRV_HCDISCHG_DIS : 1;
      volatile uint32_t LS1DRV_OCSDN_DIS : 1;
            uint32_t : 2;
      volatile uint32_t HS1DRV_HCDISCHG_DIS : 1;
      volatile uint32_t HS1DRV_OCSDN_DIS : 1;
            uint32_t : 2;
      volatile uint32_t LS2DRV_HCDISCHG_DIS : 1;
      volatile uint32_t LS2DRV_OCSDN_DIS : 1;
            uint32_t : 2;
      volatile uint32_t HS2DRV_HCDISCHG_DIS : 1;
      volatile uint32_t HS2DRV_OCSDN_DIS : 1;
            uint32_t : 2;
      volatile uint32_t LS3DRV_HCDISCHG_DIS : 1;
      volatile uint32_t LS3DRV_OCSDN_DIS : 1;
            uint32_t : 2;
      volatile uint32_t HS3DRV_HCDISCHG_DIS : 1;
      volatile uint32_t HS3DRV_OCSDN_DIS : 1;
            uint32_t : 2;
      volatile uint32_t DRVx_VCPLO_SDEN : 1;
      volatile uint32_t DRVx_VCPLO_DIS : 1;
      volatile uint32_t DRVx_VCPUP_DIS : 1;
      volatile uint32_t DRVx_VSDLO_DIS : 1;
      volatile uint32_t DRVx_VSDUP_DIS : 1;
            uint32_t : 3;
    } bit;
  } PROT_CTRL;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t LS1_OC_STS : 1;
      volatile const uint32_t LS1_DS_STS : 1;
            uint32_t : 2;
      volatile const uint32_t HS1_OC_STS : 1;
      volatile const uint32_t HS1_DS_STS : 1;

      volatile const uint32_t SH1_LOW_STS : 1;
      volatile const uint32_t SH1_HIGH_STS : 1;
      volatile const uint32_t LS2_OC_STS : 1;
      volatile const uint32_t LS2_DS_STS : 1;
            uint32_t : 2;
      volatile const uint32_t HS2_OC_STS : 1;
      volatile const uint32_t HS2_DS_STS : 1;

      volatile const uint32_t SH2_LOW_STS : 1;
      volatile const uint32_t SH2_HIGH_STS : 1;
      volatile const uint32_t LS3_OC_STS : 1;
      volatile const uint32_t LS3_DS_STS : 1;

            uint32_t : 2;
      volatile const uint32_t HS3_OC_STS : 1;
      volatile const uint32_t HS3_DS_STS : 1;

      volatile const uint32_t SH3_LOW_STS : 1;
      volatile const uint32_t SH3_HIGH_STS : 1;
      volatile const uint32_t CP_OTSD_STS : 1;
      volatile const uint32_t VCP_LOTH1_STS : 1;
      volatile const uint32_t VCP_UPTH_STS : 1;
      volatile const uint32_t VSD_LOTH_STS : 1;
      volatile const uint32_t VSD_UPTH_STS : 1;
      volatile const uint32_t VSD_CP1ST_STS : 1;
      volatile const uint32_t VSD_OV_STS : 1;
      volatile const uint32_t VCP_LOTH2_STS : 1;
    } bit;
  } STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_OC_SC : 1;
      volatile uint32_t LS1_DS_SC : 1;

            uint32_t : 2;
      volatile uint32_t HS1_OC_SC : 1;
      volatile uint32_t HS1_DS_SC : 1;

            uint32_t : 2;
      volatile uint32_t LS2_OC_SC : 1;
      volatile uint32_t LS2_DS_SC : 1;

            uint32_t : 2;
      volatile uint32_t HS2_OC_SC : 1;
      volatile uint32_t HS2_DS_SC : 1;

            uint32_t : 2;
      volatile uint32_t LS3_OC_SC : 1;
      volatile uint32_t LS3_DS_SC : 1;

            uint32_t : 2;
      volatile uint32_t HS3_OC_SC : 1;
      volatile uint32_t HS3_DS_SC : 1;

            uint32_t : 9;
      volatile uint32_t VCP_LOTH2_SC : 1;
    } bit;
  } STSCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_OC_SS : 1;
      volatile uint32_t LS1_DS_SS : 1;

            uint32_t : 2;
      volatile uint32_t HS1_OC_SS : 1;
      volatile uint32_t HS1_DS_SS : 1;

            uint32_t : 2;
      volatile uint32_t LS2_OC_SS : 1;
      volatile uint32_t LS2_DS_SS : 1;

            uint32_t : 2;
      volatile uint32_t HS2_OC_SS : 1;
      volatile uint32_t HS2_DS_SS : 1;

            uint32_t : 2;
      volatile uint32_t LS3_OC_SS : 1;
      volatile uint32_t LS3_DS_SS : 1;

            uint32_t : 2;
      volatile uint32_t HS3_OC_SS : 1;
      volatile uint32_t HS3_DS_SS : 1;

            uint32_t : 9;
      volatile uint32_t VCP_LOTH2_SS : 1;
    } bit;
  } STSSET;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t LS1_OC_IS : 1;
      volatile const uint32_t LS1_DS_IS : 1;

            uint32_t : 2;
      volatile const uint32_t HS1_OC_IS : 1;
      volatile const uint32_t HS1_DS_IS : 1;

            uint32_t : 2;
      volatile const uint32_t LS2_OC_IS : 1;
      volatile const uint32_t LS2_DS_IS : 1;

            uint32_t : 2;
      volatile const uint32_t HS2_OC_IS : 1;
      volatile const uint32_t HS2_DS_IS : 1;

            uint32_t : 2;
      volatile const uint32_t LS3_OC_IS : 1;
      volatile const uint32_t LS3_DS_IS : 1;

            uint32_t : 2;
      volatile const uint32_t HS3_OC_IS : 1;
      volatile const uint32_t HS3_DS_IS : 1;

            uint32_t : 2;
      volatile const uint32_t HB1_ASEQ_IS : 1;
      volatile const uint32_t HB2_ASEQ_IS : 1;
      volatile const uint32_t HB3_ASEQ_IS : 1;
      volatile const uint32_t SEQ_ERR_IS : 1;
      volatile const uint32_t HB1_ACTDRV_IS : 1;
      volatile const uint32_t HB2_ACTDRV_IS : 1;
      volatile const uint32_t HB3_ACTDRV_IS : 1;
      volatile const uint32_t VCP_LOTH2_IS : 1;
    } bit;
  } IRQS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_OC_ISC : 1;

      volatile uint32_t LS1_DS_ISC : 1;

            uint32_t : 2;
      volatile uint32_t HS1_OC_ISC : 1;

      volatile uint32_t HS1_DS_ISC : 1;

            uint32_t : 2;
      volatile uint32_t LS2_OC_ISC : 1;

      volatile uint32_t LS2_DS_ISC : 1;

            uint32_t : 2;
      volatile uint32_t HS2_OC_ISC : 1;

      volatile uint32_t HS2_DS_ISC : 1;

            uint32_t : 2;
      volatile uint32_t LS3_OC_ISC : 1;

      volatile uint32_t LS3_DS_ISC : 1;

            uint32_t : 2;
      volatile uint32_t HS3_OC_ISC : 1;

      volatile uint32_t HS3_DS_ISC : 1;

            uint32_t : 2;
      volatile uint32_t HB1_ASEQ_ISC : 1;
      volatile uint32_t HB2_ASEQ_ISC : 1;
      volatile uint32_t HB3_ASEQ_ISC : 1;
      volatile uint32_t SEQ_ERR_ISC : 1;
      volatile uint32_t HB1_ACTDRV_ISC : 1;

      volatile uint32_t HB2_ACTDRV_ISC : 1;

      volatile uint32_t HB3_ACTDRV_ISC : 1;

      volatile uint32_t VCP_LOTH2_ISC : 1;

    } bit;
  } IRQCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_OC_ISS : 1;

      volatile uint32_t LS1_DS_ISS : 1;

            uint32_t : 2;
      volatile uint32_t HS1_OC_ISS : 1;

      volatile uint32_t HS1_DS_ISS : 1;

            uint32_t : 2;
      volatile uint32_t LS2_OC_ISS : 1;

      volatile uint32_t LS2_DS_ISS : 1;

            uint32_t : 2;
      volatile uint32_t HS2_OC_ISS : 1;

      volatile uint32_t HS2_DS_ISS : 1;

            uint32_t : 2;
      volatile uint32_t LS3_OC_ISS : 1;

      volatile uint32_t LS3_DS_ISS : 1;

            uint32_t : 2;
      volatile uint32_t HS3_OC_ISS : 1;

      volatile uint32_t HS3_DS_ISS : 1;

            uint32_t : 2;
      volatile uint32_t HB1_ASEQ_ISS : 1;
      volatile uint32_t HB2_ASEQ_ISS : 1;
      volatile uint32_t HB3_ASEQ_ISS : 1;
      volatile uint32_t SEQ_ERR_ISS : 1;
      volatile uint32_t HB1_ACTDRV_ISS : 1;

      volatile uint32_t HB2_ACTDRV_ISS : 1;

      volatile uint32_t HB3_ACTDRV_ISS : 1;

      volatile uint32_t VCP_LOTH2_ISS : 1;

    } bit;
  } IRQSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_OC_IEN : 1;
      volatile uint32_t LS1_DS_IEN : 1;

            uint32_t : 2;
      volatile uint32_t HS1_OC_IEN : 1;
      volatile uint32_t HS1_DS_IEN : 1;

            uint32_t : 2;
      volatile uint32_t LS2_OC_IEN : 1;
      volatile uint32_t LS2_DS_IEN : 1;

            uint32_t : 2;
      volatile uint32_t HS2_OC_IEN : 1;
      volatile uint32_t HS2_DS_IEN : 1;

            uint32_t : 2;
      volatile uint32_t LS3_OC_IEN : 1;
      volatile uint32_t LS3_DS_IEN : 1;

            uint32_t : 2;
      volatile uint32_t HS3_OC_IEN : 1;
      volatile uint32_t HS3_DS_IEN : 1;

            uint32_t : 2;
      volatile uint32_t HB1_ASEQ_IEN : 1;
      volatile uint32_t HB2_ASEQ_IEN : 1;
      volatile uint32_t HB3_ASEQ_IEN : 1;
      volatile uint32_t SEQ_ERR_IEN : 1;
      volatile uint32_t HB1_ACTDRV_IEN : 1;
      volatile uint32_t HB2_ACTDRV_IEN : 1;
      volatile uint32_t HB3_ACTDRV_IEN : 1;
      volatile uint32_t VCP_LOTH2_IEN : 1;
    } bit;
  } IRQEN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB1_ICLMPON : 6;
            uint32_t : 2;
      volatile uint32_t HB1_ICLMPOFF : 6;
            uint32_t : 18;
    } bit;
  } HB1IGATECLMPC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB2_ICLMPON : 6;
            uint32_t : 2;
      volatile uint32_t HB2_ICLMPOFF : 6;
            uint32_t : 18;
    } bit;
  } HB2IGATECLMPC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB3_ICLMPON : 6;
            uint32_t : 2;
      volatile uint32_t HB3_ICLMPOFF : 6;
            uint32_t : 18;
    } bit;
  } HB3IGATECLMPC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_TAFOFF : 8;

      volatile uint32_t LS1_TAFON : 8;

            uint32_t : 16;
    } bit;
  } LS1AFTC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t LS1_IAFOFF : 6;

            uint32_t : 2;
      volatile uint32_t LS1_IAFON : 6;

            uint32_t : 18;
    } bit;
  } LS1AFIC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t HS1_TAFOFF : 8;

      volatile uint32_t HS1_TAFON : 8;

            uint32_t : 16;
    } bit;
  } HS1AFTC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t HS1_IAFOFF : 6;

            uint32_t : 2;
      volatile uint32_t HS1_IAFON : 6;

            uint32_t : 18;
    } bit;
  } HS1AFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_T1OFF : 8;

      volatile uint32_t LS1_T2OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS1_T3OFF : 6;

            uint32_t : 10;
    } bit;
  } LS1SEQOFFTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_I1OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS1_I2OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS1_I3OFF : 6;

            uint32_t : 10;
    } bit;
  } LS1SEQOFFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_T1ON : 8;

      volatile uint32_t LS1_T2ON : 6;
            uint32_t : 2;
      volatile uint32_t LS1_T3ON : 6;

            uint32_t : 2;
      volatile uint32_t LS1_T4ON : 6;

            uint32_t : 2;
    } bit;
  } LS1SEQONTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS1_I1ON : 6;

            uint32_t : 2;
      volatile uint32_t LS1_I2ON : 6;

            uint32_t : 2;
      volatile uint32_t LS1_I3ON : 6;

            uint32_t : 2;
      volatile uint32_t LS1_I4ON : 6;

            uint32_t : 2;
    } bit;
  } LS1SEQONIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS1_T1OFF : 8;

      volatile uint32_t HS1_T2OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS1_T3OFF : 6;

            uint32_t : 10;
    } bit;
  } HS1SEQOFFTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS1_I1OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS1_I2OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS1_I3OFF : 6;

            uint32_t : 10;
    } bit;
  } HS1SEQOFFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS1_T1ON : 8;

      volatile uint32_t HS1_T2ON : 6;

            uint32_t : 2;
      volatile uint32_t HS1_T3ON : 6;

            uint32_t : 2;
      volatile uint32_t HS1_T4ON : 6;

            uint32_t : 2;
    } bit;
  } HS1SEQONTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS1_I1ON : 6;

            uint32_t : 2;
      volatile uint32_t HS1_I2ON : 6;

            uint32_t : 2;
      volatile uint32_t HS1_I3ON : 6;

            uint32_t : 2;
      volatile uint32_t HS1_I4ON : 6;

            uint32_t : 2;
    } bit;
  } HS1SEQONIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS2_TAFOFF : 8;

      volatile uint32_t LS2_TAFON : 8;

            uint32_t : 16;
    } bit;
  } LS2AFTC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t LS2_IAFOFF : 6;

            uint32_t : 2;
      volatile uint32_t LS2_IAFON : 6;

            uint32_t : 18;
    } bit;
  } LS2AFIC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t HS2_TAFOFF : 8;

      volatile uint32_t HS2_TAFON : 8;

            uint32_t : 16;
    } bit;
  } HS2AFTC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t HS2_IAFOFF : 6;

            uint32_t : 2;
      volatile uint32_t HS2_IAFON : 6;

            uint32_t : 18;
    } bit;
  } HS2AFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS2_T1OFF : 8;

      volatile uint32_t LS2_T2OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS2_T3OFF : 6;

            uint32_t : 10;
    } bit;
  } LS2SEQOFFTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS2_I1OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS2_I2OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS2_I3OFF : 6;

            uint32_t : 10;
    } bit;
  } LS2SEQOFFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS2_T1ON : 8;

      volatile uint32_t LS2_T2ON : 6;
            uint32_t : 2;
      volatile uint32_t LS2_T3ON : 6;

            uint32_t : 2;
      volatile uint32_t LS2_T4ON : 6;

            uint32_t : 2;
    } bit;
  } LS2SEQONTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS2_I1ON : 6;

            uint32_t : 2;
      volatile uint32_t LS2_I2ON : 6;

            uint32_t : 2;
      volatile uint32_t LS2_I3ON : 6;

            uint32_t : 2;
      volatile uint32_t LS2_I4ON : 6;

            uint32_t : 2;
    } bit;
  } LS2SEQONIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS2_T1OFF : 8;

      volatile uint32_t HS2_T2OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS2_T3OFF : 6;

            uint32_t : 10;
    } bit;
  } HS2SEQOFFTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS2_I1OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS2_I2OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS2_I3OFF : 6;

            uint32_t : 10;
    } bit;
  } HS2SEQOFFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS2_T1ON : 8;

      volatile uint32_t HS2_T2ON : 6;

            uint32_t : 2;
      volatile uint32_t HS2_T3ON : 6;

            uint32_t : 2;
      volatile uint32_t HS2_T4ON : 6;

            uint32_t : 2;
    } bit;
  } HS2SEQONTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS2_I1ON : 6;

            uint32_t : 2;
      volatile uint32_t HS2_I2ON : 6;

            uint32_t : 2;
      volatile uint32_t HS2_I3ON : 6;

            uint32_t : 2;
      volatile uint32_t HS2_I4ON : 6;

            uint32_t : 2;
    } bit;
  } HS2SEQONIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS3_TAFOFF : 8;

      volatile uint32_t LS3_TAFON : 8;

            uint32_t : 16;
    } bit;
  } LS3AFTC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t LS3_IAFOFF : 6;

            uint32_t : 2;
      volatile uint32_t LS3_IAFON : 6;

            uint32_t : 18;
    } bit;
  } LS3AFIC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t HS3_TAFOFF : 8;

      volatile uint32_t HS3_TAFON : 8;

            uint32_t : 16;
    } bit;
  } HS3AFTC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t HS3_IAFOFF : 6;

            uint32_t : 2;
      volatile uint32_t HS3_IAFON : 6;

            uint32_t : 18;
    } bit;
  } HS3AFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS3_T1OFF : 8;

      volatile uint32_t LS3_T2OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS3_T3OFF : 6;

            uint32_t : 10;
    } bit;
  } LS3SEQOFFTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS3_I1OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS3_I2OFF : 6;

            uint32_t : 2;
      volatile uint32_t LS3_I3OFF : 6;

            uint32_t : 10;
    } bit;
  } LS3SEQOFFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS3_T1ON : 8;

      volatile uint32_t LS3_T2ON : 6;
            uint32_t : 2;
      volatile uint32_t LS3_T3ON : 6;

            uint32_t : 2;
      volatile uint32_t LS3_T4ON : 6;

            uint32_t : 2;
    } bit;
  } LS3SEQONTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LS3_I1ON : 6;

            uint32_t : 2;
      volatile uint32_t LS3_I2ON : 6;

            uint32_t : 2;
      volatile uint32_t LS3_I3ON : 6;

            uint32_t : 2;
      volatile uint32_t LS3_I4ON : 6;

            uint32_t : 2;
    } bit;
  } LS3SEQONIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS3_T1OFF : 8;

      volatile uint32_t HS3_T2OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS3_T3OFF : 6;

            uint32_t : 10;
    } bit;
  } HS3SEQOFFTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS3_I1OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS3_I2OFF : 6;

            uint32_t : 2;
      volatile uint32_t HS3_I3OFF : 6;

            uint32_t : 10;
    } bit;
  } HS3SEQOFFIC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS3_T1ON : 8;

      volatile uint32_t HS3_T2ON : 6;

            uint32_t : 2;
      volatile uint32_t HS3_T3ON : 6;

            uint32_t : 2;
      volatile uint32_t HS3_T4ON : 6;

            uint32_t : 2;
    } bit;
  } HS3SEQONTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HS3_I1ON : 6;

            uint32_t : 2;
      volatile uint32_t HS3_I2ON : 6;

            uint32_t : 2;
      volatile uint32_t HS3_I3ON : 6;

            uint32_t : 2;
      volatile uint32_t HS3_I4ON : 6;

            uint32_t : 2;
    } bit;
  } HS3SEQONIC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t T4OFF : 6;
            uint32_t : 10;
      volatile uint32_t I4OFF : 6;

            uint32_t : 10;
    } bit;
  } SEQOFFT4I4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IHCDIS : 6;
            uint32_t : 10;
      volatile uint32_t HCDIS_SSO : 1;
            uint32_t : 15;
    } bit;
  } HCDIS;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t HB1_TONDLY : 8;

      volatile const uint32_t HB1_I1ONVAL : 6;

            uint32_t : 2;
      volatile const uint32_t HB1_TONDUR : 6;

      volatile const uint32_t HB1_TONDURMERR : 1;

            uint32_t : 5;
      volatile const uint32_t HB1_ACTDRV_ON : 1;
      volatile uint32_t HB1_ONVALVF : 1;
      volatile uint32_t HB1_ONVALVF_CLR : 1;

      volatile uint32_t HB1_ONVALVF_SET : 1;

    } bit;
  } HB1ONVAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t HB1_TOFFDLY : 8;

      volatile const uint32_t HB1_I1OFFVAL : 6;

            uint32_t : 2;
      volatile const uint32_t HB1_TOFFDUR : 6;

      volatile const uint32_t HB1_TOFFDURMERR : 1;

            uint32_t : 5;
      volatile const uint32_t HB1_ACTDRV_OFF : 1;
      volatile uint32_t HB1_OFFVALVF : 1;
      volatile uint32_t HB1_OFFVALVF_CLR : 1;

      volatile uint32_t HB1_OFFVALVF_SET : 1;

    } bit;
  } HB1OFFVAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t HB2_TONDLY : 8;

      volatile const uint32_t HB2_I1ONVAL : 6;

            uint32_t : 2;
      volatile const uint32_t HB2_TONDUR : 6;

      volatile const uint32_t HB2_TONDURMERR : 1;

            uint32_t : 5;
      volatile const uint32_t HB2_ACTDRV_ON : 1;
      volatile uint32_t HB2_ONVALVF : 1;
      volatile uint32_t HB2_ONVALVF_CLR : 1;

      volatile uint32_t HB2_ONVALVF_SET : 1;

    } bit;
  } HB2ONVAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t HB2_TOFFDLY : 8;

      volatile const uint32_t HB2_I1OFFVAL : 6;

            uint32_t : 2;
      volatile const uint32_t HB2_TOFFDUR : 6;

      volatile const uint32_t HB2_TOFFDURMERR : 1;

            uint32_t : 5;
      volatile const uint32_t HB2_ACTDRV_OFF : 1;
      volatile uint32_t HB2_OFFVALVF : 1;
      volatile uint32_t HB2_OFFVALVF_CLR : 1;

      volatile uint32_t HB2_OFFVALVF_SET : 1;

    } bit;
  } HB2OFFVAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t HB3_TONDLY : 8;

      volatile const uint32_t HB3_I1ONVAL : 6;

            uint32_t : 2;
      volatile const uint32_t HB3_TONDUR : 6;

      volatile const uint32_t HB3_TONDURMERR : 1;

            uint32_t : 5;
      volatile const uint32_t HB3_ACTDRV_ON : 1;
      volatile uint32_t HB3_ONVALVF : 1;
      volatile uint32_t HB3_ONVALVF_CLR : 1;

      volatile uint32_t HB3_ONVALVF_SET : 1;

    } bit;
  } HB3ONVAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t HB3_TOFFDLY : 8;

      volatile const uint32_t HB3_I1OFFVAL : 6;

            uint32_t : 2;
      volatile const uint32_t HB3_TOFFDUR : 6;

      volatile const uint32_t HB3_TOFFDURMERR : 1;

            uint32_t : 5;
      volatile const uint32_t HB3_ACTDRV_OFF : 1;
      volatile uint32_t HB3_OFFVALVF : 1;
      volatile uint32_t HB3_OFFVALVF_CLR : 1;

      volatile uint32_t HB3_OFFVALVF_SET : 1;

    } bit;
  } HB3OFFVAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB1ASMONEN : 1;
      volatile uint32_t HB1ASMOFFEN : 1;
            uint32_t : 4;
      volatile uint32_t HB1ONHYSTEN : 1;
      volatile uint32_t HB1OFFHYSTEN : 1;
      volatile uint32_t HB2ASMONEN : 1;
      volatile uint32_t HB2ASMOFFEN : 1;
            uint32_t : 4;
      volatile uint32_t HB2ONHYSTEN : 1;
      volatile uint32_t HB2OFFHYSTEN : 1;
      volatile uint32_t HB3ASMONEN : 1;
      volatile uint32_t HB3ASMOFFEN : 1;
            uint32_t : 4;
      volatile uint32_t HB3ONHYSTEN : 1;
      volatile uint32_t HB3OFFHYSTEN : 1;
            uint32_t : 8;
    } bit;
  } ASEQC;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t HB1T12ONMAX : 1;
      volatile const uint32_t HB1I1ONMAX : 1;
      volatile const uint32_t HB1T12ONMIN : 1;
      volatile const uint32_t HB1I1ONMIN : 1;
      volatile const uint32_t HB1ONMF : 1;

            uint32_t : 2;
      volatile const uint32_t HB1ONFAILDRV : 1;
      volatile const uint32_t HB2T12ONMAX : 1;
      volatile const uint32_t HB2I1ONMAX : 1;
      volatile const uint32_t HB2T12ONMIN : 1;
      volatile const uint32_t HB2I1ONMIN : 1;
      volatile const uint32_t HB2ONMF : 1;

            uint32_t : 2;
      volatile const uint32_t HB2ONFAILDRV : 1;
      volatile const uint32_t HB3T12ONMAX : 1;
      volatile const uint32_t HB3I1ONMAX : 1;
      volatile const uint32_t HB3T12ONMIN : 1;
      volatile const uint32_t HB3I1ONMIN : 1;
      volatile const uint32_t HB3ONMF : 1;

            uint32_t : 2;
      volatile const uint32_t HB3ONFAILDRV : 1;
            uint32_t : 8;
    } bit;
  } ASEQONSTS;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t HB1T1OFFMAX : 1;
      volatile const uint32_t HB1I1OFFMAX : 1;
      volatile const uint32_t HB1T1OFFMIN : 1;
      volatile const uint32_t HB1I1OFFMIN : 1;
      volatile const uint32_t HB1OFFMF : 1;

            uint32_t : 2;
      volatile const uint32_t HB1OFFFAILDRV : 1;
      volatile const uint32_t HB2T1OFFMAX : 1;
      volatile const uint32_t HB2I1OFFMAX : 1;
      volatile const uint32_t HB2T1OFFMIN : 1;
      volatile const uint32_t HB2I1OFFMIN : 1;
      volatile const uint32_t HB2OFFMF : 1;

            uint32_t : 2;
      volatile const uint32_t HB2OFFFAILDRV : 1;
      volatile const uint32_t HB3T1OFFMAX : 1;
      volatile const uint32_t HB3I1OFFMAX : 1;
      volatile const uint32_t HB3T1OFFMIN : 1;
      volatile const uint32_t HB3I1OFFMIN : 1;
      volatile const uint32_t HB3OFFMF : 1;

            uint32_t : 2;
      volatile const uint32_t HB3OFFFAILDRV : 1;
            uint32_t : 8;
    } bit;
  } ASEQOFFSTS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t HB1T1OFFERRCNT : 2;
      volatile uint32_t HB1T12ONERRCNT : 2;
      volatile uint32_t HB1MFERRCNT : 2;
            uint32_t : 2;
      volatile uint32_t HB2T1OFFERRCNT : 2;
      volatile uint32_t HB2T12ONERRCNT : 2;
      volatile uint32_t HB2MFERRCNT : 2;
            uint32_t : 2;
      volatile uint32_t HB3T1OFFERRCNT : 2;
      volatile uint32_t HB3T12ONERRCNT : 2;
      volatile uint32_t HB3MFERRCNT : 2;
            uint32_t : 10;
    } bit;
  } ASEQERRCNT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12ONMIN : 8;
            uint32_t : 24;
    } bit;
  } ASEQONTMIN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1OFFMIN : 8;
            uint32_t : 24;
    } bit;
  } ASEQOFFTMIN;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t I1ONMIN : 6;
            uint32_t : 26;
    } bit;
  } ASEQONIMIN;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t I1OFFMIN : 6;
            uint32_t : 26;
    } bit;
  } ASEQOFFIMIN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12ONMAX : 8;
            uint32_t : 24;
    } bit;
  } ASEQONTMAX;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1OFFMAX : 8;
            uint32_t : 24;
    } bit;
  } ASEQOFFTMAX;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t I1ONMAX : 6;
            uint32_t : 26;
    } bit;
  } ASEQONIMAX;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t I1OFFMAX : 6;
            uint32_t : 26;
    } bit;
  } ASEQOFFIMAX;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t LS1T1OFFADDDLY : 4;

      volatile uint32_t HS1T1OFFADDDLY : 4;

      volatile uint32_t LS2T1OFFADDDLY : 4;

      volatile uint32_t HS2T1OFFADDDLY : 4;

      volatile uint32_t LS3T1OFFADDDLY : 4;

      volatile uint32_t HS3T1OFFADDDLY : 4;

            uint32_t : 8;
    } bit;
  } ASEQOFFADDDLY;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PH1_COMP_EN : 1;
      volatile uint32_t PH2_COMP_EN : 1;
      volatile uint32_t PH3_COMP_EN : 1;
            uint32_t : 1;
      volatile uint32_t PH1_COMP_DIS_SET : 1;
      volatile uint32_t PH2_COMP_DIS_SET : 1;
      volatile uint32_t PH3_COMP_DIS_SET : 1;
            uint32_t : 1;
      volatile uint32_t CMP_TFILT_SEL : 2;
      volatile uint32_t TBLNK_SEL : 3;
      volatile uint32_t DEMAG_FILT_BYP : 1;
      volatile uint32_t BLNK_FILT_BYP : 1;
            uint32_t : 1;
      volatile uint32_t TRIG_SEL : 2;
      volatile uint32_t IN_SEL : 1;
      volatile uint32_t TRIGA_SEL : 1;
      volatile uint32_t TRIGB_SEL : 1;
            uint32_t : 3;
      volatile uint32_t SW_TRIG : 1;
      volatile const uint32_t PH1_ZC_STS : 1;
      volatile const uint32_t PH2_ZC_STS : 1;
      volatile const uint32_t PH3_ZC_STS : 1;
            uint32_t : 4;
    } bit;
  } BEMFC_CTRL;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t PH1_ZCFALL_IS : 1;
      volatile const uint32_t PH1_ZCRISE_IS : 1;
      volatile const uint32_t PH2_ZCFALL_IS : 1;
      volatile const uint32_t PH2_ZCRISE_IS : 1;
      volatile const uint32_t PH3_ZCFALL_IS : 1;
      volatile const uint32_t PH3_ZCRISE_IS : 1;
            uint32_t : 26;
    } bit;
  } BEMFC_IRQS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PH1_ZCFALL_ISC : 1;
      volatile uint32_t PH1_ZCRISE_ISC : 1;
      volatile uint32_t PH2_ZCFALL_ISC : 1;
      volatile uint32_t PH2_ZCRISE_ISC : 1;
      volatile uint32_t PH3_ZCFALL_ISC : 1;
      volatile uint32_t PH3_ZCRISE_ISC : 1;
            uint32_t : 26;
    } bit;
  } BEMFC_IRQCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PH1_ZCFALL_ISS : 1;
      volatile uint32_t PH1_ZCRISE_ISS : 1;
      volatile uint32_t PH2_ZCFALL_ISS : 1;
      volatile uint32_t PH2_ZCRISE_ISS : 1;
      volatile uint32_t PH3_ZCFALL_ISS : 1;
      volatile uint32_t PH3_ZCRISE_ISS : 1;
            uint32_t : 26;
    } bit;
  } BEMFC_IRQSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PH1_ZCFALL_IEN : 1;
      volatile uint32_t PH1_ZCRISE_IEN : 1;
      volatile uint32_t PH2_ZCFALL_IEN : 1;
      volatile uint32_t PH2_ZCRISE_IEN : 1;
      volatile uint32_t PH3_ZCFALL_IEN : 1;
      volatile uint32_t PH3_ZCRISE_IEN : 1;
            uint32_t : 26;
    } bit;
  } BEMFC_IRQEN;
} BDRV_Type;
# 4891 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {
  volatile const uint32_t RESERVED[64];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t Clean : 32;
    } bit;
  } CACHE_AC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADDR : 32;
    } bit;
  } CACHE_SC;
  volatile const uint32_t RESERVED1[3];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADDR : 32;

    } bit;
  } CACHE_BT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADDR : 32;

    } bit;
  } CACHE_BL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADDR : 32;
    } bit;
  } CACHE_BU;
} CACHE_Type;
# 4949 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DISR : 1;
      volatile const uint32_t DISS : 1;
            uint32_t : 1;
      volatile uint32_t EDIS : 1;
            uint32_t : 28;
    } bit;
  } CLC;
  volatile const uint32_t RESERVED;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MOD_REV : 8;
      volatile const uint32_t MOD_TYPE : 8;
      volatile const uint32_t MOD_NUMBER : 16;
    } bit;
  } ID;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t STEP : 10;
            uint32_t : 4;
      volatile uint32_t DM : 2;
            uint32_t : 16;
    } bit;
  } FDR;
  volatile const uint32_t RESERVED1[60];

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST2;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST3;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST4;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST5;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST6;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BEGIN : 8;
      volatile const uint32_t END : 8;
      volatile const uint32_t SIZE : 8;
      volatile const uint32_t EMPTY : 1;
            uint32_t : 7;
    } bit;
  } LIST7;
  volatile const uint32_t RESERVED2[8];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PND : 32;
    } bit;
  } MSPND0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PND : 32;
    } bit;
  } MSPND1;
  volatile const uint32_t RESERVED3[14];

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t INDEX : 6;
            uint32_t : 26;
    } bit;
  } MSID0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t INDEX : 6;
            uint32_t : 26;
    } bit;
  } MSID1;
  volatile const uint32_t RESERVED4[14];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IM : 32;
    } bit;
  } MSIMASK;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PANCMD : 8;
      volatile const uint32_t BUSY : 1;
      volatile const uint32_t RBUSY : 1;
            uint32_t : 6;
      volatile uint32_t PANAR1 : 8;
      volatile uint32_t PANAR2 : 8;
    } bit;
  } PANCTR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CLKSEL : 4;
            uint32_t : 8;
      volatile uint32_t MPSEL : 4;
            uint32_t : 16;
    } bit;
  } MCR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IT : 8;
            uint32_t : 24;
    } bit;
  } MITR;
  volatile const uint32_t RESERVED5[12];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INIT : 1;
      volatile uint32_t TRIE : 1;
      volatile uint32_t LECIE : 1;
      volatile uint32_t ALIE : 1;
      volatile uint32_t CANDIS : 1;
      volatile uint32_t TXDIS : 1;
      volatile uint32_t CCE : 1;
      volatile uint32_t CALM : 1;
            uint32_t : 1;
      volatile uint32_t FDEN : 1;
      volatile uint32_t PED : 1;
            uint32_t : 4;
      volatile uint32_t NISO : 1;
            uint32_t : 16;
    } bit;
  } CAN_NCR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LEC : 3;
      volatile uint32_t TXOK : 1;
      volatile uint32_t RXOK : 1;
      volatile uint32_t ALERT : 1;
      volatile const uint32_t EWRN : 1;
      volatile const uint32_t BOFF : 1;
      volatile uint32_t LLE : 1;
      volatile uint32_t LOE : 1;
            uint32_t : 1;
      volatile uint32_t RESI : 1;
      volatile uint32_t FLEC : 3;
            uint32_t : 17;
    } bit;
  } CAN_NSR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ALINP : 4;
      volatile uint32_t LECINP : 4;
      volatile uint32_t TRINP : 4;
      volatile uint32_t CFCINP : 4;
            uint32_t : 16;
    } bit;
  } CAN_NIPR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXSEL : 3;
            uint32_t : 5;
      volatile uint32_t LBM : 1;
            uint32_t : 23;
    } bit;
  } CAN_NPCR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BRP : 6;
      volatile uint32_t SJW : 2;
      volatile uint32_t TSEG1 : 4;
      volatile uint32_t TSEG2 : 3;
      volatile uint32_t DIV8 : 1;
            uint32_t : 16;
    } bit;
  } CAN_NBTR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t REC : 8;
      volatile uint32_t TEC : 8;
      volatile uint32_t EWRNLVL : 8;
      volatile const uint32_t LETD : 1;
      volatile const uint32_t LEINC : 1;
            uint32_t : 6;
    } bit;
  } CAN_NECNT0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CFC : 16;
      volatile uint32_t CFSEL : 3;
      volatile uint32_t CFMOD : 2;
            uint32_t : 1;
      volatile uint32_t CFCIE : 1;
      volatile uint32_t CFCOV : 1;
            uint32_t : 8;
    } bit;
  } CAN_NFCR0;
} CANNODE_Type;
# 5276 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {
  volatile const uint32_t RESERVED[128];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BRP : 6;
            uint32_t : 2;
      volatile uint32_t SJW : 4;
            uint32_t : 3;
      volatile uint32_t DIV8 : 1;
      volatile uint32_t TSEG2 : 5;
            uint32_t : 1;
      volatile uint32_t TSEG1 : 6;
            uint32_t : 4;
    } bit;
  } CAN_NBTEVR0;
  volatile const uint32_t RESERVED1[9];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FBRP : 6;
      volatile uint32_t FSJW : 2;
      volatile uint32_t FTSEG1 : 4;
      volatile uint32_t FTSEG2 : 3;
            uint32_t : 17;
    } bit;
  } CAN_FNBTR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t TDCV : 6;
            uint32_t : 2;
      volatile uint32_t TDCO : 4;
            uint32_t : 3;
      volatile uint32_t TDC : 1;
            uint32_t : 16;
    } bit;
  } CAN_NTDCR0;
} CANNODEFD_Type;
# 5333 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {
  volatile const uint32_t RESERVED[960];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR0;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR0;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT0;
  } OBJ0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR1;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR1;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT1;
  } OBJ1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR2;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR2;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT2;
  } OBJ2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR3;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR3;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT3;
  } OBJ3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR4;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR4;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT4;
  } OBJ4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR5;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR5;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT5;
  } OBJ5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR6;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR6;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT6;
  } OBJ6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR7;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR7;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT7;
  } OBJ7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR8;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR8;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT8;
  } OBJ8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR9;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR9;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT9;
  } OBJ9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR10;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR10;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT10;
  } OBJ10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR11;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR11;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT11;
  } OBJ11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR12;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR12;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT12;
  } OBJ12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR13;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR13;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT13;
  } OBJ13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR14;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR14;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT14;
  } OBJ14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR15;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR15;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT15;
  } OBJ15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR16;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR16;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT16;
  } OBJ16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR17;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR17;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT17;
  } OBJ17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR18;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR18;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT18;
  } OBJ18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR19;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR19;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT19;
  } OBJ19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR20;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR20;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT20;
  } OBJ20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR21;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR21;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT21;
  } OBJ21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR22;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR22;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT22;
  } OBJ22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR23;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR23;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT23;
  } OBJ23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR24;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR24;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT24;
  } OBJ24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR25;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR25;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT25;
  } OBJ25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR26;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR26;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT26;
  } OBJ26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR27;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR27;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT27;
  } OBJ27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR28;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR28;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT28;
  } OBJ28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR29;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR29;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT29;
  } OBJ29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR30;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR30;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT30;
  } OBJ30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MMC : 4;
            uint32_t : 1;
      volatile uint32_t BRS : 1;
      volatile uint32_t FDF : 1;
            uint32_t : 1;
      volatile uint32_t GDFS : 1;
      volatile uint32_t IDC : 1;
      volatile uint32_t DLCC : 1;
      volatile uint32_t DATC : 1;
            uint32_t : 4;
      volatile uint32_t RXIE : 1;
      volatile uint32_t TXIE : 1;
      volatile uint32_t OVIE : 1;
            uint32_t : 1;
      volatile uint32_t FRREN : 1;
      volatile uint32_t RMM : 1;
      volatile uint32_t SDT : 1;
      volatile uint32_t STT : 1;
      volatile uint32_t DLC : 4;
            uint32_t : 4;
    } bit;
  } CAN_MOFCR31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BOT : 8;
      volatile uint32_t TOP : 8;
      volatile uint32_t CUR : 8;
      volatile uint32_t SEL : 8;
    } bit;
  } CAN_MOFGPR31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXINP : 4;
      volatile uint32_t TXINP : 4;
      volatile uint32_t MPN : 8;
      volatile uint32_t CFCVAL : 16;
    } bit;
  } CAN_MOIPR31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t AM : 29;
      volatile uint32_t MIDE : 1;
            uint32_t : 2;
    } bit;
  } CAN_MOAMR31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_MODATAL31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB4 : 8;
      volatile uint32_t DB5 : 8;
      volatile uint32_t DB6 : 8;
      volatile uint32_t DB7 : 8;
    } bit;
  } CAN_MODATAH31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ID : 29;
      volatile uint32_t IDE : 1;
      volatile uint32_t PRI : 2;
    } bit;
  } CAN_MOAR31;

  union {
    union {
      volatile uint32_t reg;

      struct {
        volatile uint32_t RESRXPND : 1;
        volatile uint32_t RESTXPND : 1;
        volatile uint32_t RESRXUPD : 1;
        volatile uint32_t RESNEWDAT : 1;
        volatile uint32_t RESMSGLST : 1;
        volatile uint32_t RESMSGVAL : 1;
        volatile uint32_t RESRTSEL : 1;
        volatile uint32_t RESRXEN : 1;
        volatile uint32_t RESTXRQ : 1;
        volatile uint32_t RESTXEN0 : 1;
        volatile uint32_t RESTXEN1 : 1;
        volatile uint32_t RESDIR_SETDIR : 1;
              uint32_t : 4;
        volatile uint32_t SETRXPND : 1;
        volatile uint32_t SETTXPND : 1;
        volatile uint32_t SETRXUPD : 1;
        volatile uint32_t SETNEWDAT : 1;
        volatile uint32_t SETMSGLST : 1;
        volatile uint32_t SETMSGVAL : 1;
        volatile uint32_t SETRTSEL : 1;
        volatile uint32_t SETRXEN : 1;
        volatile uint32_t SETTXRQ : 1;
        volatile uint32_t SETTXEN0 : 1;
        volatile uint32_t SETTXEN1 : 1;
        volatile uint32_t SETDIR : 1;
              uint32_t : 4;
      } bit;
    } CAN_MOCTR31;

    union {
      volatile const uint32_t reg;

      struct {
        volatile const uint32_t RXPND : 1;
        volatile const uint32_t TXPND : 1;
        volatile const uint32_t RXUPD : 1;
        volatile const uint32_t NEWDAT : 1;
        volatile const uint32_t MSGLST : 1;
        volatile const uint32_t MSGVAL : 1;
        volatile const uint32_t RTSEL : 1;
        volatile const uint32_t RXEN : 1;
        volatile const uint32_t TXRQ : 1;
        volatile const uint32_t TXEN0 : 1;
        volatile const uint32_t TXEN1 : 1;
        volatile const uint32_t DIR : 1;
        volatile const uint32_t LIST : 4;
        volatile const uint32_t PPREV : 8;
        volatile const uint32_t PNEXT : 8;
      } bit;
    } CAN_MOSTAT31;
  } OBJ31;
} CANMSGOBJ0_Type;
# 10084 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {
  volatile const uint32_t RESERVED[768];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA6;
  volatile const uint32_t RESERVED1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA6;
  volatile const uint32_t RESERVED2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA6;
  volatile const uint32_t RESERVED3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA6;
  volatile const uint32_t RESERVED4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA6;
  volatile const uint32_t RESERVED5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA6;
  volatile const uint32_t RESERVED6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA6;
  volatile const uint32_t RESERVED7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA6;
  volatile const uint32_t RESERVED8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA6;
  volatile const uint32_t RESERVED9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA6;
  volatile const uint32_t RESERVED10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA6;
  volatile const uint32_t RESERVED11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA6;
  volatile const uint32_t RESERVED12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA6;
  volatile const uint32_t RESERVED13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA6;
  volatile const uint32_t RESERVED14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA6;
  volatile const uint32_t RESERVED15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA6;
  volatile const uint32_t RESERVED16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA6;
  volatile const uint32_t RESERVED17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA6;
  volatile const uint32_t RESERVED18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA6;
  volatile const uint32_t RESERVED19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA6;
  volatile const uint32_t RESERVED20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA6;
  volatile const uint32_t RESERVED21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA6;
  volatile const uint32_t RESERVED22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA6;
  volatile const uint32_t RESERVED23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA6;
  volatile const uint32_t RESERVED24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA6;
  volatile const uint32_t RESERVED25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA6;
  volatile const uint32_t RESERVED26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA6;
  volatile const uint32_t RESERVED27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA6;
  volatile const uint32_t RESERVED28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA6;
  volatile const uint32_t RESERVED29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA6;
  volatile const uint32_t RESERVED30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA6;
  volatile const uint32_t RESERVED31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA6;
} CANMSGOBJ1_Type;
# 12594 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {
  volatile const uint32_t RESERVED[512];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO0DATA6;
  volatile const uint32_t RESERVED1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO1DATA6;
  volatile const uint32_t RESERVED2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO2DATA6;
  volatile const uint32_t RESERVED3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO3DATA6;
  volatile const uint32_t RESERVED4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO4DATA6;
  volatile const uint32_t RESERVED5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO5DATA6;
  volatile const uint32_t RESERVED6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO6DATA6;
  volatile const uint32_t RESERVED7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO7DATA6;
  volatile const uint32_t RESERVED8;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO8DATA6;
  volatile const uint32_t RESERVED9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO9DATA6;
  volatile const uint32_t RESERVED10;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO10DATA6;
  volatile const uint32_t RESERVED11;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO11DATA6;
  volatile const uint32_t RESERVED12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO12DATA6;
  volatile const uint32_t RESERVED13;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO13DATA6;
  volatile const uint32_t RESERVED14;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO14DATA6;
  volatile const uint32_t RESERVED15;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO15DATA6;
  volatile const uint32_t RESERVED16;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO16DATA6;
  volatile const uint32_t RESERVED17;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO17DATA6;
  volatile const uint32_t RESERVED18;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO18DATA6;
  volatile const uint32_t RESERVED19;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO19DATA6;
  volatile const uint32_t RESERVED20;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO20DATA6;
  volatile const uint32_t RESERVED21;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO21DATA6;
  volatile const uint32_t RESERVED22;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO22DATA6;
  volatile const uint32_t RESERVED23;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO23DATA6;
  volatile const uint32_t RESERVED24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO24DATA6;
  volatile const uint32_t RESERVED25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO25DATA6;
  volatile const uint32_t RESERVED26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO26DATA6;
  volatile const uint32_t RESERVED27;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO27DATA6;
  volatile const uint32_t RESERVED28;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO28DATA6;
  volatile const uint32_t RESERVED29;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO29DATA6;
  volatile const uint32_t RESERVED30;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO30DATA6;
  volatile const uint32_t RESERVED31;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DB0 : 8;
      volatile uint32_t DB1 : 8;
      volatile uint32_t DB2 : 8;
      volatile uint32_t DB3 : 8;
    } bit;
  } CAN_EMO31DATA6;
} CANMSGOBJ2_Type;
# 15104 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
      volatile uint32_t MODE : 2;
            uint32_t : 5;
      volatile uint32_t EN_TXD_TO : 1;
      volatile uint32_t TSIL_EN : 1;
            uint32_t : 6;
      volatile uint32_t TXD_IN_SEL : 2;
            uint32_t : 14;
    } bit;
  } CTRL;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BUS_TO_IS : 1;
      volatile const uint32_t TXD_TO_IS : 1;
      volatile const uint32_t OT_IS : 1;
      volatile const uint32_t BUS_ACT_IS : 1;
            uint32_t : 12;
      volatile const uint32_t BUS_TO_STS : 1;
      volatile const uint32_t TXD_TO_STS : 1;
      volatile const uint32_t OT_STS : 1;
            uint32_t : 1;
      volatile const uint32_t UV_STS : 1;
            uint32_t : 11;
    } bit;
  } IRQS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BUS_TO_ISC : 1;
      volatile uint32_t TXD_TO_ISC : 1;
      volatile uint32_t OT_ISC : 1;
      volatile uint32_t BUS_ACT_ISC : 1;
            uint32_t : 12;
      volatile uint32_t BUS_TO_SC : 1;
      volatile uint32_t TXD_TO_SC : 1;
      volatile uint32_t OT_SC : 1;
            uint32_t : 13;
    } bit;
  } IRQCLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BUS_TO_ISS : 1;
      volatile uint32_t TXD_TO_ISS : 1;
      volatile uint32_t OT_ISS : 1;
      volatile uint32_t BUS_ACT_ISS : 1;
            uint32_t : 12;
      volatile uint32_t BUS_TO_SS : 1;
      volatile uint32_t TXD_TO_SS : 1;
      volatile uint32_t OT_SS : 1;
            uint32_t : 13;
    } bit;
  } IRQSET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BUS_TO_IEN : 1;
      volatile uint32_t TXD_TO_IEN : 1;
      volatile uint32_t OT_IEN : 1;
      volatile uint32_t BUS_ACT_IEN : 1;
            uint32_t : 28;
    } bit;
  } IRQEN;
} CANTRX_Type;
# 15195 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DISR : 1;
      volatile const uint32_t DISS : 1;
            uint32_t : 30;
    } bit;
  } CLC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12 : 1;
      volatile uint32_t T13 : 1;
      volatile uint32_t MCM : 1;
            uint32_t : 1;
      volatile uint32_t T14 : 1;
      volatile uint32_t T15 : 1;
      volatile uint32_t T16 : 1;
            uint32_t : 8;
      volatile uint32_t WREN : 1;
            uint32_t : 16;
    } bit;
  } MCFG;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MODREV : 8;
      volatile const uint32_t MODNUM : 8;
            uint32_t : 16;
    } bit;
  } ID;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ISCC70 : 2;
      volatile uint32_t ISCC71 : 2;
      volatile uint32_t ISCC72 : 2;
      volatile uint32_t ISTRP : 2;
      volatile uint32_t ISPOS0 : 2;
      volatile uint32_t ISPOS1 : 2;
      volatile uint32_t ISPOS2 : 2;
      volatile uint32_t IST12HR : 2;
            uint32_t : 16;
    } bit;
  } PISEL0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IST13HR : 2;
      volatile uint32_t ISCNT12 : 2;
      volatile uint32_t ISCNT13 : 2;
      volatile uint32_t T12EXT : 1;
      volatile uint32_t T13EXT : 1;
            uint32_t : 24;
    } bit;
  } PISEL2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IST1xHR : 2;
      volatile uint32_t ISCNT1x : 2;
      volatile uint32_t T1xEXT : 1;
            uint32_t : 27;
    } bit;
  } PISEL24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IST1xHR : 2;
      volatile uint32_t ISCNT1x : 2;
      volatile uint32_t T1xEXT : 1;
            uint32_t : 27;
    } bit;
  } PISEL25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IST1xHR : 2;
      volatile uint32_t ISCNT1x : 2;
      volatile uint32_t T1xEXT : 1;
            uint32_t : 27;
    } bit;
  } PISEL26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SB0 : 1;
      volatile uint32_t SB1 : 1;
      volatile uint32_t SB2 : 1;
      volatile uint32_t SB3 : 1;
      volatile uint32_t SB4 : 1;
      volatile uint32_t SB5 : 1;
      volatile uint32_t SB6 : 1;
            uint32_t : 25;
    } bit;
  } KSCSR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12CV : 16;
            uint32_t : 16;
    } bit;
  } T12;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12PV : 16;
            uint32_t : 16;
    } bit;
  } T12PR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DTE0 : 1;
      volatile uint32_t DTE1 : 1;
      volatile uint32_t DTE2 : 1;
            uint32_t : 5;
      volatile const uint32_t DTR0 : 1;
      volatile const uint32_t DTR1 : 1;
      volatile const uint32_t DTR2 : 1;
            uint32_t : 21;
    } bit;
  } T12DTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DTM_RISE : 8;
      volatile uint32_t DTM_FALL : 8;
            uint32_t : 16;
    } bit;
  } T12DT0_VAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DTM_RISE : 8;
      volatile uint32_t DTM_FALL : 8;
            uint32_t : 16;
    } bit;
  } T12DT1_VAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DTM_RISE : 8;
      volatile uint32_t DTM_FALL : 8;
            uint32_t : 16;
    } bit;
  } T12DT2_VAL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DTINSEL0 : 2;
            uint32_t : 2;
      volatile uint32_t DTINSEL1 : 2;
            uint32_t : 2;
      volatile uint32_t DTINSEL2 : 2;
            uint32_t : 22;
    } bit;
  } T12DTINSEL;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CCV : 16;
            uint32_t : 16;
    } bit;
  } CC70R;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CCV : 16;
            uint32_t : 16;
    } bit;
  } CC71R;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CCV : 16;
            uint32_t : 16;
    } bit;
  } CC72R;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CCS : 16;

            uint32_t : 16;
    } bit;
  } CC70SR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CCS : 16;

            uint32_t : 16;
    } bit;
  } CC71SR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CCS : 16;

            uint32_t : 16;
    } bit;
  } CC72SR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CV : 16;
            uint32_t : 16;
    } bit;
  } CC70BR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CV : 16;
            uint32_t : 16;
    } bit;
  } CC71BR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CV : 16;
            uint32_t : 16;
    } bit;
  } CC72BR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CS : 16;
            uint32_t : 16;
    } bit;
  } CC70BSR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CS : 16;
            uint32_t : 16;
    } bit;
  } CC71BSR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CS : 16;
            uint32_t : 16;
    } bit;
  } CC72BSR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xCV : 16;
            uint32_t : 16;
    } bit;
  } T13R;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xCV : 16;
            uint32_t : 16;
    } bit;
  } T14R;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xCV : 16;
            uint32_t : 16;
    } bit;
  } T15R;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xCV : 16;
            uint32_t : 16;
    } bit;
  } T16R;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xPV : 16;
            uint32_t : 16;
    } bit;
  } T13PR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xPV : 16;
            uint32_t : 16;
    } bit;
  } T14PR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xPV : 16;
            uint32_t : 16;
    } bit;
  } T15PR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xPV : 16;
            uint32_t : 16;
    } bit;
  } T16PR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CCV : 16;
            uint32_t : 16;
    } bit;
  } C73R;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CCV : 16;
            uint32_t : 16;
    } bit;
  } C74R;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CCV : 16;
            uint32_t : 16;
    } bit;
  } C75R;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t CCV : 16;
            uint32_t : 16;
    } bit;
  } C76R;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CCS : 16;
            uint32_t : 16;
    } bit;
  } C73SR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CCS : 16;
            uint32_t : 16;
    } bit;
  } C74SR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CCS : 16;
            uint32_t : 16;
    } bit;
  } C75SR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CCS : 16;
            uint32_t : 16;
    } bit;
  } C76SR;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t CC70ST : 1;
      volatile const uint32_t CC71ST : 1;
      volatile const uint32_t CC72ST : 1;
      volatile const uint32_t CCPOS0 : 1;
      volatile const uint32_t CCPOS1 : 1;
      volatile const uint32_t CCPOS2 : 1;
      volatile const uint32_t CC73ST : 1;
            uint32_t : 1;
      volatile uint32_t CC70PS : 1;
      volatile uint32_t COUT70PS : 1;
      volatile uint32_t CC71PS : 1;
      volatile uint32_t COUT71PS : 1;
      volatile uint32_t CC72PS : 1;
      volatile uint32_t COUT72PS : 1;
      volatile uint32_t COUT73PS : 1;
      volatile uint32_t T13IM : 1;
            uint32_t : 16;
    } bit;
  } CMPSTAT;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t C70BST : 1;
      volatile const uint32_t C71BST : 1;
      volatile const uint32_t C72BST : 1;
            uint32_t : 1;
      volatile const uint32_t C74ST : 1;
      volatile const uint32_t C75ST : 1;
      volatile const uint32_t C76ST : 1;
            uint32_t : 1;
      volatile const uint32_t CC70ST : 1;
      volatile const uint32_t CC71ST : 1;
      volatile const uint32_t CC72ST : 1;
            uint32_t : 21;
    } bit;
  } CMPSTAT_2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MCC70S : 1;
      volatile uint32_t MCC71S : 1;
      volatile uint32_t MCC72S : 1;
      volatile uint32_t MCC70BS : 1;
      volatile uint32_t MCC71BS : 1;
      volatile uint32_t MCC72BS : 1;
      volatile uint32_t MCC73S : 1;
            uint32_t : 1;
      volatile uint32_t MCC70R : 1;
      volatile uint32_t MCC71R : 1;
      volatile uint32_t MCC72R : 1;
      volatile uint32_t MCC70BR : 1;
      volatile uint32_t MCC71BR : 1;
      volatile uint32_t MCC72BR : 1;
      volatile uint32_t MCC73R : 1;
            uint32_t : 17;
    } bit;
  } CMPMODIF;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MC74S : 1;
      volatile uint32_t MC75S : 1;
      volatile uint32_t MC76S : 1;
            uint32_t : 1;
      volatile uint32_t CC70INV : 1;
      volatile uint32_t CC71INV : 1;
      volatile uint32_t CC72INV : 1;
            uint32_t : 1;
      volatile uint32_t MC74R : 1;
      volatile uint32_t MC75R : 1;
      volatile uint32_t MC76R : 1;
            uint32_t : 1;
      volatile uint32_t C70BINV : 1;
      volatile uint32_t C71BINV : 1;
      volatile uint32_t C72BINV : 1;
            uint32_t : 17;
    } bit;
  } CMPMODIF_2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MSEL70 : 4;
      volatile uint32_t MSEL71 : 4;
      volatile uint32_t MSEL72 : 4;
      volatile uint32_t HSYNC : 3;
      volatile uint32_t DBYP : 1;
            uint32_t : 16;
    } bit;
  } T12MSEL;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t T12PRE : 1;
      volatile const uint32_t T12R : 1;
      volatile const uint32_t STE12 : 1;
      volatile const uint32_t CDIR : 1;
      volatile uint32_t CTM : 1;
            uint32_t : 3;
      volatile uint32_t T13PRE : 1;
      volatile const uint32_t T13R : 1;
      volatile const uint32_t STE13 : 1;
            uint32_t : 18;
    } bit;
  } TCTR0;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t T1xPRE : 1;
      volatile const uint32_t T14R : 1;
      volatile const uint32_t STE14 : 1;
            uint32_t : 2;
      volatile const uint32_t T15R : 1;
      volatile const uint32_t STE15 : 1;
            uint32_t : 2;
      volatile const uint32_t T16R : 1;
      volatile const uint32_t STE16 : 1;
      volatile const uint32_t STE12 : 1;
      volatile const uint32_t STE13 : 1;
            uint32_t : 16;
    } bit;
  } TCTR1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12SSC : 1;
      volatile uint32_t T13SSC : 1;
      volatile uint32_t T13TEC : 3;
      volatile uint32_t T13TED : 2;
            uint32_t : 1;
      volatile uint32_t T12RSEL : 2;
      volatile uint32_t T13RSEL : 2;
            uint32_t : 20;
    } bit;
  } TCTR2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xSSC : 1;
      volatile uint32_t T1xTEC : 3;
      volatile uint32_t T1xTED : 2;
            uint32_t : 2;
      volatile uint32_t T1xRSEL : 2;
            uint32_t : 22;
    } bit;
  } TCTR24;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xSSC : 1;
      volatile uint32_t T1xTEC : 3;
      volatile uint32_t T1xTED : 2;
            uint32_t : 2;
      volatile uint32_t T1xRSEL : 2;
            uint32_t : 22;
    } bit;
  } TCTR25;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xSSC : 1;
      volatile uint32_t T1xTEC : 3;
      volatile uint32_t T1xTED : 2;
            uint32_t : 2;
      volatile uint32_t T1xRSEL : 2;
            uint32_t : 22;
    } bit;
  } TCTR26;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12RR : 1;
      volatile uint32_t T12RS : 1;
      volatile uint32_t T12RES : 1;
      volatile uint32_t DTRES : 1;
            uint32_t : 1;
      volatile uint32_t T12CNT : 1;
      volatile uint32_t T12STR : 1;
      volatile uint32_t T12STD : 1;
      volatile uint32_t T13RR : 1;
      volatile uint32_t T13RS : 1;
      volatile uint32_t T13RES : 1;
            uint32_t : 2;
      volatile uint32_t T13CNT : 1;
      volatile uint32_t T13STR : 1;
      volatile uint32_t T13STD : 1;
            uint32_t : 16;
    } bit;
  } TCTR4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xRR : 1;
      volatile uint32_t T1xRS : 1;
      volatile uint32_t T1xRES : 1;
            uint32_t : 1;
      volatile uint32_t T1xCNT : 1;
      volatile uint32_t T1xSTR : 1;
      volatile uint32_t T1xSTD : 1;
            uint32_t : 25;
    } bit;
  } TCTR44;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xRR : 1;
      volatile uint32_t T1xRS : 1;
      volatile uint32_t T1xRES : 1;
            uint32_t : 1;
      volatile uint32_t T1xCNT : 1;
      volatile uint32_t T1xSTR : 1;
      volatile uint32_t T1xSTD : 1;
            uint32_t : 25;
    } bit;
  } TCTR45;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T1xRR : 1;
      volatile uint32_t T1xRS : 1;
      volatile uint32_t T1xRES : 1;
            uint32_t : 1;
      volatile uint32_t T1xCNT : 1;
      volatile uint32_t T1xSTR : 1;
      volatile uint32_t T1xSTD : 1;
            uint32_t : 25;
    } bit;
  } TCTR46;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12MODEN_CC70 : 1;
      volatile uint32_t T12MODEN_COUT70 : 1;
      volatile uint32_t T12MODEN_CC71 : 1;
      volatile uint32_t T12MODEN_COUT71 : 1;
      volatile uint32_t T12MODEN_CC72 : 1;
      volatile uint32_t T12MODEN_COUT72 : 1;
            uint32_t : 1;
      volatile uint32_t MCMEN : 1;
      volatile uint32_t T13MODEN_CC70 : 1;
      volatile uint32_t T13MODEN_COUT70 : 1;
      volatile uint32_t T13MODEN_CC71 : 1;
      volatile uint32_t T13MODEN_COUT71 : 1;
      volatile uint32_t T13MODEN_CC72 : 1;
      volatile uint32_t T13MODEN_COUT72 : 1;
            uint32_t : 1;
      volatile uint32_t ECT13O : 1;
            uint32_t : 16;
    } bit;
  } MODCTR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TRPM0 : 1;
      volatile uint32_t TRPM1 : 1;
      volatile uint32_t TRPM2 : 1;
            uint32_t : 5;
      volatile uint32_t TRPEN : 6;
      volatile uint32_t TRPEN13 : 1;
      volatile uint32_t TRPPEN : 1;
            uint32_t : 16;
    } bit;
  } TRPCTR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PSL_CC70 : 1;
      volatile uint32_t PSL_COUT70 : 1;
      volatile uint32_t PSL_CC71 : 1;
      volatile uint32_t PSL_COUT71 : 1;
      volatile uint32_t PSL_CC72 : 1;
      volatile uint32_t PSL_COUT72 : 1;
            uint32_t : 1;
      volatile uint32_t PSL73 : 1;
            uint32_t : 24;
    } bit;
  } PSLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MCMPS : 6;
            uint32_t : 1;
      volatile uint32_t STRMCM : 1;
      volatile uint32_t EXPHS : 3;
      volatile uint32_t CURHS : 3;
            uint32_t : 1;
      volatile uint32_t STRHP : 1;
            uint32_t : 16;
    } bit;
  } MCMOUTS;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MCMP : 6;
      volatile const uint32_t R : 1;
            uint32_t : 1;
      volatile const uint32_t EXPH : 3;
      volatile const uint32_t CURH : 3;
            uint32_t : 18;
    } bit;
  } MCMOUT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SWSEL : 3;
            uint32_t : 1;
      volatile uint32_t SWSYN : 2;
            uint32_t : 2;
      volatile uint32_t STE12U : 1;
      volatile uint32_t STE12D : 1;
      volatile uint32_t STE13U : 1;
            uint32_t : 21;
    } bit;
  } MCMCTR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LBE : 1;
      volatile uint32_t CCPOS0I : 1;
      volatile uint32_t CCPOS1I : 1;
      volatile uint32_t CCPOS2I : 1;
      volatile uint32_t CC70INI : 1;
      volatile uint32_t CC71INI : 1;
      volatile uint32_t CC72INI : 1;
      volatile uint32_t CTRAPI : 1;
      volatile uint32_t T12HRI : 1;
      volatile uint32_t T13HRI : 1;
            uint32_t : 22;
    } bit;
  } IMON;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t CCPOS0EN : 1;
      volatile uint32_t CCPOS1EN : 1;
      volatile uint32_t CCPOS2EN : 1;
      volatile uint32_t CC70INEN : 1;
      volatile uint32_t CC71INEN : 1;
      volatile uint32_t CC72INEN : 1;
      volatile uint32_t CTRAPEN : 1;
      volatile uint32_t T12HREN : 1;
      volatile uint32_t T13HREN : 1;
            uint32_t : 3;
      volatile uint32_t LBEEN : 1;
      volatile uint32_t INPLBE : 2;
            uint32_t : 16;
    } bit;
  } LI;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t ICC70R : 1;
      volatile const uint32_t ICC70F : 1;
      volatile const uint32_t ICC71R : 1;
      volatile const uint32_t ICC71F : 1;
      volatile const uint32_t ICC72R : 1;
      volatile const uint32_t ICC72F : 1;
      volatile const uint32_t T12OM : 1;
      volatile const uint32_t T12PM : 1;
      volatile const uint32_t T13CM : 1;
      volatile const uint32_t T13PM : 1;
      volatile const uint32_t TRPF : 1;
      volatile const uint32_t TRPS : 1;
      volatile const uint32_t CHE : 1;
      volatile const uint32_t WHE : 1;
      volatile const uint32_t IDLE : 1;
      volatile const uint32_t STR : 1;
            uint32_t : 16;
    } bit;
  } IS;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t SCC70R : 1;
      volatile uint32_t SCC70F : 1;
      volatile uint32_t SCC71R : 1;
      volatile uint32_t SCC71F : 1;
      volatile uint32_t SCC72R : 1;
      volatile uint32_t SCC72F : 1;
      volatile uint32_t ST12OM : 1;
      volatile uint32_t ST12PM : 1;
      volatile uint32_t ST13CM : 1;
      volatile uint32_t ST13PM : 1;
      volatile uint32_t STRPF : 1;
      volatile uint32_t SWHC : 1;
      volatile uint32_t SCHE : 1;
      volatile uint32_t SWHE : 1;
      volatile uint32_t SIDLE : 1;
      volatile uint32_t SSTR : 1;
            uint32_t : 16;
    } bit;
  } ISS;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t RCC70R : 1;
      volatile uint32_t RCC70F : 1;
      volatile uint32_t RCC71R : 1;
      volatile uint32_t RCC71F : 1;
      volatile uint32_t RCC72R : 1;
      volatile uint32_t RCC72F : 1;
      volatile uint32_t RT12OM : 1;
      volatile uint32_t RT12PM : 1;
      volatile uint32_t RT13CM : 1;
      volatile uint32_t RT13PM : 1;
      volatile uint32_t RTRPF : 1;
            uint32_t : 1;
      volatile uint32_t RCHE : 1;
      volatile uint32_t RWHE : 1;
      volatile uint32_t RIDLE : 1;
      volatile uint32_t RSTR : 1;
            uint32_t : 16;
    } bit;
  } ISR;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t INPCC70 : 2;
      volatile uint32_t INPCC71 : 2;
      volatile uint32_t INPCC72 : 2;
      volatile uint32_t INPCHE : 2;
      volatile uint32_t INPERR : 2;
      volatile uint32_t INPT12 : 2;
      volatile uint32_t INPT13 : 2;
            uint32_t : 18;
    } bit;
  } INP;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ENCC70R : 1;

      volatile uint32_t ENCC70F : 1;

      volatile uint32_t ENCC71R : 1;

      volatile uint32_t ENCC71F : 1;

      volatile uint32_t ENCC72R : 1;

      volatile uint32_t ENCC72F : 1;

      volatile uint32_t ENT12OM : 1;
      volatile uint32_t ENT12PM : 1;
      volatile uint32_t ENT13CM : 1;
      volatile uint32_t ENT13PM : 1;
      volatile uint32_t ENTRPF : 1;
            uint32_t : 1;
      volatile uint32_t ENCHE : 1;
      volatile uint32_t ENWHE : 1;
      volatile uint32_t ENIDLE : 1;
      volatile uint32_t ENSTR : 1;
            uint32_t : 16;
    } bit;
  } IEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t ICC70BR : 1;
      volatile const uint32_t ICC70BF : 1;
      volatile const uint32_t ICC71BR : 1;
      volatile const uint32_t ICC71BF : 1;
      volatile const uint32_t ICC72BR : 1;
      volatile const uint32_t ICC72BF : 1;
            uint32_t : 2;
      volatile const uint32_t T14CM : 1;
      volatile const uint32_t T14PM : 1;
      volatile const uint32_t T15CM : 1;
      volatile const uint32_t T15PM : 1;
      volatile const uint32_t T16CM : 1;
      volatile const uint32_t T16PM : 1;
            uint32_t : 18;
    } bit;
  } IS_2;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t SCC70BR : 1;
      volatile uint32_t SCC70BF : 1;
      volatile uint32_t SCC71BR : 1;
      volatile uint32_t SCC71BF : 1;
      volatile uint32_t SCC72BR : 1;
      volatile uint32_t SCC72BF : 1;
            uint32_t : 2;
      volatile uint32_t ST14CM : 1;
      volatile uint32_t ST14PM : 1;
      volatile uint32_t ST15CM : 1;
      volatile uint32_t ST15PM : 1;
      volatile uint32_t ST16CM : 1;
      volatile uint32_t ST16PM : 1;
            uint32_t : 18;
    } bit;
  } ISS_2;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t RCC70BR : 1;
      volatile uint32_t RCC70BF : 1;
      volatile uint32_t RCC71BR : 1;
      volatile uint32_t RCC71BF : 1;
      volatile uint32_t RCC72BR : 1;
      volatile uint32_t RCC72BF : 1;
            uint32_t : 2;
      volatile uint32_t RT14CM : 1;
      volatile uint32_t RT14PM : 1;
      volatile uint32_t RT15CM : 1;
      volatile uint32_t RT15PM : 1;
      volatile uint32_t RT16CM : 1;
      volatile uint32_t RT16PM : 1;
            uint32_t : 18;
    } bit;
  } ISR_2;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t INPCC70B : 2;
      volatile uint32_t INPCC71B : 2;
      volatile uint32_t INPCC72B : 2;
            uint32_t : 2;
      volatile uint32_t INPT14 : 2;
      volatile uint32_t INPT15 : 2;
      volatile uint32_t INPT16 : 2;
            uint32_t : 18;
    } bit;
  } INP_2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ENCC70BR : 1;

      volatile uint32_t ENCC70BF : 1;

      volatile uint32_t ENCC71BR : 1;

      volatile uint32_t ENCC71BF : 1;

      volatile uint32_t ENCC72BR : 1;

      volatile uint32_t ENCC72BF : 1;

            uint32_t : 2;
      volatile uint32_t ENT14CM : 1;
      volatile uint32_t ENT14PM : 1;
      volatile uint32_t ENT15CM : 1;
      volatile uint32_t ENT15PM : 1;
      volatile uint32_t ENT16CM : 1;
      volatile uint32_t ENT16PM : 1;
            uint32_t : 18;
    } bit;
  } IEN_2;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 24;
      volatile uint32_t SUS : 4;
      volatile uint32_t SUS_P : 1;
      volatile const uint32_t SUSSTA : 1;
            uint32_t : 2;
    } bit;
  } OCS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PQ : 16;
            uint32_t : 16;
    } bit;
  } T_FDIV0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PQ : 16;
            uint32_t : 16;
    } bit;
  } T_FDIV1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12_CLK_SEL : 2;
      volatile uint32_t T13_CLK_SEL : 2;
      volatile uint32_t T14_CLK_SEL : 2;
      volatile uint32_t T15_CLK_SEL : 2;
      volatile uint32_t T16_CLK_SEL : 2;
      volatile uint32_t DT_CLK_SEL : 2;
      volatile uint32_t FDIV0_SEL : 1;
      volatile uint32_t FDIV1_SEL : 1;
            uint32_t : 18;
    } bit;
  } T_CLK_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12STR : 1;
      volatile uint32_t T13STR : 1;
      volatile uint32_t T14STR : 1;
      volatile uint32_t T15STR : 1;
      volatile uint32_t T16STR : 1;
            uint32_t : 3;
      volatile uint32_t T12STD : 1;
      volatile uint32_t T13STD : 1;
      volatile uint32_t T14STD : 1;
      volatile uint32_t T15STD : 1;
      volatile uint32_t T16STD : 1;
            uint32_t : 19;
    } bit;
  } TCTR3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t GT0 : 2;
            uint32_t : 2;
      volatile uint32_t GT1 : 2;
            uint32_t : 2;
      volatile uint32_t GT2 : 2;
            uint32_t : 2;
      volatile uint32_t GT3 : 2;
            uint32_t : 18;
    } bit;
  } IGT;
} CCU7_Type;
# 16361 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {
  volatile const uint32_t RESERVED;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t INTLINESNUM : 5;
            uint32_t : 27;
    } bit;
  } ICT;
  volatile const uint32_t RESERVED1[2];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ENABLE : 1;
      volatile uint32_t TICKINT : 1;
      volatile uint32_t CLKSOURCE : 1;
            uint32_t : 13;
      volatile const uint32_t COUNTFLAG : 1;
            uint32_t : 15;
    } bit;
  } SYSTICK_CS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RELOAD : 24;
            uint32_t : 8;
    } bit;
  } SYSTICK_RL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CURRENT : 24;
            uint32_t : 8;
    } bit;
  } SYSTICK_CUR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t TENMS : 24;
            uint32_t : 6;
      volatile const uint32_t SKEW : 1;
      volatile const uint32_t NOREF : 1;
    } bit;
  } SYSTICK_CAL;
  volatile const uint32_t RESERVED2[56];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IRQEN0 : 1;
      volatile uint32_t IRQEN1 : 1;
      volatile uint32_t IRQEN2 : 1;
      volatile uint32_t IRQEN3 : 1;
      volatile uint32_t IRQEN4 : 1;
      volatile uint32_t IRQEN5 : 1;
      volatile uint32_t IRQEN6 : 1;
      volatile uint32_t IRQEN7 : 1;
      volatile uint32_t IRQEN8 : 1;
      volatile uint32_t IRQEN9 : 1;
      volatile uint32_t IRQEN10 : 1;
      volatile uint32_t IRQEN11 : 1;
      volatile uint32_t IRQEN12 : 1;
      volatile uint32_t IRQEN13 : 1;
      volatile uint32_t IRQEN14 : 1;
      volatile uint32_t IRQEN15 : 1;
      volatile uint32_t IRQEN16 : 1;
      volatile uint32_t IRQEN17 : 1;
      volatile uint32_t IRQEN18 : 1;
      volatile uint32_t IRQEN19 : 1;
      volatile uint32_t IRQEN20 : 1;
      volatile uint32_t IRQEN21 : 1;
      volatile uint32_t IRQEN22 : 1;
      volatile uint32_t IRQEN23 : 1;
      volatile uint32_t IRQEN24 : 1;
      volatile uint32_t IRQEN25 : 1;
      volatile uint32_t IRQEN26 : 1;
      volatile uint32_t IRQEN27 : 1;
      volatile uint32_t IRQEN28 : 1;
      volatile uint32_t IRQEN29 : 1;
      volatile uint32_t IRQEN30 : 1;
      volatile uint32_t IRQEN31 : 1;
    } bit;
  } NVIC_ISER;
  volatile const uint32_t RESERVED3[31];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IRQCLREN0 : 1;
      volatile uint32_t IRQCLREN1 : 1;
      volatile uint32_t IRQCLREN2 : 1;
      volatile uint32_t IRQCLREN3 : 1;
      volatile uint32_t IRQCLREN4 : 1;
      volatile uint32_t IRQCLREN5 : 1;
      volatile uint32_t IRQCLREN6 : 1;
      volatile uint32_t IRQCLREN7 : 1;
      volatile uint32_t IRQCLREN8 : 1;
      volatile uint32_t IRQCLREN9 : 1;
      volatile uint32_t IRQCLREN10 : 1;
      volatile uint32_t IRQCLREN11 : 1;
      volatile uint32_t IRQCLREN12 : 1;
      volatile uint32_t IRQCLREN13 : 1;
      volatile uint32_t IRQCLREN14 : 1;
      volatile uint32_t IRQCLREN15 : 1;
      volatile uint32_t IRQCLREN16 : 1;
      volatile uint32_t IRQCLREN17 : 1;
      volatile uint32_t IRQCLREN18 : 1;
      volatile uint32_t IRQCLREN19 : 1;
      volatile uint32_t IRQCLREN20 : 1;
      volatile uint32_t IRQCLREN21 : 1;
      volatile uint32_t IRQCLREN22 : 1;
      volatile uint32_t IRQCLREN23 : 1;
      volatile uint32_t IRQCLREN24 : 1;
      volatile uint32_t IRQCLREN25 : 1;
      volatile uint32_t IRQCLREN26 : 1;
      volatile uint32_t IRQCLREN27 : 1;
      volatile uint32_t IRQCLREN28 : 1;
      volatile uint32_t IRQCLREN29 : 1;
      volatile uint32_t IRQCLREN30 : 1;
      volatile uint32_t IRQCLREN31 : 1;
    } bit;
  } NVIC_ICER;
  volatile const uint32_t RESERVED4[31];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IRQSETPEND0 : 1;
      volatile uint32_t IRQSETPEND1 : 1;
      volatile uint32_t IRQSETPEND2 : 1;
      volatile uint32_t IRQSETPEND3 : 1;
      volatile uint32_t IRQSETPEND4 : 1;
      volatile uint32_t IRQSETPEND5 : 1;
      volatile uint32_t IRQSETPEND6 : 1;
      volatile uint32_t IRQSETPEND7 : 1;
      volatile uint32_t IRQSETPEND8 : 1;
      volatile uint32_t IRQSETPEND9 : 1;
      volatile uint32_t IRQSETPEND10 : 1;
      volatile uint32_t IRQSETPEND11 : 1;
      volatile uint32_t IRQSETPEND12 : 1;
      volatile uint32_t IRQSETPEND13 : 1;
      volatile uint32_t IRQSETPEND14 : 1;
      volatile uint32_t IRQSETPEND15 : 1;
      volatile uint32_t IRQSETPEND16 : 1;
      volatile uint32_t IRQSETPEND17 : 1;
      volatile uint32_t IRQSETPEND18 : 1;
      volatile uint32_t IRQSETPEND19 : 1;
      volatile uint32_t IRQSETPEND20 : 1;
      volatile uint32_t IRQSETPEND21 : 1;
      volatile uint32_t IRQSETPEND22 : 1;
      volatile uint32_t IRQSETPEND23 : 1;
      volatile uint32_t IRQSETPEND24 : 1;
      volatile uint32_t IRQSETPEND25 : 1;
      volatile uint32_t IRQSETPEND26 : 1;
      volatile uint32_t IRQSETPEND27 : 1;
      volatile uint32_t IRQSETPEND28 : 1;
      volatile uint32_t IRQSETPEND29 : 1;
      volatile uint32_t IRQSETPEND30 : 1;
      volatile uint32_t IRQSETPEND31 : 1;
    } bit;
  } NVIC_ISPR;
  volatile const uint32_t RESERVED5[31];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IRQCLRPEND0 : 1;
      volatile uint32_t IRQCLRPEND1 : 1;
      volatile uint32_t IRQCLRPEND2 : 1;
      volatile uint32_t IRQCLRPEND3 : 1;
      volatile uint32_t IRQCLRPEND4 : 1;
      volatile uint32_t IRQCLRPEND5 : 1;
      volatile uint32_t IRQCLRPEND6 : 1;
      volatile uint32_t IRQCLRPEND7 : 1;
      volatile uint32_t IRQCLRPEND8 : 1;
      volatile uint32_t IRQCLRPEND9 : 1;
      volatile uint32_t IRQCLRPEND10 : 1;
      volatile uint32_t IRQCLRPEND11 : 1;
      volatile uint32_t IRQCLRPEND12 : 1;
      volatile uint32_t IRQCLRPEND13 : 1;
      volatile uint32_t IRQCLRPEND14 : 1;
      volatile uint32_t IRQCLRPEND15 : 1;
      volatile uint32_t IRQCLRPEND16 : 1;
      volatile uint32_t IRQCLRPEND17 : 1;
      volatile uint32_t IRQCLRPEND18 : 1;
      volatile uint32_t IRQCLRPEND19 : 1;
      volatile uint32_t IRQCLRPEND20 : 1;
      volatile uint32_t IRQCLRPEND21 : 1;
      volatile uint32_t IRQCLRPEND22 : 1;
      volatile uint32_t IRQCLRPEND23 : 1;
      volatile uint32_t IRQCLRPEND24 : 1;
      volatile uint32_t IRQCLRPEND25 : 1;
      volatile uint32_t IRQCLRPEND26 : 1;
      volatile uint32_t IRQCLRPEND27 : 1;
      volatile uint32_t IRQCLRPEND28 : 1;
      volatile uint32_t IRQCLRPEND29 : 1;
      volatile uint32_t IRQCLRPEND30 : 1;
      volatile uint32_t IRQCLRPEND31 : 1;
    } bit;
  } NVIC_ICPR;
  volatile const uint32_t RESERVED6[31];

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t IRQACTIVE0 : 1;
      volatile const uint32_t IRQACTIVE1 : 1;
      volatile const uint32_t IRQACTIVE2 : 1;
      volatile const uint32_t IRQACTIVE3 : 1;
      volatile const uint32_t IRQACTIVE4 : 1;
      volatile const uint32_t IRQACTIVE5 : 1;
      volatile const uint32_t IRQACTIVE6 : 1;
      volatile const uint32_t IRQACTIVE7 : 1;
      volatile const uint32_t IRQACTIVE8 : 1;
      volatile const uint32_t IRQACTIVE9 : 1;
      volatile const uint32_t IRQACTIVE10 : 1;
      volatile const uint32_t IRQACTIVE11 : 1;
      volatile const uint32_t IRQACTIVE12 : 1;
      volatile const uint32_t IRQACTIVE13 : 1;
      volatile const uint32_t IRQACTIVE14 : 1;
      volatile const uint32_t IRQACTIVE15 : 1;
      volatile const uint32_t IRQACTIVE16 : 1;
      volatile const uint32_t IRQACTIVE17 : 1;
      volatile const uint32_t IRQACTIVE18 : 1;
      volatile const uint32_t IRQACTIVE19 : 1;
      volatile const uint32_t IRQACTIVE20 : 1;
      volatile const uint32_t IRQACTIVE21 : 1;
      volatile const uint32_t IRQACTIVE22 : 1;
      volatile const uint32_t IRQACTIVE23 : 1;
      volatile const uint32_t IRQACTIVE24 : 1;
      volatile const uint32_t IRQACTIVE25 : 1;
      volatile const uint32_t IRQACTIVE26 : 1;
      volatile const uint32_t IRQACTIVE27 : 1;
      volatile const uint32_t IRQACTIVE28 : 1;
      volatile const uint32_t IRQACTIVE29 : 1;
      volatile const uint32_t IRQACTIVE30 : 1;
      volatile const uint32_t IRQACTIVE31 : 1;
    } bit;
  } NVIC_IABR;
  volatile const uint32_t RESERVED7[63];

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N0 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N1 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N2 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N3 : 5;
    } bit;
  } NVIC_IPR0;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N4 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N5 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N6 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N7 : 5;
    } bit;
  } NVIC_IPR1;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N8 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N9 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N10 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N11 : 5;
    } bit;
  } NVIC_IPR2;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N12 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N13 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N14 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N15 : 5;
    } bit;
  } NVIC_IPR3;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N16 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N17 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N18 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N19 : 5;
    } bit;
  } NVIC_IPR4;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N20 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N21 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N22 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N23 : 5;
    } bit;
  } NVIC_IPR5;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N24 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N25 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N26 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N27 : 5;
    } bit;
  } NVIC_IPR6;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_N28 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N29 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N30 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_N31 : 5;
    } bit;
  } NVIC_IPR7;
  volatile const uint32_t RESERVED8[568];

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t REVISION : 4;
      volatile const uint32_t PARTNO : 12;
      volatile const uint32_t ARCHITECTURE : 4;
      volatile const uint32_t VARIANT : 4;
      volatile const uint32_t IMPLEMENTER : 8;
    } bit;
  } CPUID;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t VECTACTIVE : 9;
            uint32_t : 2;
      volatile const uint32_t RETTOBASE : 1;
      volatile const uint32_t VECTPending : 9;

            uint32_t : 1;
      volatile const uint32_t ISRPending : 1;
      volatile const uint32_t ISRPREEMPT : 1;

            uint32_t : 1;
      volatile uint32_t PENDSTCLR : 1;
      volatile uint32_t PENDSTSET : 1;
      volatile uint32_t PENDSVCLR : 1;
      volatile uint32_t PENDSVSET : 1;
            uint32_t : 2;
      volatile uint32_t NMIPENDSET : 1;
    } bit;
  } ICSR;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 7;
      volatile uint32_t TBLOFF : 25;
    } bit;
  } VTOR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t VECTRESET : 1;
      volatile uint32_t VECTCLRACTIVE : 1;

      volatile uint32_t SYSRESETREQ : 1;
            uint32_t : 5;
      volatile uint32_t PRIGROUP : 3;
            uint32_t : 4;
      volatile const uint32_t ENDIANNESS : 1;

      volatile uint32_t VECTKEY : 16;
    } bit;
  } AIRCR;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t SLEEPONEXIT : 1;

      volatile uint32_t SLEEPDEEP : 1;

            uint32_t : 1;
      volatile uint32_t SEVONPEND : 1;
            uint32_t : 27;
    } bit;
  } SCR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NONBASETHRDENA : 1;

      volatile uint32_t USERSETMPEND : 1;
            uint32_t : 1;
      volatile uint32_t UNALIGN_TRP : 1;
      volatile uint32_t DIV_0_TRP : 1;
            uint32_t : 3;
      volatile uint32_t BFHFMIGN : 1;

      volatile uint32_t STKALIGN : 1;
            uint32_t : 22;
    } bit;
  } CCR;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_4 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_5 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_6 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_7 : 5;
    } bit;
  } SHPR1;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_8 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_9 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_10 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_11 : 5;
    } bit;
  } SHPR2;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 3;
      volatile uint32_t PRI_12 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_13 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_14 : 5;
            uint32_t : 3;
      volatile uint32_t PRI_15 : 5;
    } bit;
  } SHPR3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MEMFAULTACT : 1;
      volatile uint32_t BUSFAULTACT : 1;
            uint32_t : 1;
      volatile uint32_t USGFAULTACT : 1;
            uint32_t : 3;
      volatile uint32_t SVCALLACT : 1;
      volatile uint32_t MONITORACT : 1;
            uint32_t : 1;
      volatile uint32_t PENDSVACT : 1;
      volatile uint32_t SYSTICKACT : 1;
      volatile uint32_t USGFAULTPENDED : 1;
      volatile uint32_t MEMFAULTPENDED : 1;
      volatile uint32_t BUSFAULTPENDED : 1;
      volatile uint32_t SVCALLPENDED : 1;
      volatile uint32_t MEMFAULTENA : 1;
      volatile uint32_t BUSFAULTENA : 1;
      volatile uint32_t USGFAULTENA : 1;
            uint32_t : 13;
    } bit;
  } SHCSR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IACCVIOL : 1;
      volatile uint32_t DACCVIOL : 1;
            uint32_t : 1;
      volatile uint32_t MUNSTKERR : 1;
      volatile uint32_t MSTERR : 1;
      volatile uint32_t MLSPERR : 1;
            uint32_t : 1;
      volatile uint32_t MMARVALID : 1;
      volatile uint32_t IBUSERR : 1;
      volatile uint32_t PRECISERR : 1;
      volatile uint32_t IMPRECISERR : 1;
      volatile uint32_t UNSTKERR : 1;
      volatile uint32_t STKERR : 1;
      volatile uint32_t LSPERR : 1;
            uint32_t : 1;
      volatile uint32_t BFARVALID : 1;
      volatile uint32_t UNDEFINSTR : 1;
      volatile uint32_t INVSTATE : 1;
      volatile uint32_t INVPC : 1;
      volatile uint32_t NOCP : 1;
            uint32_t : 4;
      volatile uint32_t UNALIGNED : 1;
      volatile uint32_t DIVBYZERO : 1;
            uint32_t : 6;
    } bit;
  } CFSR;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t VECTTBL : 1;

            uint32_t : 28;
      volatile uint32_t FORCED : 1;
      volatile uint32_t DEBUGEVT : 1;
    } bit;
  } HFSR;
  volatile const uint32_t RESERVED9;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADDRESS : 32;
    } bit;
  } MMFAR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADDRESS : 32;
    } bit;
  } BFAR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t AUXFAULT : 32;
    } bit;
  } AFSR;
  volatile const uint32_t RESERVED10[112];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INTID : 9;

            uint32_t : 23;
    } bit;
  } STIR;
} CPU_Type;
# 16994 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CSAC_EN : 1;
            uint32_t : 7;
      volatile uint32_t GAIN_MIN : 4;
      volatile uint32_t OFFS_MIN : 4;
      volatile uint32_t THR_MAX : 10;
            uint32_t : 6;
    } bit;
  } CTRL1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADD_INP_OFFS : 1;
      volatile uint32_t GAIN_SEL : 2;
      volatile uint32_t OFFS_SEL : 2;
            uint32_t : 3;
      volatile uint32_t VOUT_SEL : 1;
            uint32_t : 7;
      volatile uint32_t THR_SEL : 5;
            uint32_t : 3;
      volatile uint32_t TFILT_SEL : 2;
            uint32_t : 6;
    } bit;
  } CTRL2;

  union {
    volatile const uint32_t reg;


    struct {
      volatile const uint32_t CSC_OC_IS : 1;
      volatile const uint32_t SEL_ERR_IS : 1;

            uint32_t : 14;
      volatile const uint32_t CSC_OC_STS : 1;
            uint32_t : 7;
      volatile const uint32_t CSC_OC_OUT : 1;
      volatile const uint32_t CSC_BIST_STS : 1;
            uint32_t : 6;
    } bit;
  } IRQS;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t CSC_OC_ISC : 1;
      volatile uint32_t SEL_ERR_ISC : 1;

            uint32_t : 14;
      volatile uint32_t CSC_OC_SC : 1;
            uint32_t : 15;
    } bit;
  } IRQCLR;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t CSC_OC_ISS : 1;
      volatile uint32_t SEL_ERR_ISS : 1;

            uint32_t : 14;
      volatile uint32_t CSC_OC_SS : 1;
            uint32_t : 15;
    } bit;
  } IRQSET;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t CSC_OC_IEN : 1;
      volatile uint32_t SEL_ERR_IEN : 1;

            uint32_t : 30;
    } bit;
  } IRQEN;
} CSACSC_Type;
# 17095 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MASTER_ENABLE : 1;
            uint32_t : 3;
      volatile const uint32_t STATE : 4;
            uint32_t : 8;
      volatile const uint32_t CHNLS_MINUS1 : 5;
            uint32_t : 11;
    } bit;
  } DMA_STATUS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MASTER_ENABLE : 1;
            uint32_t : 4;
      volatile uint32_t CHN1_PROT_CTRL : 3;
            uint32_t : 24;
    } bit;
  } DMA_CFG;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 8;
      volatile uint32_t CTRL_BASE_PTR : 24;
    } bit;
  } CTRL_BASE_PTR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t ALT_CTRL_BASE_PTR : 32;
    } bit;
  } ALT_CTRL_BASE_PTR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t DMA_WAITONREQ_STATUS : 8;
            uint32_t : 24;
    } bit;
  } DMA_WAITONREQ_STATUS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_SW_REQUEST : 8;
            uint32_t : 24;
    } bit;
  } CHNL_SW_REQUEST;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_USEBURST_SET : 8;
            uint32_t : 24;
    } bit;
  } CHNL_USEBURST_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_USEBURST_CLR : 8;
            uint32_t : 24;
    } bit;
  } CHNL_USEBURST_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_REQ_MASK_SET : 8;
            uint32_t : 24;
    } bit;
  } CHNL_REQ_MASK_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_REQ_MASK_CLR : 8;
            uint32_t : 24;
    } bit;
  } CHNL_REQ_MASK_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_ENABLE_SET : 8;
            uint32_t : 24;
    } bit;
  } CHNL_ENABLE_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_ENABLE_CLR : 8;
            uint32_t : 24;
    } bit;
  } CHNL_ENABLE_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_PRI_ALT_SET : 8;
            uint32_t : 24;
    } bit;
  } CHNL_PRI_ALT_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_PRI_ALT_CLR : 8;
            uint32_t : 24;
    } bit;
  } CHNL_PRI_ALT_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_PRIORITY_SET : 8;
            uint32_t : 24;
    } bit;
  } CHNL_PRIORITY_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CHNL_PRIORITY_CLR : 8;
            uint32_t : 24;
    } bit;
  } CHNL_PRIORITY_CLR;
  volatile const uint32_t RESERVED[3];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ERR_CLR : 1;
            uint32_t : 31;
    } bit;
  } ERR_CLR;
} DMA_Type;
# 17268 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PO0 : 1;
      volatile uint32_t PO1 : 1;
      volatile uint32_t PO2 : 1;
      volatile uint32_t PO3 : 1;
      volatile uint32_t PO4 : 1;
      volatile uint32_t PO5 : 1;
      volatile uint32_t PO6 : 1;
      volatile uint32_t PO7 : 1;
      volatile uint32_t PO8 : 1;
      volatile uint32_t PO9 : 1;
      volatile uint32_t PO10 : 1;
            uint32_t : 21;
    } bit;
  } P0_OUT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PS0 : 1;
      volatile uint32_t PS1 : 1;
      volatile uint32_t PS2 : 1;
      volatile uint32_t PS3 : 1;
      volatile uint32_t PS4 : 1;
      volatile uint32_t PS5 : 1;
      volatile uint32_t PS6 : 1;
      volatile uint32_t PS7 : 1;
      volatile uint32_t PS8 : 1;
      volatile uint32_t PS9 : 1;
      volatile uint32_t PS10 : 1;
            uint32_t : 5;
      volatile uint32_t PR0 : 1;
      volatile uint32_t PR1 : 1;
      volatile uint32_t PR2 : 1;
      volatile uint32_t PR3 : 1;
      volatile uint32_t PR4 : 1;
      volatile uint32_t PR5 : 1;
      volatile uint32_t PR6 : 1;
      volatile uint32_t PR7 : 1;
      volatile uint32_t PR8 : 1;
      volatile uint32_t PR9 : 1;
      volatile uint32_t PR10 : 1;
            uint32_t : 5;
    } bit;
  } P0_OMR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t PI0 : 1;
      volatile const uint32_t PI1 : 1;
      volatile const uint32_t PI2 : 1;
      volatile const uint32_t PI3 : 1;
      volatile const uint32_t PI4 : 1;
      volatile const uint32_t PI5 : 1;
      volatile const uint32_t PI6 : 1;
      volatile const uint32_t PI7 : 1;
      volatile const uint32_t PI8 : 1;
      volatile const uint32_t PI9 : 1;
      volatile const uint32_t PI10 : 1;
            uint32_t : 21;
    } bit;
  } P0_IN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DIR0 : 1;
      volatile uint32_t DIR1 : 1;
      volatile uint32_t DIR2 : 1;
      volatile uint32_t DIR3 : 1;
      volatile uint32_t DIR4 : 1;
      volatile uint32_t DIR5 : 1;
      volatile uint32_t DIR6 : 1;
      volatile uint32_t DIR7 : 1;
      volatile uint32_t DIR8 : 1;
      volatile uint32_t DIR9 : 1;
      volatile uint32_t DIR10 : 1;
            uint32_t : 21;
    } bit;
  } P0_DIR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t OD0 : 1;
      volatile uint32_t OD1 : 1;
      volatile uint32_t OD2 : 1;
      volatile uint32_t OD3 : 1;
      volatile uint32_t OD4 : 1;
      volatile uint32_t OD5 : 1;
      volatile uint32_t OD6 : 1;
      volatile uint32_t OD7 : 1;
      volatile uint32_t OD8 : 1;
      volatile uint32_t OD9 : 1;
      volatile uint32_t OD10 : 1;
            uint32_t : 21;
    } bit;
  } P0_OD;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PUDEN0 : 1;
      volatile uint32_t PUDEN1 : 1;
      volatile uint32_t PUDEN2 : 1;
      volatile uint32_t PUDEN3 : 1;
      volatile uint32_t PUDEN4 : 1;
      volatile uint32_t PUDEN5 : 1;
      volatile uint32_t PUDEN6 : 1;
      volatile uint32_t PUDEN7 : 1;
      volatile uint32_t PUDEN8 : 1;
      volatile uint32_t PUDEN9 : 1;
      volatile uint32_t PUDEN10 : 1;
            uint32_t : 5;
      volatile uint32_t PUDSEL0 : 1;
      volatile uint32_t PUDSEL1 : 1;
      volatile uint32_t PUDSEL2 : 1;
      volatile uint32_t PUDSEL3 : 1;
      volatile uint32_t PUDSEL4 : 1;
      volatile uint32_t PUDSEL5 : 1;
      volatile uint32_t PUDSEL6 : 1;
      volatile uint32_t PUDSEL7 : 1;
      volatile uint32_t PUDSEL8 : 1;
      volatile uint32_t PUDSEL9 : 1;
      volatile uint32_t PUDSEL10 : 1;
            uint32_t : 5;
    } bit;
  } P0_PUD;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ALTSEL0 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL1 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL2 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL3 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL4 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL5 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL6 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL7 : 3;
            uint32_t : 1;
    } bit;
  } P0_ALTSEL0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ALTSEL8 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL9 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL10 : 3;
            uint32_t : 21;
    } bit;
  } P0_ALTSEL1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PDM0 : 2;
      volatile uint32_t PDM1 : 2;
      volatile uint32_t PDM2 : 2;
      volatile uint32_t PDM3 : 2;
      volatile uint32_t PDM4 : 2;
      volatile uint32_t PDM5 : 2;
      volatile uint32_t PDM6 : 2;
      volatile uint32_t PDM7 : 2;
      volatile uint32_t PDM8 : 2;
      volatile uint32_t PDM9 : 2;
      volatile uint32_t PDM10 : 2;
            uint32_t : 10;
    } bit;
  } P0_POCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PO0 : 1;
      volatile uint32_t PO1 : 1;
      volatile uint32_t PO2 : 1;
      volatile uint32_t PO3 : 1;
      volatile uint32_t PO4 : 1;
            uint32_t : 27;
    } bit;
  } P1_OUT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PS0 : 1;
      volatile uint32_t PS1 : 1;
      volatile uint32_t PS2 : 1;
      volatile uint32_t PS3 : 1;
      volatile uint32_t PS4 : 1;
            uint32_t : 11;
      volatile uint32_t PR0 : 1;
      volatile uint32_t PR1 : 1;
      volatile uint32_t PR2 : 1;
      volatile uint32_t PR3 : 1;
      volatile uint32_t PR4 : 1;
            uint32_t : 11;
    } bit;
  } P1_OMR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t PI0 : 1;
      volatile const uint32_t PI1 : 1;
      volatile const uint32_t PI2 : 1;
      volatile const uint32_t PI3 : 1;
      volatile const uint32_t PI4 : 1;
            uint32_t : 27;
    } bit;
  } P1_IN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DIR0 : 1;
      volatile uint32_t DIR1 : 1;
      volatile uint32_t DIR2 : 1;
      volatile uint32_t DIR3 : 1;
      volatile uint32_t DIR4 : 1;
            uint32_t : 27;
    } bit;
  } P1_DIR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t OD0 : 1;
      volatile uint32_t OD1 : 1;
      volatile uint32_t OD2 : 1;
      volatile uint32_t OD3 : 1;
      volatile uint32_t OD4 : 1;
            uint32_t : 27;
    } bit;
  } P1_OD;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PUDEN0 : 1;
      volatile uint32_t PUDEN1 : 1;
      volatile uint32_t PUDEN2 : 1;
      volatile uint32_t PUDEN3 : 1;
      volatile uint32_t PUDEN4 : 1;
            uint32_t : 11;
      volatile uint32_t PUDSEL0 : 1;
      volatile uint32_t PUDSEL1 : 1;
      volatile uint32_t PUDSEL2 : 1;
      volatile uint32_t PUDSEL3 : 1;
      volatile uint32_t PUDSEL4 : 1;
            uint32_t : 11;
    } bit;
  } P1_PUD;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ALTSEL0 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL1 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL2 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL3 : 3;
            uint32_t : 1;
      volatile uint32_t ALTSEL4 : 3;
            uint32_t : 13;
    } bit;
  } P1_ALTSEL0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PDM0 : 2;
      volatile uint32_t PDM1 : 2;
      volatile uint32_t PDM2 : 2;
      volatile uint32_t PDM3 : 2;
      volatile uint32_t PDM4 : 2;
            uint32_t : 22;
    } bit;
  } P1_POCON;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t PI0 : 1;
      volatile const uint32_t PI1 : 1;
      volatile const uint32_t PI2 : 1;
      volatile const uint32_t PI3 : 1;
      volatile const uint32_t PI4 : 1;
      volatile const uint32_t PI5 : 1;
      volatile const uint32_t PI6 : 1;
      volatile const uint32_t PI7 : 1;
      volatile const uint32_t PI8 : 1;
      volatile const uint32_t PI9 : 1;
            uint32_t : 22;
    } bit;
  } P2_IN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INDIS0 : 1;
      volatile uint32_t INDIS1 : 1;
      volatile uint32_t INDIS2 : 1;
      volatile uint32_t INDIS3 : 1;
      volatile uint32_t INDIS4 : 1;
      volatile uint32_t INDIS5 : 1;
      volatile uint32_t INDIS6 : 1;
      volatile uint32_t INDIS7 : 1;
      volatile uint32_t INDIS8 : 1;
      volatile uint32_t INDIS9 : 1;
            uint32_t : 22;
    } bit;
  } P2_INDIS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PUDEN0 : 1;
      volatile uint32_t PUDEN1 : 1;
      volatile uint32_t PUDEN2 : 1;
      volatile uint32_t PUDEN3 : 1;
      volatile uint32_t PUDEN4 : 1;
      volatile uint32_t PUDEN5 : 1;
      volatile uint32_t PUDEN6 : 1;
      volatile uint32_t PUDEN7 : 1;
      volatile uint32_t PUDEN8 : 1;
      volatile uint32_t PUDEN9 : 1;
            uint32_t : 6;
      volatile uint32_t PUDSEL0 : 1;
      volatile uint32_t PUDSEL1 : 1;
      volatile uint32_t PUDSEL2 : 1;
      volatile uint32_t PUDSEL3 : 1;
      volatile uint32_t PUDSEL4 : 1;
      volatile uint32_t PUDSEL5 : 1;
      volatile uint32_t PUDSEL6 : 1;
      volatile uint32_t PUDSEL7 : 1;
      volatile uint32_t PUDSEL8 : 1;
      volatile uint32_t PUDSEL9 : 1;
            uint32_t : 6;
    } bit;
  } P2_PUD;
} GPIO_Type;
# 17660 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MOD_REV : 8;
      volatile const uint32_t MOD_TYPE : 8;
            uint32_t : 16;
    } bit;
  } ID;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IST2IN : 1;
      volatile uint32_t IST2EUD : 1;
      volatile uint32_t IST3IN : 2;
      volatile uint32_t IST3EUD : 2;
      volatile uint32_t IST4IN : 2;
      volatile uint32_t IST4EUD : 2;
      volatile uint32_t IST5IN : 1;
      volatile uint32_t IST5EUD : 1;
      volatile uint32_t IST6IN : 1;
      volatile uint32_t IST6EUD : 1;
      volatile uint32_t ISCAPIN : 2;
            uint32_t : 16;
    } bit;
  } PISEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T2I : 3;
      volatile uint32_t T2M : 3;
      volatile uint32_t T2R : 1;
      volatile uint32_t T2UD : 1;
      volatile uint32_t T2UDE : 1;
      volatile uint32_t T2RC : 1;
            uint32_t : 2;
      volatile uint32_t T2IRIDIS : 1;
      volatile uint32_t T2EDGE : 1;
      volatile uint32_t T2CHDIR : 1;
      volatile const uint32_t T2DIR : 1;
            uint32_t : 16;
    } bit;
  } T2CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T3I : 3;
      volatile uint32_t T3M : 3;
      volatile uint32_t T3R : 1;
      volatile uint32_t T3UD : 1;
      volatile uint32_t T3UDE : 1;
      volatile uint32_t T3OE : 1;
      volatile uint32_t T3OTL : 1;
      volatile uint32_t BPS1 : 2;
      volatile uint32_t T3EDGE : 1;
      volatile uint32_t T3CHDIR : 1;
      volatile const uint32_t T3DIR : 1;
            uint32_t : 16;
    } bit;
  } T3CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T4I : 3;
      volatile uint32_t T4M : 3;
      volatile uint32_t T4R : 1;
      volatile uint32_t T4UD : 1;
      volatile uint32_t T4UDE : 1;
      volatile uint32_t T4RC : 1;
      volatile uint32_t CLRT2EN : 1;
      volatile uint32_t CLRT3EN : 1;
      volatile uint32_t T4IRDIS : 1;
      volatile uint32_t T4EDGE : 1;
      volatile uint32_t T4CHDIR : 1;
      volatile const uint32_t T4RDIR : 1;
            uint32_t : 16;
    } bit;
  } T4CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T5I : 3;
      volatile uint32_t T5M : 2;
            uint32_t : 1;
      volatile uint32_t T5R : 1;
      volatile uint32_t T5UD : 1;
      volatile uint32_t T5UDE : 1;
      volatile uint32_t T5RC : 1;
      volatile uint32_t CT3 : 1;
            uint32_t : 1;
      volatile uint32_t CI : 2;
      volatile uint32_t T5CLR : 1;
      volatile uint32_t T5SC : 1;
            uint32_t : 16;
    } bit;
  } T5CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T6I : 3;
      volatile uint32_t T6M : 3;
      volatile uint32_t T6R : 1;
      volatile uint32_t T6UD : 1;
      volatile uint32_t T6UDE : 1;
      volatile uint32_t T6OE : 1;
      volatile uint32_t T6OTL : 1;
      volatile uint32_t BPS2 : 2;
            uint32_t : 1;
      volatile uint32_t T6CLR : 1;
      volatile uint32_t T6SR : 1;
            uint32_t : 16;
    } bit;
  } T6CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CAPREL : 16;
            uint32_t : 16;
    } bit;
  } CAPREL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T2 : 16;
            uint32_t : 16;
    } bit;
  } T2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T3 : 16;
            uint32_t : 16;
    } bit;
  } T3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T4 : 16;
            uint32_t : 16;
    } bit;
  } T4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T5 : 16;
            uint32_t : 16;
    } bit;
  } T5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T6 : 16;
            uint32_t : 16;
    } bit;
  } T6;
} GPT12_Type;
# 17854 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t DBFSTS : 1;
      volatile const uint32_t SBFSTS : 1;
            uint32_t : 30;
    } bit;
  } BFSTS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DBFSTSCLR : 1;
      volatile uint32_t SBFSTSCLR : 1;
            uint32_t : 30;
    } bit;
  } BFSTSC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DBFSTSSET : 1;
      volatile uint32_t SBFSTSSET : 1;
            uint32_t : 30;
    } bit;
  } BFSTSS;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t DBFA : 32;
    } bit;
  } DBFA;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t SBFA : 32;
    } bit;
  } SBFA;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NMIDSEN : 1;
      volatile uint32_t NMIPSEN : 1;
      volatile uint32_t NMICDEN : 1;
      volatile uint32_t NMINVM0EN : 1;
      volatile uint32_t NMINVM1EN : 1;
      volatile uint32_t NMIMAP0EN : 1;
      volatile uint32_t NMIMAP1EN : 1;
      volatile uint32_t NMIWDTEN : 1;
      volatile uint32_t NMISTOFEN : 1;
            uint32_t : 23;
    } bit;
  } NMICON;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t NMIDS : 1;
      volatile const uint32_t NMIPS : 1;
      volatile const uint32_t NMICD : 1;
      volatile const uint32_t NMINVM0 : 1;
      volatile const uint32_t NMINVM1 : 1;
      volatile const uint32_t NMIMAP0 : 1;
      volatile const uint32_t NMIMAP1 : 1;
      volatile const uint32_t NMIWDT : 1;
      volatile const uint32_t NMISTOF : 1;
            uint32_t : 23;
    } bit;
  } NMISR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NMIDSCLR : 1;
      volatile uint32_t NMIPSCLR : 1;
      volatile uint32_t NMICDCLR : 1;
      volatile uint32_t NMINVM0CLR : 1;
      volatile uint32_t NMINVM1CLR : 1;
      volatile uint32_t NMIMAP0CLR : 1;
      volatile uint32_t NMIMAP1CLR : 1;
      volatile uint32_t NMIWDTCLR : 1;
      volatile uint32_t NMISTOFCLR : 1;
            uint32_t : 23;
    } bit;
  } NMISRC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NMIDSSET : 1;
      volatile uint32_t NMIPSSET : 1;
      volatile uint32_t NMICDSET : 1;
      volatile uint32_t NMINVM0SET : 1;
      volatile uint32_t NMINVM1SET : 1;
      volatile uint32_t NMIMAP0SET : 1;
      volatile uint32_t NMIMAP1SET : 1;
      volatile uint32_t NMIWDTSET : 1;
      volatile uint32_t NMISTOFSET : 1;
            uint32_t : 23;
    } bit;
  } NMISRS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NVM0OPCIEN : 1;
      volatile uint32_t NVM1OPCIEN : 1;
            uint32_t : 30;
    } bit;
  } IEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t NVM0OPC : 1;
      volatile const uint32_t NVM1OPC : 1;
            uint32_t : 30;
    } bit;
  } IS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NVM0OPCLR : 1;
      volatile uint32_t NVM1OPCLR : 1;
            uint32_t : 30;
    } bit;
  } ISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NVM0OPSET : 1;
      volatile uint32_t NVM1OPSET : 1;
            uint32_t : 30;
    } bit;
  } ISS;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t NVM0_PROT_ERR : 1;
      volatile const uint32_t NVM0_ADDR_ERR : 1;
      volatile const uint32_t NVM0_SFR_PROT_ERR : 1;
      volatile const uint32_t NVM0_SFR_ADDR_ERR : 1;
      volatile const uint32_t NVM1_PROT_ERR : 1;
      volatile const uint32_t NVM1_ADDR_ERR : 1;
      volatile const uint32_t NVM1_SFR_PROT_ERR : 1;
      volatile const uint32_t NVM1_SFR_ADDR_ERR : 1;
      volatile const uint32_t ROM_PROT_ERR : 1;
      volatile const uint32_t DSRAM_PROT_ERR : 1;
      volatile const uint32_t PSRAM_PROT_ERR : 1;
            uint32_t : 5;
      volatile const uint32_t DSSBE : 1;
      volatile const uint32_t PSSBE : 1;
      volatile const uint32_t CDSBE : 1;
            uint32_t : 13;
    } bit;
  } MEMSTS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NVM0_PROT_ERRCLR : 1;
      volatile uint32_t NVM0_ADDR_ERRCLR : 1;
      volatile uint32_t NVM0_SFR_PROT_ERRCLR : 1;
      volatile uint32_t NVM0_SFR_ADDR_ERRCLR : 1;
      volatile uint32_t NVM1_PROT_ERRCLR : 1;
      volatile uint32_t NVM1_ADDR_ERRCLR : 1;
      volatile uint32_t NVM1_SFR_PROT_ERRCLR : 1;
      volatile uint32_t NVM1_SFR_ADDR_ERRCLR : 1;
      volatile uint32_t ROM_PROT_ERRCLR : 1;
      volatile uint32_t DSRAM_PROT_ERRCLR : 1;
      volatile uint32_t PSRAM_PROT_ERRCLR : 1;
            uint32_t : 5;
      volatile uint32_t DSSBECLR : 1;
      volatile uint32_t PSSBECLR : 1;
      volatile uint32_t CDSBECLR : 1;
            uint32_t : 13;
    } bit;
  } MEMSTSC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NVM0_PROT_ERRSET : 1;
      volatile uint32_t NVM0_ADDR_ERRSET : 1;
      volatile uint32_t NVM0_SFR_PROT_ERRSET : 1;
      volatile uint32_t NVM0_SFR_ADDR_ERRSET : 1;
      volatile uint32_t NVM1_PROT_ERRSET : 1;
      volatile uint32_t NVM1_ADDR_ERRSET : 1;
      volatile uint32_t NVM1_SFR_PROT_ERRSET : 1;
      volatile uint32_t NVM1_SFR_ADDR_ERRSET : 1;
      volatile uint32_t ROM_PROT_ERRSET : 1;
      volatile uint32_t DSRAM_PROT_ERRSET : 1;
      volatile uint32_t PSRAM_PROT_ERRSET : 1;
            uint32_t : 5;
      volatile uint32_t DSSBESET : 1;
      volatile uint32_t PSSBESET : 1;
      volatile uint32_t CDSBESET : 1;
            uint32_t : 13;
    } bit;
  } MEMSTSS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ROMAWSEN : 1;
      volatile uint32_t MEM_DBG_ERR : 1;
      volatile uint32_t CACHEEN : 1;
            uint32_t : 29;
    } bit;
  } MEMCONTROL;
  volatile const uint32_t RESERVED[19];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MRAMINITSTS : 1;
      volatile uint32_t PG100TP_CHKS_ERR : 1;
            uint32_t : 14;
      volatile uint32_t MAPRAM1_MBISTEXEC : 1;
      volatile uint32_t MAPRAM0_MBISTEXEC : 1;
      volatile uint32_t CDRAM_MBISTEXEC : 1;
      volatile uint32_t CTRAM_MBISTEXEC : 1;
      volatile uint32_t CMRAM_MBISTEXEC : 1;
      volatile uint32_t PSRAM_MBISTEXEC : 1;
      volatile uint32_t DSRAM_MBISTEXEC : 1;
            uint32_t : 1;
      volatile uint32_t MAPRAM1_MBISTFAIL : 1;
      volatile uint32_t MAPRAM0_MBISTFAIL : 1;
      volatile uint32_t CDRAM_MBISTFAIL : 1;
      volatile uint32_t CTRAM_MBISTFAIL : 1;
      volatile uint32_t CMRAM_MBISTFAIL : 1;
      volatile uint32_t PSRAM_MBISTFAIL : 1;
      volatile uint32_t DSRAM_MBISTFAIL : 1;
            uint32_t : 1;
    } bit;
  } SYS_STRTUP_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RDEN_UBSL : 1;
      volatile uint32_t WREN_UBSL : 1;
      volatile uint32_t RDEN_UCODE : 1;
      volatile uint32_t WREN_UCODE : 1;
      volatile uint32_t RDEN_UDATA : 1;
      volatile uint32_t WREN_UDATA : 1;
      volatile uint32_t WREN_CS0 : 1;
      volatile uint32_t WREN_CS1 : 1;
      volatile uint32_t RDEN_CS0 : 1;
      volatile uint32_t RDEN_CS1 : 1;
      volatile uint32_t WREN_CRYPTO : 1;
      volatile uint32_t WREN_MCTRL : 1;

      volatile uint32_t SFR_PROT_DIS : 1;
      volatile uint32_t RDEN_CRYPTO : 1;
      volatile uint32_t RDEN_MCTRL : 1;
            uint32_t : 1;
      volatile uint32_t ROM_PROT_DIS : 1;
      volatile uint32_t DSRAM_PROT_DIS : 1;
      volatile uint32_t PSRAM_PROT_DIS : 1;
      volatile uint32_t NVM0_PROT_DIS : 1;
      volatile uint32_t NVM1_PROT_DIS : 1;
      volatile uint32_t NVMSFR_PROT_DIS : 1;
            uint32_t : 2;
      volatile uint32_t UBSL_SIZE : 3;
      volatile uint32_t UBSL_PRIV : 1;
            uint32_t : 4;
    } bit;
  } NVM_PROT_STS;
  volatile const uint32_t RESERVED1[3];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SECTORINFO : 6;

      volatile uint32_t SASTATUS : 2;
            uint32_t : 24;
    } bit;
  } MEMSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t STOF_EN : 1;
            uint32_t : 31;
    } bit;
  } STACK_OVF_CTRL;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 2;
      volatile uint32_t STOF_ADDR_OFF_L : 13;

            uint32_t : 3;
      volatile uint32_t STOF_ADDR_OFF_H : 13;

            uint32_t : 1;
    } bit;
  } STACK_OVF_ADDR;
  volatile const uint32_t RESERVED2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t STCALIB : 26;
            uint32_t : 6;
    } bit;
  } STCALIB;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t WDTIN : 1;
      volatile uint32_t WDTRS : 1;
      volatile uint32_t WDTEN : 1;
            uint32_t : 1;
      volatile const uint32_t WDTPR : 1;
      volatile uint32_t WDTBEN : 1;
            uint32_t : 26;
    } bit;
  } SYSWDTCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t WDTREL : 8;
            uint32_t : 24;
    } bit;
  } SYSWDTREL;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t WDT : 16;
            uint32_t : 16;
    } bit;
  } SYSWDT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t WDTWINB : 8;
            uint32_t : 24;
    } bit;
  } SYSWDTWINB;
  volatile const uint32_t RESERVED3[4];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NVM0_ACCDIS : 1;
            uint32_t : 31;
    } bit;
  } AEP_CTRL;
} MEMCTRL_Type;
# 18259 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NDIV : 8;
      volatile uint32_t PDIV : 6;
            uint32_t : 2;
      volatile uint32_t K2DIV : 3;
            uint32_t : 1;
      volatile uint32_t INSEL : 2;
            uint32_t : 2;
      volatile uint32_t FREERUN : 1;
      volatile uint32_t RESLD : 1;
            uint32_t : 5;
      volatile uint32_t PLLEN : 1;
    } bit;
  } CON0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NDIV : 8;
      volatile uint32_t PDIV : 6;
            uint32_t : 2;
      volatile uint32_t K2DIV : 3;
            uint32_t : 1;
      volatile uint32_t INSEL : 2;
            uint32_t : 2;
      volatile uint32_t FREERUN : 1;
      volatile uint32_t RESLD : 1;
            uint32_t : 5;
      volatile uint32_t PLLEN : 1;
    } bit;
  } CON1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SPEN0 : 1;
            uint32_t : 3;
      volatile uint32_t SPRANGE0 : 2;
      volatile uint32_t SPUPVAL0 : 10;
      volatile uint32_t SPEN1 : 1;
            uint32_t : 3;
      volatile uint32_t SPRANGE1 : 2;
      volatile uint32_t SPUPVAL1 : 10;
    } bit;
  } SPCTR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t LCK0 : 1;
      volatile const uint32_t LCK1 : 1;
            uint32_t : 2;
      volatile const uint32_t PLL0_LOL_STS : 1;
      volatile const uint32_t PLL1_LOL_STS : 1;
            uint32_t : 10;
      volatile const uint32_t OSCSEL_STAT0 : 1;
      volatile const uint32_t OSCSEL_STAT1 : 1;
            uint32_t : 14;
    } bit;
  } STAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PLL0_LOL_STSCLR : 1;
      volatile uint32_t PLL1_LOL_STSCLR : 1;
            uint32_t : 30;
    } bit;
  } STATC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PLL0_LOL_STSSET : 1;
      volatile uint32_t PLL1_LOL_STSSET : 1;
            uint32_t : 30;
    } bit;
  } STATS;
} PLL_Type;
# 18360 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MCNFSTOP : 2;
      volatile uint32_t ITH_SEL : 1;
            uint32_t : 29;
    } bit;
  } VDDP_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UVWARN_IEN : 1;
      volatile uint32_t OV_IEN : 1;
            uint32_t : 30;
    } bit;
  } VDDP_IRQEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t UVWARN_IS : 1;
      volatile const uint32_t OV_IS : 1;
            uint32_t : 14;
      volatile const uint32_t UVWARN_STS : 1;
            uint32_t : 3;
      volatile const uint32_t ILIM_STS : 1;
      volatile const uint32_t HCM_STS : 1;
            uint32_t : 10;
    } bit;
  } VDDP_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UVWARN_IS_CLR : 1;
      volatile uint32_t OV_IS_CLR : 1;
            uint32_t : 14;
      volatile uint32_t UVWARN_STS_CLR : 1;
            uint32_t : 3;
      volatile uint32_t ILIM_STS_CLR : 1;
      volatile uint32_t HCM_STS_CLR : 1;
            uint32_t : 10;
    } bit;
  } VDDP_STS_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UVWARN_IS_SET : 1;
      volatile uint32_t OV_IS_SET : 1;
            uint32_t : 14;
      volatile uint32_t UVWARN_STS_SET : 1;
            uint32_t : 3;
      volatile uint32_t ILIM_STS_SET : 1;
      volatile uint32_t HCM_STS_SET : 1;
            uint32_t : 10;
    } bit;
  } VDDP_STS_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MCNFSTOP : 2;
            uint32_t : 30;
    } bit;
  } VDDC_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UVWARN_IEN : 1;
      volatile uint32_t OV_IEN : 1;
            uint32_t : 30;
    } bit;
  } VDDC_IRQEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t UVWARN_IS : 1;
      volatile const uint32_t OV_IS : 1;
            uint32_t : 14;
      volatile const uint32_t UVWARN_STS : 1;
            uint32_t : 4;
      volatile const uint32_t HCM_STS : 1;
            uint32_t : 10;
    } bit;
  } VDDC_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UVWARN_IS_CLR : 1;
      volatile uint32_t OV_IS_CLR : 1;
            uint32_t : 14;
      volatile uint32_t UVWARN_STS_CLR : 1;
            uint32_t : 4;
      volatile uint32_t HCM_STS_CLR : 1;
            uint32_t : 10;
    } bit;
  } VDDC_STS_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UVWARN_IS_SET : 1;
      volatile uint32_t OV_IS_SET : 1;
            uint32_t : 14;
      volatile uint32_t UVWARN_STS_SET : 1;
            uint32_t : 4;
      volatile uint32_t HCM_STS_SET : 1;
            uint32_t : 10;
    } bit;
  } VDDC_STS_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
      volatile uint32_t CYC_EN : 1;
            uint32_t : 30;
    } bit;
  } VDDEXT_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UV_IEN : 1;
      volatile uint32_t OT_IEN : 1;
            uint32_t : 30;
    } bit;
  } VDDEXT_IRQEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t UV_IS : 1;
      volatile const uint32_t OT_IS : 1;
            uint32_t : 14;
      volatile const uint32_t UV_STS : 1;
      volatile const uint32_t OT_STS : 1;
            uint32_t : 14;
    } bit;
  } VDDEXT_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UV_IS_CLR : 1;
      volatile uint32_t OT_IS_CLR : 1;
            uint32_t : 14;
      volatile uint32_t UV_STS_CLR : 1;
      volatile uint32_t OT_STS_CLR : 1;
            uint32_t : 14;
    } bit;
  } VDDEXT_STS_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UV_IS_SET : 1;
      volatile uint32_t OT_IS_SET : 1;
            uint32_t : 14;
      volatile uint32_t UV_STS_SET : 1;
      volatile uint32_t OT_STS_SET : 1;
            uint32_t : 14;
    } bit;
  } VDDEXT_STS_SET;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t VDDP_TMOUT : 1;
      volatile const uint32_t VDDC_TMOUT : 1;
      volatile const uint32_t HPCLK_FAIL : 1;
      volatile const uint32_t SYS_OT : 1;
      volatile const uint32_t FSWD_SEQ_FAIL : 1;
      volatile const uint32_t VDDP_OT : 1;
      volatile const uint32_t VDDC_OC : 1;
            uint32_t : 25;
    } bit;
  } WAKE_FAIL_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t VDDP_TMOUT_CLR : 1;
      volatile uint32_t VDDC_TMOUT_CLR : 1;
      volatile uint32_t HPCLK_FAIL_CLR : 1;
      volatile uint32_t SYS_OT_CLR : 1;
      volatile uint32_t FSWD_SEQ_FAIL_CLR : 1;
      volatile uint32_t VDDP_OT_CLR : 1;
      volatile uint32_t VDDC_OC_CLR : 1;
            uint32_t : 25;
    } bit;
  } WAKE_FAIL_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t VDDP_TMOUT_SET : 1;
      volatile uint32_t VDDC_TMOUT_SET : 1;
      volatile uint32_t HPCLK_FAIL_SET : 1;
      volatile uint32_t SYS_OT_SET : 1;
      volatile uint32_t FSWD_SEQ_FAIL_SET : 1;
      volatile uint32_t VDDP_OT_SET : 1;
      volatile uint32_t VDDC_OC_SET : 1;
            uint32_t : 25;
    } bit;
  } WAKE_FAIL_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TFB : 3;
            uint32_t : 29;
    } bit;
  } RST_CTRL;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t VMSUP_UV_RST : 1;
      volatile const uint32_t MCLK_WD_RST : 1;
      volatile const uint32_t FS_SLEEPEX_RST : 1;
      volatile const uint32_t SLEEPEX_RST : 1;
      volatile const uint32_t STOPEX_RST : 1;
      volatile const uint32_t PIN_RST : 1;
      volatile const uint32_t FSWD_RST : 1;
      volatile const uint32_t WDT_MCU_RST : 1;
      volatile const uint32_t SOFT_RST : 1;
      volatile const uint32_t LOCKUP_RST : 1;
      volatile const uint32_t VDDP_UV_RST : 1;
      volatile const uint32_t VDDC_UV_RST : 1;
      volatile const uint32_t SEC_STACK_RST : 1;
      volatile const uint32_t TMS_RST : 1;
            uint32_t : 18;
    } bit;
  } RESET_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t VMSUP_UV_RST_CLR : 1;
      volatile uint32_t MCLK_WD_RST_CLR : 1;
      volatile uint32_t FS_SLEEPEX_RST_CLR : 1;
      volatile uint32_t SLEEPEX_RST_CLR : 1;
      volatile uint32_t STOPEX_RST_CLR : 1;
      volatile uint32_t PIN_RST_CLR : 1;
      volatile uint32_t FSWD_RST_CLR : 1;
      volatile uint32_t WDT_MCU_RST_CLR : 1;
      volatile uint32_t SOFT_RST_CLR : 1;
      volatile uint32_t LOCKUP_RST_CLR : 1;
      volatile uint32_t VDDP_UV_RST_CLR : 1;
      volatile uint32_t VDDC_UV_RST_CLR : 1;
      volatile uint32_t SEC_STACK_RST_CLR : 1;
      volatile uint32_t TMS_RST_CLR : 1;
            uint32_t : 18;
    } bit;
  } RESET_STS_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t VMSUP_UV_RST_SET : 1;
      volatile uint32_t MCLK_WD_RST_SET : 1;
      volatile uint32_t FS_SLEEPEX_RST_SET : 1;
      volatile uint32_t SLEEPEX_RST_SET : 1;
      volatile uint32_t STOPEX_RST_SET : 1;
      volatile uint32_t PIN_RST_SET : 1;
      volatile uint32_t FSWD_RST_SET : 1;
      volatile uint32_t WDT_MCU_RST_SET : 1;
      volatile uint32_t SOFT_RST_SET : 1;
      volatile uint32_t LOCKUP_RST_SET : 1;
      volatile uint32_t VDDP_UV_RST_SET : 1;
      volatile uint32_t VDDC_UV_RST_SET : 1;
      volatile uint32_t SEC_STACK_RST_SET : 1;
      volatile uint32_t TMS_RST_SET : 1;
            uint32_t : 18;
    } bit;
  } RESET_STS_SET;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t MON_FT : 1;
      volatile uint32_t GPIO_FT : 2;
            uint32_t : 28;
    } bit;
  } WAKE_FILT_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CYC_SENSE_EN : 1;
            uint32_t : 3;
      volatile uint32_t CYC_ON_TIME : 3;
            uint32_t : 9;
      volatile uint32_t CYC_SENSE_M03 : 4;
      volatile uint32_t CYC_SENSE_E01 : 2;
            uint32_t : 2;
      volatile uint32_t CYC_WAKE_M03 : 4;
      volatile uint32_t CYC_WAKE_E01 : 2;
            uint32_t : 2;
    } bit;
  } CYC_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RI : 1;
      volatile uint32_t FA : 1;
      volatile uint32_t CYC : 1;
            uint32_t : 5;
      volatile uint32_t INP : 5;
            uint32_t : 19;
    } bit;
  } WAKE_GPIO_CTRL0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RI : 1;
      volatile uint32_t FA : 1;
      volatile uint32_t CYC : 1;
            uint32_t : 5;
      volatile uint32_t INP : 5;
            uint32_t : 19;
    } bit;
  } WAKE_GPIO_CTRL1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RI : 1;
      volatile uint32_t FA : 1;
      volatile uint32_t CYC : 1;
            uint32_t : 5;
      volatile uint32_t INP : 5;
            uint32_t : 19;
    } bit;
  } WAKE_GPIO_CTRL2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RI : 1;
      volatile uint32_t FA : 1;
      volatile uint32_t CYC : 1;
            uint32_t : 5;
      volatile uint32_t INP : 5;
            uint32_t : 19;
    } bit;
  } WAKE_GPIO_CTRL3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RI : 1;
      volatile uint32_t FA : 1;
      volatile uint32_t CYC : 1;
            uint32_t : 5;
      volatile uint32_t INP : 5;
            uint32_t : 19;
    } bit;
  } WAKE_GPIO_CTRL4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RI : 1;
      volatile uint32_t FA : 1;
      volatile uint32_t CYC : 1;
            uint32_t : 5;
      volatile uint32_t INP : 5;
            uint32_t : 19;
    } bit;
  } WAKE_GPIO_CTRL5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
      volatile uint32_t WAKE_RISE : 1;
      volatile uint32_t WAKE_FALL : 1;
      volatile uint32_t CYC_SENSE_EN : 1;
      volatile uint32_t PU : 1;
      volatile uint32_t PD : 1;
            uint32_t : 26;
    } bit;
  } MON_CTRL1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
      volatile uint32_t WAKE_RISE : 1;
      volatile uint32_t WAKE_FALL : 1;
      volatile uint32_t CYC_SENSE_EN : 1;
      volatile uint32_t PU : 1;
      volatile uint32_t PD : 1;
            uint32_t : 26;
    } bit;
  } MON_CTRL2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
      volatile uint32_t WAKE_RISE : 1;
      volatile uint32_t WAKE_FALL : 1;
      volatile uint32_t CYC_SENSE_EN : 1;
      volatile uint32_t PU : 1;
      volatile uint32_t PD : 1;
            uint32_t : 26;
    } bit;
  } MON_CTRL3;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MON1_STS : 1;
      volatile const uint32_t MON2_STS : 1;
      volatile const uint32_t MON3_STS : 1;
            uint32_t : 29;
    } bit;
  } MON_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CAN_WAKE_EN : 1;
            uint32_t : 1;
      volatile uint32_t CYC_WAKE_EN : 1;
            uint32_t : 1;
      volatile uint32_t GPIO0_WAKE_EN : 1;
      volatile uint32_t GPIO1_WAKE_EN : 1;
      volatile uint32_t GPIO2_WAKE_EN : 1;
      volatile uint32_t GPIO3_WAKE_EN : 1;
      volatile uint32_t GPIO4_WAKE_EN : 1;
      volatile uint32_t GPIO5_WAKE_EN : 1;
            uint32_t : 2;
      volatile uint32_t MON1_WAKE_EN : 1;
      volatile uint32_t MON2_WAKE_EN : 1;
      volatile uint32_t MON3_WAKE_EN : 1;
            uint32_t : 1;
      volatile uint32_t VDDP_UVWARN_WAKE_EN : 1;
      volatile uint32_t VDDP_OV_WAKE_EN : 1;
      volatile uint32_t VDDP_HCM_WAKE_EN : 1;
      volatile uint32_t VDDC_UVWARN_WAKE_EN : 1;
      volatile uint32_t VDDC_OV_WAKE_EN : 1;
      volatile uint32_t VDDC_HCM_WAKE_EN : 1;
      volatile uint32_t VDDEXT_OT_WAKE_EN : 1;
      volatile uint32_t VDDEXT_UV_WAKE_EN : 1;
      volatile uint32_t VSDOV_WAKE_EN : 1;
            uint32_t : 3;
      volatile uint32_t WAKE_W_RST : 1;
      volatile uint32_t VDDC_RED_EN : 1;
            uint32_t : 2;
    } bit;
  } WAKE_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile const uint32_t CAN : 1;
            uint32_t : 1;
      volatile const uint32_t CYC_WAKE : 1;
            uint32_t : 1;
      volatile const uint32_t GPIO0 : 1;
      volatile const uint32_t GPIO1 : 1;
      volatile const uint32_t GPIO2 : 1;
      volatile const uint32_t GPIO3 : 1;
      volatile const uint32_t GPIO4 : 1;
      volatile const uint32_t GPIO5 : 1;
            uint32_t : 2;
      volatile const uint32_t MON1 : 1;
      volatile const uint32_t MON2 : 1;
      volatile const uint32_t MON3 : 1;
            uint32_t : 1;
      volatile const uint32_t VDDP_UVWARN : 1;
      volatile const uint32_t VDDP_OV : 1;
      volatile const uint32_t VDDP_HCM : 1;
      volatile const uint32_t VDDC_UVWARN : 1;
      volatile const uint32_t VDDC_OV : 1;
      volatile const uint32_t VDDC_HCM : 1;
      volatile const uint32_t VDDEXT_OT : 1;
      volatile const uint32_t VDDEXT_UV : 1;
      volatile uint32_t VSD_OV : 1;
            uint32_t : 7;
    } bit;
  } WAKE_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CAN_CLR : 1;
            uint32_t : 1;
      volatile uint32_t CYC_WAKE_CLR : 1;
            uint32_t : 1;
      volatile uint32_t GPIO0_CLR : 1;
      volatile uint32_t GPIO1_CLR : 1;
      volatile uint32_t GPIO2_CLR : 1;
      volatile uint32_t GPIO3_CLR : 1;
      volatile uint32_t GPIO4_CLR : 1;
      volatile uint32_t GPIO5_CLR : 1;
            uint32_t : 2;
      volatile uint32_t MON1_CLR : 1;
      volatile uint32_t MON2_CLR : 1;
      volatile uint32_t MON3_CLR : 1;
            uint32_t : 1;
      volatile uint32_t VDDP_UVWARN_CLR : 1;
      volatile uint32_t VDDP_OV_CLR : 1;
      volatile uint32_t VDDP_HCM_CLR : 1;
      volatile uint32_t VDDC_UVWARN_CLR : 1;
      volatile uint32_t VDDC_OV_CLR : 1;
      volatile uint32_t VDDC_HCM_CLR : 1;
      volatile uint32_t VDDEXT_OT_CLR : 1;
      volatile uint32_t VDDEXT_UV_CLR : 1;
      volatile uint32_t VSD_OV_CLR : 1;
            uint32_t : 7;
    } bit;
  } WAKE_STS_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CAN_SET : 1;
            uint32_t : 1;
      volatile uint32_t CYC_WAKE_SET : 1;
            uint32_t : 1;
      volatile uint32_t GPIO0_SET : 1;
      volatile uint32_t GPIO1_SET : 1;
      volatile uint32_t GPIO2_SET : 1;
      volatile uint32_t GPIO3_SET : 1;
      volatile uint32_t GPIO4_SET : 1;
      volatile uint32_t GPIO5_SET : 1;
            uint32_t : 2;
      volatile uint32_t MON1_SET : 1;
      volatile uint32_t MON2_SET : 1;
      volatile uint32_t MON3_SET : 1;
            uint32_t : 1;
      volatile uint32_t VDDP_UVWARN_SET : 1;
      volatile uint32_t VDDP_OV_SET : 1;
      volatile uint32_t VDDP_HCM_SET : 1;
      volatile uint32_t VDDC_UVWARN_SET : 1;
      volatile uint32_t VDDC_OV_SET : 1;
      volatile uint32_t VDDC_HCM_SET : 1;
      volatile uint32_t VDDEXT_OT_SET : 1;
      volatile uint32_t VDDEXT_UV_SET : 1;
      volatile uint32_t VSD_OV_SET : 1;
            uint32_t : 7;
    } bit;
  } WAKE_STS_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DATA : 32;
    } bit;
  } GPUDATA0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DATA : 32;
    } bit;
  } GPUDATA1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DATA : 32;
    } bit;
  } GPUDATA2;
  volatile const uint32_t RESERVED[13];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t FI_PU_EN : 1;
            uint32_t : 15;
      volatile uint32_t TRIG_RST : 1;
            uint32_t : 15;
    } bit;
  } MISC_CTRL;
  volatile const uint32_t RESERVED1[2];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CONF : 1;
      volatile uint32_t RST_PIN_EN : 1;
            uint32_t : 30;
    } bit;
  } START_CONFIG;
  volatile const uint32_t RESERVED2[390];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 2;
            uint32_t : 14;
      volatile uint32_t WDP : 6;
            uint32_t : 2;
      volatile uint32_t SOW : 2;

            uint32_t : 6;
    } bit;
  } WD_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TRIG : 1;
            uint32_t : 31;
    } bit;
  } WD_TRIG;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TRIG : 1;
            uint32_t : 31;
    } bit;
  } WD_TRIG_SOW;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MCLK_FAIL_STS : 1;
      volatile const uint32_t VMSUP_UV_STS : 1;
      volatile const uint32_t VMSUP_OV_STS : 1;
      volatile const uint32_t WD_FAIL_STS : 1;
      volatile const uint32_t WD_TEST_FAIL_STS : 1;
      volatile const uint32_t VDDC_UV_STS : 1;
      volatile const uint32_t VDDC_OV_STS : 1;
      volatile const uint32_t VDDP_UV_STS : 1;
      volatile const uint32_t VDDP_OV_STS : 1;
      volatile const uint32_t VDDP_OT_STS : 1;
      volatile const uint32_t VAREF_OV_STS : 1;
      volatile const uint32_t CSC_OC_STS : 1;
      volatile const uint32_t CSC_BIST_FAIL_STS : 1;
      volatile const uint32_t CSC_EN_FAIL_STS : 1;
      volatile const uint32_t PIN_MON_STS : 1;
            uint32_t : 1;
      volatile const uint32_t FO_OC_STS : 1;
            uint32_t : 15;
    } bit;
  } FS_STS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MCLK_FAIL_STS_CLR : 1;
      volatile uint32_t VMSUP_UV_STS_CLR : 1;
      volatile uint32_t VMSUP_OV_STS_CLR : 1;
      volatile uint32_t WD_FAIL_STS_CLR : 1;
      volatile uint32_t WD_TEST_FAIL_STS_CLR : 1;
      volatile uint32_t VDDC_UV_STS_CLR : 1;
      volatile uint32_t VDDC_OV_STS_CLR : 1;
      volatile uint32_t VDDP_UV_STS_CLR : 1;
      volatile uint32_t VDDP_OV_STS_CLR : 1;
      volatile uint32_t VDDP_OT_STS_CLR : 1;
      volatile uint32_t VAREF_OV_STS_CLR : 1;
      volatile uint32_t CSC_OC_STS_CLR : 1;
      volatile uint32_t CSC_BIST_FAIL_STS_CLR : 1;
      volatile uint32_t CSC_EN_FAIL_STS_CLR : 1;
      volatile uint32_t PIN_MON_STS_CLR : 1;
            uint32_t : 1;
      volatile uint32_t FO_OC_STS_CLR : 1;
            uint32_t : 15;
    } bit;
  } FS_STS_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MCLK_FAIL_STS_SET : 1;
      volatile uint32_t VMSUP_UV_STS_SET : 1;
      volatile uint32_t VMSUP_OV_STS_SET : 1;
      volatile uint32_t WD_FAIL_STS_SET : 1;
      volatile uint32_t WD_TEST_FAIL_STS_SET : 1;
      volatile uint32_t VDDC_UV_STS_SET : 1;
      volatile uint32_t VDDC_OV_STS_SET : 1;
      volatile uint32_t VDDP_UV_STS_SET : 1;
      volatile uint32_t VDDP_OV_STS_SET : 1;
      volatile uint32_t VDDP_OT_STS_SET : 1;
      volatile uint32_t VAREF_OV_STS_SET : 1;
      volatile uint32_t CSC_OC_STS_SET : 1;
      volatile uint32_t CSC_BIST_FAIL_STS_SET : 1;
      volatile uint32_t CSC_EN_FAIL_STS_SET : 1;
      volatile uint32_t PIN_MON_STS_SET : 1;
            uint32_t : 1;
      volatile uint32_t FO_OC_STS_SET : 1;
            uint32_t : 15;
    } bit;
  } FS_STS_SET;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t SSD_STS : 2;
      volatile const uint32_t FO_STS : 2;
            uint32_t : 28;
    } bit;
  } FS_SSD;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SSD_STS_CLR : 1;
      volatile uint32_t FO_STS_CLR : 1;
            uint32_t : 30;
    } bit;
  } FS_SSD_CLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SSD_STS_SET : 1;
      volatile uint32_t FO_STS_SET : 1;
            uint32_t : 30;
    } bit;
  } FS_SSD_SET;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CSC_DIS : 1;
            uint32_t : 31;
    } bit;
  } CSC_CTRL;
} PMU_Type;
# 19163 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SELSYS0 : 2;
      volatile uint32_t SELSYS1 : 2;
            uint32_t : 12;
      volatile uint32_t SELCLKOUT : 3;
      volatile uint32_t CLKOUTEN : 1;
            uint32_t : 12;
    } bit;
  } CLKSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t PRECPU : 3;
            uint32_t : 1;
      volatile uint32_t PREFILT : 5;
      volatile uint32_t PREMI : 3;
            uint32_t : 4;
      volatile uint32_t PRECAN : 3;
            uint32_t : 1;
      volatile uint32_t PREUART : 3;
            uint32_t : 1;
      volatile uint32_t PRECLKOUT : 3;

      volatile uint32_t DIV2CLKOUT : 1;
            uint32_t : 4;
    } bit;
  } CLKCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t UARTCLKEN : 1;
      volatile uint32_t CANCLKEN : 1;
            uint32_t : 30;
    } bit;
  } CLKEN;
  volatile const uint32_t RESERVED[2];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t XPD : 1;
      volatile uint32_t XTALHYSEN : 1;
            uint32_t : 2;
      volatile uint32_t XTALHYS : 2;
            uint32_t : 18;
      volatile uint32_t XWDGEN : 1;
            uint32_t : 3;
      volatile uint32_t XWDGRES : 1;
            uint32_t : 3;
    } bit;
  } XTALCON;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t XTAL_FAIL_STS : 1;
            uint32_t : 7;
      volatile const uint32_t XTALFAIL : 1;
            uint32_t : 23;
    } bit;
  } XTALSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t XTAL_FAIL_STSCLR : 1;
            uint32_t : 31;
    } bit;
  } XTALSTATC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t XTAL_FAIL_STSSET : 1;
            uint32_t : 31;
    } bit;
  } XTALSTATS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_PMU : 1;
      volatile uint32_t INP_BDRV_IRQ0 : 1;
      volatile uint32_t INP_BDRV_IRQ1 : 1;
      volatile uint32_t INP_CANTX : 1;
      volatile uint32_t INP_ARVG : 1;
      volatile uint32_t INP_CSC : 1;
            uint32_t : 26;
    } bit;
  } INP0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_GPT1T2 : 1;
      volatile uint32_t INP_GPT1T3 : 1;
      volatile uint32_t INP_GPT1T4 : 1;
      volatile uint32_t INP_GPT2T5 : 1;
      volatile uint32_t INP_GPT2T6 : 1;
      volatile uint32_t INP_GPT2CR : 1;
            uint32_t : 26;
    } bit;
  } INP1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_MON1 : 1;
      volatile uint32_t INP_MON2 : 1;
      volatile uint32_t INP_MON3 : 1;
            uint32_t : 29;
    } bit;
  } INP2;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_SDADC0 : 1;
      volatile uint32_t INP_SDADC1 : 1;
      volatile uint32_t INP_BEMF0 : 1;
      volatile uint32_t INP_BEMF1 : 1;
      volatile uint32_t INP_BEMF2 : 1;
            uint32_t : 27;
    } bit;
  } INP3;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_EXINT0 : 1;
      volatile uint32_t INP_EXINT1 : 1;
      volatile uint32_t INP_EXINT2 : 1;
      volatile uint32_t INP_EXINT3 : 1;
            uint32_t : 28;
    } bit;
  } INP4;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_LIN0_EOFSYN : 1;
      volatile uint32_t INP_LIN0_ERRSYN : 1;
      volatile uint32_t INP_LIN1_EOFSYN : 1;
      volatile uint32_t INP_LIN1_ERRSYN : 1;
      volatile uint32_t INP_UART0_RI : 1;
      volatile uint32_t INP_UART0_TI : 1;
      volatile uint32_t INP_UART1_RI : 1;
      volatile uint32_t INP_UART1_TI : 1;
            uint32_t : 24;
    } bit;
  } INP5;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_SSC0_RIR : 1;
      volatile uint32_t INP_SSC0_TIR : 1;
      volatile uint32_t INP_SSC0_EIR : 1;
            uint32_t : 1;
      volatile uint32_t INP_SSC1_RIR : 1;
      volatile uint32_t INP_SSC1_TIR : 1;
      volatile uint32_t INP_SSC1_EIR : 1;
            uint32_t : 25;
    } bit;
  } INP6;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t INP_DMACH0 : 1;
      volatile uint32_t INP_DMACH1 : 1;
      volatile uint32_t INP_DMACH2 : 1;
      volatile uint32_t INP_DMACH3 : 1;
      volatile uint32_t INP_DMACH4 : 1;
      volatile uint32_t INP_DMACH5 : 1;
      volatile uint32_t INP_DMACH6 : 1;
      volatile uint32_t INP_DMACH7 : 1;
      volatile uint32_t INP_DMATRERR : 1;
            uint32_t : 23;
    } bit;
  } INP7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NMIXTALEN : 1;
      volatile uint32_t NMIPLL0EN : 1;
      volatile uint32_t NMIPLL1EN : 1;
            uint32_t : 29;
    } bit;
  } NMICON;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t NMIXTAL : 1;
      volatile const uint32_t NMIPLL0 : 1;
      volatile const uint32_t NMIPLL1 : 1;
            uint32_t : 29;
    } bit;
  } NMISR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NMIXTALCLR : 1;
      volatile uint32_t NMIPLL0CLR : 1;
      volatile uint32_t NMIPLL1CLR : 1;
            uint32_t : 29;
    } bit;
  } NMISRC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t NMIXTALSET : 1;
      volatile uint32_t NMIPLL0SET : 1;
      volatile uint32_t NMIPLL1SET : 1;
            uint32_t : 29;
    } bit;
  } NMISRS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MON1EN : 1;
      volatile uint32_t MON2EN : 1;
      volatile uint32_t MON3EN : 1;
            uint32_t : 29;
    } bit;
  } MONIEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t MON1R : 1;
      volatile const uint32_t MON1F : 1;
      volatile const uint32_t MON2R : 1;
      volatile const uint32_t MON2F : 1;
      volatile const uint32_t MON3R : 1;
      volatile const uint32_t MON3F : 1;
            uint32_t : 26;
    } bit;
  } MONIS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MON1RCLR : 1;
      volatile uint32_t MON1FCLR : 1;
      volatile uint32_t MON2RCLR : 1;
      volatile uint32_t MON2FCLR : 1;
      volatile uint32_t MON3RCLR : 1;
      volatile uint32_t MON3FCLR : 1;
            uint32_t : 26;
    } bit;
  } MONISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MON1RSET : 1;
      volatile uint32_t MON1FSET : 1;
      volatile uint32_t MON2RSET : 1;
      volatile uint32_t MON2FSET : 1;
      volatile uint32_t MON3RSET : 1;
      volatile uint32_t MON3FSET : 1;
            uint32_t : 26;
    } bit;
  } MONISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MON1IEV : 2;
      volatile uint32_t MON2IEV : 2;
      volatile uint32_t MON3IEV : 2;
            uint32_t : 26;
    } bit;
  } MONCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EXTINT0EN : 1;
      volatile uint32_t EXTINT1EN : 1;
      volatile uint32_t EXTINT2EN : 1;
      volatile uint32_t EXTINT3EN : 1;
            uint32_t : 28;
    } bit;
  } EXTIEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t EXTINT0R : 1;
      volatile const uint32_t EXTINT0F : 1;
      volatile const uint32_t EXTINT1R : 1;
      volatile const uint32_t EXTINT1F : 1;
      volatile const uint32_t EXTINT2R : 1;
      volatile const uint32_t EXTINT2F : 1;
      volatile const uint32_t EXTINT3R : 1;
      volatile const uint32_t EXTINT3F : 1;
            uint32_t : 24;
    } bit;
  } EXTIS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EXTINT0RCLR : 1;
      volatile uint32_t EXTINT0FCLR : 1;
      volatile uint32_t EXTINT1RCLR : 1;
      volatile uint32_t EXTINT1FCLR : 1;
      volatile uint32_t EXTINT2RCLR : 1;
      volatile uint32_t EXTINT2FCLR : 1;
      volatile uint32_t EXTINT3RCLR : 1;
      volatile uint32_t EXTINT3FCLR : 1;
            uint32_t : 24;
    } bit;
  } EXTISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EXTINT0RSET : 1;
      volatile uint32_t EXTINT0FSET : 1;
      volatile uint32_t EXTINT1RSET : 1;
      volatile uint32_t EXTINT1FSET : 1;
      volatile uint32_t EXTINT2RSET : 1;
      volatile uint32_t EXTINT2FSET : 1;
      volatile uint32_t EXTINT3RSET : 1;
      volatile uint32_t EXTINT3FSET : 1;
            uint32_t : 24;
    } bit;
  } EXTISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EXTINT0IEV : 2;
      volatile uint32_t EXTINT1IEV : 2;
      volatile uint32_t EXTINT2IEV : 2;
      volatile uint32_t EXTINT3IEV : 2;
      volatile uint32_t EXTINT0INSEL : 2;
      volatile uint32_t EXTINT1INSEL : 2;
      volatile uint32_t EXTINT2INSEL : 2;
      volatile uint32_t EXTINT3INSEL : 2;
            uint32_t : 16;
    } bit;
  } EXTCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t GPT1T2EN : 1;
      volatile uint32_t GPT1T3EN : 1;
      volatile uint32_t GPT1T4EN : 1;
      volatile uint32_t GPT2T5EN : 1;
      volatile uint32_t GPT2T6EN : 1;
      volatile uint32_t GPT2CREN : 1;
            uint32_t : 26;
    } bit;
  } GPTIEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t GPT1T2 : 1;
      volatile const uint32_t GPT1T3 : 1;
      volatile const uint32_t GPT1T4 : 1;
      volatile const uint32_t GPT2T5 : 1;
      volatile const uint32_t GPT2T6 : 1;
      volatile const uint32_t GPT2CR : 1;
            uint32_t : 26;
    } bit;
  } GPTIS;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t GPT1T2CLR : 1;
      volatile uint32_t GPT1T3CLR : 1;
      volatile uint32_t GPT1T4CLR : 1;
      volatile uint32_t GPT2T5CLR : 1;
      volatile uint32_t GPT2T6CLR : 1;
      volatile uint32_t GPT2CRCLR : 1;
            uint32_t : 26;
    } bit;
  } GPTISC;

  union {
    volatile uint32_t reg;


    struct {
      volatile uint32_t GPT1T2SET : 1;
      volatile uint32_t GPT1T3SET : 1;
      volatile uint32_t GPT1T4SET : 1;
      volatile uint32_t GPT2T5SET : 1;
      volatile uint32_t GPT2T6SET : 1;
      volatile uint32_t GPT2CRSET : 1;
            uint32_t : 26;
    } bit;
  } GPTISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DMACH0EN : 1;
      volatile uint32_t DMACH1EN : 1;
      volatile uint32_t DMACH2EN : 1;
      volatile uint32_t DMACH3EN : 1;
      volatile uint32_t DMACH4EN : 1;
      volatile uint32_t DMACH5EN : 1;
      volatile uint32_t DMACH6EN : 1;
      volatile uint32_t DMACH7EN : 1;
      volatile uint32_t DMATRERREN : 1;
            uint32_t : 23;
    } bit;
  } DMAIEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t DMACH0 : 1;
      volatile const uint32_t DMACH1 : 1;
      volatile const uint32_t DMACH2 : 1;
      volatile const uint32_t DMACH3 : 1;
      volatile const uint32_t DMACH4 : 1;
      volatile const uint32_t DMACH5 : 1;
      volatile const uint32_t DMACH6 : 1;
      volatile const uint32_t DMACH7 : 1;
            uint32_t : 24;
    } bit;
  } DMAIS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DMACH0CLR : 1;
      volatile uint32_t DMACH1CLR : 1;
      volatile uint32_t DMACH2CLR : 1;
      volatile uint32_t DMACH3CLR : 1;
      volatile uint32_t DMACH4CLR : 1;
      volatile uint32_t DMACH5CLR : 1;
      volatile uint32_t DMACH6CLR : 1;
      volatile uint32_t DMACH7CLR : 1;
            uint32_t : 24;
    } bit;
  } DMAISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DMACH0SET : 1;
      volatile uint32_t DMACH1SET : 1;
      volatile uint32_t DMACH2SET : 1;
      volatile uint32_t DMACH3SET : 1;
      volatile uint32_t DMACH4SET : 1;
      volatile uint32_t DMACH5SET : 1;
      volatile uint32_t DMACH6SET : 1;
      volatile uint32_t DMACH7SET : 1;
            uint32_t : 24;
    } bit;
  } DMAISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T12CM70 : 2;
      volatile uint32_t T12CM71 : 2;
      volatile uint32_t T12CM72 : 2;
      volatile uint32_t T12PM : 2;
      volatile uint32_t T12ZM : 2;
      volatile uint32_t T13CM : 2;
      volatile uint32_t T13PM : 2;
      volatile uint32_t T13ZM : 2;
      volatile uint32_t T14CM : 2;
      volatile uint32_t T14PM : 2;
      volatile uint32_t T15CM : 2;
      volatile uint32_t T15PM : 2;
      volatile uint32_t T16CM : 2;
      volatile uint32_t T16PM : 2;
      volatile uint32_t CHE : 2;
            uint32_t : 2;
    } bit;
  } DMAP_CCU7;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ADC1_RES0 : 2;
      volatile uint32_t ADC1_RES1 : 2;
      volatile uint32_t ADC1_RES2 : 2;
      volatile uint32_t ADC1_RES3 : 2;
      volatile uint32_t ADC1_RES4 : 2;
      volatile uint32_t ADC1_RES5 : 2;
      volatile uint32_t ADC1_RES6 : 2;
      volatile uint32_t ADC1_RES7 : 2;
      volatile uint32_t ADC1_SQ0 : 2;
      volatile uint32_t ADC1_SQ1 : 2;
      volatile uint32_t ADC1_CMPLO : 2;
      volatile uint32_t ADC1_CMPHI : 2;
      volatile uint32_t SDADC_RES0 : 2;
      volatile uint32_t SDADC_RES1 : 2;
            uint32_t : 4;
    } bit;
  } DMAP_ADC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T2OV : 1;
      volatile uint32_t T21OV : 1;
            uint32_t : 6;
      volatile uint32_t GPT12T2 : 1;
      volatile uint32_t GPT12T3 : 1;
      volatile uint32_t GPT12T4 : 1;
      volatile uint32_t GPT12T5 : 1;
      volatile uint32_t GPT12T6 : 1;
      volatile uint32_t GPT12CR : 1;
            uint32_t : 18;
    } bit;
  } DMAP_TIM;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SSC0_RIR : 2;
      volatile uint32_t SSC0_TIR : 2;
      volatile uint32_t SSC1_RIR : 2;
      volatile uint32_t SSC1_TIR : 2;
      volatile uint32_t UART0_RI : 2;
      volatile uint32_t UART0_TI : 2;
      volatile uint32_t UART1_RI : 2;
      volatile uint32_t UART1_TI : 2;
      volatile uint32_t CAN_IR0 : 1;
            uint32_t : 1;
      volatile uint32_t CAN_IR1 : 1;
            uint32_t : 13;
    } bit;
  } DMAP_COM;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t SLEEP : 1;
      volatile uint32_t STOP : 1;
            uint32_t : 29;
    } bit;
  } PMCON0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SSC0_DIS : 1;
      volatile uint32_t SSC1_DIS : 1;
      volatile uint32_t T2_DIS : 1;
      volatile uint32_t T21_DIS : 1;
      volatile uint32_t GPT12_DIS : 1;
            uint32_t : 27;
    } bit;
  } PMCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SSC0SUS : 1;
      volatile uint32_t SSC1SUS : 1;
      volatile uint32_t T2SUS : 1;
      volatile uint32_t T21SUS : 1;
      volatile uint32_t GPT12SUS : 1;
      volatile uint32_t WDTSUS : 1;
            uint32_t : 26;
    } bit;
  } SUSCTR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t OT_SLEEP_EN : 1;
            uint32_t : 13;
      volatile uint32_t OTWARN_SD_DIS : 1;
      volatile uint32_t XTALWDG_SD_DIS : 1;
            uint32_t : 8;
      volatile uint32_t BDRV_SD_EN : 1;
            uint32_t : 7;
    } bit;
  } PCU_CTRL;
  volatile const uint32_t RESERVED1[9];

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DEMEN_CH0 : 1;
      volatile uint32_t DEMEN_CH1 : 1;
      volatile uint32_t DEMEN_CH2 : 1;
      volatile uint32_t DEMEN_CH3 : 1;
      volatile uint32_t DEMEN_CH4 : 1;
      volatile uint32_t DEMEN_CH5 : 1;
      volatile uint32_t DEMEN_CH6 : 1;
      volatile uint32_t DEMEN_CH7 : 1;
      volatile uint32_t DMAREQINTEN_CH0 : 1;
      volatile uint32_t DMAREQINTEN_CH1 : 1;
      volatile uint32_t DMAREQINTEN_CH2 : 1;
      volatile uint32_t DMAREQINTEN_CH3 : 1;
      volatile uint32_t DMAREQINTEN_CH4 : 1;
      volatile uint32_t DMAREQINTEN_CH5 : 1;
      volatile uint32_t DMAREQINTEN_CH6 : 1;
      volatile uint32_t DMAREQINTEN_CH7 : 1;
            uint32_t : 16;
    } bit;
  } DMACTRL;
  volatile const uint32_t RESERVED2;

  union {
    volatile uint32_t reg;

 struct {
      volatile uint32_t LOCKUP_EN : 1;
         uint32_t : 31;
    } bit;
  } LOCKUPCFG;
} SCU_Type;
# 19853 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN0 : 1;
      volatile uint32_t CICMODE0 : 1;
      volatile uint32_t WFREN0 : 1;
            uint32_t : 5;
      volatile uint32_t EN1 : 1;
      volatile uint32_t CICMODE1 : 1;
      volatile uint32_t WFREN1 : 1;
            uint32_t : 5;
      volatile uint32_t PRE : 3;
      volatile uint32_t DITHEREN : 1;
            uint32_t : 12;
    } bit;
  } CFG0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DECF0 : 9;
            uint32_t : 3;
      volatile uint32_t RESSHIFT0 : 4;
      volatile uint32_t DECF1 : 9;
            uint32_t : 3;
      volatile uint32_t RESSHIFT1 : 4;
    } bit;
  } CFG1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MCLK : 2;
            uint32_t : 2;
      volatile uint32_t DOUT0 : 2;
            uint32_t : 2;
      volatile uint32_t DOUT1 : 2;
            uint32_t : 22;
    } bit;
  } ALTSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t IN0PSEL : 2;
      volatile uint32_t IN0NSEL : 2;
      volatile uint32_t DIN0SEL : 2;
      volatile uint32_t TRG0SEL : 1;
            uint32_t : 9;
      volatile uint32_t IN1PSEL : 2;
      volatile uint32_t IN1NSEL : 2;
      volatile uint32_t DIN1SEL : 2;
      volatile uint32_t TRG1SEL : 1;
            uint32_t : 9;
    } bit;
  } INSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RES0_EN : 1;
      volatile uint32_t CMP0_UP_EN : 1;
      volatile uint32_t CMP0_LO_EN : 1;
            uint32_t : 1;
      volatile uint32_t RES1_EN : 1;
      volatile uint32_t CMP1_UP_EN : 1;
      volatile uint32_t CMP1_LO_EN : 1;
            uint32_t : 25;
    } bit;
  } IEN;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RES0_IS : 1;
      volatile uint32_t CMP0_UP_IS : 1;
      volatile uint32_t CMP0_LO_IS : 1;
            uint32_t : 1;
      volatile uint32_t RES1_IS : 1;
      volatile uint32_t CMP1_UP_IS : 1;
      volatile uint32_t CMP1_LO_IS : 1;
            uint32_t : 25;
    } bit;
  } IS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RES0_ISC : 1;
      volatile uint32_t CMP0_UP_ISC : 1;
      volatile uint32_t CMP0_LO_ISC : 1;
            uint32_t : 1;
      volatile uint32_t RES1_ISC : 1;
      volatile uint32_t CMP1_UP_ISC : 1;
      volatile uint32_t CMP1_LO_ISC : 1;
            uint32_t : 25;
    } bit;
  } ISR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RES0_ISS : 1;
      volatile uint32_t CMP0_UP_ISS : 1;
      volatile uint32_t CMP0_LO_ISS : 1;
            uint32_t : 1;
      volatile uint32_t RES1_ISS : 1;
      volatile uint32_t CMP1_UP_ISS : 1;
      volatile uint32_t CMP1_LO_ISS : 1;
            uint32_t : 25;
    } bit;
  } ISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RES0_INP : 1;
      volatile uint32_t CMP0_UP_INP : 1;
      volatile uint32_t CMP0_LO_INP : 1;
            uint32_t : 1;
      volatile uint32_t RES1_INP : 1;
      volatile uint32_t CMP1_UP_INP : 1;
      volatile uint32_t CMP1_LO_INP : 1;
            uint32_t : 25;
    } bit;
  } INP;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EN : 1;
            uint32_t : 31;
    } bit;
  } SUSCTR;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t STAT : 1;
            uint32_t : 31;
    } bit;
  } SUSSTAT;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 9;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;

      volatile uint32_t UPLO_OUTSEL : 2;

      volatile uint32_t UPPER : 9;
            uint32_t : 3;
      volatile uint32_t HYST_UP : 2;

      volatile uint32_t MODE : 2;
    } bit;
  } CMP0_CTRL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t LOWER : 9;
            uint32_t : 3;
      volatile uint32_t HYST_LO : 2;

      volatile uint32_t UPLO_OUTSEL : 2;

      volatile uint32_t UPPER : 9;
            uint32_t : 3;
      volatile uint32_t HYST_UP : 2;

      volatile uint32_t MODE : 2;
    } bit;
  } CMP1_CTRL;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 16;
      volatile const uint32_t TIMVAL : 9;
            uint32_t : 3;
      volatile const uint32_t VALCNT : 3;
      volatile const uint32_t RESVALID : 1;
    } bit;
  } RES0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RESULT : 16;
      volatile const uint32_t TIMVAL : 9;
            uint32_t : 3;
      volatile const uint32_t VALCNT : 3;
      volatile const uint32_t RESVALID : 1;
    } bit;
  } RES1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t TIMVAL : 9;
            uint32_t : 23;
    } bit;
  } CTIM0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t TIMVAL : 9;
            uint32_t : 23;
    } bit;
  } CTIM1;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DITH_VOLT_SEL : 4;
            uint32_t : 28;
    } bit;
  } DITHCFG;
  volatile const uint32_t RESERVED;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t CMP0_UP_SC : 1;
      volatile uint32_t CMP0_LO_SC : 1;
      volatile uint32_t WFR0_SC : 1;
            uint32_t : 1;
      volatile uint32_t CMP1_UP_SC : 1;
      volatile uint32_t CMP1_LO_SC : 1;
      volatile uint32_t WFR1_SC : 1;
            uint32_t : 24;
    } bit;
  } STSR;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t CMP0_UP_STS : 1;
      volatile uint32_t CMP0_LO_STS : 1;
      volatile uint32_t WFR0_STS : 1;
            uint32_t : 1;
      volatile uint32_t CMP1_UP_STS : 1;
      volatile uint32_t CMP1_LO_STS : 1;
      volatile uint32_t WFR1_STS : 1;
            uint32_t : 24;
    } bit;
  } STS;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 1;
      volatile uint32_t CMP0_UP_SS : 1;
      volatile uint32_t CMP0_LO_SS : 1;
      volatile uint32_t WFR0_SS : 1;
            uint32_t : 1;
      volatile uint32_t CMP1_UP_SS : 1;
      volatile uint32_t CMP1_LO_SS : 1;
      volatile uint32_t WFR1_SS : 1;
            uint32_t : 24;
    } bit;
  } STSS;
} SDADC_Type;
# 20157 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BM : 6;
      volatile uint32_t HB : 1;
      volatile uint32_t PH : 1;
      volatile uint32_t PO : 1;
      volatile uint32_t LB : 1;
            uint32_t : 2;
      volatile uint32_t AREN : 1;
            uint32_t : 1;
      volatile uint32_t MS : 1;
      volatile uint32_t EN : 1;
      volatile uint32_t SLCSEN : 1;
      volatile uint32_t MSCSEN : 1;
      volatile uint32_t MSCSSEL : 4;
      volatile uint32_t MSTXSTART : 1;
      volatile uint32_t MSTXENSEL : 2;
            uint32_t : 7;
    } bit;
  } CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MRSTSEL : 2;
      volatile uint32_t SLCLKSEL : 2;
      volatile uint32_t MTSRSEL : 2;
      volatile uint32_t SLCSSEL : 2;
      volatile uint32_t TXEVSEL : 2;
            uint32_t : 22;
    } bit;
  } INSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ST : 6;
            uint32_t : 2;
      volatile uint32_t END : 6;
            uint32_t : 2;
      volatile uint32_t HIGH : 6;
            uint32_t : 10;
    } bit;
  } CSTIM;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIREN : 1;
      volatile uint32_t RIREN : 1;
      volatile uint32_t TEIREN : 1;
      volatile uint32_t REIREN : 1;
      volatile uint32_t PEIREN : 1;
      volatile uint32_t BEIREN : 1;
            uint32_t : 26;
    } bit;
  } IEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t TIR : 1;
      volatile const uint32_t RIR : 1;
      volatile const uint32_t TEIR : 1;
      volatile const uint32_t REIR : 1;
      volatile const uint32_t PEIR : 1;
      volatile const uint32_t BEIR : 1;
            uint32_t : 26;
    } bit;
  } IS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIRSET : 1;
      volatile uint32_t RIRSET : 1;
      volatile uint32_t TEIRSET : 1;
      volatile uint32_t REIRSET : 1;
      volatile uint32_t PEIRSET : 1;
      volatile uint32_t BEIRSET : 1;
            uint32_t : 26;
    } bit;
  } ISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIRCLR : 1;
      volatile uint32_t RIRCLR : 1;
      volatile uint32_t TEIRCLR : 1;
      volatile uint32_t REIRCLR : 1;
      volatile uint32_t PEIRCLR : 1;
      volatile uint32_t BEIRCLR : 1;
            uint32_t : 26;
    } bit;
  } ISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BR_VALUE : 16;
            uint32_t : 16;
    } bit;
  } BR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TB_VALUE_LOWER : 32;
    } bit;
  } TB0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TB_VALUE_UPPER : 32;
    } bit;
  } TB1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RB_VALUE_LOWER : 32;
    } bit;
  } RB0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RB_VALUE_UPPER : 32;
    } bit;
  } RB1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BC : 6;
      volatile const uint32_t BSY : 1;
            uint32_t : 25;
    } bit;
  } STAT;
} SSC0_Type;
# 20327 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BM : 6;
      volatile uint32_t HB : 1;
      volatile uint32_t PH : 1;
      volatile uint32_t PO : 1;
      volatile uint32_t LB : 1;
            uint32_t : 2;
      volatile uint32_t AREN : 1;
            uint32_t : 1;
      volatile uint32_t MS : 1;
      volatile uint32_t EN : 1;
      volatile uint32_t SLCSEN : 1;
      volatile uint32_t MSCSEN : 1;
      volatile uint32_t MSCSSEL : 4;
      volatile uint32_t MSTXSTART : 1;
      volatile uint32_t MSTXENSEL : 2;
            uint32_t : 7;
    } bit;
  } CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t MRSTSEL : 2;
      volatile uint32_t SLCLKSEL : 2;
      volatile uint32_t MTSRSEL : 2;
      volatile uint32_t SLCSSEL : 2;
      volatile uint32_t TXEVSEL : 2;
            uint32_t : 22;
    } bit;
  } INSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t ST : 6;
            uint32_t : 2;
      volatile uint32_t END : 6;
            uint32_t : 2;
      volatile uint32_t HIGH : 6;
            uint32_t : 10;
    } bit;
  } CSTIM;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIREN : 1;
      volatile uint32_t RIREN : 1;
      volatile uint32_t TEIREN : 1;
      volatile uint32_t REIREN : 1;
      volatile uint32_t PEIREN : 1;
      volatile uint32_t BEIREN : 1;
            uint32_t : 26;
    } bit;
  } IEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t TIR : 1;
      volatile const uint32_t RIR : 1;
      volatile const uint32_t TEIR : 1;
      volatile const uint32_t REIR : 1;
      volatile const uint32_t PEIR : 1;
      volatile const uint32_t BEIR : 1;
            uint32_t : 26;
    } bit;
  } IS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIRSET : 1;
      volatile uint32_t RIRSET : 1;
      volatile uint32_t TEIRSET : 1;
      volatile uint32_t REIRSET : 1;
      volatile uint32_t PEIRSET : 1;
      volatile uint32_t BEIRSET : 1;
            uint32_t : 26;
    } bit;
  } ISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIRCLR : 1;
      volatile uint32_t RIRCLR : 1;
      volatile uint32_t TEIRCLR : 1;
      volatile uint32_t REIRCLR : 1;
      volatile uint32_t PEIRCLR : 1;
      volatile uint32_t BEIRCLR : 1;
            uint32_t : 26;
    } bit;
  } ISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BR_VALUE : 16;
            uint32_t : 16;
    } bit;
  } BR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TB_VALUE_LOWER : 32;
    } bit;
  } TB0;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TB_VALUE_UPPER : 32;
    } bit;
  } TB1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RB_VALUE_LOWER : 32;
    } bit;
  } RB0;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RB_VALUE_UPPER : 32;
    } bit;
  } RB1;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BC : 6;
      volatile const uint32_t BSY : 1;
            uint32_t : 25;
    } bit;
  } STAT;
} SSC1_Type;
# 20497 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CP_RL2 : 1;
      volatile uint32_t C_T2 : 1;
      volatile uint32_t TR2 : 1;
      volatile uint32_t EXEN2 : 1;
            uint32_t : 2;
      volatile const uint32_t EXF2 : 1;
      volatile const uint32_t TF2 : 1;
      volatile uint32_t T2INSEL : 2;
      volatile uint32_t T2EXINSEL : 2;
            uint32_t : 20;
    } bit;
  } CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DCEN : 1;
      volatile uint32_t T2PRE : 3;
      volatile uint32_t PREN : 1;
      volatile uint32_t EDGESEL : 1;

      volatile uint32_t T2RHEN : 1;
      volatile uint32_t T2REGS : 1;
            uint32_t : 24;
    } bit;
  } MOD;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RCL2 : 8;
      volatile uint32_t RCH2 : 8;
            uint32_t : 16;
    } bit;
  } RC;
  volatile const uint32_t RESERVED;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T2L : 8;
      volatile uint32_t T2H : 8;
            uint32_t : 16;
    } bit;
  } CNT;
  volatile const uint32_t RESERVED1;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 6;
      volatile uint32_t EXF2CLR : 1;
      volatile uint32_t TF2CLR : 1;
            uint32_t : 24;
    } bit;
  } ICLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EXF2EN : 1;
      volatile uint32_t TF2EN : 1;
            uint32_t : 30;
    } bit;
  } CON1;
} T20_Type;
# 20586 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t CP_RL2 : 1;
      volatile uint32_t C_T2 : 1;
      volatile uint32_t TR2 : 1;
      volatile uint32_t EXEN2 : 1;
            uint32_t : 2;
      volatile const uint32_t EXF2 : 1;
      volatile const uint32_t TF2 : 1;
      volatile uint32_t T2INSEL : 2;
      volatile uint32_t T2EXINSEL : 2;
            uint32_t : 20;
    } bit;
  } CON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t DCEN : 1;
      volatile uint32_t T2PRE : 3;
      volatile uint32_t PREN : 1;
      volatile uint32_t EDGESEL : 1;

      volatile uint32_t T2RHEN : 1;
      volatile uint32_t T2REGS : 1;
            uint32_t : 24;
    } bit;
  } MOD;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RCL2 : 8;
      volatile uint32_t RCH2 : 8;
            uint32_t : 16;
    } bit;
  } RC;
  volatile const uint32_t RESERVED;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t T2L : 8;
      volatile uint32_t T2H : 8;
            uint32_t : 16;
    } bit;
  } CNT;
  volatile const uint32_t RESERVED1;

  union {
    volatile uint32_t reg;

    struct {
            uint32_t : 6;
      volatile uint32_t EXF2CLR : 1;
      volatile uint32_t TF2CLR : 1;
            uint32_t : 24;
    } bit;
  } ICLR;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t EXF2EN : 1;
      volatile uint32_t TF2EN : 1;
            uint32_t : 30;
    } bit;
  } CON1;
} T21_Type;
# 20675 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXDSEL : 2;
      volatile uint32_t TXEVSEL : 2;
            uint32_t : 28;
    } bit;
  } INSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SM0 : 1;
      volatile uint32_t SM1 : 1;
      volatile uint32_t SM2 : 1;

      volatile uint32_t REN : 1;
      volatile uint32_t RMOD : 1;
      volatile uint32_t TXINV : 1;
            uint32_t : 2;
      volatile uint32_t TXENSEL : 2;
            uint32_t : 22;
    } bit;
  } SCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TXSTART : 1;
            uint32_t : 31;
    } bit;
  } TSTART;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TXDATA : 8;
      volatile uint32_t TB8 : 1;
            uint32_t : 23;
    } bit;
  } TXBUF;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RXDATA : 8;
      volatile const uint32_t RB8 : 1;
            uint32_t : 23;
    } bit;
  } RXBUF;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIEN : 1;
      volatile uint32_t RIEN : 1;
            uint32_t : 6;
      volatile uint32_t ERRSYNEN : 1;
      volatile uint32_t EOFSYNEN : 1;
            uint32_t : 22;
    } bit;
  } IEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t TI : 1;
      volatile const uint32_t RI : 1;
            uint32_t : 6;
      volatile const uint32_t ERRSYN : 1;
      volatile const uint32_t EOFSYN : 1;
            uint32_t : 22;
    } bit;
  } IS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TISET : 1;
      volatile uint32_t RISET : 1;
            uint32_t : 6;
      volatile uint32_t ERRSYNSET : 1;
      volatile uint32_t EOFSYNSET : 1;
            uint32_t : 22;
    } bit;
  } ISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TICLR : 1;
      volatile uint32_t RICLR : 1;
            uint32_t : 6;
      volatile uint32_t ERRSYNCLR : 1;
      volatile uint32_t EOFSYNCLR : 1;
            uint32_t : 22;
    } bit;
  } ISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BR_R : 1;
            uint32_t : 3;
      volatile uint32_t BR_PRE : 3;
            uint32_t : 9;
      volatile uint32_t BG_FD_SEL : 5;
      volatile uint32_t BG_BR_VALUE : 11;
    } bit;
  } BCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BREN : 1;
      volatile uint32_t BGSEL : 2;
            uint32_t : 29;
    } bit;
  } LINCON;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BRK : 1;
            uint32_t : 31;
    } bit;
  } LINST;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BRKCLR : 1;
            uint32_t : 31;
    } bit;
  } LINSTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BRKSET : 1;
            uint32_t : 31;
    } bit;
  } LINSTS;
} UART0_Type;
# 20847 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
typedef struct {

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t RXDSEL : 2;
      volatile uint32_t TXEVSEL : 2;
            uint32_t : 28;
    } bit;
  } INSEL;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t SM0 : 1;
      volatile uint32_t SM1 : 1;
      volatile uint32_t SM2 : 1;

      volatile uint32_t REN : 1;
      volatile uint32_t RMOD : 1;
      volatile uint32_t TXINV : 1;
            uint32_t : 2;
      volatile uint32_t TXENSEL : 2;
            uint32_t : 22;
    } bit;
  } SCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TXSTART : 1;
            uint32_t : 31;
    } bit;
  } TSTART;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TXDATA : 8;
      volatile uint32_t TB8 : 1;
            uint32_t : 23;
    } bit;
  } TXBUF;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t RXDATA : 8;
      volatile const uint32_t RB8 : 1;
            uint32_t : 23;
    } bit;
  } RXBUF;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TIEN : 1;
      volatile uint32_t RIEN : 1;
            uint32_t : 6;
      volatile uint32_t ERRSYNEN : 1;
      volatile uint32_t EOFSYNEN : 1;
            uint32_t : 22;
    } bit;
  } IEN;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t TI : 1;
      volatile const uint32_t RI : 1;
            uint32_t : 6;
      volatile const uint32_t ERRSYN : 1;
      volatile const uint32_t EOFSYN : 1;
            uint32_t : 22;
    } bit;
  } IS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TISET : 1;
      volatile uint32_t RISET : 1;
            uint32_t : 6;
      volatile uint32_t ERRSYNSET : 1;
      volatile uint32_t EOFSYNSET : 1;
            uint32_t : 22;
    } bit;
  } ISS;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t TICLR : 1;
      volatile uint32_t RICLR : 1;
            uint32_t : 6;
      volatile uint32_t ERRSYNCLR : 1;
      volatile uint32_t EOFSYNCLR : 1;
            uint32_t : 22;
    } bit;
  } ISC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BR_R : 1;
            uint32_t : 3;
      volatile uint32_t BR_PRE : 3;
            uint32_t : 9;
      volatile uint32_t BG_FD_SEL : 5;
      volatile uint32_t BG_BR_VALUE : 11;
    } bit;
  } BCON;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BREN : 1;
      volatile uint32_t BGSEL : 2;
            uint32_t : 29;
    } bit;
  } LINCON;

  union {
    volatile const uint32_t reg;

    struct {
      volatile const uint32_t BRK : 1;
            uint32_t : 31;
    } bit;
  } LINST;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BRKCLR : 1;
            uint32_t : 31;
    } bit;
  } LINSTC;

  union {
    volatile uint32_t reg;

    struct {
      volatile uint32_t BRKSET : 1;
            uint32_t : 31;
    } bit;
  } LINSTS;
} UART1_Type;
# 21757 "./RTE/Device/TLE9893_2QKW62S/tle989x.h"
#pragma clang diagnostic pop
# 34 "RTE/Device/TLE9893_2QKW62S/isr_nvic_irq7_handler.c" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/isr.h" 1
# 92 "./RTE/Device/TLE9893_2QKW62S/isr.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/isr.h" 1
# 93 "./RTE/Device/TLE9893_2QKW62S/isr.h" 2


# 1 "./RTE/Device/TLE9893_2QKW62S/tle_variants.h" 1
# 352 "./RTE/Device/TLE9893_2QKW62S/tle_variants.h"
static __inline _Bool PtrRangeCheck(const void *ptr)
{
  _Bool b_res;
  b_res = 0;


  if ((((uint32)ptr >= (0x18000000U)) && ((uint32)ptr < ((0x18000000U) + (0x2000U)))) || (((uint32)ptr >= (0x18002000U)) && ((uint32)ptr < ((0x18002000U) + (0x5C00U)))))
  {
    b_res = 1;
  }

  return (b_res);
}
# 96 "./RTE/Device/TLE9893_2QKW62S/isr.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/isr_defines.h" 1
# 97 "./RTE/Device/TLE9893_2QKW62S/isr.h" 2
# 809 "./RTE/Device/TLE9893_2QKW62S/isr.h"
extern volatile uint32 u32_globTimestamp_ms;
# 845 "./RTE/Device/TLE9893_2QKW62S/isr.h"
  extern uint8 u8_interrupt_cnt_irq12;


  extern uint8 u8_interrupt_cnt_irq13;
# 911 "./RTE/Device/TLE9893_2QKW62S/isr.h"
static __inline uint32 INT_getGlobTimestamp(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void NMI_Handler(void);
void SysTick_Handler(void);
void PendSV_Handler(void);
void NVIC_IRQ0_Handler(void);
void NVIC_IRQ1_Handler(void);
void NVIC_IRQ2_Handler(void);
void NVIC_IRQ3_Handler(void);
void NVIC_IRQ4_Handler(void);
void NVIC_IRQ5_Handler(void);
void NVIC_IRQ6_Handler(void);
void NVIC_IRQ7_Handler(void);
void NVIC_IRQ8_Handler(void);
void NVIC_IRQ9_Handler(void);
void NVIC_IRQ10_Handler(void);
void NVIC_IRQ11_Handler(void);
void NVIC_IRQ12_Handler(void);
void NVIC_IRQ13_Handler(void);
void NVIC_IRQ14_Handler(void);
void NVIC_IRQ15_Handler(void);
void NVIC_IRQ16_Handler(void);
void NVIC_IRQ17_Handler(void);
void NVIC_IRQ18_Handler(void);
void NVIC_IRQ19_Handler(void);
void NVIC_IRQ20_Handler(void);
void NVIC_IRQ21_Handler(void);
void NVIC_IRQ22_Handler(void);
void NVIC_IRQ23_Handler(void);
void NVIC_IRQ24_Handler(void);
void NVIC_IRQ25_Handler(void);
void NVIC_IRQ26_Handler(void);
void NVIC_IRQ27_Handler(void);
void NVIC_IRQ28_Handler(void);
void NVIC_IRQ29_Handler(void);
void NVIC_IRQ30_Handler(void);
void NVIC_IRQ31_Handler(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
void Systick_ISR(void);
void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void T16_ISR(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void MEMCTRL_NVM0_OP_COMPLETE_CALLBACK(void);
extern void MEMCTRL_NVM1_OP_COMPLETE_CALLBACK(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void CANNODE_NODE0_TXOK_CALLBACK(void);
extern void CANNODE_NODE0_RXOK_CALLBACK(void);
extern void CANNODE_NODE0_LEC_CALLBACK(void);
extern void CANNODE_NODE0_EWRN_CALLBACK(void);
extern void CANNODE_NODE0_BOFF_CALLBACK(void);
extern void CANNODE_NODE0_LLE_CALLBACK(void);
extern void CANNODE_NODE0_LOE_CALLBACK(void);
extern void CANNODE_NODE0_CFCOV_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_RXOVF_CALLBACK(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
extern void t20_reload_inttrg(void);
extern void place_your_function_callback_here(void);
extern void place_your_function_callback_here(void);
# 1322 "./RTE/Device/TLE9893_2QKW62S/isr.h"
static __inline uint32 INT_getGlobTimestamp(void)
{
 return u32_globTimestamp_ms;
}
# 35 "RTE/Device/TLE9893_2QKW62S/isr_nvic_irq7_handler.c" 2

