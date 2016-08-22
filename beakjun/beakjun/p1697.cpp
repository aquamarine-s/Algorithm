#include <stdio.h>
#include <queue>
using namespace std;

bool IsInBound(int n);
int solve(int n, int k);

struct Position{
	int value;
	int depth;
};

int main() {

	int n, k;
	
	scanf("%d %d", &n, &k);

	int res = solve(n, k);


	printf("%d\n", res);

	return 0;
}


int solve(int n, int k) {
	queue<Position> q;
	int visited[100001] = { 0, };
	Position start = { n,0 };
	
	q.push(start);
	visited[start.value] = 1;

	while (!q.empty()) {

		Position cur = q.front();
		int curVal = cur.value;
		int curDep = cur.depth;
		q.pop();

		if (curVal == k)
			return curDep;

		if (IsInBound(curVal - 1) && visited[curVal - 1] == 0) {
			q.push({ curVal - 1, curDep + 1 });
			visited[curVal - 1] = 1;
		}
		if (IsInBound(curVal + 1) && visited[curVal + 1] == 0) {
			q.push({ curVal + 1, curDep + 1 });
			visited[curVal + 1] = 1;
		}
		if (IsInBound(curVal * 2) && visited[2 * curVal] == 0) {
			q.push({ 2 * curVal, curDep + 1 });
			visited[2 * curVal] = 1;
		}
	}
}

bool IsInBound(int n) {
	if (n < 0 || n > 100000)
		return false;
	else
		return true;
}
