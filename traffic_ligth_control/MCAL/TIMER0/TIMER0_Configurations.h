/*
 * TIMER0_Configurations.h
 *
 * Created: 1/5/2022 2:26:03 PM
 *  Author: hosam
 */ 


#ifndef TIMER0_CONFIGURATIONS_H_
#define TIMER0_CONFIGURATIONS_H_

#include "../../APPLICATION/CONFIGURATIONS/CONFIGURATION.h"
#include "../DIO/DIO.h"

#define Frequency 16
#define Bits 256

typedef enum
{
	TIMER0_Prescaler_0 =0,
	TIMER0_Prescaler_1 ,
	TIMER0_Prescaler_8 ,
	TIMER0_Prescaler_64 ,
	TIMER0_Prescaler_256,
	TIMER0_Prescaler_1024
}TIMER0_Prescaler;

typedef enum
{
	TIMER0_Normal = 0,
	TIMER0_CTC = 1
	// TIMER0_Fast_PWM = 2,
	// TIMER0_Phase_Correct_PWM= 3
}TIMER0_Mode;

typedef enum
{
	PIN_Disconnected = 0,
	PIN_Toggle ,
	PIN_Clear,
	PIN_Set
}TIMER0_Pin_Mode;

typedef enum 
{
	TIMER0_Inverting = 0,
	TIMER0_Non_Inverting
}TIMER0_PWM_Mode;

#endif /* TIMER0_CONFIGURATIONS_H_ */