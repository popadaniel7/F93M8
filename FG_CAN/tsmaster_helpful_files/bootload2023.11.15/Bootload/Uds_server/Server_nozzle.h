#ifndef __SERVER_NOZZLE_H__
#define __SERVER_NOZZLE_H__

#include "types.h"
#include "can_iso_tp_private.h"
#include "UDS27_SA.h"

/******************UdsServerRequestProcess****************/
void UdsServerRequestProcess(const  uint8_t * payload,uint32_t size);
/******************UdsServerRequestProcess****************/

extern  can_iso_tp_link_t_p ServerLinkPoint;

/******************UdsServerRequestProcess****************/
extern int32_t  UDS27_Timelock_count;
extern uint32_t  UDS27_RN;

extern int32_t Serive_Online;

extern void UDS_init(void);
extern void UDS_server_poll(int32_t ms_add);
#endif
