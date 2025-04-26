# 1 "RTE/Device/TLE9893_2QKW62S/csacsc.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "RTE/Device/TLE9893_2QKW62S/csacsc.c" 2
# 33 "RTE/Device/TLE9893_2QKW62S/csacsc.c"
# 1 "./RTE/Device/TLE9893_2QKW62S/csacsc.h" 1
# 109 "./RTE/Device/TLE9893_2QKW62S/csacsc.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/types.h" 1
# 98 "./RTE/Device/TLE9893_2QKW62S/types.h"
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
# 99 "./RTE/Device/TLE9893_2QKW62S/types.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/error_codes.h" 1
# 61 "./RTE/Device/TLE9893_2QKW62S/error_codes.h"
# 1 "./RTE/_APP1\\RTE_Components.h" 1
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
# 110 "./RTE/Device/TLE9893_2QKW62S/csacsc.h" 2
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
# 86 "./RTE/Device/TLE9893_2QKW62S/system_tle989x.h"
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
# 111 "./RTE/Device/TLE9893_2QKW62S/csacsc.h" 2
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
# 112 "./RTE/Device/TLE9893_2QKW62S/csacsc.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/adc1.h" 1
# 123 "./RTE/Device/TLE9893_2QKW62S/adc1.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/adc1_defines.h" 1
# 124 "./RTE/Device/TLE9893_2QKW62S/adc1.h" 2
# 233 "./RTE/Device/TLE9893_2QKW62S/adc1.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"






typedef enum ADC1_Seq0Trig
{
  ADC1_Seq0Trig_SW = 0u,
  ADC1_Seq0Trig_T12ZM = 1u,
  ADC1_Seq0Trig_T12PM = 2u,
  ADC1_Seq0Trig_T13PM = 4u,
  ADC1_Seq0Trig_T16CM = 5u,
  ADC1_Seq0Trig_HallCorrect = 6u,
  ADC1_Seq0Trig_Seq0Complete = 7u,
  ADC1_Seq0Trig_Seq3Complete = 8u
} tADC1_Seq0Trig;





typedef enum ADC1_Seq1Trig
{
  ADC1_Seq1Trig_SW = 0u,
  ADC1_Seq1Trig_T12ZM = 1u,
  ADC1_Seq1Trig_T12CC70ACM = 2u,
  ADC1_Seq1Trig_T12C72BCM = 3u,
  ADC1_Seq1Trig_T14PM = 4u,
  ADC1_Seq1Trig_T13CM = 5u,
  ADC1_Seq1Trig_GPT1 = 6u,
  ADC1_Seq1Trig_Seq1Complete = 7u,
  ADC1_Seq1Trig_Seq0Complete = 8u
} tADC1_Seq1Trig;





typedef enum ADC1_Seq2Trig
{
  ADC1_Seq2Trig_SW = 0u,
  ADC1_Seq2Trig_T12ZM = 1u,
  ADC1_Seq2Trig_T12CC71ACM = 2u,
  ADC1_Seq2Trig_T12C70BCM = 3u,
  ADC1_Seq2Trig_T15PM = 4u,
  ADC1_Seq2Trig_T14CM = 5u,
  ADC1_Seq2Trig_GPT2 = 6u,
  ADC1_Seq2Trig_Seq2Complete = 7u,
  ADC1_Seq2Trig_Seq1Complete = 8u
} tADC1_Seq2Trig;





typedef enum ADC1_Seq3Trig
{
  ADC1_SQ3Trig_SW = 0u,
  ADC1_SQ3Trig_T12ZM = 1u,
  ADC1_SQ3Trig_T12CC72ACM = 2u,
  ADC1_SQ3Trig_T12C71BCM = 3u,
  ADC1_SQ3Trig_T16PM = 4u,
  ADC1_SQ3Trig_T15CM = 5u,
  ADC1_SQ3Trig_Seq3Complete = 7u,
  ADC1_SQ3Trig_Seq2Complete = 8u
} tADC1_Seq3Trig;




typedef union ADC1_SQCFGx
{
  uint32 reg;
  struct
  {
    uint32 SLOTS : 3;
    uint32 : 1;
    uint32 SQREP : 2;
    uint32 COLLCFG : 1;
    uint32 WFRCFG : 1;
    uint32 TRGSEL : 4;
    uint32 GTSEL : 2;
    uint32 TRGSW : 1;
    uint32 GTSW : 1;
  } bit;
} tADC1_SQCFGx;




typedef union ADC1_SQSLOTx
{
  uint32 reg;
  struct
  {
    uint32 CHSEL0 : 5;
    uint32 : 3;
    uint32 CHSEL1 : 5;
    uint32 : 3;
    uint32 CHSEL2 : 5;
    uint32 : 3;
    uint32 CHSEL3 : 5;
  } bit;
} tADC1_SQSLOTx;




typedef union ADC1_CHCFGx
{
  uint32 reg;
  struct
  {
    uint32 INSEL : 5;
    uint32 : 3;
    uint32 CHREP : 4;
    uint32 : 4;
    uint32 FILSEL : 3;
    uint32 CMPSEL : 3;
    uint32 CLASSEL : 2;
  } bit;
} tADC1_CHCFGx;




typedef union ADC1_CONVCFGx
{
  uint32 reg;
  struct
  {
    uint32 TCONF : 2;
    uint32 OVERS : 2;
    uint32 STC : 4;
    uint32 SESP : 1;
    uint32 : 1;
    uint32 MSBD : 1;
    uint32 PCAL : 1;
    uint32 BWD : 2;
    uint32 BWD_HI_CUR : 1;
  } bit;
} tADC1_CONVCFGx;




typedef union ADC1_CMPCFGx
{
  uint32 reg;
  struct
  {
    uint32 LOWER : 8;
    uint32 INP_SEL : 1;
    uint32 : 3;
    uint32 HYST_LO : 2;
    uint32 : 2;
    uint32 UPPER : 8;
    uint32 BLANK_TIME : 3;
    uint32 RST_BLANK_TIME: 1;
    uint32 HYST_UP : 2;
    uint32 MODE : 2;
  } bit;
} tADC1_CMPCFGx;


#pragma clang diagnostic pop






