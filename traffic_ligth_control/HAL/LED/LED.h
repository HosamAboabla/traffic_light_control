/*
 * LED.h
 *
 * Created: 8/12/2022 8:47:20 PM
 *  Author: hosam
 */ 


#ifndef LED_H_
#define LED_H_

#include "LED_Configurations.h"

void LED_Initialization(LED* led);
void LED_On(LED* led);
void LED_Off(LED* led);
void LED_Toggle(LED* led);



#endif /* LED_H_ */