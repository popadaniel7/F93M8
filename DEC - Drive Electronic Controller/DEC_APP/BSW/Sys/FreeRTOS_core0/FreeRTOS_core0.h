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

#ifndef INC_FREERTOS_CORE0_H
#define INC_FREERTOS_CORE0_H

/*
 * Include the generic headers required for the FreeRTOS_core0 port being used.
 */
#include <stddef.h>

/*
 * If stdint.h cannot be located then:
 *   + If using GCC ensure the -nostdint options is *not* being used.
 *   + Ensure the project's include path includes the directory in which your
 *     compiler stores stdint.h.
 *   + Set any compiler options necessary for it to support C99, as technically
 *     stdint.h is only mandatory with C99 (FreeRTOS_core0 does not require C99 in any
 *     other way).
 *   + The FreeRTOS_core0 download includes a simple stdint.h definition that can be
 *     used in cases where none is provided by the compiler.  The files only
 *     contains the typedefs required to build FreeRTOS_core0.  Read the instructions
 *     in FreeRTOS_core0/source/stdint.readme for more information.
 */
#include <stdint.h> /* READ COMMENT ABOVE. */

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

/* Application specific configuration options. */
#include "FreeRTOSConfig_core0.h"

/* Basic FreeRTOS_core0 definitions. */
#include "projdefs_core0.h"

/* Definitions specific to the port being used. */
#include "portable_core0.h"

/* Must be defaulted before configUSE_NEWLIB_REENTRANT_core0 is used below. */
#ifndef configUSE_NEWLIB_REENTRANT_core0
    #define configUSE_NEWLIB_REENTRANT_core0    0
#endif

/* Required if struct _reent is used. */
#if ( configUSE_NEWLIB_REENTRANT_core0 == 1 )

/* Note Newlib support has been included by popular demand, but is not
 * used by the FreeRTOS_core0 maintainers themselves.  FreeRTOS_core0 is not
 * responsible for resulting newlib operation.  User must be familiar with
 * newlib and must provide system-wide implementations of the necessary
 * stubs. Be warned that (at the time of writing) the current newlib design
 * implements a system-wide malloc() that must be provided with locks.
 *
 * See the third party link http://www.nadler.com/embedded/newlibAndFreeRTOS.html
 * for additional information. */
    //#include <reent.h>

    #define configUSE_C_RUNTIME_TLS_SUPPORT_core0    1

    #ifndef configTLS_BLOCK_TYPE_core0
        #define configTLS_BLOCK_TYPE_core0           struct _reent
    #endif

    #ifndef configINIT_TLS_BLOCK_core0
        #define configINIT_TLS_BLOCK_core0( xTLSBlock_core0 )    _REENT_INIT_PTR( &( xTLSBlock_core0 ) )
    #endif

    #ifndef configSET_TLS_BLOCK_core0
        #define configSET_TLS_BLOCK_core0( xTLSBlock_core0 )    _impure_ptr = &( xTLSBlock_core0 )
    #endif

    #ifndef configDEINIT_TLS_BLOCK_core0
        #define configDEINIT_TLS_BLOCK_core0( xTLSBlock_core0 )    _reclaim_reent( &( xTLSBlock_core0 ) )
    #endif
#endif /* if ( configUSE_NEWLIB_REENTRANT_core0 == 1 ) */

#ifndef configUSE_C_RUNTIME_TLS_SUPPORT_core0
    #define configUSE_C_RUNTIME_TLS_SUPPORT_core0    0
#endif

#if ( ( configUSE_NEWLIB_REENTRANT_core0 == 0 ) && ( configUSE_C_RUNTIME_TLS_SUPPORT_core0 == 1 ) )

    #ifndef configTLS_BLOCK_TYPE_core0
        #error Missing definition:  configTLS_BLOCK_TYPE_core0 must be defined in FreeRTOSConfig.h when configUSE_C_RUNTIME_TLS_SUPPORT_core0 is set to 1.
    #endif

    #ifndef configINIT_TLS_BLOCK_core0
        #error Missing definition:  configINIT_TLS_BLOCK_core0 must be defined in FreeRTOSConfig.h when configUSE_C_RUNTIME_TLS_SUPPORT_core0 is set to 1.
    #endif

    #ifndef configSET_TLS_BLOCK_core0
        #error Missing definition:  configSET_TLS_BLOCK_core0 must be defined in FreeRTOSConfig.h when configUSE_C_RUNTIME_TLS_SUPPORT_core0 is set to 1.
    #endif

    #ifndef configDEINIT_TLS_BLOCK_core0
        #error Missing definition:  configDEINIT_TLS_BLOCK_core0 must be defined in FreeRTOSConfig.h when configUSE_C_RUNTIME_TLS_SUPPORT_core0 is set to 1.
    #endif
#endif /* if ( ( configUSE_NEWLIB_REENTRANT_core0 == 0 ) && ( configUSE_C_RUNTIME_TLS_SUPPORT_core0 == 1 ) ) */

/*
 * Check all the required application specific macros have been defined.
 * These macros are application specific and (as downloaded) are defined
 * within FreeRTOSConfig.h.
 */

#ifndef configMINIMAL_STACK_SIZE_core0
    #error Missing definition:  configMINIMAL_STACK_SIZE_core0 must be defined in FreeRTOSConfig.h.  configMINIMAL_STACK_SIZE_core0 defines the size (in words) of the stack allocated to the idle task_core0.  Refer to the demo project provided for your port for a suitable value.
#endif

#ifndef configMAX_PRIORITIES_core0
    #error Missing definition:  configMAX_PRIORITIES_core0 must be defined in FreeRTOSConfig.h.  See the Configuration section of the FreeRTOS_core0 API documentation for details.
#endif

#if configMAX_PRIORITIES_core0 < 1
    #error configMAX_PRIORITIES_core0 must be defined to be greater than or equal to 1.
#endif

#ifndef configUSE_PREEMPTION_core0
    #error Missing definition:  configUSE_PREEMPTION_core0 must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS_core0 API documentation for details.
#endif

#ifndef configUSE_IDLE_HOOK_core0
    #error Missing definition:  configUSE_IDLE_HOOK_core0 must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS_core0 API documentation for details.
#endif

#ifndef configUSE_TICK_HOOK_core0
    #error Missing definition:  configUSE_TICK_HOOK_core0 must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS_core0 API documentation for details.
#endif

#ifndef configUSE_16_BIT_TICKS_core0
    #error Missing definition:  configUSE_16_BIT_TICKS_core0 must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS_core0 API documentation for details.
#endif

#ifndef configUSE_CO_ROUTINES_core0
    #define configUSE_CO_ROUTINES_core0    0
#endif

#ifndef INCLUDE_vTaskPrioritySet_core0
    #define INCLUDE_vTaskPrioritySet_core0    1
#endif

#ifndef INCLUDE_uxTaskPriorityGet_core0
    #define INCLUDE_uxTaskPriorityGet_core0    1
#endif

#ifndef INCLUDE_vTaskDelete_core0
    #define INCLUDE_vTaskDelete_core0    1
#endif

#ifndef INCLUDE_vTaskSuspend_core0
    #define INCLUDE_vTaskSuspend_core0    1
#endif

#ifdef INCLUDE_xTaskDelayUntil_core0
    #ifdef INCLUDE_vTaskDelayUntil_core0

/* INCLUDE_vTaskDelayUntil_core0 was replaced by INCLUDE_xTaskDelayUntil_core0.  Backward
 * compatibility is maintained if only one or the other is defined, but
 * there is a conflict if both are defined. */
        #error INCLUDE_vTaskDelayUntil_core0 and INCLUDE_xTaskDelayUntil_core0 are both defined.  INCLUDE_vTaskDelayUntil_core0 is no longer required and should be removed
    #endif
#endif

#ifndef INCLUDE_xTaskDelayUntil_core0
    #ifdef INCLUDE_vTaskDelayUntil_core0

