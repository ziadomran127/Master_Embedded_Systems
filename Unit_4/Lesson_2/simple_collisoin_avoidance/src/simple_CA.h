/*
 * simple_CA.h
 *
 *  Created on: Nov 8, 2024
 *      Author: LEGION
 */
#include "state.h"
#ifndef SIMPLE_CA_H_
#define SIMPLE_CA_H_

enum {
	CA_Waiting ,
	CA_Driving
}CA_State_Id;


STATE_define(CA_Waiting) ;
STATE_define(CA_Driving) ;

extern void (*CA_State)();

#endif /* SIMPLE_CA_H_ */
