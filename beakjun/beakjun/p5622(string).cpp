#include <stdio.h>
#include <string.h>

int main() {

	int cost[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
	char dial[16];
	scanf("%s", dial);
	int strLen = strlen(dial);
	int i;
	int time = 0;

	for (i = 0; i < strLen; i++) {
		time += (cost[dial[i] - 'A'] );
	}
	
	printf("%d\n", time);

	return 0;
}