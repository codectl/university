#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

#define MAX_DIMENSION 100

/*
 * Creates new gate
 * Returns NULL, in case of error
 */
struct gate *new_gate(char type, int number, float position_x, float position_y,
		      int size, int width, int orientation, int color,
		      int alt, int spd, int n_points, float *points, int gen_1, int gen_2, char gen_type){
	
	struct gate *gate = (struct gate *) malloc (sizeof (struct gate));
	int i;

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
	else{
		gate->points = (float *) malloc(sizeof (float) * n_points * 2);
		for(i=0; i < n_points * 2; i++)
			gate->points[i] = points[i];
	}
	gate->gen_1 = gen_1;
	gate->gen_2 = gen_2;
	gate->gen_type = gen_type;
	return gate;
}

/*
 * Erases all the memory allocated to a gate struct
 * Return -1 if error, 0 if succeded
 */
int gate_destroy(struct gate *gate){
	if(gate == NULL || sizeof(*gate) != sizeof(struct gate)) return -1;
	free(gate->points);
	free(gate);
	return 0;
}


/*
 * Count the number of represented gates in a file
 */
int gate_count(char *file_name){
	FILE *file;
	char next_line[MAX_DIMENSION], *tok;
	int count = 0;

	if ((file = fopen(file_name, "r")) == NULL){
		printf("Erro na abertura do ficheiro.\n");
		return -1;
	}

	fgets(next_line, MAX_DIMENSION, file);
	tok = strtok(next_line, " ");
	while (!feof(file)) {
		fgets(next_line, MAX_DIMENSION, file);
		tok = strtok(next_line, " ");
		if(!strcmp(tok, "GATE"))
			count++;
	}
	fclose(file);
	return count;
}

/*
 * Checks whether a gate already exists
 * Return 1 if true, false otherwise
 */
int exists_gate(int n_gates, int id_gate, char type_gate, struct airport *airport){
	int i;
	for(i=0; i<n_gates;i++)
		if(airport->gates[i]->number == id_gate && airport->gates[i]->type == type_gate)
			return 1;
	return 0;
}

/*
 * Finds a specific gate within a certain number of gates
 * Return NULL if didn't find it
 */
struct gate *find_gate(int id_gate, char type_gate, struct airport *airport){
	int i;
	for(i=0; i<airport->n_gates; i++)
		if(airport->gates[i]->number == id_gate && airport->gates[i]->type == type_gate)
			return airport->gates[i];
	return NULL;
}

/*
 * Gives a textual representation of a gate struct
 */
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



