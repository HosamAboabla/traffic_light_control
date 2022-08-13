/*
 * DIO.c
 *
 * Created: 8/12/2022 7:49:51 PM
 *  Author: hosam
 */ 


#include "DIO.h"

// Prototypes for functions pin only
void DIO_SetPinDirection (Port port , Pin pin , State state)
{
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
}
void DIO_SetPinValue (Port port , Pin pin , Status status)
{
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
	
}
void DIO_TogglePinValue(Port port , Pin pin)
{
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
}
// if pin is defined as input
void DIO_ReadPinValue(Port port , Pin pin , uint8* reading)
{
	switch(port)
	{
		case DIO_PORTA:
			*reading = GET_BIT(PINA , pin);
			break;
		case DIO_PORTB:
			*reading = GET_BIT(PINB , pin);
			break;
		case DIO_PORTC:
			*reading = GET_BIT(PINC , pin);
			break;
		case DIO_PORTD:
			*reading = GET_BIT(PIND , pin);
			break;
		default:
		break;
	}
	
}
void DIO_SetPinPullUp(Port port , Pin pin)
{
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
}

// Prototypes for functions for port only
void DIO_SetPortDirection(Port port , State state)
{
	switch(state)
	{
		case DIO_INPUT:
			switch(port)
			{
				case DIO_PORTA:
					DDRA = 0x00;
					break;
					case DIO_PORTB:
					DDRB = 0x00;
					break;
					case DIO_PORTC:
					DDRC = 0x00;
					break;
					case DIO_PORTD:
					DDRD = 0x00;
					break;
					default:
					break;
			}
			break;
		case DIO_OUTPUT:
			switch(port)
			{
				case DIO_PORTA:
				DDRA = 0xFF;
				break;
				case DIO_PORTB:
				DDRB = 0xFF;
				break;
				case DIO_PORTC:
				DDRC = 0xFF;
				break;
				case DIO_PORTD:
				DDRD = 0xFF;
				break;
				default:
				break;
			}
			break;
	}
}
void DIO_SetPortValue(Port port , Status status)
{
	switch(status)
	{
		case DIO_LOW:
		switch(port)
		{
			case DIO_PORTA:
				PORTA = 0x00;
				break;
			case DIO_PORTB:
				PORTB = 0x00;
				break;
			case DIO_PORTC:
				PORTC = 0x00;
				break;
			case DIO_PORTD:
				PORTD = 0x00;
				break;
			default:
			break;
		}
		break;
		case DIO_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
				PORTA = 0xFF;
				break;
			case DIO_PORTB:
				PORTB = 0xFF;
				break;
			case DIO_PORTC:
				PORTC = 0xFF;
				break;
			case DIO_PORTD:
				PORTD = 0xFF;
				break;
			default:
			break;
		}
		break;
	}
}
void DIO_TogglePortValue(Port port)
{
	switch(port)
	{
		case DIO_PORTA:
			PORTA ^= 0xFF;
			break;
		case DIO_PORTB:
			PORTB ^= 0xFF;
			break;
		case DIO_PORTC:
			PORTC ^= 0xFF;
			break;
		case DIO_PORTD:
			PORTD ^= 0xFF;
			break;
		default:
		break;
	}
}
uint8_t DIO_ReadPortValue(Port port)
{
	uint8_t reading = 0x00;
	switch(port)
	{
		case DIO_PORTA:
			reading = PINA;
			break;
		case DIO_PORTB:
			reading = PINB;
			break;
		case DIO_PORTC:
			reading = PINC;
			break;
		case DIO_PORTD:
			reading = PIND;
			break;
		default:
		break;
	}
	
	return reading;
}

/* 
void DIO_SetPortPullUp(Port port , Pin pin)
{
	switch(port)
	{
		case DIO_PORTA:
		 PORTA = 0xFF;
		break;
		case DIO_PORTB:
		PORTB = 0xFF;
		break;
		case DIO_PORTC:
		PORTC = 0xFF;
		break;
		case DIO_PORTD:
		PORTD = 0xFF;
		break;
		default:
		break;
	}
}
*/
