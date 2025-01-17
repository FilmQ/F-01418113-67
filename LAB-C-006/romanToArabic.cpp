#include <stdio.h>

void roman2arabic(char input[],char output[])
{   
    int input_Size = 0;
    for(int i = 0;; i++) {
        if(input[i] == '\0' || input[i] == '\n')
            break;
        input_Size++;
    }

    int j = 0;
    for(int i = 0; i < input_Size;) {
        switch(input[i])
        {
        case 'I':
            if(i + 2 < input_Size && input[i + 1] == 'I' && input[i + 2] == 'I') {
                output[j] = '3';
                i += 2; 
            }
            else if(i + 1 < input_Size && input[i + 1] == 'I') {
                output[j] = '2';
                i += 1;
            }
            else if(i + 1 < input_Size && input[i + 1] == 'V') {
                output[j] = '4';
                i += 1;
            }
            else if(i + 1 < input_Size && input[i + 1] == 'X') {
                output[j] = '9';
                i += 1;
            }
            else
                output[j] = '1';
                i += 1;
            break;

        case 'V':

            if(i + 3 < input_Size && input[i + 1] == 'I' && input[i + 2] == 'I' && input[i + 3] == 'I') {
                output[j] = '8';
                i += 4; 
            }
            else if(i + 2 < input_Size && input[i + 1] == 'I' && input[i + 2] == 'I') {
                output[j] = '7';
                i += 3;
            }
            else if(i + 1 < input_Size && input[i + 1] == 'I') {
                output[j] = '6';
                i += 2;
            }
            else {
                output[j] = '5';
                i += 1;
            }

            break;
        default:
            output[j] = input[i];
            i++;
            break;
        }
        j++;
    }

    output[j] = '\0';

}

int main()
{  char input[80], output[80];

   printf(" Input: ");
   gets(input);  /* read a line of characters from the input to "input" variable */

   roman2arabic(input,output);
   printf("Output: %s\n",output);

   return 0;
}
