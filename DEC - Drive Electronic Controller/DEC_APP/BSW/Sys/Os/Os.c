#include "Os.h"
#include "task_core0.h"
#include "McuSm.h"
#include "ColDet.h"
#include "Iven.h"
#include "EnergyMgmt.h"
#include "DcyHandler.h"
#include "Can.h"
#include "SysMgr.h"
#include "Bsw_Wrapper.h"
#include "ComMaster.h"
#include "DiagMaster.h"
#include "Dcm.h"
#include "timers_core0.h"

void Os_Init_C0(void);
void Os_Init_C1(void);
void Os_Init_C2(void);
void ASILD_APPL_PreCycle_Task_C1(void *pvParameters);
void ASILD_APPL_MainCycle_Task_C1(void *pvParameters);
void ASILD_APPL_PostCycle_Task_C1(void *pvParameters);
void ASILC_APPL_MainCycle_Task_C2(void *pvParameters);
void ASILD_APPL_MainCycle_Task_C0(void *pvParameters);
void ASILB_APPL_MainCycle_Task_C2(void *pvParameters);
void QM_APPL_MainCycle_Task_C0(void *pvParameters);
void ASILD_BSW_Task_C0(void *pvParameters);
void ASILD_BSW_Task_C1(void *pvParameters);
void ASILD_BSW_Task_C2(void *pvParameters);
void ASILB_BSW_Task_C0(void *pvParameters);
void QM_BSW_Task_C0(void *pvParameters);
//void Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1( TimerHandle_t xTimer );
//void Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1( TimerHandle_t xTimer );
//void Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1( TimerHandle_t xTimer );
//void Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2( TimerHandle_t xTimer );
void Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0( TimerHandle_t_core0 xTimer );
//void Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2( TimerHandle_t xTimer );
void Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0( TimerHandle_t_core0 xTimer );
void Alarm5ms_Callback_ASILD_BSW_Task_C0( TimerHandle_t_core0 xTimer );
//void Alarm5ms_Callback_ASILD_BSW_Task_C1( TimerHandle_t xTimer );
//void Alarm5ms_Callback_ASILD_BSW_Task_C2( TimerHandle_t xTimer );
void Alarm5ms_Callback_ASILB_BSW_Task_C0( TimerHandle_t_core0 xTimer );
void Alarm5ms_Callback_QM_BSW_Task_C0( TimerHandle_t_core0 xTimer );

long long OS_Counter = 0u;
long long IDLE_Counter = 0u;
uint8 Alarm250us_Flag_ASILD_APPL_PreCycle_Task_C1 = 0u;
uint8 Alarm1ms_Flag_ASILD_APPL_MainCycle_Task_C1 = 0u;
uint8 Alarm5ms_Flag_ASILD_APPL_PostCycle_Task_C1 = 0u;
uint8 Alarm5ms_Flag_ASILC_APPL_MainCycle_Task_C2 = 0u;
uint8 Alarm5ms_Flag_ASILD_APPL_MainCycle_Task_C0 = 0u;
uint8 Alarm5ms_Flag_ASILB_APPL_MainCycle_Task_C2 = 0u;
uint8 Alarm5ms_Flag_QM_APPL_MainCycle_Task_C0 = 0u;
uint8 Alarm5ms_Flag_ASILD_BSW_Task_C0 = 0u;
uint8 Alarm5ms_Flag_ASILD_BSW_Task_C1 = 0u;
uint8 Alarm5ms_Flag_ASILD_BSW_Task_C2 = 0u;
uint8 Alarm5ms_Flag_ASILB_BSW_Task_C0 = 0u;
uint8 Alarm5ms_Flag_QM_BSW_Task_C0 = 0u;
//TimerHandle_t Handler_Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1;
//TimerHandle_t Handler_Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1;
//TimerHandle_t Handler_Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1;
//TimerHandle_t Handler_Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2;
TimerHandle_t_core0 Handler_Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0;
//TimerHandle_t Handler_Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2;
TimerHandle_t_core0 Handler_Alarm5ms_Callback_ASILD_BSW_Task_C0;
TimerHandle_t_core0 Handler_Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0;
//TimerHandle_t Handler_Alarm5ms_Callback_ASILD_BSW_Task_C1;
//TimerHandle_t Handler_Alarm5ms_Callback_ASILD_BSW_Task_C2;
TimerHandle_t_core0 Handler_Alarm5ms_Callback_ASILB_BSW_Task_C0;
TimerHandle_t_core0 Handler_Alarm5ms_Callback_QM_BSW_Task_C0;
//TaskHandle_t ASILD_APPL_PreCycle_Task_C1_THandle    ;
//TaskHandle_t ASILD_APPL_MainCycle_Task_C1_THandle   ;
//TaskHandle_t ASILD_APPL_PostCycle_Task_C1_THandle   ;
//TaskHandle_t ASILC_APPL_MainCycle_Task_C2_THandle   ;
TaskHandle_t_core0 ASILD_APPL_MainCycle_Task_C0_THandle   ;
//TaskHandle_t ASILB_APPL_MainCycle_Task_C2_THandle   ;
TaskHandle_t_core0 QM_APPL_MainCycle_Task_C0_THandle      ;
TaskHandle_t_core0 ASILD_BSW_Task_C0_THandle              ;
//TaskHandle_t ASILD_BSW_Task_C1_THandle              ;
//TaskHandle_t ASILD_BSW_Task_C2_THandle              ;
TaskHandle_t_core0 ASILB_BSW_Task_C0_THandle              ;
TaskHandle_t_core0 QM_BSW_Task_C0_THandle                 ;

