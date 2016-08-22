#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct Point
{
	int x;
	int y;
};

int visited[100][100];
void initRoom(int *** room, int n, int m);
void printRoom(int ** room, int n, int m);
void destroyRoom(int ** room, int n);
void escape(int ** room, int n, int m);
bool IsInBound(int x, int y, int n, int m);

int main() {
	
	int ** room = NULL;
	int n, m;
		
	scanf("%d %d", &n, &m);

	initRoom(&room, n, m);
	
	escape(room, n, m);
	printf("%d\n", visited[n - 1][m - 1]);


	//printRoom(room, n, m);
	destroyRoom(room, n);
	
	return 0;
}


void initRoom(int *** room, const int n, const int m) {

	*room = (int **)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		(*room)[i] = (int*)malloc(sizeof(int) * m);
	}

	char temp[100];
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);

		for (int j = 0; j < m; j++) {
			(*room)[i][j] = temp[j] - '0';
		}
	}
}

void printRoom(const int ** room, const int n, const int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", room[i][j]);
		}
		printf("\n");
	}
}

void destroyRoom(int ** room, int n) {

	for (int i = 0; i < n; i++) {
		free(room[i]);
	}
	free(room);
}

void escape(int ** room, int n, int m) {
	queue<Point> queue;

	Point cur = { 0, 0 };
	Point goal = { m - 1, n - 1 };

	Point around[4] = { {0,1}, {1,0}, {0,-1}, {-1, 0} };

	queue.push(cur);
	visited[cur.y][cur.x] = 1;

	while (!queue.empty()) {
		cur = queue.front(); 
		queue.pop();
		
		if (cur.x == goal.x && cur.y == goal.y) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int x = cur.x + around[i].x;
			int y = cur.y + around[i].y;

			if (IsInBound(x, y, n, m) && room[y][x] == 1 && visited[y][x] == 0  ) { //길이며, 아직 방문 안했으며, 경계 안이면
				queue.push({ x,y });
				visited[y][x] = visited[cur.y][cur.x] + 1;
			}
		}
	}
}

bool IsInBound(int x, int y, int n, int m) {
	if (x < 0 || x >= m || y < 0 || y >= n)
		return false;
	else
		return true;
	
}
