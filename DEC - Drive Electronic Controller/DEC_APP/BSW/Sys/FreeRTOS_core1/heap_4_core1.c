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

/*
 * A sample implementation of pvPortMalloc_core1() and vPortFree_core1() that combines
 * (coalescences) adjacent memory blocks as they are freed, and in so doing
 * limits memory fragmentation.
 *
 * See heap_1.c, heap_2.c and heap_3.c for alternative implementations, and the
 * memory management pages of https://www.FreeRTOS_core1.org for more information.
 */
#include <stdlib.h>
#include <string.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 prevents task_core1.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core1.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1

#include "FreeRTOS_core1.h"
#include "task_core1.h"

#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1

#if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 0 )
    #error This file must not be used if configSUPPORT_DYNAMIC_ALLOCATION_core1 is 0
#endif

#ifndef configHEAP_CLEAR_MEMORY_ON_FREE
    #define configHEAP_CLEAR_MEMORY_ON_FREE    0
#endif

/* Block sizes must not get too small. */
#define heapMINIMUM_BLOCK_SIZE_core1    ( ( size_t ) ( xHeapStructSize_core1 << 1 ) )

/* Assumes 8bit bytes! */
#define heapBITS_PER_BYTE_core1         ( ( size_t ) 8 )

/* Max value that fits in a size_t type. */
#define heapSIZE_MAX_core1              ( ~( ( size_t ) 0 ) )

/* Check if multiplying a and b will result in overflow. */
#define heapMULTIPLY_WILL_OVERFLOW_core1( a, b )    ( ( ( a ) > 0 ) && ( ( b ) > ( heapSIZE_MAX_core1 / ( a ) ) ) )

/* Check if adding a and b will result in overflow. */
#define heapADD_WILL_OVERFLOW_core1( a, b )         ( ( a ) > ( heapSIZE_MAX_core1 - ( b ) ) )

/* MSB of the xBlockSize_core1 member of an BlockLink_t_core1 structure is used to track
 * the allocation status of a block.  When MSB of the xBlockSize_core1 member of
 * an BlockLink_t_core1 structure is set then the block belongs to the application.
 * When the bit is free the block is still part of the free heap space. */
#define heapBLOCK_ALLOCATED_BITMASK_core1    ( ( ( size_t ) 1 ) << ( ( sizeof( size_t ) * heapBITS_PER_BYTE_core1 ) - 1 ) )
#define heapBLOCK_SIZE_IS_VALID_core1( xBlockSize_core1 )    ( ( ( xBlockSize_core1 ) & heapBLOCK_ALLOCATED_BITMASK_core1 ) == 0 )
#define heapBLOCK_IS_ALLOCATED_core1( pxBlock_core1 )        ( ( ( pxBlock_core1->xBlockSize_core1 ) & heapBLOCK_ALLOCATED_BITMASK_core1 ) != 0 )
#define heapALLOCATE_BLOCK_core1( pxBlock_core1 )            ( ( pxBlock_core1->xBlockSize_core1 ) |= heapBLOCK_ALLOCATED_BITMASK_core1 )
#define heapFREE_BLOCK_core1( pxBlock_core1 )                ( ( pxBlock_core1->xBlockSize_core1 ) &= ~heapBLOCK_ALLOCATED_BITMASK_core1 )

/*-----------------------------------------------------------*/

/* Allocate the memory for the heap. */
#if ( configAPPLICATION_ALLOCATED_HEAP_core1 == 1 )

/* The application writer has already defined the array used for the RTOS
* heap - probably so it can be placed in a special segment or address. */
    extern uint8_t ucHeap_core1[ configTOTAL_HEAP_SIZE_core1 ];
#else
    PRIVILEGED_DATA_core1 static uint8_t ucHeap_core1[ configTOTAL_HEAP_SIZE_core1 ];
#endif /* configAPPLICATION_ALLOCATED_HEAP_core1 */

/* Define the linked list structure.  This is used to link free blocks in order
 * of their memory address. */
typedef struct A_BLOCK_LINK_core1
{
    struct A_BLOCK_LINK_core1 * pxNextFreeBlock_core1; /*<< The next free block in the list. */
    size_t xBlockSize_core1;                     /*<< The size of the free block. */
} BlockLink_t_core1;

/*-----------------------------------------------------------*/

/*
 * Inserts a block of memory that is being freed into the correct position in
 * the list of free memory blocks.  The block being freed will be merged with
 * the block in front it and/or the block behind it if the memory blocks are
 * adjacent to each other.
 */
