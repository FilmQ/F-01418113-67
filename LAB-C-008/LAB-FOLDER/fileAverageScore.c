#include <stdio.h>

double findAverage(char *filename)
{
    FILE * fileScorePtr;
    double scoreUnit = 0, sumScore = 0;
    int scoreEntry = 0;

    fileScorePtr = fopen(filename, "r");

    if(fileScorePtr == NULL)
        return -1;

    while(fscanf(fileScorePtr, "%lf", &scoreUnit) != EOF) {
        scoreEntry++;
        sumScore += scoreUnit;
    }

    fclose(fileScorePtr);

    if(scoreEntry == 0)
        return 1;

    return sumScore / scoreEntry;

}

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    average = findAverage(filename);
    printf("Average score is %.4lf\n", average);
}