/* If INCLUDE_vTaskDelayUntil_core0 is set but INCLUDE_xTaskDelayUntil_core0 is not then
 * the project's FreeRTOSConfig.h probably pre-dates the introduction of
 * xTaskDelayUntil and setting INCLUDE_xTaskDelayUntil_core0 to whatever
 * INCLUDE_vTaskDelayUntil_core0 is set to will ensure backward compatibility.
 */
        #define INCLUDE_xTaskDelayUntil_core0    INCLUDE_vTaskDelayUntil_core0
    #endif
#endif

#ifndef INCLUDE_xTaskDelayUntil_core0
    #define INCLUDE_xTaskDelayUntil_core0    1
#endif

#ifndef INCLUDE_vTaskDelay_core0
    #define INCLUDE_vTaskDelay_core0    1
#endif

#ifndef INCLUDE_xTaskGetIdleTaskHandle_core0
    #define INCLUDE_xTaskGetIdleTaskHandle_core0    1
#endif

#ifndef INCLUDE_xTaskAbortDelay_core0
    #define INCLUDE_xTaskAbortDelay_core0    1
#endif

#ifndef INCLUDE_xQueueGetMutexHolder_core0
    #define INCLUDE_xQueueGetMutexHolder_core0    1
#endif

#ifndef INCLUDE_xSemaphoreGetMutexHolder_core0
    #define INCLUDE_xSemaphoreGetMutexHolder_core0    INCLUDE_xQueueGetMutexHolder_core0
#endif

#ifndef INCLUDE_xTaskGetHandle_core0
    #define INCLUDE_xTaskGetHandle_core0    1
#endif

#ifndef INCLUDE_uxTaskGetStackHighWaterMark_core0
    #define INCLUDE_uxTaskGetStackHighWaterMark_core0    1
#endif

#ifndef INCLUDE_uxTaskGetStackHighWaterMark2_core0
    #define INCLUDE_uxTaskGetStackHighWaterMark2_core0    1
#endif

#ifndef INCLUDE_eTaskGetState_core0
    #define INCLUDE_eTaskGetState_core0    1
#endif

#ifndef INCLUDE_xTaskResumeFromISR_core0
    #define INCLUDE_xTaskResumeFromISR_core0    1
#endif

#ifndef INCLUDE_xTimerPendFunctionCall_core0
    #define INCLUDE_xTimerPendFunctionCall_core0    1
#endif

#ifndef INCLUDE_xTaskGetSchedulerState_core0
    #define INCLUDE_xTaskGetSchedulerState_core0    1
#endif

#ifndef INCLUDE_xTaskGetCurrentTaskHandle_core0
    #define INCLUDE_xTaskGetCurrentTaskHandle_core0    1
#endif

#if configUSE_CO_ROUTINES_core0 != 0
    #ifndef configMAX_CO_ROUTINE_PRIORITIES_core0
        #error configMAX_CO_ROUTINE_PRIORITIES_core0 must be greater than or equal to 1.
    #endif
#endif

#ifndef configUSE_DAEMON_TASK_STARTUP_HOOK_core0
    #define configUSE_DAEMON_TASK_STARTUP_HOOK_core0    0
#endif

#ifndef configUSE_APPLICATION_TASK_TAG_core0
    #define configUSE_APPLICATION_TASK_TAG_core0    1
#endif

#ifndef configNUM_THREAD_LOCAL_STORAGE_POINTERS_core0
    #define configNUM_THREAD_LOCAL_STORAGE_POINTERS_core0    0
#endif

#ifndef configUSE_RECURSIVE_MUTEXES_core0
    #define configUSE_RECURSIVE_MUTEXES_core0    0
#endif

#ifndef configUSE_MUTEXES_core0
    #define configUSE_MUTEXES_core0    0
#endif

#ifndef configUSE_TIMERS_core0
    #define configUSE_TIMERS_core0    0
#endif

#ifndef configUSE_COUNTING_SEMAPHORES_core0
    #define configUSE_COUNTING_SEMAPHORES_core0    0
#endif

#ifndef configUSE_ALTERNATIVE_API_core0
    #define configUSE_ALTERNATIVE_API_core0    0
#endif

#ifndef portCRITICAL_NESTING_IN_TCB_core0
    #define portCRITICAL_NESTING_IN_TCB_core0    0
#endif

#ifndef configMAX_TASK_NAME_LEN_core0
    #define configMAX_TASK_NAME_LEN_core0    16
#endif

#ifndef configIDLE_SHOULD_YIELD_core0
    #define configIDLE_SHOULD_YIELD_core0    1
#endif

#if configMAX_TASK_NAME_LEN_core0 < 1
    #error configMAX_TASK_NAME_LEN_core0 must be set to a minimum of 1 in FreeRTOSConfig.h
#endif

#ifndef configASSERT_core0
    #define configASSERT_core0( x_core0 )
    #define configASSERT_DEFINED_core0    0
#else
    #define configASSERT_DEFINED_core0    1
#endif

/* configPRECONDITION_core0 should be defined as configASSERT_core0.
 * The CBMC proofs need a way to track assumptions and assertions.
 * A configPRECONDITION_core0 statement should express an implicit invariant or
 * assumption made.  A configASSERT_core0 statement should express an invariant that must
 * hold explicit before calling the code. */
#ifndef configPRECONDITION_core0
    #define configPRECONDITION_core0( X )    configASSERT_core0( X )
    #define configPRECONDITION_DEFINED_core0    0
#else
    #define configPRECONDITION_DEFINED_core0    1
#endif

#ifndef portMEMORY_BARRIER_core0
    #define portMEMORY_BARRIER_core0()
#endif

#ifndef portSOFTWARE_BARRIER_core0
    #define portSOFTWARE_BARRIER_core0()
#endif

/* The timers_core0 module relies on xTaskGetSchedulerState_core0(). */
#if configUSE_TIMERS_core0 == 1

    #ifndef configTIMER_TASK_PRIORITY_core0
        #error If configUSE_TIMERS_core0 is set to 1 then configTIMER_TASK_PRIORITY_core0 must also be defined.
    #endif /* configTIMER_TASK_PRIORITY_core0 */

    #ifndef configTIMER_QUEUE_LENGTH_core0
        #error If configUSE_TIMERS_core0 is set to 1 then configTIMER_QUEUE_LENGTH_core0 must also be defined.
    #endif /* configTIMER_QUEUE_LENGTH_core0 */

    #ifndef configTIMER_TASK_STACK_DEPTH_core0
        #error If configUSE_TIMERS_core0 is set to 1 then configTIMER_TASK_STACK_DEPTH_core0 must also be defined.
    #endif /* configTIMER_TASK_STACK_DEPTH_core0 */

#endif /* configUSE_TIMERS_core0 */

#ifndef portSET_INTERRUPT_MASK_FROM_ISR_core0
    #define portSET_INTERRUPT_MASK_FROM_ISR_core0()    0
#endif

#ifndef portCLEAR_INTERRUPT_MASK_FROM_ISR_core0
    #define portCLEAR_INTERRUPT_MASK_FROM_ISR_core0( uxSavedStatusValue_core0 )    ( void ) ( uxSavedStatusValue_core0 )
#endif

#ifndef portCLEAN_UP_TCB_core0
    #define portCLEAN_UP_TCB_core0( pxTCB_core0 )    ( void ) ( pxTCB_core0 )
#endif

#ifndef portPRE_TASK_DELETE_HOOK_core0
    #define portPRE_TASK_DELETE_HOOK_core0( pvTaskToDelete_core0, pxYieldPending_core0 )
#endif

#ifndef portSETUP_TCB_core0
    #define portSETUP_TCB_core0( pxTCB_core0 )    ( void ) ( pxTCB_core0 )
#endif

#ifndef configQUEUE_REGISTRY_SIZE_core0
    #define configQUEUE_REGISTRY_SIZE_core0    0U
#endif

#if ( configQUEUE_REGISTRY_SIZE_core0 < 1 )
    #define vQueueAddToRegistry_core0( xQueue_core0, pcName_core0 )
    #define vQueueUnregisterQueue( xQueue_core0 )
    #define pcQueueGetName( xQueue_core0 )
#endif

#ifndef configUSE_MINI_LIST_ITEM_core0
    #define configUSE_MINI_LIST_ITEM_core0    1
#endif

#ifndef portPOINTER_SIZE_TYPE_core0
    #define portPOINTER_SIZE_TYPE_core0    uint32_t
