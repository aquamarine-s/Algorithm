#include <stdio.h>

int init(int(*img)[64]);
bool check(int(*img)[64], int size, int x, int y);
void compress(int(*img)[64], int size, int x, int y);

int main() {

	int image[64][64] = { 0, };
	int nSize;
	
	nSize = init(image);
	compress(image, nSize, 0, 0);

	return 0;
}

void compress(int(*img)[64], int size, int x, int y) {

	if (check(img, size, x, y))
		printf("%d", img[y][x]);
	else {
		printf("(");
		compress(img, size / 2 ,x, y);
		compress(img, size / 2, x + size/2, y);
		compress(img, size / 2, x, y + size/2);
		compress(img, size / 2, x + size/2, y + size/2);
		printf(")");
	}

}

bool check(int(*img)[64], int size, int x, int y) {
	int temp = img[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (temp != img[i][j])
				return false;
		}
	}
	return true;
}

int init(int (*img)[64]) {
	int n;
	int i, j;
	
	scanf("%d", &n);


	for (i = 0; i < n; i++) {
		char temp[65];
		scanf("%s", temp);
		for (j = 0; temp[j] != '\0'; j++) {
			img[i][j] = temp[j] - '0';
		}
	}

	return n;
}