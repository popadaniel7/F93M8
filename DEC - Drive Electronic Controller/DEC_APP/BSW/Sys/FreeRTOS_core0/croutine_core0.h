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

#ifndef CO_ROUTINE_CORE0_H
#define CO_ROUTINE_CORE0_H

#ifndef INC_FREERTOS_CORE0_H
    #error "include FreeRTOS_core0.h must appear in source files before include croutine.h"
#endif

#include "list_core0.h"

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

/* Used to hide the implementation of the co-routine control block.  The
 * control block structure however has to be included in the header due to
 * the macro implementation of the co-routine functionality. */
typedef void * CoRoutineHandle_t_core0;

/* Defines the prototype to which co-routine functions must conform. */
typedef void (* crCOROUTINE_CODE_core0)( CoRoutineHandle_t_core0,
                                   UBaseType_t_core0 );

typedef struct corCoRoutineControlBlock_core0
{
    crCOROUTINE_CODE_core0 pxCoRoutineFunction_core0;
    ListItem_t_core0 xGenericListItem_core0; /*< List item used to place the CRCB in ready and blocked queues. */
    ListItem_t_core0 xEventListItem_core0;   /*< List item used to place the CRCB in event lists. */
    UBaseType_t_core0 uxPriority_core0;      /*< The priority of the co-routine in relation to other co-routines. */
    UBaseType_t_core0 uxIndex_core0;         /*< Used to distinguish between co-routines when multiple co-routines use the same co-routine function. */
    uint16_t uxState_core0;            /*< Used internally by the co-routine implementation. */
} CRCB_t_core0;                        /* Co-routine control block.  Note must be identical in size down to uxPriority_core0 with TCB_t_core0. */

/**
 * croutine. h
 * @code{c}
 * BaseType_t_core0 xCoRoutineCreate_core0(
 *                               crCOROUTINE_CODE_core0 pxCoRoutineCode_core0,
 *                               UBaseType_t_core0 uxPriority_core0,
 *                               UBaseType_t_core0 uxIndex_core0
 *                             );
 * @endcode
 *
 * Create a new co-routine and add it to the list of co-routines that are
 * ready to run.
 *
 * @param pxCoRoutineCode_core0 Pointer to the co-routine function.  Co-routine
 * functions require special syntax - see the co-routine section of the WEB
 * documentation for more information.
 *
 * @param uxPriority_core0 The priority with respect to other co-routines at which
 *  the co-routine will run.
 *
 * @param uxIndex_core0 Used to distinguish between different co-routines that
 * execute the same function.  See the example below and the co-routine section
 * of the WEB documentation for further information.
 *
 * @return pdPASS_core0 if the co-routine was successfully created and added to a ready
 * list, otherwise an error code defined with ProjDefs.h.
 *
 * Example usage:
 * @code{c}
 * // Co-routine to be created.
 * void vFlashCoRoutine( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * // Variables in co-routines must be declared static if they must maintain value across a blocking call.
 * // This may not be necessary for const variables.
 * static const char cLedToFlash[ 2 ] = { 5, 6 };
 * static const TickType_t_core0 uxFlashRates[ 2 ] = { 200, 400 };
 *
 *   // Must start every co-routine with a call to crSTART_core0();
 *   crSTART_core0( xHandle_core0 );
 *
 *   for( ;; )
 *   {
 *       // This co-routine just delays for a fixed period, then toggles
 *       // an LED.  Two co-routines are created using this function, so
 *       // the uxIndex_core0 parameter is used to tell the co-routine which
 *       // LED to flash and how int32_t to delay.  This assumes xQueue has
 *       // already been created.
 *       vParTestToggleLED( cLedToFlash[ uxIndex_core0 ] );
 *       crDELAY_core0( xHandle_core0, uxFlashRates[ uxIndex_core0 ] );
 *   }
 *
 *   // Must end every co-routine with a call to crEND_core0();
 *   crEND_core0();
 * }
 *
 * // Function that creates two co-routines.
 * void vOtherFunction( void )
 * {
 * uint8_t ucParameterToPass;
 * TaskHandle_t_core0 xHandle_core0;
 *
 *   // Create two co-routines at priority 0.  The first is given index 0
 *   // so (from the code above) toggles LED 5 every 200 ticks.  The second
 *   // is given index 1 so toggles LED 6 every 400 ticks.
 *   for( uxIndex_core0 = 0; uxIndex_core0 < 2; uxIndex_core0++ )
 *   {
 *       xCoRoutineCreate_core0( vFlashCoRoutine, 0, uxIndex_core0 );
 *   }
 * }
 * @endcode
 * \defgroup xCoRoutineCreate_core0 xCoRoutineCreate_core0
 * \ingroup Tasks
 */
