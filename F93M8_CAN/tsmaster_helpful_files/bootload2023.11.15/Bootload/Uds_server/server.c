/*
BSD 2-Clause License
*    Copyright (c) 2023, LiangXinpeng
						    All rights reserved.
*    FileName:  server.c
*     Version:  v1.0
*        Date:  2023.04
* Description:  Provides the UDS service function.The consumer can modify the 
								service function to meet different requirements.

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

#include "server.h"
#include "Server_nozzle.h"
#include "Config_UdsServer.h"
#include "flash.h"
#include "scu.h"
#include "system_tle989x.h"



/*START*******UDS Service******START*/
static void UDS_Serice_DiagnosticSessionControl(void);
static void UDS_Serice_EcuReset(void)__attribute__((noreturn));
static void UDS_Serice_ReadDataByIdentifier(void);
static void UDS_Serice_READ_MEM_BY_ADDR(void);
static void UDS_Serice_SecurityAccess(void);
static void UDS_Serice_CommunicationControl(void);
static void UDS_Serice_WriteDataByIdentifier(void);
static void UDS_Serice_IO_CONTROL(void);
static void UDS_Serice_RoutineControl(void);
static void UDS_Serice_RequestDownload(void);
static void UDS_Serice_REQ_UPLOAD(void);
static void UDS_Serice_TransferData(void);
static void UDS_Serice_RequestTransferExit(void);
static void UDS_Serice_TesterPresent(void);
static void UDS_Serice_WRITE_MEM_BY_ADDR(void);
static void UDS_Serice_CountrolDTCSettingRequest(void);
/*END********UDS Service********END*/
static void udsServer_sendResponse(UDS_NRC nrc);

/***********void UdsServerRequestProcess()***********/
static UdsServerDataType ServerData;

/**
 * @brief  UDS service interface
 * @param  payload: passing array pointers
					 size: size of the array
 * @return None.
 * @private
 */
void UdsServerRequestProcess(const  uint8_t * payload,uint32_t size)
{
	
		ServerData.rxMsgLength= size;
		//ServerData.MsgDataPoint=payload;
		ServerData.sid=payload[0];		
		if(ServerData.rxMsgLength>0)
		{
				for (uint32_t i = 0;i<ServerData.rxMsgLength;i++)
				{
					ServerData.rxMsgData[i]=payload[i];
			
				}	
		}
		else
		{  
		}
		
		switch(ServerData.sid)
		{
			case UDS_SID_DiagnosticSessionControl:
			UDS_Serice_DiagnosticSessionControl();
			break;
	
			case UDS_SID_EcuReset:
			UDS_Serice_EcuReset();
			break;

			case UDS_SID_ReadDataByIdentifier:
			UDS_Serice_ReadDataByIdentifier();
			break;
	
			case UDS_SID_READ_MEM_BY_ADDR:
			UDS_Serice_READ_MEM_BY_ADDR();
			break;
	
			case UDS_SID_SecurityAccess:
			UDS_Serice_SecurityAccess();
			break;
	
			case UDS_SID_CommunicationControl:
			UDS_Serice_CommunicationControl();
			break;
	
			case UDS_SID_WriteDataByIdentifier:
			UDS_Serice_WriteDataByIdentifier();
			break;

			case UDS_SID_IO_CONTROL:
			UDS_Serice_IO_CONTROL();
			break;

		 case UDS_SID_RoutineControl:
		 UDS_Serice_RoutineControl();
		 break;

		 case UDS_SID_RequestDownload:
		 UDS_Serice_RequestDownload();
		 break;
	
	case UDS_SID_REQ_UPLOAD:
		 UDS_Serice_REQ_UPLOAD();
		 break;
	
	case UDS_SID_TransferData:
		 UDS_Serice_TransferData();
		 break;

	
	case UDS_SID_RequestTransferExit:
		 UDS_Serice_RequestTransferExit();
		 break;
	
	case UDS_SID_TesterPresent:
		 UDS_Serice_TesterPresent();
		 break;
	
	case UDS_SID_WRITE_MEM_BY_ADDR:
		 UDS_Serice_WRITE_MEM_BY_ADDR();
		 break;
	
	case UDS_SID_CountrolDTCSettingRequest:
		UDS_Serice_CountrolDTCSettingRequest();
		 break;

	default:
		 udsServer_sendResponse(UDS_NRC_GENERAL_REJECT);
		 break;
	}
}
/***********void UdsServerRequestProcess()***********/


