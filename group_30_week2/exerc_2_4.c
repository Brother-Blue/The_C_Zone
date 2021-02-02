/* ====================================
 File name: exerc_2_4.c
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

#define MAX 200 // Define max size for array

void compareString(char *string1, char *string2)
{
    while (*string1 != '\0')
    {
        if (*string1++ != *string2++)
        {
            printf("The string is not a palindrome.\n");
            return;
        }
    }
    printf("The strings is a palindrome.\n");
}

int main(void)
{
    char sentence[MAX];
    char sentence1[MAX];
    while (1)
    { // While not end of file ctrl+z (Windows) or ctrl+d (Linux)
        if (feof(stdin))
        { // Checks for EOF and exits with exit success
            exit(0);
        }
        else
        {
            printf("Enter a string to check if it is a palindrome: \n>> ");
            gets(sentence);
            strcpy(sentence1, sentence);
            strrev(sentence1);
            compareString(sentence, sentence1);
        }
    }
    return 0;
}