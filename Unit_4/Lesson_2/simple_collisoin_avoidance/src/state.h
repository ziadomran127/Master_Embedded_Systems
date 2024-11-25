/*
 * state.h
 *
 *  Created on: Nov 8, 2024
 *      Author: LEGION
 */

#ifndef STATE_H_
#define STATE_H_

#define DPRINTF(...)     {fflush(stdout); \
						  fflush(stdin); \
						  printf(__VA_ARGS__); \
						  fflush(stdout); \
						  fflush(stdin);}

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_

#include<stdio.h>
#include<stdlib.h>
#endif /* STATE_H_ */



