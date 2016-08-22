#include <stdio.h>

int fibonacci(int n, int i);
int res[41][2];

int main() {

	int t, i, input;
	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d", &input);
		fibonacci(input, i);
	}


	
	for (i = 0; i < t; i++) 
		printf("%d %d\n", res[i][0], res[i][1]);

	return 0;

}

int fibonacci(int n, int i) {
	if (n == 0) {
		res[i][0]++;
		//printf("0");
		return 0;
	}
	else if (n == 1) {
		res[i][1]++;
		//printf("1");
		return 1;
	}
	else {
		return fibonacci(n-1,i) + fibonacci(n-2,i);
	}
}