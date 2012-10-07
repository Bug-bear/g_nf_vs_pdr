/**
\brief This is a program which shows how to use the bsp modules for the board
       and leds.

Since the bsp modules for different platforms have the same declaration, you
can use this project with any platform.

\author Thomas Watteyne <watteyne@eecs.berkeley.edu>, February 2012
*/

#include "stdint.h"
#include "stdio.h"
// bsp modules required
#include "board.h"
#include "leds.h"

/**
\brief The program starts executing here.
*/
int mote_main(void) {
   uint16_t delay;
   
   board_init();
   
   leds_error_on();
   leds_error_off();
   leds_error_toggle();
   leds_radio_on();
   leds_radio_off();
   leds_radio_toggle();
   leds_sync_on();
   leds_sync_off();
   leds_sync_toggle();
   leds_debug_on();
   leds_debug_off();
   leds_debug_toggle();
   leds_sync_toggle();
   leds_circular_shift();
   
   while (1) {
      for (delay=0xffff;delay>0;delay--);
      leds_increment();
      for (delay=0xffff;delay>0;delay--);
      leds_circular_shift();
   }
}