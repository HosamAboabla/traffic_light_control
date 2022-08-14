/*
 * LED_Configurations.h
 *
 * Created: 8/12/2022 8:47:46 PM
 *  Author: hosam
 */ 


#ifndef LED_CONFIGURATIONS_H_
#define LED_CONFIGURATIONS_H_

#include "../../APPLICATION/CONFIGURATIONS/CONFIGURATION.h"
#include "../../MCAL/DIO/DIO.h"



#define CAR_PORT DIO_PORTA
#define CAR_GREEN_PIN DIO_PIN0
#define CAR_YELLOW_PIN DIO_PIN1
#define CAR_RED_PIN DIO_PIN2

#define PEDESTRAIN_PORT DIO_PORTB
#define PEDESTRAIN_GREEN_PIN DIO_PIN0
#define PEDESTRAIN_YELLOW_PIN DIO_PIN1
#define PEDESTRAIN_RED_PIN DIO_PIN2

typedef struct LED{
	Port port;
	Pin pin;
}LED;


typedef enum{
	LED_SUCCESS,
	LED_FAIL
}LED_ERROR_CODE;

#endif /* LED_CONFIGURATIONS_H_ */