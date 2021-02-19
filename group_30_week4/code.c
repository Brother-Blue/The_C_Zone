 /* ====================================
 File name: exerc_4_1.c
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

#include <stdio.h>
#include <stdlib.h>

// Declare methods
unsigned char pack(unsigned char *argv[]);
void unpack(unsigned char car_state, unsigned char *engine_on, unsigned char *gear_pos, unsigned char *key_pos, unsigned char *brake1, unsigned char *brake2);

// --- Main including arguments ---
int main(int argc, unsigned char *argv[])
{  
    // Code needs to take 5 arguments
    if (argc != 6 ) {
        printf("Needs 5 arguments to start.\n");
        exit(1);
    }
    // Check correct number range on all arguments (0-1, 0-4, 0-2, 0-1, 0-1)
    else
    { 
        if (argv[1][0] > '1' || argv[1][0] < '0') {
            printf("First argument need to be 0 or 1.\n");
            exit(1);
        }
        if (argv[2][0] > '4' || argv[2][0] < '0') {
            printf("Second argument need to be between 0 and 4.\n");
            exit(1);
        }
        if (argv[3][0] > '2' || argv[3][0] < '0') {
            printf("Third argument need to be between 0 and 2.\n");
            exit(1);
        }
        if (argv[4][0] > '1' || argv[4][0] < '0') {
            printf("Forth argument need to be 0 or 1.\n");
            exit(1);
        }
        if (argv[5][0] > '1' || argv[5][0] < '0') {
            printf("Fifth argument need to be 0 or 1.\n");
            exit(1);
        }
    }
    
    unsigned char engine_on, gear_pos, key_pos, brake1, brake2; // Declaration of all 4 different bit values
    unsigned char car_state; // Declaration for storing the values in a byte

    car_state = pack(argv);

    unpack(car_state, &engine_on, &gear_pos, &key_pos, &brake1, &brake2);
    
    printf("Packed into a byte and printed in hex form: %X\n", car_state);

    return 0;
}

// Pack values into a byte
unsigned char pack(unsigned char *argv[]) 
{
    unsigned char engine_on, gear_pos, key_pos, brake1, brake2; // Declaration of all 5 different bit values
    unsigned char mask = 3 << 4; // Mask for ignoring magic numbers (0x00110000 kept showing up in argv)
    unsigned char car_state; // Declaration for storing the values in a byte

    // Shifting 5 bit values to fit a byte, e.g: 1 2 2 1 1 -> 1 010 10 1 1. Subtract by mask to get rid of (0x00110000) that kept showing up in some argv's
    engine_on = (argv[1][0] - mask) << 7; // 1 bit (0000000X -> X0000000)
    gear_pos  = (argv[2][0] - mask) << 4; // 3 bit (00000XXX -> 0XXX0000)
    key_pos   = (argv[3][0] - mask) << 2; // 2 bit (000000XX -> 0000XX00)
    brake1    = (argv[4][0] - mask) << 1; // 1 bit (0000000X -> 000000X0)
    brake2    = (argv[5][0] - mask) << 0; // 1 bit (0000000X -> 0000000X)

    // Combining the shifted bits into a byte
    return engine_on | gear_pos | key_pos | brake1 | brake2;
}

// Unpack variables
void unpack(unsigned char car_state, unsigned char *engine_on, unsigned char *gear_pos, unsigned char *key_pos, unsigned char *brake1, unsigned char *brake2) 
{
    // Shifting byte back to its 5 different values
    *engine_on = car_state >> 7; // 1 bit (X0000000 -> 0000000X)
    *gear_pos  = car_state >> 4; // 3 bit (0XXX0000 -> 00000XXX)
    *key_pos   = car_state >> 2; // 2 bit (0000XX00 -> 000000XX)
    *brake1    = car_state >> 1; // 1 bit (000000X0 -> 0000000X)
    *brake2    = car_state >> 0; // 1 bit (0000000X -> 0000000X)
}