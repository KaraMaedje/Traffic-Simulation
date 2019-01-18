/*
Name: Kara Maedje
Student ID: 0969222
Course: CIS*2520
Date: October 11th, 2017
Assignment 1 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedListAPI.h"
#include "car.h"
#include "dummyFile.h"

int main(int argc, char *argv[])
{
	FILE *theFile;
	char line[10];

	char storeDirection1;
	char storeDirection2;
	int storeTime = 0;
	int totalCars = 0;
	int northCars = 0; 
	int eastCars = 0;
	int southCars = 0;
	int westCars = 0;
	Car * carPointer;


	/* Create a LinkedList for Cars */
   	List * carList = initializeList(printNode, deleteListNode, compare);

   	List * northList = initializeList(printNode, deleteListNode, compare);
   	List * eastList = initializeList(printNode, deleteListNode, compare);
  	List * southList = initializeList(printNode, deleteListNode, compare);
   	List * westList = initializeList(printNode, deleteListNode, compare);

	
	theFile = fopen(argv[1], "r");

    /*Check if file is empty*/
    if (theFile == NULL) {
        printf("Error, could not open file \"%s\".\n", argv[1]);
        return -1;
    }

    /*If not empty*/
    else {
		printf("File successfuly read.\n");

		while (fgets(line, 10, theFile) != NULL){
			totalCars++;
			(sscanf(line, "%c %c %d", &storeDirection1, &storeDirection2, &storeTime));

			carPointer = createCar(storeDirection1, storeDirection2, storeTime);

			if (carPointer->initialDirection == 'N'){
				insertBack(northList, carPointer);
				northCars++;
			}
			if (carPointer->initialDirection == 'E'){
				insertBack(eastList, carPointer);
				eastCars++;
			}
			if (carPointer->initialDirection == 'S'){
				insertBack(southList, carPointer);
				southCars++;
			}
			if (carPointer->initialDirection == 'W'){
				insertBack(westList, carPointer);
				westCars++;
			}
			insertFront(carList, carPointer);
		}
	}
	fclose(theFile);
	/* ============================================ SIMULATION ============================================== */
	double globalTimer = 1.0;
	double loopTimer = 1.0;
	int carsLeft = totalCars;
	double timer = 0.0;

	Node *temp = northList->head;
	Node *temp2 = eastList->head;
	Node *temp3= southList->head;
	Node *temp4 = westList->head;

	/* MAIN LOOP */
	printf("Initial Vehicle Information   Intersection Arrival Time   Completed at Time\n");
	while(carsLeft!= 0) {
		/*if ((northList->head == NULL) && (eastList->head == NULL) && (southList == NULL) && (westList == NULL)) {
			break;
		}*/

		/*printf("Next Car: %c %c %.1lf\n", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), (((Car*)(temp->data))->time));
		printf("north cars: %d\n", northCars);
		printf("loop time; %lf\n", loopTimer);
		printf("Cars left: %d\n", carsLeft);;*/

		if ((temp != NULL) && (northCars != 0) && (loopTimer < 14)) {
			/* ============================================== NORTH CARS ============================================ */
			if ((((Car*)(temp->data))->initialDirection == 'N') && (northCars != 0) && (loopTimer <=10)){
				//printf("here?\n");
				if (((Car*)(temp->data))->newDirection == 'F'){
					
					if ( (((Car*)(temp->data))->time) < globalTimer){
						if ((globalTimer + 2)  <= 10) {
							globalTimer += 2;
							loopTimer = globalTimer;
							northCars--;
							printf("%c %c %d", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), (((Car*)(temp->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							temp = temp->next;
						}
					}
					else {
						globalTimer = ((((((Car*)(temp->data))->time) - globalTimer) + 2) + globalTimer); 
						loopTimer = globalTimer;
						northCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), (((Car*)(temp->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						temp = temp->next;
					}
				}
				if (((Car*)(temp->data))->newDirection == 'R') {
					if ( (((Car*)(temp->data))->time) < globalTimer){
						if ((globalTimer + 1)  <= 10) {
							globalTimer += 1;
							loopTimer = globalTimer;
							northCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), (((Car*)(temp->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-1));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							temp = temp->next;
						}
					}
					else {
						globalTimer = ((((((Car*)(temp->data))->time) - globalTimer) + 1) + globalTimer); 
						loopTimer = globalTimer;
						northCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), (((Car*)(temp->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-1));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						temp = temp->next;
					}
					
				}
				if (((Car*)(temp->data))->newDirection == 'L'){
					if ( (((Car*)(temp->data))->time) < globalTimer){
						if ((globalTimer + 2.5)  <= 10) {
							globalTimer += 2.5;
							loopTimer = globalTimer;
							northCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), (((Car*)(temp->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2.5));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							temp = temp->next;
						}
					}
					else {
						globalTimer = ((((((Car*)(temp->data))->time) - globalTimer) + 2.5) + globalTimer); 
						loopTimer = globalTimer;
						northCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), (((Car*)(temp->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2.5));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						temp = temp->next;
					}
				}
			}
			/* YELLOW LIGHT GO FOR 3s */
			if ((((Car*)(temp->data))->initialDirection == 'N') && (northCars != 0) && (loopTimer >= 10) && (loopTimer < 14)){

				if (((((Car*)(temp->data))->newDirection == 'L')) && ( ((((((Car*)(temp->data))->time) - globalTimer) + 2.5) + globalTimer) <= 13) && ((((Car*)(temp->data))->time) >= globalTimer)) {
					globalTimer = ((((((Car*)(temp->data))->time) - globalTimer) + 2.5) + globalTimer);  
					loopTimer = ((((((Car*)(temp->data))->time) - globalTimer) + 2.5) + loopTimer) + 2.5;
					northCars--;
					carsLeft--;
					printf("%c %c %.2lf\n", (((Car*)(temp->data))->initialDirection), (((Car*)(temp->data))->newDirection), globalTimer);
				}
				else {
					globalTimer = (globalTimer + (14 - globalTimer));
					loopTimer = 14;
				}
					
			}
			/*if (northCars = 0) {
				printf("No north cars in list\n");
				if (loopTimer != 14){
					loopTimer = loopTimer + (14 - loopTimer);
					globalTimer = globalTimer + loopTimer;
				}
			}*/
		}
		loopTimer = 0;
		globalTimer += 1;
		while ((temp2 != NULL) && (loopTimer < 14)) {
			/* ============================================== EAST CARS ============================================= */
			if ((((Car*)(temp2->data))->initialDirection == 'E') && (eastCars != 0) && (loopTimer <=10)){

				if (((Car*)(temp2->data))->newDirection == 'F'){
					if ( (((Car*)(temp2->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp2->data))->time)) + 2 + loopTimer)<= 10) {
							timer = (globalTimer + 2);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 2;
							eastCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp2->data))->initialDirection), (((Car*)(temp2->data))->newDirection), (((Car*)(temp2->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (eastCars != 0){
								temp2 = temp2->next;
							}
							else{
								temp2 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp2->data))->time) - globalTimer) + 2));
						globalTimer = globalTimer + timer; 
						loopTimer = loopTimer + timer;
						eastCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp2->data))->initialDirection), (((Car*)(temp2->data))->newDirection), (((Car*)(temp2->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (eastCars != 0){
							temp2 = temp2->next;
						}
						else{
							temp2 = NULL;
							break;
						}
					}
				}
				if (((Car*)(temp2->data))->newDirection == 'R'){
					if ( (((Car*)(temp2->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp2->data))->time)) + 1 + loopTimer)<= 10) {
							timer = (globalTimer + 1);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 1;
							eastCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp2->data))->initialDirection), (((Car*)(temp2->data))->newDirection), (((Car*)(temp2->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-1));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (eastCars != 0){
								temp2 = temp2->next;
							}
							else{
								temp2 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp2->data))->time) - globalTimer) + 1));
						globalTimer = globalTimer + timer;
						loopTimer = loopTimer + timer;
						eastCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp2->data))->initialDirection), (((Car*)(temp2->data))->newDirection), (((Car*)(temp2->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-1));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (eastCars != 0){
							temp2 = temp2->next;
						}
						else{
							temp2 = NULL;
							break;
						}
					}
				}
				if (((Car*)(temp2->data))->newDirection == 'L'){
					if ( (((Car*)(temp2->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp2->data))->time)) + 2.5 + loopTimer)<= 10) {
							timer = (globalTimer + 2.5);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 2.5;
							eastCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp2->data))->initialDirection), (((Car*)(temp2->data))->newDirection), (((Car*)(temp2->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2.5));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (eastCars != 0){
								temp2 = temp2->next;
							}
							else{
								temp2 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp2->data))->time) - globalTimer) + 2.5));
						globalTimer = globalTimer + timer;
						loopTimer = loopTimer + timer;
						eastCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp2->data))->initialDirection), (((Car*)(temp2->data))->newDirection), (((Car*)(temp2->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2.5));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (eastCars != 0){
							temp2 = temp2->next;
						}
						else{
							temp2 = NULL;
							break;
						}
					}
				}
			}

			/* YELLOW LIGHT GO FOR 3s */
			if ((((Car*)(temp2->data))->initialDirection == 'E') && (eastCars != 0) && (loopTimer >= 10) && (loopTimer < 14)){
				printf("in yellow light zone\n");

				if (((((Car*)(temp2->data))->newDirection == 'L')) && ( ((((((Car*)(temp2->data))->time) - globalTimer) + 2.5) + globalTimer) <= 13) && ((((Car*)(temp2->data))->time) >= globalTimer)) {
					globalTimer = ((((((Car*)(temp2->data))->time) - globalTimer) + 2.5) + globalTimer);  
					loopTimer = ((((((Car*)(temp2->data))->time) - globalTimer) + 2.5) + loopTimer) + 2.5;
					eastCars--;
					carsLeft--;
					printf("%c %c %.2lf\n", (((Car*)(temp2->data))->initialDirection), (((Car*)(temp2->data))->newDirection), globalTimer);
					if (eastCars != 0){
						temp2 = temp2->next;
					}
					else{
						temp2 = NULL;
						break;
					}
				}
				else {
					globalTimer = (globalTimer + (14 - globalTimer));
					printf("not enough time to proceed\n");
					loopTimer = 14;
				}		
			}
			/*if (eastCars = 0) {
				printf("No east cars in list\n");
				if (loopTimer != 14){
					loopTimer = loopTimer + (14 - loopTimer);
					globalTimer = globalTimer + loopTimer;
				}
			}*/
		}
		loopTimer = 0;
		timer = 0;

		while ((temp3 != NULL) && (southCars!= 0) && (loopTimer < 14)) {
			/* ============================================== SOUTH CARS ============================================ */
			while ((((Car*)(temp3->data))->initialDirection == 'S') && (southCars != 0) && (loopTimer <=10)){
				if (((Car*)(temp3->data))->newDirection == 'F'){
					if ( (((Car*)(temp3->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp3->data))->time)) + 2 + loopTimer)<= 10) {
							timer = (globalTimer + 2);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 2;
							southCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp3->data))->initialDirection), (((Car*)(temp3->data))->newDirection), (((Car*)(temp3->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (southCars != 0){
								temp3 = temp3->next;
							}
							else{
								temp3 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp3->data))->time) - globalTimer) + 2));
						globalTimer = globalTimer + timer; 
						loopTimer = loopTimer + timer;
						southCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp3->data))->initialDirection), (((Car*)(temp3->data))->newDirection), (((Car*)(temp3->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (southCars != 0){
							temp3 = temp3->next;
						}
						else{
							temp3 = NULL;
							break;
						}
					}
				}
				if (((Car*)(temp3->data))->newDirection == 'R'){
				
					if ( (((Car*)(temp3->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp3->data))->time)) + 1 + loopTimer)<= 10) {
							timer = (globalTimer + 1);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 1;
							southCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp3->data))->initialDirection), (((Car*)(temp3->data))->newDirection), (((Car*)(temp3->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-1));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (southCars != 0){
								temp3 = temp3->next;
							}
							else{
								temp3 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp3->data))->time) - globalTimer) + 1));
						globalTimer = globalTimer + timer;
						loopTimer = loopTimer + timer;
						southCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp3->data))->initialDirection), (((Car*)(temp3->data))->newDirection), (((Car*)(temp3->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-1));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (southCars != 0){
							temp3 = temp3->next;
						}
						else{
							temp3 = NULL;
							break;
						}
					}

				}

				if (((Car*)(temp3->data))->newDirection == 'L'){
					if ( (((Car*)(temp3->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp3->data))->time)) + 2.5 + loopTimer)<= 10) {
							timer = (globalTimer + 2.5);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 2.5;
							southCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp3->data))->initialDirection), (((Car*)(temp3->data))->newDirection), (((Car*)(temp3->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2.5));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (southCars != 0){
								temp3 = temp3->next;
							}
							else{
								temp3 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp3->data))->time) - globalTimer) + 2.5));
						globalTimer = globalTimer + timer;
						loopTimer = (loopTimer + 2.5);
						southCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp3->data))->initialDirection), (((Car*)(temp3->data))->newDirection), (((Car*)(temp3->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2.5));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (southCars != 0){
							temp3 = temp3->next;
						}
						else{
							break;
							temp3 = NULL;
						}
					}
				}
			}
			/* YELLOW LIGHT GO FOR 3s */
			if ((((Car*)(temp3->data))->initialDirection == 'S') && (southCars != 0) && (loopTimer >= 10) && (loopTimer < 14)){
				printf("in yellow light zone\n");

				if (((((Car*)(temp3->data))->newDirection == 'L')) && ( ((((((Car*)(temp3->data))->time) - globalTimer) + 2.5) + globalTimer) <= 13) && ((((Car*)(temp3->data))->time) >= globalTimer)) {
					globalTimer = ((((((Car*)(temp3->data))->time) - globalTimer) + 2.5) + globalTimer);  
					loopTimer = ((((((Car*)(temp3->data))->time) - globalTimer) + 2.5) + loopTimer) + 2.5;
					southCars--;
					carsLeft--;
					printf("%c %c %.2lf\n", (((Car*)(temp3->data))->initialDirection), (((Car*)(temp3->data))->newDirection), globalTimer);
					if (southCars != 0){
						temp3 = temp3->next;
					}
					else{
						temp3 = NULL;
						break;
					}
				}
				else {
					globalTimer = (globalTimer + (14 - globalTimer));
					printf("not enough time to proceed\n");
					loopTimer = 14;
				}	
			}
			/*if (southCars = 0) {
				printf("No east cars in list\n");
				if (loopTimer != 14){
					loopTimer = loopTimer + (14 - loopTimer);
					globalTimer = globalTimer + loopTimer;
				}
			}*/
			break;
		}
		loopTimer = 0;
		timer = 0;

		while ((temp4 != NULL) && (westCars!= 0) && (loopTimer < 14)) {
			/* ============================================== WEST CARS ============================================ */
			while ((((Car*)(temp4->data))->initialDirection == 'W') && (westCars != 0) && (loopTimer <=10)){
				if (((Car*)(temp4->data))->newDirection == 'F'){
					if ( (((Car*)(temp4->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp4->data))->time)) + 2 + loopTimer)<= 10) {
							timer = (globalTimer + 2);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 2;
							westCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp4->data))->initialDirection), (((Car*)(temp4->data))->newDirection), (((Car*)(temp4->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (westCars != 0){
								temp4 = temp4->next;
							}
							else{
								temp4 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp4->data))->time) - globalTimer) + 2));
						globalTimer = globalTimer + timer; 
						loopTimer = loopTimer + timer;
						westCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp4->data))->initialDirection), (((Car*)(temp4->data))->newDirection), (((Car*)(temp4->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (westCars != 0){
							temp4 = temp4->next;
						}
						else{
							temp4 = NULL;
							break;
						}
					}
				}
				if (((Car*)(temp4->data))->newDirection == 'R'){
					if ( (((Car*)(temp4->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp4->data))->time)) + 1 + loopTimer)<= 10) {
							timer = (globalTimer + 1);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 1;
							westCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp4->data))->initialDirection), (((Car*)(temp4->data))->newDirection), (((Car*)(temp4->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-1));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (westCars != 0){
								temp4 = temp4->next;
							}
							else{
								temp4 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp4->data))->time) - globalTimer) + 1));
						globalTimer = globalTimer + timer;
						loopTimer = loopTimer + timer;
						westCars--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp4->data))->initialDirection), (((Car*)(temp4->data))->newDirection), (((Car*)(temp4->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-1));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (westCars != 0){
							temp4 = temp4->next;
						}
						else{
							temp4 = NULL;
							break;
						}
					}
				}
				if (((Car*)(temp4->data))->newDirection == 'L'){
					if ( (((Car*)(temp4->data))->time) <= globalTimer){
						if ( ((globalTimer - (((Car*)(temp4->data))->time)) + 2.5 + loopTimer)<= 10) {
							timer = (globalTimer + 2.5);
							loopTimer = loopTimer + (timer - globalTimer);
							globalTimer += 2.5;
							westCars--;
							carsLeft--;
							printf("%c %c %d", (((Car*)(temp4->data))->initialDirection), (((Car*)(temp4->data))->newDirection), (((Car*)(temp4->data))->time));
							printf("\t\t\t\t%.2lf", (globalTimer-2.5));
							printf("\t\t\t\t%.2lf\n", globalTimer);
							if (westCars != 0){
								temp4 = temp4->next;
							}
							else{
								temp4 = NULL;
								break;
							}
						}
					}
					else {
						timer = ((((((Car*)(temp4->data))->time) - globalTimer) + 2.5));
						globalTimer = globalTimer + timer;
						loopTimer = (loopTimer + 2.5);
						westCars--;
						carsLeft--;
						carsLeft--;
						printf("%c %c %d", (((Car*)(temp4->data))->initialDirection), (((Car*)(temp4->data))->newDirection), (((Car*)(temp4->data))->time));
						printf("\t\t\t\t%.2lf", (globalTimer-2.5));
						printf("\t\t\t\t%.2lf\n", globalTimer);
						if (westCars != 0){
							temp4 = temp4->next;
						}
						else{
							break;
							temp4 = NULL;
						}
					}
				}
			}

			/* YELLOW LIGHT GO FOR 3s */
			if ((((Car*)(temp4->data))->initialDirection == 'W') && (westCars != 0) && (loopTimer >= 10) && (loopTimer < 14)){
				if (((((Car*)(temp4->data))->newDirection == 'L')) && ( ((((((Car*)(temp4->data))->time) - globalTimer) + 2.5) + globalTimer) <= 13) && ((((Car*)(temp4->data))->time) >= globalTimer)) {
					globalTimer = ((((((Car*)(temp4->data))->time) - globalTimer) + 2.5) + globalTimer);  
					loopTimer = ((((((Car*)(temp4->data))->time) - globalTimer) + 2.5) + loopTimer) + 2.5;
					westCars--;
					carsLeft--;
					printf("%c %c %.2lf\n", (((Car*)(temp4->data))->initialDirection), (((Car*)(temp4->data))->newDirection), globalTimer);
					if (westCars != 0){
						temp4 = temp4->next;
					}
					else{
						temp4 = NULL;
						break;
					}
				}
				else {
					globalTimer = (globalTimer + (14 - globalTimer));
					loopTimer = 14;;
				}	
			}
			/*if (westCars = 0) {
				printf("No west cars in list\n");
				if (loopTimer != 14){
					loopTimer = loopTimer + (14 - loopTimer);
					globalTimer = globalTimer + loopTimer;
				}
			}*/
			break;

		}
		loopTimer = 0;
		timer = 0;
		globalTimer = globalTimer + (57 -globalTimer);
		/* printf("global timer: %lf\n", globalTimer);
		printf("loopTimer: %lf\n", loopTimer);
		printf("Cars left: %d\n", carsLeft); */
		break;  /* my loop doesn't work correctly so i had to break, sorry :( */ 
	}
	/* fclose(theFile); */
	return 0;
}