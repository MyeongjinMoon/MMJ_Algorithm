#include <stdio.h>

#pragma warning(disable:4996)

int tile(int n, int* flag) {
	if (n == 1)
		return flag[n] = 1;
	else if (n == 2)
		return flag[n] = 2;
	else {
		if (flag[n] == 0)
			return flag[n] = (tile(n - 1, flag) + tile(n - 2, flag)) % 10007;
		else
			return flag[n] = (flag[n - 1] + flag[n - 2]) % 10007;
	}
		
}

int main() {
	int n;
	int flag[1001] = { 0 };

	scanf("%d", &n);

	printf("%d", (tile(n, flag)));
}