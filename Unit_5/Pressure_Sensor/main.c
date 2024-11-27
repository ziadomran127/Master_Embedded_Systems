/*
 ============================================================================
 Name        : Pressure_Detection_LearnInDepth.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "driver.h"
#include "Pressure_Sensor.h"
#include "Alarm_Actuator.h"
#include "Alarm_Montor.h"
#include "mainALgo.h"

void(*PS_State)() = STATE(PS_Init) ;
void(*AA_State)() = STATE(AA_Init);
void(*AM_State)() = STATE(AM_Alarm_Off) ;
void(*MA_State)() = STATE(MA_HIGH_PRESSURE) ;



int main(void) {

	GPIO_INITIALIZATION ();

	while(1)
	{
		PS_State() ;
		AA_State() ;
		AM_State() ;
		MA_State() ;

	}
	return 0;

}
