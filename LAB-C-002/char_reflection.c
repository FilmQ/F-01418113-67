#include <stdio.h>
#include <stdlib.h>

void string_reflection(int n) 
{

    int i;
    int ascii_offset = 97 + n - 1;

    if(n <= 0 || n > 26) {
        printf("-");
        return -1;
    }

    for(i = ascii_offset; i >= 97; i--) {

        if(i == ascii_offset)                   
            printf("%c", i);
        else if(i != 97 || i != ascii_offset)   
            printf("-%c", i);

    }

    for(i = 98; i <= ascii_offset; i++)
        printf("-%c", i);

}


int main() 
{

    char str_n[10];
    int n = 0;

    fgets(str_n, 12, stdin);
    n = atoi(str_n);

    string_reflection(n);

    return 0;

}