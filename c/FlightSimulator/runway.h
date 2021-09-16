#ifndef _RUNWAY_H
#define _RUNWAY_H

#include "structs.h"

struct runway *runway_create(int id, float x0, float y0, float x1, float y1, int width, 
			     int color, int n_marks, int mark_arrow, int alt, int spd,
			     int gen_1, int gen_2, char gen_type);
int runway_count(char *file_name);
int runway_destroy(struct runway *runway);
int exists_runway(int n_runways, int id_runway, struct airport *airport);
struct runway *find_runway(int id_runway, struct airport *airport);
void runway_toString(struct runway *track);

#endif