/***********void udsServer_sendResponse()***********/
can_iso_tp_link_t_p ServerLinkPoint=0;
/**
 * @brief  UDS service response.
 * @param  nrc: UDS_NRC
 * @return None.
 * @private
 */
static void udsServer_sendResponse(UDS_NRC nrc)
{
	if(nrc==UDS_NRC_OK)
	{
	   ServerData.txMsgData[0] |= 0x40;
	   iso_can_tp_N_USData_request(ServerLinkPoint,0,&ServerData.txMsgData[0],ServerData.txMsgLength);
	}
	else
	{

		 ServerData.txMsgData[0] = 0x7F;
		 ServerData.txMsgData[1] = ServerData.rxMsgData[0];
		 ServerData.txMsgData[2] = (uint8_t)nrc;
		 ServerData.txMsgLength = 3;
		 iso_can_tp_N_USData_request(ServerLinkPoint,0,&ServerData.txMsgData[0],ServerData.txMsgLength);
	}
}
/***********void udsServer_sendResponse()***********/

/**
 * @brief  UDS 10 service
 * @param  
 * @return None.
 * @private
 */
static void UDS_Serice_DiagnosticSessionControl(void)
{
	uint32_t DataLength =ServerData.rxMsgLength;
	if(0x02==DataLength)
	{
		if (0x01==ServerData.rxMsgData[1])
		{
			DSession_address_FLAG=0x00;
			ServerData.txMsgLength=0x06;
			ServerData.txMsgData[0]=ServerData.rxMsgData[0];
			ServerData.txMsgData[1]=ServerData.rxMsgData[1];
			ServerData.txMsgData[2]=0x01;
			ServerData.txMsgData[3]=0xF4;
			ServerData.txMsgData[4]=0x01;
			ServerData.txMsgData[5]=0xF4;
			SecurityAccess_STATION=0xf0;
			udsServer_sendResponse(UDS_NRC_OK);
		}
		else if (0x02==ServerData.rxMsgData[1])
		{
			if(0x22==DSession_address_FLAG)
			{
				DSession_address_FLAG=0x11;
				ServerData.txMsgLength=0x06;
				ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				ServerData.txMsgData[2]=0x01;
				ServerData.txMsgData[3]=0xF4;
				ServerData.txMsgData[4]=0x01;
				ServerData.txMsgData[5]=0xF4;
				SecurityAccess_STATION=0xf0;
				Serive_Online=Config_ServerOnline;
				udsServer_sendResponse(UDS_NRC_OK);
			}
			else
			{
				udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);
			}
	  }
		else if (0x03==ServerData.rxMsgData[1])
		{
			DSession_address_FLAG=0x22;
			ServerData.txMsgLength=0x06;
			ServerData.txMsgData[0]=ServerData.rxMsgData[0];
			ServerData.txMsgData[1]=ServerData.rxMsgData[1];
			ServerData.txMsgData[2]=0x01;
			ServerData.txMsgData[3]=0xF4;
			ServerData.txMsgData[4]=0x01;
			ServerData.txMsgData[5]=0xF4;
			Serive_Online=Config_ServerOnline;
			udsServer_sendResponse(UDS_NRC_OK);
		}
		else
		{
			udsServer_sendResponse(UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED);
		}
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT);
	}

}
/***********UDS_SID_DiagnosticSessionControl  0x10  Server***********/

/***********UDS_Serice_EcuReset  0x11  Server***********/
/**
 * @brief  UDS 11 service. ECU restart.
 * @param  
 * @return None.
 * @private
 */
 static  void UDS_Serice_EcuReset(void) 
{	
	BOOT_APP_RESET=BOOT_APP_RESET_EQUAL_DD;
	if(BOOT_APP_RESET==BOOT_APP_RESET_EQUAL_DD)
	{
	__NVIC_SystemReset();	
	}
	else
	{}
	
}