sint8 ADC1_init(void);
sint8 ADC1_getChResult(uint16 *u16p_digValue, uint8 u8_channel);
sint8 ADC1_getChResult_mV(uint16 *u16p_digValue_mV, uint8 u8_channel);
sint8 ADC1_getChFiltResult(uint16 *u16p_filtDigValue, uint8 u8_channel);
sint8 ADC1_getChFiltResult_mV(uint16 *u16p_filtDigValue_mV, uint8 u8_channel);
sint8 ADC1_getSeqResult(uint16 *u16p_DigValue, uint8 u8_seqIdx, uint8 u8_slotIdx);
sint8 ADC1_getSeqResult_mV(uint16 *u16p_digValue_mV, uint8 u8_seqIdx, uint8 u8_slotIdx);
sint8 ADC1_startSequence(uint8 u8_seqIdx);
uint8 ADC1_getEndOfConvSts(uint8 u8_seqIdx, uint8 u8_slotIdx);
static __inline void ADC1_enPower(void);
static __inline void ADC1_disPower(void);
static __inline void ADC1_setClockDiv(uint8 u8_value);
static __inline uint8 ADC1_getClockDiv(void);
static __inline void ADC1_enSuspend(void);
static __inline void ADC1_disSuspend(void);
static __inline void ADC1_setSuspendMode(uint8 u8_value);
static __inline uint8 ADC1_getSuspendMode(void);
static __inline uint8 ADC1_getSuspendSts(void);
static __inline uint8 ADC1_getReady(void);
static __inline void ADC1_setSeq0Config(tADC1_SQCFGx s_value);
static __inline void ADC1_setSeq0Repetition(uint8 u8_value);
static __inline uint8 ADC1_getSeq0Repetition(void);
static __inline void ADC1_enSeq0CollisionDetect(void);
static __inline void ADC1_disSeq0CollisionDetect(void);
static __inline void ADC1_enSeq0WaitForRead(void);
static __inline void ADC1_disSeq0WaitForRead(void);
static __inline void ADC1_setSeq0TriggerSelect(tADC1_Seq0Trig e_Seq0Trig);
static __inline uint8 ADC1_getSeq0TriggerSelect(void);
static __inline void ADC1_setSeq0GatingSelect(uint8 u8_value);
static __inline uint8 ADC1_getSeq0GatingSelect(void);
static __inline void ADC1_enSeq0TriggerGate(void);
static __inline void ADC1_disSeq0TriggerGate(void);
static __inline void ADC1_setSeq0Slot0(uint8 u8_value);
static __inline uint8 ADC1_getSeq0Slot0(void);
static __inline void ADC1_setSeq0Slot1(uint8 u8_value);
static __inline uint8 ADC1_getSeq0Slot1(void);
static __inline void ADC1_setSeq0Slot2(uint8 u8_value);
static __inline uint8 ADC1_getSeq0Slot2(void);
static __inline void ADC1_setSeq0Slot3(uint8 u8_value);
static __inline uint8 ADC1_getSeq0Slot3(void);
static __inline void ADC1_setSeq1Config(tADC1_SQCFGx s_value);
static __inline void ADC1_setSeq1Repetition(uint8 u8_value);
static __inline uint8 ADC1_getSeq1Repetition(void);
static __inline void ADC1_enSeq1CollisionDetect(void);
static __inline void ADC1_disSeq1CollisionDetect(void);
static __inline void ADC1_enSeq1WaitForRead(void);
static __inline void ADC1_disSeq1WaitForRead(void);
static __inline void ADC1_setSeq1TriggerSelect(tADC1_Seq1Trig e_Seq1Trig);
static __inline uint8 ADC1_getSeq1TriggerSelect(void);
static __inline void ADC1_setSeq1GatingSelect(uint8 u8_value);
static __inline uint8 ADC1_getSeq1GatingSelect(void);
static __inline void ADC1_enSeq1TriggerGate(void);
static __inline void ADC1_disSeq1TriggerGate(void);
static __inline void ADC1_setSeq1Slot0(uint8 u8_value);
static __inline uint8 ADC1_getSeq1Slot0(void);
static __inline void ADC1_setSeq1Slot1(uint8 u8_value);
static __inline uint8 ADC1_getSeq1Slot1(void);
static __inline void ADC1_setSeq1Slot2(uint8 u8_value);
static __inline uint8 ADC1_getSeq1Slot2(void);
static __inline void ADC1_setSeq1Slot3(uint8 u8_value);
static __inline uint8 ADC1_getSeq1Slot3(void);
static __inline void ADC1_setSeq2Config(tADC1_SQCFGx s_value);
static __inline void ADC1_setSeq2Repetition(uint8 u8_value);
static __inline uint8 ADC1_getSeq2Repetition(void);
static __inline void ADC1_enSeq2CollisionDetect(void);
static __inline void ADC1_disSeq2CollisionDetect(void);
static __inline void ADC1_enSeq2WaitForRead(void);
static __inline void ADC1_disSeq2WaitForRead(void);
static __inline void ADC1_setSeq2TriggerSelect(tADC1_Seq2Trig e_Seq2Trig);
static __inline uint8 ADC1_getSeq2TriggerSelect(void);
static __inline void ADC1_setSeq2GatingSelect(uint8 u8_value);
static __inline uint8 ADC1_getSeq2GatingSelect(void);
static __inline void ADC1_enSeq2TriggerGate(void);
static __inline void ADC1_disSeq2TriggerGate(void);
static __inline void ADC1_setSeq2Slot0(uint8 u8_value);
static __inline uint8 ADC1_getSeq2Slot0(void);
static __inline void ADC1_setSeq2Slot1(uint8 u8_value);
static __inline uint8 ADC1_getSeq2Slot1(void);
static __inline void ADC1_setSeq2Slot2(uint8 u8_value);
static __inline uint8 ADC1_getSeq2Slot2(void);
static __inline void ADC1_setSeq2Slot3(uint8 u8_value);
static __inline uint8 ADC1_getSeq2Slot3(void);
static __inline void ADC1_setSeq3Config(tADC1_SQCFGx s_value);
static __inline void ADC1_setSeq3Repetition(uint8 u8_value);
static __inline uint8 ADC1_getSeq3Repetition(void);
static __inline void ADC1_enSeq3CollisionDetect(void);
static __inline void ADC1_disSeq3CollisionDetect(void);
static __inline void ADC1_enSeq3WaitForRead(void);
static __inline void ADC1_disSeq3WaitForRead(void);
static __inline void ADC1_setSeq3TriggerSelect(tADC1_Seq3Trig e_Seq3Trig);
static __inline uint8 ADC1_getSeq3TriggerSelect(void);
static __inline void ADC1_setSeq3GatingSelect(uint8 u8_value);
static __inline uint8 ADC1_getSeq3GatingSelect(void);
static __inline void ADC1_enSeq3TriggerGate(void);
static __inline void ADC1_disSeq3TriggerGate(void);
static __inline void ADC1_setSeq3Slot0(uint8 u8_value);
static __inline uint8 ADC1_getSeq3Slot0(void);
static __inline void ADC1_setSeq3Slot1(uint8 u8_value);
static __inline uint8 ADC1_getSeq3Slot1(void);
static __inline void ADC1_setSeq3Slot2(uint8 u8_value);
static __inline uint8 ADC1_getSeq3Slot2(void);
static __inline void ADC1_setSeq3Slot3(uint8 u8_value);
static __inline uint8 ADC1_getSeq3Slot3(void);
static __inline uint8 ADC1_getSeq0WaitForRead(void);
static __inline uint8 ADC1_getSeq1WaitForRead(void);
static __inline uint8 ADC1_getSeq2WaitForRead(void);
static __inline uint8 ADC1_getSeq3WaitForRead(void);
static __inline uint8 ADC1_getSeq0CollSts(void);
static __inline uint8 ADC1_getSeq1CollSts(void);
static __inline uint8 ADC1_getSeq2CollSts(void);
static __inline uint8 ADC1_getSeq3CollSts(void);
static __inline uint8 ADC1_getSeq0IntSts(void);
static __inline uint8 ADC1_getSeq1IntSts(void);
static __inline uint8 ADC1_getSeq2IntSts(void);
static __inline uint8 ADC1_getSeq3IntSts(void);
static __inline uint8 ADC1_getCurrSeq(void);
static __inline void ADC1_clrSeq0WaitForRead(void);
static __inline void ADC1_clrSeq1WaitForRead(void);
static __inline void ADC1_clrSeq2WaitForRead(void);
static __inline void ADC1_clrSeq3WaitForRead(void);
static __inline void ADC1_clrSeq0CollSts(void);
static __inline void ADC1_clrSeq1CollSts(void);
static __inline void ADC1_clrSeq2CollSts(void);
static __inline void ADC1_clrSeq3CollSts(void);
static __inline void ADC1_clrSeq0IntSts(void);
static __inline void ADC1_clrSeq1IntSts(void);
static __inline void ADC1_clrSeq2IntSts(void);
static __inline void ADC1_clrSeq3IntSts(void);
static __inline void ADC1_setSeq0WaitForRead(void);
static __inline void ADC1_setSeq1WaitForRead(void);
static __inline void ADC1_setSeq2WaitForRead(void);
static __inline void ADC1_setSeq3WaitForRead(void);
static __inline void ADC1_setSeq0CollSts(void);
static __inline void ADC1_setSeq1CollSts(void);
static __inline void ADC1_setSeq2CollSts(void);
static __inline void ADC1_setSeq3CollSts(void);
static __inline void ADC1_setSeq0IntSts(void);
static __inline void ADC1_setSeq1IntSts(void);
static __inline void ADC1_setSeq2IntSts(void);
static __inline void ADC1_setSeq3IntSts(void);
static __inline void ADC1_setCh0Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh1Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh2Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh3Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh4Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh5Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh6Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh7Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh8Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh9Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh10Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh11Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh12Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh13Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh14Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh15Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh16Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh17Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh18Config(tADC1_CHCFGx s_value);
static __inline void ADC1_setCh19Config(tADC1_CHCFGx s_value);
static __inline uint8 ADC1_getCh0EndOfConvSts(void);
static __inline uint8 ADC1_getCh1EndOfConvSts(void);
static __inline uint8 ADC1_getCh2EndOfConvSts(void);
static __inline uint8 ADC1_getCh3EndOfConvSts(void);
static __inline uint8 ADC1_getCh4EndOfConvSts(void);
static __inline uint8 ADC1_getCh5EndOfConvSts(void);
static __inline uint8 ADC1_getCh6EndOfConvSts(void);
static __inline uint8 ADC1_getCh7EndOfConvSts(void);
static __inline uint8 ADC1_getCh8EndOfConvSts(void);
static __inline uint8 ADC1_getCh9EndOfConvSts(void);
static __inline uint8 ADC1_getCh10EndOfConvSts(void);
static __inline uint8 ADC1_getCh11EndOfConvSts(void);
static __inline uint8 ADC1_getCh12EndOfConvSts(void);
static __inline uint8 ADC1_getCh13EndOfConvSts(void);
static __inline uint8 ADC1_getCh14EndOfConvSts(void);
static __inline uint8 ADC1_getCh15EndOfConvSts(void);
static __inline uint8 ADC1_getCh16EndOfConvSts(void);
static __inline uint8 ADC1_getCh17EndOfConvSts(void);
static __inline uint8 ADC1_getCh18EndOfConvSts(void);
static __inline uint8 ADC1_getCh19EndOfConvSts(void);
static __inline uint8 ADC1_getCurrChannel(void);
static __inline void ADC1_clrCh0EndOfConvSts(void);
static __inline void ADC1_clrCh1EndOfConvSts(void);
static __inline void ADC1_clrCh2EndOfConvSts(void);
static __inline void ADC1_clrCh3EndOfConvSts(void);
static __inline void ADC1_clrCh4EndOfConvSts(void);
static __inline void ADC1_clrCh5EndOfConvSts(void);
static __inline void ADC1_clrCh6EndOfConvSts(void);
static __inline void ADC1_clrCh7EndOfConvSts(void);
static __inline void ADC1_clrCh8EndOfConvSts(void);
static __inline void ADC1_clrCh9EndOfConvSts(void);
static __inline void ADC1_clrCh10EndOfConvSts(void);
static __inline void ADC1_clrCh11EndOfConvSts(void);
static __inline void ADC1_clrCh12EndOfConvSts(void);
static __inline void ADC1_clrCh13EndOfConvSts(void);
static __inline void ADC1_clrCh14EndOfConvSts(void);
static __inline void ADC1_clrCh15EndOfConvSts(void);
static __inline void ADC1_clrCh16EndOfConvSts(void);
static __inline void ADC1_clrCh17EndOfConvSts(void);
static __inline void ADC1_clrCh18EndOfConvSts(void);
static __inline void ADC1_clrCh19EndOfConvSts(void);
static __inline void ADC1_setCh0EndOfConvSts(void);
static __inline void ADC1_setCh1EndOfConvSts(void);
static __inline void ADC1_setCh2EndOfConvSts(void);
static __inline void ADC1_setCh3EndOfConvSts(void);
static __inline void ADC1_setCh4EndOfConvSts(void);
static __inline void ADC1_setCh5EndOfConvSts(void);
static __inline void ADC1_setCh6EndOfConvSts(void);
static __inline void ADC1_setCh7EndOfConvSts(void);
static __inline void ADC1_setCh8EndOfConvSts(void);
static __inline void ADC1_setCh9EndOfConvSts(void);
static __inline void ADC1_setCh10EndOfConvSts(void);
static __inline void ADC1_setCh11EndOfConvSts(void);
static __inline void ADC1_setCh12EndOfConvSts(void);
static __inline void ADC1_setCh13EndOfConvSts(void);
static __inline void ADC1_setCh14EndOfConvSts(void);
static __inline void ADC1_setCh15EndOfConvSts(void);
static __inline void ADC1_setCh16EndOfConvSts(void);
static __inline void ADC1_setCh17EndOfConvSts(void);
static __inline void ADC1_setCh18EndOfConvSts(void);
static __inline void ADC1_setCh19EndOfConvSts(void);
static __inline void ADC1_setConvClass0Config(tADC1_CONVCFGx s_value);
static __inline void ADC1_setConvClass1Config(tADC1_CONVCFGx s_value);
static __inline void ADC1_setConvClass2Config(tADC1_CONVCFGx s_value);
static __inline void ADC1_setConvClass3Config(tADC1_CONVCFGx s_value);
static __inline void ADC1_enCalibCh0 (void);
static __inline void ADC1_disCalibCh0 (void);
static __inline void ADC1_enCalibCh1 (void);
static __inline void ADC1_disCalibCh1 (void);
static __inline void ADC1_enCalibCh2 (void);
static __inline void ADC1_disCalibCh2 (void);
static __inline void ADC1_enCalibCh3 (void);
static __inline void ADC1_disCalibCh3 (void);
static __inline void ADC1_enCalibCh4 (void);
static __inline void ADC1_disCalibCh4 (void);
static __inline void ADC1_enCalibCh5 (void);
static __inline void ADC1_disCalibCh5 (void);
static __inline void ADC1_enCalibCh6 (void);
static __inline void ADC1_disCalibCh6 (void);
static __inline void ADC1_enCalibCh7 (void);
static __inline void ADC1_disCalibCh7 (void);
static __inline void ADC1_enCalibCh8 (void);
static __inline void ADC1_disCalibCh8 (void);
static __inline void ADC1_enCalibCh9 (void);
static __inline void ADC1_disCalibCh9 (void);
static __inline void ADC1_enCalibCh10(void);
static __inline void ADC1_disCalibCh10(void);
static __inline void ADC1_enCalibCh11(void);
static __inline void ADC1_disCalibCh11(void);
static __inline void ADC1_enCalibCh12(void);
static __inline void ADC1_disCalibCh12(void);
static __inline void ADC1_enCalibCh13(void);
static __inline void ADC1_disCalibCh13(void);
static __inline void ADC1_enCalibCh14(void);
static __inline void ADC1_disCalibCh14(void);
static __inline void ADC1_enCalibCh15(void);
static __inline void ADC1_disCalibCh15(void);
static __inline void ADC1_enCalibCh16(void);
static __inline void ADC1_disCalibCh16(void);
static __inline void ADC1_enCalibCh17(void);
static __inline void ADC1_disCalibCh17(void);
static __inline void ADC1_enCalibCh18(void);
static __inline void ADC1_disCalibCh18(void);
static __inline void ADC1_enCalibCh19(void);
static __inline void ADC1_disCalibCh19(void);
static __inline void ADC1_enCalibCh20(void);
static __inline void ADC1_disCalibCh20(void);
static __inline void ADC1_enCalibCh21(void);
static __inline void ADC1_disCalibCh21(void);
static __inline void ADC1_enCalibCh22(void);
static __inline void ADC1_disCalibCh22(void);
static __inline void ADC1_enCalibCh23(void);
static __inline void ADC1_disCalibCh23(void);
static __inline void ADC1_enCalibCh24(void);
static __inline void ADC1_disCalibCh24(void);
static __inline void ADC1_enCalibCh25(void);
static __inline void ADC1_disCalibCh25(void);
static __inline void ADC1_enCalibCh26(void);
static __inline void ADC1_disCalibCh26(void);
static __inline void ADC1_enCalibProtCh0 (void);
static __inline void ADC1_disCalibProtCh0 (void);
static __inline void ADC1_enCalibProtCh1 (void);
static __inline void ADC1_disCalibProtCh1 (void);
static __inline void ADC1_enCalibProtCh2 (void);
static __inline void ADC1_disCalibProtCh2 (void);
static __inline void ADC1_enCalibProtCh3 (void);
static __inline void ADC1_disCalibProtCh3 (void);
static __inline void ADC1_enCalibProtCh4 (void);
static __inline void ADC1_disCalibProtCh4 (void);
static __inline void ADC1_enCalibProtCh5 (void);
static __inline void ADC1_disCalibProtCh5 (void);
static __inline void ADC1_enCalibProtCh6 (void);
static __inline void ADC1_disCalibProtCh6 (void);
static __inline void ADC1_enCalibProtCh7 (void);
static __inline void ADC1_disCalibProtCh7 (void);
static __inline void ADC1_enCalibProtCh8 (void);
static __inline void ADC1_disCalibProtCh8 (void);
static __inline void ADC1_enCalibProtCh9 (void);
static __inline void ADC1_disCalibProtCh9 (void);
static __inline void ADC1_enCalibProtCh10(void);
static __inline void ADC1_disCalibProtCh10(void);
static __inline void ADC1_enCalibProtCh11(void);
static __inline void ADC1_disCalibProtCh11(void);
static __inline void ADC1_enCalibProtCh12(void);
static __inline void ADC1_disCalibProtCh12(void);
static __inline void ADC1_enCalibProtCh13(void);
static __inline void ADC1_disCalibProtCh13(void);
static __inline void ADC1_enCalibProtCh14(void);
static __inline void ADC1_disCalibProtCh14(void);
static __inline void ADC1_enCalibProtCh15(void);
static __inline void ADC1_disCalibProtCh15(void);
static __inline void ADC1_enCalibProtCh16(void);
static __inline void ADC1_disCalibProtCh16(void);
static __inline void ADC1_enCalibProtCh17(void);
static __inline void ADC1_disCalibProtCh17(void);
static __inline void ADC1_enCalibProtCh18(void);
static __inline void ADC1_disCalibProtCh18(void);
static __inline void ADC1_enCalibProtCh19(void);
static __inline void ADC1_disCalibProtCh19(void);
static __inline void ADC1_enCalibProtCh20(void);
static __inline void ADC1_disCalibProtCh20(void);
static __inline void ADC1_enCalibProtCh21(void);
static __inline void ADC1_disCalibProtCh21(void);
static __inline void ADC1_enCalibProtCh22(void);
static __inline void ADC1_disCalibProtCh22(void);
static __inline void ADC1_enCalibProtCh23(void);
static __inline void ADC1_disCalibProtCh23(void);
static __inline void ADC1_enCalibProtCh24(void);
static __inline void ADC1_disCalibProtCh24(void);
static __inline void ADC1_enCalibProtCh25(void);
static __inline void ADC1_disCalibProtCh25(void);
static __inline void ADC1_enCalibProtCh26(void);
static __inline void ADC1_disCalibProtCh26(void);
static __inline void ADC1_setFilter0Coeff(uint8 u8_value);
static __inline uint8 ADC1_getFilter0Coeff(void);
static __inline void ADC1_setFilter1Coeff(uint8 u8_value);
static __inline uint8 ADC1_getFilter1Coeff(void);
static __inline void ADC1_setFilter2Coeff(uint8 u8_value);
static __inline uint8 ADC1_getFilter2Coeff(void);
static __inline void ADC1_setFilter3Coeff(uint8 u8_value);
static __inline uint8 ADC1_getFilter3Coeff(void);
static __inline uint16 ADC1_getFilter0Result(void);
static __inline uint16 ADC1_getFilter1Result(void);
static __inline uint16 ADC1_getFilter2Result(void);
static __inline uint16 ADC1_getFilter3Result(void);
static __inline uint8 ADC1_getFilter0Sts(void);
static __inline uint8 ADC1_getFilter1Sts(void);
static __inline uint8 ADC1_getFilter2Sts(void);
static __inline uint8 ADC1_getFilter3Sts(void);
static __inline void ADC1_clrFilter0Sts(void);
static __inline void ADC1_clrFilter1Sts(void);
static __inline void ADC1_clrFilter2Sts(void);
static __inline void ADC1_clrFilter3Sts(void);
static __inline void ADC1_setFilter0Sts(void);
static __inline void ADC1_setFilter1Sts(void);
static __inline void ADC1_setFilter2Sts(void);
static __inline void ADC1_setFilter3Sts(void);
static __inline uint16 ADC1_getCh0Result(void);
static __inline uint8 ADC1_getCh0ResultValidSts(void);
static __inline uint16 ADC1_getCh1Result(void);
static __inline uint8 ADC1_getCh1ResultValidSts(void);
static __inline uint16 ADC1_getCh2Result(void);
static __inline uint8 ADC1_getCh2ResultValidSts(void);
static __inline uint16 ADC1_getCh3Result(void);
static __inline uint8 ADC1_getCh3ResultValidSts(void);
static __inline uint16 ADC1_getCh4Result(void);
static __inline uint8 ADC1_getCh4ResultValidSts(void);
static __inline uint16 ADC1_getCh5Result(void);
static __inline uint8 ADC1_getCh5ResultValidSts(void);
static __inline uint16 ADC1_getCh6Result(void);
static __inline uint8 ADC1_getCh6ResultValidSts(void);
static __inline uint16 ADC1_getCh7Result(void);
static __inline uint8 ADC1_getCh7ResultValidSts(void);
static __inline uint16 ADC1_getCh8Result(void);
static __inline uint8 ADC1_getCh8ResultValidSts(void);
static __inline uint16 ADC1_getCh9Result(void);
static __inline uint8 ADC1_getCh9ResultValidSts(void);
static __inline uint16 ADC1_getCh10Result(void);
static __inline uint8 ADC1_getCh10ResultValidSts(void);
static __inline uint16 ADC1_getCh11Result(void);
static __inline uint8 ADC1_getCh11ResultValidSts(void);
static __inline uint16 ADC1_getCh12Result(void);
static __inline uint8 ADC1_getCh12ResultValidSts(void);
static __inline uint16 ADC1_getCh13Result(void);
static __inline uint8 ADC1_getCh13ResultValidSts(void);
static __inline uint16 ADC1_getCh14Result(void);
static __inline uint8 ADC1_getCh14ResultValidSts(void);
static __inline uint16 ADC1_getCh15Result(void);
static __inline uint8 ADC1_getCh15ResultValidSts(void);
static __inline uint16 ADC1_getCh16Result(void);
static __inline uint8 ADC1_getCh16ResultValidSts(void);
static __inline uint16 ADC1_getCh17Result(void);
static __inline uint8 ADC1_getCh17ResultValidSts(void);
static __inline uint16 ADC1_getCh18Result(void);
static __inline uint8 ADC1_getCh18ResultValidSts(void);
static __inline uint16 ADC1_getCh19Result(void);
static __inline uint8 ADC1_getCh19ResultValidSts(void);
static __inline void ADC1_setCmp0Config(tADC1_CMPCFGx s_value);
static __inline void ADC1_setCmp1Config(tADC1_CMPCFGx s_value);
static __inline void ADC1_setCmp2Config(tADC1_CMPCFGx s_value);
static __inline void ADC1_setCmp3Config(tADC1_CMPCFGx s_value);
static __inline uint8 ADC1_getCmp0UpIntSts(void);
static __inline uint8 ADC1_getCmp1UpIntSts(void);
static __inline uint8 ADC1_getCmp2UpIntSts(void);
static __inline uint8 ADC1_getCmp3UpIntSts(void);
static __inline uint8 ADC1_getCmp0UpThSts(void);
static __inline uint8 ADC1_getCmp1UpThSts(void);
static __inline uint8 ADC1_getCmp2UpThSts(void);
static __inline uint8 ADC1_getCmp3UpThSts(void);
static __inline uint8 ADC1_getCmp0LoIntSts(void);
static __inline uint8 ADC1_getCmp1LoIntSts(void);
static __inline uint8 ADC1_getCmp2LoIntSts(void);
static __inline uint8 ADC1_getCmp3LoIntSts(void);
static __inline uint8 ADC1_getCmp0LoThSts(void);
static __inline uint8 ADC1_getCmp1LoThSts(void);
static __inline uint8 ADC1_getCmp2LoThSts(void);
static __inline uint8 ADC1_getCmp3LoThSts(void);
static __inline void ADC1_clrCmp0UpIntSts(void);
static __inline void ADC1_clrCmp1UpIntSts(void);
static __inline void ADC1_clrCmp2UpIntSts(void);
static __inline void ADC1_clrCmp3UpIntSts(void);
static __inline void ADC1_clrCmp0UpThSts(void);
static __inline void ADC1_clrCmp1UpThSts(void);
static __inline void ADC1_clrCmp2UpThSts(void);
static __inline void ADC1_clrCmp3UpThSts(void);
static __inline void ADC1_clrCmp0LoIntSts(void);
static __inline void ADC1_clrCmp1LoIntSts(void);
static __inline void ADC1_clrCmp2LoIntSts(void);
static __inline void ADC1_clrCmp3LoIntSts(void);
static __inline void ADC1_clrCmp0LoThSts(void);
static __inline void ADC1_clrCmp1LoThSts(void);
static __inline void ADC1_clrCmp2LoThSts(void);
static __inline void ADC1_clrCmp3LoThSts(void);
static __inline void ADC1_setCmp0UpIntSts(void);
static __inline void ADC1_setCmp1UpIntSts(void);
static __inline void ADC1_setCmp2UpIntSts(void);
static __inline void ADC1_setCmp3UpIntSts(void);
static __inline void ADC1_setCmp0UpThSts(void);
static __inline void ADC1_setCmp1UpThSts(void);
static __inline void ADC1_setCmp2UpThSts(void);
static __inline void ADC1_setCmp3UpThSts(void);
static __inline void ADC1_setCmp0LoIntSts(void);
static __inline void ADC1_setCmp1LoIntSts(void);
static __inline void ADC1_setCmp2LoIntSts(void);
static __inline void ADC1_setCmp3LoIntSts(void);
static __inline void ADC1_setCmp0LoThSts(void);
static __inline void ADC1_setCmp1LoThSts(void);
static __inline void ADC1_setCmp2LoThSts(void);
static __inline void ADC1_setCmp3LoThSts(void);
static __inline void ADC1_enCmp0UpInt(void);
static __inline void ADC1_disCmp0UpInt(void);
static __inline void ADC1_enCmp1UpInt(void);
static __inline void ADC1_disCmp1UpInt(void);
static __inline void ADC1_enCmp2UpInt(void);
static __inline void ADC1_disCmp2UpInt(void);
static __inline void ADC1_enCmp3UpInt(void);
static __inline void ADC1_disCmp3UpInt(void);
static __inline void ADC1_enCmp0LoInt(void);
static __inline void ADC1_disCmp0LoInt(void);
static __inline void ADC1_enCmp1LoInt(void);
static __inline void ADC1_disCmp1LoInt(void);
static __inline void ADC1_enCmp2LoInt(void);
static __inline void ADC1_disCmp2LoInt(void);
static __inline void ADC1_enCmp3LoInt(void);
static __inline void ADC1_disCmp3LoInt(void);
static __inline void ADC1_enSeq0Int(void);
static __inline void ADC1_disSeq0Int(void);
static __inline void ADC1_enSeq1Int(void);
static __inline void ADC1_disSeq1Int(void);
static __inline void ADC1_enSeq2Int(void);
static __inline void ADC1_disSeq2Int(void);
static __inline void ADC1_enSeq3Int(void);
static __inline void ADC1_disSeq3Int(void);
static __inline void ADC1_enCh0Int(void);
static __inline void ADC1_disCh0Int(void);
static __inline void ADC1_enCh1Int(void);
static __inline void ADC1_disCh1Int(void);
static __inline void ADC1_enCh2Int(void);
static __inline void ADC1_disCh2Int(void);
static __inline void ADC1_enCh3Int(void);
static __inline void ADC1_disCh3Int(void);
static __inline void ADC1_enCh4Int(void);
static __inline void ADC1_disCh4Int(void);
static __inline void ADC1_enCh5Int(void);
static __inline void ADC1_disCh5Int(void);
static __inline void ADC1_enCh6Int(void);
static __inline void ADC1_disCh6Int(void);
static __inline void ADC1_enCh7Int(void);
static __inline void ADC1_disCh7Int(void);
static __inline void ADC1_enCh8Int(void);
static __inline void ADC1_disCh8Int(void);
static __inline void ADC1_enCh9Int(void);
static __inline void ADC1_disCh9Int(void);
static __inline void ADC1_enCh10Int(void);
static __inline void ADC1_disCh10Int(void);
static __inline void ADC1_enCh11Int(void);
static __inline void ADC1_disCh11Int(void);
static __inline void ADC1_enCh12Int(void);
static __inline void ADC1_disCh12Int(void);
static __inline void ADC1_enCh13Int(void);
static __inline void ADC1_disCh13Int(void);
static __inline void ADC1_enCh14Int(void);
static __inline void ADC1_disCh14Int(void);
static __inline void ADC1_enCh15Int(void);
static __inline void ADC1_disCh15Int(void);
static __inline void ADC1_enCh16Int(void);
static __inline void ADC1_disCh16Int(void);
static __inline void ADC1_enCh17Int(void);
static __inline void ADC1_disCh17Int(void);
static __inline void ADC1_enCh18Int(void);
static __inline void ADC1_disCh18Int(void);
static __inline void ADC1_enCh19Int(void);
static __inline void ADC1_disCh19Int(void);
static __inline void ADC1_enSeq0WaitForReadInt(void);
static __inline void ADC1_disSeq0WaitForReadInt(void);
static __inline void ADC1_enSeq1WaitForReadInt(void);
static __inline void ADC1_disSeq1WaitForReadInt(void);
static __inline void ADC1_enSeq2WaitForReadInt(void);
static __inline void ADC1_disSeq2WaitForReadInt(void);
static __inline void ADC1_enSeq3WaitForReadInt(void);
static __inline void ADC1_disSeq3WaitForReadInt(void);
static __inline void ADC1_enSeq0CollInt(void);
static __inline void ADC1_disSeq0CollInt(void);
static __inline void ADC1_enSeq1CollInt(void);
static __inline void ADC1_disSeq1CollInt(void);
static __inline void ADC1_enSeq2CollInt(void);
static __inline void ADC1_disSeq2CollInt(void);
static __inline void ADC1_enSeq3CollInt(void);
static __inline void ADC1_disSeq3CollInt(void);
static __inline uint8 ADC1_getCh0IntNodePtr(void);
static __inline uint8 ADC1_getCh1IntNodePtr(void);
static __inline uint8 ADC1_getCh2IntNodePtr(void);
static __inline uint8 ADC1_getCh3IntNodePtr(void);
static __inline uint8 ADC1_getCh4IntNodePtr(void);
static __inline uint8 ADC1_getCh5IntNodePtr(void);
static __inline uint8 ADC1_getCh6IntNodePtr(void);
static __inline uint8 ADC1_getCh7IntNodePtr(void);
static __inline uint8 ADC1_getCh8IntNodePtr(void);
static __inline uint8 ADC1_getCh9IntNodePtr(void);
static __inline uint8 ADC1_getCh10IntNodePtr(void);
static __inline uint8 ADC1_getCh11IntNodePtr(void);
static __inline uint8 ADC1_getCh12IntNodePtr(void);
static __inline uint8 ADC1_getCh13IntNodePtr(void);
static __inline uint8 ADC1_getCh14IntNodePtr(void);
static __inline uint8 ADC1_getCh15IntNodePtr(void);
static __inline uint8 ADC1_getCh16IntNodePtr(void);
static __inline uint8 ADC1_getCh17IntNodePtr(void);
static __inline uint8 ADC1_getCh18IntNodePtr(void);
static __inline uint8 ADC1_getCh19IntNodePtr(void);
static __inline uint8 ADC1_getCmp0LoIntNodePtr(void);
static __inline uint8 ADC1_getCmp1LoIntNodePtr(void);
static __inline uint8 ADC1_getCmp2LoIntNodePtr(void);
static __inline uint8 ADC1_getCmp3LoIntNodePtr(void);
static __inline uint8 ADC1_getCmp0UpIntNodePtr(void);
static __inline uint8 ADC1_getCmp1UpIntNodePtr(void);
static __inline uint8 ADC1_getCmp2UpIntNodePtr(void);
static __inline uint8 ADC1_getCmp3UpIntNodePtr(void);
static __inline uint8 ADC1_getSeq0IntNodePtr(void);
static __inline uint8 ADC1_getSeq1IntNodePtr(void);
static __inline uint8 ADC1_getSeq2IntNodePtr(void);
static __inline uint8 ADC1_getSeq3IntNodePtr(void);
static __inline uint8 ADC1_getSeq0CollIntNodePtr(void);
static __inline uint8 ADC1_getSeq1CollIntNodePtr(void);
static __inline uint8 ADC1_getSeq2CollIntNodePtr(void);
static __inline uint8 ADC1_getSeq3CollIntNodePtr(void);
static __inline uint8 ADC1_getSeq0WaitForReadIntNodePtr(void);
static __inline uint8 ADC1_getSeq1WaitForReadIntNodePtr(void);
static __inline uint8 ADC1_getSeq2WaitForReadIntNodePtr(void);
static __inline uint8 ADC1_getSeq3WaitForReadIntNodePtr(void);
static __inline void ADC1_setSeqHwShadowTrans(uint8 u8_value);
static __inline uint8 ADC1_getSeqHwShadowTrans(void);
static __inline void ADC1_setTriggHwShadowTrans(uint8 u8_value);
static __inline uint8 ADC1_getTriggHwShadowTrans(void);
static __inline void ADC1_setGateHwShadowTrans(uint8 u8_value);
static __inline uint8 ADC1_getGateHwShadowTrans(void);
static __inline void ADC1_enSeqHwShadowTrans(void);
static __inline void ADC1_disSeqHwShadowTrans(void);
static __inline void ADC1_enTriggHwShadowTrans(void);
static __inline void ADC1_disTriggHwShadowTrans(void);
static __inline void ADC1_enGateHwShadowTrans(void);
static __inline void ADC1_disGateHwShadowTrans(void);
static __inline void ADC1_setSeqSwShadowTrans(void);
static __inline uint8 ADC1_getSeqSwShadowTrans(void);
static __inline void ADC1_setTriggSwShadowTrans(void);
static __inline uint8 ADC1_getTriggSwShadowTrans(void);
static __inline void ADC1_setGateSwShadowTrans(void);
static __inline uint8 ADC1_getGateSwShadowTrans(void);
static __inline void ADC1_enSeqSwShadowTrans(void);
static __inline void ADC1_disSeqSwShadowTrans(void);
static __inline void ADC1_enTriggSwShadowTrans(void);
static __inline void ADC1_disTriggSwShadowTrans(void);
static __inline void ADC1_enGateSwShadowTrans(void);
static __inline void ADC1_disGateSwShadowTrans(void);
static __inline void ADC1_setCalibOffsAnaIn1(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn1(void);
static __inline void ADC1_setCalibGainAnaIn1(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn1(void);
static __inline void ADC1_setCalibOffsAnaIn3(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn3(void);
static __inline void ADC1_setCalibGainAnaIn3(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn3(void);
static __inline void ADC1_setCalibOffsAnaIn5(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn5(void);
static __inline void ADC1_setCalibGainAnaIn5(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn5(void);
static __inline void ADC1_setCalibOffsAnaIn7(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn7(void);
static __inline void ADC1_setCalibGainAnaIn7(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn7(void);
static __inline void ADC1_setCalibOffsAnaIn9(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn9(void);
static __inline void ADC1_setCalibGainAnaIn9(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn9(void);
static __inline void ADC1_setCalibOffsAnaIn11(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn11(void);
static __inline void ADC1_setCalibGainAnaIn11(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn11(void);
static __inline void ADC1_setCalibOffsAnaIn13(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn13(void);
static __inline void ADC1_setCalibGainAnaIn13(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn13(void);
static __inline void ADC1_setCalibOffsAnaIn15(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn15(void);
static __inline void ADC1_setCalibGainAnaIn15(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn15(void);
static __inline void ADC1_setCalibOffsAnaIn16(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn16(void);
static __inline void ADC1_setCalibGainAnaIn16(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn16(void);
static __inline void ADC1_setCalibOffsAnaIn17(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn17(void);
static __inline void ADC1_setCalibGainAnaIn17(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn17(void);
static __inline void ADC1_setCalibOffsAnaIn18(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn18(void);
static __inline void ADC1_setCalibGainAnaIn18(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn18(void);
static __inline void ADC1_setCalibOffsAnaIn19(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn19(void);
static __inline void ADC1_setCalibGainAnaIn19(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn19(void);
static __inline void ADC1_setCalibOffsAnaIn20(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn20(void);
static __inline void ADC1_setCalibGainAnaIn20(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn20(void);
static __inline void ADC1_setCalibOffsAnaIn21(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn21(void);
static __inline void ADC1_setCalibGainAnaIn21(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn21(void);
static __inline void ADC1_setCalibOffsAnaIn22(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn22(void);
static __inline void ADC1_setCalibGainAnaIn22(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn22(void);
static __inline void ADC1_setCalibOffsAnaIn23(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn23(void);
static __inline void ADC1_setCalibGainAnaIn23(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn23(void);
static __inline void ADC1_setCalibOffsAnaIn24(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn24(void);
static __inline void ADC1_setCalibGainAnaIn24(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn24(void);
static __inline void ADC1_setCalibOffsAnaIn25(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn25(void);
static __inline void ADC1_setCalibGainAnaIn25(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn25(void);
static __inline void ADC1_setCalibOffsAnaIn26(uint8 u8_value);
static __inline uint8 ADC1_getCalibOffsAnaIn26(void);
static __inline void ADC1_setCalibGainAnaIn26(uint16 u16_value);
static __inline uint16 ADC1_getCalibGainAnaIn26(void);
static __inline void ARVG_enVAREF(void);
static __inline void ARVG_disVAREF(void);
static __inline void ARVG_enVAREFOvercurrentInt(void);
static __inline void ARVG_disVAREFOvercurrentInt(void);
static __inline uint8 ARVG_getVAREFOvercurrentIntSts(void);
static __inline uint8 ARVG_getVAREFOvercurrentSts(void);
static __inline void ARVG_clrVAREFOvercurrentIntSts(void);
static __inline void ARVG_clrVAREFOvercurrentSts(void);
# 1094 "./RTE/Device/TLE9893_2QKW62S/adc1.h"
void ADC1_setCh0IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh1IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh2IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh3IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh4IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh5IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh6IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh7IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh8IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh9IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh10IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh11IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh12IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh13IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh14IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh15IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh16IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh17IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh18IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCh19IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp0LoIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp1LoIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp2LoIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp3LoIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp0UpIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp1UpIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp2UpIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setCmp3UpIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq0IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq1IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq2IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq3IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq0CollIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq1CollIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq2CollIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq3CollIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq0WaitForReadIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq1WaitForReadIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq2WaitForReadIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void ADC1_setSeq3WaitForReadIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));
# 1298 "./RTE/Device/TLE9893_2QKW62S/adc1.h"
static __inline void ADC1_enPower(void)
{
  ((ADC1_Type*) 0x40000000UL)->GLOBCONF.bit.EN = 1u;
}



static __inline void ADC1_disPower(void)
{
  ((ADC1_Type*) 0x40000000UL)->GLOBCONF.bit.EN = 0u;
}





static __inline void ADC1_setClockDiv(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CLKCON.bit.CLKDIV = u8_value;
}





static __inline uint8 ADC1_getClockDiv(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CLKCON.bit.CLKDIV;
}



static __inline void ADC1_enSuspend(void)
{
  ((ADC1_Type*) 0x40000000UL)->SUSCTR.bit.SUSEN = 1u;
}



static __inline void ADC1_disSuspend(void)
{
  ((ADC1_Type*) 0x40000000UL)->SUSCTR.bit.SUSEN = 0u;
}





static __inline void ADC1_setSuspendMode(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SUSCTR.bit.SUSMOD = u8_value;
}





static __inline uint8 ADC1_getSuspendMode(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SUSCTR.bit.SUSMOD;
}





static __inline uint8 ADC1_getSuspendSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SUSSTAT.bit.STAT;
}





static __inline uint8 ADC1_getReady(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SUSSTAT.bit.READY;
}





static __inline void ADC1_setSeq0Config(tADC1_SQCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setSeq0Repetition(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.SQREP = u8_value;
}





static __inline uint8 ADC1_getSeq0Repetition(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.SQREP;
}



static __inline void ADC1_enSeq0CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.COLLCFG = 1u;
}



static __inline void ADC1_disSeq0CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.COLLCFG = 0u;
}



static __inline void ADC1_enSeq0WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.WFRCFG = 1u;
}



static __inline void ADC1_disSeq0WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.WFRCFG = 0u;
}





static __inline void ADC1_setSeq0TriggerSelect(tADC1_Seq0Trig e_Seq0Trig)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.TRGSEL = (uint8)e_Seq0Trig;
}





static __inline uint8 ADC1_getSeq0TriggerSelect(void)
{
  return ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.TRGSEL;
}





static __inline void ADC1_setSeq0GatingSelect(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.GTSEL = u8_value;
}





static __inline uint8 ADC1_getSeq0GatingSelect(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.GTSEL;
}



static __inline void ADC1_enSeq0TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.GTSW = 1u;
}



static __inline void ADC1_disSeq0TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG0.bit.GTSW = 0u;
}





static __inline void ADC1_setSeq0Slot0(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL0 = u8_value;
}





static __inline uint8 ADC1_getSeq0Slot0(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL0;
}





static __inline void ADC1_setSeq0Slot1(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL1 = u8_value;
}





static __inline uint8 ADC1_getSeq0Slot1(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL1;
}





static __inline void ADC1_setSeq0Slot2(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL2 = u8_value;
}





static __inline uint8 ADC1_getSeq0Slot2(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL2;
}





static __inline void ADC1_setSeq0Slot3(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL3 = u8_value;
}





static __inline uint8 ADC1_getSeq0Slot3(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT0.bit.CHSEL3;
}





static __inline void ADC1_setSeq1Config(tADC1_SQCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setSeq1Repetition(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.SQREP = u8_value;
}





static __inline uint8 ADC1_getSeq1Repetition(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.SQREP;
}



static __inline void ADC1_enSeq1CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.COLLCFG = 1u;
}



static __inline void ADC1_disSeq1CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.COLLCFG = 0u;
}



static __inline void ADC1_enSeq1WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.WFRCFG = 1u;
}



static __inline void ADC1_disSeq1WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.WFRCFG = 0u;
}





static __inline void ADC1_setSeq1TriggerSelect(tADC1_Seq1Trig e_Seq1Trig)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.TRGSEL = (uint8)e_Seq1Trig;
}





static __inline uint8 ADC1_getSeq1TriggerSelect(void)
{
  return ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.TRGSEL;
}





static __inline void ADC1_setSeq1GatingSelect(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.GTSEL = u8_value;
}





static __inline uint8 ADC1_getSeq1GatingSelect(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.GTSEL;
}



static __inline void ADC1_enSeq1TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.GTSW = 1u;
}



static __inline void ADC1_disSeq1TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG1.bit.GTSW = 0u;
}





static __inline void ADC1_setSeq1Slot0(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL0 = u8_value;
}





static __inline uint8 ADC1_getSeq1Slot0(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL0;
}





static __inline void ADC1_setSeq1Slot1(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL1 = u8_value;
}





static __inline uint8 ADC1_getSeq1Slot1(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL1;
}





static __inline void ADC1_setSeq1Slot2(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL2 = u8_value;
}





static __inline uint8 ADC1_getSeq1Slot2(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL2;
}





static __inline void ADC1_setSeq1Slot3(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL3 = u8_value;
}





static __inline uint8 ADC1_getSeq1Slot3(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT1.bit.CHSEL3;
}





static __inline void ADC1_setSeq2Config(tADC1_SQCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setSeq2Repetition(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.SQREP = u8_value;
}





static __inline uint8 ADC1_getSeq2Repetition(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.SQREP;
}



static __inline void ADC1_enSeq2CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.COLLCFG = 1u;
}



static __inline void ADC1_disSeq2CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.COLLCFG = 0u;
}



static __inline void ADC1_enSeq2WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.WFRCFG = 1u;
}



static __inline void ADC1_disSeq2WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.WFRCFG = 0u;
}





static __inline void ADC1_setSeq2TriggerSelect(tADC1_Seq2Trig e_Seq2Trig)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.TRGSEL = (uint8)e_Seq2Trig;
}





static __inline uint8 ADC1_getSeq2TriggerSelect(void)
{
  return ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.TRGSEL;
}





static __inline void ADC1_setSeq2GatingSelect(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.GTSEL = u8_value;
}





static __inline uint8 ADC1_getSeq2GatingSelect(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.GTSEL;
}



static __inline void ADC1_enSeq2TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.GTSW = 1u;
}



static __inline void ADC1_disSeq2TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG2.bit.GTSW = 0u;
}





static __inline void ADC1_setSeq2Slot0(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL0 = u8_value;
}





static __inline uint8 ADC1_getSeq2Slot0(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL0;
}





static __inline void ADC1_setSeq2Slot1(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL1 = u8_value;
}





static __inline uint8 ADC1_getSeq2Slot1(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL1;
}





static __inline void ADC1_setSeq2Slot2(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL2 = u8_value;
}





static __inline uint8 ADC1_getSeq2Slot2(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL2;
}





static __inline void ADC1_setSeq2Slot3(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL3 = u8_value;
}





static __inline uint8 ADC1_getSeq2Slot3(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT2.bit.CHSEL3;
}





static __inline void ADC1_setSeq3Config(tADC1_SQCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setSeq3Repetition(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.SQREP = u8_value;
}





static __inline uint8 ADC1_getSeq3Repetition(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.SQREP;
}



static __inline void ADC1_enSeq3CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.COLLCFG = 1u;
}



static __inline void ADC1_disSeq3CollisionDetect(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.COLLCFG = 0u;
}



static __inline void ADC1_enSeq3WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.WFRCFG = 1u;
}



static __inline void ADC1_disSeq3WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.WFRCFG = 0u;
}





static __inline void ADC1_setSeq3TriggerSelect(tADC1_Seq3Trig e_Seq3Trig)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.TRGSEL = (uint8)e_Seq3Trig;
}





static __inline uint8 ADC1_getSeq3TriggerSelect(void)
{
  return ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.TRGSEL;
}





static __inline void ADC1_setSeq3GatingSelect(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.GTSEL = u8_value;
}





static __inline uint8 ADC1_getSeq3GatingSelect(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.GTSEL;
}



static __inline void ADC1_enSeq3TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.GTSW = 1u;
}



static __inline void ADC1_disSeq3TriggerGate(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQCFG3.bit.GTSW = 0u;
}





static __inline void ADC1_setSeq3Slot0(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL0 = u8_value;
}





static __inline uint8 ADC1_getSeq3Slot0(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL0;
}





static __inline void ADC1_setSeq3Slot1(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL1 = u8_value;
}





static __inline uint8 ADC1_getSeq3Slot1(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL1;
}





static __inline void ADC1_setSeq3Slot2(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL2 = u8_value;
}





static __inline uint8 ADC1_getSeq3Slot2(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL2;
}





static __inline void ADC1_setSeq3Slot3(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL3 = u8_value;
}





static __inline uint8 ADC1_getSeq3Slot3(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSLOT3.bit.CHSEL3;
}





static __inline uint8 ADC1_getSeq0WaitForRead(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.WFR0;
}





static __inline uint8 ADC1_getSeq1WaitForRead(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.WFR1;
}





static __inline uint8 ADC1_getSeq2WaitForRead(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.WFR2;
}





static __inline uint8 ADC1_getSeq3WaitForRead(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.WFR3;
}





static __inline uint8 ADC1_getSeq0CollSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.COLL0;
}





static __inline uint8 ADC1_getSeq1CollSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.COLL1;
}





static __inline uint8 ADC1_getSeq2CollSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.COLL2;
}





static __inline uint8 ADC1_getSeq3CollSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.COLL3;
}





static __inline uint8 ADC1_getSeq0IntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.SQ0;
}





static __inline uint8 ADC1_getSeq1IntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.SQ1;
}





static __inline uint8 ADC1_getSeq2IntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.SQ2;
}





static __inline uint8 ADC1_getSeq3IntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.SQ3;
}





static __inline uint8 ADC1_getCurrSeq(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SQSTAT.bit.SQNUM;
}



static __inline void ADC1_clrSeq0WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.WFR0CLR = 1u;
}



static __inline void ADC1_clrSeq1WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.WFR1CLR = 1u;
}



static __inline void ADC1_clrSeq2WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.WFR2CLR = 1u;
}



