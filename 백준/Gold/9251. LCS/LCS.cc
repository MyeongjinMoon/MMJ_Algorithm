#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b ? a : b)

int main() {
	char str1[1000], str2[1000];
	int len1, len2;

	int** dp = (int**)calloc(sizeof(int*),1001);
	for (int i = 0; i < 1001; i++) {
		dp[i] = (int*)calloc(sizeof(int),1001);
	}

	scanf("%s", str1 + 1);
	scanf("%s", str2 + 1);

	len1 = strlen(str1 + 1);
	len2 = strlen(str2 + 1);

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d\n", dp[len1][len2]);

	return 0;
}