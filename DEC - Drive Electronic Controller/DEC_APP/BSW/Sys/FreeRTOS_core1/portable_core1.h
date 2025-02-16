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

/*-----------------------------------------------------------
* Portable layer API.  Each function must be defined for each port.
*----------------------------------------------------------*/

#ifndef PORTABLE_CORE1_H
#define PORTABLE_CORE1_H

/* Each FreeRTOS_core1 port has a unique portmacro.h header file.  Originally a
 * pre-processor definition was used to ensure the pre-processor found the correct
 * portmacro.h file for the port being used.  That scheme was deprecated in favour
 * of setting the compiler's include path such that it found the correct
 * portmacro.h file - removing the need for the constant and allowing the
 * portmacro.h file to be located anywhere in relation to the port being used.
 * Purely for reasons of backward compatibility the old method is still valid, but
 * to make it clear that new projects should not use it, support for the port
 * specific constants has been moved into the deprecated_definitions.h header
 * file. */
#include "deprecated_definitions_core1.h"

/* If portENTER_CRITICAL_core1 is not defined then including deprecated_definitions.h
 * did not result in a portmacro.h header file being included - and it should be
 * included here.  In this case the path to the correct portmacro.h header file
 * must be set in the compiler's include path. */
#ifndef portENTER_CRITICAL_core1
    #include "portmacro_core1.h"
#endif

#if portBYTE_ALIGNMENT_core1 == 32
    #define portBYTE_ALIGNMENT_MASK_core1    ( 0x001f )
#elif portBYTE_ALIGNMENT_core1 == 16
    #define portBYTE_ALIGNMENT_MASK_core1    ( 0x000f )
#elif portBYTE_ALIGNMENT_core1 == 8
    #define portBYTE_ALIGNMENT_MASK_core1    ( 0x0007 )
#elif portBYTE_ALIGNMENT_core1 == 4
    #define portBYTE_ALIGNMENT_MASK_core1    ( 0x0003 )
#elif portBYTE_ALIGNMENT_core1 == 2
    #define portBYTE_ALIGNMENT_MASK_core1    ( 0x0001 )
#elif portBYTE_ALIGNMENT_core1 == 1
    #define portBYTE_ALIGNMENT_MASK_core1    ( 0x0000 )
#else /* if portBYTE_ALIGNMENT_core1 == 32 */
    #error "Invalid portBYTE_ALIGNMENT_core1 definition"
#endif /* if portBYTE_ALIGNMENT_core1 == 32 */

#ifndef portUSING_MPU_WRAPPERS_core1
    #define portUSING_MPU_WRAPPERS_core1    0
#endif

#ifndef portNUM_CONFIGURABLE_REGIONS_core1
    #define portNUM_CONFIGURABLE_REGIONS_core1    1
#endif

#ifndef portHAS_STACK_OVERFLOW_CHECKING_core1
    #define portHAS_STACK_OVERFLOW_CHECKING_core1    0
#endif

#ifndef portARCH_NAME_core1
    #define portARCH_NAME_core1    NULL
#endif

#ifndef configSTACK_ALLOCATION_FROM_SEPARATE_HEAP_core1
    /* Defaults to 0 for backward compatibility. */
    #define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP_core1    0
#endif

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

#include "mpu_wrappers_core1.h"

/*
 * Setup the stack of a new task_core1 so it is ready to be placed under the
 * scheduler control.  The registers have to be placed on the stack in
 * the order that the port expects to find them.
 *
 */
#if ( portUSING_MPU_WRAPPERS_core1 == 1 )
    #if ( portHAS_STACK_OVERFLOW_CHECKING_core1 == 1 )
        StackType_t_core1 * pxPortInitialiseStack_core1( StackType_t_core1 * pxTopOfStack_core1,
                                             StackType_t_core1 * pxEndOfStack_core1,
                                             TaskFunction_t_core1 pxCode_core1,
                                             void * pvParameters_core1,
                                             BaseType_t_core1 xRunPrivileged_core1 ) PRIVILEGED_FUNCTION_core1;
    #else
        StackType_t_core1 * pxPortInitialiseStack_core1( StackType_t_core1 * pxTopOfStack_core1,
                                             TaskFunction_t_core1 pxCode_core1,
                                             void * pvParameters_core1,
                                             BaseType_t_core1 xRunPrivileged_core1 ) PRIVILEGED_FUNCTION_core1;
    #endif
#else /* if ( portUSING_MPU_WRAPPERS_core1 == 1 ) */
    #if ( portHAS_STACK_OVERFLOW_CHECKING_core1 == 1 )
        StackType_t_core1 * pxPortInitialiseStack_core1( StackType_t_core1 * pxTopOfStack_core1,
                                             StackType_t_core1 * pxEndOfStack_core1,
                                             TaskFunction_t_core1 pxCode_core1,
                                             void * pvParameters_core1 ) PRIVILEGED_FUNCTION_core1;
    #else
        StackType_t_core1 * pxPortInitialiseStack_core1( StackType_t_core1 * pxTopOfStack_core1,
                                             TaskFunction_t_core1 pxCode_core1,
                                             void * pvParameters_core1 ) PRIVILEGED_FUNCTION_core1;
    #endif
