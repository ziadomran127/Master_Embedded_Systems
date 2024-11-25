/*
 * sinple_CA.c
 *
 *  Created on: Nov 8, 2024
 *      Author: LEGION
 */


#include "stdio.h"
#include "stdlib.h"
#include "simple_CA.h"

int CA_Speed = 0 ;
int CA_Distance = 0 ;
int CA_Threshold =50 ;

void (*CA_State)() ;

int US_Get_Distance_Random (int l , int r , int count);


STATE_define (CA_Waiting)
{
	 CA_State_Id = CA_Waiting ;
	CA_Speed = 0 ;
	CA_Distance = US_Get_Distance_Random(45 , 55 , 1);
	(CA_Distance<=CA_Threshold) ? (CA_State = STATE(CA_Waiting)) : (CA_State = STATE(CA_Driving));
	DPRINTF("CA_Waiting State : distance = %d Speed = %d\n", CA_Distance, CA_Speed);
}



STATE_define (CA_Driving)
{
	CA_State_Id = CA_Driving ;
	CA_Speed = 30 ;
	CA_Distance = US_Get_Distance_Random(45 , 55 , 1);
	(CA_Distance<=CA_Threshold) ? (CA_State = STATE(CA_Waiting)) : (CA_State = STATE(CA_Driving));
	DPRINTF("CA_Driving State : distance = %d Speed = %d\n", CA_Distance, CA_Speed);
}




int US_Get_Distance_Random(int l, int r, int count)
{
    return (rand() % (r - l + 1)) + l;
}

