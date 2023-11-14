#include<stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int a, b, max = 0;
	scanf("%d %d", &a, &b);

	int* c = (int*)malloc(sizeof(int) * a);

	for (int i = 0; i < a; i++)
		scanf("%d", &c[i]);

	for (int i = 0; i < a - 2; i++) {
		for (int j = i + 1; j < a - 1; j++) {
			for (int k = j + 1; k < a; k++) {
				if (max < c[i] + c[j] + c[k] && c[i] + c[j] + c[k] <= b)
					max = c[i] + c[j] + c[k];
			}
		}
	}
	printf("%d", max);
}