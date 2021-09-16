#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <string.h>

#include "structs.h"
#include "runway.h"
#include "gate.h"
#include "aux_functions.h"


#define MAX_DIMENSION 100
#define PATTERN_SIZE_X 640
#define PATTERN_SIZE_Y 480


/*
 * Creates new airport
 * Returns NULL, in case of error
 */
struct airport *airport_create(char *file_name){
	
	/* declaration of all variables */
	FILE *file;
	char next_line[MAX_DIMENSION];
	char copy[MAX_DIMENSION], aux[MAX_DIMENSION], color_aux[MAX_DIMENSION];
    	char *tok;
	int count_gates = 0, count_runways = 0, i, n_gates, n_runways;
	struct airport *airport = (struct airport *) malloc (sizeof (struct airport));
	
	/* variables to airport */
	int x, y, z;

	/* variables to runway */
	float x0, y0, x1, y1;
	int id_runway, width_runway, n_marks, mark_arrow;
	int alt_runway, spd_runway, gen_1, gen_2;
	char gen_type[MAX_DIMENSION];

	/* variables to gate */
	char type_gate[MAX_DIMENSION];
	float position_x_gate, position_y_gate, *points;
	int number_gate, size_gate, width_gate, orientation_gate;
	int alt_gate, spd_gate;
	int n_points = 0;


	if (airport == NULL || sizeof(*airport) != sizeof(struct airport)) return NULL;

	n_gates = gate_count(file_name);
	n_runways = runway_count(file_name);
	airport->n_gates = n_gates;
	airport->n_runways = n_runways;
	airport->gates = (struct gate **) malloc (sizeof (struct gate *) * n_gates);
	airport->runways = (struct runway **) malloc (sizeof (struct runway *) * n_runways);
	if ((file = fopen(file_name, "r")) == NULL){
		printf("Erro na abertura do ficheiro.\n");
		printf("Nao foi possivel efectuar a representacao do aeroporto\n");
		return NULL;
	}
	
	while(!feof(file)){
		fgets(next_line, MAX_DIMENSION, file); /* there is a '\n' attached to the end */
		strcpy(copy, next_line);
		tok = strtok(next_line, " ");
		if(!strcmp(tok, "AIRPORT_SPACE")) {
			sscanf(copy,"%s %d %d %d %s\n", aux, &x, &y, &z, color_aux);
			airport->x = x;
			airport->y = y;
			airport->z = z;
			airport->color = color_to_int(color_aux);
			fgets(next_line, MAX_DIMENSION, file);
		}
		else if(!strcmp(tok, "RUNWAY")) {
			if(count_runways < n_runways){
				sscanf(copy,"%s %d %f %f %f %f %d %s\n", aux, &id_runway, &x0, &y0, &x1, &y1, &width_runway, color_aux);
				if(exists_runway(count_runways, id_runway, airport)){
					printf("A runway %d que pretende adicionar ja existe\n", id_runway);
					continue;
				}
				fgets(next_line, MAX_DIMENSION, file);
				sscanf(next_line,"%s %d %d\n", aux, &n_marks, &mark_arrow);
				fgets(next_line, MAX_DIMENSION, file);
				sscanf(next_line,"%s %d\n", aux, &alt_runway);
				fgets(next_line, MAX_DIMENSION, file);
				sscanf(next_line,"%s %d\n", aux, &spd_runway);
				fgets(next_line, MAX_DIMENSION, file);
				sscanf(next_line,"%s %s %d %d\n", aux, gen_type, &gen_1, &gen_2); 
				airport->runways[count_runways] = runway_create(id_runway, x0, y0, x1, y1, width_runway, color_to_int(color_aux),
							       n_marks, mark_arrow, alt_runway, spd_runway, gen_1, gen_2, gen_type[0]);
				count_runways++;
			}
		}
		else if(!strcmp(tok, "GATE")){
			if (count_gates < n_gates){
				sscanf(copy,"%s %s %d %f %f %d %d %d %s\n", aux, type_gate, &number_gate, &position_x_gate, 
				       &position_y_gate, &orientation_gate, &width_gate, &size_gate, color_aux);
				if(exists_gate(count_gates, number_gate, type_gate[0], airport)){
					printf("A %s gate %d que pretende adicionar ja existe\n", type_gate, number_gate);
					continue;
				}
				fgets(next_line, MAX_DIMENSION, file);
				sscanf(next_line,"%s %d\n", aux, &alt_gate);
				fgets(next_line, MAX_DIMENSION, file);
				sscanf(next_line,"%s %d\n", aux, &spd_gate);
				if(!strcmp(type_gate, "ARRIVAL")){
					fgets(next_line, MAX_DIMENSION, file);
					sscanf(next_line,"%s %s %d %d\n", aux, gen_type, &gen_1, &gen_2); 
					fgets(next_line, MAX_DIMENSION, file);
					if(strcmp(next_line, "\n")){ /* there is a ROUTE to be read */
						sscanf(next_line,"%s %d\n", aux, &n_points);
						points = (float *) malloc (sizeof (float) * n_points * 2);
						for(i=0; i<n_points * 2; i+=2){
							fgets(next_line, MAX_DIMENSION, file);
							sscanf(next_line,"%f %f\n", &points[i], &points[i+1]);
						}
						airport->gates[count_gates] = new_gate(type_gate[0], number_gate, position_x_gate,
						position_y_gate, size_gate, width_gate, orientation_gate, color_to_int(color_aux),		
						alt_gate, spd_gate, n_points, points, gen_1, gen_2, gen_type[0]);
						free(points);
						points = NULL;	
					}
					else{ /* there is no routes to be read */
						airport->gates[count_gates] = new_gate(type_gate[0], number_gate, position_x_gate,
						position_y_gate, size_gate, width_gate, orientation_gate, color_to_int(color_aux),		
						alt_gate, spd_gate, 0, NULL, gen_1, gen_2, gen_type[0]);

					}
				}
				else{ /* DEPARTURE gate */
					airport->gates[count_gates] = new_gate(type_gate[0], number_gate, position_x_gate,
					position_y_gate, size_gate, width_gate, orientation_gate, color_to_int(color_aux),		
					alt_gate, spd_gate, 0, NULL, 0, 0, '*');

				}
				count_gates++;
			}
		}
	}
	fclose(file);
	
