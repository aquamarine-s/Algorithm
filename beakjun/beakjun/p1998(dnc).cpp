#include <stdio.h>

struct _node {
	int * linker;
	
};

typedef _node Node;

bool is2k(int num);
int getBound(int n, int m);
int getCloser2k(int num);
void compress(int(*img)[128], int size, int x, int y, int * cnt);
bool check(int(*img)[128], int size, int x, int y);

int main() {

	int n, m, bound, cnt = 0;
	int i, j;
	int image[128][128] = { 0, };

	scanf("%d %d", &n, &m);

	
	for (i = 0; i < n; i++) {
		char temp[129];
		scanf("%s", temp);
		for (j = 0; temp[j] != '\0'; j++) {
			image[i][j] = temp[j] - '0';
		}
	}
	
	bound = getBound(n,m);
	//printf("%d\n", bound);

	compress(image, bound, 0, 0, &cnt);
	
	printf("%d\n", cnt);

	/*for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			printf("%d ", image[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}

void compress(int(*img)[128], int size, int x, int y, int * cnt) {
	if (check(img, size, x, y)) {
		(*cnt)++;
		return;
	}

	else {
		(*cnt)++;
		compress(img, size / 2, x, y, cnt);
		compress(img, size / 2, x + size/2, y, cnt);
		compress(img, size / 2, x, y + size/2, cnt);
		compress(img, size / 2, x + size/2 , y + size/2, cnt);

	}

}

bool check(int(*img)[128], int size, int x, int y) {
	int i, j;
	int temp = img[y][x];
	
	if (size == 1)
		return true;

	for (i = y; i < y + size; i++) {
		for (j = x; j < x + size; j++) {
			if (temp != img[i][j])
				return false;
		}
	}
	return true;
}
bool is2k(int num) {
	int i, f = 2;
	for (i = 1; i <= 7; i++) {
		if (f == num) return true;
		else f *= 2;
	}
	return false;
}

int getBound(int n, int m) {

	if (is2k(n) || is2k(m)) return n > m ? n : m;
	else return n > m ? getCloser2k(n) : getCloser2k(m);
}

int getCloser2k(int num) {
	int i, f = 2;
	for (i = 0; i <= 7; i++) {
		if (num < f) return f;
		else f *= 2;
	}
}
