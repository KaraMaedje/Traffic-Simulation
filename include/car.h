#ifndef CAR_H
#define CAR_H


typedef struct car {
	char initialDirection;
	char newDirection;
	int time;
} Car;

Car* createCar( char storeDirection1, char storeDirection2, double storeTime );


#endif
