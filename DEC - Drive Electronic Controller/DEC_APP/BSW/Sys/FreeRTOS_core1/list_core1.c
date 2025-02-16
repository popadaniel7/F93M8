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


#include <stdlib.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 prevents task_core1.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core1.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1

#include "FreeRTOS_core1.h"
#include "list_core1.h"

/* Lint e9021, e961 and e750 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 to be
 * defined for the header files above, but not in this file, in order to
 * generate the correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 /*lint !e961 !e750 !e9021. */

/*-----------------------------------------------------------
* PUBLIC LIST API documented in list.h
*----------------------------------------------------------*/

void vListInitialise_core1( List_t_core1 * const pxList_core1 )
{
    /* The list structure contains a list item which is used to mark the
     * end of the list.  To initialise the list the list end is inserted
     * as the only list entry. */
    pxList_core1->pxIndex_core1 = ( ListItem_t_core1 * ) &( pxList_core1->xListEnd_core1 ); /*lint !e826 !e740 !e9087 The mini list structure is used as the list end to save RAM.  This is checked and valid. */

    listSET_FIRST_LIST_ITEM_INTEGRITY_CHECK_VALUE_core1( &( pxList_core1->xListEnd_core1 ) );

    /* The list end value is the highest possible value in the list to
     * ensure it remains at the end of the list. */
    pxList_core1->xListEnd_core1.xItemValue_core1 = portMAX_DELAY_core1;

    /* The list end next and previous pointers point to itself so we know
     * when the list is empty. */
    pxList_core1->xListEnd_core1.pxNext_core1 = ( ListItem_t_core1 * ) &( pxList_core1->xListEnd_core1 );     /*lint !e826 !e740 !e9087 The mini list structure is used as the list end to save RAM.  This is checked and valid. */
    pxList_core1->xListEnd_core1.pxPrevious_core1 = ( ListItem_t_core1 * ) &( pxList_core1->xListEnd_core1 ); /*lint !e826 !e740 !e9087 The mini list structure is used as the list end to save RAM.  This is checked and valid. */

    /* Initialize the remaining fields of xListEnd_core1 when it is a proper ListItem_t_core1 */
    #if ( configUSE_MINI_LIST_ITEM_core1 == 0 )
    {
        pxList_core1->xListEnd_core1.pvOwner_core1 = NULL;
        pxList_core1->xListEnd_core1.pxContainer_core1 = NULL;
        listSET_SECOND_LIST_ITEM_INTEGRITY_CHECK_VALUE_core1( &( pxList_core1->xListEnd_core1 ) );
    }
    #endif

    pxList_core1->uxNumberOfItems_core1 = ( UBaseType_t_core1 ) 0U;

    /* Write known values into the list if
     * configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core1 is set to 1. */
    listSET_LIST_INTEGRITY_CHECK_1_VALUE_core1( pxList_core1 );
    listSET_LIST_INTEGRITY_CHECK_2_VALUE_core1( pxList_core1 );
}
/*-----------------------------------------------------------*/

void vListInitialiseItem_core1( ListItem_t_core1 * const pxItem_core1 )
{
    /* Make sure the list item is not recorded as being on a list. */
    pxItem_core1->pxContainer_core1 = NULL;

    /* Write known values into the list item if
     * configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES_core1 is set to 1. */
    listSET_FIRST_LIST_ITEM_INTEGRITY_CHECK_VALUE_core1( pxItem_core1 );
    listSET_SECOND_LIST_ITEM_INTEGRITY_CHECK_VALUE_core1( pxItem_core1 );
}
/*-----------------------------------------------------------*/

void vListInsertEnd_core1( List_t_core1 * const pxList_core1,
                     ListItem_t_core1 * const pxNewListItem_core1 )
{
    ListItem_t_core1 * const pxIndex_core1 = pxList_core1->pxIndex_core1;

    /* Only effective when configASSERT_core1() is also defined, these tests may catch
     * the list data structures being overwritten in memory.  They will not catch
     * data errors caused by incorrect configuration or use of FreeRTOS_core1. */
    listTEST_LIST_INTEGRITY_core1( pxList_core1 );
    listTEST_LIST_ITEM_INTEGRITY_core1( pxNewListItem_core1 );

    /* Insert a new list item into pxList_core1, but rather than sort the list,
     * makes the new list item the last item to be removed by a call to
     * listGET_OWNER_OF_NEXT_ENTRY_core1(). */
    pxNewListItem_core1->pxNext_core1 = pxIndex_core1;
    pxNewListItem_core1->pxPrevious_core1 = pxIndex_core1->pxPrevious_core1;

    /* Only used during decision coverage testing. */
    mtCOVERAGE_TEST_DELAY_core1();

    pxIndex_core1->pxPrevious_core1->pxNext_core1 = pxNewListItem_core1;
    pxIndex_core1->pxPrevious_core1 = pxNewListItem_core1;

    /* Remember which list the item is in. */
    pxNewListItem_core1->pxContainer_core1 = pxList_core1;

    ( pxList_core1->uxNumberOfItems_core1 )++;
}
/*-----------------------------------------------------------*/

