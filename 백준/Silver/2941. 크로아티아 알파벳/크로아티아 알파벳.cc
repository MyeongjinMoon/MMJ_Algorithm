#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
	char CroAlpha[3][4] = { "lj", "nj", "dz=" };
	char* a = (char*)malloc(sizeof(char) * 101);

	int count = 0;

	scanf("%s", a);

	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == '-' || a[i] == '=') {
			continue;
		}
		else {
			char temp[4];
			strncpy(temp, a + i, 2);
			temp[2] = '\0';
			if (!strcmp(temp, CroAlpha[0]) && i < 99) {
				count++;
				i++;
				continue;
			}
			else if (!strcmp(temp, CroAlpha[1]) && i < 99) {
				count++;
				i++;
				continue;
			}
			strncpy(temp, a + i, 3);
			temp[3] = '\0';
			if (!strcmp(temp,CroAlpha[2]) && i < 98) {
				count++;
				i+=2;
				continue;
			}
			else {
				count++;
			}
		}
	}
	printf("%d", count);
}