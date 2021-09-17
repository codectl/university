#ifndef _AIRPLANE_H
#define _AIRPLANE_H

/*
 * Create a new airplane.
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
	RUNWAY *departure_runway,
	RUNWAY *arrival_runway,
	GATE *departure_gate,
	GATE *arrival_gate
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
