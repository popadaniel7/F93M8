#include "Ifx_Types.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "timers.h"

extern void Os_Init_C0(void);
extern void Os_Init_C1(void);
extern void Os_Init_C2(void);
extern void ASILD_APPL_PreCycle_Task_C1(void *pvParameters);
extern void ASILD_APPL_MainCycle_Task_C1(void *pvParameters);
extern void ASILD_APPL_PostCycle_Task_C1(void *pvParameters);
extern void ASILC_APPL_MainCycle_Task_C2(void *pvParameters);
extern void ASILD_APPL_MainCycle_Task_C0(void *pvParameters);
extern void ASILB_APPL_MainCycle_Task_C2(void *pvParameters);
extern void QM_APPL_MainCycle_Task_C0(void *pvParameters);
extern void ASILD_BSW_Task_C0(void *pvParameters);
extern void ASILD_BSW_Task_C1(void *pvParameters);
extern void ASILD_BSW_Task_C2(void *pvParameters);
extern void ASILB_BSW_Task_C0(void *pvParameters);
extern void QM_BSW_Task_C0(void *pvParameters);
extern void Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1( TimerHandle_t xTimer );
extern void Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILD_BSW_Task_C0( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILD_BSW_Task_C1( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILD_BSW_Task_C2( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_ASILB_BSW_Task_C0( TimerHandle_t xTimer );
extern void Alarm5ms_Callback_QM_BSW_Task_C0( TimerHandle_t xTimer );
extern uint8 Alarm250us_Flag_ASILD_APPL_PreCycle_Task_C1;
extern uint8 Alarm1ms_Flag_ASILD_APPL_MainCycle_Task_C1;
extern uint8 Alarm5ms_Flag_ASILD_APPL_PostCycle_Task_C1;
extern uint8 Alarm5ms_Flag_ASILC_APPL_MainCycle_Task_C2;
extern uint8 Alarm5ms_Flag_ASILD_APPL_MainCycle_Task_C0;
extern uint8 Alarm5ms_Flag_ASILB_APPL_MainCycle_Task_C2;
extern uint8 Alarm5ms_Flag_QM_APPL_MainCycle_Task_C0;
extern uint8 Alarm5ms_Flag_ASILD_BSW_Task_C0;
extern uint8 Alarm5ms_Flag_ASILD_BSW_Task_C1;
extern uint8 Alarm5ms_Flag_ASILD_BSW_Task_C2;
extern uint8 Alarm5ms_Flag_ASILB_BSW_Task_C0;
extern uint8 Alarm5ms_Flag_QM_BSW_Task_C0;
extern TimerHandle_t Handler_Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1;
extern TimerHandle_t Handler_Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2;
extern TimerHandle_t Handler_Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILD_BSW_Task_C0;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILD_BSW_Task_C1;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILD_BSW_Task_C2;
extern TimerHandle_t Handler_Alarm5ms_Callback_ASILB_BSW_Task_C0;
extern TimerHandle_t Handler_Alarm5ms_Callback_QM_BSW_Task_C0;
extern long long OS_Counter;
extern long long IDLE_Counter;
