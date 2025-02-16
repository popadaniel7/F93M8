/*
 * FreeRTOS_core1 Kernel V10.5.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS_core1.org
 * https://github.com/FreeRTOS_core1
 *
 */

/* Standard includes. */
#include <stdlib.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 prevents task_core1.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core1.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1

#include "FreeRTOS_core1.h"
#include "task_core1.h"
#include "queue_core1.h"
#include "timers_core1.h"

#if ( INCLUDE_xTimerPendFunctionCall_core1 == 1 ) && ( configUSE_TIMERS_core1 == 0 )
    #error configUSE_TIMERS_core1 must be set to 1 to make the xTimerPendFunctionCall_core1() function available.
#endif

/* Lint e9021, e961 and e750 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 to be defined
 * for the header files above, but not in this file, in order to generate the
 * correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 /*lint !e9021 !e961 !e750. */


/* This entire source file will be skipped if the application is not configured
 * to include software timer functionality.  This #if is closed at the very bottom
 * of this file.  If you want to include software timer functionality then ensure
 * configUSE_TIMERS_core1 is set to 1 in FreeRTOSConfig.h. */
#if ( configUSE_TIMERS_core1 == 1 )

/* Misc definitions. */
    #define tmrNO_DELAY_core1                    ( ( TickType_t_core1 ) 0U )
    #define tmrMAX_TIME_BEFORE_OVERFLOW_core1    ( ( TickType_t_core1 ) -1 )

/* The name assigned to the timer service task_core1.  This can be overridden by
 * defining trmTIMER_SERVICE_TASK_NAME in FreeRTOSConfig.h. */
    #ifndef configTIMER_SERVICE_TASK_NAME_core1
        #define configTIMER_SERVICE_TASK_NAME_core1    "Tmr Svc_core1"
    #endif

/* Bit definitions used in the ucStatus_core1 member of a timer structure. */
    #define tmrSTATUS_IS_ACTIVE_core1                  ( ( uint8_t ) 0x01 )
    #define tmrSTATUS_IS_STATICALLY_ALLOCATED_core1    ( ( uint8_t ) 0x02 )
    #define tmrSTATUS_IS_AUTORELOAD_core1              ( ( uint8_t ) 0x04 )

/* The definition of the timers_core1 themselves. */
    typedef struct tmrTimerControl_core1                  /* The old naming convention is used to prevent breaking kernel aware debuggers. */
    {
        const char * pcTimerName_core1;                   /*<< Text name.  This is not used by the kernel, it is included simply to make debugging easier. */ /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
        ListItem_t_core1 xTimerListItem_core1;                  /*<< Standard linked list item as used by all kernel features for event management. */
        TickType_t_core1 xTimerPeriodInTicks_core1;             /*<< How quickly and often the timer expires. */
        void * pvTimerID_core1;                           /*<< An ID to identify the timer.  This allows the timer to be identified when the same callback is used for multiple timers_core1. */
        TimerCallbackFunction_t_core1 pxCallbackFunction_core1; /*<< The function that will be called when the timer expires. */
        #if ( configUSE_TRACE_FACILITY_core1 == 1 )
            UBaseType_t_core1 uxTimerNumber_core1;              /*<< An ID assigned by trace tools such as FreeRTOS_core1+Trace */
        #endif
        uint8_t ucStatus_core1;                           /*<< Holds bits to say if the timer was statically allocated or not, and if it is active or not. */
    } xTIMER_core1;

/* The old xTIMER_core1 name is maintained above then typedefed to the new Timer_t_core1
 * name below to enable the use of older kernel aware debuggers. */
    typedef xTIMER_core1 Timer_t_core1;

/* The definition of messages that can be sent and received on the timer queue.
 * Two types of message can be queued - messages that manipulate a software timer,
 * and messages that request the execution of a non-timer related callback.  The
 * two message types are defined in two separate structures, xTimerParametersType
 * and xCallbackParametersType respectively. */
    typedef struct tmrTimerParameters_core1
    {
        TickType_t_core1 xMessageValue_core1; /*<< An optional value used by a subset of commands, for example, when changing the period of a timer. */
        Timer_t_core1 * pxTimer_core1;        /*<< The timer to which the command will be applied. */
    } TimerParameter_t_core1;


    typedef struct tmrCallbackParameters_core1
    {
        PendedFunction_t_core1 pxCallbackFunction_core1; /* << The callback function to execute. */
        void * pvParameter1_core1;                 /* << The value that will be used as the callback functions first parameter. */
        uint32_t ulParameter2_core1;               /* << The value that will be used as the callback functions second parameter. */
    } CallbackParameters_t_core1;

/* The structure that contains the two message types, along with an identifier
 * that is used to determine which message type is valid. */
    typedef struct tmrTimerQueueMessage_core1
    {
        BaseType_t_core1 xMessageID_core1; /*<< The command being sent to the timer service task_core1. */
        union
        {
            TimerParameter_t_core1 xTimerParameters_core1;

            /* Don't include xCallbackParameters_core1 if it is not going to be used as
             * it makes the structure (and therefore the timer queue) larger. */
            #if ( INCLUDE_xTimerPendFunctionCall_core1 == 1 )
                CallbackParameters_t_core1 xCallbackParameters_core1;
            #endif /* INCLUDE_xTimerPendFunctionCall_core1 */
        } u;
    } DaemonTaskMessage_t_core1;

/*lint -save -e956 A manual analysis and inspection has been used to determine
 * which static variables must be declared volatile. */

/* The list in which active timers_core1 are stored.  Timers are referenced in expire
 * time order, with the nearest expiry time at the front of the list.  Only the
 * timer service task_core1 is allowed to access these lists.
 * xActiveTimerList1_core1 and xActiveTimerList2_core1 could be at function scope but that
 * breaks some kernel aware debuggers, and debuggers that reply on removing the
 * static qualifier. */
    PRIVILEGED_DATA_core1 static List_t_core1 xActiveTimerList1_core1;
    PRIVILEGED_DATA_core1 static List_t_core1 xActiveTimerList2_core1;
    PRIVILEGED_DATA_core1 static List_t_core1 * pxCurrentTimerList_core1;
    PRIVILEGED_DATA_core1 static List_t_core1 * pxOverflowTimerList_core1;

/* A queue that is used to send commands to the timer service task_core1. */
    PRIVILEGED_DATA_core1 static QueueHandle_t_core1 xTimerQueue_core1 = NULL;
    PRIVILEGED_DATA_core1 static TaskHandle_t_core1 xTimerTaskHandle_core1 = NULL;

