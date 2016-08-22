#include <stdio.h>

int main() {

	int arr[12];
	int columnMajor[4][3];
	int i, j;

	for (i = 0; i < 12; i++) 
		scanf("%d", &arr[i]);

	for (i = 0; i < 12; i++) {

		printf("%d ", arr[i]);
		if ((i + 1) % 4 == 0)
			printf("\n");
	}
	printf("\n");


	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			columnMajor[j][i] = arr[(i * 4) + j];
		}
	}
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", columnMajor[i][j]);
		}
		printf("\n");
	}
}