/***********UDS_Serice_EcuReset  0x11  Server***********/

/***********UDS_Serice_ReadDataByIdentifier  0x22  Server***********/
/**
 * @brief  UDS 22 service. 
 * @param  
 * @return None.
 * @private
 */
static void UDS_Serice_ReadDataByIdentifier(void)
{

}
/***********UDS_Serice_ReadDataByIdentifier  0x22  Server***********/

/***********UDS_Serice_READ_MEM_BY_ADDR  0x23  Server***********/
/**
 * @brief  UDS 23 service
 * @param  
 * @return None.
 * @private
 */	
static void UDS_Serice_READ_MEM_BY_ADDR(void)
{

}
/***********UDS_Serice_READ_MEM_BY_ADDR  0x23  Server***********/

/***********UDS_Serice_SecurityAccess  0x27  Server***********/
/**
 * @brief  UDS 27 service
 * @param  
 * @return None.
 * @private
 */	
int32_t UDS27_Timelock_count=Config_UDS27_Timelock_count;
static uint32_t Timelock_error_count=0;
uint8_t SecurityAccess_STATION=0xf0;
static void UDS_Serice_SecurityAccess(void)
{
	if( DSession_address_FLAG==0x11)
	{
		if(UDS27_Timelock_count<=0)
		{
			if(ServerData.rxMsgData[1]==0x01&&SecurityAccess_STATION==0xf0&&ServerData.rxMsgLength==2)        //使能对控制报文的发送与接收
			{
				ServerData.txMsgLength=ACCESS_NUM+2;
				ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				Creating_Seed(UDS_SericeAccess_Seed,4);

				for(uint8_t i=0;i<ACCESS_NUM;i++)
				{
					ServerData.txMsgData[i+2]=UDS_SericeAccess_Seed[i];
				}
				udsServer_sendResponse(UDS_NRC_OK);
				SecurityAccess_STATION=0xe0;
			}
			else if(ServerData.rxMsgData[1]==0x01&&SecurityAccess_STATION==0xe0&&ServerData.rxMsgLength==2)
			{
				ServerData.txMsgLength=ACCESS_NUM+2;
				ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				Creating_Seed(UDS_SericeAccess_Seed,4);
				for(uint8_t i=0;i<ACCESS_NUM;i++)
				{
					ServerData.txMsgData[i+2]=UDS_SericeAccess_Seed[i];
				}
				udsServer_sendResponse(UDS_NRC_OK);
			}
			else if((ServerData.rxMsgData[1]==0x02&&SecurityAccess_STATION==0xe0&&ServerData.rxMsgLength>2)||
						(ServerData.rxMsgData[1]==0x02&&SecurityAccess_STATION==0xd0&&ServerData.rxMsgLength>2))
			{
				PasswordGenerator(&UDS_SericeAccess_Seed[0],&UDS_SericeAccess_Key[0],ACCESS_NUM);
				if(!SecurityAccess_unlock(&ServerData.rxMsgData[2],&UDS_SericeAccess_Key[0],ACCESS_NUM))
				{
					ServerData.txMsgLength=0x02;
					ServerData.txMsgData[0]=ServerData.rxMsgData[0];
					ServerData.txMsgData[1]=ServerData.rxMsgData[1];
					udsServer_sendResponse(UDS_NRC_OK);
					SecurityAccess_STATION=0xd0;
				}
				else
				{   
					Timelock_error_count++;
					if(Timelock_error_count>2)
					{
						Timelock_error_count=0;
						UDS27_Timelock_count=5000;
					}
					if(SecurityAccess_STATION==0xc0)
					{
						Timelock_error_count=0;
					}
					SecurityAccess_STATION=0xf0;
					udsServer_sendResponse(UDS_NRC_INVALIDKEY);
				}
			}
			else
			{
				udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT);
			}
		}
		else
		{
			udsServer_sendResponse(UDS_NRC_REQUIRE_TIMEDELY_EXPRIED);
		}
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);
	}
}
/***********UDS_Serice_SecurityAccess  0x27  Server***********/

