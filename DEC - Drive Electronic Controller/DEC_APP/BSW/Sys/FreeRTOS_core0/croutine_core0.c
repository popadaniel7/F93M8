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

#include "FreeRTOS_core0.h"
#include "task_core0.h"
#include "croutine_core0.h"

/* Remove the whole file is co-routines are not being used. */
#if ( configUSE_CO_ROUTINES_core0 != 0 )

/*
 * Some kernel aware debuggers require data to be viewed to be global, rather
 * than file scope.
 */
    #ifdef portREMOVE_STATIC_QUALIFIER_core0
        #define static
    #endif


/* Lists for ready and blocked co-routines. --------------------*/
    static List_t_core0 pxReadyCoRoutineLists_core0[ configMAX_CO_ROUTINE_PRIORITIES_core0 ]; /*< Prioritised ready co-routines. */
    static List_t_core0 xDelayedCoRoutineList1_core0;                                   /*< Delayed co-routines. */
    static List_t_core0 xDelayedCoRoutineList2_core0;                                   /*< Delayed co-routines (two lists are used - one for delays that have overflowed the current tick count. */
    static List_t_core0 * pxDelayedCoRoutineList_core0 = NULL;                          /*< Points to the delayed co-routine list currently being used. */
    static List_t_core0 * pxOverflowDelayedCoRoutineList_core0 = NULL;                  /*< Points to the delayed co-routine list currently being used to hold co-routines that have overflowed the current tick count. */
    static List_t_core0 xPendingReadyCoRoutineList_core0;                               /*< Holds co-routines that have been readied by an external event.  They cannot be added directly to the ready lists as the ready lists cannot be accessed by interrupts. */

/* Other file private variables. --------------------------------*/
    CRCB_t_core0 * pxCurrentCoRoutine_core0 = NULL;
    static UBaseType_t_core0 uxTopCoRoutineReadyPriority_core0 = 0;
    static TickType_t_core0 xCoRoutineTickCount_core0 = 0, xLastTickCount_core0 = 0, xPassedTicks_core0 = 0;

/* The initial state of the co-routine when it is created. */
    #define corINITIAL_STATE_core0    ( 0 )

/*
 * Place the co-routine represented by pxCRCB_core0 into the appropriate ready queue
 * for the priority.  It is inserted at the end of the list.
 *
 * This macro accesses the co-routine ready lists and therefore must not be
 * used from within an ISR.
 */
    #define prvAddCoRoutineToReadyQueue_core0( pxCRCB_core0 )                                                                               \
    {                                                                                                                           \
        if( ( pxCRCB_core0 )->uxPriority_core0 > uxTopCoRoutineReadyPriority_core0 )                                                              \
        {                                                                                                                       \
            uxTopCoRoutineReadyPriority_core0 = ( pxCRCB_core0 )->uxPriority_core0;                                                               \
        }                                                                                                                       \
        vListInsertEnd_core0( ( List_t_core0 * ) &( pxReadyCoRoutineLists_core0[ ( pxCRCB_core0 )->uxPriority_core0 ] ), &( ( pxCRCB_core0 )->xGenericListItem_core0 ) ); \
    }

/*
 * Utility to ready all the lists used by the scheduler.  This is called
 * automatically upon the creation of the first co-routine.
 */
    static void prvInitialiseCoRoutineLists_core0( void );

/*
 * Co-routines that are readied by an interrupt cannot be placed directly into
 * the ready lists (there is no mutual exclusion).  Instead they are placed in
 * in the pending ready list in order that they can later be moved to the ready
 * list by the co-routine scheduler.
 */
    static void prvCheckPendingReadyList_core0( void );

/*
 * Macro that looks at the list of co-routines that are currently delayed to
 * see if any require waking.
 *
 * Co-routines are stored in the queue in the order of their wake time -
 * meaning once one co-routine has been found whose timer has not expired
 * we need not look any further down the list.
 */
    static void prvCheckDelayedList_core0( void );

