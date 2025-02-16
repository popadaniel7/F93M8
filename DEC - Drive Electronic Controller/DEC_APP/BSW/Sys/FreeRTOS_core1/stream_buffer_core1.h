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

/*
 * Stream buffers are used to send a continuous stream of data from one task_core1 or
 * interrupt to another.  Their implementation is light weight, making them
 * particularly suited for interrupt to task_core1 and core to core communication
 * scenarios.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core1 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core1 or
 * interrupt that will write to the buffer (the writer), and only one task_core1 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core1 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xStreamBufferSend_core1()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core1()) inside a critical section section and set the
 * receive block time to 0.
 *
 */

#ifndef STREAM_BUFFER_CORE1_H
#define STREAM_BUFFER_CORE1_H

#ifndef INC_FREERTOS_CORE1_H
    #error "include FreeRTOS_core1.h must appear in source files before include stream_buffer_core1.h"
#endif

/* *INDENT-OFF* */
#if defined( __cplusplus )
    extern "C" {
#endif
/* *INDENT-ON* */

/**
 * Type by which stream buffers are referenced.  For example, a call to
 * xStreamBufferCreate_core1() returns an StreamBufferHandle_t_core1 variable that can
 * then be used as a parameter to xStreamBufferSend_core1(), xStreamBufferReceive_core1(),
 * etc.
 */
struct StreamBufferDef_t_core1;
typedef struct StreamBufferDef_t_core1 * StreamBufferHandle_t_core1;

/**
 *  Type used as a stream buffer's optional callback.
 */
typedef void (* StreamBufferCallbackFunction_t_core1)( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                                 BaseType_t_core1 xIsInsideISR_core1,
                                                 BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1 );

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * StreamBufferHandle_t_core1 xStreamBufferCreate_core1( size_t xBufferSizeBytes_core1, size_t xTriggerLevelBytes_core1 );
 * @endcode
 *
 * Creates a new stream buffer using dynamically allocated memory.  See
 * xStreamBufferCreateStatic_core1() for a version that uses statically allocated
 * memory (memory that is allocated at compile time).
 *
 * configSUPPORT_DYNAMIC_ALLOCATION_core1 must be set to 1 or left undefined in
 * FreeRTOSConfig.h for xStreamBufferCreate_core1() to be available.
 *
 * @param xBufferSizeBytes_core1 The total number of bytes the stream buffer will be
 * able to hold at any one time.
 *
 * @param xTriggerLevelBytes_core1 The number of bytes that must be in the stream
 * buffer before a task_core1 that is blocked on the stream buffer to wait for data is
 * moved out of the blocked state.  For example, if a task_core1 is blocked on a read
 * of an empty stream buffer that has a trigger level of 1 then the task_core1 will be
 * unblocked when a single byte is written to the buffer or the task_core1's block
 * time expires.  As another example, if a task_core1 is blocked on a read of an empty
 * stream buffer that has a trigger level of 10 then the task_core1 will not be
 * unblocked until the stream buffer contains at least 10 bytes or the task_core1's
 * block time expires.  If a reading task_core1's block time expires before the
 * trigger level is reached then the task_core1 will still receive however many bytes
 * are actually available.  Setting a trigger level of 0 will result in a
 * trigger level of 1 being used.  It is not valid to specify a trigger level
 * that is greater than the buffer size.
 *
 * @param pxSendCompletedCallback_core1 Callback invoked when number of bytes at least equal to
 * trigger level is sent to the stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbSEND_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core1 must be set to 1 in FreeRTOSConfig.h.
 *
 * @param pxReceiveCompletedCallback_core1 Callback invoked when more than zero bytes are read from a
 * stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbRECEIVE_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core1 must be set to 1 in FreeRTOSConfig.h.
 *
 * @return If NULL is returned, then the stream buffer cannot be created
 * because there is insufficient heap memory available for FreeRTOS_core1 to allocate
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
 * StreamBufferHandle_t_core1 xStreamBuffer_core1;
 * const size_t xStreamBufferSizeBytes = 100, xTriggerLevel_core1 = 10;
 *
 *  // Create a stream buffer that can hold 100 bytes.  The memory used to hold
 *  // both the stream buffer structure and the data in the stream buffer is
 *  // allocated dynamically.
 *  xStreamBuffer_core1 = xStreamBufferCreate_core1( xStreamBufferSizeBytes, xTriggerLevel_core1 );
 *
 *  if( xStreamBuffer_core1 == NULL )
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
 * \defgroup xStreamBufferCreate_core1 xStreamBufferCreate_core1
 * \ingroup StreamBufferManagement
 */

#define xStreamBufferCreate_core1( xBufferSizeBytes_core1, xTriggerLevelBytes_core1 ) \
    xStreamBufferGenericCreate_core1( ( xBufferSizeBytes_core1 ), ( xTriggerLevelBytes_core1 ), pdFALSE_core1, NULL, NULL )

#if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
    #define xStreamBufferCreateWithCallback_core1( xBufferSizeBytes_core1, xTriggerLevelBytes_core1, pxSendCompletedCallback_core1, pxReceiveCompletedCallback_core1 ) \
    xStreamBufferGenericCreate_core1( ( xBufferSizeBytes_core1 ), ( xTriggerLevelBytes_core1 ), pdFALSE_core1, ( pxSendCompletedCallback_core1 ), ( pxReceiveCompletedCallback_core1 ) )
#endif

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * StreamBufferHandle_t_core1 xStreamBufferCreateStatic_core1( size_t xBufferSizeBytes_core1,
 *                                              size_t xTriggerLevelBytes_core1,
 *                                              uint8_t *pucStreamBufferStorageArea_core1,
 *                                              StaticStreamBuffer_t_core1 *pxStaticStreamBuffer_core1 );
 * @endcode
 * Creates a new stream buffer using statically allocated memory.  See
 * xStreamBufferCreate_core1() for a version that uses dynamically allocated memory.
 *
 * configSUPPORT_STATIC_ALLOCATION_core1 must be set to 1 in FreeRTOSConfig.h for
 * xStreamBufferCreateStatic_core1() to be available.
 *
 * @param xBufferSizeBytes_core1 The size, in bytes, of the buffer pointed to by the
 * pucStreamBufferStorageArea_core1 parameter.
 *
 * @param xTriggerLevelBytes_core1 The number of bytes that must be in the stream
 * buffer before a task_core1 that is blocked on the stream buffer to wait for data is
 * moved out of the blocked state.  For example, if a task_core1 is blocked on a read
 * of an empty stream buffer that has a trigger level of 1 then the task_core1 will be
 * unblocked when a single byte is written to the buffer or the task_core1's block
 * time expires.  As another example, if a task_core1 is blocked on a read of an empty
 * stream buffer that has a trigger level of 10 then the task_core1 will not be
 * unblocked until the stream buffer contains at least 10 bytes or the task_core1's
 * block time expires.  If a reading task_core1's block time expires before the
 * trigger level is reached then the task_core1 will still receive however many bytes
 * are actually available.  Setting a trigger level of 0 will result in a
 * trigger level of 1 being used.  It is not valid to specify a trigger level
 * that is greater than the buffer size.
 *
 * @param pucStreamBufferStorageArea_core1 Must point to a uint8_t array that is at
 * least xBufferSizeBytes_core1 big.  This is the array to which streams are
 * copied when they are written to the stream buffer.
 *
 * @param pxStaticStreamBuffer_core1 Must point to a variable of type
 * StaticStreamBuffer_t_core1, which will be used to hold the stream buffer's data
 * structure.
 *
 * @param pxSendCompletedCallback_core1 Callback invoked when number of bytes at least equal to
 * trigger level is sent to the stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbSEND_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core1 must be set to 1 in FreeRTOSConfig.h.
 *
 * @param pxReceiveCompletedCallback_core1 Callback invoked when more than zero bytes are read from a
 * stream buffer. If the parameter is NULL, it will use the default
 * implementation provided by sbRECEIVE_COMPLETED macro. To enable the callback,
 * configUSE_SB_COMPLETED_CALLBACK_core1 must be set to 1 in FreeRTOSConfig.h.
 *
 * @return If the stream buffer is created successfully then a handle to the
 * created stream buffer is returned. If either pucStreamBufferStorageArea_core1 or
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
 * StaticStreamBuffer_t_core1 xStreamBufferStruct;
 *
 * void MyFunction( void )
 * {
 * StreamBufferHandle_t_core1 xStreamBuffer_core1;
 * const size_t xTriggerLevel_core1 = 1;
 *
 *  xStreamBuffer_core1 = xStreamBufferCreateStatic_core1( sizeof( ucStorageBuffer ),
 *                                             xTriggerLevel_core1,
 *                                             ucStorageBuffer,
 *                                             &xStreamBufferStruct );
 *
 *  // As neither the pucStreamBufferStorageArea_core1 or pxStaticStreamBuffer_core1
 *  // parameters were NULL, xStreamBuffer_core1 will not be NULL, and can be used to
 *  // reference the created stream buffer in other stream buffer API calls.
 *
 *  // Other code that uses the stream buffer can go here.
 * }
 *
 * @endcode
 * \defgroup xStreamBufferCreateStatic_core1 xStreamBufferCreateStatic_core1
 * \ingroup StreamBufferManagement
 */

#define xStreamBufferCreateStatic_core1( xBufferSizeBytes_core1, xTriggerLevelBytes_core1, pucStreamBufferStorageArea_core1, pxStaticStreamBuffer_core1 ) \
    xStreamBufferGenericCreateStatic_core1( ( xBufferSizeBytes_core1 ), ( xTriggerLevelBytes_core1 ), pdFALSE_core1, ( pucStreamBufferStorageArea_core1 ), ( pxStaticStreamBuffer_core1 ), NULL, NULL )

#if ( configUSE_SB_COMPLETED_CALLBACK_core1 == 1 )
    #define xStreamBufferCreateStaticWithCallback_core1( xBufferSizeBytes_core1, xTriggerLevelBytes_core1, pucStreamBufferStorageArea_core1, pxStaticStreamBuffer_core1, pxSendCompletedCallback_core1, pxReceiveCompletedCallback_core1 ) \
    xStreamBufferGenericCreateStatic_core1( ( xBufferSizeBytes_core1 ), ( xTriggerLevelBytes_core1 ), pdFALSE_core1, ( pucStreamBufferStorageArea_core1 ), ( pxStaticStreamBuffer_core1 ), ( pxSendCompletedCallback_core1 ), ( pxReceiveCompletedCallback_core1 ) )
#endif

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * size_t xStreamBufferSend_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
 *                        const void *pvTxData_core1,
 *                        size_t xDataLengthBytes_core1,
 *                        TickType_t_core1 xTicksToWait_core1 );
 * @endcode
 *
 * Sends bytes to a stream buffer.  The bytes are copied into the stream buffer.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core1 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core1 or
 * interrupt that will write to the buffer (the writer), and only one task_core1 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core1 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xStreamBufferSend_core1()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core1()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xStreamBufferSend_core1() to write to a stream buffer from a task_core1.  Use
 * xStreamBufferSendFromISR_core1() to write to a stream buffer from an interrupt
 * service routine (ISR).
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer to which a stream is
 * being sent.
 *
 * @param pvTxData_core1 A pointer to the buffer that holds the bytes to be copied
 * into the stream buffer.
 *
 * @param xDataLengthBytes_core1   The maximum number of bytes to copy from pvTxData_core1
 * into the stream buffer.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should remain in the
 * Blocked state to wait for enough space to become available in the stream
 * buffer, should the stream buffer contain too little space to hold the
 * another xDataLengthBytes_core1 bytes.  The block time is specified in tick periods,
 * so the absolute time it represents is dependent on the tick frequency.  The
 * macro pdMS_TO_TICKS_core1() can be used to convert a time specified in milliseconds
 * into a time specified in ticks.  Setting xTicksToWait_core1 to portMAX_DELAY_core1 will
 * cause the task_core1 to wait indefinitely (without timing out), provided
 * INCLUDE_vTaskSuspend_core1 is set to 1 in FreeRTOSConfig.h.  If a task_core1 times out
 * before it can write all xDataLengthBytes_core1 into the buffer it will still write
 * as many bytes as possible.  A task_core1 does not use any CPU time when it is in
 * the blocked state.
 *
 * @return The number of bytes written to the stream buffer.  If a task_core1 times
 * out before it can write all xDataLengthBytes_core1 into the buffer it will still
 * write as many bytes as possible.
 *
 * Example use:
 * @code{c}
 * void vAFunction( StreamBufferHandle_t_core1 xStreamBuffer_core1 )
 * {
 * size_t xBytesSent_core1;
 * uint8_t ucArrayToSend[] = { 0, 1, 2, 3 };
 * char *pcStringToSend = "String to send";
 * const TickType_t_core1 x100ms = pdMS_TO_TICKS_core1( 100 );
 *
 *  // Send an array to the stream buffer, blocking for a maximum of 100ms to
 *  // wait for enough space to be available in the stream buffer.
 *  xBytesSent_core1 = xStreamBufferSend_core1( xStreamBuffer_core1, ( void * ) ucArrayToSend, sizeof( ucArrayToSend ), x100ms );
 *
 *  if( xBytesSent_core1 != sizeof( ucArrayToSend ) )
 *  {
 *      // The call to xStreamBufferSend_core1() times out before there was enough
 *      // space in the buffer for the data to be written, but it did
 *      // successfully write xBytesSent_core1 bytes.
 *  }
 *
 *  // Send the string to the stream buffer.  Return immediately if there is not
 *  // enough space in the buffer.
 *  xBytesSent_core1 = xStreamBufferSend_core1( xStreamBuffer_core1, ( void * ) pcStringToSend, strlen( pcStringToSend ), 0 );
 *
 *  if( xBytesSent_core1 != strlen( pcStringToSend ) )
 *  {
 *      // The entire string could not be added to the stream buffer because
 *      // there was not enough free space in the buffer, but xBytesSent_core1 bytes
 *      // were sent.  Could try again to send the remaining bytes.
 *  }
 * }
 * @endcode
 * \defgroup xStreamBufferSend_core1 xStreamBufferSend_core1
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferSend_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                          const void * pvTxData_core1,
                          size_t xDataLengthBytes_core1,
                          TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * size_t xStreamBufferSendFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
 *                               const void *pvTxData_core1,
 *                               size_t xDataLengthBytes_core1,
 *                               BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * @endcode
 *
 * Interrupt safe version of the API function that sends a stream of bytes to
 * the stream buffer.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core1 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core1 or
 * interrupt that will write to the buffer (the writer), and only one task_core1 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core1 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xStreamBufferSend_core1()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core1()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xStreamBufferSend_core1() to write to a stream buffer from a task_core1.  Use
 * xStreamBufferSendFromISR_core1() to write to a stream buffer from an interrupt
 * service routine (ISR).
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer to which a stream is
 * being sent.
 *
 * @param pvTxData_core1 A pointer to the data that is to be copied into the stream
 * buffer.
 *
 * @param xDataLengthBytes_core1 The maximum number of bytes to copy from pvTxData_core1
 * into the stream buffer.
 *
 * @param pxHigherPriorityTaskWoken_core1  It is possible that a stream buffer will
 * have a task_core1 blocked on it waiting for data.  Calling
 * xStreamBufferSendFromISR_core1() can make data available, and so cause a task_core1 that
 * was waiting for data to leave the Blocked state.  If calling
 * xStreamBufferSendFromISR_core1() causes a task_core1 to leave the Blocked state, and the
 * unblocked task_core1 has a priority higher than the currently executing task_core1 (the
 * task_core1 that was interrupted), then, internally, xStreamBufferSendFromISR_core1()
 * will set *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1.  If
 * xStreamBufferSendFromISR_core1() sets this value to pdTRUE_core1, then normally a
 * context switch should be performed before the interrupt is exited.  This will
 * ensure that the interrupt returns directly to the highest priority Ready
 * state task_core1.  *pxHigherPriorityTaskWoken_core1 should be set to pdFALSE_core1 before it
 * is passed into the function.  See the example code below for an example.
 *
 * @return The number of bytes actually written to the stream buffer, which will
 * be less than xDataLengthBytes_core1 if the stream buffer didn't have enough free
 * space for all the bytes to be written.
 *
 * Example use:
 * @code{c}
 * // A stream buffer that has already been created.
 * StreamBufferHandle_t_core1 xStreamBuffer_core1;
 *
 * void vAnInterruptServiceRoutine( void )
 * {
 * size_t xBytesSent_core1;
 * char *pcStringToSend = "String to send";
 * BaseType_t_core1 xHigherPriorityTaskWoken_core1 = pdFALSE_core1; // Initialised to pdFALSE_core1.
 *
 *  // Attempt to send the string to the stream buffer.
 *  xBytesSent_core1 = xStreamBufferSendFromISR_core1( xStreamBuffer_core1,
 *                                         ( void * ) pcStringToSend,
 *                                         strlen( pcStringToSend ),
 *                                         &xHigherPriorityTaskWoken_core1 );
 *
 *  if( xBytesSent_core1 != strlen( pcStringToSend ) )
 *  {
 *      // There was not enough free space in the stream buffer for the entire
 *      // string to be written, ut xBytesSent_core1 bytes were written.
 *  }
 *
 *  // If xHigherPriorityTaskWoken_core1 was set to pdTRUE_core1 inside
 *  // xStreamBufferSendFromISR_core1() then a task_core1 that has a priority above the
 *  // priority of the currently executing task_core1 was unblocked and a context
 *  // switch should be performed to ensure the ISR returns to the unblocked
 *  // task_core1.  In most FreeRTOS_core1 ports this is done by simply passing
 *  // xHigherPriorityTaskWoken_core1 into portYIELD_FROM_ISR_core1(), which will test the
 *  // variables value, and perform the context switch if necessary.  Check the
 *  // documentation for the port in use for port specific instructions.
 *  portYIELD_FROM_ISR_core1( xHigherPriorityTaskWoken_core1 );
 * }
 * @endcode
 * \defgroup xStreamBufferSendFromISR_core1 xStreamBufferSendFromISR_core1
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferSendFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                 const void * pvTxData_core1,
                                 size_t xDataLengthBytes_core1,
                                 BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * size_t xStreamBufferReceive_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
 *                           void *pvRxData_core1,
 *                           size_t xBufferLengthBytes_core1,
 *                           TickType_t_core1 xTicksToWait_core1 );
 * @endcode
 *
 * Receives bytes from a stream buffer.
 *
 * ***NOTE***:  Uniquely among FreeRTOS_core1 objects, the stream buffer
 * implementation (so also the message buffer implementation, as message buffers
 * are built on top of stream buffers) assumes there is only one task_core1 or
 * interrupt that will write to the buffer (the writer), and only one task_core1 or
 * interrupt that will read from the buffer (the reader).  It is safe for the
 * writer and reader to be different tasks or interrupts, but, unlike other
 * FreeRTOS_core1 objects, it is not safe to have multiple different writers or
 * multiple different readers.  If there are to be multiple different writers
 * then the application writer must place each call to a writing API function
 * (such as xStreamBufferSend_core1()) inside a critical section and set the send
 * block time to 0.  Likewise, if there are to be multiple different readers
 * then the application writer must place each call to a reading API function
 * (such as xStreamBufferReceive_core1()) inside a critical section and set the receive
 * block time to 0.
 *
 * Use xStreamBufferReceive_core1() to read from a stream buffer from a task_core1.  Use
 * xStreamBufferReceiveFromISR_core1() to read from a stream buffer from an
 * interrupt service routine (ISR).
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer from which bytes are to
 * be received.
 *
 * @param pvRxData_core1 A pointer to the buffer into which the received bytes will be
 * copied.
 *
 * @param xBufferLengthBytes_core1 The length of the buffer pointed to by the
 * pvRxData_core1 parameter.  This sets the maximum number of bytes to receive in one
 * call.  xStreamBufferReceive_core1 will return as many bytes as possible up to a
 * maximum set by xBufferLengthBytes_core1.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should remain in the
 * Blocked state to wait for data to become available if the stream buffer is
 * empty.  xStreamBufferReceive_core1() will return immediately if xTicksToWait_core1 is
 * zero.  The block time is specified in tick periods, so the absolute time it
 * represents is dependent on the tick frequency.  The macro pdMS_TO_TICKS_core1() can
 * be used to convert a time specified in milliseconds into a time specified in
 * ticks.  Setting xTicksToWait_core1 to portMAX_DELAY_core1 will cause the task_core1 to wait
 * indefinitely (without timing out), provided INCLUDE_vTaskSuspend_core1 is set to 1
 * in FreeRTOSConfig.h.  A task_core1 does not use any CPU time when it is in the
 * Blocked state.
 *
 * @return The number of bytes actually read from the stream buffer, which will
 * be less than xBufferLengthBytes_core1 if the call to xStreamBufferReceive_core1() timed
 * out before xBufferLengthBytes_core1 were available.
 *
 * Example use:
 * @code{c}
 * void vAFunction( StreamBuffer_t xStreamBuffer_core1 )
 * {
 * uint8_t ucRxData[ 20 ];
 * size_t xReceivedBytes;
 * const TickType_t_core1 xBlockTime_core1 = pdMS_TO_TICKS_core1( 20 );
 *
 *  // Receive up to another sizeof( ucRxData ) bytes from the stream buffer.
 *  // Wait in the Blocked state (so not using any CPU processing time) for a
 *  // maximum of 100ms for the full sizeof( ucRxData ) number of bytes to be
 *  // available.
 *  xReceivedBytes = xStreamBufferReceive_core1( xStreamBuffer_core1,
 *                                         ( void * ) ucRxData,
 *                                         sizeof( ucRxData ),
 *                                         xBlockTime_core1 );
 *
 *  if( xReceivedBytes > 0 )
 *  {
 *      // A ucRxData contains another xReceivedBytes bytes of data, which can
 *      // be processed here....
 *  }
 * }
 * @endcode
 * \defgroup xStreamBufferReceive_core1 xStreamBufferReceive_core1
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferReceive_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                             void * pvRxData_core1,
                             size_t xBufferLengthBytes_core1,
                             TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * size_t xStreamBufferReceiveFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
 *                                  void *pvRxData_core1,
 *                                  size_t xBufferLengthBytes_core1,
 *                                  BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * @endcode
 *
 * An interrupt safe version of the API function that receives bytes from a
 * stream buffer.
 *
 * Use xStreamBufferReceive_core1() to read bytes from a stream buffer from a task_core1.
 * Use xStreamBufferReceiveFromISR_core1() to read bytes from a stream buffer from an
 * interrupt service routine (ISR).
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer from which a stream
 * is being received.
 *
 * @param pvRxData_core1 A pointer to the buffer into which the received bytes are
 * copied.
 *
 * @param xBufferLengthBytes_core1 The length of the buffer pointed to by the
 * pvRxData_core1 parameter.  This sets the maximum number of bytes to receive in one
 * call.  xStreamBufferReceive_core1 will return as many bytes as possible up to a
 * maximum set by xBufferLengthBytes_core1.
 *
 * @param pxHigherPriorityTaskWoken_core1  It is possible that a stream buffer will
 * have a task_core1 blocked on it waiting for space to become available.  Calling
 * xStreamBufferReceiveFromISR_core1() can make space available, and so cause a task_core1
 * that is waiting for space to leave the Blocked state.  If calling
 * xStreamBufferReceiveFromISR_core1() causes a task_core1 to leave the Blocked state, and
 * the unblocked task_core1 has a priority higher than the currently executing task_core1
 * (the task_core1 that was interrupted), then, internally,
 * xStreamBufferReceiveFromISR_core1() will set *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1.
 * If xStreamBufferReceiveFromISR_core1() sets this value to pdTRUE_core1, then normally a
 * context switch should be performed before the interrupt is exited.  That will
 * ensure the interrupt returns directly to the highest priority Ready state
 * task_core1.  *pxHigherPriorityTaskWoken_core1 should be set to pdFALSE_core1 before it is
 * passed into the function.  See the code example below for an example.
 *
 * @return The number of bytes read from the stream buffer, if any.
 *
 * Example use:
 * @code{c}
 * // A stream buffer that has already been created.
 * StreamBuffer_t xStreamBuffer_core1;
 *
 * void vAnInterruptServiceRoutine( void )
 * {
 * uint8_t ucRxData[ 20 ];
 * size_t xReceivedBytes;
 * BaseType_t_core1 xHigherPriorityTaskWoken_core1 = pdFALSE_core1;  // Initialised to pdFALSE_core1.
 *
 *  // Receive the next stream from the stream buffer.
 *  xReceivedBytes = xStreamBufferReceiveFromISR_core1( xStreamBuffer_core1,
 *                                                ( void * ) ucRxData,
 *                                                sizeof( ucRxData ),
 *                                                &xHigherPriorityTaskWoken_core1 );
 *
 *  if( xReceivedBytes > 0 )
 *  {
 *      // ucRxData contains xReceivedBytes read from the stream buffer.
 *      // Process the stream here....
 *  }
 *
 *  // If xHigherPriorityTaskWoken_core1 was set to pdTRUE_core1 inside
 *  // xStreamBufferReceiveFromISR_core1() then a task_core1 that has a priority above the
 *  // priority of the currently executing task_core1 was unblocked and a context
 *  // switch should be performed to ensure the ISR returns to the unblocked
 *  // task_core1.  In most FreeRTOS_core1 ports this is done by simply passing
 *  // xHigherPriorityTaskWoken_core1 into portYIELD_FROM_ISR_core1(), which will test the
 *  // variables value, and perform the context switch if necessary.  Check the
 *  // documentation for the port in use for port specific instructions.
 *  portYIELD_FROM_ISR_core1( xHigherPriorityTaskWoken_core1 );
 * }
 * @endcode
 * \defgroup xStreamBufferReceiveFromISR_core1 xStreamBufferReceiveFromISR_core1
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferReceiveFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                    void * pvRxData_core1,
                                    size_t xBufferLengthBytes_core1,
                                    BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * void vStreamBufferDelete_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 );
 * @endcode
 *
 * Deletes a stream buffer that was previously created using a call to
 * xStreamBufferCreate_core1() or xStreamBufferCreateStatic_core1().  If the stream
 * buffer was created using dynamic memory (that is, by xStreamBufferCreate_core1()),
 * then the allocated memory is freed.
 *
 * A stream buffer handle must not be used after the stream buffer has been
 * deleted.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer to be deleted.
 *
 * \defgroup vStreamBufferDelete_core1 vStreamBufferDelete_core1
 * \ingroup StreamBufferManagement
 */
