/*
 ============================================================================
 Name        : simple_collisoin_avoidance.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "state.h"
#include "simple_CA.h"
void setup()
{
	CA_State = STATE (CA_Waiting) ;
}

int main(void) {

	 volatile int delay ;
	    setup() ;
	    while(1)
	    {
	    	CA_State() ;
	        for(delay = 0 ; delay<= 1000 ; delay++) ;
	    }
	    return 0 ;
}
