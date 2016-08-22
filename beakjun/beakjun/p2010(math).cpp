#include <stdio.h>

int main() {

	int multiTaps;
	int plugs[50000];
	int i;
	int res = 0;
	scanf("%d", &multiTaps);

	for (i = 0; i < multiTaps; i++) {
		scanf("%d", &plugs[i]);
		res += (plugs[i] - 1);
	}

	printf("%d\n", res + 1);
	return 0;
}