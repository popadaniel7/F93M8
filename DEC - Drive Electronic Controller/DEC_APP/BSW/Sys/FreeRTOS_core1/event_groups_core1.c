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

/* Standard includes. */
#include <stdlib.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 prevents task_core1.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core1.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1

/* FreeRTOS_core1 includes. */
#include "FreeRTOS_core1.h"
#include "task_core1.h"
#include "timers_core1.h"
#include "event_groups_core1.h"

/* Lint e961, e750 and e9021 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 to be defined
 * for the header files above, but not in this file, in order to generate the
 * correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 /*lint !e961 !e750 !e9021 See comment above. */

/* The following bit fields convey control information in a task_core1's event list
 * item value.  It is important they don't clash with the
 * taskEVENT_LIST_ITEM_VALUE_IN_USE_core1 definition. */
#if configUSE_16_BIT_TICKS_core1 == 1
    #define eventCLEAR_EVENTS_ON_EXIT_BIT_core1    0x0100U
    #define eventUNBLOCKED_DUE_TO_BIT_SET_core1    0x0200U
    #define eventWAIT_FOR_ALL_BITS_core1           0x0400U
    #define eventEVENT_BITS_CONTROL_BYTES_core1    0xff00U
#else
    #define eventCLEAR_EVENTS_ON_EXIT_BIT_core1    0x01000000UL
    #define eventUNBLOCKED_DUE_TO_BIT_SET_core1    0x02000000UL
    #define eventWAIT_FOR_ALL_BITS_core1           0x04000000UL
    #define eventEVENT_BITS_CONTROL_BYTES_core1    0xff000000UL
#endif

typedef struct EventGroupDef_t_core1
{
    EventBits_t_core1 uxEventBits_core1;
    List_t_core1 xTasksWaitingForBits_core1; /*< List of tasks waiting for a bit to be set. */

    #if ( configUSE_TRACE_FACILITY_core1 == 1 )
        UBaseType_t_core1 uxEventGroupNumber_core1;
    #endif

    #if ( ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 ) )
        uint8_t ucStaticallyAllocated_core1; /*< Set to pdTRUE_core1 if the event group is statically allocated to ensure no attempt is made to free the memory. */
    #endif
} EventGroup_t_core1;

/*-----------------------------------------------------------*/

/*
 * Test the bits set in uxCurrentEventBits to see if the wait condition is met.
 * The wait condition is defined by xWaitForAllBits_core1.  If xWaitForAllBits_core1 is
 * pdTRUE_core1 then the wait condition is met if all the bits set in uxBitsToWaitFor_core1
 * are also set in uxCurrentEventBits.  If xWaitForAllBits_core1 is pdFALSE_core1 then the
 * wait condition is met if any of the bits set in uxBitsToWait for are also set
 * in uxCurrentEventBits.
 */
static BaseType_t_core1 prvTestWaitCondition_core1( const EventBits_t_core1 uxCurrentEventBits,
                                        const EventBits_t_core1 uxBitsToWaitFor_core1,
                                        const BaseType_t_core1 xWaitForAllBits_core1 ) PRIVILEGED_FUNCTION_core1;

/*-----------------------------------------------------------*/

