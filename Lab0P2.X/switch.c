/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
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