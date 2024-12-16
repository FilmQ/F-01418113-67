#include <stdio.h>
#include <stdlib.h>

int main() 
{   
    char str_digit[10];
    int digit = 0;

    fgets(str_digit, 12, stdin);
    digit = atoi(str_digit);

    int d0 = digit & 1;
    int d1 = digit >> 1 & 1;
    int d2 = digit >> 2 & 1;
    int d3 = digit >> 3 & 1;

    printf("Binary number of %d is %d%d%d%d.", digit, d3, d2, d1, d0);

    return 0;
}