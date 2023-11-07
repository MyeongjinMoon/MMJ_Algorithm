#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
	int MAX = 101;
	char CroAlpha[3][4] = { "lj", "nj", "dz=" };
	char* a = (char*)malloc(sizeof(char) * MAX);

	int count = 0;

	scanf("%s", a);

	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == '-' || a[i] == '=') {
			continue;
		}
		else {
			char temp[4];
			int flag = 1;
			for (int j = 0; j < 3; j++) {
				strncpy(temp, a + i, strlen(CroAlpha[j]));
				temp[strlen(CroAlpha[j])] = '\0';
				if (!strcmp(temp, CroAlpha[j]) && i < MAX - strlen(CroAlpha[j])) {
					count++;
					i += strlen(CroAlpha[j]) - 1;
					flag = 0;
					break;
				}
			}
			if (flag) {
				count++;
			}
		}
	}
	printf("%d", count);
}