void vStreamBufferDelete_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * BaseType_t_core1 xStreamBufferIsFull_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 );
 * @endcode
 *
 * Queries a stream buffer to see if it is full.  A stream buffer is full if it
 * does not have any free space, and therefore cannot accept any more data.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer being queried.
 *
 * @return If the stream buffer is full then pdTRUE_core1 is returned.  Otherwise
 * pdFALSE_core1 is returned.
 *
 * \defgroup xStreamBufferIsFull_core1 xStreamBufferIsFull_core1
 * \ingroup StreamBufferManagement
 */
BaseType_t_core1 xStreamBufferIsFull_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * BaseType_t_core1 xStreamBufferIsEmpty_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 );
 * @endcode
 *
 * Queries a stream buffer to see if it is empty.  A stream buffer is empty if
 * it does not contain any data.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer being queried.
 *
 * @return If the stream buffer is empty then pdTRUE_core1 is returned.  Otherwise
 * pdFALSE_core1 is returned.
 *
 * \defgroup xStreamBufferIsEmpty_core1 xStreamBufferIsEmpty_core1
 * \ingroup StreamBufferManagement
 */
BaseType_t_core1 xStreamBufferIsEmpty_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * BaseType_t_core1 xStreamBufferReset_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 );
 * @endcode
 *
 * Resets a stream buffer to its initial, empty, state.  Any data that was in
 * the stream buffer is discarded.  A stream buffer can only be reset if there
 * are no tasks blocked waiting to either send to or receive from the stream
 * buffer.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer being reset.
 *
 * @return If the stream buffer is reset then pdPASS_core1 is returned.  If there was
 * a task_core1 blocked waiting to send to or read from the stream buffer then the
 * stream buffer is not reset and pdFAIL_core1 is returned.
 *
 * \defgroup xStreamBufferReset_core1 xStreamBufferReset_core1
 * \ingroup StreamBufferManagement
 */