static __inline void ADC1_clrSeq3WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.WFR3CLR = 1u;
}



static __inline void ADC1_clrSeq0CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.COLL0CLR = 1u;
}



static __inline void ADC1_clrSeq1CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.COLL1CLR = 1u;
}



static __inline void ADC1_clrSeq2CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.COLL2CLR = 1u;
}



static __inline void ADC1_clrSeq3CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.COLL3CLR = 1u;
}



static __inline void ADC1_clrSeq0IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.SQ0CLR = 1u;
}



static __inline void ADC1_clrSeq1IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.SQ1CLR = 1u;
}



static __inline void ADC1_clrSeq2IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.SQ2CLR = 1u;
}



static __inline void ADC1_clrSeq3IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATCLR.bit.SQ3CLR = 1u;
}



static __inline void ADC1_setSeq0WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.WFR0SET = 1u;
}



static __inline void ADC1_setSeq1WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.WFR1SET = 1u;
}



static __inline void ADC1_setSeq2WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.WFR2SET = 1u;
}



static __inline void ADC1_setSeq3WaitForRead(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.WFR3SET = 1u;
}



static __inline void ADC1_setSeq0CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.COLL0SET = 1u;
}



static __inline void ADC1_setSeq1CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.COLL1SET = 1u;
}



static __inline void ADC1_setSeq2CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.COLL2SET = 1u;
}



static __inline void ADC1_setSeq3CollSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.COLL3SET = 1u;
}



static __inline void ADC1_setSeq0IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.SQ0SET = 1u;
}



static __inline void ADC1_setSeq1IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.SQ1SET = 1u;
}



static __inline void ADC1_setSeq2IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.SQ2SET = 1u;
}



static __inline void ADC1_setSeq3IntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->SQSTATSET.bit.SQ3SET = 1u;
}





static __inline void ADC1_setCh0Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG0.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh1Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG1.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh2Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG2.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh3Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG3.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh4Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG4.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh5Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG5.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh6Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG6.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh7Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG7.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh8Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG8.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh9Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG9.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh10Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG10.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh11Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG11.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh12Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG12.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh13Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG13.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh14Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG14.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh15Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG15.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh16Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG16.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh17Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG17.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh18Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG18.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCh19Config(tADC1_CHCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CHCFG19.reg = (uint32)s_value.reg;
}





static __inline uint8 ADC1_getCh0EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH0;
}





static __inline uint8 ADC1_getCh1EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH1;
}





static __inline uint8 ADC1_getCh2EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH2;
}





static __inline uint8 ADC1_getCh3EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH3;
}





static __inline uint8 ADC1_getCh4EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH4;
}





static __inline uint8 ADC1_getCh5EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH5;
}





static __inline uint8 ADC1_getCh6EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH6;
}





static __inline uint8 ADC1_getCh7EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH7;
}





static __inline uint8 ADC1_getCh8EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH8;
}





static __inline uint8 ADC1_getCh9EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH9;
}





static __inline uint8 ADC1_getCh10EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH10;
}





static __inline uint8 ADC1_getCh11EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH11;
}





static __inline uint8 ADC1_getCh12EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH12;
}





static __inline uint8 ADC1_getCh13EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH13;
}





static __inline uint8 ADC1_getCh14EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH14;
}





static __inline uint8 ADC1_getCh15EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH15;
}





static __inline uint8 ADC1_getCh16EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH16;
}





static __inline uint8 ADC1_getCh17EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH17;
}





static __inline uint8 ADC1_getCh18EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH18;
}





static __inline uint8 ADC1_getCh19EndOfConvSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CH19;
}





static __inline uint8 ADC1_getCurrChannel(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CHSTAT.bit.CHNUM;
}



static __inline void ADC1_clrCh0EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH0CLR = 1u;
}



static __inline void ADC1_clrCh1EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH1CLR = 1u;
}



static __inline void ADC1_clrCh2EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH2CLR = 1u;
}



static __inline void ADC1_clrCh3EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH3CLR = 1u;
}



static __inline void ADC1_clrCh4EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH4CLR = 1u;
}



static __inline void ADC1_clrCh5EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH5CLR = 1u;
}



static __inline void ADC1_clrCh6EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH6CLR = 1u;
}



static __inline void ADC1_clrCh7EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH7CLR = 1u;
}



static __inline void ADC1_clrCh8EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH8CLR = 1u;
}



static __inline void ADC1_clrCh9EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH9CLR = 1u;
}



static __inline void ADC1_clrCh10EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH10CLR = 1u;
}



static __inline void ADC1_clrCh11EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH11CLR = 1u;
}



static __inline void ADC1_clrCh12EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH12CLR = 1u;
}



static __inline void ADC1_clrCh13EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH13CLR = 1u;
}



static __inline void ADC1_clrCh14EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH14CLR = 1u;
}



static __inline void ADC1_clrCh15EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH15CLR = 1u;
}



static __inline void ADC1_clrCh16EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH16CLR = 1u;
}



static __inline void ADC1_clrCh17EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH17CLR = 1u;
}



static __inline void ADC1_clrCh18EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH18CLR = 1u;
}



static __inline void ADC1_clrCh19EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATCLR.bit.CH19CLR = 1u;
}



static __inline void ADC1_setCh0EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH0SET = 1u;
}



static __inline void ADC1_setCh1EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH1SET = 1u;
}



static __inline void ADC1_setCh2EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH2SET = 1u;
}



static __inline void ADC1_setCh3EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH3SET = 1u;
}



static __inline void ADC1_setCh4EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH4SET = 1u;
}



static __inline void ADC1_setCh5EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH5SET = 1u;
}



static __inline void ADC1_setCh6EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH6SET = 1u;
}



static __inline void ADC1_setCh7EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH7SET = 1u;
}



static __inline void ADC1_setCh8EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH8SET = 1u;
}



static __inline void ADC1_setCh9EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH9SET = 1u;
}



static __inline void ADC1_setCh10EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH10SET = 1u;
}



static __inline void ADC1_setCh11EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH11SET = 1u;
}



static __inline void ADC1_setCh12EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH12SET = 1u;
}



static __inline void ADC1_setCh13EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH13SET = 1u;
}



static __inline void ADC1_setCh14EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH14SET = 1u;
}



static __inline void ADC1_setCh15EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH15SET = 1u;
}



static __inline void ADC1_setCh16EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH16SET = 1u;
}



static __inline void ADC1_setCh17EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH17SET = 1u;
}



static __inline void ADC1_setCh18EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH18SET = 1u;
}



static __inline void ADC1_setCh19EndOfConvSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CHSTATSET.bit.CH19SET = 1u;
}





static __inline void ADC1_setConvClass0Config(tADC1_CONVCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CONVCFG0.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setConvClass1Config(tADC1_CONVCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CONVCFG1.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setConvClass2Config(tADC1_CONVCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CONVCFG2.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setConvClass3Config(tADC1_CONVCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CONVCFG3.reg = (uint32)s_value.reg;
}



static __inline void ADC1_enCalibCh0 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN0 = 1u;
}



static __inline void ADC1_disCalibCh0 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN0 = 0u;
}



static __inline void ADC1_enCalibCh1 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN1 = 1u;
}



static __inline void ADC1_disCalibCh1 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN1 = 0u;
}



static __inline void ADC1_enCalibCh2 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN2 = 1u;
}



static __inline void ADC1_disCalibCh2 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN2 = 0u;
}



static __inline void ADC1_enCalibCh3 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN3 = 1u;
}



static __inline void ADC1_disCalibCh3 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN3 = 0u;
}



static __inline void ADC1_enCalibCh4 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN4 = 1u;
}



static __inline void ADC1_disCalibCh4 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN4 = 0u;
}



static __inline void ADC1_enCalibCh5 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN5 = 1u;
}



static __inline void ADC1_disCalibCh5 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN5 = 0u;
}



static __inline void ADC1_enCalibCh6 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN6 = 1u;
}



static __inline void ADC1_disCalibCh6 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN6 = 0u;
}



static __inline void ADC1_enCalibCh7 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN7 = 1u;
}



static __inline void ADC1_disCalibCh7 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN7 = 0u;
}



static __inline void ADC1_enCalibCh8 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN8 = 1u;
}



static __inline void ADC1_disCalibCh8 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN8 = 0u;
}



static __inline void ADC1_enCalibCh9 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN9 = 1u;
}



static __inline void ADC1_disCalibCh9 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN9 = 0u;
}



static __inline void ADC1_enCalibCh10(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN10 = 1u;
}



static __inline void ADC1_disCalibCh10(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN10 = 0u;
}



static __inline void ADC1_enCalibCh11(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN11 = 1u;
}



static __inline void ADC1_disCalibCh11(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN11 = 0u;
}



static __inline void ADC1_enCalibCh12(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN12 = 1u;
}



static __inline void ADC1_disCalibCh12(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN12 = 0u;
}



static __inline void ADC1_enCalibCh13(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN13 = 1u;
}



static __inline void ADC1_disCalibCh13(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN13 = 0u;
}



static __inline void ADC1_enCalibCh14(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN14 = 1u;
}



static __inline void ADC1_disCalibCh14(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN14 = 0u;
}



static __inline void ADC1_enCalibCh15(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN15 = 1u;
}



static __inline void ADC1_disCalibCh15(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN15 = 0u;
}



static __inline void ADC1_enCalibCh16(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN16 = 1u;
}



static __inline void ADC1_disCalibCh16(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN16 = 0u;
}



static __inline void ADC1_enCalibCh17(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN17 = 1u;
}



static __inline void ADC1_disCalibCh17(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN17 = 0u;
}



static __inline void ADC1_enCalibCh18(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN18 = 1u;
}



static __inline void ADC1_disCalibCh18(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN18 = 0u;
}



static __inline void ADC1_enCalibCh19(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN19 = 1u;
}



static __inline void ADC1_disCalibCh19(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN19 = 0u;
}



static __inline void ADC1_enCalibCh20(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN20 = 1u;
}



static __inline void ADC1_disCalibCh20(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN20 = 0u;
}



static __inline void ADC1_enCalibCh21(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN21 = 1u;
}



static __inline void ADC1_disCalibCh21(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN21 = 0u;
}



static __inline void ADC1_enCalibCh22(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN22 = 1u;
}



static __inline void ADC1_disCalibCh22(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN22 = 0u;
}



static __inline void ADC1_enCalibCh23(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN23 = 1u;
}



static __inline void ADC1_disCalibCh23(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN23 = 0u;
}



static __inline void ADC1_enCalibCh24(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN24 = 1u;
}



static __inline void ADC1_disCalibCh24(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN24 = 0u;
}



static __inline void ADC1_enCalibCh25(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN25 = 1u;
}



static __inline void ADC1_disCalibCh25(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN25 = 0u;
}



static __inline void ADC1_enCalibCh26(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN26 = 1u;
}



static __inline void ADC1_disCalibCh26(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALEN.bit.CALEN26 = 0u;
}



static __inline void ADC1_enCalibProtCh0 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN0 = 1u;
}



static __inline void ADC1_disCalibProtCh0 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN0 = 0u;
}



static __inline void ADC1_enCalibProtCh1 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN1 = 1u;
}



static __inline void ADC1_disCalibProtCh1 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN1 = 0u;
}



static __inline void ADC1_enCalibProtCh2 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN2 = 1u;
}



static __inline void ADC1_disCalibProtCh2 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN2 = 0u;
}



static __inline void ADC1_enCalibProtCh3 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN3 = 1u;
}



static __inline void ADC1_disCalibProtCh3 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN3 = 0u;
}



static __inline void ADC1_enCalibProtCh4 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN4 = 1u;
}



static __inline void ADC1_disCalibProtCh4 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN4 = 0u;
}



static __inline void ADC1_enCalibProtCh5 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN5 = 1u;
}



static __inline void ADC1_disCalibProtCh5 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN5 = 0u;
}



static __inline void ADC1_enCalibProtCh6 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN6 = 1u;
}



static __inline void ADC1_disCalibProtCh6 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN6 = 0u;
}



static __inline void ADC1_enCalibProtCh7 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN7 = 1u;
}



static __inline void ADC1_disCalibProtCh7 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN7 = 0u;
}



static __inline void ADC1_enCalibProtCh8 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN8 = 1u;
}



static __inline void ADC1_disCalibProtCh8 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN8 = 0u;
}



static __inline void ADC1_enCalibProtCh9 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN9 = 1u;
}



static __inline void ADC1_disCalibProtCh9 (void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN9 = 0u;
}



static __inline void ADC1_enCalibProtCh10(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN10 = 1u;
}



static __inline void ADC1_disCalibProtCh10(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN10 = 0u;
}



static __inline void ADC1_enCalibProtCh11(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN11 = 1u;
}



static __inline void ADC1_disCalibProtCh11(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN11 = 0u;
}



static __inline void ADC1_enCalibProtCh12(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN12 = 1u;
}



static __inline void ADC1_disCalibProtCh12(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN12 = 0u;
}



static __inline void ADC1_enCalibProtCh13(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN13 = 1u;
}



static __inline void ADC1_disCalibProtCh13(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN13 = 0u;
}



static __inline void ADC1_enCalibProtCh14(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN14 = 1u;
}



static __inline void ADC1_disCalibProtCh14(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN14 = 0u;
}



static __inline void ADC1_enCalibProtCh15(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN15 = 1u;
}



static __inline void ADC1_disCalibProtCh15(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN15 = 0u;
}



static __inline void ADC1_enCalibProtCh16(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN16 = 1u;
}



static __inline void ADC1_disCalibProtCh16(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN16 = 0u;
}



static __inline void ADC1_enCalibProtCh17(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN17 = 1u;
}



static __inline void ADC1_disCalibProtCh17(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN17 = 0u;
}



static __inline void ADC1_enCalibProtCh18(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN18 = 1u;
}



static __inline void ADC1_disCalibProtCh18(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN18 = 0u;
}



static __inline void ADC1_enCalibProtCh19(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN19 = 1u;
}



static __inline void ADC1_disCalibProtCh19(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN19 = 0u;
}



static __inline void ADC1_enCalibProtCh20(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN20 = 1u;
}



static __inline void ADC1_disCalibProtCh20(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN20 = 0u;
}



static __inline void ADC1_enCalibProtCh21(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN21 = 1u;
}



static __inline void ADC1_disCalibProtCh21(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN21 = 0u;
}



static __inline void ADC1_enCalibProtCh22(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN22 = 1u;
}



static __inline void ADC1_disCalibProtCh22(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN22 = 0u;
}



static __inline void ADC1_enCalibProtCh23(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN23 = 1u;
}



static __inline void ADC1_disCalibProtCh23(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN23 = 0u;
}



static __inline void ADC1_enCalibProtCh24(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN24 = 1u;
}



static __inline void ADC1_disCalibProtCh24(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN24 = 0u;
}



static __inline void ADC1_enCalibProtCh25(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN25 = 1u;
}



static __inline void ADC1_disCalibProtCh25(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN25 = 0u;
}



static __inline void ADC1_enCalibProtCh26(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN26 = 1u;
}



static __inline void ADC1_disCalibProtCh26(void)
{
  ((ADC1_Type*) 0x40000000UL)->CALPEN.bit.CALPEN26 = 0u;
}





static __inline void ADC1_setFilter0Coeff(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A0 = u8_value;
}





static __inline uint8 ADC1_getFilter0Coeff(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A0;
}





static __inline void ADC1_setFilter1Coeff(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A1 = u8_value;
}





static __inline uint8 ADC1_getFilter1Coeff(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A1;
}





static __inline void ADC1_setFilter2Coeff(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A2 = u8_value;
}





static __inline uint8 ADC1_getFilter2Coeff(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A2;
}





static __inline void ADC1_setFilter3Coeff(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A3 = u8_value;
}





static __inline uint8 ADC1_getFilter3Coeff(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILTCFG.bit.COEF_A3;
}





static __inline uint16 ADC1_getFilter0Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->FIL0.bit.FILRESULT;
}





static __inline uint16 ADC1_getFilter1Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->FIL1.bit.FILRESULT;
}





static __inline uint16 ADC1_getFilter2Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->FIL2.bit.FILRESULT;
}





static __inline uint16 ADC1_getFilter3Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->FIL3.bit.FILRESULT;
}





static __inline uint8 ADC1_getFilter0Sts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILSTAT.bit.FIL0;
}





static __inline uint8 ADC1_getFilter1Sts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILSTAT.bit.FIL1;
}





static __inline uint8 ADC1_getFilter2Sts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILSTAT.bit.FIL2;
}





static __inline uint8 ADC1_getFilter3Sts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->FILSTAT.bit.FIL3;
}



static __inline void ADC1_clrFilter0Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATCLR.bit.FIL0CLR = 1u;
}



static __inline void ADC1_clrFilter1Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATCLR.bit.FIL1CLR = 1u;
}



static __inline void ADC1_clrFilter2Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATCLR.bit.FIL2CLR = 1u;
}



static __inline void ADC1_clrFilter3Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATCLR.bit.FIL3CLR = 1u;
}



static __inline void ADC1_setFilter0Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATSET.bit.FIL0SET = 1u;
}



static __inline void ADC1_setFilter1Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATSET.bit.FIL1SET = 1u;
}



static __inline void ADC1_setFilter2Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATSET.bit.FIL2SET = 1u;
}



static __inline void ADC1_setFilter3Sts(void)
{
  ((ADC1_Type*) 0x40000000UL)->FILSTATSET.bit.FIL3SET = 1u;
}





static __inline uint16 ADC1_getCh0Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES0.bit.RESULT;
}





static __inline uint8 ADC1_getCh0ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES0.bit.VALID;
}





static __inline uint16 ADC1_getCh1Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES1.bit.RESULT;
}





static __inline uint8 ADC1_getCh1ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES1.bit.VALID;
}





static __inline uint16 ADC1_getCh2Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES2.bit.RESULT;
}





static __inline uint8 ADC1_getCh2ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES2.bit.VALID;
}





static __inline uint16 ADC1_getCh3Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES3.bit.RESULT;
}





static __inline uint8 ADC1_getCh3ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES3.bit.VALID;
}





static __inline uint16 ADC1_getCh4Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES4.bit.RESULT;
}





static __inline uint8 ADC1_getCh4ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES4.bit.VALID;
}





static __inline uint16 ADC1_getCh5Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES5.bit.RESULT;
}





static __inline uint8 ADC1_getCh5ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES5.bit.VALID;
}





static __inline uint16 ADC1_getCh6Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES6.bit.RESULT;
}





static __inline uint8 ADC1_getCh6ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES6.bit.VALID;
}





static __inline uint16 ADC1_getCh7Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES7.bit.RESULT;
}





static __inline uint8 ADC1_getCh7ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES7.bit.VALID;
}





static __inline uint16 ADC1_getCh8Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES8.bit.RESULT;
}





static __inline uint8 ADC1_getCh8ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES8.bit.VALID;
}





static __inline uint16 ADC1_getCh9Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES9.bit.RESULT;
}





static __inline uint8 ADC1_getCh9ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES9.bit.VALID;
}





static __inline uint16 ADC1_getCh10Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES10.bit.RESULT;
}





static __inline uint8 ADC1_getCh10ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES10.bit.VALID;
}





static __inline uint16 ADC1_getCh11Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES11.bit.RESULT;
}





