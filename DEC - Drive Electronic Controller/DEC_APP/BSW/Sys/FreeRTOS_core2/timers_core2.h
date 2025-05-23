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

//
#ifndef TIMERS_CORE2_H
#define TIMERS_CORE2_H

#ifndef INC_FREERTOS_CORE2_H
    #error "include FreeRTOS_core2.h must appear in source files before include timers_core2.h"
#endif

/*lint -save -e537 This headers are only multiply included if the application code
 * happens to also be including task_core2.h. */
#include "task_core2.h"
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
 * highest numbers as tmrFIRST_FROM_ISR_COMMAND_core2 is used to determine if the task_core2
 * or interrupt version of the queue send function should be used. */
#define tmrCOMMAND_EXECUTE_CALLBACK_FROM_ISR_core2    ( ( BaseType_t_core2 ) -2 )
#define tmrCOMMAND_EXECUTE_CALLBACK_core2             ( ( BaseType_t_core2 ) -1 )
#define tmrCOMMAND_START_DONT_TRACE_core2             ( ( BaseType_t_core2 ) 0 )
#define tmrCOMMAND_START_core2                        ( ( BaseType_t_core2 ) 1 )
#define tmrCOMMAND_RESET_core2                        ( ( BaseType_t_core2 ) 2 )
#define tmrCOMMAND_STOP_core2                         ( ( BaseType_t_core2 ) 3 )
#define tmrCOMMAND_CHANGE_PERIOD_core2                ( ( BaseType_t_core2 ) 4 )
#define tmrCOMMAND_DELETE_core2                       ( ( BaseType_t_core2 ) 5 )

#define tmrFIRST_FROM_ISR_COMMAND_core2               ( ( BaseType_t_core2 ) 6 )
#define tmrCOMMAND_START_FROM_ISR_core2               ( ( BaseType_t_core2 ) 6 )
#define tmrCOMMAND_RESET_FROM_ISR_core2               ( ( BaseType_t_core2 ) 7 )
#define tmrCOMMAND_STOP_FROM_ISR_core2                ( ( BaseType_t_core2 ) 8 )
#define tmrCOMMAND_CHANGE_PERIOD_FROM_ISR_core2       ( ( BaseType_t_core2 ) 9 )


/**
 * Type by which software timers_core2 are referenced.  For example, a call to
 * xTimerCreate_core2() returns an TimerHandle_t_core2 variable that can then be used to
 * reference the subject timer in calls to other software timer API functions
 * (for example, xTimerStart_core2(), xTimerReset_core2(), etc.).
 */
struct tmrTimerControl_core2; /* The old naming convention is used to prevent breaking kernel aware debuggers. */
typedef struct tmrTimerControl_core2 * TimerHandle_t_core2;

/*
 * Defines the prototype to which timer callback functions must conform.
 */
typedef void (* TimerCallbackFunction_t_core2)( TimerHandle_t_core2 xTimer_core2 );

/*
 * Defines the prototype to which functions used with the
 * xTimerPendFunctionCallFromISR_core2() function must conform.
 */
typedef void (* PendedFunction_t_core2)( void *,
                                   uint32_t );

/**
 * TimerHandle_t_core2 xTimerCreate_core2(  const char * const pcTimerName_core2,
 *                              TickType_t_core2 xTimerPeriodInTicks_core2,
 *                              BaseType_t_core2 xAutoReload_core2,
 *                              void * pvTimerID_core2,
 *                              TimerCallbackFunction_t_core2 pxCallbackFunction_core2 );
 *
 * Creates a new software timer instance, and returns a handle by which the
 * created software timer can be referenced.
 *
 * Internally, within the FreeRTOS_core2 implementation, software timers_core2 use a block
 * of memory, in which the timer data structure is stored.  If a software timer
 * is created using xTimerCreate_core2() then the required memory is automatically
 * dynamically allocated inside the xTimerCreate_core2() function.  (see
 * https://www.FreeRTOS_core2.org/a00111.html).  If a software timer is created using
 * xTimerCreateStatic_core2() then the application writer must provide the memory that
 * will get used by the software timer.  xTimerCreateStatic_core2() therefore allows a
 * software timer to be created without using any dynamic memory allocation.
 *
 * Timers are created in the dormant state.  The xTimerStart_core2(), xTimerReset_core2(),
 * xTimerStartFromISR_core2(), xTimerResetFromISR_core2(), xTimerChangePeriod_core2() and
 * xTimerChangePeriodFromISR_core2() API functions can all be used to transition a
 * timer into the active state.
 *
 * @param pcTimerName_core2 A text name that is assigned to the timer.  This is done
 * purely to assist debugging.  The kernel itself only ever references a timer
 * by its handle, and never by its name.
 *
 * @param xTimerPeriodInTicks_core2 The timer period.  The time is defined in tick
 * periods so the constant portTICK_PERIOD_MS_core2 can be used to convert a time that
 * has been specified in milliseconds.  For example, if the timer must expire
 * after 100 ticks, then xTimerPeriodInTicks_core2 should be set to 100.
 * Alternatively, if the timer must expire after 500ms, then xPeriod can be set
 * to ( 500 / portTICK_PERIOD_MS_core2 ) provided configTICK_RATE_HZ_core2 is less than or
 * equal to 1000.  Time timer period must be greater than 0.
 *
 * @param xAutoReload_core2 If xAutoReload_core2 is set to pdTRUE_core2 then the timer will
 * expire repeatedly with a frequency set by the xTimerPeriodInTicks_core2 parameter.
 * If xAutoReload_core2 is set to pdFALSE_core2 then the timer will be a one-shot timer and
 * enter the dormant state after it expires.
 *
 * @param pvTimerID_core2 An identifier that is assigned to the timer being created.
 * Typically this would be used in the timer callback function to identify which
 * timer expired when the same callback function is assigned to more than one
 * timer.
 *
 * @param pxCallbackFunction_core2 The function to call when the timer expires.
 * Callback functions must have the prototype defined by TimerCallbackFunction_t_core2,
 * which is "void vCallbackFunction( TimerHandle_t_core2 xTimer_core2 );".
 *
 * @return If the timer is successfully created then a handle to the newly
 * created timer is returned.  If the timer cannot be created because there is
 * insufficient FreeRTOS_core2 heap remaining to allocate the timer
 * structures then NULL is returned.
 *
 * Example usage:
 * @verbatim
 * #define NUM_TIMERS 5
 *
 * // An array to hold handles to the created timers_core2.
 * TimerHandle_t_core2 xTimers[ NUM_TIMERS ];
 *
 * // An array to hold a count of the number of times each timer expires.
 * int32_t lExpireCounters[ NUM_TIMERS ] = { 0 };
 *
 * // Define a callback function that will be used by multiple timer instances.
 * // The callback function does nothing but count the number of times the
 * // associated timer expires, and stop the timer once the timer has expired
 * // 10 times.
 * void vTimerCallback( TimerHandle_t_core2 pxTimer_core2 )
 * {
 * int32_t lArrayIndex;
 * const int32_t xMaxExpiryCountBeforeStopping = 10;
 *
 *     // Optionally do something if the pxTimer_core2 parameter is NULL.
 *     configASSERT_core2( pxTimer_core2 );
 *
 *     // Which timer expired?
 *     lArrayIndex = ( int32_t ) pvTimerGetTimerID_core2( pxTimer_core2 );
 *
 *     // Increment the number of times that pxTimer_core2 has expired.
 *     lExpireCounters[ lArrayIndex ] += 1;
 *
 *     // If the timer has expired 10 times then stop it from running.
 *     if( lExpireCounters[ lArrayIndex ] == xMaxExpiryCountBeforeStopping )
 *     {
 *         // Do not use a block time if calling a timer API function from a
 *         // timer callback function, as doing so could cause a deadlock!
 *         xTimerStop_core2( pxTimer_core2, 0 );
 *     }
 * }
 *
 * void main( void )
 * {
 * int32_t x_core2;
 *
 *     // Create then start some timers_core2.  Starting the timers_core2 before the scheduler
 *     // has been started means the timers_core2 will start running immediately that
 *     // the scheduler starts.
 *     for( x_core2 = 0; x_core2 < NUM_TIMERS; x_core2++ )
 *     {
 *         xTimers[ x_core2 ] = xTimerCreate_core2(    "Timer",             // Just a text name, not used by the kernel.
 *                                         ( 100 * ( x_core2 + 1 ) ), // The timer period in ticks.
 *                                         pdTRUE_core2,              // The timers_core2 will auto-reload themselves when they expire.
 *                                         ( void * ) x_core2,        // Assign each timer a unique id equal to its array index.
 *                                         vTimerCallback       // Each timer calls the same callback when it expires.
 *                                     );
 *
 *         if( xTimers[ x_core2 ] == NULL )
 *         {
 *             // The timer was not created.
 *         }
 *         else
 *         {
 *             // Start the timer.  No block time is specified, and even if one was
 *             // it would be ignored because the scheduler has not yet been
 *             // started.
 *             if( xTimerStart_core2( xTimers[ x_core2 ], 0 ) != pdPASS_core2 )
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
 *     // Starting the scheduler will start the timers_core2 running as they have already
 *     // been set into the active state.
 *     vTaskStartScheduler_core2();
 *
 *     // Should not reach here.
 *     for( ;; );
 * }
 * @endverbatim
 */
