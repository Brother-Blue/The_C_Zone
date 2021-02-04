/* ====================================
 File name: exerc_2_3.c
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
 
 #define MAX_ARG 3 // Max allowed arguments for this program.

 // take two strings and compare
 void compareString(char *string1, char *string2)
 {
     // Compare string lengths
    if (strlen(string1) != strlen(string2)) {
        printf("The strings are not equal.");
        return;
    }
    while (*string1 != '\0') {
        // check if strings are not equal
        if (*string1++ != *string2++) {
            printf("The strings are not equal.");
            return;
        }
    }
    printf("The strings are equal.");
 }
 
int main(int argc, char *argv[])
{
    // if there is 2 extra arguments, compare the strings
    if(argc == MAX_ARG)
    {
        compareString(argv[1], argv[2]);
    }
    else {
        printf("Please start the executeble with 2 strings");
    }
}              