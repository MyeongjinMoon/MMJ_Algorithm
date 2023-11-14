#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a * d + b <= c * d && a<=c)
        printf("1");
    else
        printf("0");
}