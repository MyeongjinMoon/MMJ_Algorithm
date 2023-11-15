#include<stdio.h>

#pragma warning(disable:4996)

int main() {
	int a[5], avg = 0, b;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
		avg += a[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("%d\n%d", avg / 5, a[2]);
}