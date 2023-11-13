#include<stdio.h>

#pragma warning(disable:4996)

int main() {
    int n;

    while (1) {
        int a[1000], b = 0, c = 0;
        scanf("%d", &n);
        if (n == -1)
            break;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                a[b++] = i;
            }
        }
        for (int i = 0; i < b; i++) {
            c += a[i];
        }
        if (c == n) {
            printf("%d = 1", n);
            for (int i = 1; i < b; i++) {
                printf(" + %d", a[i]);
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", n);
        }
    }
}