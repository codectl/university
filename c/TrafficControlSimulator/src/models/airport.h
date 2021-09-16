#ifndef _AIRPORT_H
#define _AIRPORT_H

/*
 * Representation of an airport.
 */
typedef struct airport {
	int x;
	int y;
	int z;
	int color;
	int n_gates;
	int n_runways;
	RUNWAY **runways;
	GATE **gates;
} AIRPORT;

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
void airport_gui(struct airport *airport);

#endif
