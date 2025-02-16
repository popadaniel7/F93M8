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
 * When the MPU is used the standard (non MPU) API functions are mapped to
 * equivalents that start "MPU_", the prototypes for which are defined in this
 * header files.  This will cause the application code to call the MPU_ version
 * which wraps the non-MPU version with privilege promoting then demoting code,
 * so the kernel code always runs will full privileges.
 */


#ifndef MPU_PROTOTYPES_CORE1_H
#define MPU_PROTOTYPES_CORE1_H

#include "FreeRTOS_core1.h"
#include "task_core1.h"

/* MPU versions of task_core1.h API functions. */
BaseType_t_core1 MPU_xTaskCreate_core1( TaskFunction_t_core1 pxTaskCode_core1,
                            const char * const pcName_core1,
                            const uint16_t usStackDepth_core1,
                            void * const pvParameters_core1,
                            UBaseType_t_core1 uxPriority_core1,
                            TaskHandle_t_core1 * const pxCreatedTask_core1 ) FREERTOS_SYSTEM_CALL_core1;
TaskHandle_t_core1 MPU_xTaskCreateStatic_core1( TaskFunction_t_core1 pxTaskCode_core1,
                                    const char * const pcName_core1,
                                    const uint32_t ulStackDepth_core1,
                                    void * const pvParameters_core1,
                                    UBaseType_t_core1 uxPriority_core1,
                                    StackType_t_core1 * const puxStackBuffer_core1,
                                    StaticTask_t_core1 * const pxTaskBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskDelete_core1( TaskHandle_t_core1 xTaskToDelete_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskDelay_core1( const TickType_t_core1 xTicksToDelay_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskDelayUntil_core1( TickType_t_core1 * const pxPreviousWakeTime_core1,
                                const TickType_t_core1 xTimeIncrement_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskAbortDelay_core1( TaskHandle_t_core1 xTask_core1 ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxTaskPriorityGet_core1( const TaskHandle_t_core1 xTask_core1 ) FREERTOS_SYSTEM_CALL_core1;
eTaskState_core1 MPU_eTaskGetState_core1( TaskHandle_t_core1 xTask_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskGetInfo_core1( TaskHandle_t_core1 xTask_core1,
                       TaskStatus_t_core1 * pxTaskStatus_core1,
                       BaseType_t_core1 xGetFreeStackSpace,
                       eTaskState_core1 eState_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskPrioritySet_core1( TaskHandle_t_core1 xTask_core1,
                           UBaseType_t_core1 uxNewPriority_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskSuspend_core1( TaskHandle_t_core1 xTaskToSuspend_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskResume_core1( TaskHandle_t_core1 xTaskToResume_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskStartScheduler_core1( void ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskSuspendAll_core1( void ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskResumeAll_core1( void ) FREERTOS_SYSTEM_CALL_core1;
TickType_t_core1 MPU_xTaskGetTickCount_core1( void ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxTaskGetNumberOfTasks_core1( void ) FREERTOS_SYSTEM_CALL_core1;
char * MPU_pcTaskGetName_core1( TaskHandle_t_core1 xTaskToQuery_core1 ) FREERTOS_SYSTEM_CALL_core1;
TaskHandle_t_core1 MPU_xTaskGetHandle_core1( const char * pcNameToQuery_core1 ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxTaskGetStackHighWaterMark_core1( TaskHandle_t_core1 xTask_core1 ) FREERTOS_SYSTEM_CALL_core1;
configSTACK_DEPTH_TYPE_core1 MPU_uxTaskGetStackHighWaterMark2_core1( TaskHandle_t_core1 xTask_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskSetApplicationTaskTag_core1( TaskHandle_t_core1 xTask_core1,
                                     TaskHookFunction_t_core1 pxHookFunction ) FREERTOS_SYSTEM_CALL_core1;
TaskHookFunction_t_core1 MPU_xTaskGetApplicationTaskTag_core1( TaskHandle_t_core1 xTask_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskSetThreadLocalStoragePointer_core1( TaskHandle_t_core1 xTaskToSet_core1,
                                            BaseType_t_core1 xIndex_core1,
                                            void * pvValue ) FREERTOS_SYSTEM_CALL_core1;
void * MPU_pvTaskGetThreadLocalStoragePointer_core1( TaskHandle_t_core1 xTaskToQuery_core1,
                                               BaseType_t_core1 xIndex_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskCallApplicationTaskHook_core1( TaskHandle_t_core1 xTask_core1,
                                             void * pvParameter_core1 ) FREERTOS_SYSTEM_CALL_core1;
TaskHandle_t_core1 MPU_xTaskGetIdleTaskHandle_core1( void ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxTaskGetSystemState_core1( TaskStatus_t_core1 * const pxTaskStatusArray_core1,
                                      const UBaseType_t_core1 uxArraySize_core1,
                                      configRUN_TIME_COUNTER_TYPE_core1 * const pulTotalRunTime_core1 ) FREERTOS_SYSTEM_CALL_core1;
configRUN_TIME_COUNTER_TYPE_core1 MPU_ulTaskGetIdleRunTimeCounter_core1( void ) FREERTOS_SYSTEM_CALL_core1;
configRUN_TIME_COUNTER_TYPE_core1 MPU_ulTaskGetIdleRunTimePercent_core1( void ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskList_core1( char * pcWriteBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskGetRunTimeStats_core1( char * pcWriteBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskGenericNotify_core1( TaskHandle_t_core1 xTaskToNotify_core1,
                                   UBaseType_t_core1 uxIndexToNotify_core1,
                                   uint32_t ulValue_core1,
                                   eNotifyAction_core1 eAction_core1,
                                   uint32_t * pulPreviousNotificationValue_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskGenericNotifyWait_core1( UBaseType_t_core1 uxIndexToWaitOn_core1,
                                       uint32_t ulBitsToClearOnEntry_core1,
                                       uint32_t ulBitsToClearOnExit_core1,
                                       uint32_t * pulNotificationValue_core1,
                                       TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
uint32_t MPU_ulTaskGenericNotifyTake_core1( UBaseType_t_core1 uxIndexToWaitOn_core1,
                                      BaseType_t_core1 xClearCountOnExit_core1,
                                      TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskGenericNotifyStateClear_core1( TaskHandle_t_core1 xTask_core1,
                                             UBaseType_t_core1 uxIndexToClear_core1 ) FREERTOS_SYSTEM_CALL_core1;
uint32_t MPU_ulTaskGenericNotifyValueClear_core1( TaskHandle_t_core1 xTask_core1,
                                            UBaseType_t_core1 uxIndexToClear_core1,
                                            uint32_t ulBitsToClear_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskIncrementTick_core1( void ) FREERTOS_SYSTEM_CALL_core1;
TaskHandle_t_core1 MPU_xTaskGetCurrentTaskHandle_core1( void ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskSetTimeOutState_core1( TimeOut_t_core1 * const pxTimeOut_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskCheckForTimeOut_core1( TimeOut_t_core1 * const pxTimeOut_core1,
                                     TickType_t_core1 * const pxTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTaskMissedYield_core1( void ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskGetSchedulerState_core1( void ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTaskCatchUpTicks_core1( TickType_t_core1 xTicksToCatchUp ) FREERTOS_SYSTEM_CALL_core1;

/* MPU versions of queue.h API functions. */
BaseType_t_core1 MPU_xQueueGenericSend_core1( QueueHandle_t_core1 xQueue_core1,
                                  const void * const pvItemToQueue_core1,
                                  TickType_t_core1 xTicksToWait_core1,
                                  const BaseType_t_core1 xCopyPosition_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueueReceive_core1( QueueHandle_t_core1 xQueue_core1,
                              void * const pvBuffer_core1,
                              TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueuePeek_core1( QueueHandle_t_core1 xQueue_core1,
                           void * const pvBuffer_core1,
                           TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueueSemaphoreTake_core1( QueueHandle_t_core1 xQueue_core1,
                                    TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxQueueMessagesWaiting_core1( const QueueHandle_t_core1 xQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxQueueSpacesAvailable_core1( const QueueHandle_t_core1 xQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vQueueDelete_core1( QueueHandle_t_core1 xQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueHandle_t_core1 MPU_xQueueCreateMutex_core1( const uint8_t ucQueueType_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueHandle_t_core1 MPU_xQueueCreateMutexStatic_core1( const uint8_t ucQueueType_core1,
                                           StaticQueue_t_core1 * pxStaticQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueHandle_t_core1 MPU_xQueueCreateCountingSemaphore_core1( const UBaseType_t_core1 uxMaxCount_core1,
                                                 const UBaseType_t_core1 uxInitialCount_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueHandle_t_core1 MPU_xQueueCreateCountingSemaphoreStatic_core1( const UBaseType_t_core1 uxMaxCount_core1,
                                                       const UBaseType_t_core1 uxInitialCount_core1,
                                                       StaticQueue_t_core1 * pxStaticQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
TaskHandle_t_core1 MPU_xQueueGetMutexHolder_core1( QueueHandle_t_core1 xSemaphore_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueueTakeMutexRecursive_core1( QueueHandle_t_core1 xMutex_core1,
                                         TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueueGiveMutexRecursive_core1( QueueHandle_t_core1 pxMutex_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vQueueAddToRegistry_core1( QueueHandle_t_core1 xQueue_core1,
                              const char * pcName_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vQueueUnregisterQueue_core1( QueueHandle_t_core1 xQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
const char * MPU_pcQueueGetName_core1( QueueHandle_t_core1 xQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueHandle_t_core1 MPU_xQueueGenericCreate_core1( const UBaseType_t_core1 uxQueueLength_core1,
                                       const UBaseType_t_core1 uxItemSize_core1,
                                       const uint8_t ucQueueType_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueHandle_t_core1 MPU_xQueueGenericCreateStatic_core1( const UBaseType_t_core1 uxQueueLength_core1,
                                             const UBaseType_t_core1 uxItemSize_core1,
                                             uint8_t * pucQueueStorage_core1,
                                             StaticQueue_t_core1 * pxStaticQueue_core1,
                                             const uint8_t ucQueueType_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueSetHandle_t_core1 MPU_xQueueCreateSet_core1( const UBaseType_t_core1 uxEventQueueLength_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueueAddToSet_core1( QueueSetMemberHandle_t_core1 xQueueOrSemaphore_core1,
                               QueueSetHandle_t_core1 xQueueSet_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueueRemoveFromSet_core1( QueueSetMemberHandle_t_core1 xQueueOrSemaphore_core1,
                                    QueueSetHandle_t_core1 xQueueSet_core1 ) FREERTOS_SYSTEM_CALL_core1;
QueueSetMemberHandle_t_core1 MPU_xQueueSelectFromSet_core1( QueueSetHandle_t_core1 xQueueSet_core1,
                                                const TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xQueueGenericReset_core1( QueueHandle_t_core1 xQueue_core1,
                                   BaseType_t_core1 xNewQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vQueueSetQueueNumber_core1( QueueHandle_t_core1 xQueue_core1,
                               UBaseType_t_core1 uxQueueNumber_core1 ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxQueueGetQueueNumber_core1( QueueHandle_t_core1 xQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;
uint8_t MPU_ucQueueGetQueueType_core1( QueueHandle_t_core1 xQueue_core1 ) FREERTOS_SYSTEM_CALL_core1;

/* MPU versions of timers_core1.h API functions. */
TimerHandle_t_core1 MPU_xTimerCreate_core1( const char * const pcTimerName_core1,
                                const TickType_t_core1 xTimerPeriodInTicks_core1,
                                const UBaseType_t_core1 uxAutoReload_core1,
                                void * const pvTimerID_core1,
                                TimerCallbackFunction_t_core1 pxCallbackFunction_core1 ) FREERTOS_SYSTEM_CALL_core1;
TimerHandle_t_core1 MPU_xTimerCreateStatic_core1( const char * const pcTimerName_core1,
                                      const TickType_t_core1 xTimerPeriodInTicks_core1,
                                      const UBaseType_t_core1 uxAutoReload_core1,
                                      void * const pvTimerID_core1,
                                      TimerCallbackFunction_t_core1 pxCallbackFunction_core1,
                                      StaticTimer_t_core1 * pxTimerBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
void * MPU_pvTimerGetTimerID_core1( const TimerHandle_t_core1 xTimer_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTimerSetTimerID_core1( TimerHandle_t_core1 xTimer_core1,
                           void * pvNewID_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTimerIsTimerActive_core1( TimerHandle_t_core1 xTimer_core1 ) FREERTOS_SYSTEM_CALL_core1;
TaskHandle_t_core1 MPU_xTimerGetTimerDaemonTaskHandle_core1( void ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTimerPendFunctionCall_core1( PendedFunction_t_core1 xFunctionToPend_core1,
                                       void * pvParameter1_core1,
                                       uint32_t ulParameter2_core1,
                                       TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
const char * MPU_pcTimerGetName_core1( TimerHandle_t_core1 xTimer_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vTimerSetReloadMode_core1( TimerHandle_t_core1 xTimer_core1,
                              const UBaseType_t_core1 uxAutoReload_core1 ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxTimerGetReloadMode_core1( TimerHandle_t_core1 xTimer_core1 ) FREERTOS_SYSTEM_CALL_core1;
TickType_t_core1 MPU_xTimerGetPeriod_core1( TimerHandle_t_core1 xTimer_core1 ) FREERTOS_SYSTEM_CALL_core1;
TickType_t_core1 MPU_xTimerGetExpiryTime_core1( TimerHandle_t_core1 xTimer_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTimerCreateTimerTask_core1( void ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xTimerGenericCommand_core1( TimerHandle_t_core1 xTimer_core1,
                                     const BaseType_t_core1 xCommandID_core1,
                                     const TickType_t_core1 xOptionalValue_core1,
                                     BaseType_t_core1 * const pxHigherPriorityTaskWoken_core1,
                                     const TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;

/* MPU versions of event_group.h API functions. */
EventGroupHandle_t_core1 MPU_xEventGroupCreate_core1( void ) FREERTOS_SYSTEM_CALL_core1;
EventGroupHandle_t_core1 MPU_xEventGroupCreateStatic_core1( StaticEventGroup_t_core1 * pxEventGroupBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
EventBits_t_core1 MPU_xEventGroupWaitBits_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                     const EventBits_t_core1 uxBitsToWaitFor_core1,
                                     const BaseType_t_core1 xClearOnExit_core1,
                                     const BaseType_t_core1 xWaitForAllBits_core1,
                                     TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
EventBits_t_core1 MPU_xEventGroupClearBits_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                      const EventBits_t_core1 uxBitsToClear_core1 ) FREERTOS_SYSTEM_CALL_core1;
EventBits_t_core1 MPU_xEventGroupSetBits_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                    const EventBits_t_core1 uxBitsToSet_core1 ) FREERTOS_SYSTEM_CALL_core1;
EventBits_t_core1 MPU_xEventGroupSync_core1( EventGroupHandle_t_core1 xEventGroup_core1,
                                 const EventBits_t_core1 uxBitsToSet_core1,
                                 const EventBits_t_core1 uxBitsToWaitFor_core1,
                                 TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vEventGroupDelete_core1( EventGroupHandle_t_core1 xEventGroup_core1 ) FREERTOS_SYSTEM_CALL_core1;
UBaseType_t_core1 MPU_uxEventGroupGetNumber_core1( void * xEventGroup_core1 ) FREERTOS_SYSTEM_CALL_core1;

/* MPU versions of message/stream_buffer_core1.h API functions. */
size_t MPU_xStreamBufferSend_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                              const void * pvTxData_core1,
                              size_t xDataLengthBytes_core1,
                              TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
size_t MPU_xStreamBufferReceive_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                 void * pvRxData_core1,
                                 size_t xBufferLengthBytes_core1,
                                 TickType_t_core1 xTicksToWait_core1 ) FREERTOS_SYSTEM_CALL_core1;
size_t MPU_xStreamBufferNextMessageLengthBytes_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
void MPU_vStreamBufferDelete_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xStreamBufferIsFull_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xStreamBufferIsEmpty_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xStreamBufferReset_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
size_t MPU_xStreamBufferSpacesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
size_t MPU_xStreamBufferBytesAvailable_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1 ) FREERTOS_SYSTEM_CALL_core1;
BaseType_t_core1 MPU_xStreamBufferSetTriggerLevel_core1( StreamBufferHandle_t_core1 xStreamBuffer_core1,
                                             size_t xTriggerLevel_core1 ) FREERTOS_SYSTEM_CALL_core1;
StreamBufferHandle_t_core1 MPU_xStreamBufferGenericCreate_core1( size_t xBufferSizeBytes_core1,
                                                     size_t xTriggerLevelBytes_core1,
                                                     BaseType_t_core1 xIsMessageBuffer_core1,
                                                     StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                                     StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 ) FREERTOS_SYSTEM_CALL_core1;
StreamBufferHandle_t_core1 MPU_xStreamBufferGenericCreateStatic_core1( size_t xBufferSizeBytes_core1,
                                                           size_t xTriggerLevelBytes_core1,
                                                           BaseType_t_core1 xIsMessageBuffer_core1,
                                                           uint8_t * const pucStreamBufferStorageArea_core1,
                                                           StaticStreamBuffer_t_core1 * const pxStaticStreamBuffer_core1,
                                                           StreamBufferCallbackFunction_t_core1 pxSendCompletedCallback_core1,
                                                           StreamBufferCallbackFunction_t_core1 pxReceiveCompletedCallback_core1 ) FREERTOS_SYSTEM_CALL_core1;



#endif /* MPU_PROTOTYPES_H */
