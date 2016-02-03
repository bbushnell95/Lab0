/* 
 * File:   switch.h
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#ifndef SWITCH_H
#define	SWITCH_H


#define INPUT 1
#define OUTPUT 0

#define PRESSED 1
#define UNPRESSED 0

#define SW1 PORTDbits.RD6

void initSwitches();

#endif	/* SWITCH_H */

