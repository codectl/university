#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "airplanes.h"
#include "airplane_list.h"


/*
 * Creates a new node that will figure in a airplane_list struct
 * Returns NULL, in case of error
 */
struct node *node_create(struct airplane *ap){
	struct node *ptr;
	if(ap == NULL || sizeof(*ap) != sizeof(struct airplane)){
		printf("Erro ao adicionar no\n");
		return NULL;
	}
	ptr = (struct node *) malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("Erro ao adicionar no\n");
		return NULL; 
	}
	ptr->ap = ap;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}


/*
 * Erase a node from the list and its correspondent airplane struct
 * Return -1 if error, 0 if succeded
 */
int node_destroy(struct node *node){
	if(node == NULL || sizeof(*node) != sizeof(struct node)){
		printf("Erro ao remover no\n");
		return -1; 
	}
	if (airplane_destroyer(node->ap) == -1) return -1;
	free(node);
	return 0;
}



/* 
 * Creates a new list that stores airplanes structs
 * Returns NULL, in case of error
 */
struct airplane_list *list_create(){
	struct airplane_list *ptr = (struct airplane_list *) malloc(sizeof(struct airplane_list));
	if(ptr == NULL){
		printf("Erro ao criar lista de aeronaves\n");
		return NULL;
	}
	ptr->head = NULL;		
	ptr->tail = NULL;
	return ptr;	
}


/*
 * Adds an airplane to the end of the airplane's list struct
 * Returns -1 if error, 0 if succeded
 */
int list_add(struct airplane_list *list, struct airplane *airplane){
	struct node *node;
	if(list == NULL || sizeof(*list) != sizeof(struct airplane_list) ||
	airplane == NULL || sizeof(*airplane) != sizeof(struct airplane)){
		printf("Erro ao adicionar aeronave a lista\n");
		return -1;
	}
	node = node_create(airplane);
	if(list_size(list)>0){	/* adds a node to a non-empty list */
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
		list->tail->next = NULL;
	}
	else{	/* adds a node to an empty list */
		list->head = node;
		list->tail = node;
		list->tail->next = NULL;
		list->tail->prev = NULL;
	}
	return 0;
}

/*
 *  Given its identifier number, removes a specific airplane from a list of airplanes
 */
int list_remove(struct airplane_list *list, int search_key){
	struct node *ptr, *aux;
	if(list == NULL || sizeof(*list) != sizeof(struct airplane_list)){
		printf("Erro ao remover aeronave da lista\n");
		return -1;
	}

	ptr = list->head;
	while(ptr != NULL){
		if(ptr->ap->airplane_id == search_key) break;
		ptr = ptr->next;
	}
	if (ptr == NULL){ /* in case the requested airplane does not exist */
		printf("A aeronave que deseja remover nao existe\n");
		return 0;
	}

	aux = ptr; /* not to lose the node reference after the following changes */

	if(ptr->prev == NULL){ /* first element removal from the list */
		if(list_size(list) == 1){
			list->head = NULL;
			list->tail = NULL;
		}
		else{
			list->head->next->prev = NULL;
			list->head = list->head->next;
		}
	}
	else if(ptr->next == NULL){	/* last element removal from the list */
		list->tail = ptr->prev;
		ptr->prev->next = NULL;
	}
	else{	/* middle list removal */
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
/*
 * Given its identifier number, checks whether the airplane exists or not
 * Returns 0 if the airplane does not exist
 */
int exists_airplane(struct airplane_list *list, int search_key){
	struct node *ptr = list->head;
	while(ptr != NULL){
		if(ptr->ap->airplane_id == search_key) break;
		ptr = ptr->next;
	}
	if (ptr == NULL) /* in case the requested airplane does not exist */
		return 0;
	return 1;
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

