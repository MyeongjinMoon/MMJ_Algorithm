#include<stdio.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);

	for (int TC = 1; TC <= t; TC++) {
		int n, p;
		
		scanf("%d", &n);

		int** a = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			a[i] = (int*)malloc(sizeof(int) * 2);
			scanf("%d %d", &a[i][0], &a[i][1]);
		}
		
		scanf("%d", &p);

		printf("#%d", TC);

		int* c = (int*)malloc(sizeof(int) * p);
		for (int i = 0; i < p; i++) {
			int ans = 0;
			scanf("%d", &c[i]);

			for (int j = 0; j < n; j++) {
				if (c[i] >= a[j][0] && c[i] <= a[j][1])
					ans++;
			}
			printf(" %d", ans);
		}
		printf("\n");
	}
}