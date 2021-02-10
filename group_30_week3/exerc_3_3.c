/* ====================================
 File name: exerc_3_3.c
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
#include <stdlib.h>
#include <time.h>

#define MAX 5 // Assuming this is the max starting length for the list?

typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} Node;

Node *random_list(void); // Init a random list of nodes
Node *add_first(Node *temp, int data); // Adds to beginning of list

int main(void)
{
    int nr = 0;
    Node *print_pointer, *head = NULL;

    srand(time(0)); // Seed a new random
    head = random_list(); // Initialize a new linked list
    print_pointer = head;

    // Print list
    printf("\nInitial list:");
    while (print_pointer != NULL)
    {
        printf("\n Post nr %d : %d", nr++, print_pointer->number);
        print_pointer = print_pointer->next;
    }

    // Add new node and set that to be the head
    head = add_first(head, 1000);
    print_pointer = head; // Reset pointer to beginning
    nr = 0; // Reset counter

    // Print new list
    printf("\n\nList after inserting new node:");
    while (print_pointer != NULL)
    {
        printf("\n Post nr %d : %d", nr++, print_pointer->number);
        print_pointer = print_pointer->next;
    }

    // Cleanup list memory allocation
    while ((print_pointer = head) != NULL)
    {
        head = print_pointer->next;
        free(print_pointer);
    }

    return 0;
}

Node *random_list(void)
{
    int nr, i = 0;
    Node *head, *prev, *cur;

    // Allocate space for head and prev pointers
    head = malloc(sizeof(Node));
    prev = malloc(sizeof(Node));

    // Initialize a head pointer
    head->number = rand() % 101; // 0-100
    head->prev = NULL;
    head->next = NULL;

    for (i = 0; i < MAX; i++) {
        nr = rand() % 101; // Create random number
        cur = malloc(sizeof(Node)); // Allocate space for a new Node
        cur->number = nr; // Give cur a value
        if (head->next == NULL) {
            head->next = cur; // If only head point to current
        }
        cur->prev = prev; // Point current prev back to prev node
        cur->next = NULL; // Point current next to null
        prev->next = cur; // Point previous node next to current
        prev = cur; // Update previous node
    }
    return head;
}

// Adds a new node to the beginning of the list
Node *add_first(Node *temp, int data)
{
    // Allocate memory for a new node
    Node *newNode = malloc(sizeof(Node));
    // Give that boy some info
    newNode->number = data;
    newNode->next = temp;
    newNode->prev = NULL;
    // Point the current head (temp)'s previous to the new node
    temp->prev = newNode;
    // Return the new node and assign it as head
    return newNode;
}