#include<stdio.h>
#include <math.h>

#pragma warning(disable:4996)

int main() {
    long long a, b, c, d = 0;

    scanf("%lld %lld %lld", &a, &b, &c);

    d = 1;

    d += (ceil)((double)(c - a) / (a - b));

    printf("%lld", d);
}