/***********UDS_Serice_CommunicationControl  0x28  Server***********/	
/**
 * @brief  UDS 28 service
 * @param  
 * @return None.
 * @private
 */	
static void UDS_Serice_CommunicationControl(void)
{
	if(DSession_address_FLAG==0x22)
	{
		if(ServerData.rxMsgData[1]==0x00)        //Enable the sending and receiving of control packets
		{
			udsServer_sendResponse(UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED);
		}
		else if(ServerData.rxMsgData[1]==0x01)  //Enable the reception of corresponding control packets but suppress their transmission
		{
			udsServer_sendResponse(UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED);
		}
		else if(ServerData.rxMsgData[1]==0x02)  //Enable the transmission of corresponding control packets but suppress their reception
		{
			udsServer_sendResponse(UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED);
		}
		else if(ServerData.rxMsgData[1]==0x03&&ServerData.rxMsgData[2]==0x01)  //The reception and transmission of corresponding packets are suppressed
		{
			ServerData.txMsgLength=0x03;
			ServerData.txMsgData[0]=ServerData.rxMsgData[0];
			ServerData.txMsgData[1]=ServerData.rxMsgData[1];
			ServerData.txMsgData[2]=ServerData.rxMsgData[2];
			udsServer_sendResponse(UDS_NRC_OK);
		}
		else if(ServerData.rxMsgData[1]==0x04)  //Indicates that the corresponding node switches to diagnostic mode
		{
			udsServer_sendResponse(UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED);
		}
		else if(ServerData.rxMsgData[1]==0x05) //Indicates that the corresponding node enters the painting mode
		{
		}
		else
		{
			udsServer_sendResponse(UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED);
		}
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);
	}
}
/***********UDS_Serice_CommunicationControl  0x28  Server***********/	

/***********UDS_Serice_WriteDataByIdentifier  0x2E  Server***********/	
/**
 * @brief  UDS 2E service
 * @param  
 * @return None.
 * @private
 */	
