#include <stdio.h>
#include <stdlib.h>

long double approximate_PiValue(int n_terms)
{
    int constant_Denominator = 3;
    long double approximated_ValueAtTerm = 4;

    for(int i = 1; i < n_terms; i++) {
        if(i % 2 == 1)
            approximated_ValueAtTerm -= (4.0 / constant_Denominator);
        else
            approximated_ValueAtTerm += (4.0 / constant_Denominator);
        constant_Denominator += 2;

    }

    return approximated_ValueAtTerm;

}

int main()
{  
    int n_Term = 1;

    printf("Enter n: ");
    scanf("%d", &n_Term);
    printf("%.10Lf", approximate_PiValue(n_Term));

}