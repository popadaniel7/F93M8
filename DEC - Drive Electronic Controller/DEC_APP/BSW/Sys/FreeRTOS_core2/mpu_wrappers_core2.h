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

#ifndef MPU_WRAPPERS_CORE2_H
#define MPU_WRAPPERS_CORE2_H

/* This file redefines API functions to be called through a wrapper macro, but
 * only for ports that are using the MPU. */
#if ( portUSING_MPU_WRAPPERS_core2 == 1 )

/* MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 will be defined when this file is
 * included from queue.c or task_core2.c to prevent it from having an effect within
 * those files. */
    #ifndef MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2

/*
 * Map standard (non MPU) API functions to equivalents that start
 * "MPU_".  This will cause the application code to call the MPU_
 * version, which wraps the non-MPU version with privilege promoting
 * then demoting code, so the kernel code always runs will full
 * privileges.
 */
//
///* Map standard task_core2.h API functions to the MPU equivalents. */
//        #define xTaskCreate_core2                            MPU_xTaskCreate_core2
//        #define xTaskCreateStatic_core2                      MPU_xTaskCreateStatic_core2
//        #define vTaskDelete_core2                            MPU_vTaskDelete_core2
//        #define vTaskDelay_core2                             MPU_vTaskDelay_core2
//        #define xTaskDelayUntil                        MPU_xTaskDelayUntil_core2
//        #define xTaskAbortDelay                        MPU_xTaskAbortDelay_core2
//        #define uxTaskPriorityGet_core2                      MPU_uxTaskPriorityGet_core2
//        #define eTaskGetState_core2                          MPU_eTaskGetState_core2
//        #define vTaskGetInfo                           MPU_vTaskGetInfo_core2
//        #define vTaskPrioritySet_core2                       MPU_vTaskPrioritySet_core2
//        #define vTaskSuspend_core2                           MPU_vTaskSuspend_core2
//        #define vTaskResume_core2                            MPU_vTaskResume_core2
//        #define vTaskSuspendAll_core2                        MPU_vTaskSuspendAll_core2
//        #define xTaskResumeAll_core2                         MPU_xTaskResumeAll_core2
//        #define xTaskGetTickCount_core2                      MPU_xTaskGetTickCount_core2
//        #define uxTaskGetNumberOfTasks_core2                 MPU_uxTaskGetNumberOfTasks_core2
//        #define pcTaskGetName_core2                          MPU_pcTaskGetName_core2
//        #define xTaskGetHandle_core2                         MPU_xTaskGetHandle_core2
//        #define uxTaskGetStackHighWaterMark            MPU_uxTaskGetStackHighWaterMark_core2
//        #define uxTaskGetStackHighWaterMark2           MPU_uxTaskGetStackHighWaterMark2_core2
//        #define vTaskSetApplicationTaskTag             MPU_vTaskSetApplicationTaskTag_core2
//        #define xTaskGetApplicationTaskTag             MPU_xTaskGetApplicationTaskTag_core2
//        #define vTaskSetThreadLocalStoragePointer      MPU_vTaskSetThreadLocalStoragePointer_core2
//        #define pvTaskGetThreadLocalStoragePointer     MPU_pvTaskGetThreadLocalStoragePointer_core2
//        #define xTaskCallApplicationTaskHook           MPU_xTaskCallApplicationTaskHook_core2
//        #define xTaskGetIdleTaskHandle                 MPU_xTaskGetIdleTaskHandle_core2
//        #define uxTaskGetSystemState_core2                   MPU_uxTaskGetSystemState_core2
//        #define vTaskList                              MPU_vTaskList_core2
//        #define vTaskGetRunTimeStats                   MPU_vTaskGetRunTimeStats_core2
//        #define ulTaskGetIdleRunTimeCounter            MPU_ulTaskGetIdleRunTimeCounter_core2
//        #define ulTaskGetIdleRunTimePercent            MPU_ulTaskGetIdleRunTimePercent_core2
//        #define xTaskGenericNotify                     MPU_xTaskGenericNotify_core2
//        #define xTaskGenericNotifyWait                 MPU_xTaskGenericNotifyWait_core2
//        #define ulTaskGenericNotifyTake                MPU_ulTaskGenericNotifyTake_core2
//        #define xTaskGenericNotifyStateClear           MPU_xTaskGenericNotifyStateClear_core2
//        #define ulTaskGenericNotifyValueClear          MPU_ulTaskGenericNotifyValueClear_core2
//        #define xTaskCatchUpTicks_core2                      MPU_xTaskCatchUpTicks_core2
//
//        #define xTaskGetCurrentTaskHandle              MPU_xTaskGetCurrentTaskHandle_core2
//        #define vTaskSetTimeOutState                   MPU_vTaskSetTimeOutState_core2
//        #define xTaskCheckForTimeOut                   MPU_xTaskCheckForTimeOut_core2
//        #define xTaskGetSchedulerState_core2                 MPU_xTaskGetSchedulerState_core2
//
///* Map standard queue.h API functions to the MPU equivalents. */
//        #define xQueueGenericSend                      MPU_xQueueGenericSend_core2
//        #define xQueueReceive_core2                          MPU_xQueueReceive_core2
//        #define xQueuePeek                             MPU_xQueuePeek_core2
//        #define xQueueSemaphoreTake                    MPU_xQueueSemaphoreTake_core2
//        #define uxQueueMessagesWaiting                 MPU_uxQueueMessagesWaiting_core2
//        #define uxQueueSpacesAvailable                 MPU_uxQueueSpacesAvailable_core2
//        #define vQueueDelete                           MPU_vQueueDelete_core2
//        #define xQueueCreateMutex                      MPU_xQueueCreateMutex_core2
//        #define xQueueCreateMutexStatic                MPU_xQueueCreateMutexStatic_core2
//        #define xQueueCreateCountingSemaphore          MPU_xQueueCreateCountingSemaphore_core2
//        #define xQueueCreateCountingSemaphoreStatic    MPU_xQueueCreateCountingSemaphoreStatic_core2
//        #define xQueueGetMutexHolder                   MPU_xQueueGetMutexHolder_core2
//        #define xQueueTakeMutexRecursive               MPU_xQueueTakeMutexRecursive_core2
//        #define xQueueGiveMutexRecursive               MPU_xQueueGiveMutexRecursive_core2
//        #define xQueueGenericCreate                    MPU_xQueueGenericCreate_core2
//        #define xQueueGenericCreateStatic              MPU_xQueueGenericCreateStatic_core2
//        #define xQueueCreateSet                        MPU_xQueueCreateSet_core2
//        #define xQueueAddToSet                         MPU_xQueueAddToSet_core2
//        #define xQueueRemoveFromSet                    MPU_xQueueRemoveFromSet_core2
//        #define xQueueSelectFromSet                    MPU_xQueueSelectFromSet_core2
//        #define xQueueGenericReset                     MPU_xQueueGenericReset_core2
//
//        #if ( configQUEUE_REGISTRY_SIZE_core2 > 0 )
//            #define vQueueAddToRegistry_core2                MPU_vQueueAddToRegistry_core2
//            #define vQueueUnregisterQueue              MPU_vQueueUnregisterQueue_core2
//            #define pcQueueGetName                     MPU_pcQueueGetName_core2
//        #endif
//
///* Map standard timer.h API functions to the MPU equivalents. */
//        #define pvTimerGetTimerID_core2                      MPU_pvTimerGetTimerID_core2
//        #define vTimerSetTimerID                       MPU_vTimerSetTimerID_core2
//        #define xTimerIsTimerActive_core2                    MPU_xTimerIsTimerActive_core2
//        #define xTimerGetTimerDaemonTaskHandle_core2         MPU_xTimerGetTimerDaemonTaskHandle_core2
//        #define pcTimerGetName_core2                         MPU_pcTimerGetName_core2
//        #define vTimerSetReloadMode_core2                    MPU_vTimerSetReloadMode_core2
//        #define uxTimerGetReloadMode_core2                   MPU_uxTimerGetReloadMode_core2
//        #define xTimerGetPeriod_core2                        MPU_xTimerGetPeriod_core2
//        #define xTimerGetExpiryTime_core2                    MPU_xTimerGetExpiryTime_core2
//        #define xTimerGenericCommand_core2                   MPU_xTimerGenericCommand_core2

