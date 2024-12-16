#include <stdio.h>
#include <stdlib.h>

int main()
{   
    double init_CollectionGoal = 0;
    char init_CollectionGoalString[50];

    double amount_PaymentForEachTerm = 0;
    char amount_PaymentForEachTermString[30];

    double accumalated_Payment = 0;
    double amount_Left = 0;
    int day_Count = 1;

    printf("Enter your goal amount: ");
    fgets(init_CollectionGoalString, 52, stdin);

    init_CollectionGoal = atof(init_CollectionGoalString);

    while(accumalated_Payment < init_CollectionGoal) {

        printf("Enter money collected today: ");
        fgets(amount_PaymentForEachTermString, 52, stdin);

        amount_PaymentForEachTerm = atof(amount_PaymentForEachTermString);

        accumalated_Payment += amount_PaymentForEachTerm;
        amount_Left = init_CollectionGoal - accumalated_Payment;

        if(accumalated_Payment >= init_CollectionGoal)
            break;

        printf("Total money collected up to day %d is %.2f. You need %.2f more.\n", day_Count, accumalated_Payment, amount_Left);

        day_Count++;

    }

    if(day_Count == 1)
        printf("Congratulations! You take 1 day to reach your goal.");
    else
        printf("Congratulations! You take %d days to reach your goal.", day_Count);

    return 0;

}