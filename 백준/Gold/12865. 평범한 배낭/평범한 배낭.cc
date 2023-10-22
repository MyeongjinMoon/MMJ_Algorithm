#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int** weight = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		weight[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &weight[i][0], &weight[i][1]);
	}
	
	int** backpack = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		backpack[i] = (int*)malloc(sizeof(int) * (k + 1));
		for (int j = 0; j <= k; j++) {
			if (i == 0 || j == 0)
				backpack[i][j] = 0;
			else
				backpack[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (weight[i][0] > j)
				backpack[i][j] = backpack[i - 1][j];
			else
				backpack[i][j] = MAX(backpack[i - 1][j], weight[i][1] + backpack[i - 1][j - weight[i][0]]);
		}
	}

	printf("%d\n", backpack[n][k]);
}