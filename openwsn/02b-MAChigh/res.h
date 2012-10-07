#ifndef __RES_H
#define __RES_H

/**
\addtogroup MAChigh
\{
\addtogroup RES
\{
*/

//=========================== define ==========================================

//=========================== typedef =========================================
/* piggy601: rpt struct */
typedef struct {
  uint8_t  flag;
  uint8_t  id;
  uint8_t  updates[2];
} rpt_t;
//=========================== variables =======================================

//=========================== prototypes ======================================

void    res_init();
bool    debugPrint_myDAGrank();
// from upper layer
error_t res_send(OpenQueueEntry_t *msg);
// from lower layer
void    task_resNotifSendDone();
void    res_sendDone(OpenQueueEntry_t* msg, error_t error);
void    task_resNotifReceive();
void    res_receive(OpenQueueEntry_t* msg);

/**
\}
\}
*/

#endif