static void prvInsertBlockIntoFreeList_core1( BlockLink_t_core1 * pxBlockToInsert_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Called automatically to setup the required heap structures the first time
 * pvPortMalloc_core1() is called.
 */
static void prvHeapInit_core1( void ) PRIVILEGED_FUNCTION_core1;

/*-----------------------------------------------------------*/

/* The size of the structure placed at the beginning of each allocated memory
 * block must by correctly byte aligned. */
static const size_t xHeapStructSize_core1 = ( sizeof( BlockLink_t_core1 ) + ( ( size_t ) ( portBYTE_ALIGNMENT_core1 - 1 ) ) ) & ~( ( size_t ) portBYTE_ALIGNMENT_MASK_core1 );

/* Create a couple of list links to mark the start and end of the list. */
PRIVILEGED_DATA_core1 static BlockLink_t_core1 xStart_core1;
PRIVILEGED_DATA_core1 static BlockLink_t_core1 * pxEnd_core1 = NULL;

/* Keeps track of the number of calls to allocate and free memory as well as the
 * number of free bytes remaining, but says nothing about fragmentation. */
PRIVILEGED_DATA_core1 static size_t xFreeBytesRemaining_core1 = 0U;
PRIVILEGED_DATA_core1 static size_t xMinimumEverFreeBytesRemaining_core1 = 0U;
PRIVILEGED_DATA_core1 static size_t xNumberOfSuccessfulAllocations_core1 = 0;
PRIVILEGED_DATA_core1 static size_t xNumberOfSuccessfulFrees_core1 = 0;

/*-----------------------------------------------------------*/

void * pvPortMalloc_core1( size_t xWantedSize_core1 )
{
    BlockLink_t_core1 * pxBlock_core1;
    BlockLink_t_core1 * pxPreviousBlock_core1;
    BlockLink_t_core1 * pxNewBlockLink_core1;
    void * pvReturn_core1 = NULL;
    size_t xAdditionalRequiredSize_core1;

    vTaskSuspendAll_core1();
    {
        /* If this is the first call to malloc then the heap will require
         * initialisation to setup the list of free blocks. */
        if( pxEnd_core1 == NULL )
        {
            prvHeapInit_core1();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }

        if( xWantedSize_core1 > 0 )
        {
            /* The wanted size must be increased so it can contain a BlockLink_t_core1
             * structure in addition to the requested amount of bytes. Some
             * additional increment may also be needed for alignment. */
            xAdditionalRequiredSize_core1 = xHeapStructSize_core1 + portBYTE_ALIGNMENT_core1 - ( xWantedSize_core1 & portBYTE_ALIGNMENT_MASK_core1 );

            if( heapADD_WILL_OVERFLOW_core1( xWantedSize_core1, xAdditionalRequiredSize_core1 ) == 0 )
            {
                xWantedSize_core1 += xAdditionalRequiredSize_core1;
            }
            else
            {
                xWantedSize_core1 = 0;
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }

        /* Check the block size we are trying to allocate is not so large that the
         * top bit is set.  The top bit of the block size member of the BlockLink_t_core1
         * structure is used to determine who owns the block - the application or
         * the kernel, so it must be free. */
        if( heapBLOCK_SIZE_IS_VALID_core1( xWantedSize_core1 ) != 0 )
        {
            if( ( xWantedSize_core1 > 0 ) && ( xWantedSize_core1 <= xFreeBytesRemaining_core1 ) )
            {
                /* Traverse the list from the start (lowest address) block until
                 * one of adequate size is found. */
                pxPreviousBlock_core1 = &xStart_core1;
                pxBlock_core1 = xStart_core1.pxNextFreeBlock_core1;

                while( ( pxBlock_core1->xBlockSize_core1 < xWantedSize_core1 ) && ( pxBlock_core1->pxNextFreeBlock_core1 != NULL ) )
                {
                    pxPreviousBlock_core1 = pxBlock_core1;
                    pxBlock_core1 = pxBlock_core1->pxNextFreeBlock_core1;
                }

                /* If the end marker was reached then a block of adequate size
                 * was not found. */
                if( pxBlock_core1 != pxEnd_core1 )
                {
                    /* Return the memory space pointed to - jumping over the
                     * BlockLink_t_core1 structure at its start. */
                    pvReturn_core1 = ( void * ) ( ( ( uint8_t * ) pxPreviousBlock_core1->pxNextFreeBlock_core1 ) + xHeapStructSize_core1 );

                    /* This block is being returned for use so must be taken out
                     * of the list of free blocks. */
                    pxPreviousBlock_core1->pxNextFreeBlock_core1 = pxBlock_core1->pxNextFreeBlock_core1;

                    /* If the block is larger than required it can be split into
                     * two. */
                    if( ( pxBlock_core1->xBlockSize_core1 - xWantedSize_core1 ) > heapMINIMUM_BLOCK_SIZE_core1 )
                    {
                        /* This block is to be split into two.  Create a new
                         * block following the number of bytes requested. The void
                         * cast is used to prevent byte alignment warnings from the
                         * compiler. */
                        pxNewBlockLink_core1 = ( void * ) ( ( ( uint8_t * ) pxBlock_core1 ) + xWantedSize_core1 );
                        configASSERT_core1( ( ( ( size_t ) pxNewBlockLink_core1 ) & portBYTE_ALIGNMENT_MASK_core1 ) == 0 );

                        /* Calculate the sizes of two blocks split from the
                         * single block. */
                        pxNewBlockLink_core1->xBlockSize_core1 = pxBlock_core1->xBlockSize_core1 - xWantedSize_core1;
                        pxBlock_core1->xBlockSize_core1 = xWantedSize_core1;

                        /* Insert the new block into the list of free blocks. */
                        prvInsertBlockIntoFreeList_core1( pxNewBlockLink_core1 );
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core1();
                    }

                    xFreeBytesRemaining_core1 -= pxBlock_core1->xBlockSize_core1;

                    if( xFreeBytesRemaining_core1 < xMinimumEverFreeBytesRemaining_core1 )
                    {
                        xMinimumEverFreeBytesRemaining_core1 = xFreeBytesRemaining_core1;
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core1();
                    }

                    /* The block is being returned - it is allocated and owned
                     * by the application and has no "next" block. */
                    heapALLOCATE_BLOCK_core1( pxBlock_core1 );
                    pxBlock_core1->pxNextFreeBlock_core1 = NULL;
                    xNumberOfSuccessfulAllocations_core1++;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core1();
                }
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core1();
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }

        traceMALLOC_core1( pvReturn_core1, xWantedSize_core1 );
    }
    ( void ) xTaskResumeAll_core1();

    #if ( configUSE_MALLOC_FAILED_HOOK_core1 == 1 )
    {
        if( pvReturn_core1 == NULL )
        {
            vApplicationMallocFailedHook_core1();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    #endif /* if ( configUSE_MALLOC_FAILED_HOOK_core1 == 1 ) */

    configASSERT_core1( ( ( ( size_t ) pvReturn_core1 ) & ( size_t ) portBYTE_ALIGNMENT_MASK_core1 ) == 0 );
    return pvReturn_core1;
}
/*-----------------------------------------------------------*/

void vPortFree_core1( void * pv_core1 )
{
    uint8_t * puc_core1 = ( uint8_t * ) pv_core1;
    BlockLink_t_core1 * pxLink_core1;

    if( pv_core1 != NULL )
    {
        /* The memory being freed will have an BlockLink_t_core1 structure immediately
         * before it. */
        puc_core1 -= xHeapStructSize_core1;

        /* This casting is to keep the compiler from issuing warnings. */
        pxLink_core1 = ( void * ) puc_core1;

        configASSERT_core1( heapBLOCK_IS_ALLOCATED_core1( pxLink_core1 ) != 0 );
        configASSERT_core1( pxLink_core1->pxNextFreeBlock_core1 == NULL );

        if( heapBLOCK_IS_ALLOCATED_core1( pxLink_core1 ) != 0 )
        {
            if( pxLink_core1->pxNextFreeBlock_core1 == NULL )
            {
                /* The block is being returned to the heap - it is no longer
                 * allocated. */
                heapFREE_BLOCK_core1( pxLink_core1 );
                #if ( configHEAP_CLEAR_MEMORY_ON_FREE == 1 )
                {
                    ( void ) memset( puc_core1 + xHeapStructSize_core1, 0, pxLink_core1->xBlockSize_core1 - xHeapStructSize_core1 );
                }
                #endif

                vTaskSuspendAll_core1();
                {
                    /* Add this block to the list of free blocks. */
                    xFreeBytesRemaining_core1 += pxLink_core1->xBlockSize_core1;
                    traceFREE_core1( pv_core1, pxLink_core1->xBlockSize_core1 );
                    prvInsertBlockIntoFreeList_core1( ( ( BlockLink_t_core1 * ) pxLink_core1 ) );
                    xNumberOfSuccessfulFrees_core1++;
                }
                ( void ) xTaskResumeAll_core1();
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core1();
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
}
/*-----------------------------------------------------------*/

size_t xPortGetFreeHeapSize_core1( void )
{
    return xFreeBytesRemaining_core1;
}
/*-----------------------------------------------------------*/

size_t xPortGetMinimumEverFreeHeapSize_core1( void )
{
    return xMinimumEverFreeBytesRemaining_core1;
}
/*-----------------------------------------------------------*/

void vPortInitialiseBlocks_core1( void )
{
    /* This just exists to keep the linker quiet. */
}
/*-----------------------------------------------------------*/

void * pvPortCalloc_core1( size_t xNum_core1,
                     size_t xSize_core1 )
{
    void * pv_core1 = NULL;

    if( heapMULTIPLY_WILL_OVERFLOW_core1( xNum_core1, xSize_core1 ) == 0 )
    {
        pv_core1 = pvPortMalloc_core1( xNum_core1 * xSize_core1 );

        if( pv_core1 != NULL )
        {
            ( void ) memset( pv_core1, 0, xNum_core1 * xSize_core1 );
        }
    }

    return pv_core1;
}
/*-----------------------------------------------------------*/

static void prvHeapInit_core1( void ) /* PRIVILEGED_FUNCTION_core1 */
{
    BlockLink_t_core1 * pxFirstFreeBlock_core1;
    uint8_t * pucAlignedHeap_core1;
    portPOINTER_SIZE_TYPE_core1 uxAddress_core1;
    size_t xTotalHeapSize_core1 = configTOTAL_HEAP_SIZE_core1;

    /* Ensure the heap starts on a correctly aligned boundary. */
    uxAddress_core1 = ( portPOINTER_SIZE_TYPE_core1 ) ucHeap_core1;

    if( ( uxAddress_core1 & portBYTE_ALIGNMENT_MASK_core1 ) != 0 )
    {
        uxAddress_core1 += ( portBYTE_ALIGNMENT_core1 - 1 );
        uxAddress_core1 &= ~( ( portPOINTER_SIZE_TYPE_core1 ) portBYTE_ALIGNMENT_MASK_core1 );
        xTotalHeapSize_core1 -= uxAddress_core1 - ( portPOINTER_SIZE_TYPE_core1 ) ucHeap_core1;
    }

    pucAlignedHeap_core1 = ( uint8_t * ) uxAddress_core1;

    /* xStart_core1 is used to hold a pointer to the first item in the list of free
     * blocks.  The void cast is used to prevent compiler warnings. */
    xStart_core1.pxNextFreeBlock_core1 = ( void * ) pucAlignedHeap_core1;
    xStart_core1.xBlockSize_core1 = ( size_t ) 0;

    /* pxEnd_core1 is used to mark the end of the list of free blocks and is inserted
     * at the end of the heap space. */
    uxAddress_core1 = ( ( portPOINTER_SIZE_TYPE_core1 ) pucAlignedHeap_core1 ) + xTotalHeapSize_core1;
    uxAddress_core1 -= xHeapStructSize_core1;
    uxAddress_core1 &= ~( ( portPOINTER_SIZE_TYPE_core1 ) portBYTE_ALIGNMENT_MASK_core1 );
    pxEnd_core1 = ( BlockLink_t_core1 * ) uxAddress_core1;
    pxEnd_core1->xBlockSize_core1 = 0;
    pxEnd_core1->pxNextFreeBlock_core1 = NULL;

    /* To start with there is a single free block that is sized to take up the
     * entire heap space, minus the space taken by pxEnd_core1. */
    pxFirstFreeBlock_core1 = ( BlockLink_t_core1 * ) pucAlignedHeap_core1;
    pxFirstFreeBlock_core1->xBlockSize_core1 = ( size_t ) ( uxAddress_core1 - ( portPOINTER_SIZE_TYPE_core1 ) pxFirstFreeBlock_core1 );
    pxFirstFreeBlock_core1->pxNextFreeBlock_core1 = pxEnd_core1;

    /* Only one block exists - and it covers the entire usable heap space. */
    xMinimumEverFreeBytesRemaining_core1 = pxFirstFreeBlock_core1->xBlockSize_core1;
    xFreeBytesRemaining_core1 = pxFirstFreeBlock_core1->xBlockSize_core1;
}
/*-----------------------------------------------------------*/

static void prvInsertBlockIntoFreeList_core1( BlockLink_t_core1 * pxBlockToInsert_core1 ) /* PRIVILEGED_FUNCTION_core1 */
{
    BlockLink_t_core1 * pxIterator_core1;
    uint8_t * puc_core1;

    /* Iterate through the list until a block is found that has a higher address
     * than the block being inserted. */
    for( pxIterator_core1 = &xStart_core1; pxIterator_core1->pxNextFreeBlock_core1 < pxBlockToInsert_core1; pxIterator_core1 = pxIterator_core1->pxNextFreeBlock_core1 )
    {
        /* Nothing to do here, just iterate to the right position. */
    }

    /* Do the block being inserted, and the block it is being inserted after
     * make a contiguous block of memory? */
    puc_core1 = ( uint8_t * ) pxIterator_core1;

    if( ( puc_core1 + pxIterator_core1->xBlockSize_core1 ) == ( uint8_t * ) pxBlockToInsert_core1 )
    {
        pxIterator_core1->xBlockSize_core1 += pxBlockToInsert_core1->xBlockSize_core1;
        pxBlockToInsert_core1 = pxIterator_core1;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    /* Do the block being inserted, and the block it is being inserted before
     * make a contiguous block of memory? */
    puc_core1 = ( uint8_t * ) pxBlockToInsert_core1;

    if( ( puc_core1 + pxBlockToInsert_core1->xBlockSize_core1 ) == ( uint8_t * ) pxIterator_core1->pxNextFreeBlock_core1 )
    {
        if( pxIterator_core1->pxNextFreeBlock_core1 != pxEnd_core1 )
        {
            /* Form one big block from the two blocks. */
            pxBlockToInsert_core1->xBlockSize_core1 += pxIterator_core1->pxNextFreeBlock_core1->xBlockSize_core1;
            pxBlockToInsert_core1->pxNextFreeBlock_core1 = pxIterator_core1->pxNextFreeBlock_core1->pxNextFreeBlock_core1;
        }
        else
        {
            pxBlockToInsert_core1->pxNextFreeBlock_core1 = pxEnd_core1;
        }
    }
    else
    {
        pxBlockToInsert_core1->pxNextFreeBlock_core1 = pxIterator_core1->pxNextFreeBlock_core1;
    }

    /* If the block being inserted plugged a gab, so was merged with the block
     * before and the block after, then it's pxNextFreeBlock_core1 pointer will have
     * already been set, and should not be set here as that would make it point
     * to itself. */
    if( pxIterator_core1 != pxBlockToInsert_core1 )
    {
        pxIterator_core1->pxNextFreeBlock_core1 = pxBlockToInsert_core1;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }
}
/*-----------------------------------------------------------*/

void vPortGetHeapStats_core1( HeapStats_t_core1 * pxHeapStats_core1 )
{
    BlockLink_t_core1 * pxBlock_core1;
    size_t xBlocks_core1 = 0, xMaxSize_core1 = 0, xMinSize_core1 = portMAX_DELAY_core1; /* portMAX_DELAY_core1 used as a portable way of getting the maximum value. */

    vTaskSuspendAll_core1();
    {
        pxBlock_core1 = xStart_core1.pxNextFreeBlock_core1;

        /* pxBlock_core1 will be NULL if the heap has not been initialised.  The heap
         * is initialised automatically when the first allocation is made. */
        if( pxBlock_core1 != NULL )
        {
            while( pxBlock_core1 != pxEnd_core1 )
            {
                /* Increment the number of blocks and record the largest block seen
                 * so far. */
                xBlocks_core1++;

                if( pxBlock_core1->xBlockSize_core1 > xMaxSize_core1 )
                {
                    xMaxSize_core1 = pxBlock_core1->xBlockSize_core1;
                }

                if( pxBlock_core1->xBlockSize_core1 < xMinSize_core1 )
                {
                    xMinSize_core1 = pxBlock_core1->xBlockSize_core1;
                }

                /* Move to the next block in the chain until the last block is
                 * reached. */
                pxBlock_core1 = pxBlock_core1->pxNextFreeBlock_core1;
            }
        }
    }
    ( void ) xTaskResumeAll_core1();

    pxHeapStats_core1->xSizeOfLargestFreeBlockInBytes_core1 = xMaxSize_core1;
    pxHeapStats_core1->xSizeOfSmallestFreeBlockInBytes_core1 = xMinSize_core1;
    pxHeapStats_core1->xNumberOfFreeBlocks_core1 = xBlocks_core1;

    taskENTER_CRITICAL_core1();
    {
        pxHeapStats_core1->xAvailableHeapSpaceInBytes_core1 = xFreeBytesRemaining_core1;
        pxHeapStats_core1->xNumberOfSuccessfulAllocations_core1 = xNumberOfSuccessfulAllocations_core1;
        pxHeapStats_core1->xNumberOfSuccessfulFrees_core1 = xNumberOfSuccessfulFrees_core1;
        pxHeapStats_core1->xMinimumEverFreeBytesRemaining_core1 = xMinimumEverFreeBytesRemaining_core1;
    }
    taskEXIT_CRITICAL_core1();
}
/*-----------------------------------------------------------*/
