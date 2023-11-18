#include <stdio.h>
#include <stdlib.h>

int main() {
	int t;

	scanf("%d", &t);

	for (int TC = 1; TC <= t; TC++) {
		int n;
		int count = 0;
		scanf("%d", &n);

		int* a = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (int i = 1; i < n - 1; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1] || a[i] < a[i - 1] && a[i] < a[i + 1])
				continue;
			else
				count++;
		}
		printf("#%d %d\n", TC, count);
	}
}