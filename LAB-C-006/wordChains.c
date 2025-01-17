#include <stdio.h>
#include <stdlib.h>

void string_InitToNULL(char *string, int size)
{
    for(int i = 0; i < size; i++)
        string[i] = '\0';
}


void string_Copy(char* original, char* strtocopyto, int size) 
{
    for(int i = 0; i < size; i++) {
        strtocopyto[i] = original[i];
    }
}

void word_Chain()
{
    int string_Length = 0;
    int string_Amount = 0;

    // 
    scanf("%d", &string_Length);
    scanf("%d", &string_Amount);

    char string_InChain[string_Length];
    char string_NextInChain[string_Length];

    string_InitToNULL(string_InChain, string_Length);
    string_InitToNULL(string_NextInChain, string_Length);

    int flag_ChainBroken = 0;
    for(int i = 0; i < string_Amount; i++) {
        if(i == 0)
            scanf("%s", string_InChain);
        else 
            scanf("%s", string_NextInChain);

        if(flag_ChainBroken)
            continue;

        if(i > 0 && flag_ChainBroken == 0) {
            int placement_Fault = 0;

            for(int j = 0; j < string_Length; j++) {
                if(placement_Fault > 2) 
                    break;

                if(string_InChain[j] != string_NextInChain[j])
                    placement_Fault++;
            }
            if(placement_Fault <= 2) 
                string_Copy(string_NextInChain, string_InChain, string_Length);
            else 
                flag_ChainBroken = 1;
        }
        
    }

    printf("%s", string_InChain);

    /*
    int flag_ChainBroken = 0;                                       // DEPRECATED
    int flag_ChainBrokenAtSecondLine = 0; 
    for(int i = 0; i < string_Amount - 1; i++) {
        scanf("%s", string_ConsecutiveChain);

        if(flag_ChainBroken == 0) {
            int faulty_Match = 0;
            for(int j = 0; j < string_Length; j++) {
                if(faulty_Match > 2) {
                    if(i == 0)
                        flag_ChainBrokenAtSecondLine = 1;
                    flag_ChainBroken = 1;
                    break;
                }
            
                if(string_FirstChain[j] != string_ConsecutiveChain[j]) 
                    faulty_Match++;   
            }
            if(flag_ChainBroken == 0)
                string_Copy(string_ConsecutiveChain, string_FirstChain, string_Length);
            else
                string_Copy(string_FirstChain, string_PreviousWordInConsecutiveChain, string_Length);
        }
        else
            continue;
        
    }

    string_PreviousWordInConsecutiveChain[string_Length] = '\0';
    printf("%s", string_PreviousWordInConsecutiveChain);
    */

}

int main()
{
    word_Chain();
}