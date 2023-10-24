#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)

#define MIN(a,b) (a < b ? a : b)

int main() {
	int n;

	scanf("%d", &n);

	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}

	for (int i = 2; pow(i, 2) <= n; i++) {
		int sqr = pow(i, 2);
		int temp, value;

		for (int j = pow(i, 2); j <= n; j++) {
			if (j % sqr == 0) {
				dp[j] = j / sqr;
			}
			else {
				temp = j / sqr;
				value = j - temp * sqr;
				dp[j] = MIN(dp[j], temp + dp[value]);
			}
		}
	}

	printf("%d", dp[n]);
}