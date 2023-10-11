#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MAX 1000001

int make(int n, int* r) {
	int a = MAX, b = MAX, c = MAX;
	if (r[n - 1] == 0 && n > 3) {
		make(n - 1, r);
	}

	if (n % 3 == 0) {
		a = r[n / 3] + 1;
	}
	if (n % 2 == 0) {
		b = r[n / 2] + 1;
	}
		c = r[n - 1] + 1;
	
	if (a <= b && a <= c) {
		return r[n] = a;
	}
	else if (b <= c) {
		return r[n] = b;
	}
	else {
		return r[n] = c;
	}
}

int main() {
	int n;

	scanf("%d", &n);

	int* r = (int*)calloc(sizeof(int), n + 1);

	r[0] = 1;
	r[1] = 0;
	r[2] = 1;
	r[3] = 1;

	if (n > 1)
		printf("%d", make(n, r));
	else
		printf("0");
}