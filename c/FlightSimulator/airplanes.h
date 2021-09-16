#ifndef _AIRPLANE_LIST_H
#define _AIRPLANE_LIST_H

#include "structs.h"

struct node {
	struct airplane *ap;	// node element (airplane)
    struct node *next;	    // next element
	struct node *prev;	    // previous element
};

struct airplanes {
	struct node *head;	    // list header
	struct node *tail;	    // list tail
};

/* Create node */
struct node *node_create(struct airplane *ap);

struct airplane_list *list_create();
int list_destroy(struct airplane_list *list);
int node_destroy(struct node *node);
int list_add(struct airplane_list *list, struct airplane *airplane);
int list_remove(struct airplane_list *list, int search_key);
int list_size(struct airplane_list *list);
struct airplane *find_airplane(struct airplane_list *list, int search_key);
int exists_airplane(struct airplane_list *list, int search_key);
void list_toString(struct airplane_list *list);

#endif
