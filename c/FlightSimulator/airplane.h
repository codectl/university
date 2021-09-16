#ifndef _AIRPLANE_H
#define _AIRPLANE_H

/*
 * Representation of an airplane.
 */
typedef struct airplane {
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
} AIRPLANE;

/*
 * Create new airplane.
 */
AIRPLANE *create_airplane(
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
 * Destroy an airplane.
 */
void destroy_airplane(AIRPLANE *airplane);

/*
 * Textual representation of an airplane.
 */
void airplane_toString(AIRPLANE *airplane);

#endif
