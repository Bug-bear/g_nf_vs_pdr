#ifndef __SES_H
#define __SES_H

#include "openwsn.h"

int16_t brown_ses(float alpha, int16_t raw, int16_t last, uint8_t index);
int16_t brown_des(float alpha, int16_t raw, int16_t lastSt1, int16_t lastSt2, uint8_t index);
#endif