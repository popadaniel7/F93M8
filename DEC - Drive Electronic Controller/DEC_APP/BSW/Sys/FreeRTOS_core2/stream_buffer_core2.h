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
 * Stream buffers are used to send a continuous stream of data from one task_core2 or
 * interrupt to another.  Their implementation is light weight, making them
 * particularly suited for interrupt to task_core2 and core to core communication
 * scenarios.
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
 * (such as xStreamBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core2()) inside a critical section section and set the
 * receive block time to 0.
 *
 */

#ifndef STREAM_BUFFER_CORE2_H
#define STREAM_BUFFER_CORE2_H

#ifndef INC_FREERTOS_CORE2_H
    #error "include FreeRTOS_core2.h must appear in source files before include stream_buffer_core2.h"
#endif

/* *INDENT-OFF* */
#if defined( __cplusplus )
    extern "C" {
#endif
/* *INDENT-ON* */

/**
 * Type by which stream buffers are referenced.  For example, a call to
 * xStreamBufferCreate_core2() returns an StreamBufferHandle_t_core2 variable that can
 * then be used as a parameter to xStreamBufferSend_core2(), xStreamBufferReceive_core2(),
 * etc.
 */
struct StreamBufferDef_t_core2;
typedef struct StreamBufferDef_t_core2 * StreamBufferHandle_t_core2;

/**
 *  Type used as a stream buffer's optional callback.
 */
typedef void (* StreamBufferCallbackFunction_t_core2)( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                                 BaseType_t_core2 xIsInsideISR_core2,
                                                 BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2 );

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * StreamBufferHandle_t_core2 xStreamBufferCreate_core2( size_t xBufferSizeBytes_core2, size_t xTriggerLevelBytes_core2 );
 * @endcode
 *
 * Creates a new stream buffer using dynamically allocated memory.  See
 * xStreamBufferCreateStatic_core2() for a version that uses statically allocated
 * memory (memory that is allocated at compile time).
 *
 * configSUPPORT_DYNAMIC_ALLOCATION_core2 must be set to 1 or left undefined in
 * FreeRTOSConfig.h for xStreamBufferCreate_core2() to be available.
 *
 * @param xBufferSizeBytes_core2 The total number of bytes the stream buffer will be
 * able to hold at any one time.
 *
 * @param xTriggerLevelBytes_core2 The number of bytes that must be in the stream
 * buffer before a task_core2 that is blocked on the stream buffer to wait for data is
 * moved out of the blocked state.  For example, if a task_core2 is blocked on a read
 * of an empty stream buffer that has a trigger level of 1 then the task_core2 will be
 * unblocked when a single byte is written to the buffer or the task_core2's block
 * time expires.  As another example, if a task_core2 is blocked on a read of an empty
 * stream buffer that has a trigger level of 10 then the task_core2 will not be
 * unblocked until the stream buffer contains at least 10 bytes or the task_core2's
 * block time expires.  If a reading task_core2's block time expires before the
 * trigger level is reached then the task_core2 will still receive however many bytes
 * are actually available.  Setting a trigger level of 0 will result in a
 * trigger level of 1 being used.  It is not valid to specify a trigger level
 * that is greater than the buffer size.
 *
 * @param pxSendCompletedCallback_core2 Callback invoked when number of bytes at least equal to
 * trigger level is sent to the stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbSEND_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @param pxReceiveCompletedCallback_core2 Callback invoked when more than zero bytes are read from a
 * stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbRECEIVE_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @return If NULL is returned, then the stream buffer cannot be created
 * because there is insufficient heap memory available for FreeRTOS_core2 to allocate
 * the stream buffer data structures and storage area.  A non-NULL value being
 * returned indicates that the stream buffer has been created successfully -
 * the returned value should be stored as the handle to the created stream
 * buffer.
 *
 * Example use:
 * @code{c}
 *
 * void vAFunction( void )
 * {
 * StreamBufferHandle_t_core2 xStreamBuffer_core2;
 * const size_t xStreamBufferSizeBytes = 100, xTriggerLevel_core2 = 10;
 *
 *  // Create a stream buffer that can hold 100 bytes.  The memory used to hold
 *  // both the stream buffer structure and the data in the stream buffer is
 *  // allocated dynamically.
 *  xStreamBuffer_core2 = xStreamBufferCreate_core2( xStreamBufferSizeBytes, xTriggerLevel_core2 );
 *
 *  if( xStreamBuffer_core2 == NULL )
 *  {
 *      // There was not enough heap memory space available to create the
 *      // stream buffer.
 *  }
 *  else
 *  {
 *      // The stream buffer was created successfully and can now be used.
 *  }
 * }
 * @endcode
 * \defgroup xStreamBufferCreate_core2 xStreamBufferCreate_core2
 * \ingroup StreamBufferManagement
 */

#define xStreamBufferCreate_core2( xBufferSizeBytes_core2, xTriggerLevelBytes_core2 ) \
    xStreamBufferGenericCreate_core2( ( xBufferSizeBytes_core2 ), ( xTriggerLevelBytes_core2 ), pdFALSE_core2, NULL, NULL )

#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define xStreamBufferCreateWithCallback_core2( xBufferSizeBytes_core2, xTriggerLevelBytes_core2, pxSendCompletedCallback_core2, pxReceiveCompletedCallback_core2 ) \
    xStreamBufferGenericCreate_core2( ( xBufferSizeBytes_core2 ), ( xTriggerLevelBytes_core2 ), pdFALSE_core2, ( pxSendCompletedCallback_core2 ), ( pxReceiveCompletedCallback_core2 ) )
#endif

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * StreamBufferHandle_t_core2 xStreamBufferCreateStatic_core2( size_t xBufferSizeBytes_core2,
 *                                              size_t xTriggerLevelBytes_core2,
 *                                              uint8_t *pucStreamBufferStorageArea_core2,
 *                                              StaticStreamBuffer_t_core2 *pxStaticStreamBuffer_core2 );
 * @endcode
 * Creates a new stream buffer using statically allocated memory.  See
 * xStreamBufferCreate_core2() for a version that uses dynamically allocated memory.
 *
 * configSUPPORT_STATIC_ALLOCATION_core2 must be set to 1 in FreeRTOSConfig.h for
 * xStreamBufferCreateStatic_core2() to be available.
 *
 * @param xBufferSizeBytes_core2 The size, in bytes, of the buffer pointed to by the
 * pucStreamBufferStorageArea_core2 parameter.
 *
 * @param xTriggerLevelBytes_core2 The number of bytes that must be in the stream
 * buffer before a task_core2 that is blocked on the stream buffer to wait for data is
 * moved out of the blocked state.  For example, if a task_core2 is blocked on a read
 * of an empty stream buffer that has a trigger level of 1 then the task_core2 will be
 * unblocked when a single byte is written to the buffer or the task_core2's block
 * time expires.  As another example, if a task_core2 is blocked on a read of an empty
 * stream buffer that has a trigger level of 10 then the task_core2 will not be
 * unblocked until the stream buffer contains at least 10 bytes or the task_core2's
 * block time expires.  If a reading task_core2's block time expires before the
 * trigger level is reached then the task_core2 will still receive however many bytes
 * are actually available.  Setting a trigger level of 0 will result in a
 * trigger level of 1 being used.  It is not valid to specify a trigger level
 * that is greater than the buffer size.
 *
 * @param pucStreamBufferStorageArea_core2 Must point to a uint8_t array that is at
 * least xBufferSizeBytes_core2 big.  This is the array to which streams are
 * copied when they are written to the stream buffer.
 *
 * @param pxStaticStreamBuffer_core2 Must point to a variable of type
 * StaticStreamBuffer_t_core2, which will be used to hold the stream buffer's data
 * structure.
 *
 * @param pxSendCompletedCallback_core2 Callback invoked when number of bytes at least equal to
 * trigger level is sent to the stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbSEND_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @param pxReceiveCompletedCallback_core2 Callback invoked when more than zero bytes are read from a
 * stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbRECEIVE_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core2 must be set to 1 in FreeRTOSConfig.h.
 *
 * @return If the stream buffer is created successfully then a handle to the
 * created stream buffer is returned. If either pucStreamBufferStorageArea_core2 or
 * pxStaticstreamBuffer are NULL then NULL is returned.
 *
 * Example use:
 * @code{c}
 *
 * // Used to dimension the array used to hold the streams.  The available space
 * // will actually be one less than this, so 999.
 #define STORAGE_SIZE_BYTES 1000
 *
 * // Defines the memory that will actually hold the streams within the stream
 * // buffer.
 * static uint8_t ucStorageBuffer[ STORAGE_SIZE_BYTES ];
 *
 * // The variable used to hold the stream buffer structure.
 * StaticStreamBuffer_t_core2 xStreamBufferStruct;
 *
 * void MyFunction( void )
 * {
 * StreamBufferHandle_t_core2 xStreamBuffer_core2;
 * const size_t xTriggerLevel_core2 = 1;
 *
 *  xStreamBuffer_core2 = xStreamBufferCreateStatic_core2( sizeof( ucStorageBuffer ),
 *                                             xTriggerLevel_core2,
 *                                             ucStorageBuffer,
 *                                             &xStreamBufferStruct );
 *
 *  // As neither the pucStreamBufferStorageArea_core2 or pxStaticStreamBuffer_core2
 *  // parameters were NULL, xStreamBuffer_core2 will not be NULL, and can be used to
 *  // reference the created stream buffer in other stream buffer API calls.
 *
 *  // Other code that uses the stream buffer can go here.
 * }
 *
 * @endcode
 * \defgroup xStreamBufferCreateStatic_core2 xStreamBufferCreateStatic_core2
 * \ingroup StreamBufferManagement
 */

#define xStreamBufferCreateStatic_core2( xBufferSizeBytes_core2, xTriggerLevelBytes_core2, pucStreamBufferStorageArea_core2, pxStaticStreamBuffer_core2 ) \
    xStreamBufferGenericCreateStatic_core2( ( xBufferSizeBytes_core2 ), ( xTriggerLevelBytes_core2 ), pdFALSE_core2, ( pucStreamBufferStorageArea_core2 ), ( pxStaticStreamBuffer_core2 ), NULL, NULL )

#if ( configUSE_SB_COMPLETED_CALLBACK_core2 == 1 )
    #define xStreamBufferCreateStaticWithCallback_core2( xBufferSizeBytes_core2, xTriggerLevelBytes_core2, pucStreamBufferStorageArea_core2, pxStaticStreamBuffer_core2, pxSendCompletedCallback_core2, pxReceiveCompletedCallback_core2 ) \
    xStreamBufferGenericCreateStatic_core2( ( xBufferSizeBytes_core2 ), ( xTriggerLevelBytes_core2 ), pdFALSE_core2, ( pucStreamBufferStorageArea_core2 ), ( pxStaticStreamBuffer_core2 ), ( pxSendCompletedCallback_core2 ), ( pxReceiveCompletedCallback_core2 ) )
#endif

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * size_t xStreamBufferSend_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
 *                        const void *pvTxData_core2,
 *                        size_t xDataLengthBytes_core2,
 *                        TickType_t_core2 xTicksToWait_core2 );
 * @endcode
 *
 * Sends bytes to a stream buffer.  The bytes are copied into the stream buffer.
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
 * (such as xStreamBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core2()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xStreamBufferSend_core2() to write to a stream buffer from a task_core2.  Use
 * xStreamBufferSendFromISR_core2() to write to a stream buffer from an interrupt
 * service routine (ISR).
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer to which a stream is
 * being sent.
 *
 * @param pvTxData_core2 A pointer to the buffer that holds the bytes to be copied
 * into the stream buffer.
 *
 * @param xDataLengthBytes_core2   The maximum number of bytes to copy from pvTxData_core2
 * into the stream buffer.
 *
 * @param xTicksToWait_core2 The maximum amount of time the task_core2 should remain in the
 * Blocked state to wait for enough space to become available in the stream
 * buffer, should the stream buffer contain too little space to hold the
 * another xDataLengthBytes_core2 bytes.  The block time is specified in tick periods,
 * so the absolute time it represents is dependent on the tick frequency.  The
 * macro pdMS_TO_TICKS_core2() can be used to convert a time specified in milliseconds
 * into a time specified in ticks.  Setting xTicksToWait_core2 to portMAX_DELAY_core2 will
 * cause the task_core2 to wait indefinitely (without timing out), provided
 * INCLUDE_vTaskSuspend_core2 is set to 1 in FreeRTOSConfig.h.  If a task_core2 times out
 * before it can write all xDataLengthBytes_core2 into the buffer it will still write
 * as many bytes as possible.  A task_core2 does not use any CPU time when it is in
 * the blocked state.
 *
 * @return The number of bytes written to the stream buffer.  If a task_core2 times
 * out before it can write all xDataLengthBytes_core2 into the buffer it will still
 * write as many bytes as possible.
 *
 * Example use:
 * @code{c}
 * void vAFunction( StreamBufferHandle_t_core2 xStreamBuffer_core2 )
 * {
 * size_t xBytesSent_core2;
 * uint8_t ucArrayToSend[] = { 0, 1, 2, 3 };
 * char *pcStringToSend = "String to send";
 * const TickType_t_core2 x100ms = pdMS_TO_TICKS_core2( 100 );
 *
 *  // Send an array to the stream buffer, blocking for a maximum of 100ms to
 *  // wait for enough space to be available in the stream buffer.
 *  xBytesSent_core2 = xStreamBufferSend_core2( xStreamBuffer_core2, ( void * ) ucArrayToSend, sizeof( ucArrayToSend ), x100ms );
 *
 *  if( xBytesSent_core2 != sizeof( ucArrayToSend ) )
 *  {
 *      // The call to xStreamBufferSend_core2() times out before there was enough
 *      // space in the buffer for the data to be written, but it did
 *      // successfully write xBytesSent_core2 bytes.
 *  }
 *
 *  // Send the string to the stream buffer.  Return immediately if there is not
 *  // enough space in the buffer.
 *  xBytesSent_core2 = xStreamBufferSend_core2( xStreamBuffer_core2, ( void * ) pcStringToSend, strlen( pcStringToSend ), 0 );
 *
 *  if( xBytesSent_core2 != strlen( pcStringToSend ) )
 *  {
 *      // The entire string could not be added to the stream buffer because
 *      // there was not enough free space in the buffer, but xBytesSent_core2 bytes
 *      // were sent.  Could try again to send the remaining bytes.
 *  }
 * }
 * @endcode
 * \defgroup xStreamBufferSend_core2 xStreamBufferSend_core2
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferSend_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                          const void * pvTxData_core2,
                          size_t xDataLengthBytes_core2,
                          TickType_t_core2 xTicksToWait_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * size_t xStreamBufferSendFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
 *                               const void *pvTxData_core2,
 *                               size_t xDataLengthBytes_core2,
 *                               BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * Interrupt safe version of the API function that sends a stream of bytes to
 * the stream buffer.
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
 * (such as xStreamBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core2()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xStreamBufferSend_core2() to write to a stream buffer from a task_core2.  Use
 * xStreamBufferSendFromISR_core2() to write to a stream buffer from an interrupt
 * service routine (ISR).
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer to which a stream is
 * being sent.
 *
 * @param pvTxData_core2 A pointer to the data that is to be copied into the stream
 * buffer.
 *
 * @param xDataLengthBytes_core2 The maximum number of bytes to copy from pvTxData_core2
 * into the stream buffer.
 *
 * @param pxHigherPriorityTaskWoken_core2  It is possible that a stream buffer will
 * have a task_core2 blocked on it waiting for data.  Calling
 * xStreamBufferSendFromISR_core2() can make data available, and so cause a task_core2 that
 * was waiting for data to leave the Blocked state.  If calling
 * xStreamBufferSendFromISR_core2() causes a task_core2 to leave the Blocked state, and the
 * unblocked task_core2 has a priority higher than the currently executing task_core2 (the
 * task_core2 that was interrupted), then, internally, xStreamBufferSendFromISR_core2()
 * will set *pxHigherPriorityTaskWoken_core2 to pdTRUE_core2.  If
 * xStreamBufferSendFromISR_core2() sets this value to pdTRUE_core2, then normally a
 * context switch should be performed before the interrupt is exited.  This will
 * ensure that the interrupt returns directly to the highest priority Ready
 * state task_core2.  *pxHigherPriorityTaskWoken_core2 should be set to pdFALSE_core2 before it
 * is passed into the function.  See the example code below for an example.
 *
 * @return The number of bytes actually written to the stream buffer, which will
 * be less than xDataLengthBytes_core2 if the stream buffer didn't have enough free
 * space for all the bytes to be written.
 *
 * Example use:
 * @code{c}
 * // A stream buffer that has already been created.
 * StreamBufferHandle_t_core2 xStreamBuffer_core2;
 *
 * void vAnInterruptServiceRoutine( void )
 * {
 * size_t xBytesSent_core2;
 * char *pcStringToSend = "String to send";
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2; // Initialised to pdFALSE_core2.
 *
 *  // Attempt to send the string to the stream buffer.
 *  xBytesSent_core2 = xStreamBufferSendFromISR_core2( xStreamBuffer_core2,
 *                                         ( void * ) pcStringToSend,
 *                                         strlen( pcStringToSend ),
 *                                         &xHigherPriorityTaskWoken_core2 );
 *
 *  if( xBytesSent_core2 != strlen( pcStringToSend ) )
 *  {
 *      // There was not enough free space in the stream buffer for the entire
 *      // string to be written, ut xBytesSent_core2 bytes were written.
 *  }
 *
 *  // If xHigherPriorityTaskWoken_core2 was set to pdTRUE_core2 inside
 *  // xStreamBufferSendFromISR_core2() then a task_core2 that has a priority above the
 *  // priority of the currently executing task_core2 was unblocked and a context
 *  // switch should be performed to ensure the ISR returns to the unblocked
 *  // task_core2.  In most FreeRTOS_core2 ports this is done by simply passing
 *  // xHigherPriorityTaskWoken_core2 into portYIELD_FROM_ISR_core2(), which will test the
 *  // variables value, and perform the context switch if necessary.  Check the
 *  // documentation for the port in use for port specific instructions.
 *  portYIELD_FROM_ISR_core2( xHigherPriorityTaskWoken_core2 );
 * }
 * @endcode
 * \defgroup xStreamBufferSendFromISR_core2 xStreamBufferSendFromISR_core2
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferSendFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                 const void * pvTxData_core2,
                                 size_t xDataLengthBytes_core2,
                                 BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * size_t xStreamBufferReceive_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
 *                           void *pvRxData_core2,
 *                           size_t xBufferLengthBytes_core2,
 *                           TickType_t_core2 xTicksToWait_core2 );
 * @endcode
 *
 * Receives bytes from a stream buffer.
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
 * (such as xStreamBufferSend_core2()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core2()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xStreamBufferReceive_core2() to read from a stream buffer from a task_core2.  Use
 * xStreamBufferReceiveFromISR_core2() to read from a stream buffer from an
 * interrupt service routine (ISR).
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer from which bytes are to
 * be received.
 *
 * @param pvRxData_core2 A pointer to the buffer into which the received bytes will be
 * copied.
 *
 * @param xBufferLengthBytes_core2 The length of the buffer pointed to by the
 * pvRxData_core2 parameter.  This sets the maximum number of bytes to receive in one
 * call.  xStreamBufferReceive_core2 will return as many bytes as possible up to a
 * maximum set by xBufferLengthBytes_core2.
 *
 * @param xTicksToWait_core2 The maximum amount of time the task_core2 should remain in the
 * Blocked state to wait for data to become available if the stream buffer is
 * empty.  xStreamBufferReceive_core2() will return immediately if xTicksToWait_core2 is
 * zero.  The block time is specified in tick periods, so the absolute time it
 * represents is dependent on the tick frequency.  The macro pdMS_TO_TICKS_core2() can
 * be used to convert a time specified in milliseconds into a time specified in
 * ticks.  Setting xTicksToWait_core2 to portMAX_DELAY_core2 will cause the task_core2 to wait
 * indefinitely (without timing out), provided INCLUDE_vTaskSuspend_core2 is set to 1
 * in FreeRTOSConfig.h.  A task_core2 does not use any CPU time when it is in the
 * Blocked state.
 *
 * @return The number of bytes actually read from the stream buffer, which will
 * be less than xBufferLengthBytes_core2 if the call to xStreamBufferReceive_core2() timed
 * out before xBufferLengthBytes_core2 were available.
 *
 * Example use:
 * @code{c}
 * void vAFunction( StreamBuffer_t xStreamBuffer_core2 )
 * {
 * uint8_t ucRxData[ 20 ];
 * size_t xReceivedBytes;
 * const TickType_t_core2 xBlockTime_core2 = pdMS_TO_TICKS_core2( 20 );
 *
 *  // Receive up to another sizeof( ucRxData ) bytes from the stream buffer.
 *  // Wait in the Blocked state (so not using any CPU processing time) for a
 *  // maximum of 100ms for the full sizeof( ucRxData ) number of bytes to be
 *  // available.
 *  xReceivedBytes = xStreamBufferReceive_core2( xStreamBuffer_core2,
 *                                         ( void * ) ucRxData,
 *                                         sizeof( ucRxData ),
 *                                         xBlockTime_core2 );
 *
 *  if( xReceivedBytes > 0 )
 *  {
 *      // A ucRxData contains another xReceivedBytes bytes of data, which can
 *      // be processed here....
 *  }
 * }
 * @endcode
 * \defgroup xStreamBufferReceive_core2 xStreamBufferReceive_core2
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferReceive_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                             void * pvRxData_core2,
                             size_t xBufferLengthBytes_core2,
                             TickType_t_core2 xTicksToWait_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * size_t xStreamBufferReceiveFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
 *                                  void *pvRxData_core2,
 *                                  size_t xBufferLengthBytes_core2,
 *                                  BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * An interrupt safe version of the API function that receives bytes from a
 * stream buffer.
 *
 * Use xStreamBufferReceive_core2() to read bytes from a stream buffer from a task_core2.
 * Use xStreamBufferReceiveFromISR_core2() to read bytes from a stream buffer from an
 * interrupt service routine (ISR).
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer from which a stream
 * is being received.
 *
 * @param pvRxData_core2 A pointer to the buffer into which the received bytes are
 * copied.
 *
 * @param xBufferLengthBytes_core2 The length of the buffer pointed to by the
 * pvRxData_core2 parameter.  This sets the maximum number of bytes to receive in one
 * call.  xStreamBufferReceive_core2 will return as many bytes as possible up to a
 * maximum set by xBufferLengthBytes_core2.
 *
 * @param pxHigherPriorityTaskWoken_core2  It is possible that a stream buffer will
 * have a task_core2 blocked on it waiting for space to become available.  Calling
 * xStreamBufferReceiveFromISR_core2() can make space available, and so cause a task_core2
 * that is waiting for space to leave the Blocked state.  If calling
 * xStreamBufferReceiveFromISR_core2() causes a task_core2 to leave the Blocked state, and
 * the unblocked task_core2 has a priority higher than the currently executing task_core2
 * (the task_core2 that was interrupted), then, internally,
 * xStreamBufferReceiveFromISR_core2() will set *pxHigherPriorityTaskWoken_core2 to pdTRUE_core2.
 * If xStreamBufferReceiveFromISR_core2() sets this value to pdTRUE_core2, then normally a
 * context switch should be performed before the interrupt is exited.  That will
 * ensure the interrupt returns directly to the highest priority Ready state
 * task_core2.  *pxHigherPriorityTaskWoken_core2 should be set to pdFALSE_core2 before it is
 * passed into the function.  See the code example below for an example.
 *
 * @return The number of bytes read from the stream buffer, if any.
 *
 * Example use:
 * @code{c}
 * // A stream buffer that has already been created.
 * StreamBuffer_t xStreamBuffer_core2;
 *
 * void vAnInterruptServiceRoutine( void )
 * {
 * uint8_t ucRxData[ 20 ];
 * size_t xReceivedBytes;
 * BaseType_t_core2 xHigherPriorityTaskWoken_core2 = pdFALSE_core2;  // Initialised to pdFALSE_core2.
 *
 *  // Receive the next stream from the stream buffer.
 *  xReceivedBytes = xStreamBufferReceiveFromISR_core2( xStreamBuffer_core2,
 *                                                ( void * ) ucRxData,
 *                                                sizeof( ucRxData ),
 *                                                &xHigherPriorityTaskWoken_core2 );
 *
 *  if( xReceivedBytes > 0 )
 *  {
 *      // ucRxData contains xReceivedBytes read from the stream buffer.
 *      // Process the stream here....
 *  }
 *
 *  // If xHigherPriorityTaskWoken_core2 was set to pdTRUE_core2 inside
 *  // xStreamBufferReceiveFromISR_core2() then a task_core2 that has a priority above the
 *  // priority of the currently executing task_core2 was unblocked and a context
 *  // switch should be performed to ensure the ISR returns to the unblocked
 *  // task_core2.  In most FreeRTOS_core2 ports this is done by simply passing
 *  // xHigherPriorityTaskWoken_core2 into portYIELD_FROM_ISR_core2(), which will test the
 *  // variables value, and perform the context switch if necessary.  Check the
 *  // documentation for the port in use for port specific instructions.
 *  portYIELD_FROM_ISR_core2( xHigherPriorityTaskWoken_core2 );
 * }
 * @endcode
 * \defgroup xStreamBufferReceiveFromISR_core2 xStreamBufferReceiveFromISR_core2
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferReceiveFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                    void * pvRxData_core2,
                                    size_t xBufferLengthBytes_core2,
                                    BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * void vStreamBufferDelete_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 );
 * @endcode
 *
 * Deletes a stream buffer that was previously created using a call to
 * xStreamBufferCreate_core2() or xStreamBufferCreateStatic_core2().  If the stream
 * buffer was created using dynamic memory (that is, by xStreamBufferCreate_core2()),
 * then the allocated memory is freed.
 *
 * A stream buffer handle must not be used after the stream buffer has been
 * deleted.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer to be deleted.
 *
 * \defgroup vStreamBufferDelete_core2 vStreamBufferDelete_core2
 * \ingroup StreamBufferManagement
 */
void vStreamBufferDelete_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * BaseType_t_core2 xStreamBufferIsFull_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 );
 * @endcode
 *
 * Queries a stream buffer to see if it is full.  A stream buffer is full if it
 * does not have any free space, and therefore cannot accept any more data.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer being queried.
 *
 * @return If the stream buffer is full then pdTRUE_core2 is returned.  Otherwise
 * pdFALSE_core2 is returned.
 *
 * \defgroup xStreamBufferIsFull_core2 xStreamBufferIsFull_core2
 * \ingroup StreamBufferManagement
 */
