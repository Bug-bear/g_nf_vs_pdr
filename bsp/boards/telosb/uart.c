/**
\brief TelosB-specific definition of the "uart" bsp module.

\author Thomas Watteyne <watteyne@eecs.berkeley.edu>, February 2012.
*/

#include "msp430f1611.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "uart.h"

//=========================== defines =========================================

//=========================== variables =======================================

typedef struct {
   uart_tx_cbt txCb;
   uart_rx_cbt rxCb;
} uart_vars_t;

uart_vars_t uart_vars;

//=========================== prototypes ======================================

//=========================== public ==========================================

void uart_init() {
   P3SEL                    |=  0xc0;            // P3.6,7 = UART1TX/RX
   
   UCTL1                     =  SWRST;           // hold UART1 module in reset
   UCTL1                    |=  CHAR;            // 8-bit character
   
   //9600 baud, clocked from 32kHz ACLK
   UTCTL1                   |=  SSEL0;           // clocking from ACLK
   UBR01                     =  0x03;            // 32768/9600 = 3.41
   UBR11                     =  0x00;            //
   UMCTL1                    =  0x4A;            // modulation
   
   ME2                      |=  UTXE1 + URXE1;   // enable UART1 TX/RX
   UCTL1                    &= ~SWRST;           // clear UART1 reset bit
}

void uart_setCallbacks(uart_tx_cbt txCb, uart_rx_cbt rxCb) {
   uart_vars.txCb = txCb;
   uart_vars.rxCb = rxCb;
}

void    uart_enableInterrupts(){
  IE2 |=  (URXIE1 | UTXIE1);  
}

void    uart_disableInterrupts(){
  IE2 &= ~(URXIE1 | UTXIE1);
}

void    uart_clearRxInterrupts(){
  IFG2   &= ~URXIFG1;
}

void    uart_clearTxInterrupts(){
  IFG2   &= ~UTXIFG1;
}

void    uart_writeByte(uint8_t byteToWrite){
  U1TXBUF = byteToWrite;
}

uint8_t uart_readByte(){
  return U1RXBUF;
}

//=========================== private =========================================

//=========================== interrupt handlers ==============================

uint8_t uart_isr_tx() {
   uart_clearTxInterrupts(); // TODO: do not clear, but disable when done
   uart_vars.txCb();
   return 0;
}

uint8_t uart_isr_rx() {
   uart_clearRxInterrupts(); // TODO: do not clear, but disable when done
   uart_vars.rxCb();
   return 0;
}