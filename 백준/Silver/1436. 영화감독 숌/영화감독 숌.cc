#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

int main() {
	int a, i = 665;

	scanf("%d", &a);

	while (a) {
		i++;
		int f = i, b = 0;
		while (f) {
			if (f % 10 == 6) {
				b++;
			}
			else {
				b = 0;
			}
			f /= 10;
			if (b == 3) {
				break;
			}
		}
		if (b == 3) {
			a--;
		}
	}
	printf("%d", i);
}