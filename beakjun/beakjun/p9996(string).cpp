
#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, k;
	char pattern[100];
	char directory[100][101];
	char f[100], r[100];
	int patternLen, fLen, rLen, strLen;

	scanf("%d", &n);
	scanf("%s", pattern);
	for (i = 0; i < n; i++) {
		scanf("%s", directory[i]);
	}

	patternLen = strlen(pattern);
	for (i = 0; pattern[i] != '*'; i++)
		f[i] = pattern[i];
	f[i] = '\0';
	fLen = strlen(f);
	for (i = fLen + 1, j =0 ; pattern[i]; i++, j++)
		r[j] = pattern[i];
	r[j] = '\0';
	rLen = strlen(r);

	for (i = 0; i < n; i++) {
		strLen = strlen(directory[i]);		
		if (strLen < patternLen - 1)
			printf("NE\n");
		else {
			int fFlag = 0, rFlag = 0;
			for (j = 0; j < fLen; j++) {
				if (f[j] != directory[i][j])
					break;
			}
			if (j == fLen)
				fFlag = 1;
			
			for (j = strLen - 1, k = rLen - 1; k >= 0; k--, j--) {
				if (directory[i][j] != r[k])
					break;
			}
			if (k == -1)
				rFlag = 1;

			if (fFlag && rFlag)
				printf("DA\n");
			else
				printf("NE\n");
		}
	}

	return 0;
}
