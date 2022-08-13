/*
 * application.h
 *
 * Created: 8/12/2022 8:33:16 PM
 *  Author: hosam
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "CONFIGURATIONS/CONFIGURATION.h"
#include "APPLICATION_Configurations.h"

#include "../HAL/LED/LED.h"
#include "../HAL/Traffic_light/traffic_light.h"

#include "../MCAL/TIMER0/TIMER0.h"

void app_init(void);
void app_start(void);


#endif /* APPLICATION_H_ */