BaseType_t_core1 xStreamBufferReset_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * size_t xStreamBufferSpacesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 );
 * @endcode
 *
 * Queries a stream buffer to see how much free space it contains, which is
 * equal to the amount of data that can be sent to the stream buffer before it
 * is full.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer being queried.
 *
 * @return The number of bytes that can be written to the stream buffer before
 * the stream buffer would be full.
 *
 * \defgroup xStreamBufferSpacesAvailable_core1 xStreamBufferSpacesAvailable_core1
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferSpacesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * size_t xStreamBufferBytesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 );
 * @endcode
 *
 * Queries a stream buffer to see how much data it contains, which is equal to
 * the number of bytes that can be read from the stream buffer before the stream
 * buffer would be empty.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer being queried.
 *
 * @return The number of bytes that can be read from the stream buffer before
 * the stream buffer would be empty.
 *
 * \defgroup xStreamBufferBytesAvailable_core1 xStreamBufferBytesAvailable_core1
 * \ingroup StreamBufferManagement
 */
size_t xStreamBufferBytesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * BaseType_t_core1 xStreamBufferSetTriggerLevel_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1, size_t xTriggerLevel_core1 );
 * @endcode
 *
 * A stream buffer's trigger level is the number of bytes that must be in the
 * stream buffer before a task_core1 that is blocked on the stream buffer to
 * wait for data is moved out of the blocked state.  For example, if a task_core1 is
 * blocked on a read of an empty stream buffer that has a trigger level of 1
 * then the task_core1 will be unblocked when a single byte is written to the buffer
 * or the task_core1's block time expires.  As another example, if a task_core1 is blocked
 * on a read of an empty stream buffer that has a trigger level of 10 then the
 * task_core1 will not be unblocked until the stream buffer contains at least 10 bytes
 * or the task_core1's block time expires.  If a reading task_core1's block time expires
 * before the trigger level is reached then the task_core1 will still receive however
 * many bytes are actually available.  Setting a trigger level of 0 will result
 * in a trigger level of 1 being used.  It is not valid to specify a trigger
 * level that is greater than the buffer size.
 *
 * A trigger level is set when the stream buffer is created, and can be modified
 * using xStreamBufferSetTriggerLevel_core1().
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer being updated.
 *
 * @param xTriggerLevel_core1 The new trigger level for the stream buffer.
 *
 * @return If xTriggerLevel_core1 was less than or equal to the stream buffer's length
 * then the trigger level will be updated and pdTRUE_core1 is returned.  Otherwise
 * pdFALSE_core1 is returned.
 *
 * \defgroup xStreamBufferSetTriggerLevel_core1 xStreamBufferSetTriggerLevel_core1
 * \ingroup StreamBufferManagement
 */
