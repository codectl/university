#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"
#include "airplanes.h"
#include "airplane_list.h"
#include "runway.h"
#include "gate.h"
#include "aux_functions.h"

#define MAX_DIMENSION 100
#define PI 3.14159265

/*
 * Reads the state of a simulation previously stored in a file
 */
void load_simulation_state(char *file_name, struct airplane_list *list, struct airport *airport){

	FILE *file;
	char next_line[MAX_DIMENSION], aux[MAX_DIMENSION], *tok;
	int airplane_id, alt, spd, orientation;
	int ref_spd, ref_alt, ref_orientation;
	float position_x, position_y;
	struct runway *origin_track, *destiny_track;
	struct gate *origin_gate, *destiny_gate;
	struct airplane *airplane;	


	if(list == NULL || sizeof(*list) != sizeof(struct airplane_list)) return;
	if ((file = fopen(file_name, "r")) == NULL){
		printf("Erro na abertura do ficheiro.\n");
		printf("Nao foi possivel efectuar o carregamento do estado da simulacao\n");
		return;
	}

	fgets(next_line, MAX_DIMENSION, file);
	while(!feof(file)){
		if (next_line[0] == '*')
			fgets(next_line, MAX_DIMENSION, file);
		else{
			sscanf(next_line,"%s %d\n", aux, &airplane_id);

			fgets(next_line, MAX_DIMENSION, file); /* defining origin */
			tok = strtok(next_line, " ");
			tok = strtok(NULL, "-");
			if(!strcmp(tok, "AR")){ /* ARRIVAL gate case */
				tok = strtok(NULL, "\n");
				origin_gate = find_gate(atoi(tok), 'A', airport);
				origin_track = NULL;
			}
			else{ /* Runway gate case */
				tok = strtok(NULL, "\n");
				origin_track = find_runway(atoi(tok), airport);
				origin_gate = NULL;
			}

			fgets(next_line, MAX_DIMENSION, file); /* defining destiny */
			tok = strtok(next_line, " ");
			tok = strtok(NULL, "-");
			if(!strcmp(tok, "DEP")){ /* DEPARTURE gate case */
				tok = strtok(NULL, "\n");
				destiny_gate = find_gate(atoi(tok), 'D', airport);
				destiny_track = NULL;

			}
			else{ /* Runway gate case */
				tok = strtok(NULL, "\n");
				destiny_track = find_runway(atoi(tok), airport);;
				destiny_gate = NULL;
			}

			fgets(next_line, MAX_DIMENSION, file); /* operation ??? */
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %f\n", aux, &position_x);
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %f\n", aux, &position_y);
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %d\n", aux, &spd);
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %d\n", aux, &alt);
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %d\n", aux, &orientation);
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %d\n", aux, &ref_spd);
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %d\n", aux, &ref_alt);
			fgets(next_line, MAX_DIMENSION, file);
			sscanf(next_line,"%s %d\n", aux, &ref_orientation);
			fgets(next_line, MAX_DIMENSION, file);

			airplane = airplane_creator(airplane_id, alt, spd, orientation, ref_spd, ref_alt, ref_orientation,
				  		    position_x, position_y, origin_track, origin_gate, destiny_track, destiny_gate);
			if (airplane == NULL) return;
			if(list_add(list, airplane) == -1) return;
		}
	}
	fclose(file);
}


/*
 * Gives a textual representation of airplanes ordered by destiny, altitude and distance to the destiny
 */