void vListInsert_core1( List_t_core1 * const pxList_core1,
                  ListItem_t_core1 * const pxNewListItem_core1 )
{
    ListItem_t_core1 * pxIterator_core1;
    const TickType_t_core1 xValueOfInsertion_core1 = pxNewListItem_core1->xItemValue_core1;

    /* Only effective when configASSERT_core1() is also defined, these tests may catch
     * the list data structures being overwritten in memory.  They will not catch
     * data errors caused by incorrect configuration or use of FreeRTOS_core1. */
    listTEST_LIST_INTEGRITY_core1( pxList_core1 );
    listTEST_LIST_ITEM_INTEGRITY_core1( pxNewListItem_core1 );

    /* Insert the new list item into the list, sorted in xItemValue_core1 order.
     *
     * If the list already contains a list item with the same item value then the
     * new list item should be placed after it.  This ensures that TCBs which are
     * stored in ready lists (all of which have the same xItemValue_core1 value) get a
     * share of the CPU.  However, if the xItemValue_core1 is the same as the back marker
     * the iteration loop below will not end.  Therefore the value is checked
     * first, and the algorithm slightly modified if necessary. */
    if( xValueOfInsertion_core1 == portMAX_DELAY_core1 )
    {
        pxIterator_core1 = pxList_core1->xListEnd_core1.pxPrevious_core1;
    }
    else
    {
        /* *** NOTE ***********************************************************
        *  If you find your application is crashing here then likely causes are
        *  listed below.  In addition see https://www.FreeRTOS_core1.org/FAQHelp.html for
        *  more tips, and ensure configASSERT_core1() is defined!
        *  https://www.FreeRTOS_core1.org/a00110.html#configASSERT_core1
        *
        *   1) Stack overflow -
        *      see https://www.FreeRTOS_core1.org/Stacks-and-stack-overflow-checking.html
        *   2) Incorrect interrupt priority assignment, especially on Cortex-M
        *      parts where numerically high priority values denote low actual
        *      interrupt priorities, which can seem counter intuitive.  See
        *      https://www.FreeRTOS_core1.org/RTOS-Cortex-M3-M4.html and the definition
        *      of configMAX_SYSCALL_INTERRUPT_PRIORITY on
        *      https://www.FreeRTOS_core1.org/a00110.html
        *   3) Calling an API function from within a critical section or when
        *      the scheduler is suspended, or calling an API function that does
        *      not end in "FromISR" from an interrupt.
        *   4) Using a queue or semaphore before it has been initialised or
        *      before the scheduler has been started (are interrupts firing
        *      before vTaskStartScheduler_core1() has been called?).
        *   5) If the FreeRTOS_core1 port supports interrupt nesting then ensure that
        *      the priority of the tick interrupt is at or below
        *      configMAX_SYSCALL_INTERRUPT_PRIORITY.
        **********************************************************************/

        for( pxIterator_core1 = ( ListItem_t_core1 * ) &( pxList_core1->xListEnd_core1 ); pxIterator_core1->pxNext_core1->xItemValue_core1 <= xValueOfInsertion_core1; pxIterator_core1 = pxIterator_core1->pxNext_core1 ) /*lint !e826 !e740 !e9087 The mini list structure is used as the list end to save RAM.  This is checked and valid. *//*lint !e440 The iterator moves to a different value, not xValueOfInsertion_core1. */
        {
            /* There is nothing to do here, just iterating to the wanted
             * insertion position. */
        }
    }

    pxNewListItem_core1->pxNext_core1 = pxIterator_core1->pxNext_core1;
    pxNewListItem_core1->pxNext_core1->pxPrevious_core1 = pxNewListItem_core1;
    pxNewListItem_core1->pxPrevious_core1 = pxIterator_core1;
    pxIterator_core1->pxNext_core1 = pxNewListItem_core1;

    /* Remember which list the item is in.  This allows fast removal of the
     * item later. */
    pxNewListItem_core1->pxContainer_core1 = pxList_core1;

    ( pxList_core1->uxNumberOfItems_core1 )++;
}
/*-----------------------------------------------------------*/

UBaseType_t_core1 uxListRemove_core1( ListItem_t_core1 * const pxItemToRemove_core1 )
{
/* The list item knows which list it is in.  Obtain the list from the list
 * item. */
    List_t_core1 * const pxList_core1 = pxItemToRemove_core1->pxContainer_core1;

    pxItemToRemove_core1->pxNext_core1->pxPrevious_core1 = pxItemToRemove_core1->pxPrevious_core1;
    pxItemToRemove_core1->pxPrevious_core1->pxNext_core1 = pxItemToRemove_core1->pxNext_core1;

    /* Only used during decision coverage testing. */
    mtCOVERAGE_TEST_DELAY_core1();

    /* Make sure the index is left pointing to a valid item. */
    if( pxList_core1->pxIndex_core1 == pxItemToRemove_core1 )
    {
        pxList_core1->pxIndex_core1 = pxItemToRemove_core1->pxPrevious_core1;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    pxItemToRemove_core1->pxContainer_core1 = NULL;
    ( pxList_core1->uxNumberOfItems_core1 )--;

    return pxList_core1->uxNumberOfItems_core1;
}
/*-----------------------------------------------------------*/
