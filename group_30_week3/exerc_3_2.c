/* ====================================
 File name: exerc_3_2.c
 Date: 2021-02-04
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: []
 ====================================== */

#include <stdio.h>

/* Declare methods */
int search_number(int num, int tab[], int size);
void sort(int num, int tab[]);
void swap(int *first, int *second);

/* Main */
int main(void)
{
    // Create test arrays
    int testArr[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int testArr2[] = {1, 2, 34, 12, 67, 3, 23, 12, 13, 10};
    sort(sizeof(testArr) / sizeof(testArr[0]), testArr); // sizeof(testArr) / sizeof(testArr[0]) gets the size of the array
    printf("Index of searched number: %d", search_number(12, testArr2, sizeof(testArr2) / sizeof(testArr2[0])));
}

// Returns index of a number in an array, -1 if number not found
int search_number(int num, int tab[], int size)
{
    // Iterate through and return first index of an element, -1 if not found
    for (int i = 0; i < size; i++) {
        // Iterate through until number is found, if found return the index
        if (tab[i] == num) return i;
    }
    // Otherwise return -1
    return -1;
}

// Swaps two elements of an array
void swap(int *first, int *second) {
    // Create a temp placeholder, and swap the passed values
    int temp = *first;
    *first = *second;
    *second = temp;
}

void sort(int num, int tab[]) {
    // Start at begin of array
    for (int i = 0; i < num; i++) {
        // Start the check at the current smallest element
        for (int j = i; j < num; j++) {
            // Swap if the current is less than the smallest
            if (tab[j] < tab[i]) {
                swap(&tab[j], &tab[i]);
            }
        }
    }

    // Print the array
    for (int i = 0; i < num; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}