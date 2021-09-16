#ifndef _OPERATIONS_H
#define _OPERATIONS_H
#include "airplane_list.h"

void load_simulation_state(char *file_name, struct airplane_list *list, struct airport *airport);
void list_airplanes(struct airplane_list *list, struct airport *airport);
void list_airplanes_by_id(struct airplane_list *list);
void add_airplane(struct airplane_list *list, struct airport *airport);
void remove_airplane(struct airplane_list *list);

#endif