BaseType_t_core2 xStreamBufferIsFull_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * BaseType_t_core2 xStreamBufferIsEmpty_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 );
 * @endcode
 *
 * Queries a stream buffer to see if it is empty.  A stream buffer is empty if
 * it does not contain any data.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer being queried.
 *
 * @return If the stream buffer is empty then pdTRUE_core2 is returned.  Otherwise
 * pdFALSE_core2 is returned.
 *
 * \defgroup xStreamBufferIsEmpty_core2 xStreamBufferIsEmpty_core2
 * \ingroup StreamBufferManagement
 */
BaseType_t_core2 xStreamBufferIsEmpty_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * BaseType_t_core2 xStreamBufferReset_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 );
 * @endcode
 *
 * Resets a stream buffer to its initial, empty, state.  Any data that was in
 * the stream buffer is discarded.  A stream buffer can only be reset if there
 * are no tasks blocked waiting to either send to or receive from the stream
 * buffer.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer being reset.
 *
 * @return If the stream buffer is reset then pdPASS_core2 is returned.  If there was
 * a task_core2 blocked waiting to send to or read from the stream buffer then the
 * stream buffer is not reset and pdFAIL_core2 is returned.
 *
 * \defgroup xStreamBufferReset_core2 xStreamBufferReset_core2
 * \ingroup StreamBufferManagement
 */
