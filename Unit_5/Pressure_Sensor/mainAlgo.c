/*
 * mainAlgo.c
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */

#include "mainALgo.h"

void(*MA_State)() ;
static unsigned int MA_PVal  ;
static unsigned int MA_Threshold = 20 ;

STATE_define(MA_HIGH_PRESSURE)
{

	MA_Id = MA_HIGH_PRESSURE ;
	MA_PVal = PS_get_pressure_value() ;
	MA_State = STATE(MA_HIGH_PRESSURE);

}

unsigned int MA_high_pressure_detected(void)
{
	return (MA_PVal > MA_Threshold);
}
