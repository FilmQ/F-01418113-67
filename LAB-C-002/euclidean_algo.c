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

long long fn_lcm(long long m, long long n) {
    return (m * n) / fn_gcd(m, n);
}

int main() 
{

    char str_m[20], str_n[20];
    long long m, n;

    fgets(str_m, 22, stdin);
    fgets(str_n, 22, stdin);

    m = atoll(str_m);
    n = atoll(str_n);

    printf("GCD: %ld\n", fn_gcd(m, n));
    printf("LCM: %ld\n", fn_lcm(m, n));

    return 0;

}