BaseType_t_core2 xStreamBufferReset_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * size_t xStreamBufferSpacesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 );
 * @endcode
 *
 * Queries a stream buffer to see how much free space it contains, which is
 * equal to the amount of data that can be sent to the stream buffer before it
 * is full.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer being queried.
 *
 * @return The number of bytes that can be written to the stream buffer before
 * the stream buffer would be full.
 *
 * \defgroup xStreamBufferSpacesAvailable_core2 xStreamBufferSpacesAvailable_core2
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferSpacesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * size_t xStreamBufferBytesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 );
 * @endcode
 *
 * Queries a stream buffer to see how much data it contains, which is equal to
 * the number of bytes that can be read from the stream buffer before the stream
 * buffer would be empty.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer being queried.
 *
 * @return The number of bytes that can be read from the stream buffer before
 * the stream buffer would be empty.
 *
 * \defgroup xStreamBufferBytesAvailable_core2 xStreamBufferBytesAvailable_core2
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferBytesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * BaseType_t_core2 xStreamBufferSetTriggerLevel_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2, size_t xTriggerLevel_core2 );
 * @endcode
 *
 * A stream buffer's trigger level is the number of bytes that must be in the
 * stream buffer before a task_core2 that is blocked on the stream buffer to
 * wait for data is moved out of the blocked state.  For example, if a task_core2 is
 * blocked on a read of an empty stream buffer that has a trigger level of 1
 * then the task_core2 will be unblocked when a single byte is written to the buffer
 * or the task_core2's block time expires.  As another example, if a task_core2 is blocked
 * on a read of an empty stream buffer that has a trigger level of 10 then the
 * task_core2 will not be unblocked until the stream buffer contains at least 10 bytes
 * or the task_core2's block time expires.  If a reading task_core2's block time expires
 * before the trigger level is reached then the task_core2 will still receive however
 * many bytes are actually available.  Setting a trigger level of 0 will result
 * in a trigger level of 1 being used.  It is not valid to specify a trigger
 * level that is greater than the buffer size.
 *
 * A trigger level is set when the stream buffer is created, and can be modified
 * using xStreamBufferSetTriggerLevel_core2().
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer being updated.
 *
 * @param xTriggerLevel_core2 The new trigger level for the stream buffer.
 *
 * @return If xTriggerLevel_core2 was less than or equal to the stream buffer's length
 * then the trigger level will be updated and pdTRUE_core2 is returned.  Otherwise
 * pdFALSE_core2 is returned.
 *
 * \defgroup xStreamBufferSetTriggerLevel_core2 xStreamBufferSetTriggerLevel_core2
 * \ingroup StreamBufferManagement
 */
