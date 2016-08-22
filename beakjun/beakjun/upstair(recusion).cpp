/*
프로그램 명: upstair(recusion)
제한시간: 1 초
최대 2 칸 까지 오를 수 있을 때 오르는 방법의 가짓수를 출력 하는 문제이다.

그림은 n 이 4 인 경우의 예 이다.

1 - 2 - 3 - 4
1 - 2 - 4
1 - 3 - 4
2 - 3 - 4
2 - 4

입력
n 은 30 이하의 양의 정수이다.

출력
오를 수 있는 가짓 수를 출력한다.
*/
#include <stdio.h>
void upStair(int cur, int goal, int * cnt);
int main() {
	int goal, cnt = 0;
	scanf("%d", &goal);
	upStair(0, goal, &cnt);
	printf("%d\n", cnt);
	return 0;
}

void upStair(int cur, int goal, int * cnt) {
	if (cur == goal)
		(*cnt)++;
	else if (cur < goal) {
		upStair(cur + 1, goal, cnt);
		upStair(cur + 2, goal, cnt);
	}
	else {
		return;
	}
}