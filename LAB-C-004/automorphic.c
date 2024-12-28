#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_NumberDigits(unsigned long long n)     // Self explanatory.
{   
    int i = 0;
    while(n != 0) {
        n = n / 10;
        i += 1;
    }

    return i;

}

int main()
{   
    int init_Digits = 0;
    char str_n[25];
    unsigned long long int squared_Digits = 0;
    char* p_DigitEnd;
    int is_Automorphic = 0;
    
    printf("Input n = ");
    fgets(str_n, 25, stdin);
    long long n = atoll(str_n);
    char* pchar_initDigits = (char*) malloc(strlen(str_n));      // INITIALIZED ARRAY, SHRINKED TO FIT.

    if(pchar_initDigits == NULL) {                               // Just in case.
        printf("Failed to allocate memory.");
        exit(-1);
    }

    for(int i = 0; i < strlen(str_n) - 1; i++)
        pchar_initDigits[i] = (str_n[i]);

    squared_Digits = strtoull(pchar_initDigits, &p_DigitEnd, 10);   // Woah, a method to assign string to unsigned long long?
    squared_Digits = squared_Digits * squared_Digits;

    unsigned long long temp = squared_Digits;
    int i = count_NumberDigits(squared_Digits);

    unsigned long temp1 = n;                            // An attempt at making a string detector
    unsigned long long temp2 = squared_Digits;
    while(temp1 != 0) {
        if(temp1 % 10 != temp2 % 10) {
            is_Automorphic = 0;
            break;
        } else {
            is_Automorphic = 1;
        }

        temp1 = temp1 / 10;
        temp2 = temp2 / 10;

    }

    int final_n = atoi(str_n);

    free(pchar_initDigits);

    //printf("Input n = %d\n", final_n);
    printf("n^2 = %llu", squared_Digits);
    
    if(is_Automorphic) 
        printf("\nYes. %d is automorphic number.", final_n);
    else 
        printf("\nNo. %d is not automorphic number.", final_n);
    

    return 0;

}