BaseType_t_core2 xStreamBufferSetTriggerLevel_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                         size_t xTriggerLevel_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * BaseType_t_core2 xStreamBufferSendCompletedFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2, BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * For advanced users only.
 *
 * The sbSEND_COMPLETED() macro is called from within the FreeRTOS_core2 APIs when
 * data is sent to a message buffer or stream buffer.  If there was a task_core2 that
 * was blocked on the message or stream buffer waiting for data to arrive then
 * the sbSEND_COMPLETED() macro sends a notification to the task_core2 to remove it
 * from the Blocked state.  xStreamBufferSendCompletedFromISR_core2() does the same
 * thing.  It is provided to enable application writers to implement their own
 * version of sbSEND_COMPLETED(), and MUST NOT BE USED AT ANY OTHER TIME.
 *
 * See the example implemented in FreeRTOS_core2/Demo/Minimal/MessageBufferAMP.c for
 * additional information.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer to which data was
 * written.
 *
 * @param pxHigherPriorityTaskWoken_core2 *pxHigherPriorityTaskWoken_core2 should be
 * initialised to pdFALSE_core2 before it is passed into
 * xStreamBufferSendCompletedFromISR_core2().  If calling
 * xStreamBufferSendCompletedFromISR_core2() removes a task_core2 from the Blocked state,
 * and the task_core2 has a priority above the priority of the currently running task_core2,
 * then *pxHigherPriorityTaskWoken_core2 will get set to pdTRUE_core2 indicating that a
 * context switch should be performed before exiting the ISR.
 *
 * @return If a task_core2 was removed from the Blocked state then pdTRUE_core2 is returned.
 * Otherwise pdFALSE_core2 is returned.
 *
 * \defgroup xStreamBufferSendCompletedFromISR_core2 xStreamBufferSendCompletedFromISR_core2
 * \ingroup StreamBufferManagement
 */
