#include <stdio.h>
#include <stdlib.h>
#include "TemperatureHandler.h"

void trafficLightHandler(int * speed){
	char tState;
	printf("Enter the traffic light state:\n");
	printf("G: green\nO: yellow\nR: red\n");
	fflush(stdout);
	scanf(" %c",&tState);
	switch(tState){
	case 'G':
	case 'g':
		*speed=100;
		break;
	case 'O':
	case 'o':
		*speed=30;
		break;
	case 'R':
	case 'r':
		*speed=0;
		break;
	default:
		printf("Enter G, O or R only.\n");
		trafficLightHandler(speed);
		break;
	}
}
