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
#include "FreeRTOS_core1.h"

#ifndef INC_TASK_CORE1_H
#define INC_TASK_CORE1_H

#ifndef INC_FREERTOS_CORE1_H
    #error "include FreeRTOS_core1.h must appear in source files before include task_core1.h"
#endif

#include "list_core1.h"

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

/*-----------------------------------------------------------
* MACROS AND DEFINITIONS
*----------------------------------------------------------*/

/*
 * If tskKERNEL_VERSION_NUMBER_core1 ends with + it represents the version in development
 * after the numbered release.
 *
 * The tskKERNEL_VERSION_MAJOR_core1, tskKERNEL_VERSION_MINOR_core1, tskKERNEL_VERSION_BUILD_core1
 * values will reflect the last released version number.
 */
#define tskKERNEL_VERSION_NUMBER_core1       "V10.5.1"
#define tskKERNEL_VERSION_MAJOR_core1        10
#define tskKERNEL_VERSION_MINOR_core1        5
#define tskKERNEL_VERSION_BUILD_core1        1

/* MPU region parameters passed in ulParameters_core1
 * of MemoryRegion_t_core1 struct. */
#define tskMPU_REGION_READ_ONLY_core1        ( 1UL << 0UL )
#define tskMPU_REGION_READ_WRITE_core1       ( 1UL << 1UL )
#define tskMPU_REGION_EXECUTE_NEVER_core1    ( 1UL << 2UL )
#define tskMPU_REGION_NORMAL_MEMORY_core1    ( 1UL << 3UL )
#define tskMPU_REGION_DEVICE_MEMORY_core1    ( 1UL << 4UL )

/* The direct to task_core1 notification feature used to have only a single notification
 * per task_core1.  Now there is an array of notifications per task_core1 that is dimensioned by
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.  For backward compatibility, any use of the
 * original direct to task_core1 notification defaults to using the first index in the
 * array. */
#define tskDEFAULT_INDEX_TO_NOTIFY_core1     ( 0 )

/**
 * task_core1. h
 *
 * Type by which tasks are referenced.  For example, a call to xTaskCreate_core1
 * returns (via a pointer parameter) an TaskHandle_t_core1 variable that can then
 * be used as a parameter to vTaskDelete_core1 to delete the task_core1.
 *
 * \defgroup TaskHandle_t_core1 TaskHandle_t_core1
 * \ingroup Tasks
 */
struct tskTaskControlBlock_core1; /* The old naming convention is used to prevent breaking kernel aware debuggers. */
typedef struct tskTaskControlBlock_core1 * TaskHandle_t_core1;

/*
 * Defines the prototype to which the application task_core1 hook function must
 * conform.
 */
typedef BaseType_t_core1 (* TaskHookFunction_t_core1)( void * );

/* Task states returned by eTaskGetState_core1. */
typedef enum
{
    eRunning_core1 = 0, /* A task_core1 is querying the state of itself, so must be running. */
    eReady_core1,       /* The task_core1 being queried is in a ready or pending ready list. */
    eBlocked_core1,     /* The task_core1 being queried is in the Blocked state. */
    eSuspended_core1,   /* The task_core1 being queried is in the Suspended state, or is in the Blocked state with an infinite time out. */
    eDeleted_core1,     /* The task_core1 being queried has been deleted, but its TCB has not yet been freed. */
    eInvalid_core1      /* Used as an 'invalid state' value. */
} eTaskState_core1;

/* Actions that can be performed when vTaskNotify() is called. */
typedef enum
{
    eNoAction_core1 = 0,            /* Notify the task_core1 without updating its notify value. */
    eSetBits_core1,                 /* Set bits in the task_core1's notification value. */
    eIncrement_core1,               /* Increment the task_core1's notification value. */
    eSetValueWithOverwrite_core1,   /* Set the task_core1's notification value to a specific value even if the previous value has not yet been read by the task_core1. */
    eSetValueWithoutOverwrite_core1 /* Set the task_core1's notification value if the previous value has been read by the task_core1. */
} eNotifyAction_core1;

/*
 * Used internally only.
 */
typedef struct xTIME_OUT_core1
{
    BaseType_t_core1 xOverflowCount_core1;
    TickType_t_core1 xTimeOnEntering_core1;
} TimeOut_t_core1;

/*
 * Defines the memory ranges allocated to the task_core1 when an MPU is used.
 */
typedef struct xMEMORY_REGION_core1
{
    void * pvBaseAddress_core1;
    uint32_t ulLengthInBytes_core1;
    uint32_t ulParameters_core1;
} MemoryRegion_t_core1;

/*
 * Parameters required to create an MPU protected task_core1.
 */
typedef struct xTASK_PARAMETERS_core1
{
    TaskFunction_t_core1 pvTaskCode_core1;
    const char * pcName_core1; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
    uint16_t usStackDepth_core1;
    void * pvParameters_core1;
    UBaseType_t_core1 uxPriority_core1;
    StackType_t_core1 * puxStackBuffer_core1;
    MemoryRegion_t_core1 xRegions_core1[ portNUM_CONFIGURABLE_REGIONS_core1 ];
    #if ( ( portUSING_MPU_WRAPPERS_core1 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 ) )
        StaticTask_t_core1 * const pxTaskBuffer_core1;
    #endif
} TaskParameters_t_core1;

/* Used with the uxTaskGetSystemState_core1() function to return the state of each task_core1
 * in the system. */
typedef struct xTASK_STATUS_core1
{
    TaskHandle_t_core1 xHandle_core1;                         /* The handle of the task_core1 to which the rest of the information in the structure relates. */
    const char * pcTaskName_core1;                      	  /* A pointer to the task_core1's name.  This value will be invalid if the task_core1 was deleted since the structure was populated! */ /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
    UBaseType_t_core1 xTaskNumber_core1;                      /* A number unique to the task_core1. */
    eTaskState_core1 eCurrentState_core1;                     /* The state in which the task_core1 existed when the structure was populated. */
    UBaseType_t_core1 uxCurrentPriority_core1;                /* The priority at which the task_core1 was running (may be inherited) when the structure was populated. */
    UBaseType_t_core1 uxBasePriority_core1;                   /* The priority to which the task_core1 will return if the task_core1's current priority has been inherited to avoid unbounded priority inversion when obtaining a mutex.  Only valid if configUSE_MUTEXES_core1 is defined as 1 in FreeRTOSConfig.h. */
    configRUN_TIME_COUNTER_TYPE_core1 ulRunTimeCounter_core1; /* The total run time allocated to the task_core1 so far, as defined by the run time stats clock.  See https://www.FreeRTOS_core1.org/rtos-run-time-stats.html.  Only valid when configGENERATE_RUN_TIME_STATS_core1 is defined as 1 in FreeRTOSConfig.h. */
    StackType_t_core1 * pxStackBase_core1;                    /* Points to the lowest address of the task_core1's stack area. */
    #if ( ( portSTACK_GROWTH_core1 > 0 ) && ( configRECORD_STACK_HIGH_ADDRESS_core1 == 1 ) )
        StackType_t_core1 * pxTopOfStack_core1;               /* Points to the top address of the task_core1's stack area. */
        StackType_t_core1 * pxEndOfStack_core1;               /* Points to the end address of the task_core1's stack area. */
    #endif
    configSTACK_DEPTH_TYPE_core1 usStackHighWaterMark_core1;  /* The minimum amount of stack space that has remained for the task_core1 since the task_core1 was created.  The closer this value is to zero the closer the task_core1 has come to overflowing its stack. */
} TaskStatus_t_core1;

/* Possible return values for eTaskConfirmSleepModeStatus_core1(). */
typedef enum
{
    eAbortSleep_core1 = 0,           /* A task_core1 has been made ready or a context switch pended since portSUPPRESS_TICKS_AND_SLEEP_core1() was called - abort entering a sleep mode. */
    eStandardSleep_core1,            /* Enter a sleep mode that will not last any longer than the expected idle time. */
    #if ( INCLUDE_vTaskSuspend_core1 == 1 )
        eNoTasksWaitingTimeout_core1 /* No tasks are waiting for a timeout so it is safe to enter a sleep mode that can only be exited by an external interrupt. */
    #endif /* INCLUDE_vTaskSuspend_core1 */
} eSleepModeStatus_core1;

/**
 * Defines the priority used by the idle task_core1.  This must not be modified.
 *
 * \ingroup TaskUtils
 */
#define tskIDLE_PRIORITY_core1    ( ( UBaseType_t_core1 ) 0U )

/**
 * task_core1. h
 *
 * Macro for forcing a context switch.
 *
 * \defgroup taskYIELD_core1 taskYIELD_core1
 * \ingroup SchedulerControl
 */
#define taskYIELD_core1()                        portYIELD_core1()

/**
 * task_core1. h
 *
 * Macro to mark the start of a critical code region.  Preemptive context
 * switches cannot occur when in a critical region.
 *
 * NOTE: This may alter the stack (depending on the portable implementation)
 * so must be used with care!
 *
 * \defgroup taskENTER_CRITICAL_core1 taskENTER_CRITICAL_core1
 * \ingroup SchedulerControl
 */
#define taskENTER_CRITICAL_core1()               portENTER_CRITICAL_core1()
#define taskENTER_CRITICAL_FROM_ISR_core1()      portSET_INTERRUPT_MASK_FROM_ISR_core1()

/**
 * task_core1. h
 *
 * Macro to mark the end of a critical code region.  Preemptive context
 * switches cannot occur when in a critical region.
 *
 * NOTE: This may alter the stack (depending on the portable implementation)
 * so must be used with care!
 *
 * \defgroup taskEXIT_CRITICAL_core1 taskEXIT_CRITICAL_core1
 * \ingroup SchedulerControl
 */
#define taskEXIT_CRITICAL_core1()                portEXIT_CRITICAL_core1()
#define taskEXIT_CRITICAL_FROM_ISR_core1( x_core1 )    portCLEAR_INTERRUPT_MASK_FROM_ISR_core1( x_core1 )

/**
 * task_core1. h
 *
 * Macro to disable all maskable interrupts.
 *
 * \defgroup taskDISABLE_INTERRUPTS_core1 taskDISABLE_INTERRUPTS_core1
 * \ingroup SchedulerControl
 */
#define taskDISABLE_INTERRUPTS_core1()           portDISABLE_INTERRUPTS_core1()

/**
 * task_core1. h
 *
 * Macro to enable microcontroller interrupts.
 *
 * \defgroup taskENABLE_INTERRUPTS_core1 taskENABLE_INTERRUPTS_core1
 * \ingroup SchedulerControl
 */
#define taskENABLE_INTERRUPTS_core1()            portENABLE_INTERRUPTS_core1()

/* Definitions returned by xTaskGetSchedulerState_core1().  taskSCHEDULER_SUSPENDED_core1 is
 * 0 to generate more optimal code when configASSERT_core1() is defined as the constant
 * is used in assert() statements. */
#define taskSCHEDULER_SUSPENDED_core1      ( ( BaseType_t_core1 ) 0 )
#define taskSCHEDULER_NOT_STARTED_core1    ( ( BaseType_t_core1 ) 1 )
#define taskSCHEDULER_RUNNING_core1        ( ( BaseType_t_core1 ) 2 )


