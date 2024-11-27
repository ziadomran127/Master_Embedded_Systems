/*
 * Pressure_Sensor.c
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */

#include "Pressure_Sensor.h"
#include "driver.h"

static unsigned int PS_Val ;

void(*PS_State)() ;

STATE_define(PS_Init)
{
	PS_State_Id = PS_Init ;
	PS_State = STATE(PS_Reading) ;
}



STATE_define(PS_Reading)
{
	PS_State_Id = PS_Reading ;
	PS_Val = getPressureVal();
	PS_State = STATE(PS_Waiting) ;

}



STATE_define(PS_Waiting)
{
	PS_State_Id = PS_Waiting ;
	Delay(1000) ;
	PS_State = STATE(PS_Reading) ;
}

unsigned int PS_get_pressure_value(void)
{
	return PS_Val;
}
