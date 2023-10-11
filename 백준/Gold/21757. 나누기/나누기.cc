#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;

	long long pos = 0;

	scanf("%d", &n);

	int* part = (int*)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &part[i]);
	}

	int i = 1, j = 2, k = 3;

	while (1) {
		int part_1 = 0, part_2 = 0, part_3 = 0, part_4 = 0;
		for (int a = 0; a < i; a++) {
			part_1 += part[a];
		}

		for (int b = i; b < j; b++) {
			part_2 += part[b];
		}

		for (int c = j; c < k; c++) {
			part_3 += part[c];
		}

		for (int d = k; d < n; d++) {
			part_4 += part[d];
		}

		if (part_1 == part_2 && part_2 == part_3 && part_3 == part_4) {
			pos++;
		}
		
		if (k + 1 < n) {
			k++;
		}
		else if (j + 1 < k) {
			j++;
			k = j + 1;
		}
		else if (i + 1 < j) {
			i++;
			j = i + 1;
			k = j + 1;
		}
		else {
			break;
		}
	}

	printf("%d", pos);
}