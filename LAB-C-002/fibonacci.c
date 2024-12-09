#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fibo(int n) {
    long long n_fibonacci = 1;

    if(n == 0)         { return 0; }
    else if(n <= 2)    { return 1; }

    else {
       n_fibonacci = (pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n)) / (pow(2, n) * sqrt(5));
        return n_fibonacci;
    }

}

/*
int main() {

    char str_n[50];
    long n;
    int i = 0;

    fgets(str_n, 52, stdin);
    n = atol(str_n);

    while(i <= n) {

        printf("%ld\n", fibo(i));
        i++;
    }

    return 0;

}
*/

int main() {

    char input_n[5];

    fgets(input_n, 5, stdin);
    int n, i;
    n = atoi(input_n);

    for (i = 0; i <= n; i++) {
        printf("F(%d) = %ld\n", i, fibo(i));
    }
    return 0;
}
