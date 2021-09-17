#include <stdlib.h>
#include <stdio.h>

#include "structs.h"
#include "airplane.h"
#include "airplanes.h"

struct node *create_node(AIRPLANE *airplane) {
	if(airplane == NULL || sizeof(*airplane) != sizeof(AIRPLANE)) {
		printf("Input error ...\n");
		exit(1);
	}
	struct node *node;
	node = (struct node *) malloc(sizeof(struct node));
	if(node == NULL) {
		printf("Error creating node ...\n");
		exit(1);
	}
	node->airplane = airplane;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void destroy_node(struct node *node) {
	if(node == NULL || sizeof(*node) != sizeof(struct node)) {
		printf("Input error ...\n");
		exit(1);
	}

	destroy_airplane(node->airplane);
	free(node);
}

AIRPLANES *init_airplanes() {
	AIRPLANES *airplanes = (AIRPLANES *) malloc(sizeof(AIRPLANES));
	if(airplanes == NULL) {
		printf("Input error ...\n");
		exit(1);
	}
	airplanes->head = NULL;
	airplanes->tail = NULL;
	return airplanes;
}

AIRPLANE *get_airplane(AIRPLANES *airplanes, int id) {
	if(airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES)) {
		printf("Invalid input ...\n");
		exit(1);
	}

	struct node *node = airplanes->head;
	while(node != NULL && node->airplane->id != id)
		node = node->next;

    if (node == NULL) {
        printf("The queried airplane does not exist.\n");
        return NULL;
    }

	return node->airplane;
}

void add_airplane(AIRPLANES *airplanes, AIRPLANE *airplane) {
	if(
	    airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES) ||
	    airplane == NULL || sizeof(*airplane) != sizeof(AIRPLANE)
	) {
		printf("Input error ...\n");
		exit(1);
	}
	struct node *node;
	node = create_node(airplane);

	// adds a node to a non-empty list
	if(airplanes_size(airplanes) > 0) {
		node->prev = airplanes->tail;
		airplanes->tail->next = node;
		airplanes->tail = node;
	}

	// adds a node to an empty list
	else {
		airplanes->head = node;
		airplanes->tail = node;
	}
}

void remove_airplane(AIRPLANES *airplanes, int id) {
	if(airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES)) {
		printf("Invalid input ...\n");
		exit(1);
	}

    struct node *node = airplanes->head;
    while(node != NULL && node->airplane->id != id)
        node = node->next;

    if (node == NULL) {
		printf("The airplane to be removed does not exist.\n");
        return;
    }

    // first element removal
	if(node->prev == NULL) {
		if(airplanes_size(airplanes) == 1) {
			airplanes->head = NULL;
			airplanes->tail = NULL;
		}
		else{
			airplanes->head = airplanes->head->next;
			airplanes->head->prev = NULL;
		}
	}

	// last element removal
	else if(node->next == NULL) {
		airplanes->tail = node->prev;
		airplanes->tail->next = NULL;
	}

	// middle list removal
	else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	destroy_node(node);
	printf("Airplane '%d' removed.\n", id);
}

void remove_airplanes(AIRPLANES *airplanes) {
	if(airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES)) {
		printf("Invalid input ...\n");
		exit(1);
	}

    struct node *node;
	while(airplanes->head != NULL) {
	    node = airplanes->head;
		airplanes->head = airplanes->head->next;
		destroy_node(node);
	}
}

int airplanes_size(AIRPLANES *airplanes) {
	if(airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES)) {
		printf("Invalid input ...\n");
		exit(1);
	}

    struct node* node = airplanes->head;
	int count = 0;
	while(node != NULL) {
		count++;
		node = node->next;
	}
	return count;
}

int exists_airplane(AIRPLANES *airplanes, int id){
	if(airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES)) {
		printf("Invalid input ...\n");
		exit(1);
	}

	struct node *node = airplanes->head;
	while(node != NULL && node->airplane->id != id)
		node = node->next;
	return node == NULL ? 0 : 1;
}

void airplanes_toString(AIRPLANES *airplanes){
	if(airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES)) {
		printf("Invalid input ...\n");
		exit(1);
	}

	printf("\nDisplay info on %d airplanes ...\n", airplanes_size(airplanes));

	struct node *node = airplanes->head;
	if(node == NULL) {
		printf("No airplanes\n");
		return;
	}
    while(node != NULL) {
        airplane_toString(node->airplane);
        node = node->next;
    }
}

