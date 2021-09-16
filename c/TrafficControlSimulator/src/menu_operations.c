#include <stdio.h>
#include <allegro5/allegro5.h>

#include "airport.h"
#include "operations.h"
#include "simulation.h"
#include "aux_functions.h"

#define MAX_DIMENSION 100


/*
 * Presents all available options user is able to perform
 */
void present_menu(int n) {
	if (n == 1){
		printf("\n\t0 – Exit\n");
		printf("\t1 – Airport presentation\n");
		printf("\t2 – Air Traffic control\n");
		printf("Option: ");
	}
	else if (n == 2){
		printf("\n\nChoose the number of the option shown in the list below:\n");
		printf("\t0 – Back to previous menu\n");
		printf("\t1 – Load simulation state\n");
		printf("\t2 – List airplanes by identification\n");
		printf("\t3 – Add airplane\n");
		printf("\t4 – Remove airplane\n");
		printf("\t5 - Store simulation state\n");
		printf("\t6 – Run ATC simulation\n");
		printf("Option: ");
	}
}

/*
 * Performs an operation depending the the user's option
 */
void air_traffic_control(struct airport *airport){
	char option[1], input[MAX_DIMENSION];
	struct airplane_list *list = list_create(); 
	load_simulation_state("simulation_state.txt", list, airport); /* remover!!! */
				list_toString(list);
				list_airplanes_by_id(list);
	do{
		present_menu(2);
		fgets(option, MAX_DIMENSION, stdin);
		switch (option[0]){
			case '0':
				break;
			case '1':
				printf("Type the file's name from where you wish to load the simulation: ");
				fgets(input, MAX_DIMENSION, stdin);
				process_string(input);
				load_simulation_state(input, list, airport);
				break;
			case '2':
				list_airplanes_by_id(list);
				break;
			case '3':
				add_airplane(list, airport);
				break;
			case '4':
				remove_airplane(list);
				break;
			case '5':
				printf("store_simulation_state()");
				break;
			case '6':
				run_atc_simulation(list, airport);
				break;
			default:
				printf("Unknown Option\n");
		}
	}
	while (option[0] != '0');
}