#if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )

    EventGroupHandle_t_core1 xEventGroupCreateStatic_core1( StaticEventGroup_t_core1 * pxEventGroupBuffer_core1 )
    {
        EventGroup_t_core1 * pxEventBits_core1;

        /* A StaticEventGroup_t_core1 object must be provided. */
        configASSERT_core1( pxEventGroupBuffer_core1 );

        #if ( configASSERT_DEFINED_core1 == 1 )
        {
            /* Sanity check that the size of the structure used to declare a
             * variable of type StaticEventGroup_t_core1 equals the size of the real
             * event group structure. */
            volatile size_t xSize_core1 = sizeof( StaticEventGroup_t_core1 );
            configASSERT_core1( xSize_core1 == sizeof( EventGroup_t_core1 ) );
        } /*lint !e529 xSize_core1 is referenced if configASSERT_core1() is defined. */
        #endif /* configASSERT_DEFINED_core1 */

        /* The user has provided a statically allocated event group - use it. */
        pxEventBits_core1 = ( EventGroup_t_core1 * ) pxEventGroupBuffer_core1; /*lint !e740 !e9087 EventGroup_t_core1 and StaticEventGroup_t_core1 are deliberately aliased for data hiding purposes and guaranteed to have the same size and alignment requirement - checked by configASSERT_core1(). */

        if( pxEventBits_core1 != NULL )
        {
            pxEventBits_core1->uxEventBits_core1 = 0;
            vListInitialise_core1( &( pxEventBits_core1->xTasksWaitingForBits_core1 ) );

            #if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )
            {
                /* Both static and dynamic allocation can be used, so note that
                 * this event group was created statically in case the event group
                 * is later deleted. */
                pxEventBits_core1->ucStaticallyAllocated_core1 = pdTRUE_core1;
            }
            #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core1 */

            traceEVENT_GROUP_CREATE_core1( pxEventBits_core1 );
        }
        else
        {
            /* xEventGroupCreateStatic_core1 should only ever be called with
             * pxEventGroupBuffer_core1 pointing to a pre-allocated (compile time
             * allocated) StaticEventGroup_t_core1 variable. */
            traceEVENT_GROUP_CREATE_FAILED_core1();
        }

        return pxEventBits_core1;
    }

#endif /* configSUPPORT_STATIC_ALLOCATION_core1 */
/*-----------------------------------------------------------*/

#if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )

    EventGroupHandle_t_core1 xEventGroupCreate_core1( void )
    {
        EventGroup_t_core1 * pxEventBits_core1;

        /* Allocate the event group.  Justification for MISRA deviation as
         * follows:  pvPortMalloc_core1() always ensures returned memory blocks are
         * aligned per the requirements of the MCU stack.  In this case
         * pvPortMalloc_core1() must return a pointer that is guaranteed to meet the
         * alignment requirements of the EventGroup_t_core1 structure - which (if you
         * follow it through) is the alignment requirements of the TickType_t_core1 type
         * (EventBits_t_core1 being of TickType_t_core1 itself).  Therefore, whenever the
         * stack alignment requirements are greater than or equal to the
         * TickType_t_core1 alignment requirements the cast is safe.  In other cases,
         * where the natural word size of the architecture is less than
         * sizeof( TickType_t_core1 ), the TickType_t_core1 variables will be accessed in two
         * or more reads operations, and the alignment requirements is only that
         * of each individual read. */
        pxEventBits_core1 = ( EventGroup_t_core1 * ) pvPortMalloc_core1( sizeof( EventGroup_t_core1 ) ); /*lint !e9087 !e9079 see comment above. */

        if( pxEventBits_core1 != NULL )
        {
            pxEventBits_core1->uxEventBits_core1 = 0;
            vListInitialise_core1( &( pxEventBits_core1->xTasksWaitingForBits_core1 ) );

            #if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )
            {
                /* Both static and dynamic allocation can be used, so note this
                 * event group was allocated statically in case the event group is
                 * later deleted. */
                pxEventBits_core1->ucStaticallyAllocated_core1 = pdFALSE_core1;
            }
            #endif /* configSUPPORT_STATIC_ALLOCATION_core1 */

            traceEVENT_GROUP_CREATE_core1( pxEventBits_core1 );
        }
        else
        {
            traceEVENT_GROUP_CREATE_FAILED_core1(); /*lint !e9063 Else branch only exists to allow tracing and does not generate code if trace macros are not defined. */
        }

        return pxEventBits_core1;
    }

#endif /* configSUPPORT_DYNAMIC_ALLOCATION_core1 */
/*-----------------------------------------------------------*/

