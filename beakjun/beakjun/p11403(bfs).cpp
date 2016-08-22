#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int main() {
	int n, startingPoint,  i,j, visitPoint;

	int adm[100][100] = { 0, };
	int visited[100][100] = { 0, };

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &adm[i][j]);
		}
	}
	
	for (startingPoint = 0; startingPoint < n; startingPoint++) {
		queue<int> q;
		q.push(startingPoint);

		while (!q.empty()) {
			int curPoint = q.front();
			q.pop();

			for (visitPoint = 0; visitPoint < n; visitPoint++) {
				if (adm[curPoint][visitPoint] == 1) {
					if (visitPoint != startingPoint && visited[startingPoint][visitPoint] != 1)
						q.push(visitPoint);
					visited[startingPoint][visitPoint] = 1;
				}
			}
		}
	}
	

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}

	return 0;
}