#include <stdio.h>
#include <stdlib.h>
#include "VehicleStates.h"
#include "TrafficLightHandler.h"
#include "TemperatureHandler.h"
#include "EngineTemperatureHandler.h"

#define WITH_ENGINE_TEMP_CONTROLLER 1

// Global variables declaration:
int vehicleSpeed=100;
float temperature=35;
float engineTemp=125;
ACStates airConditionerState = off;
ACStates engineTempController=off;

// prototype of displayMenu because I use it in handleMenu.
void displayMenu(int * state);
void displayVehicleState(int * state);

void printMenuOptions(char *option){
	printf("a)Turn off the engine.\n");
	printf("b)Set the traffic light color\n");
	printf("c)Set the room temperature\n");
	printf("d)Set the engine temperature\n");
	fflush(stdout);
	scanf(" %c",option);

}
void handleMenu(char *option,int *vState){

	switch (*option) {
	case 'a':
		*vState=turnOff;
		break;
	case 'b':
		trafficLightHandler(&vehicleSpeed);
		break;
	case 'c':
		tempHandler(&airConditionerState,&temperature);
		break;
#if WITH_ENGINE_TEMP_CONTROLLER
	case 'd':
		engineTempControl(&engineTempController,&engineTemp);
		break;
#endif
	default:
		printf("Enter a, b, c or d only.\n");
		displayMenu(vState);
		break;
	}
}

void displayMenu(int * state){
	char option;
	while (option!='a' && (vehicleStates)*state !=turnOff){
		printMenuOptions(&option);
		handleMenu(&option,state);
		if(vehicleSpeed==30){
			if(airConditionerState==off){
				airConditionerState=on;
				temperature=temperature*(5.0/4)+1;
				if(temperature>60){
					airConditionerState=off;
					printf("AC FAILURE!!! Open the windows!\n");
				}
			}
#if WITH_ENGINE_TEMP_CONTROLLER
			if(engineTempController==off){
				engineTempController=on;
				engineTemp=engineTemp*(5.0/4)+1;
				if(engineTemp>180){
					printf("WARNING!!! TURN OFF THE VEHICLE.\nThe vehicle is about to explode!\n");
					*state=turnOff;
				}
			}
#endif
		}
		displayVehicleState(state);
		fflush(stdout);
	}
}
void displayVehicleState(int * state){
	if((vehicleStates)*state!=turnOff){
		printf("- Engine is ON\n");
		if(airConditionerState==on)
			printf("- AC is ON\n");
		else
			printf("- AC is OFF\n");
		printf("- Vehicle Speed = %d\n",vehicleSpeed);
		printf("- Room Temperature = %0.2f C\n",temperature);
#if WITH_ENGINE_TEMP_CONTROLLER
		if(engineTempController==on)
			printf("- Engine Temperature Controller is ON\n");
		else
			printf("- Engine Temperature Controller is OFF\n");
		printf("- Engine Temperature = %0.2f C\n\n",engineTemp);
#endif
	}


}
