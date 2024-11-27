/*
 * Alarm_Montor.h
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */

#ifndef ALARM_MONTOR_H_
#define ALARM_MONTOR_H_
#include "States.h"
enum
{
	AM_Alarm_On,
	AM_Alarm_Off,
	AM_Waiting
}AM_State_Id;



STATE_define(AM_Alarm_On);
STATE_define(AM_Alarm_Off);
STATE_define(AM_Waiting);


extern void (*AM_State)();

#endif /* ALARM_MONTOR_H_ */
