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

/* Standard includes. */
#include <stdlib.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 prevents task_core2.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core2.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2

/* FreeRTOS_core2 includes. */
#include "FreeRTOS_core2.h"
#include "task_core2.h"
#include "timers_core2.h"
#include "event_groups_core2.h"

/* Lint e961, e750 and e9021 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 to be defined
 * for the header files above, but not in this file, in order to generate the
 * correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 /*lint !e961 !e750 !e9021 See comment above. */

/* The following bit fields convey control information in a task_core2's event list
 * item value.  It is important they don't clash with the
 * taskEVENT_LIST_ITEM_VALUE_IN_USE_core2 definition. */
#if configUSE_16_BIT_TICKS_core2 == 1
    #define eventCLEAR_EVENTS_ON_EXIT_BIT_core2    0x0100U
    #define eventUNBLOCKED_DUE_TO_BIT_SET_core2    0x0200U
    #define eventWAIT_FOR_ALL_BITS_core2           0x0400U
    #define eventEVENT_BITS_CONTROL_BYTES_core2    0xff00U
#else
    #define eventCLEAR_EVENTS_ON_EXIT_BIT_core2    0x01000000UL
    #define eventUNBLOCKED_DUE_TO_BIT_SET_core2    0x02000000UL
    #define eventWAIT_FOR_ALL_BITS_core2           0x04000000UL
    #define eventEVENT_BITS_CONTROL_BYTES_core2    0xff000000UL
#endif

typedef struct EventGroupDef_t_core2
{
    EventBits_t_core2 uxEventBits_core2;
    List_t_core2 xTasksWaitingForBits_core2; /*< List of tasks waiting for a bit to be set. */

    #if ( configUSE_TRACE_FACILITY_core2 == 1 )
        UBaseType_t_core2 uxEventGroupNumber_core2;
    #endif

    #if ( ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 ) )
        uint8_t ucStaticallyAllocated_core2; /*< Set to pdTRUE_core2 if the event group is statically allocated to ensure no attempt is made to free the memory. */
    #endif
} EventGroup_t_core2;

/*-----------------------------------------------------------*/

/*
 * Test the bits set in uxCurrentEventBits to see if the wait condition is met.
 * The wait condition is defined by xWaitForAllBits_core2.  If xWaitForAllBits_core2 is
 * pdTRUE_core2 then the wait condition is met if all the bits set in uxBitsToWaitFor_core2
 * are also set in uxCurrentEventBits.  If xWaitForAllBits_core2 is pdFALSE_core2 then the
 * wait condition is met if any of the bits set in uxBitsToWait for are also set
 * in uxCurrentEventBits.
 */
static BaseType_t_core2 prvTestWaitCondition_core2( const EventBits_t_core2 uxCurrentEventBits,
                                        const EventBits_t_core2 uxBitsToWaitFor_core2,
                                        const BaseType_t_core2 xWaitForAllBits_core2 ) PRIVILEGED_FUNCTION_core2;

/*-----------------------------------------------------------*/

#if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )

    EventGroupHandle_t_core2 xEventGroupCreateStatic_core2( StaticEventGroup_t_core2 * pxEventGroupBuffer_core2 )
    {
        EventGroup_t_core2 * pxEventBits_core2;

        /* A StaticEventGroup_t_core2 object must be provided. */
        configASSERT_core2( pxEventGroupBuffer_core2 );

        #if ( configASSERT_DEFINED_core2 == 1 )
        {
            /* Sanity check that the size of the structure used to declare a
             * variable of type StaticEventGroup_t_core2 equals the size of the real
             * event group structure. */
            volatile size_t xSize_core2 = sizeof( StaticEventGroup_t_core2 );
            configASSERT_core2( xSize_core2 == sizeof( EventGroup_t_core2 ) );
        } /*lint !e529 xSize_core2 is referenced if configASSERT_core2() is defined. */
        #endif /* configASSERT_DEFINED_core2 */

        /* The user has provided a statically allocated event group - use it. */
        pxEventBits_core2 = ( EventGroup_t_core2 * ) pxEventGroupBuffer_core2; /*lint !e740 !e9087 EventGroup_t_core2 and StaticEventGroup_t_core2 are deliberately aliased for data hiding purposes and guaranteed to have the same size and alignment requirement - checked by configASSERT_core2(). */

        if( pxEventBits_core2 != NULL )
        {
            pxEventBits_core2->uxEventBits_core2 = 0;
            vListInitialise_core2( &( pxEventBits_core2->xTasksWaitingForBits_core2 ) );

            #if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 )
            {
                /* Both static and dynamic allocation can be used, so note that
                 * this event group was created statically in case the event group
                 * is later deleted. */
                pxEventBits_core2->ucStaticallyAllocated_core2 = pdTRUE_core2;
            }
            #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core2 */

            traceEVENT_GROUP_CREATE_core2( pxEventBits_core2 );
        }
        else
        {
            /* xEventGroupCreateStatic_core2 should only ever be called with
             * pxEventGroupBuffer_core2 pointing to a pre-allocated (compile time
             * allocated) StaticEventGroup_t_core2 variable. */
            traceEVENT_GROUP_CREATE_FAILED_core2();
        }

        return pxEventBits_core2;
    }