EventBits_t_core1 xEventGroupSync_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                             const EventBits_t_core1 uxBitsToSet_core1,
                             const EventBits_t_core1 uxBitsToWaitFor_core1,
                             TickType_t_core1 xTicksToWait_core1 )
{
    EventBits_t_core1 uxOriginalBitValue_core1, uxReturn_core1;
    EventGroup_t_core1 * pxEventBits_core1 = xEventGroup_core1;
    BaseType_t_core1 xAlreadyYielded_core1;
    BaseType_t_core1 xTimeoutOccurred_core1 = pdFALSE_core1;

    configASSERT_core1( ( uxBitsToWaitFor_core1 & eventEVENT_BITS_CONTROL_BYTES_core1 ) == 0 );
    configASSERT_core1( uxBitsToWaitFor_core1 != 0 );
    #if ( ( INCLUDE_xTaskGetSchedulerState_core1 == 1 ) || ( configUSE_TIMERS_core1 == 1 ) )
    {
        configASSERT_core1( !( ( xTaskGetSchedulerState_core1() == taskSCHEDULER_SUSPENDED_core1 ) && ( xTicksToWait_core1 != 0 ) ) );
    }
    #endif

    vTaskSuspendAll_core1();
    {
        uxOriginalBitValue_core1 = pxEventBits_core1->uxEventBits_core1;

        ( void ) xEventGroupSetBits_core1( xEventGroup_core1, uxBitsToSet_core1 );

        if( ( ( uxOriginalBitValue_core1 | uxBitsToSet_core1 ) & uxBitsToWaitFor_core1 ) == uxBitsToWaitFor_core1 )
        {
            /* All the rendezvous bits are now set - no need to block. */
            uxReturn_core1 = ( uxOriginalBitValue_core1 | uxBitsToSet_core1 );

            /* Rendezvous always clear the bits.  They will have been cleared
             * already unless this is the only task_core1 in the rendezvous. */
            pxEventBits_core1->uxEventBits_core1 &= ~uxBitsToWaitFor_core1;

            xTicksToWait_core1 = 0;
        }
        else
        {
            if( xTicksToWait_core1 != ( TickType_t_core1 ) 0 )
            {
                traceEVENT_GROUP_SYNC_BLOCK_core1( xEventGroup_core1, uxBitsToSet_core1, uxBitsToWaitFor_core1 );

                /* Store the bits that the calling task_core1 is waiting for in the
                 * task_core1's event list item so the kernel knows when a match is
                 * found.  Then enter the blocked state. */
                vTaskPlaceOnUnorderedEventList_core1( &( pxEventBits_core1->xTasksWaitingForBits_core1 ), ( uxBitsToWaitFor_core1 | eventCLEAR_EVENTS_ON_EXIT_BIT_core1 | eventWAIT_FOR_ALL_BITS_core1 ), xTicksToWait_core1 );

                /* This assignment is obsolete as uxReturn_core1 will get set after
                 * the task_core1 unblocks, but some compilers mistakenly generate a
                 * warning about uxReturn_core1 being returned without being set if the
                 * assignment is omitted. */
                uxReturn_core1 = 0;
            }
            else
            {
                /* The rendezvous bits were not set, but no block time was
                 * specified - just return the current event bit value. */
                uxReturn_core1 = pxEventBits_core1->uxEventBits_core1;
                xTimeoutOccurred_core1 = pdTRUE_core1;
            }
        }
    }
    xAlreadyYielded_core1 = xTaskResumeAll_core1();

    if( xTicksToWait_core1 != ( TickType_t_core1 ) 0 )
    {
        if( xAlreadyYielded_core1 == pdFALSE_core1 )
        {
            portYIELD_WITHIN_API_core1();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }

        /* The task_core1 blocked to wait for its required bits to be set - at this
         * point either the required bits were set or the block time expired.  If
         * the required bits were set they will have been stored in the task_core1's
         * event list item, and they should now be retrieved then cleared. */
        uxReturn_core1 = uxTaskResetEventItemValue_core1();

        if( ( uxReturn_core1 & eventUNBLOCKED_DUE_TO_BIT_SET_core1 ) == ( EventBits_t_core1 ) 0 )
        {
            /* The task_core1 timed out, just return the current event bit value. */
            taskENTER_CRITICAL_core1();
            {
                uxReturn_core1 = pxEventBits_core1->uxEventBits_core1;

                /* Although the task_core1 got here because it timed out before the
                 * bits it was waiting for were set, it is possible that since it
                 * unblocked another task_core1 has set the bits.  If this is the case
                 * then it needs to clear the bits before exiting. */
                if( ( uxReturn_core1 & uxBitsToWaitFor_core1 ) == uxBitsToWaitFor_core1 )
                {
                    pxEventBits_core1->uxEventBits_core1 &= ~uxBitsToWaitFor_core1;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core1();
                }
            }
            taskEXIT_CRITICAL_core1();

            xTimeoutOccurred_core1 = pdTRUE_core1;
        }
        else
        {
            /* The task_core1 unblocked because the bits were set. */
        }

        /* Control bits might be set as the task_core1 had blocked should not be
         * returned. */
        uxReturn_core1 &= ~eventEVENT_BITS_CONTROL_BYTES_core1;
    }

    traceEVENT_GROUP_SYNC_END_core1( xEventGroup_core1, uxBitsToSet_core1, uxBitsToWaitFor_core1, xTimeoutOccurred_core1 );

    /* Prevent compiler warnings when trace macros are not used. */
    ( void ) xTimeoutOccurred_core1;

    return uxReturn_core1;
}
/*-----------------------------------------------------------*/

