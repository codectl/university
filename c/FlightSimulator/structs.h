#ifndef _STRUCTS_H
#define _STRUCTS_H

struct airport {
	int x;
	int y;
	int z;
	int color;
	int n_gates;
	int n_runways;
	struct runway **runways;
	struct gate **gates;
};

struct runway {
	int id;
	float x0;
	float y0;
	float x1;
	float y1;
	int width;
	int color;
	int n_marks;
	int mark_arrow;
	int alt;
	int spd;
	int gen_1;
	int gen_2;
	char gen_type;
};

struct gate {
	char type;
	int number;
	float position_x;
	float position_y;
	int size;
	int width;
	int orientation;
	int color;
	int alt;
	int spd;
	int n_points;
	float *points;
	int gen_1;
	int gen_2;
	char gen_type;
};



struct generation_rate{
	char type;
	int a;
	int b;
};


struct airplane{
	int airplane_id;
	int alt;
	int spd;
	int orientation;
	int ref_alt;
	int ref_spd;
	int ref_orientation;
	float position_x;
	float position_y;
	struct runway *origin_track;
	struct gate *origin_gate;
	struct runway *destiny_track;
	struct gate *destiny_gate;
};

struct sort_airplanes{	
	int id;
	int id_destiny;
	char type_destiny;
	int altitude;
	float distance;
};

#endif


