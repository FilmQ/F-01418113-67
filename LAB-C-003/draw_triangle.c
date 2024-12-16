#include <stdio.h>
#include <stdlib.h>

int main()
{
    long height = 0;
    char height_Str[20];
    int i = 0, j = 0;

    fgets(height_Str, 22, stdin);
    height = atoi(height_Str);

    // UPPER PART

    while(i < height) {

        j = 0;
        while(j <= height - (height - i)) {
            printf("*");
            j++;
        }

        printf("\n");
        i++;

    }

    // LOWER PART

    i = height - 1;
    while(i > 0) {
        j = i;
        while(j > 0) {
            printf("*");
            j--;
       }

       printf("\n");
       i--;

    }

    return 0;

}