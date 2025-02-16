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

/*
 * A sample implementation of pvPortMalloc_core2() and vPortFree_core2() that combines
 * (coalescences) adjacent memory blocks as they are freed, and in so doing
 * limits memory fragmentation.
 *
 * See heap_1.c, heap_2.c and heap_3.c for alternative implementations, and the
 * memory management pages of https://www.FreeRTOS_core2.org for more information.
 */
#include <stdlib.h>
#include <string.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 prevents task_core2.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core2.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2

#include "FreeRTOS_core2.h"
#include "task_core2.h"

#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2

#if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 0 )
    #error This file must not be used if configSUPPORT_DYNAMIC_ALLOCATION_core2 is 0
#endif

#ifndef configHEAP_CLEAR_MEMORY_ON_FREE
    #define configHEAP_CLEAR_MEMORY_ON_FREE    0
#endif

/* Block sizes must not get too small. */
#define heapMINIMUM_BLOCK_SIZE_core2    ( ( size_t ) ( xHeapStructSize_core2 << 1 ) )

/* Assumes 8bit bytes! */
#define heapBITS_PER_BYTE_core2         ( ( size_t ) 8 )

/* Max value that fits in a size_t type. */
#define heapSIZE_MAX_core2              ( ~( ( size_t ) 0 ) )

/* Check if multiplying a and b will result in overflow. */
#define heapMULTIPLY_WILL_OVERFLOW_core2( a, b )    ( ( ( a ) > 0 ) && ( ( b ) > ( heapSIZE_MAX_core2 / ( a ) ) ) )

/* Check if adding a and b will result in overflow. */
#define heapADD_WILL_OVERFLOW_core2( a, b )         ( ( a ) > ( heapSIZE_MAX_core2 - ( b ) ) )

/* MSB of the xBlockSize_core2 member of an BlockLink_t_core2 structure is used to track
 * the allocation status of a block.  When MSB of the xBlockSize_core2 member of
 * an BlockLink_t_core2 structure is set then the block belongs to the application.
 * When the bit is free the block is still part of the free heap space. */
#define heapBLOCK_ALLOCATED_BITMASK_core2    ( ( ( size_t ) 1 ) << ( ( sizeof( size_t ) * heapBITS_PER_BYTE_core2 ) - 1 ) )
#define heapBLOCK_SIZE_IS_VALID_core2( xBlockSize_core2 )    ( ( ( xBlockSize_core2 ) & heapBLOCK_ALLOCATED_BITMASK_core2 ) == 0 )
#define heapBLOCK_IS_ALLOCATED_core2( pxBlock_core2 )        ( ( ( pxBlock_core2->xBlockSize_core2 ) & heapBLOCK_ALLOCATED_BITMASK_core2 ) != 0 )
#define heapALLOCATE_BLOCK_core2( pxBlock_core2 )            ( ( pxBlock_core2->xBlockSize_core2 ) |= heapBLOCK_ALLOCATED_BITMASK_core2 )
#define heapFREE_BLOCK_core2( pxBlock_core2 )                ( ( pxBlock_core2->xBlockSize_core2 ) &= ~heapBLOCK_ALLOCATED_BITMASK_core2 )

/*-----------------------------------------------------------*/

/* Allocate the memory for the heap. */
#if ( configAPPLICATION_ALLOCATED_HEAP_core2 == 1 )

/* The application writer has already defined the array used for the RTOS
* heap - probably so it can be placed in a special segment or address. */
    extern uint8_t ucHeap_core2[ configTOTAL_HEAP_SIZE_core2 ];
#else
    PRIVILEGED_DATA_core2 static uint8_t ucHeap_core2[ configTOTAL_HEAP_SIZE_core2 ];
#endif /* configAPPLICATION_ALLOCATED_HEAP_core2 */

/* Define the linked list structure.  This is used to link free blocks in order
 * of their memory address. */
typedef struct A_BLOCK_LINK_core2
{
    struct A_BLOCK_LINK_core2 * pxNextFreeBlock_core2; /*<< The next free block in the list. */
    size_t xBlockSize_core2;                     /*<< The size of the free block. */
} BlockLink_t_core2;

/*-----------------------------------------------------------*/

/*
 * Inserts a block of memory that is being freed into the correct position in
 * the list of free memory blocks.  The block being freed will be merged with
 * the block in front it and/or the block behind it if the memory blocks are
 * adjacent to each other.
 */