static __inline uint8 ADC1_getCh11ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES11.bit.VALID;
}





static __inline uint16 ADC1_getCh12Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES12.bit.RESULT;
}





static __inline uint8 ADC1_getCh12ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES12.bit.VALID;
}





static __inline uint16 ADC1_getCh13Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES13.bit.RESULT;
}





static __inline uint8 ADC1_getCh13ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES13.bit.VALID;
}





static __inline uint16 ADC1_getCh14Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES14.bit.RESULT;
}





static __inline uint8 ADC1_getCh14ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES14.bit.VALID;
}





static __inline uint16 ADC1_getCh15Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES15.bit.RESULT;
}





static __inline uint8 ADC1_getCh15ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES15.bit.VALID;
}





static __inline uint16 ADC1_getCh16Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES16.bit.RESULT;
}





static __inline uint8 ADC1_getCh16ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES16.bit.VALID;
}





static __inline uint16 ADC1_getCh17Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES17.bit.RESULT;
}





static __inline uint8 ADC1_getCh17ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES17.bit.VALID;
}





static __inline uint16 ADC1_getCh18Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES18.bit.RESULT;
}





static __inline uint8 ADC1_getCh18ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES18.bit.VALID;
}





static __inline uint16 ADC1_getCh19Result(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->RES19.bit.RESULT;
}





static __inline uint8 ADC1_getCh19ResultValidSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->RES19.bit.VALID;
}





static __inline void ADC1_setCmp0Config(tADC1_CMPCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CMPCFG0.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCmp1Config(tADC1_CMPCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CMPCFG1.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCmp2Config(tADC1_CMPCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CMPCFG2.reg = (uint32)s_value.reg;
}





static __inline void ADC1_setCmp3Config(tADC1_CMPCFGx s_value)
{
  ((ADC1_Type*) 0x40000000UL)->CMPCFG3.reg = (uint32)s_value.reg;
}





static __inline uint8 ADC1_getCmp0UpIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP0_IS;
}





static __inline uint8 ADC1_getCmp1UpIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP1_IS;
}





static __inline uint8 ADC1_getCmp2UpIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP2_IS;
}





static __inline uint8 ADC1_getCmp3UpIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP3_IS;
}





static __inline uint8 ADC1_getCmp0UpThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP0_STS;
}





static __inline uint8 ADC1_getCmp1UpThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP1_STS;
}





static __inline uint8 ADC1_getCmp2UpThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP2_STS;
}





static __inline uint8 ADC1_getCmp3UpThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_UP3_STS;
}





static __inline uint8 ADC1_getCmp0LoIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO0_IS;
}





static __inline uint8 ADC1_getCmp1LoIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO1_IS;
}





static __inline uint8 ADC1_getCmp2LoIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO2_IS;
}





static __inline uint8 ADC1_getCmp3LoIntSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO3_IS;
}





static __inline uint8 ADC1_getCmp0LoThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO0_STS;
}





static __inline uint8 ADC1_getCmp1LoThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO1_STS;
}





static __inline uint8 ADC1_getCmp2LoThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO2_STS;
}





static __inline uint8 ADC1_getCmp3LoThSts(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CMPSTAT.bit.CMP_LO3_STS;
}



static __inline void ADC1_clrCmp0UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP0_ISCLR = 1u;
}



static __inline void ADC1_clrCmp1UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP1_ISCLR = 1u;
}



static __inline void ADC1_clrCmp2UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP2_ISCLR = 1u;
}



static __inline void ADC1_clrCmp3UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP3_ISCLR = 1u;
}



static __inline void ADC1_clrCmp0UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP0_STSCLR = 1u;
}



static __inline void ADC1_clrCmp1UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP1_STSCLR = 1u;
}



static __inline void ADC1_clrCmp2UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP2_STSCLR = 1u;
}



static __inline void ADC1_clrCmp3UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_UP3_STSCLR = 1u;
}



static __inline void ADC1_clrCmp0LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO0_ISCLR = 1u;
}



static __inline void ADC1_clrCmp1LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO1_ISCLR = 1u;
}



static __inline void ADC1_clrCmp2LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO2_ISCLR = 1u;
}



static __inline void ADC1_clrCmp3LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO3_ISCLR = 1u;
}



static __inline void ADC1_clrCmp0LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO0_STSCLR = 1u;
}



static __inline void ADC1_clrCmp1LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO1_STSCLR = 1u;
}



static __inline void ADC1_clrCmp2LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO2_STSCLR = 1u;
}



static __inline void ADC1_clrCmp3LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATCLR.bit.CMP_LO3_STSCLR = 1u;
}



static __inline void ADC1_setCmp0UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP0_ISSET = 1u;
}



static __inline void ADC1_setCmp1UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP1_ISSET = 1u;
}



static __inline void ADC1_setCmp2UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP2_ISSET = 1u;
}



static __inline void ADC1_setCmp3UpIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP3_ISSET = 1u;
}



static __inline void ADC1_setCmp0UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP0_STSSET = 1u;
}



static __inline void ADC1_setCmp1UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP1_STSSET = 1u;
}



static __inline void ADC1_setCmp2UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP2_STSSET = 1u;
}



static __inline void ADC1_setCmp3UpThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_UP3_STSSET = 1u;
}



static __inline void ADC1_setCmp0LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO0_ISSET = 1u;
}



static __inline void ADC1_setCmp1LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO1_ISSET = 1u;
}



static __inline void ADC1_setCmp2LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO2_ISSET = 1u;
}



static __inline void ADC1_setCmp3LoIntSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO3_ISSET = 1u;
}



static __inline void ADC1_setCmp0LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO0_STSSET = 1u;
}



static __inline void ADC1_setCmp1LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO1_STSSET = 1u;
}



static __inline void ADC1_setCmp2LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO2_STSSET = 1u;
}



static __inline void ADC1_setCmp3LoThSts(void)
{
  ((ADC1_Type*) 0x40000000UL)->CMPSTATSET.bit.CMP_LO3_STSSET = 1u;
}



static __inline void ADC1_enCmp0UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP0 = 1u;
}



static __inline void ADC1_disCmp0UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP0 = 0u;
}



static __inline void ADC1_enCmp1UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP1 = 1u;
}



static __inline void ADC1_disCmp1UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP1 = 0u;
}



static __inline void ADC1_enCmp2UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP2 = 1u;
}



static __inline void ADC1_disCmp2UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP2 = 0u;
}



static __inline void ADC1_enCmp3UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP3 = 1u;
}



static __inline void ADC1_disCmp3UpInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_UP3 = 0u;
}



static __inline void ADC1_enCmp0LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO0 = 1u;
}



static __inline void ADC1_disCmp0LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO0 = 0u;
}



static __inline void ADC1_enCmp1LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO1 = 1u;
}



static __inline void ADC1_disCmp1LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO1 = 0u;
}



static __inline void ADC1_enCmp2LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO2 = 1u;
}



static __inline void ADC1_disCmp2LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO2 = 0u;
}



static __inline void ADC1_enCmp3LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO3 = 1u;
}



static __inline void ADC1_disCmp3LoInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_LO3 = 0u;
}



static __inline void ADC1_enSeq0Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ0 = 1u;
}



static __inline void ADC1_disSeq0Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ0 = 0u;
}



static __inline void ADC1_enSeq1Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ1 = 1u;
}



static __inline void ADC1_disSeq1Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ1 = 0u;
}



static __inline void ADC1_enSeq2Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ2 = 1u;
}



static __inline void ADC1_disSeq2Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ2 = 0u;
}



static __inline void ADC1_enSeq3Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ3 = 1u;
}



static __inline void ADC1_disSeq3Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_SQ3 = 0u;
}



static __inline void ADC1_enCh0Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH0 = 1u;
}



static __inline void ADC1_disCh0Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH0 = 0u;
}



static __inline void ADC1_enCh1Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH1 = 1u;
}



static __inline void ADC1_disCh1Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH1 = 0u;
}



static __inline void ADC1_enCh2Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH2 = 1u;
}



static __inline void ADC1_disCh2Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH2 = 0u;
}



static __inline void ADC1_enCh3Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH3 = 1u;
}



static __inline void ADC1_disCh3Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH3 = 0u;
}



static __inline void ADC1_enCh4Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH4 = 1u;
}



static __inline void ADC1_disCh4Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH4 = 0u;
}



static __inline void ADC1_enCh5Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH5 = 1u;
}



static __inline void ADC1_disCh5Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH5 = 0u;
}



static __inline void ADC1_enCh6Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH6 = 1u;
}



static __inline void ADC1_disCh6Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH6 = 0u;
}



static __inline void ADC1_enCh7Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH7 = 1u;
}



static __inline void ADC1_disCh7Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH7 = 0u;
}



static __inline void ADC1_enCh8Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH8 = 1u;
}



static __inline void ADC1_disCh8Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH8 = 0u;
}



static __inline void ADC1_enCh9Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH9 = 1u;
}



static __inline void ADC1_disCh9Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH9 = 0u;
}



static __inline void ADC1_enCh10Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH10 = 1u;
}



static __inline void ADC1_disCh10Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH10 = 0u;
}



static __inline void ADC1_enCh11Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH11 = 1u;
}



static __inline void ADC1_disCh11Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH11 = 0u;
}



static __inline void ADC1_enCh12Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH12 = 1u;
}



static __inline void ADC1_disCh12Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH12 = 0u;
}



static __inline void ADC1_enCh13Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH13 = 1u;
}



static __inline void ADC1_disCh13Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH13 = 0u;
}



static __inline void ADC1_enCh14Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH14 = 1u;
}



static __inline void ADC1_disCh14Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH14 = 0u;
}



static __inline void ADC1_enCh15Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH15 = 1u;
}



static __inline void ADC1_disCh15Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH15 = 0u;
}



static __inline void ADC1_enCh16Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH16 = 1u;
}



static __inline void ADC1_disCh16Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH16 = 0u;
}



static __inline void ADC1_enCh17Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH17 = 1u;
}



static __inline void ADC1_disCh17Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH17 = 0u;
}



static __inline void ADC1_enCh18Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH18 = 1u;
}



static __inline void ADC1_disCh18Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH18 = 0u;
}



static __inline void ADC1_enCh19Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH19 = 1u;
}



static __inline void ADC1_disCh19Int(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN0.bit.IEN_CH19 = 0u;
}



static __inline void ADC1_enSeq0WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR0 = 1u;
}



static __inline void ADC1_disSeq0WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR0 = 0u;
}



static __inline void ADC1_enSeq1WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR1 = 1u;
}



static __inline void ADC1_disSeq1WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR1 = 0u;
}



static __inline void ADC1_enSeq2WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR2 = 1u;
}



static __inline void ADC1_disSeq2WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR2 = 0u;
}



static __inline void ADC1_enSeq3WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR3 = 1u;
}



static __inline void ADC1_disSeq3WaitForReadInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_WFR3 = 0u;
}



static __inline void ADC1_enSeq0CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL0 = 1u;
}



static __inline void ADC1_disSeq0CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL0 = 0u;
}



static __inline void ADC1_enSeq1CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL1 = 1u;
}



static __inline void ADC1_disSeq1CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL1 = 0u;
}



static __inline void ADC1_enSeq2CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL2 = 1u;
}



static __inline void ADC1_disSeq2CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL2 = 0u;
}



static __inline void ADC1_enSeq3CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL3 = 1u;
}



static __inline void ADC1_disSeq3CollInt(void)
{
  ((ADC1_Type*) 0x40000000UL)->IEN1.bit.IEN_COLL3 = 0u;
}





static __inline uint8 ADC1_getCh0IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH0;
}





static __inline uint8 ADC1_getCh1IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH1;
}





static __inline uint8 ADC1_getCh2IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH2;
}





static __inline uint8 ADC1_getCh3IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH3;
}





static __inline uint8 ADC1_getCh4IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH4;
}





static __inline uint8 ADC1_getCh5IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH5;
}





static __inline uint8 ADC1_getCh6IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH6;
}





static __inline uint8 ADC1_getCh7IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH7;
}





static __inline uint8 ADC1_getCh8IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH8;
}





static __inline uint8 ADC1_getCh9IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH9;
}





static __inline uint8 ADC1_getCh10IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH10;
}





static __inline uint8 ADC1_getCh11IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH11;
}





static __inline uint8 ADC1_getCh12IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH12;
}





static __inline uint8 ADC1_getCh13IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH13;
}





static __inline uint8 ADC1_getCh14IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH14;
}





static __inline uint8 ADC1_getCh15IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP0.bit.INP_CH15;
}





static __inline uint8 ADC1_getCh16IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP1.bit.INP_CH16;
}





static __inline uint8 ADC1_getCh17IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP1.bit.INP_CH17;
}





static __inline uint8 ADC1_getCh18IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP1.bit.INP_CH18;
}





static __inline uint8 ADC1_getCh19IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP1.bit.INP_CH19;
}





static __inline uint8 ADC1_getCmp0LoIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_LO0;
}





static __inline uint8 ADC1_getCmp1LoIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_LO1;
}





static __inline uint8 ADC1_getCmp2LoIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_LO2;
}





static __inline uint8 ADC1_getCmp3LoIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_LO3;
}





static __inline uint8 ADC1_getCmp0UpIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_UP0;
}





static __inline uint8 ADC1_getCmp1UpIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_UP1;
}





static __inline uint8 ADC1_getCmp2UpIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_UP2;
}





static __inline uint8 ADC1_getCmp3UpIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP2.bit.INP_CMP_UP3;
}





static __inline uint8 ADC1_getSeq0IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_SQ0;
}





static __inline uint8 ADC1_getSeq1IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_SQ1;
}





static __inline uint8 ADC1_getSeq2IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_SQ2;
}





static __inline uint8 ADC1_getSeq3IntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_SQ3;
}





static __inline uint8 ADC1_getSeq0CollIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_COLL0;
}





static __inline uint8 ADC1_getSeq1CollIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_COLL1;
}





static __inline uint8 ADC1_getSeq2CollIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_COLL2;
}





static __inline uint8 ADC1_getSeq3CollIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_COLL3;
}





static __inline uint8 ADC1_getSeq0WaitForReadIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_WFR0;
}





static __inline uint8 ADC1_getSeq1WaitForReadIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_WFR1;
}





static __inline uint8 ADC1_getSeq2WaitForReadIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_WFR2;
}





static __inline uint8 ADC1_getSeq3WaitForReadIntNodePtr(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->INP3.bit.INP_WFR3;
}





static __inline void ADC1_setSeqHwShadowTrans(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_SQSEL = u8_value;
}





static __inline uint8 ADC1_getSeqHwShadowTrans(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_SQSEL;
}





static __inline void ADC1_setTriggHwShadowTrans(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_TRGSEL = u8_value;
}





static __inline uint8 ADC1_getTriggHwShadowTrans(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_TRGSEL;
}





static __inline void ADC1_setGateHwShadowTrans(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_GTGSEL = u8_value;
}





static __inline uint8 ADC1_getGateHwShadowTrans(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_GTGSEL;
}



static __inline void ADC1_enSeqHwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_SQSEL = 1u;
}



static __inline void ADC1_disSeqHwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_SQSEL = 0u;
}



static __inline void ADC1_enTriggHwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_TRGSEL = 1u;
}



static __inline void ADC1_disTriggHwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_TRGSEL = 0u;
}



static __inline void ADC1_enGateHwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_GTGSEL = 1u;
}



static __inline void ADC1_disGateHwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_GTGSEL = 0u;
}



static __inline void ADC1_setSeqSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_SQSW = 1u;
}





static __inline uint8 ADC1_getSeqSwShadowTrans(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_SQSW;
}



static __inline void ADC1_setTriggSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_TRGSW = 1u;
}





static __inline uint8 ADC1_getTriggSwShadowTrans(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_TRGSW;
}



static __inline void ADC1_setGateSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_GTGSW = 1u;
}





static __inline uint8 ADC1_getGateSwShadowTrans(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.ST_GTGSW;
}



static __inline void ADC1_enSeqSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_SQ = 1u;
}



static __inline void ADC1_disSeqSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_SQ = 0u;
}



static __inline void ADC1_enTriggSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_TRG = 1u;
}



static __inline void ADC1_disTriggSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_TRG = 0u;
}



static __inline void ADC1_enGateSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_GTG = 1u;
}



static __inline void ADC1_disGateSwShadowTrans(void)
{
  ((ADC1_Type*) 0x40000000UL)->SHDCTR.bit.STE_GTG = 0u;
}





