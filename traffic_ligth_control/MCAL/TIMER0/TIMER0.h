/*
 * TIMER0.h
 *
 * Created: 1/5/2022 2:25:37 PM
 *  Author: hosam
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_Configurations.h"

void Timer0_Start(TIMER0_Prescaler prescaler);
void Timer0_without_interrupt_initialization(TIMER0_Mode mode , TIMER0_Pin_Mode pin_mode);
void Timer0_without_interrupt_set_delay(TIMER0_Mode mode , uint32_t delay , uint16_t top);

void Timer0_with_interrupt_initialization(TIMER0_Mode mode , TIMER0_Pin_Mode pin_mode);
void Timer0_with_interrupt_set_delay(TIMER0_Mode mode , uint32_t delay , uint16_t top);

void Timer0_Stop(void);

void Timer0_Fast_PWM_initialization(TIMER0_PWM_Mode mode);
void Timer0_Fast_PWM_Set_Duty(TIMER0_PWM_Mode mode , uint8_t duty);


#endif /* TIMER0_H_ */