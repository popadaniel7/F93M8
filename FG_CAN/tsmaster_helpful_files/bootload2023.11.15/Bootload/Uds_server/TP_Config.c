/*
BSD 2-Clause License

*    Copyright (c) 2023, 
						    All rights reserved.
*    FileName:  crclib.c
*     Version:  v1.0
*        Date:  2023.04
* Description:  The TP layer initializes the configuration.

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
#include "TP_Config.h"

struct can_iso_tp_link_t link_tp;
struct can_iso_tp_init_t init_tp;
static uint8_t rx_buff[MAX_BUFF_LEN]={0};
//static uint8_t payload[MAX_BUFF_LEN]={0};


/**
 * @brief  Returns the DLC length.
 * @param  dlc: 
 * @return dlc:
 * @private
 */
static uint8_t dlc2len(uint8_t dlc)
{
	static const uint8_t dlc_len_table[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64 };
	return dlc_len_table[dlc & 0xf];
}

/**
 * @brief  TP information printing function.
 * @param  msg: 
 * @return None.
 * @private
 */
static void print_debug_info(const char* msg)
{
	
}

/**
 * @brief  The TP layer calls the CAN to drive the sending data function.
 * @param  link_src: 
								msg:
 * @return        0:
							other:
 * @private
 */
static int L_Data_request(can_iso_tp_link_t_p link_src, const struct CAN_msg* msg)
{
  uint32_t Tx_buffer[16]={0};
	msgPublic=*msg;
	for(uint8_t i=0;i<16;i++)
	{
		Tx_buffer[i]=msg->data[i*4+3];
		Tx_buffer[i]=(Tx_buffer[i]<<8)+msg->data[i*4+2];
		Tx_buffer[i]=(Tx_buffer[i]<<8)+msg->data[i*4+1];
		Tx_buffer[i]=(Tx_buffer[i]<<8)+msg->data[i*4];
	}
	
	CAN_TransmitReqMsgObj3_data(Tx_buffer,msg->dlc,msg->id.id);
	
return 0;
}

/**
 * @brief  The TP layer receives the data processing function.
 * @param      link: 
					payload[]:
							 size:
              error:
 * @return        0:
							other:
 * @private
 */
static void N_USData_indication(can_iso_tp_link_t_p link, const uint8_t payload[], uint32_t size, CAN_ISO_TP_RESAULT error)
{

	if (error)
	{
	
	}
	else
	{
		UdsServerRequestProcess(payload,size);
	}
	

}

/**
 * @brief  Tp-layer error handling functions.
 * @param      link: 
					payload[]:
              error:
 * @return        0:
							other:
 * @private
 */
static void N_USData_confirm(can_iso_tp_link_t_p link, const uint8_t payload[], uint32_t size, CAN_ISO_TP_RESAULT error)
{
	if (error)
	{
	
	}
	else
	{
	}
}

/**
 * @brief  The TP layer parameter initialization function.
 * @param     None.
 * @return    None.
 * @private
 */
 void init_for_all_links(void)
{
	
		memset(&link_tp, 0, sizeof(struct can_iso_tp_init_t));
		
		init_tp.rx_id.id = 0x755;//ECU_Rx
		init_tp.rx_id.isExt = 0;
		init_tp.tx_id.id = 0x756;//ECU_Tx
		init_tp.tx_id.isExt = 0;
		init_tp.funtion_id.id = 0x7ff;
		init_tp.tx_id.isExt = 0;
		init_tp.tx_id.isRemote=0;
	
		init_tp.N_As = 50;
		init_tp.N_Bs = 200;
		init_tp.N_Cs = 50;

		init_tp.N_Br = 50;
		init_tp.N_Ar = 50;
		init_tp.N_Cr =200;
		init_tp.N_WFTmax = 5;
		init_tp.L_Data_request = L_Data_request;
		init_tp.N_USData_indication = N_USData_indication;
		init_tp.N_USData_confirm = N_USData_confirm;
		init_tp.rx_buff = rx_buff;
		init_tp.rx_buff_len = MAX_BUFF_LEN;
		init_tp.TX_DLC = 15;
		init_tp.frame_pad = 0x77;
		init_tp.FC_BS = 0;
		init_tp.STmin = 0;
		init_tp.print_debug = print_debug_info;
		init_tp.rx_id.isCANFD = 1;
		init_tp.tx_id.isCANFD = 1;
	
}