static void UDS_Serice_WriteDataByIdentifier(void)//2e
{
	if(DSession_address_FLAG==0x11&&SecurityAccess_STATION==0xd0)
	{
	   if(ServerData.rxMsgData[1]==0xF1&ServerData.rxMsgData[2]==0x86)//session
	   {
		   ServerData.txMsgLength=0x04;
		   ServerData.txMsgData[0]=ServerData.rxMsgData[0];
		   ServerData.txMsgData[1]=ServerData.rxMsgData[1];
		   ServerData.txMsgData[2]=ServerData.rxMsgData[2];
		   udsServer_sendResponse(UDS_NRC_OK);
	   }
	   else if(ServerData.rxMsgData[1]==0xF1&ServerData.rxMsgData[2]==0x8c)//ECU序列
	   {
		   if(ServerData.rxMsgLength>=7 )
		   {
			   ServerData.txMsgLength=0x03;
			   ServerData.txMsgData[0]=ServerData.rxMsgData[0];
			   ServerData.txMsgData[1]=ServerData.rxMsgData[1];
			   ServerData.txMsgData[2]=ServerData.rxMsgData[2];
			   VEHICLE_massage.ECU_IMEI=0;
			   for(int i=0;i<4;i++)
			   {
				   if(i!=0)
				   {
					   VEHICLE_massage.ECU_IMEI<<=8;
				   }
					   VEHICLE_massage.ECU_IMEI|=ServerData.rxMsgData[3+i];
			   }
			   udsServer_sendResponse(UDS_NRC_OK);
		   }
		   else
		   {
			   udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT );
		   }
	   }
	   else if(ServerData.rxMsgData[1]==0xF1&ServerData.rxMsgData[2]==0x90)//VIN码
		 {
			  if( ServerData.rxMsgLength>=20)
			  { 
					ServerData.txMsgLength=0x03;
				  ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				  ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				  ServerData.txMsgData[2]=ServerData.rxMsgData[2];
				  for(int i=0;i<17;i++)
				  {
						VEHICLE_massage.VIN[i]=ServerData.rxMsgData[3+i];
				  }
				    udsServer_sendResponse(UDS_NRC_OK);
			  }
			  else
			  {
				  udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT );
			  }
	   }
	   else if(ServerData.rxMsgData[1]==0xF1&ServerData.rxMsgData[2]==0x93)//供应商硬件版本号
	   {
				if(ServerData.rxMsgLength>=7 )
			  {
					ServerData.txMsgLength=0x03;
				  ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				  ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				  ServerData.txMsgData[2]=ServerData.rxMsgData[2];
				  VEHICLE_massage.Hardware_Version=0;
				  for(int i=0;i<4;i++)
				  {
					  if(i!=0)
					  {
							VEHICLE_massage.Hardware_Version<<=8;
					  }
						  VEHICLE_massage.Hardware_Version|=ServerData.rxMsgData[3+i];
				  }
				  udsServer_sendResponse(UDS_NRC_OK);
			  }
			  else
			  {
				  udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT );

			  }
	   }
	   else if(ServerData.rxMsgData[1]==0xF1&ServerData.rxMsgData[2]==0x95)//供应商软件版本号
	   {
				if(ServerData.rxMsgLength>=7 )
			  {
				  ServerData.txMsgLength=0x03;
				  ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				  ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				  ServerData.txMsgData[2]=ServerData.rxMsgData[2];
				  VEHICLE_massage.Software_Version=0;
				  for(int i=0;i<4;i++)
					{
						if(i!=0)
						{
							VEHICLE_massage.Software_Version<<=8;
						}
						VEHICLE_massage.Software_Version|=ServerData.rxMsgData[3+i];
					}
				   udsServer_sendResponse(UDS_NRC_OK);
			   }
			   else
			   {
				   udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT );
			   }
	   }
	   else if(ServerData.rxMsgData[1]==0xF1&ServerData.rxMsgData[2]==0x9d)//ecu安装日期
	   {
			 if(ServerData.rxMsgLength>=7 )
			 {
				 ServerData.txMsgLength=0x03;
				 ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				 ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				 ServerData.txMsgData[2]=ServerData.rxMsgData[2];
				 VEHICLE_massage.ECU_ID_Y=0;
				 VEHICLE_massage.ECU_ID_M=0;
				 VEHICLE_massage.ECU_ID_D=0;
				 VEHICLE_massage.ECU_ID_Y|=ServerData.rxMsgData[3];
				 VEHICLE_massage.ECU_ID_Y<<=8;
				 VEHICLE_massage.ECU_ID_Y|=ServerData.rxMsgData[4];
				 VEHICLE_massage.ECU_ID_M=ServerData.rxMsgData[5];
				 VEHICLE_massage.ECU_ID_D=ServerData.rxMsgData[6];
				 udsServer_sendResponse(UDS_NRC_OK);
			  }
			  else
			  {
				  udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT );
			  }
	   }
	   else
	   {
		   udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);//条件不正确
	   }

	}
	else
	{
		udsServer_sendResponse(UDS_NRC_REQUEST_SEQUENCE_ERROR );
	}

}
/***********UDS_Serice_WriteDataByIdentifier  0x2E  Server***********/

/***********UDS_Serice_IO_CONTROL  0x2F  Server***********/
/**
 * @brief  UDS 2F service
 * @param  
 * @return None.
 * @private
 */	
static void UDS_Serice_IO_CONTROL(void)
{

}
/***********UDS_Serice_IO_CONTROL  0x2F  Server***********/

/***********UDS_Serice_RoutineControl  0x31  Server***********/
/**
 * @brief  UDS 31 service
 * @param  
 * @return None.
 * @private
 */	



