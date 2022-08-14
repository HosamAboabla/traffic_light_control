/*
 * LED.c
 *
 * Created: 8/12/2022 8:47:08 PM
 *  Author: hosam
 */ 

#include "LED.h"

LED_ERROR_CODE LED_Initialization(LED* led)
{
	// set DDR pin, to make it output
	if( DIO_SetPinDirection(led->port , led->pin , DIO_OUTPUT) == DIO_SUCCESS )
		return LED_SUCCESS;
	return LED_FAIL;
	
}
LED_ERROR_CODE LED_On(LED* led)
{
	// set PORT pin, to make it on
	if( DIO_SetPinValue(led->port , led->pin , DIO_HIGH) == DIO_SUCCESS)
		return LED_SUCCESS;
	
	return LED_FAIL;
}
LED_ERROR_CODE LED_Off(LED* led)
{
	// reset PORT pin, to make it off
	if( DIO_SetPinValue(led->port , led->pin , DIO_LOW) == DIO_SUCCESS )
		return LED_SUCCESS;
	return LED_FAIL;
}
LED_ERROR_CODE LED_Toggle(LED* led)
{
	// XOR PORT pin, to make it toggle
	if( DIO_TogglePinValue(led->port , led->pin) == DIO_SUCCESS )
		return LED_SUCCESS;
	return LED_FAIL;
}