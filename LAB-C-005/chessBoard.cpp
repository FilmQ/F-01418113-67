#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos);

int main()
{
    int n, x, y;
    char piece;
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    char pieceChar[50];

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    scanf("%d", &n);            

    for(int i = 0; i <= n; i++) {
        fgets(pieceChar, 50, stdin);

        for(int j = 0; j < 50; j++)
            if(pieceChar[j] == '\n' || pieceChar[j] == '\0') {
                pieceChar[j] = '\0';
                break;
            }
        
        sscanf(pieceChar, "%c(%d, %d)", &piece, &x, &y);
        setPieceOnTable(board, piece, x, y);
    }

    printf("------------------\n");
    printf("  0 1 2 3 4 5 6 7\n");

    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i);

        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] != 0)
                printf("|%c", board[i][j]);
            else
                printf("| ");
        }
        printf("|\n");
    }
}

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos )
{   
    board[yPos][xPos] = (int)piece;
}