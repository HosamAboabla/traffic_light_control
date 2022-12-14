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
	uint8_t previous_status;
}traffic_light;

typedef enum{
	TRAFFIC_LIGHT_SUCCESS,
	TRAFFIC_LIGHT_FAIL
}TRAFFIC_LIGHT_ERROR_CODE;

#endif /* TRAFFIC_LIGHT_CONFIGURATIONS_H_ */