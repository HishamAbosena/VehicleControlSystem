#include <stdio.h>
#include <stdlib.h>
#include "VehicleStates.h"
#include "OptionsDispalying.h"
#include "TurnOnMenuDisplay.h"

int main(void) {
	//	2 lines from the docs to i/o with a user
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//	Variables declaration:
	vehicleStates state;

	//	Displaying the system options and taking the input:
	displayOptions((int *)&state);

	//	processing the input:
	while(state!=quitSystem){
		if(state==quitSystem||state==turnOn||state==turnOff)
			if(state==turnOff)
				displayOptions((int*)&state);
			else
				while(state==turnOn)
					displayMenu((int *)&state);

		else{
			printf("Enter 1, 2 or 3\n");
			displayOptions((int *)&state);
		}
	}
	printf("System finished.\n");

	return EXIT_SUCCESS;
}
