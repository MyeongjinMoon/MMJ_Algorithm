#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int* dp = (int*)calloc(sizeof(int), (n + 1));

	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && (arr[i] + dp[j]) > max) {
				max = (arr[i] + dp[j]);
			}
		}
		dp[i] = max;
	}

	int max = 0;

	for (int i = 1; i <= n; i++) {
		if (dp[i] > max) {
			max = dp[i];
		}
	}

	printf("%d", max);
}