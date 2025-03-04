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
extern uint32_t  UDS27_Timelock_count;
//extern uint32_t  UDS27_RN;

extern uint32_t Serive_Online;

void UDS_layer_pull(void);
#endif
