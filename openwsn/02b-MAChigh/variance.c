#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "openwsn.h"
#include "variance.h"

/*** Globals ***/
uint16_t var[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t last_var[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float mean[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//float M2[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float M2;
uint8_t num[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //number of readings taken

void updateVar(float rssi, uint8_t channel){ //online algorithm
  float fvar = ((float)var[channel])/100;
  num[channel]++;
  float delta=rssi-mean[channel];
  mean[channel]=mean[channel]+delta/num[channel];
  //M2[channel] = M2[channel] + delta*(rssi-mean[channel]);
  //var[channel]=M2[channel]/num[channel];
  M2 = fvar*(num[channel]-1) + delta*(rssi-mean[channel]); //causing problem,why?
  var[channel]=(uint16_t)(M2*100/num[channel]);
}

float getVarRatio(uint8_t channel){
  float ret;
  if(last_var[channel]==0){
      last_var[channel]=var[channel];
      return 1;
  }
  ret = (float)var[channel]/last_var[channel];
  last_var[channel]=var[channel];
  //var[channel]=0; //reset for next phase
  return ret;
}