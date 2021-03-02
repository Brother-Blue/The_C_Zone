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
 Demonstration code: [XXXX]
 ====================================== */

// Program for exercise 6.2alt in DIT632
// Version 2020-02-12
// File : sortandfind_20.c
// **************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);
void *swap(void *param);
void *search(void *param);

int main() {
	time_t t;
	pthread_t tid;
	pthread_attr_t attr;
	
	srand((unsigned) time(&t));
	pthread_attr_init(&attr);

	printf("Enter max value\n");
	scanf("%d", &max_value);

	pthread_create(&tid, &attr, runner, NULL);
    pthread_join(tid, NULL);
    pthread_create(&tid, &attr, swap, NULL);
    pthread_join(tid, NULL);
    pthread_create(&tid, &attr, search, NULL);
    pthread_join(tid, NULL);
    
	return 0;
}


// generates an array of integer values, running in a thread.
void *runner(void *param) {
	int c = 0, n=0;
    printf("Executing runner 1");
	for (c = 0; c < num_elems; c++) {
		for(n=0; n<1000; n++); // To delay a bit 
		array[c] = rand() % max_value;
	}

	pthread_exit(0);
}

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