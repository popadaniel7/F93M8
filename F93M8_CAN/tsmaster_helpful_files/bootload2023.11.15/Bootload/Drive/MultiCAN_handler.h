#ifndef __MULTICAN_HANDLE_H__

#define  __MULTICAN_HANDLE_H__
#include "tle_device.h"
#include "types.h"
#include "main.h"
#include "can_iso_tp_private.h"
#include "server.h"

extern volatile uint32_t can_receive_counter;

/* init */
void MultiCAN_init(void);

extern bool CAN_TransmitReqMsgObj0(uint32 highdata, uint32 lowdata);
extern bool CAN_TransmitReqMsgObj1(uint32 highdata, uint32 lowdata);
extern bool CAN_TransmitReqMsgObj2(uint32 highdata, uint32 lowdata);
extern bool CAN_TransmitReqMsgObj3_data(uint32 *data,uint32 DLC,uint32 ID);

extern struct CAN_msg msgPublic;
extern can_iso_tp_link_t_p LinkTxPoint;
extern can_iso_tp_link_t_p LinkRxPoint;

extern uint8_t msg_Rx_exit;
extern uint8_t msgPublic_ok;
extern struct CAN_msg msg_Rx;
#endif 
