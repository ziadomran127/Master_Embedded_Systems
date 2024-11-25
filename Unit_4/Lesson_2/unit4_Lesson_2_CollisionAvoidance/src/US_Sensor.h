/*
 * US_Sensor.h
 *
 *  Created on: Oct 29, 2024
 *      Author: LEGION
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "State.h"

enum{
    
US_busy

}US_state_id;


void US_Init() ;
STATE_define(US_busy) ;

extern void (*US_State)() ;

#endif /* US_SENSOR_H_ */
