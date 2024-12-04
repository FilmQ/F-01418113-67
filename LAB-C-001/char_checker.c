#include <stdio.h> 
#include <stdlib.h>

int main() {

    int cin_Char = 0;
    cin_Char = getchar();

    // printf("%d", cin_Char);

    if(cin_Char >= 48 && cin_Char <= 57) { printf("Output: digit"); }
    else if(cin_Char >= 65 && cin_Char <= 90) { printf("Output: upper case"); }
    else if(cin_Char >= 97 && cin_Char <= 122) { printf("Output: lower case"); }
    else { printf("Output: others"); }

    return 0;
}