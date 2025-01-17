#include <stdio.h>
#include <stdlib.h>

int remove_vowel(char *str)
{
    int count_String = 0;
    for(int i = 0;; i++) {
        if(str[i] == '\n' || str[i] == '\0') {
            if(str[i] == '\n') 
                str[i] = '\0';
            break;
        }
        ++count_String;
    }

    //printf("%d\n", count_String);

    int vowels_Counter = 0;
    for(int i = 0; i < count_String; ) {
        if(str[i] == 'A' || str[i] == 'a' ||
           str[i] == 'E' || str[i] == 'e' ||
           str[i] == 'I' || str[i] == 'i' ||
           str[i] == 'O' || str[i] == 'o' ||
           str[i] == 'U' || str[i] == 'u' ) 
           {
                str[i] = '\0';

                // BEGIN SHIFT LEFT.
                for(int j = i; j < count_String ; j++) {
                        str[j] = str[j + 1];
                }
                
                vowels_Counter++;
                i = 0;
           }
           else
                i++;
           
    }

    //str[count_String] = '\0';
    return *str;

}

int main()
{
    char str[80];
    printf(" Input: ");
    fgets(str, 80, stdin);

    remove_vowel(str);

    printf("Output: %s\n",str);
    return 0;
}