EventBits_t_core1 xEventGroupWaitBits_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                 const EventBits_t_core1 uxBitsToWaitFor_core1,
                                 const BaseType_t_core1 xClearOnExit_core1,
                                 const BaseType_t_core1 xWaitForAllBits_core1,
                                 TickType_t_core1 xTicksToWait_core1 )
{
    EventGroup_t_core1 * pxEventBits_core1 = xEventGroup_core1;
    EventBits_t_core1 uxReturn_core1, uxControlBits_core1 = 0;
    BaseType_t_core1 xWaitConditionMet_core1, xAlreadyYielded_core1;
    BaseType_t_core1 xTimeoutOccurred_core1 = pdFALSE_core1;

    /* Check the user is not attempting to wait on the bits used by the kernel
     * itself, and that at least one bit is being requested. */
    configASSERT_core1( xEventGroup_core1 );
    configASSERT_core1( ( uxBitsToWaitFor_core1 & eventEVENT_BITS_CONTROL_BYTES_core1 ) == 0 );
    configASSERT_core1( uxBitsToWaitFor_core1 != 0 );
    #if ( ( INCLUDE_xTaskGetSchedulerState_core1 == 1 ) || ( configUSE_TIMERS_core1 == 1 ) )
    {
        configASSERT_core1( !( ( xTaskGetSchedulerState_core1() == taskSCHEDULER_SUSPENDED_core1 ) && ( xTicksToWait_core1 != 0 ) ) );
    }
    #endif

    vTaskSuspendAll_core1();
    {
        const EventBits_t_core1 uxCurrentEventBits = pxEventBits_core1->uxEventBits_core1;

        /* Check to see if the wait condition is already met or not. */
        xWaitConditionMet_core1 = prvTestWaitCondition_core1( uxCurrentEventBits, uxBitsToWaitFor_core1, xWaitForAllBits_core1 );

        if( xWaitConditionMet_core1 != pdFALSE_core1 )
        {
            /* The wait condition has already been met so there is no need to
             * block. */
            uxReturn_core1 = uxCurrentEventBits;
            xTicksToWait_core1 = ( TickType_t_core1 ) 0;

            /* Clear the wait bits if requested to do so. */
            if( xClearOnExit_core1 != pdFALSE_core1 )
            {
                pxEventBits_core1->uxEventBits_core1 &= ~uxBitsToWaitFor_core1;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core1();
            }
        }
        else if( xTicksToWait_core1 == ( TickType_t_core1 ) 0 )
        {
            /* The wait condition has not been met, but no block time was
             * specified, so just return the current value. */
            uxReturn_core1 = uxCurrentEventBits;
            xTimeoutOccurred_core1 = pdTRUE_core1;
        }
        else
        {
            /* The task_core1 is going to block to wait for its required bits to be
             * set.  uxControlBits_core1 are used to remember the specified behaviour of
             * this call to xEventGroupWaitBits_core1() - for use when the event bits
             * unblock the task_core1. */
            if( xClearOnExit_core1 != pdFALSE_core1 )
            {
                uxControlBits_core1 |= eventCLEAR_EVENTS_ON_EXIT_BIT_core1;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core1();
            }

            if( xWaitForAllBits_core1 != pdFALSE_core1 )
            {
                uxControlBits_core1 |= eventWAIT_FOR_ALL_BITS_core1;
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core1();
            }

            /* Store the bits that the calling task_core1 is waiting for in the
             * task_core1's event list item so the kernel knows when a match is
             * found.  Then enter the blocked state. */
            vTaskPlaceOnUnorderedEventList_core1( &( pxEventBits_core1->xTasksWaitingForBits_core1 ), ( uxBitsToWaitFor_core1 | uxControlBits_core1 ), xTicksToWait_core1 );

            /* This is obsolete as it will get set after the task_core1 unblocks, but
             * some compilers mistakenly generate a warning about the variable
             * being returned without being set if it is not done. */
            uxReturn_core1 = 0;

            traceEVENT_GROUP_WAIT_BITS_BLOCK_core1( xEventGroup_core1, uxBitsToWaitFor_core1 );
        }
    }
    xAlreadyYielded_core1 = xTaskResumeAll_core1();

    if( xTicksToWait_core1 != ( TickType_t_core1 ) 0 )
    {
        if( xAlreadyYielded_core1 == pdFALSE_core1 )
        {
            portYIELD_WITHIN_API_core1();
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }

        /* The task_core1 blocked to wait for its required bits to be set - at this
         * point either the required bits were set or the block time expired.  If
         * the required bits were set they will have been stored in the task_core1's
         * event list item, and they should now be retrieved then cleared. */
        uxReturn_core1 = uxTaskResetEventItemValue_core1();

        if( ( uxReturn_core1 & eventUNBLOCKED_DUE_TO_BIT_SET_core1 ) == ( EventBits_t_core1 ) 0 )
        {
            taskENTER_CRITICAL_core1();
            {
                /* The task_core1 timed out, just return the current event bit value. */
                uxReturn_core1 = pxEventBits_core1->uxEventBits_core1;

                /* It is possible that the event bits were updated between this
                 * task_core1 leaving the Blocked state and running again. */
                if( prvTestWaitCondition_core1( uxReturn_core1, uxBitsToWaitFor_core1, xWaitForAllBits_core1 ) != pdFALSE_core1 )
                {
                    if( xClearOnExit_core1 != pdFALSE_core1 )
                    {
                        pxEventBits_core1->uxEventBits_core1 &= ~uxBitsToWaitFor_core1;
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

                xTimeoutOccurred_core1 = pdTRUE_core1;
            }
            taskEXIT_CRITICAL_core1();
        }
        else
        {
            /* The task_core1 unblocked because the bits were set. */
        }

        /* The task_core1 blocked so control bits may have been set. */
        uxReturn_core1 &= ~eventEVENT_BITS_CONTROL_BYTES_core1;
    }

    traceEVENT_GROUP_WAIT_BITS_END_core1( xEventGroup_core1, uxBitsToWaitFor_core1, xTimeoutOccurred_core1 );

    /* Prevent compiler warnings when trace macros are not used. */
    ( void ) xTimeoutOccurred_core1;

    return uxReturn_core1;
}
/*-----------------------------------------------------------*/

EventBits_t_core1 xEventGroupClearBits_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                  const EventBits_t_core1 uxBitsToClear_core1 )
{
    EventGroup_t_core1 * pxEventBits_core1 = xEventGroup_core1;
    EventBits_t_core1 uxReturn_core1;

    /* Check the user is not attempting to clear the bits used by the kernel
     * itself. */
    configASSERT_core1( xEventGroup_core1 );
    configASSERT_core1( ( uxBitsToClear_core1 & eventEVENT_BITS_CONTROL_BYTES_core1 ) == 0 );

    taskENTER_CRITICAL_core1();
    {
        traceEVENT_GROUP_CLEAR_BITS_core1( xEventGroup_core1, uxBitsToClear_core1 );

        /* The value returned is the event group value prior to the bits being
         * cleared. */
        uxReturn_core1 = pxEventBits_core1->uxEventBits_core1;

        /* Clear the bits. */
        pxEventBits_core1->uxEventBits_core1 &= ~uxBitsToClear_core1;
    }
    taskEXIT_CRITICAL_core1();

    return uxReturn_core1;
}
/*-----------------------------------------------------------*/

#if ( ( configUSE_TRACE_FACILITY_core1 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core1 == 1 ) && ( configUSE_TIMERS_core1 == 1 ) )

    BaseType_t_core1 xEventGroupClearBitsFromISR_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                            const EventBits_t_core1 uxBitsToClear_core1 )
    {
        BaseType_t_core1 xReturn_core1;

        traceEVENT_GROUP_CLEAR_BITS_FROM_ISR_core1( xEventGroup_core1, uxBitsToClear_core1 );
        xReturn_core1 = xTimerPendFunctionCallFromISR_core1( vEventGroupClearBitsCallback_core1, ( void * ) xEventGroup_core1, ( uint32_t ) uxBitsToClear_core1, NULL ); /*lint !e9087 Can't avoid cast to void* as a generic callback function not specific to this use case. Callback casts back to original type so safe. */

        return xReturn_core1;
    }

