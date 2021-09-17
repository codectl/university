#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DIMENSION 100

/*
 * Convert color name to its integer representation.
 * Returns -1 by default.
 * Color codes:
 *	 0 - black
 *	 1 - dark_blue
 * 	 2 - dark_green
 *   3 - dark_cyan
 *	 4 - dark_red
 *	 5 - dark_mangenta
 *	 6 - orange
 *	 7 - gray
 *	 8 - dark_gray
 *	 9 - blue
 *	 10 - green
 *	 11 - cyan
 *	 12 - red
 *	 13 - magenta
 *	 14 - yellow
 *	 15 - white
 */
int color_to_int(char *name){
	if (!strcmp (name, "black")) return 0;
	else if (!strcmp (name, "dark_blue")) return 1;
	else if (!strcmp (name, "dark_green")) return 2;
	else if (!strcmp (name, "dark_cyan")) return 3;
	else if (!strcmp (name, "dark_red")) return 4;
	else if (!strcmp (name, "dark_mangenta")) return 5;
	else if (!strcmp (name, "orange")) return 6;
	else if (!strcmp (name, "gray")) return 7;
	else if (!strcmp (name, "dark_gray")) return 8;
	else if (!strcmp (name, "blue")) return 9;
	else if (!strcmp (name, "green")) return 10;
	else if (!strcmp (name, "cyan")) return 11;
	else if (!strcmp (name, "red")) return 12;
	else if (!strcmp (name, "magenta")) return 13;
	else if (!strcmp (name, "yellow")) return 14;
	else if (!strcmp (name, "white")) return 15;
	else return -1;
}

/*
 * Return the closest value to c from point a and b
 */
int closest_distance(int p1, int p2, int p){
	if (p < p1 && p < p2)
		if(p1 < p2) return p1;
		else return p2;
	else
		if(p2 > p1) return p2;
		else return p1;
}

/*
 * Removes the \n character at the end of a string
 * or captures the first string before a blank space
 */
void process_string(char *str){
	int i;
	for(i = 0; i < strlen(str); i++)
		if(str[i] == ' ' || str[i] == '\n')
		    str[i] = '\0';
}

float calculate_distance(float x1, float y1,float x2 ,float y2){
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
