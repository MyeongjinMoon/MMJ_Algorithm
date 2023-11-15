#include<stdio.h>
#include <math.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int a, b[11], n = 0;

	scanf("%d", &a);

	while (a) {
		b[n++] = a % 10;
		a /= 10;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (b[i] < b[j]) {
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d", b[i]);
	}
}