static void prvInsertBlockIntoFreeList_core2( BlockLink_t_core2 * pxBlockToInsert_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Called automatically to setup the required heap structures the first time
 * pvPortMalloc_core2() is called.
 */
static void prvHeapInit_core2( void ) PRIVILEGED_FUNCTION_core2;

/*-----------------------------------------------------------*/

/* The size of the structure placed at the beginning of each allocated memory
 * block must by correctly byte aligned. */
static const size_t xHeapStructSize_core2 = ( sizeof( BlockLink_t_core2 ) + ( ( size_t ) ( portBYTE_ALIGNMENT_core2 - 1 ) ) ) & ~( ( size_t ) portBYTE_ALIGNMENT_MASK_core2 );

/* Create a couple of list links to mark the start and end of the list. */
PRIVILEGED_DATA_core2 static BlockLink_t_core2 xStart_core2;
PRIVILEGED_DATA_core2 static BlockLink_t_core2 * pxEnd_core2 = NULL;

/* Keeps track of the number of calls to allocate and free memory as well as the
 * number of free bytes remaining, but says nothing about fragmentation. */
PRIVILEGED_DATA_core2 static size_t xFreeBytesRemaining_core2 = 0U;
PRIVILEGED_DATA_core2 static size_t xMinimumEverFreeBytesRemaining_core2 = 0U;
PRIVILEGED_DATA_core2 static size_t xNumberOfSuccessfulAllocations_core2 = 0;
PRIVILEGED_DATA_core2 static size_t xNumberOfSuccessfulFrees_core2 = 0;

/*-----------------------------------------------------------*/

void * pvPortMalloc_core2( size_t xWantedSize_core2 )
{
    BlockLink_t_core2 * pxBlock_core2;
    BlockLink_t_core2 * pxPreviousBlock_core2;
    BlockLink_t_core2 * pxNewBlockLink_core2;
    void * pvReturn_core2 = NULL;
    size_t xAdditionalRequiredSize_core2;

    vTaskSuspendAll_core2();
    {
        /* If this is the first call to malloc then the heap will require
         * initialisation to setup the list of free blocks. */
        if( pxEnd_core2 == NULL )
        {
            prvHeapInit_core2();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }

        if( xWantedSize_core2 > 0 )
        {
            /* The wanted size must be increased so it can contain a BlockLink_t_core2
             * structure in addition to the requested amount of bytes. Some
             * additional increment may also be needed for alignment. */
            xAdditionalRequiredSize_core2 = xHeapStructSize_core2 + portBYTE_ALIGNMENT_core2 - ( xWantedSize_core2 & portBYTE_ALIGNMENT_MASK_core2 );

            if( heapADD_WILL_OVERFLOW_core2( xWantedSize_core2, xAdditionalRequiredSize_core2 ) == 0 )
            {
                xWantedSize_core2 += xAdditionalRequiredSize_core2;
            }
            else
            {
                xWantedSize_core2 = 0;
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }

        /* Check the block size we are trying to allocate is not so large that the
         * top bit is set.  The top bit of the block size member of the BlockLink_t_core2
         * structure is used to determine who owns the block - the application or
         * the kernel, so it must be free. */
        if( heapBLOCK_SIZE_IS_VALID_core2( xWantedSize_core2 ) != 0 )
        {
            if( ( xWantedSize_core2 > 0 ) && ( xWantedSize_core2 <= xFreeBytesRemaining_core2 ) )
            {
                /* Traverse the list from the start (lowest address) block until
                 * one of adequate size is found. */
                pxPreviousBlock_core2 = &xStart_core2;
                pxBlock_core2 = xStart_core2.pxNextFreeBlock_core2;

                while( ( pxBlock_core2->xBlockSize_core2 < xWantedSize_core2 ) && ( pxBlock_core2->pxNextFreeBlock_core2 != NULL ) )
                {
                    pxPreviousBlock_core2 = pxBlock_core2;
                    pxBlock_core2 = pxBlock_core2->pxNextFreeBlock_core2;
                }

                /* If the end marker was reached then a block of adequate size
                 * was not found. */
                if( pxBlock_core2 != pxEnd_core2 )
                {
                    /* Return the memory space pointed to - jumping over the
                     * BlockLink_t_core2 structure at its start. */
                    pvReturn_core2 = ( void * ) ( ( ( uint8_t * ) pxPreviousBlock_core2->pxNextFreeBlock_core2 ) + xHeapStructSize_core2 );

                    /* This block is being returned for use so must be taken out
                     * of the list of free blocks. */
                    pxPreviousBlock_core2->pxNextFreeBlock_core2 = pxBlock_core2->pxNextFreeBlock_core2;

                    /* If the block is larger than required it can be split into
                     * two. */
                    if( ( pxBlock_core2->xBlockSize_core2 - xWantedSize_core2 ) > heapMINIMUM_BLOCK_SIZE_core2 )
                    {
                        /* This block is to be split into two.  Create a new
                         * block following the number of bytes requested. The void
                         * cast is used to prevent byte alignment warnings from the
                         * compiler. */
                        pxNewBlockLink_core2 = ( void * ) ( ( ( uint8_t * ) pxBlock_core2 ) + xWantedSize_core2 );
                        configASSERT_core2( ( ( ( size_t ) pxNewBlockLink_core2 ) & portBYTE_ALIGNMENT_MASK_core2 ) == 0 );

                        /* Calculate the sizes of two blocks split from the
                         * single block. */
                        pxNewBlockLink_core2->xBlockSize_core2 = pxBlock_core2->xBlockSize_core2 - xWantedSize_core2;
                        pxBlock_core2->xBlockSize_core2 = xWantedSize_core2;

                        /* Insert the new block into the list of free blocks. */
                        prvInsertBlockIntoFreeList_core2( pxNewBlockLink_core2 );
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core2();
                    }

                    xFreeBytesRemaining_core2 -= pxBlock_core2->xBlockSize_core2;

                    if( xFreeBytesRemaining_core2 < xMinimumEverFreeBytesRemaining_core2 )
                    {
                        xMinimumEverFreeBytesRemaining_core2 = xFreeBytesRemaining_core2;
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER_core2();
                    }

                    /* The block is being returned - it is allocated and owned
                     * by the application and has no "next" block. */
                    heapALLOCATE_BLOCK_core2( pxBlock_core2 );
                    pxBlock_core2->pxNextFreeBlock_core2 = NULL;
                    xNumberOfSuccessfulAllocations_core2++;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core2();
                }
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core2();
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }

        traceMALLOC_core2( pvReturn_core2, xWantedSize_core2 );
    }
    ( void ) xTaskResumeAll_core2();

    #if ( configUSE_MALLOC_FAILED_HOOK_core2 == 1 )
    {
        if( pvReturn_core2 == NULL )
        {
            vApplicationMallocFailedHook_core2();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    #endif /* if ( configUSE_MALLOC_FAILED_HOOK_core2 == 1 ) */

    configASSERT_core2( ( ( ( size_t ) pvReturn_core2 ) & ( size_t ) portBYTE_ALIGNMENT_MASK_core2 ) == 0 );
    return pvReturn_core2;
}
/*-----------------------------------------------------------*/

void vPortFree_core2( void * pv_core2 )
{
    uint8_t * puc_core2 = ( uint8_t * ) pv_core2;
    BlockLink_t_core2 * pxLink_core2;

    if( pv_core2 != NULL )
    {
        /* The memory being freed will have an BlockLink_t_core2 structure immediately
         * before it. */
        puc_core2 -= xHeapStructSize_core2;

        /* This casting is to keep the compiler from issuing warnings. */
        pxLink_core2 = ( void * ) puc_core2;

        configASSERT_core2( heapBLOCK_IS_ALLOCATED_core2( pxLink_core2 ) != 0 );
        configASSERT_core2( pxLink_core2->pxNextFreeBlock_core2 == NULL );

        if( heapBLOCK_IS_ALLOCATED_core2( pxLink_core2 ) != 0 )
        {
            if( pxLink_core2->pxNextFreeBlock_core2 == NULL )
            {
                /* The block is being returned to the heap - it is no longer
                 * allocated. */
                heapFREE_BLOCK_core2( pxLink_core2 );
                #if ( configHEAP_CLEAR_MEMORY_ON_FREE == 1 )
                {
                    ( void ) memset( puc_core2 + xHeapStructSize_core2, 0, pxLink_core2->xBlockSize_core2 - xHeapStructSize_core2 );
                }
                #endif

                vTaskSuspendAll_core2();
                {
                    /* Add this block to the list of free blocks. */
                    xFreeBytesRemaining_core2 += pxLink_core2->xBlockSize_core2;
                    traceFREE_core2( pv_core2, pxLink_core2->xBlockSize_core2 );
                    prvInsertBlockIntoFreeList_core2( ( ( BlockLink_t_core2 * ) pxLink_core2 ) );
                    xNumberOfSuccessfulFrees_core2++;
                }
                ( void ) xTaskResumeAll_core2();
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core2();
            }
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
}
/*-----------------------------------------------------------*/

size_t xPortGetFreeHeapSize_core2( void )
{
    return xFreeBytesRemaining_core2;
}
/*-----------------------------------------------------------*/

size_t xPortGetMinimumEverFreeHeapSize_core2( void )
{
    return xMinimumEverFreeBytesRemaining_core2;
}
/*-----------------------------------------------------------*/

void vPortInitialiseBlocks_core2( void )
{
    /* This just exists to keep the linker quiet. */
}
/*-----------------------------------------------------------*/

void * pvPortCalloc_core2( size_t xNum_core2,
                     size_t xSize_core2 )
{
    void * pv_core2 = NULL;

    if( heapMULTIPLY_WILL_OVERFLOW_core2( xNum_core2, xSize_core2 ) == 0 )
    {
        pv_core2 = pvPortMalloc_core2( xNum_core2 * xSize_core2 );

        if( pv_core2 != NULL )
        {
            ( void ) memset( pv_core2, 0, xNum_core2 * xSize_core2 );
        }
    }

    return pv_core2;
}
/*-----------------------------------------------------------*/

static void prvHeapInit_core2( void ) /* PRIVILEGED_FUNCTION_core2 */
{
    BlockLink_t_core2 * pxFirstFreeBlock_core2;
    uint8_t * pucAlignedHeap_core2;
    portPOINTER_SIZE_TYPE_core2 uxAddress_core2;
    size_t xTotalHeapSize_core2 = configTOTAL_HEAP_SIZE_core2;

    /* Ensure the heap starts on a correctly aligned boundary. */
    uxAddress_core2 = ( portPOINTER_SIZE_TYPE_core2 ) ucHeap_core2;

    if( ( uxAddress_core2 & portBYTE_ALIGNMENT_MASK_core2 ) != 0 )
    {
        uxAddress_core2 += ( portBYTE_ALIGNMENT_core2 - 1 );
        uxAddress_core2 &= ~( ( portPOINTER_SIZE_TYPE_core2 ) portBYTE_ALIGNMENT_MASK_core2 );
        xTotalHeapSize_core2 -= uxAddress_core2 - ( portPOINTER_SIZE_TYPE_core2 ) ucHeap_core2;
    }

    pucAlignedHeap_core2 = ( uint8_t * ) uxAddress_core2;

    /* xStart_core2 is used to hold a pointer to the first item in the list of free
     * blocks.  The void cast is used to prevent compiler warnings. */
    xStart_core2.pxNextFreeBlock_core2 = ( void * ) pucAlignedHeap_core2;
    xStart_core2.xBlockSize_core2 = ( size_t ) 0;

    /* pxEnd_core2 is used to mark the end of the list of free blocks and is inserted
     * at the end of the heap space. */
    uxAddress_core2 = ( ( portPOINTER_SIZE_TYPE_core2 ) pucAlignedHeap_core2 ) + xTotalHeapSize_core2;
    uxAddress_core2 -= xHeapStructSize_core2;
    uxAddress_core2 &= ~( ( portPOINTER_SIZE_TYPE_core2 ) portBYTE_ALIGNMENT_MASK_core2 );
    pxEnd_core2 = ( BlockLink_t_core2 * ) uxAddress_core2;
    pxEnd_core2->xBlockSize_core2 = 0;
    pxEnd_core2->pxNextFreeBlock_core2 = NULL;

    /* To start with there is a single free block that is sized to take up the
     * entire heap space, minus the space taken by pxEnd_core2. */
    pxFirstFreeBlock_core2 = ( BlockLink_t_core2 * ) pucAlignedHeap_core2;
    pxFirstFreeBlock_core2->xBlockSize_core2 = ( size_t ) ( uxAddress_core2 - ( portPOINTER_SIZE_TYPE_core2 ) pxFirstFreeBlock_core2 );
    pxFirstFreeBlock_core2->pxNextFreeBlock_core2 = pxEnd_core2;

    /* Only one block exists - and it covers the entire usable heap space. */
    xMinimumEverFreeBytesRemaining_core2 = pxFirstFreeBlock_core2->xBlockSize_core2;
    xFreeBytesRemaining_core2 = pxFirstFreeBlock_core2->xBlockSize_core2;
}
/*-----------------------------------------------------------*/

static void prvInsertBlockIntoFreeList_core2( BlockLink_t_core2 * pxBlockToInsert_core2 ) /* PRIVILEGED_FUNCTION_core2 */
{
    BlockLink_t_core2 * pxIterator_core2;
    uint8_t * puc_core2;

    /* Iterate through the list until a block is found that has a higher address
     * than the block being inserted. */
    for( pxIterator_core2 = &xStart_core2; pxIterator_core2->pxNextFreeBlock_core2 < pxBlockToInsert_core2; pxIterator_core2 = pxIterator_core2->pxNextFreeBlock_core2 )
    {
        /* Nothing to do here, just iterate to the right position. */
    }

    /* Do the block being inserted, and the block it is being inserted after
     * make a contiguous block of memory? */
    puc_core2 = ( uint8_t * ) pxIterator_core2;

    if( ( puc_core2 + pxIterator_core2->xBlockSize_core2 ) == ( uint8_t * ) pxBlockToInsert_core2 )
    {
        pxIterator_core2->xBlockSize_core2 += pxBlockToInsert_core2->xBlockSize_core2;
        pxBlockToInsert_core2 = pxIterator_core2;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    /* Do the block being inserted, and the block it is being inserted before
     * make a contiguous block of memory? */
    puc_core2 = ( uint8_t * ) pxBlockToInsert_core2;

    if( ( puc_core2 + pxBlockToInsert_core2->xBlockSize_core2 ) == ( uint8_t * ) pxIterator_core2->pxNextFreeBlock_core2 )
    {
        if( pxIterator_core2->pxNextFreeBlock_core2 != pxEnd_core2 )
        {
            /* Form one big block from the two blocks. */
            pxBlockToInsert_core2->xBlockSize_core2 += pxIterator_core2->pxNextFreeBlock_core2->xBlockSize_core2;
            pxBlockToInsert_core2->pxNextFreeBlock_core2 = pxIterator_core2->pxNextFreeBlock_core2->pxNextFreeBlock_core2;
        }
        else
        {
            pxBlockToInsert_core2->pxNextFreeBlock_core2 = pxEnd_core2;
        }
    }
    else
    {
        pxBlockToInsert_core2->pxNextFreeBlock_core2 = pxIterator_core2->pxNextFreeBlock_core2;
    }

    /* If the block being inserted plugged a gab, so was merged with the block
     * before and the block after, then it's pxNextFreeBlock_core2 pointer will have
     * already been set, and should not be set here as that would make it point
     * to itself. */
    if( pxIterator_core2 != pxBlockToInsert_core2 )
    {
        pxIterator_core2->pxNextFreeBlock_core2 = pxBlockToInsert_core2;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }
}
/*-----------------------------------------------------------*/

void vPortGetHeapStats_core2( HeapStats_t_core2 * pxHeapStats_core2 )
{
    BlockLink_t_core2 * pxBlock_core2;
    size_t xBlocks_core2 = 0, xMaxSize_core2 = 0, xMinSize_core2 = portMAX_DELAY_core2; /* portMAX_DELAY_core2 used as a portable way of getting the maximum value. */

    vTaskSuspendAll_core2();
    {
        pxBlock_core2 = xStart_core2.pxNextFreeBlock_core2;

        /* pxBlock_core2 will be NULL if the heap has not been initialised.  The heap
         * is initialised automatically when the first allocation is made. */
        if( pxBlock_core2 != NULL )
        {
            while( pxBlock_core2 != pxEnd_core2 )
            {
                /* Increment the number of blocks and record the largest block seen
                 * so far. */
                xBlocks_core2++;

                if( pxBlock_core2->xBlockSize_core2 > xMaxSize_core2 )
                {
                    xMaxSize_core2 = pxBlock_core2->xBlockSize_core2;
                }

                if( pxBlock_core2->xBlockSize_core2 < xMinSize_core2 )
                {
                    xMinSize_core2 = pxBlock_core2->xBlockSize_core2;
                }

                /* Move to the next block in the chain until the last block is
                 * reached. */
                pxBlock_core2 = pxBlock_core2->pxNextFreeBlock_core2;
            }
        }
    }
    ( void ) xTaskResumeAll_core2();

    pxHeapStats_core2->xSizeOfLargestFreeBlockInBytes_core2 = xMaxSize_core2;
    pxHeapStats_core2->xSizeOfSmallestFreeBlockInBytes_core2 = xMinSize_core2;
    pxHeapStats_core2->xNumberOfFreeBlocks_core2 = xBlocks_core2;

    taskENTER_CRITICAL_core2();
    {
        pxHeapStats_core2->xAvailableHeapSpaceInBytes_core2 = xFreeBytesRemaining_core2;
        pxHeapStats_core2->xNumberOfSuccessfulAllocations_core2 = xNumberOfSuccessfulAllocations_core2;
        pxHeapStats_core2->xNumberOfSuccessfulFrees_core2 = xNumberOfSuccessfulFrees_core2;
        pxHeapStats_core2->xMinimumEverFreeBytesRemaining_core2 = xMinimumEverFreeBytesRemaining_core2;
    }
    taskEXIT_CRITICAL_core2();
}
/*-----------------------------------------------------------*/