/*lint -restore */

/*-----------------------------------------------------------*/

/*
 * Initialise the infrastructure used by the timer service task_core1 if it has not
 * been initialised already.
 */
    static void prvCheckForValidListAndQueue_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * The timer service task_core1 (daemon).  Timer functionality is controlled by this
 * task_core1.  Other tasks communicate with the timer service task_core1 using the
 * xTimerQueue_core1 queue.
 */
    static portTASK_FUNCTION_PROTO_core1( prvTimerTask_core1, pvParameters_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Called by the timer service task_core1 to interpret and process a command it
 * received on the timer queue.
 */
    static void prvProcessReceivedCommands_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * Insert the timer into either xActiveTimerList1_core1, or xActiveTimerList2_core1,
 * depending on if the expire time causes a timer counter overflow.
 */
    static BaseType_t_core1 prvInsertTimerInActiveList_core1( Timer_t_core1 * const pxTimer_core1,
                                                  const TickType_t_core1 xNextExpiryTime_core1,
                                                  const TickType_t_core1 xTimeNow_core1,
                                                  const TickType_t_core1 xCommandTime_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Reload the specified auto-reload timer.  If the reloading is backlogged,
 * clear the backlog, calling the callback for each additional reload.  When
 * this function returns, the next expiry time is after xTimeNow_core1.
 */
    static void prvReloadTimer_core1( Timer_t_core1 * const pxTimer_core1,
                                TickType_t_core1 xExpiredTime_core1,
                                const TickType_t_core1 xTimeNow_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * An active timer has reached its expire time.  Reload the timer if it is an
 * auto-reload timer, then call its callback.
 */
    static void prvProcessExpiredTimer_core1( const TickType_t_core1 xNextExpireTime_core1,
                                        const TickType_t_core1 xTimeNow_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * The tick count has overflowed.  Switch the timer lists after ensuring the
 * current timer list does not still reference some timers_core1.
 */
    static void prvSwitchTimerLists_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * Obtain the current tick count, setting *pxTimerListsWereSwitched_core1 to pdTRUE_core1
 * if a tick count overflow occurred since prvSampleTimeNow_core1() was last called.
 */
    static TickType_t_core1 prvSampleTimeNow_core1( BaseType_t_core1 * const pxTimerListsWereSwitched_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * If the timer list contains any active timers_core1 then return the expire time of
 * the timer that will expire first and set *pxListWasEmpty_core1 to false.  If the
 * timer list does not contain any timers_core1 then return 0 and set *pxListWasEmpty_core1
 * to pdTRUE_core1.
 */
    static TickType_t_core1 prvGetNextExpireTime_core1( BaseType_t_core1 * const pxListWasEmpty_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * If a timer has expired, process it.  Otherwise, block the timer service task_core1
 * until either a timer does expire or a command is received.
 */
    static void prvProcessTimerOrBlockTask_core1( const TickType_t_core1 xNextExpireTime_core1,
                                            BaseType_t_core1 xListWasEmpty_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Called after a Timer_t_core1 structure has been allocated either statically or
 * dynamically to fill in the structure's members.
 */
    static void prvInitialiseNewTimer_core1( const char * const pcTimerName_core1, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                       const TickType_t_core1 xTimerPeriodInTicks_core1,
                                       const BaseType_t_core1 xAutoReload_core1,
                                       void * const pvTimerID_core1,
                                       TimerCallbackFunction_t_core1 pxCallbackFunction_core1,
                                       Timer_t_core1 * pxNewTimer_core1 ) PRIVILEGED_FUNCTION_core1;
/*-----------------------------------------------------------*/

    BaseType_t_core1 xTimerCreateTimerTask_core1( void )
    {
        BaseType_t_core1 xReturn_core1 = pdFAIL_core1;

        /* This function is called when the scheduler is started if
         * configUSE_TIMERS_core1 is set to 1.  Check that the infrastructure used by the
         * timer service task_core1 has been created/initialised.  If timers_core1 have already
         * been created then the initialisation will already have been performed. */
        prvCheckForValidListAndQueue_core1();

        if( xTimerQueue_core1 != NULL )
        {
            #if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )
            {
                StaticTask_t_core1 * pxTimerTaskTCBBuffer_core1 = NULL;
                StackType_t_core1 * pxTimerTaskStackBuffer_core1 = NULL;
                uint32_t ulTimerTaskStackSize_core1;

                vApplicationGetTimerTaskMemory_core1( &pxTimerTaskTCBBuffer_core1, &pxTimerTaskStackBuffer_core1, &ulTimerTaskStackSize_core1 );
                xTimerTaskHandle_core1 = xTaskCreateStatic_core1( prvTimerTask_core1,
                                                      configTIMER_SERVICE_TASK_NAME_core1,
                                                      ulTimerTaskStackSize_core1,
                                                      NULL,
                                                      ( ( UBaseType_t_core1 ) configTIMER_TASK_PRIORITY_core1 ) | portPRIVILEGE_BIT_core1,
                                                      pxTimerTaskStackBuffer_core1,
                                                      pxTimerTaskTCBBuffer_core1 );

                if( xTimerTaskHandle_core1 != NULL )
                {
                    xReturn_core1 = pdPASS_core1;
                }
            }
            #else /* if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 ) */
            {
                xReturn_core1 = xTaskCreate_core1( prvTimerTask_core1,
                                       configTIMER_SERVICE_TASK_NAME_core1,
                                       configTIMER_TASK_STACK_DEPTH_core1,
                                       NULL,
                                       ( ( UBaseType_t_core1 ) configTIMER_TASK_PRIORITY_core1 ) | portPRIVILEGE_BIT_core1,
                                       &xTimerTaskHandle_core1 );
            }
            #endif /* configSUPPORT_STATIC_ALLOCATION_core1 */
        }
        else
        {
            //mtCOVERAGE_TEST_MARKER_core1();
        }

        //configASSERT_core1( xReturn_core1 );
        return xReturn_core1;
    }
/*-----------------------------------------------------------*/

    #if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )

        TimerHandle_t_core1 xTimerCreate_core1( const char * const pcTimerName_core1, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                    const TickType_t_core1 xTimerPeriodInTicks_core1,
                                    const BaseType_t_core1 xAutoReload_core1,
                                    void * const pvTimerID_core1,
                                    TimerCallbackFunction_t_core1 pxCallbackFunction_core1 )
        {
            Timer_t_core1 * pxNewTimer_core1;

            pxNewTimer_core1 = ( Timer_t_core1 * ) pvPortMalloc_core1( sizeof( Timer_t_core1 ) ); /*lint !e9087 !e9079 All values returned by pvPortMalloc_core1() have at least the alignment required by the MCU's stack, and the first member of Timer_t_core1 is always a pointer to the timer's mame. */

            if( pxNewTimer_core1 != NULL )
            {
                /* Status is thus far zero as the timer is not created statically
                 * and has not been started.  The auto-reload bit may get set in
                 * prvInitialiseNewTimer_core1. */
                pxNewTimer_core1->ucStatus_core1 = 0x00;
                prvInitialiseNewTimer_core1( pcTimerName_core1, xTimerPeriodInTicks_core1, xAutoReload_core1, pvTimerID_core1, pxCallbackFunction_core1, pxNewTimer_core1 );
            }

            return pxNewTimer_core1;
        }

    #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core1 */
/*-----------------------------------------------------------*/

    #if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )

        TimerHandle_t_core1 xTimerCreateStatic_core1( const char * const pcTimerName_core1, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                          const TickType_t_core1 xTimerPeriodInTicks_core1,
                                          const BaseType_t_core1 xAutoReload_core1,
                                          void * const pvTimerID_core1,
                                          TimerCallbackFunction_t_core1 pxCallbackFunction_core1,
                                          StaticTimer_t_core1 * pxTimerBuffer_core1 )
        {
            Timer_t_core1 * pxNewTimer_core1;

            #if ( configASSERT_DEFINED_core1 == 1 )
            {
                /* Sanity check that the size of the structure used to declare a
                 * variable of type StaticTimer_t_core1 equals the size of the real timer
                 * structure. */
                volatile size_t xSize_core1 = sizeof( StaticTimer_t_core1 );
                configASSERT_core1( xSize_core1 == sizeof( Timer_t_core1 ) );
                ( void ) xSize_core1; /* Keeps lint quiet when configASSERT_core1() is not defined. */
            }
            #endif /* configASSERT_DEFINED_core1 */

            /* A pointer to a StaticTimer_t_core1 structure MUST be provided, use it. */
            configASSERT_core1( pxTimerBuffer_core1 );
            pxNewTimer_core1 = ( Timer_t_core1 * ) pxTimerBuffer_core1; /*lint !e740 !e9087 StaticTimer_t_core1 is a pointer to a Timer_t_core1, so guaranteed to be aligned and sized correctly (checked by an assert()), so this is safe. */

            if( pxNewTimer_core1 != NULL )
            {
                /* Timers can be created statically or dynamically so note this
                 * timer was created statically in case it is later deleted.  The
                 * auto-reload bit may get set in prvInitialiseNewTimer_core1(). */
                pxNewTimer_core1->ucStatus_core1 = tmrSTATUS_IS_STATICALLY_ALLOCATED_core1;

                prvInitialiseNewTimer_core1( pcTimerName_core1, xTimerPeriodInTicks_core1, xAutoReload_core1, pvTimerID_core1, pxCallbackFunction_core1, pxNewTimer_core1 );
            }

            return pxNewTimer_core1;
        }

    #endif /* configSUPPORT_STATIC_ALLOCATION_core1 */
/*-----------------------------------------------------------*/

    static void prvInitialiseNewTimer_core1( const char * const pcTimerName_core1, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                       const TickType_t_core1 xTimerPeriodInTicks_core1,
                                       const BaseType_t_core1 xAutoReload_core1,
                                       void * const pvTimerID_core1,
                                       TimerCallbackFunction_t_core1 pxCallbackFunction_core1,
                                       Timer_t_core1 * pxNewTimer_core1 )
    {
        /* 0 is not a valid value for xTimerPeriodInTicks_core1. */
        configASSERT_core1( ( xTimerPeriodInTicks_core1 > 0 ) );

        /* Ensure the infrastructure used by the timer service task_core1 has been
         * created/initialised. */
        prvCheckForValidListAndQueue_core1();

        /* Initialise the timer structure members using the function
         * parameters. */
        pxNewTimer_core1->pcTimerName_core1 = pcTimerName_core1;
        pxNewTimer_core1->xTimerPeriodInTicks_core1 = xTimerPeriodInTicks_core1;
        pxNewTimer_core1->pvTimerID_core1 = pvTimerID_core1;
        pxNewTimer_core1->pxCallbackFunction_core1 = pxCallbackFunction_core1;
        vListInitialiseItem_core1( &( pxNewTimer_core1->xTimerListItem_core1 ) );

        if( xAutoReload_core1 != pdFALSE_core1 )
        {
            pxNewTimer_core1->ucStatus_core1 |= tmrSTATUS_IS_AUTORELOAD_core1;
        }

        traceTIMER_CREATE_core1( pxNewTimer_core1 );
    }
/*-----------------------------------------------------------*/

    BaseType_t_core1 xTimerGenericCommand_core1( TimerHandle_t_core1 xTimer_core1,
                                     const BaseType_t_core1 xCommandID_core1,
                                     const TickType_t_core1 xOptionalValue_core1,
                                     BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1,
                                     const TickType_t_core1 xTicksToWait_core1 )
    {
        BaseType_t_core1 xReturn_core1 = pdFAIL_core1;
        DaemonTaskMessage_t_core1 xMessage_core1;

        configASSERT_core1( xTimer_core1 );

        /* Send a message to the timer service task_core1 to perform a particular action
         * on a particular timer definition. */
        if( xTimerQueue_core1 != NULL )
        {
            /* Send a command to the timer service task_core1 to start the xTimer_core1 timer. */
            xMessage_core1.xMessageID_core1 = xCommandID_core1;
            xMessage_core1.u.xTimerParameters_core1.xMessageValue_core1 = xOptionalValue_core1;
            xMessage_core1.u.xTimerParameters_core1.pxTimer_core1 = xTimer_core1;

            if( xCommandID_core1 < tmrFIRST_FROM_ISR_COMMAND_core1 )
            {
                if( xTaskGetSchedulerState_core1() == taskSCHEDULER_RUNNING_core1 )
                {
                    xReturn_core1 = xQueueSendToBack_core1( xTimerQueue_core1, &xMessage_core1, xTicksToWait_core1 );
                }
                else
                {
                    xReturn_core1 = xQueueSendToBack_core1( xTimerQueue_core1, &xMessage_core1, tmrNO_DELAY_core1 );
                }
            }
            else
            {
                xReturn_core1 = xQueueSendToBackFromISR_core1( xTimerQueue_core1, &xMessage_core1, pxHigherPriorityTaskWoken_core1 );
            }

            traceTIMER_COMMAND_SEND_core1( xTimer_core1, xCommandID_core1, xOptionalValue_core1, xReturn_core1 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }

        return xReturn_core1;
    }
/*-----------------------------------------------------------*/

    TaskHandle_t_core1 xTimerGetTimerDaemonTaskHandle_core1( void )
    {
        /* If xTimerGetTimerDaemonTaskHandle_core1() is called before the scheduler has been
         * started, then xTimerTaskHandle_core1 will be NULL. */
        configASSERT_core1( ( xTimerTaskHandle_core1 != NULL ) );
        return xTimerTaskHandle_core1;
    }
/*-----------------------------------------------------------*/

    TickType_t_core1 xTimerGetPeriod_core1( TimerHandle_t_core1 xTimer_core1 )
    {
        Timer_t_core1 * pxTimer_core1 = xTimer_core1;

        configASSERT_core1( xTimer_core1 );
        return pxTimer_core1->xTimerPeriodInTicks_core1;
    }
/*-----------------------------------------------------------*/

    void vTimerSetReloadMode_core1( TimerHandle_t_core1 xTimer_core1,
                              const BaseType_t_core1 xAutoReload_core1 )
    {
        Timer_t_core1 * pxTimer_core1 = xTimer_core1;

        configASSERT_core1( xTimer_core1 );
        taskENTER_CRITICAL_core1();
        {
            if( xAutoReload_core1 != pdFALSE_core1 )
            {
                pxTimer_core1->ucStatus_core1 |= tmrSTATUS_IS_AUTORELOAD_core1;
            }
            else
            {
                pxTimer_core1->ucStatus_core1 &= ( ( uint8_t ) ~tmrSTATUS_IS_AUTORELOAD_core1 );
            }
        }
        taskEXIT_CRITICAL_core1();
    }
/*-----------------------------------------------------------*/

    BaseType_t_core1 xTimerGetReloadMode_core1( TimerHandle_t_core1 xTimer_core1 )
    {
        Timer_t_core1 * pxTimer_core1 = xTimer_core1;
        BaseType_t_core1 xReturn_core1;

        configASSERT_core1( xTimer_core1 );
        taskENTER_CRITICAL_core1();
        {
            if( ( pxTimer_core1->ucStatus_core1 & tmrSTATUS_IS_AUTORELOAD_core1 ) == 0 )
            {
                /* Not an auto-reload timer. */
                xReturn_core1 = pdFALSE_core1;
            }
            else
            {
                /* Is an auto-reload timer. */
                xReturn_core1 = pdTRUE_core1;
            }
        }
        taskEXIT_CRITICAL_core1();

        return xReturn_core1;
    }

    UBaseType_t_core1 uxTimerGetReloadMode_core1( TimerHandle_t_core1 xTimer_core1 )
    {
        return ( UBaseType_t_core1 ) xTimerGetReloadMode_core1( xTimer_core1 );
    }
/*-----------------------------------------------------------*/

    TickType_t_core1 xTimerGetExpiryTime_core1( TimerHandle_t_core1 xTimer_core1 )
    {
        Timer_t_core1 * pxTimer_core1 = xTimer_core1;
        TickType_t_core1 xReturn_core1;

        configASSERT_core1( xTimer_core1 );
        xReturn_core1 = listGET_LIST_ITEM_VALUE_core1( &( pxTimer_core1->xTimerListItem_core1 ) );
        return xReturn_core1;
    }
/*-----------------------------------------------------------*/

    const char * pcTimerGetName_core1( TimerHandle_t_core1 xTimer_core1 ) /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
    {
        Timer_t_core1 * pxTimer_core1 = xTimer_core1;

        configASSERT_core1( xTimer_core1 );
        return pxTimer_core1->pcTimerName_core1;
    }
/*-----------------------------------------------------------*/

    static void prvReloadTimer_core1( Timer_t_core1 * const pxTimer_core1,
                                TickType_t_core1 xExpiredTime_core1,
                                const TickType_t_core1 xTimeNow_core1 )
    {
        /* Insert the timer into the appropriate list for the next expiry time.
         * If the next expiry time has already passed, advance the expiry time,
         * call the callback function, and try again. */
        while( prvInsertTimerInActiveList_core1( pxTimer_core1, ( xExpiredTime_core1 + pxTimer_core1->xTimerPeriodInTicks_core1 ), xTimeNow_core1, xExpiredTime_core1 ) != pdFALSE_core1 )
        {
            /* Advance the expiry time. */
            xExpiredTime_core1 += pxTimer_core1->xTimerPeriodInTicks_core1;

            /* Call the timer callback. */
            traceTIMER_EXPIRED_core1( pxTimer_core1 );
            pxTimer_core1->pxCallbackFunction_core1( ( TimerHandle_t_core1 ) pxTimer_core1 );
        }
    }
/*-----------------------------------------------------------*/

    static void prvProcessExpiredTimer_core1( const TickType_t_core1 xNextExpireTime_core1,
                                        const TickType_t_core1 xTimeNow_core1 )
    {
        Timer_t_core1 * const pxTimer_core1 = ( Timer_t_core1 * ) listGET_OWNER_OF_HEAD_ENTRY_core1( pxCurrentTimerList_core1 ); /*lint !e9087 !e9079 void * is used as this macro is used with tasks and co-routines too.  Alignment is known to be fine as the type of the pointer stored and retrieved is the same. */

        /* Remove the timer from the list of active timers_core1.  A check has already
         * been performed to ensure the list is not empty. */

        ( void ) uxListRemove_core1( &( pxTimer_core1->xTimerListItem_core1 ) );

        /* If the timer is an auto-reload timer then calculate the next
         * expiry time and re-insert the timer in the list of active timers_core1. */
        if( ( pxTimer_core1->ucStatus_core1 & tmrSTATUS_IS_AUTORELOAD_core1 ) != 0 )
        {
            prvReloadTimer_core1( pxTimer_core1, xNextExpireTime_core1, xTimeNow_core1 );
        }
        else
        {
            pxTimer_core1->ucStatus_core1 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core1 );
        }

        /* Call the timer callback. */
        traceTIMER_EXPIRED_core1( pxTimer_core1 );
        pxTimer_core1->pxCallbackFunction_core1( ( TimerHandle_t_core1 ) pxTimer_core1 );
    }
/*-----------------------------------------------------------*/

    static portTASK_FUNCTION_core1( prvTimerTask_core1, pvParameters_core1 )
    {
        TickType_t_core1 xNextExpireTime_core1;
        BaseType_t_core1 xListWasEmpty_core1;

        /* Just to avoid compiler warnings. */
        ( void ) pvParameters_core1;

        #if ( configUSE_DAEMON_TASK_STARTUP_HOOK_core1 == 1 )
        {
            extern void vApplicationDaemonTaskStartupHook_core1( void );

            /* Allow the application writer to execute some code in the context of
             * this task_core1 at the point the task_core1 starts executing.  This is useful if the
             * application includes initialisation code that would benefit from
             * executing after the scheduler has been started. */
            vApplicationDaemonTaskStartupHook_core1();
        }
        #endif /* configUSE_DAEMON_TASK_STARTUP_HOOK_core1 */

        for( ; ; )
        {
            /* Query the timers_core1 list to see if it contains any timers_core1, and if so,
             * obtain the time at which the next timer will expire. */
            xNextExpireTime_core1 = prvGetNextExpireTime_core1( &xListWasEmpty_core1 );

            /* If a timer has expired, process it.  Otherwise, block this task_core1
             * until either a timer does expire, or a command is received. */
            prvProcessTimerOrBlockTask_core1( xNextExpireTime_core1, xListWasEmpty_core1 );

            /* Empty the command queue. */
            prvProcessReceivedCommands_core1();
        }
    }
/*-----------------------------------------------------------*/

    static void prvProcessTimerOrBlockTask_core1( const TickType_t_core1 xNextExpireTime_core1,
                                            BaseType_t_core1 xListWasEmpty_core1 )
    {
        TickType_t_core1 xTimeNow_core1;
        BaseType_t_core1 xTimerListsWereSwitched_core1;

        vTaskSuspendAll_core1();
        {
            /* Obtain the time now to make an assessment as to whether the timer
             * has expired or not.  If obtaining the time causes the lists to switch
             * then don't process this timer as any timers_core1 that remained in the list
             * when the lists were switched will have been processed within the
             * prvSampleTimeNow_core1() function. */
            xTimeNow_core1 = prvSampleTimeNow_core1( &xTimerListsWereSwitched_core1 );

            if( xTimerListsWereSwitched_core1 == pdFALSE_core1 )
            {
                /* The tick count has not overflowed, has the timer expired? */
                if( ( xListWasEmpty_core1 == pdFALSE_core1 ) && ( xNextExpireTime_core1 <= xTimeNow_core1 ) )
                {
                    ( void ) xTaskResumeAll_core1();
                    prvProcessExpiredTimer_core1( xNextExpireTime_core1, xTimeNow_core1 );
                }
                else
                {
                    /* The tick count has not overflowed, and the next expire
                     * time has not been reached yet.  This task_core1 should therefore
                     * block to wait for the next expire time or a command to be
                     * received - whichever comes first.  The following line cannot
                     * be reached unless xNextExpireTime_core1 > xTimeNow_core1, except in the
                     * case when the current timer list is empty. */
                    if( xListWasEmpty_core1 != pdFALSE_core1 )
                    {
                        /* The current timer list is empty - is the overflow list
                         * also empty? */
                        xListWasEmpty_core1 = listLIST_IS_EMPTY_core1( pxOverflowTimerList_core1 );
                    }

                    vQueueWaitForMessageRestricted_core1( xTimerQueue_core1, ( xNextExpireTime_core1 - xTimeNow_core1 ), xListWasEmpty_core1 );

                    if( xTaskResumeAll_core1() == pdFALSE_core1 )
                    {
                        /* Yield to wait for either a command to arrive, or the
                         * block time to expire.  If a command arrived between the
                         * critical section being exited and this yield then the yield
                         * will not cause the task_core1 to block. */
                        portYIELD_WITHIN_API_core1();
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core1();
                    }
                }
            }
            else
            {
                ( void ) xTaskResumeAll_core1();
            }
        }
    }
/*-----------------------------------------------------------*/

    static TickType_t_core1 prvGetNextExpireTime_core1( BaseType_t_core1 * const pxListWasEmpty_core1 )
    {
        TickType_t_core1 xNextExpireTime_core1;

        /* Timers are listed in expiry time order, with the head of the list
         * referencing the task_core1 that will expire first.  Obtain the time at which
         * the timer with the nearest expiry time will expire.  If there are no
         * active timers_core1 then just set the next expire time to 0.  That will cause
         * this task_core1 to unblock when the tick count overflows, at which point the
         * timer lists will be switched and the next expiry time can be
         * re-assessed.  */
        *pxListWasEmpty_core1 = listLIST_IS_EMPTY_core1( pxCurrentTimerList_core1 );

        if( *pxListWasEmpty_core1 == pdFALSE_core1 )
        {
            xNextExpireTime_core1 = listGET_ITEM_VALUE_OF_HEAD_ENTRY_core1( pxCurrentTimerList_core1 );
        }
        else
        {
            /* Ensure the task_core1 unblocks when the tick count rolls over. */
            xNextExpireTime_core1 = ( TickType_t_core1 ) 0U;
        }

        return xNextExpireTime_core1;
    }
/*-----------------------------------------------------------*/

    static TickType_t_core1 prvSampleTimeNow_core1( BaseType_t_core1 * const pxTimerListsWereSwitched_core1 )
    {
        TickType_t_core1 xTimeNow_core1;
        PRIVILEGED_DATA_core1 static TickType_t_core1 xLastTime_core1 = ( TickType_t_core1 ) 0U; /*lint !e956 Variable is only accessible to one task_core1. */

        xTimeNow_core1 = xTaskGetTickCount_core1();

        if( xTimeNow_core1 < xLastTime_core1 )
        {
            prvSwitchTimerLists_core1();
            *pxTimerListsWereSwitched_core1 = pdTRUE_core1;
        }
        else
        {
            *pxTimerListsWereSwitched_core1 = pdFALSE_core1;
        }

        xLastTime_core1 = xTimeNow_core1;

        return xTimeNow_core1;
    }
/*-----------------------------------------------------------*/

    static BaseType_t_core1 prvInsertTimerInActiveList_core1( Timer_t_core1 * const pxTimer_core1,
                                                  const TickType_t_core1 xNextExpiryTime_core1,
                                                  const TickType_t_core1 xTimeNow_core1,
                                                  const TickType_t_core1 xCommandTime_core1 )
    {
        BaseType_t_core1 xProcessTimerNow_core1 = pdFALSE_core1;

        listSET_LIST_ITEM_VALUE_core1( &( pxTimer_core1->xTimerListItem_core1 ), xNextExpiryTime_core1 );
        listSET_LIST_ITEM_OWNER_core1( &( pxTimer_core1->xTimerListItem_core1 ), pxTimer_core1 );

        if( xNextExpiryTime_core1 <= xTimeNow_core1 )
        {
            /* Has the expiry time elapsed between the command to start/reset a
             * timer was issued, and the time the command was processed? */
            if( ( ( TickType_t_core1 ) ( xTimeNow_core1 - xCommandTime_core1 ) ) >= pxTimer_core1->xTimerPeriodInTicks_core1 ) /*lint !e961 MISRA exception as the casts are only redundant for some ports. */
            {
                /* The time between a command being issued and the command being
                 * processed actually exceeds the timers_core1 period.  */
                xProcessTimerNow_core1 = pdTRUE_core1;
            }
            else
            {
                vListInsert_core1( pxOverflowTimerList_core1, &( pxTimer_core1->xTimerListItem_core1 ) );
            }
        }
        else
        {
            if( ( xTimeNow_core1 < xCommandTime_core1 ) && ( xNextExpiryTime_core1 >= xCommandTime_core1 ) )
            {
                /* If, since the command was issued, the tick count has overflowed
                 * but the expiry time has not, then the timer must have already passed
                 * its expiry time and should be processed immediately. */
                xProcessTimerNow_core1 = pdTRUE_core1;
            }
            else
            {
                vListInsert_core1( pxCurrentTimerList_core1, &( pxTimer_core1->xTimerListItem_core1 ) );
            }
        }

        return xProcessTimerNow_core1;
    }
/*-----------------------------------------------------------*/

    static void prvProcessReceivedCommands_core1( void )
    {
        DaemonTaskMessage_t_core1 xMessage_core1;
        Timer_t_core1 * pxTimer_core1;
        BaseType_t_core1 xTimerListsWereSwitched_core1;
        TickType_t_core1 xTimeNow_core1;

        while( xQueueReceive_core1( xTimerQueue_core1, &xMessage_core1, tmrNO_DELAY_core1 ) != pdFAIL_core1 ) /*lint !e603 xMessage_core1 does not have to be initialised as it is passed out, not in, and it is not used unless xQueueReceive_core1() returns pdTRUE_core1. */
        {
            #if ( INCLUDE_xTimerPendFunctionCall_core1 == 1 )
            {
                /* Negative commands are pended function calls rather than timer
                 * commands. */
                if( xMessage_core1.xMessageID_core1 < ( BaseType_t_core1 ) 0 )
                {
                    const CallbackParameters_t_core1 * const pxCallback_core1 = &( xMessage_core1.u.xCallbackParameters_core1 );

                    /* The timer uses the xCallbackParameters_core1 member to request a
                     * callback be executed.  Check the callback is not NULL. */
                    configASSERT_core1( pxCallback_core1 );

                    /* Call the function. */
                    pxCallback_core1->pxCallbackFunction_core1( pxCallback_core1->pvParameter1_core1, pxCallback_core1->ulParameter2_core1 );
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core1();
                }
            }
            #endif /* INCLUDE_xTimerPendFunctionCall_core1 */

            /* Commands that are positive are timer commands rather than pended
             * function calls. */
            if( xMessage_core1.xMessageID_core1 >= ( BaseType_t_core1 ) 0 )
            {
                /* The messages uses the xTimerParameters_core1 member to work on a
                 * software timer. */
                pxTimer_core1 = xMessage_core1.u.xTimerParameters_core1.pxTimer_core1;

                if( listIS_CONTAINED_WITHIN_core1( NULL, &( pxTimer_core1->xTimerListItem_core1 ) ) == pdFALSE_core1 ) /*lint !e961. The cast is only redundant when NULL is passed into the macro. */
                {
                    /* The timer is in a list, remove it. */
                    ( void ) uxListRemove_core1( &( pxTimer_core1->xTimerListItem_core1 ) );
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core1();
                }

                traceTIMER_COMMAND_RECEIVED_core1( pxTimer_core1, xMessage_core1.xMessageID_core1, xMessage_core1.u.xTimerParameters_core1.xMessageValue_core1 );

                /* In this case the xTimerListsWereSwitched_core1 parameter is not used, but
                 *  it must be present in the function call.  prvSampleTimeNow_core1() must be
                 *  called after the message is received from xTimerQueue_core1 so there is no
                 *  possibility of a higher priority task_core1 adding a message to the message
                 *  queue with a time that is ahead of the timer daemon task_core1 (because it
                 *  pre-empted the timer daemon task_core1 after the xTimeNow_core1 value was set). */
                xTimeNow_core1 = prvSampleTimeNow_core1( &xTimerListsWereSwitched_core1 );

                switch( xMessage_core1.xMessageID_core1 )
                {
                    case tmrCOMMAND_START_core1:
                    case tmrCOMMAND_START_FROM_ISR_core1:
                    case tmrCOMMAND_RESET_core1:
                    case tmrCOMMAND_RESET_FROM_ISR_core1:
                        /* Start or restart a timer. */
                        pxTimer_core1->ucStatus_core1 |= tmrSTATUS_IS_ACTIVE_core1;

                        if( prvInsertTimerInActiveList_core1( pxTimer_core1, xMessage_core1.u.xTimerParameters_core1.xMessageValue_core1 + pxTimer_core1->xTimerPeriodInTicks_core1, xTimeNow_core1, xMessage_core1.u.xTimerParameters_core1.xMessageValue_core1 ) != pdFALSE_core1 )
                        {
                            /* The timer expired before it was added to the active
                             * timer list.  Process it now. */
                            if( ( pxTimer_core1->ucStatus_core1 & tmrSTATUS_IS_AUTORELOAD_core1 ) != 0 )
                            {
                                prvReloadTimer_core1( pxTimer_core1, xMessage_core1.u.xTimerParameters_core1.xMessageValue_core1 + pxTimer_core1->xTimerPeriodInTicks_core1, xTimeNow_core1 );
                            }
                            else
                            {
                                pxTimer_core1->ucStatus_core1 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core1 );
                            }

                            /* Call the timer callback. */
                            traceTIMER_EXPIRED_core1( pxTimer_core1 );
                            pxTimer_core1->pxCallbackFunction_core1( ( TimerHandle_t_core1 ) pxTimer_core1 );
                        }
                        else
                        {
                            mtCOVERAGE_TEST_MARKER_core1();
                        }

                        break;

                    case tmrCOMMAND_STOP_core1:
                    case tmrCOMMAND_STOP_FROM_ISR_core1:
                        /* The timer has already been removed from the active list. */
                        pxTimer_core1->ucStatus_core1 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core1 );
                        break;

                    case tmrCOMMAND_CHANGE_PERIOD_core1:
                    case tmrCOMMAND_CHANGE_PERIOD_FROM_ISR_core1:
                        pxTimer_core1->ucStatus_core1 |= tmrSTATUS_IS_ACTIVE_core1;
                        pxTimer_core1->xTimerPeriodInTicks_core1 = xMessage_core1.u.xTimerParameters_core1.xMessageValue_core1;
                        configASSERT_core1( ( pxTimer_core1->xTimerPeriodInTicks_core1 > 0 ) );

                        /* The new period does not really have a reference, and can
                         * be longer or shorter than the old one.  The command time is
                         * therefore set to the current time, and as the period cannot
                         * be zero the next expiry time can only be in the future,
                         * meaning (unlike for the xTimerStart_core1() case above) there is
                         * no fail case that needs to be handled here. */
                        ( void ) prvInsertTimerInActiveList_core1( pxTimer_core1, ( xTimeNow_core1 + pxTimer_core1->xTimerPeriodInTicks_core1 ), xTimeNow_core1, xTimeNow_core1 );
                        break;

                    case tmrCOMMAND_DELETE_core1:
                        #if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )
                        {
                            /* The timer has already been removed from the active list,
                             * just free up the memory if the memory was dynamically
                             * allocated. */
                            if( ( pxTimer_core1->ucStatus_core1 & tmrSTATUS_IS_STATICALLY_ALLOCATED_core1 ) == ( uint8_t ) 0 )
                            {
                                vPortFree_core1( pxTimer_core1 );
                            }
                            else
                            {
                                pxTimer_core1->ucStatus_core1 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core1 );
                            }
                        }
                        #else /* if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 ) */
                        {
                            /* If dynamic allocation is not enabled, the memory
                             * could not have been dynamically allocated. So there is
                             * no need to free the memory - just mark the timer as
                             * "not active". */
                            pxTimer_core1->ucStatus_core1 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core1 );
                        }
                        #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core1 */
                        break;

                    default:
                        /* Don't expect to get here. */
                        break;
                }
            }
        }
    }
/*-----------------------------------------------------------*/

    static void prvSwitchTimerLists_core1( void )
    {
        TickType_t_core1 xNextExpireTime_core1;
        List_t_core1 * pxTemp_core1;

        /* The tick count has overflowed.  The timer lists must be switched.
         * If there are any timers_core1 still referenced from the current timer list
         * then they must have expired and should be processed before the lists
         * are switched. */
        while( listLIST_IS_EMPTY_core1( pxCurrentTimerList_core1 ) == pdFALSE_core1 )
        {
            xNextExpireTime_core1 = listGET_ITEM_VALUE_OF_HEAD_ENTRY_core1( pxCurrentTimerList_core1 );

            /* Process the expired timer.  For auto-reload timers_core1, be careful to
             * process only expirations that occur on the current list.  Further
             * expirations must wait until after the lists are switched. */
            prvProcessExpiredTimer_core1( xNextExpireTime_core1, tmrMAX_TIME_BEFORE_OVERFLOW_core1 );
        }

        pxTemp_core1 = pxCurrentTimerList_core1;
        pxCurrentTimerList_core1 = pxOverflowTimerList_core1;
        pxOverflowTimerList_core1 = pxTemp_core1;
    }
/*-----------------------------------------------------------*/

    static void prvCheckForValidListAndQueue_core1( void )
    {
        /* Check that the list from which active timers_core1 are referenced, and the
         * queue used to communicate with the timer service, have been
         * initialised. */
        taskENTER_CRITICAL_core1();
        {
            if( xTimerQueue_core1 == NULL )
            {
                vListInitialise_core1( &xActiveTimerList1_core1 );
                vListInitialise_core1( &xActiveTimerList2_core1 );
                pxCurrentTimerList_core1 = &xActiveTimerList1_core1;
                pxOverflowTimerList_core1 = &xActiveTimerList2_core1;

                #if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )
                {
                    /* The timer queue is allocated statically in case
                     * configSUPPORT_DYNAMIC_ALLOCATION_core1 is 0. */
                    PRIVILEGED_DATA_core1 static StaticQueue_t_core1 xStaticTimerQueue_core1;                                                                          /*lint !e956 Ok to declare in this manner to prevent additional conditional compilation guards in other locations. */
                    PRIVILEGED_DATA_core1 static uint8_t ucStaticTimerQueueStorage_core1[ ( size_t ) configTIMER_QUEUE_LENGTH_core1 * sizeof( DaemonTaskMessage_t_core1 ) ]; /*lint !e956 Ok to declare in this manner to prevent additional conditional compilation guards in other locations. */

                    xTimerQueue_core1 = xQueueCreateStatic_core1( ( UBaseType_t_core1 ) configTIMER_QUEUE_LENGTH_core1, ( UBaseType_t_core1 ) sizeof( DaemonTaskMessage_t_core1 ), &( ucStaticTimerQueueStorage_core1[ 0 ] ), &xStaticTimerQueue_core1 );
                }
                #else
                {
                    xTimerQueue_core1 = xQueueCreate_core1( ( UBaseType_t_core1 ) configTIMER_QUEUE_LENGTH_core1, sizeof( DaemonTaskMessage_t_core1 ) );
                }
                #endif /* if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 ) */

                #if ( configQUEUE_REGISTRY_SIZE_core1 > 0 )
                {
                    if( xTimerQueue_core1 != NULL )
                    {
                        vQueueAddToRegistry_core1( xTimerQueue_core1, "TmrQ_core1" );
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core1();
                    }
                }
                #endif /* configQUEUE_REGISTRY_SIZE_core1 */
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core1();
            }
        }
        taskEXIT_CRITICAL_core1();
    }
/*-----------------------------------------------------------*/

    BaseType_t_core1 xTimerIsTimerActive_core1( TimerHandle_t_core1 xTimer_core1 )
    {
        BaseType_t_core1 xReturn_core1;
        Timer_t_core1 * pxTimer_core1 = xTimer_core1;

        configASSERT_core1( xTimer_core1 );

        /* Is the timer in the list of active timers_core1? */
        taskENTER_CRITICAL_core1();
        {
            if( ( pxTimer_core1->ucStatus_core1 & tmrSTATUS_IS_ACTIVE_core1 ) == 0 )
            {
                xReturn_core1 = pdFALSE_core1;
            }
            else
            {
                xReturn_core1 = pdTRUE_core1;
            }
        }
        taskEXIT_CRITICAL_core1();

        return xReturn_core1;
    } /*lint !e818 Can't be pointer to const due to the typedef. */
/*-----------------------------------------------------------*/

    void * pvTimerGetTimerID_core1( const TimerHandle_t_core1 xTimer_core1 )
    {
        Timer_t_core1 * const pxTimer_core1 = xTimer_core1;
        void * pvReturn_core1;

        configASSERT_core1( xTimer_core1 );

        taskENTER_CRITICAL_core1();
        {
            pvReturn_core1 = pxTimer_core1->pvTimerID_core1;
        }
        taskEXIT_CRITICAL_core1();

        return pvReturn_core1;
    }
/*-----------------------------------------------------------*/

    void vTimerSetTimerID_core1( TimerHandle_t_core1 xTimer_core1,
                           void * pvNewID_core1 )
    {
        Timer_t_core1 * const pxTimer_core1 = xTimer_core1;

        configASSERT_core1( xTimer_core1 );

        taskENTER_CRITICAL_core1();
        {
            pxTimer_core1->pvTimerID_core1 = pvNewID_core1;
        }
        taskEXIT_CRITICAL_core1();
    }
/*-----------------------------------------------------------*/

    #if ( INCLUDE_xTimerPendFunctionCall_core1 == 1 )

        BaseType_t_core1 xTimerPendFunctionCallFromISR_core1( PendedFunction_t_core1 xFunctionToPend_core1,
                                                  void * pvParameter1_core1,
                                                  uint32_t ulParameter2_core1,
                                                  BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 )
        {
            DaemonTaskMessage_t_core1 xMessage_core1;
            BaseType_t_core1 xReturn_core1;

            /* Complete the message with the function parameters and post it to the
             * daemon task_core1. */
            xMessage_core1.xMessageID_core1 = tmrCOMMAND_EXECUTE_CALLBACK_FROM_ISR_core1;
            xMessage_core1.u.xCallbackParameters_core1.pxCallbackFunction_core1 = xFunctionToPend_core1;
            xMessage_core1.u.xCallbackParameters_core1.pvParameter1_core1 = pvParameter1_core1;
            xMessage_core1.u.xCallbackParameters_core1.ulParameter2_core1 = ulParameter2_core1;

            xReturn_core1 = xQueueSendFromISR_core1( xTimerQueue_core1, &xMessage_core1, pxHigherPriorityTaskWoken_core1 );

            tracePEND_FUNC_CALL_FROM_ISR_core1( xFunctionToPend_core1, pvParameter1_core1, ulParameter2_core1, xReturn_core1 );

            return xReturn_core1;
        }

    #endif /* INCLUDE_xTimerPendFunctionCall_core1 */
/*-----------------------------------------------------------*/

    #if ( INCLUDE_xTimerPendFunctionCall_core1 == 1 )

        BaseType_t_core1 xTimerPendFunctionCall_core1( PendedFunction_t_core1 xFunctionToPend_core1,
                                           void * pvParameter1_core1,
                                           uint32_t ulParameter2_core1,
                                           TickType_t_core1 xTicksToWait_core1 )
        {
            DaemonTaskMessage_t_core1 xMessage_core1;
            BaseType_t_core1 xReturn_core1;

            /* This function can only be called after a timer has been created or
             * after the scheduler has been started because, until then, the timer
             * queue does not exist. */
            configASSERT_core1( xTimerQueue_core1 );

            /* Complete the message with the function parameters and post it to the
             * daemon task_core1. */
            xMessage_core1.xMessageID_core1 = tmrCOMMAND_EXECUTE_CALLBACK_core1;
            xMessage_core1.u.xCallbackParameters_core1.pxCallbackFunction_core1 = xFunctionToPend_core1;
            xMessage_core1.u.xCallbackParameters_core1.pvParameter1_core1 = pvParameter1_core1;
            xMessage_core1.u.xCallbackParameters_core1.ulParameter2_core1 = ulParameter2_core1;

            xReturn_core1 = xQueueSendToBack_core1( xTimerQueue_core1, &xMessage_core1, xTicksToWait_core1 );

            tracePEND_FUNC_CALL_core1( xFunctionToPend_core1, pvParameter1_core1, ulParameter2_core1, xReturn_core1 );

            return xReturn_core1;
        }

    #endif /* INCLUDE_xTimerPendFunctionCall_core1 */
/*-----------------------------------------------------------*/

    #if ( configUSE_TRACE_FACILITY_core1 == 1 )

        UBaseType_t_core1 uxTimerGetTimerNumber_core1( TimerHandle_t_core1 xTimer_core1 )
        {
            return ( ( Timer_t_core1 * ) xTimer_core1 )->uxTimerNumber_core1;
        }

    #endif /* configUSE_TRACE_FACILITY_core1 */
/*-----------------------------------------------------------*/

    #if ( configUSE_TRACE_FACILITY_core1 == 1 )

        void vTimerSetTimerNumber_core1( TimerHandle_t_core1 xTimer_core1,
                                   UBaseType_t_core1 uxTimerNumber_core1 )
        {
            ( ( Timer_t_core1 * ) xTimer_core1 )->uxTimerNumber_core1 = uxTimerNumber_core1;
        }

    #endif /* configUSE_TRACE_FACILITY_core1 */
/*-----------------------------------------------------------*/

/* This entire source file will be skipped if the application is not configured
 * to include software timer functionality.  If you want to include software timer
 * functionality then ensure configUSE_TIMERS_core1 is set to 1 in FreeRTOSConfig.h. */
#endif /* configUSE_TIMERS_core1 == 1 */