/*-----------------------------------------------------------*/

    BaseType_t_core0 xCoRoutineCreate_core0( crCOROUTINE_CODE_core0 pxCoRoutineCode_core0,
                                 UBaseType_t_core0 uxPriority_core0,
                                 UBaseType_t_core0 uxIndex_core0 )
    {
        BaseType_t_core0 xReturn_core0;
        CRCB_t_core0 * pxCoRoutine_core0;

        /* Allocate the memory that will store the co-routine control block. */
        pxCoRoutine_core0 = ( CRCB_t_core0 * ) pvPortMalloc_core0( sizeof( CRCB_t_core0 ) );

        if( pxCoRoutine_core0 )
        {
            /* If pxCurrentCoRoutine_core0 is NULL then this is the first co-routine to
            * be created and the co-routine data structures need initialising. */
            if( pxCurrentCoRoutine_core0 == NULL )
            {
                pxCurrentCoRoutine_core0 = pxCoRoutine_core0;
                prvInitialiseCoRoutineLists_core0();
            }

            /* Check the priority is within limits. */
            if( uxPriority_core0 >= configMAX_CO_ROUTINE_PRIORITIES_core0 )
            {
                uxPriority_core0 = configMAX_CO_ROUTINE_PRIORITIES_core0 - 1;
            }

            /* Fill out the co-routine control block from the function parameters. */
            pxCoRoutine_core0->uxState_core0 = corINITIAL_STATE_core0;
            pxCoRoutine_core0->uxPriority_core0 = uxPriority_core0;
            pxCoRoutine_core0->uxIndex_core0 = uxIndex_core0;
            pxCoRoutine_core0->pxCoRoutineFunction_core0 = pxCoRoutineCode_core0;

            /* Initialise all the other co-routine control block parameters. */
            vListInitialiseItem_core0( &( pxCoRoutine_core0->xGenericListItem_core0 ) );
            vListInitialiseItem_core0( &( pxCoRoutine_core0->xEventListItem_core0 ) );

            /* Set the co-routine control block as a link back from the ListItem_t_core0.
             * This is so we can get back to the containing CRCB from a generic item
             * in a list. */
            listSET_LIST_ITEM_OWNER_core0( &( pxCoRoutine_core0->xGenericListItem_core0 ), pxCoRoutine_core0 );
            listSET_LIST_ITEM_OWNER_core0( &( pxCoRoutine_core0->xEventListItem_core0 ), pxCoRoutine_core0 );

            /* Event lists are always in priority order. */
            listSET_LIST_ITEM_VALUE_core0( &( pxCoRoutine_core0->xEventListItem_core0 ), ( ( TickType_t_core0 ) configMAX_CO_ROUTINE_PRIORITIES_core0 - ( TickType_t_core0 ) uxPriority_core0 ) );

            /* Now the co-routine has been initialised it can be added to the ready
             * list at the correct priority. */
            prvAddCoRoutineToReadyQueue_core0( pxCoRoutine_core0 );

            xReturn_core0 = pdPASS_core0;
        }
        else
        {
            xReturn_core0 = errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY_core0;
        }

        return xReturn_core0;
    }
/*-----------------------------------------------------------*/

    void vCoRoutineAddToDelayedList_core0( TickType_t_core0 xTicksToDelay_core0,
                                     List_t_core0 * pxEventList_core0 )
    {
        TickType_t_core0 xTimeToWake_core0;

        /* Calculate the time to wake - this may overflow but this is
         * not a problem. */
        xTimeToWake_core0 = xCoRoutineTickCount_core0 + xTicksToDelay_core0;

        /* We must remove ourselves from the ready list before adding
         * ourselves to the blocked list as the same list item is used for
         * both lists. */
        ( void ) uxListRemove_core0( ( ListItem_t_core0 * ) &( pxCurrentCoRoutine_core0->xGenericListItem_core0 ) );

        /* The list item will be inserted in wake time order. */
        listSET_LIST_ITEM_VALUE_core0( &( pxCurrentCoRoutine_core0->xGenericListItem_core0 ), xTimeToWake_core0 );

        if( xTimeToWake_core0 < xCoRoutineTickCount_core0 )
        {
            /* Wake time has overflowed.  Place this item in the
             * overflow list. */
            vListInsert_core0( ( List_t_core0 * ) pxOverflowDelayedCoRoutineList_core0, ( ListItem_t_core0 * ) &( pxCurrentCoRoutine_core0->xGenericListItem_core0 ) );
        }
        else
        {
            /* The wake time has not overflowed, so we can use the
             * current block list. */
            vListInsert_core0( ( List_t_core0 * ) pxDelayedCoRoutineList_core0, ( ListItem_t_core0 * ) &( pxCurrentCoRoutine_core0->xGenericListItem_core0 ) );
        }

        if( pxEventList_core0 )
        {
            /* Also add the co-routine to an event list.  If this is done then the
             * function must be called with interrupts disabled. */
            vListInsert_core0( pxEventList_core0, &( pxCurrentCoRoutine_core0->xEventListItem_core0 ) );
        }
    }
