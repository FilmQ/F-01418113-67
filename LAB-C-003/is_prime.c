#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int x) 
{   
    if(x < 2)
        return 0;

    for(int i = 2; i <= (int)sqrt(x); i++) {
        if(x % i == 0) 
            return 0;
    }
    
    return 1;

}

/*
int main() 
{
    char str_digit[20];
    long digit = 0;
    int i = 0;

    fgets(str_digit, 22, stdin);
    digit = atol(str_digit);

    while(i <= digit) {
        if(is_prime(i) == 1)
            printf("%d is a prime number.\n", i);
        i++;
    }

    return 0;

}
*/

int main() {
  char input[5];
  fgets(input, 5, stdin);

  int i, n;

  n = atoi(input);

  for (i = 0; i <= n; ++i) {
      if (is_prime(i)) {
          printf("%d is a prime number.\n", i);
      }
  }

  return 0;
}