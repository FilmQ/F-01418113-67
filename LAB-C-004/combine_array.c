#include <stdio.h>

int main()
{
    int i, a[5], b[5], c[10];
    
    printf("Enter array a: \n");

    for(int i = 0; i < 5; i++) {
        printf("Please enter an integer: ");
        scanf("%d",&a[i]);
    }

    printf("Enter array b: \n");

    for(int i = 0; i < 5; i++) {
        printf("Please enter an integer: ");
        scanf("%d", &b[i]);
    }

    for(int i = 0, j = 0; i < 10; i++) {
        if(i < 5)
            c[i] = a[i];
        if(i >= 5) {
            c[i] = b[j];
            ++j;
        }
    }

    printf("Array c: ");
    for (i=0;i<10;i++)
        printf ("%d ",c[i]);

    printf ("\n");
    return 0;
}