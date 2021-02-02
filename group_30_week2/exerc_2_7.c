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

void readPersnr(char *person) {
    char month_nums[] = {person[2], person[3]};
    char day_nums[] = {person[4], person[5]};
    if ((atoi(month_nums) < 1 || atoi(month_nums) > 12) || (atoi(day_nums) < 1 || atoi(day_nums) > 31)) {
        printf("Invalid personnummer.\n");
        return;
    } else {
        controlDigit(person);
    }
}

int controlDigit(const char *persnr) {
    int sum = 0;
    for (int i = 0; i < sizeof(persnr); i++) {
        int cur = atoi(persnr[i]);
        if (i % 2 == 0) {
            cur = cur * 2;
            if (cur > 9) {
                int temp = cur % 10; // 13 % 10 = 3
                cur = (cur / 10) + temp;
            }
        }
        sum += cur;
    }
    printf("%d", sum);
}

int main(void) {
    char s_personnummer[MAX];
    while(1) {
        // Prompt for input and assign it to s_personnummer
        printf("Please enter your personnummer: \n>> ");
        gets(s_personnummer);
        // Compare if s_personnummer is invalid or quit command
        if (s_personnummer[0] == 'q' || s_personnummer[0] == 'Q') {
            printf("Goodbye.\n");
            exit(0);
        } else if (strlen(s_personnummer) != 10) {
            printf("Please enter a valid personnummer.\n");
        // If not, assign it to the s_personnummer
        } else {
            readPersnr(s_personnummer);
        }
    }
    return 0;
}