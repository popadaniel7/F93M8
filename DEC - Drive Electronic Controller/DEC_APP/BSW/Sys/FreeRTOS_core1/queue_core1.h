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


#ifndef QUEUE_CORE1_H
#define QUEUE_CORE1_H

#ifndef INC_FREERTOS_CORE1_H
    #error "include FreeRTOS_core1.h" must appear in source files before "include queue.h"
#endif

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

#include "task_core1.h"

/**
 * Type by which queues are referenced.  For example, a call to xQueueCreate_core1()
 * returns an QueueHandle_t_core1 variable that can then be used as a parameter to
 * xQueueSend_core1(), xQueueReceive_core1(), etc.
 */
struct QueueDefinition; /* Using old naming convention so as not to break kernel aware debuggers. */
typedef struct QueueDefinition_core1   * QueueHandle_t_core1;

/**
 * Type by which queue sets are referenced.  For example, a call to
 * xQueueCreateSet_core1() returns an xQueueSet_core1 variable that can then be used as a
 * parameter to xQueueSelectFromSet_core1(), xQueueAddToSet_core1(), etc.
 */
typedef struct QueueDefinition_core1   * QueueSetHandle_t_core1;

/**
 * Queue sets can contain both queues and semaphores, so the
 * QueueSetMemberHandle_t_core1 is defined as a type to be used where a parameter or
 * return value can be either an QueueHandle_t_core1 or an SemaphoreHandle_t.
 */
typedef struct QueueDefinition_core1   * QueueSetMemberHandle_t_core1;

/* For internal use only. */
#define queueSEND_TO_BACK_core1                     ( ( BaseType_t_core1 ) 0 )
#define queueSEND_TO_FRONT_core1                    ( ( BaseType_t_core1 ) 1 )
#define queueOVERWRITE_core1                        ( ( BaseType_t_core1 ) 2 )

/* For internal use only.  These definitions *must* match those in queue.c. */
#define queueQUEUE_TYPE_BASE_core1                  ( ( uint8_t ) 0U )
#define queueQUEUE_TYPE_SET_core1                   ( ( uint8_t ) 0U )
#define queueQUEUE_TYPE_MUTEX_core1                 ( ( uint8_t ) 1U )
#define queueQUEUE_TYPE_COUNTING_SEMAPHORE_core1    ( ( uint8_t ) 2U )
#define queueQUEUE_TYPE_BINARY_SEMAPHORE_core1      ( ( uint8_t ) 3U )
#define queueQUEUE_TYPE_RECURSIVE_MUTEX_core1       ( ( uint8_t ) 4U )

/**
 * queue. h
 * @code{c}
 * QueueHandle_t_core1 xQueueCreate_core1(
 *                            UBaseType_t_core1 uxQueueLength_core1,
 *                            UBaseType_t_core1 uxItemSize_core1
 *                        );
 * @endcode
 *
 * Creates a new queue instance, and returns a handle by which the new queue
 * can be referenced.
 *
 * Internally, within the FreeRTOS_core1 implementation, queues use two blocks of
 * memory.  The first block is used to hold the queue's data structures.  The
 * second block is used to hold items placed into the queue.  If a queue is
 * created using xQueueCreate_core1() then both blocks of memory are automatically
 * dynamically allocated inside the xQueueCreate_core1() function.  (see
 * https://www.FreeRTOS_core1.org/a00111.html).  If a queue is created using
 * xQueueCreateStatic_core1() then the application writer must provide the memory that
 * will get used by the queue.  xQueueCreateStatic_core1() therefore allows a queue to
 * be created without using any dynamic memory allocation.
 *
 * https://www.FreeRTOS_core1.org/Embedded-RTOS-Queues.html
 *
 * @param uxQueueLength_core1 The maximum number of items that the queue can contain.
 *
 * @param uxItemSize_core1 The number of bytes each item in the queue will require.
 * Items are queued by copy, not by reference, so this is the number of bytes
 * that will be copied for each posted item.  Each item on the queue must be
 * the same size.
 *
 * @return If the queue is successfully create then a handle to the newly
 * created queue is returned.  If the queue cannot be created then 0 is
 * returned.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * };
 *
 * void vATask( void *pvParameters_core1 )
 * {
 * QueueHandle_t_core1 xQueue1, xQueue2;
 *
 *  // Create a queue capable of containing 10 uint32_t values.
 *  xQueue1 = xQueueCreate_core1( 10, sizeof( uint32_t ) );
 *  if( xQueue1 == 0 )
 *  {
 *      // Queue was not created and must not be used.
 *  }
 *
 *  // Create a queue capable of containing 10 pointers to AMessage structures.
 *  // These should be passed by pointer as they contain a lot of data.
 *  xQueue2 = xQueueCreate_core1( 10, sizeof( struct AMessage * ) );
 *  if( xQueue2 == 0 )
 *  {
 *      // Queue was not created and must not be used.
 *  }
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueueCreate_core1 xQueueCreate_core1
 * \ingroup QueueManagement
 */
#if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )
    #define xQueueCreate_core1( uxQueueLength_core1, uxItemSize_core1 )    xQueueGenericCreate_core1( ( uxQueueLength_core1 ), ( uxItemSize_core1 ), ( queueQUEUE_TYPE_BASE_core1 ) )
#endif

/**
 * queue. h
 * @code{c}
 * QueueHandle_t_core1 xQueueCreateStatic_core1(
 *                            UBaseType_t_core1 uxQueueLength_core1,
 *                            UBaseType_t_core1 uxItemSize_core1,
 *                            uint8_t *pucQueueStorage_core1,
 *                            StaticQueue_t_core1 *pxQueueBuffer
 *                        );
 * @endcode
 *
 * Creates a new queue instance, and returns a handle by which the new queue
 * can be referenced.
 *
 * Internally, within the FreeRTOS_core1 implementation, queues use two blocks of
 * memory.  The first block is used to hold the queue's data structures.  The
 * second block is used to hold items placed into the queue.  If a queue is
 * created using xQueueCreate_core1() then both blocks of memory are automatically
 * dynamically allocated inside the xQueueCreate_core1() function.  (see
 * https://www.FreeRTOS_core1.org/a00111.html).  If a queue is created using
 * xQueueCreateStatic_core1() then the application writer must provide the memory that
 * will get used by the queue.  xQueueCreateStatic_core1() therefore allows a queue to
 * be created without using any dynamic memory allocation.
 *
 * https://www.FreeRTOS_core1.org/Embedded-RTOS-Queues.html
 *
 * @param uxQueueLength_core1 The maximum number of items that the queue can contain.
 *
 * @param uxItemSize_core1 The number of bytes each item in the queue will require.
 * Items are queued by copy, not by reference, so this is the number of bytes
 * that will be copied for each posted item.  Each item on the queue must be
 * the same size.
 *
 * @param pucQueueStorage_core1 If uxItemSize_core1 is not zero then
 * pucQueueStorage_core1 must point to a uint8_t array that is at least large
 * enough to hold the maximum number of items that can be in the queue at any
 * one time - which is ( uxQueueLength_core1 * uxItemsSize ) bytes.  If uxItemSize_core1 is
 * zero then pucQueueStorage_core1 can be NULL.
 *
 * @param pxQueueBuffer Must point to a variable of type StaticQueue_t_core1, which
 * will be used to hold the queue's data structure.
 *
 * @return If the queue is created then a handle to the created queue is
 * returned.  If pxQueueBuffer is NULL then NULL is returned.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * };
 *
 #define QUEUE_LENGTH 10
 #define ITEM_SIZE sizeof( uint32_t )
 *
 * // xQueueBuffer will hold the queue structure.
 * StaticQueue_t_core1 xQueueBuffer;
 *
 * // ucQueueStorage will hold the items posted to the queue.  Must be at least
 * // [(queue length) * ( queue item size)] bytes long.
 * uint8_t ucQueueStorage[ QUEUE_LENGTH * ITEM_SIZE ];
 *
 * void vATask( void *pvParameters_core1 )
 * {
 *  QueueHandle_t_core1 xQueue1;
 *
 *  // Create a queue capable of containing 10 uint32_t values.
 *  xQueue1 = xQueueCreate_core1( QUEUE_LENGTH, // The number of items the queue can hold.
 *                          ITEM_SIZE     // The size of each item in the queue
 *                          &( ucQueueStorage[ 0 ] ), // The buffer that will hold the items in the queue.
 *                          &xQueueBuffer ); // The buffer that will hold the queue structure.
 *
 *  // The queue is guaranteed to be created successfully as no dynamic memory
 *  // allocation is used.  Therefore xQueue1 is now a handle to a valid queue.
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueueCreateStatic_core1 xQueueCreateStatic_core1
 * \ingroup QueueManagement
 */
