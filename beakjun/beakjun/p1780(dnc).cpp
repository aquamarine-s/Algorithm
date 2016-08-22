#include <stdio.h>
#define ARRAY_MAX_SIZE 2187

int init(int (*arr)[ARRAY_MAX_SIZE]);
void printPaper(int(*arr)[ARRAY_MAX_SIZE], int n);
void divide(int(*arr)[ARRAY_MAX_SIZE], int nSize, int sx, int sy);
bool check(int(*arr)[ARRAY_MAX_SIZE], int n, int x, int y);

int cnt1;
int cnt0;
int cnt_1;

int main() {
	
	int paper[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE] = { 0, };
	int nSize = init(paper);
	printPaper(paper, nSize);
	divide(paper, nSize, 0, 0);
	printf("%d\n%d\n%d\n", cnt_1, cnt0, cnt1);
	

	return 0;
}

void divide(int (*arr)[ARRAY_MAX_SIZE], int nSize, int sx, int sy) {

	if (nSize == 1) {
		if (arr[sy][sx] == -1)
			cnt_1++;
		else if (arr[sy][sx] == 0)
			cnt0++;
		else
			cnt1++;
	}

	else if (check(arr, nSize, sx, sy)) {

		if (arr[sy][sx] == -1)
			cnt_1++;
		else if (arr[sy][sx] == 0)
			cnt0++;
		else
			cnt1++;

	}

	else {
		divide(arr, nSize / 3, sx, sy);
		divide(arr, nSize / 3, sx + nSize / 3, sy);
		divide(arr, nSize / 3, sx + nSize / 3 * 2, sy);
		divide(arr, nSize / 3, sx, sy + nSize / 3);
		divide(arr, nSize / 3, sx + nSize / 3, sy + nSize / 3);
		divide(arr, nSize / 3, sx + nSize / 3 * 2, sy + nSize / 3);
		divide(arr, nSize / 3, sx, sy + nSize / 3 * 2);
		divide(arr, nSize / 3, sx + nSize / 3, sy + nSize / 3 * 2);
		divide(arr, nSize / 3, sx + nSize / 3 * 2,  sy + nSize / 3 * 2);
	}
}

bool check(int (*arr)[ARRAY_MAX_SIZE], int n, int x, int y) {
	// 모두 같은 수이면 true, 하나라도 다르면 false
	int i,j;

	int temp = arr[y][x];
	
	for (i = y; i < y + n; i++) {
		for (j = x; j < x + n; j++) {
			if (arr[i][j] != temp)
				return false;
		}
	}

	return true;
}

int init(int (*arr)[ARRAY_MAX_SIZE]) {

	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	return n;
}

void printPaper(int(*arr)[ARRAY_MAX_SIZE], int n ) {

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}