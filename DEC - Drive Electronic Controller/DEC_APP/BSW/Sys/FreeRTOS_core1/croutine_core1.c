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
#include "task_core1.h"
#include "croutine_core1.h"

/* Remove the whole file is co-routines are not being used. */
#if ( configUSE_CO_ROUTINES_core1 != 0 )

/*
 * Some kernel aware debuggers require data to be viewed to be global, rather
 * than file scope.
 */
    #ifdef portREMOVE_STATIC_QUALIFIER_core1
        #define static
    #endif


/* Lists for ready and blocked co-routines. --------------------*/
    static List_t_core1 pxReadyCoRoutineLists_core1[ configMAX_CO_ROUTINE_PRIORITIES_core1 ]; /*< Prioritised ready co-routines. */
    static List_t_core1 xDelayedCoRoutineList1_core1;                                   /*< Delayed co-routines. */
    static List_t_core1 xDelayedCoRoutineList2_core1;                                   /*< Delayed co-routines (two lists are used - one for delays that have overflowed the current tick count. */
    static List_t_core1 * pxDelayedCoRoutineList_core1 = NULL;                          /*< Points to the delayed co-routine list currently being used. */
    static List_t_core1 * pxOverflowDelayedCoRoutineList_core1 = NULL;                  /*< Points to the delayed co-routine list currently being used to hold co-routines that have overflowed the current tick count. */
    static List_t_core1 xPendingReadyCoRoutineList_core1;                               /*< Holds co-routines that have been readied by an external event.  They cannot be added directly to the ready lists as the ready lists cannot be accessed by interrupts. */

/* Other file private variables. --------------------------------*/
    CRCB_t_core1 * pxCurrentCoRoutine_core1 = NULL;
    static UBaseType_t_core1 uxTopCoRoutineReadyPriority_core1 = 0;
    static TickType_t_core1 xCoRoutineTickCount_core1 = 0, xLastTickCount_core1 = 0, xPassedTicks_core1 = 0;

/* The initial state of the co-routine when it is created. */
    #define corINITIAL_STATE_core1    ( 0 )

/*
 * Place the co-routine represented by pxCRCB_core1 into the appropriate ready queue
 * for the priority.  It is inserted at the end of the list.
 *
 * This macro accesses the co-routine ready lists and therefore must not be
 * used from within an ISR.
 */
    #define prvAddCoRoutineToReadyQueue_core1( pxCRCB_core1 )                                                                               \
    {                                                                                                                           \
        if( ( pxCRCB_core1 )->uxPriority_core1 > uxTopCoRoutineReadyPriority_core1 )                                                              \
        {                                                                                                                       \
            uxTopCoRoutineReadyPriority_core1 = ( pxCRCB_core1 )->uxPriority_core1;                                                               \
        }                                                                                                                       \
        vListInsertEnd_core1( ( List_t_core1 * ) &( pxReadyCoRoutineLists_core1[ ( pxCRCB_core1 )->uxPriority_core1 ] ), &( ( pxCRCB_core1 )->xGenericListItem_core1 ) ); \
    }

/*
 * Utility to ready all the lists used by the scheduler.  This is called
 * automatically upon the creation of the first co-routine.
 */
    static void prvInitialiseCoRoutineLists_core1( void );

/*
 * Co-routines that are readied by an interrupt cannot be placed directly into
 * the ready lists (there is no mutual exclusion).  Instead they are placed in
 * in the pending ready list in order that they can later be moved to the ready
 * list by the co-routine scheduler.
 */
    static void prvCheckPendingReadyList_core1( void );

/*
 * Macro that looks at the list of co-routines that are currently delayed to
 * see if any require waking.
 *
 * Co-routines are stored in the queue in the order of their wake time -
 * meaning once one co-routine has been found whose timer has not expired
 * we need not look any further down the list.
 */
    static void prvCheckDelayedList_core1( void );

