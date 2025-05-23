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

#ifndef MPU_WRAPPERS_CORE0_H
#define MPU_WRAPPERS_CORE0_H

/* This file redefines API functions to be called through a wrapper macro, but
 * only for ports that are using the MPU. */
#if ( portUSING_MPU_WRAPPERS_core0 == 1 )

/* MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0 will be defined when this file is
 * included from queue.c or task_core0.c to prevent it from having an effect within
 * those files. */
    #ifndef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0

/*
 * Map standard (non MPU) API functions to equivalents that start
 * "MPU_".  This will cause the application code to call the MPU_
 * version, which wraps the non-MPU version with privilege promoting
 * then demoting code, so the kernel code always runs will full
 * privileges.
 */
//
///* Map standard task_core0.h API functions to the MPU equivalents. */
//        #define xTaskCreate_core0                            MPU_xTaskCreate_core0
//        #define xTaskCreateStatic_core0                      MPU_xTaskCreateStatic_core0
//        #define vTaskDelete_core0                            MPU_vTaskDelete_core0
//        #define vTaskDelay_core0                             MPU_vTaskDelay_core0
//        #define xTaskDelayUntil                        MPU_xTaskDelayUntil_core0
//        #define xTaskAbortDelay                        MPU_xTaskAbortDelay_core0
//        #define uxTaskPriorityGet_core0                      MPU_uxTaskPriorityGet_core0
//        #define eTaskGetState_core0                          MPU_eTaskGetState_core0
//        #define vTaskGetInfo                           MPU_vTaskGetInfo_core0
//        #define vTaskPrioritySet_core0                       MPU_vTaskPrioritySet_core0
//        #define vTaskSuspend_core0                           MPU_vTaskSuspend_core0
//        #define vTaskResume_core0                            MPU_vTaskResume_core0
//        #define vTaskSuspendAll_core0                        MPU_vTaskSuspendAll_core0
//        #define xTaskResumeAll_core0                         MPU_xTaskResumeAll_core0
//        #define xTaskGetTickCount_core0                      MPU_xTaskGetTickCount_core0
//        #define uxTaskGetNumberOfTasks_core0                 MPU_uxTaskGetNumberOfTasks_core0
//        #define pcTaskGetName_core0                          MPU_pcTaskGetName_core0
//        #define xTaskGetHandle_core0                         MPU_xTaskGetHandle_core0
//        #define uxTaskGetStackHighWaterMark            MPU_uxTaskGetStackHighWaterMark_core0
//        #define uxTaskGetStackHighWaterMark2           MPU_uxTaskGetStackHighWaterMark2_core0
//        #define vTaskSetApplicationTaskTag             MPU_vTaskSetApplicationTaskTag_core0
//        #define xTaskGetApplicationTaskTag             MPU_xTaskGetApplicationTaskTag_core0
//        #define vTaskSetThreadLocalStoragePointer      MPU_vTaskSetThreadLocalStoragePointer_core0
//        #define pvTaskGetThreadLocalStoragePointer     MPU_pvTaskGetThreadLocalStoragePointer_core0
//        #define xTaskCallApplicationTaskHook           MPU_xTaskCallApplicationTaskHook_core0
//        #define xTaskGetIdleTaskHandle                 MPU_xTaskGetIdleTaskHandle_core0
//        #define uxTaskGetSystemState_core0                   MPU_uxTaskGetSystemState_core0
//        #define vTaskList                              MPU_vTaskList_core0
//        #define vTaskGetRunTimeStats                   MPU_vTaskGetRunTimeStats_core0
//        #define ulTaskGetIdleRunTimeCounter            MPU_ulTaskGetIdleRunTimeCounter_core0
//        #define ulTaskGetIdleRunTimePercent            MPU_ulTaskGetIdleRunTimePercent_core0
//        #define xTaskGenericNotify                     MPU_xTaskGenericNotify_core0
//        #define xTaskGenericNotifyWait                 MPU_xTaskGenericNotifyWait_core0
//        #define ulTaskGenericNotifyTake                MPU_ulTaskGenericNotifyTake_core0
//        #define xTaskGenericNotifyStateClear           MPU_xTaskGenericNotifyStateClear_core0
//        #define ulTaskGenericNotifyValueClear          MPU_ulTaskGenericNotifyValueClear_core0
//        #define xTaskCatchUpTicks_core0                      MPU_xTaskCatchUpTicks_core0
//
//        #define xTaskGetCurrentTaskHandle              MPU_xTaskGetCurrentTaskHandle_core0
//        #define vTaskSetTimeOutState                   MPU_vTaskSetTimeOutState_core0
//        #define xTaskCheckForTimeOut                   MPU_xTaskCheckForTimeOut_core0
//        #define xTaskGetSchedulerState_core0                 MPU_xTaskGetSchedulerState_core0
//
///* Map standard queue.h API functions to the MPU equivalents. */
//        #define xQueueGenericSend                      MPU_xQueueGenericSend_core0
//        #define xQueueReceive_core0                          MPU_xQueueReceive_core0
//        #define xQueuePeek                             MPU_xQueuePeek_core0
//        #define xQueueSemaphoreTake                    MPU_xQueueSemaphoreTake_core0
//        #define uxQueueMessagesWaiting                 MPU_uxQueueMessagesWaiting_core0
//        #define uxQueueSpacesAvailable                 MPU_uxQueueSpacesAvailable_core0
//        #define vQueueDelete                           MPU_vQueueDelete_core0
//        #define xQueueCreateMutex                      MPU_xQueueCreateMutex_core0
//        #define xQueueCreateMutexStatic                MPU_xQueueCreateMutexStatic_core0
//        #define xQueueCreateCountingSemaphore          MPU_xQueueCreateCountingSemaphore_core0
//        #define xQueueCreateCountingSemaphoreStatic    MPU_xQueueCreateCountingSemaphoreStatic_core0
//        #define xQueueGetMutexHolder                   MPU_xQueueGetMutexHolder_core0
//        #define xQueueTakeMutexRecursive               MPU_xQueueTakeMutexRecursive_core0
//        #define xQueueGiveMutexRecursive               MPU_xQueueGiveMutexRecursive_core0
//        #define xQueueGenericCreate                    MPU_xQueueGenericCreate_core0
//        #define xQueueGenericCreateStatic              MPU_xQueueGenericCreateStatic_core0
//        #define xQueueCreateSet                        MPU_xQueueCreateSet_core0
//        #define xQueueAddToSet                         MPU_xQueueAddToSet_core0
//        #define xQueueRemoveFromSet                    MPU_xQueueRemoveFromSet_core0
//        #define xQueueSelectFromSet                    MPU_xQueueSelectFromSet_core0
//        #define xQueueGenericReset                     MPU_xQueueGenericReset_core0
//
//        #if ( configQUEUE_REGISTRY_SIZE_core0 > 0 )
//            #define vQueueAddToRegistry_core0                MPU_vQueueAddToRegistry_core0
//            #define vQueueUnregisterQueue              MPU_vQueueUnregisterQueue_core0
//            #define pcQueueGetName                     MPU_pcQueueGetName_core0
//        #endif
//
///* Map standard timer.h API functions to the MPU equivalents. */
//        #define pvTimerGetTimerID_core0                      MPU_pvTimerGetTimerID_core0
//        #define vTimerSetTimerID                       MPU_vTimerSetTimerID_core0
//        #define xTimerIsTimerActive_core0                    MPU_xTimerIsTimerActive_core0
//        #define xTimerGetTimerDaemonTaskHandle_core0         MPU_xTimerGetTimerDaemonTaskHandle_core0
//        #define pcTimerGetName_core0                         MPU_pcTimerGetName_core0
//        #define vTimerSetReloadMode_core0                    MPU_vTimerSetReloadMode_core0
//        #define uxTimerGetReloadMode_core0                   MPU_uxTimerGetReloadMode_core0
//        #define xTimerGetPeriod_core0                        MPU_xTimerGetPeriod_core0
//        #define xTimerGetExpiryTime_core0                    MPU_xTimerGetExpiryTime_core0
//        #define xTimerGenericCommand_core0                   MPU_xTimerGenericCommand_core0

