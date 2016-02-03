/* 
 * File:   switch.c
 * Author: Brett Bushnell
 *
 * Created on February 1, 2016
 */

#include <xc.h>
#include "switch.h"





void initSwitch1(){
    TRISDbits.TRISD6 = INPUT;
    CNCONDbits.ON = 1;
    CNENDbits.CNIED6 = 1;
    IEC1bits.CNDIE = 1;
    IFS1bits.CNDIF = 0;   //putting down the flag
    CNPUDbits.CNPUD6 = 1;  //Enables pull up resistor
    IPC8bits.CNIP = 7;
}