static __inline void ADC1_setCalibOffsAnaIn1(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI1.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn1(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI1.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn1(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI1.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn1(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI1.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn3(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI3.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn3(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI3.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn3(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI3.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn3(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI3.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn5(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI5.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn5(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI5.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn5(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI5.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn5(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI5.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn7(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI7.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn7(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI7.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn7(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI7.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn7(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI7.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn9(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI9.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn9(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI9.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn9(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI9.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn9(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI9.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn11(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI11.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn11(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI11.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn11(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI11.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn11(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI11.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn13(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI13.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn13(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI13.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn13(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI13.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn13(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI13.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn15(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI15.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn15(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI15.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn15(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI15.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn15(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI15.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn16(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI16.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn16(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI16.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn16(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI16.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn16(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI16.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn17(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI17.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn17(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI17.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn17(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI17.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn17(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI17.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn18(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI18.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn18(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI18.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn18(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI18.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn18(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI18.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn19(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI19.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn19(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI19.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn19(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI19.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn19(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI19.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn20(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI20.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn20(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI20.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn20(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI20.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn20(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI20.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn21(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI21.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn21(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI21.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn21(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI21.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn21(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI21.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn22(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI22.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn22(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI22.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn22(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI22.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn22(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI22.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn23(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI23.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn23(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI23.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn23(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI23.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn23(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI23.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn24(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI24.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn24(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI24.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn24(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI24.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn24(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI24.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn25(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI25.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn25(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI25.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn25(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI25.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn25(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI25.bit.CALGAIN;
}





static __inline void ADC1_setCalibOffsAnaIn26(uint8 u8_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI26.bit.CALOFFS = u8_value;
}





static __inline uint8 ADC1_getCalibOffsAnaIn26(void)
{
  return (uint8)((ADC1_Type*) 0x40000000UL)->CALAI26.bit.CALOFFS;
}





static __inline void ADC1_setCalibGainAnaIn26(uint16 u16_value)
{
  ((ADC1_Type*) 0x40000000UL)->CALAI26.bit.CALGAIN = u16_value;
}





static __inline uint16 ADC1_getCalibGainAnaIn26(void)
{
  return (uint16)((ADC1_Type*) 0x40000000UL)->CALAI26.bit.CALGAIN;
}



static __inline void ARVG_enVAREF(void)
{
  ((ARVG_Type*) 0x48038000UL)->VAREF_CTRL.bit.EN = 1u;
}



static __inline void ARVG_disVAREF(void)
{
  ((ARVG_Type*) 0x48038000UL)->VAREF_CTRL.bit.EN = 0u;
}



static __inline void ARVG_enVAREFOvercurrentInt(void)
{
  ((ARVG_Type*) 0x48038000UL)->VAREF_IEN.bit.OC_IEN = 1u;
}



static __inline void ARVG_disVAREFOvercurrentInt(void)
{
  ((ARVG_Type*) 0x48038000UL)->VAREF_IEN.bit.OC_IEN = 0u;
}





static __inline uint8 ARVG_getVAREFOvercurrentIntSts(void)
{
  return (uint8)((ARVG_Type*) 0x48038000UL)->VAREF_IRQ.bit.OC_IS;
}





static __inline uint8 ARVG_getVAREFOvercurrentSts(void)
{
  return (uint8)((ARVG_Type*) 0x48038000UL)->VAREF_IRQ.bit.OC_STS;
}



static __inline void ARVG_clrVAREFOvercurrentIntSts(void)
{
  ((ARVG_Type*) 0x48038000UL)->VAREF_IRQ_CLR.bit.OC_IS_CLR = 1u;
}



static __inline void ARVG_clrVAREFOvercurrentSts(void)
{
  ((ARVG_Type*) 0x48038000UL)->VAREF_IRQ_CLR.bit.OC_STS_CLR = 1u;
}
# 113 "./RTE/Device/TLE9893_2QKW62S/csacsc.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/csacsc_defines.h" 1
# 114 "./RTE/Device/TLE9893_2QKW62S/csacsc.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/isr_defines.h" 1
# 115 "./RTE/Device/TLE9893_2QKW62S/csacsc.h" 2
# 128 "./RTE/Device/TLE9893_2QKW62S/csacsc.h"
typedef enum CSA_gain
{
  CSA_gain_10 = 0,
  CSA_gain_20 = 1,
  CSA_gain_40 = 2,
  CSA_gain_60 = 3
} tCSA_gain;





typedef enum CSA_offset
{
  CSA_offset_10 = 0,
  CSA_offset_20 = 1,
  CSA_offset_40 = 2,
  CSA_offset_60 = 3
} tCSA_offset;





sint8 CSACSC_init(void);
sint8 CSACSC_startCalibration(uint16 *pu16_Val_mV);
static __inline void CSACSC_enPower(void);
static __inline void CSACSC_disPower(void);
static __inline void CSACSC_setMinGain(tCSA_gain e_gain);
static __inline tCSA_gain CSACSC_getMinGain(void);
static __inline void CSACSC_setMinOffset(tCSA_offset e_offset);
static __inline tCSA_offset CSACSC_getMinOffset(void);
static __inline void CSACSC_setMaxThreshold(uint16 u16_value);
static __inline uint16 CSACSC_getMaxThreshold(void);
static __inline void CSACSC_setAddInputOffset(uint8 u8_value);
static __inline uint8 CSACSC_getAddInputOffset(void);
static __inline void CSACSC_setGain(tCSA_gain e_gain);
static __inline tCSA_gain CSACSC_getGain(void);
static __inline void CSACSC_setOffset(tCSA_offset e_offset);
static __inline tCSA_offset CSACSC_getOffset(void);
static __inline void CSACSC_setVout(uint8 u8_value);
static __inline uint8 CSACSC_getVout(void);
static __inline void CSACSC_setThreshold(uint8 u8_value);
static __inline uint8 CSACSC_getThreshold(void);
static __inline void CSACSC_setFilterTime(uint8 u8_value);
static __inline uint8 CSACSC_getFilterTime(void);
static __inline void CSACSC_clrOverCurrIntSts(void);
static __inline void CSACSC_clrParamErrorIntSts(void);
static __inline void CSACSC_clrOverCurrSts(void);
static __inline void CSACSC_enOverCurrInt(void);
static __inline void CSACSC_disOverCurrInt(void);
static __inline void CSACSC_enParamErrorInt(void);
static __inline void CSACSC_disParamErrorInt(void);
static __inline uint8 CSACSC_getOverCurrIntSts(void);
static __inline uint8 CSACSC_getParamErrorIntSts(void);
static __inline uint8 CSACSC_getOverCurrSts(void);
static __inline uint8 CSACSC_getOverCurrCmpOut(void);
static __inline uint8 CSACSC_getBistSts(void);
# 194 "./RTE/Device/TLE9893_2QKW62S/csacsc.h"
void CSACSC_setOverCurrIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void CSACSC_setParamErrorIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));






static __inline void CSACSC_enPower(void)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.CSAC_EN = 1u;
}



static __inline void CSACSC_disPower(void)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.CSAC_EN = 0u;
}



#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcovered-switch-default"





static __inline void CSACSC_setMinGain(tCSA_gain e_gain)
{
  switch (e_gain)
  {
    case CSA_gain_10:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.GAIN_MIN = 0u;
      break;
    }
    case CSA_gain_20:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.GAIN_MIN = 3u;
      break;
    }
    case CSA_gain_40:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.GAIN_MIN = 12u;
      break;
    }
    case CSA_gain_60:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.GAIN_MIN = 15u;
      break;
    }
    default:
    {
      break;
    }
  }
}

#pragma clang diagnostic pop






static __inline tCSA_gain CSACSC_getMinGain(void)
{
  tCSA_gain e_gain;
  uint8 u8_minGain;

  u8_minGain = ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.GAIN_MIN;

  if (u8_minGain == 0u)
  {
    e_gain = CSA_gain_10;
  }
  else if (u8_minGain == 3u)
  {
    e_gain = CSA_gain_20;
  }
  else if (u8_minGain == 12u)
  {
    e_gain = CSA_gain_40;
  }
  else
  {
    e_gain = CSA_gain_60;
  }
  return e_gain;
}



#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcovered-switch-default"





static __inline void CSACSC_setMinOffset(tCSA_offset e_offset)
{
  switch (e_offset)
  {
    case CSA_offset_10:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.OFFS_MIN = 0u;
      break;
    }
    case CSA_offset_20:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.OFFS_MIN = 3u;
      break;
    }
    case CSA_offset_40:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.OFFS_MIN = 12u;
      break;
    }
    case CSA_offset_60:
    {
      ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.OFFS_MIN = 15u;
      break;
    }
    default:
    {
      break;
    }
  }
}

#pragma clang diagnostic pop






static __inline tCSA_offset CSACSC_getMinOffset(void)
{
  tCSA_offset e_offset;
  uint8 u8_minOffset;

  u8_minOffset = ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.OFFS_MIN;

  if (u8_minOffset == 0u)
  {
    e_offset = CSA_offset_10;
  }
  else if (u8_minOffset == 3u)
  {
    e_offset = CSA_offset_20;
  }
  else if (u8_minOffset == 12u)
  {
    e_offset = CSA_offset_40;
  }
  else
  {
    e_offset = CSA_offset_60;
  }
  return e_offset;
}





static __inline void CSACSC_setMaxThreshold(uint16 u16_value)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.THR_MAX = u16_value;
}





static __inline uint16 CSACSC_getMaxThreshold(void)
{
  return (uint16)((CSACSC_Type*) 0x40010000UL)->CTRL1.bit.THR_MAX;
}





static __inline void CSACSC_setAddInputOffset(uint8 u8_value)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.ADD_INP_OFFS = u8_value;
}





static __inline uint8 CSACSC_getAddInputOffset(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.ADD_INP_OFFS;
}





static __inline void CSACSC_setGain(tCSA_gain e_gain)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.GAIN_SEL = (uint8)e_gain;
}





static __inline tCSA_gain CSACSC_getGain(void)
{



  return (tCSA_gain)((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.GAIN_SEL;


}





static __inline void CSACSC_setOffset(tCSA_offset e_offset)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.OFFS_SEL = (uint8)e_offset;
}





static __inline tCSA_offset CSACSC_getOffset(void)
{



  return (tCSA_offset)((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.OFFS_SEL;



}





static __inline void CSACSC_setVout(uint8 u8_value)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.VOUT_SEL = u8_value;
}





static __inline uint8 CSACSC_getVout(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.VOUT_SEL;
}





static __inline void CSACSC_setThreshold(uint8 u8_value)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.THR_SEL = u8_value;
}





static __inline uint8 CSACSC_getThreshold(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.THR_SEL;
}





static __inline void CSACSC_setFilterTime(uint8 u8_value)
{
  ((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.TFILT_SEL = u8_value;
}





static __inline uint8 CSACSC_getFilterTime(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->CTRL2.bit.TFILT_SEL;
}



static __inline void CSACSC_clrOverCurrIntSts(void)
{
  ((CSACSC_Type*) 0x40010000UL)->IRQCLR.bit.CSC_OC_ISC = 1u;
}



static __inline void CSACSC_clrParamErrorIntSts(void)
{
  ((CSACSC_Type*) 0x40010000UL)->IRQCLR.bit.SEL_ERR_ISC = 1u;
}



static __inline void CSACSC_clrOverCurrSts(void)
{
  ((CSACSC_Type*) 0x40010000UL)->IRQCLR.bit.CSC_OC_SC = 1u;
}



static __inline void CSACSC_enOverCurrInt(void)
{
  ((CSACSC_Type*) 0x40010000UL)->IRQEN.bit.CSC_OC_IEN = 1u;
}



static __inline void CSACSC_disOverCurrInt(void)
{
  ((CSACSC_Type*) 0x40010000UL)->IRQEN.bit.CSC_OC_IEN = 0u;
}



static __inline void CSACSC_enParamErrorInt(void)
{
  ((CSACSC_Type*) 0x40010000UL)->IRQEN.bit.SEL_ERR_IEN = 1u;
}



static __inline void CSACSC_disParamErrorInt(void)
{
  ((CSACSC_Type*) 0x40010000UL)->IRQEN.bit.SEL_ERR_IEN = 0u;
}





static __inline uint8 CSACSC_getOverCurrIntSts(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->IRQS.bit.CSC_OC_IS;
}





static __inline uint8 CSACSC_getParamErrorIntSts(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->IRQS.bit.SEL_ERR_IS;
}





static __inline uint8 CSACSC_getOverCurrSts(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->IRQS.bit.CSC_OC_STS;
}





static __inline uint8 CSACSC_getOverCurrCmpOut(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->IRQS.bit.CSC_OC_OUT;
}





static __inline uint8 CSACSC_getBistSts(void)
{
  return (uint8)((CSACSC_Type*) 0x40010000UL)->IRQS.bit.CSC_BIST_STS;
}
# 34 "RTE/Device/TLE9893_2QKW62S/csacsc.c" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/scu.h" 1
# 136 "./RTE/Device/TLE9893_2QKW62S/scu.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/bdrv.h" 1
# 129 "./RTE/Device/TLE9893_2QKW62S/bdrv.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/bdrv_defines.h" 1
# 130 "./RTE/Device/TLE9893_2QKW62S/bdrv.h" 2
# 143 "./RTE/Device/TLE9893_2QKW62S/bdrv.h"
typedef enum BDRV_chCfg
{
  BDRV_chCfg_off = 0u,
  BDRV_chCfg_en = 1u,
  BDRV_chCfg_pwm = 2u,
  BDRV_chCfg_on = 3u,
  BDRV_chCfg_hsDcs = 4u
} tBDRV_chCfg;





typedef enum BDRV_hb
{
  BDRV_hb_1 = 1u,
  BDRV_hb_2 = 2u,

  BDRV_hb_3 = 3u

} tBDRV_hb;





typedef enum BDRV_offStateDiag
{
  BDRV_offStateDiag_ok = 0u,
  BDRV_offStateDiag_short2gnd = 1u,
  BDRV_offStateDiag_short2bat = 2u,
  BDRV_offStateDiag_openload = 3u
} tBDRV_offStateDiag;




typedef struct BDRV_offState
{
  _Bool b_globFailSts;
  tBDRV_offStateDiag e_offStateDiagPhase1;
  tBDRV_offStateDiag e_offStateDiagPhase2;

  tBDRV_offStateDiag e_offStateDiagPhase3;

} tBDRV_offState;





typedef enum BDRV_currentCfg
{
  BDRV_currentCfg_5mA = 0u,
  BDRV_currentCfg_6mA = 1u,
  BDRV_currentCfg_7mA = 2u,
  BDRV_currentCfg_9mA = 3u,
  BDRV_currentCfg_11mA = 4u,
  BDRV_currentCfg_13mA = 5u,
  BDRV_currentCfg_15mA = 6u,
  BDRV_currentCfg_18mA = 7u,
  BDRV_currentCfg_21mA = 8u,
  BDRV_currentCfg_24mA = 9u,
  BDRV_currentCfg_27mA = 10u,
  BDRV_currentCfg_31mA = 11u,
  BDRV_currentCfg_34mA = 12u,
  BDRV_currentCfg_38mA = 13u,
  BDRV_currentCfg_42mA = 14u,
  BDRV_currentCfg_46mA = 15u,
  BDRV_currentCfg_50mA = 16u,
  BDRV_currentCfg_54mA = 17u,
  BDRV_currentCfg_58mA = 18u,
  BDRV_currentCfg_63mA = 19u,
  BDRV_currentCfg_67mA = 20u,
  BDRV_currentCfg_72mA = 21u,
  BDRV_currentCfg_77mA = 22u,
  BDRV_currentCfg_82mA = 23u,
  BDRV_currentCfg_87mA = 24u,
  BDRV_currentCfg_92mA = 25u,
  BDRV_currentCfg_97mA = 26u,
  BDRV_currentCfg_103mA = 27u,
  BDRV_currentCfg_108mA = 28u,
  BDRV_currentCfg_114mA = 29u,
  BDRV_currentCfg_119mA = 30u,
  BDRV_currentCfg_125mA = 31u,
  BDRV_currentCfg_131mA = 32u,
  BDRV_currentCfg_137mA = 33u,
  BDRV_currentCfg_143mA = 34u,
  BDRV_currentCfg_149mA = 35u,
  BDRV_currentCfg_155mA = 36u,
  BDRV_currentCfg_161mA = 37u,
  BDRV_currentCfg_167mA = 38u,
  BDRV_currentCfg_174mA = 39u,
  BDRV_currentCfg_180mA = 40u,
  BDRV_currentCfg_187mA = 41u,
  BDRV_currentCfg_194mA = 42u,
  BDRV_currentCfg_200mA = 43u,
  BDRV_currentCfg_207mA = 44u,
  BDRV_currentCfg_214mA = 45u,
  BDRV_currentCfg_221mA = 46u,
  BDRV_currentCfg_228mA = 47u,
  BDRV_currentCfg_235mA = 48u,
  BDRV_currentCfg_242mA = 49u,
  BDRV_currentCfg_249mA = 50u,
  BDRV_currentCfg_257mA = 51u,
  BDRV_currentCfg_264mA = 52u,
  BDRV_currentCfg_272mA = 53u,
  BDRV_currentCfg_279mA = 54u,
  BDRV_currentCfg_287mA = 55u,
  BDRV_currentCfg_294mA = 56u,
  BDRV_currentCfg_302mA = 57u,
  BDRV_currentCfg_310mA = 58u,
  BDRV_currentCfg_318mA = 59u,
  BDRV_currentCfg_326mA = 60u,
  BDRV_currentCfg_334mA = 61u,
  BDRV_currentCfg_342mA = 62u,
  BDRV_currentCfg_350mA = 63u
} tBDRV_currentCfg;
# 271 "./RTE/Device/TLE9893_2QKW62S/bdrv.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
# 288 "./RTE/Device/TLE9893_2QKW62S/bdrv.h"
typedef struct
{
  tBDRV_currentCfg e_constCurrentAct;
  uint16 u16_constTimeAct_ns;
  tBDRV_currentCfg e_constCurrentFW;
  uint16 u16_constTimeFW_ns;
} tBDRV_constCfg;







typedef struct
{
  tBDRV_currentCfg e_seqPhase1CurrentAct;
  tBDRV_currentCfg e_seqPhase2CurrentAct;
  tBDRV_currentCfg e_seqPhase3CurrentAct;
  tBDRV_currentCfg e_seqPhase4CurrentAct;
  uint16 u16_seqPhase1TimeAct_ns;
  uint16 u16_seqPhase2TimeAct_ns;
  uint16 u16_seqPhase3TimeAct_ns;
  uint16 u16_seqPhase4TimeAct_ns;
  tBDRV_currentCfg e_constCurrentFW;
  uint16 u16_constTimeFW_ns;
} tBDRV_seqCfg;






typedef struct
{
  tBDRV_currentCfg e_aseqMinCurrent;
  uint16 u16_aseqMinTime_ns;
  tBDRV_currentCfg e_aseqMaxCurrent;
  uint16 u16_aseqMaxTime_ns;
} tBDRV_aseqCfg;






#pragma clang diagnostic pop
# 351 "./RTE/Device/TLE9893_2QKW62S/bdrv.h"
sint8 BDRV_init(void);
sint8 BDRV_initCP(void);



  sint8 BDRV_setBridge(tBDRV_chCfg e_ls1Cfg, tBDRV_chCfg e_hs1Cfg, tBDRV_chCfg e_ls2Cfg, tBDRV_chCfg e_hs2Cfg, tBDRV_chCfg e_ls3Cfg, tBDRV_chCfg e_hs3Cfg);

sint8 BDRV_setLSChrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constChrgCfg);
sint8 BDRV_setHSChrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constChrgCfg);
sint8 BDRV_setLSDischrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constDischrgCfg);
sint8 BDRV_setHSDischrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constDischrgCfg);
sint8 BDRV_setLSChrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqChrgCfg);
sint8 BDRV_setHSChrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqChrgCfg);
sint8 BDRV_setLSDischrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqDischrgCfg);
sint8 BDRV_setHSDischrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqDischrgCfg);
sint8 BDRV_setChrgAdaptSeqMode(tBDRV_aseqCfg s_aseqChrgCfg);
sint8 BDRV_setDischrgAdaptSeqMode(tBDRV_aseqCfg s_aseqDischrgCfg);
tBDRV_offState BDRV_checkShortDiagnosis(void);
tBDRV_offState BDRV_checkOpenLoad(void);
_Bool BDRV_getFaultSts(void);
uint8 BDRV_getFaults(void);
void BDRV_clrFaultSts(void);
static __inline void BDRV_enExternalLS1MosfetOvercurrentInt(void);
static __inline void BDRV_enExternalHS1MosfetOvercurrentInt(void);
static __inline void BDRV_enExternalLS2MosfetOvercurrentInt(void);
static __inline void BDRV_enExternalHS2MosfetOvercurrentInt(void);
static __inline void BDRV_enExternalLS3MosfetOvercurrentInt(void);
static __inline void BDRV_enExternalHS3MosfetOvercurrentInt(void);
static __inline void BDRV_enLS1DrainSrcMonitoringInt(void);
static __inline void BDRV_enHS1DrainSrcMonitoringInt(void);
static __inline void BDRV_enLS2DrainSrcMonitoringInt(void);
static __inline void BDRV_enHS2DrainSrcMonitoringInt(void);
static __inline void BDRV_enLS3DrainSrcMonitoringInt(void);
static __inline void BDRV_enHS3DrainSrcMonitoringInt(void);
static __inline void BDRV_enHB1AdaptSeqInt(void);
static __inline void BDRV_enHB2AdaptSeqInt(void);
static __inline void BDRV_enHB3AdaptSeqInt(void);
static __inline void BDRV_enHB1ActDrvDetectInt(void);
static __inline void BDRV_enHB2ActDrvDetectInt(void);
static __inline void BDRV_enHB3ActDrvDetectInt(void);
static __inline void BDRV_enDrvSeqErrInt(void);
static __inline void BDRV_enCPUndervoltageCompInt(void);
static __inline void BDRV_disExternalLS1MosfetOvercurrentInt(void);
static __inline void BDRV_disExternalHS1MosfetOvercurrentInt(void);
static __inline void BDRV_disExternalLS2MosfetOvercurrentInt(void);
static __inline void BDRV_disExternalHS2MosfetOvercurrentInt(void);
static __inline void BDRV_disExternalLS3MosfetOvercurrentInt(void);
static __inline void BDRV_disExternalHS3MosfetOvercurrentInt(void);
static __inline void BDRV_disLS1DrainSrcMonitoringInt(void);
static __inline void BDRV_disHS1DrainSrcMonitoringInt(void);
static __inline void BDRV_disLS2DrainSrcMonitoringInt(void);
static __inline void BDRV_disHS2DrainSrcMonitoringInt(void);
static __inline void BDRV_disLS3DrainSrcMonitoringInt(void);
static __inline void BDRV_disHS3DrainSrcMonitoringInt(void);
static __inline void BDRV_disHB1AdaptSeqInt(void);
static __inline void BDRV_disHB2AdaptSeqInt(void);
static __inline void BDRV_disHB3AdaptSeqInt(void);
static __inline void BDRV_disHB1ActDrvDetectInt(void);
static __inline void BDRV_disHB2ActDrvDetectInt(void);
static __inline void BDRV_disHB3ActDrvDetectInt(void);
static __inline void BDRV_disDrvSeqErrInt(void);
static __inline void BDRV_disCPUndervoltageCompInt(void);
static __inline uint8 BDRV_getExternalLS1MosfetOvercurrentSts(void);
static __inline uint8 BDRV_getExternalHS1MosfetOvercurrentSts(void);
static __inline uint8 BDRV_getExternalLS2MosfetOvercurrentSts(void);
static __inline uint8 BDRV_getExternalHS2MosfetOvercurrentSts(void);
static __inline uint8 BDRV_getExternalLS3MosfetOvercurrentSts(void);
static __inline uint8 BDRV_getExternalHS3MosfetOvercurrentSts(void);
static __inline uint8 BDRV_getLS1DrainSrcMonitoringSts(void);
static __inline uint8 BDRV_getHS1DrainSrcMonitoringSts(void);
static __inline uint8 BDRV_getLS2DrainSrcMonitoringSts(void);
static __inline uint8 BDRV_getHS2DrainSrcMonitoringSts(void);
static __inline uint8 BDRV_getLS3DrainSrcMonitoringSts(void);
static __inline uint8 BDRV_getHS3DrainSrcMonitoringSts(void);
static __inline uint8 BDRV_getSH1UndervoltageCompSts(void);
static __inline uint8 BDRV_getSH1OvervoltageCompSts(void);
static __inline uint8 BDRV_getSH2UndervoltageCompSts(void);
static __inline uint8 BDRV_getSH2OvervoltageCompSts(void);
static __inline uint8 BDRV_getSH3UndervoltageCompSts(void);
static __inline uint8 BDRV_getSH3OvervoltageCompSts(void);
static __inline uint8 BDRV_getCPOverTempSts(void);
static __inline uint8 BDRV_getVcpUndervoltageSts(void);
static __inline uint8 BDRV_getVcpOvervoltageSts(void);
static __inline uint8 BDRV_getVsdUndervoltageSts(void);
static __inline uint8 BDRV_getVsdOvervoltageSts(void);
static __inline uint8 BDRV_getVcpUndervoltageAnalogCompSts(void);
static __inline uint8 BDRV_getVsdOvervoltageCompSts(void);
static __inline void BDRV_clrExternalLS1MosfetOvercurrentSts(void);
static __inline void BDRV_clrExternalHS1MosfetOvercurrentSts(void);
static __inline void BDRV_clrExternalLS2MosfetOvercurrentSts(void);
static __inline void BDRV_clrExternalHS2MosfetOvercurrentSts(void);
static __inline void BDRV_clrExternalLS3MosfetOvercurrentSts(void);
static __inline void BDRV_clrExternalHS3MosfetOvercurrentSts(void);
static __inline void BDRV_clrLS1DrainSrcMonitoringSts(void);
static __inline void BDRV_clrHS1DrainSrcMonitoringSts(void);
static __inline void BDRV_clrLS2DrainSrcMonitoringSts(void);
static __inline void BDRV_clrHS2DrainSrcMonitoringSts(void);
static __inline void BDRV_clrLS3DrainSrcMonitoringSts(void);
static __inline void BDRV_clrHS3DrainSrcMonitoringSts(void);
static __inline void BDRV_clrCPUndervoltageCompSts(void);
static __inline uint8 BDRV_getExternalLS1MosfetOvercurrentIntSts(void);
static __inline uint8 BDRV_getExternalHS1MosfetOvercurrentIntSts(void);
static __inline uint8 BDRV_getExternalLS2MosfetOvercurrentIntSts(void);
static __inline uint8 BDRV_getExternalHS2MosfetOvercurrentIntSts(void);
static __inline uint8 BDRV_getExternalLS3MosfetOvercurrentIntSts(void);
static __inline uint8 BDRV_getExternalHS3MosfetOvercurrentIntSts(void);
static __inline uint8 BDRV_getLS1DrainSrcMonitoringIntSts(void);
static __inline uint8 BDRV_getHS1DrainSrcMonitoringIntSts(void);
static __inline uint8 BDRV_getLS2DrainSrcMonitoringIntSts(void);
static __inline uint8 BDRV_getHS2DrainSrcMonitoringIntSts(void);
static __inline uint8 BDRV_getLS3DrainSrcMonitoringIntSts(void);
static __inline uint8 BDRV_getHS3DrainSrcMonitoringIntSts(void);
static __inline uint8 BDRV_getHB1AdaptSeqIntSts(void);
static __inline uint8 BDRV_getHB2AdaptSeqIntSts(void);
static __inline uint8 BDRV_getHB3AdaptSeqIntSts(void);
static __inline uint8 BDRV_getHB1ActDrvDetectIntSts(void);
static __inline uint8 BDRV_getHB2ActDrvDetectIntSts(void);
static __inline uint8 BDRV_getHB3ActDrvDetectIntSts(void);
static __inline uint8 BDRV_getDrvSeqErrIntSts(void);
static __inline uint8 BDRV_getCPUndervoltageCompIntSts(void);
static __inline void BDRV_clrExternalLS1MosfetOvercurrentIntSts(void);
static __inline void BDRV_clrExternalHS1MosfetOvercurrentIntSts(void);
static __inline void BDRV_clrExternalLS2MosfetOvercurrentIntSts(void);
static __inline void BDRV_clrExternalHS2MosfetOvercurrentIntSts(void);
static __inline void BDRV_clrExternalLS3MosfetOvercurrentIntSts(void);
static __inline void BDRV_clrExternalHS3MosfetOvercurrentIntSts(void);
static __inline void BDRV_clrLS1DrainSrcMonitoringIntSts(void);
static __inline void BDRV_clrHS1DrainSrcMonitoringIntSts(void);
static __inline void BDRV_clrLS2DrainSrcMonitoringIntSts(void);
static __inline void BDRV_clrHS2DrainSrcMonitoringIntSts(void);
static __inline void BDRV_clrLS3DrainSrcMonitoringIntSts(void);
static __inline void BDRV_clrHS3DrainSrcMonitoringIntSts(void);
static __inline void BDRV_clrHB1AdaptSeqIntSts(void);
static __inline void BDRV_clrHB2AdaptSeqIntSts(void);
static __inline void BDRV_clrHB3AdaptSeqIntSts(void);
static __inline void BDRV_clrHB1ActDrvDetectIntSts(void);
static __inline void BDRV_clrHB2ActDrvDetectIntSts(void);
static __inline void BDRV_clrHB3ActDrvDetectIntSts(void);
static __inline void BDRV_clrDrvSeqErrIntSts(void);
static __inline void BDRV_clrCPUndervoltageCompIntSts(void);
static __inline uint8 BDRV_getHB1MaxT12ONReachedSts(void);
static __inline uint8 BDRV_getHB1MaxI1ONReachedSts(void);
static __inline uint8 BDRV_getHB1MinT12ONReachedSts(void);
static __inline uint8 BDRV_getHB1MinI1ONReachedSts(void);
static __inline uint8 BDRV_getHB1AdaptSeqChrgMeasFailSts(void);
static __inline uint8 BDRV_getHB1ChrgFailDrvSts(void);
static __inline uint8 BDRV_getHB2MaxT12ONReachedSts(void);
static __inline uint8 BDRV_getHB2MaxI1ONReachedSts(void);
static __inline uint8 BDRV_getHB2MinT12ONReachedSts(void);
static __inline uint8 BDRV_getHB2MinI1ONReachedSts(void);
static __inline uint8 BDRV_getHB2AdaptSeqChrgMeasFailSts(void);
static __inline uint8 BDRV_getHB2ChrgFailDrvSts(void);
static __inline uint8 BDRV_getHB3MaxT12ONReachedSts(void);
static __inline uint8 BDRV_getHB3MaxI1ONReachedSts(void);
static __inline uint8 BDRV_getHB3MinT12ONReachedSts(void);
static __inline uint8 BDRV_getHB3MinI1ONReachedSts(void);
static __inline uint8 BDRV_getHB3AdaptSeqChrgMeasFailSts(void);
static __inline uint8 BDRV_getHB3ChrgFailDrvSts(void);
static __inline uint8 BDRV_getHB1MaxT1OFFReachedSts(void);
static __inline uint8 BDRV_getHB1MaxI1OFFReachedSts(void);
static __inline uint8 BDRV_getHB1MinT1OFFReachedSts(void);
static __inline uint8 BDRV_getHB1MinI1OFFReachedSts(void);
static __inline uint8 BDRV_getHB1AdaptSeqDischrgMeasFailSts(void);
static __inline uint8 BDRV_getHB1DischrgFailDrvSts(void);
static __inline uint8 BDRV_getHB2MaxT1OFFReachedSts(void);
static __inline uint8 BDRV_getHB2MaxI1OFFReachedSts(void);
static __inline uint8 BDRV_getHB2MinT1OFFReachedSts(void);
static __inline uint8 BDRV_getHB2MinI1OFFReachedSts(void);
static __inline uint8 BDRV_getHB2AdaptSeqDischrgMeasFailSts(void);
static __inline uint8 BDRV_getHB2DischrgFailDrvSts(void);
static __inline uint8 BDRV_getHB3MaxT1OFFReachedSts(void);
static __inline uint8 BDRV_getHB3MaxI1OFFReachedSts(void);
static __inline uint8 BDRV_getHB3MinT1OFFReachedSts(void);
static __inline uint8 BDRV_getHB3MinI1OFFReachedSts(void);
static __inline uint8 BDRV_getHB3AdaptSeqDischrgMeasFailSts(void);
static __inline uint8 BDRV_getHB3DischrgFailDrvSts(void);
static __inline uint8 BDRV_getHB1ChrgDlyTime(void);
static __inline uint8 BDRV_getHB1ChrgPhase1Current(void);
static __inline uint8 BDRV_getHB1ChrgSlopeTime(void);
static __inline uint8 BDRV_getHB1ChrgSlopeTimeMeasErr(void);
static __inline uint8 BDRV_getHB1ChrgActiveDrv(void);
static __inline void BDRV_clrHB1ChrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB1ChrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB1DischrgDlyTime(void);
static __inline uint8 BDRV_getHB1DischrgPhase1Current(void);
static __inline uint8 BDRV_getHB1DischrgSlopeTime(void);
static __inline uint8 BDRV_getHB1DischrgSlopeTimeMeasErr(void);
static __inline uint8 BDRV_getHB1DischrgActiveDrv(void);
static __inline void BDRV_clrHB1DischrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB1DischrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB2ChrgDlyTime(void);
static __inline uint8 BDRV_getHB2ChrgPhase1Current(void);
static __inline uint8 BDRV_getHB2ChrgSlopeTime(void);
static __inline uint8 BDRV_getHB2ChrgSlopeTimeMeasErr(void);
static __inline uint8 BDRV_getHB2ChrgActiveDrv(void);
static __inline void BDRV_clrHB2ChrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB2ChrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB2DischrgDlyTime(void);
static __inline uint8 BDRV_getHB2DischrgPhase1Current(void);
static __inline uint8 BDRV_getHB2DischrgSlopeTime(void);
static __inline uint8 BDRV_getHB2DischrgSlopeTimeMeasErr(void);
static __inline uint8 BDRV_getHB2DischrgActiveDrv(void);
static __inline void BDRV_clrHB2DischrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB2DischrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB3ChrgDlyTime(void);
static __inline uint8 BDRV_getHB3ChrgPhase1Current(void);
static __inline uint8 BDRV_getHB3ChrgSlopeTime(void);
static __inline uint8 BDRV_getHB3ChrgSlopeTimeMeasErr(void);
static __inline uint8 BDRV_getHB3ChrgActiveDrv(void);
static __inline void BDRV_clrHB3ChrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB3ChrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB3DischrgDlyTime(void);
static __inline uint8 BDRV_getHB3DischrgPhase1Current(void);
static __inline uint8 BDRV_getHB3DischrgSlopeTime(void);
static __inline uint8 BDRV_getHB3DischrgSlopeTimeMeasErr(void);
static __inline uint8 BDRV_getHB3DischrgActiveDrv(void);
static __inline void BDRV_clrHB3DischrgTimeMeasValidSts(void);
static __inline uint8 BDRV_getHB3DischrgTimeMeasValidSts(void);



static __inline void BDRV_enPh1ZCFallInt(void);
static __inline void BDRV_enPh1ZCRiseInt(void);
static __inline void BDRV_enPh2ZCFallInt(void);
static __inline void BDRV_enPh2ZCRiseInt(void);
static __inline void BDRV_enPh3ZCFallInt(void);
static __inline void BDRV_enPh3ZCRiseInt(void);
static __inline void BDRV_disPh1ZCFallInt(void);
static __inline void BDRV_disPh1ZCRiseInt(void);
static __inline void BDRV_disPh2ZCFallInt(void);
static __inline void BDRV_disPh2ZCRiseInt(void);
static __inline void BDRV_disPh3ZCFallInt(void);
static __inline void BDRV_disPh3ZCRiseInt(void);
static __inline uint8 BDRV_getPh1ZCCompSts(void);
static __inline uint8 BDRV_getPh2ZCCompSts(void);
static __inline uint8 BDRV_getPh3ZCCompSts(void);
static __inline uint8 BDRV_getPh1ZCFallIntSts(void);
static __inline uint8 BDRV_getPh1ZCRiseIntSts(void);
static __inline uint8 BDRV_getPh2ZCFallIntSts(void);
static __inline uint8 BDRV_getPh2ZCRiseIntSts(void);
static __inline uint8 BDRV_getPh3ZCFallIntSts(void);
static __inline uint8 BDRV_getPh3ZCRiseIntSts(void);
static __inline void BDRV_clrPh1ZCFallIntSts(void);
static __inline void BDRV_clrPh1ZCRiseIntSts(void);
static __inline void BDRV_clrPh2ZCFallIntSts(void);
static __inline void BDRV_clrPh2ZCRiseIntSts(void);
static __inline void BDRV_clrPh3ZCFallIntSts(void);
static __inline void BDRV_clrPh3ZCRiseIntSts(void);
# 609 "./RTE/Device/TLE9893_2QKW62S/bdrv.h"
void BDRV_setExternalLS1MosfetOvercurrentIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setExternalHS1MosfetOvercurrentIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setExternalLS2MosfetOvercurrentIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setExternalHS2MosfetOvercurrentIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setExternalLS3MosfetOvercurrentIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setExternalHS3MosfetOvercurrentIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setLS1DrainSrcMonitoringIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHS1DrainSrcMonitoringIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setLS2DrainSrcMonitoringIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHS2DrainSrcMonitoringIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setLS3DrainSrcMonitoringIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHS3DrainSrcMonitoringIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHB1AdaptSeqIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHB2AdaptSeqIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHB3AdaptSeqIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHB1ActDrvDetectIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHB2ActDrvDetectIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setHB3ActDrvDetectIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setDrvSeqErrIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));






void BDRV_setPh1ZCFallIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setPh2ZCFallIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setPh3ZCFallIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setPh1ZCRiseIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setPh2ZCRiseIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void BDRV_setPh3ZCRiseIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));
# 741 "./RTE/Device/TLE9893_2QKW62S/bdrv.h"
static __inline void BDRV_enExternalLS1MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS1_OC_IEN = 1u;
}



static __inline void BDRV_enExternalHS1MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS1_OC_IEN = 1u;
}



static __inline void BDRV_enExternalLS2MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS2_OC_IEN = 1u;
}



static __inline void BDRV_enExternalHS2MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS2_OC_IEN = 1u;
}



static __inline void BDRV_enExternalLS3MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS3_OC_IEN = 1u;
}



static __inline void BDRV_enExternalHS3MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS3_OC_IEN = 1u;
}



static __inline void BDRV_enLS1DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS1_DS_IEN = 1u;
}



static __inline void BDRV_enHS1DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS1_DS_IEN = 1u;
}



static __inline void BDRV_enLS2DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS2_DS_IEN = 1u;
}



static __inline void BDRV_enHS2DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS2_DS_IEN = 1u;
}



static __inline void BDRV_enLS3DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS3_DS_IEN = 1u;
}



static __inline void BDRV_enHS3DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS3_DS_IEN = 1u;
}



static __inline void BDRV_enHB1AdaptSeqInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB1_ASEQ_IEN = 1u;
}



static __inline void BDRV_enHB2AdaptSeqInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB2_ASEQ_IEN = 1u;
}



static __inline void BDRV_enHB3AdaptSeqInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB3_ASEQ_IEN = 1u;
}



static __inline void BDRV_enHB1ActDrvDetectInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB1_ACTDRV_IEN = 1u;
}



static __inline void BDRV_enHB2ActDrvDetectInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB2_ACTDRV_IEN = 1u;
}



static __inline void BDRV_enHB3ActDrvDetectInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB3_ACTDRV_IEN = 1u;
}



static __inline void BDRV_enDrvSeqErrInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.SEQ_ERR_IEN = 1u;
}



static __inline void BDRV_enCPUndervoltageCompInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.VCP_LOTH2_IEN = 1u;
}



static __inline void BDRV_disExternalLS1MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS1_OC_IEN = 0u;
}



static __inline void BDRV_disExternalHS1MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS1_OC_IEN = 0u;
}



static __inline void BDRV_disExternalLS2MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS2_OC_IEN = 0u;
}



static __inline void BDRV_disExternalHS2MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS2_OC_IEN = 0u;
}



static __inline void BDRV_disExternalLS3MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS3_OC_IEN = 0u;
}



static __inline void BDRV_disExternalHS3MosfetOvercurrentInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS3_OC_IEN = 0u;
}



static __inline void BDRV_disLS1DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS1_DS_IEN = 0u;
}



static __inline void BDRV_disHS1DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS1_DS_IEN = 0u;
}



static __inline void BDRV_disLS2DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS2_DS_IEN = 0u;
}



static __inline void BDRV_disHS2DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS2_DS_IEN = 0u;
}



static __inline void BDRV_disLS3DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.LS3_DS_IEN = 0u;
}



static __inline void BDRV_disHS3DrainSrcMonitoringInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HS3_DS_IEN = 0u;
}



static __inline void BDRV_disHB1AdaptSeqInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB1_ASEQ_IEN = 0u;
}



static __inline void BDRV_disHB2AdaptSeqInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB2_ASEQ_IEN = 0u;
}



static __inline void BDRV_disHB3AdaptSeqInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB3_ASEQ_IEN = 0u;
}



static __inline void BDRV_disHB1ActDrvDetectInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB1_ACTDRV_IEN = 0u;
}



static __inline void BDRV_disHB2ActDrvDetectInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB2_ACTDRV_IEN = 0u;
}



static __inline void BDRV_disHB3ActDrvDetectInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.HB3_ACTDRV_IEN = 0u;
}



static __inline void BDRV_disDrvSeqErrInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.SEQ_ERR_IEN = 0u;
}



static __inline void BDRV_disCPUndervoltageCompInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQEN.bit.VCP_LOTH2_IEN = 0u;
}





static __inline uint8 BDRV_getExternalLS1MosfetOvercurrentSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.LS1_OC_STS;
}





static __inline uint8 BDRV_getExternalHS1MosfetOvercurrentSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.HS1_OC_STS;
}





static __inline uint8 BDRV_getExternalLS2MosfetOvercurrentSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.LS2_OC_STS;
}





static __inline uint8 BDRV_getExternalHS2MosfetOvercurrentSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.HS2_OC_STS;
}





static __inline uint8 BDRV_getExternalLS3MosfetOvercurrentSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.LS3_OC_STS;
}





static __inline uint8 BDRV_getExternalHS3MosfetOvercurrentSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.HS3_OC_STS;
}





static __inline uint8 BDRV_getLS1DrainSrcMonitoringSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.LS1_DS_STS;
}





static __inline uint8 BDRV_getHS1DrainSrcMonitoringSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.HS1_DS_STS;
}





