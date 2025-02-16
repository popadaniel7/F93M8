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

/* Standard includes. */
#include <stdlib.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0 prevents task_core0.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core0.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0

/* FreeRTOS_core0 includes. */
#include "FreeRTOS_core0.h"
#include "task_core0.h"
#include "timers_core0.h"
#include "event_groups_core0.h"

/* Lint e961, e750 and e9021 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0 to be defined
 * for the header files above, but not in this file, in order to generate the
 * correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0 /*lint !e961 !e750 !e9021 See comment above. */

/* The following bit fields convey control information in a task_core0's event list
 * item value.  It is important they don't clash with the
 * taskEVENT_LIST_ITEM_VALUE_IN_USE_core0 definition. */
#if configUSE_16_BIT_TICKS_core0 == 1
    #define eventCLEAR_EVENTS_ON_EXIT_BIT_core0    0x0100U
    #define eventUNBLOCKED_DUE_TO_BIT_SET_core0    0x0200U
    #define eventWAIT_FOR_ALL_BITS_core0           0x0400U
    #define eventEVENT_BITS_CONTROL_BYTES_core0    0xff00U
#else
    #define eventCLEAR_EVENTS_ON_EXIT_BIT_core0    0x01000000UL
    #define eventUNBLOCKED_DUE_TO_BIT_SET_core0    0x02000000UL
    #define eventWAIT_FOR_ALL_BITS_core0           0x04000000UL
    #define eventEVENT_BITS_CONTROL_BYTES_core0    0xff000000UL
#endif

typedef struct EventGroupDef_t_core0
{
    EventBits_t_core0 uxEventBits_core0;
    List_t_core0 xTasksWaitingForBits_core0; /*< List of tasks waiting for a bit to be set. */

    #if ( configUSE_TRACE_FACILITY_core0 == 1 )
        UBaseType_t_core0 uxEventGroupNumber_core0;
    #endif

    #if ( ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 ) )
        uint8_t ucStaticallyAllocated_core0; /*< Set to pdTRUE_core0 if the event group is statically allocated to ensure no attempt is made to free the memory. */
    #endif
} EventGroup_t_core0;

/*-----------------------------------------------------------*/

/*
 * Test the bits set in uxCurrentEventBits to see if the wait condition is met.
 * The wait condition is defined by xWaitForAllBits_core0.  If xWaitForAllBits_core0 is
 * pdTRUE_core0 then the wait condition is met if all the bits set in uxBitsToWaitFor_core0
 * are also set in uxCurrentEventBits.  If xWaitForAllBits_core0 is pdFALSE_core0 then the
 * wait condition is met if any of the bits set in uxBitsToWait for are also set
 * in uxCurrentEventBits.
 */
static BaseType_t_core0 prvTestWaitCondition_core0( const EventBits_t_core0 uxCurrentEventBits,
                                        const EventBits_t_core0 uxBitsToWaitFor_core0,
                                        const BaseType_t_core0 xWaitForAllBits_core0 ) PRIVILEGED_FUNCTION_core0;

/*-----------------------------------------------------------*/

#if ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 )

    EventGroupHandle_t_core0 xEventGroupCreateStatic_core0( StaticEventGroup_t_core0 * pxEventGroupBuffer_core0 )
    {
        EventGroup_t_core0 * pxEventBits_core0;

        /* A StaticEventGroup_t_core0 object must be provided. */
        configASSERT_core0( pxEventGroupBuffer_core0 );

        #if ( configASSERT_DEFINED_core0 == 1 )
        {
            /* Sanity check that the size of the structure used to declare a
             * variable of type StaticEventGroup_t_core0 equals the size of the real
             * event group structure. */
            volatile size_t xSize_core0 = sizeof( StaticEventGroup_t_core0 );
            configASSERT_core0( xSize_core0 == sizeof( EventGroup_t_core0 ) );
        } /*lint !e529 xSize_core0 is referenced if configASSERT_core0() is defined. */
        #endif /* configASSERT_DEFINED_core0 */

        /* The user has provided a statically allocated event group - use it. */
        pxEventBits_core0 = ( EventGroup_t_core0 * ) pxEventGroupBuffer_core0; /*lint !e740 !e9087 EventGroup_t_core0 and StaticEventGroup_t_core0 are deliberately aliased for data hiding purposes and guaranteed to have the same size and alignment requirement - checked by configASSERT_core0(). */

        if( pxEventBits_core0 != NULL )
        {
            pxEventBits_core0->uxEventBits_core0 = 0;
            vListInitialise_core0( &( pxEventBits_core0->xTasksWaitingForBits_core0 ) );

            #if ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 )
            {
                /* Both static and dynamic allocation can be used, so note that
                 * this event group was created statically in case the event group
                 * is later deleted. */
                pxEventBits_core0->ucStaticallyAllocated_core0 = pdTRUE_core0;
            }
            #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core0 */

            traceEVENT_GROUP_CREATE_core0( pxEventBits_core0 );
        }
        else
        {
            /* xEventGroupCreateStatic_core0 should only ever be called with
             * pxEventGroupBuffer_core0 pointing to a pre-allocated (compile time
             * allocated) StaticEventGroup_t_core0 variable. */
            traceEVENT_GROUP_CREATE_FAILED_core0();
        }

        return pxEventBits_core0;
    }

