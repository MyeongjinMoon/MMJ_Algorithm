#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);

	long long* Tile = (long long*)malloc(sizeof(long long) * 1000000);
	Tile[0] = 1;
	Tile[1] = 2;

	for (int i = 2; i < n; i++) {
		Tile[i] = Tile[i - 1] % 15746 + Tile[i - 2] % 15746;
	}
	printf("%lld", Tile[n - 1] % 15746);
}