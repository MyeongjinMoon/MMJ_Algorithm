#include <stdio.h>
#include<stdlib.h>

int main() {
	int t;
	scanf("%d", &t);

	for (int TC = 1; TC <= t; TC++) {
		int n;
		scanf("%d", &n);

		int** a = (int**)calloc(sizeof(int*),n);
		for (int i = 0; i < n; i++) {
			a[i] = (int*)calloc(sizeof(int),n);
			for (int j = 0; j < n; j++) {
				if (j == 0 || i == j)
					a[i][j] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (a[i][j] == 0) {
					a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
				}
			}
		}
		printf("#%d\n", TC);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}