/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>
#define INPUT 1

void initSwitch1(){
    TRISDbits.TRISD6 = INPUT; 
    CNPUDbits.CNPUD6 = 1;  //Enables pull up resistor
}