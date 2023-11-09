#include<stdio.h>

#pragma warning(disable:4996)

int main() {
    long long a;
    long long b = 1;
    scanf("%lld", &a);

    a--;
    if (a == 0) {
        printf("1");
        return 0;
    }
    while (a > 0) {
        a -= b++ * 6;
    }
    printf("%lld", b);
}