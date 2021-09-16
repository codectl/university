#include <stdio.h>
#include <allegro5/allegro.h>
#include "airport.h"
#include "menu_operations.c"

#define AIRPORT_CONFIG "airport_configuration.txt"


int main(int argc, char *argv[]) {

	char option[1];
	struct airport *airport = airport_create(AIRPORT_CONFIG);

	air_traffic_control(airport); /* Remover */
	do {
		present_menu(1);
		fgets(option, MAX_DIMENSION, stdin);
		switch (option[0]){
			case '0':
				break;
			case '1':
				airport_presentation(airport);
				break;
			case '2':
				air_traffic_control(airport);
				break;
			default:
				printf("Opcao invalida\n");
		}
	}
	while (option[0] != '0');

	airport_destroy(airport);
	return 0;
}
