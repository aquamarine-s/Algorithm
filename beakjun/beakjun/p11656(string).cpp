#include <stdio.h>
#include <string.h>

int main() {

	char string[1001];
	char suffixs[1000][1001];
	char temp[1001];
	int i, j, strLen, minIndex;

	
	scanf("%s", string);
	strLen = strlen(string);
	for (i = 0; i < strLen; i++) {
		strcpy(suffixs[i], string + i);
		//printf("%s\n", suffixs[i]);
	}

	for (i = 0; i < strLen - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < strLen; j++) {
			if (strcmp(suffixs[j], suffixs[minIndex]) == -1)
				minIndex = j;
		}

		strcpy(temp, suffixs[minIndex]);
		strcpy(suffixs[minIndex], suffixs[i]);
		strcpy(suffixs[i], temp);
	}

	for (i = 0; i < strLen; i++)
		printf("%s\n", suffixs[i]);

	return 0;
}