void Os_Init_C0(void)
{
    xTaskCreate_core0(ASILD_APPL_MainCycle_Task_C0, "ASILD_APPL_MainCycle_Task_C0", 4*configMINIMAL_STACK_SIZE_core0, NULL, 25u, &ASILD_APPL_MainCycle_Task_C0_THandle);

    xTaskCreate_core0(QM_APPL_MainCycle_Task_C0, "QM_APPL_MainCycle_Task_C0", 4*configMINIMAL_STACK_SIZE_core0, NULL, 29u, &QM_APPL_MainCycle_Task_C0_THandle);

    xTaskCreate_core0(ASILD_BSW_Task_C0, "ASILD_BSW_Task_C0", configMINIMAL_STACK_SIZE_core0, NULL, 28u, &ASILD_BSW_Task_C0_THandle);

    xTaskCreate_core0(ASILB_BSW_Task_C0, "ASILB_BSW_Task_C0", configMINIMAL_STACK_SIZE_core0, NULL, 27u, &ASILB_BSW_Task_C0_THandle);

    xTaskCreate_core0(QM_BSW_Task_C0, "QM_BSW_Task_C0", configMINIMAL_STACK_SIZE_core0, NULL, 26u, &QM_BSW_Task_C0_THandle);

    Handler_Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0 = xTimerCreate_core0("Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0",
            pdMS_TO_TICKS_core0(5u),
            1u,
            NULL,
            Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0);

    Handler_Alarm5ms_Callback_ASILD_BSW_Task_C0 = xTimerCreate_core0("Alarm5ms_Callback_ASILD_BSW_Task_C0",
            pdMS_TO_TICKS_core0(5u),
            1u,
            NULL,
            Alarm5ms_Callback_ASILD_BSW_Task_C0);

    Handler_Alarm5ms_Callback_ASILB_BSW_Task_C0 = xTimerCreate_core0("Alarm5ms_Callback_ASILB_BSW_Task_C0",
            pdMS_TO_TICKS_core0(5u),
            1u,
            NULL,
            Alarm5ms_Callback_ASILB_BSW_Task_C0);

    Handler_Alarm5ms_Callback_QM_BSW_Task_C0 = xTimerCreate_core0("Alarm5ms_Callback_QM_BSW_Task_C0",
            pdMS_TO_TICKS_core0(5u),
            1u,
            NULL,
            Alarm5ms_Callback_QM_BSW_Task_C0);

    Handler_Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0 = xTimerCreate_core0("Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0",
            pdMS_TO_TICKS_core0(5u),
            1u,
            NULL,
            Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0);

    xTimerStart_core0(Handler_Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0, pdMS_TO_TICKS_core0(5u));

    xTimerStart_core0(Handler_Alarm5ms_Callback_ASILD_BSW_Task_C0, pdMS_TO_TICKS_core0(5u));

    xTimerStart_core0(Handler_Alarm5ms_Callback_ASILB_BSW_Task_C0, pdMS_TO_TICKS_core0(5u));

    xTimerStart_core0(Handler_Alarm5ms_Callback_QM_BSW_Task_C0, pdMS_TO_TICKS_core0(5u));

    xTimerStart_core0(Handler_Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0, 5u);
}