static __inline uint8 BDRV_getLS2DrainSrcMonitoringSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.LS2_DS_STS;
}





static __inline uint8 BDRV_getHS2DrainSrcMonitoringSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.HS2_DS_STS;
}





static __inline uint8 BDRV_getLS3DrainSrcMonitoringSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.LS3_DS_STS;
}





static __inline uint8 BDRV_getHS3DrainSrcMonitoringSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.HS3_DS_STS;
}





static __inline uint8 BDRV_getSH1UndervoltageCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.SH1_LOW_STS;
}





static __inline uint8 BDRV_getSH1OvervoltageCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.SH1_HIGH_STS;
}





static __inline uint8 BDRV_getSH2UndervoltageCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.SH2_LOW_STS;
}





static __inline uint8 BDRV_getSH2OvervoltageCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.SH2_HIGH_STS;
}





static __inline uint8 BDRV_getSH3UndervoltageCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.SH3_LOW_STS;
}





static __inline uint8 BDRV_getSH3OvervoltageCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.SH3_HIGH_STS;
}





static __inline uint8 BDRV_getCPOverTempSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.CP_OTSD_STS;
}





static __inline uint8 BDRV_getVcpUndervoltageSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.VCP_LOTH1_STS;
}





static __inline uint8 BDRV_getVcpOvervoltageSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.VCP_UPTH_STS;
}





static __inline uint8 BDRV_getVsdUndervoltageSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.VSD_LOTH_STS;
}





static __inline uint8 BDRV_getVsdOvervoltageSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.VSD_UPTH_STS;
}





static __inline uint8 BDRV_getVcpUndervoltageAnalogCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.VCP_LOTH2_STS;
}





static __inline uint8 BDRV_getVsdOvervoltageCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->STS.bit.VSD_OV_STS;
}



static __inline void BDRV_clrExternalLS1MosfetOvercurrentSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.LS1_OC_SC = 1u;
}



static __inline void BDRV_clrExternalHS1MosfetOvercurrentSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.HS1_OC_SC = 1u;
}



static __inline void BDRV_clrExternalLS2MosfetOvercurrentSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.LS2_OC_SC = 1u;
}



static __inline void BDRV_clrExternalHS2MosfetOvercurrentSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.HS2_OC_SC = 1u;
}



static __inline void BDRV_clrExternalLS3MosfetOvercurrentSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.LS3_OC_SC = 1u;
}



static __inline void BDRV_clrExternalHS3MosfetOvercurrentSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.HS3_OC_SC = 1u;
}



static __inline void BDRV_clrLS1DrainSrcMonitoringSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.LS1_DS_SC = 1u;
}



static __inline void BDRV_clrHS1DrainSrcMonitoringSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.HS1_DS_SC = 1u;
}



static __inline void BDRV_clrLS2DrainSrcMonitoringSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.LS2_DS_SC = 1u;
}



static __inline void BDRV_clrHS2DrainSrcMonitoringSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.HS2_DS_SC = 1u;
}



static __inline void BDRV_clrLS3DrainSrcMonitoringSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.LS3_DS_SC = 1u;
}



static __inline void BDRV_clrHS3DrainSrcMonitoringSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.HS3_DS_SC = 1u;
}



static __inline void BDRV_clrCPUndervoltageCompSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->STSCLR.bit.VCP_LOTH2_SC = 1u;
}





static __inline uint8 BDRV_getExternalLS1MosfetOvercurrentIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.LS1_OC_IS;
}





static __inline uint8 BDRV_getExternalHS1MosfetOvercurrentIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HS1_OC_IS;
}





static __inline uint8 BDRV_getExternalLS2MosfetOvercurrentIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.LS2_OC_IS;
}





static __inline uint8 BDRV_getExternalHS2MosfetOvercurrentIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HS2_OC_IS;
}





static __inline uint8 BDRV_getExternalLS3MosfetOvercurrentIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.LS3_OC_IS;
}





static __inline uint8 BDRV_getExternalHS3MosfetOvercurrentIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HS3_OC_IS;
}





static __inline uint8 BDRV_getLS1DrainSrcMonitoringIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.LS1_DS_IS;
}





static __inline uint8 BDRV_getHS1DrainSrcMonitoringIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HS1_DS_IS;
}





static __inline uint8 BDRV_getLS2DrainSrcMonitoringIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.LS2_DS_IS;
}





static __inline uint8 BDRV_getHS2DrainSrcMonitoringIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HS2_DS_IS;
}





static __inline uint8 BDRV_getLS3DrainSrcMonitoringIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.LS3_DS_IS;
}





static __inline uint8 BDRV_getHS3DrainSrcMonitoringIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HS3_DS_IS;
}





static __inline uint8 BDRV_getHB1AdaptSeqIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HB1_ASEQ_IS;
}





static __inline uint8 BDRV_getHB2AdaptSeqIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HB2_ASEQ_IS;
}





static __inline uint8 BDRV_getHB3AdaptSeqIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HB3_ASEQ_IS;
}





static __inline uint8 BDRV_getHB1ActDrvDetectIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HB1_ACTDRV_IS;
}





static __inline uint8 BDRV_getHB2ActDrvDetectIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HB2_ACTDRV_IS;
}





static __inline uint8 BDRV_getHB3ActDrvDetectIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.HB3_ACTDRV_IS;
}





static __inline uint8 BDRV_getDrvSeqErrIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.SEQ_ERR_IS;
}





static __inline uint8 BDRV_getCPUndervoltageCompIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->IRQS.bit.VCP_LOTH2_IS;
}



static __inline void BDRV_clrExternalLS1MosfetOvercurrentIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.LS1_OC_ISC = 1u;
}



static __inline void BDRV_clrExternalHS1MosfetOvercurrentIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HS1_OC_ISC = 1u;
}



static __inline void BDRV_clrExternalLS2MosfetOvercurrentIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.LS2_OC_ISC = 1u;
}



static __inline void BDRV_clrExternalHS2MosfetOvercurrentIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HS2_OC_ISC = 1u;
}



static __inline void BDRV_clrExternalLS3MosfetOvercurrentIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.LS3_OC_ISC = 1u;
}



static __inline void BDRV_clrExternalHS3MosfetOvercurrentIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HS3_OC_ISC = 1u;
}



static __inline void BDRV_clrLS1DrainSrcMonitoringIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.LS1_DS_ISC = 1u;
}



static __inline void BDRV_clrHS1DrainSrcMonitoringIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HS1_DS_ISC = 1u;
}



static __inline void BDRV_clrLS2DrainSrcMonitoringIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.LS2_DS_ISC = 1u;
}



static __inline void BDRV_clrHS2DrainSrcMonitoringIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HS2_DS_ISC = 1u;
}



static __inline void BDRV_clrLS3DrainSrcMonitoringIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.LS3_DS_ISC = 1u;
}



static __inline void BDRV_clrHS3DrainSrcMonitoringIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HS3_DS_ISC = 1u;
}



static __inline void BDRV_clrHB1AdaptSeqIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HB1_ASEQ_ISC = 1u;
}



static __inline void BDRV_clrHB2AdaptSeqIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HB2_ASEQ_ISC = 1u;
}



static __inline void BDRV_clrHB3AdaptSeqIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HB3_ASEQ_ISC = 1u;
}



static __inline void BDRV_clrHB1ActDrvDetectIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HB1_ACTDRV_ISC = 1u;
}



static __inline void BDRV_clrHB2ActDrvDetectIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HB2_ACTDRV_ISC = 1u;
}



static __inline void BDRV_clrHB3ActDrvDetectIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.HB3_ACTDRV_ISC = 1u;
}



static __inline void BDRV_clrDrvSeqErrIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.SEQ_ERR_ISC = 1u;
}



static __inline void BDRV_clrCPUndervoltageCompIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->IRQCLR.bit.VCP_LOTH2_ISC = 1u;
}





static __inline uint8 BDRV_getHB1MaxT12ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB1T12ONMAX;
}





static __inline uint8 BDRV_getHB1MaxI1ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB1I1ONMAX;
}





static __inline uint8 BDRV_getHB1MinT12ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB1T12ONMIN;
}





static __inline uint8 BDRV_getHB1MinI1ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB1I1ONMIN;
}





static __inline uint8 BDRV_getHB1AdaptSeqChrgMeasFailSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB1ONMF;
}





static __inline uint8 BDRV_getHB1ChrgFailDrvSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB1ONFAILDRV;
}





static __inline uint8 BDRV_getHB2MaxT12ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB2T12ONMAX;
}





static __inline uint8 BDRV_getHB2MaxI1ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB2I1ONMAX;
}





static __inline uint8 BDRV_getHB2MinT12ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB2T12ONMIN;
}





static __inline uint8 BDRV_getHB2MinI1ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB2I1ONMIN;
}





static __inline uint8 BDRV_getHB2AdaptSeqChrgMeasFailSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB2ONMF;
}





static __inline uint8 BDRV_getHB2ChrgFailDrvSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB2ONFAILDRV;
}





static __inline uint8 BDRV_getHB3MaxT12ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB3T12ONMAX;
}





static __inline uint8 BDRV_getHB3MaxI1ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB3I1ONMAX;
}





static __inline uint8 BDRV_getHB3MinT12ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB3T12ONMIN;
}





static __inline uint8 BDRV_getHB3MinI1ONReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB3I1ONMIN;
}





static __inline uint8 BDRV_getHB3AdaptSeqChrgMeasFailSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB3ONMF;
}





static __inline uint8 BDRV_getHB3ChrgFailDrvSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQONSTS.bit.HB3ONFAILDRV;
}





static __inline uint8 BDRV_getHB1MaxT1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB1T1OFFMAX;
}





static __inline uint8 BDRV_getHB1MaxI1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB1I1OFFMAX;
}





static __inline uint8 BDRV_getHB1MinT1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB1T1OFFMIN;
}





static __inline uint8 BDRV_getHB1MinI1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB1I1OFFMIN;
}





static __inline uint8 BDRV_getHB1AdaptSeqDischrgMeasFailSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB1OFFMF;
}





static __inline uint8 BDRV_getHB1DischrgFailDrvSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB1OFFFAILDRV;
}





static __inline uint8 BDRV_getHB2MaxT1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB2T1OFFMAX;
}





static __inline uint8 BDRV_getHB2MaxI1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB2I1OFFMAX;
}





static __inline uint8 BDRV_getHB2MinT1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB2T1OFFMIN;
}





static __inline uint8 BDRV_getHB2MinI1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB2I1OFFMIN;
}





static __inline uint8 BDRV_getHB2AdaptSeqDischrgMeasFailSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB2OFFMF;
}





static __inline uint8 BDRV_getHB2DischrgFailDrvSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB2OFFFAILDRV;
}





static __inline uint8 BDRV_getHB3MaxT1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB3T1OFFMAX;
}





static __inline uint8 BDRV_getHB3MaxI1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB3I1OFFMAX;
}





static __inline uint8 BDRV_getHB3MinT1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB3T1OFFMIN;
}





static __inline uint8 BDRV_getHB3MinI1OFFReachedSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB3I1OFFMIN;
}





static __inline uint8 BDRV_getHB3AdaptSeqDischrgMeasFailSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB3OFFMF;
}





static __inline uint8 BDRV_getHB3DischrgFailDrvSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->ASEQOFFSTS.bit.HB3OFFFAILDRV;
}





static __inline uint8 BDRV_getHB1ChrgDlyTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1ONVAL.bit.HB1_TONDLY;
}





static __inline uint8 BDRV_getHB1ChrgPhase1Current(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1ONVAL.bit.HB1_I1ONVAL;
}





static __inline uint8 BDRV_getHB1ChrgSlopeTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1ONVAL.bit.HB1_TONDUR;
}





static __inline uint8 BDRV_getHB1ChrgSlopeTimeMeasErr(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1ONVAL.bit.HB1_TONDURMERR;
}





static __inline uint8 BDRV_getHB1ChrgActiveDrv(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1ONVAL.bit.HB1_ACTDRV_ON;
}



static __inline void BDRV_clrHB1ChrgTimeMeasValidSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->HB1ONVAL.bit.HB1_ONVALVF_CLR = 1u;
}





static __inline uint8 BDRV_getHB1ChrgTimeMeasValidSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1ONVAL.bit.HB1_ONVALVF;
}





static __inline uint8 BDRV_getHB1DischrgDlyTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1OFFVAL.bit.HB1_TOFFDLY;
}





static __inline uint8 BDRV_getHB1DischrgPhase1Current(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1OFFVAL.bit.HB1_I1OFFVAL;
}





static __inline uint8 BDRV_getHB1DischrgSlopeTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1OFFVAL.bit.HB1_TOFFDUR;
}





static __inline uint8 BDRV_getHB1DischrgSlopeTimeMeasErr(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1OFFVAL.bit.HB1_TOFFDURMERR;
}





static __inline uint8 BDRV_getHB1DischrgActiveDrv(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1OFFVAL.bit.HB1_ACTDRV_OFF;
}



static __inline void BDRV_clrHB1DischrgTimeMeasValidSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->HB1OFFVAL.bit.HB1_OFFVALVF_CLR = 1u;
}





static __inline uint8 BDRV_getHB1DischrgTimeMeasValidSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB1OFFVAL.bit.HB1_OFFVALVF;
}





static __inline uint8 BDRV_getHB2ChrgDlyTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2ONVAL.bit.HB2_TONDLY;
}





static __inline uint8 BDRV_getHB2ChrgPhase1Current(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2ONVAL.bit.HB2_I1ONVAL;
}





static __inline uint8 BDRV_getHB2ChrgSlopeTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2ONVAL.bit.HB2_TONDUR;
}





static __inline uint8 BDRV_getHB2ChrgSlopeTimeMeasErr(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2ONVAL.bit.HB2_TONDURMERR;
}





static __inline uint8 BDRV_getHB2ChrgActiveDrv(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2ONVAL.bit.HB2_ACTDRV_ON;
}



static __inline void BDRV_clrHB2ChrgTimeMeasValidSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->HB2ONVAL.bit.HB2_ONVALVF_CLR = 1u;
}





static __inline uint8 BDRV_getHB2ChrgTimeMeasValidSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2ONVAL.bit.HB2_ONVALVF;
}





static __inline uint8 BDRV_getHB2DischrgDlyTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2OFFVAL.bit.HB2_TOFFDLY;
}





static __inline uint8 BDRV_getHB2DischrgPhase1Current(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2OFFVAL.bit.HB2_I1OFFVAL;
}





static __inline uint8 BDRV_getHB2DischrgSlopeTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2OFFVAL.bit.HB2_TOFFDUR;
}





static __inline uint8 BDRV_getHB2DischrgSlopeTimeMeasErr(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2OFFVAL.bit.HB2_TOFFDURMERR;
}





static __inline uint8 BDRV_getHB2DischrgActiveDrv(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2OFFVAL.bit.HB2_ACTDRV_OFF;
}



static __inline void BDRV_clrHB2DischrgTimeMeasValidSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->HB2OFFVAL.bit.HB2_OFFVALVF_CLR = 1u;
}





static __inline uint8 BDRV_getHB2DischrgTimeMeasValidSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB2OFFVAL.bit.HB2_OFFVALVF;
}





static __inline uint8 BDRV_getHB3ChrgDlyTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3ONVAL.bit.HB3_TONDLY;
}





static __inline uint8 BDRV_getHB3ChrgPhase1Current(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3ONVAL.bit.HB3_I1ONVAL;
}





static __inline uint8 BDRV_getHB3ChrgSlopeTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3ONVAL.bit.HB3_TONDUR;
}





static __inline uint8 BDRV_getHB3ChrgSlopeTimeMeasErr(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3ONVAL.bit.HB3_TONDURMERR;
}





static __inline uint8 BDRV_getHB3ChrgActiveDrv(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3ONVAL.bit.HB3_ACTDRV_ON;
}



static __inline void BDRV_clrHB3ChrgTimeMeasValidSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->HB3ONVAL.bit.HB3_ONVALVF_CLR = 1u;
}





static __inline uint8 BDRV_getHB3ChrgTimeMeasValidSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3ONVAL.bit.HB3_ONVALVF;
}