void list_airplanes(struct airplane_list *list, struct airport *airport){
	int i, j, min;
	struct node *ptr = list->head;
	struct sort_airplanes *sorting =  (struct sort_airplanes *) malloc (sizeof (struct sort_airplanes) * list_size(list));
	struct sort_airplanes aux;

	for(i=0; i<list_size(list); i++, ptr = ptr->next){ /* Fulfilling the array struct with the necessary data */
		sorting[i].id = ptr->ap->airplane_id;
		sorting[i].altitude = ptr->ap->alt;
		if(ptr->ap->destiny_track == NULL){
			sorting[i].distance = calculate_distance(ptr->ap->position_x, ptr->ap->position_y,
								closest_distance(ptr->ap->destiny_gate->position_x, ptr->ap->destiny_gate->position_x + ptr->ap->destiny_gate->size, ptr->ap->position_x),
								closest_distance(ptr->ap->destiny_gate->position_y, ptr->ap->destiny_gate->position_y + ptr->ap->destiny_gate->width, ptr->ap->position_y));
			sorting[i].id_destiny = ptr->ap->destiny_gate->number;
			sorting[i].type_destiny = ptr->ap->destiny_gate->type;
		}
		else{
			sorting[i].distance = calculate_distance(ptr->ap->position_x, ptr->ap->position_y,
								ptr->ap->destiny_track->x0, ptr->ap->destiny_track->y0);
			sorting[i].id_destiny = ptr->ap->destiny_track->id;
			sorting[i].type_destiny = 'R';
		}
	}
	for(i=0, min=0; i<list_size(list); i++, min=i){ /* Sorting having in count the airplane's type of destiny */
		for(j=i; j<list_size(list); j++)
			if(sorting[j].type_destiny < sorting[min].type_destiny)
				min = j;
		aux = sorting[i];
		sorting[i] = sorting[min];
		sorting[min] = aux;
	}

	for(i=0, min=0; i<list_size(list); i++, min=i){ /* Sorting having in count the id of the airplane's destiny */
		for(j=i; j<list_size(list); j++)
			if(sorting[j].id_destiny < sorting[min].id_destiny && sorting[j].type_destiny == sorting[i].type_destiny)
				min = j;
		aux = sorting[i];
		sorting[i] = sorting[min];
		sorting[min] = aux;
	}

	for(i=0, min=0; i<list_size(list); i++, min=i){ /* Sorting having in count the airplane's altitude */
		for(j=i; j<list_size(list); j++)
			if(sorting[j].altitude < sorting[min].altitude && sorting[j].type_destiny == sorting[i].type_destiny
			  && sorting[j].id_destiny == sorting[i].id_destiny)
				min = j;
		aux = sorting[i];
		sorting[i] = sorting[min];
		sorting[min] = aux;
	}

	for(i=0, min=0; i<list_size(list); i++, min=i){ /* Sorting having in count the distance to the destiny */
		for(j=i; j<list_size(list); j++)
			if(sorting[j].distance < sorting[min].distance && sorting[j].type_destiny == sorting[i].type_destiny
			  && sorting[j].id_destiny == sorting[i].id_destiny && sorting[j].altitude == sorting[min].altitude)
				min = j;
		aux = sorting[i];
		sorting[i] = sorting[min];
		sorting[min] = aux;
	}


	
	/* Listing airplanes ordered by destiny, altitude and distance to destiny */
	printf("     --- ORDERED AIRPLANE LIST --- \n");
	for(i=0; i<list_size(list); i++){
		printf("****************************** \n");
		printf("PLANE: %d\n", sorting[i].id);
		if(sorting[i].type_destiny == 'D')
			printf("DESTINY: DEPARTURE GATE-%d\n", sorting[i].id_destiny);
		else
			printf("DESTINY: RUNWAY-%d \n", sorting[i].id_destiny);
		printf("ALTITUDE: %d\n", sorting[i].altitude);
		printf("DISTANCE TO DESTINY: %f\n", sorting[i].distance);
		printf("\n");
	}
	free(sorting);
}


/*
 * Gives a textual representation of airplanes ordered their identities
 */
void list_airplanes_by_id(struct airplane_list *list){
	struct node *ptr = list->head;
	struct airplane *aux;
	int i, min, *sort = (int *) malloc (sizeof(int) * list_size(list)), swap = 1;
	for(i=0; i<list_size(list); i++, ptr = ptr->next) /* Fulfilling the array struct with the necessary data */
		sort[i] = ptr->ap->airplane_id;

	/* Bubble sorting algorithm */
	while(swap){
		swap = 0;
		for(i=1; i<list_size(list); i++){
			if(sort[i] < sort[i-1]){
				min = sort[i];
				sort[i] = sort[i-1];
				sort[i-1] = min;
				swap = 1;
			}
		}
	}

	printf(" *** List of airplanes ***\n");
	printf("(ordered by identification) \n");
	for(i=0; i<list_size(list); i++){ /* Ordered list printing */
		aux = find_airplane(list, sort[i]);
		airplane_toString(aux);
	}
	free(sort);
}



/*
 * Adds an airplane to the airplane's list
 * Airplane's parameters are defined by the user
 */
