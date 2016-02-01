/* 
 * File:   led.h
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#ifndef LED_H
#define	LED_H

//defining each Led latch so code more readable
#define LED1 LATDbits.LATD0
#define LED2 LATDbits.LATD1
#define LED3 LATDbits.LATD2

void initLEDs();
void turnOnLED(int led);

#endif	/* LED_H */

