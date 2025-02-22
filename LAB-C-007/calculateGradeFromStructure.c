#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#define SIZE 5

struct StudentInfo {
    char ID[20];
    double midterm_score;
    double final_score;
};

void calculateGrade(struct StudentInfo Students[])
{
    for(int i = 0; i < SIZE; i++) {
        double combined_score = Students[i].midterm_score + Students[i].final_score;
        
        if(combined_score >= 80)
            printf("Student ID %s receives grade A.\n", Students[i].ID);
        if(combined_score >= 70 && combined_score < 80)
            printf("Student ID %s receives grade B.\n", Students[i].ID);
        if(combined_score >= 60 && combined_score < 70)
            printf("Student ID %s receives grade C.\n", Students[i].ID);
        if(combined_score >= 50 && combined_score < 60)
            printf("Student ID %s receives grade D.\n", Students[i].ID);
        if(combined_score < 50)
            printf("Student ID %s receives grade F.\n", Students[i].ID);
    }
}

int main()
{
    struct StudentInfo Students[5];

    for(int i = 0; i < SIZE; i++) {
        printf("Enter Student ID: ");
        scanf("%20s", Students[i].ID);
        
        int c;
        while((c = getchar()) != '\n' && c != EOF); // flushes stream in case of bad input by moving the stream's internal pointer

        printf("Enter Student Midterm: ");
        scanf("%lf", &Students[i].midterm_score);

        printf("Enter Student Final: ");
        scanf("%lf", &Students[i].final_score);
        
    }

    calculateGrade(Students);

}