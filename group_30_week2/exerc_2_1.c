 /* ====================================
 File name: exerc_2_1.c
 Date: 2021-02-01
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Demonstration code: [6197]
 ====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20 // Max length of input text

void copyString(char *location, char *toCopy)
{
    // Iterate through until the end of the string
    while (*toCopy != '\0') { 
        // Assign the pointer for the target the value of the string to copy
        // then increment both pointers
        *location++ = *toCopy++; 
        
    }                           
}

int main(int argc, char *argv[])
{
    char s_copyLib[MAX]; // Init the 'copy with library' array
    char s_copyFunc[MAX]; // Init the 'copy with our function' array
    char s_input[MAX]; // Init the user input / file input array

    // // If there is no extra arguments (file redirect)
    // if (argc == 1) 
    // {
    //     printf(">> ");
    //     gets(s_input);
    //     s_input[MAX] = '\0'; // Clip the user input to max 20 chars
    //     // Call lib copy
    //     strcpy(s_copyLib, s_input); 
    //     // Call our copy
    //     copyString(s_copyFunc, s_input); 
    // }
    // // If there is more than one arg then we get the file redirect
    // else 
    // {
    //     strcpy(s_copyLib, argv[1]);
    //     copyString(s_copyFunc, argv[1]);
    // }

    // Better code discussed during review
    fgets(s_input, 20, stdin);
    strcpy(s_copyLib, s_input);
    copyString(s_copyFunc, s_input);

    printf("String copied using library: %s\n", s_copyLib);
    printf("String copied using own function: %s\n", s_copyFunc);
    // Free up the memory
    free(s_copyLib); 
    free(s_copyFunc); 
    free(s_input); 
    return 0;
}