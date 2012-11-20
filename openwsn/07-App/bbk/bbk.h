#ifndef __BBK_H
#define __BBK_H

/**
\addtogroup App
\{
\addtogroup rT
\{
*/

//=========================== define ==========================================

//=========================== typedef =========================================
typedef struct {
  uint8_t       start;
    uint8_t       id;
    uint8_t       parent;
    uint8_t	  asn[5];   //either side
    uint8_t       channel;  //either side
    uint8_t       retry;  //now used for pkt rssi
    uint8_t       seq[4];   //Tx
    mask_t	  Smask;
    mask_t	  Rmask;
  uint8_t       end;
} demo_t;
//=========================== variables =======================================

//=========================== prototypes ======================================

void bbk_init();
void    construct_demo(demo_t*);
/**
\}
\}
*/

void singleChanStop();
void singleChanResume();
#endif