#endif /* if ( portUSING_MPU_WRAPPERS_core1 == 1 ) */

/* Used by heap_5.c to define the start address and size of each memory region
 * that together comprise the total FreeRTOS_core1 heap space. */
typedef struct HeapRegion_core1
{
    uint8_t * pucStartAddress_core1;
    size_t xSizeInBytes_core1;
} HeapRegion_t_core1;

/* Used to pass information about the heap out of vPortGetHeapStats_core1(). */
typedef struct xHeapStats_core1
{
    size_t xAvailableHeapSpaceInBytes_core1;      /* The total heap size currently available - this is the sum of all the free blocks, not the largest block that can be allocated. */
    size_t xSizeOfLargestFreeBlockInBytes_core1;  /* The maximum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats_core1() is called. */
    size_t xSizeOfSmallestFreeBlockInBytes_core1; /* The minimum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats_core1() is called. */
    size_t xNumberOfFreeBlocks_core1;             /* The number of free memory blocks within the heap at the time vPortGetHeapStats_core1() is called. */
    size_t xMinimumEverFreeBytesRemaining_core1;  /* The minimum amount of total free memory (sum of all free blocks) there has been in the heap since the system booted. */
    size_t xNumberOfSuccessfulAllocations_core1;  /* The number of calls to pvPortMalloc_core1() that have returned a valid memory block. */
    size_t xNumberOfSuccessfulFrees_core1;        /* The number of calls to vPortFree_core1() that has successfully freed a block of memory. */
} HeapStats_t_core1;

/*
 * Used to define multiple heap regions for use by heap_5.c.  This function
 * must be called before any calls to pvPortMalloc_core1() - not creating a task_core1,
 * queue, semaphore, mutex, software timer, event group, etc. will result in
 * pvPortMalloc_core1 being called.
 *
 * pxHeapRegions_core1 passes in an array of HeapRegion_t_core1 structures - each of which
 * defines a region of memory that can be used as the heap.  The array is
 * terminated by a HeapRegions_t structure that has a size of 0.  The region
 * with the lowest start address must appear first in the array.
 */
void vPortDefineHeapRegions_core1( const HeapRegion_t_core1 * const pxHeapRegions_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Returns a HeapStats_t_core1 structure filled with information about the current
 * heap state.
 */
void vPortGetHeapStats_core1( HeapStats_t_core1 * pxHeapStats_core1 );

/*
 * Map to the memory management routines required for the port.
 */
void * pvPortMalloc_core1( size_t xSize_core1 ) PRIVILEGED_FUNCTION_core1;
void * pvPortCalloc_core1( size_t xNum_core1,
                     size_t xSize_core1 ) PRIVILEGED_FUNCTION_core1;
void vPortFree_core1( void * pv_core1 ) PRIVILEGED_FUNCTION_core1;
void vPortInitialiseBlocks_core1( void ) PRIVILEGED_FUNCTION_core1;
size_t xPortGetFreeHeapSize_core1( void ) PRIVILEGED_FUNCTION_core1;
size_t xPortGetMinimumEverFreeHeapSize_core1( void ) PRIVILEGED_FUNCTION_core1;

#if ( configSTACK_ALLOCATION_FROM_SEPARATE_HEAP_core1 == 1 )
    void * pvPortMallocStack_core1( size_t xSize_core1 ) PRIVILEGED_FUNCTION_core1;
    void vPortFreeStack_core1( void * pv_core1 ) PRIVILEGED_FUNCTION_core1;
#else
    #define pvPortMallocStack_core1    pvPortMalloc_core1
    #define vPortFreeStack_core1       vPortFree_core1
#endif

#if ( configUSE_MALLOC_FAILED_HOOK_core1 == 1 )

/**
 * task_core1.h
 * @code{c}
 * void vApplicationMallocFailedHook_core1( void )
 * @endcode
 *
 * This hook function is called when allocation failed.
 */
    void vApplicationMallocFailedHook_core1( void ); /*lint !e526 Symbol not defined as it is an application callback. */
#endif

/*
 * Setup the hardware ready for the scheduler to take control.  This generally
 * sets up a tick interrupt and sets timers_core1 for the correct tick frequency.
 */
BaseType_t_core1 xPortStartScheduler_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * Undo any hardware/ISR setup that was performed by xPortStartScheduler_core1() so
 * the hardware is left in its original condition after the scheduler stops
 * executing.
 */
void vPortEndScheduler_core1( void ) PRIVILEGED_FUNCTION_core1;

/*
 * The structures and methods of manipulating the MPU are contained within the
 * port layer.
 *
 * Fills the xMPUSettings_core1 structure with the memory region information
 * contained in xRegions_core1.
 */
#if ( portUSING_MPU_WRAPPERS_core1 == 1 )
    struct xMEMORY_REGION_core1;
    void vPortStoreTaskMPUSettings_core1( xMPU_SETTINGS_core1 * xMPUSettings_core1,
                                    const struct xMEMORY_REGION_core1 * const xRegions_core1,
                                    StackType_t_core1 * pxBottomOfStack_core1,
                                    uint32_t ulStackDepth_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* PORTABLE_H */
