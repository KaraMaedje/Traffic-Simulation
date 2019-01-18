# Traffic-Simulation
Data Structures Course Project


This program makes use of a LinkedListAPI.c file and creates a set of doubly linked lists 
based on input given in a text file through the command line. The purpose of the program 
is to sort the data and then simulate a traffic light with various rules.The goal is too 
allow each "car" to safely pass through the light while making use of the linked list 
functions and within a simulated time frame. The assignment forlder also contains a testMain
where these functions can be tested with various different cases. For more details, please 
refer to the assignment guidlines. 

I was not able to complete the insertSorted() function for this assignment, therefore I also
did not test for it in my testMain.c. There are only 18 test cases in total.

In the exectuion of my main.c, I had to add a break after the first cycle (one complete light
for each direction) due to my loop breaking at last moment. I did this to prevent ruining the
entire program and at least be able to spare the first cycle that was successful. 
