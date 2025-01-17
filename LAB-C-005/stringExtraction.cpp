#include <stdio.h>
#include <stdlib.h>


void str_extract(char** source, char** vowel);

int main() {
    char* str = (char*) malloc(201);
    scanf("%[^\n]s", str);
    char* vowel = NULL;

    str_extract(&str, &vowel);

    printf("Consonants: \"%s\"\n", str);
    printf("    Vowels: \"%s\"\n", vowel);

    free(str);
    free(vowel);
    return 0;
}

void str_extract(char** source, char** vowel) 
{
    int str_size = 0;
    for(int i = 0; i < 201; i++) {
        if(source[0][i] == '\0' || source[0][i] == '\n') {
            break;
        }
        str_size++;
    }

    int vowel_Count = 0;
    int last_VowelOccured = 0;
    for(int i = 0; i < str_size; i++) 
        if(source[0][i] == 'a' || source[0][i] == 'A' || 
           source[0][i] == 'e' || source[0][i] == 'E' || 
           source[0][i] == 'i' || source[0][i] == 'I' || 
           source[0][i] == 'o' || source[0][i] == 'O' || 
           source[0][i] == 'u' || source[0][i] == 'U') {
            last_VowelOccured = i;
            vowel_Count++;
           }

    *vowel = (char*) malloc(sizeof(unsigned char) * vowel_Count);

    int j = 0;
    for(int i = 0; i < str_size;) {
        vowel[0][vowel_Count] = '\0';

        if(source[0][i] == 'a' || source[0][i] == 'A' || 
           source[0][i] == 'e' || source[0][i] == 'E' || 
           source[0][i] == 'i' || source[0][i] == 'I' || 
           source[0][i] == 'o' || source[0][i] == 'O' || 
           source[0][i] == 'u' || source[0][i] == 'U') 
        {
            vowel[0][j] = source[0][i];
            source[0][i] = '\0';
            j++;

            for(int k = i; k < str_size - 1; k++) {
                char temp = source[0][k];
                source[0][k] = source[0][k + 1];
                source[0][k + 1] = temp;
            }
            i = 0;
        }
        else
            i++;
        
    }
       
}
