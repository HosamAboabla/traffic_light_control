/*
 * traffic_light.c
 *
 * Created: 8/13/2022 8:41:36 PM
 *  Author: hosam
 */ 

#include "traffic_light.h"

TRAFFIC_LIGHT_ERROR_CODE traffic_light_init(traffic_light* tl)
{
	if( LED_Initialization(&tl->green) != LED_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	if( LED_Initialization(&tl->yellow) != LED_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	if( LED_Initialization(&tl->red) != LED_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	
	if( stop(tl) != TRAFFIC_LIGHT_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	
	return TRAFFIC_LIGHT_SUCCESS;
}

TRAFFIC_LIGHT_ERROR_CODE stop(traffic_light* tl)
{
	if( LED_On(&tl->red) != LED_SUCCESS)
		return TRAFFIC_LIGHT_FAIL;
	if( LED_Off(&tl->green) != LED_SUCCESS)
		return TRAFFIC_LIGHT_FAIL;
	if( LED_Off(&tl->yellow) != LED_SUCCESS)
		return TRAFFIC_LIGHT_FAIL;
	tl->status = traffic_status_red;

	return TRAFFIC_LIGHT_SUCCESS;
}
TRAFFIC_LIGHT_ERROR_CODE go(traffic_light* tl)
{
	if( LED_On(&tl->green) != LED_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	if( LED_Off(&tl->red) != LED_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	if( LED_Off(&tl->yellow) != LED_SUCCESS)
		return TRAFFIC_LIGHT_FAIL;
	
	tl->status = traffic_status_green;

	return TRAFFIC_LIGHT_SUCCESS;
}
TRAFFIC_LIGHT_ERROR_CODE ready(traffic_light* tl)
{
	
	if( tl->status == traffic_status_green)
	{
		if( LED_On(&tl->green) != LED_SUCCESS )
			return TRAFFIC_LIGHT_FAIL;
	}else{
		if( LED_Off(&tl->green) != LED_SUCCESS )
			return TRAFFIC_LIGHT_FAIL;
	}
	
	if( LED_Off(&tl->yellow) != LED_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	if( LED_Off(&tl->red) != LED_SUCCESS )
		return TRAFFIC_LIGHT_FAIL;
	
	tl->previous_status = tl->status;
	tl->status = traffic_status_yellow;
	
	return TRAFFIC_LIGHT_SUCCESS;
}


TRAFFIC_LIGHT_ERROR_CODE next_state(traffic_light* tl)
{
	if(tl->status == traffic_status_green)
	{
		if (ready(tl) != TRAFFIC_LIGHT_SUCCESS )
			return TRAFFIC_LIGHT_FAIL;
	}
	else if(tl->status == traffic_status_yellow)
	{
		if(tl->previous_status == traffic_status_green)
		{
			if( stop(tl) != TRAFFIC_LIGHT_SUCCESS )
				return TRAFFIC_LIGHT_FAIL;	
		}
		else{
			if( go(tl) != TRAFFIC_LIGHT_SUCCESS )
				return TRAFFIC_LIGHT_FAIL;
		}
		
	}
	else if(tl->status == traffic_status_red)
	{
		if( ready(tl) != TRAFFIC_LIGHT_SUCCESS )
			return TRAFFIC_LIGHT_FAIL;
	}
	
	return TRAFFIC_LIGHT_SUCCESS;
}