BaseType_t_core1 xStreamBufferSetTriggerLevel_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                         size_t xTriggerLevel_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * BaseType_t_core1 xStreamBufferSendCompletedFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * @endcode
 *
 * For advanced users only.
 *
 * The sbSEND_COMPLETED() macro is called from within the FreeRTOS_core1 APIs when
 * data is sent to a message buffer or stream buffer.  If there was a task_core1 that
 * was blocked on the message or stream buffer waiting for data to arrive then
 * the sbSEND_COMPLETED() macro sends a notification to the task_core1 to remove it
 * from the Blocked state.  xStreamBufferSendCompletedFromISR_core1() does the same
 * thing.  It is provided to enable application writers to implement their own
 * version of sbSEND_COMPLETED(), and MUST NOT BE USED AT ANY OTHER TIME.
 *
 * See the example implemented in FreeRTOS_core1/Demo/Minimal/MessageBufferAMP.c for
 * additional information.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer to which data was
 * written.
 *
 * @param pxHigherPriorityTaskWoken_core1 *pxHigherPriorityTaskWoken_core1 should be
 * initialised to pdFALSE_core1 before it is passed into
 * xStreamBufferSendCompletedFromISR_core1().  If calling
 * xStreamBufferSendCompletedFromISR_core1() removes a task_core1 from the Blocked state,
 * and the task_core1 has a priority above the priority of the currently running task_core1,
 * then *pxHigherPriorityTaskWoken_core1 will get set to pdTRUE_core1 indicating that a
 * context switch should be performed before exiting the ISR.
 *
 * @return If a task_core1 was removed from the Blocked state then pdTRUE_core1 is returned.
 * Otherwise pdFALSE_core1 is returned.
 *
 * \defgroup xStreamBufferSendCompletedFromISR_core1 xStreamBufferSendCompletedFromISR_core1
 * \ingroup StreamBufferManagement
 */