static void UDS_Serice_RoutineControl(void)
{ 
	uint32_t checksum_R=0;
	uint32_t checksum=0;
	uint8_t Write_the_Bootload_Information[128]={0};
	user_nvm_page_write_t user_nvm_page_write_Data={0};
	user_nvm_page_write_Data.data=&Write_the_Bootload_Information[0];
	user_nvm_page_write_Data.nbyte=0x80;//128
	user_nvm_page_write_Data.options=1;
	checksum=crc32((uint8_t *)ServerData.memoryAddress_CheckBegain,ServerData.memorySize);
	checksum_R=ServerData.rxMsgData[4];
	checksum_R=(checksum_R<<8)|ServerData.rxMsgData[5];
	checksum_R=(checksum_R<<8)|ServerData.rxMsgData[6];
	checksum_R=(checksum_R<<8)|ServerData.rxMsgData[7];
  if(DSession_address_FLAG==0x11&&SecurityAccess_STATION==0xd0&&checksum==checksum_R)
	{
		Write_the_Bootload_Information[0]=APP_EXISTS;
		Write_the_Bootload_Information[4]=(uint8_t)checksum;
		Write_the_Bootload_Information[5]=(uint8_t)(checksum>>8);
		Write_the_Bootload_Information[6]=(uint8_t)(checksum>>16);
		Write_the_Bootload_Information[7]=(uint8_t)(checksum>>24);
		Write_the_Bootload_Information[8]=(uint8_t)(ServerData.memoryAddress_CheckBegain);
		Write_the_Bootload_Information[9]=(uint8_t)(ServerData.memoryAddress_CheckBegain>>8);
		Write_the_Bootload_Information[10]=(uint8_t)(ServerData.memoryAddress_CheckBegain>>16);
		Write_the_Bootload_Information[11]=(uint8_t)(ServerData.memoryAddress_CheckBegain>>24);
		Write_the_Bootload_Information[12]=(uint8_t)(ServerData.memorySize);
		Write_the_Bootload_Information[13]=(uint8_t)(ServerData.memorySize>>8);
		Write_the_Bootload_Information[14]=(uint8_t)(ServerData.memorySize>>16);
		Write_the_Bootload_Information[15]=(uint8_t)(ServerData.memorySize>>24);
		
		__disable_irq();
		user_nvm_page_write(BOOTLOAD_INFORMATION_ADDRESS,&user_nvm_page_write_Data);
		__enable_irq();
		
		ServerData.txMsgLength=0x04;
		ServerData.txMsgData[0]=ServerData.rxMsgData[0];
		ServerData.txMsgData[1]=ServerData.rxMsgData[1];
		ServerData.txMsgData[2]=ServerData.rxMsgData[2];
		ServerData.txMsgData[3]=ServerData.rxMsgData[3];
		udsServer_sendResponse(UDS_NRC_OK);
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);
	}

}
/***********UDS_Serice_RoutineControl  0x31  Server***********/

/***********UDS_Serice_RequestDownload  0x34  Server***********/
/**
 * @brief  UDS 34 service
 * @param  
 * @return None.
 * @private
 */	

static void UDS_Serice_RequestDownload(void)
{
	
	uint32_t ADD=0,ADD_SIZE=0;
	uint8_t Clear_the_Bootload_Information[128]={0};
	user_nvm_page_write_t user_nvm_page_write_Data={0};
	user_nvm_page_write_Data.data=&Clear_the_Bootload_Information[0];
	user_nvm_page_write_Data.nbyte=0x80;//128
	user_nvm_page_write_Data.options=1;
	__disable_irq();
	user_nvm_page_write(BOOTLOAD_INFORMATION_ADDRESS,&user_nvm_page_write_Data);
	__enable_irq();// reenable suspended interrupts 	
	
	if(SecurityAccess_STATION==0xd0&&DSession_address_FLAG==0x11)
	{

		ADD=ServerData.rxMsgData[3];
		ADD=(ADD<<8)|ServerData.rxMsgData[4];
		ADD=(ADD<<8)|ServerData.rxMsgData[5];
		ADD=(ADD<<8)|ServerData.rxMsgData[6];
		ServerData.memoryAddress=ADD;
		ServerData.memoryAddress_CheckBegain=ADD;
	
		ADD_SIZE=ServerData.rxMsgData[7];
		ADD_SIZE=(ADD_SIZE<<8)|ServerData.rxMsgData[8];
		ADD_SIZE=(ADD_SIZE<<8)|ServerData.rxMsgData[9];
		ADD_SIZE=(ADD_SIZE<<8)|ServerData.rxMsgData[10];
		ServerData.memorySize=ADD_SIZE;
		
		
		ServerData.txMsgLength=0x04;
		ServerData.txMsgData[0]=ServerData.rxMsgData[0];
		ServerData.txMsgData[1]=0x20;
		ServerData.txMsgData[2]=0x04;
		ServerData.txMsgData[3]=0x02;
		udsServer_sendResponse(UDS_NRC_OK);
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT);
	}
}
/***********UDS_Serice_RequestDownload  0x34  Server***********/