#endif /* configSUPPORT_STATIC_ALLOCATION_core0 */
/*-----------------------------------------------------------*/

#if ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 )

    EventGroupHandle_t_core0 xEventGroupCreate_core0( void )
    {
        EventGroup_t_core0 * pxEventBits_core0;

        /* Allocate the event group.  Justification for MISRA deviation as
         * follows:  pvPortMalloc_core0() always ensures returned memory blocks are
         * aligned per the requirements of the MCU stack.  In this case
         * pvPortMalloc_core0() must return a pointer that is guaranteed to meet the
         * alignment requirements of the EventGroup_t_core0 structure - which (if you
         * follow it through) is the alignment requirements of the TickType_t_core0 type
         * (EventBits_t_core0 being of TickType_t_core0 itself).  Therefore, whenever the
         * stack alignment requirements are greater than or equal to the
         * TickType_t_core0 alignment requirements the cast is safe.  In other cases,
         * where the natural word size of the architecture is less than
         * sizeof( TickType_t_core0 ), the TickType_t_core0 variables will be accessed in two
         * or more reads operations, and the alignment requirements is only that
         * of each individual read. */
        pxEventBits_core0 = ( EventGroup_t_core0 * ) pvPortMalloc_core0( sizeof( EventGroup_t_core0 ) ); /*lint !e9087 !e9079 see comment above. */

        if( pxEventBits_core0 != NULL )
        {
            pxEventBits_core0->uxEventBits_core0 = 0;
            vListInitialise_core0( &( pxEventBits_core0->xTasksWaitingForBits_core0 ) );

            #if ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 )
            {
                /* Both static and dynamic allocation can be used, so note this
                 * event group was allocated statically in case the event group is
                 * later deleted. */
                pxEventBits_core0->ucStaticallyAllocated_core0 = pdFALSE_core0;
            }
            #endif /* configSUPPORT_STATIC_ALLOCATION_core0 */

            traceEVENT_GROUP_CREATE_core0( pxEventBits_core0 );
        }
        else
        {
            traceEVENT_GROUP_CREATE_FAILED_core0(); /*lint !e9063 Else branch only exists to allow tracing and does not generate code if trace macros are not defined. */
        }

        return pxEventBits_core0;
    }

#endif /* configSUPPORT_DYNAMIC_ALLOCATION_core0 */
/*-----------------------------------------------------------*/