/*-----------------------------------------------------------
* TASK CREATION API
*----------------------------------------------------------*/

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskCreate_core1(
 *                            TaskFunction_t_core1 pxTaskCode_core1,
 *                            const char *pcName_core1,
 *                            configSTACK_DEPTH_TYPE_core1 usStackDepth_core1,
 *                            void *pvParameters_core1,
 *                            UBaseType_t_core1 uxPriority_core1,
 *                            TaskHandle_t_core1 *pxCreatedTask_core1
 *                        );
 * @endcode
 *
 * Create a new task_core1 and add it to the list of tasks that are ready to run.
 *
 * Internally, within the FreeRTOS_core1 implementation, tasks use two blocks of
 * memory.  The first block is used to hold the task_core1's data structures.  The
 * second block is used by the task_core1 as its stack.  If a task_core1 is created using
 * xTaskCreate_core1() then both blocks of memory are automatically dynamically
 * allocated inside the xTaskCreate_core1() function.  (see
 * https://www.FreeRTOS_core1.org/a00111.html).  If a task_core1 is created using
 * xTaskCreateStatic_core1() then the application writer must provide the required
 * memory.  xTaskCreateStatic_core1() therefore allows a task_core1 to be created without
 * using any dynamic memory allocation.
 *
 * See xTaskCreateStatic_core1() for a version that does not use any dynamic memory
 * allocation.
 *
 * xTaskCreate_core1() can only be used to create a task_core1 that has unrestricted
 * access to the entire microcontroller memory map.  Systems that include MPU
 * support can alternatively create an MPU constrained task_core1 using
 * xTaskCreateRestricted_core1().
 *
 * @param pxTaskCode_core1 Pointer to the task_core1 entry function.  Tasks
 * must be implemented to never return (i.e. continuous loop).
 *
 * @param pcName_core1 A descriptive name for the task_core1.  This is mainly used to
 * facilitate debugging.  Max length defined by configMAX_TASK_NAME_LEN_core1 - default
 * is 16.
 *
 * @param usStackDepth_core1 The size of the task_core1 stack specified as the number of
 * variables the stack can hold - not the number of bytes.  For example, if
 * the stack is 16 bits wide and usStackDepth_core1 is defined as 100, 200 bytes
 * will be allocated for stack storage.
 *
 * @param pvParameters_core1 Pointer that will be used as the parameter for the task_core1
 * being created.
 *
 * @param uxPriority_core1 The priority at which the task_core1 should run.  Systems that
 * include MPU support can optionally create tasks in a privileged (system)
 * mode by setting bit portPRIVILEGE_BIT_core1 of the priority parameter.  For
 * example, to create a privileged task_core1 at priority 2 the uxPriority_core1 parameter
 * should be set to ( 2 | portPRIVILEGE_BIT_core1 ).
 *
 * @param pxCreatedTask_core1 Used to pass back a handle by which the created task_core1
 * can be referenced.
 *
 * @return pdPASS_core1 if the task_core1 was successfully created and added to a ready
 * list, otherwise an error code defined in the file projdefs.h
 *
 * Example usage:
 * @code{c}
 * // Task to be created.
 * void vTaskCode( void * pvParameters_core1 )
 * {
 *   for( ;; )
 *   {
 *       // Task code goes here.
 *   }
 * }
 *
 * // Function that creates a task_core1.
 * void vOtherFunction( void )
 * {
 * static uint8_t ucParameterToPass;
 * TaskHandle_t_core1 xHandle_core1 = NULL;
 *
 *   // Create the task_core1, storing the handle.  Note that the passed parameter ucParameterToPass
 *   // must exist for the lifetime of the task_core1, so in this case is declared static.  If it was just an
 *   // an automatic stack variable it might no longer exist, or at least have been corrupted, by the time
 *   // the new task_core1 attempts to access it.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, &ucParameterToPass, tskIDLE_PRIORITY_core1, &xHandle_core1 );
 *   configASSERT_core1( xHandle_core1 );
 *
 *   // Use the handle to delete the task_core1.
 *   if( xHandle_core1 != NULL )
 *   {
 *      vTaskDelete_core1( xHandle_core1 );
 *   }
 * }
 * @endcode
 * \defgroup xTaskCreate_core1 xTaskCreate_core1
 * \ingroup Tasks
 */
#if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )
    BaseType_t_core1 xTaskCreate_core1( TaskFunction_t_core1 pxTaskCode_core1,
                            const char * const pcName_core1, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                            const configSTACK_DEPTH_TYPE_core1 usStackDepth_core1,
                            void * const pvParameters_core1,
                            UBaseType_t_core1 uxPriority_core1,
                            TaskHandle_t_core1 * const pxCreatedTask_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/**
 * task_core1. h
 * @code{c}
 * TaskHandle_t_core1 xTaskCreateStatic_core1( TaskFunction_t_core1 pxTaskCode_core1,
 *                               const char *pcName_core1,
 *                               uint32_t ulStackDepth_core1,
 *                               void *pvParameters_core1,
 *                               UBaseType_t_core1 uxPriority_core1,
 *                               StackType_t_core1 *puxStackBuffer_core1,
 *                               StaticTask_t_core1 *pxTaskBuffer_core1 );
 * @endcode
 *
 * Create a new task_core1 and add it to the list of tasks that are ready to run.
 *
 * Internally, within the FreeRTOS_core1 implementation, tasks use two blocks of
 * memory.  The first block is used to hold the task_core1's data structures.  The
 * second block is used by the task_core1 as its stack.  If a task_core1 is created using
 * xTaskCreate_core1() then both blocks of memory are automatically dynamically
 * allocated inside the xTaskCreate_core1() function.  (see
 * https://www.FreeRTOS_core1.org/a00111.html).  If a task_core1 is created using
 * xTaskCreateStatic_core1() then the application writer must provide the required
 * memory.  xTaskCreateStatic_core1() therefore allows a task_core1 to be created without
 * using any dynamic memory allocation.
 *
 * @param pxTaskCode_core1 Pointer to the task_core1 entry function.  Tasks
 * must be implemented to never return (i.e. continuous loop).
 *
 * @param pcName_core1 A descriptive name for the task_core1.  This is mainly used to
 * facilitate debugging.  The maximum length of the string is defined by
 * configMAX_TASK_NAME_LEN_core1 in FreeRTOSConfig.h.
 *
 * @param ulStackDepth_core1 The size of the task_core1 stack specified as the number of
 * variables the stack can hold - not the number of bytes.  For example, if
 * the stack is 32-bits wide and ulStackDepth_core1 is defined as 100 then 400 bytes
 * will be allocated for stack storage.
 *
 * @param pvParameters_core1 Pointer that will be used as the parameter for the task_core1
 * being created.
 *
 * @param uxPriority_core1 The priority at which the task_core1 will run.
 *
 * @param puxStackBuffer_core1 Must point to a StackType_t_core1 array that has at least
 * ulStackDepth_core1 indexes - the array will then be used as the task_core1's stack,
 * removing the need for the stack to be allocated dynamically.
 *
 * @param pxTaskBuffer_core1 Must point to a variable of type StaticTask_t_core1, which will
 * then be used to hold the task_core1's data structures, removing the need for the
 * memory to be allocated dynamically.
 *
 * @return If neither puxStackBuffer_core1 nor pxTaskBuffer_core1 are NULL, then the task_core1
 * will be created and a handle to the created task_core1 is returned.  If either
 * puxStackBuffer_core1 or pxTaskBuffer_core1 are NULL then the task_core1 will not be created and
 * NULL is returned.
 *
 * Example usage:
 * @code{c}
 *
 *  // Dimensions of the buffer that the task_core1 being created will use as its stack.
 *  // NOTE:  This is the number of words the stack will hold, not the number of
 *  // bytes.  For example, if each stack item is 32-bits, and this is set to 100,
 *  // then 400 bytes (100 * 32-bits) will be allocated.
 #define STACK_SIZE 200
 *
 *  // Structure that will hold the TCB of the task_core1 being created.
 *  StaticTask_t_core1 xTaskBuffer;
 *
 *  // Buffer that the task_core1 being created will use as its stack.  Note this is
 *  // an array of StackType_t_core1 variables.  The size of StackType_t_core1 is dependent on
 *  // the RTOS port.
 *  StackType_t_core1 xStack[ STACK_SIZE ];
 *
 *  // Function that implements the task_core1 being created.
 *  void vTaskCode( void * pvParameters_core1 )
 *  {
 *      // The parameter value is expected to be 1 as 1 is passed in the
 *      // pvParameters_core1 value in the call to xTaskCreateStatic_core1().
 *      configASSERT_core1( ( uint32_t ) pvParameters_core1 == 1UL );
 *
 *      for( ;; )
 *      {
 *          // Task code goes here.
 *      }
 *  }
 *
 *  // Function that creates a task_core1.
 *  void vOtherFunction( void )
 *  {
 *      TaskHandle_t_core1 xHandle_core1 = NULL;
 *
 *      // Create the task_core1 without using any dynamic memory allocation.
 *      xHandle_core1 = xTaskCreateStatic_core1(
 *                    vTaskCode,       // Function that implements the task_core1.
 *                    "NAME",          // Text name for the task_core1.
 *                    STACK_SIZE,      // Stack size in words, not bytes.
 *                    ( void * ) 1,    // Parameter passed into the task_core1.
 *                    tskIDLE_PRIORITY_core1,// Priority at which the task_core1 is created.
 *                    xStack,          // Array to use as the task_core1's stack.
 *                    &xTaskBuffer );  // Variable to hold the task_core1's data structure.
 *
 *      // puxStackBuffer_core1 and pxTaskBuffer_core1 were not NULL, so the task_core1 will have
 *      // been created, and xHandle_core1 will be the task_core1's handle.  Use the handle
 *      // to suspend the task_core1.
 *      vTaskSuspend_core1( xHandle_core1 );
 *  }
 * @endcode
 * \defgroup xTaskCreateStatic_core1 xTaskCreateStatic_core1
 * \ingroup Tasks
 */
#if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )
    TaskHandle_t_core1 xTaskCreateStatic_core1( TaskFunction_t_core1 pxTaskCode_core1,
                                    const char * const pcName_core1, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                    const uint32_t ulStackDepth_core1,
                                    void * const pvParameters_core1,
                                    UBaseType_t_core1 uxPriority_core1,
                                    StackType_t_core1 * const puxStackBuffer_core1,
                                    StaticTask_t_core1 * const pxTaskBuffer_core1 ) PRIVILEGED_FUNCTION_core1;
#endif /* configSUPPORT_STATIC_ALLOCATION_core1 */

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskCreateRestricted_core1( TaskParameters_t_core1 *pxTaskDefinition_core1, TaskHandle_t_core1 *pxCreatedTask_core1 );
 * @endcode
 *
 * Only available when configSUPPORT_DYNAMIC_ALLOCATION_core1 is set to 1.
 *
 * xTaskCreateRestricted_core1() should only be used in systems that include an MPU
 * implementation.
 *
 * Create a new task_core1 and add it to the list of tasks that are ready to run.
 * The function parameters define the memory regions and associated access
 * permissions allocated to the task_core1.
 *
 * See xTaskCreateRestrictedStatic_core1() for a version that does not use any
 * dynamic memory allocation.
 *
 * @param pxTaskDefinition_core1 Pointer to a structure that contains a member
 * for each of the normal xTaskCreate_core1() parameters (see the xTaskCreate_core1() API
 * documentation) plus an optional stack buffer and the memory region
 * definitions.
 *
 * @param pxCreatedTask_core1 Used to pass back a handle by which the created task_core1
 * can be referenced.
 *
 * @return pdPASS_core1 if the task_core1 was successfully created and added to a ready
 * list, otherwise an error code defined in the file projdefs.h
 *
 * Example usage:
 * @code{c}
 * // Create an TaskParameters_t_core1 structure that defines the task_core1 to be created.
 * static const TaskParameters_t_core1 xCheckTaskParameters =
 * {
 *  vATask,     // pvTaskCode_core1 - the function that implements the task_core1.
 *  "ATask",    // pcName_core1 - just a text name for the task_core1 to assist debugging.
 *  100,        // usStackDepth_core1 - the stack size DEFINED IN WORDS.
 *  NULL,       // pvParameters_core1 - passed into the task_core1 function as the function parameters.
 *  ( 1UL | portPRIVILEGE_BIT_core1 ),// uxPriority_core1 - task_core1 priority, set the portPRIVILEGE_BIT_core1 if the task_core1 should run in a privileged state.
 *  cStackBuffer,// puxStackBuffer_core1 - the buffer to be used as the task_core1 stack.
 *
 *  // xRegions_core1 - Allocate up to three separate memory regions for access by
 *  // the task_core1, with appropriate access permissions.  Different processors have
 *  // different memory alignment requirements - refer to the FreeRTOS_core1 documentation
 *  // for full information.
 *  {
 *      // Base address                 Length  Parameters
 *      { cReadWriteArray,              32,     portMPU_REGION_READ_WRITE },
 *      { cReadOnlyArray,               32,     portMPU_REGION_READ_ONLY },
 *      { cPrivilegedOnlyAccessArray,   128,    portMPU_REGION_PRIVILEGED_READ_WRITE }
 *  }
 * };
 *
 * int main( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 *
 *  // Create a task_core1 from the const structure defined above.  The task_core1 handle
 *  // is requested (the second parameter is not NULL) but in this case just for
 *  // demonstration purposes as its not actually used.
 *  xTaskCreateRestricted_core1( &xRegTest1Parameters, &xHandle_core1 );
 *
 *  // Start the scheduler.
 *  vTaskStartScheduler_core1();
 *
 *  // Will only get here if there was insufficient memory to create the idle
 *  // and/or timer task_core1.
 *  for( ;; );
 * }
 * @endcode
 * \defgroup xTaskCreateRestricted_core1 xTaskCreateRestricted_core1
 * \ingroup Tasks
 */
#if ( portUSING_MPU_WRAPPERS_core1 == 1 )
    BaseType_t_core1 xTaskCreateRestricted_core1( const TaskParameters_t_core1 * const pxTaskDefinition_core1,
                                      TaskHandle_t_core1 * pxCreatedTask_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskCreateRestrictedStatic_core1( TaskParameters_t_core1 *pxTaskDefinition_core1, TaskHandle_t_core1 *pxCreatedTask_core1 );
 * @endcode
 *
 * Only available when configSUPPORT_STATIC_ALLOCATION_core1 is set to 1.
 *
 * xTaskCreateRestrictedStatic_core1() should only be used in systems that include an
 * MPU implementation.
 *
 * Internally, within the FreeRTOS_core1 implementation, tasks use two blocks of
 * memory.  The first block is used to hold the task_core1's data structures.  The
 * second block is used by the task_core1 as its stack.  If a task_core1 is created using
 * xTaskCreateRestricted_core1() then the stack is provided by the application writer,
 * and the memory used to hold the task_core1's data structure is automatically
 * dynamically allocated inside the xTaskCreateRestricted_core1() function.  If a task_core1
 * is created using xTaskCreateRestrictedStatic_core1() then the application writer
 * must provide the memory used to hold the task_core1's data structures too.
 * xTaskCreateRestrictedStatic_core1() therefore allows a memory protected task_core1 to be
 * created without using any dynamic memory allocation.
 *
 * @param pxTaskDefinition_core1 Pointer to a structure that contains a member
 * for each of the normal xTaskCreate_core1() parameters (see the xTaskCreate_core1() API
 * documentation) plus an optional stack buffer and the memory region
 * definitions.  If configSUPPORT_STATIC_ALLOCATION_core1 is set to 1 the structure
 * contains an additional member, which is used to point to a variable of type
 * StaticTask_t_core1 - which is then used to hold the task_core1's data structure.
 *
 * @param pxCreatedTask_core1 Used to pass back a handle by which the created task_core1
 * can be referenced.
 *
 * @return pdPASS_core1 if the task_core1 was successfully created and added to a ready
 * list, otherwise an error code defined in the file projdefs.h
 *
 * Example usage:
 * @code{c}
 * // Create an TaskParameters_t_core1 structure that defines the task_core1 to be created.
 * // The StaticTask_t_core1 variable is only included in the structure when
 * // configSUPPORT_STATIC_ALLOCATION_core1 is set to 1.  The PRIVILEGED_DATA_core1 macro can
 * // be used to force the variable into the RTOS kernel's privileged data area.
 * static PRIVILEGED_DATA_core1 StaticTask_t_core1 xTaskBuffer;
 * static const TaskParameters_t_core1 xCheckTaskParameters =
 * {
 *  vATask,     // pvTaskCode_core1 - the function that implements the task_core1.
 *  "ATask",    // pcName_core1 - just a text name for the task_core1 to assist debugging.
 *  100,        // usStackDepth_core1 - the stack size DEFINED IN WORDS.
 *  NULL,       // pvParameters_core1 - passed into the task_core1 function as the function parameters.
 *  ( 1UL | portPRIVILEGE_BIT_core1 ),// uxPriority_core1 - task_core1 priority, set the portPRIVILEGE_BIT_core1 if the task_core1 should run in a privileged state.
 *  cStackBuffer,// puxStackBuffer_core1 - the buffer to be used as the task_core1 stack.
 *
 *  // xRegions_core1 - Allocate up to three separate memory regions for access by
 *  // the task_core1, with appropriate access permissions.  Different processors have
 *  // different memory alignment requirements - refer to the FreeRTOS_core1 documentation
 *  // for full information.
 *  {
 *      // Base address                 Length  Parameters
 *      { cReadWriteArray,              32,     portMPU_REGION_READ_WRITE },
 *      { cReadOnlyArray,               32,     portMPU_REGION_READ_ONLY },
 *      { cPrivilegedOnlyAccessArray,   128,    portMPU_REGION_PRIVILEGED_READ_WRITE }
 *  }
 *
 *  &xTaskBuffer; // Holds the task_core1's data structure.
 * };
 *
 * int main( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 *
 *  // Create a task_core1 from the const structure defined above.  The task_core1 handle
 *  // is requested (the second parameter is not NULL) but in this case just for
 *  // demonstration purposes as its not actually used.
 *  xTaskCreateRestrictedStatic_core1( &xRegTest1Parameters, &xHandle_core1 );
 *
 *  // Start the scheduler.
 *  vTaskStartScheduler_core1();
 *
 *  // Will only get here if there was insufficient memory to create the idle
 *  // and/or timer task_core1.
 *  for( ;; );
 * }
 * @endcode
 * \defgroup xTaskCreateRestrictedStatic_core1 xTaskCreateRestrictedStatic_core1
 * \ingroup Tasks
 */
#if ( ( portUSING_MPU_WRAPPERS_core1 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 ) )
    BaseType_t_core1 xTaskCreateRestrictedStatic_core1( const TaskParameters_t_core1 * const pxTaskDefinition_core1,
                                            TaskHandle_t_core1 * pxCreatedTask_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/**
 * task_core1. h
 * @code{c}
 * void vTaskAllocateMPURegions_core1( TaskHandle_t_core1 xTask_core1, const MemoryRegion_t_core1 * const pxRegions_core1 );
 * @endcode
 *
 * Memory regions are assigned to a restricted task_core1 when the task_core1 is created by
 * a call to xTaskCreateRestricted_core1().  These regions can be redefined using
 * vTaskAllocateMPURegions_core1().
 *
 * @param xTask_core1 The handle of the task_core1 being updated.
 *
 * @param xRegions_core1 A pointer to a MemoryRegion_t_core1 structure that contains the
 * new memory region definitions.
 *
 * Example usage:
 * @code{c}
 * // Define an array of MemoryRegion_t_core1 structures that configures an MPU region
 * // allowing read/write access for 1024 bytes starting at the beginning of the
 * // ucOneKByte array.  The other two of the maximum 3 definable regions are
 * // unused so set to zero.
 * static const MemoryRegion_t_core1 xAltRegions[ portNUM_CONFIGURABLE_REGIONS_core1 ] =
 * {
 *  // Base address     Length      Parameters
 *  { ucOneKByte,       1024,       portMPU_REGION_READ_WRITE },
 *  { 0,                0,          0 },
 *  { 0,                0,          0 }
 * };
 *
 * void vATask( void *pvParameters_core1 )
 * {
 *  // This task_core1 was created such that it has access to certain regions of
 *  // memory as defined by the MPU configuration.  At some point it is
 *  // desired that these MPU regions are replaced with that defined in the
 *  // xAltRegions const struct above.  Use a call to vTaskAllocateMPURegions_core1()
 *  // for this purpose.  NULL is used as the task_core1 handle to indicate that this
 *  // function should modify the MPU regions of the calling task_core1.
 *  vTaskAllocateMPURegions_core1( NULL, xAltRegions );
 *
 *  // Now the task_core1 can continue its function, but from this point on can only
 *  // access its stack and the ucOneKByte array (unless any other statically
 *  // defined or shared regions have been declared elsewhere).
 * }
 * @endcode
 * \defgroup vTaskAllocateMPURegions_core1 vTaskAllocateMPURegions_core1
 * \ingroup Tasks
 */
void vTaskAllocateMPURegions_core1( TaskHandle_t_core1 xTask_core1,
                              const MemoryRegion_t_core1 * const pxRegions_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskDelete_core1( TaskHandle_t_core1 xTaskToDelete_core1 );
 * @endcode
 *
 * INCLUDE_vTaskDelete_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 * Remove a task_core1 from the RTOS real time kernel's management.  The task_core1 being
 * deleted will be removed from all ready, blocked, suspended and event lists.
 *
 * NOTE:  The idle task_core1 is responsible for freeing the kernel allocated
 * memory from tasks that have been deleted.  It is therefore important that
 * the idle task_core1 is not starved of microcontroller processing time if your
 * application makes any calls to vTaskDelete_core1 ().  Memory allocated by the
 * task_core1 code is not automatically freed, and should be freed before the task_core1
 * is deleted.
 *
 * See the demo application file death.c for sample code that utilises
 * vTaskDelete_core1 ().
 *
 * @param xTaskToDelete_core1 The handle of the task_core1 to be deleted.  Passing NULL will
 * cause the calling task_core1 to be deleted.
 *
 * Example usage:
 * @code{c}
 * void vOtherFunction( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 *
 *   // Create the task_core1, storing the handle.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY_core1, &xHandle_core1 );
 *
 *   // Use the handle to delete the task_core1.
 *   vTaskDelete_core1( xHandle_core1 );
 * }
 * @endcode
 * \defgroup vTaskDelete_core1 vTaskDelete_core1
 * \ingroup Tasks
 */
void vTaskDelete_core1( TaskHandle_t_core1 xTaskToDelete_core1 ) PRIVILEGED_FUNCTION_core1;

/*-----------------------------------------------------------
* TASK CONTROL API
*----------------------------------------------------------*/

/**
 * task_core1. h
 * @code{c}
 * void vTaskDelay_core1( const TickType_t_core1 xTicksToDelay_core1 );
 * @endcode
 *
 * Delay a task_core1 for a given number of ticks.  The actual time that the
 * task_core1 remains blocked depends on the tick rate.  The constant
 * portTICK_PERIOD_MS_core1 can be used to calculate real time from the tick
 * rate - with the resolution of one tick period.
 *
 * INCLUDE_vTaskDelay_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 *
 * vTaskDelay_core1() specifies a time at which the task_core1 wishes to unblock relative to
 * the time at which vTaskDelay_core1() is called.  For example, specifying a block
 * period of 100 ticks will cause the task_core1 to unblock 100 ticks after
 * vTaskDelay_core1() is called.  vTaskDelay_core1() does not therefore provide a good method
 * of controlling the frequency of a periodic task_core1 as the path taken through the
 * code, as well as other task_core1 and interrupt activity, will affect the frequency
 * at which vTaskDelay_core1() gets called and therefore the time at which the task_core1
 * next executes.  See xTaskDelayUntil_core1() for an alternative API function designed
 * to facilitate fixed frequency execution.  It does this by specifying an
 * absolute time (rather than a relative time) at which the calling task_core1 should
 * unblock.
 *
 * @param xTicksToDelay_core1 The amount of time, in tick periods, that
 * the calling task_core1 should block.
 *
 * Example usage:
 *
 * void vTaskFunction( void * pvParameters_core1 )
 * {
 * // Block for 500ms.
 * const TickType_t_core1 xDelay = 500 / portTICK_PERIOD_MS_core1;
 *
 *   for( ;; )
 *   {
 *       // Simply toggle the LED every 500ms, blocking between each toggle.
 *       vToggleLED();
 *       vTaskDelay_core1( xDelay );
 *   }
 * }
 *
 * \defgroup vTaskDelay_core1 vTaskDelay_core1
 * \ingroup TaskCtrl
 */
void vTaskDelay_core1( const TickType_t_core1 xTicksToDelay_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskDelayUntil_core1( TickType_t_core1 *pxPreviousWakeTime_core1, const TickType_t_core1 xTimeIncrement_core1 );
 * @endcode
 *
 * INCLUDE_xTaskDelayUntil_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 * Delay a task_core1 until a specified time.  This function can be used by periodic
 * tasks to ensure a constant execution frequency.
 *
 * This function differs from vTaskDelay_core1 () in one important aspect:  vTaskDelay_core1 () will
 * cause a task_core1 to block for the specified number of ticks from the time vTaskDelay_core1 () is
 * called.  It is therefore difficult to use vTaskDelay_core1 () by itself to generate a fixed
 * execution frequency as the time between a task_core1 starting to execute and that task_core1
 * calling vTaskDelay_core1 () may not be fixed [the task_core1 may take a different path though the
 * code between calls, or may get interrupted or preempted a different number of times
 * each time it executes].
 *
 * Whereas vTaskDelay_core1 () specifies a wake time relative to the time at which the function
 * is called, xTaskDelayUntil_core1 () specifies the absolute (exact) time at which it wishes to
 * unblock.
 *
 * The macro pdMS_TO_TICKS_core1() can be used to calculate the number of ticks from a
 * time specified in milliseconds with a resolution of one tick period.
 *
 * @param pxPreviousWakeTime_core1 Pointer to a variable that holds the time at which the
 * task_core1 was last unblocked.  The variable must be initialised with the current time
 * prior to its first use (see the example below).  Following this the variable is
 * automatically updated within xTaskDelayUntil_core1 ().
 *
 * @param xTimeIncrement_core1 The cycle time period.  The task_core1 will be unblocked at
 * time *pxPreviousWakeTime_core1 + xTimeIncrement_core1.  Calling xTaskDelayUntil_core1 with the
 * same xTimeIncrement_core1 parameter value will cause the task_core1 to execute with
 * a fixed interface period.
 *
 * @return Value which can be used to check whether the task_core1 was actually delayed.
 * Will be pdTRUE_core1 if the task_core1 way delayed and pdFALSE_core1 otherwise.  A task_core1 will not
 * be delayed if the next expected wake time is in the past.
 *
 * Example usage:
 * @code{c}
 * // Perform an action every 10 ticks.
 * void vTaskFunction( void * pvParameters_core1 )
 * {
 * TickType_t_core1 xLastWakeTime;
 * const TickType_t_core1 xFrequency = 10;
 * BaseType_t_core1 xWasDelayed;
 *
 *     // Initialise the xLastWakeTime variable with the current time.
 *     xLastWakeTime = xTaskGetTickCount_core1 ();
 *     for( ;; )
 *     {
 *         // Wait for the next cycle.
 *         xWasDelayed = xTaskDelayUntil_core1( &xLastWakeTime, xFrequency );
 *
 *         // Perform action here. xWasDelayed value can be used to determine
 *         // whether a deadline was missed if the code here took too long.
 *     }
 * }
 * @endcode
 * \defgroup xTaskDelayUntil_core1 xTaskDelayUntil_core1
 * \ingroup TaskCtrl
 */
BaseType_t_core1 xTaskDelayUntil_core1( TickType_t_core1 * const pxPreviousWakeTime_core1,
                            const TickType_t_core1 xTimeIncrement_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * vTaskDelayUntil_core1() is the older version of xTaskDelayUntil_core1() and does not
 * return a value.
 */
#define vTaskDelayUntil_core1( pxPreviousWakeTime_core1, xTimeIncrement_core1 )                   \
    do {                                                                        \
        ( void ) xTaskDelayUntil_core1( ( pxPreviousWakeTime_core1 ), ( xTimeIncrement_core1 ) ); \
    } while( 0 )


/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskAbortDelay_core1( TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * INCLUDE_xTaskAbortDelay_core1 must be defined as 1 in FreeRTOSConfig.h for this
 * function to be available.
 *
 * A task_core1 will enter the Blocked state when it is waiting for an event.  The
 * event it is waiting for can be a temporal event (waiting for a time), such
 * as when vTaskDelay_core1() is called, or an event on an object, such as when
 * xQueueReceive_core1() or ulTaskNotifyTake_core1() is called.  If the handle of a task_core1
 * that is in the Blocked state is used in a call to xTaskAbortDelay_core1() then the
 * task_core1 will leave the Blocked state, and return from whichever function call
 * placed the task_core1 into the Blocked state.
 *
 * There is no 'FromISR' version of this function as an interrupt would need to
 * know which object a task_core1 was blocked on in order to know which actions to
 * take.  For example, if the task_core1 was blocked on a queue the interrupt handler
 * would then need to know if the queue was locked.
 *
 * @param xTask_core1 The handle of the task_core1 to remove from the Blocked state.
 *
 * @return If the task_core1 referenced by xTask_core1 was not in the Blocked state then
 * pdFAIL_core1 is returned.  Otherwise pdPASS_core1 is returned.
 *
 * \defgroup xTaskAbortDelay_core1 xTaskAbortDelay_core1
 * \ingroup TaskCtrl
 */
BaseType_t_core1 xTaskAbortDelay_core1( TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * UBaseType_t_core1 uxTaskPriorityGet_core1( const TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * INCLUDE_uxTaskPriorityGet_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 * Obtain the priority of any task_core1.
 *
 * @param xTask_core1 Handle of the task_core1 to be queried.  Passing a NULL
 * handle results in the priority of the calling task_core1 being returned.
 *
 * @return The priority of xTask_core1.
 *
 * Example usage:
 * @code{c}
 * void vAFunction( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 *
 *   // Create a task_core1, storing the handle.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY_core1, &xHandle_core1 );
 *
 *   // ...
 *
 *   // Use the handle to obtain the priority of the created task_core1.
 *   // It was created with tskIDLE_PRIORITY_core1, but may have changed
 *   // it itself.
 *   if( uxTaskPriorityGet_core1( xHandle_core1 ) != tskIDLE_PRIORITY_core1 )
 *   {
 *       // The task_core1 has changed it's priority.
 *   }
 *
 *   // ...
 *
 *   // Is our priority higher than the created task_core1?
 *   if( uxTaskPriorityGet_core1( xHandle_core1 ) < uxTaskPriorityGet_core1( NULL ) )
 *   {
 *       // Our priority (obtained using NULL handle) is higher.
 *   }
 * }
 * @endcode
 * \defgroup uxTaskPriorityGet_core1 uxTaskPriorityGet_core1
 * \ingroup TaskCtrl
 */
UBaseType_t_core1 uxTaskPriorityGet_core1( const TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * UBaseType_t_core1 uxTaskPriorityGetFromISR_core1( const TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * A version of uxTaskPriorityGet_core1() that can be used from an ISR.
 */
UBaseType_t_core1 uxTaskPriorityGetFromISR_core1( const TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * eTaskState_core1 eTaskGetState_core1( TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * INCLUDE_eTaskGetState_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 * Obtain the state of any task_core1.  States are encoded by the eTaskState_core1
 * enumerated type.
 *
 * @param xTask_core1 Handle of the task_core1 to be queried.
 *
 * @return The state of xTask_core1 at the time the function was called.  Note the
 * state of the task_core1 might change between the function being called, and the
 * functions return value being tested by the calling task_core1.
 */
eTaskState_core1 eTaskGetState_core1( TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskGetInfo_core1( TaskHandle_t_core1 xTask_core1, TaskStatus_t_core1 *pxTaskStatus_core1, BaseType_t_core1 xGetFreeStackSpace_core1, eTaskState_core1 eState_core1 );
 * @endcode
 *
 * configUSE_TRACE_FACILITY_core1 must be defined as 1 for this function to be
 * available.  See the configuration section for more information.
 *
 * Populates a TaskStatus_t_core1 structure with information about a task_core1.
 *
 * @param xTask_core1 Handle of the task_core1 being queried.  If xTask_core1 is NULL then
 * information will be returned about the calling task_core1.
 *
 * @param pxTaskStatus_core1 A pointer to the TaskStatus_t_core1 structure that will be
 * filled with information about the task_core1 referenced by the handle passed using
 * the xTask_core1 parameter.
 *
 * @param xGetFreeStackSpace_core1 The TaskStatus_t_core1 structure contains a member to report
 * the stack high water mark of the task_core1 being queried.  Calculating the stack
 * high water mark takes a relatively long time, and can make the system
 * temporarily unresponsive - so the xGetFreeStackSpace_core1 parameter is provided to
 * allow the high water mark checking to be skipped.  The high watermark value
 * will only be written to the TaskStatus_t_core1 structure if xGetFreeStackSpace_core1 is
 * not set to pdFALSE_core1;
 *
 * @param eState_core1 The TaskStatus_t_core1 structure contains a member to report the
 * state of the task_core1 being queried.  Obtaining the task_core1 state is not as fast as
 * a simple assignment - so the eState_core1 parameter is provided to allow the state
 * information to be omitted from the TaskStatus_t_core1 structure.  To obtain state
 * information then set eState_core1 to eInvalid - otherwise the value passed in
 * eState_core1 will be reported as the task_core1 state in the TaskStatus_t_core1 structure.
 *
 * Example usage:
 * @code{c}
 * void vAFunction( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 * TaskStatus_t_core1 xTaskDetails;
 *
 *  // Obtain the handle of a task_core1 from its name.
 *  xHandle_core1 = xTaskGetHandle_core1( "Task_Name" );
 *
 *  // Check the handle is not NULL.
 *  configASSERT_core1( xHandle_core1 );
 *
 *  // Use the handle to obtain further information about the task_core1.
 *  vTaskGetInfo_core1( xHandle_core1,
 *                &xTaskDetails,
 *                pdTRUE_core1, // Include the high water mark in xTaskDetails.
 *                eInvalid ); // Include the task_core1 state in xTaskDetails.
 * }
 * @endcode
 * \defgroup vTaskGetInfo_core1 vTaskGetInfo_core1
 * \ingroup TaskCtrl
 */
void vTaskGetInfo_core1( TaskHandle_t_core1 xTask_core1,
                   TaskStatus_t_core1 * pxTaskStatus_core1,
                   BaseType_t_core1 xGetFreeStackSpace_core1,
                   eTaskState_core1 eState_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskPrioritySet_core1( TaskHandle_t_core1 xTask_core1, UBaseType_t_core1 uxNewPriority_core1 );
 * @endcode
 *
 * INCLUDE_vTaskPrioritySet_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 * Set the priority of any task_core1.
 *
 * A context switch will occur before the function returns if the priority
 * being set is higher than the currently executing task_core1.
 *
 * @param xTask_core1 Handle to the task_core1 for which the priority is being set.
 * Passing a NULL handle results in the priority of the calling task_core1 being set.
 *
 * @param uxNewPriority_core1 The priority to which the task_core1 will be set.
 *
 * Example usage:
 * @code{c}
 * void vAFunction( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 *
 *   // Create a task_core1, storing the handle.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY_core1, &xHandle_core1 );
 *
 *   // ...
 *
 *   // Use the handle to raise the priority of the created task_core1.
 *   vTaskPrioritySet_core1( xHandle_core1, tskIDLE_PRIORITY_core1 + 1 );
 *
 *   // ...
 *
 *   // Use a NULL handle to raise our priority to the same value.
 *   vTaskPrioritySet_core1( NULL, tskIDLE_PRIORITY_core1 + 1 );
 * }
 * @endcode
 * \defgroup vTaskPrioritySet_core1 vTaskPrioritySet_core1
 * \ingroup TaskCtrl
 */
void vTaskPrioritySet_core1( TaskHandle_t_core1 xTask_core1,
                       UBaseType_t_core1 uxNewPriority_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskSuspend_core1( TaskHandle_t_core1 xTaskToSuspend_core1 );
 * @endcode
 *
 * INCLUDE_vTaskSuspend_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 * Suspend any task_core1.  When suspended a task_core1 will never get any microcontroller
 * processing time, no matter what its priority.
 *
 * Calls to vTaskSuspend_core1 are not accumulative -
 * i.e. calling vTaskSuspend_core1 () twice on the same task_core1 still only requires one
 * call to vTaskResume_core1 () to ready the suspended task_core1.
 *
 * @param xTaskToSuspend_core1 Handle to the task_core1 being suspended.  Passing a NULL
 * handle will cause the calling task_core1 to be suspended.
 *
 * Example usage:
 * @code{c}
 * void vAFunction( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 *
 *   // Create a task_core1, storing the handle.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY_core1, &xHandle_core1 );
 *
 *   // ...
 *
 *   // Use the handle to suspend the created task_core1.
 *   vTaskSuspend_core1( xHandle_core1 );
 *
 *   // ...
 *
 *   // The created task_core1 will not run during this period, unless
 *   // another task_core1 calls vTaskResume_core1( xHandle_core1 ).
 *
 *   //...
 *
 *
 *   // Suspend ourselves.
 *   vTaskSuspend_core1( NULL );
 *
 *   // We cannot get here unless another task_core1 calls vTaskResume_core1
 *   // with our handle as the parameter.
 * }
 * @endcode
 * \defgroup vTaskSuspend_core1 vTaskSuspend_core1
 * \ingroup TaskCtrl
 */
void vTaskSuspend_core1( TaskHandle_t_core1 xTaskToSuspend_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskResume_core1( TaskHandle_t_core1 xTaskToResume_core1 );
 * @endcode
 *
 * INCLUDE_vTaskSuspend_core1 must be defined as 1 for this function to be available.
 * See the configuration section for more information.
 *
 * Resumes a suspended task_core1.
 *
 * A task_core1 that has been suspended by one or more calls to vTaskSuspend_core1 ()
 * will be made available for running again by a single call to
 * vTaskResume_core1 ().
 *
 * @param xTaskToResume_core1 Handle to the task_core1 being readied.
 *
 * Example usage:
 * @code{c}
 * void vAFunction( void )
 * {
 * TaskHandle_t_core1 xHandle_core1;
 *
 *   // Create a task_core1, storing the handle.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY_core1, &xHandle_core1 );
 *
 *   // ...
 *
 *   // Use the handle to suspend the created task_core1.
 *   vTaskSuspend_core1( xHandle_core1 );
 *
 *   // ...
 *
 *   // The created task_core1 will not run during this period, unless
 *   // another task_core1 calls vTaskResume_core1( xHandle_core1 ).
 *
 *   //...
 *
 *
 *   // Resume the suspended task_core1 ourselves.
 *   vTaskResume_core1( xHandle_core1 );
 *
 *   // The created task_core1 will once again get microcontroller processing
 *   // time in accordance with its priority within the system.
 * }
 * @endcode
 * \defgroup vTaskResume_core1 vTaskResume_core1
 * \ingroup TaskCtrl
 */
void vTaskResume_core1( TaskHandle_t_core1 xTaskToResume_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void xTaskResumeFromISR_core1( TaskHandle_t_core1 xTaskToResume_core1 );
 * @endcode
 *
 * INCLUDE_xTaskResumeFromISR_core1 must be defined as 1 for this function to be
 * available.  See the configuration section for more information.
 *
 * An implementation of vTaskResume_core1() that can be called from within an ISR.
 *
 * A task_core1 that has been suspended by one or more calls to vTaskSuspend_core1 ()
 * will be made available for running again by a single call to
 * xTaskResumeFromISR_core1 ().
 *
 * xTaskResumeFromISR_core1() should not be used to synchronise a task_core1 with an
 * interrupt if there is a chance that the interrupt could arrive prior to the
 * task_core1 being suspended - as this can lead to interrupts being missed. Use of a
 * semaphore as a synchronisation mechanism would avoid this eventuality.
 *
 * @param xTaskToResume_core1 Handle to the task_core1 being readied.
 *
 * @return pdTRUE_core1 if resuming the task_core1 should result in a context switch,
 * otherwise pdFALSE_core1. This is used by the ISR to determine if a context switch
 * may be required following the ISR.
 *
 * \defgroup vTaskResumeFromISR vTaskResumeFromISR
 * \ingroup TaskCtrl
 */
BaseType_t_core1 xTaskResumeFromISR_core1( TaskHandle_t_core1 xTaskToResume_core1 ) PRIVILEGED_FUNCTION_core1;

/*-----------------------------------------------------------
* SCHEDULER CONTROL
*----------------------------------------------------------*/

/**
 * task_core1. h
 * @code{c}
 * void vTaskStartScheduler_core1( void );
 * @endcode
 *
 * Starts the real time kernel tick processing.  After calling the kernel
 * has control over which tasks are executed and when.
 *
 * See the demo application file main.c for an example of creating
 * tasks and starting the kernel.
 *
 * Example usage:
 * @code{c}
 * void vAFunction( void )
 * {
 *   // Create at least one task_core1 before starting the kernel.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY_core1, NULL );
 *
 *   // Start the real time kernel with preemption.
 *   vTaskStartScheduler_core1 ();
 *
 *   // Will not get here unless a task_core1 calls vTaskEndScheduler_core1 ()
 * }
 * @endcode
 *
 * \defgroup vTaskStartScheduler_core1 vTaskStartScheduler_core1
 * \ingroup SchedulerControl
 */
void vTaskStartScheduler_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskEndScheduler_core1( void );
 * @endcode
 *
 * NOTE:  At the time of writing only the x86 real mode port, which runs on a PC
 * in place of DOS, implements this function.
 *
 * Stops the real time kernel tick.  All created tasks will be automatically
 * deleted and multitasking (either preemptive or cooperative) will
 * stop.  Execution then resumes from the point where vTaskStartScheduler_core1 ()
 * was called, as if vTaskStartScheduler_core1 () had just returned.
 *
 * See the demo application file main. c in the demo/PC directory for an
 * example that uses vTaskEndScheduler_core1 ().
 *
 * vTaskEndScheduler_core1 () requires an exit function to be defined within the
 * portable layer (see vPortEndScheduler_core1 () in port. c for the PC port).  This
 * performs hardware specific operations such as stopping the kernel tick.
 *
 * vTaskEndScheduler_core1 () will cause all of the resources allocated by the
 * kernel to be freed - but will not free resources allocated by application
 * tasks.
 *
 * Example usage:
 * @code{c}
 * void vTaskCode( void * pvParameters_core1 )
 * {
 *   for( ;; )
 *   {
 *       // Task code goes here.
 *
 *       // At some point we want to end the real time kernel processing
 *       // so call ...
 *       vTaskEndScheduler_core1 ();
 *   }
 * }
 *
 * void vAFunction( void )
 * {
 *   // Create at least one task_core1 before starting the kernel.
 *   xTaskCreate_core1( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY_core1, NULL );
 *
 *   // Start the real time kernel with preemption.
 *   vTaskStartScheduler_core1 ();
 *
 *   // Will only get here when the vTaskCode () task_core1 has called
 *   // vTaskEndScheduler_core1 ().  When we get here we are back to single task_core1
 *   // execution.
 * }
 * @endcode
 *
 * \defgroup vTaskEndScheduler_core1 vTaskEndScheduler_core1
 * \ingroup SchedulerControl
 */
void vTaskEndScheduler_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskSuspendAll_core1( void );
 * @endcode
 *
 * Suspends the scheduler without disabling interrupts.  Context switches will
 * not occur while the scheduler is suspended.
 *
 * After calling vTaskSuspendAll_core1 () the calling task_core1 will continue to execute
 * without risk of being swapped out until a call to xTaskResumeAll_core1 () has been
 * made.
 *
 * API functions that have the potential to cause a context switch (for example,
 * xTaskDelayUntil_core1(), xQueueSend_core1(), etc.) must not be called while the scheduler
 * is suspended.
 *
 * Example usage:
 * @code{c}
 * void vTask1( void * pvParameters_core1 )
 * {
 *   for( ;; )
 *   {
 *       // Task code goes here.
 *
 *       // ...
 *
 *       // At some point the task_core1 wants to perform a long operation during
 *       // which it does not want to get swapped out.  It cannot use
 *       // taskENTER_CRITICAL_core1 ()/taskEXIT_CRITICAL_core1 () as the length of the
 *       // operation may cause interrupts to be missed - including the
 *       // ticks.
 *
 *       // Prevent the real time kernel swapping out the task_core1.
 *       vTaskSuspendAll_core1 ();
 *
 *       // Perform the operation here.  There is no need to use critical
 *       // sections as we have all the microcontroller processing time.
 *       // During this time interrupts will still operate and the kernel
 *       // tick count will be maintained.
 *
 *       // ...
 *
 *       // The operation is complete.  Restart the kernel.
 *       xTaskResumeAll_core1 ();
 *   }
 * }
 * @endcode
 * \defgroup vTaskSuspendAll_core1 vTaskSuspendAll_core1
 * \ingroup SchedulerControl
 */
void vTaskSuspendAll_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskResumeAll_core1( void );
 * @endcode
 *
 * Resumes scheduler activity after it was suspended by a call to
 * vTaskSuspendAll_core1().
 *
 * xTaskResumeAll_core1() only resumes the scheduler.  It does not unsuspend tasks
 * that were previously suspended by a call to vTaskSuspend_core1().
 *
 * @return If resuming the scheduler caused a context switch then pdTRUE_core1 is
 *         returned, otherwise pdFALSE_core1 is returned.
 *
 * Example usage:
 * @code{c}
 * void vTask1( void * pvParameters_core1 )
 * {
 *   for( ;; )
 *   {
 *       // Task code goes here.
 *
 *       // ...
 *
 *       // At some point the task_core1 wants to perform a long operation during
 *       // which it does not want to get swapped out.  It cannot use
 *       // taskENTER_CRITICAL_core1 ()/taskEXIT_CRITICAL_core1 () as the length of the
 *       // operation may cause interrupts to be missed - including the
 *       // ticks.
 *
 *       // Prevent the real time kernel swapping out the task_core1.
 *       vTaskSuspendAll_core1 ();
 *
 *       // Perform the operation here.  There is no need to use critical
 *       // sections as we have all the microcontroller processing time.
 *       // During this time interrupts will still operate and the real
 *       // time kernel tick count will be maintained.
 *
 *       // ...
 *
 *       // The operation is complete.  Restart the kernel.  We want to force
 *       // a context switch - but there is no point if resuming the scheduler
 *       // caused a context switch already.
 *       if( !xTaskResumeAll_core1 () )
 *       {
 *            taskYIELD_core1 ();
 *       }
 *   }
 * }
 * @endcode
 * \defgroup xTaskResumeAll_core1 xTaskResumeAll_core1
 * \ingroup SchedulerControl
 */
BaseType_t_core1 xTaskResumeAll_core1( void ) PRIVILEGED_FUNCTION_core1;

/*-----------------------------------------------------------
* TASK UTILITIES
*----------------------------------------------------------*/

/**
 * task_core1. h
 * @code{c}
 * TickType_t_core1 xTaskGetTickCount_core1( void );
 * @endcode
 *
 * @return The count of ticks since vTaskStartScheduler_core1 was called.
 *
 * \defgroup xTaskGetTickCount_core1 xTaskGetTickCount_core1
 * \ingroup TaskUtils
 */
TickType_t_core1 xTaskGetTickCount_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * TickType_t_core1 xTaskGetTickCountFromISR_core1( void );
 * @endcode
 *
 * @return The count of ticks since vTaskStartScheduler_core1 was called.
 *
 * This is a version of xTaskGetTickCount_core1() that is safe to be called from an
 * ISR - provided that TickType_t_core1 is the natural word size of the
 * microcontroller being used or interrupt nesting is either not supported or
 * not being used.
 *
 * \defgroup xTaskGetTickCountFromISR_core1 xTaskGetTickCountFromISR_core1
 * \ingroup TaskUtils
 */
TickType_t_core1 xTaskGetTickCountFromISR_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * uint16_t uxTaskGetNumberOfTasks_core1( void );
 * @endcode
 *
 * @return The number of tasks that the real time kernel is currently managing.
 * This includes all ready, blocked and suspended tasks.  A task_core1 that
 * has been deleted but not yet freed by the idle task_core1 will also be
 * included in the count.
 *
 * \defgroup uxTaskGetNumberOfTasks_core1 uxTaskGetNumberOfTasks_core1
 * \ingroup TaskUtils
 */
UBaseType_t_core1 uxTaskGetNumberOfTasks_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * char *pcTaskGetName_core1( TaskHandle_t_core1 xTaskToQuery_core1 );
 * @endcode
 *
 * @return The text (human readable) name of the task_core1 referenced by the handle
 * xTaskToQuery_core1.  A task_core1 can query its own name by either passing in its own
 * handle, or by setting xTaskToQuery_core1 to NULL.
 *
 * \defgroup pcTaskGetName_core1 pcTaskGetName_core1
 * \ingroup TaskUtils
 */
char * pcTaskGetName_core1( TaskHandle_t_core1 xTaskToQuery_core1 ) PRIVILEGED_FUNCTION_core1; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */

/**
 * task_core1. h
 * @code{c}
 * TaskHandle_t_core1 xTaskGetHandle_core1( const char *pcNameToQuery_core1 );
 * @endcode
 *
 * NOTE:  This function takes a relatively long time to complete and should be
 * used sparingly.
 *
 * @return The handle of the task_core1 that has the human readable name pcNameToQuery_core1.
 * NULL is returned if no matching name is found.  INCLUDE_xTaskGetHandle_core1
 * must be set to 1 in FreeRTOSConfig.h for pcTaskGetHandle() to be available.
 *
 * \defgroup pcTaskGetHandle pcTaskGetHandle
 * \ingroup TaskUtils
 */
TaskHandle_t_core1 xTaskGetHandle_core1( const char * pcNameToQuery_core1 ) PRIVILEGED_FUNCTION_core1; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */

/**
 * task_core1.h
 * @code{c}
 * UBaseType_t_core1 uxTaskGetStackHighWaterMark_core1( TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * INCLUDE_uxTaskGetStackHighWaterMark_core1 must be set to 1 in FreeRTOSConfig.h for
 * this function to be available.
 *
 * Returns the high water mark of the stack associated with xTask_core1.  That is,
 * the minimum free stack space there has been (in words, so on a 32 bit machine
 * a value of 1 means 4 bytes) since the task_core1 started.  The smaller the returned
 * number the closer the task_core1 has come to overflowing its stack.
 *
 * uxTaskGetStackHighWaterMark_core1() and uxTaskGetStackHighWaterMark2_core1() are the
 * same except for their return type.  Using configSTACK_DEPTH_TYPE_core1 allows the
 * user to determine the return type.  It gets around the problem of the value
 * overflowing on 8-bit types without breaking backward compatibility for
 * applications that expect an 8-bit return type.
 *
 * @param xTask_core1 Handle of the task_core1 associated with the stack to be checked.
 * Set xTask_core1 to NULL to check the stack of the calling task_core1.
 *
 * @return The smallest amount of free stack space there has been (in words, so
 * actual spaces on the stack rather than bytes) since the task_core1 referenced by
 * xTask_core1 was created.
 */
UBaseType_t_core1 uxTaskGetStackHighWaterMark_core1( TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1.h
 * @code{c}
 * configSTACK_DEPTH_TYPE_core1 uxTaskGetStackHighWaterMark2_core1( TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * INCLUDE_uxTaskGetStackHighWaterMark2_core1 must be set to 1 in FreeRTOSConfig.h for
 * this function to be available.
 *
 * Returns the high water mark of the stack associated with xTask_core1.  That is,
 * the minimum free stack space there has been (in words, so on a 32 bit machine
 * a value of 1 means 4 bytes) since the task_core1 started.  The smaller the returned
 * number the closer the task_core1 has come to overflowing its stack.
 *
 * uxTaskGetStackHighWaterMark_core1() and uxTaskGetStackHighWaterMark2_core1() are the
 * same except for their return type.  Using configSTACK_DEPTH_TYPE_core1 allows the
 * user to determine the return type.  It gets around the problem of the value
 * overflowing on 8-bit types without breaking backward compatibility for
 * applications that expect an 8-bit return type.
 *
 * @param xTask_core1 Handle of the task_core1 associated with the stack to be checked.
 * Set xTask_core1 to NULL to check the stack of the calling task_core1.
 *
 * @return The smallest amount of free stack space there has been (in words, so
 * actual spaces on the stack rather than bytes) since the task_core1 referenced by
 * xTask_core1 was created.
 */
configSTACK_DEPTH_TYPE_core1 uxTaskGetStackHighWaterMark2_core1( TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/* When using trace macros it is sometimes necessary to include task_core1.h before
 * FreeRTOS_core1.h.  When this is done TaskHookFunction_t_core1 will not yet have been defined,
 * so the following two prototypes will cause a compilation error.  This can be
 * fixed by simply guarding against the inclusion of these two prototypes unless
 * they are explicitly required by the configUSE_APPLICATION_TASK_TAG_core1 configuration
 * constant. */
#ifdef configUSE_APPLICATION_TASK_TAG_core1
    #if configUSE_APPLICATION_TASK_TAG_core1 == 1

/**
 * task_core1.h
 * @code{c}
 * void vTaskSetApplicationTaskTag_core1( TaskHandle_t_core1 xTask_core1, TaskHookFunction_t_core1 pxHookFunction_core1 );
 * @endcode
 *
 * Sets pxHookFunction_core1 to be the task_core1 hook function used by the task_core1 xTask_core1.
 * Passing xTask_core1 as NULL has the effect of setting the calling tasks hook
 * function.
 */
        void vTaskSetApplicationTaskTag_core1( TaskHandle_t_core1 xTask_core1,
                                         TaskHookFunction_t_core1 pxHookFunction_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1.h
 * @code{c}
 * void xTaskGetApplicationTaskTag_core1( TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * Returns the pxHookFunction_core1 value assigned to the task_core1 xTask_core1.  Do not
 * call from an interrupt service routine - call
 * xTaskGetApplicationTaskTagFromISR_core1() instead.
 */
        TaskHookFunction_t_core1 xTaskGetApplicationTaskTag_core1( TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1.h
 * @code{c}
 * void xTaskGetApplicationTaskTagFromISR_core1( TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * Returns the pxHookFunction_core1 value assigned to the task_core1 xTask_core1.  Can
 * be called from an interrupt service routine.
 */
        TaskHookFunction_t_core1 xTaskGetApplicationTaskTagFromISR_core1( TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;
    #endif /* configUSE_APPLICATION_TASK_TAG_core1 ==1 */
#endif /* ifdef configUSE_APPLICATION_TASK_TAG_core1 */

#if ( configNUM_THREAD_LOCAL_STORAGE_POINTERS_core1 > 0 )

/* Each task_core1 contains an array of pointers that is dimensioned by the
 * configNUM_THREAD_LOCAL_STORAGE_POINTERS_core1 setting in FreeRTOSConfig.h.  The
 * kernel does not use the pointers itself, so the application writer can use
 * the pointers for any purpose they wish.  The following two functions are
 * used to set and query a pointer respectively. */
    void vTaskSetThreadLocalStoragePointer_core1( TaskHandle_t_core1 xTaskToSet_core1,
                                            BaseType_t_core1 xIndex_core1,
                                            void * pvValue_core1 ) PRIVILEGED_FUNCTION_core1;
    void * pvTaskGetThreadLocalStoragePointer_core1( TaskHandle_t_core1 xTaskToQuery_core1,
                                               BaseType_t_core1 xIndex_core1 ) PRIVILEGED_FUNCTION_core1;

#endif

#if ( configCHECK_FOR_STACK_OVERFLOW_core1 > 0 )

/**
 * task_core1.h
 * @code{c}
 * void vApplicationStackOverflowHook_core1( TaskHandle_t_core1 xTask_core1 char *pcTaskName_core1);
 * @endcode
 *
 * The application stack overflow hook is called when a stack overflow is detected for a task_core1.
 *
 * Details on stack overflow detection can be found here: https://www.FreeRTOS_core1.org/Stacks-and-stack-overflow-checking.html
 *
 * @param xTask_core1 the task_core1 that just exceeded its stack boundaries.
 * @param pcTaskName_core1 A character string containing the name of the offending task_core1.
 */
    void vApplicationStackOverflowHook_core1( TaskHandle_t_core1 xTask_core1,
                                        char * pcTaskName_core1 );

#endif

#if  ( configUSE_TICK_HOOK_core1 > 0 )

/**
 *  task_core1.h
 * @code{c}
 * void vApplicationTickHook_core1( void );
 * @endcode
 *
 * This hook function is called in the system tick handler after any OS work is completed.
 */
    void vApplicationTickHook_core1( void ); /*lint !e526 Symbol not defined as it is an application callback. */

#endif

#if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )

/**
 * task_core1.h
 * @code{c}
 * void vApplicationGetIdleTaskMemory_core1( StaticTask_t_core1 ** ppxIdleTaskTCBBuffer_core1, StackType_t_core1 ** ppxIdleTaskStackBuffer_core1, uint32_t *pulIdleTaskStackSize_core1 )
 * @endcode
 *
 * This function is used to provide a statically allocated block of memory to FreeRTOS_core1 to hold the Idle Task TCB.  This function is required when
 * configSUPPORT_STATIC_ALLOCATION_core1 is set.  For more information see this URI: https://www.FreeRTOS_core1.org/a00110.html#configSUPPORT_STATIC_ALLOCATION_core1
 *
 * @param ppxIdleTaskTCBBuffer_core1 A handle to a statically allocated TCB buffer
 * @param ppxIdleTaskStackBuffer_core1 A handle to a statically allocated Stack buffer for the idle task_core1
 * @param pulIdleTaskStackSize_core1 A pointer to the number of elements that will fit in the allocated stack buffer
 */
    void vApplicationGetIdleTaskMemory_core1( StaticTask_t_core1 ** ppxIdleTaskTCBBuffer_core1,
                                        StackType_t_core1 ** ppxIdleTaskStackBuffer_core1,
                                        uint32_t * pulIdleTaskStackSize_core1 ); /*lint !e526 Symbol not defined as it is an application callback. */
#endif

/**
 * task_core1.h
 * @code{c}
 * BaseType_t_core1 xTaskCallApplicationTaskHook_core1( TaskHandle_t_core1 xTask_core1, void *pvParameter_core1 );
 * @endcode
 *
 * Calls the hook function associated with xTask_core1.  Passing xTask_core1 as NULL has
 * the effect of calling the Running tasks (the calling task_core1) hook function.
 *
 * pvParameter_core1 is passed to the hook function for the task_core1 to interpret as it
 * wants.  The return value is the value returned by the task_core1 hook function
 * registered by the user.
 */
BaseType_t_core1 xTaskCallApplicationTaskHook_core1( TaskHandle_t_core1 xTask_core1,
                                         void * pvParameter_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * xTaskGetIdleTaskHandle_core1() is only available if
 * INCLUDE_xTaskGetIdleTaskHandle_core1 is set to 1 in FreeRTOSConfig.h.
 *
 * Simply returns the handle of the idle task_core1.  It is not valid to call
 * xTaskGetIdleTaskHandle_core1() before the scheduler has been started.
 */
TaskHandle_t_core1 xTaskGetIdleTaskHandle_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * configUSE_TRACE_FACILITY_core1 must be defined as 1 in FreeRTOSConfig.h for
 * uxTaskGetSystemState_core1() to be available.
 *
 * uxTaskGetSystemState_core1() populates an TaskStatus_t_core1 structure for each task_core1 in
 * the system.  TaskStatus_t_core1 structures contain, among other things, members
 * for the task_core1 handle, task_core1 name, task_core1 priority, task_core1 state, and total amount
 * of run time consumed by the task_core1.  See the TaskStatus_t_core1 structure
 * definition in this file for the full member list.
 *
 * NOTE:  This function is intended for debugging use only as its use results in
 * the scheduler remaining suspended for an extended period.
 *
 * @param pxTaskStatusArray_core1 A pointer to an array of TaskStatus_t_core1 structures.
 * The array must contain at least one TaskStatus_t_core1 structure for each task_core1
 * that is under the control of the RTOS.  The number of tasks under the control
 * of the RTOS can be determined using the uxTaskGetNumberOfTasks_core1() API function.
 *
 * @param uxArraySize_core1 The size of the array pointed to by the pxTaskStatusArray_core1
 * parameter.  The size is specified as the number of indexes in the array, or
 * the number of TaskStatus_t_core1 structures contained in the array, not by the
 * number of bytes in the array.
 *
 * @param pulTotalRunTime_core1 If configGENERATE_RUN_TIME_STATS_core1 is set to 1 in
 * FreeRTOSConfig.h then *pulTotalRunTime_core1 is set by uxTaskGetSystemState_core1() to the
 * total run time (as defined by the run time stats clock, see
 * https://www.FreeRTOS_core1.org/rtos-run-time-stats.html) since the target booted.
 * pulTotalRunTime_core1 can be set to NULL to omit the total run time information.
 *
 * @return The number of TaskStatus_t_core1 structures that were populated by
 * uxTaskGetSystemState_core1().  This should equal the number returned by the
 * uxTaskGetNumberOfTasks_core1() API function, but will be zero if the value passed
 * in the uxArraySize_core1 parameter was too small.
 *
 * Example usage:
 * @code{c}
 *  // This example demonstrates how a human readable table of run time stats
 *  // information is generated from raw data provided by uxTaskGetSystemState_core1().
 *  // The human readable table is written to pcWriteBuffer_core1
 *  void vTaskGetRunTimeStats_core1( char *pcWriteBuffer_core1 )
 *  {
 *  TaskStatus_t_core1 *pxTaskStatusArray_core1;
 *  volatile UBaseType_t_core1 uxArraySize_core1, x_core1;
 *  configRUN_TIME_COUNTER_TYPE_core1 ulTotalRunTime_core1, ulStatsAsPercentage;
 *
 *      // Make sure the write buffer does not contain a string.
 * pcWriteBuffer_core1 = 0x00;
 *
 *      // Take a snapshot of the number of tasks in case it changes while this
 *      // function is executing.
 *      uxArraySize_core1 = uxTaskGetNumberOfTasks_core1();
 *
 *      // Allocate a TaskStatus_t_core1 structure for each task_core1.  An array could be
 *      // allocated statically at compile time.
 *      pxTaskStatusArray_core1 = pvPortMalloc_core1( uxArraySize_core1 * sizeof( TaskStatus_t_core1 ) );
 *
 *      if( pxTaskStatusArray_core1 != NULL )
 *      {
 *          // Generate raw status information about each task_core1.
 *          uxArraySize_core1 = uxTaskGetSystemState_core1( pxTaskStatusArray_core1, uxArraySize_core1, &ulTotalRunTime_core1 );
 *
 *          // For percentage calculations.
 *          ulTotalRunTime_core1 /= 100UL;
 *
 *          // Avoid divide by zero errors.
 *          if( ulTotalRunTime_core1 > 0 )
 *          {
 *              // For each populated position in the pxTaskStatusArray_core1 array,
 *              // format the raw data as human readable ASCII data
 *              for( x_core1 = 0; x_core1 < uxArraySize_core1; x_core1++ )
 *              {
 *                  // What percentage of the total run time has the task_core1 used?
 *                  // This will always be rounded down to the nearest integer.
 *                  // ulTotalRunTimeDiv100 has already been divided by 100.
 *                  ulStatsAsPercentage = pxTaskStatusArray_core1[ x_core1 ].ulRunTimeCounter_core1 / ulTotalRunTime_core1;
 *
 *                  if( ulStatsAsPercentage > 0UL )
 *                  {
 *                      sprintf( pcWriteBuffer_core1, "%s\t\t%lu\t\t%lu%%\r\n", pxTaskStatusArray_core1[ x_core1 ].pcTaskName_core1, pxTaskStatusArray_core1[ x_core1 ].ulRunTimeCounter_core1, ulStatsAsPercentage );
 *                  }
 *                  else
 *                  {
 *                      // If the percentage is zero here then the task_core1 has
 *                      // consumed less than 1% of the total run time.
 *                      sprintf( pcWriteBuffer_core1, "%s\t\t%lu\t\t<1%%\r\n", pxTaskStatusArray_core1[ x_core1 ].pcTaskName_core1, pxTaskStatusArray_core1[ x_core1 ].ulRunTimeCounter_core1 );
 *                  }
 *
 *                  pcWriteBuffer_core1 += strlen( ( char * ) pcWriteBuffer_core1 );
 *              }
 *          }
 *
 *          // The array is no longer needed, free the memory it consumes.
 *          vPortFree_core1( pxTaskStatusArray_core1 );
 *      }
 *  }
 *  @endcode
 */
UBaseType_t_core1 uxTaskGetSystemState_core1( TaskStatus_t_core1 * const pxTaskStatusArray_core1,
                                  const UBaseType_t_core1 uxArraySize_core1,
                                  configRUN_TIME_COUNTER_TYPE_core1 * const pulTotalRunTime_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * void vTaskList_core1( char *pcWriteBuffer_core1 );
 * @endcode
 *
 * configUSE_TRACE_FACILITY_core1 and configUSE_STATS_FORMATTING_FUNCTIONS_core1 must
 * both be defined as 1 for this function to be available.  See the
 * configuration section of the FreeRTOS_core1.org website for more information.
 *
 * NOTE 1: This function will disable interrupts for its duration.  It is
 * not intended for normal application runtime use but as a debug aid.
 *
 * Lists all the current tasks, along with their current state and stack
 * usage high water mark.
 *
 * Tasks are reported as blocked ('B'), ready ('R'), deleted ('D') or
 * suspended ('S').
 *
 * PLEASE NOTE:
 *
 * This function is provided for convenience only, and is used by many of the
 * demo applications.  Do not consider it to be part of the scheduler.
 *
 * vTaskList_core1() calls uxTaskGetSystemState_core1(), then formats part of the
 * uxTaskGetSystemState_core1() output into a human readable table that displays task_core1:
 * names, states, priority, stack usage and task_core1 number.
 * Stack usage specified as the number of unused StackType_t_core1 words stack can hold
 * on top of stack - not the number of bytes.
 *
 * vTaskList_core1() has a dependency on the sprintf() C library function that might
 * bloat the code size, use a lot of stack, and provide different results on
 * different platforms.  An alternative, tiny, third party, and limited
 * functionality implementation of sprintf() is provided in many of the
 * FreeRTOS_core1/Demo sub-directories in a file called printf-stdarg.c (note
 * printf-stdarg.c does not provide a full snprintf() implementation!).
 *
 * It is recommended that production systems call uxTaskGetSystemState_core1()
 * directly to get access to raw stats data, rather than indirectly through a
 * call to vTaskList_core1().
 *
 * @param pcWriteBuffer_core1 A buffer into which the above mentioned details
 * will be written, in ASCII form.  This buffer is assumed to be large
 * enough to contain the generated report.  Approximately 40 bytes per
 * task_core1 should be sufficient.
 *
 * \defgroup vTaskList_core1 vTaskList_core1
 * \ingroup TaskUtils
 */
void vTaskList_core1( char * pcWriteBuffer_core1 ) PRIVILEGED_FUNCTION_core1; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */

/**
 * task_core1. h
 * @code{c}
 * void vTaskGetRunTimeStats_core1( char *pcWriteBuffer_core1 );
 * @endcode
 *
 * configGENERATE_RUN_TIME_STATS_core1 and configUSE_STATS_FORMATTING_FUNCTIONS_core1
 * must both be defined as 1 for this function to be available.  The application
 * must also then provide definitions for
 * portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core1() and portGET_RUN_TIME_COUNTER_VALUE_core1()
 * to configure a peripheral timer/counter and return the timers_core1 current count
 * value respectively.  The counter should be at least 10 times the frequency of
 * the tick count.
 *
 * NOTE 1: This function will disable interrupts for its duration.  It is
 * not intended for normal application runtime use but as a debug aid.
 *
 * Setting configGENERATE_RUN_TIME_STATS_core1 to 1 will result in a total
 * accumulated execution time being stored for each task_core1.  The resolution
 * of the accumulated time value depends on the frequency of the timer
 * configured by the portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core1() macro.
 * Calling vTaskGetRunTimeStats_core1() writes the total execution time of each
 * task_core1 into a buffer, both as an absolute count value and as a percentage
 * of the total system execution time.
 *
 * NOTE 2:
 *
 * This function is provided for convenience only, and is used by many of the
 * demo applications.  Do not consider it to be part of the scheduler.
 *
 * vTaskGetRunTimeStats_core1() calls uxTaskGetSystemState_core1(), then formats part of the
 * uxTaskGetSystemState_core1() output into a human readable table that displays the
 * amount of time each task_core1 has spent in the Running state in both absolute and
 * percentage terms.
 *
 * vTaskGetRunTimeStats_core1() has a dependency on the sprintf() C library function
 * that might bloat the code size, use a lot of stack, and provide different
 * results on different platforms.  An alternative, tiny, third party, and
 * limited functionality implementation of sprintf() is provided in many of the
 * FreeRTOS_core1/Demo sub-directories in a file called printf-stdarg.c (note
 * printf-stdarg.c does not provide a full snprintf() implementation!).
 *
 * It is recommended that production systems call uxTaskGetSystemState_core1() directly
 * to get access to raw stats data, rather than indirectly through a call to
 * vTaskGetRunTimeStats_core1().
 *
 * @param pcWriteBuffer_core1 A buffer into which the execution times will be
 * written, in ASCII form.  This buffer is assumed to be large enough to
 * contain the generated report.  Approximately 40 bytes per task_core1 should
 * be sufficient.
 *
 * \defgroup vTaskGetRunTimeStats_core1 vTaskGetRunTimeStats_core1
 * \ingroup TaskUtils
 */
void vTaskGetRunTimeStats_core1( char * pcWriteBuffer_core1 ) PRIVILEGED_FUNCTION_core1; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */

/**
 * task_core1. h
 * @code{c}
 * configRUN_TIME_COUNTER_TYPE_core1 ulTaskGetIdleRunTimeCounter_core1( void );
 * configRUN_TIME_COUNTER_TYPE_core1 ulTaskGetIdleRunTimePercent_core1( void );
 * @endcode
 *
 * configGENERATE_RUN_TIME_STATS_core1, configUSE_STATS_FORMATTING_FUNCTIONS_core1 and
 * INCLUDE_xTaskGetIdleTaskHandle_core1 must all be defined as 1 for these functions
 * to be available.  The application must also then provide definitions for
 * portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core1() and portGET_RUN_TIME_COUNTER_VALUE_core1()
 * to configure a peripheral timer/counter and return the timers_core1 current count
 * value respectively.  The counter should be at least 10 times the frequency of
 * the tick count.
 *
 * Setting configGENERATE_RUN_TIME_STATS_core1 to 1 will result in a total
 * accumulated execution time being stored for each task_core1.  The resolution
 * of the accumulated time value depends on the frequency of the timer
 * configured by the portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core1() macro.
 * While uxTaskGetSystemState_core1() and vTaskGetRunTimeStats_core1() writes the total
 * execution time of each task_core1 into a buffer, ulTaskGetIdleRunTimeCounter_core1()
 * returns the total execution time of just the idle task_core1 and
 * ulTaskGetIdleRunTimePercent_core1() returns the percentage of the CPU time used by
 * just the idle task_core1.
 *
 * Note the amount of idle time is only a good measure of the slack time in a
 * system if there are no other tasks executing at the idle priority, tickless
 * idle is not used, and configIDLE_SHOULD_YIELD_core1 is set to 0.
 *
 * @return The total run time of the idle task_core1 or the percentage of the total
 * run time consumed by the idle task_core1.  This is the amount of time the
 * idle task_core1 has actually been executing.  The unit of time is dependent on the
 * frequency configured using the portCONFIGURE_TIMER_FOR_RUN_TIME_STATS_core1() and
 * portGET_RUN_TIME_COUNTER_VALUE_core1() macros.
 *
 * \defgroup ulTaskGetIdleRunTimeCounter_core1 ulTaskGetIdleRunTimeCounter_core1
 * \ingroup TaskUtils
 */
configRUN_TIME_COUNTER_TYPE_core1 ulTaskGetIdleRunTimeCounter_core1( void ) PRIVILEGED_FUNCTION_core1;
configRUN_TIME_COUNTER_TYPE_core1 ulTaskGetIdleRunTimePercent_core1( void ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskNotifyIndexed_core1( TaskHandle_t_core1 xTaskToNotify_core1, UBaseType_t_core1 uxIndexToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1 );
 * BaseType_t_core1 xTaskNotify_core1( TaskHandle_t_core1 xTaskToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1 );
 * @endcode
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for these
 * functions to be available.
 *
 * Sends a direct to task_core1 notification to a task_core1, with an optional value and
 * action.
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * Events can be sent to a task_core1 using an intermediary object.  Examples of such
 * objects are queues, semaphores, mutexes and event groups.  Task notifications
 * are a method of sending an event directly to a task_core1 without the need for such
 * an intermediary object.
 *
 * A notification sent to a task_core1 can optionally perform an action, such as
 * update, overwrite or increment one of the task_core1's notification values.  In
 * that way task_core1 notifications can be used to send data to a task_core1, or be used as
 * light weight and fast binary or counting semaphores.
 *
 * A task_core1 can use xTaskNotifyWaitIndexed_core1() or ulTaskNotifyTakeIndexed_core1() to
 * [optionally] block to wait for a notification to be pending.  The task_core1 does
 * not consume any CPU time while it is in the Blocked state.
 *
 * A notification sent to a task_core1 will remain pending until it is cleared by the
 * task_core1 calling xTaskNotifyWaitIndexed_core1() or ulTaskNotifyTakeIndexed_core1() (or their
 * un-indexed equivalents).  If the task_core1 was already in the Blocked state to
 * wait for a notification when the notification arrives then the task_core1 will
 * automatically be removed from the Blocked state (unblocked) and the
 * notification cleared.
 *
 * **NOTE** Each notification within the array operates independently - a task_core1
 * can only block on one notification within the array at a time and will not be
 * unblocked by a notification sent to any other array index.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  xTaskNotify_core1() is the original API function, and remains backward
 * compatible by always operating on the notification value at index 0 in the
 * array. Calling xTaskNotify_core1() is equivalent to calling xTaskNotifyIndexed_core1()
 * with the uxIndexToNotify_core1 parameter set to 0.
 *
 * @param xTaskToNotify_core1 The handle of the task_core1 being notified.  The handle to a
 * task_core1 can be returned from the xTaskCreate_core1() API function used to create the
 * task_core1, and the handle of the currently running task_core1 can be obtained by calling
 * xTaskGetCurrentTaskHandle_core1().
 *
 * @param uxIndexToNotify_core1 The index within the target task_core1's array of
 * notification values to which the notification is to be sent.  uxIndexToNotify_core1
 * must be less than configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.  xTaskNotify_core1() does
 * not have this parameter and always sends notifications to index 0.
 *
 * @param ulValue_core1 Data that can be sent with the notification.  How the data is
 * used depends on the value of the eAction_core1 parameter.
 *
 * @param eAction_core1 Specifies how the notification updates the task_core1's notification
 * value, if at all.  Valid values for eAction_core1 are as follows:
 *
 * eSetBits -
 * The target notification value is bitwise ORed with ulValue_core1.
 * xTaskNotifyIndexed_core1() always returns pdPASS_core1 in this case.
 *
 * eIncrement_core1 -
 * The target notification value is incremented.  ulValue_core1 is not used and
 * xTaskNotifyIndexed_core1() always returns pdPASS_core1 in this case.
 *
 * eSetValueWithOverwrite -
 * The target notification value is set to the value of ulValue_core1, even if the
 * task_core1 being notified had not yet processed the previous notification at the
 * same array index (the task_core1 already had a notification pending at that index).
 * xTaskNotifyIndexed_core1() always returns pdPASS_core1 in this case.
 *
 * eSetValueWithoutOverwrite -
 * If the task_core1 being notified did not already have a notification pending at the
 * same array index then the target notification value is set to ulValue_core1 and
 * xTaskNotifyIndexed_core1() will return pdPASS_core1.  If the task_core1 being notified already
 * had a notification pending at the same array index then no action is
 * performed and pdFAIL_core1 is returned.
 *
 * eNoAction_core1 -
 * The task_core1 receives a notification at the specified array index without the
 * notification value at that index being updated.  ulValue_core1 is not used and
 * xTaskNotifyIndexed_core1() always returns pdPASS_core1 in this case.
 *
 * pulPreviousNotificationValue_core1 -
 * Can be used to pass out the subject task_core1's notification value before any
 * bits are modified by the notify function.
 *
 * @return Dependent on the value of eAction_core1.  See the description of the
 * eAction_core1 parameter.
 *
 * \defgroup xTaskNotifyIndexed_core1 xTaskNotifyIndexed_core1
 * \ingroup TaskNotifications
 */
BaseType_t_core1 xTaskGenericNotify_core1( TaskHandle_t_core1 xTaskToNotify_core1,
                               UBaseType_t_core1 uxIndexToNotify_core1,
                               uint32_t ulValue_core1,
                               eNotifyAction_core1 eAction_core1,
                               uint32_t * pulPreviousNotificationValue_core1 ) PRIVILEGED_FUNCTION_core1;
#define xTaskNotify_core1( xTaskToNotify_core1, ulValue_core1, eAction_core1 ) \
    xTaskGenericNotify_core1( ( xTaskToNotify_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( ulValue_core1 ), ( eAction_core1 ), NULL )
#define xTaskNotifyIndexed_core1( xTaskToNotify_core1, uxIndexToNotify_core1, ulValue_core1, eAction_core1 ) \
    xTaskGenericNotify_core1( ( xTaskToNotify_core1 ), ( uxIndexToNotify_core1 ), ( ulValue_core1 ), ( eAction_core1 ), NULL )

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskNotifyAndQueryIndexed_core1( TaskHandle_t_core1 xTaskToNotify_core1, UBaseType_t_core1 uxIndexToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1, uint32_t *pulPreviousNotifyValue_core1 );
 * BaseType_t_core1 xTaskNotifyAndQuery_core1( TaskHandle_t_core1 xTaskToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1, uint32_t *pulPreviousNotifyValue_core1 );
 * @endcode
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * xTaskNotifyAndQueryIndexed_core1() performs the same operation as
 * xTaskNotifyIndexed_core1() with the addition that it also returns the subject
 * task_core1's prior notification value (the notification value at the time the
 * function is called rather than when the function returns) in the additional
 * pulPreviousNotifyValue_core1 parameter.
 *
 * xTaskNotifyAndQuery_core1() performs the same operation as xTaskNotify_core1() with the
 * addition that it also returns the subject task_core1's prior notification value
 * (the notification value as it was at the time the function is called, rather
 * than when the function returns) in the additional pulPreviousNotifyValue_core1
 * parameter.
 *
 * \defgroup xTaskNotifyAndQueryIndexed_core1 xTaskNotifyAndQueryIndexed_core1
 * \ingroup TaskNotifications
 */
#define xTaskNotifyAndQuery_core1( xTaskToNotify_core1, ulValue_core1, eAction_core1, pulPreviousNotifyValue_core1 ) \
    xTaskGenericNotify_core1( ( xTaskToNotify_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( ulValue_core1 ), ( eAction_core1 ), ( pulPreviousNotifyValue_core1 ) )
#define xTaskNotifyAndQueryIndexed_core1( xTaskToNotify_core1, uxIndexToNotify_core1, ulValue_core1, eAction_core1, pulPreviousNotifyValue_core1 ) \
    xTaskGenericNotify_core1( ( xTaskToNotify_core1 ), ( uxIndexToNotify_core1 ), ( ulValue_core1 ), ( eAction_core1 ), ( pulPreviousNotifyValue_core1 ) )

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskNotifyIndexedFromISR_core1( TaskHandle_t_core1 xTaskToNotify_core1, UBaseType_t_core1 uxIndexToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * BaseType_t_core1 xTaskNotifyFromISR_core1( TaskHandle_t_core1 xTaskToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * @endcode
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for these
 * functions to be available.
 *
 * A version of xTaskNotifyIndexed_core1() that can be used from an interrupt service
 * routine (ISR).
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * Events can be sent to a task_core1 using an intermediary object.  Examples of such
 * objects are queues, semaphores, mutexes and event groups.  Task notifications
 * are a method of sending an event directly to a task_core1 without the need for such
 * an intermediary object.
 *
 * A notification sent to a task_core1 can optionally perform an action, such as
 * update, overwrite or increment one of the task_core1's notification values.  In
 * that way task_core1 notifications can be used to send data to a task_core1, or be used as
 * light weight and fast binary or counting semaphores.
 *
 * A task_core1 can use xTaskNotifyWaitIndexed_core1() to [optionally] block to wait for a
 * notification to be pending, or ulTaskNotifyTakeIndexed_core1() to [optionally] block
 * to wait for a notification value to have a non-zero value.  The task_core1 does
 * not consume any CPU time while it is in the Blocked state.
 *
 * A notification sent to a task_core1 will remain pending until it is cleared by the
 * task_core1 calling xTaskNotifyWaitIndexed_core1() or ulTaskNotifyTakeIndexed_core1() (or their
 * un-indexed equivalents).  If the task_core1 was already in the Blocked state to
 * wait for a notification when the notification arrives then the task_core1 will
 * automatically be removed from the Blocked state (unblocked) and the
 * notification cleared.
 *
 * **NOTE** Each notification within the array operates independently - a task_core1
 * can only block on one notification within the array at a time and will not be
 * unblocked by a notification sent to any other array index.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  xTaskNotifyFromISR_core1() is the original API function, and remains
 * backward compatible by always operating on the notification value at index 0
 * within the array. Calling xTaskNotifyFromISR_core1() is equivalent to calling
 * xTaskNotifyIndexedFromISR_core1() with the uxIndexToNotify_core1 parameter set to 0.
 *
 * @param uxIndexToNotify_core1 The index within the target task_core1's array of
 * notification values to which the notification is to be sent.  uxIndexToNotify_core1
 * must be less than configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.  xTaskNotifyFromISR_core1()
 * does not have this parameter and always sends notifications to index 0.
 *
 * @param xTaskToNotify_core1 The handle of the task_core1 being notified.  The handle to a
 * task_core1 can be returned from the xTaskCreate_core1() API function used to create the
 * task_core1, and the handle of the currently running task_core1 can be obtained by calling
 * xTaskGetCurrentTaskHandle_core1().
 *
 * @param ulValue_core1 Data that can be sent with the notification.  How the data is
 * used depends on the value of the eAction_core1 parameter.
 *
 * @param eAction_core1 Specifies how the notification updates the task_core1's notification
 * value, if at all.  Valid values for eAction_core1 are as follows:
 *
 * eSetBits -
 * The task_core1's notification value is bitwise ORed with ulValue_core1.  xTaskNotify_core1()
 * always returns pdPASS_core1 in this case.
 *
 * eIncrement_core1 -
 * The task_core1's notification value is incremented.  ulValue_core1 is not used and
 * xTaskNotify_core1() always returns pdPASS_core1 in this case.
 *
 * eSetValueWithOverwrite -
 * The task_core1's notification value is set to the value of ulValue_core1, even if the
 * task_core1 being notified had not yet processed the previous notification (the
 * task_core1 already had a notification pending).  xTaskNotify_core1() always returns
 * pdPASS_core1 in this case.
 *
 * eSetValueWithoutOverwrite -
 * If the task_core1 being notified did not already have a notification pending then
 * the task_core1's notification value is set to ulValue_core1 and xTaskNotify_core1() will
 * return pdPASS_core1.  If the task_core1 being notified already had a notification
 * pending then no action is performed and pdFAIL_core1 is returned.
 *
 * eNoAction_core1 -
 * The task_core1 receives a notification without its notification value being
 * updated.  ulValue_core1 is not used and xTaskNotify_core1() always returns pdPASS_core1 in
 * this case.
 *
 * @param pxHigherPriorityTaskWoken_core1  xTaskNotifyFromISR_core1() will set
 * *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1 if sending the notification caused the
 * task_core1 to which the notification was sent to leave the Blocked state, and the
 * unblocked task_core1 has a priority higher than the currently running task_core1.  If
 * xTaskNotifyFromISR_core1() sets this value to pdTRUE_core1 then a context switch should
 * be requested before the interrupt is exited.  How a context switch is
 * requested from an ISR is dependent on the port - see the documentation page
 * for the port in use.
 *
 * @return Dependent on the value of eAction_core1.  See the description of the
 * eAction_core1 parameter.
 *
 * \defgroup xTaskNotifyIndexedFromISR_core1 xTaskNotifyIndexedFromISR_core1
 * \ingroup TaskNotifications
 */
BaseType_t_core1 xTaskGenericNotifyFromISR_core1( TaskHandle_t_core1 xTaskToNotify_core1,
                                      UBaseType_t_core1 uxIndexToNotify_core1,
                                      uint32_t ulValue_core1,
                                      eNotifyAction_core1 eAction_core1,
                                      uint32_t * pulPreviousNotificationValue_core1,
                                      BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;
#define xTaskNotifyFromISR_core1( xTaskToNotify_core1, ulValue_core1, eAction_core1, pxHigherPriorityTaskWoken_core1 ) \
    xTaskGenericNotifyFromISR_core1( ( xTaskToNotify_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( ulValue_core1 ), ( eAction_core1 ), NULL, ( pxHigherPriorityTaskWoken_core1 ) )
#define xTaskNotifyIndexedFromISR_core1( xTaskToNotify_core1, uxIndexToNotify_core1, ulValue_core1, eAction_core1, pxHigherPriorityTaskWoken_core1 ) \
    xTaskGenericNotifyFromISR_core1( ( xTaskToNotify_core1 ), ( uxIndexToNotify_core1 ), ( ulValue_core1 ), ( eAction_core1 ), NULL, ( pxHigherPriorityTaskWoken_core1 ) )

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskNotifyAndQueryIndexedFromISR_core1( TaskHandle_t_core1 xTaskToNotify_core1, UBaseType_t_core1 uxIndexToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1, uint32_t *pulPreviousNotificationValue_core1, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * BaseType_t_core1 xTaskNotifyAndQueryFromISR_core1( TaskHandle_t_core1 xTaskToNotify_core1, uint32_t ulValue_core1, eNotifyAction_core1 eAction_core1, uint32_t *pulPreviousNotificationValue_core1, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * @endcode
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * xTaskNotifyAndQueryIndexedFromISR_core1() performs the same operation as
 * xTaskNotifyIndexedFromISR_core1() with the addition that it also returns the
 * subject task_core1's prior notification value (the notification value at the time
 * the function is called rather than at the time the function returns) in the
 * additional pulPreviousNotifyValue_core1 parameter.
 *
 * xTaskNotifyAndQueryFromISR_core1() performs the same operation as
 * xTaskNotifyFromISR_core1() with the addition that it also returns the subject
 * task_core1's prior notification value (the notification value at the time the
 * function is called rather than at the time the function returns) in the
 * additional pulPreviousNotifyValue_core1 parameter.
 *
 * \defgroup xTaskNotifyAndQueryIndexedFromISR_core1 xTaskNotifyAndQueryIndexedFromISR_core1
 * \ingroup TaskNotifications
 */
#define xTaskNotifyAndQueryIndexedFromISR_core1( xTaskToNotify_core1, uxIndexToNotify_core1, ulValue_core1, eAction_core1, pulPreviousNotificationValue_core1, pxHigherPriorityTaskWoken_core1 ) \
    xTaskGenericNotifyFromISR_core1( ( xTaskToNotify_core1 ), ( uxIndexToNotify_core1 ), ( ulValue_core1 ), ( eAction_core1 ), ( pulPreviousNotificationValue_core1 ), ( pxHigherPriorityTaskWoken_core1 ) )
#define xTaskNotifyAndQueryFromISR_core1( xTaskToNotify_core1, ulValue_core1, eAction_core1, pulPreviousNotificationValue_core1, pxHigherPriorityTaskWoken_core1 ) \
    xTaskGenericNotifyFromISR_core1( ( xTaskToNotify_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( ulValue_core1 ), ( eAction_core1 ), ( pulPreviousNotificationValue_core1 ), ( pxHigherPriorityTaskWoken_core1 ) )

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskNotifyWaitIndexed_core1( UBaseType_t_core1 uxIndexToWaitOn_core1, uint32_t ulBitsToClearOnEntry_core1, uint32_t ulBitsToClearOnExit_core1, uint32_t *pulNotificationValue_core1, TickType_t_core1 xTicksToWait_core1 );
 *
 * BaseType_t_core1 xTaskNotifyWait_core1( uint32_t ulBitsToClearOnEntry_core1, uint32_t ulBitsToClearOnExit_core1, uint32_t *pulNotificationValue_core1, TickType_t_core1 xTicksToWait_core1 );
 * @endcode
 *
 * Waits for a direct to task_core1 notification to be pending at a given index within
 * an array of direct to task_core1 notifications.
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for this
 * function to be available.
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * Events can be sent to a task_core1 using an intermediary object.  Examples of such
 * objects are queues, semaphores, mutexes and event groups.  Task notifications
 * are a method of sending an event directly to a task_core1 without the need for such
 * an intermediary object.
 *
 * A notification sent to a task_core1 can optionally perform an action, such as
 * update, overwrite or increment one of the task_core1's notification values.  In
 * that way task_core1 notifications can be used to send data to a task_core1, or be used as
 * light weight and fast binary or counting semaphores.
 *
 * A notification sent to a task_core1 will remain pending until it is cleared by the
 * task_core1 calling xTaskNotifyWaitIndexed_core1() or ulTaskNotifyTakeIndexed_core1() (or their
 * un-indexed equivalents).  If the task_core1 was already in the Blocked state to
 * wait for a notification when the notification arrives then the task_core1 will
 * automatically be removed from the Blocked state (unblocked) and the
 * notification cleared.
 *
 * A task_core1 can use xTaskNotifyWaitIndexed_core1() to [optionally] block to wait for a
 * notification to be pending, or ulTaskNotifyTakeIndexed_core1() to [optionally] block
 * to wait for a notification value to have a non-zero value.  The task_core1 does
 * not consume any CPU time while it is in the Blocked state.
 *
 * **NOTE** Each notification within the array operates independently - a task_core1
 * can only block on one notification within the array at a time and will not be
 * unblocked by a notification sent to any other array index.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  xTaskNotifyWait_core1() is the original API function, and remains backward
 * compatible by always operating on the notification value at index 0 in the
 * array. Calling xTaskNotifyWait_core1() is equivalent to calling
 * xTaskNotifyWaitIndexed_core1() with the uxIndexToWaitOn_core1 parameter set to 0.
 *
 * @param uxIndexToWaitOn_core1 The index within the calling task_core1's array of
 * notification values on which the calling task_core1 will wait for a notification to
 * be received.  uxIndexToWaitOn_core1 must be less than
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.  xTaskNotifyWait_core1() does
 * not have this parameter and always waits for notifications on index 0.
 *
 * @param ulBitsToClearOnEntry_core1 Bits that are set in ulBitsToClearOnEntry_core1 value
 * will be cleared in the calling task_core1's notification value before the task_core1
 * checks to see if any notifications are pending, and optionally blocks if no
 * notifications are pending.  Setting ulBitsToClearOnEntry_core1 to ULONG_MAX (if
 * limits.h is included) or 0xffffffffUL (if limits.h is not included) will have
 * the effect of resetting the task_core1's notification value to 0.  Setting
 * ulBitsToClearOnEntry_core1 to 0 will leave the task_core1's notification value unchanged.
 *
 * @param ulBitsToClearOnExit_core1 If a notification is pending or received before
 * the calling task_core1 exits the xTaskNotifyWait_core1() function then the task_core1's
 * notification value (see the xTaskNotify_core1() API function) is passed out using
 * the pulNotificationValue_core1 parameter.  Then any bits that are set in
 * ulBitsToClearOnExit_core1 will be cleared in the task_core1's notification value (note
 * *pulNotificationValue_core1 is set before any bits are cleared).  Setting
 * ulBitsToClearOnExit_core1 to ULONG_MAX (if limits.h is included) or 0xffffffffUL
 * (if limits.h is not included) will have the effect of resetting the task_core1's
 * notification value to 0 before the function exits.  Setting
 * ulBitsToClearOnExit_core1 to 0 will leave the task_core1's notification value unchanged
 * when the function exits (in which case the value passed out in
 * pulNotificationValue_core1 will match the task_core1's notification value).
 *
 * @param pulNotificationValue_core1 Used to pass the task_core1's notification value out
 * of the function.  Note the value passed out will not be effected by the
 * clearing of any bits caused by ulBitsToClearOnExit_core1 being non-zero.
 *
 * @param xTicksToWait_core1 The maximum amount of time that the task_core1 should wait in
 * the Blocked state for a notification to be received, should a notification
 * not already be pending when xTaskNotifyWait_core1() was called.  The task_core1
 * will not consume any processing time while it is in the Blocked state.  This
 * is specified in kernel ticks, the macro pdMS_TO_TICKS_core1( value_in_ms ) can be
 * used to convert a time specified in milliseconds to a time specified in
 * ticks.
 *
 * @return If a notification was received (including notifications that were
 * already pending when xTaskNotifyWait_core1 was called) then pdPASS_core1 is
 * returned.  Otherwise pdFAIL_core1 is returned.
 *
 * \defgroup xTaskNotifyWaitIndexed_core1 xTaskNotifyWaitIndexed_core1
 * \ingroup TaskNotifications
 */
BaseType_t_core1 xTaskGenericNotifyWait_core1( UBaseType_t_core1 uxIndexToWaitOn_core1,
                                   uint32_t ulBitsToClearOnEntry_core1,
                                   uint32_t ulBitsToClearOnExit_core1,
                                   uint32_t * pulNotificationValue_core1,
                                   TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;
#define xTaskNotifyWait_core1( ulBitsToClearOnEntry_core1, ulBitsToClearOnExit_core1, pulNotificationValue_core1, xTicksToWait_core1 ) \
    xTaskGenericNotifyWait_core1( tskDEFAULT_INDEX_TO_NOTIFY_core1, ( ulBitsToClearOnEntry_core1 ), ( ulBitsToClearOnExit_core1 ), ( pulNotificationValue_core1 ), ( xTicksToWait_core1 ) )
#define xTaskNotifyWaitIndexed_core1( uxIndexToWaitOn_core1, ulBitsToClearOnEntry_core1, ulBitsToClearOnExit_core1, pulNotificationValue_core1, xTicksToWait_core1 ) \
    xTaskGenericNotifyWait_core1( ( uxIndexToWaitOn_core1 ), ( ulBitsToClearOnEntry_core1 ), ( ulBitsToClearOnExit_core1 ), ( pulNotificationValue_core1 ), ( xTicksToWait_core1 ) )

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskNotifyGiveIndexed_core1( TaskHandle_t_core1 xTaskToNotify_core1, UBaseType_t_core1 uxIndexToNotify_core1 );
 * BaseType_t_core1 xTaskNotifyGive_core1( TaskHandle_t_core1 xTaskToNotify_core1 );
 * @endcode
 *
 * Sends a direct to task_core1 notification to a particular index in the target
 * task_core1's notification array in a manner similar to giving a counting semaphore.
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for more details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for these
 * macros to be available.
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * Events can be sent to a task_core1 using an intermediary object.  Examples of such
 * objects are queues, semaphores, mutexes and event groups.  Task notifications
 * are a method of sending an event directly to a task_core1 without the need for such
 * an intermediary object.
 *
 * A notification sent to a task_core1 can optionally perform an action, such as
 * update, overwrite or increment one of the task_core1's notification values.  In
 * that way task_core1 notifications can be used to send data to a task_core1, or be used as
 * light weight and fast binary or counting semaphores.
 *
 * xTaskNotifyGiveIndexed_core1() is a helper macro intended for use when task_core1
 * notifications are used as light weight and faster binary or counting
 * semaphore equivalents.  Actual FreeRTOS_core1 semaphores are given using the
 * xSemaphoreGive_core1() API function, the equivalent action that instead uses a task_core1
 * notification is xTaskNotifyGiveIndexed_core1().
 *
 * When task_core1 notifications are being used as a binary or counting semaphore
 * equivalent then the task_core1 being notified should wait for the notification
 * using the ulTaskNotifyTakeIndexed_core1() API function rather than the
 * xTaskNotifyWaitIndexed_core1() API function.
 *
 * **NOTE** Each notification within the array operates independently - a task_core1
 * can only block on one notification within the array at a time and will not be
 * unblocked by a notification sent to any other array index.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  xTaskNotifyGive_core1() is the original API function, and remains backward
 * compatible by always operating on the notification value at index 0 in the
 * array. Calling xTaskNotifyGive_core1() is equivalent to calling
 * xTaskNotifyGiveIndexed_core1() with the uxIndexToNotify_core1 parameter set to 0.
 *
 * @param xTaskToNotify_core1 The handle of the task_core1 being notified.  The handle to a
 * task_core1 can be returned from the xTaskCreate_core1() API function used to create the
 * task_core1, and the handle of the currently running task_core1 can be obtained by calling
 * xTaskGetCurrentTaskHandle_core1().
 *
 * @param uxIndexToNotify_core1 The index within the target task_core1's array of
 * notification values to which the notification is to be sent.  uxIndexToNotify_core1
 * must be less than configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.  xTaskNotifyGive_core1()
 * does not have this parameter and always sends notifications to index 0.
 *
 * @return xTaskNotifyGive_core1() is a macro that calls xTaskNotify_core1() with the
 * eAction_core1 parameter set to eIncrement_core1 - so pdPASS_core1 is always returned.
 *
 * \defgroup xTaskNotifyGiveIndexed_core1 xTaskNotifyGiveIndexed_core1
 * \ingroup TaskNotifications
 */
#define xTaskNotifyGive_core1( xTaskToNotify_core1 ) \
    xTaskGenericNotify_core1( ( xTaskToNotify_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( 0 ), eIncrement_core1, NULL )
#define xTaskNotifyGiveIndexed_core1( xTaskToNotify_core1, uxIndexToNotify_core1 ) \
    xTaskGenericNotify_core1( ( xTaskToNotify_core1 ), ( uxIndexToNotify_core1 ), ( 0 ), eIncrement_core1, NULL )

/**
 * task_core1. h
 * @code{c}
 * void vTaskNotifyGiveIndexedFromISR_core1( TaskHandle_t_core1 xTaskHandle, UBaseType_t_core1 uxIndexToNotify_core1, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * void vTaskNotifyGiveFromISR_core1( TaskHandle_t_core1 xTaskHandle, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * @endcode
 *
 * A version of xTaskNotifyGiveIndexed_core1() that can be called from an interrupt
 * service routine (ISR).
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for more details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for this macro
 * to be available.
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * Events can be sent to a task_core1 using an intermediary object.  Examples of such
 * objects are queues, semaphores, mutexes and event groups.  Task notifications
 * are a method of sending an event directly to a task_core1 without the need for such
 * an intermediary object.
 *
 * A notification sent to a task_core1 can optionally perform an action, such as
 * update, overwrite or increment one of the task_core1's notification values.  In
 * that way task_core1 notifications can be used to send data to a task_core1, or be used as
 * light weight and fast binary or counting semaphores.
 *
 * vTaskNotifyGiveIndexedFromISR_core1() is intended for use when task_core1 notifications
 * are used as light weight and faster binary or counting semaphore equivalents.
 * Actual FreeRTOS_core1 semaphores are given from an ISR using the
 * xSemaphoreGiveFromISR_core1() API function, the equivalent action that instead uses
 * a task_core1 notification is vTaskNotifyGiveIndexedFromISR_core1().
 *
 * When task_core1 notifications are being used as a binary or counting semaphore
 * equivalent then the task_core1 being notified should wait for the notification
 * using the ulTaskNotifyTakeIndexed_core1() API function rather than the
 * xTaskNotifyWaitIndexed_core1() API function.
 *
 * **NOTE** Each notification within the array operates independently - a task_core1
 * can only block on one notification within the array at a time and will not be
 * unblocked by a notification sent to any other array index.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  xTaskNotifyFromISR_core1() is the original API function, and remains
 * backward compatible by always operating on the notification value at index 0
 * within the array. Calling xTaskNotifyGiveFromISR() is equivalent to calling
 * xTaskNotifyGiveIndexedFromISR() with the uxIndexToNotify_core1 parameter set to 0.
 *
 * @param xTaskToNotify_core1 The handle of the task_core1 being notified.  The handle to a
 * task_core1 can be returned from the xTaskCreate_core1() API function used to create the
 * task_core1, and the handle of the currently running task_core1 can be obtained by calling
 * xTaskGetCurrentTaskHandle_core1().
 *
 * @param uxIndexToNotify_core1 The index within the target task_core1's array of
 * notification values to which the notification is to be sent.  uxIndexToNotify_core1
 * must be less than configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.
 * xTaskNotifyGiveFromISR() does not have this parameter and always sends
 * notifications to index 0.
 *
 * @param pxHigherPriorityTaskWoken_core1  vTaskNotifyGiveFromISR_core1() will set
 * *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1 if sending the notification caused the
 * task_core1 to which the notification was sent to leave the Blocked state, and the
 * unblocked task_core1 has a priority higher than the currently running task_core1.  If
 * vTaskNotifyGiveFromISR_core1() sets this value to pdTRUE_core1 then a context switch
 * should be requested before the interrupt is exited.  How a context switch is
 * requested from an ISR is dependent on the port - see the documentation page
 * for the port in use.
 *
 * \defgroup vTaskNotifyGiveIndexedFromISR_core1 vTaskNotifyGiveIndexedFromISR_core1
 * \ingroup TaskNotifications
 */
void vTaskGenericNotifyGiveFromISR_core1( TaskHandle_t_core1 xTaskToNotify_core1,
                                    UBaseType_t_core1 uxIndexToNotify_core1,
                                    BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;
#define vTaskNotifyGiveFromISR_core1( xTaskToNotify_core1, pxHigherPriorityTaskWoken_core1 ) \
    vTaskGenericNotifyGiveFromISR_core1( ( xTaskToNotify_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( pxHigherPriorityTaskWoken_core1 ) )
#define vTaskNotifyGiveIndexedFromISR_core1( xTaskToNotify_core1, uxIndexToNotify_core1, pxHigherPriorityTaskWoken_core1 ) \
    vTaskGenericNotifyGiveFromISR_core1( ( xTaskToNotify_core1 ), ( uxIndexToNotify_core1 ), ( pxHigherPriorityTaskWoken_core1 ) )

/**
 * task_core1. h
 * @code{c}
 * uint32_t ulTaskNotifyTakeIndexed_core1( UBaseType_t_core1 uxIndexToWaitOn_core1, BaseType_t_core1 xClearCountOnExit_core1, TickType_t_core1 xTicksToWait_core1 );
 *
 * uint32_t ulTaskNotifyTake_core1( BaseType_t_core1 xClearCountOnExit_core1, TickType_t_core1 xTicksToWait_core1 );
 * @endcode
 *
 * Waits for a direct to task_core1 notification on a particular index in the calling
 * task_core1's notification array in a manner similar to taking a counting semaphore.
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for this
 * function to be available.
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * Events can be sent to a task_core1 using an intermediary object.  Examples of such
 * objects are queues, semaphores, mutexes and event groups.  Task notifications
 * are a method of sending an event directly to a task_core1 without the need for such
 * an intermediary object.
 *
 * A notification sent to a task_core1 can optionally perform an action, such as
 * update, overwrite or increment one of the task_core1's notification values.  In
 * that way task_core1 notifications can be used to send data to a task_core1, or be used as
 * light weight and fast binary or counting semaphores.
 *
 * ulTaskNotifyTakeIndexed_core1() is intended for use when a task_core1 notification is
 * used as a faster and lighter weight binary or counting semaphore alternative.
 * Actual FreeRTOS_core1 semaphores are taken using the xSemaphoreTake_core1() API function,
 * the equivalent action that instead uses a task_core1 notification is
 * ulTaskNotifyTakeIndexed_core1().
 *
 * When a task_core1 is using its notification value as a binary or counting semaphore
 * other tasks should send notifications to it using the xTaskNotifyGiveIndexed_core1()
 * macro, or xTaskNotifyIndex() function with the eAction_core1 parameter set to
 * eIncrement_core1.
 *
 * ulTaskNotifyTakeIndexed_core1() can either clear the task_core1's notification value at
 * the array index specified by the uxIndexToWaitOn_core1 parameter to zero on exit,
 * in which case the notification value acts like a binary semaphore, or
 * decrement the notification value on exit, in which case the notification
 * value acts like a counting semaphore.
 *
 * A task_core1 can use ulTaskNotifyTakeIndexed_core1() to [optionally] block to wait for
 * a notification.  The task_core1 does not consume any CPU time while it is in the
 * Blocked state.
 *
 * Where as xTaskNotifyWaitIndexed_core1() will return when a notification is pending,
 * ulTaskNotifyTakeIndexed_core1() will return when the task_core1's notification value is
 * not zero.
 *
 * **NOTE** Each notification within the array operates independently - a task_core1
 * can only block on one notification within the array at a time and will not be
 * unblocked by a notification sent to any other array index.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  ulTaskNotifyTake_core1() is the original API function, and remains backward
 * compatible by always operating on the notification value at index 0 in the
 * array. Calling ulTaskNotifyTake_core1() is equivalent to calling
 * ulTaskNotifyTakeIndexed_core1() with the uxIndexToWaitOn_core1 parameter set to 0.
 *
 * @param uxIndexToWaitOn_core1 The index within the calling task_core1's array of
 * notification values on which the calling task_core1 will wait for a notification to
 * be non-zero.  uxIndexToWaitOn_core1 must be less than
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.  xTaskNotifyTake() does
 * not have this parameter and always waits for notifications on index 0.
 *
 * @param xClearCountOnExit_core1 if xClearCountOnExit_core1 is pdFALSE_core1 then the task_core1's
 * notification value is decremented when the function exits.  In this way the
 * notification value acts like a counting semaphore.  If xClearCountOnExit_core1 is
 * not pdFALSE_core1 then the task_core1's notification value is cleared to zero when the
 * function exits.  In this way the notification value acts like a binary
 * semaphore.
 *
 * @param xTicksToWait_core1 The maximum amount of time that the task_core1 should wait in
 * the Blocked state for the task_core1's notification value to be greater than zero,
 * should the count not already be greater than zero when
 * ulTaskNotifyTake_core1() was called.  The task_core1 will not consume any processing
 * time while it is in the Blocked state.  This is specified in kernel ticks,
 * the macro pdMS_TO_TICKS_core1( value_in_ms ) can be used to convert a time
 * specified in milliseconds to a time specified in ticks.
 *
 * @return The task_core1's notification count before it is either cleared to zero or
 * decremented (see the xClearCountOnExit_core1 parameter).
 *
 * \defgroup ulTaskNotifyTakeIndexed_core1 ulTaskNotifyTakeIndexed_core1
 * \ingroup TaskNotifications
 */
uint32_t ulTaskGenericNotifyTake_core1( UBaseType_t_core1 uxIndexToWaitOn_core1,
                                  BaseType_t_core1 xClearCountOnExit_core1,
                                  TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;
#define ulTaskNotifyTake_core1( xClearCountOnExit_core1, xTicksToWait_core1 ) \
    ulTaskGenericNotifyTake_core1( ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( xClearCountOnExit_core1 ), ( xTicksToWait_core1 ) )
#define ulTaskNotifyTakeIndexed_core1( uxIndexToWaitOn_core1, xClearCountOnExit_core1, xTicksToWait_core1 ) \
    ulTaskGenericNotifyTake_core1( ( uxIndexToWaitOn_core1 ), ( xClearCountOnExit_core1 ), ( xTicksToWait_core1 ) )

/**
 * task_core1. h
 * @code{c}
 * BaseType_t_core1 xTaskNotifyStateClearIndexed_core1( TaskHandle_t_core1 xTask_core1, UBaseType_t_core1 uxIndexToCLear );
 *
 * BaseType_t_core1 xTaskNotifyStateClear_core1( TaskHandle_t_core1 xTask_core1 );
 * @endcode
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for these
 * functions to be available.
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * If a notification is sent to an index within the array of notifications then
 * the notification at that index is said to be 'pending' until it is read or
 * explicitly cleared by the receiving task_core1.  xTaskNotifyStateClearIndexed_core1()
 * is the function that clears a pending notification without reading the
 * notification value.  The notification value at the same array index is not
 * altered.  Set xTask_core1 to NULL to clear the notification state of the calling
 * task_core1.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  xTaskNotifyStateClear_core1() is the original API function, and remains
 * backward compatible by always operating on the notification value at index 0
 * within the array. Calling xTaskNotifyStateClear_core1() is equivalent to calling
 * xTaskNotifyStateClearIndexed_core1() with the uxIndexToNotify_core1 parameter set to 0.
 *
 * @param xTask_core1 The handle of the RTOS task_core1 that will have a notification state
 * cleared.  Set xTask_core1 to NULL to clear a notification state in the calling
 * task_core1.  To obtain a task_core1's handle create the task_core1 using xTaskCreate_core1() and
 * make use of the pxCreatedTask_core1 parameter, or create the task_core1 using
 * xTaskCreateStatic_core1() and store the returned value, or use the task_core1's name in
 * a call to xTaskGetHandle_core1().
 *
 * @param uxIndexToClear_core1 The index within the target task_core1's array of
 * notification values to act upon.  For example, setting uxIndexToClear_core1 to 1
 * will clear the state of the notification at index 1 within the array.
 * uxIndexToClear_core1 must be less than configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.
 * ulTaskNotifyStateClear() does not have this parameter and always acts on the
 * notification at index 0.
 *
 * @return pdTRUE_core1 if the task_core1's notification state was set to
 * eNotWaitingNotification, otherwise pdFALSE_core1.
 *
 * \defgroup xTaskNotifyStateClearIndexed_core1 xTaskNotifyStateClearIndexed_core1
 * \ingroup TaskNotifications
 */
BaseType_t_core1 xTaskGenericNotifyStateClear_core1( TaskHandle_t_core1 xTask_core1,
                                         UBaseType_t_core1 uxIndexToClear_core1 ) PRIVILEGED_FUNCTION_core1;
#define xTaskNotifyStateClear_core1( xTask_core1 ) \
    xTaskGenericNotifyStateClear_core1( ( xTask_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ) )
#define xTaskNotifyStateClearIndexed_core1( xTask_core1, uxIndexToClear_core1 ) \
    xTaskGenericNotifyStateClear_core1( ( xTask_core1 ), ( uxIndexToClear_core1 ) )

/**
 * task_core1. h
 * @code{c}
 * uint32_t ulTaskNotifyValueClearIndexed_core1( TaskHandle_t_core1 xTask_core1, UBaseType_t_core1 uxIndexToClear_core1, uint32_t ulBitsToClear_core1 );
 *
 * uint32_t ulTaskNotifyValueClear_core1( TaskHandle_t_core1 xTask_core1, uint32_t ulBitsToClear_core1 );
 * @endcode
 *
 * See https://www.FreeRTOS_core1.org/RTOS-task_core1-notifications.html for details.
 *
 * configUSE_TASK_NOTIFICATIONS_core1 must be undefined or defined as 1 for these
 * functions to be available.
 *
 * Each task_core1 has a private array of "notification values" (or 'notifications'),
 * each of which is a 32-bit unsigned integer (uint32_t).  The constant
 * configTASK_NOTIFICATION_ARRAY_ENTRIES_core1 sets the number of indexes in the
 * array, and (for backward compatibility) defaults to 1 if left undefined.
 * Prior to FreeRTOS_core1 V10.4.0 there was only one notification value per task_core1.
 *
 * ulTaskNotifyValueClearIndexed_core1() clears the bits specified by the
 * ulBitsToClear_core1 bit mask in the notification value at array index uxIndexToClear_core1
 * of the task_core1 referenced by xTask_core1.
 *
 * Backward compatibility information:
 * Prior to FreeRTOS_core1 V10.4.0 each task_core1 had a single "notification value", and
 * all task_core1 notification API functions operated on that value. Replacing the
 * single notification value with an array of notification values necessitated a
 * new set of API functions that could address specific notifications within the
 * array.  ulTaskNotifyValueClear_core1() is the original API function, and remains
 * backward compatible by always operating on the notification value at index 0
 * within the array. Calling ulTaskNotifyValueClear_core1() is equivalent to calling
 * ulTaskNotifyValueClearIndexed_core1() with the uxIndexToClear_core1 parameter set to 0.
 *
 * @param xTask_core1 The handle of the RTOS task_core1 that will have bits in one of its
 * notification values cleared. Set xTask_core1 to NULL to clear bits in a
 * notification value of the calling task_core1.  To obtain a task_core1's handle create the
 * task_core1 using xTaskCreate_core1() and make use of the pxCreatedTask_core1 parameter, or
 * create the task_core1 using xTaskCreateStatic_core1() and store the returned value, or
 * use the task_core1's name in a call to xTaskGetHandle_core1().
 *
 * @param uxIndexToClear_core1 The index within the target task_core1's array of
 * notification values in which to clear the bits.  uxIndexToClear_core1
 * must be less than configTASK_NOTIFICATION_ARRAY_ENTRIES_core1.
 * ulTaskNotifyValueClear_core1() does not have this parameter and always clears bits
 * in the notification value at index 0.
 *
 * @param ulBitsToClear_core1 Bit mask of the bits to clear in the notification value of
 * xTask_core1. Set a bit to 1 to clear the corresponding bits in the task_core1's notification
 * value. Set ulBitsToClear_core1 to 0xffffffff (UINT_MAX on 32-bit architectures) to clear
 * the notification value to 0.  Set ulBitsToClear_core1 to 0 to query the task_core1's
 * notification value without clearing any bits.
 *
 *
 * @return The value of the target task_core1's notification value before the bits
 * specified by ulBitsToClear_core1 were cleared.
 * \defgroup ulTaskNotifyValueClear_core1 ulTaskNotifyValueClear_core1
 * \ingroup TaskNotifications
 */
uint32_t ulTaskGenericNotifyValueClear_core1( TaskHandle_t_core1 xTask_core1,
                                        UBaseType_t_core1 uxIndexToClear_core1,
                                        uint32_t ulBitsToClear_core1 ) PRIVILEGED_FUNCTION_core1;
#define ulTaskNotifyValueClear_core1( xTask_core1, ulBitsToClear_core1 ) \
    ulTaskGenericNotifyValueClear_core1( ( xTask_core1 ), ( tskDEFAULT_INDEX_TO_NOTIFY_core1 ), ( ulBitsToClear_core1 ) )
#define ulTaskNotifyValueClearIndexed_core1( xTask_core1, uxIndexToClear_core1, ulBitsToClear_core1 ) \
    ulTaskGenericNotifyValueClear_core1( ( xTask_core1 ), ( uxIndexToClear_core1 ), ( ulBitsToClear_core1 ) )

/**
 * task_core1.h
 * @code{c}
 * void vTaskSetTimeOutState_core1( TimeOut_t_core1 * const pxTimeOut_core1 );
 * @endcode
 *
 * Capture the current time for future use with xTaskCheckForTimeOut_core1().
 *
 * @param pxTimeOut_core1 Pointer to a timeout object into which the current time
 * is to be captured.  The captured time includes the tick count and the number
 * of times the tick count has overflowed since the system first booted.
 * \defgroup vTaskSetTimeOutState_core1 vTaskSetTimeOutState_core1
 * \ingroup TaskCtrl
 */
void vTaskSetTimeOutState_core1( TimeOut_t_core1 * const pxTimeOut_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1.h
 * @code{c}
 * BaseType_t_core1 xTaskCheckForTimeOut_core1( TimeOut_t_core1 * const pxTimeOut_core1, TickType_t_core1 * const pxTicksToWait_core1 );
 * @endcode
 *
 * Determines if pxTicksToWait_core1 ticks has passed since a time was captured
 * using a call to vTaskSetTimeOutState_core1().  The captured time includes the tick
 * count and the number of times the tick count has overflowed.
 *
 * @param pxTimeOut_core1 The time status as captured previously using
 * vTaskSetTimeOutState_core1. If the timeout has not yet occurred, it is updated
 * to reflect the current time status.
 * @param pxTicksToWait_core1 The number of ticks to check for timeout i.e. if
 * pxTicksToWait_core1 ticks have passed since pxTimeOut_core1 was last updated (either by
 * vTaskSetTimeOutState_core1() or xTaskCheckForTimeOut_core1()), the timeout has occurred.
 * If the timeout has not occurred, pxTicksToWait_core1 is updated to reflect the
 * number of remaining ticks.
 *
 * @return If timeout has occurred, pdTRUE_core1 is returned. Otherwise pdFALSE_core1 is
 * returned and pxTicksToWait_core1 is updated to reflect the number of remaining
 * ticks.
 *
 * @see https://www.FreeRTOS_core1.org/xTaskCheckForTimeOut_core1.html
 *
 * Example Usage:
 * @code{c}
 *  // Driver library function used to receive uxWantedBytes from an Rx buffer
 *  // that is filled by a UART interrupt. If there are not enough bytes in the
 *  // Rx buffer then the task_core1 enters the Blocked state until it is notified that
 *  // more data has been placed into the buffer. If there is still not enough
 *  // data then the task_core1 re-enters the Blocked state, and xTaskCheckForTimeOut_core1()
 *  // is used to re-calculate the Block time to ensure the total amount of time
 *  // spent in the Blocked state does not exceed MAX_TIME_TO_WAIT. This
 *  // continues until either the buffer contains at least uxWantedBytes bytes,
 *  // or the total amount of time spent in the Blocked state reaches
 *  // MAX_TIME_TO_WAIT - at which point the task_core1 reads however many bytes are
 *  // available up to a maximum of uxWantedBytes.
 *
 *  size_t xUART_Receive( uint8_t *pucBuffer, size_t uxWantedBytes )
 *  {
 *  size_t uxReceived = 0;
 *  TickType_t_core1 xTicksToWait_core1 = MAX_TIME_TO_WAIT;
 *  TimeOut_t_core1 xTimeOut;
 *
 *      // Initialize xTimeOut.  This records the time at which this function
 *      // was entered.
 *      vTaskSetTimeOutState_core1( &xTimeOut );
 *
 *      // Loop until the buffer contains the wanted number of bytes, or a
 *      // timeout occurs.
 *      while( UART_bytes_in_rx_buffer( pxUARTInstance ) < uxWantedBytes )
 *      {
 *          // The buffer didn't contain enough data so this task_core1 is going to
 *          // enter the Blocked state. Adjusting xTicksToWait_core1 to account for
 *          // any time that has been spent in the Blocked state within this
 *          // function so far to ensure the total amount of time spent in the
 *          // Blocked state does not exceed MAX_TIME_TO_WAIT.
 *          if( xTaskCheckForTimeOut_core1( &xTimeOut, &xTicksToWait_core1 ) != pdFALSE_core1 )
 *          {
 *              //Timed out before the wanted number of bytes were available,
 *              // exit the loop.
 *              break;
 *          }
 *
 *          // Wait for a maximum of xTicksToWait_core1 ticks to be notified that the
 *          // receive interrupt has placed more data into the buffer.
 *          ulTaskNotifyTake_core1( pdTRUE_core1, xTicksToWait_core1 );
 *      }
 *
 *      // Attempt to read uxWantedBytes from the receive buffer into pucBuffer.
 *      // The actual number of bytes read (which might be less than
 *      // uxWantedBytes) is returned.
 *      uxReceived = UART_read_from_receive_buffer( pxUARTInstance,
 *                                                  pucBuffer,
 *                                                  uxWantedBytes );
 *
 *      return uxReceived;
 *  }
 * @endcode
 * \defgroup xTaskCheckForTimeOut_core1 xTaskCheckForTimeOut_core1
 * \ingroup TaskCtrl
 */
BaseType_t_core1 xTaskCheckForTimeOut_core1( TimeOut_t_core1 * const pxTimeOut_core1,
                                 TickType_t_core1 * const pxTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * task_core1.h
 * @code{c}
 * BaseType_t_core1 xTaskCatchUpTicks_core1( TickType_t_core1 xTicksToCatchUp );
 * @endcode
 *
 * This function corrects the tick count value after the application code has held
 * interrupts disabled for an extended period resulting in tick interrupts having
 * been missed.
 *
 * This function is similar to vTaskStepTick_core1(), however, unlike
 * vTaskStepTick_core1(), xTaskCatchUpTicks_core1() may move the tick count forward past a
 * time at which a task_core1 should be removed from the blocked state.  That means
 * tasks may have to be removed from the blocked state as the tick count is
 * moved.
 *
 * @param xTicksToCatchUp The number of tick interrupts that have been missed due to
 * interrupts being disabled.  Its value is not computed automatically, so must be
 * computed by the application writer.
 *
 * @return pdTRUE_core1 if moving the tick count forward resulted in a task_core1 leaving the
 * blocked state and a context switch being performed.  Otherwise pdFALSE_core1.
 *
 * \defgroup xTaskCatchUpTicks_core1 xTaskCatchUpTicks_core1
 * \ingroup TaskCtrl
 */
BaseType_t_core1 xTaskCatchUpTicks_core1( TickType_t_core1 xTicksToCatchUp ) PRIVILEGED_FUNCTION_core1;


/*-----------------------------------------------------------
* SCHEDULER INTERNALS AVAILABLE FOR PORTING PURPOSES
*----------------------------------------------------------*/

/*
 * THIS FUNCTION MUST NOT BE USED FROM APPLICATION CODE.  IT IS ONLY
 * INTENDED FOR USE WHEN IMPLEMENTING A PORT OF THE SCHEDULER AND IS
 * AN INTERFACE WHICH IS FOR THE EXCLUSIVE USE OF THE SCHEDULER.
 *
 * Called from the real time kernel tick (either preemptive or cooperative),
 * this increments the tick count and checks if any tasks that are blocked
 * for a finite period required removing from a blocked list and placing on
 * a ready list.  If a non-zero value is returned then a context switch is
 * required because either:
 *   + A task_core1 was removed from a blocked list because its timeout had expired,
 *     or
 *   + Time slicing is in use and there is a task_core1 of equal priority to the
 *     currently running task_core1.
 */
BaseType_t_core1 xTaskIncrementTick_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * THIS FUNCTION MUST NOT BE USED FROM APPLICATION CODE.  IT IS AN
 * INTERFACE WHICH IS FOR THE EXCLUSIVE USE OF THE SCHEDULER.
 *
 * THIS FUNCTION MUST BE CALLED WITH INTERRUPTS DISABLED.
 *
 * Removes the calling task_core1 from the ready list and places it both
 * on the list of tasks waiting for a particular event, and the
 * list of delayed tasks.  The task_core1 will be removed from both lists
 * and replaced on the ready list should either the event occur (and
 * there be no higher priority tasks waiting on the same event) or
 * the delay period expires.
 *
 * The 'unordered' version replaces the event list item value with the
 * xItemValue_core1 value, and inserts the list item at the end of the list.
 *
 * The 'ordered' version uses the existing event list item value (which is the
 * owning task_core1's priority) to insert the list item into the event list in task_core1
 * priority order.
 *
 * @param pxEventList_core1 The list containing tasks that are blocked waiting
 * for the event to occur.
 *
 * @param xItemValue_core1 The item value to use for the event list item when the
 * event list is not ordered by task_core1 priority.
 *
 * @param xTicksToWait_core1 The maximum amount of time that the task_core1 should wait
 * for the event to occur.  This is specified in kernel ticks, the constant
 * portTICK_PERIOD_MS_core1 can be used to convert kernel ticks into a real time
 * period.
 */
void vTaskPlaceOnEventList_core1( List_t_core1 * const pxEventList_core1,
                            const TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;
void vTaskPlaceOnUnorderedEventList_core1( List_t_core1 * pxEventList_core1,
                                     const TickType_t_core1 xItemValue_core1,
                                     const TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * THIS FUNCTION MUST NOT BE USED FROM APPLICATION CODE.  IT IS AN
 * INTERFACE WHICH IS FOR THE EXCLUSIVE USE OF THE SCHEDULER.
 *
 * THIS FUNCTION MUST BE CALLED WITH INTERRUPTS DISABLED.
 *
 * This function performs nearly the same function as vTaskPlaceOnEventList_core1().
 * The difference being that this function does not permit tasks to block
 * indefinitely, whereas vTaskPlaceOnEventList_core1() does.
 *
 */
void vTaskPlaceOnEventListRestricted_core1( List_t_core1 * const pxEventList_core1,
                                      TickType_t_core1 xTicksToWait_core1,
                                      const BaseType_t_core1 xWaitIndefinitely_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * THIS FUNCTION MUST NOT BE USED FROM APPLICATION CODE.  IT IS AN
 * INTERFACE WHICH IS FOR THE EXCLUSIVE USE OF THE SCHEDULER.
 *
 * THIS FUNCTION MUST BE CALLED WITH INTERRUPTS DISABLED.
 *
 * Removes a task_core1 from both the specified event list and the list of blocked
 * tasks, and places it on a ready queue.
 *
 * xTaskRemoveFromEventList_core1()/vTaskRemoveFromUnorderedEventList_core1() will be called
 * if either an event occurs to unblock a task_core1, or the block timeout period
 * expires.
 *
 * xTaskRemoveFromEventList_core1() is used when the event list is in task_core1 priority
 * order.  It removes the list item from the head of the event list as that will
 * have the highest priority owning task_core1 of all the tasks on the event list.
 * vTaskRemoveFromUnorderedEventList_core1() is used when the event list is not
 * ordered and the event list items hold something other than the owning tasks
 * priority.  In this case the event list item value is updated to the value
 * passed in the xItemValue_core1 parameter.
 *
 * @return pdTRUE_core1 if the task_core1 being removed has a higher priority than the task_core1
 * making the call, otherwise pdFALSE_core1.
 */
BaseType_t_core1 xTaskRemoveFromEventList_core1( const List_t_core1 * const pxEventList_core1 ) PRIVILEGED_FUNCTION_core1;
void vTaskRemoveFromUnorderedEventList_core1( ListItem_t_core1 * pxEventListItem_core1,
                                        const TickType_t_core1 xItemValue_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * THIS FUNCTION MUST NOT BE USED FROM APPLICATION CODE.  IT IS ONLY
 * INTENDED FOR USE WHEN IMPLEMENTING A PORT OF THE SCHEDULER AND IS
 * AN INTERFACE WHICH IS FOR THE EXCLUSIVE USE OF THE SCHEDULER.
 *
 * Sets the pointer to the current TCB to the TCB of the highest priority task_core1
 * that is ready to run.
 */
portDONT_DISCARD_core1 void vTaskSwitchContext_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * THESE FUNCTIONS MUST NOT BE USED FROM APPLICATION CODE.  THEY ARE USED BY
 * THE EVENT BITS MODULE.
 */
TickType_t_core1 uxTaskResetEventItemValue_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * Return the handle of the calling task_core1.
 */
TaskHandle_t_core1 xTaskGetCurrentTaskHandle_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * Shortcut used by the queue implementation to prevent unnecessary call to
 * taskYIELD_core1();
 */
void vTaskMissedYield_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * Returns the scheduler state as taskSCHEDULER_RUNNING_core1,
 * taskSCHEDULER_NOT_STARTED_core1 or taskSCHEDULER_SUSPENDED_core1.
 */
BaseType_t_core1 xTaskGetSchedulerState_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * Raises the priority of the mutex holder to that of the calling task_core1 should
 * the mutex holder have a priority less than the calling task_core1.
 */
BaseType_t_core1 xTaskPriorityInherit_core1( TaskHandle_t_core1 const pxMutexHolder_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Set the priority of a task_core1 back to its proper priority in the case that it
 * inherited a higher priority while it was holding a semaphore.
 */
BaseType_t_core1 xTaskPriorityDisinherit_core1( TaskHandle_t_core1 const pxMutexHolder_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * If a higher priority task_core1 attempting to obtain a mutex caused a lower
 * priority task_core1 to inherit the higher priority task_core1's priority - but the higher
 * priority task_core1 then timed out without obtaining the mutex, then the lower
 * priority task_core1 will disinherit the priority again - but only down as far as
 * the highest priority task_core1 that is still waiting for the mutex (if there were
 * more than one task_core1 waiting for the mutex).
 */
void vTaskPriorityDisinheritAfterTimeout_core1( TaskHandle_t_core1 const pxMutexHolder_core1,
                                          UBaseType_t_core1 uxHighestPriorityWaitingTask_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Get the uxTaskNumber_core1 assigned to the task_core1 referenced by the xTask_core1 parameter.
 */
UBaseType_t_core1 uxTaskGetTaskNumber_core1( TaskHandle_t_core1 xTask_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Set the uxTaskNumber_core1 of the task_core1 referenced by the xTask_core1 parameter to
 * uxHandle_core1.
 */
void vTaskSetTaskNumber_core1( TaskHandle_t_core1 xTask_core1,
                         const UBaseType_t_core1 uxHandle_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Only available when configUSE_TICKLESS_IDLE_core1 is set to 1.
 * If tickless mode is being used, or a low power mode is implemented, then
 * the tick interrupt will not execute during idle periods.  When this is the
 * case, the tick count value maintained by the scheduler needs to be kept up
 * to date with the actual execution time by being skipped forward by a time
 * equal to the idle period.
 */
void vTaskStepTick_core1( TickType_t_core1 xTicksToJump_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Only available when configUSE_TICKLESS_IDLE_core1 is set to 1.
 * Provided for use within portSUPPRESS_TICKS_AND_SLEEP_core1() to allow the port
 * specific sleep function to determine if it is ok to proceed with the sleep,
 * and if it is ok to proceed, if it is ok to sleep indefinitely.
 *
 * This function is necessary because portSUPPRESS_TICKS_AND_SLEEP_core1() is only
 * called with the scheduler suspended, not from within a critical section.  It
 * is therefore possible for an interrupt to request a context switch between
 * portSUPPRESS_TICKS_AND_SLEEP_core1() and the low power mode actually being
 * entered.  eTaskConfirmSleepModeStatus_core1() should be called from a short
 * critical section between the timer being stopped and the sleep mode being
 * entered to ensure it is ok to proceed into the sleep mode.
 */
eSleepModeStatus_core1 eTaskConfirmSleepModeStatus_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * For internal use only.  Increment the mutex held count when a mutex is
 * taken and return the handle of the task_core1 that has taken the mutex.
 */
TaskHandle_t_core1 pvTaskIncrementMutexHeldCount_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * For internal use only.  Same as vTaskSetTimeOutState_core1(), but without a critical
 * section.
 */
void vTaskInternalSetTimeOutState_core1( TimeOut_t_core1 * const pxTimeOut_core1 ) PRIVILEGED_FUNCTION_core1;


/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */
#endif /* INC_TASK_H */
