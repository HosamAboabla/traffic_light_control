/*
 * DIO_Configurations.h
 *
 * Created: 8/12/2022 7:50:46 PM
 *  Author: hosam
 */ 


#ifndef DIO_CONFIGURATIONS_H_
#define DIO_CONFIGURATIONS_H_


// Include configurations library (IO  , Delay , Interrupt , Bit math , Standard types)
#include "../../APPLICATION/CONFIGURATIONS/CONFIGURATION.h"

// Define port type
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
	
}Port;

// Define pin type
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}Pin;
// Define state type
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
}State;
// Define status type
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1
}Status;


typedef enum{
	DIO_SUCCESS,
	DIO_FAIL
}DIO_ERROR_CODE;

// Define boolean type
typedef enum
{
	FALSE = 0,
	TRUE = 1
}boolean;



#endif /* DIO_CONFIGURATIONS_H_ */