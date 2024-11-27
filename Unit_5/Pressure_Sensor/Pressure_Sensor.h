/*
 * Pressure_Sensor.h
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */



#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "States.h"

enum
{
	PS_Init,
	PS_Reading,
	PS_Waiting
}PS_State_Id;


unsigned int PS_get_pressure_value(void);
STATE_define(PS_Init) ;
STATE_define(PS_Reading) ;
STATE_define(PS_Waiting) ;

extern void (*PS_State)();

#endif /* PRESSURE_SENSOR_H_ */