#if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 )
    TimerHandle_t_core2 xTimerCreate_core2( const char * const pcTimerName_core2, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                const TickType_t_core2 xTimerPeriodInTicks_core2,
                                const BaseType_t_core2 xAutoReload_core2,
                                void * const pvTimerID_core2,
                                TimerCallbackFunction_t_core2 pxCallbackFunction_core2 ) PRIVILEGED_FUNCTION_core2;
#endif

/**
 * TimerHandle_t_core2 xTimerCreateStatic_core2(const char * const pcTimerName_core2,
 *                                  TickType_t_core2 xTimerPeriodInTicks_core2,
 *                                  BaseType_t_core2 xAutoReload_core2,
 *                                  void * pvTimerID_core2,
 *                                  TimerCallbackFunction_t_core2 pxCallbackFunction_core2,
 *                                  StaticTimer_t_core2 *pxTimerBuffer_core2 );
 *
 * Creates a new software timer instance, and returns a handle by which the
 * created software timer can be referenced.
 *
 * Internally, within the FreeRTOS_core2 implementation, software timers_core2 use a block
 * of memory, in which the timer data structure is stored.  If a software timer
 * is created using xTimerCreate_core2() then the required memory is automatically
 * dynamically allocated inside the xTimerCreate_core2() function.  (see
 * https://www.FreeRTOS_core2.org/a00111.html).  If a software timer is created using
 * xTimerCreateStatic_core2() then the application writer must provide the memory that
 * will get used by the software timer.  xTimerCreateStatic_core2() therefore allows a
 * software timer to be created without using any dynamic memory allocation.
 *
 * Timers are created in the dormant state.  The xTimerStart_core2(), xTimerReset_core2(),
 * xTimerStartFromISR_core2(), xTimerResetFromISR_core2(), xTimerChangePeriod_core2() and
 * xTimerChangePeriodFromISR_core2() API functions can all be used to transition a
 * timer into the active state.
 *
 * @param pcTimerName_core2 A text name that is assigned to the timer.  This is done
 * purely to assist debugging.  The kernel itself only ever references a timer
 * by its handle, and never by its name.
 *
 * @param xTimerPeriodInTicks_core2 The timer period.  The time is defined in tick
 * periods so the constant portTICK_PERIOD_MS_core2 can be used to convert a time that
 * has been specified in milliseconds.  For example, if the timer must expire
 * after 100 ticks, then xTimerPeriodInTicks_core2 should be set to 100.
 * Alternatively, if the timer must expire after 500ms, then xPeriod can be set
 * to ( 500 / portTICK_PERIOD_MS_core2 ) provided configTICK_RATE_HZ_core2 is less than or
 * equal to 1000.  The timer period must be greater than 0.
 *
 * @param xAutoReload_core2 If xAutoReload_core2 is set to pdTRUE_core2 then the timer will
 * expire repeatedly with a frequency set by the xTimerPeriodInTicks_core2 parameter.
 * If xAutoReload_core2 is set to pdFALSE_core2 then the timer will be a one-shot timer and
 * enter the dormant state after it expires.
 *
 * @param pvTimerID_core2 An identifier that is assigned to the timer being created.
 * Typically this would be used in the timer callback function to identify which
 * timer expired when the same callback function is assigned to more than one
 * timer.
 *
 * @param pxCallbackFunction_core2 The function to call when the timer expires.
 * Callback functions must have the prototype defined by TimerCallbackFunction_t_core2,
 * which is "void vCallbackFunction( TimerHandle_t_core2 xTimer_core2 );".
 *
 * @param pxTimerBuffer_core2 Must point to a variable of type StaticTimer_t_core2, which
 * will be then be used to hold the software timer's data structures, removing
 * the need for the memory to be allocated dynamically.
 *
 * @return If the timer is created then a handle to the created timer is
 * returned.  If pxTimerBuffer_core2 was NULL then NULL is returned.
 *
 * Example usage:
 * @verbatim
 *
 * // The buffer used to hold the software timer's data structure.
 * static StaticTimer_t_core2 xTimerBuffer;
 *
 * // A variable that will be incremented by the software timer's callback
 * // function.
 * UBaseType_t_core2 uxVariableToIncrement = 0;
 *
 * // A software timer callback function that increments a variable passed to
 * // it when the software timer was created.  After the 5th increment the
 * // callback function stops the software timer.
 * static void prvTimerCallback( TimerHandle_t_core2 xExpiredTimer )
 * {
 * UBaseType_t_core2 *puxVariableToIncrement;
 * BaseType_t_core2 xReturned;
 *
 *     // Obtain the address of the variable to increment from the timer ID.
 *     puxVariableToIncrement = ( UBaseType_t_core2 * ) pvTimerGetTimerID_core2( xExpiredTimer );
 *
 *     // Increment the variable to show the timer callback has executed.
 *     ( *puxVariableToIncrement )++;
 *
 *     // If this callback has executed the required number of times, stop the
 *     // timer.
 *     if( *puxVariableToIncrement == 5 )
 *     {
 *         // This is called from a timer callback so must not block.
 *         xTimerStop_core2( xExpiredTimer, staticDONT_BLOCK );
 *     }
 * }
 *
 *
 * void main( void )
 * {
 *     // Create the software time.  xTimerCreateStatic_core2() has an extra parameter
 *     // than the normal xTimerCreate_core2() API function.  The parameter is a pointer
 *     // to the StaticTimer_t_core2 structure that will hold the software timer
 *     // structure.  If the parameter is passed as NULL then the structure will be
 *     // allocated dynamically, just as if xTimerCreate_core2() had been called.
 *     xTimer_core2 = xTimerCreateStatic_core2( "T1",             // Text name for the task_core2.  Helps debugging only.  Not used by FreeRTOS_core2.
 *                                  xTimerPeriod,     // The period of the timer in ticks.
 *                                  pdTRUE_core2,           // This is an auto-reload timer.
 *                                  ( void * ) &uxVariableToIncrement,    // A variable incremented by the software timer's callback function
 *                                  prvTimerCallback, // The function to execute when the timer expires.
 *                                  &xTimerBuffer );  // The buffer that will hold the software timer structure.
 *
 *     // The scheduler has not started yet so a block time is not used.
 *     xReturned = xTimerStart_core2( xTimer_core2, 0 );
 *
 *     // ...
 *     // Create tasks here.
 *     // ...
 *
 *     // Starting the scheduler will start the timers_core2 running as they have already
 *     // been set into the active state.
 *     vTaskStartScheduler_core2();
 *
 *     // Should not reach here.
 *     for( ;; );
 * }
 * @endverbatim
 */
