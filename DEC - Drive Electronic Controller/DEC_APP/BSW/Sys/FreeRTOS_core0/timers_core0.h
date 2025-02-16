/*
 * FreeRTOS_core0 Kernel V10.5.1
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
 * https://www.FreeRTOS_core0.org
 * https://github.com/FreeRTOS_core0
 *
 */


#ifndef TIMERS_CORE0_H
#define TIMERS_CORE0_H

#ifndef INC_FREERTOS_CORE0_H
    #error "include FreeRTOS_core0.h must appear in source files before include timers_core0.h"
#endif

/*lint -save -e537 This headers are only multiply included if the application code
 * happens to also be including task_core0.h. */
#include "task_core0.h"
/*lint -restore */

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

/*-----------------------------------------------------------
* MACROS AND DEFINITIONS
*----------------------------------------------------------*/

/* IDs for commands that can be sent/received on the timer queue.  These are to
 * be used solely through the macros that make up the public software timer API,
 * as defined below.  The commands that are sent from interrupts must use the
 * highest numbers as tmrFIRST_FROM_ISR_COMMAND_core0 is used to determine if the task_core0
 * or interrupt version of the queue send function should be used. */
#define tmrCOMMAND_EXECUTE_CALLBACK_FROM_ISR_core0    ( ( BaseType_t_core0 ) -2 )
#define tmrCOMMAND_EXECUTE_CALLBACK_core0             ( ( BaseType_t_core0 ) -1 )
#define tmrCOMMAND_START_DONT_TRACE_core0             ( ( BaseType_t_core0 ) 0 )
#define tmrCOMMAND_START_core0                        ( ( BaseType_t_core0 ) 1 )
#define tmrCOMMAND_RESET_core0                        ( ( BaseType_t_core0 ) 2 )
#define tmrCOMMAND_STOP_core0                         ( ( BaseType_t_core0 ) 3 )
#define tmrCOMMAND_CHANGE_PERIOD_core0                ( ( BaseType_t_core0 ) 4 )
#define tmrCOMMAND_DELETE_core0                       ( ( BaseType_t_core0 ) 5 )

#define tmrFIRST_FROM_ISR_COMMAND_core0               ( ( BaseType_t_core0 ) 6 )
#define tmrCOMMAND_START_FROM_ISR_core0               ( ( BaseType_t_core0 ) 6 )
#define tmrCOMMAND_RESET_FROM_ISR_core0               ( ( BaseType_t_core0 ) 7 )
#define tmrCOMMAND_STOP_FROM_ISR_core0                ( ( BaseType_t_core0 ) 8 )
#define tmrCOMMAND_CHANGE_PERIOD_FROM_ISR_core0       ( ( BaseType_t_core0 ) 9 )


/**
 * Type by which software timers_core0 are referenced.  For example, a call to
 * xTimerCreate_core0() returns an TimerHandle_t_core0 variable that can then be used to
 * reference the subject timer in calls to other software timer API functions
 * (for example, xTimerStart_core0(), xTimerReset_core0(), etc.).
 */
struct tmrTimerControl_core0; /* The old naming convention is used to prevent breaking kernel aware debuggers. */
typedef struct tmrTimerControl_core0 * TimerHandle_t_core0;

/*
 * Defines the prototype to which timer callback functions must conform.
 */
typedef void (* TimerCallbackFunction_t_core0)( TimerHandle_t_core0 xTimer_core0 );

/*
 * Defines the prototype to which functions used with the
 * xTimerPendFunctionCallFromISR_core0() function must conform.
 */
typedef void (* PendedFunction_t_core0)( void *,
                                   uint32_t );

/**
 * TimerHandle_t_core0 xTimerCreate_core0(  const char * const pcTimerName_core0,
 *                              TickType_t_core0 xTimerPeriodInTicks_core0,
 *                              BaseType_t_core0 xAutoReload_core0,
 *                              void * pvTimerID_core0,
 *                              TimerCallbackFunction_t_core0 pxCallbackFunction_core0 );
 *
 * Creates a new software timer instance, and returns a handle by which the
 * created software timer can be referenced.
 *
 * Internally, within the FreeRTOS_core0 implementation, software timers_core0 use a block
 * of memory, in which the timer data structure is stored.  If a software timer
 * is created using xTimerCreate_core0() then the required memory is automatically
 * dynamically allocated inside the xTimerCreate_core0() function.  (see
 * https://www.FreeRTOS_core0.org/a00111.html).  If a software timer is created using
 * xTimerCreateStatic_core0() then the application writer must provide the memory that
 * will get used by the software timer.  xTimerCreateStatic_core0() therefore allows a
 * software timer to be created without using any dynamic memory allocation.
 *
 * Timers are created in the dormant state.  The xTimerStart_core0(), xTimerReset_core0(),
 * xTimerStartFromISR_core0(), xTimerResetFromISR_core0(), xTimerChangePeriod_core0() and
 * xTimerChangePeriodFromISR_core0() API functions can all be used to transition a
 * timer into the active state.
 *
 * @param pcTimerName_core0 A text name that is assigned to the timer.  This is done
 * purely to assist debugging.  The kernel itself only ever references a timer
 * by its handle, and never by its name.
 *
 * @param xTimerPeriodInTicks_core0 The timer period.  The time is defined in tick
 * periods so the constant portTICK_PERIOD_MS_core0 can be used to convert a time that
 * has been specified in milliseconds.  For example, if the timer must expire
 * after 100 ticks, then xTimerPeriodInTicks_core0 should be set to 100.
 * Alternatively, if the timer must expire after 500ms, then xPeriod can be set
 * to ( 500 / portTICK_PERIOD_MS_core0 ) provided configTICK_RATE_HZ_core0 is less than or
 * equal to 1000.  Time timer period must be greater than 0.
 *
 * @param xAutoReload_core0 If xAutoReload_core0 is set to pdTRUE_core0 then the timer will
 * expire repeatedly with a frequency set by the xTimerPeriodInTicks_core0 parameter.
 * If xAutoReload_core0 is set to pdFALSE_core0 then the timer will be a one-shot timer and
 * enter the dormant state after it expires.
 *
 * @param pvTimerID_core0 An identifier that is assigned to the timer being created.
 * Typically this would be used in the timer callback function to identify which
 * timer expired when the same callback function is assigned to more than one
 * timer.
 *
 * @param pxCallbackFunction_core0 The function to call when the timer expires.
 * Callback functions must have the prototype defined by TimerCallbackFunction_t_core0,
 * which is "void vCallbackFunction( TimerHandle_t_core0 xTimer_core0 );".
 *
 * @return If the timer is successfully created then a handle to the newly
 * created timer is returned.  If the timer cannot be created because there is
 * insufficient FreeRTOS_core0 heap remaining to allocate the timer
 * structures then NULL is returned.
 *
 * Example usage:
 * @verbatim
 * #define NUM_TIMERS 5
 *
 * // An array to hold handles to the created timers_core0.
 * TimerHandle_t_core0 xTimers[ NUM_TIMERS ];
 *
 * // An array to hold a count of the number of times each timer expires.
 * int32_t lExpireCounters[ NUM_TIMERS ] = { 0 };
 *
 * // Define a callback function that will be used by multiple timer instances.
 * // The callback function does nothing but count the number of times the
 * // associated timer expires, and stop the timer once the timer has expired
 * // 10 times.
 * void vTimerCallback( TimerHandle_t_core0 pxTimer_core0 )
 * {
 * int32_t lArrayIndex;
 * const int32_t xMaxExpiryCountBeforeStopping = 10;
 *
 *     // Optionally do something if the pxTimer_core0 parameter is NULL.
 *     configASSERT_core0( pxTimer_core0 );
 *
 *     // Which timer expired?
 *     lArrayIndex = ( int32_t ) pvTimerGetTimerID_core0( pxTimer_core0 );
 *
 *     // Increment the number of times that pxTimer_core0 has expired.
 *     lExpireCounters[ lArrayIndex ] += 1;
 *
 *     // If the timer has expired 10 times then stop it from running.
 *     if( lExpireCounters[ lArrayIndex ] == xMaxExpiryCountBeforeStopping )
 *     {
 *         // Do not use a block time if calling a timer API function from a
 *         // timer callback function, as doing so could cause a deadlock!
 *         xTimerStop_core0( pxTimer_core0, 0 );
 *     }
 * }
 *
 * void main( void )
 * {
 * int32_t x_core0;
 *
 *     // Create then start some timers_core0.  Starting the timers_core0 before the scheduler
 *     // has been started means the timers_core0 will start running immediately that
 *     // the scheduler starts.
 *     for( x_core0 = 0; x_core0 < NUM_TIMERS; x_core0++ )
 *     {
 *         xTimers[ x_core0 ] = xTimerCreate_core0(    "Timer",             // Just a text name, not used by the kernel.
 *                                         ( 100 * ( x_core0 + 1 ) ), // The timer period in ticks.
 *                                         pdTRUE_core0,              // The timers_core0 will auto-reload themselves when they expire.
 *                                         ( void * ) x_core0,        // Assign each timer a unique id equal to its array index.
 *                                         vTimerCallback       // Each timer calls the same callback when it expires.
 *                                     );
 *
 *         if( xTimers[ x_core0 ] == NULL )
 *         {
 *             // The timer was not created.
 *         }
 *         else
 *         {
 *             // Start the timer.  No block time is specified, and even if one was
 *             // it would be ignored because the scheduler has not yet been
 *             // started.
 *             if( xTimerStart_core0( xTimers[ x_core0 ], 0 ) != pdPASS_core0 )
 *             {
 *                 // The timer could not be set into the Active state.
 *             }
 *         }
 *     }
 *
 *     // ...
 *     // Create tasks here.
 *     // ...
 *
 *     // Starting the scheduler will start the timers_core0 running as they have already
 *     // been set into the active state.
 *     vTaskStartScheduler_core0();
 *
 *     // Should not reach here.
 *     for( ;; );
 * }
 * @endverbatim
 */