#endif /* configSUPPORT_STATIC_ALLOCATION_core2 */
/*-----------------------------------------------------------*/

#if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 )

    EventGroupHandle_t_core2 xEventGroupCreate_core2( void )
    {
        EventGroup_t_core2 * pxEventBits_core2;

        /* Allocate the event group.  Justification for MISRA deviation as
         * follows:  pvPortMalloc_core2() always ensures returned memory blocks are
         * aligned per the requirements of the MCU stack.  In this case
         * pvPortMalloc_core2() must return a pointer that is guaranteed to meet the
         * alignment requirements of the EventGroup_t_core2 structure - which (if you
         * follow it through) is the alignment requirements of the TickType_t_core2 type
         * (EventBits_t_core2 being of TickType_t_core2 itself).  Therefore, whenever the
         * stack alignment requirements are greater than or equal to the
         * TickType_t_core2 alignment requirements the cast is safe.  In other cases,
         * where the natural word size of the architecture is less than
         * sizeof( TickType_t_core2 ), the TickType_t_core2 variables will be accessed in two
         * or more reads operations, and the alignment requirements is only that
         * of each individual read. */
        pxEventBits_core2 = ( EventGroup_t_core2 * ) pvPortMalloc_core2( sizeof( EventGroup_t_core2 ) ); /*lint !e9087 !e9079 see comment above. */

        if( pxEventBits_core2 != NULL )
        {
            pxEventBits_core2->uxEventBits_core2 = 0;
            vListInitialise_core2( &( pxEventBits_core2->xTasksWaitingForBits_core2 ) );

            #if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )
            {
                /* Both static and dynamic allocation can be used, so note this
                 * event group was allocated statically in case the event group is
                 * later deleted. */
                pxEventBits_core2->ucStaticallyAllocated_core2 = pdFALSE_core2;
            }
            #endif /* configSUPPORT_STATIC_ALLOCATION_core2 */

            traceEVENT_GROUP_CREATE_core2( pxEventBits_core2 );
        }
        else
        {
            traceEVENT_GROUP_CREATE_FAILED_core2(); /*lint !e9063 Else branch only exists to allow tracing and does not generate code if trace macros are not defined. */
        }

        return pxEventBits_core2;
    }

#endif /* configSUPPORT_DYNAMIC_ALLOCATION_core2 */
/*-----------------------------------------------------------*/

