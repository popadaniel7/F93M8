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

/*
 * A sample implementation of pvPortMalloc_core0() and vPortFree_core0() that combines
 * (coalescences) adjacent memory blocks as they are freed, and in so doing
 * limits memory fragmentation.
 *
 * See heap_1.c, heap_2.c and heap_3.c for alternative implementations, and the
 * memory management pages of https://www.FreeRTOS_core0.org for more information.
 */
#include <stdlib.h>
#include <string.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0 prevents task_core0.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core0.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0

#include "FreeRTOS_core0.h"
#include "task_core0.h"

#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0

#if ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 0 )
    #error This file must not be used if configSUPPORT_DYNAMIC_ALLOCATION_core0 is 0
#endif

#ifndef configHEAP_CLEAR_MEMORY_ON_FREE
    #define configHEAP_CLEAR_MEMORY_ON_FREE    0
#endif

/* Block sizes must not get too small. */
#define heapMINIMUM_BLOCK_SIZE_core0    ( ( size_t ) ( xHeapStructSize_core0 << 1 ) )

/* Assumes 8bit bytes! */
#define heapBITS_PER_BYTE_core0         ( ( size_t ) 8 )

/* Max value that fits in a size_t type. */
#define heapSIZE_MAX_core0              ( ~( ( size_t ) 0 ) )

/* Check if multiplying a and b will result in overflow. */
#define heapMULTIPLY_WILL_OVERFLOW_core0( a, b )    ( ( ( a ) > 0 ) && ( ( b ) > ( heapSIZE_MAX_core0 / ( a ) ) ) )

/* Check if adding a and b will result in overflow. */
#define heapADD_WILL_OVERFLOW_core0( a, b )         ( ( a ) > ( heapSIZE_MAX_core0 - ( b ) ) )

/* MSB of the xBlockSize_core0 member of an BlockLink_t_core0 structure is used to track
 * the allocation status of a block.  When MSB of the xBlockSize_core0 member of
 * an BlockLink_t_core0 structure is set then the block belongs to the application.
 * When the bit is free the block is still part of the free heap space. */
#define heapBLOCK_ALLOCATED_BITMASK_core0    ( ( ( size_t ) 1 ) << ( ( sizeof( size_t ) * heapBITS_PER_BYTE_core0 ) - 1 ) )
#define heapBLOCK_SIZE_IS_VALID_core0( xBlockSize_core0 )    ( ( ( xBlockSize_core0 ) & heapBLOCK_ALLOCATED_BITMASK_core0 ) == 0 )
#define heapBLOCK_IS_ALLOCATED_core0( pxBlock_core0 )        ( ( ( pxBlock_core0->xBlockSize_core0 ) & heapBLOCK_ALLOCATED_BITMASK_core0 ) != 0 )
#define heapALLOCATE_BLOCK_core0( pxBlock_core0 )            ( ( pxBlock_core0->xBlockSize_core0 ) |= heapBLOCK_ALLOCATED_BITMASK_core0 )
#define heapFREE_BLOCK_core0( pxBlock_core0 )                ( ( pxBlock_core0->xBlockSize_core0 ) &= ~heapBLOCK_ALLOCATED_BITMASK_core0 )

/*-----------------------------------------------------------*/

/* Allocate the memory for the heap. */
#if ( configAPPLICATION_ALLOCATED_HEAP_core0 == 1 )

/* The application writer has already defined the array used for the RTOS
* heap - probably so it can be placed in a special segment or address. */
    extern uint8_t ucHeap_core0[ configTOTAL_HEAP_SIZE_core0 ];
#else
    PRIVILEGED_DATA_core0 static uint8_t ucHeap_core0[ configTOTAL_HEAP_SIZE_core0 ];
#endif /* configAPPLICATION_ALLOCATED_HEAP_core0 */

/* Define the linked list structure.  This is used to link free blocks in order
 * of their memory address. */
typedef struct A_BLOCK_LINK_core0
{
    struct A_BLOCK_LINK_core0 * pxNextFreeBlock_core0; /*<< The next free block in the list. */
    size_t xBlockSize_core0;                     /*<< The size of the free block. */
} BlockLink_t_core0;

/*-----------------------------------------------------------*/

/*
 * Inserts a block of memory that is being freed into the correct position in
 * the list of free memory blocks.  The block being freed will be merged with
 * the block in front it and/or the block behind it if the memory blocks are
 * adjacent to each other.
 */
static void prvInsertBlockIntoFreeList_core0( BlockLink_t_core0 * pxBlockToInsert_core0 ) PRIVILEGED_FUNCTION_core0;