BaseType_t_core1 xStreamBufferSendCompletedFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                              BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * stream_buffer_core1.h
 *
 * @code{c}
 * BaseType_t_core1 xStreamBufferReceiveCompletedFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1, BaseType_t_core1 *pxHigherPriorityTaskWoken_core1 );
 * @endcode
 *
 * For advanced users only.
 *
 * The sbRECEIVE_COMPLETED() macro is called from within the FreeRTOS_core1 APIs when
 * data is read out of a message buffer or stream buffer.  If there was a task_core1
 * that was blocked on the message or stream buffer waiting for data to arrive
 * then the sbRECEIVE_COMPLETED() macro sends a notification to the task_core1 to
 * remove it from the Blocked state.  xStreamBufferReceiveCompletedFromISR_core1()
 * does the same thing.  It is provided to enable application writers to
 * implement their own version of sbRECEIVE_COMPLETED(), and MUST NOT BE USED AT
 * ANY OTHER TIME.
 *
 * See the example implemented in FreeRTOS_core1/Demo/Minimal/MessageBufferAMP.c for
 * additional information.
 *
 * @param xStreamBuffer_core1 The handle of the stream buffer from which data was
 * read.
 *
 * @param pxHigherPriorityTaskWoken_core1 *pxHigherPriorityTaskWoken_core1 should be
 * initialised to pdFALSE_core1 before it is passed into
 * xStreamBufferReceiveCompletedFromISR_core1().  If calling
 * xStreamBufferReceiveCompletedFromISR_core1() removes a task_core1 from the Blocked state,
 * and the task_core1 has a priority above the priority of the currently running task_core1,
 * then *pxHigherPriorityTaskWoken_core1 will get set to pdTRUE_core1 indicating that a
 * context switch should be performed before exiting the ISR.
 *
 * @return If a task_core1 was removed from the Blocked state then pdTRUE_core1 is returned.
 * Otherwise pdFALSE_core1 is returned.
 *
 * \defgroup xStreamBufferReceiveCompletedFromISR_core1 xStreamBufferReceiveCompletedFromISR_core1
 * \ingroup StreamBufferManagement
 */
