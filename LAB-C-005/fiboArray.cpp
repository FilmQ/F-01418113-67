#include <stdio.h>
#include <stdlib.h>


unsigned long *fibo_array(unsigned int n, double *golden_ratio);

int main() {

    // MAIN FN. ONLY CONSISTS OF TESTS; THE ONLY THING THAT MATTERS IS THE FUNCTION IMPLEMENTATION.

    int n = 10;
    double main_GoldenRatio;
    unsigned long* ptr_FiboArray;
    ptr_FiboArray = fibo_array(n, &main_GoldenRatio);

    for(int i = 0; i < n; i++) 
        printf("%lu\n", ptr_FiboArray[i]);

    printf("%lf", main_GoldenRatio);

    free(ptr_FiboArray);

    return 0;   

}

unsigned long *fibo_array(unsigned int n, double *golden_ratio)
{   
    unsigned long* fib_array = (unsigned long*) malloc(n * sizeof(unsigned long));

    int i = 0;
    for(i = 0; i < n; i++) {
        if(i < 2) 
            fib_array[i] = i;
        if(i >= 2)
            fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
    }

    double temp = fib_array[i - 1] + fib_array[i - 2];
    double temp2 = temp + fib_array[i - 1];
    double golden_ratioDigit = temp2 / temp;

    *golden_ratio = golden_ratioDigit;  // Pointer to a value

    return fib_array;
}