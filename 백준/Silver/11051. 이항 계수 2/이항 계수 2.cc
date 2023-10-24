#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MOD 10007

int main() {
	int n, k;

	int ans = 1;

	scanf("%d %d", &n, &k);

	int** dp = (int**)calloc(sizeof(int*), n);
	for (int i = 0; i < n; i++) {
		dp[i] = (int*)calloc(sizeof(int), 2);
	}

	for (int i = 0; i < n; i++) {
		dp[i][0] = n - i;
		dp[i][1] = n - i;
	}

	for (int i = n - k; i < n - 1; i++) {
		int flag = 0;
		for (int j = 0; j < k; j++ ) {
			if (dp[j][0] % dp[i][1] == 0) {
				dp[j][0] /= dp[i][1];
				break;
			}
			for (int l = dp[i][1] - 1; l > 1; l--) {
				if (dp[j][0] % l == 0 && dp[i][1] % l == 0) {
					dp[j][0] /= l;
					dp[i][1] /= l;
					break;
				}
			}
		}
	}

	for (int i = 0; i < k; i++) {
		ans = (ans * dp[i][0]) % MOD;
	}

	printf("%d", ans);
}