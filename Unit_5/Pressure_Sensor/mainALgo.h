/*
 * mainALgo.h
 *
 *  Created on: Nov 23, 2024
 *      Author: LEGION
 */



#ifndef MAINALGO_H_
#define MAINALGO_H_

#include "States.h"

enum
{
	MA_HIGH_PRESSURE
}MA_Id;

STATE_define(MA_HIGH_PRESSURE);

extern void (*MA_State)();

#endif /* MAINALGO_H_ */
