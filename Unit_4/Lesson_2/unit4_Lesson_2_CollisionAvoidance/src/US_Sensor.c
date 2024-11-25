/*
 * US_Sensor.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Ziad abdelhakeem
 */


#include "State.h"
#include "US_Sensor.h"
void(*US_State)() ;
unsigned int US_distance = 0 ;

int Generate_Random(int l , int r , int count){

	int i ;
	for(i=0 ; i<count ; i++){
		int Rand_num = (rand()%(r-l+1))+l ;
		return Rand_num ;
	}
}

void US_Init()
{
	DPRINTF("US_init\n") ;
}

STATE_define(US_busy)
{
	US_state_id = US_busy ;
	US_distance = Generate_Random(45,55,1) ;
	DPRINTF("US_busy state : distance = %d \n" , US_distance);
	US_Distance_Set( US_distance) ;
	US_State = STATE(US_busy) ;
}