void Os_Init_C1(void)
{
    //    xTaskCreate(ASILD_APPL_PreCycle_Task_C1, "ASILD_APPL_PreCycle_Task_C1", 1*configMINIMAL_STACK_SIZE, NULL, 31, &ASILD_APPL_PreCycle_Task_C1_THandle);
    //    xTaskCreate(ASILD_APPL_PostCycle_Task_C1, "ASILD_APPL_PostCycle_Task_C1", 1*configMINIMAL_STACK_SIZE, NULL, 30, &ASILD_APPL_PostCycle_Task_C1_THandle);
    //    xTaskCreate(ASILD_APPL_MainCycle_Task_C1, "ASILD_APPL_MainCycle_Task_C1", 1*configMINIMAL_STACK_SIZE, NULL, 29, &ASILD_APPL_MainCycle_Task_C1_THandle);
    //    xTaskCreate(ASILD_BSW_Task_C1, "ASILD_BSW_Task_C1", 4u*configMINIMAL_STACK_SIZE, NULL, 28, &ASILD_BSW_Task_C1_THandle);
    //    Handler_Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1 = xTimerCreate("Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1",1u, 1u, NULL, Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1);
    //    Handler_Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1 = xTimerCreate("Handler_Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1",4u, 1u, NULL, Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1);
    //    Handler_Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1 = xTimerCreate("Handler_Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1",20u, 1u, NULL, Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1);
    //    Handler_Alarm5ms_Callback_ASILD_BSW_Task_C1 = xTimerCreate("Alarm5ms_Callback_ASILD_BSW_Task_C1", 20u, 1u, NULL, Alarm5ms_Callback_ASILD_BSW_Task_C1);
    //    xTimerStart(Handler_Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1, 1u);
    //    xTimerStart(Handler_Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1, 1u);
    //    xTimerStart(Handler_Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1, 5u);
    //    xTimerStart(Handler_Alarm5ms_Callback_ASILD_BSW_Task_C1, 5u);
}

void Os_Init_C2(void)
{
    //    xTaskCreate(ASILC_APPL_MainCycle_Task_C2, "ASILC_APPL_MainCycle_Task_C2", 4*configMINIMAL_STACK_SIZE, NULL, 31, NULL);
    //    xTaskCreate(ASILB_APPL_MainCycle_Task_C2, "ASILB_APPL_MainCycle_Task_C2", 4*configMINIMAL_STACK_SIZE, NULL, 30, NULL);
    //    xTaskCreate(ASILD_BSW_Task_C2, "ASILD_BSW_Task_C2", 4*configMINIMAL_STACK_SIZE, NULL, 29, NULL);
    //    Handler_Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2 = xTimerCreate("Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2", 20u, 1u, NULL, Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2);
    //    Handler_Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2 = xTimerCreate("Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2", 20u, 1u, NULL, Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2);
    //    Handler_Alarm5ms_Callback_ASILD_BSW_Task_C2 = xTimerCreate("Alarm5ms_Callback_ASILD_BSW_Task_C2",20u, 1u, NULL, Alarm5ms_Callback_ASILD_BSW_Task_C2);
    //    xTimerStart(Handler_Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2, 5u);
    //    xTimerStart(Handler_Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2, 5u);
    //    xTimerStart(Handler_Alarm5ms_Callback_ASILD_BSW_Task_C2, 5u);
}

void vApplicationMallocFailedHook_core0(void)
{
    McuSm_PerformResetHook(380u, 1u);
}

void vApplicationStackOverflowHook_core0(TaskHandle_t_core0 xTask, char * pcTaskName )
{
    McuSm_PerformResetHook(379u, (uint8)pcTaskName);
}

void vApplicationTickHook_core0(void)
{
    OS_Counter++;
}

