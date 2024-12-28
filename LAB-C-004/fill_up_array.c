#include <stdlib.h>
#include <stdlib.h>

int main() 
{
    int n, i, j;

    printf("Enter the number of rows or columns: ");
    scanf("%d",&n);

    int **a = (int**) malloc(sizeof(int) * n * n);
    for(int i = 0; i < n; i++) {
        a[i] = (int*) malloc(sizeof(int) * n * n);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = (i + 1) + (j);
        }
    }

    // Print all values in array a
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%2d ", a[i][j]);
        printf("\n");
    }

    free(a);

    return 0;

}