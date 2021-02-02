/* ====================================
File name: exerc_1_3.c
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
#include <string.h>

#define ASCII_CONVERT 13 // Converter for ascii chars

void encode(char *sentence) {
    while (*sentence) {
        if (('A' <= *sentence && *sentence <= 'Z')) { // Filter out Uppercase
            if (*sentence <= 'M') { // Filter out A-M
                *sentence += ASCII_CONVERT;  // Increments ASCII value
            } else if (*sentence >= 'N') { // Filter out N-Z
                *sentence -= ASCII_CONVERT; // Decrements ASCII value
            }
        } else if ('a' <= *sentence && *sentence <= 'z') { // Filter out Lowercase
            if (*sentence <= 'm') { // Filter out a-m
                *sentence += ASCII_CONVERT; // Increments ASCII value
            } else if (*sentence >= 'n') { // Filter our n-z
                *sentence -= ASCII_CONVERT; // Decrements ASCII value
            }
        }
        *sentence++;
    } 
}

int main(void) {
    char sentence[] = "";
    while (1) { // While not end of file ctrl+z (Windows) or ctrl+d (Linux)
        printf("Please enter your word or phrase: ");
        gets(sentence);
        if (feof(stdin)) {  // Checks for EOF and exits with exit success
            exit(0);
        }
        encode(&sentence); // Else encode the message
        printf("Your message: %s\n", sentence);
    }
    return 0;
}