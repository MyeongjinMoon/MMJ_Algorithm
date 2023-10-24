#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	int** dp = (int**)calloc(sizeof(int*), 1001);
	for (int i = 0; i < 1001; i++) {
		dp[i] = (int*)calloc(sizeof(int), 11);
	}

	for (int i = 1; i <= 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = j; k > 0; k--) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}

	int temp = 0;
	for (int i = 1; i <= 10; i++) {
		temp = (temp + dp[n][i]) % 10007;
	}
	printf("%d", temp);
}