/*
 * traffic_light.c
 *
 * Created: 8/13/2022 8:41:36 PM
 *  Author: hosam
 */ 

#include "traffic_light.h"

void traffic_light_init(traffic_light* tl)
{
	LED_Initialization(&tl->green);
	LED_Initialization(&tl->yellow);
	LED_Initialization(&tl->red);
	tl->status = traffic_status_red;
}

void stop(traffic_light* tl)
{
	LED_On(&tl->red);
	LED_Off(&tl->green);
	LED_Off(&tl->yellow);
	tl->status = traffic_status_red;
}
void go(traffic_light* tl)
{
	LED_On(&tl->green);
	LED_Off(&tl->red);
	LED_Off(&tl->yellow);
	tl->status = traffic_status_green;
}
void ready(traffic_light* tl)
{
	LED_On(&tl->yellow);
	LED_Off(&tl->green);
	LED_Off(&tl->red);
	tl->status = traffic_status_yellow;
}