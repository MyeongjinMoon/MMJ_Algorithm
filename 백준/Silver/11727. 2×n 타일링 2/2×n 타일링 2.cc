#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	int* TwoXOne = (int*)malloc(sizeof(int) * 1000);

	TwoXOne[0] = 1;
	TwoXOne[1] = 3;

	for (int i = 2; i < n; i++) {
		TwoXOne[i] = (TwoXOne[i - 1] + 2 * TwoXOne[i - 2]) % 10007;
	}

	printf("%d", TwoXOne[n - 1]);
}