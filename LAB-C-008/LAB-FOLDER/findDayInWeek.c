#include <stdio.h>

typedef enum {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday} DayOfWeek;

DayOfWeek findDayOfWeek (int day, int month)
{
    int const_MonthInYear[] = {31, 28, 31, 30, 
                             31, 30, 31, 31, 
                             30, 31, 30, 31};
    
    int days_BeforeCurrentMonth = 0;
    for(int i = 0; i < month - 1; i++) 
        days_BeforeCurrentMonth += const_MonthInYear[i];
    
    return (Tuesday + (days_BeforeCurrentMonth + day) - 1) % 7;
}


int main()   
{
    int day, month;
	DayOfWeek dow;

	printf("Day:1 Month:1 of Year 2013 is Tuesday.\n");
	printf("Enter Day and Month: ");
	scanf("%d %d", &day, &month);
	dow = findDayOfWeek(day, month);
	printf("Day:%d Month:%d of Year 2013 is ", day, month);

	switch(dow){
		case Sunday: printf("Sunday.\n"); break;
		case Monday: printf("Monday.\n"); break;
		case Tuesday: printf("Tuesday.\n"); break;
		case Wednesday: printf("Wednesday.\n"); break;
		case Thursday: printf("Thursday.\n"); break;
		case Friday: printf("Friday.\n"); break;
		case Saturday: printf("Saturday.\n"); break;
	}
}
    