	return airport;
}


/*
 * Erases all the memory allocated to an airport struct
 * Return -1 if error, 0 if succeded
 */
int airport_destroy(struct airport *airport){
	int i;
	if(airport == NULL || sizeof(*airport) != sizeof(struct airport)){
		printf("Erro ao eliminar aeroporto\n");
		return -1;
	}
	for(i=0; i<airport->n_runways; i++)
		if(runway_destroy(airport->runways[i]) == -1) 
			return -1;
	for(i=0; i<airport->n_gates; i++)
		if(gate_destroy(airport->gates[i]) == -1)
			return -1;
	free(airport->runways);
	free(airport->gates);
	free(airport);
	return 0;
}



/*
 * Gives a textual representation of an airport struct
 */
void airport_toString(struct airport *airport){
	int i;
	printf("\n");
	printf("*********************************************************** \n");
	printf("*************** AIRPORT TEXTUAL DESCRIPTION *************** \n");
	printf("*********************************************************** \n");
	printf("SCALE: %d %d %d; Color (int): %d\n", airport->x, airport->y, airport->z, airport->color);
	for(i=0; i<airport->n_runways; i++)
		runway_toString(airport->runways[i]);
	for(i=0; i<airport->n_gates; i++)
		gate_toString(airport->gates[i]);
	printf("\n");
	printf("*********************************************************** \n");
	printf("\n");
}


