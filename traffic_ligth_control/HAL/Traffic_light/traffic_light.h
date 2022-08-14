/*
 * traffic_light.h
 *
 * Created: 8/13/2022 8:41:57 PM
 *  Author: hosam
 */ 


#ifndef TRAFFIC_LIGHT_H_
#define TRAFFIC_LIGHT_H_

#include "traffic_light_configurations.h"

TRAFFIC_LIGHT_ERROR_CODE traffic_light_init(traffic_light* tl);
TRAFFIC_LIGHT_ERROR_CODE stop(traffic_light* tl);
TRAFFIC_LIGHT_ERROR_CODE go(traffic_light* tl);
TRAFFIC_LIGHT_ERROR_CODE ready(traffic_light* tl);
TRAFFIC_LIGHT_ERROR_CODE next_state(traffic_light* tl);



#endif /* TRAFFIC_LIGHT_H_ */