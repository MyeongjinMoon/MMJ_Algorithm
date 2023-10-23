#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MAX(a,b) (a > b ? a : b)

int main() {
	int n;

	scanf("%d", &n);

	int** dp = (int**)calloc(sizeof(int*), 1001);
	for (int i = 0; i < 1001; i++) {
		dp[i] = (int*)calloc(sizeof(int), 1001);
	}

	int* card = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == j) {
				dp[i][j] = MAX(dp[i][j - 1], card[j]);
			}
			else {
				dp[i][j] = MAX(dp[i][j - 1], (i / j) * dp[j][j] + dp[i % j][i % j]);
			}
		}
	}

	printf("%d", dp[n][n]);
}