#endif

/* Remove any unused trace macros. */
#ifndef traceSTART_core0

/* Used to perform any necessary initialisation - for example, open a file
 * into which trace is to be written. */
    #define traceSTART_core0()
#endif

#ifndef traceEND_core0

/* Use to close a trace, for example close a file into which trace has been
 * written. */
    #define traceEND_core0()
#endif

#ifndef traceTASK_SWITCHED_IN_core0

/* Called after a task_core0 has been selected to run.  pxCurrentTCB_core0 holds a pointer
 * to the task_core0 control block of the selected task_core0. */
    #define traceTASK_SWITCHED_IN_core0()
#endif

#ifndef traceINCREASE_TICK_COUNT_core0

/* Called before stepping the tick count after waking from tickless idle
 * sleep. */
    #define traceINCREASE_TICK_COUNT_core0( x_core0 )
#endif

#ifndef traceLOW_POWER_IDLE_BEGIN_core0
    /* Called immediately before entering tickless idle. */
    #define traceLOW_POWER_IDLE_BEGIN_core0()
#endif

#ifndef traceLOW_POWER_IDLE_END_core0
    /* Called when returning to the Idle task_core0 after a tickless idle. */
    #define traceLOW_POWER_IDLE_END_core0()
#endif

#ifndef traceTASK_SWITCHED_OUT_core0

/* Called before a task_core0 has been selected to run.  pxCurrentTCB_core0 holds a pointer
 * to the task_core0 control block of the task_core0 being switched out. */
    #define traceTASK_SWITCHED_OUT_core0()
#endif

#ifndef traceTASK_PRIORITY_INHERIT_core0

/* Called when a task_core0 attempts to take a mutex that is already held by a
 * lower priority task_core0.  pxTCBOfMutexHolder_core0 is a pointer to the TCB of the task_core0
 * that holds the mutex.  uxInheritedPriority is the priority the mutex holder
 * will inherit (the priority of the task_core0 that is attempting to obtain the
 * muted. */
    #define traceTASK_PRIORITY_INHERIT_core0( pxTCBOfMutexHolder_core0, uxInheritedPriority )
#endif

#ifndef traceTASK_PRIORITY_DISINHERIT_core0

/* Called when a task_core0 releases a mutex, the holding of which had resulted in
 * the task_core0 inheriting the priority of a higher priority task_core0.
 * pxTCBOfMutexHolder_core0 is a pointer to the TCB of the task_core0 that is releasing the
 * mutex.  uxOriginalPriority_core0 is the task_core0's configured (base) priority. */
    #define traceTASK_PRIORITY_DISINHERIT_core0( pxTCBOfMutexHolder_core0, uxOriginalPriority_core0 )
#endif

#ifndef traceBLOCKING_ON_QUEUE_RECEIVE_core0

/* Task is about to block because it cannot read from a
 * queue/mutex/semaphore.  pxQueue_core0 is a pointer to the queue/mutex/semaphore
 * upon which the read was attempted.  pxCurrentTCB_core0 points to the TCB of the
 * task_core0 that attempted the read. */
    #define traceBLOCKING_ON_QUEUE_RECEIVE_core0( pxQueue_core0 )
#endif

#ifndef traceBLOCKING_ON_QUEUE_PEEK_core0

/* Task is about to block because it cannot read from a
 * queue/mutex/semaphore.  pxQueue_core0 is a pointer to the queue/mutex/semaphore
 * upon which the read was attempted.  pxCurrentTCB_core0 points to the TCB of the
 * task_core0 that attempted the read. */
    #define traceBLOCKING_ON_QUEUE_PEEK_core0( pxQueue_core0 )
#endif

#ifndef traceBLOCKING_ON_QUEUE_SEND_core0

/* Task is about to block because it cannot write to a
 * queue/mutex/semaphore.  pxQueue_core0 is a pointer to the queue/mutex/semaphore
 * upon which the write was attempted.  pxCurrentTCB_core0 points to the TCB of the
 * task_core0 that attempted the write. */
    #define traceBLOCKING_ON_QUEUE_SEND_core0( pxQueue_core0 )
#endif

#ifndef configCHECK_FOR_STACK_OVERFLOW_core0
    #define configCHECK_FOR_STACK_OVERFLOW_core0    0
#endif

#ifndef configRECORD_STACK_HIGH_ADDRESS_core0
    #define configRECORD_STACK_HIGH_ADDRESS_core0    0
#endif

#ifndef configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H
    #define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H    0
#endif

/* The following event macros are embedded in the kernel API calls. */

#ifndef traceMOVED_TASK_TO_READY_STATE_core0
    #define traceMOVED_TASK_TO_READY_STATE_core0( pxTCB_core0 )
#endif

#ifndef tracePOST_MOVED_TASK_TO_READY_STATE
    #define tracePOST_MOVED_TASK_TO_READY_STATE( pxTCB_core0 )
#endif

#ifndef traceQUEUE_CREATE_core0
    #define traceQUEUE_CREATE_core0( pxNewQueue_core0 )
#endif

#ifndef traceQUEUE_CREATE_FAILED_core0
    #define traceQUEUE_CREATE_FAILED_core0( ucQueueType_core0 )
#endif

#ifndef traceCREATE_MUTEX_core0
    #define traceCREATE_MUTEX_core0( pxNewQueue_core0 )
#endif

#ifndef traceCREATE_MUTEX_FAILED_core0
    #define traceCREATE_MUTEX_FAILED_core0()
#endif

#ifndef traceGIVE_MUTEX_RECURSIVE_core0
    #define traceGIVE_MUTEX_RECURSIVE_core0( pxMutex_core0 )
#endif

#ifndef traceGIVE_MUTEX_RECURSIVE_FAILED_core0
    #define traceGIVE_MUTEX_RECURSIVE_FAILED_core0( pxMutex_core0 )
#endif

#ifndef traceTAKE_MUTEX_RECURSIVE_core0
    #define traceTAKE_MUTEX_RECURSIVE_core0( pxMutex_core0 )
#endif

#ifndef traceTAKE_MUTEX_RECURSIVE_FAILED_core0
    #define traceTAKE_MUTEX_RECURSIVE_FAILED_core0( pxMutex_core0 )
#endif

#ifndef traceCREATE_COUNTING_SEMAPHORE_core0
    #define traceCREATE_COUNTING_SEMAPHORE_core0()
#endif

#ifndef traceCREATE_COUNTING_SEMAPHORE_FAILED_core0
    #define traceCREATE_COUNTING_SEMAPHORE_FAILED_core0()
#endif

#ifndef traceQUEUE_SET_SEND_core0
    #define traceQUEUE_SET_SEND_core0    traceQUEUE_SEND_core0
#endif

#ifndef traceQUEUE_SEND_core0
    #define traceQUEUE_SEND_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_SEND_FAILED_core0
    #define traceQUEUE_SEND_FAILED_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_RECEIVE_core0
    #define traceQUEUE_RECEIVE_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_PEEK_core0
    #define traceQUEUE_PEEK_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_PEEK_FAILED_core0
    #define traceQUEUE_PEEK_FAILED_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_PEEK_FROM_ISR_core0
    #define traceQUEUE_PEEK_FROM_ISR_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_RECEIVE_FAILED_core0
    #define traceQUEUE_RECEIVE_FAILED_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_SEND_FROM_ISR_core0
    #define traceQUEUE_SEND_FROM_ISR_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_SEND_FROM_ISR_FAILED_core0
    #define traceQUEUE_SEND_FROM_ISR_FAILED_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_RECEIVE_FROM_ISR_core0
    #define traceQUEUE_RECEIVE_FROM_ISR_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_RECEIVE_FROM_ISR_FAILED_core0
    #define traceQUEUE_RECEIVE_FROM_ISR_FAILED_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_PEEK_FROM_ISR_FAILED_core0
    #define traceQUEUE_PEEK_FROM_ISR_FAILED_core0( pxQueue_core0 )
#endif

#ifndef traceQUEUE_DELETE_core0
    #define traceQUEUE_DELETE_core0( pxQueue_core0 )
#endif

#ifndef traceTASK_CREATE_core0
    #define traceTASK_CREATE_core0( pxNewTCB_core0 )
