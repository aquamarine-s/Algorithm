#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

	char string[101];
	char conversedString[34];
	int i, cnt = 0, sum = 0, idx = 0;

	scanf("%s", &string);
	
	int strLen = strlen(string);
	
	for (i = strLen - 1; i >= 0 ; i--) {
		sum += (string[i] - '0') * (int)pow(2.0, cnt);
		cnt++;
		if (cnt % 3 == 0 || i == 0) {	
			conversedString[idx++] = sum + '0';
			cnt = 0;
			sum = 0;
		}
	}
	for (i = idx -1; i >= 0; i--) {
		printf("%c", conversedString[i]);
	}
	printf("\n");
	return 0;
}