/***********UDS_Serice_REQ_UPLOAD  0x35  Server***********/
/**
 * @brief  UDS 35 service
 * @param  
 * @return None.
 * @private
 */
static void UDS_Serice_REQ_UPLOAD(void)
{

}
/***********UDS_Serice_REQ_UPLOAD  0x35  Server***********/

/***********UDS_Serice_TransferData  0x36  Server***********/
/**
 * @brief  UDS 36 service
 * @param  
 * @return None.
 * @private
 */	
static int32_t flag=3;
static void UDS_Serice_TransferData(void)
{
	int32_t  temp=0;
	user_nvm_page_write_t user_nvm_page_write_Data={0};
	
	if(SecurityAccess_STATION==0xd0&&DSession_address_FLAG==0x11)
	{
		if(ServerData.memoryAddress>=DownloadStartAddress)
		{
			user_nvm_page_write_Data.data=&ServerData.rxMsgData[2];
			user_nvm_page_write_Data.nbyte=0x80;//128
			user_nvm_page_write_Data.options=1;
		
			for(int i=0;i<8;i++)//8*128=1024
			{
			 __disable_irq(); // suspend and remember all enabled interrupts 
       flag=user_nvm_page_write(ServerData.memoryAddress,&user_nvm_page_write_Data);
			 ServerData.memoryAddress=ServerData.memoryAddress+128;//+128
			 user_nvm_page_write_Data.data=user_nvm_page_write_Data.data+128;//+128
				
			 if(flag>=0)
			 {
				temp++;
			 }
			 __enable_irq();// reenable suspended interrupts 		
			}
			 
			if(temp==8)
			{
				ServerData.txMsgLength=0x02;
				ServerData.txMsgData[0]=ServerData.rxMsgData[0];
				ServerData.txMsgData[1]=ServerData.rxMsgData[1];
				udsServer_sendResponse(UDS_NRC_OK); 
				
			}
			else
			{
				udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT);
			}
		}
		else
		{
			udsServer_sendResponse(UDS_NRC_INCORRECT_MESSAGE_LENGTH_OR_INVALID_FORMAT);
		}
	}
	else
	{
	
	}
}
/***********UDS_Serice_TransferData  0x36  Server***********/

/***********UDS_Serice_RequestTransferExit  0x37  Server***********/
/**
 * @brief  UDS 37 service
 * @param  
 * @return None.
 * @private
 */	
static void UDS_Serice_RequestTransferExit(void)
{
	if(SecurityAccess_STATION==0xd0&&DSession_address_FLAG==0x11)
	{
		ServerData.txMsgLength=0x01;
		ServerData.txMsgData[0]=ServerData.rxMsgData[0];
		udsServer_sendResponse(UDS_NRC_OK);

//			if(APP_FLAG==APP_FLAG_EQUAL_BB)//RESET-BOOT_JUMP_APP
//		{							
//			BOOTLOAD_FLAG=0X11;
//			APP_BOOT_RESET=0x11;			
//		}			
//		if(APP_FLAG!=APP_FLAG_EQUAL_BB)//RESET-APP_RETURN_BOOTLOADER
//		{			
//			BOOTLOAD_FLAG =BOOTLOAD_FLAG_EQUAL_DD;
//			APP_FLAG=0X11;					
//			APP_BOOT_RESET=0x11;			
//		}
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);
	}

}
/***********UDS_Serice_RequestTransferExit  0x37  Server***********/

