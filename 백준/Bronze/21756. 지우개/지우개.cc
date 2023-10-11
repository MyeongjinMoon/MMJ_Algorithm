#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	int temp = n;

	int* erase = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		erase[i] = i + 1;
	}
	
	while (erase[1] != 0 && n != 1) {
		temp /= 2;

		int j = 1;

		for (int i = 0; i < temp; i++) {
			erase[i] = erase[j];
			j += 2;
		}

		for (int i = temp; i < n; i++) {
			erase[i] = 0;
		}
	}

	printf("%d", erase[0]);
}