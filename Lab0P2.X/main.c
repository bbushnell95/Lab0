/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
//#include "switch.h"
//#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    led1, led2, led3, wait, wait2, debouncePress, debounceRelease, debounceRelease2
} stateType;

volatile stateType state = led1;

int main() {
    //This function is necessary to use interrupts. 
    enableInterrupts();
    SYSTEMConfigPerformance(10000000);
    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    //initTimer2();
    initTimer1();
    
    while(1){

        switch(state){
            case led1:
                turnOnLED(1);
            case led2:
                turnOnLED(2);
            case led3:
                turnOnLED(3);
        }
        
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt(){
    IFS0bits.T1IF = 0;    //sets the flag down
    

}
