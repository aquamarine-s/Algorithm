#include <stdio.h>
#include <string.h>

int main() {

	char string[10001];
	int i, j, k;
	int joi_cnt = 0;
	int ioi_cnt = 0;

	scanf("%s", string);
	int strLen = strlen(string);
	for (i = 0; i < strLen - 2; i++) {
		char temp[4];
		for (j = i, k = 0; j < i + 3; j++, k++) {
			temp[k] = string[j];
		}
		temp[k] = '\0';

		if (strcmp(temp, "JOI") == 0)
			joi_cnt++;
		else if (strcmp(temp, "IOI") == 0)
			ioi_cnt++;
	}
	printf("%d\n%d\n", joi_cnt, ioi_cnt);
	return 0;
}