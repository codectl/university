#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "runway.h"
#include "gate.h"
#include "../utils.c"

#define MAX_DIMENSION 100

AIRPORT *create_airport(char *filename){
	
	/* declaration of all variables */
//	char next_line[MAX_DIMENSION];
//	char copy[MAX_DIMENSION], aux[MAX_DIMENSION], color_aux[MAX_DIMENSION];
//	int gates_counter = 0, runways_counter = 0, i;
	AIRPORT *airport = (AIRPORT *) malloc (sizeof(AIRPORT));

	// variables to gate
//	char type_gate[MAX_DIMENSION];
//	float position_x_gate, position_y_gate, *points;
//	int number_gate, size_gate, width_gate, orientation_gate;
//	int alt_gate, spd_gate;
//	int n_points = 0;

    if (airport == NULL || sizeof(*airport) != sizeof(AIRPORT)) {
        printf("Error creating airplane ...\n");
        exit(1);
    }

	int n_gates = count_gates(filename);
	int n_runways = count_runways(filename);

	airport->n_gates = n_gates;
	airport->n_runways = n_runways;
	airport->gates = (GATE **) malloc (sizeof(GATE *) * n_gates);
	airport->runways = (RUNWAY **) malloc (sizeof(RUNWAY *) * n_runways);

	FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error opening file ...\n");
        exit(1);
    }

    char line[MAX_DIMENSION], _[20], token[20], color[20], gen[5];
	int id, x, y, z, n1, n2, g1, g2, width, altitude, speed;
	int runways_ctr = 0, gates_ctr = 0;
	float x0, y0, x1, y1;

    do {

        // read next line
        fgets(line, MAX_DIMENSION, file);

        // evaluate first token
        sscanf(line, "%s", token);

        // skip if line is empty
        if (!strcmp(line, "\n")) {
            continue;
        }

        // airport data
        else if (!strcmp(token, "AIRPORT_SPACE")) {
            sscanf(line, "%s %d %d %d %s\n", _,
                &airport->x,
                &airport->y,
                &airport->z,
                color
            );
            airport->color = color_to_int(color);
        }

        // runway data
        else if (!strcmp(token, "RUNWAY")) {
            sscanf(line, "%s %d %f %f %f %f %d %s\n", _, &id, &x0, &y0, &x1, &y1, &width, color);
            fgets(line, MAX_DIMENSION, file);
            sscanf(line,"%s %d %d\n", _, &n1, &n2);
            fgets(line, MAX_DIMENSION, file);
            sscanf(line,"%s %d\n", _, &altitude);
            fgets(line, MAX_DIMENSION, file);
            sscanf(line,"%s %d\n", _, &speed);
            fgets(line, MAX_DIMENSION, file);
            sscanf(line,"%s %s %d %d\n", _, gen, &g1, &g2);
            airport->runways[runways_ctr++] = create_runway(
                id, x0, y0, x1, y1, width, color,
                n1, n2, altitude, speed, g1, g2, gen
            );
        }

    } while( !feof(file) );

