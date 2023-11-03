#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;
	unsigned long long m;
	scanf("%d %llu", &n, &m);

	int* Array = (int*)malloc(sizeof(int) * (n+1));

	for (int i = 0; i < n; i++) {
		scanf("%d", &Array[i]);
	}
	Array[n] = 0;
	long long temp = Array[0];
	int min = n + 1;
	int i = 1, j = 0;
	while (i <= n && j <= n) {
		if (temp < m) {
			temp += Array[i++];
		}
		else {
			if (min > i - j)
				min = i - j;
			temp -= Array[j++];
		}
	}

	if (min == n + 1)
		printf("0");
	else
		printf("%d", min);
}