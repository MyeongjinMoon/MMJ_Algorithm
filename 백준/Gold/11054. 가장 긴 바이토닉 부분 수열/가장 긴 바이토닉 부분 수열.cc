#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;

	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int),  (n + 1));

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	int* dp_asc = (int*)calloc(sizeof(int), (n + 1));
	int* dp_dec = (int*)calloc(sizeof(int), (n + 1));

	for (int i = 1; i <= n; i++) {
		int max = -1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && max <= dp_asc[j])
				max = dp_asc[j] + 1;
		}
		dp_asc[i] = max;
	}

	for (int i = n - 1; i > 0; i--) {
		int max = 0;
		for (int j = i + 1; j <= n; j++) {
			if (arr[i] > arr[j] && max <= dp_dec[j])
				max = dp_dec[j] + 1;
		}
		dp_dec[i] = max;
	}

	for (int i = 1; i <= n; i++) {
		dp_asc[i] += dp_dec[i];
	}
    
	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (dp_asc[i] > max)
			max = dp_asc[i];
	}
	printf("%d", max);
}