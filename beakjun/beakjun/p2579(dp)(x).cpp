#include <stdio.h>

int main() {

	int n, i;
	int stair[301] = { 0, };
	int visit[301];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}

	int cnt = 0, cur = 0;
	int sum = 0;
	int flag = 0;

	//���� �ΰ���ΰ�? �׷� 2�� �پ�...
	//�ƴ϶�� ���� ��� ��ģ�Ŷ� ������ܿ��� 2�� �ڰ��� �� ū��.

	while (1) {
		
		if (stair[cur + 1] < stair[cur + 2] && ) {
			sum += stair[cur + 1];
			cur += 2;
		}
		else {
			sum += stair[cur + 1];
			cur += 1;
		}

	}
	printf("%d", sum);

	return 0;
}