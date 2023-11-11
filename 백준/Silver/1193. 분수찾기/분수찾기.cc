#include<stdio.h>

#pragma warning(disable:4996)

int main() {
    int a, b = 0, i, j;
    scanf("%d", &a);

    for (i = 1; i <= a; i++) {
        b = b + i;
        if (b >= a) {
            break;
        }
    }
    for (j = 1; j <= i; j++) {
        if (j + b - i == a) {
            break;
        }
    }
    if (i % 2 == 0) {
        int k = 1;
        for ( ; k < j; k++) {

        }
        printf("%d/%d", k, i + 1 - k);
    }
    else {
        int k = 1;
        for (; k < j; k++) {

        }
        printf("%d/%d", i + 1 - k, k);
    }
}