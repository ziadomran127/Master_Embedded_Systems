/*
 * DC_Motor.h
 *
 *  Created on: Oct 29, 2024
 *      Author: LEGION
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "State.h"

enum {
    DC_idle,
    DC_busy
}DC_state_id;


void DC_Init() ;
STATE_define(DC_idle) ;
STATE_define(DC_busy) ;


extern void(*DC_state)() ;

#endif /* DC_MOTOR_H_ */