/* Map standard event_group.h API functions to the MPU equivalents. */
//        #define xEventGroupCreate_core0                      MPU_xEventGroupCreate_core0
//        #define xEventGroupCreateStatic_core0                MPU_xEventGroupCreateStatic_core0
//        #define xEventGroupWaitBits_core0                    MPU_xEventGroupWaitBits_core0
//        #define xEventGroupClearBits_core0                   MPU_xEventGroupClearBits_core0
//        #define xEventGroupSetBits_core0                     MPU_xEventGroupSetBits_core0
//        #define xEventGroupSync_core0                        MPU_xEventGroupSync_core0
//        #define vEventGroupDelete_core0                      MPU_vEventGroupDelete_core0

/* Map standard message/stream_buffer_core0.h API functions to the MPU
 * equivalents. */
//        #define xStreamBufferSend_core0                      MPU_xStreamBufferSend_core0
//        #define xStreamBufferReceive_core0                   MPU_xStreamBufferReceive_core0
//        #define xStreamBufferNextMessageLengthBytes_core0    MPU_xStreamBufferNextMessageLengthBytes_core0
//        #define vStreamBufferDelete_core0                    MPU_vStreamBufferDelete_core0
//        #define xStreamBufferIsFull_core0                    MPU_xStreamBufferIsFull_core0
//        #define xStreamBufferIsEmpty_core0                   MPU_xStreamBufferIsEmpty_core0
//        #define xStreamBufferReset_core0                     MPU_xStreamBufferReset_core0
//        #define xStreamBufferSpacesAvailable_core0           MPU_xStreamBufferSpacesAvailable_core0
//        #define xStreamBufferBytesAvailable            MPU_xStreamBufferBytesAvailable_core0
//        #define xStreamBufferSetTriggerLevel           MPU_xStreamBufferSetTriggerLevel_core0
//        #define xStreamBufferGenericCreate_core0             MPU_xStreamBufferGenericCreate_core0
//        #define xStreamBufferGenericCreateStatic_core0       MPU_xStreamBufferGenericCreateStatic_core0


/* Remove the privileged function macro, but keep the PRIVILEGED_DATA_core0
 * macro so applications can place data in privileged access sections
 * (useful when using statically allocated objects). */
        #define PRIVILEGED_FUNCTION_core0
        #define PRIVILEGED_DATA_core0    __attribute__( ( section( "privileged_data" ) ) )
        #define FREERTOS_SYSTEM_CALL_core0

    #else /* MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0 */

/* Ensure API functions go in the privileged execution section. */
        #define PRIVILEGED_FUNCTION_core0     __attribute__( ( section( "privileged_functions" ) ) )
        #define PRIVILEGED_DATA_core0         __attribute__( ( section( "privileged_data" ) ) )
        #define FREERTOS_SYSTEM_CALL_core0    __attribute__( ( section( "freertos_system_calls" ) ) )

    #endif /* MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core0 */

#else /* portUSING_MPU_WRAPPERS_core0 */

    #define PRIVILEGED_FUNCTION_core0
    #define PRIVILEGED_DATA_core0
    #define FREERTOS_SYSTEM_CALL_core0

#endif /* portUSING_MPU_WRAPPERS_core0 */


#endif /* MPU_WRAPPERS_H */
