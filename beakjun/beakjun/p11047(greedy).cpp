#include <stdio.h>

int main() {

	unsigned int n, k, i, cnt = 0;
	int arr[11];

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) 
		scanf("%d", &arr[i]);

	while (k != 0) {
		for (i = 0; i < n; i++) {
			if (k < arr[i])
				break;
		}
		k -= arr[i - 1];
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}