void vApplicationIdleHook_core0(void)
{
    IDLE_Counter++;
}

void vApplicationMallocFailedHook_core1(void)
{
    McuSm_PerformResetHook(380u, 1u);
}

void vApplicationStackOverflowHook_core1(TaskHandle_t_core0 xTask, char * pcTaskName )
{
    McuSm_PerformResetHook(379u, (uint8)pcTaskName);
}

void vApplicationTickHook_core1(void)
{
    OS_Counter++;
}

void vApplicationIdleHook_core1(void)
{
    IDLE_Counter++;
}


void vApplicationMallocFailedHook_core2(void)
{
    McuSm_PerformResetHook(380u, 1u);
}

void vApplicationStackOverflowHook_core2(TaskHandle_t_core0 xTask, char * pcTaskName )
{
    McuSm_PerformResetHook(379u, (uint8)pcTaskName);
}

void vApplicationTickHook_core2(void)
{
    OS_Counter++;
}

void vApplicationIdleHook_core2(void)
{
    IDLE_Counter++;
}


void ASILD_APPL_PreCycle_Task_C1(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm250us_Flag_ASILD_APPL_PreCycle_Task_C1)
        {
            Alarm250us_Flag_ASILD_APPL_PreCycle_Task_C1 = 0u;
            //EPSCtrl_CommandLoop_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void ASILD_APPL_MainCycle_Task_C1(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm1ms_Flag_ASILD_APPL_MainCycle_Task_C1)
        {
            Alarm1ms_Flag_ASILD_APPL_MainCycle_Task_C1 = 0u;
            //EPSCtrl_ControlLoop_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void ASILD_APPL_PostCycle_Task_C1(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_ASILD_APPL_PostCycle_Task_C1)
        {
            Alarm5ms_Flag_ASILD_APPL_PostCycle_Task_C1 = 0u;
            //EPSCtrl_DiagnosticLoop_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void ASILC_APPL_MainCycle_Task_C2(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_ASILC_APPL_MainCycle_Task_C2)
        {
            Alarm5ms_Flag_ASILC_APPL_MainCycle_Task_C2 = 0u;
            ColDet_MainFunction();
            //EMotorCtrl_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

uint32 counter_task = 0;

void ASILD_APPL_MainCycle_Task_C0(void *pvParameters)
{
    for(;;)
    {
        if(1u == Alarm5ms_Flag_ASILD_APPL_MainCycle_Task_C0)
        {
            Alarm5ms_Flag_ASILD_APPL_MainCycle_Task_C0 = 0u;
            ComMaster_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        counter_task++;

        vTaskSuspend_core0(NULL);
    }
}

void ASILB_APPL_MainCycle_Task_C2(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_ASILB_APPL_MainCycle_Task_C2)
        {
            Alarm5ms_Flag_ASILB_APPL_MainCycle_Task_C2 = 0u;
            Iven_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void QM_APPL_MainCycle_Task_C0(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_QM_APPL_MainCycle_Task_C0)
        {
            Alarm5ms_Flag_QM_APPL_MainCycle_Task_C0 = 0u;
            EnergyMgmt_MainFunction();
            DcyHandler_MainFunction();
            DiagMaster_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void ASILD_BSW_Task_C0(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_ASILD_BSW_Task_C0)
        {
            Alarm5ms_Flag_ASILD_BSW_Task_C0 = 0u;
            Bsw_Wrapper_MainFunction_C0();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void ASILD_BSW_Task_C1(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_ASILD_BSW_Task_C1)
        {
            Alarm5ms_Flag_ASILD_BSW_Task_C1 = 0u;
            Bsw_Wrapper_MainFunction_C1();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void ASILD_BSW_Task_C2(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_ASILD_BSW_Task_C2)
        {
            Alarm5ms_Flag_ASILD_BSW_Task_C2 = 0u;
            Bsw_Wrapper_MainFunction_C2();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void ASILB_BSW_Task_C0(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_ASILB_BSW_Task_C0)
        {
            Alarm5ms_Flag_ASILB_BSW_Task_C0 = 0u;
            SysMgr_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

void QM_BSW_Task_C0(void *pvParameters)
{
    while(1)
    {
        if(1u == Alarm5ms_Flag_QM_BSW_Task_C0)
        {
            Alarm5ms_Flag_QM_BSW_Task_C0 = 0u;
            Dcm_MainFunction();
            Can_MainFunction();
        }
        else
        {
            /* Do nothing. */
        }

        vTaskSuspend_core0(NULL);
    }
}

//void Alarm250us_Callback_ASILD_APPL_PreCycle_Task_C1( TimerHandle_t xTimer )
//{
//    Alarm250us_Flag_ASILD_APPL_PreCycle_Task_C1 = 1u;
//    vTaskResume(ASILD_APPL_PreCycle_Task_C1_THandle);
//}
//
//void Alarm1ms_Callback_ASILD_APPL_MainCycle_Task_C1( TimerHandle_t xTimer )
//{
//    Alarm1ms_Flag_ASILD_APPL_MainCycle_Task_C1 = 1u;
//    vTaskResume(ASILD_APPL_MainCycle_Task_C1_THandle);
//}
//
//void Alarm5ms_Callback_ASILD_APPL_PostCycle_Task_C1( TimerHandle_t xTimer )
//{
//    Alarm5ms_Flag_ASILD_APPL_PostCycle_Task_C1 = 1u;
//    vTaskResume(ASILD_APPL_PostCycle_Task_C1_THandle);
//}
//
//void Alarm5ms_Callback_ASILC_APPL_MainCycle_Task_C2( TimerHandle_t xTimer )
//{
//    Alarm5ms_Flag_ASILC_APPL_MainCycle_Task_C2 = 1u;
//    vTaskResume(ASILC_APPL_MainCycle_Task_C2_THandle);
//}

uint32 counter_timer = 0u;

void Alarm5ms_Callback_ASILD_APPL_MainCycle_Task_C0( TimerHandle_t_core0 xTimer )
{
    counter_timer++;
    Alarm5ms_Flag_ASILD_APPL_MainCycle_Task_C0 = 1u;
    vTaskResume_core0(ASILD_APPL_MainCycle_Task_C0_THandle);
}

//void Alarm5ms_Callback_ASILB_APPL_MainCycle_Task_C2( TimerHandle_t xTimer )
//{
//    Alarm5ms_Flag_ASILB_APPL_MainCycle_Task_C2 = 1u;
//    vTaskResume(ASILB_APPL_MainCycle_Task_C2_THandle);
//}

void Alarm5ms_Callback_QM_APPL_MainCycle_Task_C0( TimerHandle_t_core0 xTimer )
{
    Alarm5ms_Flag_QM_APPL_MainCycle_Task_C0 = 1u;
    vTaskResume_core0(QM_APPL_MainCycle_Task_C0_THandle);
}

void Alarm5ms_Callback_ASILD_BSW_Task_C0( TimerHandle_t_core0 xTimer )
{
    Alarm5ms_Flag_ASILD_BSW_Task_C0 = 1u;
    vTaskResume_core0(ASILD_BSW_Task_C0_THandle);
}

//void Alarm5ms_Callback_ASILD_BSW_Task_C1( TimerHandle_t xTimer )
//{
//    Alarm5ms_Flag_ASILD_BSW_Task_C1 = 1u;
//    vTaskResume(ASILD_BSW_Task_C2_THandle);
//}
//
//void Alarm5ms_Callback_ASILD_BSW_Task_C2( TimerHandle_t xTimer )
//{
//    Alarm5ms_Flag_ASILD_BSW_Task_C2 = 1u;
//    vTaskResume(ASILD_BSW_Task_C2_THandle);
//}

void Alarm5ms_Callback_ASILB_BSW_Task_C0( TimerHandle_t_core0 xTimer )
{
    Alarm5ms_Flag_ASILB_BSW_Task_C0 = 1u;
    vTaskResume_core0(ASILB_BSW_Task_C0_THandle);
}

void Alarm5ms_Callback_QM_BSW_Task_C0( TimerHandle_t_core0 xTimer )
{
    Alarm5ms_Flag_QM_BSW_Task_C0 = 1u;
    vTaskResume_core0(QM_BSW_Task_C0_THandle);
}
