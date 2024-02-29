#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int tmp;

	scanf("%d", &n);

	int* time = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &time[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (time[i] > time[j]) {
				tmp = time[i];
				time[i] = time[j];
				time[j] = tmp;
			}
		}
	}
	int total_t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			total_t += time[j];
		}
	}

	printf("%d", total_t);

	return 0;
}