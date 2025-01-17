#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

void bishopMoves(int x, int y)
{
    char Line_Partition[] = "------------------\n";
    int i = 0, j = 0, k = 0;

    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%s", Line_Partition);
        printf("%d|", i);

        k = i;
        for(j = 0; j < BOARD_SIZE; j++) {
            if(j == x && i == y) 
                printf("B");
            else if(x - i == j - y)
                printf("X");
            else if(y + j == x + i)
                printf("X");
            else 
                printf(" ");
            
            if(j == BOARD_SIZE - 1)
                printf("|\n");
            else
                printf("|");
        }
    }
    printf("%s", Line_Partition);
}

int main()
{   
    int x, y;

    printf("Enter Bishop's X Y position: ");
    scanf("%d %d", &x, &y);

    bishopMoves(x, y);
}