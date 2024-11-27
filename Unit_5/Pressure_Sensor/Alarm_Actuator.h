/*
 * Alarm_Actuator.h
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */


#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_
#include "States.h"

enum
{
	AA_Init,
	AA_Alarm_On,
	AA_Alarm_Off,
	AA_Waiting
}AA_State_Id;


STATE_define(AA_Init);
STATE_define(AA_Alarm_On);
STATE_define(AA_Alarm_Off);
STATE_define(AA_Waiting);


extern void (*AA_State)();


void AA_Start_Alarm();
void AA_Stop_Alarm();

#endif /* ALARM_ACTUATOR_H_ */
