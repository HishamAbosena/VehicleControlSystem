#include <stdio.h>
#include <stdlib.h>
#include "VehicleStates.h"

void engineTempControl(ACStates * state,float *temperature){
	printf("Enter the engine temperature:\n");
	fflush(stdout);
	scanf("%f",temperature);
	if(*temperature<100){
		*state=on;
		*temperature=125;
	}
	else if(*temperature>150){
		*state=on;
		*temperature=125;
	}
	else
		*state=off;
}
