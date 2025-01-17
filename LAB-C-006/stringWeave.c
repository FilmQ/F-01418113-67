#include <stdio.h>

int charcount(char *s)
{   
    int str_Count = 0;
    for(int i = 0;; i++) {
        if(s[i] == '\0' || s[i] == '\n')
            break;
        str_Count++;
    }

    return str_Count;
}

void charweave(char *s, char *result)
{
    int string_Size = charcount(s);

    // BEGIN: FORMAT RESULT.
    for(int i = 0; i < 200; i++)
        result[i] = '\0';
    // END;

    for(int i = 0, j = string_Size - 1, k = 0; i < string_Size || j >= 0; k++) {
        if(k % 2 == 1) {
            result[k] = s[j];
            j--;
        }
        else {
            result[k] = s[i];
            i++;
        }
    }

}

int main()
{  char str[100], result[200];

   printf("String: ");
   gets(str);   /* read a line of characters from the input to "str" variable */
   charweave(str, result);
   printf("Output: %s\n",result);
   return 0;
}