#endif

#ifndef traceTASK_CREATE_FAILED_core0
    #define traceTASK_CREATE_FAILED_core0()
#endif

#ifndef traceTASK_DELETE_core0
    #define traceTASK_DELETE_core0( pxTaskToDelete )
#endif

#ifndef traceTASK_DELAY_UNTIL_core0
    #define traceTASK_DELAY_UNTIL_core0( x_core0 )
#endif

#ifndef traceTASK_DELAY_core0
    #define traceTASK_DELAY_core0()
#endif

#ifndef traceTASK_PRIORITY_SET_core0
    #define traceTASK_PRIORITY_SET_core0( pxTask, uxNewPriority_core0 )
#endif

#ifndef traceTASK_SUSPEND_core0
    #define traceTASK_SUSPEND_core0( pxTaskToSuspend )
#endif

#ifndef traceTASK_RESUME_core0
    #define traceTASK_RESUME_core0( pxTaskToResume )
#endif

#ifndef traceTASK_RESUME_FROM_ISR_core0
    #define traceTASK_RESUME_FROM_ISR_core0( pxTaskToResume )
#endif

#ifndef traceTASK_INCREMENT_TICK_core0
    #define traceTASK_INCREMENT_TICK_core0( xTickCount_core0 )
#endif

#ifndef traceTIMER_CREATE_core0
    #define traceTIMER_CREATE_core0( pxNewTimer_core0 )
#endif

#ifndef traceTIMER_CREATE_FAILED_core0
    #define traceTIMER_CREATE_FAILED_core0()
#endif

#ifndef traceTIMER_COMMAND_SEND_core0
    #define traceTIMER_COMMAND_SEND_core0( xTimer_core0, xMessageID_core0, xMessageValueValue_core0, xReturn_core0 )
#endif

#ifndef traceTIMER_EXPIRED_core0
    #define traceTIMER_EXPIRED_core0( pxTimer_core0 )
#endif

#ifndef traceTIMER_COMMAND_RECEIVED_core0
    #define traceTIMER_COMMAND_RECEIVED_core0( pxTimer_core0, xMessageID_core0, xMessageValue_core0 )
#endif

#ifndef traceMALLOC_core0
    #define traceMALLOC_core0( pvAddress_core0, uiSize_core0 )
#endif

#ifndef traceFREE_core0
    #define traceFREE_core0( pvAddress_core0, uiSize_core0 )
#endif

#ifndef traceEVENT_GROUP_CREATE_core0
    #define traceEVENT_GROUP_CREATE_core0( xEventGroup_core0 )
#endif

#ifndef traceEVENT_GROUP_CREATE_FAILED_core0
    #define traceEVENT_GROUP_CREATE_FAILED_core0()
#endif

#ifndef traceEVENT_GROUP_SYNC_BLOCK_core0
    #define traceEVENT_GROUP_SYNC_BLOCK_core0( xEventGroup_core0, uxBitsToSet_core0, uxBitsToWaitFor_core0 )
#endif

#ifndef traceEVENT_GROUP_SYNC_END_core0
    #define traceEVENT_GROUP_SYNC_END_core0( xEventGroup_core0, uxBitsToSet_core0, uxBitsToWaitFor_core0, xTimeoutOccurred_core0 )    ( void ) ( xTimeoutOccurred_core0 )
#endif

#ifndef traceEVENT_GROUP_WAIT_BITS_BLOCK_core0
    #define traceEVENT_GROUP_WAIT_BITS_BLOCK_core0( xEventGroup_core0, uxBitsToWaitFor_core0 )
#endif

#ifndef traceEVENT_GROUP_WAIT_BITS_END_core0
    #define traceEVENT_GROUP_WAIT_BITS_END_core0( xEventGroup_core0, uxBitsToWaitFor_core0, xTimeoutOccurred_core0 )    ( void ) ( xTimeoutOccurred_core0 )
#endif

#ifndef traceEVENT_GROUP_CLEAR_BITS_core0
    #define traceEVENT_GROUP_CLEAR_BITS_core0( xEventGroup_core0, uxBitsToClear_core0 )
#endif

#ifndef traceEVENT_GROUP_CLEAR_BITS_FROM_ISR_core0
    #define traceEVENT_GROUP_CLEAR_BITS_FROM_ISR_core0( xEventGroup_core0, uxBitsToClear_core0 )
#endif

#ifndef traceEVENT_GROUP_SET_BITS_core0
    #define traceEVENT_GROUP_SET_BITS_core0( xEventGroup_core0, uxBitsToSet_core0 )
#endif

#ifndef traceEVENT_GROUP_SET_BITS_FROM_ISR_core0
    #define traceEVENT_GROUP_SET_BITS_FROM_ISR_core0( xEventGroup_core0, uxBitsToSet_core0 )
#endif

#ifndef traceEVENT_GROUP_DELETE_core0
    #define traceEVENT_GROUP_DELETE_core0( xEventGroup_core0 )
#endif

#ifndef tracePEND_FUNC_CALL_core0
    #define tracePEND_FUNC_CALL_core0( xFunctionToPend_core0, pvParameter1_core0, ulParameter2_core0, ret_core0 )
#endif

#ifndef tracePEND_FUNC_CALL_FROM_ISR_core0
    #define tracePEND_FUNC_CALL_FROM_ISR_core0( xFunctionToPend_core0, pvParameter1_core0, ulParameter2_core0, ret_core0 )
#endif

#ifndef traceQUEUE_REGISTRY_ADD_core0
    #define traceQUEUE_REGISTRY_ADD_core0( xQueue_core0, pcQueueName_core0 )
#endif

#ifndef traceTASK_NOTIFY_TAKE_BLOCK_core0
    #define traceTASK_NOTIFY_TAKE_BLOCK_core0( uxIndexToWait_core0 )
#endif

#ifndef traceTASK_NOTIFY_TAKE_core0
    #define traceTASK_NOTIFY_TAKE_core0( uxIndexToWait_core0 )
#endif

#ifndef traceTASK_NOTIFY_WAIT_BLOCK_core0
    #define traceTASK_NOTIFY_WAIT_BLOCK_core0( uxIndexToWait_core0 )
#endif

#ifndef traceTASK_NOTIFY_WAIT_core0
    #define traceTASK_NOTIFY_WAIT_core0( uxIndexToWait_core0 )
#endif

#ifndef traceTASK_NOTIFY_core0
    #define traceTASK_NOTIFY_core0( uxIndexToNotify_core0 )
#endif

#ifndef traceTASK_NOTIFY_FROM_ISR_core0
    #define traceTASK_NOTIFY_FROM_ISR_core0( uxIndexToNotify_core0 )
#endif

#ifndef traceTASK_NOTIFY_GIVE_FROM_ISR_core0
    #define traceTASK_NOTIFY_GIVE_FROM_ISR_core0( uxIndexToNotify_core0 )
#endif

#ifndef traceSTREAM_BUFFER_CREATE_FAILED_core0
    #define traceSTREAM_BUFFER_CREATE_FAILED_core0( xIsMessageBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_CREATE_STATIC_FAILED_core0
    #define traceSTREAM_BUFFER_CREATE_STATIC_FAILED_core0( xReturn_core0, xIsMessageBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_CREATE_core0
    #define traceSTREAM_BUFFER_CREATE_core0( pxStreamBuffer_core0, xIsMessageBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_DELETE_core0
    #define traceSTREAM_BUFFER_DELETE_core0( xStreamBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_RESET_core0
    #define traceSTREAM_BUFFER_RESET_core0( xStreamBuffer_core0 )
#endif

#ifndef traceBLOCKING_ON_STREAM_BUFFER_SEND_core0
    #define traceBLOCKING_ON_STREAM_BUFFER_SEND_core0( xStreamBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_SEND_core0
    #define traceSTREAM_BUFFER_SEND_core0( xStreamBuffer_core0, xBytesSent_core0 )
#endif

#ifndef traceSTREAM_BUFFER_SEND_FAILED_core0
    #define traceSTREAM_BUFFER_SEND_FAILED_core0( xStreamBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_SEND_FROM_ISR_core0
    #define traceSTREAM_BUFFER_SEND_FROM_ISR_core0( xStreamBuffer_core0, xBytesSent_core0 )
