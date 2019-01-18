#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dummyFile.h"
#include "car.h"

void deleteListNode(void *toBeDeleted){}


void printNode(void *toBePrinted) {
	printf("%c %c %d\n", ((Car*)(toBePrinted))->initialDirection, ((Car*)(toBePrinted))->newDirection, ((Car*)(toBePrinted))->time);
}

int compare(const void *first,const void *second){
	Car* a = (Car*)first;
	Car* b = (Car*)second;

	if(a->time == b->time )
		return 0;
	else if( a->time < b->time )
		return -1;
	return 1;
}