BaseType_t_core2 xStreamBufferSendCompletedFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                              BaseType_t_core2 * pxHigherPriorityTaskWoken_core2 ) PRIVILEGED_FUNCTION_core2;

/**
 * stream_buffer_core2.h
 *
 * @code{c}
 * BaseType_t_core2 xStreamBufferReceiveCompletedFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2, BaseType_t_core2 *pxHigherPriorityTaskWoken_core2 );
 * @endcode
 *
 * For advanced users only.
 *
 * The sbRECEIVE_COMPLETED() macro is called from within the FreeRTOS_core2 APIs when
 * data is read out of a message buffer or stream buffer.  If there was a task_core2
 * that was blocked on the message or stream buffer waiting for data to arrive
 * then the sbRECEIVE_COMPLETED() macro sends a notification to the task_core2 to
 * remove it from the Blocked state.  xStreamBufferReceiveCompletedFromISR_core2()
 * does the same thing.  It is provided to enable application writers to
 * implement their own version of sbRECEIVE_COMPLETED(), and MUST NOT BE USED AT
 * ANY OTHER TIME.
 *
 * See the example implemented in FreeRTOS_core2/Demo/Minimal/MessageBufferAMP.c for
 * additional information.
 *
 * @param xStreamBuffer_core2 The handle of the stream buffer from which data was
 * read.
 *
 * @param pxHigherPriorityTaskWoken_core2 *pxHigherPriorityTaskWoken_core2 should be
 * initialised to pdFALSE_core2 before it is passed into
 * xStreamBufferReceiveCompletedFromISR_core2().  If calling
 * xStreamBufferReceiveCompletedFromISR_core2() removes a task_core2 from the Blocked state,
 * and the task_core2 has a priority above the priority of the currently running task_core2,
 * then *pxHigherPriorityTaskWoken_core2 will get set to pdTRUE_core2 indicating that a
 * context switch should be performed before exiting the ISR.
 *
 * @return If a task_core2 was removed from the Blocked state then pdTRUE_core2 is returned.
 * Otherwise pdFALSE_core2 is returned.
 *
 * \defgroup xStreamBufferReceiveCompletedFromISR_core2 xStreamBufferReceiveCompletedFromISR_core2
 * \ingroup StreamBufferManagement
 */
