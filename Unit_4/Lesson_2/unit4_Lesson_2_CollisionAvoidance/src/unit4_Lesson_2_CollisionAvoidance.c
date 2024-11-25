/*
 ============================================================================
 Name        : unit4_Lesson_2_CollisionAvoidance.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "Collision_Avoidance.h"
#include "US_Sensor.h"
#include "DC_Motor.h"
#include <stdio.h>
#include <stdlib.h>

void setup()
{
	US_Init() ;
	DC_init() ;


	CA_State = STATE (CA_Waiting) ;
	US_State = STATE (US_busy)    ;
	DC_state = STATE (DC_idle)    ;
}

int main(void) {
setup() ;


while(1)
{
	US_State();
	CA_State();
	DC_state();
}
	return EXIT_SUCCESS;
}
