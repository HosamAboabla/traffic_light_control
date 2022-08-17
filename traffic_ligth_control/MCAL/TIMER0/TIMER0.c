/*
 * TIMER0.c
 *
 * Created: 1/5/2022 2:25:29 PM
 *  Author: hosam
 */ 

#include "TIMER0.h"


uint16_t Global_Prescaler = 0;

void Timer0_Start(TIMER0_Prescaler prescaler)
{
	switch(prescaler)
	{
		case TIMER0_Prescaler_0:
			// CLEAR_BIT(TCCR0  , CS02); CLEAR_BIT(TCCR0  , CS01); CLEAR_BIT(TCCR0  , CS00);
			// Global_Prescaler = 0;
			break;
		case TIMER0_Prescaler_1:
			CLEAR_BIT(TCCR0  , CS02); CLEAR_BIT(TCCR0  , CS01); SET_BIT(TCCR0  , CS00);
			Global_Prescaler = 1;
			break;
		
		case TIMER0_Prescaler_8:
			CLEAR_BIT(TCCR0  , CS02); SET_BIT(TCCR0  , CS01); CLEAR_BIT(TCCR0  , CS00);
			Global_Prescaler = 8;
			break;
		
		case TIMER0_Prescaler_64:
			CLEAR_BIT(TCCR0  , CS02); SET_BIT(TCCR0  , CS01); SET_BIT(TCCR0  , CS00);
			Global_Prescaler = 64;
			break;
		
		case TIMER0_Prescaler_256:
			SET_BIT(TCCR0  , CS02); CLEAR_BIT(TCCR0  , CS01); CLEAR_BIT(TCCR0  , CS00);
			Global_Prescaler = 256;
			break;
		
		case TIMER0_Prescaler_1024:
			SET_BIT(TCCR0  , CS02); CLEAR_BIT(TCCR0  , CS01); SET_BIT(TCCR0  , CS00);
			Global_Prescaler = 1024;
			break;
	}
}



void Timer0_Stop(void)
{
	CLEAR_BIT(TCCR0  , CS02); CLEAR_BIT(TCCR0  , CS01); CLEAR_BIT(TCCR0  , CS00);
	Global_Prescaler = 0;
}




void Timer0_without_interrupt_initialization(TIMER0_Mode mode , TIMER0_Pin_Mode pin_mode)
{
	cli();
	switch(mode)
	{
		case TIMER0_Normal:
			CLEAR_BIT(TCCR0 , WGM01); CLEAR_BIT(TCCR0 , WGM00);
			CLEAR_BIT(TIMSK , TOIE0);
			break;
		case TIMER0_CTC:
			SET_BIT(TCCR0 , WGM01); CLEAR_BIT(TCCR0 , WGM00);
			CLEAR_BIT(TIMSK , OCIE0);
			break;
	}
	
	switch(pin_mode)
	{
		case PIN_Disconnected:
			CLEAR_BIT(TCCR0 , COM01); CLEAR_BIT(TCCR0 , COM00);
			break;
		case PIN_Toggle:
			CLEAR_BIT(TCCR0 , COM01); SET_BIT(TCCR0 , COM00);
			break;
		case PIN_Clear:
			SET_BIT(TCCR0 , COM01); CLEAR_BIT(TCCR0 , COM00);
			break;
		case PIN_Set:
			SET_BIT(TCCR0 , COM01); SET_BIT(TCCR0 , COM00);
			break;
	}
}


void Timer0_without_interrupt_set_delay(TIMER0_Mode mode , uint32_t delay , uint16_t top)
{
	if(mode == TIMER0_Normal)
	{
		uint32_t counter = 0;
		uint8_t tick = (1 * Global_Prescaler) / Frequency;
		uint32_t Count = (delay * 1000) / tick;
		uint32_t OVF = Count / Bits;
		OVF ++;
		uint8_t initail_value = Bits - ( Count % Bits);
		TCNT0 = initail_value;
		
		while(counter < OVF)
		{
			while(GET_BIT(TIFR , TOV0) != 1);
			SET_BIT(TIFR , TOV0);
			counter++;
		}
	}
	else if(mode == TIMER0_CTC)
	{
		OCR0 = top;
		uint32_t counter = 0;
		uint8_t tick = (Global_Prescaler) / Frequency;
		uint32_t Count = ( delay * 1000 ) / tick;
		uint32_t CTC = Count / OCR0;
		CTC++;

		
		while(counter < CTC)
		{
			while(GET_BIT(TIFR , OCF0) != 1 );
			counter++;
			SET_BIT(TIFR , OCF0);
		}
	}
}

