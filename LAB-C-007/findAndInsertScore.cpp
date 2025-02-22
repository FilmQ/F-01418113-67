#include <stdio.h>
#include <string.h>

typedef struct {
    char id[12];
    int score; 
} studentRecord;

void init(studentRecord list[], int size) 
{
	for(int i = 0; i < 3; i++) {
		sprintf(list[i].id, "5510000%d", i + 1);
		list[i].score = 0;
		// printf("%s %d\n", list[i].id, list[i].score);
	}

}

void enterScore(studentRecord list[], int size)
{
	char sub_string[64];
	int cin_score = 0;

	scanf("%19s %d", sub_string, &cin_score);

	if(strstr(list[0].id, sub_string) != NULL)
		list[0].score = cin_score;
	else if(strstr(list[1].id, sub_string) != NULL)
		list[1].score = cin_score;
	else if(strstr(list[2].id, sub_string) != NULL)
		list[2].score = cin_score;
	else;
}

void printRecords(studentRecord list[], int size) 
{
	int i;

	printf("   ID        Score\n");
	for (i = 0; i < size; i++) {
		printf("%s       %d\n", list[i].id, list[i].score);
	}
}


int main() 
{
	int enter;
	studentRecord list[3];

	init(list, 3);
        enterScore(list, 3);
	printRecords(list, 3);
	return 0;
}