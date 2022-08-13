/*
 * traffic_light.h
 *
 * Created: 8/13/2022 8:41:57 PM
 *  Author: hosam
 */ 


#ifndef TRAFFIC_LIGHT_H_
#define TRAFFIC_LIGHT_H_

#include "traffic_light_configurations.h"

void traffic_light_init(traffic_light* tl);
void stop(traffic_light* tl);
void go(traffic_light* tl);
void ready(traffic_light* tl);



#endif /* TRAFFIC_LIGHT_H_ */