BaseType_t_core1 xStreamBufferReceiveCompletedFromISR_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                                 BaseType_t_core1 * pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;

/* Functions below here are not part of the public API. */
StreamBufferHandle_t_core1 xStreamBufferGenericCreate_core1( size_t xBufferSizeBytes_core1,
                                                 size_t xTriggerLevelBytes_core1,
                                                 BaseType_t_core1 xIsMessageBuffer_core1,
                                                 StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                                 StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 ) PRIVILEGED_FUNCTION_core1;


StreamBufferHandle_t_core1 xStreamBufferGenericCreateStatic_core1( size_t xBufferSizeBytes_core1,
                                                       size_t xTriggerLevelBytes_core1,
                                                       BaseType_t_core1 xIsMessageBuffer_core1,
                                                       uint8_t * const pucStreamBufferStorageArea_core1,
                                                       StaticStreamBuffer_t_core1 * const pxStaticStreamBuffer_core1,
                                                       StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                                       StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 ) PRIVILEGED_FUNCTION_core1;

size_t xStreamBufferNextMessageLengthBytes_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

#if ( configUSE_TRACE_FACILITY_core1 == 1 )
    void vStreamBufferSetStreamBufferNumber_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                             UBaseType_t_core1 uxStreamBufferNumber ) PRIVILEGED_FUNCTION_core1;
    UBaseType_t_core1 uxStreamBufferGetStreamBufferNumber_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;
    uint8_t ucStreamBufferGetStreamBufferType_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/* *INDENT-OFF* */
#if defined( __cplusplus )
    }
#endif
/* *INDENT-ON* */

#endif /* !defined( STREAM_BUFFER_H ) */