BaseType_t_core0 xCoRoutineCreate_core0( crCOROUTINE_CODE_core0 pxCoRoutineCode_core0,
                             UBaseType_t_core0 uxPriority_core0,
                             UBaseType_t_core0 uxIndex_core0 );


/**
 * croutine. h
 * @code{c}
 * void vCoRoutineSchedule_core0( void );
 * @endcode
 *
 * Run a co-routine.
 *
 * vCoRoutineSchedule_core0() executes the highest priority co-routine that is able
 * to run.  The co-routine will execute until it either blocks, yields or is
 * preempted by a task_core0.  Co-routines execute cooperatively so one
 * co-routine cannot be preempted by another, but can be preempted by a task_core0.
 *
 * If an application comprises of both tasks and co-routines then
 * vCoRoutineSchedule_core0 should be called from the idle task_core0 (in an idle task_core0
 * hook).
 *
 * Example usage:
 * @code{c}
 * // This idle task_core0 hook will schedule a co-routine each time it is called.
 * // The rest of the idle task_core0 will execute between co-routine calls.
 * void vApplicationIdleHook( void )
 * {
 *  vCoRoutineSchedule_core0();
 * }
 *
 * // Alternatively, if you do not require any other part of the idle task_core0 to
 * // execute, the idle task_core0 hook can call vCoRoutineSchedule_core0() within an
 * // infinite loop.
 * void vApplicationIdleHook( void )
 * {
 *  for( ;; )
 *  {
 *      vCoRoutineSchedule_core0();
 *  }
 * }
 * @endcode
 * \defgroup vCoRoutineSchedule_core0 vCoRoutineSchedule_core0
 * \ingroup Tasks
 */
void vCoRoutineSchedule_core0( void );

/**
 * croutine. h
 * @code{c}
 * crSTART_core0( CoRoutineHandle_t_core0 xHandle_core0 );
 * @endcode
 *
 * This macro MUST always be called at the start of a co-routine function.
 *
 * Example usage:
 * @code{c}
 * // Co-routine to be created.
 * void vACoRoutine( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * // Variables in co-routines must be declared static if they must maintain value across a blocking call.
 * static int32_t ulAVariable;
 *
 *   // Must start every co-routine with a call to crSTART_core0();
 *   crSTART_core0( xHandle_core0 );
 *
 *   for( ;; )
 *   {
 *        // Co-routine functionality goes here.
 *   }
 *
 *   // Must end every co-routine with a call to crEND_core0();
 *   crEND_core0();
 * }
 * @endcode
 * \defgroup crSTART_core0 crSTART_core0
 * \ingroup Tasks
 */
