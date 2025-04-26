# 1 "Can_iso_tp/can_iso_tp/can_iso_tp.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 379 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "Can_iso_tp/can_iso_tp/can_iso_tp.c" 2
# 30 "Can_iso_tp/can_iso_tp/can_iso_tp.c"
# 1 "./Can_iso_tp/can_iso_tp/can_iso_tp.h" 1
# 34 "./Can_iso_tp/can_iso_tp/can_iso_tp.h"
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
# 35 "./Can_iso_tp/can_iso_tp/can_iso_tp.h" 2





typedef struct can_iso_tp_link_t* can_iso_tp_link_t_p;
struct CAN_msg_id {
 uint32_t id:29;
 uint32_t isExt:1;
 uint32_t isCANFD : 1;
 uint32_t isRemote : 1;
};
struct CAN_msg {
 struct CAN_msg_id id;
 uint8_t dlc;

 uint8_t data[64];




};
typedef enum {
 N_OK
 , N_TIMEOUT_A
 , N_TIMEOUT_BS
 , N_TIMEOUT_CR
 , N_WRONG_SN
 , N_INVALID_FS
 , N_UNEXP_PDU
 , N_WFT_OVRN
 , N_BUFFER_OVFLW
 , N_ERROR
}CAN_ISO_TP_RESAULT;
struct can_iso_tp_init_t {
 void* usr_arg;
 struct CAN_msg_id tx_id;
 struct CAN_msg_id rx_id;
 struct CAN_msg_id funtion_id;
 int (*L_Data_request)(can_iso_tp_link_t_p link, const struct CAN_msg* msg);
 void (*N_USData_indication)(can_iso_tp_link_t_p link, const uint8_t payload[], uint32_t size, CAN_ISO_TP_RESAULT error);
 void (*N_USData_confirm)(can_iso_tp_link_t_p link, const uint8_t payload[], uint32_t size, CAN_ISO_TP_RESAULT error);
 uint8_t *rx_buff;
 uint32_t rx_buff_len;

 uint16_t N_As;
 uint16_t N_Ar;
 uint16_t N_Bs;
 uint16_t N_Br;
 uint16_t N_Cs;
 uint16_t N_Cr;

 void(*print_debug)(const char *str);
 uint8_t N_WFTmax;
 uint8_t FC_BS;
 uint8_t STmin;
 uint8_t TX_DLC;
 uint8_t frame_pad;
};
# 106 "./Can_iso_tp/can_iso_tp/can_iso_tp.h"
int iso_can_tp_create(can_iso_tp_link_t_p link, struct can_iso_tp_init_t* init);
# 117 "./Can_iso_tp/can_iso_tp/can_iso_tp.h"
void iso_can_tp_poll(can_iso_tp_link_t_p link, unsigned int user_ms);
# 129 "./Can_iso_tp/can_iso_tp/can_iso_tp.h"
int iso_can_tp_L_Data_indication(can_iso_tp_link_t_p link, const struct CAN_msg* msg);
# 154 "./Can_iso_tp/can_iso_tp/can_iso_tp.h"
int iso_can_tp_L_Data_confirm(can_iso_tp_link_t_p link, const struct CAN_msg* msg, int8_t error);
# 179 "./Can_iso_tp/can_iso_tp/can_iso_tp.h"
int iso_can_tp_N_USData_request(can_iso_tp_link_t_p link, uint8_t isFunction, const uint8_t payload[], uint32_t size);
# 31 "Can_iso_tp/can_iso_tp/can_iso_tp.c" 2
# 1 "./Can_iso_tp/can_iso_tp/can_iso_tp_private.h" 1
# 36 "./Can_iso_tp/can_iso_tp/can_iso_tp_private.h"
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
# 37 "./Can_iso_tp/can_iso_tp/can_iso_tp_private.h" 2
# 1 "./Can_iso_tp/fifo\\FIFOQUEUE.h" 1
# 37 "./Can_iso_tp/fifo\\FIFOQUEUE.h"
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
# 38 "./Can_iso_tp/can_iso_tp/can_iso_tp_private.h" 2

typedef void(*event_handle_t)(void*);
struct time_poll_par_t {
 event_handle_t handle;
 can_iso_tp_link_t_p link;
 unsigned int user_ms;
};
struct L_Data_confirm_par_t {
 event_handle_t handle;
 can_iso_tp_link_t_p link;
 int8_t error;
};
struct N_USData_request_par_t {
 event_handle_t handle;
 can_iso_tp_link_t_p link;
 uint8_t isFunction;
 uint32_t size;
 const uint8_t* payload;
};
struct L_Data_indication_par_t {
 event_handle_t handle;
 can_iso_tp_link_t_p link;
 struct CAN_msg rx_msg;
};

struct event_mange_t {
 mcu_lock_t lock;
 ElemType fifo_data[(3)];
 struct FifoQueue fifo;
};

typedef enum {
 tx_idle = 0
 , tx_sf_wait_tx
 , tx_sf_wait_confirm

 , tx_ff_wait_tx
 , tx_ff_wait_confirm

 , tx_wait_fc

 , tx_cf_wait_tx
 , tx_cf_wait_tx_retry
 , tx_cf_wait_confirm
}e_tx_status;
typedef enum {
 rx_idle = 0
 , rx_tx_fc
 , rx_tx_fc_wait_confirm
 , rx_wait_cf

 , rx_tx_fc_overrun
 , rx_tx_fc_overrun_wait_confirm
}e_rx_status;


struct can_iso_tp_link_t {
 struct can_iso_tp_init_t init_info;
 unsigned int init_done_flag;
 unsigned int current_time_ms;