EventBits_t_core0 xEventGroupSync_core0( EventGroupHandle_t_core0 xEventGroup_core0,
                             const EventBits_t_core0 uxBitsToSet_core0,
                             const EventBits_t_core0 uxBitsToWaitFor_core0,
                             TickType_t_core0 xTicksToWait_core0 )
{
    EventBits_t_core0 uxOriginalBitValue_core0, uxReturn_core0;
    EventGroup_t_core0 * pxEventBits_core0 = xEventGroup_core0;
    BaseType_t_core0 xAlreadyYielded_core0;
    BaseType_t_core0 xTimeoutOccurred_core0 = pdFALSE_core0;

    configASSERT_core0( ( uxBitsToWaitFor_core0 & eventEVENT_BITS_CONTROL_BYTES_core0 ) == 0 );
    configASSERT_core0( uxBitsToWaitFor_core0 != 0 );
    #if ( ( INCLUDE_xTaskGetSchedulerState_core0 == 1 ) || ( configUSE_TIMERS_core0 == 1 ) )
    {
        configASSERT_core0( !( ( xTaskGetSchedulerState_core0() == taskSCHEDULER_SUSPENDED_core0 ) && ( xTicksToWait_core0 != 0 ) ) );
    }
    #endif

    vTaskSuspendAll_core0();
    {
        uxOriginalBitValue_core0 = pxEventBits_core0->uxEventBits_core0;

        ( void ) xEventGroupSetBits_core0( xEventGroup_core0, uxBitsToSet_core0 );

        if( ( ( uxOriginalBitValue_core0 | uxBitsToSet_core0 ) & uxBitsToWaitFor_core0 ) == uxBitsToWaitFor_core0 )
        {
            /* All the rendezvous bits are now set - no need to block. */
            uxReturn_core0 = ( uxOriginalBitValue_core0 | uxBitsToSet_core0 );

            /* Rendezvous always clear the bits.  They will have been cleared
             * already unless this is the only task_core0 in the rendezvous. */
            pxEventBits_core0->uxEventBits_core0 &= ~uxBitsToWaitFor_core0;

            xTicksToWait_core0 = 0;
        }
        else
        {
            if( xTicksToWait_core0 != ( TickType_t_core0 ) 0 )
            {
                traceEVENT_GROUP_SYNC_BLOCK_core0( xEventGroup_core0, uxBitsToSet_core0, uxBitsToWaitFor_core0 );

                /* Store the bits that the calling task_core0 is waiting for in the
                 * task_core0's event list item so the kernel knows when a match is
                 * found.  Then enter the blocked state. */
                vTaskPlaceOnUnorderedEventList_core0( &( pxEventBits_core0->xTasksWaitingForBits_core0 ), ( uxBitsToWaitFor_core0 | eventCLEAR_EVENTS_ON_EXIT_BIT_core0 | eventWAIT_FOR_ALL_BITS_core0 ), xTicksToWait_core0 );

                /* This assignment is obsolete as uxReturn_core0 will get set after
                 * the task_core0 unblocks, but some compilers mistakenly generate a
                 * warning about uxReturn_core0 being returned without being set if the
                 * assignment is omitted. */
                uxReturn_core0 = 0;
            }
            else
            {
                /* The rendezvous bits were not set, but no block time was
                 * specified - just return the current event bit value. */
                uxReturn_core0 = pxEventBits_core0->uxEventBits_core0;
                xTimeoutOccurred_core0 = pdTRUE_core0;
            }
        }
    }
    xAlreadyYielded_core0 = xTaskResumeAll_core0();

    if( xTicksToWait_core0 != ( TickType_t_core0 ) 0 )
    {
        if( xAlreadyYielded_core0 == pdFALSE_core0 )
        {
            portYIELD_WITHIN_API_core0();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }

        /* The task_core0 blocked to wait for its required bits to be set - at this
         * point either the required bits were set or the block time expired.  If
         * the required bits were set they will have been stored in the task_core0's
         * event list item, and they should now be retrieved then cleared. */
        uxReturn_core0 = uxTaskResetEventItemValue_core0();

        if( ( uxReturn_core0 & eventUNBLOCKED_DUE_TO_BIT_SET_core0 ) == ( EventBits_t_core0 ) 0 )
        {
            /* The task_core0 timed out, just return the current event bit value. */
            taskENTER_CRITICAL_core0();
            {
                uxReturn_core0 = pxEventBits_core0->uxEventBits_core0;

                /* Although the task_core0 got here because it timed out before the
                 * bits it was waiting for were set, it is possible that since it
                 * unblocked another task_core0 has set the bits.  If this is the case
                 * then it needs to clear the bits before exiting. */
                if( ( uxReturn_core0 & uxBitsToWaitFor_core0 ) == uxBitsToWaitFor_core0 )
                {
                    pxEventBits_core0->uxEventBits_core0 &= ~uxBitsToWaitFor_core0;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core0();
                }
            }
            taskEXIT_CRITICAL_core0();

            xTimeoutOccurred_core0 = pdTRUE_core0;
        }
        else
        {
            /* The task_core0 unblocked because the bits were set. */
        }

        /* Control bits might be set as the task_core0 had blocked should not be
         * returned. */
        uxReturn_core0 &= ~eventEVENT_BITS_CONTROL_BYTES_core0;
    }

    traceEVENT_GROUP_SYNC_END_core0( xEventGroup_core0, uxBitsToSet_core0, uxBitsToWaitFor_core0, xTimeoutOccurred_core0 );

    /* Prevent compiler warnings when trace macros are not used. */
    ( void ) xTimeoutOccurred_core0;

    return uxReturn_core0;
}
/*-----------------------------------------------------------*/

