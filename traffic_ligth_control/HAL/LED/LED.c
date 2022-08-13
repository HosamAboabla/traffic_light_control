/*
 * LED.c
 *
 * Created: 8/12/2022 8:47:08 PM
 *  Author: hosam
 */ 

#include "LED.h"

void LED_Initialization(LED* led)
{
	DIO_SetPinDirection(led->port , led->pin , DIO_OUTPUT);
}
void LED_On(LED* led)
{
	DIO_SetPinValue(led->port , led->pin , DIO_HIGH);
}
void LED_Off(LED* led)
{
	DIO_SetPinValue(led->port , led->pin , DIO_LOW);
}
void LED_Toggle(LED* led)
{
	DIO_TogglePinValue(led->port , led->pin);
}