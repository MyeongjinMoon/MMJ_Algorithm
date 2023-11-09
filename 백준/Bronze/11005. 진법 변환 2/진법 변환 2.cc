#include <stdio.h>

#pragma warning(disable:4996)

int main() {
	char a[10000];
	int b;	//진법
	long long c;	//10진수 수
	int d = 0;	// n진수 크기

	scanf("%lld %d", &c, &b);

	while (c) {
		int temp = c % b;
		if (temp >= 10) {
			a[d++] = temp + 55;
		}
		else {
			a[d++] = temp + 48;
		}
		
		c /= b;
	}
	for (int i = d - 1; i >= 0; i--) {
		printf("%c", a[i]);
	}
}