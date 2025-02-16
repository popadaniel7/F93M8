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

/*-----------------------------------------------------------
* Portable layer API.  Each function must be defined for each port.
*----------------------------------------------------------*/

#ifndef PORTABLE_CORE2_H
#define PORTABLE_CORE2_H

/* Each FreeRTOS_core2 port has a unique portmacro.h header file.  Originally a
 * pre-processor definition was used to ensure the pre-processor found the correct
 * portmacro.h file for the port being used.  That scheme was deprecated in favour
 * of setting the compiler's include path such that it found the correct
 * portmacro.h file - removing the need for the constant and allowing the
 * portmacro.h file to be located anywhere in relation to the port being used.
 * Purely for reasons of backward compatibility the old method is still valid, but
 * to make it clear that new projects should not use it, support for the port
 * specific constants has been moved into the deprecated_definitions.h header
 * file. */
#include "deprecated_definitions_core2.h"

/* If portENTER_CRITICAL_core2 is not defined then including deprecated_definitions.h
 * did not result in a portmacro.h header file being included - and it should be
 * included here.  In this case the path to the correct portmacro.h header file
 * must be set in the compiler's include path. */
#ifndef portENTER_CRITICAL_core2
    #include "portmacro_core2.h"
#endif

#if portBYTE_ALIGNMENT_core2 == 32
    #define portBYTE_ALIGNMENT_MASK_core2    ( 0x001f )
#elif portBYTE_ALIGNMENT_core2 == 16
    #define portBYTE_ALIGNMENT_MASK_core2    ( 0x000f )
#elif portBYTE_ALIGNMENT_core2 == 8
    #define portBYTE_ALIGNMENT_MASK_core2    ( 0x0007 )
#elif portBYTE_ALIGNMENT_core2 == 4
    #define portBYTE_ALIGNMENT_MASK_core2    ( 0x0003 )
#elif portBYTE_ALIGNMENT_core2 == 2
    #define portBYTE_ALIGNMENT_MASK_core2    ( 0x0001 )
#elif portBYTE_ALIGNMENT_core2 == 1
    #define portBYTE_ALIGNMENT_MASK_core2    ( 0x0000 )
#else /* if portBYTE_ALIGNMENT_core2 == 32 */
    #error "Invalid portBYTE_ALIGNMENT_core2 definition"
#endif /* if portBYTE_ALIGNMENT_core2 == 32 */

#ifndef portUSING_MPU_WRAPPERS_core2
    #define portUSING_MPU_WRAPPERS_core2    0
#endif

#ifndef portNUM_CONFIGURABLE_REGIONS_core2
    #define portNUM_CONFIGURABLE_REGIONS_core2    1
#endif

#ifndef portHAS_STACK_OVERFLOW_CHECKING_core2
    #define portHAS_STACK_OVERFLOW_CHECKING_core2    0
#endif

#ifndef portARCH_NAME_core2
    #define portARCH_NAME_core2    NULL
#endif

#ifndef configSTACK_ALLOCATION_FROM_SEPARATE_HEAP_core2
    /* Defaults to 0 for backward compatibility. */
    #define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP_core2    0
#endif

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

#include "mpu_wrappers_core2.h"

/*
 * Setup the stack of a new task_core2 so it is ready to be placed under the
 * scheduler control.  The registers have to be placed on the stack in
 * the order that the port expects to find them.
 *
 */
#if ( portUSING_MPU_WRAPPERS_core2 == 1 )
    #if ( portHAS_STACK_OVERFLOW_CHECKING_core2 == 1 )
        StackType_t_core2 * pxPortInitialiseStack_core2( StackType_t_core2 * pxTopOfStack_core2,
                                             StackType_t_core2 * pxEndOfStack_core2,
                                             TaskFunction_t_core2 pxCode_core2,
                                             void * pvParameters_core2,
                                             BaseType_t_core2 xRunPrivileged_core2 ) PRIVILEGED_FUNCTION_core2;
    #else
        StackType_t_core2 * pxPortInitialiseStack_core2( StackType_t_core2 * pxTopOfStack_core2,
                                             TaskFunction_t_core2 pxCode_core2,
                                             void * pvParameters_core2,
                                             BaseType_t_core2 xRunPrivileged_core2 ) PRIVILEGED_FUNCTION_core2;
    #endif
#else /* if ( portUSING_MPU_WRAPPERS_core2 == 1 ) */
    #if ( portHAS_STACK_OVERFLOW_CHECKING_core2 == 1 )
        StackType_t_core2 * pxPortInitialiseStack_core2( StackType_t_core2 * pxTopOfStack_core2,
                                             StackType_t_core2 * pxEndOfStack_core2,
                                             TaskFunction_t_core2 pxCode_core2,
                                             void * pvParameters_core2 ) PRIVILEGED_FUNCTION_core2;
    #else
        StackType_t_core2 * pxPortInitialiseStack_core2( StackType_t_core2 * pxTopOfStack_core2,
                                             TaskFunction_t_core2 pxCode_core2,
                                             void * pvParameters_core2 ) PRIVILEGED_FUNCTION_core2;
    #endif
#endif /* if ( portUSING_MPU_WRAPPERS_core2 == 1 ) */

