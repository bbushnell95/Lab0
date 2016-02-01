/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "timer.h"
#define PRESCALER_256 3

void initTimer1(){
    TMR1 = 0;             //keeps count of ticks
    T1CONbits.TCKPS = PRESCALER_256;  //setting prescaler to 256
    T1CONbits.TCS = 0;
    PR1 = 39061;          //Comparing TMR1 to this (39062)
    T1CONbits.ON = 1;     //turns on the timer
    IFS0bits.T1IF = 0;   //interrupt flag
    IEC0bits.T1IE = 1;
    IPC1bits.T1IP = 7;   //set the priority
}

initTimer2(){
    TMR2 = 0;
    T2CONbits.TCKPS = PRESCALER_256;
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}