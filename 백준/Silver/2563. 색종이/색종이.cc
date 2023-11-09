#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int n, m=0;
    int a[100][100] = { 0 };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int b, c;
        scanf("%d %d", &b, &c);
        for (int j = b; j < b + 10; j++) {
            for (int k = c; k < c + 10; k++) {
                a[j][k] = 1;
            }
        }
    }

    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            m += a[j][k];
        }
    }

    printf("%d", m);
}