#endif

#ifndef traceBLOCKING_ON_STREAM_BUFFER_RECEIVE_core0
    #define traceBLOCKING_ON_STREAM_BUFFER_RECEIVE_core0( xStreamBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_RECEIVE_core0
    #define traceSTREAM_BUFFER_RECEIVE_core0( xStreamBuffer_core0, xReceivedLength_core0 )
#endif

#ifndef traceSTREAM_BUFFER_RECEIVE_FAILED_core0
    #define traceSTREAM_BUFFER_RECEIVE_FAILED_core0( xStreamBuffer_core0 )
#endif

#ifndef traceSTREAM_BUFFER_RECEIVE_FROM_ISR_core0
    #define traceSTREAM_BUFFER_RECEIVE_FROM_ISR_core0( xStreamBuffer_core0, xReceivedLength_core0 )
#endif

#ifndef configGENERATE_RUN_TIME_STATS_core0
    #define configGENERATE_RUN_TIME_STATS_core0   0
#endif

#if ( configGENERATE_RUN_TIME_STATS_core0 == 1 )

    #ifndef portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core0
        #error If configGENERATE_RUN_TIME_STATS_core0 is defined then portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core0 must also be defined.  portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core0 should call a port layer function to setup a peripheral timer/counter that can then be used as the run time counter time base.
    #endif /* portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core0 */

    #ifndef portGET_RUN_TIME_COUNTER_VALUE_core0
        #ifndef portALT_GET_RUN_TIME_COUNTER_VALUE_core0
            #error If configGENERATE_RUN_TIME_STATS_core0 is defined then either portGET_RUN_TIME_COUNTER_VALUE_core0 or portALT_GET_RUN_TIME_COUNTER_VALUE_core0 must also be defined.  See the examples provided and the FreeRTOS_core0 web site for more information.
        #endif /* portALT_GET_RUN_TIME_COUNTER_VALUE_core0 */
    #endif /* portGET_RUN_TIME_COUNTER_VALUE_core0 */

#endif /* configGENERATE_RUN_TIME_STATS_core0 */

#ifndef portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core0

#endif

#ifndef configUSE_MALLOC_FAILED_HOOK_core0
    #define configUSE_MALLOC_FAILED_HOOK_core0    0
#endif

#ifndef portPRIVILEGE_BIT_core0
    #define portPRIVILEGE_BIT_core0    ( ( UBaseType_t_core0 ) 0x00 )
#endif

#ifndef portYIELD_WITHIN_API_core0
    #define portYIELD_WITHIN_API_core0    portYIELD_core0
#endif

#ifndef portSUPPRESS_TICKS_AND_SLEEP_core0
    #define portSUPPRESS_TICKS_AND_SLEEP_core0( xExpectedIdleTime_core0 )
#endif

#ifndef configEXPECTED_IDLE_TIME_BEFORE_SLEEP_core0
    #define configEXPECTED_IDLE_TIME_BEFORE_SLEEP_core0    2
#endif

#if configEXPECTED_IDLE_TIME_BEFORE_SLEEP_core0 < 2
    #error configEXPECTED_IDLE_TIME_BEFORE_SLEEP_core0 must not be less than 2
#endif

#ifndef configUSE_TICKLESS_IDLE_core0
    #define configUSE_TICKLESS_IDLE_core0    0
#endif

#ifndef configPRE_SUPPRESS_TICKS_AND_SLEEP_PROCESSING_core0
    #define configPRE_SUPPRESS_TICKS_AND_SLEEP_PROCESSING_core0( x_core0 )
#endif

#ifndef configPRE_SLEEP_PROCESSING_core0
    #define configPRE_SLEEP_PROCESSING_core0( x_core0 )
#endif

#ifndef configPOST_SLEEP_PROCESSING_core0
    #define configPOST_SLEEP_PROCESSING_core0( x_core0 )
#endif

#ifndef configUSE_QUEUE_SETS_core0
    #define configUSE_QUEUE_SETS_core0    0
#endif

#ifndef portTASK_USES_FLOATING_POINT_core0
    #define portTASK_USES_FLOATING_POINT_core0()
#endif

#ifndef portALLOCATE_SECURE_CONTEXT_core0
    #define portALLOCATE_SECURE_CONTEXT_core0( ulSecureStackSize_core0 )
#endif

#ifndef portDONT_DISCARD_core0
    #define portDONT_DISCARD_core0
#endif

#ifndef configUSE_TIME_SLICING_core0
    #define configUSE_TIME_SLICING_core0    1
#endif

#ifndef configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS_core0
    #define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS_core0    0
#endif

#ifndef configUSE_STATS_FORMATTING_FUNCTIONS_core0
    #define configUSE_STATS_FORMATTING_FUNCTIONS_core0    0
#endif

#ifndef portASSERT_IF_INTERRUPT_PRIORITY_INVALID_core0
    #define portASSERT_IF_INTERRUPT_PRIORITY_INVALID_core0()
#endif

#ifndef configUSE_TRACE_FACILITY_core0
    #define configUSE_TRACE_FACILITY_core0    0
#endif

#ifndef mtCOVERAGE_TEST_MARKER_core0
    #define mtCOVERAGE_TEST_MARKER_core0()
#endif

#ifndef mtCOVERAGE_TEST_DELAY_core0
    #define mtCOVERAGE_TEST_DELAY_core0()
#endif

#ifndef portASSERT_IF_IN_ISR_core0
    #define portASSERT_IF_IN_ISR_core0()
#endif

#ifndef configUSE_PORT_OPTIMISED_TASK_SELECTION_core0
    #define configUSE_PORT_OPTIMISED_TASK_SELECTION_core0    0
#endif

#ifndef configAPPLICATION_ALLOCATED_HEAP_core0
    #define configAPPLICATION_ALLOCATED_HEAP_core0    0
#endif

#ifndef configUSE_TASK_NOTIFICATIONS_core0
    #define configUSE_TASK_NOTIFICATIONS_core0    1
#endif

#ifndef configTASK_NOTIFICATION_ARRAY_ENTRIES_core0
    #define configTASK_NOTIFICATION_ARRAY_ENTRIES_core0    1
#endif

#if configTASK_NOTIFICATION_ARRAY_ENTRIES_core0 < 1
    #error configTASK_NOTIFICATION_ARRAY_ENTRIES_core0 must be at least 1
#endif

#ifndef configUSE_POSIX_ERRNO_core0
    #define configUSE_POSIX_ERRNO_core0    0
#endif

#ifndef configUSE_SB_COMPLETED_CALLBACK_core0

/* By default per-instance callbacks are not enabled for stream buffer or message buffer. */
    #define configUSE_SB_COMPLETED_CALLBACK_core0    0
#endif

#ifndef portTICK_TYPE_IS_ATOMIC_core0
    #define portTICK_TYPE_IS_ATOMIC_core0    0
#endif

#ifndef configSUPPORT_STATIC_ALLOCATION_core0
    /* Defaults to 0 for backward compatibility. */
    #define configSUPPORT_STATIC_ALLOCATION_core0    0
#endif

#ifndef configSUPPORT_DYNAMIC_ALLOCATION_core0
    /* Defaults to 1 for backward compatibility. */
    #define configSUPPORT_DYNAMIC_ALLOCATION_core0    1
#endif

#if ( ( configUSE_STATS_FORMATTING_FUNCTIONS_core0 > 0 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core0 != 1 ) )
    #error configUSE_STATS_FORMATTING_FUNCTIONS_core0 cannot be used without dynamic allocation, but configSUPPORT_DYNAMIC_ALLOCATION_core0 is not set to 1.
#endif

#if ( configUSE_STATS_FORMATTING_FUNCTIONS_core0 > 0 )
    #if ( ( configUSE_TRACE_FACILITY_core0 != 1 ) && ( configGENERATE_RUN_TIME_STATS_core0 != 1 ) )
        #error configUSE_STATS_FORMATTING_FUNCTIONS_core0 is 1 but the functions it enables are not used because neither configUSE_TRACE_FACILITY_core0 or configGENERATE_RUN_TIME_STATS_core0 are 1.  Set configUSE_STATS_FORMATTING_FUNCTIONS_core0 to 0 in FreeRTOSConfig.h.
    #endif
