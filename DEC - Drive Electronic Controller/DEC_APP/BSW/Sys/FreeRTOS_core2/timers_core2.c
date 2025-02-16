/*
 * FreeRTOS_core2 Kernel V10.5.1
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
 * https://www.FreeRTOS_core2.org
 * https://github.com/FreeRTOS_core2
 *
 */

/* Standard includes. */
#include <stdlib.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 prevents task_core2.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core2.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2

#include "FreeRTOS_core2.h"
#include "task_core2.h"
#include "queue_core2.h"
#include "timers_core2.h"

#if ( INCLUDE_xTimerPendFunctionCall_core2 == 1 ) && ( configUSE_TIMERS_core2 == 0 )
    #error configUSE_TIMERS_core2 must be set to 1 to make the xTimerPendFunctionCall_core2() function available.
#endif

/* Lint e9021, e961 and e750 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 to be defined
 * for the header files above, but not in this file, in order to generate the
 * correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 /*lint !e9021 !e961 !e750. */


/* This entire source file will be skipped if the application is not configured
 * to include software timer functionality.  This #if is closed at the very bottom
 * of this file.  If you want to include software timer functionality then ensure
 * configUSE_TIMERS_core2 is set to 1 in FreeRTOSConfig.h. */
#if ( configUSE_TIMERS_core2 == 1 )

/* Misc definitions. */
    #define tmrNO_DELAY_core2                    ( ( TickType_t_core2 ) 0U )
    #define tmrMAX_TIME_BEFORE_OVERFLOW_core2    ( ( TickType_t_core2 ) -1 )

/* The name assigned to the timer service task_core2.  This can be overridden by
 * defining trmTIMER_SERVICE_TASK_NAME in FreeRTOSConfig.h. */
    #ifndef configTIMER_SERVICE_TASK_NAME_core2
        #define configTIMER_SERVICE_TASK_NAME_core2    "Tmr Svc_core2"
    #endif

/* Bit definitions used in the ucStatus_core2 member of a timer structure. */
    #define tmrSTATUS_IS_ACTIVE_core2                  ( ( uint8_t ) 0x01 )
    #define tmrSTATUS_IS_STATICALLY_ALLOCATED_core2    ( ( uint8_t ) 0x02 )
    #define tmrSTATUS_IS_AUTORELOAD_core2              ( ( uint8_t ) 0x04 )

/* The definition of the timers_core2 themselves. */
    typedef struct tmrTimerControl_core2                  /* The old naming convention is used to prevent breaking kernel aware debuggers. */
    {
        const char * pcTimerName_core2;                   /*<< Text name.  This is not used by the kernel, it is included simply to make debugging easier. */ /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
        ListItem_t_core2 xTimerListItem_core2;                  /*<< Standard linked list item as used by all kernel features for event management. */
        TickType_t_core2 xTimerPeriodInTicks_core2;             /*<< How quickly and often the timer expires. */
        void * pvTimerID_core2;                           /*<< An ID to identify the timer.  This allows the timer to be identified when the same callback is used for multiple timers_core2. */
        TimerCallbackFunction_t_core2 pxCallbackFunction_core2; /*<< The function that will be called when the timer expires. */
        #if ( configUSE_TRACE_FACILITY_core2 == 1 )
            UBaseType_t_core2 uxTimerNumber_core2;              /*<< An ID assigned by trace tools such as FreeRTOS_core2+Trace */
        #endif
        uint8_t ucStatus_core2;                           /*<< Holds bits to say if the timer was statically allocated or not, and if it is active or not. */
    } xTIMER_core2;

/* The old xTIMER_core2 name is maintained above then typedefed to the new Timer_t_core2
 * name below to enable the use of older kernel aware debuggers. */
    typedef xTIMER_core2 Timer_t_core2;

/* The definition of messages that can be sent and received on the timer queue.
 * Two types of message can be queued - messages that manipulate a software timer,
 * and messages that request the execution of a non-timer related callback.  The
 * two message types are defined in two separate structures, xTimerParametersType
 * and xCallbackParametersType respectively. */
    typedef struct tmrTimerParameters_core2
    {
        TickType_t_core2 xMessageValue_core2; /*<< An optional value used by a subset of commands, for example, when changing the period of a timer. */
        Timer_t_core2 * pxTimer_core2;        /*<< The timer to which the command will be applied. */
    } TimerParameter_t_core2;


    typedef struct tmrCallbackParameters_core2
    {
        PendedFunction_t_core2 pxCallbackFunction_core2; /* << The callback function to execute. */
        void * pvParameter1_core2;                 /* << The value that will be used as the callback functions first parameter. */
        uint32_t ulParameter2_core2;               /* << The value that will be used as the callback functions second parameter. */
    } CallbackParameters_t_core2;

/* The structure that contains the two message types, along with an identifier
 * that is used to determine which message type is valid. */
    typedef struct tmrTimerQueueMessage_core2
    {
        BaseType_t_core2 xMessageID_core2; /*<< The command being sent to the timer service task_core2. */
        union
        {
            TimerParameter_t_core2 xTimerParameters_core2;

            /* Don't include xCallbackParameters_core2 if it is not going to be used as
             * it makes the structure (and therefore the timer queue) larger. */
            #if ( INCLUDE_xTimerPendFunctionCall_core2 == 1 )
                CallbackParameters_t_core2 xCallbackParameters_core2;
            #endif /* INCLUDE_xTimerPendFunctionCall_core2 */
        } u;
    } DaemonTaskMessage_t_core2;

/*lint -save -e956 A manual analysis and inspection has been used to determine
 * which static variables must be declared volatile. */

/* The list in which active timers_core2 are stored.  Timers are referenced in expire
 * time order, with the nearest expiry time at the front of the list.  Only the
 * timer service task_core2 is allowed to access these lists.
 * xActiveTimerList1_core2 and xActiveTimerList2_core2 could be at function scope but that
 * breaks some kernel aware debuggers, and debuggers that reply on removing the
 * static qualifier. */
    PRIVILEGED_DATA_core2 static List_t_core2 xActiveTimerList1_core2;
    PRIVILEGED_DATA_core2 static List_t_core2 xActiveTimerList2_core2;
    PRIVILEGED_DATA_core2 static List_t_core2 * pxCurrentTimerList_core2;
    PRIVILEGED_DATA_core2 static List_t_core2 * pxOverflowTimerList_core2;