static __inline uint8 BDRV_getHB3DischrgDlyTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3OFFVAL.bit.HB3_TOFFDLY;
}





static __inline uint8 BDRV_getHB3DischrgPhase1Current(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3OFFVAL.bit.HB3_I1OFFVAL;
}





static __inline uint8 BDRV_getHB3DischrgSlopeTime(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3OFFVAL.bit.HB3_TOFFDUR;
}





static __inline uint8 BDRV_getHB3DischrgSlopeTimeMeasErr(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3OFFVAL.bit.HB3_TOFFDURMERR;
}





static __inline uint8 BDRV_getHB3DischrgActiveDrv(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3OFFVAL.bit.HB3_ACTDRV_OFF;
}



static __inline void BDRV_clrHB3DischrgTimeMeasValidSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->HB3OFFVAL.bit.HB3_OFFVALVF_CLR = 1u;
}





static __inline uint8 BDRV_getHB3DischrgTimeMeasValidSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->HB3OFFVAL.bit.HB3_OFFVALVF;
}





static __inline void BDRV_enPh1ZCFallInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH1_ZCFALL_IEN = 1u;
}



static __inline void BDRV_enPh1ZCRiseInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH1_ZCRISE_IEN = 1u;
}



static __inline void BDRV_enPh2ZCFallInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH2_ZCFALL_IEN = 1u;
}



static __inline void BDRV_enPh2ZCRiseInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH2_ZCRISE_IEN = 1u;
}



static __inline void BDRV_enPh3ZCFallInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH3_ZCFALL_IEN = 1u;
}



static __inline void BDRV_enPh3ZCRiseInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH3_ZCRISE_IEN = 1u;
}



static __inline void BDRV_disPh1ZCFallInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH1_ZCFALL_IEN = 0u;
}



static __inline void BDRV_disPh1ZCRiseInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH1_ZCRISE_IEN = 0u;
}



static __inline void BDRV_disPh2ZCFallInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH2_ZCFALL_IEN = 0u;
}



static __inline void BDRV_disPh2ZCRiseInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH2_ZCRISE_IEN = 0u;
}



static __inline void BDRV_disPh3ZCFallInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH3_ZCFALL_IEN = 0u;
}



static __inline void BDRV_disPh3ZCRiseInt(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQEN.bit.PH3_ZCRISE_IEN = 0u;
}





static __inline uint8 BDRV_getPh1ZCCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_CTRL.bit.PH1_ZC_STS;
}





static __inline uint8 BDRV_getPh2ZCCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_CTRL.bit.PH2_ZC_STS;
}





static __inline uint8 BDRV_getPh3ZCCompSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_CTRL.bit.PH3_ZC_STS;
}





static __inline uint8 BDRV_getPh1ZCFallIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQS.bit.PH1_ZCFALL_IS;
}





static __inline uint8 BDRV_getPh1ZCRiseIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQS.bit.PH1_ZCRISE_IS;
}





static __inline uint8 BDRV_getPh2ZCFallIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQS.bit.PH2_ZCFALL_IS;
}





static __inline uint8 BDRV_getPh2ZCRiseIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQS.bit.PH2_ZCRISE_IS;
}





static __inline uint8 BDRV_getPh3ZCFallIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQS.bit.PH3_ZCFALL_IS;
}





static __inline uint8 BDRV_getPh3ZCRiseIntSts(void)
{
  return (uint8)((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQS.bit.PH3_ZCRISE_IS;
}



static __inline void BDRV_clrPh1ZCFallIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQCLR.bit.PH1_ZCFALL_ISC = 1u;
}



static __inline void BDRV_clrPh1ZCRiseIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQCLR.bit.PH1_ZCRISE_ISC = 1u;
}



static __inline void BDRV_clrPh2ZCFallIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQCLR.bit.PH2_ZCFALL_ISC = 1u;
}



static __inline void BDRV_clrPh2ZCRiseIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQCLR.bit.PH2_ZCRISE_ISC = 1u;
}



static __inline void BDRV_clrPh3ZCFallIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQCLR.bit.PH3_ZCFALL_ISC = 1u;
}



static __inline void BDRV_clrPh3ZCRiseIntSts(void)
{
  ((BDRV_Type*) 0x4000C000UL)->BEMFC_IRQCLR.bit.PH3_ZCRISE_ISC = 1u;
}
# 137 "./RTE/Device/TLE9893_2QKW62S/scu.h" 2

# 1 "./RTE/Device/TLE9893_2QKW62S/isr.h" 1
# 92 "./RTE/Device/TLE9893_2QKW62S/isr.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/isr.h" 1
# 93 "./RTE/Device/TLE9893_2QKW62S/isr.h" 2
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
# 139 "./RTE/Device/TLE9893_2QKW62S/scu.h" 2
# 1 "./RTE/Device/TLE9893_2QKW62S/pmu.h" 1
# 141 "./RTE/Device/TLE9893_2QKW62S/pmu.h"
# 1 "./RTE/Device/TLE9893_2QKW62S/pmu_defines.h" 1
# 142 "./RTE/Device/TLE9893_2QKW62S/pmu.h" 2

# 1 "./RTE/Device/TLE9893_2QKW62S/scu_defines.h" 1
# 144 "./RTE/Device/TLE9893_2QKW62S/pmu.h" 2
# 203 "./RTE/Device/TLE9893_2QKW62S/pmu.h"
typedef enum PMU_gpioInput
{
  PMU_gpioInput_P0_0 = 0u,
  PMU_gpioInput_P0_1 = 1u,
  PMU_gpioInput_P0_2 = 2u,
  PMU_gpioInput_P0_3 = 3u,
  PMU_gpioInput_P0_4 = 4u,
  PMU_gpioInput_P0_5 = 5u,
  PMU_gpioInput_P0_6 = 6u,
  PMU_gpioInput_P0_7 = 7u,
  PMU_gpioInput_P0_8 = 8u,
  PMU_gpioInput_P0_9 = 9u,
  PMU_gpioInput_P1_0 = 10u,
  PMU_gpioInput_P1_1 = 11u,
  PMU_gpioInput_P1_2 = 12u,
  PMU_gpioInput_P1_3 = 13u,
  PMU_gpioInput_P1_4 = 14u,
  PMU_gpioInput_P2_0 = 15u,
  PMU_gpioInput_P2_1 = 16u,
  PMU_gpioInput_P2_2 = 17u,
  PMU_gpioInput_P2_3 = 18u,
  PMU_gpioInput_P2_4 = 19u,
  PMU_gpioInput_P2_5 = 20u,
  PMU_gpioInput_P2_6 = 21u,
  PMU_gpioInput_P2_7 = 22u,
  PMU_gpioInput_P2_8 = 23u,
  PMU_gpioInput_P2_9 = 24u
} tPMU_gpioInput;





sint8 PMU_init(void);
void PMU_countFailSafeWatchdog(void);
sint8 PMU_initFailSafeWatchdog(void);
void PMU_stopFailSafeWatchdog(void);
sint8 PMU_serviceFailSafeWatchdog(void);
void PMU_clrFailSafeWatchdogFailSts(void);
sint8 PMU_serviceFailSafeWatchdogSOW(void);
static __inline void PMU_enVDDPUndervoltageWarnInt(void);
static __inline void PMU_enVDDPOvervoltageInt(void);
static __inline void PMU_disVDDPUndervoltageWarnInt(void);
static __inline void PMU_disVDDPOvervoltageInt(void);
static __inline uint8 PMU_getVDDPUndervoltageWarnIntSts(void);
static __inline uint8 PMU_getVDDPOvervoltageIntSts(void);
static __inline uint8 PMU_getVDDPUndervoltageWarnSts(void);
static __inline uint8 PMU_getVDDPCurrentLimitSts(void);
static __inline uint8 PMU_getVDDPHighCurrentModeSts(void);
static __inline void PMU_clrVDDPUndervoltageWarnIntSts(void);
static __inline void PMU_clrVDDPOvervoltageIntSts(void);
static __inline void PMU_clrVDDPUndervoltageWarnSts(void);
static __inline void PMU_clrVDDPCurrentLimitSts(void);
static __inline void PMU_clrVDDPHighCurrentModeSts(void);
static __inline void PMU_enVDDCUndervoltageWarnInt(void);
static __inline void PMU_enVDDCOvervoltageInt(void);
static __inline void PMU_disVDDCUndervoltageWarnInt(void);
static __inline void PMU_disVDDCOvervoltageInt(void);
static __inline uint8 PMU_getVDDCUndervoltageWarnIntSts(void);
static __inline uint8 PMU_getVDDCOvervoltageIntSts(void);
static __inline uint8 PMU_getVDDCUndervoltageWarnSts(void);
static __inline uint8 PMU_getVDDCHighCurrentModeSts(void);
static __inline void PMU_clrVDDCUndervoltageWarnIntSts(void);
static __inline void PMU_clrVDDCOvervoltageIntSts(void);
static __inline void PMU_clrVDDCUndervoltageWarnSts(void);
static __inline void PMU_clrVDDCHighCurrentModeSts(void);
static __inline void PMU_enVDDEXTUndervoltageInt(void);
static __inline void PMU_enVDDEXTOvertemperatureInt(void);
static __inline void PMU_disVDDEXTUndervoltageInt(void);
static __inline void PMU_disVDDEXTOvertemperatureInt(void);
static __inline uint8 PMU_getVDDEXTUndervoltageIntSts(void);
static __inline uint8 PMU_getVDDEXTOvertemperatureIntSts(void);
static __inline uint8 PMU_getVDDEXTUndervoltageSts(void);
static __inline uint8 PMU_getVDDEXTOvertemperatureSts(void);
static __inline void PMU_clrVDDEXTUndervoltageIntSts(void);
static __inline void PMU_clrVDDEXTOvertemperatureIntSts(void);
static __inline void PMU_clrVDDEXTUndervoltageSts(void);
static __inline void PMU_clrVDDEXTOvertemperatureSts(void);
static __inline uint8 PMU_getVDDPRegulatorTimeoutSts(void);
static __inline uint8 PMU_getVDDCRegulatorTimeoutSts(void);
static __inline uint8 PMU_getHPClkFailSts(void);
static __inline uint8 PMU_getSysOvertemperatureSts(void);
static __inline uint8 PMU_getSeqWdFailSts(void);
static __inline uint8 PMU_getVDDPRegulatorOvertemperatureSts(void);
static __inline uint8 PMU_getVDDCOvercurrentSts(void);
static __inline void PMU_clrVDDPRegulatorTimeoutSts(void);
static __inline void PMU_clrVDDCRegulatorTimeoutSts(void);
static __inline void PMU_clrHPClkFailSts(void);
static __inline void PMU_clrSysOvertemperatureSts(void);
static __inline void PMU_clrSeqWdFailSts(void);
static __inline void PMU_clrVDDPRegulatorOvertemperatureSts(void);
static __inline void PMU_clrVDDCOvercurrentSts(void);
static __inline uint8 PMU_getMstrSupplyUndervoltageRstSts(void);
static __inline uint8 PMU_getMstrClkWDRstSts(void);
static __inline uint8 PMU_getFailSleepExitRstSts(void);
static __inline uint8 PMU_getSleepExitRstSts(void);
static __inline uint8 PMU_getStopExitRstSts(void);
static __inline uint8 PMU_getPinRstSts(void);
static __inline uint8 PMU_getFailSafeWDRstSts(void);
static __inline uint8 PMU_getWDTimerRstSts(void);
static __inline uint8 PMU_getSoftRstSts(void);
static __inline uint8 PMU_getLockupRstSts(void);
static __inline uint8 PMU_getVDDPUndervoltageRstSts(void);
static __inline uint8 PMU_getVDDCUndervoltageRstSts(void);
static __inline uint8 PMU_getSecureStackOverflowRstSts(void);
static __inline void PMU_clrMstrSupplyUndervoltageRstSts(void);
static __inline void PMU_clrMstrClkWDRstSts(void);
static __inline void PMU_clrFailSleepExitRstSts(void);
static __inline void PMU_clrSleepExitRstSts(void);
static __inline void PMU_clrStopExitRstSts(void);
static __inline void PMU_clrPinRstSts(void);
static __inline void PMU_clrFailSafeWDRstSts(void);
static __inline void PMU_clrWDTimerRstSts(void);
static __inline void PMU_clrSoftRstSts(void);
static __inline void PMU_clrLockupRstSts(void);
static __inline void PMU_clrVDDPUndervoltageRstSts(void);
static __inline void PMU_clrVDDCUndervoltageRstSts(void);
static __inline void PMU_clrSecureStackOverflowRstSts(void);
static __inline sint8 PMU_enWakeupSrc(uint32 u32_wakeupSrc);
static __inline sint8 PMU_disWakeupSrc(uint32 u32_wakeupSrc);
static __inline uint32 PMU_getWakeupSrc(void);
static __inline void PMU_enStopModeVDDCReduct(void);
static __inline void PMU_disStopModeVDDCReduct(void);
static __inline sint8 PMU_setGPIOWakeCfg(uint8 u8_GPIO, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, tPMU_gpioInput e_gpioInput);
static __inline sint8 PMU_setMONWakeCfg(uint8 u8_MON, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, uint8 u8_enPullupCurrSrc, uint8 u8_enPulldownCurrSrc);
static __inline uint8 PMU_getMON1InputSts(void);
static __inline uint8 PMU_getMON2InputSts(void);
static __inline uint8 PMU_getMON3InputSts(void);
static __inline uint8 PMU_getCANWakeSts(void);
static __inline uint8 PMU_getCyclicWakeSts(void);
static __inline uint8 PMU_getGPIO0WakeSts(void);
static __inline uint8 PMU_getGPIO1WakeSts(void);
static __inline uint8 PMU_getGPIO2WakeSts(void);
static __inline uint8 PMU_getGPIO3WakeSts(void);
static __inline uint8 PMU_getGPIO4WakeSts(void);
static __inline uint8 PMU_getGPIO5WakeSts(void);
static __inline uint8 PMU_getMON1WakeSts(void);
static __inline uint8 PMU_getMON2WakeSts(void);
static __inline uint8 PMU_getMON3WakeSts(void);
static __inline uint8 PMU_getVDDPUndervoltageWarnWakeSts(void);
static __inline uint8 PMU_getVDDPOvervoltageWakeSts(void);
static __inline uint8 PMU_getVDDPHighCurrentModeWakeSts(void);
static __inline uint8 PMU_getVDDCUndervoltageWarnWakeSts(void);
static __inline uint8 PMU_getVDDCOvervoltageWakeSts(void);
static __inline uint8 PMU_getVDDCHighCurrentModeWakeSts(void);
static __inline uint8 PMU_getVDDEXTOvertemperatureWakeSts(void);
static __inline uint8 PMU_getVDDEXTUndervoltageWakeSts(void);
static __inline uint8 PMU_getVSDOvervoltageWakeSts(void);
static __inline void PMU_clrCANWakeSts(void);
static __inline void PMU_clrCyclicWakeSts(void);
static __inline void PMU_clrGPIO0WakeSts(void);
static __inline void PMU_clrGPIO1WakeSts(void);
static __inline void PMU_clrGPIO2WakeSts(void);
static __inline void PMU_clrGPIO3WakeSts(void);
static __inline void PMU_clrGPIO4WakeSts(void);
static __inline void PMU_clrGPIO5WakeSts(void);
static __inline void PMU_clrMON1WakeSts(void);
static __inline void PMU_clrMON2WakeSts(void);
static __inline void PMU_clrMON3WakeSts(void);
static __inline void PMU_clrVDDPUndervoltageWarnWakeSts(void);
static __inline void PMU_clrVDDPOvervoltageWakeSts(void);
static __inline void PMU_clrVDDPHighCurrentModeWakeSts(void);
static __inline void PMU_clrVDDCUndervoltageWarnWakeSts(void);
static __inline void PMU_clrVDDCOvervoltageWakeSts(void);
static __inline void PMU_clrVDDCHighCurrentModeWakeSts(void);
static __inline void PMU_clrVDDEXTOvertemperatureWakeSts(void);
static __inline void PMU_clrVDDEXTUndervoltageWakeSts(void);
static __inline void PMU_clrVSDOvervoltageWakeSts(void);
static __inline void PMU_enFailInputPullUp(void);
static __inline void PMU_enStartCfg(void);
static __inline void PMU_enResetPin(void);
static __inline void PMU_disFailInputPullUp(void);
static __inline void PMU_disStartCfg(void);
static __inline void PMU_disResetPin(void);
static __inline uint8 PMU_getMstrClkWDFailSts(void);
static __inline uint8 PMU_getMstrSupplyUndervoltageSts(void);
static __inline uint8 PMU_getMstrSupplyOvervoltageSts(void);
static __inline uint8 PMU_getWDFailSts(void);
static __inline uint8 PMU_getWDSelfTestFailSts(void);
static __inline uint8 PMU_getVDDCUndervoltageSts(void);
static __inline uint8 PMU_getVDDCOvervoltageSts(void);
static __inline uint8 PMU_getVDDPUndervoltageSts(void);
static __inline uint8 PMU_getVDDPOvervoltageSts(void);
static __inline uint8 PMU_getVDDPOvertemperatureSts(void);
static __inline uint8 PMU_getVAREFOvervoltageSts(void);
static __inline uint8 PMU_getCSCOvercurrentSts(void);
static __inline uint8 PMU_getCSCSelfTestFailSts(void);
static __inline uint8 PMU_getCSCEnFailSts(void);
static __inline uint8 PMU_getPinMonitorFailSts(void);
static __inline uint8 PMU_getFOOvercurrentSts(void);
static __inline void PMU_clrMstrClkWDFailSts(void);
static __inline void PMU_clrMstrSupplyUndervoltageSts(void);
static __inline void PMU_clrMstrSupplyOvervoltageSts(void);
static __inline void PMU_clrWDFailSts(void);
static __inline void PMU_clrWDSelfTestFailSts(void);
static __inline void PMU_clrVDDCUndervoltageSts(void);
static __inline void PMU_clrVDDCOvervoltageSts(void);
static __inline void PMU_clrVDDPUndervoltageSts(void);
static __inline void PMU_clrVDDPOvervoltageSts(void);
static __inline void PMU_clrVDDPOvertemperatureSts(void);
static __inline void PMU_clrVAREFOvervoltageSts(void);
static __inline void PMU_clrCSCOvercurrentSts(void);
static __inline void PMU_clrCSCSelfTestFailSts(void);
static __inline void PMU_clrCSCEnFailSts(void);
static __inline void PMU_clrPinMonitorFailSts(void);
static __inline void PMU_clrFOOvercurrentSts(void);
static __inline uint8 PMU_getSafeShutdownSts(void);
static __inline uint8 PMU_getFailOutputSts(void);
static __inline void PMU_clrSafeShutdownSts(void);
static __inline void PMU_clrFailOutputSts(void);
# 421 "./RTE/Device/TLE9893_2QKW62S/pmu.h"
void PMU_setVDDPUndervoltageWarnIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void PMU_setVDDPOvervoltageIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void PMU_setVDDCUndervoltageWarnIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void PMU_setVDDCOvervoltageIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void PMU_setVDDEXTUndervoltageIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));




void PMU_setVDDEXTOvertemperatureIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));







static __inline void PMU_enVDDPUndervoltageWarnInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_IRQEN.bit.UVWARN_IEN = 1u;
}



static __inline void PMU_enVDDPOvervoltageInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_IRQEN.bit.OV_IEN = 1u;
}



static __inline void PMU_disVDDPUndervoltageWarnInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_IRQEN.bit.UVWARN_IEN = 0u;
}



static __inline void PMU_disVDDPOvervoltageInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_IRQEN.bit.OV_IEN = 0u;
}





static __inline uint8 PMU_getVDDPUndervoltageWarnIntSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDP_STS.bit.UVWARN_IS;
}





static __inline uint8 PMU_getVDDPOvervoltageIntSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDP_STS.bit.OV_IS;
}





static __inline uint8 PMU_getVDDPUndervoltageWarnSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDP_STS.bit.UVWARN_STS;
}





static __inline uint8 PMU_getVDDPCurrentLimitSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDP_STS.bit.ILIM_STS;
}





static __inline uint8 PMU_getVDDPHighCurrentModeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDP_STS.bit.HCM_STS;
}



static __inline void PMU_clrVDDPUndervoltageWarnIntSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_STS_CLR.bit.UVWARN_IS_CLR = 1u;
}



static __inline void PMU_clrVDDPOvervoltageIntSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_STS_CLR.bit.OV_IS_CLR = 1u;
}



static __inline void PMU_clrVDDPUndervoltageWarnSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_STS_CLR.bit.UVWARN_STS_CLR = 1u;
}



static __inline void PMU_clrVDDPCurrentLimitSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_STS_CLR.bit.ILIM_STS_CLR = 1u;
}



static __inline void PMU_clrVDDPHighCurrentModeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDP_STS_CLR.bit.HCM_STS_CLR = 1u;
}



static __inline void PMU_enVDDCUndervoltageWarnInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_IRQEN.bit.UVWARN_IEN = 1u;
}



static __inline void PMU_enVDDCOvervoltageInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_IRQEN.bit.OV_IEN = 1u;
}



static __inline void PMU_disVDDCUndervoltageWarnInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_IRQEN.bit.UVWARN_IEN = 0u;
}



static __inline void PMU_disVDDCOvervoltageInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_IRQEN.bit.OV_IEN = 0u;
}





static __inline uint8 PMU_getVDDCUndervoltageWarnIntSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDC_STS.bit.UVWARN_IS;
}





static __inline uint8 PMU_getVDDCOvervoltageIntSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDC_STS.bit.OV_IS;
}





static __inline uint8 PMU_getVDDCUndervoltageWarnSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDC_STS.bit.UVWARN_STS;
}





static __inline uint8 PMU_getVDDCHighCurrentModeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDC_STS.bit.HCM_STS;
}



static __inline void PMU_clrVDDCUndervoltageWarnIntSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_STS_CLR.bit.UVWARN_IS_CLR = 1u;
}



static __inline void PMU_clrVDDCOvervoltageIntSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_STS_CLR.bit.OV_IS_CLR = 1u;
}



static __inline void PMU_clrVDDCUndervoltageWarnSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_STS_CLR.bit.UVWARN_STS_CLR = 1u;
}



static __inline void PMU_clrVDDCHighCurrentModeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDC_STS_CLR.bit.HCM_STS_CLR = 1u;
}



static __inline void PMU_enVDDEXTUndervoltageInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_IRQEN.bit.UV_IEN = 1u;
}



static __inline void PMU_enVDDEXTOvertemperatureInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_IRQEN.bit.OT_IEN = 1u;
}



static __inline void PMU_disVDDEXTUndervoltageInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_IRQEN.bit.UV_IEN = 0u;
}



static __inline void PMU_disVDDEXTOvertemperatureInt(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_IRQEN.bit.OT_IEN = 0u;
}





static __inline uint8 PMU_getVDDEXTUndervoltageIntSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDEXT_STS.bit.UV_IS;
}





static __inline uint8 PMU_getVDDEXTOvertemperatureIntSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDEXT_STS.bit.OT_IS;
}





static __inline uint8 PMU_getVDDEXTUndervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDEXT_STS.bit.UV_STS;
}





static __inline uint8 PMU_getVDDEXTOvertemperatureSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->VDDEXT_STS.bit.OT_STS;
}



static __inline void PMU_clrVDDEXTUndervoltageIntSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_STS_CLR.bit.UV_IS_CLR = 1u;
}



static __inline void PMU_clrVDDEXTOvertemperatureIntSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_STS_CLR.bit.OT_IS_CLR = 1u;
}



static __inline void PMU_clrVDDEXTUndervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_STS_CLR.bit.UV_STS_CLR = 1u;
}



static __inline void PMU_clrVDDEXTOvertemperatureSts(void)
{
  ((PMU_Type*) 0x48000000UL)->VDDEXT_STS_CLR.bit.OT_STS_CLR = 1u;
}





static __inline uint8 PMU_getVDDPRegulatorTimeoutSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_FAIL_STS.bit.VDDP_TMOUT;
}





static __inline uint8 PMU_getVDDCRegulatorTimeoutSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_FAIL_STS.bit.VDDC_TMOUT;
}





static __inline uint8 PMU_getHPClkFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_FAIL_STS.bit.HPCLK_FAIL;
}





static __inline uint8 PMU_getSysOvertemperatureSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_FAIL_STS.bit.SYS_OT;
}





static __inline uint8 PMU_getSeqWdFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_FAIL_STS.bit.FSWD_SEQ_FAIL;
}





static __inline uint8 PMU_getVDDPRegulatorOvertemperatureSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_FAIL_STS.bit.VDDP_OT;
}





static __inline uint8 PMU_getVDDCOvercurrentSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_FAIL_STS.bit.VDDC_OC;
}



static __inline void PMU_clrVDDPRegulatorTimeoutSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_FAIL_CLR.bit.VDDP_TMOUT_CLR = 1u;
}



