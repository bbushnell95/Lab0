/* 
 * File:   main.c
 * Author: Brett Bushnell
 * Description: lab 0.
 * Created on January 30, 2016
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine

typedef enum stateTypeEnum {
    led1, led2, led3, wait, debouncePress, debounceRelease
} stateType;

volatile stateType state = led1;
volatile stateType nextState = led1;

int main() {
    int i = 0;
    //This function is necessary to use interrupts. 
    enableInterrupts();
    SYSTEMConfigPerformance(10000000);
    //initializing all components
    initSwitch1();
    initLEDs();
    initTimer2();
    initTimer1();

    while (1) {

        switch (state) {
            case led1:
                turnOnLED(1);
                break;
            case led2:
                turnOnLED(2);
                break;
            case led3:
                turnOnLED(3);
                break;
            case debouncePress:
                startTimer1();
                delayMs();
                state = wait;
                break;
            case debounceRelease:
                delayMs();
                endTimer1();
                state = nextState;
                break;
            case wait:
                if (LED1 == 1) if (nextState != led3) nextState = led2;
                if (LED2 == 1) if (nextState != led1) nextState = led3;
                if (LED3 == 1) if (nextState != led2) nextState = led1;
        }

    }

    return 0;
}
//ISR for timer1
void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt() {
    IFS0bits.T1IF = 0; //sets the flag down

    if (SW1 == PRESSED) {
        if (LED1 == 1) nextState = led3;
        else if (LED2 == 1) nextState = led1;
        else if (LED3 == 1) nextState = led2;
    }

}
//ISR for SW1
void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt() {
    IFS1bits.CNDIF = 0;
    int i;
    i = PORTD;

    if (SW1 == PRESSED) state = debouncePress;
    else state = debounceRelease;

}



