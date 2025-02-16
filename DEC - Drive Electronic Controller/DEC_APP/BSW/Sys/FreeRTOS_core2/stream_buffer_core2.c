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
#include <stdint.h>
#include <string.h>

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 prevents task_core2.h from redefining
 * all the API functions to use the MPU wrappers.  That should only be done when
 * task_core2.h is included from an application file. */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2

/* FreeRTOS_core2 includes. */
#include "FreeRTOS_core2.h"
#include "task_core2.h"
#include "stream_buffer_core2.h"

#if ( configUSE_TASK_NOTIFICATIONS_core2 != 1 )
    #error configUSE_TASK_NOTIFICATIONS_core2 must be set to 1 to build stream_buffer_core2.c
#endif

#if ( INCLUDE_xTaskGetCurrentTaskHandle_core2 != 1 )
    #error INCLUDE_xTaskGetCurrentTaskHandle_core2 must be set to 1 to build stream_buffer_core2.c
#endif

/* Lint e961, e9021 and e750 are suppressed as a MISRA exception justified
 * because the MPU ports require MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 to be defined
 * for the header files above, but not in this file, in order to generate the
 * correct privileged Vs unprivileged linkage and placement. */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 /*lint !e961 !e750 !e9021. */

/* If the user has not provided application specific Rx notification macros,
 * or #defined the notification macros away, then provide default implementations
 * that uses task_core2 notifications. */
/*lint -save -e9026 Function like macros allowed and needed here so they can be overridden. */
#ifndef sbRECEIVE_COMPLETED_core2
    #define sbRECEIVE_COMPLETED_core2( pxStreamBuffer_core2 )                         \
    vTaskSuspendAll_core2();                                                    \
    {                                                                     \
        if( ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2 != NULL )              \
        {                                                                 \
            ( void ) xTaskNotify_core2( ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2, \
                                  ( uint32_t ) 0,                         \
                                  eNoAction_core2 );                            \
            ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2 = NULL;                \
        }                                                                 \
    }                                                                     \
    ( void ) xTaskResumeAll_core2();
#endif /* sbRECEIVE_COMPLETED_core2 */

/* If user has provided a per-instance receive complete callback, then
 * invoke the callback else use the receive complete macro which is provided by default for all instances.
 */
#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define prvRECEIVE_COMPLETED_core2( pxStreamBuffer_core2 )                                               \
    {                                                                                            \
        if( ( pxStreamBuffer_core2 )->pxReceiveCompletedCallback_core2 != NULL )                             \
        {                                                                                        \
            ( pxStreamBuffer_core2 )->pxReceiveCompletedCallback_core2( ( pxStreamBuffer_core2 ), pdFALSE_core2, NULL ); \
        }                                                                                        \
        else                                                                                     \
        {                                                                                        \
            sbRECEIVE_COMPLETED_core2( ( pxStreamBuffer_core2 ) );                                           \
        }                                                                                        \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */
    #define prvRECEIVE_COMPLETED_core2( pxStreamBuffer_core2 )    sbRECEIVE_COMPLETED_core2( ( pxStreamBuffer_core2 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */

#ifndef sbRECEIVE_COMPLETED_FROM_ISR_core2
    #define sbRECEIVE_COMPLETED_FROM_ISR_core2( pxStreamBuffer_core2,                            \
                                          pxHigherPriorityTaskWoken_core2 )                \
    {                                                                                \
        UBaseType_t_core2 uxSavedInterruptStatus_core2;                                          \
                                                                                     \
        uxSavedInterruptStatus_core2 = ( UBaseType_t_core2 ) portSET_INTERRUPT_MASK_FROM_ISR_core2();  \
        {                                                                            \
            if( ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2 != NULL )                     \
            {                                                                        \
                ( void ) xTaskNotifyFromISR_core2( ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2, \
                                             ( uint32_t ) 0,                         \
                                             eNoAction_core2,                              \
                                             ( pxHigherPriorityTaskWoken_core2 ) );        \
                ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2 = NULL;                       \
            }                                                                        \
        }                                                                            \
        portCLEAR_INTERRUPT_MASK_FROM_ISR_core2( uxSavedInterruptStatus_core2 );                 \
    }
#endif /* sbRECEIVE_COMPLETED_FROM_ISR_core2 */

