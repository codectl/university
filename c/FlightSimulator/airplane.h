#ifndef _AIRPLANE_H
#define _AIRPLANE_H

#include "structs.h"

/*
 * Create new airplane
 * Return null if error
 */
struct airplane *create_airplane(
    int id,
    int altitude,
	int speed,
	int orientation,
	int ref_speed,
	int ref_altitude,
	int ref_orientation,
	float position_x,
	float position_y,
	struct runway *origin_track,
	struct gate *origin_gate,
	struct runway *destiny_track,
	struct gate *destiny_gate
);

/*
 * Destroy an airplane
 */
int destroy_airplane(struct airplane *airplane);

/*
 * String representation of an airplane
 */
void airplane_toString(struct airplane *airplane);

#endif
