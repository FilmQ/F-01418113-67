#include <stdio.h>
#include <stdlib.h>


void print_Rhombus(int row, int column) 
{
    int i = 0, j = 0, k = 0;

    while(i < row) {

        j = 0;
        while(j < column) {
            if(i == row - 1 || i == 0) {
                printf("*");
                j++;
            }
            else {
                if(j == 0 || j == column - 1)
                    printf("*");
                else
                    printf(" ");
                j++;
            }
        }

//      ROW LOOP

        printf("\n");

        k = 0;
        while(k <= i) {
            printf(" ");
            k++;
        }

        i++;

    }

}
    



int main() 
{
    int row, column;
    char str_Row[20], str_Column[20];

    fgets(str_Column, 22, stdin);
    fgets(str_Row, 22, stdin);

    column = atoi(str_Column);
    row = atoi(str_Row);

    print_Rhombus(row, column);

    return 0;

}