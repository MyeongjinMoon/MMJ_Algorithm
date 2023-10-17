#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int MAX(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	int n;
	int score = 0;

	scanf("%d", &n);

	int* stair = (int*)malloc(sizeof(int) * (n + 1));
	int* flag = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}

	flag[0] = 0;
	flag[1] = stair[1];
	flag[2] = stair[2] + stair[1];

	for (int i = 3; i <= n; i++) {
		flag[i] = MAX((stair[i] + flag[i - 2]), (stair[i] + stair[i - 1] + flag[i - 3]));
	}

	printf("%d", flag[n]);
}