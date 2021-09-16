#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "airplane.h"
#include "airplanes.h"

int main(){

	
	struct airport *destiny;
	struct gate *dg;
	printf("000 \n");
	struct airplane_list *list = list_create();
	list_add(list, airplane_creator("airplane 1",1,2,3,destiny,dg));
	list_add(list, airplane_creator("airplane 2",11,22,33,destiny,dg));
	list_add(list, airplane_creator("airplane 3",111,222,333,destiny,dg));
	list_toString(list);
	list_destroy(list);
	printf("A execucao do programa terminou \n");
	return 0;

}
