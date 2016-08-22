#include <stdio.h>
#include <string.h>

int main() {
	char string[30001];
	char key[1000];
	int i, j, strLen, keyLen;
	scanf("%[^\n]", string);
	scanf("%s", key);

	strLen = strlen(string);
	keyLen = strlen(key);
	for (i = 0, j = 0; i < strLen; i++, j++) {
		if (string[i] == ' ')
			;
		else {
			if (string[i] > key[j]) {
				string[i] -= key[j];
				string[i] += ('a' -1);
			}
			else {
				string[i] -= key[j];
				string[i] = 'z' - (string[i] * -1);
			}
		}
			
		if (j == keyLen -1)
			j = -1;
	}

	printf("%s\n", string);
	return 0;
}