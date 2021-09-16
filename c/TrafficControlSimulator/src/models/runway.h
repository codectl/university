#ifndef _RUNWAY_H
#define _RUNWAY_H

/*
 * Representation of a runway.
 */
typedef struct runway {
	int id;
	float x0;
	float y0;
	float x1;
	float y1;
	int width;
	int color;
	int n_marks;
	int mark_arrow;
	int altitude;
	int speed;
	int gen_1;
	int gen_2;
	char gen_type;
} RUNWAY;

/*
 * Create a new runway.
 */
RUNWAY *create_runway(
    int id,
    float x0,
    float y0,
    float x1,
    float y1,
    int width,
	int color,
	int n_marks,
	int mark_arrow,
	int altitude,
	int speed,
    int gen_1,
    int gen_2,
    char gen_type
);

/*
 * Get a runway from an airport given its id.
 * Return NULL if not found.
 */
RUNWAY *get_runway(AIRPORT *airport, int id);

/*
 * Destroy a runway.
 */
void destroy_runway(RUNWAY *runway);

/*
 * Count the number of represented runways in a file.
 */
int count_runways(char *filename);

/*
 * Checks whether a runway exists in an airport given its id.
 * Return 1 if true, 0 otherwise.
 */
int exists_runway(AIRPORT *airport, int n, int id);

/*
 * Textual representation of a runway.
 */
void runway_toString(struct runway *track);

#endif
