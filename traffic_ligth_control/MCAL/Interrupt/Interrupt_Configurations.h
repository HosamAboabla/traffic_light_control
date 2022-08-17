/*
 * Interrupt_Configurations.h
 *
 * Created: 12/10/2021 1:38:03 PM
 *  Author: hosam
 */ 


#ifndef INTERRUPT_CONFIGURATIONS_H_
#define INTERRUPT_CONFIGURATIONS_H_

#include "../../APPLICATION/CONFIGURATIONS/CONFIGURATION.h"

#define LOW_SIGNAL		0
#define HIGH_SIGNAL		1
#define FALLING_SIGNAL	2
#define RISING_SIGNAL	3

#define INTERRUPT_SENSE	LOW_SIGNAL

#define GLOBAL_EN	1
#define GLOBAL_DS	0

#define INT0_SIGNAL 0
#define INT1_SIGNAL 1
#define INT2_SIGNAL 2

#define GLOBAL_INTERRUPT_STATUS	GLOBAL_EN



typedef enum
{
	INT0_Signal = 0,
	INT1_Signal = 1,
	INT2_Signal = 2,
} Interrupt_Signal_Pin;

#endif /* INTERRUPT_CONFIGURATIONS_H_ */