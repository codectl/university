#ifndef _GATE_H
#define _GATE_H
#include "structs.h"


struct gate *new_gate(char type, int number, float position_x, float position_y,
		      int size, int width, int orientation, int color,
		      int alt, int spd, int n_points, float *points, int gen_1, int gen_2, char gen_type);

int gate_destroy(struct gate *gate);
int gate_count(char *file_name);
int exists_gate(int n_gates, int id_gate, char type_gate, struct airport *airport);
struct gate *find_gate(int id_gate, char type_gate, struct airport *airport);
void gate_toString(struct gate *gate);

#endif
