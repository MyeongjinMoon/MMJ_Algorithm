#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);

	long long pinary[91][2];

	pinary[0][0] = 0;
	pinary[0][1] = 1;
	for (int i = 1; i < n; i++) {
		
		pinary[i][0] = pinary[i - 1][0] + pinary[i - 1][1];
		pinary[i][1] = pinary[i - 1][0];
		
	}

	printf("%lld", pinary[n - 1][0] + pinary[n - 1][1]);
}