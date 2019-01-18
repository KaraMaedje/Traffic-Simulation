#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "patient.h"
#include "dummyFile.h"
#include "LinkedListAPI.h"


List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){
	
	List *listPtr = malloc(sizeof(List));
	
	listPtr->head = NULL;
	listPtr->tail = NULL;
	listPtr->deleteNode = deleteFunction;
	listPtr->compare = compareFunction;
	listPtr->printNode = printFunction;
	return listPtr;
}


Node *initializeNode(void *data){

	Node *nodePtr = malloc(sizeof(Node));
	
	nodePtr->data = data;
	nodePtr->next = NULL;
	nodePtr->previous = NULL;

	return nodePtr;
}

void insertFront(List *list, void *toBeAdded){

	Node *n = initializeNode(toBeAdded);
	Node *temp = malloc(sizeof(Node));

	if (list->head == NULL){
		list->head = n;
		list->tail = n;
	}
	else {

		temp = list->head;
		temp->previous = n;
		list->head = n;
		n->next = temp;
		n->previous = NULL;
	}
}


void insertBack(List *list, void *toBeAdded){

	Node *n = initializeNode(toBeAdded);
	Node *temp = malloc(sizeof(Node));

	if (list->head == NULL){
		list->head = n;
		list->tail = n;
	}
	else {
		temp = list->tail;
		temp->next = n;
		list->tail = n;
		n->previous = temp;
	}
}

void printForward(List *list){				
	Node *temp;

	temp = list->head; 
	while(temp != NULL){
		list->printNode( ((void*)(temp->data)) );
		temp = temp->next;
	}
}

void printBackwards(List *list){				
	Node *temp;

	temp = list->tail; 
	while(temp != NULL){
		list->printNode( ((void*)(temp->data)) );
		temp = temp->previous;
	}
}

void deleteList(List *list){
	Node *temp;
	while (list->head != NULL){
		temp = list->head;
		list->head = temp->next;
		free(temp);
	}
}

void *getFromFront(List *list){
	
	if (list != NULL && list->head != NULL) {
		return (list->head->data);
	}
	return NULL;
}

void *getFromBack(List *list){
	
	if (list != NULL && list->tail != NULL) {
		return (list->tail->data);
	}
	return NULL;
}

int deleteNodeFromList(List *list, void *toBeDeleted){
Node *itr = list->head;

   while(itr != NULL){
       
       if(toBeDeleted == itr->data){

          if(itr->previous == NULL){

          list->head = itr->next;
          itr->next->previous = NULL;
          free(itr);
          return 0;
          }
          else if(itr->next == NULL){
          list->tail = itr->previous;
          itr->previous->next = NULL;
          free(itr);
          return 0;
          }
          else {
          itr->previous->next = itr->next;
          itr->next->previous = itr->previous;
          free(itr);
          return 0;
          }
       }
       itr = itr->next;
   }
   return 0;

}