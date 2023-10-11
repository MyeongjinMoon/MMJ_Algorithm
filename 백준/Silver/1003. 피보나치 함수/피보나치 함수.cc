#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int fibonacci_zero(int n, int* pibo) {
	if (n == 0) {
		pibo[0] = 1;
		return pibo[0];
	}
	else if (n == 1) {
		pibo[1] = 1;
		return 0;
	}
	else if (pibo[n] > 0) {
		return pibo[n];
	}
	else {
		return pibo[n] = fibonacci_zero(n - 1, pibo) + fibonacci_zero(n - 2, pibo);
	}
}

int fibonacci_one(int n, int* pibo) {
	if (n == 0) {
		pibo[0] = 1;
		return 0;
	}
	else if (n == 1) {
		pibo[1] = 1;
		return pibo[1];
	}
	else if (pibo[n] > 0) {
		return pibo[n];
	}
	else {
		return pibo[n] = fibonacci_one(n - 1, pibo) + fibonacci_one(n - 2, pibo);
	}
}

int main() {
	int n, m;

	int* pibo = (int*)calloc(sizeof(int), 40);
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int* pibo = (int*)calloc(sizeof(int), 40);

		scanf("%d", &m);

		int z = fibonacci_zero(m, pibo);

		pibo = (int*)calloc(sizeof(int), 40);

		int o = fibonacci_one(m, pibo);

		printf("%d %d\n", z, o);
		free(pibo);
	}
}