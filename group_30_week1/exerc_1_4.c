/* ====================================
File name: exerc_1_4.c
Date: 2020-01-26
Group 30
Members that contribute to the solutions
Hjalmar Thunberg
Christian O'Neill
Hugo Hempel
Member not present at demonstration time:
-----
Demonstration code: [6798]
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 7

int genNumber() {
    srand(time(NULL)); // Seeds a new generation with the current time
    int random = rand() % 100 + 1; // range of 100, min of 1
    return random;
}

int main(void) {
    int num = genNumber();
    int guess;
    int guesses = 0;
    printf("Guess a number between 1-100: \n");
    while (guesses < MAX_GUESSES) {
        if (guesses != 0 && guess != num) {
            printf("Try again: ");
        }
        scanf("%d", &guess);
        guesses++;
        if (guess == num) {
            printf("Congrats! You guessed the number in %d tries! WOW!\n", guesses);
            exit(0);
        } else if (guesses >= MAX_GUESSES) {
            printf("You have no more guesses left. Goodbye.\n");
            exit(0);
        } else if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        } else {
            printf("Something happened!\n");
        }
    }
}