#if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )
    TimerHandle_t_core2 xTimerCreateStatic_core2( const char * const pcTimerName_core2, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                      const TickType_t_core2 xTimerPeriodInTicks_core2,
                                      const BaseType_t_core2 xAutoReload_core2,
                                      void * const pvTimerID_core2,
                                      TimerCallbackFunction_t_core2 pxCallbackFunction_core2,
                                      StaticTimer_t_core2 * pxTimerBuffer_core2 ) PRIVILEGED_FUNCTION_core2;
#endif /* configSUPPORT_STATIC_ALLOCATION_core2 */

/**
 * void *pvTimerGetTimerID_core2( TimerHandle_t_core2 xTimer_core2 );
 *
 * Returns the ID assigned to the timer.
 *
 * IDs are assigned to timers_core2 using the pvTimerID_core2 parameter of the call to
 * xTimerCreated() that was used to create the timer, and by calling the
 * vTimerSetTimerID_core2() API function.
 *
 * If the same callback function is assigned to multiple timers_core2 then the timer
 * ID can be used as time specific (timer local) storage.
 *
 * @param xTimer_core2 The timer being queried.
 *
 * @return The ID assigned to the timer being queried.
 *
 * Example usage:
 *
 * See the xTimerCreate_core2() API function example usage scenario.
 */
void * pvTimerGetTimerID_core2( const TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * void vTimerSetTimerID_core2( TimerHandle_t_core2 xTimer_core2, void *pvNewID_core2 );
 *
 * Sets the ID assigned to the timer.
 *
 * IDs are assigned to timers_core2 using the pvTimerID_core2 parameter of the call to
 * xTimerCreated() that was used to create the timer.
 *
 * If the same callback function is assigned to multiple timers_core2 then the timer
 * ID can be used as time specific (timer local) storage.
 *
 * @param xTimer_core2 The timer being updated.
 *
 * @param pvNewID_core2 The ID to assign to the timer.
 *
 * Example usage:
 *
 * See the xTimerCreate_core2() API function example usage scenario.
 */
void vTimerSetTimerID_core2( TimerHandle_t_core2 xTimer_core2,
                       void * pvNewID_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * BaseType_t_core2 xTimerIsTimerActive_core2( TimerHandle_t_core2 xTimer_core2 );
 *
 * Queries a timer to see if it is active or dormant.
 *
 * A timer will be dormant if:
 *     1) It has been created but not started, or
 *     2) It is an expired one-shot timer that has not been restarted.
 *
 * Timers are created in the dormant state.  The xTimerStart_core2(), xTimerReset_core2(),
 * xTimerStartFromISR_core2(), xTimerResetFromISR_core2(), xTimerChangePeriod_core2() and
 * xTimerChangePeriodFromISR_core2() API functions can all be used to transition a timer into the
 * active state.
 *
 * @param xTimer_core2 The timer being queried.
 *
 * @return pdFALSE_core2 will be returned if the timer is dormant.  A value other than
 * pdFALSE_core2 will be returned if the timer is active.
 *
 * Example usage:
 * @verbatim
 * // This function assumes xTimer_core2 has already been created.
 * void vAFunction( TimerHandle_t_core2 xTimer_core2 )
 * {
 *     if( xTimerIsTimerActive_core2( xTimer_core2 ) != pdFALSE_core2 ) // or more simply and equivalently "if( xTimerIsTimerActive_core2( xTimer_core2 ) )"
 *     {
 *         // xTimer_core2 is active, do something.
 *     }
 *     else
 *     {
 *         // xTimer_core2 is not active, do something else.
 *     }
 * }
 * @endverbatim
 */
