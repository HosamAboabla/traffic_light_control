/*
 * DIO.c
 *
 * Created: 8/12/2022 7:49:51 PM
 *  Author: hosam
 */ 


#include "DIO.h"

// Prototypes for functions pin only
DIO_ERROR_CODE DIO_SetPinDirection (Port port , Pin pin , State state)
{
	// Input state, clear DDR pin
	// Output state, set DDR pin
	switch(state)
	{
		case DIO_INPUT:
			switch(port)
			{
				case DIO_PORTA:
					CLEAR_BIT(DDRA , pin);
					break;
				case DIO_PORTB:
					CLEAR_BIT(DDRB , pin);
					break;
				case DIO_PORTC:
					CLEAR_BIT(DDRC , pin);
					break;
				case DIO_PORTD:
					CLEAR_BIT(DDRD , pin);
					break;
				default:
					break;
			}
			break;
		
		case DIO_OUTPUT:
			switch(port)
			{
				case DIO_PORTA:
					SET_BIT(DDRA , pin);
					break;
				case DIO_PORTB:
					SET_BIT(DDRB , pin);
					break;
				case DIO_PORTC:
					SET_BIT(DDRC , pin);
					break;
				case DIO_PORTD:
					SET_BIT(DDRD , pin);
					break;
				default:
					break;
			}
			default:
			break;
		
	}
	
	return DIO_SUCCESS;
}
DIO_ERROR_CODE DIO_SetPinValue (Port port , Pin pin , Status status)
{
	// To make it low, clear PORT pin
	// To make it hight, set PORT pin
	
	switch(status)
	{
		case DIO_LOW:
			switch(port)
			{
				case DIO_PORTA:
				CLEAR_BIT(PORTA , pin);
				break;
				case DIO_PORTB:
				CLEAR_BIT(PORTB , pin);
				break;
				case DIO_PORTC:
				CLEAR_BIT(PORTC , pin);
				break;
				case DIO_PORTD:
				CLEAR_BIT(PORTD , pin);
				break;
				default:
				break;
			}
			break;
		
		case DIO_HIGH:
			switch(port)
			{
				case DIO_PORTA:
					SET_BIT(PORTA , pin);
					break;
				case DIO_PORTB:
					SET_BIT(PORTB , pin);
					break;
				case DIO_PORTC:
					SET_BIT(PORTC , pin);
					break;
				case DIO_PORTD:
					SET_BIT(PORTD , pin);
					break;
				default:
					break;
			}
		default:
			break;
		
	}
	
	return DIO_SUCCESS;
	
}
DIO_ERROR_CODE DIO_TogglePinValue(Port port , Pin pin)
{
	// to toggle, XOR PORT pin
	switch(port)
	{
		case DIO_PORTA:
			TOGGLE_BIT(PORTA , pin);
			break;
		case DIO_PORTB:
			TOGGLE_BIT(PORTB , pin);
			break;
		case DIO_PORTC:
			TOGGLE_BIT(PORTC , pin);
			break;
		case DIO_PORTD:
			TOGGLE_BIT(PORTD , pin);
			break;
		default:
			break;
	}
	return DIO_SUCCESS;
}
