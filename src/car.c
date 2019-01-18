#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car.h"
#include "dummyFile.h"



Car* createCar( char storeDirection1, char storeDirection2, double storeTime )
{
    Car *c = malloc(sizeof(Car));
    
    c->initialDirection = storeDirection1;
    c->newDirection = storeDirection2;
    c->time = storeTime;
    return c;
}

