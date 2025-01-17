#include <stdio.h>

int main() 
{   
    char c_String[200];
    char str_VowelsArray[150];


    // BEGIN: INIT ALL ENTRIES WITH NULL CHAR.
    for(int i = 0; i < 200; i++)
        c_String[i] = '\0';

    for(int i = 0; i < 150; i++)
        str_VowelsArray[i] = '\0';
    // END: BEGIN. NULL CHAR ASSIGNMENT


    printf("String (without a space): ");
    scanf("%s", c_String);


    // BEGIN: COUNT STRING TO {string_Length}.
    int string_Length = 0;
    for(int i = 0;; i++) {
        if(c_String[i] == '\0' || c_String[i] == '\n')
            break;
        string_Length++;
    }
    // END: COUNT STRING.


    // BEGIN: COUNT AND INSERT VOWELS INTO {str_VowelsArray}.
    int j = 0;
    for(int i = 0; i < string_Length; i++) {
        if(c_String[i] == 'A' || c_String[i] == 'a' ||
           c_String[i] == 'E' || c_String[i] == 'e' ||
           c_String[i] == 'I' || c_String[i] == 'i' ||
           c_String[i] == 'O' || c_String[i] == 'o' ||
           c_String[i] == 'U' || c_String[i] == 'u' ) 
           {
                str_VowelsArray[j] = c_String[i];
                ++j;
           }
    }
    // END: COUNT AND INSERT.

    // BEGIN: PRINT RESULT.
    if(j > 1) {
        for(int i = 0;; i++) {
            if(str_VowelsArray[i] == '\0' || str_VowelsArray[i] == '\n')
                break;
            else
                printf("%c ", str_VowelsArray[i]);
        }
        printf("\nThis string contains %d vowels.", j);
    }
    else if(j == 1) {
        printf("%c", str_VowelsArray[0]);
        printf("\nThis string contains 1 vowel.", j);
    }
    else {
        printf("\nThis string contains 0 vowel.");
    }
    // END. PRINT RESULT.
    
}