 struct {
  struct CAN_msg last_msg;
  unsigned int last_msg_time_ms;
  const uint8_t *current_playload;
  uint32_t current_size;
  uint32_t current_tx_index;
  uint8_t current_tx_SN;
  uint8_t rx_BS;
  uint8_t rx_BS_tx;
  uint8_t rx_Stmin;
  uint8_t N_WFT_cnt;
  e_tx_status status;
 }tx_record;
 struct {
  struct L_Data_indication_par_t L_Data_indication_par;
  struct L_Data_confirm_par_t L_Data_confirm_par;
  struct time_poll_par_t time_poll_par;
  struct N_USData_request_par_t N_USData_request_par;
  struct event_mange_t event_manage;
 }tx_events;

 struct {
  e_rx_status status;
  uint32_t rx_index;
  uint32_t rx_len;
  uint8_t rx_SN;
  uint8_t tx_BS_cnt;
  struct CAN_msg last_msg;
  unsigned int last_msg_time_ms;
 }rx_record;
 struct {
  struct L_Data_indication_par_t L_Data_indication_par;
  struct L_Data_confirm_par_t L_Data_confirm_par;
  struct time_poll_par_t time_poll_par;
  struct event_mange_t event_manage;
 }rx_events;
};
# 32 "Can_iso_tp/can_iso_tp/can_iso_tp.c" 2
# 1 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 1 3
# 51 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
    typedef unsigned int size_t;






extern __attribute__((__nothrow__)) void *memcpy(void * __restrict ,
                    const void * __restrict , size_t ) __attribute__((__nonnull__(1,2)));






extern __attribute__((__nothrow__)) void *memmove(void * ,
                    const void * , size_t ) __attribute__((__nonnull__(1,2)));
# 77 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) char *strcpy(char * __restrict , const char * __restrict ) __attribute__((__nonnull__(1,2)));






extern __attribute__((__nothrow__)) char *strncpy(char * __restrict , const char * __restrict , size_t ) __attribute__((__nonnull__(1,2)));
# 93 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) char *strcat(char * __restrict , const char * __restrict ) __attribute__((__nonnull__(1,2)));






extern __attribute__((__nothrow__)) char *strncat(char * __restrict , const char * __restrict , size_t ) __attribute__((__nonnull__(1,2)));
# 117 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) int memcmp(const void * , const void * , size_t ) __attribute__((__nonnull__(1,2)));







extern __attribute__((__nothrow__)) int strcmp(const char * , const char * ) __attribute__((__nonnull__(1,2)));






extern __attribute__((__nothrow__)) int strncmp(const char * , const char * , size_t ) __attribute__((__nonnull__(1,2)));
# 141 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) int strcasecmp(const char * , const char * ) __attribute__((__nonnull__(1,2)));







extern __attribute__((__nothrow__)) int strncasecmp(const char * , const char * , size_t ) __attribute__((__nonnull__(1,2)));
# 158 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) int strcoll(const char * , const char * ) __attribute__((__nonnull__(1,2)));
# 169 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) size_t strxfrm(char * __restrict , const char * __restrict , size_t ) __attribute__((__nonnull__(2)));
# 193 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) void *memchr(const void * , int , size_t ) __attribute__((__nonnull__(1)));
# 209 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) char *strchr(const char * , int ) __attribute__((__nonnull__(1)));
# 218 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) size_t strcspn(const char * , const char * ) __attribute__((__nonnull__(1,2)));
# 232 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) char *strpbrk(const char * , const char * ) __attribute__((__nonnull__(1,2)));
# 247 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) char *strrchr(const char * , int ) __attribute__((__nonnull__(1)));
# 257 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) size_t strspn(const char * , const char * ) __attribute__((__nonnull__(1,2)));
# 270 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) char *strstr(const char * , const char * ) __attribute__((__nonnull__(1,2)));
# 280 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) char *strtok(char * __restrict , const char * __restrict ) __attribute__((__nonnull__(2)));
extern __attribute__((__nothrow__)) char *_strtok_r(char * , const char * , char ** ) __attribute__((__nonnull__(2,3)));
# 321 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) void *memset(void * , int , size_t ) __attribute__((__nonnull__(1)));





extern __attribute__((__nothrow__)) char *strerror(int );







extern __attribute__((__nothrow__)) size_t strlen(const char * ) __attribute__((__nonnull__(1)));