#endif /* if ( ( configUSE_TRACE_FACILITY_core1 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core1 == 1 ) && ( configUSE_TIMERS_core1 == 1 ) ) */
/*-----------------------------------------------------------*/

EventBits_t_core1 xEventGroupGetBitsFromISR_core1( EventGroupHandle_t_core1 xEventGroup_core1 )
{
    UBaseType_t_core1 uxSavedInterruptStatus_core1;
    EventGroup_t_core1 const * const pxEventBits_core1 = xEventGroup_core1;
    EventBits_t_core1 uxReturn_core1;

    uxSavedInterruptStatus_core1 = portSET_INTERRUPT_MASK_FROM_ISR_core1();
    {
        uxReturn_core1 = pxEventBits_core1->uxEventBits_core1;
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core1( uxSavedInterruptStatus_core1 );

    return uxReturn_core1;
} /*lint !e818 EventGroupHandle_t_core1 is a typedef used in other functions to so can't be pointer to const. */
/*-----------------------------------------------------------*/

EventBits_t_core1 xEventGroupSetBits_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                const EventBits_t_core1 uxBitsToSet_core1 )
{
    ListItem_t_core1 * pxListItem_core1;
    ListItem_t_core1 * pxNext_core1;
    ListItem_t_core1 const * pxListEnd_core1;
    List_t_core1 const * pxList_core1;
    EventBits_t_core1 uxBitsToClear_core1 = 0, uxBitsWaitedFor_core1, uxControlBits_core1;
    EventGroup_t_core1 * pxEventBits_core1 = xEventGroup_core1;
    BaseType_t_core1 xMatchFound = pdFALSE_core1;

    /* Check the user is not attempting to set the bits used by the kernel
     * itself. */
    configASSERT_core1( xEventGroup_core1 );
    configASSERT_core1( ( uxBitsToSet_core1 & eventEVENT_BITS_CONTROL_BYTES_core1 ) == 0 );

    pxList_core1 = &( pxEventBits_core1->xTasksWaitingForBits_core1 );
    pxListEnd_core1 = listGET_END_MARKER_core1( pxList_core1 ); /*lint !e826 !e740 !e9087 The mini list structure is used as the list end to save RAM.  This is checked and valid. */
    vTaskSuspendAll_core1();
    {
        traceEVENT_GROUP_SET_BITS_core1( xEventGroup_core1, uxBitsToSet_core1 );

        pxListItem_core1 = listGET_HEAD_ENTRY_core1( pxList_core1 );

        /* Set the bits. */
        pxEventBits_core1->uxEventBits_core1 |= uxBitsToSet_core1;

        /* See if the new bit value should unblock any tasks. */
        while( pxListItem_core1 != pxListEnd_core1 )
        {
            pxNext_core1 = listGET_NEXT_core1( pxListItem_core1 );
            uxBitsWaitedFor_core1 = listGET_LIST_ITEM_VALUE_core1( pxListItem_core1 );
            xMatchFound = pdFALSE_core1;

            /* Split the bits waited for from the control bits. */
            uxControlBits_core1 = uxBitsWaitedFor_core1 & eventEVENT_BITS_CONTROL_BYTES_core1;
            uxBitsWaitedFor_core1 &= ~eventEVENT_BITS_CONTROL_BYTES_core1;

            if( ( uxControlBits_core1 & eventWAIT_FOR_ALL_BITS_core1 ) == ( EventBits_t_core1 ) 0 )
            {
                /* Just looking for single bit being set. */
                if( ( uxBitsWaitedFor_core1 & pxEventBits_core1->uxEventBits_core1 ) != ( EventBits_t_core1 ) 0 )
                {
                    xMatchFound = pdTRUE_core1;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core1();
                }
            }
            else if( ( uxBitsWaitedFor_core1 & pxEventBits_core1->uxEventBits_core1 ) == uxBitsWaitedFor_core1 )
            {
                /* All bits are set. */
                xMatchFound = pdTRUE_core1;
            }
            else
            {
                /* Need all bits to be set, but not all the bits were set. */
            }

            if( xMatchFound != pdFALSE_core1 )
            {
                /* The bits match.  Should the bits be cleared on exit? */
                if( ( uxControlBits_core1 & eventCLEAR_EVENTS_ON_EXIT_BIT_core1 ) != ( EventBits_t_core1 ) 0 )
                {
                    uxBitsToClear_core1 |= uxBitsWaitedFor_core1;
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER_core1();
                }

                /* Store the actual event flag value in the task_core1's event list
                 * item before removing the task_core1 from the event list.  The
                 * eventUNBLOCKED_DUE_TO_BIT_SET_core1 bit is set so the task_core1 knows
                 * that is was unblocked due to its required bits matching, rather
                 * than because it timed out. */
                vTaskRemoveFromUnorderedEventList_core1( pxListItem_core1, pxEventBits_core1->uxEventBits_core1 | eventUNBLOCKED_DUE_TO_BIT_SET_core1 );
            }

            /* Move onto the next list item.  Note pxListItem_core1->pxNext_core1 is not
             * used here as the list item may have been removed from the event list
             * and inserted into the ready/pending reading list. */
            pxListItem_core1 = pxNext_core1;
        }

        /* Clear any bits that matched when the eventCLEAR_EVENTS_ON_EXIT_BIT_core1
         * bit was set in the control word. */
        pxEventBits_core1->uxEventBits_core1 &= ~uxBitsToClear_core1;
    }
    ( void ) xTaskResumeAll_core1();

    return pxEventBits_core1->uxEventBits_core1;
}
/*-----------------------------------------------------------*/

