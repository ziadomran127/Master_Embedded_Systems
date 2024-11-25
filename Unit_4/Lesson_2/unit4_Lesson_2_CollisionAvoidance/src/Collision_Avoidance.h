/*
 * CA.h
 *
 *  Created on: Oct 27, 2024
 *      Author: LEGION
 */

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_

#include "State.h"

 enum {
	CA_Waiting ,
	CA_Driving
}CA_State_Id;


STATE_define(CA_Waiting) ;
STATE_define(CA_Driving) ;

extern void (*CA_State)();
#endif /* COLLISION_AVOIDANCE_H_ */
