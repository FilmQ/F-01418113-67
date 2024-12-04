#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x_str[5], y_str[5];

    printf("Enter the x coordinate: ");
    fgets(x_str, 5, stdin);
    printf("Enter the y coordinate: ");
    fgets(y_str, 5, stdin);

    int x = atoi(x_str);
    int y = atoi(y_str);

    if(y == 0) {

        if(x < 0) { printf("West"); }
        if(x > 0) { printf("East"); }
        if(x == 0) { printf("Center"); }
    }

    if(x == 0) {

        if(y > 0) { printf("North"); }
        if(y < 0) { printf("South"); }
    }

    if(x != 0 && y != 0) {

        if(x > 0 && y > 0) { printf("North-east"); } 
        if(x > 0 && y < 0) { printf("South-east"); }

        if(x < 0 && y > 0) { printf("North-west"); }
        if(x < 0 && y < 0) { printf("South-west"); }

    }   
    return 0;
}