#endif

#ifndef configSTACK_DEPTH_TYPE_core0

/* Defaults to uint16_t for backward compatibility, but can be overridden
 * in FreeRTOSConfig.h if uint16_t is too restrictive. */
    #define configSTACK_DEPTH_TYPE_core0    uint32_t
#endif

#ifndef configRUN_TIME_COUNTER_TYPE_core0

/* Defaults to uint32_t for backward compatibility, but can be overridden in
 * FreeRTOSConfig.h if uint32_t is too restrictive. */

    #define configRUN_TIME_COUNTER_TYPE_core0    uint32_t
#endif

#ifndef configMESSAGE_BUFFER_LENGTH_TYPE_core0

/* Defaults to size_t for backward compatibility, but can be overridden
 * in FreeRTOSConfig.h if lengths will always be less than the number of bytes
 * in a size_t. */
    #define configMESSAGE_BUFFER_LENGTH_TYPE_core0    size_t
#endif

/* Sanity check the configuration. */
#if ( ( configSUPPORT_STATIC_ALLOCATION_core0 == 0 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 0 ) )
    #error configSUPPORT_STATIC_ALLOCATION_core0 and configSUPPORT_DYNAMIC_ALLOCATION_core0 cannot both be 0, but can both be 1.
#endif

#if ( ( configUSE_RECURSIVE_MUTEXES_core0 == 1 ) && ( configUSE_MUTEXES_core0 != 1 ) )
    #error configUSE_MUTEXES_core0 must be set to 1 to use recursive mutexes
#endif

#ifndef configINITIAL_TICK_COUNT_core0
    #define configINITIAL_TICK_COUNT_core0    0
#endif

#if ( portTICK_TYPE_IS_ATOMIC_core0 == 0 )

/* Either variables of tick type cannot be read atomically, or
 * portTICK_TYPE_IS_ATOMIC_core0 was not set - map the critical sections used when
 * the tick count is returned to the standard critical section macros. */
    #define portTICK_TYPE_ENTER_CRITICAL_core0()                      portENTER_CRITICAL_core0()
    #define portTICK_TYPE_EXIT_CRITICAL_core0()                       portEXIT_CRITICAL_core0()
    #define portTICK_TYPE_SET_INTERRUPT_MASK_FROM_ISR_core0()         portSET_INTERRUPT_MASK_FROM_ISR_core0()
    #define portTICK_TYPE_CLEAR_INTERRUPT_MASK_FROM_ISR_core0( x_core0 )    portCLEAR_INTERRUPT_MASK_FROM_ISR_core0( ( x_core0 ) )
#else

/* The tick type can be read atomically, so critical sections used when the
 * tick count is returned can be defined away. */
    #define portTICK_TYPE_ENTER_CRITICAL_core0()
    #define portTICK_TYPE_EXIT_CRITICAL_core0()
    #define portTICK_TYPE_SET_INTERRUPT_MASK_FROM_ISR_core0()         0
    #define portTICK_TYPE_CLEAR_INTERRUPT_MASK_FROM_ISR_core0( x_core0 )    ( void ) ( x_core0 )
#endif /* if ( portTICK_TYPE_IS_ATOMIC_core0 == 0 ) */

/* Definitions to allow backward compatibility with FreeRTOS_core0 versions prior to
 * V8 if desired. */
#ifndef configENABLE_BACKWARD_COMPATIBILITY_core0
    #define configENABLE_BACKWARD_COMPATIBILITY_core0    1
#endif

#ifndef configPRINTF_core0

/* configPRINTF_core0() was not defined, so define it away to nothing.  To use
 * configPRINTF_core0() then define it as follows (where MyPrintFunction() is
 * provided by the application writer):
 *
 * void MyPrintFunction(const char *pcFormat, ... );
 #define configPRINTF_core0( X )   MyPrintFunction X
 *
 * Then call like a standard printf() function, but placing brackets around
 * all parameters so they are passed as a single parameter.  For example:
 * configPRINTF_core0( ("Value = %d", MyVariable) ); */
    #define configPRINTF_core0( X )
#endif

#ifndef configMAX_core0

/* The application writer has not provided their own MAX macro, so define
 * the following generic implementation. */
    #define configMAX_core0( a, b )    ( ( ( a ) > ( b ) ) ? ( a ) : ( b ) )
#endif

#ifndef configMIN_core0

/* The application writer has not provided their own MIN macro, so define
 * the following generic implementation. */
    #define configMIN_core0( a, b )    ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
#endif

#if configENABLE_BACKWARD_COMPATIBILITY_core0 == 1
    #define eTaskStateGet_core0                 eTaskGetState_core0
    #define portTickType_core0                  TickType_t_core0
    #define xTaskHandle_core0                   TaskHandle_t_core0
    #define xQueueHandle_core0                  QueueHandle_t_core0
    #define xSemaphoreHandle_core0              SemaphoreHandle_t_core0
    #define xQueueSetHandle_core0               QueueSetHandle_t_core0
    #define xQueueSetMemberHandle_core0         QueueSetMemberHandle_t_core0
    #define xTimeOutType_core0                  TimeOut_t_core0
    #define xMemoryRegion_core0                 MemoryRegion_t_core0
    #define xTaskParameters_core0               TaskParameters_t_core0
    #define xTaskStatusType_core0               TaskStatus_t_core0
    #define xTimerHandle_core0                  TimerHandle_t_core0
    #define xCoRoutineHandle_core0              CoRoutineHandle_t_core0
    #define pdTASK_HOOK_CODE_core0              TaskHookFunction_t_core0
    #define portTICK_RATE_MS_core0              portTICK_PERIOD_MS_core0
    #define pcTaskGetTaskName_core0             pcTaskGetName_core0
    #define pcTimerGetTimerName_core0           pcTimerGetName_core0
    #define pcQueueGetQueueName_core0           pcQueueGetName_core0
    #define vTaskGetTaskInfo_core0              vTaskGetInfo_core0
    #define xTaskGetIdleRunTimeCounter_core0    ulTaskGetIdleRunTimeCounter_core0

/* Backward compatibility within the scheduler code only - these definitions
 * are not really required but are included for completeness. */
    #define tmrTIMER_CALLBACK_core0             TimerCallbackFunction_t_core0
    #define pdTASK_CODE_core0                   TaskFunction_t_core0
    #define xListItem_core0                     ListItem_t_core0
    #define xList_core0                         List_t_core0

/* For libraries that break the list data hiding, and access list structure
 * members directly (which is not supposed to be done). */
    #define pxContainer_core0                   pvContainer_core0
#endif /* configENABLE_BACKWARD_COMPATIBILITY_core0 */

#if ( configUSE_ALTERNATIVE_API_core0 != 0 )
    #error The alternative API was deprecated some time ago, and was removed in FreeRTOS_core0 V9.0 0
#endif

/* Set configUSE_TASK_FPU_SUPPORT to 0 to omit floating point support even
 * if floating point hardware is otherwise supported by the FreeRTOS_core0 port in use.
 * This constant is not supported by all FreeRTOS_core0 ports that include floating
 * point support. */
#ifndef configUSE_TASK_FPU_SUPPORT_core0
    #define configUSE_TASK_FPU_SUPPORT_core0    0
#endif

/* Set configENABLE_MPU to 1 to enable MPU support and 0 to disable it. This is
 * currently used in ARMv8M ports. */
#ifndef configENABLE_MPU_core0
    #define configENABLE_MPU_core0    0
#endif

/* Set configENABLE_FPU to 1 to enable FPU support and 0 to disable it. This is
 * currently used in ARMv8M ports. */
#ifndef configENABLE_FPU_core0
    #define configENABLE_FPU_core0    0
#endif

/* Set configENABLE_MVE to 1 to enable MVE support and 0 to disable it. This is
 * currently used in ARMv8M ports. */
#ifndef configENABLE_MVE_core0
    #define configENABLE_MVE_core0   1
#endif

/* Set configENABLE_TRUSTZONE to 1 enable TrustZone support and 0 to disable it.
 * This is currently used in ARMv8M ports. */
