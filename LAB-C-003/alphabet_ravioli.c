#include <stdio.h>
#include <stdlib.h>


void draw_Line(int size) 
{
    int i = 0;
    int first_LineSize = 2 * (size - 1);
    
    while(i < first_LineSize) {
        printf("-");
        i++;
    }
}

void draw_Ravioli(int offset)
{      
    int i = 0;
    int j = 0;
    int k = 0;
    int size = offset;
    char first_Ascii = 97 + offset - 1;

    for(i = 0; i < offset; i++) {

        draw_Line(size);
        
        //
        k = 0;
        for(j = first_Ascii; j >= 97; j--) {
            if(k > i)
                break;

            if(i == 0 || i == offset)                   // DESCENDING ORDER
                printf("%c", j);
            else
                printf("%c-", j);

            ++k;
        }
        // 

        j += 2;

        for(j; j <= first_Ascii; j++) {
            if(j == first_Ascii)
                printf("%c", j);
            else
                printf("%c-", j);
        }

        draw_Line(size);

        size -= 1;
        if(i != offset - 1)
            printf("\n");

    }

    size = 1;
    for(i = offset; i > 0; i--) {

        draw_Line(size);

        k = 0;
        for(j = first_Ascii; j > 97; j--) {
            if(k >= i || i == offset)
                break;
            if(i == 1)
                printf("%c", j);
            else
                printf("%c-", j);
            ++k;
        }

        j += 2;

        for(j; j <= first_Ascii; ++j) {
            if(j == first_Ascii)
                printf("%c", j);
            else
                printf("%c-", j);
        }

        draw_Line(size);

        size += 1;
        printf("\n");
    }
    
}


int main() 
{
    int offset = 0;
    char size_String[20];
    char first_Ascii = 97;

    fgets(size_String, 22, stdin);
    offset = atoi(size_String);

    if(offset < 1 || offset > 26) 
        printf("-");
    else
        draw_Ravioli(offset);
    return 0;
}