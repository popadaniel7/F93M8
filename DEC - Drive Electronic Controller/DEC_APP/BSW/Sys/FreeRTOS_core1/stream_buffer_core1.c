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
#include <stdint.h>
#include <string.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 prevents task_core1.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core1.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1

/* FreeRTOS_core1 includes. */
#include "FreeRTOS_core1.h"
#include "task_core1.h"
#include "stream_buffer_core1.h"

#if ( configUSE_TASK_NOTIFICATIONS_core1 != 1 )
    #error configUSE_TASK_NOTIFICATIONS_core1 must be set to 1 to build stream_buffer_core1.c
#endif

#if ( INCLUDE_xTaskGetCurrentTaskHandle_core1 != 1 )
    #error INCLUDE_xTaskGetCurrentTaskHandle_core1 must be set to 1 to build stream_buffer_core1.c
#endif

/* Lint e961, e9021 and e750 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 to be defined
 * for the header files above, but not in this file, in order to generate the
 * correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core1 /*lint !e961 !e750 !e9021. */

/* If the user has not provided application specific Rx notification macros,
 * or #defined the notification macros away, then provide default implementations
 * that uses task_core1 notifications. */
/*lint -save -e9026 Function like macros allowed and needed here so they can be overridden. */
#ifndef sbRECEIVE_COMPLETED_core1
    #define sbRECEIVE_COMPLETED_core1( pxStreamBuffer_core1 )                         \
    vTaskSuspendAll_core1();                                                    \
    {                                                                     \
        if( ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1 != NULL )              \
        {                                                                 \
            ( void ) xTaskNotify_core1( ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1, \
                                  ( uint32_t ) 0,                         \
                                  eNoAction_core1 );                            \
            ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1 = NULL;                \
        }                                                                 \
    }                                                                     \
    ( void ) xTaskResumeAll_core1();
#endif /* sbRECEIVE_COMPLETED_core1 */

/* If user has provided a per-instance receive complete callback, then
 * invoke the callback else use the receive complete macro which is provided by default for all instances.
 */
#if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
    #define prvRECEIVE_COMPLETED_core1( pxStreamBuffer_core1 )                                               \
    {                                                                                            \
        if( ( pxStreamBuffer_core1 )->pxReceiveCompletedCallback_core1 != NULL )                             \
        {                                                                                        \
            ( pxStreamBuffer_core1 )->pxReceiveCompletedCallback_core1( ( pxStreamBuffer_core1 ), pdFALSE_core1, NULL ); \
        }                                                                                        \
        else                                                                                     \
        {                                                                                        \
            sbRECEIVE_COMPLETED_core1( ( pxStreamBuffer_core1 ) );                                           \
        }                                                                                        \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */
    #define prvRECEIVE_COMPLETED_core1( pxStreamBuffer_core1 )    sbRECEIVE_COMPLETED_core1( ( pxStreamBuffer_core1 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */

#ifndef sbRECEIVE_COMPLETED_FROM_ISR_core1
    #define sbRECEIVE_COMPLETED_FROM_ISR_core1( pxStreamBuffer_core1,                            \
                                          pxHigherPriorityTaskWoken_core1 )                \
    {                                                                                \
        UBaseType_t_core1 uxSavedInterruptStatus_core1;                                          \
                                                                                     \
        uxSavedInterruptStatus_core1 = ( UBaseType_t_core1 ) portSET_INTERRUPT_MASK_FROM_ISR_core1();  \
        {                                                                            \
            if( ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1 != NULL )                     \
            {                                                                        \
                ( void ) xTaskNotifyFromISR_core1( ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1, \
                                             ( uint32_t ) 0,                         \
                                             eNoAction_core1,                              \
                                             ( pxHigherPriorityTaskWoken_core1 ) );        \
                ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1 = NULL;                       \
            }                                                                        \
        }                                                                            \
        portCLEAR_INTERRUPT_MASK_FROM_ISR_core1( uxSavedInterruptStatus_core1 );                 \
    }
#endif /* sbRECEIVE_COMPLETED_FROM_ISR_core1 */

