/*
 * Alarm_Actuator.c
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */
#include "driver.h"
#include "Alarm_Actuator.h"

void(*AA_State)() ;

STATE_define(AA_Init)
{
	AA_State_Id = AA_Init ;

	AA_State = STATE(AA_Waiting) ;

}

STATE_define(AA_Waiting)
{
	AA_State_Id = AA_Waiting ;

}

STATE_define(AA_Alarm_On)
{

AA_State_Id =AA_Alarm_On ;
Set_Alarm_actuator(1) ;
AA_State = STATE(AA_Waiting);

}
STATE_define(AA_Alarm_Off){

	AA_State_Id =AA_Alarm_Off ;
	Set_Alarm_actuator(0) ;
	AA_State = STATE(AA_Waiting);

}


void AA_Start_Alarm()
{
	AA_State = STATE(AA_Alarm_On);
}


void AA_Stop_Alarm()
{
	AA_State = STATE(AA_Alarm_Off) ;
}
