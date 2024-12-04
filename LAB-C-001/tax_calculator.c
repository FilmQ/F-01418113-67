#include <stdio.h>
#include <stdlib.h>

int main() {

        char str_yearly_income[50];
        double yearly_income = 0, income_tax = 0;

        printf("");
        fgets(str_yearly_income, 52, stdin);

        yearly_income = atof(str_yearly_income);

        if(yearly_income < 0) { 
            printf("Error: Salary must be greater or equal to 0"); 
        }
        else {
            if(yearly_income <= 300000) { 
                income_tax = (5.0 * yearly_income) / 100.0 ;
            }
            else { 
                income_tax = 15000; 
                income_tax += (10.0 * (yearly_income - 300000)) / 100.0;
            }

            printf("%.2lf", income_tax);

        }

        return 0;

    }