EventBits_t_core0 xEventGroupWaitBits_core0( EventGroupHandle_t_core0 xEventGroup_core0,
                                 const EventBits_t_core0 uxBitsToWaitFor_core0,
                                 const BaseType_t_core0 xClearOnExit_core0,
                                 const BaseType_t_core0 xWaitForAllBits_core0,
                                 TickType_t_core0 xTicksToWait_core0 )
{
    EventGroup_t_core0 * pxEventBits_core0 = xEventGroup_core0;
    EventBits_t_core0 uxReturn_core0, uxControlBits_core0 = 0;
    BaseType_t_core0 xWaitConditionMet_core0, xAlreadyYielded_core0;
    BaseType_t_core0 xTimeoutOccurred_core0 = pdFALSE_core0;

    /* Check the user is not attempting to wait on the bits used by the kernel
     * itself, and that at least one bit is being requested. */
    configASSERT_core0( xEventGroup_core0 );
    configASSERT_core0( ( uxBitsToWaitFor_core0 & eventEVENT_BITS_CONTROL_BYTES_core0 ) == 0 );
    configASSERT_core0( uxBitsToWaitFor_core0 != 0 );
    #if ( ( INCLUDE_xTaskGetSchedulerState_core0 == 1 ) || ( configUSE_TIMERS_core0 == 1 ) )
    {
        configASSERT_core0( !( ( xTaskGetSchedulerState_core0() == taskSCHEDULER_SUSPENDED_core0 ) && ( xTicksToWait_core0 != 0 ) ) );
    }
    #endif

    vTaskSuspendAll_core0();
    {
        const EventBits_t_core0 uxCurrentEventBits = pxEventBits_core0->uxEventBits_core0;

        /* Check to see if the wait condition is already met or not. */
        xWaitConditionMet_core0 = prvTestWaitCondition_core0( uxCurrentEventBits, uxBitsToWaitFor_core0, xWaitForAllBits_core0 );

        if( xWaitConditionMet_core0 != pdFALSE_core0 )
        {
            /* The wait condition has already been met so there is no need to
             * block. */
            uxReturn_core0 = uxCurrentEventBits;
            xTicksToWait_core0 = ( TickType_t_core0 ) 0;

            /* Clear the wait bits if requested to do so. */
            if( xClearOnExit_core0 != pdFALSE_core0 )
            {
                pxEventBits_core0->uxEventBits_core0 &= ~uxBitsToWaitFor_core0;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core0();
            }
        }
        else if( xTicksToWait_core0 == ( TickType_t_core0 ) 0 )
        {
            /* The wait condition has not been met, but no block time was
             * specified, so just return the current value. */
            uxReturn_core0 = uxCurrentEventBits;
            xTimeoutOccurred_core0 = pdTRUE_core0;
        }
        else
        {
            /* The task_core0 is going to block to wait for its required bits to be
             * set.  uxControlBits_core0 are used to remember the specified behaviour of
             * this call to xEventGroupWaitBits_core0() - for use when the event bits
             * unblock the task_core0. */
            if( xClearOnExit_core0 != pdFALSE_core0 )
            {
                uxControlBits_core0 |= eventCLEAR_EVENTS_ON_EXIT_BIT_core0;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core0();
            }

            if( xWaitForAllBits_core0 != pdFALSE_core0 )
            {
                uxControlBits_core0 |= eventWAIT_FOR_ALL_BITS_core0;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core0();
            }

            /* Store the bits that the calling task_core0 is waiting for in the
             * task_core0's event list item so the kernel knows when a match is
             * found.  Then enter the blocked state. */
            vTaskPlaceOnUnorderedEventList_core0( &( pxEventBits_core0->xTasksWaitingForBits_core0 ), ( uxBitsToWaitFor_core0 | uxControlBits_core0 ), xTicksToWait_core0 );

            /* This is obsolete as it will get set after the task_core0 unblocks, but
             * some compilers mistakenly generate a warning about the variable
             * being returned without being set if it is not done. */
            uxReturn_core0 = 0;

            traceEVENT_GROUP_WAIT_BITS_BLOCK_core0( xEventGroup_core0, uxBitsToWaitFor_core0 );
        }
    }
    xAlreadyYielded_core0 = xTaskResumeAll_core0();

    if( xTicksToWait_core0 != ( TickType_t_core0 ) 0 )
    {
        if( xAlreadyYielded_core0 == pdFALSE_core0 )
        {
            portYIELD_WITHIN_API_core0();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }

        /* The task_core0 blocked to wait for its required bits to be set - at this
         * point either the required bits were set or the block time expired.  If
         * the required bits were set they will have been stored in the task_core0's
         * event list item, and they should now be retrieved then cleared. */
        uxReturn_core0 = uxTaskResetEventItemValue_core0();

        if( ( uxReturn_core0 & eventUNBLOCKED_DUE_TO_BIT_SET_core0 ) == ( EventBits_t_core0 ) 0 )
        {
            taskENTER_CRITICAL_core0();
            {
                /* The task_core0 timed out, just return the current event bit value. */
                uxReturn_core0 = pxEventBits_core0->uxEventBits_core0;

                /* It is possible that the event bits were updated between this
                 * task_core0 leaving the Blocked state and running again. */
                if( prvTestWaitCondition_core0( uxReturn_core0, uxBitsToWaitFor_core0, xWaitForAllBits_core0 ) != pdFALSE_core0 )
                {
                    if( xClearOnExit_core0 != pdFALSE_core0 )
                    {
                        pxEventBits_core0->uxEventBits_core0 &= ~uxBitsToWaitFor_core0;
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

                xTimeoutOccurred_core0 = pdTRUE_core0;
            }
            taskEXIT_CRITICAL_core0();
        }
        else
        {
            /* The task_core0 unblocked because the bits were set. */
        }

        /* The task_core0 blocked so control bits may have been set. */
        uxReturn_core0 &= ~eventEVENT_BITS_CONTROL_BYTES_core0;
    }

    traceEVENT_GROUP_WAIT_BITS_END_core0( xEventGroup_core0, uxBitsToWaitFor_core0, xTimeoutOccurred_core0 );

    /* Prevent compiler warnings when trace macros are not used. */
    ( void ) xTimeoutOccurred_core0;

    return uxReturn_core0;
}
/*-----------------------------------------------------------*/

EventBits_t_core0 xEventGroupClearBits_core0( EventGroupHandle_t_core0 xEventGroup_core0,
                                  const EventBits_t_core0 uxBitsToClear_core0 )
{
    EventGroup_t_core0 * pxEventBits_core0 = xEventGroup_core0;
    EventBits_t_core0 uxReturn_core0;

    /* Check the user is not attempting to clear the bits used by the kernel
     * itself. */
    configASSERT_core0( xEventGroup_core0 );
    configASSERT_core0( ( uxBitsToClear_core0 & eventEVENT_BITS_CONTROL_BYTES_core0 ) == 0 );

    taskENTER_CRITICAL_core0();
    {
        traceEVENT_GROUP_CLEAR_BITS_core0( xEventGroup_core0, uxBitsToClear_core0 );

        /* The value returned is the event group value prior to the bits being
         * cleared. */
        uxReturn_core0 = pxEventBits_core0->uxEventBits_core0;

        /* Clear the bits. */
        pxEventBits_core0->uxEventBits_core0 &= ~uxBitsToClear_core0;
    }
    taskEXIT_CRITICAL_core0();

    return uxReturn_core0;
}
/*-----------------------------------------------------------*/

#if ( ( configUSE_TRACE_FACILITY_core0 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core0 == 1 ) && ( configUSE_TIMERS_core0 == 1 ) )

    BaseType_t_core0 xEventGroupClearBitsFromISR_core0( EventGroupHandle_t_core0 xEventGroup_core0,
                                            const EventBits_t_core0 uxBitsToClear_core0 )
    {
        BaseType_t_core0 xReturn_core0;

        traceEVENT_GROUP_CLEAR_BITS_FROM_ISR_core0( xEventGroup_core0, uxBitsToClear_core0 );
        xReturn_core0 = xTimerPendFunctionCallFromISR_core0( vEventGroupClearBitsCallback_core0, ( void * ) xEventGroup_core0, ( uint32_t ) uxBitsToClear_core0, NULL ); /*lint !e9087 Can't avoid cast to void* as a generic callback function not specific to this use case. Callback casts back to original type so safe. */

        return xReturn_core0;
    }

#endif /* if ( ( configUSE_TRACE_FACILITY_core0 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core0 == 1 ) && ( configUSE_TIMERS_core0 == 1 ) ) */
/*-----------------------------------------------------------*/

EventBits_t_core0 xEventGroupGetBitsFromISR_core0( EventGroupHandle_t_core0 xEventGroup_core0 )
{
    UBaseType_t_core0 uxSavedInterruptStatus_core0;
    EventGroup_t_core0 const * const pxEventBits_core0 = xEventGroup_core0;
    EventBits_t_core0 uxReturn_core0;

    uxSavedInterruptStatus_core0 = portSET_INTERRUPT_MASK_FROM_ISR_core0();
    {
        uxReturn_core0 = pxEventBits_core0->uxEventBits_core0;
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core0( uxSavedInterruptStatus_core0 );

    return uxReturn_core0;
} /*lint !e818 EventGroupHandle_t_core0 is a typedef used in other functions to so can't be pointer to const. */
/*-----------------------------------------------------------*/

EventBits_t_core0 xEventGroupSetBits_core0( EventGroupHandle_t_core0 xEventGroup_core0,
                                const EventBits_t_core0 uxBitsToSet_core0 )
{
    ListItem_t_core0 * pxListItem_core0;
    ListItem_t_core0 * pxNext_core0;
    ListItem_t_core0 const * pxListEnd_core0;
    List_t_core0 const * pxList_core0;
    EventBits_t_core0 uxBitsToClear_core0 = 0, uxBitsWaitedFor_core0, uxControlBits_core0;
    EventGroup_t_core0 * pxEventBits_core0 = xEventGroup_core0;
    BaseType_t_core0 xMatchFound = pdFALSE_core0;

    /* Check the user is not attempting to set the bits used by the kernel
     * itself. */
    configASSERT_core0( xEventGroup_core0 );
    configASSERT_core0( ( uxBitsToSet_core0 & eventEVENT_BITS_CONTROL_BYTES_core0 ) == 0 );

    pxList_core0 = &( pxEventBits_core0->xTasksWaitingForBits_core0 );
    pxListEnd_core0 = listGET_END_MARKER_core0( pxList_core0 ); /*lint !e826 !e740 !e9087 The mini list structure is used as the list end to save RAM.  This is checked and valid. */
    vTaskSuspendAll_core0();
    {
        traceEVENT_GROUP_SET_BITS_core0( xEventGroup_core0, uxBitsToSet_core0 );

        pxListItem_core0 = listGET_HEAD_ENTRY_core0( pxList_core0 );

        /* Set the bits. */
        pxEventBits_core0->uxEventBits_core0 |= uxBitsToSet_core0;

        /* See if the new bit value should unblock any tasks. */
        while( pxListItem_core0 != pxListEnd_core0 )
        {
            pxNext_core0 = listGET_NEXT_core0( pxListItem_core0 );
            uxBitsWaitedFor_core0 = listGET_LIST_ITEM_VALUE_core0( pxListItem_core0 );
            xMatchFound = pdFALSE_core0;

            /* Split the bits waited for from the control bits. */
            uxControlBits_core0 = uxBitsWaitedFor_core0 & eventEVENT_BITS_CONTROL_BYTES_core0;
            uxBitsWaitedFor_core0 &= ~eventEVENT_BITS_CONTROL_BYTES_core0;

            if( ( uxControlBits_core0 & eventWAIT_FOR_ALL_BITS_core0 ) == ( EventBits_t_core0 ) 0 )
            {
                /* Just looking for single bit being set. */
                if( ( uxBitsWaitedFor_core0 & pxEventBits_core0->uxEventBits_core0 ) != ( EventBits_t_core0 ) 0 )
                {
                    xMatchFound = pdTRUE_core0;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core0();
                }
            }
            else if( ( uxBitsWaitedFor_core0 & pxEventBits_core0->uxEventBits_core0 ) == uxBitsWaitedFor_core0 )
            {
                /* All bits are set. */
                xMatchFound = pdTRUE_core0;
            }
            else
            {
                /* Need all bits to be set, but not all the bits were set. */
            }

            if( xMatchFound != pdFALSE_core0 )
            {
                /* The bits match.  Should the bits be cleared on exit? */
                if( ( uxControlBits_core0 & eventCLEAR_EVENTS_ON_EXIT_BIT_core0 ) != ( EventBits_t_core0 ) 0 )
                {
                    uxBitsToClear_core0 |= uxBitsWaitedFor_core0;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core0();
                }

                /* Store the actual event flag value in the task_core0's event list
                 * item before removing the task_core0 from the event list.  The
                 * eventUNBLOCKED_DUE_TO_BIT_SET_core0 bit is set so the task_core0 knows
                 * that is was unblocked due to its required bits matching, rather
                 * than because it timed out. */
                vTaskRemoveFromUnorderedEventList_core0( pxListItem_core0, pxEventBits_core0->uxEventBits_core0 | eventUNBLOCKED_DUE_TO_BIT_SET_core0 );
            }

            /* Move onto the next list item.  Note pxListItem_core0->pxNext_core0 is not
             * used here as the list item may have been removed from the event list
             * and inserted into the ready/pending reading list. */
            pxListItem_core0 = pxNext_core0;
        }

        /* Clear any bits that matched when the eventCLEAR_EVENTS_ON_EXIT_BIT_core0
         * bit was set in the control word. */
        pxEventBits_core0->uxEventBits_core0 &= ~uxBitsToClear_core0;
    }
    ( void ) xTaskResumeAll_core0();

    return pxEventBits_core0->uxEventBits_core0;
}
/*-----------------------------------------------------------*/

void vEventGroupDelete_core0( EventGroupHandle_t_core0 xEventGroup_core0 )
{
    EventGroup_t_core0 * pxEventBits_core0 = xEventGroup_core0;
    const List_t_core0 * pxTasksWaitingForBits;

    configASSERT_core0( pxEventBits_core0 );

    pxTasksWaitingForBits = &( pxEventBits_core0->xTasksWaitingForBits_core0 );

    vTaskSuspendAll_core0();
    {
        traceEVENT_GROUP_DELETE_core0( xEventGroup_core0 );

        while( listCURRENT_LIST_LENGTH_core0( pxTasksWaitingForBits ) > ( UBaseType_t_core0 ) 0 )
        {
            /* Unblock the task_core0, returning 0 as the event list is being deleted
             * and cannot therefore have any bits set. */
            configASSERT_core0( pxTasksWaitingForBits->xListEnd_core0.pxNext_core0 != ( const ListItem_t_core0 * ) &( pxTasksWaitingForBits->xListEnd_core0 ) );
            vTaskRemoveFromUnorderedEventList_core0( pxTasksWaitingForBits->xListEnd_core0.pxNext_core0, eventUNBLOCKED_DUE_TO_BIT_SET_core0 );
        }
    }
    ( void ) xTaskResumeAll_core0();

    #if ( ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core0 == 0 ) )
    {
        /* The event group can only have been allocated dynamically - free
         * it again. */
        vPortFree_core0( pxEventBits_core0 );
    }
    #elif ( ( configSUPPORT_DYNAMIC_ALLOCATION_core0 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core0 == 1 ) )
    {
        /* The event group could have been allocated statically or
         * dynamically, so check before attempting to free the memory. */
        if( pxEventBits_core0->ucStaticallyAllocated_core0 == ( uint8_t ) pdFALSE_core0 )
        {
            vPortFree_core0( pxEventBits_core0 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }
    }
    #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core0 */
}
/*-----------------------------------------------------------*/

/* For internal use only - execute a 'set bits' command that was pended from
 * an interrupt. */
void vEventGroupSetBitsCallback_core0( void * pvEventGroup_core0,
                                 const uint32_t ulBitsToSet_core0 )
{
    ( void ) xEventGroupSetBits_core0( pvEventGroup_core0, ( EventBits_t_core0 ) ulBitsToSet_core0 ); /*lint !e9079 Can't avoid cast to void* as a generic timer callback prototype. Callback casts back to original type so safe. */
}
/*-----------------------------------------------------------*/

/* For internal use only - execute a 'clear bits' command that was pended from
 * an interrupt. */
void vEventGroupClearBitsCallback_core0( void * pvEventGroup_core0,
                                   const uint32_t ulBitsToClear_core0 )
{
    ( void ) xEventGroupClearBits_core0( pvEventGroup_core0, ( EventBits_t_core0 ) ulBitsToClear_core0 ); /*lint !e9079 Can't avoid cast to void* as a generic timer callback prototype. Callback casts back to original type so safe. */
}
/*-----------------------------------------------------------*/

static BaseType_t_core0 prvTestWaitCondition_core0( const EventBits_t_core0 uxCurrentEventBits,
                                        const EventBits_t_core0 uxBitsToWaitFor_core0,
                                        const BaseType_t_core0 xWaitForAllBits_core0 )
{
    BaseType_t_core0 xWaitConditionMet_core0 = pdFALSE_core0;

    if( xWaitForAllBits_core0 == pdFALSE_core0 )
    {
        /* Task only has to wait for one bit within uxBitsToWaitFor_core0 to be
         * set.  Is one already set? */
        if( ( uxCurrentEventBits & uxBitsToWaitFor_core0 ) != ( EventBits_t_core0 ) 0 )
        {
            xWaitConditionMet_core0 = pdTRUE_core0;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }
    }
    else
    {
        /* Task has to wait for all the bits in uxBitsToWaitFor_core0 to be set.
         * Are they set already? */
        if( ( uxCurrentEventBits & uxBitsToWaitFor_core0 ) == uxBitsToWaitFor_core0 )
        {
            xWaitConditionMet_core0 = pdTRUE_core0;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core0();
        }
    }

    return xWaitConditionMet_core0;
}
/*-----------------------------------------------------------*/

#if ( ( configUSE_TRACE_FACILITY_core0 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core0 == 1 ) && ( configUSE_TIMERS_core0 == 1 ) )

    BaseType_t_core0 xEventGroupSetBitsFromISR_core0( EventGroupHandle_t_core0 xEventGroup_core0,
                                          const EventBits_t_core0 uxBitsToSet_core0,
                                          BaseType_t_core0 * pxHigherPriorityTaskWoken_core0 )
    {
        BaseType_t_core0 xReturn_core0;

        traceEVENT_GROUP_SET_BITS_FROM_ISR_core0( xEventGroup_core0, uxBitsToSet_core0 );
        xReturn_core0 = xTimerPendFunctionCallFromISR_core0( vEventGroupSetBitsCallback_core0, ( void * ) xEventGroup_core0, ( uint32_t ) uxBitsToSet_core0, pxHigherPriorityTaskWoken_core0 ); /*lint !e9087 Can't avoid cast to void* as a generic callback function not specific to this use case. Callback casts back to original type so safe. */

        return xReturn_core0;
    }

#endif /* if ( ( configUSE_TRACE_FACILITY_core0 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core0 == 1 ) && ( configUSE_TIMERS_core0 == 1 ) ) */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core0 == 1 )

    UBaseType_t_core0 uxEventGroupGetNumber_core0( void * xEventGroup_core0 )
    {
        UBaseType_t_core0 xReturn_core0;
        EventGroup_t_core0 const * pxEventBits_core0 = ( EventGroup_t_core0 * ) xEventGroup_core0; /*lint !e9087 !e9079 EventGroupHandle_t_core0 is a pointer to an EventGroup_t_core0, but EventGroupHandle_t_core0 is kept opaque outside of this file for data hiding purposes. */

        if( xEventGroup_core0 == NULL )
        {
            xReturn_core0 = 0;
        }
        else
        {
            xReturn_core0 = pxEventBits_core0->uxEventGroupNumber_core0;
        }

        return xReturn_core0;
    }

#endif /* configUSE_TRACE_FACILITY_core0 */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core0 == 1 )

    void vEventGroupSetNumber_core0( void * xEventGroup_core0,
                               UBaseType_t_core0 uxEventGroupNumber_core0 )
    {
        ( ( EventGroup_t_core0 * ) xEventGroup_core0 )->uxEventGroupNumber_core0 = uxEventGroupNumber_core0; /*lint !e9087 !e9079 EventGroupHandle_t_core0 is a pointer to an EventGroup_t_core0, but EventGroupHandle_t_core0 is kept opaque outside of this file for data hiding purposes. */
    }

#endif /* configUSE_TRACE_FACILITY_core0 */
/*-----------------------------------------------------------*/
