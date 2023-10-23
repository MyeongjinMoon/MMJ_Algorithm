#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n, k;

	scanf("%d %d", &n, & k);

	int* coin = (int*)calloc(sizeof(int), n);
	int* dp = (int*)calloc(sizeof(int), (k + 1));

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d", dp[k]);
}