EventBits_t_core2 xEventGroupSync_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                             const EventBits_t_core2 uxBitsToSet_core2,
                             const EventBits_t_core2 uxBitsToWaitFor_core2,
                             TickType_t_core2 xTicksToWait_core2 )
{
    EventBits_t_core2 uxOriginalBitValue_core2, uxReturn_core2;
    EventGroup_t_core2 * pxEventBits_core2 = xEventGroup_core2;
    BaseType_t_core2 xAlreadyYielded_core2;
    BaseType_t_core2 xTimeoutOccurred_core2 = pdFALSE_core2;

    configASSERT_core2( ( uxBitsToWaitFor_core2 & eventEVENT_BITS_CONTROL_BYTES_core2 ) == 0 );
    configASSERT_core2( uxBitsToWaitFor_core2 != 0 );
    #if ( ( INCLUDE_xTaskGetSchedulerState_core2 == 1 ) || ( configUSE_TIMERS_core2 == 1 ) )
    {
        configASSERT_core2( !( ( xTaskGetSchedulerState_core2() == taskSCHEDULER_SUSPENDED_core2 ) && ( xTicksToWait_core2 != 0 ) ) );
    }
    #endif

    vTaskSuspendAll_core2();
    {
        uxOriginalBitValue_core2 = pxEventBits_core2->uxEventBits_core2;

        ( void ) xEventGroupSetBits_core2( xEventGroup_core2, uxBitsToSet_core2 );

        if( ( ( uxOriginalBitValue_core2 | uxBitsToSet_core2 ) & uxBitsToWaitFor_core2 ) == uxBitsToWaitFor_core2 )
        {
            /* All the rendezvous bits are now set - no need to block. */
            uxReturn_core2 = ( uxOriginalBitValue_core2 | uxBitsToSet_core2 );

            /* Rendezvous always clear the bits.  They will have been cleared
             * already unless this is the only task_core2 in the rendezvous. */
            pxEventBits_core2->uxEventBits_core2 &= ~uxBitsToWaitFor_core2;

            xTicksToWait_core2 = 0;
        }
        else
        {
            if( xTicksToWait_core2 != ( TickType_t_core2 ) 0 )
            {
                traceEVENT_GROUP_SYNC_BLOCK_core2( xEventGroup_core2, uxBitsToSet_core2, uxBitsToWaitFor_core2 );

                /* Store the bits that the calling task_core2 is waiting for in the
                 * task_core2's event list item so the kernel knows when a match is
                 * found.  Then enter the blocked state. */
                vTaskPlaceOnUnorderedEventList_core2( &( pxEventBits_core2->xTasksWaitingForBits_core2 ), ( uxBitsToWaitFor_core2 | eventCLEAR_EVENTS_ON_EXIT_BIT_core2 | eventWAIT_FOR_ALL_BITS_core2 ), xTicksToWait_core2 );

                /* This assignment is obsolete as uxReturn_core2 will get set after
                 * the task_core2 unblocks, but some compilers mistakenly generate a
                 * warning about uxReturn_core2 being returned without being set if the
                 * assignment is omitted. */
                uxReturn_core2 = 0;
            }
            else
            {
                /* The rendezvous bits were not set, but no block time was
                 * specified - just return the current event bit value. */
                uxReturn_core2 = pxEventBits_core2->uxEventBits_core2;
                xTimeoutOccurred_core2 = pdTRUE_core2;
            }
        }
    }
    xAlreadyYielded_core2 = xTaskResumeAll_core2();

    if( xTicksToWait_core2 != ( TickType_t_core2 ) 0 )
    {
        if( xAlreadyYielded_core2 == pdFALSE_core2 )
        {
            portYIELD_WITHIN_API_core2();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }

        /* The task_core2 blocked to wait for its required bits to be set - at this
         * point either the required bits were set or the block time expired.  If
         * the required bits were set they will have been stored in the task_core2's
         * event list item, and they should now be retrieved then cleared. */
        uxReturn_core2 = uxTaskResetEventItemValue_core2();

        if( ( uxReturn_core2 & eventUNBLOCKED_DUE_TO_BIT_SET_core2 ) == ( EventBits_t_core2 ) 0 )
        {
            /* The task_core2 timed out, just return the current event bit value. */
            taskENTER_CRITICAL_core2();
            {
                uxReturn_core2 = pxEventBits_core2->uxEventBits_core2;

                /* Although the task_core2 got here because it timed out before the
                 * bits it was waiting for were set, it is possible that since it
                 * unblocked another task_core2 has set the bits.  If this is the case
                 * then it needs to clear the bits before exiting. */
                if( ( uxReturn_core2 & uxBitsToWaitFor_core2 ) == uxBitsToWaitFor_core2 )
                {
                    pxEventBits_core2->uxEventBits_core2 &= ~uxBitsToWaitFor_core2;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core2();
                }
            }
            taskEXIT_CRITICAL_core2();

            xTimeoutOccurred_core2 = pdTRUE_core2;
        }
        else
        {
            /* The task_core2 unblocked because the bits were set. */
        }

        /* Control bits might be set as the task_core2 had blocked should not be
         * returned. */
        uxReturn_core2 &= ~eventEVENT_BITS_CONTROL_BYTES_core2;
    }

    traceEVENT_GROUP_SYNC_END_core2( xEventGroup_core2, uxBitsToSet_core2, uxBitsToWaitFor_core2, xTimeoutOccurred_core2 );

    /* Prevent compiler warnings when trace macros are not used. */
    ( void ) xTimeoutOccurred_core2;

    return uxReturn_core2;
}
/*-----------------------------------------------------------*/

