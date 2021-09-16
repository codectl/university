#ifndef _AIRPLANES_H
#define _AIRPLANES_H

#include "airplane.h"

struct node {
    AIRPLANE *airplane;	    // node element (airplane)
    struct node *next;	    // next element
    struct node *prev;	    // previous element
};

typedef struct airplane_list {
    struct node *head;	    // list header
    struct node *tail;	    // list tail
} AIRPLANES;

/*
 * Create an empty list of airplanes.
 */
AIRPLANES *init_airplanes();

/*
 * Remove an airplane given its id.
 */
void remove_airplane(AIRPLANES *airplanes, int id);

/*
 * Remove all airplanes.
 */
void remove_airplanes(AIRPLANES *airplanes);

/*
 * Add a new airplane.
 */
void add_airplane(AIRPLANES *airplanes, AIRPLANE *airplane);

/*
 * Get number of airplanes.
 */
int airplanes_size(AIRPLANES *airplanes);

/*
 * Get airplane given its id.
 * Return NULL if not found.
 */
AIRPLANE *get_airplane(AIRPLANES *airplanes, int id);

/*
 * Check whether airplane exists given its id.
 */
int exists_airplane(AIRPLANES *airplanes, int id);

/*
 * Textual representation for airplanes.
 */
void airplanes_toString(AIRPLANES *airplanes);

#endif
