#include <stdlib.h>
#include <stdio.h>

#include "airplanes.h"

struct node *create_node(AIRPLANE *airplane) {
	if(airplane == NULL || sizeof(*airplane) != sizeof(AIRPLANE)) {
		printf("Input error ...\n");
		exit(1);
	}
	struct node *node;
	node = (struct node *) malloc(sizeof(struct node));
	if(node == NULL){
		printf("Error creating node ...\n");
		exit(1);
	}
	node->airplane = airplane;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void destroy_node(struct node *node) {
	if(node == NULL || sizeof(*node) != sizeof(struct node)){
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

void add_airplane(AIRPLANES *airplanes, AIRPLANE *airplane) {
	if(
	    airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES) ||
	    airplane == NULL || sizeof(*airplane) != sizeof(AIRPLANE)
	) {
		printf("Input error ...\n");
		exit(1);
	}
	struct node *node;
	node = node_create(airplane);

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
	struct node *node, *aux;
	if(airplanes == NULL || sizeof(*airplanes) != sizeof(AIRPLANES)) {
		printf("Invalid input ...\n");
		exit(1);
	}

    airplane = find_airplane(airplanes, id);
	if (!exists_airplane(airplanes, id)) {
		printf("The airplane to be removed does not exist.\n");
		return;
	}

    node = list->head;
    while(node->airplane->id != id)
        node = node->next;

    // keep reference
	aux = ptr;

    // first element removal
	if(node->prev == NULL){
		if(airplanes_size(list) == 1){
			list->head = NULL;
			list->tail = NULL;
		}
		else{
			list->head->next->prev = NULL;
			list->head = list->head->next;
		}
	}

	// last element removal
	else if(ptr->next == NULL){
		list->tail = ptr->prev;
		ptr->prev->next = NULL;
	}

	// middle list removal
	else {
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}

	if (node_destroy(aux) == -1) return -1;	
	printf("Airplane %d removed successfully\n", search_key);

	return 0;
}



/*
 * Totally erase all the airplanes structs from the airplane list
 * Return -1 if error, 0 if succedded
 */
int list_destroy(struct airplane_list *list){
	struct node *aux;
	if(list == NULL || sizeof(*list) != sizeof(struct airplane_list)) return -1;
	aux = NULL;
	while((list->head)!= NULL){
		aux = list->head->next;
		if(node_destroy(list->head) == -1) /* destroy completely each node from the list */
			return -1;
		list->head = aux;
	}
	list->tail = NULL;
	free(list);
	return 0;
}



/* 
 * Returns the number of airplane structs in the list. -1 if error.
 */
int list_size(struct airplane_list *list){
	struct node *node;
	int count;
	if(list == NULL || sizeof(*list) != sizeof(struct airplane_list)) return -1;
	node = list->head;
	count = 0;
	while(node!=NULL){
		count++;
		node = node->next;
	}
	return count;
}

/*
 * Given its identifier number, finds a specific airplane from a list of airplanes
 * Returns NULL if the airplane does not exist
 */
struct airplane *find_airplane(struct airplane_list *list, int search_key){
	struct node *ptr = list->head;
	while(ptr != NULL){
		if(ptr->ap->airplane_id == search_key) break;
		ptr = ptr->next;
	}
	if (ptr == NULL){ /* in case the requested airplane does not exist */
		printf("A aeronave que procura nao existe\n");
		return NULL;
	}
	return ptr->ap;
}

int exists_airplane(AIRPLANES *airplanes, int id){
	struct node *node = list->head;
	while(node != NULL && node->airplane->id != id)
		node = node->next;
	return node == NULL ? 0 : 1;
}

/*
 * Gives a textual representation of the airplane list
 */
void list_toString(struct airplane_list *list){
	struct node *node = list->head;
	if(node == NULL) /* in case the list is empty */
		printf("Nao se verifica a existencia de qualquer aeronave\n");
	else{	
		while(node!=NULL){
			airplane_toString(node->ap);
			node = node->next;
		}
	}
}

