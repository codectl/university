#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DIMENSION 100

GATE *create_gate(
    char type,
    int number,
    float position_x,
    float position_y,
    int size,
    int width,
    int orientation,
    int color,
    int alt,
    int spd,
    int n_points,
    float *points,
    int gen_1,
    int gen_2,
    char gen_type
){
	GATE *gate = (GATE *) malloc (sizeof(GATE));
    if (gate == NULL || sizeof(*gate) != sizeof(GATE)) {
        printf("Error creating gate ...\n");
        exit(1);
    }

	gate->type = type;
	gate->number = number;
	gate->position_x = position_x;
	gate->position_y = position_y;
	gate->size = size;
	gate->width = width;
	gate->orientation = orientation;
	gate->color = color;
	gate->alt = alt;
	gate->spd = spd;
	gate->n_points = n_points;
	if(n_points == 0)
		points = NULL;
	else {
	    int i;
		gate->points = (float *) malloc(sizeof (float) * n_points * 2);
		for(i = 0; i < n_points * 2; i++)
			gate->points[i] = points[i];
	}
	gate->gen_1 = gen_1;
	gate->gen_2 = gen_2;
	gate->gen_type = gen_type;

    printf("Gate '%d' created.\n", id);
	return gate;
}

GATE *get_gate(AIRPORT *airport, int id, char type){
	int i;
	for(i=0; i < airport->n_gates; i++)
		if(airport->gates[i]->number == id && airport->gates[i]->type == type)
			return airport->gates[i];
	return NULL;
}

void destroy_gate(GATE *gate){
	if(gate == NULL || sizeof(*gate) != sizeof(GATE)) {
		printf("Invalid input ...\n");
		exit(1);
	}

    int id = gate->id;
	free(gate->points);
	free(gate);
    printf("Gate '%d' destroyed.\n", id);
}

int count_gates(char *filename){
	FILE *file;
	char next_line[MAX_DIMENSION], *tok;
	int count = 0;

	if ((file = fopen(file_name, "r")) == NULL){
		printf("Error opening file ...\n");
        exit(1);
	}

	fgets(next_line, MAX_DIMENSION, file);
	token = strtok(next_line, " ");
	while (!feof(file)) {
		fgets(next_line, MAX_DIMENSION, file);
		token = strtok(next_line, " ");
		if(!strcmp(token, "GATE"))
			count++;
	}
	fclose(file);

	return count;
}

int exists_gate(AIRPORT *airport, int n, int id, char type){
	int i;
	for(i=0; i<n_gates;i++)
		if(airport->gates[i]->number == id && airport->gates[i]->type == type)
			return 1;
	return 0;
}

void gate_toString(struct gate *gate){
	int i, j;
	printf("\n");
	printf("GATE %d of type %c\n", gate->number, gate->type);
	printf("Position in coordinates (%f,%f)\n", gate->position_x, gate->position_y);
	printf("Orientation: %d; Width: %d; Size: %d; Color (int): %d\n", gate->orientation, gate->width, gate->size, gate->color);
	printf("Altidude : %d\n", gate->alt);
	printf("Speed : %d\n", gate->spd);
	for(i=0, j=0; i<gate->n_points; i++, j+=2)
		printf("Point %d with coordinate (%f,%f)\n", i+1, gate->points[j], gate->points[j+1]);
	if(gate->type == 'A')
		printf("Generation type and its parameters: %c %d %d\n", gate->gen_type, gate->gen_1, gate->gen_2);
}
