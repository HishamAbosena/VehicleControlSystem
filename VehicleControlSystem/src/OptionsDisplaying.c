#include <stdio.h>
#include <stdlib.h>

void displayOptions(int * state){
	char choice;
	printf("What do you want to do?\n");
	printf("a)Turn on the vehicle engine\n");
	printf("b)Turn off the vehicle engine\n");
	printf("c)Quit the system\n");
	fflush(stdout);
	scanf(" %c",&choice);
	switch(choice){
	case 'a':
		printf("Turn on the vehicle engine\n");
		*state=1;
		break;
	case 'b':
		printf("Turn off the vehicle engine\n");
		*state=2;
		break;
	case 'c':
		printf("Quit the system\n");
		*state=3;
		break;
	}
	fflush(stdout);
}
