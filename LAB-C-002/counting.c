#include <stdio.h>
#include <stdlib.h>

int main() 
{

    char str_counter[50];
    int i;

    printf("");
    fgets(str_counter, 52, stdin);

    i = atoi(str_counter);

    while(i >= 0) {
        printf("%d\n", i);
        i--;
    }

    return 0;

}