#ifndef configENABLE_TRUSTZONE_core0
    #define configENABLE_TRUSTZONE_core0    1
#endif

/* Set configRUN_FREERTOS_SECURE_ONLY to 1 to run the FreeRTOS_core0 ARMv8M port on
 * the Secure Side only. */
#ifndef configRUN_FREERTOS_SECURE_ONLY_core0
    #define configRUN_FREERTOS_SECURE_ONLY_core0    0
#endif

#ifndef configRUN_ADDITIONAL_TESTS_core0
    #define configRUN_ADDITIONAL_TESTS_core0    0
#endif


/* Sometimes the FreeRTOSConfig.h settings only allow a task_core0 to be created using
 * dynamically allocated RAM, in which case when any task_core0 is deleted it is known
 * that both the task_core0's stack and TCB need to be freed.  Sometimes the
 * FreeRTOSConfig.h settings only allow a task_core0 to be created using statically
 * allocated RAM, in which case when any task_core0 is deleted it is known that neither
 * the task_core0's stack or TCB should be freed.  Sometimes the FreeRTOSConfig.h
 * settings allow a task_core0 to be created using either statically or dynamically
 * allocated RAM, in which case a member of the TCB is used to record whether the
 * stack and/or TCB were allocated statically or dynamically, so when a task_core0 is
 * deleted the RAM that was allocated dynamically is freed again and no attempt is
 * made to free the RAM that was allocated statically.
 * tskSTATIC_AND_DYNAMIC_ALLOCATION_POSSIBLE_core0 is only true if it is possible for a
 * task_core0 to be created using either statically or dynamically allocated RAM.  Note
 * that if portUSING_MPU_WRAPPERS_core0 is 1 then a protected task_core0 can be created with
 * a statically allocated stack and a dynamically allocated TCB.
 *
 * The following table lists various combinations of portUSING_MPU_WRAPPERS_core0,
 * configSUPPORT_DYNAMIC_ALLOCATION_core0 and configSUPPORT_STATIC_ALLOCATION_core0 and
 * when it is possible to have both static and dynamic allocation:
 *  +-----+---------+--------+-----------------------------+-----------------------------------+------------------+-----------+
 * | MPU | Dynamic | Static |     Available Functions     |       Possible Allocations        | Both Dynamic and | Need Free |
 * |     |         |        |                             |                                   | Static Possible  |           |
 * +-----+---------+--------+-----------------------------+-----------------------------------+------------------+-----------+
 * | 0   | 0       | 1      | xTaskCreateStatic_core0           | TCB - Static, Stack - Static      | No               | No        |
 * +-----|---------|--------|-----------------------------|-----------------------------------|------------------|-----------|
 * | 0   | 1       | 0      | xTaskCreate_core0                 | TCB - Dynamic, Stack - Dynamic    | No               | Yes       |
 * +-----|---------|--------|-----------------------------|-----------------------------------|------------------|-----------|
 * | 0   | 1       | 1      | xTaskCreate_core0,                | 1. TCB - Dynamic, Stack - Dynamic | Yes              | Yes       |
 * |     |         |        | xTaskCreateStatic_core0           | 2. TCB - Static, Stack - Static   |                  |           |
 * +-----|---------|--------|-----------------------------|-----------------------------------|------------------|-----------|
 * | 1   | 0       | 1      | xTaskCreateStatic_core0,          | TCB - Static, Stack - Static      | No               | No        |
 * |     |         |        | xTaskCreateRestrictedStatic_core0 |                                   |                  |           |
 * +-----|---------|--------|-----------------------------|-----------------------------------|------------------|-----------|
 * | 1   | 1       | 0      | xTaskCreate_core0,                | 1. TCB - Dynamic, Stack - Dynamic | Yes              | Yes       |
 * |     |         |        | xTaskCreateRestricted_core0       | 2. TCB - Dynamic, Stack - Static  |                  |           |
 * +-----|---------|--------|-----------------------------|-----------------------------------|------------------|-----------|
 * | 1   | 1       | 1      | xTaskCreate_core0,                | 1. TCB - Dynamic, Stack - Dynamic | Yes              | Yes       |
 * |     |         |        | xTaskCreateStatic_core0,          | 2. TCB - Dynamic, Stack - Static  |                  |           |
 * |     |         |        | xTaskCreateRestricted_core0,      | 3. TCB - Static, Stack - Static   |                  |           |
 * |     |         |        | xTaskCreateRestrictedStatic_core0 |                                   |                  |           |
 * +-----+---------+--------+-----------------------------+-----------------------------------+------------------+-----------+
 */
#define tskSTATIC_AND_DYNAMIC_ALLOCATION_POSSIBLE_core0                                                                                     \
    ( ( ( portUSING_MPU_WRAPPERS_core0 == 0 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 ) ) || \
      ( ( portUSING_MPU_WRAPPERS_core0 == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 ) ) )

/*
 * In line with software engineering best practice, FreeRTOS_core0 implements a strict
 * data hiding policy, so the real structures used by FreeRTOS_core0 to maintain the
 * state of tasks, queues, semaphores, etc. are not accessible to the application
 * code.  However, if the application writer wants to statically allocate such
 * an object then the size of the object needs to be known.  Dummy structures
 * that are guaranteed to have the same size and alignment requirements of the
 * real objects are used for this purpose.  The dummy list and list item
 * structures below are used for inclusion in such a dummy structure.
 */
struct xSTATIC_LIST_ITEM_core0
{
    #if ( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core0 == 1 )
        TickType_t_core0 xDummy1_core0;
    #endif
    TickType_t_core0 xDummy2_core0;
    void * pvDummy3_core0[ 4 ];
    #if ( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core0 == 1 )
        TickType_t_core0 xDummy4_core0;
    #endif
};
typedef struct xSTATIC_LIST_ITEM_core0 StaticListItem_t_core0;

#if ( configUSE_MINI_LIST_ITEM_core0 == 1 )
    /* See the comments above the struct xSTATIC_LIST_ITEM_core0 definition. */
    struct xSTATIC_MINI_LIST_ITEM_core0
    {
        #if ( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core0 == 1 )
            TickType_t_core0 xDummy1_core0;
        #endif
        TickType_t_core0 xDummy2_core0;
        void * pvDummy3_core0[ 2 ];
    };
    typedef struct xSTATIC_MINI_LIST_ITEM_core0 StaticMiniListItem_t_core0;
#else /* if ( configUSE_MINI_LIST_ITEM_core0 == 1 ) */
    typedef struct xSTATIC_LIST_ITEM_core0      StaticMiniListItem_t_core0;
#endif /* if ( configUSE_MINI_LIST_ITEM_core0 == 1 ) */

/* See the comments above the struct xSTATIC_LIST_ITEM_core0 definition. */
typedef struct xSTATIC_LIST_core0
{
    #if ( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core0 == 1 )
        TickType_t_core0 xDummy1_core0;
    #endif
    UBaseType_t_core0 uxDummy2_core0;
    void * pvDummy3_core0;
    StaticMiniListItem_t_core0 xDummy4_core0;
    #if ( configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core0 == 1 )
        TickType_t_core0 xDummy5_core0;
    #endif
} StaticList_t_core0;

/*
 * In line with software engineering best practice, especially when supplying a
 * library that is likely to change in future versions, FreeRTOS_core0 implements a
 * strict data hiding policy.  This means the Task structure used internally by
 * FreeRTOS_core0 is not accessible to application code.  However, if the application
 * writer wants to statically allocate the memory required to create a task_core0 then
 * the size of the task_core0 object needs to be known.  The StaticTask_t_core0 structure
 * below is provided for this purpose.  Its sizes and alignment requirements are
 * guaranteed to match those of the genuine structure, no matter which
 * architecture is being used, and no matter how the values in FreeRTOSConfig.h
 * are set.  Its contents are somewhat obfuscated in the hope users will
 * recognise that it would be unwise to make direct use of the structure members.
 */
