/* ====================================
 File name: exerc_2_6.c
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

#define MAX 5          // Define max queue size
#define EMPTY_SPACE -1 //Define empty queue space

// TODO: FIX so it shows -1 instead of bs
// Initialize an empty queue with EMPTY_SPACE
void initQue(int list[], int max)
{
    for (int i = 0; i < max; i++)
    {
        list[i] = EMPTY_SPACE;
    }
}

// Input an item into the queue
int input(int list[], int number, int max) //queue
{
    printf("Queuing number: %d\n", number);
    // Iterate through queue until empty space is reached
    for (int i = 0; i < max; i++)
    {
        // Replace empty space with number
        if (list[i] == EMPTY_SPACE)
        {
            list[i] = number;
            printf("Number %d was queued.\n", number);
            return 1;
        }
    }
    printf("Queue is full\n");
    return 0;
}
// "dequeues" the first element of the array if the element is not equal to EMPTY_SPACE (-1).
int output(int list[], int max)
{
    // Iterate through queue if first element is not empty print element
    for (int i = 0; i < max; i++)
    {
        if (list[i] != EMPTY_SPACE)
        {
            printf("Dequeued %d.\n", list[i]);
            // Scooch all other elements down
            for (int j = 1; j < max; j++)
            {
                list[j - 1] = list[j];
                list[j] = EMPTY_SPACE;
            }
            return list[0];
        }
        return 0;
    }
}
// init queue and run sequence of methods to test
int main(void)
{
    int list[MAX];
    initQue(list, MAX); // Init new queue
    for (int i = 0; i < MAX; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    input(list, 3, MAX);
    input(list, 4, MAX);
    input(list, 5, MAX);
    input(list, 6, MAX);
    input(list, 7, MAX);
    input(list, 8, MAX);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    output(list, MAX);
    output(list, MAX);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    input(list, 11, MAX);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}