static __inline void PMU_clrVDDCRegulatorTimeoutSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_FAIL_CLR.bit.VDDC_TMOUT_CLR = 1u;
}



static __inline void PMU_clrHPClkFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_FAIL_CLR.bit.HPCLK_FAIL_CLR = 1u;
}



static __inline void PMU_clrSysOvertemperatureSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_FAIL_CLR.bit.SYS_OT_CLR = 1u;
}



static __inline void PMU_clrSeqWdFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_FAIL_CLR.bit.FSWD_SEQ_FAIL_CLR = 1u;
}



static __inline void PMU_clrVDDPRegulatorOvertemperatureSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_FAIL_CLR.bit.VDDP_OT_CLR = 1u;
}



static __inline void PMU_clrVDDCOvercurrentSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_FAIL_CLR.bit.VDDC_OC_CLR = 1u;
}





static __inline uint8 PMU_getMstrSupplyUndervoltageRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.VMSUP_UV_RST;
}





static __inline uint8 PMU_getMstrClkWDRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.MCLK_WD_RST;
}





static __inline uint8 PMU_getFailSleepExitRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.FS_SLEEPEX_RST;
}





static __inline uint8 PMU_getSleepExitRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.SLEEPEX_RST;
}





static __inline uint8 PMU_getStopExitRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.STOPEX_RST;
}





static __inline uint8 PMU_getPinRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.PIN_RST;
}





static __inline uint8 PMU_getFailSafeWDRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.FSWD_RST;
}





static __inline uint8 PMU_getWDTimerRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.WDT_MCU_RST;
}





static __inline uint8 PMU_getSoftRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.SOFT_RST;
}





static __inline uint8 PMU_getLockupRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.LOCKUP_RST;
}





static __inline uint8 PMU_getVDDPUndervoltageRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.VDDP_UV_RST;
}





static __inline uint8 PMU_getVDDCUndervoltageRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.VDDC_UV_RST;
}





static __inline uint8 PMU_getSecureStackOverflowRstSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->RESET_STS.bit.SEC_STACK_RST;
}



static __inline void PMU_clrMstrSupplyUndervoltageRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.VMSUP_UV_RST_CLR = 1u;
}



static __inline void PMU_clrMstrClkWDRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.MCLK_WD_RST_CLR = 1u;
}



static __inline void PMU_clrFailSleepExitRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.FS_SLEEPEX_RST_CLR = 1u;
}



static __inline void PMU_clrSleepExitRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.SLEEPEX_RST_CLR = 1u;
}



static __inline void PMU_clrStopExitRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.STOPEX_RST_CLR = 1u;
}



static __inline void PMU_clrPinRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.PIN_RST_CLR = 1u;
}



static __inline void PMU_clrFailSafeWDRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.FSWD_RST_CLR = 1u;
}



static __inline void PMU_clrWDTimerRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.WDT_MCU_RST_CLR = 1u;
}



static __inline void PMU_clrSoftRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.SOFT_RST_CLR = 1u;
}



static __inline void PMU_clrLockupRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.LOCKUP_RST_CLR = 1u;
}



static __inline void PMU_clrVDDPUndervoltageRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.VDDP_UV_RST_CLR = 1u;
}



static __inline void PMU_clrVDDCUndervoltageRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.VDDC_UV_RST_CLR = 1u;
}



static __inline void PMU_clrSecureStackOverflowRstSts(void)
{
  ((PMU_Type*) 0x48000000UL)->RESET_STS_CLR.bit.SEC_STACK_RST_CLR = 1u;
}






static __inline sint8 PMU_enWakeupSrc(uint32 u32_wakeupSrc)
{
  sint8 s8_returnCode;
  uint32 u32_wakeupSrcWithoutCycSense;
  s8_returnCode = 0;

  u32_wakeupSrcWithoutCycSense = u32_wakeupSrc & (~(2u));

  if ((u32_wakeupSrc & (~(0x11FF73F7UL))) == 0u)
  {
    ((PMU_Type*) 0x48000000UL)->WAKE_CTRL.reg |= u32_wakeupSrcWithoutCycSense;

    if ((u32_wakeupSrc & (2u)) == (2u))
    {
     ((PMU_Type*) 0x48000000UL)->CYC_CTRL.bit.CYC_SENSE_EN = 1u;
    }
  }
  else
  {
    s8_returnCode = (-122);
  }

  return s8_returnCode;
}






static __inline sint8 PMU_disWakeupSrc(uint32 u32_wakeupSrc)
{
  sint8 s8_returnCode;
  uint32 u32_wakeupSrcWithoutCycSense;
  s8_returnCode = 0;

  u32_wakeupSrcWithoutCycSense = u32_wakeupSrc &~(2u);

  if ((u32_wakeupSrc & (~(0x11FF73F7UL))) == 0u)
  {
    ((PMU_Type*) 0x48000000UL)->WAKE_CTRL.reg &= (~u32_wakeupSrcWithoutCycSense);

    if ((u32_wakeupSrc & (2u)) == (2u))
    {
     ((PMU_Type*) 0x48000000UL)->CYC_CTRL.bit.CYC_SENSE_EN = 0u;
    }
  }
  else
  {
    s8_returnCode = (-122);
  }

  return s8_returnCode;
}





static __inline uint32 PMU_getWakeupSrc(void)
{
  return ((PMU_Type*) 0x48000000UL)->WAKE_CTRL.reg;
}



static __inline void PMU_enStopModeVDDCReduct(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_CTRL.bit.VDDC_RED_EN = 1u;
}



static __inline void PMU_disStopModeVDDCReduct(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_CTRL.bit.VDDC_RED_EN = 0u;
}
# 1156 "./RTE/Device/TLE9893_2QKW62S/pmu.h"
static __inline sint8 PMU_setGPIOWakeCfg(uint8 u8_GPIO, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, tPMU_gpioInput e_gpioInput)
{
  sint8 s8_returnCode;
  s8_returnCode = 0;

  if ((u8_enRisingEdge <= 1) && (u8_enFallingEdge <= 1) && (u8_enCycSen <= 1) && (e_gpioInput <= PMU_gpioInput_P2_9))
  {
    switch (u8_GPIO)
    {
      case 0:
      {
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL0.bit.RI = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL0.bit.FA = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL0.bit.CYC = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL0.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 1:
      {
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL1.bit.RI = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL1.bit.FA = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL1.bit.CYC = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL1.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 2:
      {
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL2.bit.RI = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL2.bit.FA = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL2.bit.CYC = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL2.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 3:
      {
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL3.bit.RI = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL3.bit.FA = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL3.bit.CYC = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL3.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 4:
      {
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL4.bit.RI = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL4.bit.FA = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL4.bit.CYC = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL4.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 5:
      {
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL5.bit.RI = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL5.bit.FA = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL5.bit.CYC = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->WAKE_GPIO_CTRL5.bit.INP = (uint8)e_gpioInput;
        break;
      }

      default:
      {
        s8_returnCode = (-122);
        break;
      }
    }
  }
  else
  {
    s8_returnCode = (-122);
  }

  return s8_returnCode;
}
# 1244 "./RTE/Device/TLE9893_2QKW62S/pmu.h"
static __inline sint8 PMU_setMONWakeCfg(uint8 u8_MON, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, uint8 u8_enPullupCurrSrc, uint8 u8_enPulldownCurrSrc)
{
  sint8 s8_returnCode;
  s8_returnCode = 0;

  if ((u8_enRisingEdge <= 1) && (u8_enFallingEdge <= 1) && (u8_enCycSen <= 1) && (u8_enPullupCurrSrc <= 1) && (u8_enPulldownCurrSrc <= 1))
  {
    switch (u8_MON)
    {
      case 1:
      {
        ((PMU_Type*) 0x48000000UL)->MON_CTRL1.bit.WAKE_RISE = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL1.bit.WAKE_FALL = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL1.bit.CYC_SENSE_EN = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL1.bit.PU = u8_enPullupCurrSrc;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL1.bit.PD = u8_enPulldownCurrSrc;
        break;
      }

      case 2:
      {
        ((PMU_Type*) 0x48000000UL)->MON_CTRL2.bit.WAKE_RISE = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL2.bit.WAKE_FALL = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL2.bit.CYC_SENSE_EN = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL2.bit.PU = u8_enPullupCurrSrc;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL2.bit.PD = u8_enPulldownCurrSrc;
        break;
      }

      case 3:
      {
        ((PMU_Type*) 0x48000000UL)->MON_CTRL3.bit.WAKE_RISE = u8_enRisingEdge;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL3.bit.WAKE_FALL = u8_enFallingEdge;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL3.bit.CYC_SENSE_EN = u8_enCycSen;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL3.bit.PU = u8_enPullupCurrSrc;
        ((PMU_Type*) 0x48000000UL)->MON_CTRL3.bit.PD = u8_enPulldownCurrSrc;
        break;
      }

      default:
      {
        s8_returnCode = (-122);
        break;
      }
    }
  }
  else
  {
    s8_returnCode = (-122);
  }

  return s8_returnCode;
}





static __inline uint8 PMU_getMON1InputSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->MON_STS.bit.MON1_STS;
}





static __inline uint8 PMU_getMON2InputSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->MON_STS.bit.MON2_STS;
}





static __inline uint8 PMU_getMON3InputSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->MON_STS.bit.MON3_STS;
}





static __inline uint8 PMU_getCANWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.CAN;
}





static __inline uint8 PMU_getCyclicWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.CYC_WAKE;
}





static __inline uint8 PMU_getGPIO0WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.GPIO0;
}





static __inline uint8 PMU_getGPIO1WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.GPIO1;
}





static __inline uint8 PMU_getGPIO2WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.GPIO2;
}





static __inline uint8 PMU_getGPIO3WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.GPIO3;
}





static __inline uint8 PMU_getGPIO4WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.GPIO4;
}





static __inline uint8 PMU_getGPIO5WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.GPIO5;
}





static __inline uint8 PMU_getMON1WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.MON1;
}





static __inline uint8 PMU_getMON2WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.MON2;
}





static __inline uint8 PMU_getMON3WakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.MON3;
}





static __inline uint8 PMU_getVDDPUndervoltageWarnWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDP_UVWARN;
}





static __inline uint8 PMU_getVDDPOvervoltageWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDP_OV;
}





static __inline uint8 PMU_getVDDPHighCurrentModeWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDP_HCM;
}





static __inline uint8 PMU_getVDDCUndervoltageWarnWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDC_UVWARN;
}





static __inline uint8 PMU_getVDDCOvervoltageWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDC_OV;
}





static __inline uint8 PMU_getVDDCHighCurrentModeWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDC_HCM;
}





static __inline uint8 PMU_getVDDEXTOvertemperatureWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDEXT_OT;
}





static __inline uint8 PMU_getVDDEXTUndervoltageWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VDDEXT_UV;
}





static __inline uint8 PMU_getVSDOvervoltageWakeSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->WAKE_STS.bit.VSD_OV;
}



static __inline void PMU_clrCANWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.CAN_CLR = 1u;
}



static __inline void PMU_clrCyclicWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.CYC_WAKE_CLR = 1u;
}



static __inline void PMU_clrGPIO0WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.GPIO0_CLR = 1u;
}



static __inline void PMU_clrGPIO1WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.GPIO1_CLR = 1u;
}



static __inline void PMU_clrGPIO2WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.GPIO2_CLR = 1u;
}



static __inline void PMU_clrGPIO3WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.GPIO3_CLR = 1u;
}



static __inline void PMU_clrGPIO4WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.GPIO4_CLR = 1u;
}



static __inline void PMU_clrGPIO5WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.GPIO5_CLR = 1u;
}



static __inline void PMU_clrMON1WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.MON1_CLR = 1u;
}



static __inline void PMU_clrMON2WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.MON2_CLR = 1u;
}



static __inline void PMU_clrMON3WakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.MON3_CLR = 1u;
}



static __inline void PMU_clrVDDPUndervoltageWarnWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDP_UVWARN_CLR = 1u;
}



static __inline void PMU_clrVDDPOvervoltageWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDP_OV_CLR = 1u;
}



static __inline void PMU_clrVDDPHighCurrentModeWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDP_HCM_CLR = 1u;
}



static __inline void PMU_clrVDDCUndervoltageWarnWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDC_UVWARN_CLR = 1u;
}



static __inline void PMU_clrVDDCOvervoltageWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDC_OV_CLR = 1u;
}



static __inline void PMU_clrVDDCHighCurrentModeWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDC_HCM_CLR = 1u;
}



static __inline void PMU_clrVDDEXTOvertemperatureWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDEXT_OT_CLR = 1u;
}



static __inline void PMU_clrVDDEXTUndervoltageWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VDDEXT_UV_CLR = 1u;
}



static __inline void PMU_clrVSDOvervoltageWakeSts(void)
{
  ((PMU_Type*) 0x48000000UL)->WAKE_STS_CLR.bit.VSD_OV_CLR = 1u;
}



static __inline void PMU_enFailInputPullUp(void)
{
  ((PMU_Type*) 0x48000000UL)->MISC_CTRL.bit.FI_PU_EN = 1u;
}



static __inline void PMU_enStartCfg(void)
{
  ((PMU_Type*) 0x48000000UL)->START_CONFIG.bit.CONF = 1u;
}



static __inline void PMU_enResetPin(void)
{
  ((PMU_Type*) 0x48000000UL)->START_CONFIG.bit.RST_PIN_EN = 1u;
}



static __inline void PMU_disFailInputPullUp(void)
{
  ((PMU_Type*) 0x48000000UL)->MISC_CTRL.bit.FI_PU_EN = 0u;
}



static __inline void PMU_disStartCfg(void)
{
  ((PMU_Type*) 0x48000000UL)->START_CONFIG.bit.CONF = 0u;
}



static __inline void PMU_disResetPin(void)
{
  ((PMU_Type*) 0x48000000UL)->START_CONFIG.bit.RST_PIN_EN = 0u;
}





static __inline uint8 PMU_getMstrClkWDFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.MCLK_FAIL_STS;
}





static __inline uint8 PMU_getMstrSupplyUndervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VMSUP_UV_STS;
}





static __inline uint8 PMU_getMstrSupplyOvervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VMSUP_OV_STS;
}





static __inline uint8 PMU_getWDFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.WD_FAIL_STS;
}





static __inline uint8 PMU_getWDSelfTestFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.WD_TEST_FAIL_STS;
}





static __inline uint8 PMU_getVDDCUndervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VDDC_UV_STS;
}





static __inline uint8 PMU_getVDDCOvervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VDDC_OV_STS;
}





static __inline uint8 PMU_getVDDPUndervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VDDP_UV_STS;
}





static __inline uint8 PMU_getVDDPOvervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VDDP_OV_STS;
}





static __inline uint8 PMU_getVDDPOvertemperatureSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VDDP_OT_STS;
}





static __inline uint8 PMU_getVAREFOvervoltageSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.VAREF_OV_STS;
}





static __inline uint8 PMU_getCSCOvercurrentSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.CSC_OC_STS;
}





static __inline uint8 PMU_getCSCSelfTestFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.CSC_BIST_FAIL_STS;
}





static __inline uint8 PMU_getCSCEnFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.CSC_EN_FAIL_STS;
}





static __inline uint8 PMU_getPinMonitorFailSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.PIN_MON_STS;
}





static __inline uint8 PMU_getFOOvercurrentSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_STS.bit.FO_OC_STS;
}



static __inline void PMU_clrMstrClkWDFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.MCLK_FAIL_STS_CLR = 1u;
}



static __inline void PMU_clrMstrSupplyUndervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VMSUP_UV_STS_CLR = 1u;
}



static __inline void PMU_clrMstrSupplyOvervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VMSUP_OV_STS_CLR = 1u;
}



static __inline void PMU_clrWDFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.WD_FAIL_STS_CLR = 1u;
}



static __inline void PMU_clrWDSelfTestFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.WD_TEST_FAIL_STS_CLR = 1u;
}



static __inline void PMU_clrVDDCUndervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VDDC_UV_STS_CLR = 1u;
}



static __inline void PMU_clrVDDCOvervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VDDC_OV_STS_CLR = 1u;
}



static __inline void PMU_clrVDDPUndervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VDDP_UV_STS_CLR = 1u;
}



static __inline void PMU_clrVDDPOvervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VDDP_OV_STS_CLR = 1u;
}



static __inline void PMU_clrVDDPOvertemperatureSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VDDP_OT_STS_CLR = 1u;
}



static __inline void PMU_clrVAREFOvervoltageSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.VAREF_OV_STS_CLR = 1u;
}



static __inline void PMU_clrCSCOvercurrentSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.CSC_OC_STS_CLR = 1u;
}



static __inline void PMU_clrCSCSelfTestFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.CSC_BIST_FAIL_STS_CLR = 1u;
}



static __inline void PMU_clrCSCEnFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.CSC_EN_FAIL_STS_CLR = 1u;
}



static __inline void PMU_clrPinMonitorFailSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.PIN_MON_STS_CLR = 1u;
}



static __inline void PMU_clrFOOvercurrentSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.bit.FO_OC_STS_CLR = 1u;
}





static __inline uint8 PMU_getSafeShutdownSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_SSD.bit.SSD_STS;
}





static __inline uint8 PMU_getFailOutputSts(void)
{
  return (uint8)((PMU_Type*) 0x48000000UL)->FS_SSD.bit.FO_STS;
}



static __inline void PMU_clrSafeShutdownSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_SSD_CLR.bit.SSD_STS_CLR = 1u;
}



static __inline void PMU_clrFailOutputSts(void)
{
  ((PMU_Type*) 0x48000000UL)->FS_SSD_CLR.bit.FO_STS_CLR = 1u;
}
# 140 "./RTE/Device/TLE9893_2QKW62S/scu.h" 2
# 163 "./RTE/Device/TLE9893_2QKW62S/scu.h"
extern sint8 e_xtalSts;





void SCU_init(void);
sint8 SCU_initClk(void);
sint8 SCU_checkXTALDiagnosis(void);
void SCU_delay_us(uint32 u32_time_us);
void SCU_initSysTick(uint32 u32_value);
sint8 SCU_enSafeSwitchOffSeq(void);
void SCU_enterDeepSleepMode(void);
void SCU_enterStopModeWithResetWakeup(void);
sint8 SCU_enterStopModeWithoutResetWakeup(void);
void SCU_enterSleepMode(uint8 u8_enRAMTest);
static __inline uint8 SCU_GetXTALFailSts(void);
static __inline uint8 SCU_GetPLL0LockSts(void);
static __inline uint8 SCU_GetPLL1LockSts(void);
static __inline uint32 SCU_getSysTickCntVal(void);
static __inline uint32 SCU_getSysTickRelVal(void);
static __inline void CACHE_setCleanAll(void);
static __inline void CACHE_setLockBlock(uint32 u32_value);
static __inline void CACHE_setTouchBlock(uint32 u32_value);
static __inline void CACHE_setUnlockBlock(uint32 u32_value);
static __inline void CACHE_setCleanSet(uint32 u32_value);
# 198 "./RTE/Device/TLE9893_2QKW62S/scu.h"
static __inline uint8 SCU_GetXTALFailSts(void)
{
  return (uint8)((SCU_Type*) 0x48004000UL)->XTALSTAT.bit.XTALFAIL;
}





static __inline uint8 SCU_GetPLL0LockSts(void)
{
  return (uint8)((PLL_Type*) 0x48008000UL)->STAT.bit.LCK0;
}





static __inline uint8 SCU_GetPLL1LockSts(void)
{
  return (uint8)((PLL_Type*) 0x48008000UL)->STAT.bit.LCK1;
}





static __inline uint32 SCU_getSysTickCntVal(void)
{
  return (uint32)((CPU_Type*) 0xE000E000UL)->SYSTICK_CUR.bit.CURRENT;
}





static __inline uint32 SCU_getSysTickRelVal(void)
{
  return (uint32)((CPU_Type*) 0xE000E000UL)->SYSTICK_RL.bit.RELOAD;
}



static __inline void CACHE_setCleanAll(void)
{
  ((CACHE_Type*) 0x48048000UL)->CACHE_AC.bit.Clean = 1u;
}





static __inline void CACHE_setLockBlock(uint32 u32_value)
{
  ((CACHE_Type*) 0x48048000UL)->CACHE_BL.bit.ADDR = u32_value;
}





static __inline void CACHE_setTouchBlock(uint32 u32_value)
{
  ((CACHE_Type*) 0x48048000UL)->CACHE_BT.bit.ADDR = u32_value;
}





static __inline void CACHE_setUnlockBlock(uint32 u32_value)
{
  ((CACHE_Type*) 0x48048000UL)->CACHE_BU.bit.ADDR = u32_value;
}





static __inline void CACHE_setCleanSet(uint32 u32_value)
{
  ((CACHE_Type*) 0x48048000UL)->CACHE_SC.bit.ADDR = u32_value;
}
# 35 "RTE/Device/TLE9893_2QKW62S/csacsc.c" 2
# 65 "RTE/Device/TLE9893_2QKW62S/csacsc.c"
sint8 CSACSC_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = (-116);




    ((CSACSC_Type*) 0x40010000UL)->CTRL1.reg = (uint32)(0x3FF0001u) & (uint32)~(0x1UL);

    ((CSACSC_Type*) 0x40010000UL)->CTRL1.reg = (0x3FF0001u);

    while ((CSACSC_getBistSts() == 0u) && (((PMU_Type*) 0x48000000UL)->FS_STS.bit.CSC_BIST_FAIL_STS == 0u))
    {

      s8_returnCode = PMU_serviceFailSafeWatchdog();
    }

    if (CSACSC_getBistSts() == 1u)
    {

      ((CSACSC_Type*) 0x40010000UL)->CTRL2.reg = (0x10000u);
      s8_returnCode = 0;
    }
    else
    {

      s8_returnCode = (-1);
    }


    ((PMU_Type*) 0x48000000UL)->FS_STS_CLR.reg = (uint32)0x17FFFu;
    ((PMU_Type*) 0x48000000UL)->FS_SSD_CLR.reg = (uint32)0x3u;


  return s8_returnCode;
}
# 111 "RTE/Device/TLE9893_2QKW62S/csacsc.c"
sint8 CSACSC_startCalibration(uint16 *u16p_Val_mV)
{
  uint32 u32_chCfg19Bak;
  uint32 u32_sqCfg3Bak;
  uint32 u32_sq3SlotBak;
  tADC1_CHCFGx s_chCfgNew;
  tADC1_SQCFGx s_sqCfgNew;
  tADC1_SQSLOTx s_slotNew;
  sint8 s8_returnCode;

  s8_returnCode = 0;

  if (PtrRangeCheck(u16p_Val_mV) == 1)
  {

    u32_chCfg19Bak = ((ADC1_Type*) 0x40000000UL)->CHCFG19.reg;
    u32_sqCfg3Bak = ((ADC1_Type*) 0x40000000UL)->SQCFG3.reg;
    u32_sq3SlotBak = ((ADC1_Type*) 0x40000000UL)->SQSLOT3.reg;

    s_chCfgNew.reg = 0;

    s_chCfgNew.bit.CLASSEL = 2;

    s_chCfgNew.bit.CMPSEL = 4;

    s_chCfgNew.bit.FILSEL = 4;

    s_chCfgNew.bit.INSEL = 18;

    s_sqCfgNew.reg = 0;

    s_sqCfgNew.bit.SLOTS = 1;

    s_slotNew.reg = 0;

    s_slotNew.bit.CHSEL0 = 19;

    ((ADC1_Type*) 0x40000000UL)->SQSLOT3.reg = s_slotNew.reg;
    ((ADC1_Type*) 0x40000000UL)->SQCFG3.reg = s_sqCfgNew.reg;
    ((ADC1_Type*) 0x40000000UL)->CHCFG19.reg = s_chCfgNew.reg;

    ((ADC1_Type*) 0x40000000UL)->SHDCTR.reg = (uint32)(0x00700000u);
    ((ADC1_Type*) 0x40000000UL)->SHDCTR.reg = (uint32)(0x00770000u);

    s8_returnCode = ADC1_startSequence((3u));

    if (s8_returnCode == 0)
    {

      while (ADC1_getEndOfConvSts((3u), (0u)) == 0) {}


      s8_returnCode = ADC1_getSeqResult_mV(u16p_Val_mV, (3u), (0u));
    }


    ((ADC1_Type*) 0x40000000UL)->SQSLOT3.reg = u32_sq3SlotBak;
    ((ADC1_Type*) 0x40000000UL)->SQCFG3.reg = u32_sqCfg3Bak;
    ((ADC1_Type*) 0x40000000UL)->CHCFG19.reg = u32_chCfg19Bak;

    ((ADC1_Type*) 0x40000000UL)->SHDCTR.reg = (uint32)(0x00700000u);
    ((ADC1_Type*) 0x40000000UL)->SHDCTR.reg = (uint32)(0x00770000u);
  }
  else
  {
    s8_returnCode = (-122);
  }

  return s8_returnCode;
}
# 190 "RTE/Device/TLE9893_2QKW62S/csacsc.c"
void CSACSC_setOverCurrIntNodePtr(void)
{

}

void CSACSC_setParamErrorIntNodePtr(void)
{

}
