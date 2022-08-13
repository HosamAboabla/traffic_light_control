/*
 * traffic_light_configurations.h
 *
 * Created: 8/13/2022 8:42:13 PM
 *  Author: hosam
 */ 


#ifndef TRAFFIC_LIGHT_CONFIGURATIONS_H_
#define TRAFFIC_LIGHT_CONFIGURATIONS_H_

#include "../../APPLICATION/CONFIGURATIONS/CONFIGURATION.h"
#include "../LED/LED.h"

typedef enum {
	traffic_status_green = 0,
	traffic_status_yellow,
	traffic_status_red
}traffic_light_status;

typedef struct traffic_light {
	LED green;
	LED yellow;
	LED red;
	uint8_t status;
}traffic_light;



#endif /* TRAFFIC_LIGHT_CONFIGURATIONS_H_ */