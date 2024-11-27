/*
 * States.h
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */

#ifndef STATES_H_
#define STATES_H_

#define DPRINTF(...)     {fflush(stdout); \
						  fflush(stdin); \
						  printf(__VA_ARGS__); \
						  fflush(stdout); \
						  fflush(stdin);}

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_

#include<stdio.h>
#include<stdlib.h>

#endif /* STATES_H_ */