#if ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 )
    TimerHandle_t_core0 xTimerCreate_core0( const char * const pcTimerName_core0, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                const TickType_t_core0 xTimerPeriodInTicks_core0,
                                const BaseType_t_core0 xAutoReload_core0,
                                void * const pvTimerID_core0,
                                TimerCallbackFunction_t_core0 pxCallbackFunction_core0 ) PRIVILEGED_FUNCTION_core0;
#endif

/**
 * TimerHandle_t_core0 xTimerCreateStatic_core0(const char * const pcTimerName_core0,
 *                                  TickType_t_core0 xTimerPeriodInTicks_core0,
 *                                  BaseType_t_core0 xAutoReload_core0,
 *                                  void * pvTimerID_core0,
 *                                  TimerCallbackFunction_t_core0 pxCallbackFunction_core0,
 *                                  StaticTimer_t_core0 *pxTimerBuffer_core0 );
 *
 * Creates a new software timer instance, and returns a handle by which the
 * created software timer can be referenced.
 *
 * Internally, within the FreeRTOS_core0 implementation, software timers_core0 use a block
 * of memory, in which the timer data structure is stored.  If a software timer
 * is created using xTimerCreate_core0() then the required memory is automatically
 * dynamically allocated inside the xTimerCreate_core0() function.  (see
 * https://www.FreeRTOS_core0.org/a00111.html).  If a software timer is created using
 * xTimerCreateStatic_core0() then the application writer must provide the memory that
 * will get used by the software timer.  xTimerCreateStatic_core0() therefore allows a
 * software timer to be created without using any dynamic memory allocation.
 *
 * Timers are created in the dormant state.  The xTimerStart_core0(), xTimerReset_core0(),
 * xTimerStartFromISR_core0(), xTimerResetFromISR_core0(), xTimerChangePeriod_core0() and
 * xTimerChangePeriodFromISR_core0() API functions can all be used to transition a
 * timer into the active state.
 *
 * @param pcTimerName_core0 A text name that is assigned to the timer.  This is done
 * purely to assist debugging.  The kernel itself only ever references a timer
 * by its handle, and never by its name.
 *
 * @param xTimerPeriodInTicks_core0 The timer period.  The time is defined in tick
 * periods so the constant portTICK_PERIOD_MS_core0 can be used to convert a time that
 * has been specified in milliseconds.  For example, if the timer must expire
 * after 100 ticks, then xTimerPeriodInTicks_core0 should be set to 100.
 * Alternatively, if the timer must expire after 500ms, then xPeriod can be set
 * to ( 500 / portTICK_PERIOD_MS_core0 ) provided configTICK_RATE_HZ_core0 is less than or
 * equal to 1000.  The timer period must be greater than 0.
 *
 * @param xAutoReload_core0 If xAutoReload_core0 is set to pdTRUE_core0 then the timer will
 * expire repeatedly with a frequency set by the xTimerPeriodInTicks_core0 parameter.
 * If xAutoReload_core0 is set to pdFALSE_core0 then the timer will be a one-shot timer and
 * enter the dormant state after it expires.
 *
 * @param pvTimerID_core0 An identifier that is assigned to the timer being created.
 * Typically this would be used in the timer callback function to identify which
 * timer expired when the same callback function is assigned to more than one
 * timer.
 *
 * @param pxCallbackFunction_core0 The function to call when the timer expires.
 * Callback functions must have the prototype defined by TimerCallbackFunction_t_core0,
 * which is "void vCallbackFunction( TimerHandle_t_core0 xTimer_core0 );".
 *
 * @param pxTimerBuffer_core0 Must point to a variable of type StaticTimer_t_core0, which
 * will be then be used to hold the software timer's data structures, removing
 * the need for the memory to be allocated dynamically.
 *
 * @return If the timer is created then a handle to the created timer is
 * returned.  If pxTimerBuffer_core0 was NULL then NULL is returned.
 *
 * Example usage:
 * @verbatim
 *
 * // The buffer used to hold the software timer's data structure.
 * static StaticTimer_t_core0 xTimerBuffer;
 *
 * // A variable that will be incremented by the software timer's callback
 * // function.
 * UBaseType_t_core0 uxVariableToIncrement = 0;
 *
 * // A software timer callback function that increments a variable passed to
 * // it when the software timer was created.  After the 5th increment the
 * // callback function stops the software timer.
 * static void prvTimerCallback( TimerHandle_t_core0 xExpiredTimer )
 * {
 * UBaseType_t_core0 *puxVariableToIncrement;
 * BaseType_t_core0 xReturned;
 *
 *     // Obtain the address of the variable to increment from the timer ID.
 *     puxVariableToIncrement = ( UBaseType_t_core0 * ) pvTimerGetTimerID_core0( xExpiredTimer );
 *
 *     // Increment the variable to show the timer callback has executed.
 *     ( *puxVariableToIncrement )++;
 *
 *     // If this callback has executed the required number of times, stop the
 *     // timer.
 *     if( *puxVariableToIncrement == 5 )
 *     {
 *         // This is called from a timer callback so must not block.
 *         xTimerStop_core0( xExpiredTimer, staticDONT_BLOCK );
 *     }
 * }
 *
 *
 * void main( void )
 * {
 *     // Create the software time.  xTimerCreateStatic_core0() has an extra parameter
 *     // than the normal xTimerCreate_core0() API function.  The parameter is a pointer
 *     // to the StaticTimer_t_core0 structure that will hold the software timer
 *     // structure.  If the parameter is passed as NULL then the structure will be
 *     // allocated dynamically, just as if xTimerCreate_core0() had been called.
 *     xTimer_core0 = xTimerCreateStatic_core0( "T1",             // Text name for the task_core0.  Helps debugging only.  Not used by FreeRTOS_core0.
 *                                  xTimerPeriod,     // The period of the timer in ticks.
 *                                  pdTRUE_core0,           // This is an auto-reload timer.
 *                                  ( void * ) &uxVariableToIncrement,    // A variable incremented by the software timer's callback function
 *                                  prvTimerCallback, // The function to execute when the timer expires.
 *                                  &xTimerBuffer );  // The buffer that will hold the software timer structure.
 *
 *     // The scheduler has not started yet so a block time is not used.
 *     xReturned = xTimerStart_core0( xTimer_core0, 0 );
 *
 *     // ...
 *     // Create tasks here.
 *     // ...
 *
 *     // Starting the scheduler will start the timers_core0 running as they have already
 *     // been set into the active state.
 *     vTaskStartScheduler_core0();
 *
 *     // Should not reach here.
 *     for( ;; );
 * }
 * @endverbatim
 */