/*
 * Called automatically to setup the required heap structures the first time
 * pvPortMalloc_core0() is called.
 */
static void prvHeapInit_core0( void ) PRIVILEGED_FUNCTION_core0;

/*-----------------------------------------------------------*/

/* The size of the structure placed at the beginning of each allocated memory
 * block must by correctly byte aligned. */
static const size_t xHeapStructSize_core0 = ( sizeof( BlockLink_t_core0 ) + ( ( size_t ) ( portBYTE_ALIGNMENT_core0 - 1 ) ) ) & ~( ( size_t ) portBYTE_ALIGNMENT_MASK_core0 );

/* Create a couple of list links to mark the start and end of the list. */
PRIVILEGED_DATA_core0 static BlockLink_t_core0 xStart_core0;
PRIVILEGED_DATA_core0 static BlockLink_t_core0 * pxEnd_core0 = NULL;

/* Keeps track of the number of calls to allocate and free memory as well as the
 * number of free bytes remaining, but says nothing about fragmentation. */
PRIVILEGED_DATA_core0 static size_t xFreeBytesRemaining_core0 = 0U;
PRIVILEGED_DATA_core0 static size_t xMinimumEverFreeBytesRemaining_core0 = 0U;
PRIVILEGED_DATA_core0 static size_t xNumberOfSuccessfulAllocations_core0 = 0;
PRIVILEGED_DATA_core0 static size_t xNumberOfSuccessfulFrees_core0 = 0;

/*-----------------------------------------------------------*/

