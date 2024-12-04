#include <stdio.h>
#include <stdlib.h>

int main() {

    char str_A[20], str_B[20], str_C[20];

    printf("Enter length of side A: ");
    fgets(str_A, 100, stdin);

    printf("Enter length of side B: ");
    fgets(str_B, 100, stdin);

    printf("Enter length of side C: ");
    fgets(str_C, 100, stdin);

    int A = atoi(str_A);
    int B = atoi(str_B);
    int C = atoi(str_C);

    if((A <= 0 || B <= 0 || C <= 0) || (A + B == C || A + C == B ||  B + C == A)) { printf("Triangle type is invalid."); }
    else if(A == B && A == C && B == C) { printf("Triangle type is equilateral."); }
    else if(A != B && A != C && B != C) { printf("Triangle type is scalene."); }
    else { printf("Triangle type is isosceles."); }

    return 0;
    
}