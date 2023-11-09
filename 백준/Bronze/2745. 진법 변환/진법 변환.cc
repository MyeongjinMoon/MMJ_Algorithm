#include <stdio.h>
#include <string.h>
#include <math.h>

#pragma warning(disable:4996)

int main() {
	char a[10000];
	double b;
	double c = 0;

	scanf("%s %lf", a, &b);

	for (int i = strlen(a) - 1; i >= 0; i--) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			c += (a[i] - 55) * pow(b, strlen(a) - i - 1);
		}
		else {
			c += (a[i] - 48) * pow(b, strlen(a) - i - 1);
		}
	}
	printf("%.lf", c);
}