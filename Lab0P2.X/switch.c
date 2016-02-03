/* 
 * File:   switch.c
 * Author: Brett Bushnell
 *
 * Created on February 1, 2016
 */

#include <xc.h>
#include "switch.h"

#define ENABLED 1
#define DISABLED 0

#define PRIORITY_7 7



void initSwitch1(){
    TRISDbits.TRISD6 = INPUT;
    CNCONDbits.ON = ENABLED;    //CN device
    CNENDbits.CNIED6 = ENABLED; //CN interrupt for pin
    IEC1bits.CNDIE = ENABLED;   //Overall CN Interrupt
    IFS1bits.CNDIF = 0;   
    CNPUDbits.CNPUD6 = ENABLED;  //Pull-up resistor
    IPC8bits.CNIP = PRIORITY_7;  
}