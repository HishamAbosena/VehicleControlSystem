/*
 * TempratureHandler.h
 *
 *  Created on: Apr 15, 2024
 *      Author: mega
 */

#ifndef TEMPERATUREHANDLER_H_
#define TEMPERATUREHANDLER_H_
#include "VehicleStates.h"

void tempHandler(ACStates * state,float *temperature);
void tempSpeedHandler(float *temperature,int * speed);
#endif /* TEMPERATUREHANDLER_H_ */
