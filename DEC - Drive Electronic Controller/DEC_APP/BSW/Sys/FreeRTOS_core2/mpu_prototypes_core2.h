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
 * When the MPU is used the standard (non MPU) API functions are mapped to
 * equivalents that start "MPU_", the prototypes for which are defined in this
 * header files.  This will cause the application code to call the MPU_ version
 * which wraps the non-MPU version with privilege promoting then demoting code,
 * so the kernel code always runs will full privileges.
 */


#ifndef MPU_PROTOTYPES_CORE2_H
#define MPU_PROTOTYPES_CORE2_H

#include "FreeRTOS_core2.h"
#include "task_core2.h"

/* MPU versions of task_core2.h API functions. */
BaseType_t_core2 MPU_xTaskCreate_core2( TaskFunction_t_core2 pxTaskCode_core2,
                            const char * const pcName_core2,
                            const uint16_t usStackDepth_core2,
                            void * const pvParameters_core2,
                            UBaseType_t_core2 uxPriority_core2,
                            TaskHandle_t_core2 * const pxCreatedTask_core2 ) FREERTOS_SYSTEM_CALL_core2;
TaskHandle_t_core2 MPU_xTaskCreateStatic_core2( TaskFunction_t_core2 pxTaskCode_core2,
                                    const char * const pcName_core2,
                                    const uint32_t ulStackDepth_core2,
                                    void * const pvParameters_core2,
                                    UBaseType_t_core2 uxPriority_core2,
                                    StackType_t_core2 * const puxStackBuffer_core2,
                                    StaticTask_t_core2 * const pxTaskBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskDelete_core2( TaskHandle_t_core2 xTaskToDelete_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskDelay_core2( const TickType_t_core2 xTicksToDelay_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskDelayUntil_core2( TickType_t_core2 * const pxPreviousWakeTime_core2,
                                const TickType_t_core2 xTimeIncrement_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskAbortDelay_core2( TaskHandle_t_core2 xTask_core2 ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxTaskPriorityGet_core2( const TaskHandle_t_core2 xTask_core2 ) FREERTOS_SYSTEM_CALL_core2;
eTaskState_core2 MPU_eTaskGetState_core2( TaskHandle_t_core2 xTask_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskGetInfo_core2( TaskHandle_t_core2 xTask_core2,
                       TaskStatus_t_core2 * pxTaskStatus_core2,
                       BaseType_t_core2 xGetFreeStackSpace,
                       eTaskState_core2 eState_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskPrioritySet_core2( TaskHandle_t_core2 xTask_core2,
                           UBaseType_t_core2 uxNewPriority_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskSuspend_core2( TaskHandle_t_core2 xTaskToSuspend_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskResume_core2( TaskHandle_t_core2 xTaskToResume_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskStartScheduler_core2( void ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskSuspendAll_core2( void ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskResumeAll_core2( void ) FREERTOS_SYSTEM_CALL_core2;
TickType_t_core2 MPU_xTaskGetTickCount_core2( void ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxTaskGetNumberOfTasks_core2( void ) FREERTOS_SYSTEM_CALL_core2;
char * MPU_pcTaskGetName_core2( TaskHandle_t_core2 xTaskToQuery_core2 ) FREERTOS_SYSTEM_CALL_core2;
TaskHandle_t_core2 MPU_xTaskGetHandle_core2( const char * pcNameToQuery_core2 ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxTaskGetStackHighWaterMark_core2( TaskHandle_t_core2 xTask_core2 ) FREERTOS_SYSTEM_CALL_core2;
configSTACK_DEPTH_TYPE_core2 MPU_uxTaskGetStackHighWaterMark2_core2( TaskHandle_t_core2 xTask_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskSetApplicationTaskTag_core2( TaskHandle_t_core2 xTask_core2,
                                     TaskHookFunction_t_core2 pxHookFunction ) FREERTOS_SYSTEM_CALL_core2;
TaskHookFunction_t_core2 MPU_xTaskGetApplicationTaskTag_core2( TaskHandle_t_core2 xTask_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskSetThreadLocalStoragePointer_core2( TaskHandle_t_core2 xTaskToSet_core2,
                                            BaseType_t_core2 xIndex_core2,
                                            void * pvValue ) FREERTOS_SYSTEM_CALL_core2;
void * MPU_pvTaskGetThreadLocalStoragePointer_core2( TaskHandle_t_core2 xTaskToQuery_core2,
                                               BaseType_t_core2 xIndex_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskCallApplicationTaskHook_core2( TaskHandle_t_core2 xTask_core2,
                                             void * pvParameter_core2 ) FREERTOS_SYSTEM_CALL_core2;
TaskHandle_t_core2 MPU_xTaskGetIdleTaskHandle_core2( void ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxTaskGetSystemState_core2( TaskStatus_t_core2 * const pxTaskStatusArray_core2,
                                      const UBaseType_t_core2 uxArraySize_core2,
                                      configRUN_TIME_COUNTER_TYPE_core2 * const pulTotalRunTime_core2 ) FREERTOS_SYSTEM_CALL_core2;
configRUN_TIME_COUNTER_TYPE_core2 MPU_ulTaskGetIdleRunTimeCounter_core2( void ) FREERTOS_SYSTEM_CALL_core2;
configRUN_TIME_COUNTER_TYPE_core2 MPU_ulTaskGetIdleRunTimePercent_core2( void ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskList_core2( char * pcWriteBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskGetRunTimeStats_core2( char * pcWriteBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskGenericNotify_core2( TaskHandle_t_core2 xTaskToNotify_core2,
                                   UBaseType_t_core2 uxIndexToNotify_core2,
                                   uint32_t ulValue_core2,
                                   eNotifyAction_core2 eAction_core2,
                                   uint32_t * pulPreviousNotificationValue_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskGenericNotifyWait_core2( UBaseType_t_core2 uxIndexToWaitOn_core2,
                                       uint32_t ulBitsToClearOnEntry_core2,
                                       uint32_t ulBitsToClearOnExit_core2,
                                       uint32_t * pulNotificationValue_core2,
                                       TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
uint32_t MPU_ulTaskGenericNotifyTake_core2( UBaseType_t_core2 uxIndexToWaitOn_core2,
                                      BaseType_t_core2 xClearCountOnExit_core2,
                                      TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskGenericNotifyStateClear_core2( TaskHandle_t_core2 xTask_core2,
                                             UBaseType_t_core2 uxIndexToClear_core2 ) FREERTOS_SYSTEM_CALL_core2;
uint32_t MPU_ulTaskGenericNotifyValueClear_core2( TaskHandle_t_core2 xTask_core2,
                                            UBaseType_t_core2 uxIndexToClear_core2,
                                            uint32_t ulBitsToClear_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskIncrementTick_core2( void ) FREERTOS_SYSTEM_CALL_core2;
TaskHandle_t_core2 MPU_xTaskGetCurrentTaskHandle_core2( void ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskSetTimeOutState_core2( TimeOut_t_core2 * const pxTimeOut_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskCheckForTimeOut_core2( TimeOut_t_core2 * const pxTimeOut_core2,
                                     TickType_t_core2 * const pxTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTaskMissedYield_core2( void ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskGetSchedulerState_core2( void ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTaskCatchUpTicks_core2( TickType_t_core2 xTicksToCatchUp ) FREERTOS_SYSTEM_CALL_core2;

/* MPU versions of queue.h API functions. */
BaseType_t_core2 MPU_xQueueGenericSend_core2( QueueHandle_t_core2 xQueue_core2,
                                  const void * const pvItemToQueue_core2,
                                  TickType_t_core2 xTicksToWait_core2,
                                  const BaseType_t_core2 xCopyPosition_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueueReceive_core2( QueueHandle_t_core2 xQueue_core2,
                              void * const pvBuffer_core2,
                              TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueuePeek_core2( QueueHandle_t_core2 xQueue_core2,
                           void * const pvBuffer_core2,
                           TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueueSemaphoreTake_core2( QueueHandle_t_core2 xQueue_core2,
                                    TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxQueueMessagesWaiting_core2( const QueueHandle_t_core2 xQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxQueueSpacesAvailable_core2( const QueueHandle_t_core2 xQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vQueueDelete_core2( QueueHandle_t_core2 xQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueHandle_t_core2 MPU_xQueueCreateMutex_core2( const uint8_t ucQueueType_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueHandle_t_core2 MPU_xQueueCreateMutexStatic_core2( const uint8_t ucQueueType_core2,
                                           StaticQueue_t_core2 * pxStaticQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueHandle_t_core2 MPU_xQueueCreateCountingSemaphore_core2( const UBaseType_t_core2 uxMaxCount_core2,
                                                 const UBaseType_t_core2 uxInitialCount_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueHandle_t_core2 MPU_xQueueCreateCountingSemaphoreStatic_core2( const UBaseType_t_core2 uxMaxCount_core2,
                                                       const UBaseType_t_core2 uxInitialCount_core2,
                                                       StaticQueue_t_core2 * pxStaticQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
TaskHandle_t_core2 MPU_xQueueGetMutexHolder_core2( QueueHandle_t_core2 xSemaphore_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueueTakeMutexRecursive_core2( QueueHandle_t_core2 xMutex_core2,
                                         TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueueGiveMutexRecursive_core2( QueueHandle_t_core2 pxMutex_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vQueueAddToRegistry_core2( QueueHandle_t_core2 xQueue_core2,
                              const char * pcName_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vQueueUnregisterQueue_core2( QueueHandle_t_core2 xQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
const char * MPU_pcQueueGetName_core2( QueueHandle_t_core2 xQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueHandle_t_core2 MPU_xQueueGenericCreate_core2( const UBaseType_t_core2 uxQueueLength_core2,
                                       const UBaseType_t_core2 uxItemSize_core2,
                                       const uint8_t ucQueueType_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueHandle_t_core2 MPU_xQueueGenericCreateStatic_core2( const UBaseType_t_core2 uxQueueLength_core2,
                                             const UBaseType_t_core2 uxItemSize_core2,
                                             uint8_t * pucQueueStorage_core2,
                                             StaticQueue_t_core2 * pxStaticQueue_core2,
                                             const uint8_t ucQueueType_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueSetHandle_t_core2 MPU_xQueueCreateSet_core2( const UBaseType_t_core2 uxEventQueueLength_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueueAddToSet_core2( QueueSetMemberHandle_t_core2 xQueueOrSemaphore_core2,
                               QueueSetHandle_t_core2 xQueueSet_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueueRemoveFromSet_core2( QueueSetMemberHandle_t_core2 xQueueOrSemaphore_core2,
                                    QueueSetHandle_t_core2 xQueueSet_core2 ) FREERTOS_SYSTEM_CALL_core2;
QueueSetMemberHandle_t_core2 MPU_xQueueSelectFromSet_core2( QueueSetHandle_t_core2 xQueueSet_core2,
                                                const TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xQueueGenericReset_core2( QueueHandle_t_core2 xQueue_core2,
                                   BaseType_t_core2 xNewQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vQueueSetQueueNumber_core2( QueueHandle_t_core2 xQueue_core2,
                               UBaseType_t_core2 uxQueueNumber_core2 ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxQueueGetQueueNumber_core2( QueueHandle_t_core2 xQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;
uint8_t MPU_ucQueueGetQueueType_core2( QueueHandle_t_core2 xQueue_core2 ) FREERTOS_SYSTEM_CALL_core2;

/* MPU versions of timers_core2.h API functions. */
TimerHandle_t_core2 MPU_xTimerCreate_core2( const char * const pcTimerName_core2,
                                const TickType_t_core2 xTimerPeriodInTicks_core2,
                                const UBaseType_t_core2 uxAutoReload_core2,
                                void * const pvTimerID_core2,
                                TimerCallbackFunction_t_core2 pxCallbackFunction_core2 ) FREERTOS_SYSTEM_CALL_core2;
TimerHandle_t_core2 MPU_xTimerCreateStatic_core2( const char * const pcTimerName_core2,
                                      const TickType_t_core2 xTimerPeriodInTicks_core2,
                                      const UBaseType_t_core2 uxAutoReload_core2,
                                      void * const pvTimerID_core2,
                                      TimerCallbackFunction_t_core2 pxCallbackFunction_core2,
                                      StaticTimer_t_core2 * pxTimerBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
void * MPU_pvTimerGetTimerID_core2( const TimerHandle_t_core2 xTimer_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTimerSetTimerID_core2( TimerHandle_t_core2 xTimer_core2,
                           void * pvNewID_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTimerIsTimerActive_core2( TimerHandle_t_core2 xTimer_core2 ) FREERTOS_SYSTEM_CALL_core2;
TaskHandle_t_core2 MPU_xTimerGetTimerDaemonTaskHandle_core2( void ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTimerPendFunctionCall_core2( PendedFunction_t_core2 xFunctionToPend_core2,
                                       void * pvParameter1_core2,
                                       uint32_t ulParameter2_core2,
                                       TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
const char * MPU_pcTimerGetName_core2( TimerHandle_t_core2 xTimer_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vTimerSetReloadMode_core2( TimerHandle_t_core2 xTimer_core2,
                              const UBaseType_t_core2 uxAutoReload_core2 ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxTimerGetReloadMode_core2( TimerHandle_t_core2 xTimer_core2 ) FREERTOS_SYSTEM_CALL_core2;
TickType_t_core2 MPU_xTimerGetPeriod_core2( TimerHandle_t_core2 xTimer_core2 ) FREERTOS_SYSTEM_CALL_core2;
TickType_t_core2 MPU_xTimerGetExpiryTime_core2( TimerHandle_t_core2 xTimer_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTimerCreateTimerTask_core2( void ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xTimerGenericCommand_core2( TimerHandle_t_core2 xTimer_core2,
                                     const BaseType_t_core2 xCommandID_core2,
                                     const TickType_t_core2 xOptionalValue_core2,
                                     BaseType_t_core2 * const pxHigherPriorityTaskWoken_core2,
                                     const TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;

/* MPU versions of event_group.h API functions. */
EventGroupHandle_t_core2 MPU_xEventGroupCreate_core2( void ) FREERTOS_SYSTEM_CALL_core2;
EventGroupHandle_t_core2 MPU_xEventGroupCreateStatic_core2( StaticEventGroup_t_core2 * pxEventGroupBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
EventBits_t_core2 MPU_xEventGroupWaitBits_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                     const EventBits_t_core2 uxBitsToWaitFor_core2,
                                     const BaseType_t_core2 xClearOnExit_core2,
                                     const BaseType_t_core2 xWaitForAllBits_core2,
                                     TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
EventBits_t_core2 MPU_xEventGroupClearBits_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                      const EventBits_t_core2 uxBitsToClear_core2 ) FREERTOS_SYSTEM_CALL_core2;
EventBits_t_core2 MPU_xEventGroupSetBits_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                    const EventBits_t_core2 uxBitsToSet_core2 ) FREERTOS_SYSTEM_CALL_core2;
EventBits_t_core2 MPU_xEventGroupSync_core2( EventGroupHandle_t_core2 xEventGroup_core2,
                                 const EventBits_t_core2 uxBitsToSet_core2,
                                 const EventBits_t_core2 uxBitsToWaitFor_core2,
                                 TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vEventGroupDelete_core2( EventGroupHandle_t_core2 xEventGroup_core2 ) FREERTOS_SYSTEM_CALL_core2;
UBaseType_t_core2 MPU_uxEventGroupGetNumber_core2( void * xEventGroup_core2 ) FREERTOS_SYSTEM_CALL_core2;

/* MPU versions of message/stream_buffer_core2.h API functions. */
size_t MPU_xStreamBufferSend_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                              const void * pvTxData_core2,
                              size_t xDataLengthBytes_core2,
                              TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
size_t MPU_xStreamBufferReceive_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                 void * pvRxData_core2,
                                 size_t xBufferLengthBytes_core2,
                                 TickType_t_core2 xTicksToWait_core2 ) FREERTOS_SYSTEM_CALL_core2;
size_t MPU_xStreamBufferNextMessageLengthBytes_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
void MPU_vStreamBufferDelete_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xStreamBufferIsFull_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xStreamBufferIsEmpty_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xStreamBufferReset_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
size_t MPU_xStreamBufferSpacesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
size_t MPU_xStreamBufferBytesAvailable_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2 ) FREERTOS_SYSTEM_CALL_core2;
BaseType_t_core2 MPU_xStreamBufferSetTriggerLevel_core2( StreamBufferHandle_t_core2 xStreamBuffer_core2,
                                             size_t xTriggerLevel_core2 ) FREERTOS_SYSTEM_CALL_core2;
StreamBufferHandle_t_core2 MPU_xStreamBufferGenericCreate_core2( size_t xBufferSizeBytes_core2,
                                                     size_t xTriggerLevelBytes_core2,
                                                     BaseType_t_core2 xIsMessageBuffer_core2,
                                                     StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                                     StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 ) FREERTOS_SYSTEM_CALL_core2;
StreamBufferHandle_t_core2 MPU_xStreamBufferGenericCreateStatic_core2( size_t xBufferSizeBytes_core2,
                                                           size_t xTriggerLevelBytes_core2,
                                                           BaseType_t_core2 xIsMessageBuffer_core2,
                                                           uint8_t * const pucStreamBufferStorageArea_core2,
                                                           StaticStreamBuffer_t_core2 * const pxStaticStreamBuffer_core2,
                                                           StreamBufferCallbackFunction_t_core2 pxSendCompletedCallback_core2,
                                                           StreamBufferCallbackFunction_t_core2 pxReceiveCompletedCallback_core2 ) FREERTOS_SYSTEM_CALL_core2;



#endif /* MPU_PROTOTYPES_H */
