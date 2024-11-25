#include<stdio.h>





int main() {
    int computer_time = 785;  // minutes

    int day, hour, minutes;

    day = (computer_time / 60) / 24;
    hour = (computer_time / 60) % 24;
    minutes = (computer_time - (60 * hour)) % 60;

    printf("It is %d days %d hours and %d minutes.", day, hour, minutes);
    
    return 0;
}