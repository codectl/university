#include <stdlib.h>
#include <stdio.h>

#include "structs.h"

AIRPLANE *create_airplane(
    int id,
    int altitude,
	int speed,
	int orientation,
	int ref_speed,
	int ref_altitude,
	int ref_orientation,
	float position_x,
	float position_y,
	RUNWAY *departure_runway,
	RUNWAY *arrival_runway,
	GATE *departure_gate,
	GATE *arrival_gate
) {
	AIRPLANE *airplane = (AIRPLANE *) malloc(sizeof(AIRPLANE));
	if (airplane == NULL || sizeof(*airplane) != sizeof(AIRPLANE)) {
		printf("Error creating airplane ...\n");
		exit(1);
	}

	airplane->id = id;
	airplane->altitude = altitude;
	airplane->speed = speed;
	airplane->orientation = orientation;
	airplane->ref_altitude = ref_altitude;
	airplane->ref_speed = ref_speed;
	airplane->ref_orientation = ref_orientation;
	airplane->position_x = position_x;
	airplane->position_y = position_y;
	airplane->departure_runway = departure_runway;
	airplane->arrival_runway = arrival_runway;
	airplane->departure_gate = departure_gate;
	airplane->arrival_gate = arrival_gate;

    printf("Airplane '%d' created.\n", id);
	return airplane;
}

void destroy_airplane(AIRPLANE *airplane) {
	if(airplane == NULL || sizeof(*airplane) != sizeof(AIRPLANE)) {
		printf("Invalid input ...\n");
		exit(1);
	}

	int id = airplane->id;
	free(airplane);
    printf("Airplane '%d' destroyed.\n", id);
}

void airplane_toString(AIRPLANE *airplane) {
	printf("******************************\n");
	printf("ID: %d\n", airplane->id);
	printf("POSITION X: %f\n", airplane->position_x);
	printf("POSITION Y: %f\n", airplane->position_y);
	printf("SPEED: %d\n", airplane->speed);
	printf("ALTITUDE: %d\n", airplane->altitude);
	printf("ORIENTATION: %d\n", airplane->orientation);
	printf("REF_SPEED: %d\n", airplane->ref_speed);
	printf("REF_ALTITUDE: %d\n", airplane->ref_altitude);
	printf("REF_ORIENTATION: %d\n", airplane->ref_orientation);
    printf("DEPARTURE RUNWAY: %d\n", airplane->departure_runway->id);
    printf("DEPARTURE GATE: %d\n", airplane->departure_gate->number);
    printf("ARRIVAL RUNWAY: %d\n", airplane->arrival_runway->id);
    printf("ARRIVAL GATE: %d\n", airplane->arrival_gate->number);
	printf("\n");
}
