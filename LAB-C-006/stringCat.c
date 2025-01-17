#include <stdio.h>

void stringcat(char src[], char dest[])
{   
    // BEGIN. COUNT SIZE.
    int src_Length = 0, dest_Length = 0;

    for(int i = 0;; i++) {
        if(src[i] == '\0' || src[i] == '\n')
            break;
        src_Length++;
    }

    for(int i = 0;; i++) {
        if(dest[i] == '\0' || dest[i] == '\n')
            break;
        dest_Length++;
    }
    // END: COUNT SIZE.

    // BEGIN. CONCAT.
    for(int i = dest_Length, j = 0; i < src_Length + dest_Length; i++, j++) {
        dest[i] = src[j];
    }
    // END. CONCAT.
}

int main()
{
  char in1[100], in2[100];

  printf("Input 1: ");
  gets(in1);  /* read a line of characters from the input to "in1" variable */

  printf("Input 2: ");
  gets(in2);  /* read another line of characters from the input to "in2" variable */

  stringcat(in1, in2);

  printf(" Output: ");
  printf("%s\n", in2);

  return 0;
}