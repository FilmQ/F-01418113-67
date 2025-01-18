#include <stdio.h>
#include <stdlib.h>

void removeKilled(int *array, int size, int killedPrisoner);

int main()
{
	int numPrisoners, m, i;

	scanf("%d", &numPrisoners);
	scanf("%d", &m);

	int prisoners[numPrisoners];
	int killed[numPrisoners];

	// generate array 1 to numPrisoners
	for (i = 0; i < numPrisoners; i++) {
		prisoners[i] = i + 1;
	}

	int *killerPtr = &prisoners[0];

	// printf("@@ &prisoners[0] %d\n", (int) &prisoners[0]);
	// printf("@@ &prisoners[%d] %d\n", numPrisoners - 1, (int) &prisoners[numPrisoners - 1]);

	// Select prisoner to be killed
	for (int i = 0; i < numPrisoners; i++) {
		int n_Steps = m;
		
		if(i >= 1)
			n_Steps = ((killed[0] * 2) - killed[0]) % numPrisoners;  // imagine having to do this because you cant use static

		if(i == 0)
			m -= 1;

		int flag_EncounteredRemovedPrisoner = 0;
		for(int j = 0;;) {									// we're doing this iteratively for maximum "control"
			if(prisoners[m] == 0) {
				flag_EncounteredRemovedPrisoner = 1;
				m++;
				m %= numPrisoners;
				continue;
			}

			if(i == 0 || j == n_Steps - 1 || (flag_EncounteredRemovedPrisoner && j >= n_Steps)) {
				killerPtr = &prisoners[m];
				break;
			}

			m++;
			j++;
			m %= numPrisoners;
		}

		// append number of prisoner who is killed to array `killed`
		killed[i] = *killerPtr;
		// remove number killed prisoner from array `prisoners`
		removeKilled(&prisoners[0], numPrisoners, *killerPtr);

	}

	for (i = 0; i < numPrisoners; i++) {
		printf("%d ", killed[i]);
	}
	return 0;
}

void removeKilled(int *array, int size, int killedPrisoner)
{
    array[killedPrisoner - 1] = 0;
}