/*-----------------------------------------------------------*/

    static void prvCheckPendingReadyList_core0( void )
    {
        /* Are there any co-routines waiting to get moved to the ready list?  These
         * are co-routines that have been readied by an ISR.  The ISR cannot access
         * the ready lists itself. */
        while( listLIST_IS_EMPTY_core0( &xPendingReadyCoRoutineList_core0 ) == pdFALSE_core0 )
        {
            CRCB_t_core0 * pxUnblockedCRCB_core0;

            /* The pending ready list can be accessed by an ISR. */
            portDISABLE_INTERRUPTS_core0();
            {
                pxUnblockedCRCB_core0 = ( CRCB_t_core0 * ) listGET_OWNER_OF_HEAD_ENTRY_core0( ( &xPendingReadyCoRoutineList_core0 ) );
                ( void ) uxListRemove_core0( &( pxUnblockedCRCB_core0->xEventListItem_core0 ) );
            }
            portENABLE_INTERRUPTS_core0();

            ( void ) uxListRemove_core0( &( pxUnblockedCRCB_core0->xGenericListItem_core0 ) );
            prvAddCoRoutineToReadyQueue_core0( pxUnblockedCRCB_core0 );
        }
    }
/*-----------------------------------------------------------*/

    static void prvCheckDelayedList_core0( void )
    {
        CRCB_t_core0 * pxCRCB_core0;

        xPassedTicks_core0 = xTaskGetTickCount_core0() - xLastTickCount_core0;

        while( xPassedTicks_core0 )
        {
            xCoRoutineTickCount_core0++;
            xPassedTicks_core0--;

            /* If the tick count has overflowed we need to swap the ready lists. */
            if( xCoRoutineTickCount_core0 == 0 )
            {
                List_t_core0 * pxTemp_core0;

                /* Tick count has overflowed so we need to swap the delay lists.  If there are
                 * any items in pxDelayedCoRoutineList_core0 here then there is an error! */
                pxTemp_core0 = pxDelayedCoRoutineList_core0;
                pxDelayedCoRoutineList_core0 = pxOverflowDelayedCoRoutineList_core0;
                pxOverflowDelayedCoRoutineList_core0 = pxTemp_core0;
            }

            /* See if this tick has made a timeout expire. */
            while( listLIST_IS_EMPTY_core0( pxDelayedCoRoutineList_core0 ) == pdFALSE_core0 )
            {
                pxCRCB_core0 = ( CRCB_t_core0 * ) listGET_OWNER_OF_HEAD_ENTRY_core0( pxDelayedCoRoutineList_core0 );

                if( xCoRoutineTickCount_core0 < listGET_LIST_ITEM_VALUE_core0( &( pxCRCB_core0->xGenericListItem_core0 ) ) )
                {
                    /* Timeout not yet expired. */
                    break;
                }

                portDISABLE_INTERRUPTS_core0();
                {
                    /* The event could have occurred just before this critical
                     *  section.  If this is the case then the generic list item will
                     *  have been moved to the pending ready list and the following
                     *  line is still valid.  Also the pvContainer parameter will have
                     *  been set to NULL so the following lines are also valid. */
                    ( void ) uxListRemove_core0( &( pxCRCB_core0->xGenericListItem_core0 ) );

                    /* Is the co-routine waiting on an event also? */
                    if( pxCRCB_core0->xEventListItem_core0.pxContainer_core0 )
                    {
                        ( void ) uxListRemove_core0( &( pxCRCB_core0->xEventListItem_core0 ) );
                    }
                }
                portENABLE_INTERRUPTS_core0();

                prvAddCoRoutineToReadyQueue_core0( pxCRCB_core0 );
            }
        }

        xLastTickCount_core0 = xCoRoutineTickCount_core0;
    }
