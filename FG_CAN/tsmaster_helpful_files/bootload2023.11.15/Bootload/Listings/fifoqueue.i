# 1 "Can_iso_tp/fifo/FIFOQUEUE.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "Can_iso_tp/fifo/FIFOQUEUE.c" 2
# 28 "Can_iso_tp/fifo/FIFOQUEUE.c"
# 1 "./Can_iso_tp/fifo/FIFOQUEUE.h" 1
# 36 "./Can_iso_tp/fifo/FIFOQUEUE.h"
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
# 37 "./Can_iso_tp/fifo/FIFOQUEUE.h" 2
 typedef void* ElemType;




 struct FifoQueue
 {

  ElemType *dat;
  uint16_t queue_size;

  uint16_t front;
  uint16_t rear;
  uint16_t count;
 };

 extern uint8_t QueueInit(struct FifoQueue *Queue, ElemType* dat, uint16_t queue_size);

 extern uint8_t QueueIn(struct FifoQueue *Queue, ElemType sdat);

 extern uint8_t QueueOut(struct FifoQueue *Queue, ElemType *sdat);
# 29 "Can_iso_tp/fifo/FIFOQUEUE.c" 2
# 1 "./Can_iso_tp/mcu_lock\\mcu_lock.h" 1
# 37 "./Can_iso_tp/mcu_lock\\mcu_lock.h"
# 1 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 1
# 31 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
# 64 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
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
# 260 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 295 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint8_t __CLZ(uint32_t value)
{
# 306 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}
# 425 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __RRX(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 440 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint8_t __LDRBT(volatile uint8_t *ptr)
{
  uint32_t result;

  __asm volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*ptr) );
  return ((uint8_t) result);
}
# 455 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint16_t __LDRHT(volatile uint16_t *ptr)
{
  uint32_t result;

  __asm volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*ptr) );
  return ((uint16_t) result);
}
# 470 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __LDRT(volatile uint32_t *ptr)
{
  uint32_t result;

  __asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
  return(result);
}
# 485 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __STRBT(uint8_t value, volatile uint8_t *ptr)
{
  __asm volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 497 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __STRHT(uint16_t value, volatile uint16_t *ptr)
{
  __asm volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 509 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __STRT(uint32_t value, volatile uint32_t *ptr)
{
  __asm volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
# 737 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}
# 750 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}
# 762 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 792 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
  __builtin_arm_isb(0xF);
}
# 818 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
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
# 890 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : );
}
# 914 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __get_MSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 944 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}
# 995 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
# 1025 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 1053 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
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
# 1105 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_BASEPRI(uint32_t basePri)
{
  __asm volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}
# 1130 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
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
# 1171 "C:/Users/Lxp20/AppData/Local/Arm/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include\\cmsis_armclang.h" 3
__attribute__((always_inline)) static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 38 "./Can_iso_tp/mcu_lock\\mcu_lock.h" 2

typedef unsigned int mcu_lock_t;
typedef unsigned int cpu_status_t;
# 65 "./Can_iso_tp/mcu_lock\\mcu_lock.h"
void mcu_lock_init(mcu_lock_t *lock);
unsigned int mcu_lock_try_lock(register mcu_lock_t *lock);
void mcu_lock_unlock(mcu_lock_t *lock);
# 30 "Can_iso_tp/fifo/FIFOQUEUE.c" 2

uint8_t
QueueInit(struct FifoQueue* Queue, ElemType* dat, uint16_t queue_size)
{
 uint8_t ret = (0==1);
 Queue->queue_size = queue_size;
 Queue->dat = dat;
 if ((Queue->dat != (ElemType*)0)
  && (Queue->queue_size != 0)
  )
 {
  Queue->front = 0;
  Queue->rear = 0;
  Queue->count = 0;
  ret = (1 == 1);
 }
 return ret;
}


uint8_t
QueueIn (register struct FifoQueue *Queue, ElemType sdat)
{
 register volatile cpu_status_t cpu_sr;
 do{cpu_sr = 1;__disable_irq();}while(0);
    if ((Queue->front == Queue->rear) && (Queue->count == Queue->queue_size))
    {
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
        return 0;
    }
    else
    {
        Queue->dat[Queue->rear] = sdat;
        Queue->rear = (Queue->rear + 1) % Queue->queue_size;
        Queue->count = Queue->count + 1;
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
        return 2;
    }
}


uint8_t
QueueOut (register struct FifoQueue * Queue, ElemType * sdat)
{
 register volatile cpu_status_t cpu_sr;
 do{cpu_sr = 1;__disable_irq();}while(0);
    if ((Queue->front == Queue->rear) && (Queue->count == 0))
    {
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
        return 1;
    }
    else
    {
        *sdat = Queue->dat[Queue->front];
        Queue->front = (Queue->front + 1) % Queue->queue_size;
        Queue->count = Queue->count - 1;
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
        return 2;
    }
}
