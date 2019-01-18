CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -Iinclude -c -o

all:
	
	$(CC) $(CFLAGS) bin/patient.o src/patient.c
	$(CC) $(CFLAGS) bin/LinkedListAPI.o src/LinkedListAPI.c
	$(CC) $(CFLAGS) bin/QueueAPI.o src/QueueAPI.c
	$(CC) $(CFLAGS) bin/main.o src/main.c 
	$(CC) bin/main.o bin/patient.o bin/patient.o bin/patient.o -o bin/run

clean:
	rm bin/*.o bin/runMain
