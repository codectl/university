#ifndef _GATE_H
#define _GATE_H

/*
 * Create a new gate.
 */
GATE *create_gate(
    char type,
    int number,
    float position_x,
    float position_y,
    int size,
    int width,
    int orientation,
    int color,
    int alt,
    int spd,
    int n_points,
    float *points,
    int gen_1,
    int gen_2,
    char gen_type
);

/*
 * Get a gate from an airport given its id and type.
 * Return NULL if not found.
 */
GATE *get_gate(AIRPORT *airport, int id, char type);

/*
 * Destroy a gate.
 */
void destroy_gate(GATE *gate);

/*
 * Count the number of represented gates in a file.
 */
int count_gates(char *filename);

/*
 * Checks whether a gate exists in an airport given its id and type.
 * Return 1 if true, 0 otherwise.
 */
int exists_gate(AIRPORT *airport, int n, int id, char type);

/*
 * Textual representation of a gate.
 */
void gate_toString(GATE *gate);

#endif
