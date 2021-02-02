/* ====================================
File name: exerc_1_1.c
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

void printSentence(int num) {
    if (num < 1 || num > 5) {
        exit(1);
    }
    /* Sentences from: https://randomwordgenerator.com/sentence.php */
    switch(num) {
        case 1:
            printf("We have never been to Asia, nor have we visited Africa.\n\n");
            return;
        case 2:
            printf("Karen realized the only way she was getting into heaven was to cheat.\n\n");
            return;
        case 3:
            printf("As the asteroid hurtled toward earth, Becky was upset her dentist appointment had been canceled.\n\n");
            return;
        case 4: 
            printf("Whenever he saw a red flag warning at the beach he grabbed his surfboard.\n\n");
            return;
        case 5:
            printf("You're unsure whether or not to trust him, but very thankful that you wore a turtle neck.\n\n");
            return;
        default:
            return;
    }
}

int main(void) {
    while (1) {
        short input;
        printf("Enter a number 1-5: ");
        scanf("%d", &input);
        printSentence(input);
    }
    return 0;
}