#if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )
    #define xQueueCreateStatic_core1( uxQueueLength_core1, uxItemSize_core1, pucQueueStorage_core1, pxQueueBuffer_core1 )    xQueueGenericCreateStatic_core1( ( uxQueueLength_core1 ), ( uxItemSize_core1 ), ( pucQueueStorage_core1 ), ( pxQueueBuffer_core1 ), ( queueQUEUE_TYPE_BASE_core1 ) )
#endif /* configSUPPORT_STATIC_ALLOCATION_core1 */

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueSendToToFront(
 *                                 QueueHandle_t_core1    xQueue_core1,
 *                                 const void       *pvItemToQueue_core1,
 *                                 TickType_t_core1       xTicksToWait_core1
 *                             );
 * @endcode
 *
 * Post an item to the front of a queue.  The item is queued by copy, not by
 * reference.  This function must not be called from an interrupt service
 * routine.  See xQueueSendFromISR_core1 () for an alternative which may be used
 * in an ISR.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should block
 * waiting for space to become available on the queue, should it already
 * be full.  The call will return immediately if this is set to 0 and the
 * queue is full.  The time is defined in tick periods so the constant
 * portTICK_PERIOD_MS_core1 should be used to convert to real time if this is required.
 *
 * @return pdTRUE_core1 if the item was successfully posted, otherwise errQUEUE_FULL_core1.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * } xMessage_core1;
 *
 * uint32_t ulVar = 10UL;
 *
 * void vATask( void *pvParameters_core1 )
 * {
 * QueueHandle_t_core1 xQueue1, xQueue2;
 * struct AMessage *pxMessage;
 *
 *  // Create a queue capable of containing 10 uint32_t values.
 *  xQueue1 = xQueueCreate_core1( 10, sizeof( uint32_t ) );
 *
 *  // Create a queue capable of containing 10 pointers to AMessage structures.
 *  // These should be passed by pointer as they contain a lot of data.
 *  xQueue2 = xQueueCreate_core1( 10, sizeof( struct AMessage * ) );
 *
 *  // ...
 *
 *  if( xQueue1 != 0 )
 *  {
 *      // Send an uint32_t.  Wait for 10 ticks for space to become
 *      // available if necessary.
 *      if( xQueueSendToFront_core1( xQueue1, ( void * ) &ulVar, ( TickType_t_core1 ) 10 ) != pdPASS_core1 )
 *      {
 *          // Failed to post the message, even after 10 ticks.
 *      }
 *  }
 *
 *  if( xQueue2 != 0 )
 *  {
 *      // Send a pointer to a struct AMessage object.  Don't block if the
 *      // queue is already full.
 *      pxMessage = & xMessage_core1;
 *      xQueueSendToFront_core1( xQueue2, ( void * ) &pxMessage, ( TickType_t_core1 ) 0 );
 *  }
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueueSend_core1 xQueueSend_core1
 * \ingroup QueueManagement
 */
#define xQueueSendToFront_core1( xQueue_core1, pvItemToQueue_core1, xTicksToWait_core1 ) \
    xQueueGenericSend_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), ( xTicksToWait_core1 ), queueSEND_TO_FRONT_core1 )

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueSendToBack_core1(
 *                                 QueueHandle_t_core1    xQueue_core1,
 *                                 const void       *pvItemToQueue_core1,
 *                                 TickType_t_core1       xTicksToWait_core1
 *                             );
 * @endcode
 *
 * This is a macro that calls xQueueGenericSend_core1().
 *
 * Post an item to the back of a queue.  The item is queued by copy, not by
 * reference.  This function must not be called from an interrupt service
 * routine.  See xQueueSendFromISR_core1 () for an alternative which may be used
 * in an ISR.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should block
 * waiting for space to become available on the queue, should it already
 * be full.  The call will return immediately if this is set to 0 and the queue
 * is full.  The  time is defined in tick periods so the constant
 * portTICK_PERIOD_MS_core1 should be used to convert to real time if this is required.
 *
 * @return pdTRUE_core1 if the item was successfully posted, otherwise errQUEUE_FULL_core1.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * } xMessage_core1;
 *
 * uint32_t ulVar = 10UL;
 *
 * void vATask( void *pvParameters_core1 )
 * {
 * QueueHandle_t_core1 xQueue1, xQueue2;
 * struct AMessage *pxMessage;
 *
 *  // Create a queue capable of containing 10 uint32_t values.
 *  xQueue1 = xQueueCreate_core1( 10, sizeof( uint32_t ) );
 *
 *  // Create a queue capable of containing 10 pointers to AMessage structures.
 *  // These should be passed by pointer as they contain a lot of data.
 *  xQueue2 = xQueueCreate_core1( 10, sizeof( struct AMessage * ) );
 *
 *  // ...
 *
 *  if( xQueue1 != 0 )
 *  {
 *      // Send an uint32_t.  Wait for 10 ticks for space to become
 *      // available if necessary.
 *      if( xQueueSendToBack_core1( xQueue1, ( void * ) &ulVar, ( TickType_t_core1 ) 10 ) != pdPASS_core1 )
 *      {
 *          // Failed to post the message, even after 10 ticks.
 *      }
 *  }
 *
 *  if( xQueue2 != 0 )
 *  {
 *      // Send a pointer to a struct AMessage object.  Don't block if the
 *      // queue is already full.
 *      pxMessage = & xMessage_core1;
 *      xQueueSendToBack_core1( xQueue2, ( void * ) &pxMessage, ( TickType_t_core1 ) 0 );
 *  }
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueueSend_core1 xQueueSend_core1
 * \ingroup QueueManagement
 */
#define xQueueSendToBack_core1( xQueue_core1, pvItemToQueue_core1, xTicksToWait_core1 ) \
    xQueueGenericSend_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), ( xTicksToWait_core1 ), queueSEND_TO_BACK_core1 )

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueSend_core1(
 *                            QueueHandle_t_core1 xQueue_core1,
 *                            const void * pvItemToQueue_core1,
 *                            TickType_t_core1 xTicksToWait_core1
 *                       );
 * @endcode
 *
 * This is a macro that calls xQueueGenericSend_core1().  It is included for
 * backward compatibility with versions of FreeRTOS_core1.org that did not
 * include the xQueueSendToFront_core1() and xQueueSendToBack_core1() macros.  It is
 * equivalent to xQueueSendToBack_core1().
 *
 * Post an item on a queue.  The item is queued by copy, not by reference.
 * This function must not be called from an interrupt service routine.
 * See xQueueSendFromISR_core1 () for an alternative which may be used in an ISR.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should block
 * waiting for space to become available on the queue, should it already
 * be full.  The call will return immediately if this is set to 0 and the
 * queue is full.  The time is defined in tick periods so the constant
 * portTICK_PERIOD_MS_core1 should be used to convert to real time if this is required.
 *
 * @return pdTRUE_core1 if the item was successfully posted, otherwise errQUEUE_FULL_core1.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * } xMessage_core1;
 *
 * uint32_t ulVar = 10UL;
 *
 * void vATask( void *pvParameters_core1 )
 * {
 * QueueHandle_t_core1 xQueue1, xQueue2;
 * struct AMessage *pxMessage;
 *
 *  // Create a queue capable of containing 10 uint32_t values.
 *  xQueue1 = xQueueCreate_core1( 10, sizeof( uint32_t ) );
 *
 *  // Create a queue capable of containing 10 pointers to AMessage structures.
 *  // These should be passed by pointer as they contain a lot of data.
 *  xQueue2 = xQueueCreate_core1( 10, sizeof( struct AMessage * ) );
 *
 *  // ...
 *
 *  if( xQueue1 != 0 )
 *  {
 *      // Send an uint32_t.  Wait for 10 ticks for space to become
 *      // available if necessary.
 *      if( xQueueSend_core1( xQueue1, ( void * ) &ulVar, ( TickType_t_core1 ) 10 ) != pdPASS_core1 )
 *      {
 *          // Failed to post the message, even after 10 ticks.
 *      }
 *  }
 *
 *  if( xQueue2 != 0 )
 *  {
 *      // Send a pointer to a struct AMessage object.  Don't block if the
 *      // queue is already full.
 *      pxMessage = & xMessage_core1;
 *      xQueueSend_core1( xQueue2, ( void * ) &pxMessage, ( TickType_t_core1 ) 0 );
 *  }
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueueSend_core1 xQueueSend_core1
 * \ingroup QueueManagement
 */
#define xQueueSend_core1( xQueue_core1, pvItemToQueue_core1, xTicksToWait_core1 ) \
    xQueueGenericSend_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), ( xTicksToWait_core1 ), queueSEND_TO_BACK_core1 )

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueOverwrite_core1(
 *                            QueueHandle_t_core1 xQueue_core1,
 *                            const void * pvItemToQueue_core1
 *                       );
 * @endcode
 *
 * Only for use with queues that have a length of one - so the queue is either
 * empty or full.
 *
 * Post an item on a queue.  If the queue is already full then overwrite the
 * value held in the queue.  The item is queued by copy, not by reference.
 *
 * This function must not be called from an interrupt service routine.
 * See xQueueOverwriteFromISR_core1 () for an alternative which may be used in an ISR.
 *
 * @param xQueue_core1 The handle of the queue to which the data is being sent.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @return xQueueOverwrite_core1() is a macro that calls xQueueGenericSend_core1(), and
 * therefore has the same return values as xQueueSendToFront_core1().  However, pdPASS_core1
 * is the only value that can be returned because xQueueOverwrite_core1() will write
 * to the queue even when the queue is already full.
 *
 * Example usage:
 * @code{c}
 *
 * void vFunction_core1( void *pvParameters_core1 )
 * {
 * QueueHandle_t_core1 xQueue_core1;
 * uint32_t ulVarToSend, ulValReceived;
 *
 *  // Create a queue to hold one uint32_t value.  It is strongly
 *  // recommended *not* to use xQueueOverwrite_core1() on queues that can
 *  // contain more than one value, and doing so will trigger an assertion
 *  // if configASSERT_core1() is defined.
 *  xQueue_core1 = xQueueCreate_core1( 1, sizeof( uint32_t ) );
 *
 *  // Write the value 10 to the queue using xQueueOverwrite_core1().
 *  ulVarToSend = 10;
 *  xQueueOverwrite_core1( xQueue_core1, &ulVarToSend );
 *
 *  // Peeking the queue should now return 10, but leave the value 10 in
 *  // the queue.  A block time of zero is used as it is known that the
 *  // queue holds a value.
 *  ulValReceived = 0;
 *  xQueuePeek_core1( xQueue_core1, &ulValReceived, 0 );
 *
 *  if( ulValReceived != 10 )
 *  {
 *      // Error unless the item was removed by a different task_core1.
 *  }
 *
 *  // The queue is still full.  Use xQueueOverwrite_core1() to overwrite the
 *  // value held in the queue with 100.
 *  ulVarToSend = 100;
 *  xQueueOverwrite_core1( xQueue_core1, &ulVarToSend );
 *
 *  // This time read from the queue, leaving the queue empty once more.
 *  // A block time of 0 is used again.
 *  xQueueReceive_core1( xQueue_core1, &ulValReceived, 0 );
 *
 *  // The value read should be the last value written, even though the
 *  // queue was already full when the value was written.
 *  if( ulValReceived != 100 )
 *  {
 *      // Error!
 *  }
 *
 *  // ...
 * }
 * @endcode
 * \defgroup xQueueOverwrite_core1 xQueueOverwrite_core1
 * \ingroup QueueManagement
 */
