#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ses.h"
#include "openwsn.h"
#include "noiseprobe.h"

// Globals

//smoothing factor
//const float alpha = 0.5;

/* Brown's Simple Exponential Smoothing (exponentially weighted moving average) */
int16_t brown_ses(float alpha, int16_t raw, int16_t last, uint8_t index){
  float ret = alpha*((float)raw/SCALAR)+(1-alpha)*((float)last/SCALAR);
  return (int16_t)(ret*SCALAR);
}

/* Brown's Linear (i.e., double) Exponential Smoothing */
int16_t brown_des(float alpha, int16_t raw, int16_t lastSt1, int16_t lastSt2, uint8_t index){
  float St1 = alpha*((float)raw/SCALAR) + (1-alpha)*((float)lastSt1/SCALAR);
  float St2 = alpha*St1 + (1-alpha)*((float)lastSt2/SCALAR);
  float ret = 2*St1 - St2 + (alpha/(1-alpha))*(St1 - St2);
  return (int16_t)(ret*SCALAR);
}