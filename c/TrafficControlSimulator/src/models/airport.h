#ifndef _AIRPORT_H
#define _AIRPORT_H

/*
 * Create a new runway from a file.
 */
AIRPORT *create_airport(char *filename);

/*
 * Destroy an airport.
 */
void airport_destroy(AIRPORT *airport);

/*
 * Textual representation of an airport.
 */
void airport_toString(AIRPORT *airport);

/*
 * Graphical representation of an airport.
 */
void airport_gui(AIRPORT *airport);

#endif
