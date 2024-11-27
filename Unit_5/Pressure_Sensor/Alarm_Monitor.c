/*
 * Alarm_Monitor.c
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */

#include "driver.h"
#include "Alarm_Montor.h"

void(*AM_State)() ;

STATE_define(AM_Alarm_Off)
{
	AM_State_Id = AM_Alarm_Off ;
	AA_Stop_Alarm() ;

	if(MA_high_pressure_detected()==1)
	{AM_State = STATE(AM_Alarm_On) ; }

}

STATE_define(AM_Alarm_On)
{
	AM_State_Id = AM_Alarm_On ;
		AA_Start_Alarm() ;
		AM_State = STATE(AM_Waiting) ;
}


STATE_define(AM_Waiting)
{
	AM_State_Id = AM_Waiting ;
	Delay(500) ;
	AM_State = STATE(AM_Alarm_Off) ;
}
