#ifndef __BIT2BOOL_H
#define __BIT2BOOL_H

#include "openwsn.h"

/**
\addtogroup MAChigh
\{
\addtogroup LinkCost
\{
*/

void convert(uint16_t bit, bool* boolArray);//calculate link cost based on ETX.
//uint8_t linkcost_calcRSSI();
//other metrics can be used.

void convert3(uint16_t bitA, uint16_t bitB, bool* boolArray);

#endif
