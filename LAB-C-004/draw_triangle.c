#include <stdio.h>
#include <stdlib.h>

void draw_Triangle(int n_Line) 
{   
    // BEGIN: DESCENDING;
    for(int i = 1; i <= n_Line; i++) {
        for(int j = 1; j <= i; j++) {
            if(j % 2 == 1)
                printf("-");
            else
                printf("x");

            if(j == i)
                printf("\n");
        }
    }
    // END DESCENDING;


    // BEGIN: ASCENDING.
    for(int i = n_Line - 1; i > 0; i--) {
        for(int j = 1; j <= i; j++) {
            if(j % 2 == 1)
                printf("-");
            else
                printf("x");

            if(j == i)
                printf("\n");
        }
    }
    // END: ASCENDING.
}

int main()
{
    int n = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    draw_Triangle(n);
}