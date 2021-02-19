/* ====================================
 File name: exerc_4_3.c
 Date: 2021-02-16
 Group 30
 Members that contribute to the solutions
 Christian O'Neill
 Hugo Hempel
 Hjalmar Thunberg
 Member not present at demonstration time:
 Hugo Hempel
 Demonstration code: [4580]
 ====================================== */

#include <time.h>
#include <stdio.h>

// Declare methods
void f_delay(int);
unsigned char random_inport(void);
void printport(int);

// --- Main ---
int main()
{
    int nr;
    unsigned char port;
    srand(time(0));
    for (nr = 0; nr < 10; nr++)
    {
        port = random_inport();
        printport(port);
        f_delay(5);
    }
    return (0);
}
// Gives a time delay for a number of tenths of a second.
void f_delay(int tenth_sec)
{

    clock_t start_t, end_t;
    long int i;
    start_t = clock();
    do
    {
        for (i = 0; i < 10000000; i++)
            ;
        end_t = clock();
    } while ((end_t - start_t) < (tenth_sec * CLOCKS_PER_SEC) / 10);
    return;
}
// Generates a random value 0 – 255. "simulates a keypress"
unsigned char random_inport(void)
{
    unsigned char inport = 0;
    inport = rand() % 256;
    return (inport);
}
// Prints out the binary pattern and the decimal value for a char of value 0 – 255.
void printport(int portvalue)
{
    int binchar[8], rest, j, i = 0; // Declaration of new variables
    rest = portvalue;
    while (rest != 0)
    {
        binchar[i++] = rest % 2;
        rest = rest / 2;
    }
    // Fill to 8 bits
    while (i < 8)
    {
        binchar[i++] = 0;
    }
    // Print hex if the 7th bit is 0  
    if (binchar[7] == 0) {
        unsigned char val = 0x00000000; // Declaration of printing value
        // Take first 4 (0-3) bits in the byte and store then in val
        for ( int i = 3 ; i >=0 ; i--)
        {
            val += binchar[i] << i; // Store and shift each bit into val
        }
        printf("\nHex value: %X\n", val); // Print val in a hexidecimal value
    }

    return;
}