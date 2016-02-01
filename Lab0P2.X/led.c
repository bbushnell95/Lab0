/* 
 * File:   led.c
 * Author: bbushnell
 *
 * Created on January 27, 2015
 */

#include <xc.h>
#include "led.h"
#define OUTPUT 0
#define INPUT 1
#define ON 1
#define OFF 0


void initLEDs(){
    TRISDbits.TRISD0 = OUTPUT;
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
     
    LED1 = ON;
    LED2 = OFF;
    LED3 = OFF;
}

void turnOnLED(int led){
    
    switch (led){
        case(1):
            LED1 = ON;
            LED2 = OFF;
            LED3 = OFF;
            break;
        case(2):
            LED1 = OFF;
            LED2 = ON;
            LED3 = OFF;
            break;
        case(3):
            LED1 = OFF;
            LED2 = OFF;
            LED3 = ON;
            break;
            
    }
    
}