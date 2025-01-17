#include <stdio.h>
#include <stdlib.h>

void removeTarget(int *array, int size, int target);

int main()
{
    int num, count, target, i;
	num = 0;

	scanf("%d", &num);
	scanf("%d", &count);

	int numbers[num];
	int *numbersPtr = &numbers[0];

	// initialize array numbers from 1 to num by numbersPtr
	for(int i = 1; i <= num; i++, numbersPtr++) {
	   *numbersPtr = i;
	}

	// loop through count
	for (int i = 0; i < count; i++) {
		scanf("%d", &target);
		removeTarget(&numbers[0], num, target);
	}

	numbersPtr = &numbers[0];

	// print elements in numbers using numberPtr
	for (int i = 0; i < num; i++, numbersPtr++) {
	       printf("%d ", *numbersPtr);
	}
	puts("");
	return 0;
}

void removeTarget(int *array, int size, int target)
{	
	int count_Target = 0;

	for(int i = 0; i < size; i++) {
		if(array[i] == target) {
			array[i] = 0;
			++count_Target;
		}
	}

	// Improv. bubble sort.
	int temp;
	for(int i = 0; i < size; i++) {
		if(i + 1 != size && array[i] == 0) {
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
		}

	}
	
}

