/* ====================================
 File name: exerc_2_5.c
 Date: 2021-02-02
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Yyyyyy  yyyy
 Demonstration code: [<Ass code 1-4> <abc>]
 ====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Define max size for array
#define MAXNUMBER 20 // Define upper bound for random integer

// Populate the array with random integers
void create_random(int *table)
{
    for (int i = 0; i < MAX; i++) {
        *table++ = rand() % MAXNUMBER; // Creates a random integer 0-20
    }
}

// Iterate through the integer range 0-MAXNUMBER
// Count the occurances of a number and store them in frequency[]
void count_frequency(int *table, int *freq)
{
    // Iterate through each number 0-MAXNUMBER
    for (int i = 0; i <= MAXNUMBER; i++) {
        int count = 0; // Init count of each number
        // Iterate through each element of the table
        for (int j = 0; j < MAX; j++) {
            // Compare if they're equal to the current number, if yes increment
            if(i == table[j]) {
                count++;
            }
        }
        // Set freq pointer to the count since it will be in order of 0-MAXNUMBER
        freq[i] = count;
    }
}

// Iterate through each number in frequency
// Print n amount of 'x' for each occurance
void draw_histogram(int *freq)
{       
    for (int i = 0; i < MAXNUMBER; i++) {
        if (freq[i] != 0) {
            printf("%d ", i);
        } else {
            continue;
        }
        for (int j = 0; j < freq[i]; j++) {
            printf("x");
        }
        printf("\n");
    }
}

int main(void)
{
    int table[MAX]; // Init table with MAX size
    int frequency[MAXNUMBER]; // Init table with upper bound
    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);
    return 0;
}