/*
 * Representation of an airplane.
 */
typedef struct airplane {
    int id;
    int altitude;
	int speed;
	int orientation;
	int ref_speed;
	int ref_altitude;
	int ref_orientation;
	float position_x;
	float position_y;
	struct runway *origin_track;
	struct gate *origin_gate;
	struct runway *destiny_track;
	struct gate *destiny_gate;
} AIRPLANE;

/*
 * Representation of a gate.
 */
typedef struct gate {
	char type;
	int number;
	float position_x;
	float position_y;
	int size;
	int width;
	int orientation;
	int color;
	int altitude;
	int speed;
	int n_points;
	float *points;
	int gen_1;
	int gen_2;
	char gen_type;
} GATE;


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
 * Representation of an airport.
 */
typedef struct airport {
	int x;
	int y;
	int z;
	int color;
	int n_runways;
	int n_gates;
	RUNWAY **runways;
	GATE **gates;
} AIRPORT;
