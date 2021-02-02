#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

void copyString(char *location, char *toCopy)
{
    while (*toCopy != '\0') {
        *location++ = *toCopy++;
    }
}

int main(int argc, char *argv[])
{
    char s_copyLib[MAX];
    char s_copyFunc[MAX];
    char s_input[MAX];

    if (argc == 1)
    {
        printf(">> ");
        gets(s_input);
        s_input[MAX] = '\0';
        strcpy(s_copyLib, s_input);
        copyString(s_copyFunc, s_input);
    }
    else
    {
        strcpy(s_copyLib, argv[1]);
        copyString(s_copyFunc, argv[1]);
    }
    printf("String copied using library: %s\n", s_copyLib);
    printf("String copied using own function: %s\n", s_copyFunc);
    free(s_copyLib);
    free(s_copyFunc);
    free(s_input);
    return 0;
}