/*-----------------------------------------------------------*/

    BaseType_t_core1 xCoRoutineCreate_core1( crCOROUTINE_CODE_core1 pxCoRoutineCode_core1,
                                 UBaseType_t_core1 uxPriority_core1,
                                 UBaseType_t_core1 uxIndex_core1 )
    {
        BaseType_t_core1 xReturn_core1;
        CRCB_t_core1 * pxCoRoutine_core1;

        /* Allocate the memory that will store the co-routine control block. */
        pxCoRoutine_core1 = ( CRCB_t_core1 * ) pvPortMalloc_core1( sizeof( CRCB_t_core1 ) );

        if( pxCoRoutine_core1 )
        {
            /* If pxCurrentCoRoutine_core1 is NULL then this is the first co-routine to
            * be created and the co-routine data structures need initialising. */
            if( pxCurrentCoRoutine_core1 == NULL )
            {
                pxCurrentCoRoutine_core1 = pxCoRoutine_core1;
                prvInitialiseCoRoutineLists_core1();
            }

            /* Check the priority is within limits. */
            if( uxPriority_core1 >= configMAX_CO_ROUTINE_PRIORITIES_core1 )
            {
                uxPriority_core1 = configMAX_CO_ROUTINE_PRIORITIES_core1 - 1;
            }

            /* Fill out the co-routine control block from the function parameters. */
            pxCoRoutine_core1->uxState_core1 = corINITIAL_STATE_core1;
            pxCoRoutine_core1->uxPriority_core1 = uxPriority_core1;
            pxCoRoutine_core1->uxIndex_core1 = uxIndex_core1;
            pxCoRoutine_core1->pxCoRoutineFunction_core1 = pxCoRoutineCode_core1;

            /* Initialise all the other co-routine control block parameters. */
            vListInitialiseItem_core1( &( pxCoRoutine_core1->xGenericListItem_core1 ) );
            vListInitialiseItem_core1( &( pxCoRoutine_core1->xEventListItem_core1 ) );

            /* Set the co-routine control block as a link back from the ListItem_t_core1.
             * This is so we can get back to the containing CRCB from a generic item
             * in a list. */
            listSET_LIST_ITEM_OWNER_core1( &( pxCoRoutine_core1->xGenericListItem_core1 ), pxCoRoutine_core1 );
            listSET_LIST_ITEM_OWNER_core1( &( pxCoRoutine_core1->xEventListItem_core1 ), pxCoRoutine_core1 );

            /* Event lists are always in priority order. */
            listSET_LIST_ITEM_VALUE_core1( &( pxCoRoutine_core1->xEventListItem_core1 ), ( ( TickType_t_core1 ) configMAX_CO_ROUTINE_PRIORITIES_core1 - ( TickType_t_core1 ) uxPriority_core1 ) );

            /* Now the co-routine has been initialised it can be added to the ready
             * list at the correct priority. */
            prvAddCoRoutineToReadyQueue_core1( pxCoRoutine_core1 );

            xReturn_core1 = pdPASS_core1;
        }
        else
        {
            xReturn_core1 = errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY_core1;
        }

        return xReturn_core1;
    }
/*-----------------------------------------------------------*/

    void vCoRoutineAddToDelayedList_core1( TickType_t_core1 xTicksToDelay_core1,
                                     List_t_core1 * pxEventList_core1 )
    {
        TickType_t_core1 xTimeToWake_core1;

        /* Calculate the time to wake - this may overflow but this is
         * not a problem. */
        xTimeToWake_core1 = xCoRoutineTickCount_core1 + xTicksToDelay_core1;

        /* We must remove ourselves from the ready list before adding
         * ourselves to the blocked list as the same list item is used for
         * both lists. */
        ( void ) uxListRemove_core1( ( ListItem_t_core1 * ) &( pxCurrentCoRoutine_core1->xGenericListItem_core1 ) );

        /* The list item will be inserted in wake time order. */
        listSET_LIST_ITEM_VALUE_core1( &( pxCurrentCoRoutine_core1->xGenericListItem_core1 ), xTimeToWake_core1 );

        if( xTimeToWake_core1 < xCoRoutineTickCount_core1 )
        {
            /* Wake time has overflowed.  Place this item in the
             * overflow list. */
            vListInsert_core1( ( List_t_core1 * ) pxOverflowDelayedCoRoutineList_core1, ( ListItem_t_core1 * ) &( pxCurrentCoRoutine_core1->xGenericListItem_core1 ) );
        }
        else
        {
            /* The wake time has not overflowed, so we can use the
             * current block list. */
            vListInsert_core1( ( List_t_core1 * ) pxDelayedCoRoutineList_core1, ( ListItem_t_core1 * ) &( pxCurrentCoRoutine_core1->xGenericListItem_core1 ) );
        }

        if( pxEventList_core1 )
        {
            /* Also add the co-routine to an event list.  If this is done then the
             * function must be called with interrupts disabled. */
            vListInsert_core1( pxEventList_core1, &( pxCurrentCoRoutine_core1->xEventListItem_core1 ) );
        }
    }