#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define prvRECEIVE_COMPLETED_FROM_ISR_core2( pxStreamBuffer_core2,                                                               \
                                           pxHigherPriorityTaskWoken_core2 )                                                   \
    {                                                                                                                    \
        if( ( pxStreamBuffer_core2 )->pxReceiveCompletedCallback_core2 != NULL )                                                     \
        {                                                                                                                \
            ( pxStreamBuffer_core2 )->pxReceiveCompletedCallback_core2( ( pxStreamBuffer_core2 ), pdTRUE_core2, ( pxHigherPriorityTaskWoken_core2 ) ); \
        }                                                                                                                \
        else                                                                                                             \
        {                                                                                                                \
            sbRECEIVE_COMPLETED_FROM_ISR_core2( ( pxStreamBuffer_core2 ), ( pxHigherPriorityTaskWoken_core2 ) );                           \
        }                                                                                                                \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */
    #define prvRECEIVE_COMPLETED_FROM_ISR_core2( pxStreamBuffer_core2, pxHigherPriorityTaskWoken_core2 ) \
    sbRECEIVE_COMPLETED_FROM_ISR_core2( ( pxStreamBuffer_core2 ), ( pxHigherPriorityTaskWoken_core2 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */

/* If the user has not provided an application specific Tx notification macro,
 * or #defined the notification macro away, then provide a default
 * implementation that uses task_core2 notifications.
 */
#ifndef sbSEND_COMPLETED_core2
    #define sbSEND_COMPLETED_core2( pxStreamBuffer_core2 )                               \
    vTaskSuspendAll_core2();                                                       \
    {                                                                        \
        if( ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2 != NULL )              \
        {                                                                    \
            ( void ) xTaskNotify_core2( ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2, \
                                  ( uint32_t ) 0,                            \
                                  eNoAction_core2 );                               \
            ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2 = NULL;                \
        }                                                                    \
    }                                                                        \
    ( void ) xTaskResumeAll_core2();
#endif /* sbSEND_COMPLETED_core2 */

/* If user has provided a per-instance send completed callback, then
 * invoke the callback else use the send complete macro which is provided by default for all instances.
 */
#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define prvSEND_COMPLETED_core2( pxStreamBuffer_core2 )                                           \
    {                                                                                     \
        if( ( pxStreamBuffer_core2 )->pxSendCompletedCallback_core2 != NULL )                         \
        {                                                                                 \
            pxStreamBuffer_core2->pxSendCompletedCallback_core2( ( pxStreamBuffer_core2 ), pdFALSE_core2, NULL ); \
        }                                                                                 \
        else                                                                              \
        {                                                                                 \
            sbSEND_COMPLETED_core2( ( pxStreamBuffer_core2 ) );                                       \
        }                                                                                 \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */
    #define prvSEND_COMPLETED_core2( pxStreamBuffer_core2 )    sbSEND_COMPLETED_core2( ( pxStreamBuffer_core2 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */


#ifndef sbSEND_COMPLETE_FROM_ISR_core2
    #define sbSEND_COMPLETE_FROM_ISR_core2( pxStreamBuffer_core2, pxHigherPriorityTaskWoken_core2 )       \
    {                                                                                   \
        UBaseType_t_core2 uxSavedInterruptStatus_core2;                                             \
                                                                                        \
        uxSavedInterruptStatus_core2 = ( UBaseType_t_core2 ) portSET_INTERRUPT_MASK_FROM_ISR_core2();     \
        {                                                                               \
            if( ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2 != NULL )                     \
            {                                                                           \
                ( void ) xTaskNotifyFromISR_core2( ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2, \
                                             ( uint32_t ) 0,                            \
                                             eNoAction_core2,                                 \
                                             ( pxHigherPriorityTaskWoken_core2 ) );           \
                ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2 = NULL;                       \
            }                                                                           \
        }                                                                               \
        portCLEAR_INTERRUPT_MASK_FROM_ISR_core2( uxSavedInterruptStatus_core2 );                    \
    }
#endif /* sbSEND_COMPLETE_FROM_ISR_core2 */


#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define prvSEND_COMPLETE_FROM_ISR_core2( pxStreamBuffer_core2, pxHigherPriorityTaskWoken_core2 )                                    \
    {                                                                                                                 \
        if( ( pxStreamBuffer_core2 )->pxSendCompletedCallback_core2 != NULL )                                                     \
        {                                                                                                             \
            ( pxStreamBuffer_core2 )->pxSendCompletedCallback_core2( ( pxStreamBuffer_core2 ), pdTRUE_core2, ( pxHigherPriorityTaskWoken_core2 ) ); \
        }                                                                                                             \
        else                                                                                                          \
        {                                                                                                             \
            sbSEND_COMPLETE_FROM_ISR_core2( ( pxStreamBuffer_core2 ), ( pxHigherPriorityTaskWoken_core2 ) );                            \
        }                                                                                                             \
    }
#else /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */
    #define prvSEND_COMPLETE_FROM_ISR_core2( pxStreamBuffer_core2, pxHigherPriorityTaskWoken_core2 ) \
    sbSEND_COMPLETE_FROM_ISR_core2( ( pxStreamBuffer_core2 ), ( pxHigherPriorityTaskWoken_core2 ) )
#endif /* if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 ) */

/*lint -restore (9026) */

/* The number of bytes used to hold the length of a message in the buffer. */
#define sbBYTES_TO_STORE_MESSAGE_LENGTH_core2    ( sizeof( configMESSAGE_BUFFER_LENGTH_TYPE_core2 ) )

/* Bits stored in the ucFlags_core2 field of the stream buffer. */
#define sbFLAGS_IS_MESSAGE_BUFFER_core2          ( ( uint8_t ) 1 ) /* Set if the stream buffer was created as a message buffer, in which case it holds discrete messages rather than a stream. */
#define sbFLAGS_IS_STATICALLY_ALLOCATED_core2    ( ( uint8_t ) 2 ) /* Set if the stream buffer was created using statically allocated memory. */

/*-----------------------------------------------------------*/

/* Structure that hold state information on the buffer. */
typedef struct StreamBufferDef_t_core2                 /*lint !e9058 Style convention uses tag. */
{
    volatile size_t xTail_core2;                       /* Index to the next item to read within the buffer. */
    volatile size_t xHead_core2;                       /* Index to the next item to write within the buffer. */
    size_t xLength_core2;                              /* The length of the buffer pointed to by pucBuffer_core2. */
    size_t xTriggerLevelBytes_core2;                   /* The number of bytes that must be in the stream buffer before a task_core2 that is waiting for data is unblocked. */
    volatile TaskHandle_t_core2 xTaskWaitingToReceive_core2; /* Holds the handle of a task_core2 waiting for data, or NULL if no tasks are waiting. */
    volatile TaskHandle_t_core2 xTaskWaitingToSend_core2;    /* Holds the handle of a task_core2 waiting to send data to a message buffer that is full. */
    uint8_t * pucBuffer_core2;                         /* Points to the buffer itself - that is - the RAM that stores the data passed through the buffer. */
    uint8_t ucFlags_core2;

    #if ( configUSE_TRACE_FACILITY_core2 == 1 )
        UBaseType_t_core2 uxStreamBufferNumber_core2; /* Used for tracing purposes. */
    #endif

    #if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
        StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2;    /* Optional callback called on send complete. sbSEND_COMPLETED_core2 is called if this is NULL. */
        StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2; /* Optional callback called on receive complete.  sbRECEIVE_COMPLETED_core2 is called if this is NULL. */
    #endif
} StreamBuffer_t_core2;

/*
 * The number of bytes available to be read from the buffer.
 */
static size_t prvBytesInBuffer_core2( const StreamBuffer_t_core2 * const pxStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Add xCount_core2 bytes from pucData_core2 into the pxStreamBuffer_core2's data storage area.
 * This function does not update the buffer's xHead_core2 pointer, so multiple writes
 * may be chained together "atomically". This is useful for Message Buffers where
 * the length and data bytes are written in two separate chunks, and we don't want
 * the reader to see the buffer as having grown until after all data is copied over.
 * This function takes a custom xHead_core2 value to indicate where to write to (necessary
 * for chaining) and returns the the resulting xHead_core2 position.
 * To mark the write as complete, manually set the buffer's xHead_core2 field with the
 * returned xHead_core2 from this function.
 */
static size_t prvWriteBytesToBuffer_core2( StreamBuffer_t_core2 * const pxStreamBuffer_core2,
                                     const uint8_t * pucData_core2,
                                     size_t xCount_core2,
                                     size_t xHead_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * If the stream buffer is being used as a message buffer, then reads an entire
 * message out of the buffer.  If the stream buffer is being used as a stream
 * buffer then read as many bytes as possible from the buffer.
 * prvReadBytesFromBuffer_core2() is called to actually extract the bytes from the
 * buffer's data storage area.
 */
static size_t prvReadMessageFromBuffer_core2( StreamBuffer_t_core2 * pxStreamBuffer_core2,
                                        void * pvRxData_core2,
                                        size_t xBufferLengthBytes_core2,
                                        size_t xBytesAvailable_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * If the stream buffer is being used as a message buffer, then writes an entire
 * message to the buffer.  If the stream buffer is being used as a stream
 * buffer then write as many bytes as possible to the buffer.
 * prvWriteBytestoBuffer() is called to actually send the bytes to the buffer's
 * data storage area.
 */
static size_t prvWriteMessageToBuffer_core2( StreamBuffer_t_core2 * const pxStreamBuffer_core2,
                                       const void * pvTxData_core2,
                                       size_t xDataLengthBytes_core2,
                                       size_t xSpace_core2,
                                       size_t xRequiredSpace_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Copies xCount_core2 bytes from the pxStreamBuffer_core2's data storage area to pucData_core2.
 * This function does not update the buffer's xTail_core2 pointer, so multiple reads
 * may be chained together "atomically". This is useful for Message Buffers where
 * the length and data bytes are read in two separate chunks, and we don't want
 * the writer to see the buffer as having more free space until after all data is
 * copied over, especially if we have to abort the read due to insufficient receiving space.
 * This function takes a custom xTail_core2 value to indicate where to read from (necessary
 * for chaining) and returns the the resulting xTail_core2 position.
 * To mark the read as complete, manually set the buffer's xTail_core2 field with the
 * returned xTail_core2 from this function.
 */
static size_t prvReadBytesFromBuffer_core2( StreamBuffer_t_core2 * pxStreamBuffer_core2,
                                      uint8_t * pucData_core2,
                                      size_t xCount_core2,
                                      size_t xTail_core2 ) PRIVILEGED_FUNCTION_core2;

/*
 * Called by both pxStreamBufferCreate() and pxStreamBufferCreateStatic() to
 * initialise the members of the newly created stream buffer structure.
 */
static void prvInitialiseNewStreamBuffer_core2( StreamBuffer_t_core2 * const pxStreamBuffer_core2,
                                          uint8_t * const pucBuffer_core2,
                                          size_t xBufferSizeBytes_core2,
                                          size_t xTriggerLevelBytes_core2,
                                          uint8_t ucFlags_core2,
                                          StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                          StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 ) PRIVILEGED_FUNCTION_core2;

/*-----------------------------------------------------------*/
#if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 )
    StreamBufferHandle_t_core2 xStreamBufferGenericCreate_core2( size_t xBufferSizeBytes_core2,
                                                     size_t xTriggerLevelBytes_core2,
                                                     BaseType_t_core2 xIsMessageBuffer_core2,
                                                     StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                                     StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 )
    {
        uint8_t * pucAllocatedMemory_core2;
        uint8_t ucFlags_core2;

        /* In case the stream buffer is going to be used as a message buffer
         * (that is, it will hold discrete messages with a little meta data that
         * says how big the next message is) check the buffer will be large enough
         * to hold at least one message. */
        if( xIsMessageBuffer_core2 == pdTRUE_core2 )
        {
            /* Is a message buffer but not statically allocated. */
            ucFlags_core2 = sbFLAGS_IS_MESSAGE_BUFFER_core2;
            configASSERT_core2( xBufferSizeBytes_core2 > sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 );
        }
        else
        {
            /* Not a message buffer and not statically allocated. */
            ucFlags_core2 = 0;
            configASSERT_core2( xBufferSizeBytes_core2 > 0 );
        }

        configASSERT_core2( xTriggerLevelBytes_core2 <= xBufferSizeBytes_core2 );

        /* A trigger level of 0 would cause a waiting task_core2 to unblock even when
         * the buffer was empty. */
        if( xTriggerLevelBytes_core2 == ( size_t ) 0 )
        {
            xTriggerLevelBytes_core2 = ( size_t ) 1;
        }

        /* A stream buffer requires a StreamBuffer_t_core2 structure and a buffer.
         * Both are allocated in a single call to pvPortMalloc_core2().  The
         * StreamBuffer_t_core2 structure is placed at the start of the allocated memory
         * and the buffer follows immediately after.  The requested size is
         * incremented so the free space is returned as the user would expect -
         * this is a quirk of the implementation that means otherwise the free
         * space would be reported as one byte smaller than would be logically
         * expected. */
        if( xBufferSizeBytes_core2 < ( xBufferSizeBytes_core2 + 1 + sizeof( StreamBuffer_t_core2 ) ) )
        {
            xBufferSizeBytes_core2++;
            pucAllocatedMemory_core2 = ( uint8_t * ) pvPortMalloc_core2( xBufferSizeBytes_core2 + sizeof( StreamBuffer_t_core2 ) ); /*lint !e9079 malloc() only returns void*. */
        }
        else
        {
            pucAllocatedMemory_core2 = NULL;
        }

        if( pucAllocatedMemory_core2 != NULL )
        {
            prvInitialiseNewStreamBuffer_core2( ( StreamBuffer_t_core2 * ) pucAllocatedMemory_core2,       /* Structure at the start of the allocated memory. */ /*lint !e9087 Safe cast as allocated memory is aligned. */ /*lint !e826 Area is not too small and alignment is guaranteed provided malloc() behaves as expected and returns aligned buffer. */
                                          pucAllocatedMemory_core2 + sizeof( StreamBuffer_t_core2 ), /* Storage area follows. */ /*lint !e9016 Indexing past structure valid for uint8_t pointer, also storage area has no alignment requirement. */
                                          xBufferSizeBytes_core2,
                                          xTriggerLevelBytes_core2,
                                          ucFlags_core2,
                                          pxSendCompletedCallback_core2,
                                          pxReceiveCompletedCallback_core2 );

            traceSTREAM_BUFFER_CREATE_core2( ( ( StreamBuffer_t_core2 * ) pucAllocatedMemory_core2 ), xIsMessageBuffer_core2 );
        }
        else
        {
            traceSTREAM_BUFFER_CREATE_FAILED_core2( xIsMessageBuffer_core2 );
        }

        return ( StreamBufferHandle_t_core2 ) pucAllocatedMemory_core2; /*lint !e9087 !e826 Safe cast as allocated memory is aligned. */
    }
#endif /* configSUPPORT_DYNAMIC_ALLOCATION_core2 */
/*-----------------------------------------------------------*/

#if ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 )

    StreamBufferHandle_t_core2 xStreamBufferGenericCreateStatic_core2( size_t xBufferSizeBytes_core2,
                                                           size_t xTriggerLevelBytes_core2,
                                                           BaseType_t_core2 xIsMessageBuffer_core2,
                                                           uint8_t * const pucStreamBufferStorageArea_core2,
                                                           StaticStreamBuffer_t_core2 * const pxStaticStreamBuffer_core2,
                                                           StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                                           StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 )
    {
        StreamBuffer_t_core2 * const pxStreamBuffer_core2 = ( StreamBuffer_t_core2 * ) pxStaticStreamBuffer_core2; /*lint !e740 !e9087 Safe cast as StaticStreamBuffer_t_core2 is opaque Streambuffer_t. */
        StreamBufferHandle_t_core2 xReturn_core2;
        uint8_t ucFlags_core2;

        configASSERT_core2( pucStreamBufferStorageArea_core2 );
        configASSERT_core2( pxStaticStreamBuffer_core2 );
        configASSERT_core2( xTriggerLevelBytes_core2 <= xBufferSizeBytes_core2 );

        /* A trigger level of 0 would cause a waiting task_core2 to unblock even when
         * the buffer was empty. */
        if( xTriggerLevelBytes_core2 == ( size_t ) 0 )
        {
            xTriggerLevelBytes_core2 = ( size_t ) 1;
        }

        if( xIsMessageBuffer_core2 != pdFALSE_core2 )
        {
            /* Statically allocated message buffer. */
            ucFlags_core2 = sbFLAGS_IS_MESSAGE_BUFFER_core2 | sbFLAGS_IS_STATICALLY_ALLOCATED_core2;
        }
        else
        {
            /* Statically allocated stream buffer. */
            ucFlags_core2 = sbFLAGS_IS_STATICALLY_ALLOCATED_core2;
        }

        /* In case the stream buffer is going to be used as a message buffer
         * (that is, it will hold discrete messages with a little meta data that
         * says how big the next message is) check the buffer will be large enough
         * to hold at least one message. */
        configASSERT_core2( xBufferSizeBytes_core2 > sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 );

        #if ( configASSERT_DEFINED_core2 == 1 )
        {
            /* Sanity check that the size of the structure used to declare a
             * variable of type StaticStreamBuffer_t_core2 equals the size of the real
             * message buffer structure. */
            volatile size_t xSize_core2 = sizeof( StaticStreamBuffer_t_core2 );
            configASSERT_core2( xSize_core2 == sizeof( StreamBuffer_t_core2 ) );
        } /*lint !e529 xSize_core2 is referenced is configASSERT_core2() is defined. */
        #endif /* configASSERT_DEFINED_core2 */

        if( ( pucStreamBufferStorageArea_core2 != NULL ) && ( pxStaticStreamBuffer_core2 != NULL ) )
        {
            prvInitialiseNewStreamBuffer_core2( pxStreamBuffer_core2,
                                          pucStreamBufferStorageArea_core2,
                                          xBufferSizeBytes_core2,
                                          xTriggerLevelBytes_core2,
                                          ucFlags_core2,
                                          pxSendCompletedCallback_core2,
                                          pxReceiveCompletedCallback_core2 );

            /* Remember this was statically allocated in case it is ever deleted
             * again. */
            pxStreamBuffer_core2->ucFlags_core2 |= sbFLAGS_IS_STATICALLY_ALLOCATED_core2;

            traceSTREAM_BUFFER_CREATE_core2( pxStreamBuffer_core2, xIsMessageBuffer_core2 );

            xReturn_core2 = ( StreamBufferHandle_t_core2 ) pxStaticStreamBuffer_core2; /*lint !e9087 Data hiding requires cast to opaque type. */
        }
        else
        {
            xReturn_core2 = NULL;
            traceSTREAM_BUFFER_CREATE_STATIC_FAILED_core2( xReturn_core2, xIsMessageBuffer_core2 );
        }

        return xReturn_core2;
    }
#endif /* ( configSUPPORT_STATIC_ALLOCATION_core2 == 1 ) */
/*-----------------------------------------------------------*/

void vStreamBufferDelete_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
{
    StreamBuffer_t_core2 * pxStreamBuffer_core2 = xStreamBuffer_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    traceSTREAM_BUFFER_DELETE_core2( xStreamBuffer_core2 );

    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_STATICALLY_ALLOCATED_core2 ) == ( uint8_t ) pdFALSE_core2 )
    {
        #if ( configSUPPORT_DYNAMIC_ALLOCATION_core2 == 1 )
        {
            /* Both the structure and the buffer were allocated using a single call
            * to pvPortMalloc_core2(), hence only one call to vPortFree_core2() is required. */
            vPortFree_core2( ( void * ) pxStreamBuffer_core2 ); /*lint !e9087 Standard free() semantics require void *, plus pxStreamBuffer_core2 was allocated by pvPortMalloc_core2(). */
        }
        #else
        {
            /* Should not be possible to get here, ucFlags_core2 must be corrupt.
             * Force an assert. */
            configASSERT_core2( xStreamBuffer_core2 == ( StreamBufferHandle_t_core2 ) ~0 );
        }
        #endif
    }
    else
    {
        /* The structure and buffer were not allocated dynamically and cannot be
         * freed - just scrub the structure so future use will assert. */
        ( void ) memset( pxStreamBuffer_core2, 0x00, sizeof( StreamBuffer_t_core2 ) );
    }
}
/*-----------------------------------------------------------*/

BaseType_t_core2 xStreamBufferReset_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    BaseType_t_core2 xReturn_core2 = pdFAIL_core2;
    StreamBufferCallbackFunction_t_core2 pxSendCallback_core2 = NULL, pxReceiveCallback_core2 = NULL;

    #if ( configUSE_TRACE_FACILITY_core2 == 1 )
        UBaseType_t_core2 uxStreamBufferNumber_core2;
    #endif

    configASSERT_core2( pxStreamBuffer_core2 );

    #if ( configUSE_TRACE_FACILITY_core2 == 1 )
    {
        /* Store the stream buffer number so it can be restored after the
         * reset. */
        uxStreamBufferNumber_core2 = pxStreamBuffer_core2->uxStreamBufferNumber_core2;
    }
    #endif

    /* Can only reset a message buffer if there are no tasks blocked on it. */
    taskENTER_CRITICAL_core2();
    {
        if( ( pxStreamBuffer_core2->xTaskWaitingToReceive_core2 == NULL ) && ( pxStreamBuffer_core2->xTaskWaitingToSend_core2 == NULL ) )
        {
            #if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
            {
                pxSendCallback_core2 = pxStreamBuffer_core2->pxSendCompletedCallback_core2;
                pxReceiveCallback_core2 = pxStreamBuffer_core2->pxReceiveCompletedCallback_core2;
            }
            #endif

            prvInitialiseNewStreamBuffer_core2( pxStreamBuffer_core2,
                                          pxStreamBuffer_core2->pucBuffer_core2,
                                          pxStreamBuffer_core2->xLength_core2,
                                          pxStreamBuffer_core2->xTriggerLevelBytes_core2,
                                          pxStreamBuffer_core2->ucFlags_core2,
                                          pxSendCallback_core2,
                                          pxReceiveCallback_core2 );

            #if ( configUSE_TRACE_FACILITY_core2 == 1 )
            {
                pxStreamBuffer_core2->uxStreamBufferNumber_core2 = uxStreamBufferNumber_core2;
            }
            #endif

            traceSTREAM_BUFFER_RESET_core2( xStreamBuffer_core2 );

            xReturn_core2 = pdPASS_core2;
        }
    }
    taskEXIT_CRITICAL_core2();

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

BaseType_t_core2 xStreamBufferSetTriggerLevel_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                         size_t xTriggerLevel_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    BaseType_t_core2 xReturn_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    /* It is not valid for the trigger level to be 0. */
    if( xTriggerLevel_core2 == ( size_t ) 0 )
    {
        xTriggerLevel_core2 = ( size_t ) 1;
    }

    /* The trigger level is the number of bytes that must be in the stream
     * buffer before a task_core2 that is waiting for data is unblocked. */
    if( xTriggerLevel_core2 < pxStreamBuffer_core2->xLength_core2 )
    {
        pxStreamBuffer_core2->xTriggerLevelBytes_core2 = xTriggerLevel_core2;
        xReturn_core2 = pdPASS_core2;
    }
    else
    {
        xReturn_core2 = pdFALSE_core2;
    }

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferSpacesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
{
    const StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    size_t xSpace_core2;
    size_t xOriginalTail_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    /* The code below reads xTail_core2 and then xHead_core2.  This is safe if the stream
     * buffer is updated once between the two reads - but not if the stream buffer
     * is updated more than once between the two reads - hence the loop. */
    do
    {
        xOriginalTail_core2 = pxStreamBuffer_core2->xTail_core2;
        xSpace_core2 = pxStreamBuffer_core2->xLength_core2 + pxStreamBuffer_core2->xTail_core2;
        xSpace_core2 -= pxStreamBuffer_core2->xHead_core2;
    } while( xOriginalTail_core2 != pxStreamBuffer_core2->xTail_core2 );

    xSpace_core2 -= ( size_t ) 1;

    if( xSpace_core2 >= pxStreamBuffer_core2->xLength_core2 )
    {
        xSpace_core2 -= pxStreamBuffer_core2->xLength_core2;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    return xSpace_core2;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferBytesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
{
    const StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    size_t xReturn_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    xReturn_core2 = prvBytesInBuffer_core2( pxStreamBuffer_core2 );
    return xReturn_core2;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferSend_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                          const void * pvTxData_core2,
                          size_t xDataLengthBytes_core2,
                          TickType_t_core2 xTicksToWait_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    size_t xReturn_core2, xSpace_core2 = 0;
    size_t xRequiredSpace_core2 = xDataLengthBytes_core2;
    TimeOut_t_core2 xTimeOut;
    size_t xMaxReportedSpace_core2 = 0;

    configASSERT_core2( pvTxData_core2 );
    configASSERT_core2( pxStreamBuffer_core2 );

    /* The maximum amount of space a stream buffer will ever report is its length
     * minus 1. */
    xMaxReportedSpace_core2 = pxStreamBuffer_core2->xLength_core2 - ( size_t ) 1;

    /* This send function is used to write to both message buffers and stream
     * buffers.  If this is a message buffer then the space needed must be
     * increased by the amount of bytes needed to store the length of the
     * message. */
    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        xRequiredSpace_core2 += sbBYTES_TO_STORE_MESSAGE_LENGTH_core2;

        /* Overflow? */
        configASSERT_core2( xRequiredSpace_core2 > xDataLengthBytes_core2 );

        /* If this is a message buffer then it must be possible to write the
         * whole message. */
        if( xRequiredSpace_core2 > xMaxReportedSpace_core2 )
        {
            /* The message would not fit even if the entire buffer was empty,
             * so don't wait for space. */
            xTicksToWait_core2 = ( TickType_t_core2 ) 0;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    else
    {
        /* If this is a stream buffer then it is acceptable to write only part
         * of the message to the buffer.  Cap the length to the total length of
         * the buffer. */
        if( xRequiredSpace_core2 > xMaxReportedSpace_core2 )
        {
            xRequiredSpace_core2 = xMaxReportedSpace_core2;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }

    if( xTicksToWait_core2 != ( TickType_t_core2 ) 0 )
    {
        vTaskSetTimeOutState_core2( &xTimeOut );

        do
        {
            /* Wait until the required number of bytes are free in the message
             * buffer. */
            taskENTER_CRITICAL_core2();
            {
                xSpace_core2 = xStreamBufferSpacesAvailable_core2( pxStreamBuffer_core2 );

                if( xSpace_core2 < xRequiredSpace_core2 )
                {
                    /* Clear notification state as going to wait for space. */
                    ( void ) xTaskNotifyStateClear_core2( NULL );

                    /* Should only be one writer. */
                    configASSERT_core2( pxStreamBuffer_core2->xTaskWaitingToSend_core2 == NULL );
                    pxStreamBuffer_core2->xTaskWaitingToSend_core2 = xTaskGetCurrentTaskHandle_core2();
                }
                else
                {
                    taskEXIT_CRITICAL_core2();
                    break;
                }
            }
            taskEXIT_CRITICAL_core2();

            traceBLOCKING_ON_STREAM_BUFFER_SEND_core2( xStreamBuffer_core2 );
            ( void ) xTaskNotifyWait_core2( ( uint32_t ) 0, ( uint32_t ) 0, NULL, xTicksToWait_core2 );
            pxStreamBuffer_core2->xTaskWaitingToSend_core2 = NULL;
        } while( xTaskCheckForTimeOut_core2( &xTimeOut, &xTicksToWait_core2 ) == pdFALSE_core2 );
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    if( xSpace_core2 == ( size_t ) 0 )
    {
        xSpace_core2 = xStreamBufferSpacesAvailable_core2( pxStreamBuffer_core2 );
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    xReturn_core2 = prvWriteMessageToBuffer_core2( pxStreamBuffer_core2, pvTxData_core2, xDataLengthBytes_core2, xSpace_core2, xRequiredSpace_core2 );

    if( xReturn_core2 > ( size_t ) 0 )
    {
        traceSTREAM_BUFFER_SEND_core2( xStreamBuffer_core2, xReturn_core2 );

        /* Was a task_core2 waiting for the data? */
        if( prvBytesInBuffer_core2( pxStreamBuffer_core2 ) >= pxStreamBuffer_core2->xTriggerLevelBytes_core2 )
        {
            prvSEND_COMPLETED_core2( pxStreamBuffer_core2 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
        traceSTREAM_BUFFER_SEND_FAILED_core2( xStreamBuffer_core2 );
    }

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferSendFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                 const void * pvTxData_core2,
                                 size_t xDataLengthBytes_core2,
                                 BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    size_t xReturn_core2, xSpace_core2;
    size_t xRequiredSpace_core2 = xDataLengthBytes_core2;

    configASSERT_core2( pvTxData_core2 );
    configASSERT_core2( pxStreamBuffer_core2 );

    /* This send function is used to write to both message buffers and stream
     * buffers.  If this is a message buffer then the space needed must be
     * increased by the amount of bytes needed to store the length of the
     * message. */
    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        xRequiredSpace_core2 += sbBYTES_TO_STORE_MESSAGE_LENGTH_core2;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    xSpace_core2 = xStreamBufferSpacesAvailable_core2( pxStreamBuffer_core2 );
    xReturn_core2 = prvWriteMessageToBuffer_core2( pxStreamBuffer_core2, pvTxData_core2, xDataLengthBytes_core2, xSpace_core2, xRequiredSpace_core2 );

    if( xReturn_core2 > ( size_t ) 0 )
    {
        /* Was a task_core2 waiting for the data? */
        if( prvBytesInBuffer_core2( pxStreamBuffer_core2 ) >= pxStreamBuffer_core2->xTriggerLevelBytes_core2 )
        {
            prvSEND_COMPLETE_FROM_ISR_core2( pxStreamBuffer_core2, pxHigherPriorityTaskWoken_core2 );
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

    traceSTREAM_BUFFER_SEND_FROM_ISR_core2( xStreamBuffer_core2, xReturn_core2 );

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

static size_t prvWriteMessageToBuffer_core2( StreamBuffer_t_core2 * const pxStreamBuffer_core2,
                                       const void * pvTxData_core2,
                                       size_t xDataLengthBytes_core2,
                                       size_t xSpace_core2,
                                       size_t xRequiredSpace_core2 )
{
    size_t xNextHead_core2 = pxStreamBuffer_core2->xHead_core2;
    configMESSAGE_BUFFER_LENGTH_TYPE_core2 xMessageLength_core2;

    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        /* This is a message buffer, as opposed to a stream buffer. */

        /* Convert xDataLengthBytes_core2 to the message length type. */
        xMessageLength_core2 = ( configMESSAGE_BUFFER_LENGTH_TYPE_core2 ) xDataLengthBytes_core2;

        /* Ensure the data length given fits within configMESSAGE_BUFFER_LENGTH_TYPE_core2. */
        configASSERT_core2( ( size_t ) xMessageLength_core2 == xDataLengthBytes_core2 );

        if( xSpace_core2 >= xRequiredSpace_core2 )
        {
            /* There is enough space to write both the message length and the message
             * itself into the buffer.  Start by writing the length of the data, the data
             * itself will be written later in this function. */
            xNextHead_core2 = prvWriteBytesToBuffer_core2( pxStreamBuffer_core2, ( const uint8_t * ) &( xMessageLength_core2 ), sbBYTES_TO_STORE_MESSAGE_LENGTH_core2, xNextHead_core2 );
        }
        else
        {
            /* Not enough space, so do not write data to the buffer. */
            xDataLengthBytes_core2 = 0;
        }
    }
    else
    {
        /* This is a stream buffer, as opposed to a message buffer, so writing a
         * stream of bytes rather than discrete messages.  Plan to write as many
         * bytes as possible. */
        xDataLengthBytes_core2 = configMIN_core2( xDataLengthBytes_core2, xSpace_core2 );
    }

    if( xDataLengthBytes_core2 != ( size_t ) 0 )
    {
        /* Write the data to the buffer. */
        pxStreamBuffer_core2->xHead_core2 = prvWriteBytesToBuffer_core2( pxStreamBuffer_core2, ( const uint8_t * ) pvTxData_core2, xDataLengthBytes_core2, xNextHead_core2 ); /*lint !e9079 Storage buffer is implemented as uint8_t for ease of sizing, alignment and access. */
    }

    return xDataLengthBytes_core2;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferReceive_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                             void * pvRxData_core2,
                             size_t xBufferLengthBytes_core2,
                             TickType_t_core2 xTicksToWait_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    size_t xReceivedLength_core2 = 0, xBytesAvailable_core2, xBytesToStoreMessageLength_core2;

    configASSERT_core2( pvRxData_core2 );
    configASSERT_core2( pxStreamBuffer_core2 );

    /* This receive function is used by both message buffers, which store
     * discrete messages, and stream buffers, which store a continuous stream of
     * bytes.  Discrete messages include an additional
     * sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 bytes that hold the length of the
     * message. */
    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        xBytesToStoreMessageLength_core2 = sbBYTES_TO_STORE_MESSAGE_LENGTH_core2;
    }
    else
    {
        xBytesToStoreMessageLength_core2 = 0;
    }

    if( xTicksToWait_core2 != ( TickType_t_core2 ) 0 )
    {
        /* Checking if there is data and clearing the notification state must be
         * performed atomically. */
        taskENTER_CRITICAL_core2();
        {
            xBytesAvailable_core2 = prvBytesInBuffer_core2( pxStreamBuffer_core2 );

            /* If this function was invoked by a message buffer read then
             * xBytesToStoreMessageLength_core2 holds the number of bytes used to hold
             * the length of the next discrete message.  If this function was
             * invoked by a stream buffer read then xBytesToStoreMessageLength_core2 will
             * be 0. */
            if( xBytesAvailable_core2 <= xBytesToStoreMessageLength_core2 )
            {
                /* Clear notification state as going to wait for data. */
                ( void ) xTaskNotifyStateClear_core2( NULL );

                /* Should only be one reader. */
                configASSERT_core2( pxStreamBuffer_core2->xTaskWaitingToReceive_core2 == NULL );
                pxStreamBuffer_core2->xTaskWaitingToReceive_core2 = xTaskGetCurrentTaskHandle_core2();
            }
            else
            {
                mtCOVERAGE_TEST_MARKER_core2();
            }
        }
        taskEXIT_CRITICAL_core2();

        if( xBytesAvailable_core2 <= xBytesToStoreMessageLength_core2 )
        {
            /* Wait for data to be available. */
            traceBLOCKING_ON_STREAM_BUFFER_RECEIVE_core2( xStreamBuffer_core2 );
            ( void ) xTaskNotifyWait_core2( ( uint32_t ) 0, ( uint32_t ) 0, NULL, xTicksToWait_core2 );
            pxStreamBuffer_core2->xTaskWaitingToReceive_core2 = NULL;

            /* Recheck the data available after blocking. */
            xBytesAvailable_core2 = prvBytesInBuffer_core2( pxStreamBuffer_core2 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    else
    {
        xBytesAvailable_core2 = prvBytesInBuffer_core2( pxStreamBuffer_core2 );
    }

    /* Whether receiving a discrete message (where xBytesToStoreMessageLength_core2
     * holds the number of bytes used to store the message length) or a stream of
     * bytes (where xBytesToStoreMessageLength_core2 is zero), the number of bytes
     * available must be greater than xBytesToStoreMessageLength_core2 to be able to
     * read bytes from the buffer. */
    if( xBytesAvailable_core2 > xBytesToStoreMessageLength_core2 )
    {
        xReceivedLength_core2 = prvReadMessageFromBuffer_core2( pxStreamBuffer_core2, pvRxData_core2, xBufferLengthBytes_core2, xBytesAvailable_core2 );

        /* Was a task_core2 waiting for space in the buffer? */
        if( xReceivedLength_core2 != ( size_t ) 0 )
        {
            traceSTREAM_BUFFER_RECEIVE_core2( xStreamBuffer_core2, xReceivedLength_core2 );
            prvRECEIVE_COMPLETED_core2( xStreamBuffer_core2 );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    else
    {
        traceSTREAM_BUFFER_RECEIVE_FAILED_core2( xStreamBuffer_core2 );
        mtCOVERAGE_TEST_MARKER_core2();
    }

    return xReceivedLength_core2;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferNextMessageLengthBytes_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    size_t xReturn_core2, xBytesAvailable_core2;
    configMESSAGE_BUFFER_LENGTH_TYPE_core2 xTempReturn_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    /* Ensure the stream buffer is being used as a message buffer. */
    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        xBytesAvailable_core2 = prvBytesInBuffer_core2( pxStreamBuffer_core2 );

        if( xBytesAvailable_core2 > sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 )
        {
            /* The number of bytes available is greater than the number of bytes
             * required to hold the length of the next message, so another message
             * is available. */
            ( void ) prvReadBytesFromBuffer_core2( pxStreamBuffer_core2, ( uint8_t * ) &xTempReturn_core2, sbBYTES_TO_STORE_MESSAGE_LENGTH_core2, pxStreamBuffer_core2->xTail_core2 );
            xReturn_core2 = ( size_t ) xTempReturn_core2;
        }
        else
        {
            /* The minimum amount of bytes in a message buffer is
             * ( sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 + 1 ), so if xBytesAvailable_core2 is
             * less than sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 the only other valid
             * value is 0. */
            configASSERT_core2( xBytesAvailable_core2 == 0 );
            xReturn_core2 = 0;
        }
    }
    else
    {
        xReturn_core2 = 0;
    }

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

size_t xStreamBufferReceiveFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                    void * pvRxData_core2,
                                    size_t xBufferLengthBytes_core2,
                                    BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    size_t xReceivedLength_core2 = 0, xBytesAvailable_core2, xBytesToStoreMessageLength_core2;

    configASSERT_core2( pvRxData_core2 );
    configASSERT_core2( pxStreamBuffer_core2 );

    /* This receive function is used by both message buffers, which store
     * discrete messages, and stream buffers, which store a continuous stream of
     * bytes.  Discrete messages include an additional
     * sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 bytes that hold the length of the
     * message. */
    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        xBytesToStoreMessageLength_core2 = sbBYTES_TO_STORE_MESSAGE_LENGTH_core2;
    }
    else
    {
        xBytesToStoreMessageLength_core2 = 0;
    }

    xBytesAvailable_core2 = prvBytesInBuffer_core2( pxStreamBuffer_core2 );

    /* Whether receiving a discrete message (where xBytesToStoreMessageLength_core2
     * holds the number of bytes used to store the message length) or a stream of
     * bytes (where xBytesToStoreMessageLength_core2 is zero), the number of bytes
     * available must be greater than xBytesToStoreMessageLength_core2 to be able to
     * read bytes from the buffer. */
    if( xBytesAvailable_core2 > xBytesToStoreMessageLength_core2 )
    {
        xReceivedLength_core2 = prvReadMessageFromBuffer_core2( pxStreamBuffer_core2, pvRxData_core2, xBufferLengthBytes_core2, xBytesAvailable_core2 );

        /* Was a task_core2 waiting for space in the buffer? */
        if( xReceivedLength_core2 != ( size_t ) 0 )
        {
            prvRECEIVE_COMPLETED_FROM_ISR_core2( pxStreamBuffer_core2, pxHigherPriorityTaskWoken_core2 );
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

    traceSTREAM_BUFFER_RECEIVE_FROM_ISR_core2( xStreamBuffer_core2, xReceivedLength_core2 );

    return xReceivedLength_core2;
}
/*-----------------------------------------------------------*/

static size_t prvReadMessageFromBuffer_core2( StreamBuffer_t_core2 * pxStreamBuffer_core2,
                                        void * pvRxData_core2,
                                        size_t xBufferLengthBytes_core2,
                                        size_t xBytesAvailable_core2 )
{
    size_t xCount_core2, xNextMessageLength_core2;
    configMESSAGE_BUFFER_LENGTH_TYPE_core2 xTempNextMessageLength_core2;
    size_t xNextTail_core2 = pxStreamBuffer_core2->xTail_core2;

    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        /* A discrete message is being received.  First receive the length
         * of the message. */
        xNextTail_core2 = prvReadBytesFromBuffer_core2( pxStreamBuffer_core2, ( uint8_t * ) &xTempNextMessageLength_core2, sbBYTES_TO_STORE_MESSAGE_LENGTH_core2, xNextTail_core2 );
        xNextMessageLength_core2 = ( size_t ) xTempNextMessageLength_core2;

        /* Reduce the number of bytes available by the number of bytes just
         * read out. */
        xBytesAvailable_core2 -= sbBYTES_TO_STORE_MESSAGE_LENGTH_core2;

        /* Check there is enough space in the buffer provided by the
         * user. */
        if( xNextMessageLength_core2 > xBufferLengthBytes_core2 )
        {
            /* The user has provided insufficient space to read the message. */
            xNextMessageLength_core2 = 0;
        }
        else
        {
            mtCOVERAGE_TEST_MARKER_core2();
        }
    }
    else
    {
        /* A stream of bytes is being received (as opposed to a discrete
         * message), so read as many bytes as possible. */
        xNextMessageLength_core2 = xBufferLengthBytes_core2;
    }

    /* Use the minimum of the wanted bytes and the available bytes. */
    xCount_core2 = configMIN_core2( xNextMessageLength_core2, xBytesAvailable_core2 );

    if( xCount_core2 != ( size_t ) 0 )
    {
        /* Read the actual data and update the tail to mark the data as officially consumed. */
        pxStreamBuffer_core2->xTail_core2 = prvReadBytesFromBuffer_core2( pxStreamBuffer_core2, ( uint8_t * ) pvRxData_core2, xCount_core2, xNextTail_core2 ); /*lint !e9079 Data storage area is implemented as uint8_t array for ease of sizing, indexing and alignment. */
    }

    return xCount_core2;
}
/*-----------------------------------------------------------*/

BaseType_t_core2 xStreamBufferIsEmpty_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
{
    const StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    BaseType_t_core2 xReturn_core2;
    size_t xTail_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    /* True if no bytes are available. */
    xTail_core2 = pxStreamBuffer_core2->xTail_core2;

    if( pxStreamBuffer_core2->xHead_core2 == xTail_core2 )
    {
        xReturn_core2 = pdTRUE_core2;
    }
    else
    {
        xReturn_core2 = pdFALSE_core2;
    }

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

BaseType_t_core2 xStreamBufferIsFull_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
{
    BaseType_t_core2 xReturn_core2;
    size_t xBytesToStoreMessageLength_core2;
    const StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    /* This generic version of the receive function is used by both message
     * buffers, which store discrete messages, and stream buffers, which store a
     * continuous stream of bytes.  Discrete messages include an additional
     * sbBYTES_TO_STORE_MESSAGE_LENGTH_core2 bytes that hold the length of the message. */
    if( ( pxStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 ) != ( uint8_t ) 0 )
    {
        xBytesToStoreMessageLength_core2 = sbBYTES_TO_STORE_MESSAGE_LENGTH_core2;
    }
    else
    {
        xBytesToStoreMessageLength_core2 = 0;
    }

    /* True if the available space equals zero. */
    if( xStreamBufferSpacesAvailable_core2( xStreamBuffer_core2 ) <= xBytesToStoreMessageLength_core2 )
    {
        xReturn_core2 = pdTRUE_core2;
    }
    else
    {
        xReturn_core2 = pdFALSE_core2;
    }

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

BaseType_t_core2 xStreamBufferSendCompletedFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                              BaseType_t_core2 * pxHigherPriorityTaskWoken_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    BaseType_t_core2 xReturn_core2;
    UBaseType_t_core2 uxSavedInterruptStatus_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    uxSavedInterruptStatus_core2 = ( UBaseType_t_core2 ) portSET_INTERRUPT_MASK_FROM_ISR_core2();
    {
        if( ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2 != NULL )
        {
            ( void ) xTaskNotifyFromISR_core2( ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2,
                                         ( uint32_t ) 0,
                                         eNoAction_core2,
                                         pxHigherPriorityTaskWoken_core2 );
            ( pxStreamBuffer_core2 )->xTaskWaitingToReceive_core2 = NULL;
            xReturn_core2 = pdTRUE_core2;
        }
        else
        {
            xReturn_core2 = pdFALSE_core2;
        }
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core2( uxSavedInterruptStatus_core2 );

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

BaseType_t_core2 xStreamBufferReceiveCompletedFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                                 BaseType_t_core2 * pxHigherPriorityTaskWoken_core2 )
{
    StreamBuffer_t_core2 * const pxStreamBuffer_core2 = xStreamBuffer_core2;
    BaseType_t_core2 xReturn_core2;
    UBaseType_t_core2 uxSavedInterruptStatus_core2;

    configASSERT_core2( pxStreamBuffer_core2 );

    uxSavedInterruptStatus_core2 = ( UBaseType_t_core2 ) portSET_INTERRUPT_MASK_FROM_ISR_core2();
    {
        if( ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2 != NULL )
        {
            ( void ) xTaskNotifyFromISR_core2( ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2,
                                         ( uint32_t ) 0,
                                         eNoAction_core2,
                                         pxHigherPriorityTaskWoken_core2 );
            ( pxStreamBuffer_core2 )->xTaskWaitingToSend_core2 = NULL;
            xReturn_core2 = pdTRUE_core2;
        }
        else
        {
            xReturn_core2 = pdFALSE_core2;
        }
    }
    portCLEAR_INTERRUPT_MASK_FROM_ISR_core2( uxSavedInterruptStatus_core2 );

    return xReturn_core2;
}
/*-----------------------------------------------------------*/

static size_t prvWriteBytesToBuffer_core2( StreamBuffer_t_core2 * const pxStreamBuffer_core2,
                                     const uint8_t * pucData_core2,
                                     size_t xCount_core2,
                                     size_t xHead_core2 )
{
    size_t xFirstLength_core2;

    configASSERT_core2( xCount_core2 > ( size_t ) 0 );

    /* Calculate the number of bytes that can be added in the first write -
     * which may be less than the total number of bytes that need to be added if
     * the buffer will wrap back to the beginning. */
    xFirstLength_core2 = configMIN_core2( pxStreamBuffer_core2->xLength_core2 - xHead_core2, xCount_core2 );

    /* Write as many bytes as can be written in the first write. */
    configASSERT_core2( ( xHead_core2 + xFirstLength_core2 ) <= pxStreamBuffer_core2->xLength_core2 );
    ( void ) memcpy( ( void * ) ( &( pxStreamBuffer_core2->pucBuffer_core2[ xHead_core2 ] ) ), ( const void * ) pucData_core2, xFirstLength_core2 ); /*lint !e9087 memcpy() requires void *. */

    /* If the number of bytes written was less than the number that could be
     * written in the first write... */
    if( xCount_core2 > xFirstLength_core2 )
    {
        /* ...then write the remaining bytes to the start of the buffer. */
        configASSERT_core2( ( xCount_core2 - xFirstLength_core2 ) <= pxStreamBuffer_core2->xLength_core2 );
        ( void ) memcpy( ( void * ) pxStreamBuffer_core2->pucBuffer_core2, ( const void * ) &( pucData_core2[ xFirstLength_core2 ] ), xCount_core2 - xFirstLength_core2 ); /*lint !e9087 memcpy() requires void *. */
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    xHead_core2 += xCount_core2;

    if( xHead_core2 >= pxStreamBuffer_core2->xLength_core2 )
    {
        xHead_core2 -= pxStreamBuffer_core2->xLength_core2;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    return xHead_core2;
}
/*-----------------------------------------------------------*/

static size_t prvReadBytesFromBuffer_core2( StreamBuffer_t_core2 * pxStreamBuffer_core2,
                                      uint8_t * pucData_core2,
                                      size_t xCount_core2,
                                      size_t xTail_core2 )
{
    size_t xFirstLength_core2;

    configASSERT_core2( xCount_core2 != ( size_t ) 0 );

    /* Calculate the number of bytes that can be read - which may be
     * less than the number wanted if the data wraps around to the start of
     * the buffer. */
    xFirstLength_core2 = configMIN_core2( pxStreamBuffer_core2->xLength_core2 - xTail_core2, xCount_core2 );

    /* Obtain the number of bytes it is possible to obtain in the first
     * read.  Asserts check bounds of read and write. */
    configASSERT_core2( xFirstLength_core2 <= xCount_core2 );
    configASSERT_core2( ( xTail_core2 + xFirstLength_core2 ) <= pxStreamBuffer_core2->xLength_core2 );
    ( void ) memcpy( ( void * ) pucData_core2, ( const void * ) &( pxStreamBuffer_core2->pucBuffer_core2[ xTail_core2 ] ), xFirstLength_core2 ); /*lint !e9087 memcpy() requires void *. */

    /* If the total number of wanted bytes is greater than the number
     * that could be read in the first read... */
    if( xCount_core2 > xFirstLength_core2 )
    {
        /* ...then read the remaining bytes from the start of the buffer. */
        ( void ) memcpy( ( void * ) &( pucData_core2[ xFirstLength_core2 ] ), ( void * ) ( pxStreamBuffer_core2->pucBuffer_core2 ), xCount_core2 - xFirstLength_core2 ); /*lint !e9087 memcpy() requires void *. */
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    /* Move the tail pointer to effectively remove the data read from the buffer. */
    xTail_core2 += xCount_core2;

    if( xTail_core2 >= pxStreamBuffer_core2->xLength_core2 )
    {
        xTail_core2 -= pxStreamBuffer_core2->xLength_core2;
    }

    return xTail_core2;
}
/*-----------------------------------------------------------*/

static size_t prvBytesInBuffer_core2( const StreamBuffer_t_core2 * const pxStreamBuffer_core2 )
{
/* Returns the distance between xTail_core2 and xHead_core2. */
    size_t xCount_core2;

    xCount_core2 = pxStreamBuffer_core2->xLength_core2 + pxStreamBuffer_core2->xHead_core2;
    xCount_core2 -= pxStreamBuffer_core2->xTail_core2;

    if( xCount_core2 >= pxStreamBuffer_core2->xLength_core2 )
    {
        xCount_core2 -= pxStreamBuffer_core2->xLength_core2;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER_core2();
    }

    return xCount_core2;
}
/*-----------------------------------------------------------*/

static void prvInitialiseNewStreamBuffer_core2( StreamBuffer_t_core2 * const pxStreamBuffer_core2,
                                          uint8_t * const pucBuffer_core2,
                                          size_t xBufferSizeBytes_core2,
                                          size_t xTriggerLevelBytes_core2,
                                          uint8_t ucFlags_core2,
                                          StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                          StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 )
{
    /* Assert here is deliberately writing to the entire buffer to ensure it can
     * be written to without generating exceptions, and is setting the buffer to a
     * known value to assist in development/debugging. */
    #if ( configASSERT_DEFINED_core2 == 1 )
    {
        /* The value written just has to be identifiable when looking at the
         * memory.  Don't use 0xA5 as that is the stack fill value and could
         * result in confusion as to what is actually being observed. */
        const BaseType_t_core2 xWriteValue_core2 = 0x55;
        configASSERT_core2( memset( pucBuffer_core2, ( int ) xWriteValue_core2, xBufferSizeBytes_core2 ) == pucBuffer_core2 );
    } /*lint !e529 !e438 xWriteValue_core2 is only used if configASSERT_core2() is defined. */
    #endif

    ( void ) memset( ( void * ) pxStreamBuffer_core2, 0x00, sizeof( StreamBuffer_t_core2 ) ); /*lint !e9087 memset() requires void *. */
    pxStreamBuffer_core2->pucBuffer_core2 = pucBuffer_core2;
    pxStreamBuffer_core2->xLength_core2 = xBufferSizeBytes_core2;
    pxStreamBuffer_core2->xTriggerLevelBytes_core2 = xTriggerLevelBytes_core2;
    pxStreamBuffer_core2->ucFlags_core2 = ucFlags_core2;
    #if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    {
        pxStreamBuffer_core2->pxSendCompletedCallback_core2 = pxSendCompletedCallback_core2;
        pxStreamBuffer_core2->pxReceiveCompletedCallback_core2 = pxReceiveCompletedCallback_core2;
    }
    #else
    {
        ( void ) pxSendCompletedCallback_core2;
        ( void ) pxReceiveCompletedCallback_core2;
    }
    #endif
}

#if ( configUSE_TRACE_FACILITY_core2 == 1 )

    UBaseType_t_core2 uxStreamBufferGetStreamBufferNumber_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
    {
        return xStreamBuffer_core2->uxStreamBufferNumber_core2;
    }

#endif /* configUSE_TRACE_FACILITY_core2 */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core2 == 1 )

    void vStreamBufferSetStreamBufferNumber_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                             UBaseType_t_core2 uxStreamBufferNumber_core2 )
    {
        xStreamBuffer_core2->uxStreamBufferNumber_core2 = uxStreamBufferNumber_core2;
    }

#endif /* configUSE_TRACE_FACILITY_core2 */
/*-----------------------------------------------------------*/

#if ( configUSE_TRACE_FACILITY_core2 == 1 )

    uint8_t ucStreamBufferGetStreamBufferType_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
    {
        return( xStreamBuffer_core2->ucFlags_core2 & sbFLAGS_IS_MESSAGE_BUFFER_core2 );
    }

#endif /* configUSE_TRACE_FACILITY_core2 */
/*-----------------------------------------------------------*/
