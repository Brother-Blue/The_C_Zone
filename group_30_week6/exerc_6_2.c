 /* ====================================
 File name: exerc_6_2.c
 Date: 2021-03-03
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Hugo Hempel
 Demonstration code: [9421]
 ====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define num_elems 200 // declare constant of value 200
int array[200]; // declare array of size 200
int max_value; // declare variable

/* Declare methods */
void *runner(void *param);
void *swap(void *param);
void *search(void *param);

/* Main */
int main() {
	time_t t; // declare time
	pthread_t tid; // declare thread id
	pthread_attr_t attr; // declare thread attribute
	
	srand((unsigned) time(&t));
	pthread_attr_init(&attr);

	printf("Enter max value\n");
	scanf("%d", &max_value);
	pthread_create(&tid, &attr, runner, NULL); // creates thread nr1
    pthread_join(tid, NULL); // wait for thread nr1 to finish
    pthread_create(&tid, &attr, swap, NULL); // creates thread nr2
    pthread_join(tid, NULL); // wait for thread nr2 to finish
    pthread_create(&tid, &attr, search, NULL); // creates thread n3
    pthread_join(tid, NULL); // wait for thread nr3 to finish
    
	return 0;
}

// Define methods

// generates an array of integer values, running in a thread.
void *runner(void *param) {
	int c = 0, n=0; // variables for use in for loops.
    printf("Executing runner 1");
	for (c = 0; c < num_elems; c++) {
		for(n=0; n<1000; n++); // To delay a bit 
		array[c] = rand() % max_value;
	}
	pthread_exit(0);
}

// sorts the array from lowest to highest by swapping.
void *swap(void *param) {
    int c, d, swap;
    printf("\nExecuting runner 2");
	for (c = 0; c < num_elems; c++) {
		for (d = 0; d < num_elems - c - 1; d++) {
			if (array[d] > array[d + 1]) {
				swap = array[d];
				array[d] = array[d + 1];
				array[d + 1] = swap;
			}
		}
	}
    pthread_exit(0);
}

// searches for a number given by the user and prints the position of it
void *search(void *param) {
	int search;
	printf("\nEnter value to find\n");
	scanf("%d", &search);
    printf("\n Executing runner 3");

	int first = 0;
	int last = num_elems - 1;
	int middle = (first + last) / 2;
	int n;
	for(n=0; n<num_elems; n++){
	    printf("\n %d", array[n]);
	}

	while (first <= last) {
		if (array[middle] < search)
			first = middle + 1;
		else if (array[middle] == search) {
			printf("\n %d found at location %d.\n", search, middle + 1);
			break;
		} else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)
		printf("\n Not found! %d is not present in the list.\n", search);

    pthread_exit(0);
}