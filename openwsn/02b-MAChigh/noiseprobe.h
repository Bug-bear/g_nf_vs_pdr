#ifndef __NOISEPROBE_H
#define __NOISEPROBE_H

/**
\addtogroup MAClow
\{
\addtogroup IEEE802154E
\{
*/

#include "openwsn.h"

//=========================== define ==========================================
enum {
  MASK_SIZE = 6,
  LOG2SAMPLES = 5, //this is the best a slot can cope
  ED_OFFSET = -91,
  SCALAR = 100
};

//=========================== typedef =========================================

//IEEE802.15.4E acknowledgement (ACK)
/*
typedef struct {
   uint8_t channel;
   uint8_t size;
} NF_CMD;
*/

//=========================== variables =======================================

//=========================== prototypes ======================================
// admin
void nf_init();
void startProbeSlot(uint8_t channel, uint8_t size);
void readEd();
void nf_endOfED(PORT_TIMER_WIDTH capturedTime);      //collect samples
void record();  
void sift(); //debug - show those whose rssi is above -91dBm

void sort();
//void sort(float[]); //float version
//void sort(uint8_t[]); //int version

void electFixed();  
void electThreshold();  

void notifyMe();
void notifyOther();
void reset_vars();
void reset_record();

uint8_t get_temp(); // debug only
#endif