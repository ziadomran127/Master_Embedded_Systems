/*
 * DC_Motor.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Ziad abdelhakeem 
 */

#include<stdio.h>
#include<stdlib.h>
#include "DC_Motor.h"

unsigned int speed ;
void (*DC_state)() ;

void DC_init()
{
    DPRINTF("DC_init\n") ;
}

void DC_Motor(int s)
{
    speed = s ;
    DC_state = STATE(DC_busy) ;
    DPRINTF("CA -> -> -> -> DC   DC_motor() \n") ;

}
STATE_define(DC_idle)
{
    DC_state_id = DC_idle ;
    DC_state = STATE(DC_idle) ;
    DPRINTF("DC_idle state : speed= %d \n \n" , speed) ;
}


STATE_define(DC_busy)
{
    DC_state_id = DC_busy ;

    DC_state = STATE(DC_idle) ;
    DPRINTF("DC_busy state : speed=%d \n\n\n" , speed) ;
}