//	while (!feof(file)) {
//		fgets(next_line, MAX_DIMENSION, file); /* there is a '\n' attached to the end */
//		strcpy(copy, next_line);
//		token = strtok(next_line, " ");
//		if(!strcmp(token, "AIRPORT_SPACE")) {
//			sscanf(copy,"%s %d %d %d %s\n", _, &x, &y, &z, color_aux);
//			airport->x = x;
//			airport->y = y;
//			airport->z = z;
//			airport->color = color_to_int(color_aux);
//			fgets(next_line, MAX_DIMENSION, file);
//		}
//		else if(!strcmp(token, "RUNWAY")) {
//			if(runways_counter < n_runways) {
//				sscanf(copy,"%s %d %f %f %f %f %d %s\n", aux, &id_runway, &x0, &y0, &x1, &y1, &width_runway, color_aux);
//				if(exists_runway(airport, runways_counter, id_runway)){
//					printf("A runway %d que pretende adicionar ja existe\n", id_runway);
//					continue;
//				}
//				fgets(next_line, MAX_DIMENSION, file);
//				sscanf(next_line,"%s %d %d\n", aux, &n_marks, &mark_arrow);
//				fgets(next_line, MAX_DIMENSION, file);
//				sscanf(next_line,"%s %d\n", aux, &altitude_runway);
//				fgets(next_line, MAX_DIMENSION, file);
//				sscanf(next_line,"%s %d\n", aux, &speed_runway);
//				fgets(next_line, MAX_DIMENSION, file);
//				sscanf(next_line,"%s %s %d %d\n", aux, gen_type, &gen_1, &gen_2);
//				airport->runways[runways_counter] = create_runway(
//				    id_runway, x0, y0, x1, y1, width_runway, color_to_int(color_aux),
//			        n_marks, mark_arrow, altitude_runway, speed_runway, gen_1, gen_2, gen_type[0]
//			    );
//				runways_counter++;
//			}
//		}
//		else if(!strcmp(tok, "GATE")) {
//			if (gates_counter < n_gates) {
//				sscanf(copy,"%s %s %d %f %f %d %d %d %s\n", aux, type_gate, &number_gate, &position_x_gate,
//				       &position_y_gate, &orientation_gate, &width_gate, &size_gate, color_aux);
//				if(exists_gate(airport, gates_counter, number_gate, type_gate[0])){
//					printf("A %s gate %d que pretende adicionar ja existe\n", type_gate, number_gate);
//					continue;
//				}
//				fgets(next_line, MAX_DIMENSION, file);
//				sscanf(next_line,"%s %d\n", aux, &alt_gate);
//				fgets(next_line, MAX_DIMENSION, file);
//				sscanf(next_line,"%s %d\n", aux, &spd_gate);
//				if(!strcmp(type_gate, "ARRIVAL")){
//					fgets(next_line, MAX_DIMENSION, file);
//					sscanf(next_line,"%s %s %d %d\n", aux, gen_type, &gen_1, &gen_2);
//					fgets(next_line, MAX_DIMENSION, file);
//					if(strcmp(next_line, "\n")){ /* there is a ROUTE to be read */
//						sscanf(next_line,"%s %d\n", aux, &n_points);
//						points = (float *) malloc (sizeof (float) * n_points * 2);
//						for(i=0; i<n_points * 2; i+=2){
//							fgets(next_line, MAX_DIMENSION, file);
//							sscanf(next_line,"%f %f\n", &points[i], &points[i+1]);
//						}
//						airport->gates[gates_counter] = create_gate(
//						    type_gate[0], number_gate, position_x_gate, position_y_gate,
//						    size_gate, width_gate, orientation_gate, color_to_int(color_aux),
//						    alt_gate, spd_gate, n_points, points, gen_1, gen_2, gen_type[0]
//						);
//						free(points);
//						points = NULL;
//					}
//					else{ /* there is no routes to be read */
//						airport->gates[gates_counter] = create_gate(type_gate[0], number_gate, position_x_gate,
//						position_y_gate, size_gate, width_gate, orientation_gate, color_to_int(color_aux),
//						alt_gate, spd_gate, 0, NULL, gen_1, gen_2, gen_type[0]);
//
//					}
//				}
//				else{ /* DEPARTURE gate */
//					airport->gates[gates_counter] = create_gate(type_gate[0], number_gate, position_x_gate,
//					position_y_gate, size_gate, width_gate, orientation_gate, color_to_int(color_aux),
//					alt_gate, spd_gate, 0, NULL, 0, 0, '*');
//
//				}
//				gates_counter++;
//			}
//		}
//	}
	fclose(file);

	printf("Airport created.\n");
	return airport;
}

void destroy_airport(AIRPORT *airport){
    if(airport == NULL || sizeof(*airport) != sizeof(AIRPORT)) {
        printf("Invalid input ...\n");
        exit(1);
    }

	int i;
	for(i = 0; i < airport->n_runways; i++)
		destroy_runway(airport->runways[i]);
	for(i = 0; i < airport->n_gates; i++)
		destroy_gate(airport->gates[i]);
	free(airport->runways);
	free(airport->gates);
	free(airport);
}

void airport_toString(AIRPORT *airport){
	int i;
	printf("\n");
	printf("*********************************************************** \n");
	printf("*************** AIRPORT TEXTUAL DESCRIPTION *************** \n");
	printf("*********************************************************** \n");
	printf("SCALE: %d %d %d; Color (int): %d\n", airport->x, airport->y, airport->z, airport->color);
	for(i = 0; i < airport->n_runways; i++)
		runway_toString(airport->runways[i]);
	for(i = 0; i < airport->n_gates; i++)
		gate_toString(airport->gates[i]);
}