EventBits_t_core2 xEventGroupWaitBits_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                 const EventBits_t_core2 uxBitsToWaitFor_core2,
                                 const BaseType_t_core2 xClearOnExit_core2,
                                 const BaseType_t_core2 xWaitForAllBits_core2,
                                 TickType_t_core2 xTicksToWait_core2 )
{
    EventGroup_t_core2 * pxEventBits_core2 = xEventGroup_core2;
    EventBits_t_core2 uxReturn_core2, uxControlBits_core2 = 0;
    BaseType_t_core2 xWaitConditionMet_core2, xAlreadyYielded_core2;
    BaseType_t_core2 xTimeoutOccurred_core2 = pdFALSE_core2;

    /* Check the user is not attempting to wait on the bits used by the kernel
     * itself, and that at least one bit is being requested. */
    configASSERT_core2( xEventGroup_core2 );
    configASSERT_core2( ( uxBitsToWaitFor_core2 & eventEVENT_BITS_CONTROL_BYTES_core2 ) == 0 );
    configASSERT_core2( uxBitsToWaitFor_core2 != 0 );
    #if ( ( INCLUDE_xTaskGetSchedulerState_core2 == 1 ) || ( configUSE_TIMERS_core2 == 1 ) )
    {
        configASSERT_core2( !( ( xTaskGetSchedulerState_core2() == taskSCHEDULER_SUSPENDED_core2 ) && ( xTicksToWait_core2 != 0 ) ) );
    }
    #endif

    vTaskSuspendAll_core2();
    {
        const EventBits_t_core2 uxCurrentEventBits = pxEventBits_core2->uxEventBits_core2;

        /* Check to see if the wait condition is already met or not. */
        xWaitConditionMet_core2 = prvTestWaitCondition_core2( uxCurrentEventBits, uxBitsToWaitFor_core2, xWaitForAllBits_core2 );

        if( xWaitConditionMet_core2 != pdFALSE_core2 )
        {
            /* The wait condition has already been met so there is no need to
             * block. */
            uxReturn_core2 = uxCurrentEventBits;
            xTicksToWait_core2 = ( TickType_t_core2 ) 0;

            /* Clear the wait bits if requested to do so. */
            if( xClearOnExit_core2 != pdFALSE_core2 )
            {
                pxEventBits_core2->uxEventBits_core2 &= ~uxBitsToWaitFor_core2;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core2();
            }
        }
        else if( xTicksToWait_core2 == ( TickType_t_core2 ) 0 )
        {
            /* The wait condition has not been met, but no block time was
             * specified, so just return the current value. */
            uxReturn_core2 = uxCurrentEventBits;
            xTimeoutOccurred_core2 = pdTRUE_core2;
        }
        else
        {
            /* The task_core2 is going to block to wait for its required bits to be
             * set.  uxControlBits_core2 are used to remember the specified behaviour of
             * this call to xEventGroupWaitBits_core2() - for use when the event bits
             * unblock the task_core2. */
            if( xClearOnExit_core2 != pdFALSE_core2 )
            {
                uxControlBits_core2 |= eventCLEAR_EVENTS_ON_EXIT_BIT_core2;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core2();
            }

            if( xWaitForAllBits_core2 != pdFALSE_core2 )
            {
                uxControlBits_core2 |= eventWAIT_FOR_ALL_BITS_core2;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core2();
            }

            /* Store the bits that the calling task_core2 is waiting for in the
             * task_core2's event list item so the kernel knows when a match is
             * found.  Then enter the blocked state. */
            vTaskPlaceOnUnorderedEventList_core2( &( pxEventBits_core2->xTasksWaitingForBits_core2 ), ( uxBitsToWaitFor_core2 | uxControlBits_core2 ), xTicksToWait_core2 );

            /* This is obsolete as it will get set after the task_core2 unblocks, but
             * some compilers mistakenly generate a warning about the variable
             * being returned without being set if it is not done. */
            uxReturn_core2 = 0;

            traceEVENT_GROUP_WAIT_BITS_BLOCK_core2( xEventGroup_core2, uxBitsToWaitFor_core2 );
        }
    }
    xAlreadyYielded_core2 = xTaskResumeAll_core2();

    if( xTicksToWait_core2 != ( TickType_t_core2 ) 0 )
    {
        if( xAlreadyYielded_core2 == pdFALSE_core2 )
        {
            portYIELD_WITHIN_API_core2();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }

        /* The task_core2 blocked to wait for its required bits to be set - at this
         * point either the required bits were set or the block time expired.  If
         * the required bits were set they will have been stored in the task_core2's
         * event list item, and they should now be retrieved then cleared. */
        uxReturn_core2 = uxTaskResetEventItemValue_core2();

        if( ( uxReturn_core2 & eventUNBLOCKED_DUE_TO_BIT_SET_core2 ) == ( EventBits_t_core2 ) 0 )
        {
            taskENTER_CRITICAL_core2();
            {
                /* The task_core2 timed out, just return the current event bit value. */
                uxReturn_core2 = pxEventBits_core2->uxEventBits_core2;

                /* It is possible that the event bits were updated between this
                 * task_core2 leaving the Blocked state and running again. */
                if( prvTestWaitCondition_core2( uxReturn_core2, uxBitsToWaitFor_core2, xWaitForAllBits_core2 ) != pdFALSE_core2 )
                {
                    if( xClearOnExit_core2 != pdFALSE_core2 )
                    {
                        pxEventBits_core2->uxEventBits_core2 &= ~uxBitsToWaitFor_core2;
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

                xTimeoutOccurred_core2 = pdTRUE_core2;
            }
            taskEXIT_CRITICAL_core2();
        }
        else
        {
            /* The task_core2 unblocked because the bits were set. */
        }

        /* The task_core2 blocked so control bits may have been set. */
        uxReturn_core2 &= ~eventEVENT_BITS_CONTROL_BYTES_core2;
    }

    traceEVENT_GROUP_WAIT_BITS_END_core2( xEventGroup_core2, uxBitsToWaitFor_core2, xTimeoutOccurred_core2 );

    /* Prevent compiler warnings when trace macros are not used. */
    ( void ) xTimeoutOccurred_core2;

    return uxReturn_core2;
}
/*-----------------------------------------------------------*/

EventBits_t_core2 xEventGroupClearBits_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                  const EventBits_t_core2 uxBitsToClear_core2 )
{
    EventGroup_t_core2 * pxEventBits_core2 = xEventGroup_core2;
    EventBits_t_core2 uxReturn_core2;

    /* Check the user is not attempting to clear the bits used by the kernel
     * itself. */
    configASSERT_core2( xEventGroup_core2 );
    configASSERT_core2( ( uxBitsToClear_core2 & eventEVENT_BITS_CONTROL_BYTES_core2 ) == 0 );

    taskENTER_CRITICAL_core2();
    {
        traceEVENT_GROUP_CLEAR_BITS_core2( xEventGroup_core2, uxBitsToClear_core2 );

        /* The value returned is the event group value prior to the bits being
         * cleared. */
        uxReturn_core2 = pxEventBits_core2->uxEventBits_core2;

        /* Clear the bits. */
        pxEventBits_core2->uxEventBits_core2 &= ~uxBitsToClear_core2;
    }
    taskEXIT_CRITICAL_core2();

    return uxReturn_core2;
}
/*-----------------------------------------------------------*/

#if ( ( configUSE_TRACE_FACILITY_core2 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core2 == 1 ) && ( configUSE_TIMERS_core2 == 1 ) )

    BaseType_t_core2 xEventGroupClearBitsFromISR_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                            const EventBits_t_core2 uxBitsToClear_core2 )
    {
        BaseType_t_core2 xReturn_core2;

        traceEVENT_GROUP_CLEAR_BITS_FROM_ISR_core2( xEventGroup_core2, uxBitsToClear_core2 );
        xReturn_core2 = xTimerPendFunctionCallFromISR_core2( vEventGroupClearBitsCallback_core2, ( void * ) xEventGroup_core2, ( uint32_t ) uxBitsToClear_core2, NULL ); /*lint !e9087 Can't avoid cast to void* as a generic callback function not specific to this use case. Callback casts back to original type so safe. */

        return xReturn_core2;
    }

