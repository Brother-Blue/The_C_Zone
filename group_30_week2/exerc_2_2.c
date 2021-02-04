/* ====================================
 File name: exerc_2_2.c
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

#define MAX 20 // Max length of the int array

// Populate the array with random integers
void populateArr(int *arr)
{
    for (int i = 0; i < MAX; i++, *arr++) {
        *arr = rand() % 99 + 1; // Creates a random integer 1-99
    }
}

// Print the integer value along with the double casted value
void printDouble(int *arr)
{
    for (int i = 0; i < MAX; i++, *arr++) {
        printf("Int value: %d | Double value: %f\n", *arr, (double) *arr);
    }
}

int main(void)
{
    int arr[MAX]; // Init an int array of MAX size
    
    // Populate the array
    populateArr(arr);

    printf("Address of array: %p\n", &arr);
    printf("First integer of array: %d\n", arr[0]);
    printf("Size of an integer (in bytes): %d\n", sizeof(int));
    printf("Size of whole array (size | memory): %d | %d\n", MAX, MAX * sizeof(int));
    
    // Print integer value and double value
    printDouble(arr);
    
    return 0;
}