#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* stoupper(const char* s) 
{   
    int s_Size = 0;
    for(int i = 0;; i++) {
        if(s[i] == '\0' || s[i] == '\n') 
            break;
        s_Size++;
    }

    char *string_Upper = (char*) malloc(sizeof(char) * s_Size);

    for(int i = 0; i < s_Size; i++)
        string_Upper[i] = '\0';

    for(int i = 0; i < s_Size; i++) 
        string_Upper[i] = toupper(s[i]);

    string_Upper[s_Size] = '\0';

    return string_Upper;
}

int main(){
	char s[100];
	char* result;

	scanf("%s",s);
	result = stoupper(s);
        if (result == s) printf("ERROR.\n");
	printf("%s\n",result);
}