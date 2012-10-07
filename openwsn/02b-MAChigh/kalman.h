#ifndef __KALMAN_H
#define __KALMAN_H

#include "openwsn.h"

/* float version 
float kalman(float raw, float last, uint8_t index);
void getQ(float, uint8_t);
void getR(float, uint8_t); */

/* int version */
int16_t kalman(int16_t raw, int16_t last, uint8_t index);
void getQ(float, uint8_t);
void getR(float, uint8_t);

void adjustQ(uint8_t);
void adjustQall();
#endif