typedef struct xSTATIC_TCB
{
    void * pxDummy1;
    #if ( portUSING_MPU_WRAPPERS_core0 == 1 )
        xMPU_SETTINGS_core0 xDummy2_core0;
    #endif
    StaticListItem_t_core0 xDummy3_core0[ 2 ];
    UBaseType_t_core0 uxDummy5_core0;
    void * pxDummy6_core0;
    uint8_t ucDummy7_core0[ configMAX_TASK_NAME_LEN_core0 ];
    #if ( ( portSTACK_GROWTH_core0 > 0 ) || ( configRECORD_STACK_HIGH_ADDRESS_core0 == 1 ) )
        void * pxDummy8_core0;
    #endif
    #if ( portCRITICAL_NESTING_IN_TCB_core0 == 1 )
        UBaseType_t_core0 uxDummy9_core0;
    #endif
    #if ( configUSE_TRACE_FACILITY_core0 == 1 )
        UBaseType_t_core0 uxDummy10_core0[ 2 ];
    #endif
    #if ( configUSE_MUTEXES_core0 == 1 )
        UBaseType_t_core0 uxDummy12_core0[ 2 ];
    #endif
    #if ( configUSE_APPLICATION_TASK_TAG_core0 == 1 )
        void * pxDummy14_core0;
    #endif
    #if ( configNUM_THREAD_LOCAL_STORAGE_POINTERS_core0 > 0 )
        void * pvDummy15_core0[ configNUM_THREAD_LOCAL_STORAGE_POINTERS_core0 ];
    #endif
    #if ( configGENERATE_RUN_TIME_STATS_core0 == 1 )
        configRUN_TIME_COUNTER_TYPE_core0 ulDummy16_core0;
    #endif
    #if ( ( configUSE_NEWLIB_REENTRANT_core0 == 1 ) || ( configUSE_C_RUNTIME_TLS_SUPPORT_core0 == 1 ) )
        configTLS_BLOCK_TYPE_core0 xDummy17_core0;
    #endif
    #if ( configUSE_TASK_NOTIFICATIONS_core0 == 1 )
        uint32_t ulDummy18_core0[ configTASK_NOTIFICATION_ARRAY_ENTRIES_core0 ];
        uint8_t ucDummy19_core0[ configTASK_NOTIFICATION_ARRAY_ENTRIES_core0 ];
    #endif
    #if ( tskSTATIC_AND_DYNAMIC_ALLOCATION_POSSIBLE_core0 != 0 )
        uint8_t uxDummy20_core0;
    #endif

    #if ( INCLUDE_xTaskAbortDelay_core0 == 1 )
        uint8_t ucDummy21_core0;
    #endif
    #if ( configUSE_POSIX_ERRNO_core0 == 1 )
        int iDummy22_core0;
    #endif
} StaticTask_t_core0;

/*
 * In line with software engineering best practice, especially when supplying a
 * library that is likely to change in future versions, FreeRTOS_core0 implements a
 * strict data hiding policy.  This means the Queue structure used internally by
 * FreeRTOS_core0 is not accessible to application code.  However, if the application
 * writer wants to statically allocate the memory required to create a queue
 * then the size of the queue object needs to be known.  The StaticQueue_t_core0
 * structure below is provided for this purpose.  Its sizes and alignment
 * requirements are guaranteed to match those of the genuine structure, no
 * matter which architecture is being used, and no matter how the values in
 * FreeRTOSConfig.h are set.  Its contents are somewhat obfuscated in the hope
 * users will recognise that it would be unwise to make direct use of the
 * structure members.
 */
typedef struct xSTATIC_QUEUE_core0
{
    void * pvDummy1_core0[ 3 ];

    union
    {
        void * pvDummy2_core0;
        UBaseType_t_core0 uxDummy2_core0;
    } u;

    StaticList_t_core0 xDummy3_core0[ 2 ];
    UBaseType_t_core0 uxDummy4_core0[ 3 ];
    uint8_t ucDummy5_core0[ 2 ];

    #if ( ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 ) )
        uint8_t ucDummy6_core0;
    #endif

    #if ( configUSE_QUEUE_SETS_core0 == 1 )
        void * pvDummy7_core0;
    #endif

    #if ( configUSE_TRACE_FACILITY_core0 == 1 )
        UBaseType_t_core0 uxDummy8_core0;
        uint8_t ucDummy9_core0;
    #endif
} StaticQueue_t_core0;
typedef StaticQueue_t_core0 StaticSemaphore_t_core0;

/*
 * In line with software engineering best practice, especially when supplying a
 * library that is likely to change in future versions, FreeRTOS_core0 implements a
 * strict data hiding policy.  This means the event group structure used
 * internally by FreeRTOS_core0 is not accessible to application code.  However, if
 * the application writer wants to statically allocate the memory required to
 * create an event group then the size of the event group object needs to be
 * know.  The StaticEventGroup_t_core0 structure below is provided for this purpose.
 * Its sizes and alignment requirements are guaranteed to match those of the
 * genuine structure, no matter which architecture is being used, and no matter
 * how the values in FreeRTOSConfig.h are set.  Its contents are somewhat
 * obfuscated in the hope users will recognise that it would be unwise to make
 * direct use of the structure members.
 */
typedef struct xSTATIC_EVENT_GROUP_core0
{
    TickType_t_core0 xDummy1_core0;
    StaticList_t_core0 xDummy2_core0;

    #if ( configUSE_TRACE_FACILITY_core0 == 1 )
        UBaseType_t_core0 uxDummy3_core0;
    #endif

    #if ( ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 ) )
        uint8_t ucDummy4_core0;
    #endif
} StaticEventGroup_t_core0;

/*
 * In line with software engineering best practice, especially when supplying a
 * library that is likely to change in future versions, FreeRTOS_core0 implements a
 * strict data hiding policy.  This means the software timer structure used
 * internally by FreeRTOS_core0 is not accessible to application code.  However, if
 * the application writer wants to statically allocate the memory required to
 * create a software timer then the size of the queue object needs to be known.
 * The StaticTimer_t_core0 structure below is provided for this purpose.  Its sizes
 * and alignment requirements are guaranteed to match those of the genuine
 * structure, no matter which architecture is being used, and no matter how the
 * values in FreeRTOSConfig.h are set.  Its contents are somewhat obfuscated in
 * the hope users will recognise that it would be unwise to make direct use of
 * the structure members.
 */
typedef struct xSTATIC_TIMER_core0
{
    void * pvDummy1_core0;
    StaticListItem_t_core0 xDummy2_core0;
    TickType_t_core0 xDummy3_core0;
    void * pvDummy5_core0;
    TaskFunction_t_core0 pvDummy6_core0;
    #if ( configUSE_TRACE_FACILITY_core0 == 1 )
        UBaseType_t_core0 uxDummy7_core0;
    #endif
    uint8_t ucDummy8_core0;
} StaticTimer_t_core0;

/*
 * In line with software engineering best practice, especially when supplying a
 * library that is likely to change in future versions, FreeRTOS_core0 implements a
 * strict data hiding policy.  This means the stream buffer structure used
 * internally by FreeRTOS_core0 is not accessible to application code.  However, if
 * the application writer wants to statically allocate the memory required to
 * create a stream buffer then the size of the stream buffer object needs to be
 * known.  The StaticStreamBuffer_t_core0 structure below is provided for this
 * purpose.  Its size and alignment requirements are guaranteed to match those
 * of the genuine structure, no matter which architecture is being used, and
 * no matter how the values in FreeRTOSConfig.h are set.  Its contents are
 * somewhat obfuscated in the hope users will recognise that it would be unwise
 * to make direct use of the structure members.
 */
typedef struct xSTATIC_STREAM_BUFFER_core0
{
    size_t uxDummy1_core0[ 4 ];
    void * pvDummy2_core0[ 3 ];
    uint8_t ucDummy3_core0;
    #if ( configUSE_TRACE_FACILITY_core0 == 1 )
        UBaseType_t_core0 uxDummy4_core0;
    #endif
    #if ( configUSE_SB_COMPLETED_CALLBACK_core0 == 1 )
        void * pvDummy5_core0[ 2 ];
    #endif
} StaticStreamBuffer_t_core0;

/* Message buffers are built on stream buffers. */
typedef StaticStreamBuffer_t_core0 StaticMessageBuffer_t;

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* INC_FREERTOS_H */
