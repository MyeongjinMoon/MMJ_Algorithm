#include<stdio.h>

#pragma warning(disable:4996)

int main() {
	int a[1001], b, c;

	scanf("%d %d", &b, &c);

	for (int i = 0; i < b; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < b-1; i++) {
		for (int j = i + 1; j < b; j++) {
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("%d", a[c-1]);
}