void add_airplane(struct airplane_list *list, struct airport *airport){
	int i, id, alt, spd, orientation, ref_spd, ref_alt, ref_orientation, id_origin, id_destiny, first_loop = 1, *id_total, count = 0;
	float position_x, position_y;
	char type, input[MAX_DIMENSION];
	struct runway *origin_track, *destiny_track;
	struct gate *origin_gate, *destiny_gate;
	struct node *ptr = list->head;

	do{
		if(!first_loop){
			printf("\n");
			printf("A aeronave que deseja adicionar ja existe.\n");
		}
		printf(" * Lista de aeronaves ja existentes * \n");
		for(i=0; i<list_size(list); i++, ptr = ptr->next)
			printf("Aeronave %d\n", ptr->ap->airplane_id);
		printf("Digite um identificador para a aeronave: ");
		fgets(input, MAX_DIMENSION, stdin);
		sscanf(input,"%d\n", &id);
		first_loop = 0;
	}
	while(exists_airplane(list, id));

	do{
		printf("\n");
		if(!first_loop)
			printf("Origem incorrecta, tente de novo de acordo com a lista apresentada\n");
		printf(" * Pontos de origem possiveis * \n");
		for(i=0; i<airport->n_runways; i++)
			printf("Pista de descolagem numero %d (R %d)\n", airport->runways[i]->id, airport->runways[i]->id);
		for(i=0; i<airport->n_gates; i++)
			if(airport->gates[i]->type == 'A')
				printf("Arrival gate numero: %d (A %d)\n", airport->gates[i]->number, airport->gates[i]->number);
		printf("Defina o tipo de origem (R para pista ou A para porta de entrada) \n");
		printf("seguido do identificador da porta de origem para a aeronave: ");
		fgets(input, MAX_DIMENSION, stdin);
		sscanf(input,"%c %d\n", &type, &id_origin);
		first_loop = 0;
	}
	while((type != 'A' && type != 'R') || (type == 'A' && !exists_gate(airport->n_gates, id_origin, type, airport)) || 
	      (type == 'R' && !exists_runway(airport->n_runways, id_origin, airport)));
	
	if(type == 'A'){ /* Gives the user the option to define the destiny */
		origin_gate = find_gate(id_origin, type, airport);
		origin_track = NULL;
		first_loop = 1;
		do{
			printf("\n");
			if(!first_loop)
				printf("Destino incorrecto, tente de novo de acordo com a lista apresentada\n");
			printf(" * Pontos de destino possiveis * \n");
			for(i=0; i<airport->n_runways; i++)
				printf("Pista de aterragem numero %d\n", airport->runways[i]->id);
			printf("Defina o numero da pista de aterragem para a aeronave: ");
			fgets(input, MAX_DIMENSION, stdin);
			sscanf(input,"%d\n", &id_destiny);
			first_loop = 0;
		}
		while(!exists_runway(airport->n_runways, id_destiny, airport));

		destiny_track = find_runway(id_destiny, airport);
		destiny_gate = NULL;
	
		position_x = origin_gate->position_x + (float) origin_gate->size/2;
		position_y = origin_gate->position_y + (float) origin_gate->width/2;
		alt = origin_gate->alt;
		spd = origin_gate->spd;
		if(origin_gate->n_points >= 2){
			orientation = atan2(origin_gate->points[1] - position_y, origin_gate->points[0] - position_x)*180/PI;
			orientation = (180 - orientation) + 180; /* y grows down side */
		}
		else
			orientation = origin_gate->orientation;
		ref_spd = spd;
		ref_alt = alt;
		ref_orientation = orientation;
		list_add(list, airplane_creator(id, alt, spd, orientation, ref_spd, ref_alt, ref_orientation,
			 position_x, position_y, origin_track, origin_gate, destiny_track, destiny_gate));
	}
	else{ /* Will choose the departure gate randomly */
		
		origin_track = find_runway(id_origin, airport);
		origin_gate = NULL;
		for(i=0; i<airport->n_gates; i++)
			if(airport->gates[i]->type == 'D')
				count++;
		id_total = (int *) malloc (sizeof(int) * count);
		for(i=0; i<airport->n_gates; i++)
			if(airport->gates[i]->type == 'D')
				id_total[i] = airport->gates[i]->number;
		destiny_gate = find_gate(id_total[rand()%(count-1)], 'D', airport);
		destiny_track = NULL;
		position_x = origin_track->x0 + ((origin_track->x1 - origin_track->x0)/2);
		position_y = origin_track->y0;
		alt = 0;
		spd = 0;
		orientation = 180;
		ref_spd = 200;
		ref_alt = 3000;
		ref_orientation = orientation;
		list_add(list, airplane_creator(id, alt, spd, orientation, ref_spd, ref_alt, ref_orientation,
			 position_x, position_y, origin_track, origin_gate, destiny_track, destiny_gate));
		free(id_total);
	}
}

/*
 * Allows user to remove a specific airplane
 */
void remove_airplane(struct airplane_list *list){
	char input[MAX_DIMENSION];
	int id, first_loop = 1;
	printf("Digite o identificador da aeronave que deseja remover: ");
	do{
		if(!first_loop){
			printf("\n");
			printf("A aeronave que pretende remover nao existe, tente de novo: ");
		}
		fgets(input, MAX_DIMENSION, stdin);
		sscanf(input,"%d\n", &id);
		first_loop = 0;
	}
	while(exists_airplane(list, id)==0);
	list_remove(list, id);
}