/***********UDS_Serice_TesterPresent  0x3E  Server***********/
/**
 * @brief  UDS 3E service
 * @param  
 * @return None.
 * @private
 */	
int32_t Serive_Online=Config_ServerOnline;
static void UDS_Serice_TesterPresent(void)
{
	if (0x3E==ServerData.rxMsgData[0])
	{
		Serive_Online=Config_ServerOnline;
		ServerData.txMsgLength=0x02;
		ServerData.txMsgData[0]=ServerData.rxMsgData[0];
		ServerData.txMsgData[1]=ServerData.rxMsgData[1];
		udsServer_sendResponse(UDS_NRC_OK); 
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);
	}

}
/***********UDS_Serice_TesterPresent  0x3E  Server***********/

/***********UDS_Serice_WRITE_MEM_BY_ADDR  0x3D  Server***********/
/**
 * @brief  UDS 3D service
 * @param  
 * @return None.
 * @private
 */	
static void UDS_Serice_WRITE_MEM_BY_ADDR(void)
{

}
/***********UDS_Serice_WRITE_MEM_BY_ADDR  0x3D  Server***********/	
	
/***********UDS_Serice_CountrolDTCSettingRequest  0x85  Server***********/
/**
 * @brief  UDS 85 service countrol DTC setting request
 * @param  None.
 * @return None.
 * @private
 */
static void UDS_Serice_CountrolDTCSettingRequest(void)
{
	if(DSession_address_FLAG==0x22)
	{
		if(ServerData.rxMsgData[1]==0x01)
		{
			ServerData.txMsgData[0]=ServerData.rxMsgData[0];
			ServerData.txMsgData[1]=ServerData.rxMsgData[1];
			ServerData.txMsgLength=ServerData.rxMsgLength;
			udsServer_sendResponse(UDS_NRC_OK);
		}
		else if(ServerData.rxMsgData[1]==0x02)
		{
			ServerData.txMsgData[0]=ServerData.rxMsgData[0];
			ServerData.txMsgData[1]=ServerData.rxMsgData[1];
			ServerData.txMsgLength=ServerData.rxMsgLength;
			udsServer_sendResponse(UDS_NRC_OK);
		}
		else
		{
			udsServer_sendResponse(UDS_NRC_SUB_FUNCTION_NOT_SUPPORTED);
		}
	}
	else
	{
		udsServer_sendResponse(UDS_NRC_CONDITION_NOT_CORRECT);
	}

}
/***********UDS_Serice_CountrolDTCSettingRequest  0x85  Server***********/

/**
 * @brief  	UDS layer initialization function.
 * @param  	None.
 * @return 	None.
 * @private
 */

void UDS_init(void)
{
	APP_BOOT_RESET=BOOT_EQUAL_CC;
			
	/* Entering a programming session */
	SecurityAccess_STATION=0xf0;
			
	/* Secure access to unlock */
	DSession_address_FLAG=0x22;	
			
	/* 3E Service Online */
	Serive_Online=Config_ServerOnline;
			
	UDS27_Timelock_count=0;
}


/**
 * @brief   UDS layer time parameter update function.
 * @param   ms_add: Time of update.
 * @return  None.
 * @private
 */

void UDS_server_poll(int32_t ms_add)
{
	  /* Service power on download delay and key error delay */
		if(UDS27_Timelock_count>0)
		{
			UDS27_Timelock_count=UDS27_Timelock_count-ms_add;
		}
	
		/* Service uptime */		
		if(Serive_Online>0)
		{
			Serive_Online=Serive_Online-ms_add;
		}
		else
		{
			DSession_address_FLAG=0x00;
			BOOT_APP_RESET=BOOT_APP_RESET_EQUAL_DD;		
			__NVIC_SystemReset();
		}
}
