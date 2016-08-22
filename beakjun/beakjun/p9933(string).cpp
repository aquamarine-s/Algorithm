#include <string.h>
#include <stdio.h>
using namespace std;

char * reverseString(char * str);
int strCmp(char * str1, char *str2);

int main() {

	int n, i, j;
	char list[100][15];
	bool flag = false;
	int strLen;
	//입력
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", list[i]);
	}
	
	//처리
	for (i = 0; i < n; i++) {
		char reverseStr[15];
		strcpy(reverseStr, reverseString(list[i]));
		for (j = i + 1; j < n; j++) {

			if (strCmp(reverseStr, list[j]) == 0) {
				flag = true;
				break;
			}

		}
		if (flag == true)
			break;
	}


	//출력
	strLen = strlen(list[i]);
	printf("%d %c\n", strLen, list[i][strLen/2]);

	return 0;
}

int strCmp(char * str1, char *str2) {
	int i;
	int str1Len, str2Len;
	str1Len = strlen(str1);
	str2Len = strlen(str2);

	for (i = 0; i < str1[i] != '\0'; i++) {
	
		if (i >= str2Len)
			return 1;
		
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] == str2[i])
			;
		else
			return -1;
	
	}

	if (str1Len == str2Len)
		return 0;
	else
		return -1;
}

char * reverseString(char * str) {
	int i, j;
	char temp[15];
	int size = strlen(str);

	for (i = 0, j = size-1; i < size; i++, j--) {
		temp[i] = str[j];
	}
	temp[size] = '\0';

	return temp;
}