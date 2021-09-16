#ifndef _AIRPORT_H
#define _AIRPORT_H
#include "structs.h"

struct airport *airport_create(char *file_name);
int airport_destroy(struct airport *airport);
void airport_toString(struct airport *airport);
void airport_presentation(struct airport *airport);

#endif
