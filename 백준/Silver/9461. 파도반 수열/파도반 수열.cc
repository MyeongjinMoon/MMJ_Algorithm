#include <stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main() {
	int n;
	scanf("%d", &n);

	long long* answer = (long long*)malloc(sizeof(long long) * n);

	for (int i = 0; i < n; i++) {
		int value;
		scanf("%d", &value);

		long long* seq = (long long*)malloc(sizeof(long long) * value);

		for (int i = 0; i < MIN(5, value); i++) {
			if (i > 2) {
				seq[i] = 2;
				continue;
			}
			seq[i] = 1;
		}

		for (int i = 5; i < value; i++) {
			seq[i] = seq[i - 1] + seq[i - 5];
		}

		answer[i] = seq[value - 1];
	}

	for (int i = 0; i < n; i++) {
		printf("%lld\n", answer[i]);
	}
}