/* A queue that is used to send commands to the timer service task_core2. */
    PRIVILEGED_DATA_core2 static QueueHandle_t_core2 xTimerQueue_core2 = NULL;
    PRIVILEGED_DATA_core2 static TaskHandle_t_core2 xTimerTaskHandle_core2 = NULL;

/*lint -restore */

/*-----------------------------------------------------------*/

/*
 * Initialise the infrastructure used by the timer service task_core2 if it has not
 * been initialised already.
 */
    static void prvCheckForValidListAndQueue_core2( void ) PRIVILEGED_FUNCTION_core2;

/*
 * The timer service task_core2 (daemon).  Timer functionality is controlled by this
 * task_core2.  Other tasks communicate with the timer service task_core2 using the
 * xTimerQueue_core2 queue.
 */
    static portTASK_FUNCTION_PROTO_core2( prvTimerTask_core2, pvParameters_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Called by the timer service task_core2 to interpret and process a command it
 * received on the timer queue.
 */
    static void prvProcessReceivedCommands_core2( void ) PRIVILEGED_FUNCTION_core2;

/*
 * Insert the timer into either xActiveTimerList1_core2, or xActiveTimerList2_core2,
 * depending on if the expire time causes a timer counter overflow.
 */
    static BaseType_t_core2 prvInsertTimerInActiveList_core2( Timer_t_core2 * const pxTimer_core2,
                                                  const TickType_t_core2 xNextExpiryTime_core2,
                                                  const TickType_t_core2 xTimeNow_core2,
                                                  const TickType_t_core2 xCommandTime_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Reload the specified auto-reload timer.  If the reloading is backlogged,
 * clear the backlog, calling the callback for each additional reload.  When
 * this function returns, the next expiry time is after xTimeNow_core2.
 */
    static void prvReloadTimer_core2( Timer_t_core2 * const pxTimer_core2,
                                TickType_t_core2 xExpiredTime_core2,
                                const TickType_t_core2 xTimeNow_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * An active timer has reached its expire time.  Reload the timer if it is an
 * auto-reload timer, then call its callback.
 */
    static void prvProcessExpiredTimer_core2( const TickType_t_core2 xNextExpireTime_core2,
                                        const TickType_t_core2 xTimeNow_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * The tick count has overflowed.  Switch the timer lists after ensuring the
 * current timer list does not still reference some timers_core2.
 */
    static void prvSwitchTimerLists_core2( void ) PRIVILEGED_FUNCTION_core2;

/*
 * Obtain the current tick count, setting *pxTimerListsWereSwitched_core2 to pdTRUE_core2
 * if a tick count overflow occurred since prvSampleTimeNow_core2() was last called.
 */
    static TickType_t_core2 prvSampleTimeNow_core2( BaseType_t_core2 * const pxTimerListsWereSwitched_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * If the timer list contains any active timers_core2 then return the expire time of
 * the timer that will expire first and set *pxListWasEmpty_core2 to false.  If the
 * timer list does not contain any timers_core2 then return 0 and set *pxListWasEmpty_core2
 * to pdTRUE_core2.
 */
    static TickType_t_core2 prvGetNextExpireTime_core2( BaseType_t_core2 * const pxListWasEmpty_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * If a timer has expired, process it.  Otherwise, block the timer service task_core2
 * until either a timer does expire or a command is received.
 */
    static void prvProcessTimerOrBlockTask_core2( const TickType_t_core2 xNextExpireTime_core2,
                                            BaseType_t_core2 xListWasEmpty_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Called after a Timer_t_core2 structure has been allocated either statically or
 * dynamically to fill in the structure's members.
 */
    static void prvInitialiseNewTimer_core2( const char * const pcTimerName_core2, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                       const TickType_t_core2 xTimerPeriodInTicks_core2,
                                       const BaseType_t_core2 xAutoReload_core2,
                                       void * const pvTimerID_core2,
                                       TimerCallbackFunction_t_core2 pxCallbackFunction_core2,
                                       Timer_t_core2 * pxNewTimer_core2 ) PRIVILEGED_FUNCTION_core2;
/*-----------------------------------------------------------*/

    BaseType_t_core2 xTimerCreateTimerTask_core2( void )
    {
        BaseType_t_core2 xReturn_core2 = pdFAIL_core2;

        /* This function is called when the scheduler is started if
         * configUSE_TIMERS_core2 is set to 1.  Check that the infrastructure used by the
         * timer service task_core2 has been created/initialised.  If timers_core2 have already
         * been created then the initialisation will already have been performed. */
        prvCheckForValidListAndQueue_core2();

        if( xTimerQueue_core2 != NULL )
        {
            #if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )
            {
                StaticTask_t_core2 * pxTimerTaskTCBBuffer_core2 = NULL;
                StackType_t_core2 * pxTimerTaskStackBuffer_core2 = NULL;
                uint32_t ulTimerTaskStackSize_core2;

                vApplicationGetTimerTaskMemory_core2( &pxTimerTaskTCBBuffer_core2, &pxTimerTaskStackBuffer_core2, &ulTimerTaskStackSize_core2 );
                xTimerTaskHandle_core2 = xTaskCreateStatic_core2( prvTimerTask_core2,
                                                      configTIMER_SERVICE_TASK_NAME_core2,
                                                      ulTimerTaskStackSize_core2,
                                                      NULL,
                                                      ( ( UBaseType_t_core2 ) configTIMER_TASK_PRIORITY_core2 ) | portPRIVILEGE_BIT_core2,
                                                      pxTimerTaskStackBuffer_core2,
                                                      pxTimerTaskTCBBuffer_core2 );

                if( xTimerTaskHandle_core2 != NULL )
                {
                    xReturn_core2 = pdPASS_core2;
                }
            }
            #else /* if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 ) */
            {
                xReturn_core2 = xTaskCreate_core2( prvTimerTask_core2,
                                       configTIMER_SERVICE_TASK_NAME_core2,
                                       configTIMER_TASK_STACK_DEPTH_core2,
                                       NULL,
                                       ( ( UBaseType_t_core2 ) configTIMER_TASK_PRIORITY_core2 ) | portPRIVILEGE_BIT_core2,
                                       &xTimerTaskHandle_core2 );
            }
            #endif /* configSUPPORT_STATIC_ALLOCATION_core2 */
        }
        else
        {
            //mtCOVERAGE_TEST_MARKER_core2();
        }

        //configASSERT_core2( xReturn_core2 );
        return xReturn_core2;
    }
/*-----------------------------------------------------------*/

    #if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 )

        TimerHandle_t_core2 xTimerCreate_core2( const char * const pcTimerName_core2, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                    const TickType_t_core2 xTimerPeriodInTicks_core2,
                                    const BaseType_t_core2 xAutoReload_core2,
                                    void * const pvTimerID_core2,
                                    TimerCallbackFunction_t_core2 pxCallbackFunction_core2 )
        {
            Timer_t_core2 * pxNewTimer_core2;

            pxNewTimer_core2 = ( Timer_t_core2 * ) pvPortMalloc_core2( sizeof( Timer_t_core2 ) ); /*lint !e9087 !e9079 All values returned by pvPortMalloc_core2() have at least the alignment required by the MCU's stack, and the first member of Timer_t_core2 is always a pointer to the timer's mame. */

            if( pxNewTimer_core2 != NULL )
            {
                /* Status is thus far zero as the timer is not created statically
                 * and has not been started.  The auto-reload bit may get set in
                 * prvInitialiseNewTimer_core2. */
                pxNewTimer_core2->ucStatus_core2 = 0x00;
                prvInitialiseNewTimer_core2( pcTimerName_core2, xTimerPeriodInTicks_core2, xAutoReload_core2, pvTimerID_core2, pxCallbackFunction_core2, pxNewTimer_core2 );
            }

            return pxNewTimer_core2;
        }

    #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core2 */
/*-----------------------------------------------------------*/

    #if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )

        TimerHandle_t_core2 xTimerCreateStatic_core2( const char * const pcTimerName_core2, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                          const TickType_t_core2 xTimerPeriodInTicks_core2,
                                          const BaseType_t_core2 xAutoReload_core2,
                                          void * const pvTimerID_core2,
                                          TimerCallbackFunction_t_core2 pxCallbackFunction_core2,
                                          StaticTimer_t_core2 * pxTimerBuffer_core2 )
        {
            Timer_t_core2 * pxNewTimer_core2;

            #if ( configASSERT_DEFINED_core2 == 1 )
            {
                /* Sanity check that the size of the structure used to declare a
                 * variable of type StaticTimer_t_core2 equals the size of the real timer
                 * structure. */
                volatile size_t xSize_core2 = sizeof( StaticTimer_t_core2 );
                configASSERT_core2( xSize_core2 == sizeof( Timer_t_core2 ) );
                ( void ) xSize_core2; /* Keeps lint quiet when configASSERT_core2() is not defined. */
            }
            #endif /* configASSERT_DEFINED_core2 */

            /* A pointer to a StaticTimer_t_core2 structure MUST be provided, use it. */
            configASSERT_core2( pxTimerBuffer_core2 );
            pxNewTimer_core2 = ( Timer_t_core2 * ) pxTimerBuffer_core2; /*lint !e740 !e9087 StaticTimer_t_core2 is a pointer to a Timer_t_core2, so guaranteed to be aligned and sized correctly (checked by an assert()), so this is safe. */

            if( pxNewTimer_core2 != NULL )
            {
                /* Timers can be created statically or dynamically so note this
                 * timer was created statically in case it is later deleted.  The
                 * auto-reload bit may get set in prvInitialiseNewTimer_core2(). */
                pxNewTimer_core2->ucStatus_core2 = tmrSTATUS_IS_STATICALLY_ALLOCATED_core2;

                prvInitialiseNewTimer_core2( pcTimerName_core2, xTimerPeriodInTicks_core2, xAutoReload_core2, pvTimerID_core2, pxCallbackFunction_core2, pxNewTimer_core2 );
            }

            return pxNewTimer_core2;
        }

    #endif /* configSUPPORT_STATIC_ALLOCATION_core2 */
/*-----------------------------------------------------------*/

    static void prvInitialiseNewTimer_core2( const char * const pcTimerName_core2, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                       const TickType_t_core2 xTimerPeriodInTicks_core2,
                                       const BaseType_t_core2 xAutoReload_core2,
                                       void * const pvTimerID_core2,
                                       TimerCallbackFunction_t_core2 pxCallbackFunction_core2,
                                       Timer_t_core2 * pxNewTimer_core2 )
    {
        /* 0 is not a valid value for xTimerPeriodInTicks_core2. */
        configASSERT_core2( ( xTimerPeriodInTicks_core2 > 0 ) );

        /* Ensure the infrastructure used by the timer service task_core2 has been
         * created/initialised. */
        prvCheckForValidListAndQueue_core2();

        /* Initialise the timer structure members using the function
         * parameters. */
        pxNewTimer_core2->pcTimerName_core2 = pcTimerName_core2;
        pxNewTimer_core2->xTimerPeriodInTicks_core2 = xTimerPeriodInTicks_core2;
        pxNewTimer_core2->pvTimerID_core2 = pvTimerID_core2;
        pxNewTimer_core2->pxCallbackFunction_core2 = pxCallbackFunction_core2;
        vListInitialiseItem_core2( &( pxNewTimer_core2->xTimerListItem_core2 ) );

        if( xAutoReload_core2 != pdFALSE_core2 )
        {
            pxNewTimer_core2->ucStatus_core2 |= tmrSTATUS_IS_AUTORELOAD_core2;
        }

        traceTIMER_CREATE_core2( pxNewTimer_core2 );
    }
/*-----------------------------------------------------------*/

    BaseType_t_core2 xTimerGenericCommand_core2( TimerHandle_t_core2 xTimer_core2,
                                     const BaseType_t_core2 xCommandID_core2,
                                     const TickType_t_core2 xOptionalValue_core2,
                                     BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2,
                                     const TickType_t_core2 xTicksToWait_core2 )
    {
        BaseType_t_core2 xReturn_core2 = pdFAIL_core2;
        DaemonTaskMessage_t_core2 xMessage_core2;

        configASSERT_core2( xTimer_core2 );

        /* Send a message to the timer service task_core2 to perform a particular action
         * on a particular timer definition. */
        if( xTimerQueue_core2 != NULL )
        {
            /* Send a command to the timer service task_core2 to start the xTimer_core2 timer. */
            xMessage_core2.xMessageID_core2 = xCommandID_core2;
            xMessage_core2.u.xTimerParameters_core2.xMessageValue_core2 = xOptionalValue_core2;
            xMessage_core2.u.xTimerParameters_core2.pxTimer_core2 = xTimer_core2;

            if( xCommandID_core2 < tmrFIRST_FROM_ISR_COMMAND_core2 )
            {
                if( xTaskGetSchedulerState_core2() == taskSCHEDULER_RUNNING_core2 )
                {
                    xReturn_core2 = xQueueSendToBack_core2( xTimerQueue_core2, &xMessage_core2, xTicksToWait_core2 );
                }
                else
                {
                    xReturn_core2 = xQueueSendToBack_core2( xTimerQueue_core2, &xMessage_core2, tmrNO_DELAY_core2 );
                }
            }
            else
            {
                xReturn_core2 = xQueueSendToBackFromISR_core2( xTimerQueue_core2, &xMessage_core2, pxHigherPriorityTaskWoken_core2 );
            }

            traceTIMER_COMMAND_SEND_core2( xTimer_core2, xCommandID_core2, xOptionalValue_core2, xReturn_core2 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }

        return xReturn_core2;
    }
/*-----------------------------------------------------------*/

    TaskHandle_t_core2 xTimerGetTimerDaemonTaskHandle_core2( void )
    {
        /* If xTimerGetTimerDaemonTaskHandle_core2() is called before the scheduler has been
         * started, then xTimerTaskHandle_core2 will be NULL. */
        configASSERT_core2( ( xTimerTaskHandle_core2 != NULL ) );
        return xTimerTaskHandle_core2;
    }
/*-----------------------------------------------------------*/

    TickType_t_core2 xTimerGetPeriod_core2( TimerHandle_t_core2 xTimer_core2 )
    {
        Timer_t_core2 * pxTimer_core2 = xTimer_core2;

        configASSERT_core2( xTimer_core2 );
        return pxTimer_core2->xTimerPeriodInTicks_core2;
    }
/*-----------------------------------------------------------*/

    void vTimerSetReloadMode_core2( TimerHandle_t_core2 xTimer_core2,
                              const BaseType_t_core2 xAutoReload_core2 )
    {
        Timer_t_core2 * pxTimer_core2 = xTimer_core2;

        configASSERT_core2( xTimer_core2 );
        taskENTER_CRITICAL_core2();
        {
            if( xAutoReload_core2 != pdFALSE_core2 )
            {
                pxTimer_core2->ucStatus_core2 |= tmrSTATUS_IS_AUTORELOAD_core2;
            }
            else
            {
                pxTimer_core2->ucStatus_core2 &= ( ( uint8_t ) ~tmrSTATUS_IS_AUTORELOAD_core2 );
            }
        }
        taskEXIT_CRITICAL_core2();
    }
/*-----------------------------------------------------------*/

    BaseType_t_core2 xTimerGetReloadMode_core2( TimerHandle_t_core2 xTimer_core2 )
    {
        Timer_t_core2 * pxTimer_core2 = xTimer_core2;
        BaseType_t_core2 xReturn_core2;

        configASSERT_core2( xTimer_core2 );
        taskENTER_CRITICAL_core2();
        {
            if( ( pxTimer_core2->ucStatus_core2 & tmrSTATUS_IS_AUTORELOAD_core2 ) == 0 )
            {
                /* Not an auto-reload timer. */
                xReturn_core2 = pdFALSE_core2;
            }
            else
            {
                /* Is an auto-reload timer. */
                xReturn_core2 = pdTRUE_core2;
            }
        }
        taskEXIT_CRITICAL_core2();

        return xReturn_core2;
    }

    UBaseType_t_core2 uxTimerGetReloadMode_core2( TimerHandle_t_core2 xTimer_core2 )
    {
        return ( UBaseType_t_core2 ) xTimerGetReloadMode_core2( xTimer_core2 );
    }
/*-----------------------------------------------------------*/

    TickType_t_core2 xTimerGetExpiryTime_core2( TimerHandle_t_core2 xTimer_core2 )
    {
        Timer_t_core2 * pxTimer_core2 = xTimer_core2;
        TickType_t_core2 xReturn_core2;

        configASSERT_core2( xTimer_core2 );
        xReturn_core2 = listGET_LIST_ITEM_VALUE_core2( &( pxTimer_core2->xTimerListItem_core2 ) );
        return xReturn_core2;
    }
/*-----------------------------------------------------------*/

    const char * pcTimerGetName_core2( TimerHandle_t_core2 xTimer_core2 ) /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
    {
        Timer_t_core2 * pxTimer_core2 = xTimer_core2;

        configASSERT_core2( xTimer_core2 );
        return pxTimer_core2->pcTimerName_core2;
    }
/*-----------------------------------------------------------*/

    static void prvReloadTimer_core2( Timer_t_core2 * const pxTimer_core2,
                                TickType_t_core2 xExpiredTime_core2,
                                const TickType_t_core2 xTimeNow_core2 )
    {
        /* Insert the timer into the appropriate list for the next expiry time.
         * If the next expiry time has already passed, advance the expiry time,
         * call the callback function, and try again. */
        while( prvInsertTimerInActiveList_core2( pxTimer_core2, ( xExpiredTime_core2 + pxTimer_core2->xTimerPeriodInTicks_core2 ), xTimeNow_core2, xExpiredTime_core2 ) != pdFALSE_core2 )
        {
            /* Advance the expiry time. */
            xExpiredTime_core2 += pxTimer_core2->xTimerPeriodInTicks_core2;

            /* Call the timer callback. */
            traceTIMER_EXPIRED_core2( pxTimer_core2 );
            pxTimer_core2->pxCallbackFunction_core2( ( TimerHandle_t_core2 ) pxTimer_core2 );
        }
    }
/*-----------------------------------------------------------*/

    static void prvProcessExpiredTimer_core2( const TickType_t_core2 xNextExpireTime_core2,
                                        const TickType_t_core2 xTimeNow_core2 )
    {
        Timer_t_core2 * const pxTimer_core2 = ( Timer_t_core2 * ) listGET_OWNER_OF_HEAD_ENTRY_core2( pxCurrentTimerList_core2 ); /*lint !e9087 !e9079 void * is used as this macro is used with tasks and co-routines too.  Alignment is known to be fine as the type of the pointer stored and retrieved is the same. */

        /* Remove the timer from the list of active timers_core2.  A check has already
         * been performed to ensure the list is not empty. */

        ( void ) uxListRemove_core2( &( pxTimer_core2->xTimerListItem_core2 ) );

        /* If the timer is an auto-reload timer then calculate the next
         * expiry time and re-insert the timer in the list of active timers_core2. */
        if( ( pxTimer_core2->ucStatus_core2 & tmrSTATUS_IS_AUTORELOAD_core2 ) != 0 )
        {
            prvReloadTimer_core2( pxTimer_core2, xNextExpireTime_core2, xTimeNow_core2 );
        }
        else
        {
            pxTimer_core2->ucStatus_core2 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core2 );
        }

        /* Call the timer callback. */
        traceTIMER_EXPIRED_core2( pxTimer_core2 );
        pxTimer_core2->pxCallbackFunction_core2( ( TimerHandle_t_core2 ) pxTimer_core2 );
    }
/*-----------------------------------------------------------*/

    static portTASK_FUNCTION_core2( prvTimerTask_core2, pvParameters_core2 )
    {
        TickType_t_core2 xNextExpireTime_core2;
        BaseType_t_core2 xListWasEmpty_core2;

        /* Just to avoid compiler warnings. */
        ( void ) pvParameters_core2;

        #if ( configUSE_DAEMON_TASK_STARTUP_HOOK_core2 == 1 )
        {
            extern void vApplicationDaemonTaskStartupHook_core2( void );

            /* Allow the application writer to execute some code in the context of
             * this task_core2 at the point the task_core2 starts executing.  This is useful if the
             * application includes initialisation code that would benefit from
             * executing after the scheduler has been started. */
            vApplicationDaemonTaskStartupHook_core2();
        }
        #endif /* configUSE_DAEMON_TASK_STARTUP_HOOK_core2 */

        for( ; ; )
        {
            /* Query the timers_core2 list to see if it contains any timers_core2, and if so,
             * obtain the time at which the next timer will expire. */
            xNextExpireTime_core2 = prvGetNextExpireTime_core2( &xListWasEmpty_core2 );

            /* If a timer has expired, process it.  Otherwise, block this task_core2
             * until either a timer does expire, or a command is received. */
            prvProcessTimerOrBlockTask_core2( xNextExpireTime_core2, xListWasEmpty_core2 );

            /* Empty the command queue. */
            prvProcessReceivedCommands_core2();
        }
    }
/*-----------------------------------------------------------*/

    static void prvProcessTimerOrBlockTask_core2( const TickType_t_core2 xNextExpireTime_core2,
                                            BaseType_t_core2 xListWasEmpty_core2 )
    {
        TickType_t_core2 xTimeNow_core2;
        BaseType_t_core2 xTimerListsWereSwitched_core2;

        vTaskSuspendAll_core2();
        {
            /* Obtain the time now to make an assessment as to whether the timer
             * has expired or not.  If obtaining the time causes the lists to switch
             * then don't process this timer as any timers_core2 that remained in the list
             * when the lists were switched will have been processed within the
             * prvSampleTimeNow_core2() function. */
            xTimeNow_core2 = prvSampleTimeNow_core2( &xTimerListsWereSwitched_core2 );

            if( xTimerListsWereSwitched_core2 == pdFALSE_core2 )
            {
                /* The tick count has not overflowed, has the timer expired? */
                if( ( xListWasEmpty_core2 == pdFALSE_core2 ) && ( xNextExpireTime_core2 <= xTimeNow_core2 ) )
                {
                    ( void ) xTaskResumeAll_core2();
                    prvProcessExpiredTimer_core2( xNextExpireTime_core2, xTimeNow_core2 );
                }
                else
                {
                    /* The tick count has not overflowed, and the next expire
                     * time has not been reached yet.  This task_core2 should therefore
                     * block to wait for the next expire time or a command to be
                     * received - whichever comes first.  The following line cannot
                     * be reached unless xNextExpireTime_core2 > xTimeNow_core2, except in the
                     * case when the current timer list is empty. */
                    if( xListWasEmpty_core2 != pdFALSE_core2 )
                    {
                        /* The current timer list is empty - is the overflow list
                         * also empty? */
                        xListWasEmpty_core2 = listLIST_IS_EMPTY_core2( pxOverflowTimerList_core2 );
                    }

                    vQueueWaitForMessageRestricted_core2( xTimerQueue_core2, ( xNextExpireTime_core2 - xTimeNow_core2 ), xListWasEmpty_core2 );

                    if( xTaskResumeAll_core2() == pdFALSE_core2 )
                    {
                        /* Yield to wait for either a command to arrive, or the
                         * block time to expire.  If a command arrived between the
                         * critical section being exited and this yield then the yield
                         * will not cause the task_core2 to block. */
                        portYIELD_WITHIN_API_core2();
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core2();
                    }
                }
            }
            else
            {
                ( void ) xTaskResumeAll_core2();
            }
        }
    }
/*-----------------------------------------------------------*/

    static TickType_t_core2 prvGetNextExpireTime_core2( BaseType_t_core2 * const pxListWasEmpty_core2 )
    {
        TickType_t_core2 xNextExpireTime_core2;

        /* Timers are listed in expiry time order, with the head of the list
         * referencing the task_core2 that will expire first.  Obtain the time at which
         * the timer with the nearest expiry time will expire.  If there are no
         * active timers_core2 then just set the next expire time to 0.  That will cause
         * this task_core2 to unblock when the tick count overflows, at which point the
         * timer lists will be switched and the next expiry time can be
         * re-assessed.  */
        *pxListWasEmpty_core2 = listLIST_IS_EMPTY_core2( pxCurrentTimerList_core2 );

        if( *pxListWasEmpty_core2 == pdFALSE_core2 )
        {
            xNextExpireTime_core2 = listGET_ITEM_VALUE_OF_HEAD_ENTRY_core2( pxCurrentTimerList_core2 );
        }
        else
        {
            /* Ensure the task_core2 unblocks when the tick count rolls over. */
            xNextExpireTime_core2 = ( TickType_t_core2 ) 0U;
        }

        return xNextExpireTime_core2;
    }
/*-----------------------------------------------------------*/

    static TickType_t_core2 prvSampleTimeNow_core2( BaseType_t_core2 * const pxTimerListsWereSwitched_core2 )
    {
        TickType_t_core2 xTimeNow_core2;
        PRIVILEGED_DATA_core2 static TickType_t_core2 xLastTime_core2 = ( TickType_t_core2 ) 0U; /*lint !e956 Variable is only accessible to one task_core2. */

        xTimeNow_core2 = xTaskGetTickCount_core2();

        if( xTimeNow_core2 < xLastTime_core2 )
        {
            prvSwitchTimerLists_core2();
            *pxTimerListsWereSwitched_core2 = pdTRUE_core2;
        }
        else
        {
            *pxTimerListsWereSwitched_core2 = pdFALSE_core2;
        }

        xLastTime_core2 = xTimeNow_core2;

        return xTimeNow_core2;
    }
/*-----------------------------------------------------------*/

    static BaseType_t_core2 prvInsertTimerInActiveList_core2( Timer_t_core2 * const pxTimer_core2,
                                                  const TickType_t_core2 xNextExpiryTime_core2,
                                                  const TickType_t_core2 xTimeNow_core2,
                                                  const TickType_t_core2 xCommandTime_core2 )
    {
        BaseType_t_core2 xProcessTimerNow_core2 = pdFALSE_core2;

        listSET_LIST_ITEM_VALUE_core2( &( pxTimer_core2->xTimerListItem_core2 ), xNextExpiryTime_core2 );
        listSET_LIST_ITEM_OWNER_core2( &( pxTimer_core2->xTimerListItem_core2 ), pxTimer_core2 );

        if( xNextExpiryTime_core2 <= xTimeNow_core2 )
        {
            /* Has the expiry time elapsed between the command to start/reset a
             * timer was issued, and the time the command was processed? */
            if( ( ( TickType_t_core2 ) ( xTimeNow_core2 - xCommandTime_core2 ) ) >= pxTimer_core2->xTimerPeriodInTicks_core2 ) /*lint !e961 MISRA exception as the casts are only redundant for some ports. */
            {
                /* The time between a command being issued and the command being
                 * processed actually exceeds the timers_core2 period.  */
                xProcessTimerNow_core2 = pdTRUE_core2;
            }
            else
            {
                vListInsert_core2( pxOverflowTimerList_core2, &( pxTimer_core2->xTimerListItem_core2 ) );
            }
        }
        else
        {
            if( ( xTimeNow_core2 < xCommandTime_core2 ) && ( xNextExpiryTime_core2 >= xCommandTime_core2 ) )
            {
                /* If, since the command was issued, the tick count has overflowed
                 * but the expiry time has not, then the timer must have already passed
                 * its expiry time and should be processed immediately. */
                xProcessTimerNow_core2 = pdTRUE_core2;
            }
            else
            {
                vListInsert_core2( pxCurrentTimerList_core2, &( pxTimer_core2->xTimerListItem_core2 ) );
            }
        }

        return xProcessTimerNow_core2;
    }
/*-----------------------------------------------------------*/

    static void prvProcessReceivedCommands_core2( void )
    {
        DaemonTaskMessage_t_core2 xMessage_core2;
        Timer_t_core2 * pxTimer_core2;
        BaseType_t_core2 xTimerListsWereSwitched_core2;
        TickType_t_core2 xTimeNow_core2;

        while( xQueueReceive_core2( xTimerQueue_core2, &xMessage_core2, tmrNO_DELAY_core2 ) != pdFAIL_core2 ) /*lint !e603 xMessage_core2 does not have to be initialised as it is passed out, not in, and it is not used unless xQueueReceive_core2() returns pdTRUE_core2. */
        {
            #if ( INCLUDE_xTimerPendFunctionCall_core2 == 1 )
            {
                /* Negative commands are pended function calls rather than timer
                 * commands. */
                if( xMessage_core2.xMessageID_core2 < ( BaseType_t_core2 ) 0 )
                {
                    const CallbackParameters_t_core2 * const pxCallback_core2 = &( xMessage_core2.u.xCallbackParameters_core2 );

                    /* The timer uses the xCallbackParameters_core2 member to request a
                     * callback be executed.  Check the callback is not NULL. */
                    configASSERT_core2( pxCallback_core2 );

                    /* Call the function. */
                    pxCallback_core2->pxCallbackFunction_core2( pxCallback_core2->pvParameter1_core2, pxCallback_core2->ulParameter2_core2 );
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core2();
                }
            }
            #endif /* INCLUDE_xTimerPendFunctionCall_core2 */

            /* Commands that are positive are timer commands rather than pended
             * function calls. */
            if( xMessage_core2.xMessageID_core2 >= ( BaseType_t_core2 ) 0 )
            {
                /* The messages uses the xTimerParameters_core2 member to work on a
                 * software timer. */
                pxTimer_core2 = xMessage_core2.u.xTimerParameters_core2.pxTimer_core2;

                if( listIS_CONTAINED_WITHIN_core2( NULL, &( pxTimer_core2->xTimerListItem_core2 ) ) == pdFALSE_core2 ) /*lint !e961. The cast is only redundant when NULL is passed into the macro. */
                {
                    /* The timer is in a list, remove it. */
                    ( void ) uxListRemove_core2( &( pxTimer_core2->xTimerListItem_core2 ) );
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core2();
                }

                traceTIMER_COMMAND_RECEIVED_core2( pxTimer_core2, xMessage_core2.xMessageID_core2, xMessage_core2.u.xTimerParameters_core2.xMessageValue_core2 );

                /* In this case the xTimerListsWereSwitched_core2 parameter is not used, but
                 *  it must be present in the function call.  prvSampleTimeNow_core2() must be
                 *  called after the message is received from xTimerQueue_core2 so there is no
                 *  possibility of a higher priority task_core2 adding a message to the message
                 *  queue with a time that is ahead of the timer daemon task_core2 (because it
                 *  pre-empted the timer daemon task_core2 after the xTimeNow_core2 value was set). */
                xTimeNow_core2 = prvSampleTimeNow_core2( &xTimerListsWereSwitched_core2 );

                switch( xMessage_core2.xMessageID_core2 )
                {
                    case tmrCOMMAND_START_core2:
                    case tmrCOMMAND_START_FROM_ISR_core2:
                    case tmrCOMMAND_RESET_core2:
                    case tmrCOMMAND_RESET_FROM_ISR_core2:
                        /* Start or restart a timer. */
                        pxTimer_core2->ucStatus_core2 |= tmrSTATUS_IS_ACTIVE_core2;

                        if( prvInsertTimerInActiveList_core2( pxTimer_core2, xMessage_core2.u.xTimerParameters_core2.xMessageValue_core2 + pxTimer_core2->xTimerPeriodInTicks_core2, xTimeNow_core2, xMessage_core2.u.xTimerParameters_core2.xMessageValue_core2 ) != pdFALSE_core2 )
                        {
                            /* The timer expired before it was added to the active
                             * timer list.  Process it now. */
                            if( ( pxTimer_core2->ucStatus_core2 & tmrSTATUS_IS_AUTORELOAD_core2 ) != 0 )
                            {
                                prvReloadTimer_core2( pxTimer_core2, xMessage_core2.u.xTimerParameters_core2.xMessageValue_core2 + pxTimer_core2->xTimerPeriodInTicks_core2, xTimeNow_core2 );
                            }
                            else
                            {
                                pxTimer_core2->ucStatus_core2 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core2 );
                            }

                            /* Call the timer callback. */
                            traceTIMER_EXPIRED_core2( pxTimer_core2 );
                            pxTimer_core2->pxCallbackFunction_core2( ( TimerHandle_t_core2 ) pxTimer_core2 );
                        }
                        else
                        {
                            mtCOVERAGE_TEST_MARKER_core2();
                        }

                        break;

                    case tmrCOMMAND_STOP_core2:
                    case tmrCOMMAND_STOP_FROM_ISR_core2:
                        /* The timer has already been removed from the active list. */
                        pxTimer_core2->ucStatus_core2 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core2 );
                        break;

                    case tmrCOMMAND_CHANGE_PERIOD_core2:
                    case tmrCOMMAND_CHANGE_PERIOD_FROM_ISR_core2:
                        pxTimer_core2->ucStatus_core2 |= tmrSTATUS_IS_ACTIVE_core2;
                        pxTimer_core2->xTimerPeriodInTicks_core2 = xMessage_core2.u.xTimerParameters_core2.xMessageValue_core2;
                        configASSERT_core2( ( pxTimer_core2->xTimerPeriodInTicks_core2 > 0 ) );

                        /* The new period does not really have a reference, and can
                         * be longer or shorter than the old one.  The command time is
                         * therefore set to the current time, and as the period cannot
                         * be zero the next expiry time can only be in the future,
                         * meaning (unlike for the xTimerStart_core2() case above) there is
                         * no fail case that needs to be handled here. */
                        ( void ) prvInsertTimerInActiveList_core2( pxTimer_core2, ( xTimeNow_core2 + pxTimer_core2->xTimerPeriodInTicks_core2 ), xTimeNow_core2, xTimeNow_core2 );
                        break;

                    case tmrCOMMAND_DELETE_core2:
                        #if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 )
                        {
                            /* The timer has already been removed from the active list,
                             * just free up the memory if the memory was dynamically
                             * allocated. */
                            if( ( pxTimer_core2->ucStatus_core2 & tmrSTATUS_IS_STATICALLY_ALLOCATED_core2 ) == ( uint8_t ) 0 )
                            {
                                vPortFree_core2( pxTimer_core2 );
                            }
                            else
                            {
                                pxTimer_core2->ucStatus_core2 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core2 );
                            }
                        }
                        #else /* if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 ) */
                        {
                            /* If dynamic allocation is not enabled, the memory
                             * could not have been dynamically allocated. So there is
                             * no need to free the memory - just mark the timer as
                             * "not active". */
                            pxTimer_core2->ucStatus_core2 &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE_core2 );
                        }
                        #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core2 */
                        break;

                    default:
                        /* Don't expect to get here. */
                        break;
                }
            }
        }
    }
/*-----------------------------------------------------------*/

    static void prvSwitchTimerLists_core2( void )
    {
        TickType_t_core2 xNextExpireTime_core2;
        List_t_core2 * pxTemp_core2;

        /* The tick count has overflowed.  The timer lists must be switched.
         * If there are any timers_core2 still referenced from the current timer list
         * then they must have expired and should be processed before the lists
         * are switched. */
        while( listLIST_IS_EMPTY_core2( pxCurrentTimerList_core2 ) == pdFALSE_core2 )
        {
            xNextExpireTime_core2 = listGET_ITEM_VALUE_OF_HEAD_ENTRY_core2( pxCurrentTimerList_core2 );

            /* Process the expired timer.  For auto-reload timers_core2, be careful to
             * process only expirations that occur on the current list.  Further
             * expirations must wait until after the lists are switched. */
            prvProcessExpiredTimer_core2( xNextExpireTime_core2, tmrMAX_TIME_BEFORE_OVERFLOW_core2 );
        }

        pxTemp_core2 = pxCurrentTimerList_core2;
        pxCurrentTimerList_core2 = pxOverflowTimerList_core2;
        pxOverflowTimerList_core2 = pxTemp_core2;
    }
/*-----------------------------------------------------------*/

    static void prvCheckForValidListAndQueue_core2( void )
    {
        /* Check that the list from which active timers_core2 are referenced, and the
         * queue used to communicate with the timer service, have been
         * initialised. */
        taskENTER_CRITICAL_core2();
        {
            if( xTimerQueue_core2 == NULL )
            {
                vListInitialise_core2( &xActiveTimerList1_core2 );
                vListInitialise_core2( &xActiveTimerList2_core2 );
                pxCurrentTimerList_core2 = &xActiveTimerList1_core2;
                pxOverflowTimerList_core2 = &xActiveTimerList2_core2;

                #if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )
                {
                    /* The timer queue is allocated statically in case
                     * configSUPPORT_DYNAMIC_ALLOCATION_core2 is 0. */
                    PRIVILEGED_DATA_core2 static StaticQueue_t_core2 xStaticTimerQueue_core2;                                                                          /*lint !e956 Ok to declare in this manner to prevent additional conditional compilation guards in other locations. */
                    PRIVILEGED_DATA_core2 static uint8_t ucStaticTimerQueueStorage_core2[ ( size_t ) configTIMER_QUEUE_LENGTH_core2 * sizeof( DaemonTaskMessage_t_core2 ) ]; /*lint !e956 Ok to declare in this manner to prevent additional conditional compilation guards in other locations. */

                    xTimerQueue_core2 = xQueueCreateStatic_core2( ( UBaseType_t_core2 ) configTIMER_QUEUE_LENGTH_core2, ( UBaseType_t_core2 ) sizeof( DaemonTaskMessage_t_core2 ), &( ucStaticTimerQueueStorage_core2[ 0 ] ), &xStaticTimerQueue_core2 );
                }
                #else
                {
                    xTimerQueue_core2 = xQueueCreate_core2( ( UBaseType_t_core2 ) configTIMER_QUEUE_LENGTH_core2, sizeof( DaemonTaskMessage_t_core2 ) );
                }
                #endif /* if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 ) */

                #if ( configQUEUE_REGISTRY_SIZE_core2 > 0 )
                {
                    if( xTimerQueue_core2 != NULL )
                    {
                        vQueueAddToRegistry_core2( xTimerQueue_core2, "TmrQ_core2" );
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core2();
                    }
                }
                #endif /* configQUEUE_REGISTRY_SIZE_core2 */
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core2();
            }
        }
        taskEXIT_CRITICAL_core2();
    }
/*-----------------------------------------------------------*/

    BaseType_t_core2 xTimerIsTimerActive_core2( TimerHandle_t_core2 xTimer_core2 )
    {
        BaseType_t_core2 xReturn_core2;
        Timer_t_core2 * pxTimer_core2 = xTimer_core2;

        configASSERT_core2( xTimer_core2 );

        /* Is the timer in the list of active timers_core2? */
        taskENTER_CRITICAL_core2();
        {
            if( ( pxTimer_core2->ucStatus_core2 & tmrSTATUS_IS_ACTIVE_core2 ) == 0 )
            {
                xReturn_core2 = pdFALSE_core2;
            }
            else
            {
                xReturn_core2 = pdTRUE_core2;
            }
        }
        taskEXIT_CRITICAL_core2();

        return xReturn_core2;
    } /*lint !e818 Can't be pointer to const due to the typedef. */
/*-----------------------------------------------------------*/

    void * pvTimerGetTimerID_core2( const TimerHandle_t_core2 xTimer_core2 )
    {
        Timer_t_core2 * const pxTimer_core2 = xTimer_core2;
        void * pvReturn_core2;

        configASSERT_core2( xTimer_core2 );

        taskENTER_CRITICAL_core2();
        {
            pvReturn_core2 = pxTimer_core2->pvTimerID_core2;
        }
        taskEXIT_CRITICAL_core2();

        return pvReturn_core2;
    }
/*-----------------------------------------------------------*/

    void vTimerSetTimerID_core2( TimerHandle_t_core2 xTimer_core2,
                           void * pvNewID_core2 )
    {
        Timer_t_core2 * const pxTimer_core2 = xTimer_core2;

        configASSERT_core2( xTimer_core2 );

        taskENTER_CRITICAL_core2();
        {
            pxTimer_core2->pvTimerID_core2 = pvNewID_core2;
        }
        taskEXIT_CRITICAL_core2();
    }
/*-----------------------------------------------------------*/

    #if ( INCLUDE_xTimerPendFunctionCall_core2 == 1 )

        BaseType_t_core2 xTimerPendFunctionCallFromISR_core2( PendedFunction_t_core2 xFunctionToPend_core2,
                                                  void * pvParameter1_core2,
                                                  uint32_t ulParameter2_core2,
                                                  BaseType_t_core2 * pxHigherPriorityTaskWoken_core2 )
        {
            DaemonTaskMessage_t_core2 xMessage_core2;
            BaseType_t_core2 xReturn_core2;

            /* Complete the message with the function parameters and post it to the
             * daemon task_core2. */
            xMessage_core2.xMessageID_core2 = tmrCOMMAND_EXECUTE_CALLBACK_FROM_ISR_core2;
            xMessage_core2.u.xCallbackParameters_core2.pxCallbackFunction_core2 = xFunctionToPend_core2;
            xMessage_core2.u.xCallbackParameters_core2.pvParameter1_core2 = pvParameter1_core2;
            xMessage_core2.u.xCallbackParameters_core2.ulParameter2_core2 = ulParameter2_core2;

            xReturn_core2 = xQueueSendFromISR_core2( xTimerQueue_core2, &xMessage_core2, pxHigherPriorityTaskWoken_core2 );

            tracePEND_FUNC_CALL_FROM_ISR_core2( xFunctionToPend_core2, pvParameter1_core2, ulParameter2_core2, xReturn_core2 );

            return xReturn_core2;
        }

    #endif /* INCLUDE_xTimerPendFunctionCall_core2 */
/*-----------------------------------------------------------*/

    #if ( INCLUDE_xTimerPendFunctionCall_core2 == 1 )

        BaseType_t_core2 xTimerPendFunctionCall_core2( PendedFunction_t_core2 xFunctionToPend_core2,
                                           void * pvParameter1_core2,
                                           uint32_t ulParameter2_core2,
                                           TickType_t_core2 xTicksToWait_core2 )
        {
            DaemonTaskMessage_t_core2 xMessage_core2;
            BaseType_t_core2 xReturn_core2;

            /* This function can only be called after a timer has been created or
             * after the scheduler has been started because, until then, the timer
             * queue does not exist. */
            configASSERT_core2( xTimerQueue_core2 );

            /* Complete the message with the function parameters and post it to the
             * daemon task_core2. */
            xMessage_core2.xMessageID_core2 = tmrCOMMAND_EXECUTE_CALLBACK_core2;
            xMessage_core2.u.xCallbackParameters_core2.pxCallbackFunction_core2 = xFunctionToPend_core2;
            xMessage_core2.u.xCallbackParameters_core2.pvParameter1_core2 = pvParameter1_core2;
            xMessage_core2.u.xCallbackParameters_core2.ulParameter2_core2 = ulParameter2_core2;

            xReturn_core2 = xQueueSendToBack_core2( xTimerQueue_core2, &xMessage_core2, xTicksToWait_core2 );

            tracePEND_FUNC_CALL_core2( xFunctionToPend_core2, pvParameter1_core2, ulParameter2_core2, xReturn_core2 );

            return xReturn_core2;
        }

    #endif /* INCLUDE_xTimerPendFunctionCall_core2 */
/*-----------------------------------------------------------*/

    #if ( configUSE_TRACE_FACILITY_core2 == 1 )

        UBaseType_t_core2 uxTimerGetTimerNumber_core2( TimerHandle_t_core2 xTimer_core2 )
        {
            return ( ( Timer_t_core2 * ) xTimer_core2 )->uxTimerNumber_core2;
        }

    #endif /* configUSE_TRACE_FACILITY_core2 */
/*-----------------------------------------------------------*/

    #if ( configUSE_TRACE_FACILITY_core2 == 1 )

        void vTimerSetTimerNumber_core2( TimerHandle_t_core2 xTimer_core2,
                                   UBaseType_t_core2 uxTimerNumber_core2 )
        {
            ( ( Timer_t_core2 * ) xTimer_core2 )->uxTimerNumber_core2 = uxTimerNumber_core2;
        }

    #endif /* configUSE_TRACE_FACILITY_core2 */
/*-----------------------------------------------------------*/

/* This entire source file will be skipped if the application is not configured
 * to include software timer functionality.  If you want to include software timer
 * functionality then ensure configUSE_TIMERS_core2 is set to 1 in FreeRTOSConfig.h. */
#endif /* configUSE_TIMERS_core2 == 1 */
