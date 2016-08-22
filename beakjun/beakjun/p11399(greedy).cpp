#include <stdio.h>
#include <stdlib.h>

int compare(const void * first, const void * second);

int main() {

	int input[1001];
	int waitingLine[100];
	int n, i, j, sum = 0;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++) 
		scanf("%d", &input[i]);
	
	
	qsort(input, n, sizeof(int), compare);

	/*for (i = 0; i < n; i++)
		printf("%d ", input[i]);
	printf("\n");*/
	
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			sum += input[j];
		}
	}

	printf("%d\n", sum);


	return 0;
}


int compare(const void * first, const void * second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}