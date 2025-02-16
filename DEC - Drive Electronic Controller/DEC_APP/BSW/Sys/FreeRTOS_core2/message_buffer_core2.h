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
 * Message buffers build functionality on top of FreeRTOS_core2 stream buffers.
 * Whereas stream buffers are used to send a continuous stream of data from one
 * task_core2 or interrupt to another, message buffers are used to send variable
 * length discrete messages from one task_core2 or interrupt to another.  Their
 * implementation is light weight, making them particularly suited for interrupt
 * to task_core2 and core to core communication scenarios.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core2 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core2 or
 * interrupt that will write to the buffer (the writer), and only one task_core2 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core2 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xMessageBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xMessageBufferRead()) inside a critical section and set the receive
 * timeout to 0.
 *
 * Message buffers hold variable length messages.  To enable that, when a
 * message is written to the message buffer an additional sizeof( size_t ) bytes
 * are also written to store the message's length (that happens internally, with
 * the API function).  sizeof( size_t ) is typically 4 bytes on a 32-bit
 * architecture, so writing a 10 byte message to a message buffer on a 32-bit
 * architecture will actually reduce the available space in the message buffer
 * by 14 bytes (10 byte are used by the message, and 4 bytes to hold the length
 * of the message).
 */

#ifndef FREERTOS_MESSAGE_BUFFER_CORE2_H
#define FREERTOS_MESSAGE_BUFFER_CORE2_H

#ifndef INC_FREERTOS_CORE2_H
    #error "include FreeRTOS_core2.h must appear in source files before include message_buffer.h"
#endif

/* Message buffers are built onto of stream buffers. */
#include "stream_buffer_core2.h"