void airport_presentation(struct airport *airport){

	int convert_x, convert_y;
	int i, j;
	BITMAP *text;

	airport_toString(airport);
	allegro_init();
	install_keyboard(); /* Initializes keyboard routines */
	install_mouse(); /* Initializes mouse routines */
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, PATTERN_SIZE_X, PATTERN_SIZE_Y, 0, 0);
	rectfill(screen, 0, 0, PATTERN_SIZE_X, PATTERN_SIZE_Y, airport->color);  /* Background color */
	
	convert_x = PATTERN_SIZE_X/airport->x; /* convert nmi's into pixels */
	convert_y = PATTERN_SIZE_Y/airport->y;

	/* Drawing the runway */
	for (i=0; i<airport->n_runways; i++){
		rectfill(screen, airport->runways[i]->x0 * convert_x, airport->runways[i]->y0 * convert_y - airport->runways[i]->width/2,
			airport->runways[i]->x1 * convert_x, airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2, airport->runways[i]->color);
		if(airport->runways[i]->x1 > airport->runways[i]->x0){ /* orientation of the runway comes from the left */
			for(j=0; j<airport->runways[i]->n_marks; j++)
				circlefill(screen, airport->runways[i]->x0 * convert_x - convert_x * (j+1), airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2, airport->runways[i]->width/2, 1); /* Runway approaching marks */
			line(screen, airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow, 
			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
			     (airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5,
			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
			line(screen, airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow, 
			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
			     (airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5,
			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) + ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
	

			/* Details about the runway */
			text = create_bitmap(PATTERN_SIZE_X, PATTERN_SIZE_X);
			clear(text);
			textprintf_centre_ex(text, font, airport->runways[i]->x1 * convert_x + convert_x, 
				airport->runways[i]->y1 * convert_y, 7, -1, "R%d:%d/%d", airport->runways[i]->id, airport->runways[i]->alt, airport->runways[i]->spd);
			pivot_sprite(screen, text, airport->runways[i]->x1 * convert_x + convert_x, 
				airport->runways[i]->y1 * convert_y,
				airport->runways[i]->x1 * convert_x + convert_x, 
				airport->runways[i]->y1 * convert_y + convert_y, itofix(64));
			clear(text);
			textprintf_centre_ex(text, font, airport->runways[i]->x0 * convert_x - airport->runways[i]->mark_arrow * convert_x, 
				airport->runways[i]->y0 * convert_y, 7, -1, "ALT:3000  SPD:200");
			pivot_sprite(screen, text, airport->runways[i]->x0 * convert_x - airport->runways[i]->mark_arrow * convert_x, 
				airport->runways[i]->y0 * convert_y,
				airport->runways[i]->x0 * convert_x - airport->runways[i]->mark_arrow * convert_x, 
				airport->runways[i]->y0 * convert_y + convert_y, itofix(64));
	

		}
		else{ /* orientation of the runway comes from the right */
			for(j=0; j<airport->runways[i]->n_marks; j++)
				circlefill(screen, airport->runways[i]->x0 * convert_x + convert_x * (j+1), airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2, airport->runways[i]->width/2, 1);	
			line(screen, airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow, 
			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
			     (airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow) + convert_x * 1.5,
			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
			line(screen, airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow, 
			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
			     (airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow) + convert_x * 1.5,
			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) + ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
		}
	}

	/* Drawing GATES */
	for (i=0; i<airport->n_gates; i++){
		rectfill(screen, airport->gates[i]->position_x * convert_x, airport->gates[i]->position_y * convert_y,
			 airport->gates[i]->position_x * convert_x + airport->gates[i]->size * convert_x,
			 airport->gates[i]->position_y * convert_y + airport->gates[i]->width * convert_y,
			 airport->gates[i]->color);

		if(airport->gates[i]->width > airport->gates[i]->size){
			text = create_bitmap(PATTERN_SIZE_X, PATTERN_SIZE_X);
			clear(text);
			if(airport->gates[i]->type == 'A'){
				textprintf_centre_ex(text, font, airport->gates[i]->position_x * convert_x, 
					(airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width/2) * convert_y, 
					7, -1, "AR%d; %d/%d", airport->gates[i]->number, 
					airport->gates[i]->alt, airport->gates[i]->spd);
			}
			else
				textprintf_centre_ex(text, font, airport->gates[i]->position_x * convert_x, 
					(airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width/2) * convert_y, 
					7, -1, "DEP%d; %d/%d", airport->gates[i]->number, 
					airport->gates[i]->alt, airport->gates[i]->spd);
		 	pivot_sprite(screen, text, airport->gates[i]->position_x * convert_x, 
				    (airport->gates[i]->position_y * convert_y),
				    airport->gates[i]->position_x * convert_x - airport->gates[i]->size/2 * convert_x * 0.75, 
				    (airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width) * convert_y * airport->gates[i]->size * 0.7, itofix(64));
		}
		else{
			if(airport->gates[i]->type == 'A')
				textprintf_centre_ex(screen, font, airport->gates[i]->position_x * convert_x + airport->gates[i]->size/2 * convert_x, 
						(airport->gates[i]->position_y * convert_y - convert_y * 0.75), 
						7, -1, "AR%d; %d/%d", airport->gates[i]->number, 
						airport->gates[i]->alt, airport->gates[i]->spd);

			else
				textprintf_centre_ex(screen, font, airport->gates[i]->position_x * convert_x + airport->gates[i]->size/2 * convert_x, 
						(airport->gates[i]->position_y * convert_y - convert_y * 0.75), 
						7, -1, "DEP%d; %d/%d", airport->gates[i]->number, 
						airport->gates[i]->alt, airport->gates[i]->spd);
		}

		/* Drawing points */
		for (j=0; j<airport->gates[i]->n_points * 2; j+=2){
			if (j>0)
				line(screen, airport->gates[i]->points[j] * convert_x, 
				airport->gates[i]->points[j+1] * convert_y, 
				airport->gates[i]->points[j-2] * convert_x, 
				airport->gates[i]->points[j-1] * convert_y, 9);
			else{
				if(airport->gates[i]->width > airport->gates[i]->size){
					line(screen, closest_distance(airport->gates[i]->position_x, airport->gates[i]->position_x + airport->gates[i]->size, airport->gates[i]->points[j]) * convert_x,
					(airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width/2) * convert_y,
					airport->gates[i]->points[j] * convert_x,
					airport->gates[i]->points[j+1] * convert_y, 9);

				}

				else{
					line(screen, (airport->gates[i]->position_x * convert_x) + (airport->gates[i]->size/2) * convert_x,
					closest_distance(airport->gates[i]->position_y, airport->gates[i]->position_y + airport->gates[i]->width, airport->gates[i]->points[j+1]) * convert_y,
					airport->gates[i]->points[j] * convert_x,
					airport->gates[i]->points[j+1] * convert_y, 9);
				}
			}
			circlefill(screen, airport->gates[i]->points[j] * convert_x,
				  airport->gates[i]->points[j+1] * convert_y, convert_y/2, 9); 
		}
	}
	while (!key[KEY_ESC]){  
		if(mouse_b & 1) break;
	} 
 	allegro_exit();
}











