#ifndef _STRUCTS_H
#define _STRUCTS_H

struct generation_rate{
	char type;
	int a;
	int b;
};

struct sort_airplanes{	
	int id;
	int id_destiny;
	char type_destiny;
	int altitude;
	float distance;
};

#endif
