#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structs.h"
#include "runway.h"

#define MAX_DIMENSION 100

RUNWAY *create_runway(
    int id,
    float x0,
    float y0,
    float x1,
    float y1,
    int width,
	int color,
	int n_marks,
	int mark_arrow,
	int altitude,
	int speed,
    int gen_1,
    int gen_2,
    char gen_type
) {
	RUNWAY *runway = (RUNWAY *) malloc(sizeof(RUNWAY));
	if (runway == NULL || sizeof(*runway) != sizeof(RUNWAY)) {
		printf("Error creating runway ...\n");
		exit(1);
	}

	runway->id = id;
	runway->x0 = x0;
	runway->y0 = y0;
	runway->x1 = x1;
	runway->y1 = y1;
	runway->width = width;
	runway->color = color;
	runway->n_marks = n_marks;
	runway->mark_arrow = mark_arrow;
	runway->altitude = altitude;
	runway->speed = speed;
	runway->gen_1 = gen_1;
	runway->gen_2 = gen_2;
	runway->gen_type = gen_type;

    printf("Runway '%d' created.\n", id);
	return runway;
}

RUNWAY *get_runway(AIRPORT *airport, int id) {
	int i;
	for(i=0; i<airport->n_runways; i++)
		if(airport->runways[i]->id == id)
			return airport->runways[i];
	return NULL;
}

void destroy_runway(RUNWAY *runway) {
	if(runway == NULL || sizeof(*runway) != sizeof(RUNWAY)) {
		printf("Invalid input ...\n");
		exit(1);
	}

	int id = runway->id;
	free(runway);
    printf("Runway '%d' destroyed.\n", id);
}

int count_runways(char *filename) {
	FILE *file;
	char next_line[MAX_DIMENSION], *token;
	int count = 0;

	if ((file = fopen(filename, "r")) == NULL){
		printf("Error opening file ...\n");
        exit(1);
	}

	fgets(next_line, MAX_DIMENSION, file);
	token = strtok(next_line, " ");
	while (!feof(file)) {
		fgets(next_line, MAX_DIMENSION, file);
		token = strtok(next_line, " ");
		if(!strcmp(token, "RUNWAY"))
			count++;
	}
	fclose(file);

	return count;
}

int exists_runway(AIRPORT *airport, int n, int id){
	int i;
	for(i = 0; i < n; i++)
		if(airport->runways[i]->id == id)
			return 1;
	return 0;
}

void runway_toString(RUNWAY *runway){
	printf("\n");
	printf("ID: %d\n", runway->id);
	printf("Direction given by (%f,%f) and (%f,%f)\n", runway->x0, runway->y0, runway->x1, runway->y1);
	printf("Width: %d; Color (int): %d\n", runway->width, runway->color);
	printf("Marks number and selected mark: %d %d\n", runway->n_marks, runway->mark_arrow);
	printf("Altitude : %d\n", runway->altitude);
	printf("Speed: %d\n", runway->speed);
	printf("Generation type and its parameters: %c %d %d\n", runway->gen_type, runway->gen_1, runway->gen_2);
}
