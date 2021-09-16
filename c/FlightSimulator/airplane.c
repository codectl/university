#include <stdlib.h>
#include <stdio.h>

#include "structs.h"
#include "airplanes.h"

struct airplane *create_airplane(
    int id,
    int altitude,
	int speed,
	int orientation,
	int ref_speed,
	int ref_altitude,
	int ref_orientation,
	float position_x,
	float position_y,
	struct runway *origin_track,
	struct gate *origin_gate,
	struct runway *destiny_track,
	struct gate *destiny_gate
) {
	struct airplane *airplane = (struct airplane *) malloc (sizeof (struct airplane));
	if (airplane == NULL || sizeof(*airplane) != sizeof(struct airplane)){		
		printf("Error creating airplane ...\n");
		return NULL;
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
	airplane->origin_track = origin_track;
	airplane->origin_gate = origin_gate;
	airplane->destiny_track = destiny_track;
	airplane->destiny_gate = destiny_gate;

	return airplane;
}

int destroy_airplane(struct airplane *airplane){
	if(airplane == NULL || sizeof(*airplane) != sizeof(struct airplane)){
		printf("Invalid input ...\n");
		return -1;
	}
	free(airplane);
	return 0;
}

void airplane_toString(struct airplane *airplane){
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
    printf("DEPARTURE RUNWAY: %d\n", airplane->origin_track->id);
    printf("DEPARTURE GATE: %d\n", airplane->origin_gate->number);
    printf("ARRIVAL RUNWAY: %d\n", airplane->destiny_track->id);
    printf("ARRIVAL GATE: %d\n", airplane->destiny_gate->number);
	printf("\n");
}
