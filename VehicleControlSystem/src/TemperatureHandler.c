#include <stdio.h>
#include <stdlib.h>
#include "VehicleStates.h"

void tempHandler(ACStates * state,float * temperature){
	printf("Enter the room temperature:");
	fflush(stdout);
	scanf("%f",temperature);
	printf("\n");
	fflush(stdout);
	if(*temperature<10){
		*state= on;
		*temperature=20;
	}
	else if(*temperature>30){
		*state=on;
		*temperature=20;
	}
	else
		*state=off;
	if(*state)
		printf("AC is on\n");
}
void tempSpeedHandler(float *temperature,int * speed,ACStates *state){


}