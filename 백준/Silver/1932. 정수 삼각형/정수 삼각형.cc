#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	int** triangle = (int**)malloc(sizeof(int*) * n);
	int** sum_triangle = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		triangle[i] = (int*)malloc(sizeof(int) * (i + 1));
		sum_triangle[i] = (int*)malloc(sizeof(int) * (i + 1));
		for (int j = 0; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}
	int max = triangle[0][0];

	sum_triangle[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				sum_triangle[i][j] = triangle[i][j] + sum_triangle[i - 1][j];
			}
			else if (j == i) {
				sum_triangle[i][j] = triangle[i][j] + sum_triangle[i - 1][j - 1];
			}
			else {
				sum_triangle[i][j] = MAX(triangle[i][j] + sum_triangle[i - 1][j], triangle[i][j] + sum_triangle[i - 1][j - 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (sum_triangle[n - 1][i] > max) {
			max = sum_triangle[n - 1][i];
		}
	}
	
	printf("%d", max);
}