#define crSTART_core0( pxCRCB_core0 )                            \
    switch( ( ( CRCB_t_core0 * ) ( pxCRCB_core0 ) )->uxState_core0 ) { \
        case 0:

/**
 * croutine. h
 * @code{c}
 * crEND_core0();
 * @endcode
 *
 * This macro MUST always be called at the end of a co-routine function.
 *
 * Example usage:
 * @code{c}
 * // Co-routine to be created.
 * void vACoRoutine( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * // Variables in co-routines must be declared static if they must maintain value across a blocking call.
 * static int32_t ulAVariable;
 *
 *   // Must start every co-routine with a call to crSTART_core0();
 *   crSTART_core0( xHandle_core0 );
 *
 *   for( ;; )
 *   {
 *        // Co-routine functionality goes here.
 *   }
 *
 *   // Must end every co-routine with a call to crEND_core0();
 *   crEND_core0();
 * }
 * @endcode
 * \defgroup crSTART_core0 crSTART_core0
 * \ingroup Tasks
 */
#define crEND_core0()    }

/*
 * These macros are intended for internal use by the co-routine implementation
 * only.  The macros should not be used directly by application writers.
 */
#define crSET_STATE0( xHandle_core0 )                                       \
    ( ( CRCB_t_core0 * ) ( xHandle_core0 ) )->uxState_core0 = ( __LINE__ * 2 ); return; \
    case ( __LINE__ * 2 ):
#define crSET_STATE1( xHandle_core0 )                                               \
    ( ( CRCB_t_core0 * ) ( xHandle_core0 ) )->uxState_core0 = ( ( __LINE__ * 2 ) + 1 ); return; \
    case ( ( __LINE__ * 2 ) + 1 ):

/**
 * croutine. h
 * @code{c}
 * crDELAY_core0( CoRoutineHandle_t_core0 xHandle_core0, TickType_t_core0 xTicksToDelay_core0 );
 * @endcode
 *
 * Delay a co-routine for a fixed period of time.
 *
 * crDELAY_core0 can only be called from the co-routine function itself - not
 * from within a function called by the co-routine function.  This is because
 * co-routines do not maintain their own stack.
 *
 * @param xHandle_core0 The handle of the co-routine to delay.  This is the xHandle_core0
 * parameter of the co-routine function.
 *
 * @param xTickToDelay The number of ticks that the co-routine should delay
 * for.  The actual amount of time this equates to is defined by
 * configTICK_RATE_HZ_core0 (set in FreeRTOSConfig.h).  The constant portTICK_PERIOD_MS_core0
 * can be used to convert ticks to milliseconds.
 *
 * Example usage:
 * @code{c}
 * // Co-routine to be created.
 * void vACoRoutine( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * // Variables in co-routines must be declared static if they must maintain value across a blocking call.
 * // This may not be necessary for const variables.
 * // We are to delay for 200ms.
 * static const xTickType xDelayTime = 200 / portTICK_PERIOD_MS_core0;
 *
 *   // Must start every co-routine with a call to crSTART_core0();
 *   crSTART_core0( xHandle_core0 );
 *
 *   for( ;; )
 *   {
 *      // Delay for 200ms.
 *      crDELAY_core0( xHandle_core0, xDelayTime );
 *
 *      // Do something here.
 *   }
 *
 *   // Must end every co-routine with a call to crEND_core0();
 *   crEND_core0();
 * }
 * @endcode
 * \defgroup crDELAY_core0 crDELAY_core0
 * \ingroup Tasks
 */
#define crDELAY_core0( xHandle_core0, xTicksToDelay_core0 )                      \
    if( ( xTicksToDelay_core0 ) > 0 )                                \
    {                                                          \
        vCoRoutineAddToDelayedList_core0( ( xTicksToDelay_core0 ), NULL ); \
    }                                                          \
    crSET_STATE0( ( xHandle_core0 ) );

/**
 * @code{c}
 * crQUEUE_SEND_core0(
 *                CoRoutineHandle_t_core0 xHandle_core0,
 *                QueueHandle_t pxQueue_core0,
 *                void *pvItemToQueue_core0,
 *                TickType_t_core0 xTicksToWait_core0,
 *                BaseType_t_core0 *pxResult_core0
 *           )
 * @endcode
 *
 * The macro's crQUEUE_SEND_core0() and crQUEUE_RECEIVE_core0() are the co-routine
 * equivalent to the xQueueSend() and xQueueReceive_core0() functions used by tasks.
 *
 * crQUEUE_SEND_core0 and crQUEUE_RECEIVE_core0 can only be used from a co-routine whereas
 * xQueueSend() and xQueueReceive_core0() can only be used from tasks.
 *
 * crQUEUE_SEND_core0 can only be called from the co-routine function itself - not
 * from within a function called by the co-routine function.  This is because
 * co-routines do not maintain their own stack.
 *
 * See the co-routine section of the WEB documentation for information on
 * passing data between tasks and co-routines and between ISR's and
 * co-routines.
 *
 * @param xHandle_core0 The handle of the calling co-routine.  This is the xHandle_core0
 * parameter of the co-routine function.
 *
 * @param pxQueue_core0 The handle of the queue on which the data will be posted.
 * The handle is obtained as the return value when the queue is created using
 * the xQueueCreate_core0() API function.
 *
 * @param pvItemToQueue_core0 A pointer to the data being posted onto the queue.
 * The number of bytes of each queued item is specified when the queue is
 * created.  This number of bytes is copied from pvItemToQueue_core0 into the queue
 * itself.
 *
 * @param xTickToDelay The number of ticks that the co-routine should block
 * to wait for space to become available on the queue, should space not be
 * available immediately. The actual amount of time this equates to is defined
 * by configTICK_RATE_HZ_core0 (set in FreeRTOSConfig.h).  The constant
 * portTICK_PERIOD_MS_core0 can be used to convert ticks to milliseconds (see example
 * below).
 *
 * @param pxResult_core0 The variable pointed to by pxResult_core0 will be set to pdPASS_core0 if
 * data was successfully posted onto the queue, otherwise it will be set to an
 * error defined within ProjDefs.h.
 *
 * Example usage:
 * @code{c}
 * // Co-routine function that blocks for a fixed period then posts a number onto
 * // a queue.
 * static void prvCoRoutineFlashTask( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * // Variables in co-routines must be declared static if they must maintain value across a blocking call.
 * static BaseType_t_core0 xNumberToPost = 0;
 * static BaseType_t_core0 xResult;
 *
 *  // Co-routines must begin with a call to crSTART_core0().
 *  crSTART_core0( xHandle_core0 );
 *
 *  for( ;; )
 *  {
 *      // This assumes the queue has already been created.
 *      crQUEUE_SEND_core0( xHandle_core0, xCoRoutineQueue, &xNumberToPost, NO_DELAY, &xResult );
 *
 *      if( xResult != pdPASS_core0 )
 *      {
 *          // The message was not posted!
 *      }
 *
 *      // Increment the number to be posted onto the queue.
 *      xNumberToPost++;
 *
 *      // Delay for 100 ticks.
 *      crDELAY_core0( xHandle_core0, 100 );
 *  }
 *
 *  // Co-routines must end with a call to crEND_core0().
 *  crEND_core0();
 * }
 * @endcode
 * \defgroup crQUEUE_SEND_core0 crQUEUE_SEND_core0
 * \ingroup Tasks
 */
#define crQUEUE_SEND_core0( xHandle_core0, pxQueue_core0, pvItemToQueue_core0, xTicksToWait_core0, pxResult_core0 )           \
    {                                                                                     \
        *( pxResult_core0 ) = xQueueCRSend_core0( ( pxQueue_core0 ), ( pvItemToQueue_core0 ), ( xTicksToWait_core0 ) ); \
        if( *( pxResult_core0 ) == errQUEUE_BLOCKED_core0 )                                           \
        {                                                                                 \
            crSET_STATE0( ( xHandle_core0 ) );                                                  \
            *pxResult_core0 = xQueueCRSend_core0( ( pxQueue_core0 ), ( pvItemToQueue_core0 ), 0 );                \
        }                                                                                 \
        if( *pxResult_core0 == errQUEUE_YIELD_core0 )                                                 \
        {                                                                                 \
            crSET_STATE1( ( xHandle_core0 ) );                                                  \
            *pxResult_core0 = pdPASS_core0;                                                           \
        }                                                                                 \
    }

/**
 * croutine. h
 * @code{c}
 * crQUEUE_RECEIVE_core0(
 *                   CoRoutineHandle_t_core0 xHandle_core0,
 *                   QueueHandle_t pxQueue_core0,
 *                   void *pvBuffer_core0,
 *                   TickType_t_core0 xTicksToWait_core0,
 *                   BaseType_t_core0 *pxResult_core0
 *               )
 * @endcode
 *
 * The macro's crQUEUE_SEND_core0() and crQUEUE_RECEIVE_core0() are the co-routine
 * equivalent to the xQueueSend() and xQueueReceive_core0() functions used by tasks.
 *
 * crQUEUE_SEND_core0 and crQUEUE_RECEIVE_core0 can only be used from a co-routine whereas
 * xQueueSend() and xQueueReceive_core0() can only be used from tasks.
 *
 * crQUEUE_RECEIVE_core0 can only be called from the co-routine function itself - not
 * from within a function called by the co-routine function.  This is because
 * co-routines do not maintain their own stack.
 *
 * See the co-routine section of the WEB documentation for information on
 * passing data between tasks and co-routines and between ISR's and
 * co-routines.
 *
 * @param xHandle_core0 The handle of the calling co-routine.  This is the xHandle_core0
 * parameter of the co-routine function.
 *
 * @param pxQueue_core0 The handle of the queue from which the data will be received.
 * The handle is obtained as the return value when the queue is created using
 * the xQueueCreate_core0() API function.
 *
 * @param pvBuffer_core0 The buffer into which the received item is to be copied.
 * The number of bytes of each queued item is specified when the queue is
 * created.  This number of bytes is copied into pvBuffer_core0.
 *
 * @param xTickToDelay The number of ticks that the co-routine should block
 * to wait for data to become available from the queue, should data not be
 * available immediately. The actual amount of time this equates to is defined
 * by configTICK_RATE_HZ_core0 (set in FreeRTOSConfig.h).  The constant
 * portTICK_PERIOD_MS_core0 can be used to convert ticks to milliseconds (see the
 * crQUEUE_SEND_core0 example).
 *
 * @param pxResult_core0 The variable pointed to by pxResult_core0 will be set to pdPASS_core0 if
 * data was successfully retrieved from the queue, otherwise it will be set to
 * an error code as defined within ProjDefs.h.
 *
 * Example usage:
 * @code{c}
 * // A co-routine receives the number of an LED to flash from a queue.  It
 * // blocks on the queue until the number is received.
 * static void prvCoRoutineFlashWorkTask( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * // Variables in co-routines must be declared static if they must maintain value across a blocking call.
 * static BaseType_t_core0 xResult;
 * static UBaseType_t_core0 uxLEDToFlash;
 *
 *  // All co-routines must start with a call to crSTART_core0().
 *  crSTART_core0( xHandle_core0 );
 *
 *  for( ;; )
 *  {
 *      // Wait for data to become available on the queue.
 *      crQUEUE_RECEIVE_core0( xHandle_core0, xCoRoutineQueue, &uxLEDToFlash, portMAX_DELAY_core0, &xResult );
 *
 *      if( xResult == pdPASS_core0 )
 *      {
 *          // We received the LED to flash - flash it!
 *          vParTestToggleLED( uxLEDToFlash );
 *      }
 *  }
 *
 *  crEND_core0();
 * }
 * @endcode
 * \defgroup crQUEUE_RECEIVE_core0 crQUEUE_RECEIVE_core0
 * \ingroup Tasks
 */
#define crQUEUE_RECEIVE_core0( xHandle_core0, pxQueue_core0, pvBuffer_core0, xTicksToWait_core0, pxResult_core0 )           \
    {                                                                                   \
        *( pxResult_core0 ) = xQueueCRReceive_core0( ( pxQueue_core0 ), ( pvBuffer_core0 ), ( xTicksToWait_core0 ) ); \
        if( *( pxResult_core0 ) == errQUEUE_BLOCKED_core0 )                                         \
        {                                                                               \
            crSET_STATE0( ( xHandle_core0 ) );                                                \
            *( pxResult_core0 ) = xQueueCRReceive_core0( ( pxQueue_core0 ), ( pvBuffer_core0 ), 0 );            \
        }                                                                               \
        if( *( pxResult_core0 ) == errQUEUE_YIELD_core0 )                                           \
        {                                                                               \
            crSET_STATE1( ( xHandle_core0 ) );                                                \
            *( pxResult_core0 ) = pdPASS_core0;                                                     \
        }                                                                               \
    }

/**
 * croutine. h
 * @code{c}
 * crQUEUE_SEND_FROM_ISR_core0(
 *                          QueueHandle_t pxQueue_core0,
 *                          void *pvItemToQueue_core0,
 *                          BaseType_t_core0 xCoRoutinePreviouslyWoken_core0
 *                     )
 * @endcode
 *
 * The macro's crQUEUE_SEND_FROM_ISR_core0() and crQUEUE_RECEIVE_FROM_ISR_core0() are the
 * co-routine equivalent to the xQueueSendFromISR_core0() and xQueueReceiveFromISR()
 * functions used by tasks.
 *
 * crQUEUE_SEND_FROM_ISR_core0() and crQUEUE_RECEIVE_FROM_ISR_core0() can only be used to
 * pass data between a co-routine and and ISR, whereas xQueueSendFromISR_core0() and
 * xQueueReceiveFromISR() can only be used to pass data between a task_core0 and and
 * ISR.
 *
 * crQUEUE_SEND_FROM_ISR_core0 can only be called from an ISR to send data to a queue
 * that is being used from within a co-routine.
 *
 * See the co-routine section of the WEB documentation for information on
 * passing data between tasks and co-routines and between ISR's and
 * co-routines.
 *
 * @param xQueue The handle to the queue on which the item is to be posted.
 *
 * @param pvItemToQueue_core0 A pointer to the item that is to be placed on the
 * queue.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from pvItemToQueue_core0
 * into the queue storage area.
 *
 * @param xCoRoutinePreviouslyWoken_core0 This is included so an ISR can post onto
 * the same queue multiple times from a single interrupt.  The first call
 * should always pass in pdFALSE_core0.  Subsequent calls should pass in
 * the value returned from the previous call.
 *
 * @return pdTRUE_core0 if a co-routine was woken by posting onto the queue.  This is
 * used by the ISR to determine if a context switch may be required following
 * the ISR.
 *
 * Example usage:
 * @code{c}
 * // A co-routine that blocks on a queue waiting for characters to be received.
 * static void vReceivingCoRoutine( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * char cRxedChar;
 * BaseType_t_core0 xResult;
 *
 *   // All co-routines must start with a call to crSTART_core0().
 *   crSTART_core0( xHandle_core0 );
 *
 *   for( ;; )
 *   {
 *       // Wait for data to become available on the queue.  This assumes the
 *       // queue xCommsRxQueue has already been created!
 *       crQUEUE_RECEIVE_core0( xHandle_core0, xCommsRxQueue, &uxLEDToFlash, portMAX_DELAY_core0, &xResult );
 *
 *       // Was a character received?
 *       if( xResult == pdPASS_core0 )
 *       {
 *           // Process the character here.
 *       }
 *   }
 *
 *   // All co-routines must end with a call to crEND_core0().
 *   crEND_core0();
 * }
 *
 * // An ISR that uses a queue to send characters received on a serial port to
 * // a co-routine.
 * void vUART_ISR( void )
 * {
 * char cRxedChar;
 * BaseType_t_core0 xCRWokenByPost = pdFALSE_core0;
 *
 *   // We loop around reading characters until there are none left in the UART.
 *   while( UART_RX_REG_NOT_EMPTY() )
 *   {
 *       // Obtain the character from the UART.
 *       cRxedChar = UART_RX_REG;
 *
 *       // Post the character onto a queue.  xCRWokenByPost will be pdFALSE_core0
 *       // the first time around the loop.  If the post causes a co-routine
 *       // to be woken (unblocked) then xCRWokenByPost will be set to pdTRUE_core0.
 *       // In this manner we can ensure that if more than one co-routine is
 *       // blocked on the queue only one is woken by this ISR no matter how
 *       // many characters are posted to the queue.
 *       xCRWokenByPost = crQUEUE_SEND_FROM_ISR_core0( xCommsRxQueue, &cRxedChar, xCRWokenByPost );
 *   }
 * }
 * @endcode
 * \defgroup crQUEUE_SEND_FROM_ISR_core0 crQUEUE_SEND_FROM_ISR_core0
 * \ingroup Tasks
 */
#define crQUEUE_SEND_FROM_ISR_core0( pxQueue_core0, pvItemToQueue_core0, xCoRoutinePreviouslyWoken_core0 ) \
    xQueueCRSendFromISR_core0( ( pxQueue_core0 ), ( pvItemToQueue_core0 ), ( xCoRoutinePreviouslyWoken_core0 ) )


/**
 * croutine. h
 * @code{c}
 * crQUEUE_SEND_FROM_ISR_core0(
 *                          QueueHandle_t pxQueue_core0,
 *                          void *pvBuffer_core0,
 *                          BaseType_t_core0 * pxCoRoutineWoken_core0
 *                     )
 * @endcode
 *
 * The macro's crQUEUE_SEND_FROM_ISR_core0() and crQUEUE_RECEIVE_FROM_ISR_core0() are the
 * co-routine equivalent to the xQueueSendFromISR_core0() and xQueueReceiveFromISR()
 * functions used by tasks.
 *
 * crQUEUE_SEND_FROM_ISR_core0() and crQUEUE_RECEIVE_FROM_ISR_core0() can only be used to
 * pass data between a co-routine and and ISR, whereas xQueueSendFromISR_core0() and
 * xQueueReceiveFromISR() can only be used to pass data between a task_core0 and and
 * ISR.
 *
 * crQUEUE_RECEIVE_FROM_ISR_core0 can only be called from an ISR to receive data
 * from a queue that is being used from within a co-routine (a co-routine
 * posted to the queue).
 *
 * See the co-routine section of the WEB documentation for information on
 * passing data between tasks and co-routines and between ISR's and
 * co-routines.
 *
 * @param xQueue The handle to the queue on which the item is to be posted.
 *
 * @param pvBuffer_core0 A pointer to a buffer into which the received item will be
 * placed.  The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from the queue into
 * pvBuffer_core0.
 *
 * @param pxCoRoutineWoken_core0 A co-routine may be blocked waiting for space to become
 * available on the queue.  If crQUEUE_RECEIVE_FROM_ISR_core0 causes such a
 * co-routine to unblock *pxCoRoutineWoken_core0 will get set to pdTRUE_core0, otherwise
 * *pxCoRoutineWoken_core0 will remain unchanged.
 *
 * @return pdTRUE_core0 an item was successfully received from the queue, otherwise
 * pdFALSE_core0.
 *
 * Example usage:
 * @code{c}
 * // A co-routine that posts a character to a queue then blocks for a fixed
 * // period.  The character is incremented each time.
 * static void vSendingCoRoutine( CoRoutineHandle_t_core0 xHandle_core0, UBaseType_t_core0 uxIndex_core0 )
 * {
 * // cChar holds its value while this co-routine is blocked and must therefore
 * // be declared static.
 * static char cCharToTx = 'a';
 * BaseType_t_core0 xResult;
 *
 *   // All co-routines must start with a call to crSTART_core0().
 *   crSTART_core0( xHandle_core0 );
 *
 *   for( ;; )
 *   {
 *       // Send the next character to the queue.
 *       crQUEUE_SEND_core0( xHandle_core0, xCoRoutineQueue, &cCharToTx, NO_DELAY, &xResult );
 *
 *       if( xResult == pdPASS_core0 )
 *       {
 *           // The character was successfully posted to the queue.
 *       }
 *       else
 *       {
 *          // Could not post the character to the queue.
 *       }
 *
 *       // Enable the UART Tx interrupt to cause an interrupt in this
 *       // hypothetical UART.  The interrupt will obtain the character
 *       // from the queue and send it.
 *       ENABLE_RX_INTERRUPT();
 *
 *       // Increment to the next character then block for a fixed period.
 *       // cCharToTx will maintain its value across the delay as it is
 *       // declared static.
 *       cCharToTx++;
 *       if( cCharToTx > 'x_core0' )
 *       {
 *          cCharToTx = 'a';
 *       }
 *       crDELAY_core0( 100 );
 *   }
 *
 *   // All co-routines must end with a call to crEND_core0().
 *   crEND_core0();
 * }
 *
 * // An ISR that uses a queue to receive characters to send on a UART.
 * void vUART_ISR( void )
 * {
 * char cCharToTx;
 * BaseType_t_core0 xCRWokenByPost = pdFALSE_core0;
 *
 *   while( UART_TX_REG_EMPTY() )
 *   {
 *       // Are there any characters in the queue waiting to be sent?
 *       // xCRWokenByPost will automatically be set to pdTRUE_core0 if a co-routine
 *       // is woken by the post - ensuring that only a single co-routine is
 *       // woken no matter how many times we go around this loop.
 *       if( crQUEUE_RECEIVE_FROM_ISR_core0( pxQueue_core0, &cCharToTx, &xCRWokenByPost ) )
 *       {
 *           SEND_CHARACTER( cCharToTx );
 *       }
 *   }
 * }
 * @endcode
 * \defgroup crQUEUE_RECEIVE_FROM_ISR_core0 crQUEUE_RECEIVE_FROM_ISR_core0
 * \ingroup Tasks
 */
#define crQUEUE_RECEIVE_FROM_ISR_core0( pxQueue_core0, pvBuffer_core0, pxCoRoutineWoken_core0 ) \
    xQueueCRReceiveFromISR_core0( ( pxQueue_core0 ), ( pvBuffer_core0 ), ( pxCoRoutineWoken_core0 ) )

/*
 * This function is intended for internal use by the co-routine macros only.
 * The macro nature of the co-routine implementation requires that the
 * prototype appears here.  The function should not be used by application
 * writers.
 *
 * Removes the current co-routine from its ready list and places it in the
 * appropriate delayed list.
 */
void vCoRoutineAddToDelayedList_core0( TickType_t_core0 xTicksToDelay_core0,
                                 List_t_core0 * pxEventList_core0 );

/*
 * This function is intended for internal use by the queue implementation only.
 * The function should not be used by application writers.
 *
 * Removes the highest priority co-routine from the event list and places it in
 * the pending ready list.
 */
BaseType_t_core0 xCoRoutineRemoveFromEventList( const List_t_core0 * pxEventList_core0 );

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* CO_ROUTINE_H */