/*-----------------------------------------------------------*/

    static void prvCheckPendingReadyList_core1( void )
    {
        /* Are there any co-routines waiting to get moved to the ready list?  These
         * are co-routines that have been readied by an ISR.  The ISR cannot access
         * the ready lists itself. */
        while( listLIST_IS_EMPTY_core1( &xPendingReadyCoRoutineList_core1 ) == pdFALSE_core1 )
        {
            CRCB_t_core1 * pxUnblockedCRCB_core1;

            /* The pending ready list can be accessed by an ISR. */
            portDISABLE_INTERRUPTS_core1();
            {
                pxUnblockedCRCB_core1 = ( CRCB_t_core1 * ) listGET_OWNER_OF_HEAD_ENTRY_core1( ( &xPendingReadyCoRoutineList_core1 ) );
                ( void ) uxListRemove_core1( &( pxUnblockedCRCB_core1->xEventListItem_core1 ) );
            }
            portENABLE_INTERRUPTS_core1();

            ( void ) uxListRemove_core1( &( pxUnblockedCRCB_core1->xGenericListItem_core1 ) );
            prvAddCoRoutineToReadyQueue_core1( pxUnblockedCRCB_core1 );
        }
    }
/*-----------------------------------------------------------*/

    static void prvCheckDelayedList_core1( void )
    {
        CRCB_t_core1 * pxCRCB_core1;

        xPassedTicks_core1 = xTaskGetTickCount_core1() - xLastTickCount_core1;

        while( xPassedTicks_core1 )
        {
            xCoRoutineTickCount_core1++;
            xPassedTicks_core1--;

            /* If the tick count has overflowed we need to swap the ready lists. */
            if( xCoRoutineTickCount_core1 == 0 )
            {
                List_t_core1 * pxTemp_core1;

                /* Tick count has overflowed so we need to swap the delay lists.  If there are
                 * any items in pxDelayedCoRoutineList_core1 here then there is an error! */
                pxTemp_core1 = pxDelayedCoRoutineList_core1;
                pxDelayedCoRoutineList_core1 = pxOverflowDelayedCoRoutineList_core1;
                pxOverflowDelayedCoRoutineList_core1 = pxTemp_core1;
            }

            /* See if this tick has made a timeout expire. */
            while( listLIST_IS_EMPTY_core1( pxDelayedCoRoutineList_core1 ) == pdFALSE_core1 )
            {
                pxCRCB_core1 = ( CRCB_t_core1 * ) listGET_OWNER_OF_HEAD_ENTRY_core1( pxDelayedCoRoutineList_core1 );

                if( xCoRoutineTickCount_core1 < listGET_LIST_ITEM_VALUE_core1( &( pxCRCB_core1->xGenericListItem_core1 ) ) )
                {
                    /* Timeout not yet expired. */
                    break;
                }

                portDISABLE_INTERRUPTS_core1();
                {
                    /* The event could have occurred just before this critical
                     *  section.  If this is the case then the generic list item will
                     *  have been moved to the pending ready list and the following
                     *  line is still valid.  Also the pvContainer parameter will have
                     *  been set to NULL so the following lines are also valid. */
                    ( void ) uxListRemove_core1( &( pxCRCB_core1->xGenericListItem_core1 ) );

                    /* Is the co-routine waiting on an event also? */
                    if( pxCRCB_core1->xEventListItem_core1.pxContainer_core1 )
                    {
                        ( void ) uxListRemove_core1( &( pxCRCB_core1->xEventListItem_core1 ) );
                    }
                }
                portENABLE_INTERRUPTS_core1();

                prvAddCoRoutineToReadyQueue_core1( pxCRCB_core1 );
            }
        }

        xLastTickCount_core1 = xCoRoutineTickCount_core1;
    }
