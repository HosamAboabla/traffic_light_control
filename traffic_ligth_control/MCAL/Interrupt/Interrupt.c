/*
 * Interrupt.c
 *
 * Created: 12/10/2021 1:37:26 PM
 *  Author: hosam
 */ 

#include "Interrupt.h"

void Interrupt_Initialization(Interrupt_Signal_Pin pin)
{
	
	sei();
	SET_BIT(GICR , INT0);
	#if GLOBAL_INTERRUPT_STATUS == GLOBAL_EN
		sei();
		// SET_BIT(SREG , 7 );
	#elif GLOBAL_INTERRUPT_STATUS == GLOBAL_DS
		cli();
		// CLEAR_BIT(SREG , 7 );
	#else
		#warning This is invalid
	#endif
	
	
	
	
	// ================================================================
	
	if(pin == INT0_Signal)
	{
		SET_BIT(DDRD , 2);
		// SET_BIT(PORTD , 2);
		SET_BIT(GICR , INT0);
		// Interrupt Sense
		#if INTERRUPT_SENSE == LOW_SIGNAL
			CLEAR_BIT(MCUCR , ISC00);
			CLEAR_BIT(MCUCR , ISC01);
		#elif INTERRUPT_SENSE == HIGH_SIGNAL
			SET_BIT(MCUCR , ISC00);
			CLEAR_BIT(MCUCR , ISC01);
		#elif INTERRUPT_SENSE == FALLING_SIGNAL
			CLEAR_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
		#elif INTERRUPT_SENSE == RISING_SIGNAL
			SET_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
		
		#else
			#warning This is invalid
		#endif
	}
	else if(pin == INT1_Signal)
	{
		SET_BIT(DDRD , 3);
		SET_BIT(GICR , INT1);
		// Interrupt Sense
		#if INTERRUPT_SENSE == LOW_SIGNAL
			CLEAR_BIT(MCUCR , ISC10);
			CLEAR_BIT(MCUCR , ISC11);
		#elif INTERRUPT_SENSE == HIGH_SIGNAL
			SET_BIT(MCUCR , ISC10);
			CLEAR_BIT(MCUCR , ISC11);
		#elif INTERRUPT_SENSE == FALLING_SIGNAL
			CLEAR_BIT(MCUCR , ISC10);
			SET_BIT(MCUCR , ISC11);
		#elif INTERRUPT_SENSE == RISING_SIGNAL
			SET_BIT(MCUCR , ISC10);
			SET_BIT(MCUCR , ISC11);
		#else
			#warning This is invalid
		#endif
	}
	else if(pin == INT2_Signal)
	{
		SET_BIT(DDRB , 2);
		SET_BIT(GICR , INT2);
		// Interrupt Sense
		#if INTERRUPT_SENSE == FALLING_SIGNAL
			CLEAR_BIT(MCUCSR , ISC2);
		#elif INTERRUPT_SENSE == RISING_SIGNAL
			SET_BIT(MCUCSR , ISC2);
		#else
			#warning This is invalid
		#endif
	}
	


	
}
