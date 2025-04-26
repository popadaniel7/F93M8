/*
BSD 2-Clause License

Copyright (c) 2023, LiangXenpeng
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef __SERVER_H__
#define __SERVER_H__
#include "tle989x.h"
#include "can_iso_tp_private.h"
#include "UDS27_SA.h"
#include "JumpToAPP.h"

#define BOOT 0


#define APP_FLAG   PMU->GPUDATA0.reg
#define APP_FLAG_EQUAL_BB  0XBB
#define BOOTLOAD_FLAG 	PMU->GPUDATA1.reg
#define BOOTLOAD_FLAG_EQUAL_DD  0XDD

#define APP_BOOT_RESET 	 PMU->GPUDATA2.reg
#define BOOT_APP_RESET 	 PMU->GPUDATA2.reg
#define APP_BOOT_RESET_EQUAL_EE  0xee
#define BOOT_APP_RESET_EQUAL_DD  0xdd
#define BOOT_EQUAL_CC            0xcc
#define APP_EQUAL_BB             0xbb

#define DSession_address_FLAG  ReservedRAM//     *((uint8_t *)0x18000000)
extern volatile uint32_t can_receive_counter;
extern uint8_t  SecurityAccess_STATION;
extern uint32_t UDS27_Timelock_count;
/******************UDS_SID****************/
typedef enum
{
	UDS_SID_DiagnosticSessionControl = 0x10,
	UDS_SID_EcuReset = 0x11,
	UDS_SID_ReadDataByIdentifier = 0x22,
	UDS_SID_READ_MEM_BY_ADDR = 0x23,
	UDS_SID_SecurityAccess = 0x27,
	UDS_SID_CommunicationControl = 0x28,
	UDS_SID_WriteDataByIdentifier = 0x2E,
	UDS_SID_IO_CONTROL = 0x2F,

	UDS_SID_RoutineControl = 0x31,
	UDS_SID_RequestDownload = 0x34,
	UDS_SID_REQ_UPLOAD = 0x35,
	UDS_SID_TransferData = 0x36,
	UDS_SID_RequestTransferExit = 0x37,
	UDS_SID_TesterPresent = 0x3E,
	UDS_SID_WRITE_MEM_BY_ADDR = 0x3D,
	UDS_SID_CountrolDTCSettingRequest=0x85
}
UDS_SID;
/******************UDS_SID****************/

/******************UDS_NRC****************/
typedef enum
{
	UDS_NRC_OK = 0,

	UDS_NRC_GENERAL_REJECT = 0x11,
	UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED = 0x12,
	UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT = 0x13,
	UDS_NRC_CONDITION_NOT_CORRECT = 0x22,
	UDS_NRC_REQUEST_SEQUENCE_ERROR = 0x24,
	UDS_NRC_REQUEST_OUT_OF_RANGE = 0x31,
	UDS_NRC_SECURITY_ACCESS_DENIED = 0x33,
	UDS_NRC_INVALIDKEY = 0x35,
	UDS_NRC_REQUIRE_TIMEDELY_EXPRIED = 0x37,
	UDS_NRC_FLASH_EraseNPage_ERROR = 0x72,
	UDS_NRC_ServiceNotSupportedInActiveSession = 0x7F
}
UDS_NRC;
/******************UDS_NRC****************/

/******************UdsServerDataType****************/
#define UDSMassageBufferLength 1026
typedef struct
{ 
	uint8_t 	*MsgDataPoint;
	uint32_t	 rxMsgLength;
	uint32_t	 txMsgLength;
	uint8_t 	 rxMsgData[UDSMassageBufferLength];
	uint8_t 	 txMsgData[UDSMassageBufferLength];

	UDS_SID 	 sid;			// service id
	uint16_t 	 did;			// data id
	uint32_t   memoryAddress;
  uint32_t   memorySize;
	
}UdsServerDataType;
/******************UdsServerDataType****************/

extern uint8_t  SecurityAccess_STATION;
extern  void app_jump(uint32_t user_jump_flag);



//VEHICLE
typedef struct
{
	uint32_t ECU_IMEI;
	uint8_t  VIN[17];
	uint8_t  VIN_occupancy;
	uint32_t Hardware_Version;
	uint32_t Software_Version;
	uint32_t ECU_ID_Y:16;
	uint32_t ECU_ID_M:8;
	uint32_t ECU_ID_D:8;

}VEHICLE_MAS;
static VEHICLE_MAS VEHICLE_massage={0x12345678,"TRUMMM1MXQZ123456",0x55,0x1111,0x2222,0x2022,0x12,0x19};
#endif
