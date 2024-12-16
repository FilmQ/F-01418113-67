#include <stdio.h>
#include <stdlib.h>

void recursive_bin(int base_ten)
{
    if(base_ten == 0) {

    }
    else {
        recursive_bin(base_ten / 2);
        printf("%d", base_ten % 2);
    }
}


int main()
{   
    int base10_digit = 0;
    char base10_digitString[50];

    fgets(base10_digitString, 52, stdin);
    base10_digit = atoi(base10_digitString);

    if(base10_digit > 0)
        recursive_bin(base10_digit);
    else
        printf("0");

    return 0;
    
}