#endif /* if ( ( configUSE_TRACE_FACILITY_core2 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core2 == 1 ) && ( configUSE_TIMERS_core2 == 1 ) ) */
/*-----------------------------------------------------------*/

EventBits_t_core2 xEventGroupGetBitsFromISR_core2( EventGroupHandle_t_core2 xEventGroup_core2 )
{
    UBaseType_t_core2 uxSavedInterruptStatus_core2;
    EventGroup_t_core2 const * const pxEventBits_core2 = xEventGroup_core2;
    EventBits_t_core2 uxReturn_core2;

    uxSavedInterruptStatus_core2 = portSET_INTERRUPT_MASK_FROM_ISR_core2();
    {
        uxReturn_core2 = pxEventBits_core2->uxEventBits_core2;
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core2( uxSavedInterruptStatus_core2 );

    return uxReturn_core2;
} /*lint !e818 EventGroupHandle_t_core2 is a typedef used in other functions to so can't be pointer to const. */
/*-----------------------------------------------------------*/

EventBits_t_core2 xEventGroupSetBits_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                const EventBits_t_core2 uxBitsToSet_core2 )
{
    ListItem_t_core2 * pxListItem_core2;
    ListItem_t_core2 * pxNext_core2;
    ListItem_t_core2 const * pxListEnd_core2;
    List_t_core2 const * pxList_core2;
    EventBits_t_core2 uxBitsToClear_core2 = 0, uxBitsWaitedFor_core2, uxControlBits_core2;
    EventGroup_t_core2 * pxEventBits_core2 = xEventGroup_core2;
    BaseType_t_core2 xMatchFound = pdFALSE_core2;

    /* Check the user is not attempting to set the bits used by the kernel
     * itself. */
    configASSERT_core2( xEventGroup_core2 );
    configASSERT_core2( ( uxBitsToSet_core2 & eventEVENT_BITS_CONTROL_BYTES_core2 ) == 0 );

    pxList_core2 = &( pxEventBits_core2->xTasksWaitingForBits_core2 );
    pxListEnd_core2 = listGET_END_MARKER_core2( pxList_core2 ); /*lint !e826 !e740 !e9087 The mini list structure is used as the list end to save RAM.  This is checked and valid. */
    vTaskSuspendAll_core2();
    {
        traceEVENT_GROUP_SET_BITS_core2( xEventGroup_core2, uxBitsToSet_core2 );

        pxListItem_core2 = listGET_HEAD_ENTRY_core2( pxList_core2 );

        /* Set the bits. */
        pxEventBits_core2->uxEventBits_core2 |= uxBitsToSet_core2;

        /* See if the new bit value should unblock any tasks. */
        while( pxListItem_core2 != pxListEnd_core2 )
        {
            pxNext_core2 = listGET_NEXT_core2( pxListItem_core2 );
            uxBitsWaitedFor_core2 = listGET_LIST_ITEM_VALUE_core2( pxListItem_core2 );
            xMatchFound = pdFALSE_core2;

            /* Split the bits waited for from the control bits. */
            uxControlBits_core2 = uxBitsWaitedFor_core2 & eventEVENT_BITS_CONTROL_BYTES_core2;
            uxBitsWaitedFor_core2 &= ~eventEVENT_BITS_CONTROL_BYTES_core2;

            if( ( uxControlBits_core2 & eventWAIT_FOR_ALL_BITS_core2 ) == ( EventBits_t_core2 ) 0 )
            {
                /* Just looking for single bit being set. */
                if( ( uxBitsWaitedFor_core2 & pxEventBits_core2->uxEventBits_core2 ) != ( EventBits_t_core2 ) 0 )
                {
                    xMatchFound = pdTRUE_core2;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core2();
                }
            }
            else if( ( uxBitsWaitedFor_core2 & pxEventBits_core2->uxEventBits_core2 ) == uxBitsWaitedFor_core2 )
            {
                /* All bits are set. */
                xMatchFound = pdTRUE_core2;
            }
            else
            {
                /* Need all bits to be set, but not all the bits were set. */
            }

            if( xMatchFound != pdFALSE_core2 )
            {
                /* The bits match.  Should the bits be cleared on exit? */
                if( ( uxControlBits_core2 & eventCLEAR_EVENTS_ON_EXIT_BIT_core2 ) != ( EventBits_t_core2 ) 0 )
                {
                    uxBitsToClear_core2 |= uxBitsWaitedFor_core2;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core2();
                }

                /* Store the actual event flag value in the task_core2's event list
                 * item before removing the task_core2 from the event list.  The
                 * eventUNBLOCKED_DUE_TO_BIT_SET_core2 bit is set so the task_core2 knows
                 * that is was unblocked due to its required bits matching, rather
                 * than because it timed out. */
                vTaskRemoveFromUnorderedEventList_core2( pxListItem_core2, pxEventBits_core2->uxEventBits_core2 | eventUNBLOCKED_DUE_TO_BIT_SET_core2 );
            }

            /* Move onto the next list item.  Note pxListItem_core2->pxNext_core2 is not
             * used here as the list item may have been removed from the event list
             * and inserted into the ready/pending reading list. */
            pxListItem_core2 = pxNext_core2;
        }

        /* Clear any bits that matched when the eventCLEAR_EVENTS_ON_EXIT_BIT_core2
         * bit was set in the control word. */
        pxEventBits_core2->uxEventBits_core2 &= ~uxBitsToClear_core2;
    }
    ( void ) xTaskResumeAll_core2();

    return pxEventBits_core2->uxEventBits_core2;
}
/*-----------------------------------------------------------*/

