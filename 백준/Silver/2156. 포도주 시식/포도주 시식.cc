#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

/*
6
6
10
13
9
8
1
*/

int main() {
	int n;

	scanf("%d", &n);

	int* beer = (int*)malloc(sizeof(int) * n);
	int* drink = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &beer[i]);
	}

	for (int i = 0; i < MIN(n, 3); i++) {
		if (i == 0) {
			drink[i] = beer[i];
		}
		if (i == 1) {
			drink[i] = beer[0] + beer[i];
		}
		if (i == 2) {
			drink[i] = MAX(beer[0] + beer[i], MAX(beer[0] + beer[1], beer[1] + beer[i]));
		}
	}

	for (int i = 3; i < n; i++) {
		drink[i] = MAX(beer[i] + drink[i - 2], MAX(beer[i] + beer[i - 1] + drink[i - 3], beer[i - 1] + beer[i - 2] + drink[i - 4]));
	}

	printf("%d", drink[n - 1]);
}