extern __attribute__((__nothrow__)) size_t strlcpy(char * , const char * , size_t ) __attribute__((__nonnull__(1,2)));
# 362 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) size_t strlcat(char * , const char * , size_t ) __attribute__((__nonnull__(1,2)));
# 388 "C:\\Keil_v5\\ARM\\ARMCLANG\\Bin\\..\\include\\string.h" 3
extern __attribute__((__nothrow__)) void _membitcpybl(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitcpybb(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitcpyhl(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitcpyhb(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitcpywl(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitcpywb(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitmovebl(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitmovebb(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitmovehl(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitmovehb(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitmovewl(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
extern __attribute__((__nothrow__)) void _membitmovewb(void * , const void * , int , int , size_t ) __attribute__((__nonnull__(1,2)));
# 33 "Can_iso_tp/can_iso_tp/can_iso_tp.c" 2






static void printf_debug_msg(struct can_iso_tp_init_t* link, char *msg)
{
 if (link->print_debug)
 {
  link->print_debug(msg);
 }
}
static const uint8_t dlc_len_table[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64 };
static inline uint8_t dlc2len(uint8_t dlc)
{
 return dlc_len_table[dlc & 0xf];
}
static unsigned int lenToMinDlc(uint32_t len)
{
  unsigned int dlc;
 for (dlc = 0; dlc <= sizeof(dlc_len_table)/sizeof(dlc_len_table[0]); dlc++)
 {
  if (len <= dlc_len_table[dlc])
   break;
 }
 return dlc;
}

static int event_manage_block_init(struct event_mange_t* event)
{
 mcu_lock_init(&event->lock);
 if (!QueueInit(&event->fifo, event->fifo_data, sizeof(event->fifo_data) / sizeof(event->fifo_data[0])))
 {
  return -1;
 }
 return 0;
}
static int report_event_to_manage_block(struct event_mange_t* task, void* par_with_handle)
{
 int res = 1;


 if (2 != QueueIn(&task->fifo, (ElemType)par_with_handle))
 {

 }
 else {
  if (mcu_lock_try_lock(&task->lock))
  {
   do {
    struct {
     event_handle_t handle;
    }*par;

    if (2 != QueueOut(&task->fifo, (ElemType*)& par))
    {
     break;
    }
    else {
     if (par->handle)
     {
      par->handle((void*)par);
     }
    }
   } while (1 == 1);
   mcu_lock_unlock(&task->lock);
  }
  res = 0;
 }
 return res;
}

static int tx_event_cf_frame(can_iso_tp_link_t_p link)
{
 if (link->tx_record.status == tx_cf_wait_tx)
 {
  int tx_frame = 1;
  if (link->tx_record.rx_Stmin != 0)
  {
   if ((link->current_time_ms - link->tx_record.last_msg_time_ms) < link->tx_record.rx_Stmin)
   {
    tx_frame = 0;
   }
  }
  if (0 != tx_frame)
  {
   uint32_t txLen = link->tx_record.current_size - link->tx_record.current_tx_index;
   if (txLen > (uint32_t)(dlc2len(link->init_info.TX_DLC)-1))
   {
    txLen = (dlc2len(link->init_info.TX_DLC)-1);
   }
   if (txLen == 0)
   {
    link->tx_record.status = tx_idle;
    if (link->init_info.N_USData_confirm)
    {
     link->init_info.N_USData_confirm(link, link->tx_record.current_playload, link->tx_record.current_size, N_OK);
    }
   }
   else {
    link->tx_record.last_msg.id = link->init_info.tx_id;
    link->tx_record.last_msg.data[0] = 0x20 | (link->tx_record.current_tx_SN & 0xf);
    memcpy(&link->tx_record.last_msg.data[1], &link->tx_record.current_playload[link->tx_record.current_tx_index], txLen);
    if (dlc2len(link->init_info.TX_DLC) > (1 + txLen))
    {
     memset(&link->tx_record.last_msg.data[1 + txLen], link->init_info.frame_pad, dlc2len(link->init_info.TX_DLC) - 1 - txLen);
     link->tx_record.last_msg.dlc =(uint8_t)(lenToMinDlc(txLen+1));
     if (link->tx_record.last_msg.dlc < 8)
      link->tx_record.last_msg.dlc = 8;
    }
    else {
     link->tx_record.last_msg.dlc = link->init_info.TX_DLC;
    }
    link->tx_record.current_tx_index += txLen;
    link->tx_record.status = tx_cf_wait_tx;
    link->tx_record.last_msg_time_ms = link->current_time_ms;
    if (0 == link->init_info.L_Data_request(link, &link->tx_record.last_msg))
    {
     link->tx_record.rx_BS_tx++;
     link->tx_record.current_tx_SN++;
     link->tx_record.status = tx_cf_wait_confirm;
    }
    else {
     link->tx_record.status = tx_cf_wait_tx_retry;
    }
   }
  }
 }
 return 0;
}
static int tx_event_poll(can_iso_tp_link_t_p link, unsigned int user_ms)
{

 if (link->tx_record.status != tx_idle)
 {

  if ((user_ms - link->tx_record.last_msg_time_ms) > link->init_info.N_As)
  {
   if (link->init_info.N_USData_confirm)
   {
    if (link->tx_record.status == tx_wait_fc)
    {
     link->init_info.N_USData_confirm(link, link->tx_record.current_playload, link->tx_record.current_size, N_TIMEOUT_BS);
    }
    else {
     link->init_info.N_USData_confirm(link, link->tx_record.current_playload, link->tx_record.current_size, N_TIMEOUT_A);
    }
   }
   link->tx_record.status = tx_idle;
  }
  else if (link->tx_record.status == tx_sf_wait_tx)
  {

   if (0 == link->init_info.L_Data_request(link, &link->tx_record.last_msg))
   {
    link->tx_record.status = tx_sf_wait_confirm;
   }
  }
  else if (link->tx_record.status == tx_ff_wait_tx)
  {

   if (0 == link->init_info.L_Data_request(link, &link->tx_record.last_msg))
   {
    link->tx_record.status = tx_ff_wait_confirm;
   }
  }
  else if (link->tx_record.status == tx_cf_wait_tx_retry)
  {

   if (0 == link->init_info.L_Data_request(link, &link->tx_record.last_msg))
   {
    link->tx_record.rx_BS_tx++;
    link->tx_record.current_tx_SN++;
    link->tx_record.status = tx_cf_wait_confirm;
   }
  }
  else {

  }
 }
 tx_event_cf_frame(link);
 return 0;
}
static int tx_event_L_Data_Confirm(can_iso_tp_link_t_p link, int8_t error)
{
 if (link->tx_record.status == tx_sf_wait_confirm)
 {
  if (link->init_info.N_USData_confirm)
  {
   if (0 == error)
   {
    link->init_info.N_USData_confirm(link, link->tx_record.current_playload, link->tx_record.current_size, N_OK);
   }
   else {
    link->init_info.N_USData_confirm(link, link->tx_record.current_playload, link->tx_record.current_size, N_ERROR);
   }
  }
  link->tx_record.status = tx_idle;
 }
 else if (link->tx_record.status == tx_ff_wait_confirm)
 {
  if (link->tx_record.current_size > 0xfff)
  {
   link->tx_record.current_tx_index = dlc2len(link->init_info.TX_DLC) - 6;
  }
  else {
   link->tx_record.current_tx_index = dlc2len(link->init_info.TX_DLC) - 2;
  }
  link->tx_record.current_tx_SN = 1;
  link->tx_record.status = tx_wait_fc;
 }
 else if (link->tx_record.status == tx_cf_wait_confirm)
 {
  if (link->tx_record.rx_BS != 0)
  {
   if ((link->tx_record.rx_BS == link->tx_record.rx_BS_tx)
    && (link->tx_record.current_size != link->tx_record.current_tx_index)
    )
   {
    link->tx_record.status = tx_wait_fc;
   }
  }
  if (link->tx_record.status == tx_cf_wait_confirm)
  {
   link->tx_record.status = tx_cf_wait_tx;
  }
  tx_event_cf_frame(link);
 }
 return 0;
}
static int tx_event_N_USData_Request(can_iso_tp_link_t_p link, uint8_t isFunction, const uint8_t payload[], uint32_t size)
{
 unsigned int i;
 uint8_t single_frame_max_len = 7;
 if (link->init_info.TX_DLC > 8)
 {
  single_frame_max_len = dlc2len(link->init_info.TX_DLC) - 2;
 }

 if (link->tx_record.status == tx_idle)
 {
  if (size <= single_frame_max_len)
  {

   if (isFunction == 0)
   {
    link->tx_record.last_msg.id = link->init_info.tx_id;
   }
   else {
    link->tx_record.last_msg.id = link->init_info.funtion_id;
   }

   if (size <= 7)
   {
    link->tx_record.last_msg.data[0] = (uint8_t)size;
    for (i = 0; i < size; i++)
    {
     link->tx_record.last_msg.data[1 + i] = payload[i];
    }
    for (; i < single_frame_max_len; i++)
    {
     link->tx_record.last_msg.data[1 + i] = link->init_info.frame_pad;
    }
    link->tx_record.last_msg.dlc = 8;
   }
   else {
    link->tx_record.last_msg.data[0] = 0;
    link->tx_record.last_msg.data[1] = (uint8_t)size;
    for (i = 0; i < size; i++)
    {
     link->tx_record.last_msg.data[2 + i] = payload[i];
    }
    for (; i < single_frame_max_len; i++)
    {
     link->tx_record.last_msg.data[2 + i] = link->init_info.frame_pad;
    }
    link->tx_record.last_msg.dlc = (uint8_t)(lenToMinDlc(size+2));
   }
   link->tx_record.status = tx_sf_wait_tx;
   link->tx_record.last_msg_time_ms = link->current_time_ms;
   link->tx_record.current_playload = payload;
   link->tx_record.current_size = size;
   if (0 == link->init_info.L_Data_request(link, &link->tx_record.last_msg))
   {
    link->tx_record.status = tx_sf_wait_confirm;
   }
  }
  else {

   link->tx_record.N_WFT_cnt = 0;
   link->tx_record.last_msg.id = link->init_info.tx_id;
   if (size <= 0xfff)
   {
    link->tx_record.last_msg.data[0] = 0x10 | ((uint8_t)(size >> 8));
    link->tx_record.last_msg.data[1] = (uint8_t)(size & 0xff);
    memcpy(&link->tx_record.last_msg.data[2], payload, dlc2len(link->init_info.TX_DLC) - 2);
   }
   else {
    link->tx_record.last_msg.data[0] = 0x10;
    link->tx_record.last_msg.data[1] = 0;
    link->tx_record.last_msg.data[2] = (uint8_t)(size >> 24);
    link->tx_record.last_msg.data[3] = (uint8_t)(size >> 16);
    link->tx_record.last_msg.data[4] = (uint8_t)(size >> 8);
    link->tx_record.last_msg.data[5] = (uint8_t)(size);
    memcpy(&link->tx_record.last_msg.data[6], payload, dlc2len(link->init_info.TX_DLC) - 6);
   }
   link->tx_record.last_msg.dlc = link->init_info.TX_DLC;
   link->tx_record.status = tx_ff_wait_tx;
   link->tx_record.last_msg_time_ms = link->current_time_ms;
   link->tx_record.current_playload = payload;
   link->tx_record.current_size = size;
   if (0 == link->init_info.L_Data_request(link, &link->tx_record.last_msg))
   {
    link->tx_record.status = tx_ff_wait_confirm;
   }
  }
 }
 else {
  printf_debug_msg(&link->init_info, "can_iso_tp: ""can not tx diag request when last request is not done\n");
  if (link->init_info.N_USData_confirm)
  {
   link->init_info.N_USData_confirm(link, payload, size, N_ERROR);
  }
 }
 return 0;
}
static int tx_event_L_Data_indication(can_iso_tp_link_t_p link, const struct CAN_msg* rx_msg)
{
 if (link->tx_record.status == tx_wait_fc)
 {
  if (rx_msg->data[0] != 0x31)
  {
   link->tx_record.N_WFT_cnt = 0;
  }
  if (rx_msg->data[0] == 0x30)
  {
   link->tx_record.status = tx_cf_wait_tx;
   link->tx_record.rx_BS = rx_msg->data[1];
   link->tx_record.rx_BS_tx = 0;
   link->tx_record.rx_Stmin = rx_msg->data[2];
   if (link->tx_record.rx_Stmin > 0x7f)
   {
    link->tx_record.rx_Stmin = 1;
   }
   link->tx_record.last_msg_time_ms = link->current_time_ms - link->tx_record.rx_Stmin - 1;
  }
  else if (rx_msg->data[0] == 0x32)
  {
   link->tx_record.status = tx_idle;
   if (link->init_info.N_USData_confirm)
   {
    link->init_info.N_USData_confirm(link, link->tx_record.current_playload, link->tx_record.current_size, N_BUFFER_OVFLW);
   }
  }
  else if (rx_msg->data[0] == 0x31)
  {
   if (0 != link->init_info.N_WFTmax)
   {
    link->tx_record.N_WFT_cnt++;
    if (link->init_info.N_WFTmax <= link->tx_record.N_WFT_cnt)
    {
     link->tx_record.N_WFT_cnt = 0;
     link->tx_record.status = tx_idle;
    }
   }
  }
  else {
   if (link->init_info.N_USData_confirm)
   {
    link->init_info.N_USData_confirm(link, link->tx_record.current_playload, link->tx_record.current_size, N_INVALID_FS);
   }
   link->tx_record.status = tx_idle;
  }
 }
 tx_event_cf_frame(link);
 return 0;
}
static int rx_event_handle_poll(can_iso_tp_link_t_p link, unsigned int user_ms)
{
 if (link->rx_record.status == rx_wait_cf)
 {

  if ((user_ms - link->rx_record.last_msg_time_ms) > link->init_info.N_Cr)
  {
   if (link->init_info.N_USData_indication)
   {
    link->init_info.N_USData_indication(link, link->init_info.rx_buff, link->rx_record.rx_len, N_TIMEOUT_CR);
   }
   link->rx_record.status = rx_idle;
  }
 }
 if ((link->rx_record.status == rx_tx_fc_wait_confirm) || (link->rx_record.status == rx_tx_fc))
 {

  if ((user_ms - link->rx_record.last_msg_time_ms) > link->init_info.N_Ar)
  {
   if (link->init_info.N_USData_indication)
   {
    link->init_info.N_USData_indication(link, link->init_info.rx_buff, link->rx_record.rx_len, N_TIMEOUT_A);
   }
   link->rx_record.status = rx_idle;
  }
 }
 if (link->rx_record.status == rx_tx_fc)
 {

  if (0 == link->init_info.L_Data_request(link, &link->rx_record.last_msg))
  {
   link->rx_record.status = rx_tx_fc_wait_confirm;
  }
 }
 else if (link->rx_record.status == rx_tx_fc_overrun)
 {

  if (0 == link->init_info.L_Data_request(link, &link->rx_record.last_msg))
  {
   link->rx_record.status = rx_tx_fc_overrun_wait_confirm;
  }
 }
 return 0;
}
static int rx_event_L_Data_Confirm(can_iso_tp_link_t_p link, int8_t error)
{
 if (link->rx_record.status == rx_tx_fc_wait_confirm)
 {
  link->rx_record.status = rx_wait_cf;
 }
 else if (link->rx_record.status == rx_tx_fc_overrun_wait_confirm)
 {
  link->rx_record.status = rx_idle;
 }
 return 0;
}
static int rx_event_L_Data_indication(can_iso_tp_link_t_p link, const struct CAN_msg* rx_msg)
{
 if ((rx_msg->data[0] & 0xf0) == 0)
 {
  if (rx_msg->data[0] != 0)
  {
   if ((rx_msg->dlc <= 8) && (rx_msg->data[0] <= 7))
   {
    uint8_t len = rx_msg->data[0];
    uint8_t rx_len = dlc2len(rx_msg->dlc);
    if (rx_len >= (1 + len))
    {
     if (link->init_info.N_USData_indication)
     {
      if (link->rx_record.status != rx_idle)
      {
       link->init_info.N_USData_indication(link, link->init_info.rx_buff, link->rx_record.rx_len, N_UNEXP_PDU);
      }
      link->init_info.N_USData_indication(link, &rx_msg->data[1], rx_msg->data[0], N_OK);
      link->rx_record.status = rx_idle;
     }
    }
   }
  }
  else {
   if (rx_msg->dlc > 8)
   {
    uint8_t len = rx_msg->data[1];
    if (len > 0)
    {
     uint8_t rx_len = dlc2len(rx_msg->dlc);
     if (rx_len >= (2 + len))
     {

      if (lenToMinDlc(len + 2) == rx_msg->dlc)
      {
       link->init_info.N_USData_indication(link, &rx_msg->data[2], len, N_OK);
      }
     }
    }
   }
  }
 }
 else if ((rx_msg->data[0] & 0xf0) == 0x10) {
  uint8_t rx_index_offset;
  if (link->rx_record.status != rx_idle)
  {
   link->init_info.N_USData_indication(link, link->init_info.rx_buff, link->rx_record.rx_len, N_UNEXP_PDU);
  }

  link->rx_record.rx_len = (rx_msg->data[0] & 0xf) * 256 + rx_msg->data[1];
  if (0 == link->rx_record.rx_len)
  {
   link->rx_record.rx_len = (((uint32_t)rx_msg->data[2]) << 24)
    + (((uint32_t)rx_msg->data[3]) << 16)
    + (((uint32_t)rx_msg->data[4]) << 8)
    + (((uint32_t)rx_msg->data[5]))
    ;
   rx_index_offset = 6;
  }
  else {
   rx_index_offset = 2;
  }
  if (link->rx_record.rx_len <= link->init_info.rx_buff_len)
  {
   link->rx_record.rx_index = dlc2len(rx_msg->dlc) - rx_index_offset;
   memcpy(link->init_info.rx_buff, &rx_msg->data[rx_index_offset], link->rx_record.rx_index);
   link->rx_record.rx_SN = 0;
   link->rx_record.tx_BS_cnt = 0;
   link->rx_record.status = rx_tx_fc;
  }
  else {
   link->rx_record.status = rx_tx_fc_overrun;
  }
 }
 else if ((rx_msg->data[0] & 0xf0) == 0x20) {

  if (link->rx_record.status == rx_wait_cf)
  {
   uint32_t rx_len = link->rx_record.rx_len - link->rx_record.rx_index;
   if (rx_len > (uint32_t)(dlc2len(rx_msg->dlc) - 1))
   {
    rx_len = (dlc2len(rx_msg->dlc) - 1);
   }
   link->rx_record.rx_SN++;
   link->rx_record.last_msg_time_ms = link->current_time_ms;
   if ((link->rx_record.rx_SN & 0xf) == (rx_msg->data[0] & 0xf))
   {
    memcpy(&link->init_info.rx_buff[link->rx_record.rx_index], &rx_msg->data[1], rx_len);
    link->rx_record.rx_index += rx_len;
    if (link->rx_record.status != rx_idle)
    {
     if (link->rx_record.rx_index >= link->rx_record.rx_len)
     {
      if (link->init_info.N_USData_indication)
      {
       link->init_info.N_USData_indication(link, link->init_info.rx_buff, link->rx_record.rx_len, N_OK);
      }
      link->rx_record.status = rx_idle;
     }
     else {
      link->rx_record.tx_BS_cnt++;
      if (link->init_info.FC_BS != 0)
      {
       if ((link->rx_record.tx_BS_cnt % link->init_info.FC_BS) == 0)
       {
        link->rx_record.status = rx_tx_fc;
        link->rx_record.tx_BS_cnt = 0;
       }
      }
     }
    }
   }
   else {
    link->init_info.N_USData_indication(link, link->init_info.rx_buff, link->rx_record.rx_len, N_WRONG_SN);
    link->rx_record.status = rx_idle;
   }
  }
 }
 if (link->rx_record.status == rx_tx_fc)
 {
  link->rx_record.last_msg.id = link->init_info.tx_id;
  link->rx_record.last_msg.data[0] = 0x30;
  link->rx_record.last_msg.data[1] = link->init_info.FC_BS;
  link->rx_record.last_msg.data[2] = link->init_info.STmin;
  memset(&link->rx_record.last_msg.data[3], link->init_info.frame_pad, dlc2len(link->init_info.TX_DLC) - 3);
  link->rx_record.last_msg.dlc = link->init_info.TX_DLC;
  link->rx_record.last_msg_time_ms = link->current_time_ms;
  if (0 == link->init_info.L_Data_request(link, &link->rx_record.last_msg))
  {
   link->rx_record.status = rx_tx_fc_wait_confirm;
  }
 }
 else if (link->rx_record.status == rx_tx_fc_overrun)
 {
  link->rx_record.last_msg.id = link->init_info.tx_id;
  link->rx_record.last_msg.data[0] = 0x32;
  link->rx_record.last_msg.data[1] = 0;
  link->rx_record.last_msg.data[2] = 0;
  memset(&link->rx_record.last_msg.data[3], link->init_info.frame_pad, dlc2len(link->init_info.TX_DLC) - 3);
  link->rx_record.last_msg.dlc = link->init_info.TX_DLC;
  link->rx_record.last_msg_time_ms = link->current_time_ms;
  if (0 == link->init_info.L_Data_request(link, &link->rx_record.last_msg))
  {
   link->rx_record.status = rx_tx_fc_overrun_wait_confirm;
  }
 }
 return 0;
}

static void tx_event_poll_handle(void* par_src)
{
 struct time_poll_par_t* par = (struct time_poll_par_t*)par_src;
 tx_event_poll(par->link, par->user_ms);
 par->handle = (event_handle_t)0;
}
static void tx_event_L_Data_Confirm_handle(void* par_src)
{
 struct L_Data_confirm_par_t* par = (struct L_Data_confirm_par_t*)par_src;

 par->handle = (event_handle_t)0;
 tx_event_L_Data_Confirm(par->link, par->error);
}
static void tx_event_N_USData_Request_handle(void* par_src)
{
 struct N_USData_request_par_t* par = (struct N_USData_request_par_t*)par_src;
 tx_event_N_USData_Request(par->link, par->isFunction, par->payload, par->size);
 par->handle = (event_handle_t)0;
}
static void tx_event_L_Data_indication_handle(void* par_src)
{
 struct L_Data_indication_par_t* par = (struct L_Data_indication_par_t*)par_src;
 tx_event_L_Data_indication(par->link, &par->rx_msg);
 par->handle = (event_handle_t)0;
}
static void rx_event_poll_handle(void* par_src)
{
 struct time_poll_par_t* par = (struct time_poll_par_t*)par_src;
 rx_event_handle_poll(par->link, par->user_ms);
 par->handle = (event_handle_t)0;
}
static void rx_event_L_Data_Confirm_handle(void* par_src)
{
 struct L_Data_confirm_par_t* par = (struct L_Data_confirm_par_t*)par_src;
 int8_t error = par->error;
 par->handle = (event_handle_t)0;
 rx_event_L_Data_Confirm(par->link, error);
}
static void rx_event_L_Data_indication_handle(void* par_src)
{
 struct L_Data_indication_par_t* par = (struct L_Data_indication_par_t*)par_src;
 rx_event_L_Data_indication(par->link, &par->rx_msg);
 par->handle = (event_handle_t)0;
}


int iso_can_tp_create(can_iso_tp_link_t_p link, struct can_iso_tp_init_t* init)
{
 if ((struct can_iso_tp_init_t*)0 == init)
 {
  return 1;
 }
 if ((can_iso_tp_link_t_p)0 == link)
 {
  return 1;
 }
 if ((uint8_t*)0 == init->rx_buff)
 {
  printf_debug_msg(init, "can_iso_tp: " "null rx_buff\n");
  return 1;
 }
 if (init->rx_buff_len < 8)
 {
  printf_debug_msg(init, "can_iso_tp: " "rx_buff_len should not less than 8\n");
  return 1;
 }
 if (memcmp(&init->rx_id, &init->tx_id, sizeof(init->tx_id)) == 0)
 {
  printf_debug_msg(init, "can_iso_tp: " "rx_id should not = tx_id\n");
  return 1;
 }
 if (memcmp(&init->funtion_id, &init->tx_id, sizeof(init->tx_id)) == 0)
 {
  printf_debug_msg(init, "can_iso_tp: ""funtion_id should not = tx_id\n");
  return 1;
 }
 if (memcmp(&init->funtion_id, &init->rx_id, sizeof(init->tx_id)) == 0)
 {
  printf_debug_msg(init, "can_iso_tp: ""funtion_id should not = rx_id\n");
  return 1;
 }
 if (init->tx_id.isRemote != 0)
 {
  printf_debug_msg(init, "can_iso_tp: ""tx frame should not be remote frame\n");
  init->tx_id.isRemote = 0;
 }
 if (init->funtion_id.isRemote != 0)
 {
  printf_debug_msg(init, "can_iso_tp: ""funtion frame should not be remote frame\n");
  init->funtion_id.isRemote = 0;
 }
 if (init->rx_id.isRemote != 0)
 {
  printf_debug_msg(init, "can_iso_tp: ""rx frame should not be remote frame\n");
  init->rx_id.isRemote = 0;
 }

  if (init->TX_DLC < 8)
  {
   printf_debug_msg(init, "can_iso_tp: ""TX_DLC can not less than 8\n");
   init->TX_DLC = 8;
  }
  if (init->TX_DLC > 0xf)
  {
   printf_debug_msg(init, "can_iso_tp: ""TX_DLC can not more than 0xf\n");
   init->TX_DLC = 0xf;
  }
# 743 "Can_iso_tp/can_iso_tp/can_iso_tp.c"
 memset(link, 0, sizeof(struct can_iso_tp_link_t));
 link->init_info = *init;
 if (0 != event_manage_block_init(&link->rx_events.event_manage))
 {
  printf_debug_msg(init, "can_iso_tp: ""can not create rx_events mamage block\n");
  return 1;
 }
 if (0 != event_manage_block_init(&link->tx_events.event_manage))
 {
  printf_debug_msg(init, "can_iso_tp: ""can not create tx_events mamage block\n");
  return 1;
 }
 do{link->init_done_flag = ((unsigned int)0x74185295);}while(0);
 return 0;
}
void iso_can_tp_poll(can_iso_tp_link_t_p link, unsigned int user_ms)
{
 register volatile cpu_status_t cpu_sr;
 if (!(link->init_done_flag == ((unsigned int)0x74185295)))
 {
  return;
 }

 link->current_time_ms = user_ms;
 do{cpu_sr = 1;__disable_irq();}while(0);
 if (link->rx_events.time_poll_par.handle == (event_handle_t)0)
 {
  link->rx_events.time_poll_par.handle = rx_event_poll_handle;
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
  link->rx_events.time_poll_par.link = link;
  link->rx_events.time_poll_par.user_ms = user_ms;
  report_event_to_manage_block(&link->rx_events.event_manage, &link->rx_events.time_poll_par);
 }
 else {
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
  printf_debug_msg(&link->init_info, "iso_can_tp_poll cannot insert new rx evnent when last is not done.\n");
 }

 do{cpu_sr = 1;__disable_irq();}while(0);
 if (link->tx_events.time_poll_par.handle == (event_handle_t)0)
 {
  link->tx_events.time_poll_par.handle = tx_event_poll_handle;
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
  link->tx_events.time_poll_par.link = link;
  link->tx_events.time_poll_par.user_ms = user_ms;
  report_event_to_manage_block(&link->tx_events.event_manage, &link->tx_events.time_poll_par);
 }
 else {
  do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
  printf_debug_msg(&link->init_info, "iso_can_tp_poll cannot insert new tx evnent when last is not done.\n");
 }

}
int iso_can_tp_L_Data_confirm(can_iso_tp_link_t_p link, const struct CAN_msg* msg, int8_t error)
{
 int res = 1;
 if((can_iso_tp_link_t_p)0 == link)
 {
  return 1;
 }
 if (!(link->init_done_flag == ((unsigned int)0x74185295)))
 {
  return 1;
 }
 if (msg != (const struct CAN_msg*)0)
 {
  register volatile cpu_status_t cpu_sr;

  if ((msg->data[0] & 0xf0) == 0x30)
  {
   if ((msg->id.isExt == link->rx_record.last_msg.id.isExt)
    && (msg->id.id == link->rx_record.last_msg.id.id)
    && (msg->dlc == link->rx_record.last_msg.dlc)
    && (0 == memcmp(msg->data, link->rx_record.last_msg.data, dlc2len(link->rx_record.last_msg.dlc)))
    )
   {
    do{cpu_sr = 1;__disable_irq();}while(0);
    if (link->rx_events.L_Data_confirm_par.handle == (event_handle_t)0)
    {
     link->rx_events.L_Data_confirm_par.handle = rx_event_L_Data_Confirm_handle;
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     link->rx_events.L_Data_confirm_par.link = link;
     link->rx_events.L_Data_confirm_par.error = error;
     res = report_event_to_manage_block(&link->rx_events.event_manage, &link->rx_events.L_Data_confirm_par);
    }
    else {
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     printf_debug_msg(&link->init_info, "L_Data_confirm cannot insert new rx evnent when last is not done.\n");
    }

   }
  }
  else {
   if ((msg->id.isExt == link->tx_record.last_msg.id.isExt)
    && (msg->id.id == link->tx_record.last_msg.id.id)
    && (msg->dlc == link->tx_record.last_msg.dlc)
    && (0 == memcmp(msg->data, link->tx_record.last_msg.data, dlc2len(link->tx_record.last_msg.dlc)))
    )
   {
    do{cpu_sr = 1;__disable_irq();}while(0);
    if (link->tx_events.L_Data_confirm_par.handle == (event_handle_t)0)
    {
     link->tx_events.L_Data_confirm_par.handle = tx_event_L_Data_Confirm_handle;
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     link->tx_events.L_Data_confirm_par.link = link;
     link->tx_events.L_Data_confirm_par.error = error;
     res = report_event_to_manage_block(&link->tx_events.event_manage, &link->tx_events.L_Data_confirm_par);
    }
    else {
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     printf_debug_msg(&link->init_info, "L_Data_confirm cannot insert new tx evnent when last is not done.\n");
    }
   }
  }
 }
 else {

 }
 return res;
}
int iso_can_tp_L_Data_indication(can_iso_tp_link_t_p link, const struct CAN_msg* msg)
{
 int res = 1;
 if((can_iso_tp_link_t_p)0 == link)
 {
  return 1;
 }
 if (!(link->init_done_flag == ((unsigned int)0x74185295)))
 {
  return 1;
 }
 if (msg)
 {

  if (msg->id.isRemote != 0)
  {
   return 1;
  }







  if (((msg->id.isExt == link->init_info.rx_id.isExt)&& (msg->id.id == link->init_info.rx_id.id))
   || ((msg->id.isExt == link->init_info.funtion_id.isExt)&& (msg->id.id == link->init_info.funtion_id.id))
   )
  {
   register volatile cpu_status_t cpu_sr;

   if ((msg->data[0] & 0xf0) == 0x30)
   {
    do{cpu_sr = 1;__disable_irq();}while(0);
    if (link->tx_events.L_Data_indication_par.handle == (event_handle_t)0)
    {
     link->tx_events.L_Data_indication_par.handle = tx_event_L_Data_indication_handle;
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     link->tx_events.L_Data_indication_par.link = link;
     link->tx_events.L_Data_indication_par.rx_msg = *msg;
     res = report_event_to_manage_block(&link->tx_events.event_manage, &link->tx_events.L_Data_indication_par);
    }
    else {
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     printf_debug_msg(&link->init_info, "L_Data_indication cannot insert new tx evnent when last is not done.\n");
    }
   }
   else {
    do{cpu_sr = 1;__disable_irq();}while(0);
    if (link->rx_events.L_Data_indication_par.handle == (event_handle_t)0)
    {
     link->rx_events.L_Data_indication_par.handle = rx_event_L_Data_indication_handle;
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     link->rx_events.L_Data_indication_par.link = link;
     link->rx_events.L_Data_indication_par.rx_msg = *msg;
     res = report_event_to_manage_block(&link->rx_events.event_manage, &link->rx_events.L_Data_indication_par);
    }
    else {
     do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
     printf_debug_msg(&link->init_info, "L_Data_indication cannot insert new rx evnent when last is not done.\n");
    }
   }

  }
 }
 return res;
}
int iso_can_tp_N_USData_request(can_iso_tp_link_t_p link, uint8_t isFunction, const uint8_t payload[], uint32_t size)
{
 int res = 1;
 if((can_iso_tp_link_t_p)0 == link)
 {
  return 1;
 }
 if (!(link->init_done_flag == ((unsigned int)0x74185295)))
 {
  return 1;
 }
 if ((const uint8_t*)0 == payload)
 {
  res = 1;
  printf_debug_msg(&link->init_info, "can_iso_tp: ""can not tx diag request when payload == (const uint8_t*)0\n");
 }
 else {
  if (0 == size)
  {
   res = 1;
   printf_debug_msg(&link->init_info, "can_iso_tp: ""can not tx diag request when size == 0\n");
  }
  else {
   register volatile cpu_status_t cpu_sr;
   do{cpu_sr = 1;__disable_irq();}while(0);
   if (link->tx_events.N_USData_request_par.handle == (event_handle_t)0)
   {
    link->tx_events.N_USData_request_par.handle = tx_event_N_USData_Request_handle;
    do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
    link->tx_events.N_USData_request_par.link = link;
    link->tx_events.N_USData_request_par.isFunction = isFunction;
    link->tx_events.N_USData_request_par.payload = payload;
    link->tx_events.N_USData_request_par.size = size;
    res = report_event_to_manage_block(&link->tx_events.event_manage, &link->tx_events.N_USData_request_par);
   }
   else {
    do{if(cpu_sr>0)__enable_irq();cpu_sr = 0;}while(0);
    printf_debug_msg(&link->init_info, "N_USData_request cannot insert new tx evnent when last is not done.\n");
   }
  }
 }
 return res;
}
