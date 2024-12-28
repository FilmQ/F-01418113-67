#include <stdio.h>
#include <stdlib.h>

void shift_left(char str[], int n);

int main()
{  char str[80], *c;
   int n;

   printf("String: ");
   fgets(str, sizeof(str), stdin);
   for (c=str; *c && *c != '\n'; c++)
       ;
   *c = 0;
   printf("     n: ");
   scanf("%d", &n);
   shift_left(str, n);
   printf("Output: >>%s<<\n",str);
   return 0;
}

void shift_left(char str[], int n) 
{

    // BEGIN: COUNT CHAR ARRAY (EXCLUDING \n)

    int string_length = 0;

    for(int i = 0; ; i++) {
        if(str[i] == '\0' || str[i] == '\n') {
            break;
        }
        ++string_length;
    }

    // END: COUNT CHAR ARRAY.

    // BEGIN: SHIFTING.
    char temp = '0';

    
    if(string_length != 0)
        for(int i = 0; i < n % string_length; i++) {
            
            temp = str[0];
            str[0] = ' ';

            for(int j = 0; j < string_length; j++) {
                if(j == string_length - 1)
                    str[j] = temp;
                else
                    str[j] = str[j + 1];
            }

        }
    // END: SHIFTING.

}