/*-----------------------------------------------------------*/

    void vCoRoutineSchedule_core0( void )
    {
        /* Only run a co-routine after prvInitialiseCoRoutineLists_core0() has been
         * called.  prvInitialiseCoRoutineLists_core0() is called automatically when a
         * co-routine is created. */
        if( pxDelayedCoRoutineList_core0 != NULL )
        {
            /* See if any co-routines readied by events need moving to the ready lists. */
            prvCheckPendingReadyList_core0();

            /* See if any delayed co-routines have timed out. */
            prvCheckDelayedList_core0();

            /* Find the highest priority queue that contains ready co-routines. */
            while( listLIST_IS_EMPTY_core0( &( pxReadyCoRoutineLists_core0[ uxTopCoRoutineReadyPriority_core0 ] ) ) )
            {
                if( uxTopCoRoutineReadyPriority_core0 == 0 )
                {
                    /* No more co-routines to check. */
                    return;
                }

                --uxTopCoRoutineReadyPriority_core0;
            }

            /* listGET_OWNER_OF_NEXT_ENTRY_core0 walks through the list, so the co-routines
             * of the same priority get an equal share of the processor time. */
            listGET_OWNER_OF_NEXT_ENTRY_core0( pxCurrentCoRoutine_core0, &( pxReadyCoRoutineLists_core0[ uxTopCoRoutineReadyPriority_core0 ] ) );

            /* Call the co-routine. */
            ( pxCurrentCoRoutine_core0->pxCoRoutineFunction_core0 )( pxCurrentCoRoutine_core0, pxCurrentCoRoutine_core0->uxIndex_core0 );
        }
    }
/*-----------------------------------------------------------*/

    static void prvInitialiseCoRoutineLists_core0( void )
    {
        UBaseType_t_core0 uxPriority_core0;

        for( uxPriority_core0 = 0; uxPriority_core0 < configMAX_CO_ROUTINE_PRIORITIES_core0; uxPriority_core0++ )
        {
            vListInitialise_core0( ( List_t_core0 * ) &( pxReadyCoRoutineLists_core0[ uxPriority_core0 ] ) );
        }

        vListInitialise_core0( ( List_t_core0 * ) &xDelayedCoRoutineList1_core0 );
        vListInitialise_core0( ( List_t_core0 * ) &xDelayedCoRoutineList2_core0 );
        vListInitialise_core0( ( List_t_core0 * ) &xPendingReadyCoRoutineList_core0 );

        /* Start with pxDelayedCoRoutineList_core0 using list1 and the
         * pxOverflowDelayedCoRoutineList_core0 using list2. */
        pxDelayedCoRoutineList_core0 = &xDelayedCoRoutineList1_core0;
        pxOverflowDelayedCoRoutineList_core0 = &xDelayedCoRoutineList2_core0;
    }
/*-----------------------------------------------------------*/

    BaseType_t_core0 xCoRoutineRemoveFromEventList( const List_t_core0 * pxEventList_core0 )
    {
        CRCB_t_core0 * pxUnblockedCRCB_core0;
        BaseType_t_core0 xReturn_core0;

        /* This function is called from within an interrupt.  It can only access
         * event lists and the pending ready list.  This function assumes that a
         * check has already been made to ensure pxEventList_core0 is not empty. */
        pxUnblockedCRCB_core0 = ( CRCB_t_core0 * ) listGET_OWNER_OF_HEAD_ENTRY_core0( pxEventList_core0 );
        ( void ) uxListRemove_core0( &( pxUnblockedCRCB_core0->xEventListItem_core0 ) );
        vListInsertEnd_core0( ( List_t_core0 * ) &( xPendingReadyCoRoutineList_core0 ), &( pxUnblockedCRCB_core0->xEventListItem_core0 ) );

        if( pxUnblockedCRCB_core0->uxPriority_core0 >= pxCurrentCoRoutine_core0->uxPriority_core0 )
        {
            xReturn_core0 = pdTRUE_core0;
        }
        else
        {
            xReturn_core0 = pdFALSE_core0;
        }

        return xReturn_core0;
    }

#endif /* configUSE_CO_ROUTINES_core0 == 0 */