/* *INDENT-OFF* */
#if defined( __cplusplus )
    extern "C" {
#endif
/* *INDENT-ON* */

/**
 * Type by which message buffers are referenced.  For example, a call to
 * xMessageBufferCreate_core2() returns an MessageBufferHandle_t_core2 variable that can
 * then be used as a parameter to xMessageBufferSend_core2(), xMessageBufferReceive_core2(),
 * etc. Message buffer is essentially built as a stream buffer hence its handle
 * is also set to same type as a stream buffer handle.
 */
typedef StreamBufferHandle_t_core2 MessageBufferHandle_t_core2;

/*-----------------------------------------------------------*/

/**
 * message_buffer.h
 *
 * @code{c}
 * MessageBufferHandle_t_core2 xMessageBufferCreate_core2( size_t xBufferSizeBytes_core2 );
 * @endcode
 *
 * Creates a new message buffer using dynamically allocated memory.  See
 * xMessageBufferCreateStatic_core2() for a version that uses statically allocated
 * memory (memory that is allocated at compile time).
 *
 * configSUPPORT_DYNAMIC_ALLOCATION_core2 must be set to 1 or left undefined in
 * FreeRTOSConfig.h for xMessageBufferCreate_core2() to be available.
 *
 * @param xBufferSizeBytes_core2 The total number of bytes (not messages) the message
 * buffer will be able to hold at any one time.  When a message is written to
 * the message buffer an additional sizeof( size_t ) bytes are also written to
 * store the message's length.  sizeof( size_t ) is typically 4 bytes on a
 * 32-bit architecture, so on most 32-bit architectures a 10 byte message will
 * take up 14 bytes of message buffer space.
 *
 * @param pxSendCompletedCallback_core2 Callback invoked when a send operation to the
 * message buffer is complete. If the parameter is NULL or xMessageBufferCreate_core2()
 * is called without the parameter, then it will use the default implementation
 * provided by sbSEND_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @param pxReceiveCompletedCallback_core2 Callback invoked when a receive operation from
 * the message buffer is complete. If the parameter is NULL or xMessageBufferCreate_core2()
 * is called without the parameter, it will use the default implementation provided
 * by sbRECEIVE_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @return If NULL is returned, then the message buffer cannot be created
 * because there is insufficient heap memory available for FreeRTOS_core2 to allocate
 * the message buffer data structures and storage area.  A non-NULL value being
 * returned indicates that the message buffer has been created successfully -
 * the returned value should be stored as the handle to the created message
 * buffer.
 *
 * Example use:
 * @code{c}
 *
 * void vAFunction( void )
 * {
 * MessageBufferHandle_t_core2 xMessageBuffer_core2;
 * const size_t xMessageBufferSizeBytes = 100;
 *
 *  // Create a message buffer that can hold 100 bytes.  The memory used to hold
 *  // both the message buffer structure and the messages themselves is allocated
 *  // dynamically.  Each message added to the buffer consumes an additional 4
 *  // bytes which are used to hold the length of the message.
 *  xMessageBuffer_core2 = xMessageBufferCreate_core2( xMessageBufferSizeBytes );
 *
 *  if( xMessageBuffer_core2 == NULL )
 *  {
 *      // There was not enough heap memory space available to create the
 *      // message buffer.
 *  }
 *  else
 *  {
 *      // The message buffer was created successfully and can now be used.
 *  }
 *
 * @endcode
 * \defgroup xMessageBufferCreate_core2 xMessageBufferCreate_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferCreate_core2( xBufferSizeBytes_core2 ) \
    xStreamBufferGenericCreate_core2( ( xBufferSizeBytes_core2 ), ( size_t ) 0, pdTRUE_core2, NULL, NULL )

#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define xMessageBufferCreateWithCallback_core2( xBufferSizeBytes_core2, pxSendCompletedCallback_core2, pxReceiveCompletedCallback_core2 ) \
    xStreamBufferGenericCreate_core2( ( xBufferSizeBytes_core2 ), ( size_t ) 0, pdTRUE_core2, ( pxSendCompletedCallback_core2 ), ( pxReceiveCompletedCallback_core2 ) )
#endif

/**
 * message_buffer.h
 *
 * @code{c}
 * MessageBufferHandle_t_core2 xMessageBufferCreateStatic_core2( size_t xBufferSizeBytes_core2,
 *                                                uint8_t *pucMessageBufferStorageArea_core2,
 *                                                StaticMessageBuffer_t *pxStaticMessageBuffer_core2 );
 * @endcode
 * Creates a new message buffer using statically allocated memory.  See
 * xMessageBufferCreate_core2() for a version that uses dynamically allocated memory.
 *
 * @param xBufferSizeBytes_core2 The size, in bytes, of the buffer pointed to by the
 * pucMessageBufferStorageArea_core2 parameter.  When a message is written to the
 * message buffer an additional sizeof( size_t ) bytes are also written to store
 * the message's length.  sizeof( size_t ) is typically 4 bytes on a 32-bit
 * architecture, so on most 32-bit architecture a 10 byte message will take up
 * 14 bytes of message buffer space.  The maximum number of bytes that can be
 * stored in the message buffer is actually (xBufferSizeBytes_core2 - 1).
 *
 * @param pucMessageBufferStorageArea_core2 Must point to a uint8_t array that is at
 * least xBufferSizeBytes_core2 big.  This is the array to which messages are
 * copied when they are written to the message buffer.
 *
 * @param pxStaticMessageBuffer_core2 Must point to a variable of type
 * StaticMessageBuffer_t, which will be used to hold the message buffer's data
 * structure.
 *
 * @param pxSendCompletedCallback_core2 Callback invoked when a new message is sent to the message buffer.
 * If the parameter is NULL or xMessageBufferCreate_core2() is called without the parameter, then it will use the default
 * implementation provided by sbSEND_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @param pxReceiveCompletedCallback_core2 Callback invoked when a message is read from a
 * message buffer. If the parameter is NULL or xMessageBufferCreate_core2() is called without the parameter, it will
 * use the default implementation provided by sbRECEIVE_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @return If the message buffer is created successfully then a handle to the
 * created message buffer is returned. If either pucMessageBufferStorageArea_core2 or
 * pxStaticmessageBuffer are NULL then NULL is returned.
 *
 * Example use:
 * @code{c}
 *
 * // Used to dimension the array used to hold the messages.  The available space
 * // will actually be one less than this, so 999.
 #define STORAGE_SIZE_BYTES 1000
 *
 * // Defines the memory that will actually hold the messages within the message
 * // buffer.
 * static uint8_t ucStorageBuffer[ STORAGE_SIZE_BYTES ];
 *
 * // The variable used to hold the message buffer structure.
 * StaticMessageBuffer_t xMessageBufferStruct;
 *
 * void MyFunction( void )
 * {
 * MessageBufferHandle_t_core2 xMessageBuffer_core2;
 *
 *  xMessageBuffer_core2 = xMessageBufferCreateStatic_core2( sizeof( ucStorageBuffer ),
 *                                               ucStorageBuffer,
 *                                               &xMessageBufferStruct );
 *
 *  // As neither the pucMessageBufferStorageArea_core2 or pxStaticMessageBuffer_core2
 *  // parameters were NULL, xMessageBuffer_core2 will not be NULL, and can be used to
 *  // reference the created message buffer in other message buffer API calls.
 *
 *  // Other code that uses the message buffer can go here.
 * }
 *
 * @endcode
 * \defgroup xMessageBufferCreateStatic_core2 xMessageBufferCreateStatic_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferCreateStatic_core2( xBufferSizeBytes_core2, pucMessageBufferStorageArea_core2, pxStaticMessageBuffer_core2 ) \
    xStreamBufferGenericCreateStatic_core2( ( xBufferSizeBytes_core2 ), 0, pdTRUE_core2, ( pucMessageBufferStorageArea_core2 ), ( pxStaticMessageBuffer_core2 ), NULL, NULL )

#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define xMessageBufferCreateStaticWithCallback_core2( xBufferSizeBytes_core2, pucMessageBufferStorageArea_core2, pxStaticMessageBuffer_core2, pxSendCompletedCallback_core2, pxReceiveCompletedCallback_core2 ) \
    xStreamBufferGenericCreateStatic_core2( ( xBufferSizeBytes_core2 ), 0, pdTRUE_core2, ( pucMessageBufferStorageArea_core2 ), ( pxStaticMessageBuffer_core2 ), ( pxSendCompletedCallback_core2 ), ( pxReceiveCompletedCallback_core2 ) )
#endif

/**
 * message_buffer.h
 *
 * @code{c}
 * size_t xMessageBufferSend_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2,
 *                         const void *pvTxData_core2,
 *                         size_t xDataLengthBytes_core2,
 *                         TickType_t_core2 xTicksToWait_core2 );
 * @endcode
 *
 * Sends a discrete message to the message buffer.  The message can be any
 * length that fits within the buffer's free space, and is copied into the
 * buffer.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core2 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core2 or
 * interrupt that will write to the buffer (the writer), and only one task_core2 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core2 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xMessageBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xMessageBufferRead()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xMessageBufferSend_core2() to write to a message buffer from a task_core2.  Use
 * xMessageBufferSendFromISR_core2() to write to a message buffer from an interrupt
 * service routine (ISR).
 *
 * @param xMessageBuffer_core2 The handle of the message buffer to which a message is
 * being sent.
 *
 * @param pvTxData_core2 A pointer to the message that is to be copied into the
 * message buffer.
 *
 * @param xDataLengthBytes_core2 The length of the message.  That is, the number of
 * bytes to copy from pvTxData_core2 into the message buffer.  When a message is
 * written to the message buffer an additional sizeof( size_t ) bytes are also
 * written to store the message's length.  sizeof( size_t ) is typically 4 bytes
 * on a 32-bit architecture, so on most 32-bit architecture setting
 * xDataLengthBytes_core2 to 20 will reduce the free space in the message buffer by 24
 * bytes (20 bytes of message data and 4 bytes to hold the message length).
 *
 * @param xTicksToWait_core2 The maximum amount of time the calling task_core2 should remain
 * in the Blocked state to wait for enough space to become available in the
 * message buffer, should the message buffer have insufficient space when
 * xMessageBufferSend_core2() is called.  The calling task_core2 will never block if
 * xTicksToWait_core2 is zero.  The block time is specified in tick periods, so the
 * absolute time it represents is dependent on the tick frequency.  The macro
 * pdMS_TO_TICKS() can be used to convert a time specified in milliseconds into
 * a time specified in ticks.  Setting xTicksToWait_core2 to portMAX_DELAY_core2 will cause
 * the task_core2 to wait indefinitely (without timing out), provided
 * INCLUDE_vTaskSuspend_core2 is set to 1 in FreeRTOSConfig.h.  Tasks do not use any
 * CPU time when they are in the Blocked state.
 *
 * @return The number of bytes written to the message buffer.  If the call to
 * xMessageBufferSend_core2() times out before there was enough space to write the
 * message into the message buffer then zero is returned.  If the call did not
 * time out then xDataLengthBytes_core2 is returned.
 *
 * Example use:
 * @code{c}
 * void vAFunction( MessageBufferHandle_t_core2 xMessageBuffer_core2 )
 * {
 * size_t xBytesSent_core2;
 * uint8_t ucArrayToSend[] = { 0, 1, 2, 3 };
 * char *pcStringToSend = "String to send";
 * const TickType_t_core2 x100ms = pdMS_TO_TICKS( 100 );
 *
 *  // Send an array to the message buffer, blocking for a maximum of 100ms to
 *  // wait for enough space to be available in the message buffer.
 *  xBytesSent_core2 = xMessageBufferSend_core2( xMessageBuffer_core2, ( void * ) ucArrayToSend, sizeof( ucArrayToSend ), x100ms );
 *
 *  if( xBytesSent_core2 != sizeof( ucArrayToSend ) )
 *  {
 *      // The call to xMessageBufferSend_core2() times out before there was enough
 *      // space in the buffer for the data to be written.
 *  }
 *
 *  // Send the string to the message buffer.  Return immediately if there is
 *  // not enough space in the buffer.
 *  xBytesSent_core2 = xMessageBufferSend_core2( xMessageBuffer_core2, ( void * ) pcStringToSend, strlen( pcStringToSend ), 0 );
 *
 *  if( xBytesSent_core2 != strlen( pcStringToSend ) )
 *  {
 *      // The string could not be added to the message buffer because there was
 *      // not enough free space in the buffer.
 *  }
 * }
 * @endcode
 * \defgroup xMessageBufferSend_core2 xMessageBufferSend_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferSend_core2( xMessageBuffer_core2, pvTxData_core2, xDataLengthBytes_core2, xTicksToWait_core2 ) \
    xStreamBufferSend_core2( ( xMessageBuffer_core2 ), ( pvTxData_core2 ), ( xDataLengthBytes_core2 ), ( xTicksToWait_core2 ) )

/**
 * message_buffer.h
 *
 * @code{c}
 * size_t xMessageBufferSendFromISR_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2,
 *                                const void *pvTxData_core2,
 *                                size_t xDataLengthBytes_core2,
 *                                BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * Interrupt safe version of the API function that sends a discrete message to
 * the message buffer.  The message can be any length that fits within the
 * buffer's free space, and is copied into the buffer.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core2 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core2 or
 * interrupt that will write to the buffer (the writer), and only one task_core2 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core2 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xMessageBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xMessageBufferRead()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xMessageBufferSend_core2() to write to a message buffer from a task_core2.  Use
 * xMessageBufferSendFromISR_core2() to write to a message buffer from an interrupt
 * service routine (ISR).
 *
 * @param xMessageBuffer_core2 The handle of the message buffer to which a message is
 * being sent.
 *
 * @param pvTxData_core2 A pointer to the message that is to be copied into the
 * message buffer.
 *
 * @param xDataLengthBytes_core2 The length of the message.  That is, the number of
 * bytes to copy from pvTxData_core2 into the message buffer.  When a message is
 * written to the message buffer an additional sizeof( size_t ) bytes are also
 * written to store the message's length.  sizeof( size_t ) is typically 4 bytes
 * on a 32-bit architecture, so on most 32-bit architecture setting
 * xDataLengthBytes_core2 to 20 will reduce the free space in the message buffer by 24
 * bytes (20 bytes of message data and 4 bytes to hold the message length).
 *
 * @param pxHigherPriorityTaskWoken_core2  It is possible that a message buffer will
 * have a task_core2 blocked on it waiting for data.  Calling
 * xMessageBufferSendFromISR_core2() can make data available, and so cause a task_core2 that
 * was waiting for data to leave the Blocked state.  If calling
 * xMessageBufferSendFromISR_core2() causes a task_core2 to leave the Blocked state, and the
 * unblocked task_core2 has a priority higher than the currently executing task_core2 (the
 * task_core2 that was interrupted), then, internally, xMessageBufferSendFromISR_core2()
 * will set *pxHigherPriorityTaskWoken_core2 to pdTRUE_core2.  If
 * xMessageBufferSendFromISR_core2() sets this value to pdTRUE_core2, then normally a
 * context switch should be performed before the interrupt is exited.  This will
 * ensure that the interrupt returns directly to the highest priority Ready
 * state task_core2.  *pxHigherPriorityTaskWoken_core2 should be set to pdFALSE_core2 before it
 * is passed into the function.  See the code example below for an example.
 *
 * @return The number of bytes actually written to the message buffer.  If the
 * message buffer didn't have enough free space for the message to be stored
 * then 0 is returned, otherwise xDataLengthBytes_core2 is returned.
 *
 * Example use:
 * @code{c}
 * // A message buffer that has already been created.
 * MessageBufferHandle_t_core2 xMessageBuffer_core2;
 *
 * void vAnInterruptServiceRoutine( void )
 * {
 * size_t xBytesSent_core2;
 * char *pcStringToSend = "String to send";
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2; // Initialised to pdFALSE_core2.
 *
 *  // Attempt to send the string to the message buffer.
 *  xBytesSent_core2 = xMessageBufferSendFromISR_core2( xMessageBuffer_core2,
 *                                          ( void * ) pcStringToSend,
 *                                          strlen( pcStringToSend ),
 *                                          &xHigherPriorityTaskWoken_core2 );
 *
 *  if( xBytesSent_core2 != strlen( pcStringToSend ) )
 *  {
 *      // The string could not be added to the message buffer because there was
 *      // not enough free space in the buffer.
 *  }
 *
 *  // If xHigherPriorityTaskWoken_core2 was set to pdTRUE_core2 inside
 *  // xMessageBufferSendFromISR_core2() then a task_core2 that has a priority above the
 *  // priority of the currently executing task_core2 was unblocked and a context
 *  // switch should be performed to ensure the ISR returns to the unblocked
 *  // task_core2.  In most FreeRTOS_core2 ports this is done by simply passing
 *  // xHigherPriorityTaskWoken_core2 into portYIELD_FROM_ISR_core2(), which will test the
 *  // variables value, and perform the context switch if necessary.  Check the
 *  // documentation for the port in use for port specific instructions.
 *  portYIELD_FROM_ISR_core2( xHigherPriorityTaskWoken_core2 );
 * }
 * @endcode
 * \defgroup xMessageBufferSendFromISR_core2 xMessageBufferSendFromISR_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferSendFromISR_core2( xMessageBuffer_core2, pvTxData_core2, xDataLengthBytes_core2, pxHigherPriorityTaskWoken_core2 ) \
    xStreamBufferSendFromISR_core2( ( xMessageBuffer_core2 ), ( pvTxData_core2 ), ( xDataLengthBytes_core2 ), ( pxHigherPriorityTaskWoken_core2 ) )

/**
 * message_buffer.h
 *
 * @code{c}
 * size_t xMessageBufferReceive_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2,
 *                            void *pvRxData_core2,
 *                            size_t xBufferLengthBytes_core2,
 *                            TickType_t_core2 xTicksToWait_core2 );
 * @endcode
 *
 * Receives a discrete message from a message buffer.  Messages can be of
 * variable length and are copied out of the buffer.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core2 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core2 or
 * interrupt that will write to the buffer (the writer), and only one task_core2 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core2 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xMessageBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xMessageBufferRead()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xMessageBufferReceive_core2() to read from a message buffer from a task_core2.  Use
 * xMessageBufferReceiveFromISR_core2() to read from a message buffer from an
 * interrupt service routine (ISR).
 *
 * @param xMessageBuffer_core2 The handle of the message buffer from which a message
 * is being received.
 *
 * @param pvRxData_core2 A pointer to the buffer into which the received message is
 * to be copied.
 *
 * @param xBufferLengthBytes_core2 The length of the buffer pointed to by the pvRxData_core2
 * parameter.  This sets the maximum length of the message that can be received.
 * If xBufferLengthBytes_core2 is too small to hold the next message then the message
 * will be left in the message buffer and 0 will be returned.
 *
 * @param xTicksToWait_core2 The maximum amount of time the task_core2 should remain in the
 * Blocked state to wait for a message, should the message buffer be empty.
 * xMessageBufferReceive_core2() will return immediately if xTicksToWait_core2 is zero and
 * the message buffer is empty.  The block time is specified in tick periods, so
 * the absolute time it represents is dependent on the tick frequency.  The
 * macro pdMS_TO_TICKS() can be used to convert a time specified in milliseconds
 * into a time specified in ticks.  Setting xTicksToWait_core2 to portMAX_DELAY_core2 will
 * cause the task_core2 to wait indefinitely (without timing out), provided
 * INCLUDE_vTaskSuspend_core2 is set to 1 in FreeRTOSConfig.h.  Tasks do not use any
 * CPU time when they are in the Blocked state.
 *
 * @return The length, in bytes, of the message read from the message buffer, if
 * any.  If xMessageBufferReceive_core2() times out before a message became available
 * then zero is returned.  If the length of the message is greater than
 * xBufferLengthBytes_core2 then the message will be left in the message buffer and
 * zero is returned.
 *
 * Example use:
 * @code{c}
 * void vAFunction( MessageBuffer_t xMessageBuffer_core2 )
 * {
 * uint8_t ucRxData[ 20 ];
 * size_t xReceivedBytes;
 * const TickType_t_core2 xBlockTime = pdMS_TO_TICKS( 20 );
 *
 *  // Receive the next message from the message buffer.  Wait in the Blocked
 *  // state (so not using any CPU processing time) for a maximum of 100ms for
 *  // a message to become available.
 *  xReceivedBytes = xMessageBufferReceive_core2( xMessageBuffer_core2,
 *                                          ( void * ) ucRxData,
 *                                          sizeof( ucRxData ),
 *                                          xBlockTime );
 *
 *  if( xReceivedBytes > 0 )
 *  {
 *      // A ucRxData contains a message that is xReceivedBytes long.  Process
 *      // the message here....
 *  }
 * }
 * @endcode
 * \defgroup xMessageBufferReceive_core2 xMessageBufferReceive_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferReceive_core2( xMessageBuffer_core2, pvRxData_core2, xBufferLengthBytes_core2, xTicksToWait_core2 ) \
    xStreamBufferReceive_core2( ( xMessageBuffer_core2 ), ( pvRxData_core2 ), ( xBufferLengthBytes_core2 ), ( xTicksToWait_core2 ) )


/**
 * message_buffer.h
 *
 * @code{c}
 * size_t xMessageBufferReceiveFromISR_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2,
 *                                   void *pvRxData_core2,
 *                                   size_t xBufferLengthBytes_core2,
 *                                   BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * An interrupt safe version of the API function that receives a discrete
 * message from a message buffer.  Messages can be of variable length and are
 * copied out of the buffer.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core2 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core2 or
 * interrupt that will write to the buffer (the writer), and only one task_core2 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core2 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xMessageBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xMessageBufferRead()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xMessageBufferReceive_core2() to read from a message buffer from a task_core2.  Use
 * xMessageBufferReceiveFromISR_core2() to read from a message buffer from an
 * interrupt service routine (ISR).
 *
 * @param xMessageBuffer_core2 The handle of the message buffer from which a message
 * is being received.
 *
 * @param pvRxData_core2 A pointer to the buffer into which the received message is
 * to be copied.
 *
 * @param xBufferLengthBytes_core2 The length of the buffer pointed to by the pvRxData_core2
 * parameter.  This sets the maximum length of the message that can be received.
 * If xBufferLengthBytes_core2 is too small to hold the next message then the message
 * will be left in the message buffer and 0 will be returned.
 *
 * @param pxHigherPriorityTaskWoken_core2  It is possible that a message buffer will
 * have a task_core2 blocked on it waiting for space to become available.  Calling
 * xMessageBufferReceiveFromISR_core2() can make space available, and so cause a task_core2
 * that is waiting for space to leave the Blocked state.  If calling
 * xMessageBufferReceiveFromISR_core2() causes a task_core2 to leave the Blocked state, and
 * the unblocked task_core2 has a priority higher than the currently executing task_core2
 * (the task_core2 that was interrupted), then, internally,
 * xMessageBufferReceiveFromISR_core2() will set *pxHigherPriorityTaskWoken_core2 to pdTRUE_core2.
 * If xMessageBufferReceiveFromISR_core2() sets this value to pdTRUE_core2, then normally a
 * context switch should be performed before the interrupt is exited.  That will
 * ensure the interrupt returns directly to the highest priority Ready state
 * task_core2.  *pxHigherPriorityTaskWoken_core2 should be set to pdFALSE_core2 before it is
 * passed into the function.  See the code example below for an example.
 *
 * @return The length, in bytes, of the message read from the message buffer, if
 * any.
 *
 * Example use:
 * @code{c}
 * // A message buffer that has already been created.
 * MessageBuffer_t xMessageBuffer_core2;
 *
 * void vAnInterruptServiceRoutine( void )
 * {
 * uint8_t ucRxData[ 20 ];
 * size_t xReceivedBytes;
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2;  // Initialised to pdFALSE_core2.
 *
 *  // Receive the next message from the message buffer.
 *  xReceivedBytes = xMessageBufferReceiveFromISR_core2( xMessageBuffer_core2,
 *                                                ( void * ) ucRxData,
 *                                                sizeof( ucRxData ),
 *                                                &xHigherPriorityTaskWoken_core2 );
 *
 *  if( xReceivedBytes > 0 )
 *  {
 *      // A ucRxData contains a message that is xReceivedBytes long.  Process
 *      // the message here....
 *  }
 *
 *  // If xHigherPriorityTaskWoken_core2 was set to pdTRUE_core2 inside
 *  // xMessageBufferReceiveFromISR_core2() then a task_core2 that has a priority above the
 *  // priority of the currently executing task_core2 was unblocked and a context
 *  // switch should be performed to ensure the ISR returns to the unblocked
 *  // task_core2.  In most FreeRTOS_core2 ports this is done by simply passing
 *  // xHigherPriorityTaskWoken_core2 into portYIELD_FROM_ISR_core2(), which will test the
 *  // variables value, and perform the context switch if necessary.  Check the
 *  // documentation for the port in use for port specific instructions.
 *  portYIELD_FROM_ISR_core2( xHigherPriorityTaskWoken_core2 );
 * }
 * @endcode
 * \defgroup xMessageBufferReceiveFromISR_core2 xMessageBufferReceiveFromISR_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferReceiveFromISR_core2( xMessageBuffer_core2, pvRxData_core2, xBufferLengthBytes_core2, pxHigherPriorityTaskWoken_core2 ) \
    xStreamBufferReceiveFromISR_core2( ( xMessageBuffer_core2 ), ( pvRxData_core2 ), ( xBufferLengthBytes_core2 ), ( pxHigherPriorityTaskWoken_core2 ) )

/**
 * message_buffer.h
 *
 * @code{c}
 * void vMessageBufferDelete_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2 );
 * @endcode
 *
 * Deletes a message buffer that was previously created using a call to
 * xMessageBufferCreate_core2() or xMessageBufferCreateStatic_core2().  If the message
 * buffer was created using dynamic memory (that is, by xMessageBufferCreate_core2()),
 * then the allocated memory is freed.
 *
 * A message buffer handle must not be used after the message buffer has been
 * deleted.
 *
 * @param xMessageBuffer_core2 The handle of the message buffer to be deleted.
 *
 */
#define vMessageBufferDelete_core2( xMessageBuffer_core2 ) \
    vStreamBufferDelete_core2( xMessageBuffer_core2 )

/**
 * message_buffer.h
 * @code{c}
 * BaseType_t_core2 xMessageBufferIsFull_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2 );
 * @endcode
 *
 * Tests to see if a message buffer is full.  A message buffer is full if it
 * cannot accept any more messages, of any size, until space is made available
 * by a message being removed from the message buffer.
 *
 * @param xMessageBuffer_core2 The handle of the message buffer being queried.
 *
 * @return If the message buffer referenced by xMessageBuffer_core2 is full then
 * pdTRUE_core2 is returned.  Otherwise pdFALSE_core2 is returned.
 */
#define xMessageBufferIsFull_core2( xMessageBuffer_core2 ) \
    xStreamBufferIsFull_core2( xMessageBuffer_core2 )

/**
 * message_buffer.h
 * @code{c}
 * BaseType_t_core2 xMessageBufferIsEmpty_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2 );
 * @endcode
 *
 * Tests to see if a message buffer is empty (does not contain any messages).
 *
 * @param xMessageBuffer_core2 The handle of the message buffer being queried.
 *
 * @return If the message buffer referenced by xMessageBuffer_core2 is empty then
 * pdTRUE_core2 is returned.  Otherwise pdFALSE_core2 is returned.
 *
 */
#define xMessageBufferIsEmpty_core2( xMessageBuffer_core2 ) \
    xStreamBufferIsEmpty_core2( xMessageBuffer_core2 )

/**
 * message_buffer.h
 * @code{c}
 * BaseType_t_core2 xMessageBufferReset_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2 );
 * @endcode
 *
 * Resets a message buffer to its initial empty state, discarding any message it
 * contained.
 *
 * A message buffer can only be reset if there are no tasks blocked on it.
 *
 * @param xMessageBuffer_core2 The handle of the message buffer being reset.
 *
 * @return If the message buffer was reset then pdPASS_core2 is returned.  If the
 * message buffer could not be reset because either there was a task_core2 blocked on
 * the message queue to wait for space to become available, or to wait for a
 * a message to be available, then pdFAIL_core2 is returned.
 *
 * \defgroup xMessageBufferReset_core2 xMessageBufferReset_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferReset_core2( xMessageBuffer_core2 ) \
    xStreamBufferReset_core2( xMessageBuffer_core2 )


/**
 * message_buffer.h
 * @code{c}
 * size_t xMessageBufferSpaceAvailable_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2 );
 * @endcode
 * Returns the number of bytes of free space in the message buffer.
 *
 * @param xMessageBuffer_core2 The handle of the message buffer being queried.
 *
 * @return The number of bytes that can be written to the message buffer before
 * the message buffer would be full.  When a message is written to the message
 * buffer an additional sizeof( size_t ) bytes are also written to store the
 * message's length.  sizeof( size_t ) is typically 4 bytes on a 32-bit
 * architecture, so if xMessageBufferSpacesAvailable_core2() returns 10, then the size
 * of the largest message that can be written to the message buffer is 6 bytes.
 *
 * \defgroup xMessageBufferSpaceAvailable_core2 xMessageBufferSpaceAvailable_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferSpaceAvailable_core2( xMessageBuffer_core2 ) \
    xStreamBufferSpacesAvailable_core2( xMessageBuffer_core2 )
#define xMessageBufferSpacesAvailable_core2( xMessageBuffer_core2 ) \
    xStreamBufferSpacesAvailable_core2( xMessageBuffer_core2 ) /* Corrects typo in original macro name. */

/**
 * message_buffer.h
 * @code{c}
 * size_t xMessageBufferNextLengthBytes_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2 );
 * @endcode
 * Returns the length (in bytes) of the next message in a message buffer.
 * Useful if xMessageBufferReceive_core2() returned 0 because the size of the buffer
 * passed into xMessageBufferReceive_core2() was too small to hold the next message.
 *
 * @param xMessageBuffer_core2 The handle of the message buffer being queried.
 *
 * @return The length (in bytes) of the next message in the message buffer, or 0
 * if the message buffer is empty.
 *
 * \defgroup xMessageBufferNextLengthBytes_core2 xMessageBufferNextLengthBytes_core2
 * \ingroup MessageBufferManagement
 */
#define xMessageBufferNextLengthBytes_core2( xMessageBuffer_core2 ) \
    xStreamBufferNextMessageLengthBytes_core2( xMessageBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * message_buffer.h
 *
 * @code{c}
 * BaseType_t_core2 xMessageBufferSendCompletedFromISR_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2, BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * For advanced users only.
 *
 * The sbSEND_COMPLETED() macro is called from within the FreeRTOS_core2 APIs when
 * data is sent to a message buffer or stream buffer.  If there was a task_core2 that
 * was blocked on the message or stream buffer waiting for data to arrive then
 * the sbSEND_COMPLETED() macro sends a notification to the task_core2 to remove it
 * from the Blocked state.  xMessageBufferSendCompletedFromISR_core2() does the same
 * thing.  It is provided to enable application writers to implement their own
 * version of sbSEND_COMPLETED(), and MUST NOT BE USED AT ANY OTHER TIME.
 *
 * See the example implemented in FreeRTOS_core2/Demo/Minimal/MessageBufferAMP.c for
 * additional information.
 *
 * @param xMessageBuffer_core2 The handle of the stream buffer to which data was
 * written.
 *
 * @param pxHigherPriorityTaskWoken_core2 *pxHigherPriorityTaskWoken_core2 should be
 * initialised to pdFALSE_core2 before it is passed into
 * xMessageBufferSendCompletedFromISR_core2().  If calling
 * xMessageBufferSendCompletedFromISR_core2() removes a task_core2 from the Blocked state,
 * and the task_core2 has a priority above the priority of the currently running task_core2,
 * then *pxHigherPriorityTaskWoken_core2 will get set to pdTRUE_core2 indicating that a
 * context switch should be performed before exiting the ISR.
 *
 * @return If a task_core2 was removed from the Blocked state then pdTRUE_core2 is returned.
 * Otherwise pdFALSE_core2 is returned.
 *
 * \defgroup xMessageBufferSendCompletedFromISR_core2 xMessageBufferSendCompletedFromISR_core2
 * \ingroup StreamBufferManagement
 */
#define xMessageBufferSendCompletedFromISR_core2( xMessageBuffer_core2, pxHigherPriorityTaskWoken_core2 ) \
    xStreamBufferSendCompletedFromISR_core2( ( xMessageBuffer_core2 ), ( pxHigherPriorityTaskWoken_core2 ) )

/**
 * message_buffer.h
 *
 * @code{c}
 * BaseType_t_core2 xMessageBufferReceiveCompletedFromISR_core2( MessageBufferHandle_t_core2 xMessageBuffer_core2, BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * For advanced users only.
 *
 * The sbRECEIVE_COMPLETED() macro is called from within the FreeRTOS_core2 APIs when
 * data is read out of a message buffer or stream buffer.  If there was a task_core2
 * that was blocked on the message or stream buffer waiting for data to arrive
 * then the sbRECEIVE_COMPLETED() macro sends a notification to the task_core2 to
 * remove it from the Blocked state.  xMessageBufferReceiveCompletedFromISR_core2()
 * does the same thing.  It is provided to enable application writers to
 * implement their own version of sbRECEIVE_COMPLETED(), and MUST NOT BE USED AT
 * ANY OTHER TIME.
 *
 * See the example implemented in FreeRTOS_core2/Demo/Minimal/MessageBufferAMP.c for
 * additional information.
 *
 * @param xMessageBuffer_core2 The handle of the stream buffer from which data was
 * read.
 *
 * @param pxHigherPriorityTaskWoken_core2 *pxHigherPriorityTaskWoken_core2 should be
 * initialised to pdFALSE_core2 before it is passed into
 * xMessageBufferReceiveCompletedFromISR_core2().  If calling
 * xMessageBufferReceiveCompletedFromISR_core2() removes a task_core2 from the Blocked state,
 * and the task_core2 has a priority above the priority of the currently running task_core2,
 * then *pxHigherPriorityTaskWoken_core2 will get set to pdTRUE_core2 indicating that a
 * context switch should be performed before exiting the ISR.
 *
 * @return If a task_core2 was removed from the Blocked state then pdTRUE_core2 is returned.
 * Otherwise pdFALSE_core2 is returned.
 *
 * \defgroup xMessageBufferReceiveCompletedFromISR_core2 xMessageBufferReceiveCompletedFromISR_core2
 * \ingroup StreamBufferManagement
 */
#define xMessageBufferReceiveCompletedFromISR_core2( xMessageBuffer_core2, pxHigherPriorityTaskWoken_core2 ) \
    xStreamBufferReceiveCompletedFromISR_core2( ( xMessageBuffer_core2 ), ( pxHigherPriorityTaskWoken_core2 ) )

/* *INDENT-OFF* */
#if defined( __cplusplus )
    } /* extern "C" */
#endif
/* *INDENT-ON* */

#endif /* !defined( FREERTOS_MESSAGE_BUFFER_H ) */
