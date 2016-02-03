/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "timer.h"

#define PRESCALER_256 3
#define TIMER2_PRESCALER_256 7
#define ENABLE 1
#define DISABLE 0

void initTimer1(){
    TMR1 = 0;             //keeps count of ticks
    T1CONbits.TCKPS = PRESCALER_256;  //setting prescaler to 256
    T1CONbits.TCS = 0;
    PR1 = 39061;          //PR value to have 1 second timer
    IFS0bits.T1IF = 0;   //interrupt flag
    IEC0bits.T1IE = ENABLE;  //enables the interrupt 
    IPC1bits.T1IP = 7;   //set the priority
}
void startTimer1(){
    TMR1 = 0;
    T1CONbits.ON = 1;  
}
void endTimer1(){
    T1CONbits.ON = 0;
}

void initTimer2(){
    TMR2 = 0;
    IFS0bits.T2IF = 0;
}

void delayMs(){
    TMR2 = 0;
    PR2 = 1952;   //50 ms
    
    T2CONbits.TCKPS = TIMER2_PRESCALER_256;
    IFS0bits.T2IF = 0;
    T2CONbits.ON = 1;
    
    while(!IFS0bits.T2IF){
        Nop();            //no operation
    }
    IFS0bits.T2IF = 0;
}