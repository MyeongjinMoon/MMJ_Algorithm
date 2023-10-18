#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);

	int* seq = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	int sum = 0;
	int max = -1001;

	for (int i = 0; i < n; i++) {
		if (sum + seq[i] > 0) {
			sum += seq[i];
			if (sum > max) {
				max = sum;
			}
		}
		else {
			if (seq[i] > max) {
				max = seq[i];
			}
			sum = 0;
		}
	}

	printf("%d", max);
}