BaseType_t_core2 xTimerIsTimerActive_core2( TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * TaskHandle_t_core2 xTimerGetTimerDaemonTaskHandle_core2( void );
 *
 * Simply returns the handle of the timer service/daemon task_core2.  It it not valid
 * to call xTimerGetTimerDaemonTaskHandle_core2() before the scheduler has been started.
 */
TaskHandle_t_core2 xTimerGetTimerDaemonTaskHandle_core2( void ) PRIVILEGED_FUNCTION_core2;

/**
 * BaseType_t_core2 xTimerStart_core2( TimerHandle_t_core2 xTimer_core2, TickType_t_core2 xTicksToWait_core2 );
 *
 * Timer functionality is provided by a timer service/daemon task_core2.  Many of the
 * public FreeRTOS_core2 timer API functions send commands to the timer service task_core2
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core2 configuration constant.
 *
 * xTimerStart_core2() starts a timer that was previously created using the
 * xTimerCreate_core2() API function.  If the timer had already been started and was
 * already in the active state, then xTimerStart_core2() has equivalent functionality
 * to the xTimerReset_core2() API function.
 *
 * Starting a timer ensures the timer is in the active state.  If the timer
 * is not stopped, deleted, or reset in the mean time, the callback function
 * associated with the timer will get called 'n' ticks after xTimerStart_core2() was
 * called, where 'n' is the timers_core2 defined period.
 *
 * It is valid to call xTimerStart_core2() before the scheduler has been started, but
 * when this is done the timer will not actually start until the scheduler is
 * started, and the timers_core2 expiry time will be relative to when the scheduler is
 * started, not relative to when xTimerStart_core2() was called.
 *
 * The configUSE_TIMERS_core2 configuration constant must be set to 1 for xTimerStart_core2()
 * to be available.
 *
 * @param xTimer_core2 The handle of the timer being started/restarted.
 *
 * @param xTicksToWait_core2 Specifies the time, in ticks, that the calling task_core2 should
 * be held in the Blocked state to wait for the start command to be successfully
 * sent to the timer command queue, should the queue already be full when
 * xTimerStart_core2() was called.  xTicksToWait_core2 is ignored if xTimerStart_core2() is called
 * before the scheduler is started.
 *
 * @return pdFAIL_core2 will be returned if the start command could not be sent to
 * the timer command queue even after xTicksToWait_core2 ticks had passed.  pdPASS_core2 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core2 relative to other tasks in the system, although the
 * timers_core2 expiry time is relative to when xTimerStart_core2() is actually called.  The
 * timer service/daemon task_core2 priority is set by the configTIMER_TASK_PRIORITY_core2
 * configuration constant.
 *
 * Example usage:
 *
 * See the xTimerCreate_core2() API function example usage scenario.
 *
 */
#define xTimerStart_core2( xTimer_core2, xTicksToWait_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_START_core2, ( xTaskGetTickCount_core2() ), NULL, ( xTicksToWait_core2 ) )

/**
 * BaseType_t_core2 xTimerStop_core2( TimerHandle_t_core2 xTimer_core2, TickType_t_core2 xTicksToWait_core2 );
 *
 * Timer functionality is provided by a timer service/daemon task_core2.  Many of the
 * public FreeRTOS_core2 timer API functions send commands to the timer service task_core2
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core2 configuration constant.
 *
 * xTimerStop_core2() stops a timer that was previously started using either of the
 * The xTimerStart_core2(), xTimerReset_core2(), xTimerStartFromISR_core2(), xTimerResetFromISR_core2(),
 * xTimerChangePeriod_core2() or xTimerChangePeriodFromISR_core2() API functions.
 *
 * Stopping a timer ensures the timer is not in the active state.
 *
 * The configUSE_TIMERS_core2 configuration constant must be set to 1 for xTimerStop_core2()
 * to be available.
 *
 * @param xTimer_core2 The handle of the timer being stopped.
 *
 * @param xTicksToWait_core2 Specifies the time, in ticks, that the calling task_core2 should
 * be held in the Blocked state to wait for the stop command to be successfully
 * sent to the timer command queue, should the queue already be full when
 * xTimerStop_core2() was called.  xTicksToWait_core2 is ignored if xTimerStop_core2() is called
 * before the scheduler is started.
 *
 * @return pdFAIL_core2 will be returned if the stop command could not be sent to
 * the timer command queue even after xTicksToWait_core2 ticks had passed.  pdPASS_core2 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core2 relative to other tasks in the system.  The timer
 * service/daemon task_core2 priority is set by the configTIMER_TASK_PRIORITY_core2
 * configuration constant.
 *
 * Example usage:
 *
 * See the xTimerCreate_core2() API function example usage scenario.
 *
 */
#define xTimerStop_core2( xTimer_core2, xTicksToWait_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_STOP_core2, 0U, NULL, ( xTicksToWait_core2 ) )

/**
 * BaseType_t_core2 xTimerChangePeriod_core2(   TimerHandle_t_core2 xTimer_core2,
 *                                  TickType_t_core2 xNewPeriod_core2,
 *                                  TickType_t_core2 xTicksToWait_core2 );
 *
 * Timer functionality is provided by a timer service/daemon task_core2.  Many of the
 * public FreeRTOS_core2 timer API functions send commands to the timer service task_core2
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core2 configuration constant.
 *
 * xTimerChangePeriod_core2() changes the period of a timer that was previously
 * created using the xTimerCreate_core2() API function.
 *
 * xTimerChangePeriod_core2() can be called to change the period of an active or
 * dormant state timer.
 *
 * The configUSE_TIMERS_core2 configuration constant must be set to 1 for
 * xTimerChangePeriod_core2() to be available.
 *
 * @param xTimer_core2 The handle of the timer that is having its period changed.
 *
 * @param xNewPeriod_core2 The new period for xTimer_core2. Timer periods are specified in
 * tick periods, so the constant portTICK_PERIOD_MS_core2 can be used to convert a time
 * that has been specified in milliseconds.  For example, if the timer must
 * expire after 100 ticks, then xNewPeriod_core2 should be set to 100.  Alternatively,
 * if the timer must expire after 500ms, then xNewPeriod_core2 can be set to
 * ( 500 / portTICK_PERIOD_MS_core2 ) provided configTICK_RATE_HZ_core2 is less than
 * or equal to 1000.
 *
 * @param xTicksToWait_core2 Specifies the time, in ticks, that the calling task_core2 should
 * be held in the Blocked state to wait for the change period command to be
 * successfully sent to the timer command queue, should the queue already be
 * full when xTimerChangePeriod_core2() was called.  xTicksToWait_core2 is ignored if
 * xTimerChangePeriod_core2() is called before the scheduler is started.
 *
 * @return pdFAIL_core2 will be returned if the change period command could not be
 * sent to the timer command queue even after xTicksToWait_core2 ticks had passed.
 * pdPASS_core2 will be returned if the command was successfully sent to the timer
 * command queue.  When the command is actually processed will depend on the
 * priority of the timer service/daemon task_core2 relative to other tasks in the
 * system.  The timer service/daemon task_core2 priority is set by the
 * configTIMER_TASK_PRIORITY_core2 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This function assumes xTimer_core2 has already been created.  If the timer
 * // referenced by xTimer_core2 is already active when it is called, then the timer
 * // is deleted.  If the timer referenced by xTimer_core2 is not active when it is
 * // called, then the period of the timer is set to 500ms and the timer is
 * // started.
 * void vAFunction( TimerHandle_t_core2 xTimer_core2 )
 * {
 *     if( xTimerIsTimerActive_core2( xTimer_core2 ) != pdFALSE_core2 ) // or more simply and equivalently "if( xTimerIsTimerActive_core2( xTimer_core2 ) )"
 *     {
 *         // xTimer_core2 is already active - delete it.
 *         xTimerDelete_core2( xTimer_core2 );
 *     }
 *     else
 *     {
 *         // xTimer_core2 is not active, change its period to 500ms.  This will also
 *         // cause the timer to start.  Block for a maximum of 100 ticks if the
 *         // change period command cannot immediately be sent to the timer
 *         // command queue.
 *         if( xTimerChangePeriod_core2( xTimer_core2, 500 / portTICK_PERIOD_MS_core2, 100 ) == pdPASS_core2 )
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
#define xTimerChangePeriod_core2( xTimer_core2, xNewPeriod_core2, xTicksToWait_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_CHANGE_PERIOD_core2, ( xNewPeriod_core2 ), NULL, ( xTicksToWait_core2 ) )

/**
 * BaseType_t_core2 xTimerDelete_core2( TimerHandle_t_core2 xTimer_core2, TickType_t_core2 xTicksToWait_core2 );
 *
 * Timer functionality is provided by a timer service/daemon task_core2.  Many of the
 * public FreeRTOS_core2 timer API functions send commands to the timer service task_core2
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core2 configuration constant.
 *
 * xTimerDelete_core2() deletes a timer that was previously created using the
 * xTimerCreate_core2() API function.
 *
 * The configUSE_TIMERS_core2 configuration constant must be set to 1 for
 * xTimerDelete_core2() to be available.
 *
 * @param xTimer_core2 The handle of the timer being deleted.
 *
 * @param xTicksToWait_core2 Specifies the time, in ticks, that the calling task_core2 should
 * be held in the Blocked state to wait for the delete command to be
 * successfully sent to the timer command queue, should the queue already be
 * full when xTimerDelete_core2() was called.  xTicksToWait_core2 is ignored if xTimerDelete_core2()
 * is called before the scheduler is started.
 *
 * @return pdFAIL_core2 will be returned if the delete command could not be sent to
 * the timer command queue even after xTicksToWait_core2 ticks had passed.  pdPASS_core2 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core2 relative to other tasks in the system.  The timer
 * service/daemon task_core2 priority is set by the configTIMER_TASK_PRIORITY_core2
 * configuration constant.
 *
 * Example usage:
 *
 * See the xTimerChangePeriod_core2() API function example usage scenario.
 */
#define xTimerDelete_core2( xTimer_core2, xTicksToWait_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_DELETE_core2, 0U, NULL, ( xTicksToWait_core2 ) )

/**
 * BaseType_t_core2 xTimerReset_core2( TimerHandle_t_core2 xTimer_core2, TickType_t_core2 xTicksToWait_core2 );
 *
 * Timer functionality is provided by a timer service/daemon task_core2.  Many of the
 * public FreeRTOS_core2 timer API functions send commands to the timer service task_core2
 * through a queue called the timer command queue.  The timer command queue is
 * private to the kernel itself and is not directly accessible to application
 * code.  The length of the timer command queue is set by the
 * configTIMER_QUEUE_LENGTH_core2 configuration constant.
 *
 * xTimerReset_core2() re-starts a timer that was previously created using the
 * xTimerCreate_core2() API function.  If the timer had already been started and was
 * already in the active state, then xTimerReset_core2() will cause the timer to
 * re-evaluate its expiry time so that it is relative to when xTimerReset_core2() was
 * called.  If the timer was in the dormant state then xTimerReset_core2() has
 * equivalent functionality to the xTimerStart_core2() API function.
 *
 * Resetting a timer ensures the timer is in the active state.  If the timer
 * is not stopped, deleted, or reset in the mean time, the callback function
 * associated with the timer will get called 'n' ticks after xTimerReset_core2() was
 * called, where 'n' is the timers_core2 defined period.
 *
 * It is valid to call xTimerReset_core2() before the scheduler has been started, but
 * when this is done the timer will not actually start until the scheduler is
 * started, and the timers_core2 expiry time will be relative to when the scheduler is
 * started, not relative to when xTimerReset_core2() was called.
 *
 * The configUSE_TIMERS_core2 configuration constant must be set to 1 for xTimerReset_core2()
 * to be available.
 *
 * @param xTimer_core2 The handle of the timer being reset/started/restarted.
 *
 * @param xTicksToWait_core2 Specifies the time, in ticks, that the calling task_core2 should
 * be held in the Blocked state to wait for the reset command to be successfully
 * sent to the timer command queue, should the queue already be full when
 * xTimerReset_core2() was called.  xTicksToWait_core2 is ignored if xTimerReset_core2() is called
 * before the scheduler is started.
 *
 * @return pdFAIL_core2 will be returned if the reset command could not be sent to
 * the timer command queue even after xTicksToWait_core2 ticks had passed.  pdPASS_core2 will
 * be returned if the command was successfully sent to the timer command queue.
 * When the command is actually processed will depend on the priority of the
 * timer service/daemon task_core2 relative to other tasks in the system, although the
 * timers_core2 expiry time is relative to when xTimerStart_core2() is actually called.  The
 * timer service/daemon task_core2 priority is set by the configTIMER_TASK_PRIORITY_core2
 * configuration constant.
 *
 * Example usage:
 * @verbatim
 * // When a key is pressed, an LCD back-light is switched on.  If 5 seconds pass
 * // without a key being pressed, then the LCD back-light is switched off.  In
 * // this case, the timer is a one-shot timer.
 *
 * TimerHandle_t_core2 xBacklightTimer = NULL;
 *
 * // The callback function assigned to the one-shot timer.  In this case the
 * // parameter is not used.
 * void vBacklightTimerCallback( TimerHandle_t_core2 pxTimer_core2 )
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
 *     if( xTimerReset_core2( xBacklightTimer, 100 ) != pdPASS_core2 )
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
 * int32_t x_core2;
 *
 *     // Create then start the one-shot timer that is responsible for turning
 *     // the back-light off if no keys are pressed within a 5 second period.
 *     xBacklightTimer = xTimerCreate_core2( "BacklightTimer",           // Just a text name, not used by the kernel.
 *                                     ( 5000 / portTICK_PERIOD_MS_core2), // The timer period in ticks.
 *                                     pdFALSE_core2,                    // The timer is a one-shot timer.
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
 *         if( xTimerStart_core2( xBacklightTimer, 0 ) != pdPASS_core2 )
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
 *     vTaskStartScheduler_core2();
 *
 *     // Should not reach here.
 *     for( ;; );
 * }
 * @endverbatim
 */
#define xTimerReset_core2( xTimer_core2, xTicksToWait_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_RESET_core2, ( xTaskGetTickCount_core2() ), NULL, ( xTicksToWait_core2 ) )

/**
 * BaseType_t_core2 xTimerStartFromISR_core2(   TimerHandle_t_core2 xTimer_core2,
 *                                  BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 *
 * A version of xTimerStart_core2() that can be called from an interrupt service
 * routine.
 *
 * @param xTimer_core2 The handle of the timer being started/restarted.
 *
 * @param pxHigherPriorityTaskWoken_core2 The timer service/daemon task_core2 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerStartFromISR_core2() writes a message to the timer
 * command queue, so has the potential to transition the timer service/daemon
 * task_core2 out of the Blocked state.  If calling xTimerStartFromISR_core2() causes the
 * timer service/daemon task_core2 to leave the Blocked state, and the timer service/
 * daemon task_core2 has a priority equal to or greater than the currently executing
 * task_core2 (the task_core2 that was interrupted), then *pxHigherPriorityTaskWoken_core2 will
 * get set to pdTRUE_core2 internally within the xTimerStartFromISR_core2() function.  If
 * xTimerStartFromISR_core2() sets this value to pdTRUE_core2 then a context switch should
 * be performed before the interrupt exits.
 *
 * @return pdFAIL_core2 will be returned if the start command could not be sent to
 * the timer command queue.  pdPASS_core2 will be returned if the command was
 * successfully sent to the timer command queue.  When the command is actually
 * processed will depend on the priority of the timer service/daemon task_core2
 * relative to other tasks in the system, although the timers_core2 expiry time is
 * relative to when xTimerStartFromISR_core2() is actually called.  The timer
 * service/daemon task_core2 priority is set by the configTIMER_TASK_PRIORITY_core2
 * configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xBacklightTimer has already been created.  When a
 * // key is pressed, an LCD back-light is switched on.  If 5 seconds pass
 * // without a key being pressed, then the LCD back-light is switched off.  In
 * // this case, the timer is a one-shot timer, and unlike the example given for
 * // the xTimerReset_core2() function, the key press event handler is an interrupt
 * // service routine.
 *
 * // The callback function assigned to the one-shot timer.  In this case the
 * // parameter is not used.
 * void vBacklightTimerCallback( TimerHandle_t_core2 pxTimer_core2 )
 * {
 *     // The timer expired, therefore 5 seconds must have passed since a key
 *     // was pressed.  Switch off the LCD back-light.
 *     vSetBacklightState( BACKLIGHT_OFF );
 * }
 *
 * // The key press interrupt service routine.
 * void vKeyPressEventInterruptHandler( void )
 * {
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2;
 *
 *     // Ensure the LCD back-light is on, then restart the timer that is
 *     // responsible for turning the back-light off after 5 seconds of
 *     // key inactivity.  This is an interrupt service routine so can only
 *     // call FreeRTOS_core2 API functions that end in "FromISR".
 *     vSetBacklightState( BACKLIGHT_ON );
 *
 *     // xTimerStartFromISR_core2() or xTimerResetFromISR_core2() could be called here
 *     // as both cause the timer to re-calculate its expiry time.
 *     // xHigherPriorityTaskWoken_core2 was initialised to pdFALSE_core2 when it was
 *     // declared (in this function).
 *     if( xTimerStartFromISR_core2( xBacklightTimer, &xHigherPriorityTaskWoken_core2 ) != pdPASS_core2 )
 *     {
 *         // The start command was not executed successfully.  Take appropriate
 *         // action here.
 *     }
 *
 *     // Perform the rest of the key processing here.
 *
 *     // If xHigherPriorityTaskWoken_core2 equals pdTRUE_core2, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core2 != pdFALSE_core2 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core2 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerStartFromISR_core2( xTimer_core2, pxHigherPriorityTaskWoken_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_START_FROM_ISR_core2, ( xTaskGetTickCountFromISR_core2() ), ( pxHigherPriorityTaskWoken_core2 ), 0U )

/**
 * BaseType_t_core2 xTimerStopFromISR_core2(    TimerHandle_t_core2 xTimer_core2,
 *                                  BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 *
 * A version of xTimerStop_core2() that can be called from an interrupt service
 * routine.
 *
 * @param xTimer_core2 The handle of the timer being stopped.
 *
 * @param pxHigherPriorityTaskWoken_core2 The timer service/daemon task_core2 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerStopFromISR_core2() writes a message to the timer
 * command queue, so has the potential to transition the timer service/daemon
 * task_core2 out of the Blocked state.  If calling xTimerStopFromISR_core2() causes the
 * timer service/daemon task_core2 to leave the Blocked state, and the timer service/
 * daemon task_core2 has a priority equal to or greater than the currently executing
 * task_core2 (the task_core2 that was interrupted), then *pxHigherPriorityTaskWoken_core2 will
 * get set to pdTRUE_core2 internally within the xTimerStopFromISR_core2() function.  If
 * xTimerStopFromISR_core2() sets this value to pdTRUE_core2 then a context switch should
 * be performed before the interrupt exits.
 *
 * @return pdFAIL_core2 will be returned if the stop command could not be sent to
 * the timer command queue.  pdPASS_core2 will be returned if the command was
 * successfully sent to the timer command queue.  When the command is actually
 * processed will depend on the priority of the timer service/daemon task_core2
 * relative to other tasks in the system.  The timer service/daemon task_core2
 * priority is set by the configTIMER_TASK_PRIORITY_core2 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xTimer_core2 has already been created and started.  When
 * // an interrupt occurs, the timer should be simply stopped.
 *
 * // The interrupt service routine that stops the timer.
 * void vAnExampleInterruptServiceRoutine( void )
 * {
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2;
 *
 *     // The interrupt has occurred - simply stop the timer.
 *     // xHigherPriorityTaskWoken_core2 was set to pdFALSE_core2 where it was defined
 *     // (within this function).  As this is an interrupt service routine, only
 *     // FreeRTOS_core2 API functions that end in "FromISR" can be used.
 *     if( xTimerStopFromISR_core2( xTimer_core2, &xHigherPriorityTaskWoken_core2 ) != pdPASS_core2 )
 *     {
 *         // The stop command was not executed successfully.  Take appropriate
 *         // action here.
 *     }
 *
 *     // If xHigherPriorityTaskWoken_core2 equals pdTRUE_core2, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core2 != pdFALSE_core2 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core2 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerStopFromISR_core2( xTimer_core2, pxHigherPriorityTaskWoken_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_STOP_FROM_ISR_core2, 0, ( pxHigherPriorityTaskWoken_core2 ), 0U )

/**
 * BaseType_t_core2 xTimerChangePeriodFromISR_core2( TimerHandle_t_core2 xTimer_core2,
 *                                       TickType_t_core2 xNewPeriod_core2,
 *                                       BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 *
 * A version of xTimerChangePeriod_core2() that can be called from an interrupt
 * service routine.
 *
 * @param xTimer_core2 The handle of the timer that is having its period changed.
 *
 * @param xNewPeriod_core2 The new period for xTimer_core2. Timer periods are specified in
 * tick periods, so the constant portTICK_PERIOD_MS_core2 can be used to convert a time
 * that has been specified in milliseconds.  For example, if the timer must
 * expire after 100 ticks, then xNewPeriod_core2 should be set to 100.  Alternatively,
 * if the timer must expire after 500ms, then xNewPeriod_core2 can be set to
 * ( 500 / portTICK_PERIOD_MS_core2 ) provided configTICK_RATE_HZ_core2 is less than
 * or equal to 1000.
 *
 * @param pxHigherPriorityTaskWoken_core2 The timer service/daemon task_core2 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerChangePeriodFromISR_core2() writes a message to the
 * timer command queue, so has the potential to transition the timer service/
 * daemon task_core2 out of the Blocked state.  If calling xTimerChangePeriodFromISR_core2()
 * causes the timer service/daemon task_core2 to leave the Blocked state, and the
 * timer service/daemon task_core2 has a priority equal to or greater than the
 * currently executing task_core2 (the task_core2 that was interrupted), then
 * *pxHigherPriorityTaskWoken_core2 will get set to pdTRUE_core2 internally within the
 * xTimerChangePeriodFromISR_core2() function.  If xTimerChangePeriodFromISR_core2() sets
 * this value to pdTRUE_core2 then a context switch should be performed before the
 * interrupt exits.
 *
 * @return pdFAIL_core2 will be returned if the command to change the timers_core2 period
 * could not be sent to the timer command queue.  pdPASS_core2 will be returned if the
 * command was successfully sent to the timer command queue.  When the command
 * is actually processed will depend on the priority of the timer service/daemon
 * task_core2 relative to other tasks in the system.  The timer service/daemon task_core2
 * priority is set by the configTIMER_TASK_PRIORITY_core2 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xTimer_core2 has already been created and started.  When
 * // an interrupt occurs, the period of xTimer_core2 should be changed to 500ms.
 *
 * // The interrupt service routine that changes the period of xTimer_core2.
 * void vAnExampleInterruptServiceRoutine( void )
 * {
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2;
 *
 *     // The interrupt has occurred - change the period of xTimer_core2 to 500ms.
 *     // xHigherPriorityTaskWoken_core2 was set to pdFALSE_core2 where it was defined
 *     // (within this function).  As this is an interrupt service routine, only
 *     // FreeRTOS_core2 API functions that end in "FromISR" can be used.
 *     if( xTimerChangePeriodFromISR_core2( xTimer_core2, &xHigherPriorityTaskWoken_core2 ) != pdPASS_core2 )
 *     {
 *         // The command to change the timers_core2 period was not executed
 *         // successfully.  Take appropriate action here.
 *     }
 *
 *     // If xHigherPriorityTaskWoken_core2 equals pdTRUE_core2, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core2 != pdFALSE_core2 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core2 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerChangePeriodFromISR_core2( xTimer_core2, xNewPeriod_core2, pxHigherPriorityTaskWoken_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_CHANGE_PERIOD_FROM_ISR_core2, ( xNewPeriod_core2 ), ( pxHigherPriorityTaskWoken_core2 ), 0U )

/**
 * BaseType_t_core2 xTimerResetFromISR_core2(   TimerHandle_t_core2 xTimer_core2,
 *                                  BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 *
 * A version of xTimerReset_core2() that can be called from an interrupt service
 * routine.
 *
 * @param xTimer_core2 The handle of the timer that is to be started, reset, or
 * restarted.
 *
 * @param pxHigherPriorityTaskWoken_core2 The timer service/daemon task_core2 spends most
 * of its time in the Blocked state, waiting for messages to arrive on the timer
 * command queue.  Calling xTimerResetFromISR_core2() writes a message to the timer
 * command queue, so has the potential to transition the timer service/daemon
 * task_core2 out of the Blocked state.  If calling xTimerResetFromISR_core2() causes the
 * timer service/daemon task_core2 to leave the Blocked state, and the timer service/
 * daemon task_core2 has a priority equal to or greater than the currently executing
 * task_core2 (the task_core2 that was interrupted), then *pxHigherPriorityTaskWoken_core2 will
 * get set to pdTRUE_core2 internally within the xTimerResetFromISR_core2() function.  If
 * xTimerResetFromISR_core2() sets this value to pdTRUE_core2 then a context switch should
 * be performed before the interrupt exits.
 *
 * @return pdFAIL_core2 will be returned if the reset command could not be sent to
 * the timer command queue.  pdPASS_core2 will be returned if the command was
 * successfully sent to the timer command queue.  When the command is actually
 * processed will depend on the priority of the timer service/daemon task_core2
 * relative to other tasks in the system, although the timers_core2 expiry time is
 * relative to when xTimerResetFromISR_core2() is actually called.  The timer service/daemon
 * task_core2 priority is set by the configTIMER_TASK_PRIORITY_core2 configuration constant.
 *
 * Example usage:
 * @verbatim
 * // This scenario assumes xBacklightTimer has already been created.  When a
 * // key is pressed, an LCD back-light is switched on.  If 5 seconds pass
 * // without a key being pressed, then the LCD back-light is switched off.  In
 * // this case, the timer is a one-shot timer, and unlike the example given for
 * // the xTimerReset_core2() function, the key press event handler is an interrupt
 * // service routine.
 *
 * // The callback function assigned to the one-shot timer.  In this case the
 * // parameter is not used.
 * void vBacklightTimerCallback( TimerHandle_t_core2 pxTimer_core2 )
 * {
 *     // The timer expired, therefore 5 seconds must have passed since a key
 *     // was pressed.  Switch off the LCD back-light.
 *     vSetBacklightState( BACKLIGHT_OFF );
 * }
 *
 * // The key press interrupt service routine.
 * void vKeyPressEventInterruptHandler( void )
 * {
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2;
 *
 *     // Ensure the LCD back-light is on, then reset the timer that is
 *     // responsible for turning the back-light off after 5 seconds of
 *     // key inactivity.  This is an interrupt service routine so can only
 *     // call FreeRTOS_core2 API functions that end in "FromISR".
 *     vSetBacklightState( BACKLIGHT_ON );
 *
 *     // xTimerStartFromISR_core2() or xTimerResetFromISR_core2() could be called here
 *     // as both cause the timer to re-calculate its expiry time.
 *     // xHigherPriorityTaskWoken_core2 was initialised to pdFALSE_core2 when it was
 *     // declared (in this function).
 *     if( xTimerResetFromISR_core2( xBacklightTimer, &xHigherPriorityTaskWoken_core2 ) != pdPASS_core2 )
 *     {
 *         // The reset command was not executed successfully.  Take appropriate
 *         // action here.
 *     }
 *
 *     // Perform the rest of the key processing here.
 *
 *     // If xHigherPriorityTaskWoken_core2 equals pdTRUE_core2, then a context switch
 *     // should be performed.  The syntax required to perform a context switch
 *     // from inside an ISR varies from port to port, and from compiler to
 *     // compiler.  Inspect the demos for the port you are using to find the
 *     // actual syntax required.
 *     if( xHigherPriorityTaskWoken_core2 != pdFALSE_core2 )
 *     {
 *         // Call the interrupt safe yield function here (actual function
 *         // depends on the FreeRTOS_core2 port being used).
 *     }
 * }
 * @endverbatim
 */
#define xTimerResetFromISR_core2( xTimer_core2, pxHigherPriorityTaskWoken_core2 ) \
    xTimerGenericCommand_core2( ( xTimer_core2 ), tmrCOMMAND_RESET_FROM_ISR_core2, ( xTaskGetTickCountFromISR_core2() ), ( pxHigherPriorityTaskWoken_core2 ), 0U )


/**
 * BaseType_t_core2 xTimerPendFunctionCallFromISR_core2( PendedFunction_t_core2 xFunctionToPend_core2,
 *                                          void *pvParameter1_core2,
 *                                          uint32_t ulParameter2_core2,
 *                                          BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 *
 *
 * Used from application interrupt service routines to defer the execution of a
 * function to the RTOS daemon task_core2 (the timer service task_core2, hence this function
 * is implemented in timers_core2.c and is prefixed with 'Timer').
 *
 * Ideally an interrupt service routine (ISR) is kept as short as possible, but
 * sometimes an ISR either has a lot of processing to do, or needs to perform
 * processing that is not deterministic.  In these cases
 * xTimerPendFunctionCallFromISR_core2() can be used to defer processing of a function
 * to the RTOS daemon task_core2.
 *
 * A mechanism is provided that allows the interrupt to return directly to the
 * task_core2 that will subsequently execute the pended callback function.  This
 * allows the callback function to execute contiguously in time with the
 * interrupt - just as if the callback had executed in the interrupt itself.
 *
 * @param xFunctionToPend_core2 The function to execute from the timer service/
 * daemon task_core2.  The function must conform to the PendedFunction_t_core2
 * prototype.
 *
 * @param pvParameter1_core2 The value of the callback function's first parameter.
 * The parameter has a void * type to allow it to be used to pass any type.
 * For example, unsigned longs can be cast to a void *, or the void * can be
 * used to point to a structure.
 *
 * @param ulParameter2_core2 The value of the callback function's second parameter.
 *
 * @param pxHigherPriorityTaskWoken_core2 As mentioned above, calling this function
 * will result in a message being sent to the timer daemon task_core2.  If the
 * priority of the timer daemon task_core2 (which is set using
 * configTIMER_TASK_PRIORITY_core2 in FreeRTOSConfig.h) is higher than the priority of
 * the currently running task_core2 (the task_core2 the interrupt interrupted) then
 * *pxHigherPriorityTaskWoken_core2 will be set to pdTRUE_core2 within
 * xTimerPendFunctionCallFromISR_core2(), indicating that a context switch should be
 * requested before the interrupt exits.  For that reason
 * *pxHigherPriorityTaskWoken_core2 must be initialised to pdFALSE_core2.  See the
 * example code below.
 *
 * @return pdPASS_core2 is returned if the message was successfully sent to the
 * timer daemon task_core2, otherwise pdFALSE_core2 is returned.
 *
 * Example usage:
 * @verbatim
 *
 *  // The callback function that will execute in the context of the daemon task_core2.
 *  // Note callback functions must all use this same prototype.
 *  void vProcessInterface( void *pvParameter1_core2, uint32_t ulParameter2_core2 )
 *  {
 *      BaseType_t_core2 xInterfaceToService;
 *
 *      // The interface that requires servicing is passed in the second
 *      // parameter.  The first parameter is not used in this case.
 *      xInterfaceToService = ( BaseType_t_core2 ) ulParameter2_core2;
 *
 *      // ...Perform the processing here...
 *  }
 *
 *  // An ISR that receives data packets from multiple interfaces
 *  void vAnISR( void )
 *  {
 *      BaseType_t_core2 xInterfaceToService, xHigherPriorityTaskWoken_core2;
 *
 *      // Query the hardware to determine which interface needs processing.
 *      xInterfaceToService = prvCheckInterfaces();
 *
 *      // The actual processing is to be deferred to a task_core2.  Request the
 *      // vProcessInterface() callback function is executed, passing in the
 *      // number of the interface that needs processing.  The interface to
 *      // service is passed in the second parameter.  The first parameter is
 *      // not used in this case.
 *      xHigherPriorityTaskWoken_core2 = pdFALSE_core2;
 *      xTimerPendFunctionCallFromISR_core2( vProcessInterface, NULL, ( uint32_t ) xInterfaceToService, &xHigherPriorityTaskWoken_core2 );
 *
 *      // If xHigherPriorityTaskWoken_core2 is now set to pdTRUE_core2 then a context
 *      // switch should be requested.  The macro used is port specific and will
 *      // be either portYIELD_FROM_ISR_core2() or portEND_SWITCHING_ISR() - refer to
 *      // the documentation page for the port being used.
 *      portYIELD_FROM_ISR_core2( xHigherPriorityTaskWoken_core2 );
 *
 *  }
 * @endverbatim
 */
BaseType_t_core2 xTimerPendFunctionCallFromISR_core2( PendedFunction_t_core2 xFunctionToPend_core2,
                                          void * pvParameter1_core2,
                                          uint32_t ulParameter2_core2,
                                          BaseType_t_core2 * pxHigherPriorityTaskWoken_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * BaseType_t_core2 xTimerPendFunctionCall_core2( PendedFunction_t_core2 xFunctionToPend_core2,
 *                                    void *pvParameter1_core2,
 *                                    uint32_t ulParameter2_core2,
 *                                    TickType_t_core2 xTicksToWait_core2 );
 *
 *
 * Used to defer the execution of a function to the RTOS daemon task_core2 (the timer
 * service task_core2, hence this function is implemented in timers_core2.c and is prefixed
 * with 'Timer').
 *
 * @param xFunctionToPend_core2 The function to execute from the timer service/
 * daemon task_core2.  The function must conform to the PendedFunction_t_core2
 * prototype.
 *
 * @param pvParameter1_core2 The value of the callback function's first parameter.
 * The parameter has a void * type to allow it to be used to pass any type.
 * For example, unsigned longs can be cast to a void *, or the void * can be
 * used to point to a structure.
 *
 * @param ulParameter2_core2 The value of the callback function's second parameter.
 *
 * @param xTicksToWait_core2 Calling this function will result in a message being
 * sent to the timer daemon task_core2 on a queue.  xTicksToWait_core2 is the amount of
 * time the calling task_core2 should remain in the Blocked state (so not using any
 * processing time) for space to become available on the timer queue if the
 * queue is found to be full.
 *
 * @return pdPASS_core2 is returned if the message was successfully sent to the
 * timer daemon task_core2, otherwise pdFALSE_core2 is returned.
 *
 */
BaseType_t_core2 xTimerPendFunctionCall_core2( PendedFunction_t_core2 xFunctionToPend_core2,
                                   void * pvParameter1_core2,
                                   uint32_t ulParameter2_core2,
                                   TickType_t_core2 xTicksToWait_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * const char * const pcTimerGetName_core2( TimerHandle_t_core2 xTimer_core2 );
 *
 * Returns the name that was assigned to a timer when the timer was created.
 *
 * @param xTimer_core2 The handle of the timer being queried.
 *
 * @return The name assigned to the timer specified by the xTimer_core2 parameter.
 */
const char * pcTimerGetName_core2( TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */

/**
 * void vTimerSetReloadMode_core2( TimerHandle_t_core2 xTimer_core2, const BaseType_t_core2 xAutoReload_core2 );
 *
 * Updates a timer to be either an auto-reload timer, in which case the timer
 * automatically resets itself each time it expires, or a one-shot timer, in
 * which case the timer will only expire once unless it is manually restarted.
 *
 * @param xTimer_core2 The handle of the timer being updated.
 *
 * @param xAutoReload_core2 If xAutoReload_core2 is set to pdTRUE_core2 then the timer will
 * expire repeatedly with a frequency set by the timer's period (see the
 * xTimerPeriodInTicks_core2 parameter of the xTimerCreate_core2() API function).  If
 * xAutoReload_core2 is set to pdFALSE_core2 then the timer will be a one-shot timer and
 * enter the dormant state after it expires.
 */
void vTimerSetReloadMode_core2( TimerHandle_t_core2 xTimer_core2,
                          const BaseType_t_core2 xAutoReload_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * BaseType_t_core2 xTimerGetReloadMode_core2( TimerHandle_t_core2 xTimer_core2 );
 *
 * Queries a timer to determine if it is an auto-reload timer, in which case the timer
 * automatically resets itself each time it expires, or a one-shot timer, in
 * which case the timer will only expire once unless it is manually restarted.
 *
 * @param xTimer_core2 The handle of the timer being queried.
 *
 * @return If the timer is an auto-reload timer then pdTRUE_core2 is returned, otherwise
 * pdFALSE_core2 is returned.
 */
BaseType_t_core2 xTimerGetReloadMode_core2( TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * UBaseType_t_core2 uxTimerGetReloadMode_core2( TimerHandle_t_core2 xTimer_core2 );
 *
 * Queries a timer to determine if it is an auto-reload timer, in which case the timer
 * automatically resets itself each time it expires, or a one-shot timer, in
 * which case the timer will only expire once unless it is manually restarted.
 *
 * @param xTimer_core2 The handle of the timer being queried.
 *
 * @return If the timer is an auto-reload timer then pdTRUE_core2 is returned, otherwise
 * pdFALSE_core2 is returned.
 */
UBaseType_t_core2 uxTimerGetReloadMode_core2( TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * TickType_t_core2 xTimerGetPeriod_core2( TimerHandle_t_core2 xTimer_core2 );
 *
 * Returns the period of a timer.
 *
 * @param xTimer_core2 The handle of the timer being queried.
 *
 * @return The period of the timer in ticks.
 */
TickType_t_core2 xTimerGetPeriod_core2( TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * TickType_t_core2 xTimerGetExpiryTime_core2( TimerHandle_t_core2 xTimer_core2 );
 *
 * Returns the time in ticks at which the timer will expire.  If this is less
 * than the current tick count then the expiry time has overflowed from the
 * current time.
 *
 * @param xTimer_core2 The handle of the timer being queried.
 *
 * @return If the timer is running then the time in ticks at which the timer
 * will next expire is returned.  If the timer is not running then the return
 * value is undefined.
 */
TickType_t_core2 xTimerGetExpiryTime_core2( TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Functions beyond this part are not part of the public API and are intended
 * for use by the kernel only.
 */
BaseType_t_core2 xTimerCreateTimerTask_core2( void ) PRIVILEGED_FUNCTION_core2;
BaseType_t_core2 xTimerGenericCommand_core2( TimerHandle_t_core2 xTimer_core2,
                                 const BaseType_t_core2 xCommandID_core2,
                                 const TickType_t_core2 xOptionalValue_core2,
                                 BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2,
                                 const TickType_t_core2 xTicksToWait_core2 ) PRIVILEGED_FUNCTION_core2;

#if ( configUSE_TRACE_FACILITY_core2 == 1 )
    void vTimerSetTimerNumber_core2( TimerHandle_t_core2 xTimer_core2,
                               UBaseType_t_core2 uxTimerNumber_core2 ) PRIVILEGED_FUNCTION_core2;
    UBaseType_t_core2 uxTimerGetTimerNumber_core2( TimerHandle_t_core2 xTimer_core2 ) PRIVILEGED_FUNCTION_core2;
#endif

#if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )

/**
 * task_core2.h
 * @code{c}
 * void vApplicationGetTimerTaskMemory_core2( StaticTask_t_core2 ** ppxTimerTaskTCBBuffer_core2, StackType_t_core2 ** ppxTimerTaskStackBuffer_core2, uint32_t *pulTimerTaskStackSize_core2 )
 * @endcode
 *
 * This function is used to provide a statically allocated block of memory to FreeRTOS_core2 to hold the Timer Task TCB.  This function is required when
 * configSUPPORT_STATIC_ALLOCATION_core2 is set.  For more information see this URI: https://www.FreeRTOS_core2.org/a00110.html#configSUPPORT_STATIC_ALLOCATION_core2
 *
 * @param ppxTimerTaskTCBBuffer_core2   A handle to a statically allocated TCB buffer
 * @param ppxTimerTaskStackBuffer_core2 A handle to a statically allocated Stack buffer for the idle task_core2
 * @param pulTimerTaskStackSize_core2   A pointer to the number of elements that will fit in the allocated stack buffer
 */
    void vApplicationGetTimerTaskMemory_core2( StaticTask_t_core2 ** ppxTimerTaskTCBBuffer_core2,
                                         StackType_t_core2 ** ppxTimerTaskStackBuffer_core2,
                                         uint32_t * pulTimerTaskStackSize_core2 );

#endif

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */
#endif /* TIMERS_H */
