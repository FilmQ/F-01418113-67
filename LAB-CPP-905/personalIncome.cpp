#include <cstdio>

int main()
{
    char employeeName[51], employeeLog[51];
    double employeeMonthlyIncome = 0, employeeSalesFig = 0, employeeTotalIncome = 0, employeeTotalSaleFig = 0;

    std::scanf("%49s", employeeName);
    std::scanf("%lf", &employeeTotalIncome);

    employeeTotalIncome *= 12; // theres 12 months in a year yeah?

    for(int i = 0; i < 12; i++) {
        std::scanf("%lf", &employeeSalesFig);
        employeeTotalSaleFig += employeeSalesFig * (15.0/100);
    }

    employeeTotalIncome += employeeTotalSaleFig; // add the rest of sales fig

    std::sprintf(employeeLog, "%s %.2lf", employeeName, employeeTotalIncome);
    std::printf("%s", employeeLog);
}