/* ====================================
 File name: exerc_2_7.c
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

#define MAX 10 // Max length for personnummer

int charToInt(char c)
{
    // Substract '0' from entered char to get digit
    int num = 0;
    num = c -'0';

    return num;
}

int controlDigit(const char *persnr)
{
    int sum = 0; // Init sum as 0
    for (int i = 0; i < MAX; i++)
    {
        // Convert current 
        int cur = charToInt(persnr[i]);
        // Multiply every other number by 2
        if (i % 2 == 0)
        {
            cur = cur * 2;
            // If the multiplied number is >= 10, split the number and add its parts
            if (cur > 9)
            {
                // e.g (13 / 10) + (13 % 10) = 1 + 3 = 4
                cur = (cur / 10) + (cur % 10);
            }
        }
        // Add the current calculated value to the sum
        sum += cur;
    }
    // If the sum is divisible by 10 then it is a valid personnummer
    if (sum % 10 == 0)
    {
        return 1;
    }
    return 0;
}

int readPersnr(char *person)
{
    // Multiply by 10 to convert to double digit months / dates    e.g. 2*10+7 = 27
    int month_nums = (charToInt(person[2])* 10) + charToInt(person[3]);
    int day_nums = (charToInt(person[4])* 10) + charToInt(person[5]);
    // Check if month and day is valid
    if ((month_nums < 1 || month_nums > 12) || (day_nums < 1 || day_nums > 31))
    {
        printf("Invalid personnummer.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    char s_personnummer[MAX];
    while (1)
    {
        // Prompt for input and assign it to s_personnummer
        printf("Please enter your personnummer: \n>> ");
        gets(s_personnummer);
        // Compare if s_personnummer is invalid or quit command
        if (s_personnummer[0] == 'q' || s_personnummer[0] == 'Q')
        {
            printf("Goodbye.\n");
            exit(0);
        }
        else if (strlen(s_personnummer) != 10)
        {
            printf("Please enter a valid personnummer.\n");
            // If not, assign it to the s_personnummer
        }
        else if (readPersnr(s_personnummer))
        {
            if (controlDigit(s_personnummer))
            {
                printf("This is a valid personnummer.\n");
            }
            else
            {
                printf("This is not a valid personnummer.\n");
            }
        }
    }
    return 0;
}