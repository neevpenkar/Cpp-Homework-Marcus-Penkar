/*
 * timer_1.h
 *
 *  Created on: 20 May 2024
 *      Author: neevp
 */

#ifndef TIMER_1_H_
#define TIMER_1_H_

#define TA_CLOCK_SOURCE_ACLK 1
#define TA_CLOCK_SOURCE_SMCLK 2

#define TA_PRESCALER_1 0
#define TA_PRESCALER_2 1
#define TA_PRESCALER_4 2
#define TA_PRESCALER_8 3

#define TA_MODE_STOP 0
#define TA_MODE_UP 1 // Timer counts to TAxCCR0
#define TA_MODE_CONT 2
#define TA_MODE_UPDOWN 3 // Timer counts to TAxCCR0 then down

#define TA_INT_EN 1
#define TA_INT_DIS 1

#define CLR_BIT 2
 //#define TA_INT_PENDING GETBIT()
#define CONFIG_TIMER(timrctr, src, mode, scale) timrctr = (src << 8) | (mode << 4) | (1 << 2) | (1 << 1)
#define DISABLE_TIMERA(timrctr) RESETBIT(timrctr, 0)
#define CLR_TIMER_A(timrctr) SETBIT(timrctr, 2)
#define CLR_TIMER(timrctr, rb) SETBIT(timrctr, rb)
#define SET_COMPARE(ccreg, val) ccreg = val; _BIS_SR(LPM0_bits | GIE)



// This should be the secondary A1 vector
//#pragma vector=TIMER0_A1_VECTOR
//__interrupt void Timer (void) {
//
//    if (TA0CTL && TAIFG) P1OUT ^= BIT0; //if TAIFG Toggle P1.0
//    TA0CTL &=~ TAIFG;  //Reset TAIFG
//}


#endif /* TIMER_1_H_ */
