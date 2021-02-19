/* ====================================
 File name: exerc_4_2.c
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
void decode(__uint8_t code);

// --- Main including arguments ---
int main(int argc, unsigned char *argv[])
{
    __uint8_t input; // Init space for the hex input
    // If the amount of arguments is invalid exit the program
    if (argc != 2)
    {
        printf("Needs 1 argument (00-FF) to start.\n");
        exit(1);
    }
    else
    {
        // Convert first two chars of the string input to hex, invalid inputs will be 0x00
        input = strtol(argv[1], NULL, 16);
        // Check if hex is in a 8-bit range (0...256)
        if ((int)input < 0 || (int)input > 255)
        {
            printf("Incorrect input.\n");
            exit(1);
        }
        // Pass the hex to be decoded
        decode(input);
    }
    return 0;
}
// defining the decode method
void decode(__uint8_t code)
{
    unsigned char engine_on, gear_pos, key_pos, brake1, brake2; // Declaration of all 5 different bit values
    // Shifting byte back to its 5 different values
    engine_on   = code >> 7; // 1 bit (X0000000 -> 0000000X)
    gear_pos    = code << 1;  // shifting back to get rid of magic numbers
    gear_pos    = gear_pos >> 5; // 3 bit (XXX00000 -> 00000XXX)
    key_pos     = code << 4; // shifting back to get rid of magic numbers
    key_pos     = key_pos >> 6; // 2 bit (XX000000 -> 000000XX)
    brake1      = code << 6; // shifting back to get rid of magic numbers
    brake1      = brake1 >> 7; // 1 bit (X0000000 -> 0000000X)
    brake2      = code << 7; // shifting back to get rid of magic numbers
    brake2      = brake2 >> 7; // 1 bit (X0000000 -> 0000000X)
    // Print the values
    printf("\nName             Value\n----------------------\n");
    printf("engine_on:       %u\n", engine_on);
    printf("gear_pos:        %u\n", gear_pos);
    printf("key_pos:         %u\n", key_pos);
    printf("brake1:          %u\n", brake1);
    printf("brake2:          %u\n", brake2);
}