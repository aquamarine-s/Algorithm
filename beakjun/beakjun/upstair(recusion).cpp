/*
���α׷� ��: upstair(recusion)
���ѽð�: 1 ��
�ִ� 2 ĭ ���� ���� �� ���� �� ������ ����� �������� ��� �ϴ� �����̴�.

�׸��� n �� 4 �� ����� �� �̴�.

1 - 2 - 3 - 4
1 - 2 - 4
1 - 3 - 4
2 - 3 - 4
2 - 4

�Է�
n �� 30 ������ ���� �����̴�.

���
���� �� �ִ� ���� ���� ����Ѵ�.
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