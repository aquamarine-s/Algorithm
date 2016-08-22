#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 100000000-2

struct _point{
	int x, y;
};

typedef _point Point;

void sortPoint(Point(*p)[ARR_SIZE], int n);
void swap(Point(*p)[ARR_SIZE], int i, int j);
int closetPair(Point p[], int idx1, int idx2);
void getEndPointOfIdx(Point p[], double m, int d, int * idx1, int * idx2);
int closetBruteForce(Point p[], int idx1, int idx2);
int getDistance(Point p1, Point p2);
int compare(const void *first, const void *second);

int main() {

	int n, i;
	//Point points[ARR_SIZE];
	scanf("%d", &n);

	Point * points = (Point *)malloc(sizeof(Point) * n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &(points[i].x), &(points[i].y));
	}

	qsort(points, n, sizeof(Point), compare);
	//sortPoint(&points, n);
	/*for (int i = 0; i < n; i++) {
		printf("%d %d\n", points[i].x, points[i].y);
	}*/
	int res = closetPair(points, 0, n - 1);
	printf("%d\n", res);
	return 0;
}

int compare(const void *first, const void *second)
{
	if (((Point*)first)->x > ((Point*)second)->x)
		return 1;
	else if (((Point*)first)->x < ((Point*)second)->x)
		return -1;
	else
		return 0;
}

void sortPoint(Point (*p)[ARR_SIZE], int n) {
	int i, j;
	int min_x;
	for (i = 0; i < n - 1; i++) {
		min_x = i;
		for (j = i + 1; j < n; j++) {
			if ((*p)[min_x].x > (*p)[j].x) {
				min_x = j;
			}
		}
		swap(p, i, min_x);
	}
}

void swap(Point (*p)[ARR_SIZE], int i, int j) {
	Point temp = (*p)[i];
	(*p)[i] = (*p)[j];
	(*p)[j] = temp;
}

int closetPair(Point p[], int idx1, int idx2) {
	if (idx2 - idx1 > 3) {
		int d1 = closetPair(p, idx1, (idx1 + idx2) / 2);
		int d2 = closetPair(p, (idx1 + idx2) / 2 + 1, idx2);
		int min_d = d1 > d2 ? d2 : d1;
		
		//범위를 정하고, 범위안에 속하는 점 중 양끝에 있는 배열 인덱스 두개를 알아내야...
		double m = (p[idx1].x + p[idx2].x) / 2.0;
		int endIdx1 = idx1, endIdx2 = idx2;
		getEndPointOfIdx(p, m, min_d, &endIdx1, &endIdx2);
		
		if (endIdx1 != idx1 && endIdx2 != idx2) {
			int cross_d = closetBruteForce(p, endIdx1, endIdx2);
			min_d = min_d > cross_d ? cross_d : min_d;
		}
		
		return min_d;
	}
	else {
		return closetBruteForce(p, idx1, idx2);
	}
}

void getEndPointOfIdx(Point p[], double m, int d, int * idx1, int * idx2) {
	int i;
	for (i = *idx1; p[i].x < m; i++) {
		if (p[i].x > (m - d)) {
			*idx1 = i;
			break;
		}
	}

	for (i = *idx2; p[i].x > m; i--) {
		if (p[i].x < m + d) {
			*idx2 = i;
			break;
		}
	}
}

int closetBruteForce(Point p[], int idx1, int idx2) {
	int min_d = getDistance(p[idx1], p[idx1+1]);
	int temp_d;
	int i, j;
	for (i = idx1; i <= idx2 - 1; i++) {
		for (j = i + 1; j <= idx2; j++) {
			temp_d = getDistance(p[i], p[j]);
			if (temp_d < min_d) {
				min_d = temp_d;
			}
		}
	}
	return min_d;
}

int getDistance(Point p1, Point p2) {
	return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
}