#if ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 )
    TimerHandle_t_core0 xTimerCreateStatic_core0( const char * const pcTimerName_core0, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                      const TickType_t_core0 xTimerPeriodInTicks_core0,
                                      const BaseType_t_core0 xAutoReload_core0,
                                      void * const pvTimerID_core0,
                                      TimerCallbackFunction_t_core0 pxCallbackFunction_core0,
                                      StaticTimer_t_core0 * pxTimerBuffer_core0 ) PRIVILEGED_FUNCTION_core0;
#endif /* configSUPPORT_STATIC_ALLOCATION_core0 */

/**
 * void *pvTimerGetTimerID_core0( TimerHandle_t_core0 xTimer_core0 );
 *
 * Returns the ID assigned to the timer.
 *
 * IDs are assigned to timers_core0 using the pvTimerID_core0 parameter of the call to
 * xTimerCreated() that was used to create the timer, and by calling the
 * vTimerSetTimerID_core0() API function.
 *
 * If the same callback function is assigned to multiple timers_core0 then the timer
 * ID can be used as time specific (timer local) storage.
 *
 * @param xTimer_core0 The timer being queried.
 *
 * @return The ID assigned to the timer being queried.
 *
 * Example usage:
 *
 * See the xTimerCreate_core0() API function example usage scenario.
 */
void * pvTimerGetTimerID_core0( const TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * void vTimerSetTimerID_core0( TimerHandle_t_core0 xTimer_core0, void *pvNewID_core0 );
 *
 * Sets the ID assigned to the timer.
 *
 * IDs are assigned to timers_core0 using the pvTimerID_core0 parameter of the call to
 * xTimerCreated() that was used to create the timer.
 *
 * If the same callback function is assigned to multiple timers_core0 then the timer
 * ID can be used as time specific (timer local) storage.
 *
 * @param xTimer_core0 The timer being updated.
 *
 * @param pvNewID_core0 The ID to assign to the timer.
 *
 * Example usage:
 *
 * See the xTimerCreate_core0() API function example usage scenario.
 */
void vTimerSetTimerID_core0( TimerHandle_t_core0 xTimer_core0,
                       void * pvNewID_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * BaseType_t_core0 xTimerIsTimerActive_core0( TimerHandle_t_core0 xTimer_core0 );
 *
 * Queries a timer to see if it is active or dormant.
 *
 * A timer will be dormant if:
 *     1) It has been created but not started, or
 *     2) It is an expired one-shot timer that has not been restarted.
 *
 * Timers are created in the dormant state.  The xTimerStart_core0(), xTimerReset_core0(),
 * xTimerStartFromISR_core0(), xTimerResetFromISR_core0(), xTimerChangePeriod_core0() and
 * xTimerChangePeriodFromISR_core0() API functions can all be used to transition a timer into the
 * active state.
 *
 * @param xTimer_core0 The timer being queried.
 *
 * @return pdFALSE_core0 will be returned if the timer is dormant.  A value other than
 * pdFALSE_core0 will be returned if the timer is active.
 *
 * Example usage:
 * @verbatim
 * // This function assumes xTimer_core0 has already been created.
 * void vAFunction( TimerHandle_t_core0 xTimer_core0 )
 * {
 *     if( xTimerIsTimerActive_core0( xTimer_core0 ) != pdFALSE_core0 ) // or more simply and equivalently "if( xTimerIsTimerActive_core0( xTimer_core0 ) )"
 *     {
 *         // xTimer_core0 is active, do something.
 *     }
 *     else
 *     {
 *         // xTimer_core0 is not active, do something else.
 *     }
 * }
 * @endverbatim
 */
