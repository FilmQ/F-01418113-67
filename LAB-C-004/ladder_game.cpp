#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int n_Stairs = 0;
    int n_RoundCount = 1;
    int n_Steps = 0;
    int n_HeadPosition = 0;
    int n_TailsPosition = 0;
    char ladder_Base[] = "|---|";
    char ladder_Head[] = "|-O-|";
    char ladder_Tails[] = "|-^-|";

    printf("Input number of stairs: ");
    scanf("%d", &n_Stairs);

    n_HeadPosition = n_Stairs;
    n_TailsPosition = n_Stairs - 1;
    
    do {
        printf("---- round %d ----\n", n_RoundCount);

        for(int i = n_Stairs; i > 0; i--) {

            if(i == n_Stairs - (n_HeadPosition - 1))         { printf("%s", ladder_Tails); } 
            else if(i == n_Stairs - (n_HeadPosition - 2))    { printf("%s", ladder_Head); } 
            else                                             { printf("%s", ladder_Base); }
            
            printf("\n");

        }

        printf("Input step command: ");
        scanf("%d", &n_Steps);

        ++n_RoundCount;

        if(n_Steps > 0) {
            if(n_HeadPosition - n_Steps > 1)
                n_HeadPosition -= n_Steps;
            else
                n_HeadPosition = 2;
        }
        else if(n_Steps < 0) {
            if(n_HeadPosition - n_Steps < n_Stairs)
                n_HeadPosition += -(n_Steps);
            else
                n_HeadPosition = n_Stairs;
        }
        else {
            continue;
        }

        n_TailsPosition = n_HeadPosition - 1;

    } while(n_Steps != 0);

    return 0;
    
}