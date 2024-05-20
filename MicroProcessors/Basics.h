/*
 * Basics.h
 *
 *  Created on: 20 May 2024
 *      Author: neevp
 */
#include "msp430.h"

#ifndef BASICS_H_
#define BASICS_H_

 // Bit Manipulations
#define SETBIT(m, k) ((m) =  (m) | ( 1 << (k)))
#define RESETBIT(m, k) ((m) =  (m) & (~(1 << (k))))
#define TOGGLEBIT(m, k) ((m) =  (m) ^ (1 << (k)))
#define GETBIT(m, k) (((m) & ( 1 << (k) )) !=0 )

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0

// Port Directions
#define set_out(p, b) SETBIT(p, b)
#define set_in(p, b)  RESETBIT(p, b)

// Port Outputs
#define write_high(p, b) SETBIT(p, b)
#define write_low(p, b) RESETBIT(p, b)

// Port Input Configs
#define attachPULLUP(pdir, pren, pout, b) RESETBIT(pdir, b); SETBIT(pren, b); SETBIT(pout, b)
#define attachPULLDOWN(pdir, pren, pout, b) RESETBIT(pdir, b); SETBIT(pren, b); RESETBIT(pout, b)
#define digitalRead(p, b) GETBIT(p, b)

// Interrupt Configs
#define setInterruptH2L(pies, pie, pifg, b) SETBIT(pies, b); clearPIFG(pifg); SETBIT(pie, b); finalizeInterrupts
#define setInterruptL2H(pies, pie, pifg, b) RESETBIT(pies, b); clearPIFG(pifg); SETBIT(pie, b); finalizeInterrupts
#define finalizeInterrupts __bis_SR_register(GIE)
#define clearPIFG(pifg) pifg = 0;

// # External - Special Cases on MSP430FR6989 Red Breakout Board
#define LEDG_OUTPUT set_out(P9DIR, 7)
#define LEDG_LOW write_low(P9OUT, 7)
#define LEDG_HIGH write_high(P9OUT, 7)

#define LEDR_OUTPUT set_out(P1DIR, 0)
#define LEDR_LOW write_low(P1OUT, 0)
#define LEDR_HIGH write_high(P1OUT, 0)

#define LEFT_BUTTON_INPUT_PULLUP attachPULLUP(P1DIR, P1REN, P1OUT, 1)
#define LEFT_BUTTON_READ digitalRead(P1IN, 1)

#define RIGHT_BUTTON_INPUT_PULLUP attachPULLUP(P1DIR, P1REN, P1OUT, 2)
#define RIGHT_BUTTON_READ digitalRead(P1IN, 2)

#endif /* BASICS_H_ */
