#include <stdio.h>
#define ARRAY_SIZE 98

int main()
{

	int i, j;
	int A[ARRAY_SIZE] = {0};

	for (i = 2; i < ARRAY_SIZE; i++)
		A[i] = 1;

	for(i = 4; i < ARRAY_SIZE; i++) {
		for(j = 2; j < i; j++) {
			if(i % j == 0) {
				A[i] = 0;
				break;
			}
		}
	}

	for (i = 0; i < ARRAY_SIZE; i++)
		if(A[i] != 0)
			printf("%d ", i);
			
	printf("\n");
	return 0;
}