/*-----------------------------------------------------------*/

    void vCoRoutineSchedule_core1( void )
    {
        /* Only run a co-routine after prvInitialiseCoRoutineLists_core1() has been
         * called.  prvInitialiseCoRoutineLists_core1() is called automatically when a
         * co-routine is created. */
        if( pxDelayedCoRoutineList_core1 != NULL )
        {
            /* See if any co-routines readied by events need moving to the ready lists. */
            prvCheckPendingReadyList_core1();

            /* See if any delayed co-routines have timed out. */
            prvCheckDelayedList_core1();

            /* Find the highest priority queue that contains ready co-routines. */
            while( listLIST_IS_EMPTY_core1( &( pxReadyCoRoutineLists_core1[ uxTopCoRoutineReadyPriority_core1 ] ) ) )
            {
                if( uxTopCoRoutineReadyPriority_core1 == 0 )
                {
                    /* No more co-routines to check. */
                    return;
                }

                --uxTopCoRoutineReadyPriority_core1;
            }

            /* listGET_OWNER_OF_NEXT_ENTRY_core1 walks through the list, so the co-routines
             * of the same priority get an equal share of the processor time. */
            listGET_OWNER_OF_NEXT_ENTRY_core1( pxCurrentCoRoutine_core1, &( pxReadyCoRoutineLists_core1[ uxTopCoRoutineReadyPriority_core1 ] ) );

            /* Call the co-routine. */
            ( pxCurrentCoRoutine_core1->pxCoRoutineFunction_core1 )( pxCurrentCoRoutine_core1, pxCurrentCoRoutine_core1->uxIndex_core1 );
        }
    }
/*-----------------------------------------------------------*/

    static void prvInitialiseCoRoutineLists_core1( void )
    {
        UBaseType_t_core1 uxPriority_core1;

        for( uxPriority_core1 = 0; uxPriority_core1 < configMAX_CO_ROUTINE_PRIORITIES_core1; uxPriority_core1++ )
        {
            vListInitialise_core1( ( List_t_core1 * ) &( pxReadyCoRoutineLists_core1[ uxPriority_core1 ] ) );
        }

        vListInitialise_core1( ( List_t_core1 * ) &xDelayedCoRoutineList1_core1 );
        vListInitialise_core1( ( List_t_core1 * ) &xDelayedCoRoutineList2_core1 );
        vListInitialise_core1( ( List_t_core1 * ) &xPendingReadyCoRoutineList_core1 );

        /* Start with pxDelayedCoRoutineList_core1 using list1 and the
         * pxOverflowDelayedCoRoutineList_core1 using list2. */
        pxDelayedCoRoutineList_core1 = &xDelayedCoRoutineList1_core1;
        pxOverflowDelayedCoRoutineList_core1 = &xDelayedCoRoutineList2_core1;
    }
/*-----------------------------------------------------------*/

    BaseType_t_core1 xCoRoutineRemoveFromEventList( const List_t_core1 * pxEventList_core1 )
    {
        CRCB_t_core1 * pxUnblockedCRCB_core1;
        BaseType_t_core1 xReturn_core1;

        /* This function is called from within an interrupt.  It can only access
         * event lists and the pending ready list.  This function assumes that a
         * check has already been made to ensure pxEventList_core1 is not empty. */
        pxUnblockedCRCB_core1 = ( CRCB_t_core1 * ) listGET_OWNER_OF_HEAD_ENTRY_core1( pxEventList_core1 );
        ( void ) uxListRemove_core1( &( pxUnblockedCRCB_core1->xEventListItem_core1 ) );
        vListInsertEnd_core1( ( List_t_core1 * ) &( xPendingReadyCoRoutineList_core1 ), &( pxUnblockedCRCB_core1->xEventListItem_core1 ) );

        if( pxUnblockedCRCB_core1->uxPriority_core1 >= pxCurrentCoRoutine_core1->uxPriority_core1 )
        {
            xReturn_core1 = pdTRUE_core1;
        }
        else
        {
            xReturn_core1 = pdFALSE_core1;
        }

        return xReturn_core1;
    }

#endif /* configUSE_CO_ROUTINES_core1 == 0 */