#define xQueueOverwrite_core1( xQueue_core1, pvItemToQueue_core1 ) \
    xQueueGenericSend_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), 0, queueOVERWRITE_core1 )


/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueGenericSend_core1(
 *                                  QueueHandle_t_core1 xQueue_core1,
 *                                  const void * pvItemToQueue_core1,
 *                                  TickType_t_core1 xTicksToWait_core1
 *                                  BaseType_t_core1 xCopyPosition_core1
 *                              );
 * @endcode
 *
 * It is preferred that the macros xQueueSend_core1(), xQueueSendToFront_core1() and
 * xQueueSendToBack_core1() are used in place of calling this function directly.
 *
 * Post an item on a queue.  The item is queued by copy, not by reference.
 * This function must not be called from an interrupt service routine.
 * See xQueueSendFromISR_core1 () for an alternative which may be used in an ISR.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should block
 * waiting for space to become available on the queue, should it already
 * be full.  The call will return immediately if this is set to 0 and the
 * queue is full.  The time is defined in tick periods so the constant
 * portTICK_PERIOD_MS_core1 should be used to convert to real time if this is required.
 *
 * @param xCopyPosition_core1 Can take the value queueSEND_TO_BACK_core1 to place the
 * item at the back of the queue, or queueSEND_TO_FRONT_core1 to place the item
 * at the front of the queue (for high priority messages).
 *
 * @return pdTRUE_core1 if the item was successfully posted, otherwise errQUEUE_FULL_core1.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * } xMessage_core1;
 *
 * uint32_t ulVar = 10UL;
 *
 * void vATask( void *pvParameters_core1 )
 * {
 * QueueHandle_t_core1 xQueue1, xQueue2;
 * struct AMessage *pxMessage;
 *
 *  // Create a queue capable of containing 10 uint32_t values.
 *  xQueue1 = xQueueCreate_core1( 10, sizeof( uint32_t ) );
 *
 *  // Create a queue capable of containing 10 pointers to AMessage structures.
 *  // These should be passed by pointer as they contain a lot of data.
 *  xQueue2 = xQueueCreate_core1( 10, sizeof( struct AMessage * ) );
 *
 *  // ...
 *
 *  if( xQueue1 != 0 )
 *  {
 *      // Send an uint32_t.  Wait for 10 ticks for space to become
 *      // available if necessary.
 *      if( xQueueGenericSend_core1( xQueue1, ( void * ) &ulVar, ( TickType_t_core1 ) 10, queueSEND_TO_BACK_core1 ) != pdPASS_core1 )
 *      {
 *          // Failed to post the message, even after 10 ticks.
 *      }
 *  }
 *
 *  if( xQueue2 != 0 )
 *  {
 *      // Send a pointer to a struct AMessage object.  Don't block if the
 *      // queue is already full.
 *      pxMessage = & xMessage_core1;
 *      xQueueGenericSend_core1( xQueue2, ( void * ) &pxMessage, ( TickType_t_core1 ) 0, queueSEND_TO_BACK_core1 );
 *  }
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueueSend_core1 xQueueSend_core1
 * \ingroup QueueManagement
 */
BaseType_t_core1 xQueueGenericSend_core1( QueueHandle_t_core1 xQueue_core1,
                              const void * const pvItemToQueue_core1,
                              TickType_t_core1 xTicksToWait_core1,
                              const BaseType_t_core1 xCopyPosition_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueuePeek_core1(
 *                           QueueHandle_t_core1 xQueue_core1,
 *                           void * const pvBuffer_core1,
 *                           TickType_t_core1 xTicksToWait_core1
 *                       );
 * @endcode
 *
 * Receive an item from a queue without removing the item from the queue.
 * The item is received by copy so a buffer of adequate size must be
 * provided.  The number of bytes copied into the buffer was defined when
 * the queue was created.
 *
 * Successfully received items remain on the queue so will be returned again
 * by the next call, or a call to xQueueReceive_core1().
 *
 * This macro must not be used in an interrupt service routine.  See
 * xQueuePeekFromISR_core1() for an alternative that can be called from an interrupt
 * service routine.
 *
 * @param xQueue_core1 The handle to the queue from which the item is to be
 * received.
 *
 * @param pvBuffer_core1 Pointer to the buffer into which the received item will
 * be copied.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should block
 * waiting for an item to receive should the queue be empty at the time
 * of the call. The time is defined in tick periods so the constant
 * portTICK_PERIOD_MS_core1 should be used to convert to real time if this is required.
 * xQueuePeek_core1() will return immediately if xTicksToWait_core1 is 0 and the queue
 * is empty.
 *
 * @return pdTRUE_core1 if an item was successfully received from the queue,
 * otherwise pdFALSE_core1.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * } xMessage_core1;
 *
 * QueueHandle_t_core1 xQueue_core1;
 *
 * // Task to create a queue and post a value.
 * void vATask( void *pvParameters_core1 )
 * {
 * struct AMessage *pxMessage;
 *
 *  // Create a queue capable of containing 10 pointers to AMessage structures.
 *  // These should be passed by pointer as they contain a lot of data.
 *  xQueue_core1 = xQueueCreate_core1( 10, sizeof( struct AMessage * ) );
 *  if( xQueue_core1 == 0 )
 *  {
 *      // Failed to create the queue.
 *  }
 *
 *  // ...
 *
 *  // Send a pointer to a struct AMessage object.  Don't block if the
 *  // queue is already full.
 *  pxMessage = & xMessage_core1;
 *  xQueueSend_core1( xQueue_core1, ( void * ) &pxMessage, ( TickType_t_core1 ) 0 );
 *
 *  // ... Rest of task_core1 code.
 * }
 *
 * // Task to peek the data from the queue.
 * void vADifferentTask( void *pvParameters_core1 )
 * {
 * struct AMessage *pxRxedMessage;
 *
 *  if( xQueue_core1 != 0 )
 *  {
 *      // Peek a message on the created queue.  Block for 10 ticks if a
 *      // message is not immediately available.
 *      if( xQueuePeek_core1( xQueue_core1, &( pxRxedMessage ), ( TickType_t_core1 ) 10 ) )
 *      {
 *          // pcRxedMessage now points to the struct AMessage variable posted
 *          // by vATask, but the item still remains on the queue.
 *      }
 *  }
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueuePeek_core1 xQueuePeek_core1
 * \ingroup QueueManagement
 */
BaseType_t_core1 xQueuePeek_core1( QueueHandle_t_core1 xQueue_core1,
                       void * const pvBuffer_core1,
                       TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueuePeekFromISR_core1(
 *                                  QueueHandle_t_core1 xQueue_core1,
 *                                  void *pvBuffer_core1,
 *                              );
 * @endcode
 *
 * A version of xQueuePeek_core1() that can be called from an interrupt service
 * routine (ISR).
 *
 * Receive an item from a queue without removing the item from the queue.
 * The item is received by copy so a buffer of adequate size must be
 * provided.  The number of bytes copied into the buffer was defined when
 * the queue was created.
 *
 * Successfully received items remain on the queue so will be returned again
 * by the next call, or a call to xQueueReceive_core1().
 *
 * @param xQueue_core1 The handle to the queue from which the item is to be
 * received.
 *
 * @param pvBuffer_core1 Pointer to the buffer into which the received item will
 * be copied.
 *
 * @return pdTRUE_core1 if an item was successfully received from the queue,
 * otherwise pdFALSE_core1.
 *
 * \defgroup xQueuePeekFromISR_core1 xQueuePeekFromISR_core1
 * \ingroup QueueManagement
 */
BaseType_t_core1 xQueuePeekFromISR_core1( QueueHandle_t_core1 xQueue_core1,
                              void * const pvBuffer_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueReceive_core1(
 *                               QueueHandle_t_core1 xQueue_core1,
 *                               void *pvBuffer_core1,
 *                               TickType_t_core1 xTicksToWait_core1
 *                          );
 * @endcode
 *
 * Receive an item from a queue.  The item is received by copy so a buffer of
 * adequate size must be provided.  The number of bytes copied into the buffer
 * was defined when the queue was created.
 *
 * Successfully received items are removed from the queue.
 *
 * This function must not be used in an interrupt service routine.  See
 * xQueueReceiveFromISR_core1 for an alternative that can.
 *
 * @param xQueue_core1 The handle to the queue from which the item is to be
 * received.
 *
 * @param pvBuffer_core1 Pointer to the buffer into which the received item will
 * be copied.
 *
 * @param xTicksToWait_core1 The maximum amount of time the task_core1 should block
 * waiting for an item to receive should the queue be empty at the time
 * of the call. xQueueReceive_core1() will return immediately if xTicksToWait_core1
 * is zero and the queue is empty.  The time is defined in tick periods so the
 * constant portTICK_PERIOD_MS_core1 should be used to convert to real time if this is
 * required.
 *
 * @return pdTRUE_core1 if an item was successfully received from the queue,
 * otherwise pdFALSE_core1.
 *
 * Example usage:
 * @code{c}
 * struct AMessage
 * {
 *  char ucMessageID;
 *  char ucData[ 20 ];
 * } xMessage_core1;
 *
 * QueueHandle_t_core1 xQueue_core1;
 *
 * // Task to create a queue and post a value.
 * void vATask( void *pvParameters_core1 )
 * {
 * struct AMessage *pxMessage;
 *
 *  // Create a queue capable of containing 10 pointers to AMessage structures.
 *  // These should be passed by pointer as they contain a lot of data.
 *  xQueue_core1 = xQueueCreate_core1( 10, sizeof( struct AMessage * ) );
 *  if( xQueue_core1 == 0 )
 *  {
 *      // Failed to create the queue.
 *  }
 *
 *  // ...
 *
 *  // Send a pointer to a struct AMessage object.  Don't block if the
 *  // queue is already full.
 *  pxMessage = & xMessage_core1;
 *  xQueueSend_core1( xQueue_core1, ( void * ) &pxMessage, ( TickType_t_core1 ) 0 );
 *
 *  // ... Rest of task_core1 code.
 * }
 *
 * // Task to receive from the queue.
 * void vADifferentTask( void *pvParameters_core1 )
 * {
 * struct AMessage *pxRxedMessage;
 *
 *  if( xQueue_core1 != 0 )
 *  {
 *      // Receive a message on the created queue.  Block for 10 ticks if a
 *      // message is not immediately available.
 *      if( xQueueReceive_core1( xQueue_core1, &( pxRxedMessage ), ( TickType_t_core1 ) 10 ) )
 *      {
 *          // pcRxedMessage now points to the struct AMessage variable posted
 *          // by vATask.
 *      }
 *  }
 *
 *  // ... Rest of task_core1 code.
 * }
 * @endcode
 * \defgroup xQueueReceive_core1 xQueueReceive_core1
 * \ingroup QueueManagement
 */
BaseType_t_core1 xQueueReceive_core1( QueueHandle_t_core1 xQueue_core1,
                          void * const pvBuffer_core1,
                          TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * UBaseType_t_core1 uxQueueMessagesWaiting_core1( const QueueHandle_t_core1 xQueue_core1 );
 * @endcode
 *
 * Return the number of messages stored in a queue.
 *
 * @param xQueue_core1 A handle to the queue being queried.
 *
 * @return The number of messages available in the queue.
 *
 * \defgroup uxQueueMessagesWaiting_core1 uxQueueMessagesWaiting_core1
 * \ingroup QueueManagement
 */
UBaseType_t_core1 uxQueueMessagesWaiting_core1( const QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * UBaseType_t_core1 uxQueueSpacesAvailable_core1( const QueueHandle_t_core1 xQueue_core1 );
 * @endcode
 *
 * Return the number of free spaces available in a queue.  This is equal to the
 * number of items that can be sent to the queue before the queue becomes full
 * if no items are removed.
 *
 * @param xQueue_core1 A handle to the queue being queried.
 *
 * @return The number of spaces available in the queue.
 *
 * \defgroup uxQueueMessagesWaiting_core1 uxQueueMessagesWaiting_core1
 * \ingroup QueueManagement
 */
UBaseType_t_core1 uxQueueSpacesAvailable_core1( const QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * void vQueueDelete_core1( QueueHandle_t_core1 xQueue_core1 );
 * @endcode
 *
 * Delete a queue - freeing all the memory allocated for storing of items
 * placed on the queue.
 *
 * @param xQueue_core1 A handle to the queue to be deleted.
 *
 * \defgroup vQueueDelete_core1 vQueueDelete_core1
 * \ingroup QueueManagement
 */
void vQueueDelete_core1( QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueSendToFrontFromISR_core1(
 *                                       QueueHandle_t_core1 xQueue_core1,
 *                                       const void *pvItemToQueue_core1,
 *                                       BaseType_t_core1 *pxHigherPriorityTaskWoken_core1
 *                                    );
 * @endcode
 *
 * This is a macro that calls xQueueGenericSendFromISR_core1().
 *
 * Post an item to the front of a queue.  It is safe to use this macro from
 * within an interrupt service routine.
 *
 * Items are queued by copy not reference so it is preferable to only
 * queue small items, especially when called from an ISR.  In most cases
 * it would be preferable to store a pointer to the item being queued.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param pxHigherPriorityTaskWoken_core1 xQueueSendToFrontFromISR_core1() will set
 * *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1 if sending to the queue caused a task_core1
 * to unblock, and the unblocked task_core1 has a priority higher than the currently
 * running task_core1.  If xQueueSendToFromFromISR() sets this value to pdTRUE_core1 then
 * a context switch should be requested before the interrupt is exited.
 *
 * @return pdTRUE_core1 if the data was successfully sent to the queue, otherwise
 * errQUEUE_FULL_core1.
 *
 * Example usage for buffered IO (where the ISR can obtain more than one value
 * per call):
 * @code{c}
 * void vBufferISR( void )
 * {
 * char cIn;
 * BaseType_t_core1 xHigherPriorityTaskWoken_core1;
 *
 *  // We have not woken a task_core1 at the start of the ISR.
 *  xHigherPriorityTaskWoken_core1 = pdFALSE_core1;
 *
 *  // Loop until the buffer is empty.
 *  do
 *  {
 *      // Obtain a byte from the buffer.
 *      cIn = portINPUT_BYTE( RX_REGISTER_ADDRESS );
 *
 *      // Post the byte.
 *      xQueueSendToFrontFromISR_core1( xRxQueue, &cIn, &xHigherPriorityTaskWoken_core1 );
 *
 *  } while( portINPUT_BYTE( BUFFER_COUNT ) );
 *
 *  // Now the buffer is empty we can switch context if necessary.
 *  if( xHigherPriorityTaskWoken_core1 )
 *  {
 *      taskYIELD ();
 *  }
 * }
 * @endcode
 *
 * \defgroup xQueueSendFromISR_core1 xQueueSendFromISR_core1
 * \ingroup QueueManagement
 */
#define xQueueSendToFrontFromISR_core1( xQueue_core1, pvItemToQueue_core1, pxHigherPriorityTaskWoken_core1 ) \
    xQueueGenericSendFromISR_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), ( pxHigherPriorityTaskWoken_core1 ), queueSEND_TO_FRONT_core1 )


/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueSendToBackFromISR_core1(
 *                                       QueueHandle_t_core1 xQueue_core1,
 *                                       const void *pvItemToQueue_core1,
 *                                       BaseType_t_core1 *pxHigherPriorityTaskWoken_core1
 *                                    );
 * @endcode
 *
 * This is a macro that calls xQueueGenericSendFromISR_core1().
 *
 * Post an item to the back of a queue.  It is safe to use this macro from
 * within an interrupt service routine.
 *
 * Items are queued by copy not reference so it is preferable to only
 * queue small items, especially when called from an ISR.  In most cases
 * it would be preferable to store a pointer to the item being queued.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param pxHigherPriorityTaskWoken_core1 xQueueSendToBackFromISR_core1() will set
 * *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1 if sending to the queue caused a task_core1
 * to unblock, and the unblocked task_core1 has a priority higher than the currently
 * running task_core1.  If xQueueSendToBackFromISR_core1() sets this value to pdTRUE_core1 then
 * a context switch should be requested before the interrupt is exited.
 *
 * @return pdTRUE_core1 if the data was successfully sent to the queue, otherwise
 * errQUEUE_FULL_core1.
 *
 * Example usage for buffered IO (where the ISR can obtain more than one value
 * per call):
 * @code{c}
 * void vBufferISR( void )
 * {
 * char cIn;
 * BaseType_t_core1 xHigherPriorityTaskWoken_core1;
 *
 *  // We have not woken a task_core1 at the start of the ISR.
 *  xHigherPriorityTaskWoken_core1 = pdFALSE_core1;
 *
 *  // Loop until the buffer is empty.
 *  do
 *  {
 *      // Obtain a byte from the buffer.
 *      cIn = portINPUT_BYTE( RX_REGISTER_ADDRESS );
 *
 *      // Post the byte.
 *      xQueueSendToBackFromISR_core1( xRxQueue, &cIn, &xHigherPriorityTaskWoken_core1 );
 *
 *  } while( portINPUT_BYTE( BUFFER_COUNT ) );
 *
 *  // Now the buffer is empty we can switch context if necessary.
 *  if( xHigherPriorityTaskWoken_core1 )
 *  {
 *      taskYIELD ();
 *  }
 * }
 * @endcode
 *
 * \defgroup xQueueSendFromISR_core1 xQueueSendFromISR_core1
 * \ingroup QueueManagement
 */
#define xQueueSendToBackFromISR_core1( xQueue_core1, pvItemToQueue_core1, pxHigherPriorityTaskWoken_core1 ) \
    xQueueGenericSendFromISR_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), ( pxHigherPriorityTaskWoken_core1 ), queueSEND_TO_BACK_core1 )

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueOverwriteFromISR_core1(
 *                            QueueHandle_t_core1 xQueue_core1,
 *                            const void * pvItemToQueue_core1,
 *                            BaseType_t_core1 *pxHigherPriorityTaskWoken_core1
 *                       );
 * @endcode
 *
 * A version of xQueueOverwrite_core1() that can be used in an interrupt service
 * routine (ISR).
 *
 * Only for use with queues that can hold a single item - so the queue is either
 * empty or full.
 *
 * Post an item on a queue.  If the queue is already full then overwrite the
 * value held in the queue.  The item is queued by copy, not by reference.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param pxHigherPriorityTaskWoken_core1 xQueueOverwriteFromISR_core1() will set
 * *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1 if sending to the queue caused a task_core1
 * to unblock, and the unblocked task_core1 has a priority higher than the currently
 * running task_core1.  If xQueueOverwriteFromISR_core1() sets this value to pdTRUE_core1 then
 * a context switch should be requested before the interrupt is exited.
 *
 * @return xQueueOverwriteFromISR_core1() is a macro that calls
 * xQueueGenericSendFromISR_core1(), and therefore has the same return values as
 * xQueueSendToFrontFromISR_core1().  However, pdPASS_core1 is the only value that can be
 * returned because xQueueOverwriteFromISR_core1() will write to the queue even when
 * the queue is already full.
 *
 * Example usage:
 * @code{c}
 *
 * QueueHandle_t_core1 xQueue_core1;
 *
 * void vFunction_core1( void *pvParameters_core1 )
 * {
 *  // Create a queue to hold one uint32_t value.  It is strongly
 *  // recommended *not* to use xQueueOverwriteFromISR_core1() on queues that can
 *  // contain more than one value, and doing so will trigger an assertion
 *  // if configASSERT_core1() is defined.
 *  xQueue_core1 = xQueueCreate_core1( 1, sizeof( uint32_t ) );
 * }
 *
 * void vAnInterruptHandler( void )
 * {
 * // xHigherPriorityTaskWoken_core1 must be set to pdFALSE_core1 before it is used.
 * BaseType_t_core1 xHigherPriorityTaskWoken_core1 = pdFALSE_core1;
 * uint32_t ulVarToSend, ulValReceived;
 *
 *  // Write the value 10 to the queue using xQueueOverwriteFromISR_core1().
 *  ulVarToSend = 10;
 *  xQueueOverwriteFromISR_core1( xQueue_core1, &ulVarToSend, &xHigherPriorityTaskWoken_core1 );
 *
 *  // The queue is full, but calling xQueueOverwriteFromISR_core1() again will still
 *  // pass because the value held in the queue will be overwritten with the
 *  // new value.
 *  ulVarToSend = 100;
 *  xQueueOverwriteFromISR_core1( xQueue_core1, &ulVarToSend, &xHigherPriorityTaskWoken_core1 );
 *
 *  // Reading from the queue will now return 100.
 *
 *  // ...
 *
 *  if( xHigherPrioritytaskWoken == pdTRUE_core1 )
 *  {
 *      // Writing to the queue caused a task_core1 to unblock and the unblocked task_core1
 *      // has a priority higher than or equal to the priority of the currently
 *      // executing task_core1 (the task_core1 this interrupt interrupted).  Perform a context
 *      // switch so this interrupt returns directly to the unblocked task_core1.
 *      portYIELD_FROM_ISR_core1(); // or portEND_SWITCHING_ISR() depending on the port.
 *  }
 * }
 * @endcode
 * \defgroup xQueueOverwriteFromISR_core1 xQueueOverwriteFromISR_core1
 * \ingroup QueueManagement
 */
#define xQueueOverwriteFromISR_core1( xQueue_core1, pvItemToQueue_core1, pxHigherPriorityTaskWoken_core1 ) \
    xQueueGenericSendFromISR_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), ( pxHigherPriorityTaskWoken_core1 ), queueOVERWRITE_core1 )

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueSendFromISR_core1(
 *                                   QueueHandle_t_core1 xQueue_core1,
 *                                   const void *pvItemToQueue_core1,
 *                                   BaseType_t_core1 *pxHigherPriorityTaskWoken_core1
 *                              );
 * @endcode
 *
 * This is a macro that calls xQueueGenericSendFromISR_core1().  It is included
 * for backward compatibility with versions of FreeRTOS_core1.org that did not
 * include the xQueueSendToBackFromISR_core1() and xQueueSendToFrontFromISR_core1()
 * macros.
 *
 * Post an item to the back of a queue.  It is safe to use this function from
 * within an interrupt service routine.
 *
 * Items are queued by copy not reference so it is preferable to only
 * queue small items, especially when called from an ISR.  In most cases
 * it would be preferable to store a pointer to the item being queued.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param pxHigherPriorityTaskWoken_core1 xQueueSendFromISR_core1() will set
 * *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1 if sending to the queue caused a task_core1
 * to unblock, and the unblocked task_core1 has a priority higher than the currently
 * running task_core1.  If xQueueSendFromISR_core1() sets this value to pdTRUE_core1 then
 * a context switch should be requested before the interrupt is exited.
 *
 * @return pdTRUE_core1 if the data was successfully sent to the queue, otherwise
 * errQUEUE_FULL_core1.
 *
 * Example usage for buffered IO (where the ISR can obtain more than one value
 * per call):
 * @code{c}
 * void vBufferISR( void )
 * {
 * char cIn;
 * BaseType_t_core1 xHigherPriorityTaskWoken_core1;
 *
 *  // We have not woken a task_core1 at the start of the ISR.
 *  xHigherPriorityTaskWoken_core1 = pdFALSE_core1;
 *
 *  // Loop until the buffer is empty.
 *  do
 *  {
 *      // Obtain a byte from the buffer.
 *      cIn = portINPUT_BYTE( RX_REGISTER_ADDRESS );
 *
 *      // Post the byte.
 *      xQueueSendFromISR_core1( xRxQueue, &cIn, &xHigherPriorityTaskWoken_core1 );
 *
 *  } while( portINPUT_BYTE( BUFFER_COUNT ) );
 *
 *  // Now the buffer is empty we can switch context if necessary.
 *  if( xHigherPriorityTaskWoken_core1 )
 *  {
 *      // Actual macro used here is port specific.
 *      portYIELD_FROM_ISR_core1 ();
 *  }
 * }
 * @endcode
 *
 * \defgroup xQueueSendFromISR_core1 xQueueSendFromISR_core1
 * \ingroup QueueManagement
 */
#define xQueueSendFromISR_core1( xQueue_core1, pvItemToQueue_core1, pxHigherPriorityTaskWoken_core1 ) \
    xQueueGenericSendFromISR_core1( ( xQueue_core1 ), ( pvItemToQueue_core1 ), ( pxHigherPriorityTaskWoken_core1 ), queueSEND_TO_BACK_core1 )

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueGenericSendFromISR_core1(
 *                                         QueueHandle_t_core1    xQueue_core1,
 *                                         const    void    *pvItemToQueue_core1,
 *                                         BaseType_t_core1  *pxHigherPriorityTaskWoken_core1,
 *                                         BaseType_t_core1  xCopyPosition_core1
 *                                     );
 * @endcode
 *
 * It is preferred that the macros xQueueSendFromISR_core1(),
 * xQueueSendToFrontFromISR_core1() and xQueueSendToBackFromISR_core1() be used in place
 * of calling this function directly.  xQueueGiveFromISR() is an
 * equivalent for use by semaphores that don't actually copy any data.
 *
 * Post an item on a queue.  It is safe to use this function from within an
 * interrupt service routine.
 *
 * Items are queued by copy not reference so it is preferable to only
 * queue small items, especially when called from an ISR.  In most cases
 * it would be preferable to store a pointer to the item being queued.
 *
 * @param xQueue_core1 The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core1 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core1
 * into the queue storage area.
 *
 * @param pxHigherPriorityTaskWoken_core1 xQueueGenericSendFromISR_core1() will set
 * *pxHigherPriorityTaskWoken_core1 to pdTRUE_core1 if sending to the queue caused a task_core1
 * to unblock, and the unblocked task_core1 has a priority higher than the currently
 * running task_core1.  If xQueueGenericSendFromISR_core1() sets this value to pdTRUE_core1 then
 * a context switch should be requested before the interrupt is exited.
 *
 * @param xCopyPosition_core1 Can take the value queueSEND_TO_BACK_core1 to place the
 * item at the back of the queue, or queueSEND_TO_FRONT_core1 to place the item
 * at the front of the queue (for high priority messages).
 *
 * @return pdTRUE_core1 if the data was successfully sent to the queue, otherwise
 * errQUEUE_FULL_core1.
 *
 * Example usage for buffered IO (where the ISR can obtain more than one value
 * per call):
 * @code{c}
 * void vBufferISR( void )
 * {
 * char cIn;
 * BaseType_t_core1 xHigherPriorityTaskWokenByPost;
 *
 *  // We have not woken a task_core1 at the start of the ISR.
 *  xHigherPriorityTaskWokenByPost = pdFALSE_core1;
 *
 *  // Loop until the buffer is empty.
 *  do
 *  {
 *      // Obtain a byte from the buffer.
 *      cIn = portINPUT_BYTE( RX_REGISTER_ADDRESS );
 *
 *      // Post each byte.
 *      xQueueGenericSendFromISR_core1( xRxQueue, &cIn, &xHigherPriorityTaskWokenByPost, queueSEND_TO_BACK_core1 );
 *
 *  } while( portINPUT_BYTE( BUFFER_COUNT ) );
 *
 *  // Now the buffer is empty we can switch context if necessary.  Note that the
 *  // name of the yield function required is port specific.
 *  if( xHigherPriorityTaskWokenByPost )
 *  {
 *      portYIELD_FROM_ISR_core1();
 *  }
 * }
 * @endcode
 *
 * \defgroup xQueueSendFromISR_core1 xQueueSendFromISR_core1
 * \ingroup QueueManagement
 */
BaseType_t_core1 xQueueGenericSendFromISR_core1( QueueHandle_t_core1 xQueue_core1,
                                     const void * const pvItemToQueue_core1,
                                     BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1,
                                     const BaseType_t_core1 xCopyPosition_core1 ) PRIVILEGED_FUNCTION_core1;
BaseType_t_core1 xQueueGiveFromISR( QueueHandle_t_core1 xQueue_core1,
                              BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;

/**
 * queue. h
 * @code{c}
 * BaseType_t_core1 xQueueReceiveFromISR_core1(
 *                                     QueueHandle_t_core1    xQueue_core1,
 *                                     void             *pvBuffer_core1,
 *                                     BaseType_t_core1       *pxTaskWoken
 *                                 );
 * @endcode
 *
 * Receive an item from a queue.  It is safe to use this function from within an
 * interrupt service routine.
 *
 * @param xQueue_core1 The handle to the queue from which the item is to be
 * received.
 *
 * @param pvBuffer_core1 Pointer to the buffer into which the received item will
 * be copied.
 *
 * @param pxTaskWoken A task_core1 may be blocked waiting for space to become
 * available on the queue.  If xQueueReceiveFromISR_core1 causes such a task_core1 to
 * unblock *pxTaskWoken will get set to pdTRUE_core1, otherwise *pxTaskWoken will
 * remain unchanged.
 *
 * @return pdTRUE_core1 if an item was successfully received from the queue,
 * otherwise pdFALSE_core1.
 *
 * Example usage:
 * @code{c}
 *
 * QueueHandle_t_core1 xQueue_core1;
 *
 * // Function to create a queue and post some values.
 * void vAFunction( void *pvParameters_core1 )
 * {
 * char cValueToPost;
 * const TickType_t_core1 xTicksToWait_core1 = ( TickType_t_core1 )0xff;
 *
 *  // Create a queue capable of containing 10 characters.
 *  xQueue_core1 = xQueueCreate_core1( 10, sizeof( char ) );
 *  if( xQueue_core1 == 0 )
 *  {
 *      // Failed to create the queue.
 *  }
 *
 *  // ...
 *
 *  // Post some characters that will be used within an ISR.  If the queue
 *  // is full then this task_core1 will block for xTicksToWait_core1 ticks.
 *  cValueToPost = 'a';
 *  xQueueSend_core1( xQueue_core1, ( void * ) &cValueToPost, xTicksToWait_core1 );
 *  cValueToPost = 'b';
 *  xQueueSend_core1( xQueue_core1, ( void * ) &cValueToPost, xTicksToWait_core1 );
 *
 *  // ... keep posting characters ... this task_core1 may block when the queue
 *  // becomes full.
 *
 *  cValueToPost = 'c';
 *  xQueueSend_core1( xQueue_core1, ( void * ) &cValueToPost, xTicksToWait_core1 );
 * }
 *
 * // ISR that outputs all the characters received on the queue.
 * void vISR_Routine( void )
 * {
 * BaseType_t_core1 xTaskWokenByReceive = pdFALSE_core1;
 * char cRxedChar;
 *
 *  while( xQueueReceiveFromISR_core1( xQueue_core1, ( void * ) &cRxedChar, &xTaskWokenByReceive) )
 *  {
 *      // A character was received.  Output the character now.
 *      vOutputCharacter( cRxedChar );
 *
 *      // If removing the character from the queue woke the task_core1 that was
 *      // posting onto the queue xTaskWokenByReceive will have been set to
 *      // pdTRUE_core1.  No matter how many times this loop iterates only one
 *      // task_core1 will be woken.
 *  }
 *
 *  if( xTaskWokenByReceive != ( char ) pdFALSE_core1;
 *  {
 *      taskYIELD ();
 *  }
 * }
 * @endcode
 * \defgroup xQueueReceiveFromISR_core1 xQueueReceiveFromISR_core1
 * \ingroup QueueManagement
 */
BaseType_t_core1 xQueueReceiveFromISR_core1( QueueHandle_t_core1 xQueue_core1,
                                 void * const pvBuffer_core1,
                                 BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Utilities to query queues that are safe to use from an ISR.  These utilities
 * should be used only from within an ISR, or within a critical section.
 */
BaseType_t_core1 xQueueIsQueueEmptyFromISR_core1( const QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;
BaseType_t_core1 xQueueIsQueueFullFromISR_core1( const QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;
UBaseType_t_core1 uxQueueMessagesWaitingFromISR_core1( const QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * The functions defined above are for passing data to and from tasks.  The
 * functions below are the equivalents for passing data to and from
 * co-routines.
 *
 * These functions are called from the co-routine macro implementation and
 * should not be called directly from application code.  Instead use the macro
 * wrappers defined within croutine.h.
 */
BaseType_t_core1 xQueueCRSendFromISR_core1( QueueHandle_t_core1 xQueue_core1,
                                const void * pvItemToQueue_core1,
                                BaseType_t_core1 xCoRoutinePreviouslyWoken_core1 );
BaseType_t_core1 xQueueCRReceiveFromISR_core1( QueueHandle_t_core1 xQueue_core1,
                                   void * pvBuffer_core1,
                                   BaseType_t_core1 * pxTaskWoken );
BaseType_t_core1 xQueueCRSend_core1( QueueHandle_t_core1 xQueue_core1,
                         const void * pvItemToQueue_core1,
                         TickType_t_core1 xTicksToWait_core1 );
BaseType_t_core1 xQueueCRReceive_core1( QueueHandle_t_core1 xQueue_core1,
                            void * pvBuffer_core1,
                            TickType_t_core1 xTicksToWait_core1 );

/*
 * For internal use only.  Use xSemaphoreCreateMutex(),
 * xSemaphoreCreateCounting() or xSemaphoreGetMutexHolder() instead of calling
 * these functions directly.
 */
QueueHandle_t_core1 xQueueCreateMutex_core1( const uint8_t ucQueueType_core1 ) PRIVILEGED_FUNCTION_core1;
QueueHandle_t_core1 xQueueCreateMutexStatic_core1( const uint8_t ucQueueType_core1,
                                       StaticQueue_t_core1 * pxStaticQueue_core1 ) PRIVILEGED_FUNCTION_core1;
QueueHandle_t_core1 xQueueCreateCountingSemaphore_core1( const UBaseType_t_core1 uxMaxCount_core1,
                                             const UBaseType_t_core1 uxInitialCount_core1 ) PRIVILEGED_FUNCTION_core1;
QueueHandle_t_core1 xQueueCreateCountingSemaphoreStatic_core1( const UBaseType_t_core1 uxMaxCount_core1,
                                                   const UBaseType_t_core1 uxInitialCount_core1,
                                                   StaticQueue_t_core1 * pxStaticQueue_core1 ) PRIVILEGED_FUNCTION_core1;
BaseType_t_core1 xQueueSemaphoreTake_core1( QueueHandle_t_core1 xQueue_core1,
                                TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;
TaskHandle_t_core1 xQueueGetMutexHolder_core1( QueueHandle_t_core1 xSemaphore_core1 ) PRIVILEGED_FUNCTION_core1;
TaskHandle_t_core1 xQueueGetMutexHolderFromISR_core1( QueueHandle_t_core1 xSemaphore_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * For internal use only.  Use xSemaphoreTakeMutexRecursive() or
 * xSemaphoreGiveMutexRecursive() instead of calling these functions directly.
 */
BaseType_t_core1 xQueueTakeMutexRecursive_core1( QueueHandle_t_core1 xMutex_core1,
                                     TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;
BaseType_t_core1 xQueueGiveMutexRecursive_core1( QueueHandle_t_core1 xMutex_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Reset a queue back to its original empty state.  The return value is now
 * obsolete and is always set to pdPASS_core1.
 */
#define xQueueReset_core1( xQueue_core1 )    xQueueGenericReset_core1( ( xQueue_core1 ), pdFALSE_core1 )

/*
 * The registry is provided as a means for kernel aware debuggers to
 * locate queues, semaphores and mutexes.  Call vQueueAddToRegistry_core1() add
 * a queue, semaphore or mutex handle to the registry if you want the handle
 * to be available to a kernel aware debugger.  If you are not using a kernel
 * aware debugger then this function can be ignored.
 *
 * configQUEUE_REGISTRY_SIZE_core1 defines the maximum number of handles the
 * registry can hold.  configQUEUE_REGISTRY_SIZE_core1 must be greater than 0
 * within FreeRTOSConfig.h for the registry to be available.  Its value
 * does not affect the number of queues, semaphores and mutexes that can be
 * created - just the number that the registry can hold.
 *
 * If vQueueAddToRegistry_core1 is called more than once with the same xQueue_core1
 * parameter, the registry will store the pcQueueName_core1 parameter from the
 * most recent call to vQueueAddToRegistry_core1.
 *
 * @param xQueue_core1 The handle of the queue being added to the registry.  This
 * is the handle returned by a call to xQueueCreate_core1().  Semaphore and mutex
 * handles can also be passed in here.
 *
 * @param pcQueueName_core1 The name to be associated with the handle.  This is the
 * name that the kernel aware debugger will display.  The queue registry only
 * stores a pointer to the string - so the string must be persistent (global or
 * preferably in ROM/Flash), not on the stack.
 */
#if ( configQUEUE_REGISTRY_SIZE_core1 > 0 )
    void vQueueAddToRegistry_core1( QueueHandle_t_core1 xQueue_core1,
                              const char * pcQueueName_core1 ) PRIVILEGED_FUNCTION_core1; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
#endif

/*
 * The registry is provided as a means for kernel aware debuggers to
 * locate queues, semaphores and mutexes.  Call vQueueAddToRegistry_core1() add
 * a queue, semaphore or mutex handle to the registry if you want the handle
 * to be available to a kernel aware debugger, and vQueueUnregisterQueue_core1() to
 * remove the queue, semaphore or mutex from the register.  If you are not using
 * a kernel aware debugger then this function can be ignored.
 *
 * @param xQueue_core1 The handle of the queue being removed from the registry.
 */
#if ( configQUEUE_REGISTRY_SIZE_core1 > 0 )
    void vQueueUnregisterQueue_core1( QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/*
 * The queue registry is provided as a means for kernel aware debuggers to
 * locate queues, semaphores and mutexes.  Call pcQueueGetName_core1() to look
 * up and return the name of a queue in the queue registry from the queue's
 * handle.
 *
 * @param xQueue_core1 The handle of the queue the name of which will be returned.
 * @return If the queue is in the registry then a pointer to the name of the
 * queue is returned.  If the queue is not in the registry then NULL is
 * returned.
 */
#if ( configQUEUE_REGISTRY_SIZE_core1 > 0 )
    const char * pcQueueGetName_core1( QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1; /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
#endif

/*
 * Generic version of the function used to create a queue using dynamic memory
 * allocation.  This is called by other functions and macros that create other
 * RTOS objects that use the queue structure as their base.
 */
#if ( configSUPPORT_DYNAMIC_ALLOCATION_core1 == 1 )
    QueueHandle_t_core1 xQueueGenericCreate_core1( const UBaseType_t_core1 uxQueueLength_core1,
                                       const UBaseType_t_core1 uxItemSize_core1,
                                       const uint8_t ucQueueType_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/*
 * Generic version of the function used to create a queue using dynamic memory
 * allocation.  This is called by other functions and macros that create other
 * RTOS objects that use the queue structure as their base.
 */
#if ( configSUPPORT_STATIC_ALLOCATION_core1 == 1 )
    QueueHandle_t_core1 xQueueGenericCreateStatic_core1( const UBaseType_t_core1 uxQueueLength_core1,
                                             const UBaseType_t_core1 uxItemSize_core1,
                                             uint8_t * pucQueueStorage_core1,
                                             StaticQueue_t_core1 * pxStaticQueue_core1,
                                             const uint8_t ucQueueType_core1 ) PRIVILEGED_FUNCTION_core1;
#endif

/*
 * Queue sets provide a mechanism to allow a task_core1 to block (pend) on a read
 * operation from multiple queues or semaphores simultaneously.
 *
 * See FreeRTOS_core1/Source/Demo/Common/Minimal/QueueSet.c for an example using this
 * function.
 *
 * A queue set must be explicitly created using a call to xQueueCreateSet_core1()
 * before it can be used.  Once created, standard FreeRTOS_core1 queues and semaphores
 * can be added to the set using calls to xQueueAddToSet_core1().
 * xQueueSelectFromSet_core1() is then used to determine which, if any, of the queues
 * or semaphores contained in the set is in a state where a queue read or
 * semaphore take operation would be successful.
 *
 * Note 1:  See the documentation on https://www.FreeRTOS_core1.org/RTOS-queue-sets.html
 * for reasons why queue sets are very rarely needed in practice as there are
 * simpler methods of blocking on multiple objects.
 *
 * Note 2:  Blocking on a queue set that contains a mutex will not cause the
 * mutex holder to inherit the priority of the blocked task_core1.
 *
 * Note 3:  An additional 4 bytes of RAM is required for each space in a every
 * queue added to a queue set.  Therefore counting semaphores that have a high
 * maximum count value should not be added to a queue set.
 *
 * Note 4:  A receive (in the case of a queue) or take (in the case of a
 * semaphore) operation must not be performed on a member of a queue set unless
 * a call to xQueueSelectFromSet_core1() has first returned a handle to that set member.
 *
 * @param uxEventQueueLength_core1 Queue sets store events that occur on
 * the queues and semaphores contained in the set.  uxEventQueueLength_core1 specifies
 * the maximum number of events that can be queued at once.  To be absolutely
 * certain that events are not lost uxEventQueueLength_core1 should be set to the
 * total sum of the length of the queues added to the set, where binary
 * semaphores and mutexes have a length of 1, and counting semaphores have a
 * length set by their maximum count value.  Examples:
 *  + If a queue set is to hold a queue of length 5, another queue of length 12,
 *    and a binary semaphore, then uxEventQueueLength_core1 should be set to
 *    (5 + 12 + 1), or 18.
 *  + If a queue set is to hold three binary semaphores then uxEventQueueLength_core1
 *    should be set to (1 + 1 + 1 ), or 3.
 *  + If a queue set is to hold a counting semaphore that has a maximum count of
 *    5, and a counting semaphore that has a maximum count of 3, then
 *    uxEventQueueLength_core1 should be set to (5 + 3), or 8.
 *
 * @return If the queue set is created successfully then a handle to the created
 * queue set is returned.  Otherwise NULL is returned.
 */
QueueSetHandle_t_core1 xQueueCreateSet_core1( const UBaseType_t_core1 uxEventQueueLength_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Adds a queue or semaphore to a queue set that was previously created by a
 * call to xQueueCreateSet_core1().
 *
 * See FreeRTOS_core1/Source/Demo/Common/Minimal/QueueSet.c for an example using this
 * function.
 *
 * Note 1:  A receive (in the case of a queue) or take (in the case of a
 * semaphore) operation must not be performed on a member of a queue set unless
 * a call to xQueueSelectFromSet_core1() has first returned a handle to that set member.
 *
 * @param xQueueOrSemaphore_core1 The handle of the queue or semaphore being added to
 * the queue set (cast to an QueueSetMemberHandle_t_core1 type).
 *
 * @param xQueueSet_core1 The handle of the queue set to which the queue or semaphore
 * is being added.
 *
 * @return If the queue or semaphore was successfully added to the queue set
 * then pdPASS_core1 is returned.  If the queue could not be successfully added to the
 * queue set because it is already a member of a different queue set then pdFAIL_core1
 * is returned.
 */
BaseType_t_core1 xQueueAddToSet_core1( QueueSetMemberHandle_t_core1 xQueueOrSemaphore_core1,
                           QueueSetHandle_t_core1 xQueueSet_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * Removes a queue or semaphore from a queue set.  A queue or semaphore can only
 * be removed from a set if the queue or semaphore is empty.
 *
 * See FreeRTOS_core1/Source/Demo/Common/Minimal/QueueSet.c for an example using this
 * function.
 *
 * @param xQueueOrSemaphore_core1 The handle of the queue or semaphore being removed
 * from the queue set (cast to an QueueSetMemberHandle_t_core1 type).
 *
 * @param xQueueSet_core1 The handle of the queue set in which the queue or semaphore
 * is included.
 *
 * @return If the queue or semaphore was successfully removed from the queue set
 * then pdPASS_core1 is returned.  If the queue was not in the queue set, or the
 * queue (or semaphore) was not empty, then pdFAIL_core1 is returned.
 */
BaseType_t_core1 xQueueRemoveFromSet_core1( QueueSetMemberHandle_t_core1 xQueueOrSemaphore_core1,
                                QueueSetHandle_t_core1 xQueueSet_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * xQueueSelectFromSet_core1() selects from the members of a queue set a queue or
 * semaphore that either contains data (in the case of a queue) or is available
 * to take (in the case of a semaphore).  xQueueSelectFromSet_core1() effectively
 * allows a task_core1 to block (pend) on a read operation on all the queues and
 * semaphores in a queue set simultaneously.
 *
 * See FreeRTOS_core1/Source/Demo/Common/Minimal/QueueSet.c for an example using this
 * function.
 *
 * Note 1:  See the documentation on https://www.FreeRTOS_core1.org/RTOS-queue-sets.html
 * for reasons why queue sets are very rarely needed in practice as there are
 * simpler methods of blocking on multiple objects.
 *
 * Note 2:  Blocking on a queue set that contains a mutex will not cause the
 * mutex holder to inherit the priority of the blocked task_core1.
 *
 * Note 3:  A receive (in the case of a queue) or take (in the case of a
 * semaphore) operation must not be performed on a member of a queue set unless
 * a call to xQueueSelectFromSet_core1() has first returned a handle to that set member.
 *
 * @param xQueueSet_core1 The queue set on which the task_core1 will (potentially) block.
 *
 * @param xTicksToWait_core1 The maximum time, in ticks, that the calling task_core1 will
 * remain in the Blocked state (with other tasks executing) to wait for a member
 * of the queue set to be ready for a successful queue read or semaphore take
 * operation.
 *
 * @return xQueueSelectFromSet_core1() will return the handle of a queue (cast to
 * a QueueSetMemberHandle_t_core1 type) contained in the queue set that contains data,
 * or the handle of a semaphore (cast to a QueueSetMemberHandle_t_core1 type) contained
 * in the queue set that is available, or NULL if no such queue or semaphore
 * exists before before the specified block time expires.
 */
QueueSetMemberHandle_t_core1 xQueueSelectFromSet_core1( QueueSetHandle_t_core1 xQueueSet_core1,
                                            const TickType_t_core1 xTicksToWait_core1 ) PRIVILEGED_FUNCTION_core1;

/*
 * A version of xQueueSelectFromSet_core1() that can be used from an ISR.
 */
QueueSetMemberHandle_t_core1 xQueueSelectFromSetFromISR_core1( QueueSetHandle_t_core1 xQueueSet_core1 ) PRIVILEGED_FUNCTION_core1;

/* Not public API functions. */
void vQueueWaitForMessageRestricted_core1( QueueHandle_t_core1 xQueue_core1,
                                     TickType_t_core1 xTicksToWait_core1,
                                     const BaseType_t_core1 xWaitIndefinitely_core1 ) PRIVILEGED_FUNCTION_core1;
BaseType_t_core1 xQueueGenericReset_core1( QueueHandle_t_core1 xQueue_core1,
                               BaseType_t_core1 xNewQueue_core1 ) PRIVILEGED_FUNCTION_core1;
void vQueueSetQueueNumber( QueueHandle_t_core1 xQueue_core1,
                           UBaseType_t_core1 uxQueueNumber_core1 ) PRIVILEGED_FUNCTION_core1;
UBaseType_t_core1 uxQueueGetQueueNumber( QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;
uint8_t ucQueueGetQueueType( QueueHandle_t_core1 xQueue_core1 ) PRIVILEGED_FUNCTION_core1;


/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* QUEUE_H */
