#include<stdio.h>

#pragma warning(disable:4996)

int main() {
	int a;
	scanf("%d", &a);
	if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) {
		printf("1");
	}
	else printf("0");
}