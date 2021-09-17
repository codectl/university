#include <stdio.h>
#include <stdlib.h>

#include "models/structs.h"
#include "models/airplanes.h"

int main(int argc, char *argv[]) {

	AIRPORT *departure_airport;

	RUNWAY *departure_runway;
	RUNWAY *arrival_runway;

	GATE *departure_gate;
	GATE *arrival_gate;

	AIRPLANES *airplanes = init_airplanes();

//	add_airplane(airplanes, create_airplane(1, 100, 110, 20, 100, 110, 20, 50, 50, departure_runway, arrival_runway, departure_gate, arrival_gate));
	airplanes_toString(airplanes);
	remove_airplanes(airplanes);

	printf("Finish ... \n");

    exit(0);
}