void * pvPortMalloc_core0( size_t xWantedSize_core0 )
{
    BlockLink_t_core0 * pxBlock_core0;
    BlockLink_t_core0 * pxPreviousBlock_core0;
    BlockLink_t_core0 * pxNewBlockLink_core0;
    void * pvReturn_core0 = NULL;
    size_t xAdditionalRequiredSize_core0;

    vTaskSuspendAll_core0();
    {
        /* If this is the first call to malloc then the heap will require
         * initialisation to setup the list of free blocks. */
        if( pxEnd_core0 == NULL )
        {
            prvHeapInit_core0();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }

        if( xWantedSize_core0 > 0 )
        {
            /* The wanted size must be increased so it can contain a BlockLink_t_core0
             * structure in addition to the requested amount of bytes. Some
             * additional increment may also be needed for alignment. */
            xAdditionalRequiredSize_core0 = xHeapStructSize_core0 + portBYTE_ALIGNMENT_core0 - ( xWantedSize_core0 & portBYTE_ALIGNMENT_MASK_core0 );

            if( heapADD_WILL_OVERFLOW_core0( xWantedSize_core0, xAdditionalRequiredSize_core0 ) == 0 )
            {
                xWantedSize_core0 += xAdditionalRequiredSize_core0;
            }
            else
            {
                xWantedSize_core0 = 0;
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }

        /* Check the block size we are trying to allocate is not so large that the
         * top bit is set.  The top bit of the block size member of the BlockLink_t_core0
         * structure is used to determine who owns the block - the application or
         * the kernel, so it must be free. */
        if( heapBLOCK_SIZE_IS_VALID_core0( xWantedSize_core0 ) != 0 )
        {
            if( ( xWantedSize_core0 > 0 ) && ( xWantedSize_core0 <= xFreeBytesRemaining_core0 ) )
            {
                /* Traverse the list from the start (lowest address) block until
                 * one of adequate size is found. */
                pxPreviousBlock_core0 = &xStart_core0;
                pxBlock_core0 = xStart_core0.pxNextFreeBlock_core0;

                while( ( pxBlock_core0->xBlockSize_core0 < xWantedSize_core0 ) && ( pxBlock_core0->pxNextFreeBlock_core0 != NULL ) )
                {
                    pxPreviousBlock_core0 = pxBlock_core0;
                    pxBlock_core0 = pxBlock_core0->pxNextFreeBlock_core0;
                }

                /* If the end marker was reached then a block of adequate size
                 * was not found. */
                if( pxBlock_core0 != pxEnd_core0 )
                {
                    /* Return the memory space pointed to - jumping over the
                     * BlockLink_t_core0 structure at its start. */
                    pvReturn_core0 = ( void * ) ( ( ( uint8_t * ) pxPreviousBlock_core0->pxNextFreeBlock_core0 ) + xHeapStructSize_core0 );

                    /* This block is being returned for use so must be taken out
                     * of the list of free blocks. */
                    pxPreviousBlock_core0->pxNextFreeBlock_core0 = pxBlock_core0->pxNextFreeBlock_core0;

                    /* If the block is larger than required it can be split into
                     * two. */
                    if( ( pxBlock_core0->xBlockSize_core0 - xWantedSize_core0 ) > heapMINIMUM_BLOCK_SIZE_core0 )
                    {
                        /* This block is to be split into two.  Create a new
                         * block following the number of bytes requested. The void
                         * cast is used to prevent byte alignment warnings from the
                         * compiler. */
                        pxNewBlockLink_core0 = ( void * ) ( ( ( uint8_t * ) pxBlock_core0 ) + xWantedSize_core0 );
                        configASSERT_core0( ( ( ( size_t ) pxNewBlockLink_core0 ) & portBYTE_ALIGNMENT_MASK_core0 ) == 0 );

                        /* Calculate the sizes of two blocks split from the
                         * single block. */
                        pxNewBlockLink_core0->xBlockSize_core0 = pxBlock_core0->xBlockSize_core0 - xWantedSize_core0;
                        pxBlock_core0->xBlockSize_core0 = xWantedSize_core0;

                        /* Insert the new block into the list of free blocks. */
                        prvInsertBlockIntoFreeList_core0( pxNewBlockLink_core0 );
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core0();
                    }

                    xFreeBytesRemaining_core0 -= pxBlock_core0->xBlockSize_core0;

                    if( xFreeBytesRemaining_core0 < xMinimumEverFreeBytesRemaining_core0 )
                    {
                        xMinimumEverFreeBytesRemaining_core0 = xFreeBytesRemaining_core0;
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core0();
                    }

                    /* The block is being returned - it is allocated and owned
                     * by the application and has no "next" block. */
                    heapALLOCATE_BLOCK_core0( pxBlock_core0 );
                    pxBlock_core0->pxNextFreeBlock_core0 = NULL;
                    xNumberOfSuccessfulAllocations_core0++;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core0();
                }
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core0();
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }

        traceMALLOC_core0( pvReturn_core0, xWantedSize_core0 );
    }
    ( void ) xTaskResumeAll_core0();

    #if ( configUSE_MALLOC_FAILED_HOOK_core0 == 1 )
    {
        if( pvReturn_core0 == NULL )
        {
            vApplicationMallocFailedHook_core0();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }
    }
    #endif /* if ( configUSE_MALLOC_FAILED_HOOK_core0 == 1 ) */

    configASSERT_core0( ( ( ( size_t ) pvReturn_core0 ) & ( size_t ) portBYTE_ALIGNMENT_MASK_core0 ) == 0 );
    return pvReturn_core0;
}
/*-----------------------------------------------------------*/

void vPortFree_core0( void * pv_core0 )
{
    uint8_t * puc_core0 = ( uint8_t * ) pv_core0;
    BlockLink_t_core0 * pxLink_core0;

    if( pv_core0 != NULL )
    {
        /* The memory being freed will have an BlockLink_t_core0 structure immediately
         * before it. */
        puc_core0 -= xHeapStructSize_core0;

        /* This casting is to keep the compiler from issuing warnings. */
        pxLink_core0 = ( void * ) puc_core0;

        configASSERT_core0( heapBLOCK_IS_ALLOCATED_core0( pxLink_core0 ) != 0 );
        configASSERT_core0( pxLink_core0->pxNextFreeBlock_core0 == NULL );

        if( heapBLOCK_IS_ALLOCATED_core0( pxLink_core0 ) != 0 )
        {
            if( pxLink_core0->pxNextFreeBlock_core0 == NULL )
            {
                /* The block is being returned to the heap - it is no longer
                 * allocated. */
                heapFREE_BLOCK_core0( pxLink_core0 );
                #if ( configHEAP_CLEAR_MEMORY_ON_FREE == 1 )
                {
                    ( void ) memset( puc_core0 + xHeapStructSize_core0, 0, pxLink_core0->xBlockSize_core0 - xHeapStructSize_core0 );
                }
                #endif

                vTaskSuspendAll_core0();
                {
                    /* Add this block to the list of free blocks. */
                    xFreeBytesRemaining_core0 += pxLink_core0->xBlockSize_core0;
                    traceFREE_core0( pv_core0, pxLink_core0->xBlockSize_core0 );
                    prvInsertBlockIntoFreeList_core0( ( ( BlockLink_t_core0 * ) pxLink_core0 ) );
                    xNumberOfSuccessfulFrees_core0++;
                }
                ( void ) xTaskResumeAll_core0();
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core0();
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }
    }
}
/*-----------------------------------------------------------*/

size_t xPortGetFreeHeapSize_core0( void )
{
    return xFreeBytesRemaining_core0;
}
/*-----------------------------------------------------------*/

size_t xPortGetMinimumEverFreeHeapSize_core0( void )
{
    return xMinimumEverFreeBytesRemaining_core0;
}
/*-----------------------------------------------------------*/

void vPortInitialiseBlocks_core0( void )
{
    /* This just exists to keep the linker quiet. */
}
/*-----------------------------------------------------------*/

void * pvPortCalloc_core0( size_t xNum_core0,
                     size_t xSize_core0 )
{
    void * pv_core0 = NULL;

    if( heapMULTIPLY_WILL_OVERFLOW_core0( xNum_core0, xSize_core0 ) == 0 )
    {
        pv_core0 = pvPortMalloc_core0( xNum_core0 * xSize_core0 );

        if( pv_core0 != NULL )
        {
            ( void ) memset( pv_core0, 0, xNum_core0 * xSize_core0 );
        }
    }

    return pv_core0;
}
/*-----------------------------------------------------------*/

static void prvHeapInit_core0( void ) /* PRIVILEGED_FUNCTION_core0 */
{
    BlockLink_t_core0 * pxFirstFreeBlock_core0;
    uint8_t * pucAlignedHeap_core0;
    portPOINTER_SIZE_TYPE_core0 uxAddress_core0;
    size_t xTotalHeapSize_core0 = configTOTAL_HEAP_SIZE_core0;

    /* Ensure the heap starts on a correctly aligned boundary. */
    uxAddress_core0 = ( portPOINTER_SIZE_TYPE_core0 ) ucHeap_core0;

    if( ( uxAddress_core0 & portBYTE_ALIGNMENT_MASK_core0 ) != 0 )
    {
        uxAddress_core0 += ( portBYTE_ALIGNMENT_core0 - 1 );
        uxAddress_core0 &= ~( ( portPOINTER_SIZE_TYPE_core0 ) portBYTE_ALIGNMENT_MASK_core0 );
        xTotalHeapSize_core0 -= uxAddress_core0 - ( portPOINTER_SIZE_TYPE_core0 ) ucHeap_core0;
    }

    pucAlignedHeap_core0 = ( uint8_t * ) uxAddress_core0;

    /* xStart_core0 is used to hold a pointer to the first item in the list of free
     * blocks.  The void cast is used to prevent compiler warnings. */
    xStart_core0.pxNextFreeBlock_core0 = ( void * ) pucAlignedHeap_core0;
    xStart_core0.xBlockSize_core0 = ( size_t ) 0;

    /* pxEnd_core0 is used to mark the end of the list of free blocks and is inserted
     * at the end of the heap space. */
    uxAddress_core0 = ( ( portPOINTER_SIZE_TYPE_core0 ) pucAlignedHeap_core0 ) + xTotalHeapSize_core0;
    uxAddress_core0 -= xHeapStructSize_core0;
    uxAddress_core0 &= ~( ( portPOINTER_SIZE_TYPE_core0 ) portBYTE_ALIGNMENT_MASK_core0 );
    pxEnd_core0 = ( BlockLink_t_core0 * ) uxAddress_core0;
    pxEnd_core0->xBlockSize_core0 = 0;
    pxEnd_core0->pxNextFreeBlock_core0 = NULL;

    /* To start with there is a single free block that is sized to take up the
     * entire heap space, minus the space taken by pxEnd_core0. */
    pxFirstFreeBlock_core0 = ( BlockLink_t_core0 * ) pucAlignedHeap_core0;
    pxFirstFreeBlock_core0->xBlockSize_core0 = ( size_t ) ( uxAddress_core0 - ( portPOINTER_SIZE_TYPE_core0 ) pxFirstFreeBlock_core0 );
    pxFirstFreeBlock_core0->pxNextFreeBlock_core0 = pxEnd_core0;

    /* Only one block exists - and it covers the entire usable heap space. */
    xMinimumEverFreeBytesRemaining_core0 = pxFirstFreeBlock_core0->xBlockSize_core0;
    xFreeBytesRemaining_core0 = pxFirstFreeBlock_core0->xBlockSize_core0;
}
/*-----------------------------------------------------------*/

static void prvInsertBlockIntoFreeList_core0( BlockLink_t_core0 * pxBlockToInsert_core0 ) /* PRIVILEGED_FUNCTION_core0 */
{
    BlockLink_t_core0 * pxIterator_core0;
    uint8_t * puc_core0;

    /* Iterate through the list until a block is found that has a higher address
     * than the block being inserted. */
    for( pxIterator_core0 = &xStart_core0; pxIterator_core0->pxNextFreeBlock_core0 < pxBlockToInsert_core0; pxIterator_core0 = pxIterator_core0->pxNextFreeBlock_core0 )
    {
        /* Nothing to do here, just iterate to the right position. */
    }

    /* Do the block being inserted, and the block it is being inserted after
     * make a contiguous block of memory? */
    puc_core0 = ( uint8_t * ) pxIterator_core0;

    if( ( puc_core0 + pxIterator_core0->xBlockSize_core0 ) == ( uint8_t * ) pxBlockToInsert_core0 )
    {
        pxIterator_core0->xBlockSize_core0 += pxBlockToInsert_core0->xBlockSize_core0;
        pxBlockToInsert_core0 = pxIterator_core0;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core0();
    }

    /* Do the block being inserted, and the block it is being inserted before
     * make a contiguous block of memory? */
    puc_core0 = ( uint8_t * ) pxBlockToInsert_core0;

    if( ( puc_core0 + pxBlockToInsert_core0->xBlockSize_core0 ) == ( uint8_t * ) pxIterator_core0->pxNextFreeBlock_core0 )
    {
        if( pxIterator_core0->pxNextFreeBlock_core0 != pxEnd_core0 )
        {
            /* Form one big block from the two blocks. */
            pxBlockToInsert_core0->xBlockSize_core0 += pxIterator_core0->pxNextFreeBlock_core0->xBlockSize_core0;
            pxBlockToInsert_core0->pxNextFreeBlock_core0 = pxIterator_core0->pxNextFreeBlock_core0->pxNextFreeBlock_core0;
        }
        else
        {
            pxBlockToInsert_core0->pxNextFreeBlock_core0 = pxEnd_core0;
        }
    }
    else
    {
        pxBlockToInsert_core0->pxNextFreeBlock_core0 = pxIterator_core0->pxNextFreeBlock_core0;
    }

    /* If the block being inserted plugged a gab, so was merged with the block
     * before and the block after, then it's pxNextFreeBlock_core0 pointer will have
     * already been set, and should not be set here as that would make it point
     * to itself. */
    if( pxIterator_core0 != pxBlockToInsert_core0 )
    {
        pxIterator_core0->pxNextFreeBlock_core0 = pxBlockToInsert_core0;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core0();
    }
}
/*-----------------------------------------------------------*/

void vPortGetHeapStats_core0( HeapStats_t_core0 * pxHeapStats_core0 )
{
    BlockLink_t_core0 * pxBlock_core0;
    size_t xBlocks_core0 = 0, xMaxSize_core0 = 0, xMinSize_core0 = portMAX_DELAY_core0; /* portMAX_DELAY_core0 used as a portable way of getting the maximum value. */

    vTaskSuspendAll_core0();
    {
        pxBlock_core0 = xStart_core0.pxNextFreeBlock_core0;

        /* pxBlock_core0 will be NULL if the heap has not been initialised.  The heap
         * is initialised automatically when the first allocation is made. */
        if( pxBlock_core0 != NULL )
        {
            while( pxBlock_core0 != pxEnd_core0 )
            {
                /* Increment the number of blocks and record the largest block seen
                 * so far. */
                xBlocks_core0++;

                if( pxBlock_core0->xBlockSize_core0 > xMaxSize_core0 )
                {
                    xMaxSize_core0 = pxBlock_core0->xBlockSize_core0;
                }

                if( pxBlock_core0->xBlockSize_core0 < xMinSize_core0 )
                {
                    xMinSize_core0 = pxBlock_core0->xBlockSize_core0;
                }

                /* Move to the next block in the chain until the last block is
                 * reached. */
                pxBlock_core0 = pxBlock_core0->pxNextFreeBlock_core0;
            }
        }
    }
    ( void ) xTaskResumeAll_core0();

    pxHeapStats_core0->xSizeOfLargestFreeBlockInBytes_core0 = xMaxSize_core0;
    pxHeapStats_core0->xSizeOfSmallestFreeBlockInBytes_core0 = xMinSize_core0;
    pxHeapStats_core0->xNumberOfFreeBlocks_core0 = xBlocks_core0;

    taskENTER_CRITICAL_core0();
    {
        pxHeapStats_core0->xAvailableHeapSpaceInBytes_core0 = xFreeBytesRemaining_core0;
        pxHeapStats_core0->xNumberOfSuccessfulAllocations_core0 = xNumberOfSuccessfulAllocations_core0;
        pxHeapStats_core0->xNumberOfSuccessfulFrees_core0 = xNumberOfSuccessfulFrees_core0;
        pxHeapStats_core0->xMinimumEverFreeBytesRemaining_core0 = xMinimumEverFreeBytesRemaining_core0;
    }
    taskEXIT_CRITICAL_core0();
}
/*-----------------------------------------------------------*/
