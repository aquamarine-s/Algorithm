#include <stdio.h>

void main() {

	int arr[6];
	int perfectSet[6] = { 1, 1, 2, 2, 2, 8 };
	int i;

	for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
		scanf("%d", &arr[i]);
	}


	for (i = 0; i < 6; i++) {
		printf("%d ", perfectSet[i] - arr[i]);
	}
	printf("\n");


}