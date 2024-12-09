#include <stdio.h>
#include <stdlib.h>

long long fn_gcd(long long m, long long n) 
{
    long long temp_n = 0;

    while(m % n != 0) {
        temp_n = m % n;
        m = n;
        n = temp_n;
    }

    return n;

}


int main() {

    char str_numerator[20], str_denominator[20];
    long long numerator, denominator, lowest_numerator, lowest_denominator;

    fgets(str_numerator, 22, stdin);
    fgets(str_denominator, 22, stdin);

    numerator = atoll(str_numerator);
    denominator = atoll(str_denominator);
    
    lowest_numerator = numerator / fn_gcd(numerator, denominator);
    lowest_denominator = denominator / fn_gcd(numerator, denominator);

    if(lowest_denominator == 1) { printf("= %d", lowest_numerator); }
    else { printf("= %lld/%lld", lowest_numerator, lowest_denominator); }
    
    return 0;

}