void vEventGroupDelete_core1( EventGroupHandle_t_core1 xEventGroup_core1 )
{
    EventGroup_t_core1 * pxEventBits_core1 = xEventGroup_core1;
    const List_t_core1 * pxTasksWaitingForBits;

    configASSERT_core1( pxEventBits_core1 );

    pxTasksWaitingForBits = &( pxEventBits_core1->xTasksWaitingForBits_core1 );

    vTaskSuspendAll_core1();
    {
        traceEVENT_GROUP_DELETE_core1( xEventGroup_core1 );

        while( listCURRENT_LIST_LENGTH_core1( pxTasksWaitingForBits ) > ( UBaseType_t_core1 ) 0 )
        {
            /* Unblock the task_core1, returning 0 as the event list is being deleted
             * and cannot therefore have any bits set. */
            configASSERT_core1( pxTasksWaitingForBits->xListEnd_core1.pxNext_core1 != ( const ListItem_t_core1 * ) &( pxTasksWaitingForBits->xListEnd_core1 ) );
            vTaskRemoveFromUnorderedEventList_core1( pxTasksWaitingForBits->xListEnd_core1.pxNext_core1, eventUNBLOCKED_DUE_TO_BIT_SET_core1 );
        }
    }
    ( void ) xTaskResumeAll_core1();

    #if ( ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core1 == 0 ) )
    {
        /* The event group can only have been allocated dynamically - free
         * it again. */
        vPortFree_core1( pxEventBits_core1 );
    }
    #elif ( ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 ) && ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 ) )
    {
        /* The event group could have been allocated statically or
         * dynamically, so check before attempting to free the memory. */
        if( pxEventBits_core1->ucStaticallyAllocated_core1 == ( uint8_t ) pdFALSE_core1 )
        {
            vPortFree_core1( pxEventBits_core1 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    #endif /* configSUPPORT_DYNAMIC_ALLOCATION_core1 */
}
/*-----------------------------------------------------------*/

/* For internal use only - execute a 'set bits' command that was pended from
 * an interrupt. */
void vEventGroupSetBitsCallback_core1( void * pvEventGroup_core1,
                                 const uint32_t ulBitsToSet_core1 )
{
    ( void ) xEventGroupSetBits_core1( pvEventGroup_core1, ( EventBits_t_core1 ) ulBitsToSet_core1 ); /*lint !e9079 Can't avoid cast to void* as a generic timer callback prototype. Callback casts back to original type so safe. */
}
/*-----------------------------------------------------------*/

/* For internal use only - execute a 'clear bits' command that was pended from
 * an interrupt. */
void vEventGroupClearBitsCallback_core1( void * pvEventGroup_core1,
                                   const uint32_t ulBitsToClear_core1 )
{
    ( void ) xEventGroupClearBits_core1( pvEventGroup_core1, ( EventBits_t_core1 ) ulBitsToClear_core1 ); /*lint !e9079 Can't avoid cast to void* as a generic timer callback prototype. Callback casts back to original type so safe. */
}
/*-----------------------------------------------------------*/

static BaseType_t_core1 prvTestWaitCondition_core1( const EventBits_t_core1 uxCurrentEventBits,
                                        const EventBits_t_core1 uxBitsToWaitFor_core1,
                                        const BaseType_t_core1 xWaitForAllBits_core1 )
{
    BaseType_t_core1 xWaitConditionMet_core1 = pdFALSE_core1;

    if( xWaitForAllBits_core1 == pdFALSE_core1 )
    {
        /* Task only has to wait for one bit within uxBitsToWaitFor_core1 to be
         * set.  Is one already set? */
        if( ( uxCurrentEventBits & uxBitsToWaitFor_core1 ) != ( EventBits_t_core1 ) 0 )
        {
            xWaitConditionMet_core1 = pdTRUE_core1;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    else
    {
        /* Task has to wait for all the bits in uxBitsToWaitFor_core1 to be set.
         * Are they set already? */
        if( ( uxCurrentEventBits & uxBitsToWaitFor_core1 ) == uxBitsToWaitFor_core1 )
        {
            xWaitConditionMet_core1 = pdTRUE_core1;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }

    return xWaitConditionMet_core1;
}
/*-----------------------------------------------------------*/

#if ( ( configUSE_TRACE_FACILITY_core1 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core1 == 1 ) && ( configUSE_TIMERS_core1 == 1 ) )

    BaseType_t_core1 xEventGroupSetBitsFromISR_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                          const EventBits_t_core1 uxBitsToSet_core1,
                                          BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 )
    {
        BaseType_t_core1 xReturn_core1;

        traceEVENT_GROUP_SET_BITS_FROM_ISR_core1( xEventGroup_core1, uxBitsToSet_core1 );
        xReturn_core1 = xTimerPendFunctionCallFromISR_core1( vEventGroupSetBitsCallback_core1, ( void * ) xEventGroup_core1, ( uint32_t ) uxBitsToSet_core1, pxHigherPriorityTaskWoken_core1 ); /*lint !e9087 Can't avoid cast to void* as a generic callback function not specific to this use case. Callback casts back to original type so safe. */

        return xReturn_core1;
    }

#endif /* if ( ( configUSE_TRACE_FACILITY_core1 == 1 ) && ( INCLUDE_xTimerPendFunctionCall_core1 == 1 ) && ( configUSE_TIMERS_core1 == 1 ) ) */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core1 == 1 )

    UBaseType_t_core1 uxEventGroupGetNumber_core1( void * xEventGroup_core1 )
    {
        UBaseType_t_core1 xReturn_core1;
        EventGroup_t_core1 const * pxEventBits_core1 = ( EventGroup_t_core1 * ) xEventGroup_core1; /*lint !e9087 !e9079 EventGroupHandle_t_core1 is a pointer to an EventGroup_t_core1, but EventGroupHandle_t_core1 is kept opaque outside of this file for data hiding purposes. */

        if( xEventGroup_core1 == NULL )
        {
            xReturn_core1 = 0;
        }
        else
        {
            xReturn_core1 = pxEventBits_core1->uxEventGroupNumber_core1;
        }

        return xReturn_core1;
    }

#endif /* configUSE_TRACE_FACILITY_core1 */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core1 == 1 )

    void vEventGroupSetNumber_core1( void * xEventGroup_core1,
                               UBaseType_t_core1 uxEventGroupNumber_core1 )
    {
        ( ( EventGroup_t_core1 * ) xEventGroup_core1 )->uxEventGroupNumber_core1 = uxEventGroupNumber_core1; /*lint !e9087 !e9079 EventGroupHandle_t_core1 is a pointer to an EventGroup_t_core1, but EventGroupHandle_t_core1 is kept opaque outside of this file for data hiding purposes. */
    }

#endif /* configUSE_TRACE_FACILITY_core1 */
/*-----------------------------------------------------------*/
