#include <stdio.h>
#include <stdlib.h>

void print_TwelveToMilitaryTime(char* fString_TwelveHourTimeFormat)
{
    int time_Hours, time_Mins;
    char time_Range;

    sscanf(fString_TwelveHourTimeFormat, "%d:%d %c", &time_Hours, &time_Mins, &time_Range); // Read for numerical format from fgets instead of stdin.

    if(((time_Range == 'P' || time_Range == 'p') && time_Hours != 12) || ((time_Range == 'A' || time_Range == 'a') && time_Hours >= 12))
        time_Hours += 12;
    
    time_Hours %= 24;

    printf("Equivalent 24-hour time: %02d:%02d", time_Hours, time_Mins);
}


int main()
{   
    char str_Time[50];

    printf("Enter a 12-hour time [eg. 12:34 am]: ");
    fgets(str_Time, 50, stdin);

    print_TwelveToMilitaryTime(str_Time);
}