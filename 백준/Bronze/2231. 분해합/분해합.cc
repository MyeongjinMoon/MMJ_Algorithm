#include<stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int a,min = 1000001;
	scanf("%d", &a);

	for (int i = 1; i < a; i++) {
		int b = i;
		int c = b;
		while (b) {
			c += b % 10;
			b /= 10;
		}
		if (c == a && min > c)
			min = i;
	}

	if (min == 1000001)
		printf("0");
	else
		printf("%d", min);
}