/* Used by heap_5.c to define the start address and size of each memory region
 * that together comprise the total FreeRTOS_core2 heap space. */
typedef struct HeapRegion_core2
{
    uint8_t * pucStartAddress_core2;
    size_t xSizeInBytes_core2;
} HeapRegion_t_core2;

/* Used to pass information about the heap out of vPortGetHeapStats_core2(). */
typedef struct xHeapStats_core2
{
    size_t xAvailableHeapSpaceInBytes_core2;      /* The total heap size currently available - this is the sum of all the free blocks, not the largest block that can be allocated. */
    size_t xSizeOfLargestFreeBlockInBytes_core2;  /* The maximum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats_core2() is called. */
    size_t xSizeOfSmallestFreeBlockInBytes_core2; /* The minimum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats_core2() is called. */
    size_t xNumberOfFreeBlocks_core2;             /* The number of free memory blocks within the heap at the time vPortGetHeapStats_core2() is called. */
    size_t xMinimumEverFreeBytesRemaining_core2;  /* The minimum amount of total free memory (sum of all free blocks) there has been in the heap since the system booted. */
    size_t xNumberOfSuccessfulAllocations_core2;  /* The number of calls to pvPortMalloc_core2() that have returned a valid memory block. */
    size_t xNumberOfSuccessfulFrees_core2;        /* The number of calls to vPortFree_core2() that has successfully freed a block of memory. */
} HeapStats_t_core2;

/*
 * Used to define multiple heap regions for use by heap_5.c.  This function
 * must be called before any calls to pvPortMalloc_core2() - not creating a task_core2,
 * queue, semaphore, mutex, software timer, event group, etc. will result in
 * pvPortMalloc_core2 being called.
 *
 * pxHeapRegions_core2 passes in an array of HeapRegion_t_core2 structures - each of which
 * defines a region of memory that can be used as the heap.  The array is
 * terminated by a HeapRegions_t structure that has a size of 0.  The region
 * with the lowest start address must appear first in the array.
 */
void vPortDefineHeapRegions_core2( const HeapRegion_t_core2 * const pxHeapRegions_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Returns a HeapStats_t_core2 structure filled with information about the current
 * heap state.
 */
void vPortGetHeapStats_core2( HeapStats_t_core2 * pxHeapStats_core2 );

/*
 * Map to the memory management routines required for the port.
 */
void * pvPortMalloc_core2( size_t xSize_core2 ) PRIVILEGED_FUNCTION_core2;
void * pvPortCalloc_core2( size_t xNum_core2,
                     size_t xSize_core2 ) PRIVILEGED_FUNCTION_core2;
void vPortFree_core2( void * pv_core2 ) PRIVILEGED_FUNCTION_core2;
void vPortInitialiseBlocks_core2( void ) PRIVILEGED_FUNCTION_core2;
size_t xPortGetFreeHeapSize_core2( void ) PRIVILEGED_FUNCTION_core2;
size_t xPortGetMinimumEverFreeHeapSize_core2( void ) PRIVILEGED_FUNCTION_core2;

#if ( configSTACK_ALLOCATION_FROM_SEPARATE_HEAP_core2 == 1 )
    void * pvPortMallocStack_core2( size_t xSize_core2 ) PRIVILEGED_FUNCTION_core2;
    void vPortFreeStack_core2( void * pv_core2 ) PRIVILEGED_FUNCTION_core2;
#else
    #define pvPortMallocStack_core2    pvPortMalloc_core2
    #define vPortFreeStack_core2       vPortFree_core2
#endif

#if ( configUSE_MALLOC_FAILED_HOOK_core2 == 1 )

/**
 * task_core2.h
 * @code{c}
 * void vApplicationMallocFailedHook_core2( void )
 * @endcode
 *
 * This hook function is called when allocation failed.
 */
    void vApplicationMallocFailedHook_core2( void ); /*lint !e526 Symbol not defined as it is an application callback. */
#endif

/*
 * Setup the hardware ready for the scheduler to take control.  This generally
 * sets up a tick interrupt and sets timers_core2 for the correct tick frequency.
 */
BaseType_t_core2 xPortStartScheduler_core2( void ) PRIVILEGED_FUNCTION_core2;

/*
 * Undo any hardware/ISR setup that was performed by xPortStartScheduler_core2() so
 * the hardware is left in its original condition after the scheduler stops
 * executing.
 */
void vPortEndScheduler_core2( void ) PRIVILEGED_FUNCTION_core2;

/*
 * The structures and methods of manipulating the MPU are contained within the
 * port layer.
 *
 * Fills the xMPUSettings_core2 structure with the memory region information
 * contained in xRegions_core2.
 */
#if ( portUSING_MPU_WRAPPERS_core2 == 1 )
    struct xMEMORY_REGION_core2;
    void vPortStoreTaskMPUSettings_core2( xMPU_SETTINGS_core2 * xMPUSettings_core2,
                                    const struct xMEMORY_REGION_core2 * const xRegions_core2,
                                    StackType_t_core2 * pxBottomOfStack_core2,
                                    uint32_t ulStackDepth_core2 ) PRIVILEGED_FUNCTION_core2;
#endif

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* PORTABLE_H */
