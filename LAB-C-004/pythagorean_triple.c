#include <stdio.h>
#include <stdlib.h>

int main() 
{   

    int max = 0;

    scanf("%d", &max);

    if(max <= 5000) {
        int a = 1, b = 1, c = 1;


    while(a*2 <= max) {
        b = a;
        while(b*2 <= max) {
            c = b;
            while(c*2 <= max) {
                if((a * a) + (b * b) == (c * c) && (a + b + c) == max) {
                    printf("(%d, %d, %d)", a, b, c);
                    exit(0);
                }
                c++;
            }
            b++;
        }
        a++;
    }
    
    printf("No triple found.");
    exit(0);

    }

    else {
        int a, b, c = 0;
        int m = 2;  

        scanf("%d", &max);  
        while(c < max) {    
            for(int n = 1; n < m; ++n) {    

                a = m * m - n * n;
                b = 2 * m * n;
                c = m * m + n * n;  

                if((a*a) + (b*b) == (c*c) && (a + b + c) == max) {
                    printf("(%d, %d, %d)", a, b, c);
                    exit(0);
                }   
            }
            m++;
        }   
        printf("No triple found.");
        }

}



