#include<stdio.h>

#pragma warning(disable:4996)

int main() {
	int a, b, c, d, e, f;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	for (int i = -999; i < 1000; i++) {
		for (int j = -999; j < 1000; j++) {
			if (i * a + j * b == c && i * d + j * e == f) {
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
}