void vEventGroupDelete_core2( EventGroupHandle_t_core2 xEventGroup_core2 )
{
    EventGroup_t_core2 * pxEventBits_core2 = xEventGroup_core2;
    const List_t_core2 * pxTasksWaitingForBits;

    configASSERT_core2( pxEventBits_core2 );

    pxTasksWaitingForBits = &( pxEventBits_core2->xTasksWaitingForBits_core2 );

    vTaskSuspendAll_core2();
    {
        traceEVENT_GROUP_DELETE_core2( xEventGroup_core2 );

        while( listCURRENT_LIST_LENGTH_core2( pxTasksWaitingForBits ) > ( UBaseType_t_core2 ) 0 )
        {
            /* Unblock the task_core2, returning 0 as the event list is being deleted
             * and cannot therefore have any bits set. */
            configASSERT_core2( pxTasksWaitingForBits->xListEnd_core2.pxNext_core2 != ( const ListItem_t_core2 * ) &( pxTasksWaitingForBits->xListEnd_core2 ) );
            vTaskRemoveFromUnorderedEventList_core2( pxTasksWaitingForBits->xListEnd_core2.pxNext_core2, eventUNBLOCKED_DUE_TO_BIT_SET_core2 );
        }
    }
    ( void ) xTaskResumeAll_core2();

    #if ( ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core2 == 0 ) )
    {
        /* The event group can only have been allocated dynamically - free
         * it again. */
        vPortFree_core2( pxEventBits_core2 );
    }
    #elif ( ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 ) )
    {
        /* The event group could have been allocated statically or
         * dynamically, so check before attempting to free the memory. */
        if( pxEventBits_core2->ucStaticallyAllocated_core2 == ( uint8_t ) pdFALSE_core2 )
        {
            vPortFree_core2( pxEventBits_core2 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core2 */
}
/*-----------------------------------------------------------*/

/* For internal use only - execute a 'set bits' command that was pended from
 * an interrupt. */
void vEventGroupSetBitsCallback_core2( void * pvEventGroup_core2,
                                 const uint32_t ulBitsToSet_core2 )
{
    ( void ) xEventGroupSetBits_core2( pvEventGroup_core2, ( EventBits_t_core2 ) ulBitsToSet_core2 ); /*lint !e9079 Can't avoid cast to void* as a generic timer callback prototype. Callback casts back to original type so safe. */
}
/*-----------------------------------------------------------*/

/* For internal use only - execute a 'clear bits' command that was pended from
 * an interrupt. */
void vEventGroupClearBitsCallback_core2( void * pvEventGroup_core2,
                                   const uint32_t ulBitsToClear_core2 )
{
    ( void ) xEventGroupClearBits_core2( pvEventGroup_core2, ( EventBits_t_core2 ) ulBitsToClear_core2 ); /*lint !e9079 Can't avoid cast to void* as a generic timer callback prototype. Callback casts back to original type so safe. */
}
/*-----------------------------------------------------------*/

static BaseType_t_core2 prvTestWaitCondition_core2( const EventBits_t_core2 uxCurrentEventBits,
                                        const EventBits_t_core2 uxBitsToWaitFor_core2,
                                        const BaseType_t_core2 xWaitForAllBits_core2 )
{
    BaseType_t_core2 xWaitConditionMet_core2 = pdFALSE_core2;

    if( xWaitForAllBits_core2 == pdFALSE_core2 )
    {
        /* Task only has to wait for one bit within uxBitsToWaitFor_core2 to be
         * set.  Is one already set? */
        if( ( uxCurrentEventBits & uxBitsToWaitFor_core2 ) != ( EventBits_t_core2 ) 0 )
        {
            xWaitConditionMet_core2 = pdTRUE_core2;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    else
    {
        /* Task has to wait for all the bits in uxBitsToWaitFor_core2 to be set.
         * Are they set already? */
        if( ( uxCurrentEventBits & uxBitsToWaitFor_core2 ) == uxBitsToWaitFor_core2 )
        {
            xWaitConditionMet_core2 = pdTRUE_core2;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }

    return xWaitConditionMet_core2;
}
/*-----------------------------------------------------------*/

#if ( ( configUSE_TRACE_FACILITY_core2 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core2 == 1 ) && ( configUSE_TIMERS_core2 == 1 ) )

    BaseType_t_core2 xEventGroupSetBitsFromISR_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                          const EventBits_t_core2 uxBitsToSet_core2,
                                          BaseType_t_core2 * pxHigherPriorityTaskWoken_core2 )
    {
        BaseType_t_core2 xReturn_core2;

        traceEVENT_GROUP_SET_BITS_FROM_ISR_core2( xEventGroup_core2, uxBitsToSet_core2 );
        xReturn_core2 = xTimerPendFunctionCallFromISR_core2( vEventGroupSetBitsCallback_core2, ( void * ) xEventGroup_core2, ( uint32_t ) uxBitsToSet_core2, pxHigherPriorityTaskWoken_core2 ); /*lint !e9087 Can't avoid cast to void* as a generic callback function not specific to this use case. Callback casts back to original type so safe. */

        return xReturn_core2;
    }

#endif /* if ( ( configUSE_TRACE_FACILITY_core2 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core2 == 1 ) && ( configUSE_TIMERS_core2 == 1 ) ) */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core2 == 1 )

    UBaseType_t_core2 uxEventGroupGetNumber_core2( void * xEventGroup_core2 )
    {
        UBaseType_t_core2 xReturn_core2;
        EventGroup_t_core2 const * pxEventBits_core2 = ( EventGroup_t_core2 * ) xEventGroup_core2; /*lint !e9087 !e9079 EventGroupHandle_t_core2 is a pointer to an EventGroup_t_core2, but EventGroupHandle_t_core2 is kept opaque outside of this file for data hiding purposes. */

        if( xEventGroup_core2 == NULL )
        {
            xReturn_core2 = 0;
        }
        else
        {
            xReturn_core2 = pxEventBits_core2->uxEventGroupNumber_core2;
        }

        return xReturn_core2;
    }

#endif /* configUSE_TRACE_FACILITY_core2 */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core2 == 1 )

    void vEventGroupSetNumber_core2( void * xEventGroup_core2,
                               UBaseType_t_core2 uxEventGroupNumber_core2 )
    {
        ( ( EventGroup_t_core2 * ) xEventGroup_core2 )->uxEventGroupNumber_core2 = uxEventGroupNumber_core2; /*lint !e9087 !e9079 EventGroupHandle_t_core2 is a pointer to an EventGroup_t_core2, but EventGroupHandle_t_core2 is kept opaque outside of this file for data hiding purposes. */
    }

#endif /* configUSE_TRACE_FACILITY_core2 */
/*-----------------------------------------------------------*/