/* Map standard event_group.h API functions to the MPU equivalents. */
//        #define xEventGroupCreate_core2                      MPU_xEventGroupCreate_core2
//        #define xEventGroupCreateStatic_core2                MPU_xEventGroupCreateStatic_core2
//        #define xEventGroupWaitBits_core2                    MPU_xEventGroupWaitBits_core2
//        #define xEventGroupClearBits_core2                   MPU_xEventGroupClearBits_core2
//        #define xEventGroupSetBits_core2                     MPU_xEventGroupSetBits_core2
//        #define xEventGroupSync_core2                        MPU_xEventGroupSync_core2
//        #define vEventGroupDelete_core2                      MPU_vEventGroupDelete_core2

/* Map standard message/stream_buffer_core2.h API functions to the MPU
 * equivalents. */
//        #define xStreamBufferSend_core2                      MPU_xStreamBufferSend_core2
//        #define xStreamBufferReceive_core2                   MPU_xStreamBufferReceive_core2
//        #define xStreamBufferNextMessageLengthBytes_core2    MPU_xStreamBufferNextMessageLengthBytes_core2
//        #define vStreamBufferDelete_core2                    MPU_vStreamBufferDelete_core2
//        #define xStreamBufferIsFull_core2                    MPU_xStreamBufferIsFull_core2
//        #define xStreamBufferIsEmpty_core2                   MPU_xStreamBufferIsEmpty_core2
//        #define xStreamBufferReset_core2                     MPU_xStreamBufferReset_core2
//        #define xStreamBufferSpacesAvailable_core2           MPU_xStreamBufferSpacesAvailable_core2
//        #define xStreamBufferBytesAvailable            MPU_xStreamBufferBytesAvailable_core2
//        #define xStreamBufferSetTriggerLevel           MPU_xStreamBufferSetTriggerLevel_core2
//        #define xStreamBufferGenericCreate_core2             MPU_xStreamBufferGenericCreate_core2
//        #define xStreamBufferGenericCreateStatic_core2       MPU_xStreamBufferGenericCreateStatic_core2


/* Remove the privileged function macro, but keep the PRIVILEGED_DATA_core2
 * macro so applications can place data in privileged access sections
 * (useful when using statically allocated objects). */
        #define PRIVILEGED_FUNCTION_core2
        #define PRIVILEGED_DATA_core2    __attribute__( ( section( "privileged_data" ) ) )
        #define FREERTOS_SYSTEM_CALL_core2

    #else /* MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 */

/* Ensure API functions go in the privileged execution section. */
        #define PRIVILEGED_FUNCTION_core2     __attribute__( ( section( "privileged_functions" ) ) )
        #define PRIVILEGED_DATA_core2         __attribute__( ( section( "privileged_data" ) ) )
        #define FREERTOS_SYSTEM_CALL_core2    __attribute__( ( section( "freertos_system_calls" ) ) )

    #endif /* MPU_WRAPPERS_INCLUDED_FROM_API_FILE_core2 */

#else /* portUSING_MPU_WRAPPERS_core2 */

    #define PRIVILEGED_FUNCTION_core2
    #define PRIVILEGED_DATA_core2
    #define FREERTOS_SYSTEM_CALL_core2

#endif /* portUSING_MPU_WRAPPERS_core2 */


#endif /* MPU_WRAPPERS_H */
