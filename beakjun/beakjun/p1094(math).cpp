#include <stdio.h>
#include <stdlib.h>
#include <stack>

int main() {

	int x;
	//int cnt = 1; // ����� ����
	
	int sticks[65] = { 64 ,};

	scanf("%d", &x);

	while (1) {
		int i = 0;
		int stickLength = 0; // ����� ����

		while (sticks[i] != 0) {
			stickLength += sticks[i];
			i++;
		}
		// ����� ������ i - 1 ��

		if (stickLength == x) {
			printf("%d\n", i);
			return 0;
		}

		sticks[i] = sticks[i-1] = sticks[i - 1] / 2;
		//int sum = 0;
		/*for (int j = 0; j < i; j++) {
			sum += sticks[j];
		}*/

		if (stickLength - sticks[i] >= x)
			sticks[i] = 0;
	}

	return 0;
}

/*int getStickLength(int * arr, int i) {
	int res = 0;
	for (int j = 0; i < i; j++) {
		res += arr[j];
	}
	return res;
}*/