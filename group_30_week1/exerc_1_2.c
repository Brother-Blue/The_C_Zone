/* ====================================
File name: exerc_1_2.c
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

#define MAX_SIZE 200 // Max size of user input
#define AT_WORD 1 // If pointer is at a word
#define AT_SPACE 0 // If pointer is at a space

unsigned countWords(char *sentence) { // Counts words in a given sentence
    unsigned wordCount = 0;
    short flag = AT_SPACE;
    while (*sentence) {
        if (isspace(*sentence)) { // isspace() checks for ' ', \n, \t, \r, \v, \f
            if (flag == AT_WORD) { //checking to see if its only spaces
                flag = AT_SPACE;
            }
        } else {
            if (flag == AT_SPACE) { // triggers once we come to a word
                wordCount++; // Increment word count
                flag = AT_WORD;
            }
        }
        *sentence++; // Increment pointer
    }
    return wordCount;
}

int main(void) {
    while (1) {
        char sentence[] = " ";
        printf("Enter sentence: ");
        gets(sentence); // Using scanf only grabbed the first word, could use some explaining :)
        if (strlen(sentence) > MAX_SIZE) { // Compare with predefined max size
            printf("Sorry, your sentence was too long.");
            continue;
        } else {
            printf("Word count: %u", countWords(&sentence)); // Pass reference to sentence's address
            exit(0);
        }
    }
    return 0;
}