#if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
    #define prvRECEIVE_COMPLETED_FROM_ISR_core1( pxStreamBuffer_core1,                                                               \
                                           pxHigherPriorityTaskWoken_core1 )                                                   \
    {                                                                                                                    \
        if( ( pxStreamBuffer_core1 )->pxReceiveCompletedCallback_core1 != NULL )                                                     \
        {                                                                                                                \
            ( pxStreamBuffer_core1 )->pxReceiveCompletedCallback_core1( ( pxStreamBuffer_core1 ), pdTRUE_core1, ( pxHigherPriorityTaskWoken_core1 ) ); \
        }                                                                                                                \
        else                                                                                                             \
        {                                                                                                                \
            sbRECEIVE_COMPLETED_FROM_ISR_core1( ( pxStreamBuffer_core1 ), ( pxHigherPriorityTaskWoken_core1 ) );                           \
        }                                                                                                                \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */
    #define prvRECEIVE_COMPLETED_FROM_ISR_core1( pxStreamBuffer_core1, pxHigherPriorityTaskWoken_core1 ) \
    sbRECEIVE_COMPLETED_FROM_ISR_core1( ( pxStreamBuffer_core1 ), ( pxHigherPriorityTaskWoken_core1 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */

/* If the user has not provided an application specific Tx notification macro,
 * or #defined the notification macro away, then provide a default
 * implementation that uses task_core1 notifications.
 */
#ifndef sbSEND_COMPLETED_core1
    #define sbSEND_COMPLETED_core1( pxStreamBuffer_core1 )                               \
    vTaskSuspendAll_core1();                                                       \
    {                                                                        \
        if( ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1 != NULL )              \
        {                                                                    \
            ( void ) xTaskNotify_core1( ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1, \
                                  ( uint32_t ) 0,                            \
                                  eNoAction_core1 );                               \
            ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1 = NULL;                \
        }                                                                    \
    }                                                                        \
    ( void ) xTaskResumeAll_core1();
#endif /* sbSEND_COMPLETED_core1 */

/* If user has provided a per-instance send completed callback, then
 * invoke the callback else use the send complete macro which is provided by default for all instances.
 */
#if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
    #define prvSEND_COMPLETED_core1( pxStreamBuffer_core1 )                                           \
    {                                                                                     \
        if( ( pxStreamBuffer_core1 )->pxSendCompletedCallback_core1 != NULL )                         \
        {                                                                                 \
            pxStreamBuffer_core1->pxSendCompletedCallback_core1( ( pxStreamBuffer_core1 ), pdFALSE_core1, NULL ); \
        }                                                                                 \
        else                                                                              \
        {                                                                                 \
            sbSEND_COMPLETED_core1( ( pxStreamBuffer_core1 ) );                                       \
        }                                                                                 \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */
    #define prvSEND_COMPLETED_core1( pxStreamBuffer_core1 )    sbSEND_COMPLETED_core1( ( pxStreamBuffer_core1 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */


#ifndef sbSEND_COMPLETE_FROM_ISR_core1
    #define sbSEND_COMPLETE_FROM_ISR_core1( pxStreamBuffer_core1, pxHigherPriorityTaskWoken_core1 )       \
    {                                                                                   \
        UBaseType_t_core1 uxSavedInterruptStatus_core1;                                             \
                                                                                        \
        uxSavedInterruptStatus_core1 = ( UBaseType_t_core1 ) portSET_INTERRUPT_MASK_FROM_ISR_core1();     \
        {                                                                               \
            if( ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1 != NULL )                     \
            {                                                                           \
                ( void ) xTaskNotifyFromISR_core1( ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1, \
                                             ( uint32_t ) 0,                            \
                                             eNoAction_core1,                                 \
                                             ( pxHigherPriorityTaskWoken_core1 ) );           \
                ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1 = NULL;                       \
            }                                                                           \
        }                                                                               \
        portCLEAR_INTERRUPT_MASK_FROM_ISR_core1( uxSavedInterruptStatus_core1 );                    \
    }
#endif /* sbSEND_COMPLETE_FROM_ISR_core1 */


#if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
    #define prvSEND_COMPLETE_FROM_ISR_core1( pxStreamBuffer_core1, pxHigherPriorityTaskWoken_core1 )                                    \
    {                                                                                                                 \
        if( ( pxStreamBuffer_core1 )->pxSendCompletedCallback_core1 != NULL )                                                     \
        {                                                                                                             \
            ( pxStreamBuffer_core1 )->pxSendCompletedCallback_core1( ( pxStreamBuffer_core1 ), pdTRUE_core1, ( pxHigherPriorityTaskWoken_core1 ) ); \
        }                                                                                                             \
        else                                                                                                          \
        {                                                                                                             \
            sbSEND_COMPLETE_FROM_ISR_core1( ( pxStreamBuffer_core1 ), ( pxHigherPriorityTaskWoken_core1 ) );                            \
        }                                                                                                             \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */
    #define prvSEND_COMPLETE_FROM_ISR_core1( pxStreamBuffer_core1, pxHigherPriorityTaskWoken_core1 ) \
    sbSEND_COMPLETE_FROM_ISR_core1( ( pxStreamBuffer_core1 ), ( pxHigherPriorityTaskWoken_core1 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 ) */

/*lint -restore (9026) */

/* The number of bytes used to hold the length of a message in the buffer. */
#define sbBYTES_TO_STORE_MESSAGE_LENGTH_core1    ( sizeof( configMESSAGE_BUFFER_LENGTH_TYPE_core1 ) )

/* Bits stored in the ucFlags_core1 field of the stream buffer. */
#define sbFLAGS_IS_MESSAGE_BUFFER_core1          ( ( uint8_t ) 1 ) /* Set if the stream buffer was created as a message buffer, in which case it holds discrete messages rather than a stream. */
#define sbFLAGS_IS_STATICALLY_ALLOCATED_core1    ( ( uint8_t ) 2 ) /* Set if the stream buffer was created using statically allocated memory. */

/*-----------------------------------------------------------*/

/* Structure that hold state information on the buffer. */
typedef struct StreamBufferDef_t_core1                 /*lint !e9058 Style convention uses tag. */
{
    volatile size_t xTail_core1;                       /* Index to the next item to read within the buffer. */
    volatile size_t xHead_core1;                       /* Index to the next item to write within the buffer. */
    size_t xLength_core1;                              /* The length of the buffer pointed to by pucBuffer_core1. */
    size_t xTriggerLevelBytes_core1;                   /* The number of bytes that must be in the stream buffer before a task_core1 that is waiting for data is unblocked. */
    volatile TaskHandle_t_core1 xTaskWaitingToReceive_core1; /* Holds the handle of a task_core1 waiting for data, or NULL if no tasks are waiting. */
    volatile TaskHandle_t_core1 xTaskWaitingToSend_core1;    /* Holds the handle of a task_core1 waiting to send data to a message buffer that is full. */
    uint8_t * pucBuffer_core1;                         /* Points to the buffer itself - that is - the RAM that stores the data passed through the buffer. */
    uint8_t ucFlags_core1;

    #if ( configUSE_TRACE_FACILITY_core1 == 1 )
        UBaseType_t_core1 uxStreamBufferNumber_core1; /* Used for tracing purposes. */
    #endif

    #if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
        StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1;    /* Optional callback called on send complete. sbSEND_COMPLETED_core1 is called if this is NULL. */
        StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1; /* Optional callback called on receive complete.  sbRECEIVE_COMPLETED_core1 is called if this is NULL. */
    #endif
} StreamBuffer_t_core1;

/*
 * The number of bytes available to be read from the buffer.
 */
static size_t prvBytesInBuffer_core1( const StreamBuffer_t_core1 * const pxStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Add xCount_core1 bytes from pucData_core1 into the pxStreamBuffer_core1's data storage area.
 * This function does not update the buffer's xHead_core1 pointer, so multiple writes
 * may be chained together "atomically". This is useful for Message Buffers where
 * the length and data bytes are written in two separate chunks, and we don't want
 * the reader to see the buffer as having grown until after all data is copied over.
 * This function takes a custom xHead_core1 value to indicate where to write to (necessary
 * for chaining) and returns the the resulting xHead_core1 position.
 * To mark the write as complete, manually set the buffer's xHead_core1 field with the
 * returned xHead_core1 from this function.
 */
static size_t prvWriteBytesToBuffer_core1( StreamBuffer_t_core1 * const pxStreamBuffer_core1,
                                     const uint8_t * pucData_core1,
                                     size_t xCount_core1,
                                     size_t xHead_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * If the stream buffer is being used as a message buffer, then reads an entire
 * message out of the buffer.  If the stream buffer is being used as a stream
 * buffer then read as many bytes as possible from the buffer.
 * prvReadBytesFromBuffer_core1() is called to actually extract the bytes from the
 * buffer's data storage area.
 */
static size_t prvReadMessageFromBuffer_core1( StreamBuffer_t_core1 * pxStreamBuffer_core1,
                                        void * pvRxData_core1,
                                        size_t xBufferLengthBytes_core1,
                                        size_t xBytesAvailable_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * If the stream buffer is being used as a message buffer, then writes an entire
 * message to the buffer.  If the stream buffer is being used as a stream
 * buffer then write as many bytes as possible to the buffer.
 * prvWriteBytestoBuffer() is called to actually send the bytes to the buffer's
 * data storage area.
 */
static size_t prvWriteMessageToBuffer_core1( StreamBuffer_t_core1 * const pxStreamBuffer_core1,
                                       const void * pvTxData_core1,
                                       size_t xDataLengthBytes_core1,
                                       size_t xSpace_core1,
                                       size_t xRequiredSpace_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Copies xCount_core1 bytes from the pxStreamBuffer_core1's data storage area to pucData_core1.
 * This function does not update the buffer's xTail_core1 pointer, so multiple reads
 * may be chained together "atomically". This is useful for Message Buffers where
 * the length and data bytes are read in two separate chunks, and we don't want
 * the writer to see the buffer as having more free space until after all data is
 * copied over, especially if we have to abort the read due to insufficient receiving space.
 * This function takes a custom xTail_core1 value to indicate where to read from (necessary
 * for chaining) and returns the the resulting xTail_core1 position.
 * To mark the read as complete, manually set the buffer's xTail_core1 field with the
 * returned xTail_core1 from this function.
 */
static size_t prvReadBytesFromBuffer_core1( StreamBuffer_t_core1 * pxStreamBuffer_core1,
                                      uint8_t * pucData_core1,
                                      size_t xCount_core1,
                                      size_t xTail_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Called by both pxStreamBufferCreate() and pxStreamBufferCreateStatic() to
 * initialise the members of the newly created stream buffer structure.
 */
static void prvInitialiseNewStreamBuffer_core1( StreamBuffer_t_core1 * const pxStreamBuffer_core1,
                                          uint8_t * const pucBuffer_core1,
                                          size_t xBufferSizeBytes_core1,
                                          size_t xTriggerLevelBytes_core1,
                                          uint8_t ucFlags_core1,
                                          StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                          StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 ) PRIVILEGED_FUNCTION_core1;

/*-----------------------------------------------------------*/
#if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )
    StreamBufferHandle_t_core1 xStreamBufferGenericCreate_core1( size_t xBufferSizeBytes_core1,
                                                     size_t xTriggerLevelBytes_core1,
                                                     BaseType_t_core1 xIsMessageBuffer_core1,
                                                     StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                                     StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 )
    {
        uint8_t * pucAllocatedMemory_core1;
        uint8_t ucFlags_core1;

        /* In case the stream buffer is going to be used as a message buffer
         * (that is, it will hold discrete messages with a little meta data that
         * says how big the next message is) check the buffer will be large enough
         * to hold at least one message. */
        if( xIsMessageBuffer_core1 == pdTRUE_core1 )
        {
            /* Is a message buffer but not statically allocated. */
            ucFlags_core1 = sbFLAGS_IS_MESSAGE_BUFFER_core1;
            configASSERT_core1( xBufferSizeBytes_core1 > sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 );
        }
        else
        {
            /* Not a message buffer and not statically allocated. */
            ucFlags_core1 = 0;
            configASSERT_core1( xBufferSizeBytes_core1 > 0 );
        }

        configASSERT_core1( xTriggerLevelBytes_core1 <= xBufferSizeBytes_core1 );

        /* A trigger level of 0 would cause a waiting task_core1 to unblock even when
         * the buffer was empty. */
        if( xTriggerLevelBytes_core1 == ( size_t ) 0 )
        {
            xTriggerLevelBytes_core1 = ( size_t ) 1;
        }

        /* A stream buffer requires a StreamBuffer_t_core1 structure and a buffer.
         * Both are allocated in a single call to pvPortMalloc_core1().  The
         * StreamBuffer_t_core1 structure is placed at the start of the allocated memory
         * and the buffer follows immediately after.  The requested size is
         * incremented so the free space is returned as the user would expect -
         * this is a quirk of the implementation that means otherwise the free
         * space would be reported as one byte smaller than would be logically
         * expected. */
        if( xBufferSizeBytes_core1 < ( xBufferSizeBytes_core1 + 1 + sizeof( StreamBuffer_t_core1 ) ) )
        {
            xBufferSizeBytes_core1++;
            pucAllocatedMemory_core1 = ( uint8_t * ) pvPortMalloc_core1( xBufferSizeBytes_core1 + sizeof( StreamBuffer_t_core1 ) ); /*lint !e9079 malloc() only returns void*. */
        }
        else
        {
            pucAllocatedMemory_core1 = NULL;
        }

        if( pucAllocatedMemory_core1 != NULL )
        {
            prvInitialiseNewStreamBuffer_core1( ( StreamBuffer_t_core1 * ) pucAllocatedMemory_core1,       /* Structure at the start of the allocated memory. */ /*lint !e9087 Safe cast as allocated memory is aligned. */ /*lint !e826 Area is not too small and alignment is guaranteed provided malloc() behaves as expected and returns aligned buffer. */
                                          pucAllocatedMemory_core1 + sizeof( StreamBuffer_t_core1 ), /* Storage area follows. */ /*lint !e9016 Indexing past structure valid for uint8_t pointer, also storage area has no alignment requirement. */
                                          xBufferSizeBytes_core1,
                                          xTriggerLevelBytes_core1,
                                          ucFlags_core1,
                                          pxSendCompletedCallback_core1,
                                          pxReceiveCompletedCallback_core1 );

            traceSTREAM_BUFFER_CREATE_core1( ( ( StreamBuffer_t_core1 * ) pucAllocatedMemory_core1 ), xIsMessageBuffer_core1 );
        }
        else
        {
            traceSTREAM_BUFFER_CREATE_FAILED_core1( xIsMessageBuffer_core1 );
        }

        return ( StreamBufferHandle_t_core1 ) pucAllocatedMemory_core1; /*lint !e9087 !e826 Safe cast as allocated memory is aligned. */
    }
#endif /* configSUPPORT_DYNAMIC_ALLOCATION_core1 */
/*-----------------------------------------------------------*/

#if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )

    StreamBufferHandle_t_core1 xStreamBufferGenericCreateStatic_core1( size_t xBufferSizeBytes_core1,
                                                           size_t xTriggerLevelBytes_core1,
                                                           BaseType_t_core1 xIsMessageBuffer_core1,
                                                           uint8_t * const pucStreamBufferStorageArea_core1,
                                                           StaticStreamBuffer_t_core1 * const pxStaticStreamBuffer_core1,
                                                           StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                                           StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 )
    {
        StreamBuffer_t_core1 * const pxStreamBuffer_core1 = ( StreamBuffer_t_core1 * ) pxStaticStreamBuffer_core1; /*lint !e740 !e9087 Safe cast as StaticStreamBuffer_t_core1 is opaque Streambuffer_t. */
        StreamBufferHandle_t_core1 xReturn_core1;
        uint8_t ucFlags_core1;

        configASSERT_core1( pucStreamBufferStorageArea_core1 );
        configASSERT_core1( pxStaticStreamBuffer_core1 );
        configASSERT_core1( xTriggerLevelBytes_core1 <= xBufferSizeBytes_core1 );

        /* A trigger level of 0 would cause a waiting task_core1 to unblock even when
         * the buffer was empty. */
        if( xTriggerLevelBytes_core1 == ( size_t ) 0 )
        {
            xTriggerLevelBytes_core1 = ( size_t ) 1;
        }

        if( xIsMessageBuffer_core1 != pdFALSE_core1 )
        {
            /* Statically allocated message buffer. */
            ucFlags_core1 = sbFLAGS_IS_MESSAGE_BUFFER_core1 | sbFLAGS_IS_STATICALLY_ALLOCATED_core1;
        }
        else
        {
            /* Statically allocated stream buffer. */
            ucFlags_core1 = sbFLAGS_IS_STATICALLY_ALLOCATED_core1;
        }

        /* In case the stream buffer is going to be used as a message buffer
         * (that is, it will hold discrete messages with a little meta data that
         * says how big the next message is) check the buffer will be large enough
         * to hold at least one message. */
        configASSERT_core1( xBufferSizeBytes_core1 > sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 );

        #if ( configASSERT_DEFINED_core1 == 1 )
        {
            /* Sanity check that the size of the structure used to declare a
             * variable of type StaticStreamBuffer_t_core1 equals the size of the real
             * message buffer structure. */
            volatile size_t xSize_core1 = sizeof( StaticStreamBuffer_t_core1 );
            configASSERT_core1( xSize_core1 == sizeof( StreamBuffer_t_core1 ) );
        } /*lint !e529 xSize_core1 is referenced is configASSERT_core1() is defined. */
        #endif /* configASSERT_DEFINED_core1 */

        if( ( pucStreamBufferStorageArea_core1 != NULL ) && ( pxStaticStreamBuffer_core1 != NULL ) )
        {
            prvInitialiseNewStreamBuffer_core1( pxStreamBuffer_core1,
                                          pucStreamBufferStorageArea_core1,
                                          xBufferSizeBytes_core1,
                                          xTriggerLevelBytes_core1,
                                          ucFlags_core1,
                                          pxSendCompletedCallback_core1,
                                          pxReceiveCompletedCallback_core1 );

            /* Remember this was statically allocated in case it is ever deleted
             * again. */
            pxStreamBuffer_core1->ucFlags_core1 |= sbFLAGS_IS_STATICALLY_ALLOCATED_core1;

            traceSTREAM_BUFFER_CREATE_core1( pxStreamBuffer_core1, xIsMessageBuffer_core1 );

            xReturn_core1 = ( StreamBufferHandle_t_core1 ) pxStaticStreamBuffer_core1; /*lint !e9087 Data hiding requires cast to opaque type. */
        }
        else
        {
            xReturn_core1 = NULL;
            traceSTREAM_BUFFER_CREATE_STATIC_FAILED_core1( xReturn_core1, xIsMessageBuffer_core1 );
        }

        return xReturn_core1;
    }
#endif /* ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 ) */
/*-----------------------------------------------------------*/

void vStreamBufferDelete_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
{
    StreamBuffer_t_core1 * pxStreamBuffer_core1 = xStreamBuffer_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    traceSTREAM_BUFFER_DELETE_core1( xStreamBuffer_core1 );

    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_STATICALLY_ALLOCATED_core1 ) == ( uint8_t ) pdFALSE_core1 )
    {
        #if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )
        {
            /* Both the structure and the buffer were allocated using a single call
            * to pvPortMalloc_core1(), hence only one call to vPortFree_core1() is required. */
            vPortFree_core1( ( void * ) pxStreamBuffer_core1 ); /*lint !e9087 Standard free() semantics require void *, plus pxStreamBuffer_core1 was allocated by pvPortMalloc_core1(). */
        }
        #else
        {
            /* Should not be possible to get here, ucFlags_core1 must be corrupt.
             * Force an assert. */
            configASSERT_core1( xStreamBuffer_core1 == ( StreamBufferHandle_t_core1 ) ~0 );
        }
        #endif
    }
    else
    {
        /* The structure and buffer were not allocated dynamically and cannot be
         * freed - just scrub the structure so future use will assert. */
        ( void ) memset( pxStreamBuffer_core1, 0x00, sizeof( StreamBuffer_t_core1 ) );
    }
}
/*-----------------------------------------------------------*/

BaseType_t_core1 xStreamBufferReset_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    BaseType_t_core1 xReturn_core1 = pdFAIL_core1;
    StreamBufferCallbackFunction_t_core1 pxSendCallback_core1 = NULL, pxReceiveCallback_core1 = NULL;

    #if ( configUSE_TRACE_FACILITY_core1 == 1 )
        UBaseType_t_core1 uxStreamBufferNumber_core1;
    #endif

    configASSERT_core1( pxStreamBuffer_core1 );

    #if ( configUSE_TRACE_FACILITY_core1 == 1 )
    {
        /* Store the stream buffer number so it can be restored after the
         * reset. */
        uxStreamBufferNumber_core1 = pxStreamBuffer_core1->uxStreamBufferNumber_core1;
    }
    #endif

    /* Can only reset a message buffer if there are no tasks blocked on it. */
    taskENTER_CRITICAL_core1();
    {
        if( ( pxStreamBuffer_core1->xTaskWaitingToReceive_core1 == NULL ) && ( pxStreamBuffer_core1->xTaskWaitingToSend_core1 == NULL ) )
        {
            #if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
            {
                pxSendCallback_core1 = pxStreamBuffer_core1->pxSendCompletedCallback_core1;
                pxReceiveCallback_core1 = pxStreamBuffer_core1->pxReceiveCompletedCallback_core1;
            }
            #endif

            prvInitialiseNewStreamBuffer_core1( pxStreamBuffer_core1,
                                          pxStreamBuffer_core1->pucBuffer_core1,
                                          pxStreamBuffer_core1->xLength_core1,
                                          pxStreamBuffer_core1->xTriggerLevelBytes_core1,
                                          pxStreamBuffer_core1->ucFlags_core1,
                                          pxSendCallback_core1,
                                          pxReceiveCallback_core1 );

            #if ( configUSE_TRACE_FACILITY_core1 == 1 )
            {
                pxStreamBuffer_core1->uxStreamBufferNumber_core1 = uxStreamBufferNumber_core1;
            }
            #endif

            traceSTREAM_BUFFER_RESET_core1( xStreamBuffer_core1 );

            xReturn_core1 = pdPASS_core1;
        }
    }
    taskEXIT_CRITICAL_core1();

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

BaseType_t_core1 xStreamBufferSetTriggerLevel_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                         size_t xTriggerLevel_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    BaseType_t_core1 xReturn_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    /* It is not valid for the trigger level to be 0. */
    if( xTriggerLevel_core1 == ( size_t ) 0 )
    {
        xTriggerLevel_core1 = ( size_t ) 1;
    }

    /* The trigger level is the number of bytes that must be in the stream
     * buffer before a task_core1 that is waiting for data is unblocked. */
    if( xTriggerLevel_core1 < pxStreamBuffer_core1->xLength_core1 )
    {
        pxStreamBuffer_core1->xTriggerLevelBytes_core1 = xTriggerLevel_core1;
        xReturn_core1 = pdPASS_core1;
    }
    else
    {
        xReturn_core1 = pdFALSE_core1;
    }

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferSpacesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
{
    const StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    size_t xSpace_core1;
    size_t xOriginalTail_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    /* The code below reads xTail_core1 and then xHead_core1.  This is safe if the stream
     * buffer is updated once between the two reads - but not if the stream buffer
     * is updated more than once between the two reads - hence the loop. */
    do
    {
        xOriginalTail_core1 = pxStreamBuffer_core1->xTail_core1;
        xSpace_core1 = pxStreamBuffer_core1->xLength_core1 + pxStreamBuffer_core1->xTail_core1;
        xSpace_core1 -= pxStreamBuffer_core1->xHead_core1;
    } while( xOriginalTail_core1 != pxStreamBuffer_core1->xTail_core1 );

    xSpace_core1 -= ( size_t ) 1;

    if( xSpace_core1 >= pxStreamBuffer_core1->xLength_core1 )
    {
        xSpace_core1 -= pxStreamBuffer_core1->xLength_core1;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    return xSpace_core1;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferBytesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
{
    const StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    size_t xReturn_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    xReturn_core1 = prvBytesInBuffer_core1( pxStreamBuffer_core1 );
    return xReturn_core1;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferSend_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                          const void * pvTxData_core1,
                          size_t xDataLengthBytes_core1,
                          TickType_t_core1 xTicksToWait_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    size_t xReturn_core1, xSpace_core1 = 0;
    size_t xRequiredSpace_core1 = xDataLengthBytes_core1;
    TimeOut_t_core1 xTimeOut;
    size_t xMaxReportedSpace_core1 = 0;

    configASSERT_core1( pvTxData_core1 );
    configASSERT_core1( pxStreamBuffer_core1 );

    /* The maximum amount of space a stream buffer will ever report is its length
     * minus 1. */
    xMaxReportedSpace_core1 = pxStreamBuffer_core1->xLength_core1 - ( size_t ) 1;

    /* This send function is used to write to both message buffers and stream
     * buffers.  If this is a message buffer then the space needed must be
     * increased by the amount of bytes needed to store the length of the
     * message. */
    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        xRequiredSpace_core1 += sbBYTES_TO_STORE_MESSAGE_LENGTH_core1;

        /* Overflow? */
        configASSERT_core1( xRequiredSpace_core1 > xDataLengthBytes_core1 );

        /* If this is a message buffer then it must be possible to write the
         * whole message. */
        if( xRequiredSpace_core1 > xMaxReportedSpace_core1 )
        {
            /* The message would not fit even if the entire buffer was empty,
             * so don't wait for space. */
            xTicksToWait_core1 = ( TickType_t_core1 ) 0;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    else
    {
        /* If this is a stream buffer then it is acceptable to write only part
         * of the message to the buffer.  Cap the length to the total length of
         * the buffer. */
        if( xRequiredSpace_core1 > xMaxReportedSpace_core1 )
        {
            xRequiredSpace_core1 = xMaxReportedSpace_core1;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }

    if( xTicksToWait_core1 != ( TickType_t_core1 ) 0 )
    {
        vTaskSetTimeOutState_core1( &xTimeOut );

        do
        {
            /* Wait until the required number of bytes are free in the message
             * buffer. */
            taskENTER_CRITICAL_core1();
            {
                xSpace_core1 = xStreamBufferSpacesAvailable_core1( pxStreamBuffer_core1 );

                if( xSpace_core1 < xRequiredSpace_core1 )
                {
                    /* Clear notification state as going to wait for space. */
                    ( void ) xTaskNotifyStateClear_core1( NULL );

                    /* Should only be one writer. */
                    configASSERT_core1( pxStreamBuffer_core1->xTaskWaitingToSend_core1 == NULL );
                    pxStreamBuffer_core1->xTaskWaitingToSend_core1 = xTaskGetCurrentTaskHandle_core1();
                }
                else
                {
                    taskEXIT_CRITICAL_core1();
                    break;
                }
            }
            taskEXIT_CRITICAL_core1();

            traceBLOCKING_ON_STREAM_BUFFER_SEND_core1( xStreamBuffer_core1 );
            ( void ) xTaskNotifyWait_core1( ( uint32_t ) 0, ( uint32_t ) 0, NULL, xTicksToWait_core1 );
            pxStreamBuffer_core1->xTaskWaitingToSend_core1 = NULL;
        } while( xTaskCheckForTimeOut_core1( &xTimeOut, &xTicksToWait_core1 ) == pdFALSE_core1 );
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    if( xSpace_core1 == ( size_t ) 0 )
    {
        xSpace_core1 = xStreamBufferSpacesAvailable_core1( pxStreamBuffer_core1 );
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    xReturn_core1 = prvWriteMessageToBuffer_core1( pxStreamBuffer_core1, pvTxData_core1, xDataLengthBytes_core1, xSpace_core1, xRequiredSpace_core1 );

    if( xReturn_core1 > ( size_t ) 0 )
    {
        traceSTREAM_BUFFER_SEND_core1( xStreamBuffer_core1, xReturn_core1 );

        /* Was a task_core1 waiting for the data? */
        if( prvBytesInBuffer_core1( pxStreamBuffer_core1 ) >= pxStreamBuffer_core1->xTriggerLevelBytes_core1 )
        {
            prvSEND_COMPLETED_core1( pxStreamBuffer_core1 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
        traceSTREAM_BUFFER_SEND_FAILED_core1( xStreamBuffer_core1 );
    }

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferSendFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                 const void * pvTxData_core1,
                                 size_t xDataLengthBytes_core1,
                                 BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    size_t xReturn_core1, xSpace_core1;
    size_t xRequiredSpace_core1 = xDataLengthBytes_core1;

    configASSERT_core1( pvTxData_core1 );
    configASSERT_core1( pxStreamBuffer_core1 );

    /* This send function is used to write to both message buffers and stream
     * buffers.  If this is a message buffer then the space needed must be
     * increased by the amount of bytes needed to store the length of the
     * message. */
    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        xRequiredSpace_core1 += sbBYTES_TO_STORE_MESSAGE_LENGTH_core1;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    xSpace_core1 = xStreamBufferSpacesAvailable_core1( pxStreamBuffer_core1 );
    xReturn_core1 = prvWriteMessageToBuffer_core1( pxStreamBuffer_core1, pvTxData_core1, xDataLengthBytes_core1, xSpace_core1, xRequiredSpace_core1 );

    if( xReturn_core1 > ( size_t ) 0 )
    {
        /* Was a task_core1 waiting for the data? */
        if( prvBytesInBuffer_core1( pxStreamBuffer_core1 ) >= pxStreamBuffer_core1->xTriggerLevelBytes_core1 )
        {
            prvSEND_COMPLETE_FROM_ISR_core1( pxStreamBuffer_core1, pxHigherPriorityTaskWoken_core1 );
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

    traceSTREAM_BUFFER_SEND_FROM_ISR_core1( xStreamBuffer_core1, xReturn_core1 );

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

static size_t prvWriteMessageToBuffer_core1( StreamBuffer_t_core1 * const pxStreamBuffer_core1,
                                       const void * pvTxData_core1,
                                       size_t xDataLengthBytes_core1,
                                       size_t xSpace_core1,
                                       size_t xRequiredSpace_core1 )
{
    size_t xNextHead_core1 = pxStreamBuffer_core1->xHead_core1;
    configMESSAGE_BUFFER_LENGTH_TYPE_core1 xMessageLength_core1;

    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        /* This is a message buffer, as opposed to a stream buffer. */

        /* Convert xDataLengthBytes_core1 to the message length type. */
        xMessageLength_core1 = ( configMESSAGE_BUFFER_LENGTH_TYPE_core1 ) xDataLengthBytes_core1;

        /* Ensure the data length given fits within configMESSAGE_BUFFER_LENGTH_TYPE_core1. */
        configASSERT_core1( ( size_t ) xMessageLength_core1 == xDataLengthBytes_core1 );

        if( xSpace_core1 >= xRequiredSpace_core1 )
        {
            /* There is enough space to write both the message length and the message
             * itself into the buffer.  Start by writing the length of the data, the data
             * itself will be written later in this function. */
            xNextHead_core1 = prvWriteBytesToBuffer_core1( pxStreamBuffer_core1, ( const uint8_t * ) &( xMessageLength_core1 ), sbBYTES_TO_STORE_MESSAGE_LENGTH_core1, xNextHead_core1 );
        }
        else
        {
            /* Not enough space, so do not write data to the buffer. */
            xDataLengthBytes_core1 = 0;
        }
    }
    else
    {
        /* This is a stream buffer, as opposed to a message buffer, so writing a
         * stream of bytes rather than discrete messages.  Plan to write as many
         * bytes as possible. */
        xDataLengthBytes_core1 = configMIN_core1( xDataLengthBytes_core1, xSpace_core1 );
    }

    if( xDataLengthBytes_core1 != ( size_t ) 0 )
    {
        /* Write the data to the buffer. */
        pxStreamBuffer_core1->xHead_core1 = prvWriteBytesToBuffer_core1( pxStreamBuffer_core1, ( const uint8_t * ) pvTxData_core1, xDataLengthBytes_core1, xNextHead_core1 ); /*lint !e9079 Storage buffer is implemented as uint8_t for ease of sizing, alignment and access. */
    }

    return xDataLengthBytes_core1;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferReceive_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                             void * pvRxData_core1,
                             size_t xBufferLengthBytes_core1,
                             TickType_t_core1 xTicksToWait_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    size_t xReceivedLength_core1 = 0, xBytesAvailable_core1, xBytesToStoreMessageLength_core1;

    configASSERT_core1( pvRxData_core1 );
    configASSERT_core1( pxStreamBuffer_core1 );

    /* This receive function is used by both message buffers, which store
     * discrete messages, and stream buffers, which store a continuous stream of
     * bytes.  Discrete messages include an additional
     * sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 bytes that hold the length of the
     * message. */
    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        xBytesToStoreMessageLength_core1 = sbBYTES_TO_STORE_MESSAGE_LENGTH_core1;
    }
    else
    {
        xBytesToStoreMessageLength_core1 = 0;
    }

    if( xTicksToWait_core1 != ( TickType_t_core1 ) 0 )
    {
        /* Checking if there is data and clearing the notification state must be
         * performed atomically. */
        taskENTER_CRITICAL_core1();
        {
            xBytesAvailable_core1 = prvBytesInBuffer_core1( pxStreamBuffer_core1 );

            /* If this function was invoked by a message buffer read then
             * xBytesToStoreMessageLength_core1 holds the number of bytes used to hold
             * the length of the next discrete message.  If this function was
             * invoked by a stream buffer read then xBytesToStoreMessageLength_core1 will
             * be 0. */
            if( xBytesAvailable_core1 <= xBytesToStoreMessageLength_core1 )
            {
                /* Clear notification state as going to wait for data. */
                ( void ) xTaskNotifyStateClear_core1( NULL );

                /* Should only be one reader. */
                configASSERT_core1( pxStreamBuffer_core1->xTaskWaitingToReceive_core1 == NULL );
                pxStreamBuffer_core1->xTaskWaitingToReceive_core1 = xTaskGetCurrentTaskHandle_core1();
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core1();
            }
        }
        taskEXIT_CRITICAL_core1();

        if( xBytesAvailable_core1 <= xBytesToStoreMessageLength_core1 )
        {
            /* Wait for data to be available. */
            traceBLOCKING_ON_STREAM_BUFFER_RECEIVE_core1( xStreamBuffer_core1 );
            ( void ) xTaskNotifyWait_core1( ( uint32_t ) 0, ( uint32_t ) 0, NULL, xTicksToWait_core1 );
            pxStreamBuffer_core1->xTaskWaitingToReceive_core1 = NULL;

            /* Recheck the data available after blocking. */
            xBytesAvailable_core1 = prvBytesInBuffer_core1( pxStreamBuffer_core1 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    else
    {
        xBytesAvailable_core1 = prvBytesInBuffer_core1( pxStreamBuffer_core1 );
    }

    /* Whether receiving a discrete message (where xBytesToStoreMessageLength_core1
     * holds the number of bytes used to store the message length) or a stream of
     * bytes (where xBytesToStoreMessageLength_core1 is zero), the number of bytes
     * available must be greater than xBytesToStoreMessageLength_core1 to be able to
     * read bytes from the buffer. */
    if( xBytesAvailable_core1 > xBytesToStoreMessageLength_core1 )
    {
        xReceivedLength_core1 = prvReadMessageFromBuffer_core1( pxStreamBuffer_core1, pvRxData_core1, xBufferLengthBytes_core1, xBytesAvailable_core1 );

        /* Was a task_core1 waiting for space in the buffer? */
        if( xReceivedLength_core1 != ( size_t ) 0 )
        {
            traceSTREAM_BUFFER_RECEIVE_core1( xStreamBuffer_core1, xReceivedLength_core1 );
            prvRECEIVE_COMPLETED_core1( xStreamBuffer_core1 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    else
    {
        traceSTREAM_BUFFER_RECEIVE_FAILED_core1( xStreamBuffer_core1 );
        mtCOVERAGE_TEST_MARKER_core1();
    }

    return xReceivedLength_core1;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferNextMessageLengthBytes_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    size_t xReturn_core1, xBytesAvailable_core1;
    configMESSAGE_BUFFER_LENGTH_TYPE_core1 xTempReturn_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    /* Ensure the stream buffer is being used as a message buffer. */
    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        xBytesAvailable_core1 = prvBytesInBuffer_core1( pxStreamBuffer_core1 );

        if( xBytesAvailable_core1 > sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 )
        {
            /* The number of bytes available is greater than the number of bytes
             * required to hold the length of the next message, so another message
             * is available. */
            ( void ) prvReadBytesFromBuffer_core1( pxStreamBuffer_core1, ( uint8_t * ) &xTempReturn_core1, sbBYTES_TO_STORE_MESSAGE_LENGTH_core1, pxStreamBuffer_core1->xTail_core1 );
            xReturn_core1 = ( size_t ) xTempReturn_core1;
        }
        else
        {
            /* The minimum amount of bytes in a message buffer is
             * ( sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 + 1 ), so if xBytesAvailable_core1 is
             * less than sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 the only other valid
             * value is 0. */
            configASSERT_core1( xBytesAvailable_core1 == 0 );
            xReturn_core1 = 0;
        }
    }
    else
    {
        xReturn_core1 = 0;
    }

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferReceiveFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                    void * pvRxData_core1,
                                    size_t xBufferLengthBytes_core1,
                                    BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    size_t xReceivedLength_core1 = 0, xBytesAvailable_core1, xBytesToStoreMessageLength_core1;

    configASSERT_core1( pvRxData_core1 );
    configASSERT_core1( pxStreamBuffer_core1 );

    /* This receive function is used by both message buffers, which store
     * discrete messages, and stream buffers, which store a continuous stream of
     * bytes.  Discrete messages include an additional
     * sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 bytes that hold the length of the
     * message. */
    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        xBytesToStoreMessageLength_core1 = sbBYTES_TO_STORE_MESSAGE_LENGTH_core1;
    }
    else
    {
        xBytesToStoreMessageLength_core1 = 0;
    }

    xBytesAvailable_core1 = prvBytesInBuffer_core1( pxStreamBuffer_core1 );

    /* Whether receiving a discrete message (where xBytesToStoreMessageLength_core1
     * holds the number of bytes used to store the message length) or a stream of
     * bytes (where xBytesToStoreMessageLength_core1 is zero), the number of bytes
     * available must be greater than xBytesToStoreMessageLength_core1 to be able to
     * read bytes from the buffer. */
    if( xBytesAvailable_core1 > xBytesToStoreMessageLength_core1 )
    {
        xReceivedLength_core1 = prvReadMessageFromBuffer_core1( pxStreamBuffer_core1, pvRxData_core1, xBufferLengthBytes_core1, xBytesAvailable_core1 );

        /* Was a task_core1 waiting for space in the buffer? */
        if( xReceivedLength_core1 != ( size_t ) 0 )
        {
            prvRECEIVE_COMPLETED_FROM_ISR_core1( pxStreamBuffer_core1, pxHigherPriorityTaskWoken_core1 );
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

    traceSTREAM_BUFFER_RECEIVE_FROM_ISR_core1( xStreamBuffer_core1, xReceivedLength_core1 );

    return xReceivedLength_core1;
}
/*-----------------------------------------------------------*/

static size_t prvReadMessageFromBuffer_core1( StreamBuffer_t_core1 * pxStreamBuffer_core1,
                                        void * pvRxData_core1,
                                        size_t xBufferLengthBytes_core1,
                                        size_t xBytesAvailable_core1 )
{
    size_t xCount_core1, xNextMessageLength_core1;
    configMESSAGE_BUFFER_LENGTH_TYPE_core1 xTempNextMessageLength_core1;
    size_t xNextTail_core1 = pxStreamBuffer_core1->xTail_core1;

    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        /* A discrete message is being received.  First receive the length
         * of the message. */
        xNextTail_core1 = prvReadBytesFromBuffer_core1( pxStreamBuffer_core1, ( uint8_t * ) &xTempNextMessageLength_core1, sbBYTES_TO_STORE_MESSAGE_LENGTH_core1, xNextTail_core1 );
        xNextMessageLength_core1 = ( size_t ) xTempNextMessageLength_core1;

        /* Reduce the number of bytes available by the number of bytes just
         * read out. */
        xBytesAvailable_core1 -= sbBYTES_TO_STORE_MESSAGE_LENGTH_core1;

        /* Check there is enough space in the buffer provided by the
         * user. */
        if( xNextMessageLength_core1 > xBufferLengthBytes_core1 )
        {
            /* The user has provided insufficient space to read the message. */
            xNextMessageLength_core1 = 0;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core1();
        }
    }
    else
    {
        /* A stream of bytes is being received (as opposed to a discrete
         * message), so read as many bytes as possible. */
        xNextMessageLength_core1 = xBufferLengthBytes_core1;
    }

    /* Use the minimum of the wanted bytes and the available bytes. */
    xCount_core1 = configMIN_core1( xNextMessageLength_core1, xBytesAvailable_core1 );

    if( xCount_core1 != ( size_t ) 0 )
    {
        /* Read the actual data and update the tail to mark the data as officially consumed. */
        pxStreamBuffer_core1->xTail_core1 = prvReadBytesFromBuffer_core1( pxStreamBuffer_core1, ( uint8_t * ) pvRxData_core1, xCount_core1, xNextTail_core1 ); /*lint !e9079 Data storage area is implemented as uint8_t array for ease of sizing, indexing and alignment. */
    }

    return xCount_core1;
}
/*-----------------------------------------------------------*/

BaseType_t_core1 xStreamBufferIsEmpty_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
{
    const StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    BaseType_t_core1 xReturn_core1;
    size_t xTail_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    /* True if no bytes are available. */
    xTail_core1 = pxStreamBuffer_core1->xTail_core1;

    if( pxStreamBuffer_core1->xHead_core1 == xTail_core1 )
    {
        xReturn_core1 = pdTRUE_core1;
    }
    else
    {
        xReturn_core1 = pdFALSE_core1;
    }

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

BaseType_t_core1 xStreamBufferIsFull_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
{
    BaseType_t_core1 xReturn_core1;
    size_t xBytesToStoreMessageLength_core1;
    const StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    /* This generic version of the receive function is used by both message
     * buffers, which store discrete messages, and stream buffers, which store a
     * continuous stream of bytes.  Discrete messages include an additional
     * sbBYTES_TO_STORE_MESSAGE_LENGTH_core1 bytes that hold the length of the message. */
    if( ( pxStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 ) != ( uint8_t ) 0 )
    {
        xBytesToStoreMessageLength_core1 = sbBYTES_TO_STORE_MESSAGE_LENGTH_core1;
    }
    else
    {
        xBytesToStoreMessageLength_core1 = 0;
    }

    /* True if the available space equals zero. */
    if( xStreamBufferSpacesAvailable_core1( xStreamBuffer_core1 ) <= xBytesToStoreMessageLength_core1 )
    {
        xReturn_core1 = pdTRUE_core1;
    }
    else
    {
        xReturn_core1 = pdFALSE_core1;
    }

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

BaseType_t_core1 xStreamBufferSendCompletedFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                              BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    BaseType_t_core1 xReturn_core1;
    UBaseType_t_core1 uxSavedInterruptStatus_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    uxSavedInterruptStatus_core1 = ( UBaseType_t_core1 ) portSET_INTERRUPT_MASK_FROM_ISR_core1();
    {
        if( ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1 != NULL )
        {
            ( void ) xTaskNotifyFromISR_core1( ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1,
                                         ( uint32_t ) 0,
                                         eNoAction_core1,
                                         pxHigherPriorityTaskWoken_core1 );
            ( pxStreamBuffer_core1 )->xTaskWaitingToReceive_core1 = NULL;
            xReturn_core1 = pdTRUE_core1;
        }
        else
        {
            xReturn_core1 = pdFALSE_core1;
        }
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core1( uxSavedInterruptStatus_core1 );

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

BaseType_t_core1 xStreamBufferReceiveCompletedFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                                 BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 )
{
    StreamBuffer_t_core1 * const pxStreamBuffer_core1 = xStreamBuffer_core1;
    BaseType_t_core1 xReturn_core1;
    UBaseType_t_core1 uxSavedInterruptStatus_core1;

    configASSERT_core1( pxStreamBuffer_core1 );

    uxSavedInterruptStatus_core1 = ( UBaseType_t_core1 ) portSET_INTERRUPT_MASK_FROM_ISR_core1();
    {
        if( ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1 != NULL )
        {
            ( void ) xTaskNotifyFromISR_core1( ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1,
                                         ( uint32_t ) 0,
                                         eNoAction_core1,
                                         pxHigherPriorityTaskWoken_core1 );
            ( pxStreamBuffer_core1 )->xTaskWaitingToSend_core1 = NULL;
            xReturn_core1 = pdTRUE_core1;
        }
        else
        {
            xReturn_core1 = pdFALSE_core1;
        }
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core1( uxSavedInterruptStatus_core1 );

    return xReturn_core1;
}
/*-----------------------------------------------------------*/

static size_t prvWriteBytesToBuffer_core1( StreamBuffer_t_core1 * const pxStreamBuffer_core1,
                                     const uint8_t * pucData_core1,
                                     size_t xCount_core1,
                                     size_t xHead_core1 )
{
    size_t xFirstLength_core1;

    configASSERT_core1( xCount_core1 > ( size_t ) 0 );

    /* Calculate the number of bytes that can be added in the first write -
     * which may be less than the total number of bytes that need to be added if
     * the buffer will wrap back to the beginning. */
    xFirstLength_core1 = configMIN_core1( pxStreamBuffer_core1->xLength_core1 - xHead_core1, xCount_core1 );

    /* Write as many bytes as can be written in the first write. */
    configASSERT_core1( ( xHead_core1 + xFirstLength_core1 ) <= pxStreamBuffer_core1->xLength_core1 );
    ( void ) memcpy( ( void * ) ( &( pxStreamBuffer_core1->pucBuffer_core1[ xHead_core1 ] ) ), ( const void * ) pucData_core1, xFirstLength_core1 ); /*lint !e9087 memcpy() requires void *. */

    /* If the number of bytes written was less than the number that could be
     * written in the first write... */
    if( xCount_core1 > xFirstLength_core1 )
    {
        /* ...then write the remaining bytes to the start of the buffer. */
        configASSERT_core1( ( xCount_core1 - xFirstLength_core1 ) <= pxStreamBuffer_core1->xLength_core1 );
        ( void ) memcpy( ( void * ) pxStreamBuffer_core1->pucBuffer_core1, ( const void * ) &( pucData_core1[ xFirstLength_core1 ] ), xCount_core1 - xFirstLength_core1 ); /*lint !e9087 memcpy() requires void *. */
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    xHead_core1 += xCount_core1;

    if( xHead_core1 >= pxStreamBuffer_core1->xLength_core1 )
    {
        xHead_core1 -= pxStreamBuffer_core1->xLength_core1;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    return xHead_core1;
}
/*-----------------------------------------------------------*/

static size_t prvReadBytesFromBuffer_core1( StreamBuffer_t_core1 * pxStreamBuffer_core1,
                                      uint8_t * pucData_core1,
                                      size_t xCount_core1,
                                      size_t xTail_core1 )
{
    size_t xFirstLength_core1;

    configASSERT_core1( xCount_core1 != ( size_t ) 0 );

    /* Calculate the number of bytes that can be read - which may be
     * less than the number wanted if the data wraps around to the start of
     * the buffer. */
    xFirstLength_core1 = configMIN_core1( pxStreamBuffer_core1->xLength_core1 - xTail_core1, xCount_core1 );

    /* Obtain the number of bytes it is possible to obtain in the first
     * read.  Asserts check bounds of read and write. */
    configASSERT_core1( xFirstLength_core1 <= xCount_core1 );
    configASSERT_core1( ( xTail_core1 + xFirstLength_core1 ) <= pxStreamBuffer_core1->xLength_core1 );
    ( void ) memcpy( ( void * ) pucData_core1, ( const void * ) &( pxStreamBuffer_core1->pucBuffer_core1[ xTail_core1 ] ), xFirstLength_core1 ); /*lint !e9087 memcpy() requires void *. */

    /* If the total number of wanted bytes is greater than the number
     * that could be read in the first read... */
    if( xCount_core1 > xFirstLength_core1 )
    {
        /* ...then read the remaining bytes from the start of the buffer. */
        ( void ) memcpy( ( void * ) &( pucData_core1[ xFirstLength_core1 ] ), ( void * ) ( pxStreamBuffer_core1->pucBuffer_core1 ), xCount_core1 - xFirstLength_core1 ); /*lint !e9087 memcpy() requires void *. */
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    /* Move the tail pointer to effectively remove the data read from the buffer. */
    xTail_core1 += xCount_core1;

    if( xTail_core1 >= pxStreamBuffer_core1->xLength_core1 )
    {
        xTail_core1 -= pxStreamBuffer_core1->xLength_core1;
    }

    return xTail_core1;
}
/*-----------------------------------------------------------*/

static size_t prvBytesInBuffer_core1( const StreamBuffer_t_core1 * const pxStreamBuffer_core1 )
{
/* Returns the distance between xTail_core1 and xHead_core1. */
    size_t xCount_core1;

    xCount_core1 = pxStreamBuffer_core1->xLength_core1 + pxStreamBuffer_core1->xHead_core1;
    xCount_core1 -= pxStreamBuffer_core1->xTail_core1;

    if( xCount_core1 >= pxStreamBuffer_core1->xLength_core1 )
    {
        xCount_core1 -= pxStreamBuffer_core1->xLength_core1;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core1();
    }

    return xCount_core1;
}
/*-----------------------------------------------------------*/

static void prvInitialiseNewStreamBuffer_core1( StreamBuffer_t_core1 * const pxStreamBuffer_core1,
                                          uint8_t * const pucBuffer_core1,
                                          size_t xBufferSizeBytes_core1,
                                          size_t xTriggerLevelBytes_core1,
                                          uint8_t ucFlags_core1,
                                          StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                          StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 )
{
    /* Assert here is deliberately writing to the entire buffer to ensure it can
     * be written to without generating exceptions, and is setting the buffer to a
     * known value to assist in development/debugging. */
    #if ( configASSERT_DEFINED_core1 == 1 )
    {
        /* The value written just has to be identifiable when looking at the
         * memory.  Don't use 0xA5 as that is the stack fill value and could
         * result in confusion as to what is actually being observed. */
        const BaseType_t_core1 xWriteValue_core1 = 0x55;
        configASSERT_core1( memset( pucBuffer_core1, ( int ) xWriteValue_core1, xBufferSizeBytes_core1 ) == pucBuffer_core1 );
    } /*lint !e529 !e438 xWriteValue_core1 is only used if configASSERT_core1() is defined. */
    #endif

    ( void ) memset( ( void * ) pxStreamBuffer_core1, 0x00, sizeof( StreamBuffer_t_core1 ) ); /*lint !e9087 memset() requires void *. */
    pxStreamBuffer_core1->pucBuffer_core1 = pucBuffer_core1;
    pxStreamBuffer_core1->xLength_core1 = xBufferSizeBytes_core1;
    pxStreamBuffer_core1->xTriggerLevelBytes_core1 = xTriggerLevelBytes_core1;
    pxStreamBuffer_core1->ucFlags_core1 = ucFlags_core1;
    #if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
    {
        pxStreamBuffer_core1->pxSendCompletedCallback_core1 = pxSendCompletedCallback_core1;
        pxStreamBuffer_core1->pxReceiveCompletedCallback_core1 = pxReceiveCompletedCallback_core1;
    }
    #else
    {
        ( void ) pxSendCompletedCallback_core1;
        ( void ) pxReceiveCompletedCallback_core1;
    }
    #endif
}

#if ( configUSE_TRACE_FACILITY_core1 == 1 )

    UBaseType_t_core1 uxStreamBufferGetStreamBufferNumber_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
    {
        return xStreamBuffer_core1->uxStreamBufferNumber_core1;
    }

#endif /* configUSE_TRACE_FACILITY_core1 */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core1 == 1 )

    void vStreamBufferSetStreamBufferNumber_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                             UBaseType_t_core1 uxStreamBufferNumber_core1 )
    {
        xStreamBuffer_core1->uxStreamBufferNumber_core1 = uxStreamBufferNumber_core1;
    }

#endif /* configUSE_TRACE_FACILITY_core1 */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core1 == 1 )

    uint8_t ucStreamBufferGetStreamBufferType_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
    {
        return( xStreamBuffer_core1->ucFlags_core1 & sbFLAGS_IS_MESSAGE_BUFFER_core1 );
    }

#endif /* configUSE_TRACE_FACILITY_core1 */
/*-----------------------------------------------------------*/
