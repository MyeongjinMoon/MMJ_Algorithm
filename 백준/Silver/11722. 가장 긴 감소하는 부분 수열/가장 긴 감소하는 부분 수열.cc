#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	int* dp = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int max = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] > arr[i] && dp[j] > max) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
	}

	int max = 1;

	for (int i = 2; i <= n; i++) {
		if (dp[i] > max)
			max = dp[i];
	}

	printf("%d", max);
}