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
	stop(tl);
}

void stop(traffic_light* tl)
{
	LED_On(&tl->red);
	LED_Off(&tl->green);
	LED_Off(&tl->yellow);
	tl->status = traffic_status_red;
	// tl->previous_status = traffic_status_yellow;
}
void go(traffic_light* tl)
{
	LED_On(&tl->green);
	LED_Off(&tl->red);
	LED_Off(&tl->yellow);
	tl->status = traffic_status_green;
	// tl->previous_status = traffic_status_red;
}
void ready(traffic_light* tl)
{
	
	if( tl->status == traffic_status_green)
	{
		LED_On(&tl->green);
	}else{
		LED_Off(&tl->green);
	}
	
	LED_Off(&tl->yellow);
	LED_Off(&tl->red);
	
	tl->previous_status = tl->status;
	tl->status = traffic_status_yellow;
}


void next_state(traffic_light* tl)
{
	if(tl->status == traffic_status_green)
	{
		ready(tl);
	}
	else if(tl->status == traffic_status_yellow)
	{
		if(tl->previous_status == traffic_status_green)
		{
			stop(tl);	
		}
		else{
			go(tl);
		}
		
	}
	else if(tl->status == traffic_status_red)
	{
		ready(tl);
	}
}