#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

#define MAX_DIMENSION 100

/*
 * Creates new runway
 * Returns NULL, in case of error
 */
struct runway *runway_create(int id, float x0, float y0, float x1, float y1, int width, 
			     int color, int n_marks, int mark_arrow, int alt, int spd,
			     int gen_1, int gen_2, char gen_type){

	struct runway *track = (struct runway *) malloc (sizeof (struct runway));
	if (track == NULL || sizeof(*track) != sizeof(struct runway)){
		printf("Erro ao criar pista de descolagem/aterragem\n");
		return NULL;
	}
	track->id = id;
	track->x0 = x0;
	track->y0 = y0;
	track->x1 = x1;
	track->y1 = y1;
	track->width = width;
	track->color = color;
	track->n_marks = n_marks;
	track->mark_arrow = mark_arrow;
	track->alt = alt;
	track->spd = spd;
	track->gen_1 = gen_1;
	track->gen_2 = gen_2;
	track->gen_type = gen_type;
	return track;
}


/*
 * Erases all the memory allocated to a runway struct
 * Return -1 if error, 0 if succeded
 */
int runway_destroy(struct runway *runway){
	if(runway == NULL || sizeof(*runway) != sizeof(struct runway)){
		printf("Erro ao eliminar pista de descolagem/aterragem\n");
		return -1;
	}
	free(runway);
	return 0;
}

/*
 * Count the number of represented runways in a file
 */
int runway_count(char *file_name){
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
		if(!strcmp(tok, "RUNWAY"))
			count++;
	}
	fclose(file);
	return count;
}

/*
 * Checks whether a runway already exists
 * Return 1 if true, false otherwise
 */
int exists_runway(int n_runways, int id_runway, struct airport *airport){
	int i;
	for(i=0; i<n_runways; i++)
		if(airport->runways[i]->id == id_runway)
			return 1;
	return 0;
}

/*
 * Finds a specific runway within a certain number of runway
 * Return NULL if didn't find it
 */
struct runway *find_runway(int id_runway, struct airport *airport){
	int i;
	for(i=0; i<airport->n_runways; i++)
		if(airport->runways[i]->id == id_runway)
			return airport->runways[i];
	return NULL;
}

/*
 * Gives a textual representation of a runway struct
 */
void runway_toString(struct runway *track){
	printf("\n");
	printf("RUNWAY: %d\n", track->id);
	printf("Direction given by (%f,%f) and (%f,%f)\n", track->x0, track->y0, track->x1, track->y1);
	printf("Width: %d; Color (int): %d\n", track->width, track->color);
	printf("Marks number and selected mark: %d %d\n", track->n_marks, track->mark_arrow);
	printf("Altidude : %d\n", track->alt);
	printf("Speed : %d\n", track->spd);
	printf("Generation type and its parameters: %c %d %d\n", track->gen_type, track->gen_1, track->gen_2);
}
