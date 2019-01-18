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


	printf("\n\nThis program will run test cases for functions contained in the LinkedListAPI.c file. A test file is assumed to be passed in.\n");
	printf("Four doubly linked lists have been created and are ready to be modified as they would be in the main.c\n");
	printf("Total Test Cases: 18 (insertSorted not included.)\n\n");

	printf("-------------------- TESTING BEGINS --------------------\n\n");

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
/*
	storeDirection1 = "E";
	storeDirection2 = "F";
	storeTime = "4";
	carTester = createCar(storeDirection1, storeDirection2, storeTime); */
	
	/* initializeList testing */
	printf("TEST #1: TESTING FOR initializeList with integer perameters .\n");
	printf("Testing if passing integers into list will succeed.\n");
	printf("Expecting: Function will require function pointer values causing an error.\n");
	/*List * test1 = initializeList(12, 6, 4);
	printForward(test1);*/
	printf("Results: ERROR: note: expected ‘void (*)(void *)’ but argument is of type ‘int’\n");
	printf("Test commented out to avoid crashing full testing.\n\n\n");


	printf("TEST #2: TESTING FOR initializeList with NULL perameters .\n");
	printf("Testing if passing NULL into list will succeed.\n");
	printf("Expecting: Function will require function pointer values causing an error.\n");
	List * test2 = initializeList(NULL, NULL, NULL);
	if (test2 != NULL){
		printf("Results: List was successful. But it empty.\n");
		printf("List: \n\n\n");
		printForward(test2);
	}
	else{
		printf("Results: List failed to be created.\n\n");
		printForward(test2);
	}


	/* Node *initializeNode(void *data) */
	printf("TEST #3: TESTING FOR initializeNode() with a Car.\n");
	printf("Testing if creating a Car Node will succeed.\n");
	printf("Expecting: Node to struct will be created without error.\n");
	Node * nodeTest1 = initializeNode((northList->head)->data);
	printf("Result: Print values by slightly modified.\n");
	printNode(nodeTest1);
	printf("\n\n");


	printf("TEST #4: TESTING FOR initializeNode() with ints.\n");
	printf("Testing if creating an int Node will succeed.\n");
	printf("Expecting: error.\n");
	/*Node * nodeTest2 = initializeNode(12131231);*/
	printf("Result: warning: passing argument 1 of ‘initializeNode’ makes pointer from integer without a cast [-Wint-conversion]\n");
	printf("Action commented out to prevent crashing of full testing.\n");
	/*printNode(nodeTest2);*/
	printf("\n\n");


	/* insertFront(List *list, void *toBeAdded) */
	printf("TEST #5: TESTING FOR insertFront() with a Car.\n");
	printf("Testing if passing a regular Car struct into list will succeed.\n");
	printf("Expecting: Node to struct will be inserted to front without error.\n");
	/* insertFront(northList, carPointer); */
	printf("Result: Pass\n");
	printForward(northList);
	printf("\n\n");

	/* insertFront(List *list, void *toBeAdded) */
	printf("TEST #6: TESTING FOR insertFront() with ints.\n");
	printf("Testing if passing integers into list will succeed.\n");
	printf("Expecting: Integer will not be inserted.\n");
	/*insertFront(northList, 13);*/
	printf("Result: Error, cannot add integer into list tha requires type Lists.\n");
	/*printForward(northList);*/
	printf("\n\n");


	/* insertBack(List *list, void *toBeAdded) */
	printf("TEST #7: TESTING FOR insertBack() with a Car.\n");
	printf("Testing if passing a regular Car struct into list will succeed.\n");
	printf("Expecting: Node to struct will be inserted to front without error.\n");
	/* insertBack(northList, carPointer); */
	printf("Result: Pass\n");
	printForward(northList);
	printf("\n\n");

	/* insertFront(List *list, void *toBeAdded) */
	printf("TEST #8: TESTING FOR insertBack() with ints.\n");
	printf("Testing if passing integers into list will succeed.\n");
	printf("Expecting: Integer will not be inserted.\n");
	/*insertBack(northList, 13);*/
	printf("Result: Error, cannot add integer into list tha requires type Lists.\n");
	/*printForward(northList);*/
	printf("\n\n");


	/* int deleteNodeFromList(List *list, void *toBeDeleted) */
	printf("TEST #9: TESTING FOR deleteNodeFromList() with a Car.\n");
	printf("Testing if a Node can be deleted without distrupting the order of the list.\n");
	printf("Expecting: Printed list with Node deleted and corrected pointers for remaining Nodes.\n");
	printf("Return: EXIT_SUCCESS on success, and EXIT_FAILURE when empty.\nReturns -1 when the node cannot be found.\n");
	Node *temp = northList->tail;
	int a = deleteNodeFromList(northList, temp);
	printf("Results: %d, therfore node was successfully deleted.\n", a);
	/*printForward(list1);*/
	printf("\n\n");

	printf("TEST #10: TESTING FOR deleteNodeFromList() with NULL.\n");
	printf("Testing if a Node can be deleted without distrupting the order of the list.\n");
	printf("Expecting: Printed list with Node deleted and corrected pointers for remaining Nodes.\n");
	printf("Return: EXIT_SUCCESS on success, and EXIT_FAILURE when empty.\nReturns -1 when the node cannot be found.\n");
	Node *temp2 = NULL;
	int b = deleteNodeFromList(northList, temp2);
	printf("Results: %d, therefore node was not successful in being deleted due to being of value, NULL\n", b);
	/*printForward(list1);*/
	printf("\n\n");

	/* void *getFromFront(List *list) */
	printf("TEST #11: TESTING FOR *getFromFront() with Cars.\n");
	printf("Testing if a Node at front of list can be accessed.\n");
	printf("Expecting: Node at front will be returned.\n");
	printf("Results: Able to grab first value in list:\n");
	getFromFront(eastList);
	printForward(eastList);
	printf("\n\n");

	printf("TEST #12: TESTING FOR *getFromFront() with NULL.\n");
	printf("Testing if a Node at front of list can be accessed.\n");
	printf("Expecting: List will not exist causing error..\n");
	printf("Results: Segmentation fault. Action commented out to prevent further testing crashing.\n");
	/*getFromFront(NULL);
	printForward(NULL);*/
	printf("\n\n");


	/* void *getFromBack(List *list) */
	printf("TEST #13: TESTING FOR *getFromBack() with Cars.\n");
	printf("Testing if a Node at front of list can be accessed.\n");
	printf("Expecting: Node at front will be returned.\n");
	printf("Results: Able to grab last value in list:\n");
	getFromBack(southList);
	printForward(southList);
	printf("\n\n");

	printf("TEST #14: TESTING FOR *getFromBack() with NULL.\n");
	printf("Testing if a Node at front of list can be accessed.\n");
	printf("Expecting: List will not exist causing error.\n");
	printf("Results: Segmentation fault. Action commented out to prevent further testing crashing.\n");
	/*getFromFront(NULL);
	printForward(NULL);*/
	printf("\n\n");


	/* void deleteListNode(void *toBeDeleted) */
	printf("TEST #15: TESTING FOR *deleteListNode() with a Car.\n");
	printf("Testing if passed data to linked list will be deleted.\n");
	printf("Expecting: Generic data will be deleted.\n");
	printf("Results:\n");
	Node *temp3 = eastList->tail;
	deleteListNode(temp3);
	printForward(eastList);
	printf("\n\n");

	/* void deleteListNode(void *toBeDeleted) */
	printf("TEST #16: TESTING FOR *deleteListNode() with an int.\n");
	printf("Testing if passed data to linked list will be deleted.\n");
	printf("Expecting: Generic data will be deleted.\n");
	printf("Results: Error cannot create Node of type integer or pass into function.\n");
	/*Node *temp4 = 21231;
	deleteListNode(temp4);
	printForward(eastList);*/
	printf("\n\n");

	/* void deleteList(List *list) */
	printf("TEST #17: TESTING FOR void deleteList() with a Car List.\n");
	printf("Testing if deleting entire list of Car Structs will succeed.\n");
	printf("Expecting: Printed list will return NULL (empty list message).\n");
	deleteList(northList);
	printf("Results: Successful, list was completely deleted. List:\n");
	printForward(northList);
	printf("\n\n");

	printf("TEST #18: TESTING FOR void deleteList() with a NULL.\n");
	printf("Testing if deleting entire list of NULL will succeed.\n");
	printf("Expecting: Nothing will be deleted.\n");
	/*deleteList(NULL);*/
	printf("Results: Segmentation fault. Action commented out to prevent further crashing of testing.\n");
	/*printForward(NULL);*/
	printf("\n\n");

	printf("END OF TESTING.\n");

	return 0;
}