BaseType_t_core0 xTimerIsTimerActive_core0( TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * TaskHandle_t_core0 xTimerGetTimerDaemonTaskHandle_core0( void );
 *
 * Simply returns the handle of the timer service/daemon task_core0.  It it not valid
 * to call xTimerGetTimerDaemonTaskHandle_core0() before the scheduler has been started.
 */
TaskHandle_t_core0 xTimerGetTimerDaemonTaskHandle_core0( void ) PRIVILEGED_FUNCTION_core0;

/**
 * BaseType_t_core0 xTimerStart_core0( TimerHandle_t_core0 xTimer_core0, TickType_t_core0 xTicksToWait_core0 );
 *
 * Timer functionality is provided by a timer service/daemon task_core0.  Many of the
 * public FreeRTOS_core0 timer API functions send commands to the timer service task_core0
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core0 configuration constant.
 *
 * xTimerStart_core0() starts a timer that was previously created using the
 * xTimerCreate_core0() API function.  If the timer had already been started and was
 * already in the active state, then xTimerStart_core0() has equivalent functionality
 * to the xTimerReset_core0() API function.
 *
 * Starting a timer ensures the timer is in the active state.  If the timer
 * is not stopped, deleted, or reset in the mean time, the callback function
 * associated with the timer will get called 'n' ticks after xTimerStart_core0() was
 * called, where 'n' is the timers_core0 defined period.
 *
 * It is valid to call xTimerStart_core0() before the scheduler has been started, but
 * when this is done the timer will not actually start until the scheduler is
 * started, and the timers_core0 expiry time will be relative to when the scheduler is
 * started, not relative to when xTimerStart_core0() was called.
 *
 * The configUSE_TIMERS_core0 configuration constant must be set to 1 for xTimerStart_core0()
 * to be available.
 *
 * @param xTimer_core0 The handle of the timer being started/restarted.
 *
 * @param xTicksToWait_core0 Specifies the time, in ticks, that the calling task_core0 should
 * be held in the Blocked state to wait for the start command to be successfully
 * sent to the timer command queue, should the queue already be full when
 * xTimerStart_core0() was called.  xTicksToWait_core0 is ignored if xTimerStart_core0() is called
 * before the scheduler is started.
 *
 * @return pdFAIL_core0 will be returned if the start command could not be sent to
 * the timer command queue even after xTicksToWait_core0 ticks had passed.  pdPASS_core0 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core0 relative to other tasks in the system, although the
 * timers_core0 expiry time is relative to when xTimerStart_core0() is actually called.  The
 * timer service/daemon task_core0 priority is set by the configTIMER_TASK_PRIORITY_core0
 * configuration constant.
 *
 * Example usage:
 *
 * See the xTimerCreate_core0() API function example usage scenario.
 *
 */
#define xTimerStart_core0( xTimer_core0, xTicksToWait_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_START_core0, ( xTaskGetTickCount_core0() ), NULL, ( xTicksToWait_core0 ) )

/**
 * BaseType_t_core0 xTimerStop_core0( TimerHandle_t_core0 xTimer_core0, TickType_t_core0 xTicksToWait_core0 );
 *
 * Timer functionality is provided by a timer service/daemon task_core0.  Many of the
 * public FreeRTOS_core0 timer API functions send commands to the timer service task_core0
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core0 configuration constant.
 *
 * xTimerStop_core0() stops a timer that was previously started using either of the
 * The xTimerStart_core0(), xTimerReset_core0(), xTimerStartFromISR_core0(), xTimerResetFromISR_core0(),
 * xTimerChangePeriod_core0() or xTimerChangePeriodFromISR_core0() API functions.
 *
 * Stopping a timer ensures the timer is not in the active state.
 *
 * The configUSE_TIMERS_core0 configuration constant must be set to 1 for xTimerStop_core0()
 * to be available.
 *
 * @param xTimer_core0 The handle of the timer being stopped.
 *
 * @param xTicksToWait_core0 Specifies the time, in ticks, that the calling task_core0 should
 * be held in the Blocked state to wait for the stop command to be successfully
 * sent to the timer command queue, should the queue already be full when
 * xTimerStop_core0() was called.  xTicksToWait_core0 is ignored if xTimerStop_core0() is called
 * before the scheduler is started.
 *
 * @return pdFAIL_core0 will be returned if the stop command could not be sent to
 * the timer command queue even after xTicksToWait_core0 ticks had passed.  pdPASS_core0 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core0 relative to other tasks in the system.  The timer
 * service/daemon task_core0 priority is set by the configTIMER_TASK_PRIORITY_core0
 * configuration constant.
 *
 * Example usage:
 *
 * See the xTimerCreate_core0() API function example usage scenario.
 *
 */
#define xTimerStop_core0( xTimer_core0, xTicksToWait_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_STOP_core0, 0U, NULL, ( xTicksToWait_core0 ) )

/**
 * BaseType_t_core0 xTimerChangePeriod_core0(   TimerHandle_t_core0 xTimer_core0,
 *                                  TickType_t_core0 xNewPeriod_core0,
 *                                  TickType_t_core0 xTicksToWait_core0 );
 *
 * Timer functionality is provided by a timer service/daemon task_core0.  Many of the
 * public FreeRTOS_core0 timer API functions send commands to the timer service task_core0
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core0 configuration constant.
 *
 * xTimerChangePeriod_core0() changes the period of a timer that was previously
 * created using the xTimerCreate_core0() API function.
 *
 * xTimerChangePeriod_core0() can be called to change the period of an active or
 * dormant state timer.
 *
 * The configUSE_TIMERS_core0 configuration constant must be set to 1 for
 * xTimerChangePeriod_core0() to be available.
 *
 * @param xTimer_core0 The handle of the timer that is having its period changed.
 *
 * @param xNewPeriod_core0 The new period for xTimer_core0. Timer periods are specified in
 * tick periods, so the constant portTICK_PERIOD_MS_core0 can be used to convert a time
 * that has been specified in milliseconds.  For example, if the timer must
 * expire after 100 ticks, then xNewPeriod_core0 should be set to 100.  Alternatively,
 * if the timer must expire after 500ms, then xNewPeriod_core0 can be set to
 * ( 500 / portTICK_PERIOD_MS_core0 ) provided configTICK_RATE_HZ_core0 is less than
 * or equal to 1000.
 *
 * @param xTicksToWait_core0 Specifies the time, in ticks, that the calling task_core0 should
 * be held in the Blocked state to wait for the change period command to be
 * successfully sent to the timer command queue, should the queue already be
 * full when xTimerChangePeriod_core0() was called.  xTicksToWait_core0 is ignored if
 * xTimerChangePeriod_core0() is called before the scheduler is started.
 *
 * @return pdFAIL_core0 will be returned if the change period command could not be
 * sent to the timer command queue even after xTicksToWait_core0 ticks had passed.
 * pdPASS_core0 will be returned if the command was successfully sent to the timer
 * command queue.  When the command is actually processed will depend on the
 * priority of the timer service/daemon task_core0 relative to other tasks in the
 * system.  The timer service/daemon task_core0 priority is set by the
 * configTIMER_TASK_PRIORITY_core0 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This function assumes xTimer_core0 has already been created.  If the timer
 * // referenced by xTimer_core0 is already active when it is called, then the timer
 * // is deleted.  If the timer referenced by xTimer_core0 is not active when it is
 * // called, then the period of the timer is set to 500ms and the timer is
 * // started.
 * void vAFunction( TimerHandle_t_core0 xTimer_core0 )
 * {
 *     if( xTimerIsTimerActive_core0( xTimer_core0 ) != pdFALSE_core0 ) // or more simply and equivalently "if( xTimerIsTimerActive_core0( xTimer_core0 ) )"
 *     {
 *         // xTimer_core0 is already active - delete it.
 *         xTimerDelete_core0( xTimer_core0 );
 *     }
 *     else
 *     {
 *         // xTimer_core0 is not active, change its period to 500ms.  This will also
 *         // cause the timer to start.  Block for a maximum of 100 ticks if the
 *         // change period command cannot immediately be sent to the timer
 *         // command queue.
 *         if( xTimerChangePeriod_core0( xTimer_core0, 500 / portTICK_PERIOD_MS_core0, 100 ) == pdPASS_core0 )
 *         {
 *             // The command was successfully sent.
 *         }
 *         else
 *         {
 *             // The command could not be sent, even after waiting for 100 ticks
 *             // to pass.  Take appropriate action here.
 *         }
 *     }
 * }
 * @endverbatim
 */
#define xTimerChangePeriod_core0( xTimer_core0, xNewPeriod_core0, xTicksToWait_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_CHANGE_PERIOD_core0, ( xNewPeriod_core0 ), NULL, ( xTicksToWait_core0 ) )

/**
 * BaseType_t_core0 xTimerDelete_core0( TimerHandle_t_core0 xTimer_core0, TickType_t_core0 xTicksToWait_core0 );
 *
 * Timer functionality is provided by a timer service/daemon task_core0.  Many of the
 * public FreeRTOS_core0 timer API functions send commands to the timer service task_core0
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core0 configuration constant.
 *
 * xTimerDelete_core0() deletes a timer that was previously created using the
 * xTimerCreate_core0() API function.
 *
 * The configUSE_TIMERS_core0 configuration constant must be set to 1 for
 * xTimerDelete_core0() to be available.
 *
 * @param xTimer_core0 The handle of the timer being deleted.
 *
 * @param xTicksToWait_core0 Specifies the time, in ticks, that the calling task_core0 should
 * be held in the Blocked state to wait for the delete command to be
 * successfully sent to the timer command queue, should the queue already be
 * full when xTimerDelete_core0() was called.  xTicksToWait_core0 is ignored if xTimerDelete_core0()
 * is called before the scheduler is started.
 *
 * @return pdFAIL_core0 will be returned if the delete command could not be sent to
 * the timer command queue even after xTicksToWait_core0 ticks had passed.  pdPASS_core0 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core0 relative to other tasks in the system.  The timer
 * service/daemon task_core0 priority is set by the configTIMER_TASK_PRIORITY_core0
 * configuration constant.
 *
 * Example usage:
 *
 * See the xTimerChangePeriod_core0() API function example usage scenario.
 */
#define xTimerDelete_core0( xTimer_core0, xTicksToWait_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_DELETE_core0, 0U, NULL, ( xTicksToWait_core0 ) )

/**
 * BaseType_t_core0 xTimerReset_core0( TimerHandle_t_core0 xTimer_core0, TickType_t_core0 xTicksToWait_core0 );
 *
 * Timer functionality is provided by a timer service/daemon task_core0.  Many of the
 * public FreeRTOS_core0 timer API functions send commands to the timer service task_core0
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core0 configuration constant.
 *
 * xTimerReset_core0() re-starts a timer that was previously created using the
 * xTimerCreate_core0() API function.  If the timer had already been started and was
 * already in the active state, then xTimerReset_core0() will cause the timer to
 * re-evaluate its expiry time so that it is relative to when xTimerReset_core0() was
 * called.  If the timer was in the dormant state then xTimerReset_core0() has
 * equivalent functionality to the xTimerStart_core0() API function.
 *
 * Resetting a timer ensures the timer is in the active state.  If the timer
 * is not stopped, deleted, or reset in the mean time, the callback function
 * associated with the timer will get called 'n' ticks after xTimerReset_core0() was
 * called, where 'n' is the timers_core0 defined period.
 *
 * It is valid to call xTimerReset_core0() before the scheduler has been started, but
 * when this is done the timer will not actually start until the scheduler is
 * started, and the timers_core0 expiry time will be relative to when the scheduler is
 * started, not relative to when xTimerReset_core0() was called.
 *
 * The configUSE_TIMERS_core0 configuration constant must be set to 1 for xTimerReset_core0()
 * to be available.
 *
 * @param xTimer_core0 The handle of the timer being reset/started/restarted.
 *
 * @param xTicksToWait_core0 Specifies the time, in ticks, that the calling task_core0 should
 * be held in the Blocked state to wait for the reset command to be successfully
 * sent to the timer command queue, should the queue already be full when
 * xTimerReset_core0() was called.  xTicksToWait_core0 is ignored if xTimerReset_core0() is called
 * before the scheduler is started.
 *
 * @return pdFAIL_core0 will be returned if the reset command could not be sent to
 * the timer command queue even after xTicksToWait_core0 ticks had passed.  pdPASS_core0 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core0 relative to other tasks in the system, although the
 * timers_core0 expiry time is relative to when xTimerStart_core0() is actually called.  The
 * timer service/daemon task_core0 priority is set by the configTIMER_TASK_PRIORITY_core0
 * configuration constant.
 *
 * Example usage:
 * @verbatim
 * // When a key is pressed, an LCD back-light is switched on.  If 5 seconds pass
 * // without a key being pressed, then the LCD back-light is switched off.  In
 * // this case, the timer is a one-shot timer.
 *
 * TimerHandle_t_core0 xBacklightTimer = NULL;
 *
 * // The callback function assigned to the one-shot timer.  In this case the
 * // parameter is not used.
 * void vBacklightTimerCallback( TimerHandle_t_core0 pxTimer_core0 )
 * {
 *     // The timer expired, therefore 5 seconds must have passed since a key
 *     // was pressed.  Switch off the LCD back-light.
 *     vSetBacklightState( BACKLIGHT_OFF );
 * }
 *
 * // The key press event handler.
 * void vKeyPressEventHandler( char cKey )
 * {
 *     // Ensure the LCD back-light is on, then reset the timer that is
 *     // responsible for turning the back-light off after 5 seconds of
 *     // key inactivity.  Wait 10 ticks for the command to be successfully sent
 *     // if it cannot be sent immediately.
 *     vSetBacklightState( BACKLIGHT_ON );
 *     if( xTimerReset_core0( xBacklightTimer, 100 ) != pdPASS_core0 )
 *     {
 *         // The reset command was not executed successfully.  Take appropriate
 *         // action here.
 *     }
 *
 *     // Perform the rest of the key processing here.
 * }
 *
 * void main( void )
 * {
 * int32_t x_core0;
 *
 *     // Create then start the one-shot timer that is responsible for turning
 *     // the back-light off if no keys are pressed within a 5 second period.
 *     xBacklightTimer = xTimerCreate_core0( "BacklightTimer",           // Just a text name, not used by the kernel.
 *                                     ( 5000 / portTICK_PERIOD_MS_core0), // The timer period in ticks.
 *                                     pdFALSE_core0,                    // The timer is a one-shot timer.
 *                                     0,                          // The id is not used by the callback so can take any value.
 *                                     vBacklightTimerCallback     // The callback function that switches the LCD back-light off.
 *                                   );
 *
 *     if( xBacklightTimer == NULL )
 *     {
 *         // The timer was not created.
 *     }
 *     else
 *     {
 *         // Start the timer.  No block time is specified, and even if one was
 *         // it would be ignored because the scheduler has not yet been
 *         // started.
 *         if( xTimerStart_core0( xBacklightTimer, 0 ) != pdPASS_core0 )
 *         {
 *             // The timer could not be set into the Active state.
 *         }
 *     }
 *
 *     // ...
 *     // Create tasks here.
 *     // ...
 *
 *     // Starting the scheduler will start the timer running as it has already
 *     // been set into the active state.
 *     vTaskStartScheduler_core0();
 *
 *     // Should not reach here.
 *     for( ;; );
 * }
 * @endverbatim
 */
#define xTimerReset_core0( xTimer_core0, xTicksToWait_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_RESET_core0, ( xTaskGetTickCount_core0() ), NULL, ( xTicksToWait_core0 ) )

/**
 * BaseType_t_core0 xTimerStartFromISR_core0(   TimerHandle_t_core0 xTimer_core0,
 *                                  BaseType_t_core0 *pxHigherPriorityTaskWoken_core0 );
 *
 * A version of xTimerStart_core0() that can be called from an interrupt service
 * routine.
 *
 * @param xTimer_core0 The handle of the timer being started/restarted.
 *
 * @param pxHigherPriorityTaskWoken_core0 The timer service/daemon task_core0 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerStartFromISR_core0() writes a message to the timer
 * command queue, so has the potential to transition the timer service/daemon
 * task_core0 out of the Blocked state.  If calling xTimerStartFromISR_core0() causes the
 * timer service/daemon task_core0 to leave the Blocked state, and the timer service/
 * daemon task_core0 has a priority equal to or greater than the currently executing
 * task_core0 (the task_core0 that was interrupted), then *pxHigherPriorityTaskWoken_core0 will
 * get set to pdTRUE_core0 internally within the xTimerStartFromISR_core0() function.  If
 * xTimerStartFromISR_core0() sets this value to pdTRUE_core0 then a context switch should
 * be performed before the interrupt exits.
 *
 * @return pdFAIL_core0 will be returned if the start command could not be sent to
 * the timer command queue.  pdPASS_core0 will be returned if the command was
 * successfully sent to the timer command queue.  When the command is actually
 * processed will depend on the priority of the timer service/daemon task_core0
 * relative to other tasks in the system, although the timers_core0 expiry time is
 * relative to when xTimerStartFromISR_core0() is actually called.  The timer
 * service/daemon task_core0 priority is set by the configTIMER_TASK_PRIORITY_core0
 * configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xBacklightTimer has already been created.  When a
 * // key is pressed, an LCD back-light is switched on.  If 5 seconds pass
 * // without a key being pressed, then the LCD back-light is switched off.  In
 * // this case, the timer is a one-shot timer, and unlike the example given for
 * // the xTimerReset_core0() function, the key press event handler is an interrupt
 * // service routine.
 *
 * // The callback function assigned to the one-shot timer.  In this case the
 * // parameter is not used.
 * void vBacklightTimerCallback( TimerHandle_t_core0 pxTimer_core0 )
 * {
 *     // The timer expired, therefore 5 seconds must have passed since a key
 *     // was pressed.  Switch off the LCD back-light.
 *     vSetBacklightState( BACKLIGHT_OFF );
 * }
 *
 * // The key press interrupt service routine.
 * void vKeyPressEventInterruptHandler( void )
 * {
 * BaseType_t_core0 xHigherPriorityTaskWoken_core0 = pdFALSE_core0;
 *
 *     // Ensure the LCD back-light is on, then restart the timer that is
 *     // responsible for turning the back-light off after 5 seconds of
 *     // key inactivity.  This is an interrupt service routine so can only
 *     // call FreeRTOS_core0 API functions that end in "FromISR".
 *     vSetBacklightState( BACKLIGHT_ON );
 *
 *     // xTimerStartFromISR_core0() or xTimerResetFromISR_core0() could be called here
 *     // as both cause the timer to re-calculate its expiry time.
 *     // xHigherPriorityTaskWoken_core0 was initialised to pdFALSE_core0 when it was
 *     // declared (in this function).
 *     if( xTimerStartFromISR_core0( xBacklightTimer, &xHigherPriorityTaskWoken_core0 ) != pdPASS_core0 )
 *     {
 *         // The start command was not executed successfully.  Take appropriate
 *         // action here.
 *     }
 *
 *     // Perform the rest of the key processing here.
 *
 *     // If xHigherPriorityTaskWoken_core0 equals pdTRUE_core0, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core0 != pdFALSE_core0 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core0 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerStartFromISR_core0( xTimer_core0, pxHigherPriorityTaskWoken_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_START_FROM_ISR_core0, ( xTaskGetTickCountFromISR_core0() ), ( pxHigherPriorityTaskWoken_core0 ), 0U )

/**
 * BaseType_t_core0 xTimerStopFromISR_core0(    TimerHandle_t_core0 xTimer_core0,
 *                                  BaseType_t_core0 *pxHigherPriorityTaskWoken_core0 );
 *
 * A version of xTimerStop_core0() that can be called from an interrupt service
 * routine.
 *
 * @param xTimer_core0 The handle of the timer being stopped.
 *
 * @param pxHigherPriorityTaskWoken_core0 The timer service/daemon task_core0 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerStopFromISR_core0() writes a message to the timer
 * command queue, so has the potential to transition the timer service/daemon
 * task_core0 out of the Blocked state.  If calling xTimerStopFromISR_core0() causes the
 * timer service/daemon task_core0 to leave the Blocked state, and the timer service/
 * daemon task_core0 has a priority equal to or greater than the currently executing
 * task_core0 (the task_core0 that was interrupted), then *pxHigherPriorityTaskWoken_core0 will
 * get set to pdTRUE_core0 internally within the xTimerStopFromISR_core0() function.  If
 * xTimerStopFromISR_core0() sets this value to pdTRUE_core0 then a context switch should
 * be performed before the interrupt exits.
 *
 * @return pdFAIL_core0 will be returned if the stop command could not be sent to
 * the timer command queue.  pdPASS_core0 will be returned if the command was
 * successfully sent to the timer command queue.  When the command is actually
 * processed will depend on the priority of the timer service/daemon task_core0
 * relative to other tasks in the system.  The timer service/daemon task_core0
 * priority is set by the configTIMER_TASK_PRIORITY_core0 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xTimer_core0 has already been created and started.  When
 * // an interrupt occurs, the timer should be simply stopped.
 *
 * // The interrupt service routine that stops the timer.
 * void vAnExampleInterruptServiceRoutine( void )
 * {
 * BaseType_t_core0 xHigherPriorityTaskWoken_core0 = pdFALSE_core0;
 *
 *     // The interrupt has occurred - simply stop the timer.
 *     // xHigherPriorityTaskWoken_core0 was set to pdFALSE_core0 where it was defined
 *     // (within this function).  As this is an interrupt service routine, only
 *     // FreeRTOS_core0 API functions that end in "FromISR" can be used.
 *     if( xTimerStopFromISR_core0( xTimer_core0, &xHigherPriorityTaskWoken_core0 ) != pdPASS_core0 )
 *     {
 *         // The stop command was not executed successfully.  Take appropriate
 *         // action here.
 *     }
 *
 *     // If xHigherPriorityTaskWoken_core0 equals pdTRUE_core0, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core0 != pdFALSE_core0 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core0 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerStopFromISR_core0( xTimer_core0, pxHigherPriorityTaskWoken_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_STOP_FROM_ISR_core0, 0, ( pxHigherPriorityTaskWoken_core0 ), 0U )

/**
 * BaseType_t_core0 xTimerChangePeriodFromISR_core0( TimerHandle_t_core0 xTimer_core0,
 *                                       TickType_t_core0 xNewPeriod_core0,
 *                                       BaseType_t_core0 *pxHigherPriorityTaskWoken_core0 );
 *
 * A version of xTimerChangePeriod_core0() that can be called from an interrupt
 * service routine.
 *
 * @param xTimer_core0 The handle of the timer that is having its period changed.
 *
 * @param xNewPeriod_core0 The new period for xTimer_core0. Timer periods are specified in
 * tick periods, so the constant portTICK_PERIOD_MS_core0 can be used to convert a time
 * that has been specified in milliseconds.  For example, if the timer must
 * expire after 100 ticks, then xNewPeriod_core0 should be set to 100.  Alternatively,
 * if the timer must expire after 500ms, then xNewPeriod_core0 can be set to
 * ( 500 / portTICK_PERIOD_MS_core0 ) provided configTICK_RATE_HZ_core0 is less than
 * or equal to 1000.
 *
 * @param pxHigherPriorityTaskWoken_core0 The timer service/daemon task_core0 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerChangePeriodFromISR_core0() writes a message to the
 * timer command queue, so has the potential to transition the timer service/
 * daemon task_core0 out of the Blocked state.  If calling xTimerChangePeriodFromISR_core0()
 * causes the timer service/daemon task_core0 to leave the Blocked state, and the
 * timer service/daemon task_core0 has a priority equal to or greater than the
 * currently executing task_core0 (the task_core0 that was interrupted), then
 * *pxHigherPriorityTaskWoken_core0 will get set to pdTRUE_core0 internally within the
 * xTimerChangePeriodFromISR_core0() function.  If xTimerChangePeriodFromISR_core0() sets
 * this value to pdTRUE_core0 then a context switch should be performed before the
 * interrupt exits.
 *
 * @return pdFAIL_core0 will be returned if the command to change the timers_core0 period
 * could not be sent to the timer command queue.  pdPASS_core0 will be returned if the
 * command was successfully sent to the timer command queue.  When the command
 * is actually processed will depend on the priority of the timer service/daemon
 * task_core0 relative to other tasks in the system.  The timer service/daemon task_core0
 * priority is set by the configTIMER_TASK_PRIORITY_core0 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xTimer_core0 has already been created and started.  When
 * // an interrupt occurs, the period of xTimer_core0 should be changed to 500ms.
 *
 * // The interrupt service routine that changes the period of xTimer_core0.
 * void vAnExampleInterruptServiceRoutine( void )
 * {
 * BaseType_t_core0 xHigherPriorityTaskWoken_core0 = pdFALSE_core0;
 *
 *     // The interrupt has occurred - change the period of xTimer_core0 to 500ms.
 *     // xHigherPriorityTaskWoken_core0 was set to pdFALSE_core0 where it was defined
 *     // (within this function).  As this is an interrupt service routine, only
 *     // FreeRTOS_core0 API functions that end in "FromISR" can be used.
 *     if( xTimerChangePeriodFromISR_core0( xTimer_core0, &xHigherPriorityTaskWoken_core0 ) != pdPASS_core0 )
 *     {
 *         // The command to change the timers_core0 period was not executed
 *         // successfully.  Take appropriate action here.
 *     }
 *
 *     // If xHigherPriorityTaskWoken_core0 equals pdTRUE_core0, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core0 != pdFALSE_core0 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core0 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerChangePeriodFromISR_core0( xTimer_core0, xNewPeriod_core0, pxHigherPriorityTaskWoken_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_CHANGE_PERIOD_FROM_ISR_core0, ( xNewPeriod_core0 ), ( pxHigherPriorityTaskWoken_core0 ), 0U )

/**
 * BaseType_t_core0 xTimerResetFromISR_core0(   TimerHandle_t_core0 xTimer_core0,
 *                                  BaseType_t_core0 *pxHigherPriorityTaskWoken_core0 );
 *
 * A version of xTimerReset_core0() that can be called from an interrupt service
 * routine.
 *
 * @param xTimer_core0 The handle of the timer that is to be started, reset, or
 * restarted.
 *
 * @param pxHigherPriorityTaskWoken_core0 The timer service/daemon task_core0 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerResetFromISR_core0() writes a message to the timer
 * command queue, so has the potential to transition the timer service/daemon
 * task_core0 out of the Blocked state.  If calling xTimerResetFromISR_core0() causes the
 * timer service/daemon task_core0 to leave the Blocked state, and the timer service/
 * daemon task_core0 has a priority equal to or greater than the currently executing
 * task_core0 (the task_core0 that was interrupted), then *pxHigherPriorityTaskWoken_core0 will
 * get set to pdTRUE_core0 internally within the xTimerResetFromISR_core0() function.  If
 * xTimerResetFromISR_core0() sets this value to pdTRUE_core0 then a context switch should
 * be performed before the interrupt exits.
 *
 * @return pdFAIL_core0 will be returned if the reset command could not be sent to
 * the timer command queue.  pdPASS_core0 will be returned if the command was
 * successfully sent to the timer command queue.  When the command is actually
 * processed will depend on the priority of the timer service/daemon task_core0
 * relative to other tasks in the system, although the timers_core0 expiry time is
 * relative to when xTimerResetFromISR_core0() is actually called.  The timer service/daemon
 * task_core0 priority is set by the configTIMER_TASK_PRIORITY_core0 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xBacklightTimer has already been created.  When a
 * // key is pressed, an LCD back-light is switched on.  If 5 seconds pass
 * // without a key being pressed, then the LCD back-light is switched off.  In
 * // this case, the timer is a one-shot timer, and unlike the example given for
 * // the xTimerReset_core0() function, the key press event handler is an interrupt
 * // service routine.
 *
 * // The callback function assigned to the one-shot timer.  In this case the
 * // parameter is not used.
 * void vBacklightTimerCallback( TimerHandle_t_core0 pxTimer_core0 )
 * {
 *     // The timer expired, therefore 5 seconds must have passed since a key
 *     // was pressed.  Switch off the LCD back-light.
 *     vSetBacklightState( BACKLIGHT_OFF );
 * }
 *
 * // The key press interrupt service routine.
 * void vKeyPressEventInterruptHandler( void )
 * {
 * BaseType_t_core0 xHigherPriorityTaskWoken_core0 = pdFALSE_core0;
 *
 *     // Ensure the LCD back-light is on, then reset the timer that is
 *     // responsible for turning the back-light off after 5 seconds of
 *     // key inactivity.  This is an interrupt service routine so can only
 *     // call FreeRTOS_core0 API functions that end in "FromISR".
 *     vSetBacklightState( BACKLIGHT_ON );
 *
 *     // xTimerStartFromISR_core0() or xTimerResetFromISR_core0() could be called here
 *     // as both cause the timer to re-calculate its expiry time.
 *     // xHigherPriorityTaskWoken_core0 was initialised to pdFALSE_core0 when it was
 *     // declared (in this function).
 *     if( xTimerResetFromISR_core0( xBacklightTimer, &xHigherPriorityTaskWoken_core0 ) != pdPASS_core0 )
 *     {
 *         // The reset command was not executed successfully.  Take appropriate
 *         // action here.
 *     }
 *
 *     // Perform the rest of the key processing here.
 *
 *     // If xHigherPriorityTaskWoken_core0 equals pdTRUE_core0, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core0 != pdFALSE_core0 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core0 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerResetFromISR_core0( xTimer_core0, pxHigherPriorityTaskWoken_core0 ) \
    xTimerGenericCommand_core0( ( xTimer_core0 ), tmrCOMMAND_RESET_FROM_ISR_core0, ( xTaskGetTickCountFromISR_core0() ), ( pxHigherPriorityTaskWoken_core0 ), 0U )


/**
 * BaseType_t_core0 xTimerPendFunctionCallFromISR_core0( PendedFunction_t_core0 xFunctionToPend_core0,
 *                                          void *pvParameter1_core0,
 *                                          uint32_t ulParameter2_core0,
 *                                          BaseType_t_core0 *pxHigherPriorityTaskWoken_core0 );
 *
 *
 * Used from application interrupt service routines to defer the execution of a
 * function to the RTOS daemon task_core0 (the timer service task_core0, hence this function
 * is implemented in timers_core0.c and is prefixed with 'Timer').
 *
 * Ideally an interrupt service routine (ISR) is kept as short as possible, but
 * sometimes an ISR either has a lot of processing to do, or needs to perform
 * processing that is not deterministic.  In these cases
 * xTimerPendFunctionCallFromISR_core0() can be used to defer processing of a function
 * to the RTOS daemon task_core0.
 *
 * A mechanism is provided that allows the interrupt to return directly to the
 * task_core0 that will subsequently execute the pended callback function.  This
 * allows the callback function to execute contiguously in time with the
 * interrupt - just as if the callback had executed in the interrupt itself.
 *
 * @param xFunctionToPend_core0 The function to execute from the timer service/
 * daemon task_core0.  The function must conform to the PendedFunction_t_core0
 * prototype.
 *
 * @param pvParameter1_core0 The value of the callback function's first parameter.
 * The parameter has a void * type to allow it to be used to pass any type.
 * For example, unsigned longs can be cast to a void *, or the void * can be
 * used to point to a structure.
 *
 * @param ulParameter2_core0 The value of the callback function's second parameter.
 *
 * @param pxHigherPriorityTaskWoken_core0 As mentioned above, calling this function
 * will result in a message being sent to the timer daemon task_core0.  If the
 * priority of the timer daemon task_core0 (which is set using
 * configTIMER_TASK_PRIORITY_core0 in FreeRTOSConfig.h) is higher than the priority of
 * the currently running task_core0 (the task_core0 the interrupt interrupted) then
 * *pxHigherPriorityTaskWoken_core0 will be set to pdTRUE_core0 within
 * xTimerPendFunctionCallFromISR_core0(), indicating that a context switch should be
 * requested before the interrupt exits.  For that reason
 * *pxHigherPriorityTaskWoken_core0 must be initialised to pdFALSE_core0.  See the
 * example code below.
 *
 * @return pdPASS_core0 is returned if the message was successfully sent to the
 * timer daemon task_core0, otherwise pdFALSE_core0 is returned.
 *
 * Example usage:
 * @verbatim
 *
 *  // The callback function that will execute in the context of the daemon task_core0.
 *  // Note callback functions must all use this same prototype.
 *  void vProcessInterface( void *pvParameter1_core0, uint32_t ulParameter2_core0 )
 *  {
 *      BaseType_t_core0 xInterfaceToService;
 *
 *      // The interface that requires servicing is passed in the second
 *      // parameter.  The first parameter is not used in this case.
 *      xInterfaceToService = ( BaseType_t_core0 ) ulParameter2_core0;
 *
 *      // ...Perform the processing here...
 *  }
 *
 *  // An ISR that receives data packets from multiple interfaces
 *  void vAnISR( void )
 *  {
 *      BaseType_t_core0 xInterfaceToService, xHigherPriorityTaskWoken_core0;
 *
 *      // Query the hardware to determine which interface needs processing.
 *      xInterfaceToService = prvCheckInterfaces();
 *
 *      // The actual processing is to be deferred to a task_core0.  Request the
 *      // vProcessInterface() callback function is executed, passing in the
 *      // number of the interface that needs processing.  The interface to
 *      // service is passed in the second parameter.  The first parameter is
 *      // not used in this case.
 *      xHigherPriorityTaskWoken_core0 = pdFALSE_core0;
 *      xTimerPendFunctionCallFromISR_core0( vProcessInterface, NULL, ( uint32_t ) xInterfaceToService, &xHigherPriorityTaskWoken_core0 );
 *
 *      // If xHigherPriorityTaskWoken_core0 is now set to pdTRUE_core0 then a context
 *      // switch should be requested.  The macro used is port specific and will
 *      // be either portYIELD_FROM_ISR_core0() or portEND_SWITCHING_ISR() - refer to
 *      // the documentation page for the port being used.
 *      portYIELD_FROM_ISR_core0( xHigherPriorityTaskWoken_core0 );
 *
 *  }
 * @endverbatim
 */
BaseType_t_core0 xTimerPendFunctionCallFromISR_core0( PendedFunction_t_core0 xFunctionToPend_core0,
                                          void * pvParameter1_core0,
                                          uint32_t ulParameter2_core0,
                                          BaseType_t_core0 * pxHigherPriorityTaskWoken_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * BaseType_t_core0 xTimerPendFunctionCall_core0( PendedFunction_t_core0 xFunctionToPend_core0,
 *                                    void *pvParameter1_core0,
 *                                    uint32_t ulParameter2_core0,
 *                                    TickType_t_core0 xTicksToWait_core0 );
 *
 *
 * Used to defer the execution of a function to the RTOS daemon task_core0 (the timer
 * service task_core0, hence this function is implemented in timers_core0.c and is prefixed
 * with 'Timer').
 *
 * @param xFunctionToPend_core0 The function to execute from the timer service/
 * daemon task_core0.  The function must conform to the PendedFunction_t_core0
 * prototype.
 *
 * @param pvParameter1_core0 The value of the callback function's first parameter.
 * The parameter has a void * type to allow it to be used to pass any type.
 * For example, unsigned longs can be cast to a void *, or the void * can be
 * used to point to a structure.
 *
 * @param ulParameter2_core0 The value of the callback function's second parameter.
 *
 * @param xTicksToWait_core0 Calling this function will result in a message being
 * sent to the timer daemon task_core0 on a queue.  xTicksToWait_core0 is the amount of
 * time the calling task_core0 should remain in the Blocked state (so not using any
 * processing time) for space to become available on the timer queue if the
 * queue is found to be full.
 *
 * @return pdPASS_core0 is returned if the message was successfully sent to the
 * timer daemon task_core0, otherwise pdFALSE_core0 is returned.
 *
 */
BaseType_t_core0 xTimerPendFunctionCall_core0( PendedFunction_t_core0 xFunctionToPend_core0,
                                   void * pvParameter1_core0,
                                   uint32_t ulParameter2_core0,
                                   TickType_t_core0 xTicksToWait_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * const char * const pcTimerGetName_core0( TimerHandle_t_core0 xTimer_core0 );
 *
 * Returns the name that was assigned to a timer when the timer was created.
 *
 * @param xTimer_core0 The handle of the timer being queried.
 *
 * @return The name assigned to the timer specified by the xTimer_core0 parameter.
 */
const char * pcTimerGetName_core0( TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */

/**
 * void vTimerSetReloadMode_core0( TimerHandle_t_core0 xTimer_core0, const BaseType_t_core0 xAutoReload_core0 );
 *
 * Updates a timer to be either an auto-reload timer, in which case the timer
 * automatically resets itself each time it expires, or a one-shot timer, in
 * which case the timer will only expire once unless it is manually restarted.
 *
 * @param xTimer_core0 The handle of the timer being updated.
 *
 * @param xAutoReload_core0 If xAutoReload_core0 is set to pdTRUE_core0 then the timer will
 * expire repeatedly with a frequency set by the timer's period (see the
 * xTimerPeriodInTicks_core0 parameter of the xTimerCreate_core0() API function).  If
 * xAutoReload_core0 is set to pdFALSE_core0 then the timer will be a one-shot timer and
 * enter the dormant state after it expires.
 */
void vTimerSetReloadMode_core0( TimerHandle_t_core0 xTimer_core0,
                          const BaseType_t_core0 xAutoReload_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * BaseType_t_core0 xTimerGetReloadMode_core0( TimerHandle_t_core0 xTimer_core0 );
 *
 * Queries a timer to determine if it is an auto-reload timer, in which case the timer
 * automatically resets itself each time it expires, or a one-shot timer, in
 * which case the timer will only expire once unless it is manually restarted.
 *
 * @param xTimer_core0 The handle of the timer being queried.
 *
 * @return If the timer is an auto-reload timer then pdTRUE_core0 is returned, otherwise
 * pdFALSE_core0 is returned.
 */
BaseType_t_core0 xTimerGetReloadMode_core0( TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * UBaseType_t_core0 uxTimerGetReloadMode_core0( TimerHandle_t_core0 xTimer_core0 );
 *
 * Queries a timer to determine if it is an auto-reload timer, in which case the timer
 * automatically resets itself each time it expires, or a one-shot timer, in
 * which case the timer will only expire once unless it is manually restarted.
 *
 * @param xTimer_core0 The handle of the timer being queried.
 *
 * @return If the timer is an auto-reload timer then pdTRUE_core0 is returned, otherwise
 * pdFALSE_core0 is returned.
 */
UBaseType_t_core0 uxTimerGetReloadMode_core0( TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * TickType_t_core0 xTimerGetPeriod_core0( TimerHandle_t_core0 xTimer_core0 );
 *
 * Returns the period of a timer.
 *
 * @param xTimer_core0 The handle of the timer being queried.
 *
 * @return The period of the timer in ticks.
 */
TickType_t_core0 xTimerGetPeriod_core0( TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0;

/**
 * TickType_t_core0 xTimerGetExpiryTime_core0( TimerHandle_t_core0 xTimer_core0 );
 *
 * Returns the time in ticks at which the timer will expire.  If this is less
 * than the current tick count then the expiry time has overflowed from the
 * current time.
 *
 * @param xTimer_core0 The handle of the timer being queried.
 *
 * @return If the timer is running then the time in ticks at which the timer
 * will next expire is returned.  If the timer is not running then the return
 * value is undefined.
 */
TickType_t_core0 xTimerGetExpiryTime_core0( TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0;

/*
 * Functions beyond this part are not part of the public API and are intended
 * for use by the kernel only.
 */
BaseType_t_core0 xTimerCreateTimerTask_core0( void ) PRIVILEGED_FUNCTION_core0;
BaseType_t_core0 xTimerGenericCommand_core0( TimerHandle_t_core0 xTimer_core0,
                                 const BaseType_t_core0 xCommandID_core0,
                                 const TickType_t_core0 xOptionalValue_core0,
                                 BaseType_t_core0 * const pxHigherPriorityTaskWoken_core0,
                                 const TickType_t_core0 xTicksToWait_core0 ) PRIVILEGED_FUNCTION_core0;

#if ( configUSE_TRACE_FACILITY_core0 == 1 )
    void vTimerSetTimerNumber_core0( TimerHandle_t_core0 xTimer_core0,
                               UBaseType_t_core0 uxTimerNumber_core0 ) PRIVILEGED_FUNCTION_core0;
    UBaseType_t_core0 uxTimerGetTimerNumber_core0( TimerHandle_t_core0 xTimer_core0 ) PRIVILEGED_FUNCTION_core0;
#endif

#if ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 )

/**
 * task_core0.h
 * @code{c}
 * void vApplicationGetTimerTaskMemory_core0( StaticTask_t_core0 ** ppxTimerTaskTCBBuffer_core0, StackType_t_core0 ** ppxTimerTaskStackBuffer_core0, uint32_t *pulTimerTaskStackSize_core0 )
 * @endcode
 *
 * This function is used to provide a statically allocated block of memory to FreeRTOS_core0 to hold the Timer Task TCB.  This function is required when
 * configSUPPORT_STATIC_ALLOCATION_core0 is set.  For more information see this URI: https://www.FreeRTOS_core0.org/a00110.html#configSUPPORT_STATIC_ALLOCATION_core0
 *
 * @param ppxTimerTaskTCBBuffer_core0   A handle to a statically allocated TCB buffer
 * @param ppxTimerTaskStackBuffer_core0 A handle to a statically allocated Stack buffer for the idle task_core0
 * @param pulTimerTaskStackSize_core0   A pointer to the number of elements that will fit in the allocated stack buffer
 */
    void vApplicationGetTimerTaskMemory_core0( StaticTask_t_core0 ** ppxTimerTaskTCBBuffer_core0,
                                         StackType_t_core0 ** ppxTimerTaskStackBuffer_core0,
                                         uint32_t * pulTimerTaskStackSize_core0 );

#endif

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */
#endif /* TIMERS_H */