// Global variables

uint32_t Number_OVF = 0;
uint32_t Number_CTC = 0;
uint32_t init_val = 0;

void Timer0_with_interrupt_initialization(TIMER0_Mode mode , TIMER0_Pin_Mode pin_mode)
{
	cli();
	switch(mode)
	{
		case TIMER0_Normal:
			CLEAR_BIT(TCCR0 , WGM01); CLEAR_BIT(TCCR0 , WGM00);
			SET_BIT(TIMSK , TOIE0);
			break;
		case TIMER0_CTC:
			SET_BIT(TCCR0 , WGM01); CLEAR_BIT(TCCR0 , WGM00);
			SET_BIT(TIMSK , OCIE0);
			break;
	}
	
	switch(pin_mode)
	{
		case PIN_Disconnected:
			CLEAR_BIT(TCCR0 , COM01); CLEAR_BIT(TCCR0 , COM00);
			break;
		case PIN_Toggle:
			CLEAR_BIT(TCCR0 , COM01); SET_BIT(TCCR0 , COM00);
			break;
		case PIN_Clear:
			SET_BIT(TCCR0 , COM01); CLEAR_BIT(TCCR0 , COM00);
			break;
		case PIN_Set:
			SET_BIT(TCCR0 , COM01); SET_BIT(TCCR0 , COM00);
			break;
		default:
			break;
	}
	sei();
}





void Timer0_with_interrupt_set_delay(TIMER0_Mode mode , uint32_t delay , uint16_t top)
{
	if(mode == TIMER0_Normal)
	{
		uint32_t tick = (1 * Global_Prescaler) / Frequency;
		uint32_t Count = (delay * 1000) / tick;
		Number_OVF = Count / Bits;
		if( Count % Bits )
			Number_OVF++;
		
		init_val = Bits - (Count % Bits);
		TCNT0 = init_val;
	}
	else if(mode == TIMER0_CTC)
	{
		OCR0 = top;
		uint32_t tick = (1 * Global_Prescaler) / Frequency;
		uint32_t Count = (delay * 1000) / tick;
		Number_CTC = Count / OCR0;
		Number_CTC++;
	}
}


void Timer0_Fast_PWM_initialization(TIMER0_PWM_Mode mode)
{
	// Configure pin as output
	DIO_SetPinDirection(DIO_PORTB , DIO_PIN3 , DIO_OUTPUT);
	
	// Select fast pwm WGM
	SET_BIT(TCCR0 , WGM01); SET_BIT(TCCR0 , WGM00);
	
	// Select prescaler
	SET_BIT(TCCR0 , CS02); CLEAR_BIT(TCCR0 , CS01) ; CLEAR_BIT(TCCR0 , CS00);
	
	// Select pin mode
	switch(mode)
	{
		case TIMER0_Non_Inverting:
			SET_BIT(TCCR0 , COM01) ; CLEAR_BIT(TCCR0 , COM00);	
			break;
		case TIMER0_Inverting:
			SET_BIT(TCCR0 , COM01) ; SET_BIT(TCCR0 , COM00);
			break;
	}
	
	
	
	
	
		
}
void Timer0_Fast_PWM_Set_Duty(TIMER0_PWM_Mode mode , uint8_t duty)
{
	switch(mode)
	{
		case TIMER0_Non_Inverting:
			OCR0 = ((Bits * duty) / 100) - 1;
			break;
		case TIMER0_Inverting:
			OCR0 = (Bits -1) - ((duty * Bits) / 100) - 1;
	}
}