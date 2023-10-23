#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MAX(a,b) (a > b ? a : b)

int main() {
	int n, T;
	scanf("%d", &T);

	int* answer = (int*)malloc(sizeof(int) * T);

	for (int k = 0; k < T; k++) {
		scanf("%d", &n);

		int** sticker = (int**)malloc(sizeof(int*) * 2);
		int** dp = (int**)calloc(sizeof(int*), 2);
		for (int i = 0; i < 2; i++) {
			sticker[i] = (int*)malloc(sizeof(int) * (n + 1));
			dp[i] = (int*)calloc(sizeof(int), (n + 1));
		}

		for (int j = 0; j < 2; j++) {
			for (int i = 1; i < (n + 1); i++) {
				scanf("%d", &sticker[j][i]);
			}
		}

		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];

		for (int i = 2; i < (n + 1); i++) {
			dp[0][i] = MAX((sticker[0][i] + dp[1][i - 1]), (sticker[0][i] + dp[1][i - 2]));
			dp[1][i] = MAX((sticker[1][i] + dp[0][i - 1]), (sticker[1][i] + dp[0][i - 2]));
		}
		answer[k] = MAX(dp[0][n], dp[1][n]);
		
	}
	for (int k = 0; k < T; k++) {
		printf("%d\n", answer[k]);
	}
}