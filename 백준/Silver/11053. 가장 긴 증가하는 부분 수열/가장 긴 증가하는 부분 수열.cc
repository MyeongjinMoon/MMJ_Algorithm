#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	int* Array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &Array[i]);
	}

	int* step = (int*)calloc(sizeof(int), 1000);
	
	step[0] = 1;

	int max = step[0];

	for (int i = 1; i < n; i++) {
		int temp = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (Array[i] > Array[j] && step[j] > temp) {
				temp = step[j];
			}
		}

		step[i] = temp + 1;

		if (step[i] > max) {
			max = step[i];
		}
	}

	printf("%d", max);
}