BaseType_t_core2 xStreamBufferReceiveCompletedFromISR_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                                 BaseType_t_core2 * pxHigherPriorityTaskWoken_core2 ) PRIVILEGED_FUNCTION_core2;

/* Functions below here are not part of the public API. */
StreamBufferHandle_t_core2 xStreamBufferGenericCreate_core2( size_t xBufferSizeBytes_core2,
                                                 size_t xTriggerLevelBytes_core2,
                                                 BaseType_t_core2 xIsMessageBuffer_core2,
                                                 StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                                 StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 ) PRIVILEGED_FUNCTION_core2;


StreamBufferHandle_t_core2 xStreamBufferGenericCreateStatic_core2( size_t xBufferSizeBytes_core2,
                                                       size_t xTriggerLevelBytes_core2,
                                                       BaseType_t_core2 xIsMessageBuffer_core2,
                                                       uint8_t * const pucStreamBufferStorageArea_core2,
                                                       StaticStreamBuffer_t_core2 * const pxStaticStreamBuffer_core2,
                                                       StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                                       StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 ) PRIVILEGED_FUNCTION_core2;

size_t xStreamBufferNextMessageLengthBytes_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;

#if ( configUSE_TRACE_FACILITY_core2 == 1 )
    void vStreamBufferSetStreamBufferNumber_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                             UBaseType_t_core2 uxStreamBufferNumber ) PRIVILEGED_FUNCTION_core2;
    UBaseType_t_core2 uxStreamBufferGetStreamBufferNumber_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;
    uint8_t ucStreamBufferGetStreamBufferType_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) PRIVILEGED_FUNCTION_core2;
#endif

/* *INDENT-OFF* */
#if defined( __cplusplus )
    }
#endif
/* *INDENT-ON* */

#endif /* !defined( STREAM_BUFFER_H ) */
