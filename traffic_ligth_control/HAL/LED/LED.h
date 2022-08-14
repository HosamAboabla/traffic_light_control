/*
 * LED.h
 *
 * Created: 8/12/2022 8:47:20 PM
 *  Author: hosam
 */ 


#ifndef LED_H_
#define LED_H_

#include "LED_Configurations.h"

LED_ERROR_CODE LED_Initialization(LED* led);
LED_ERROR_CODE LED_On(LED* led);
LED_ERROR_CODE LED_Off(LED* led);
LED_ERROR_CODE LED_Toggle(LED* led);



#endif /* LED_H_ */