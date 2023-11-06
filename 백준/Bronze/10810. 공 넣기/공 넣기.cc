#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int a, b;
    int c[101] = { 0 };

    scanf("%d %d", &a, &b);

    for (int i = 0; i < b; i++) {
        int d, e, f;
        scanf("%d %d %d", &d, &e, &f);

        for (int j = d - 1; j <= e - 1; j++) {
            c[j] = f;
        }
    }
    for (int i = 0; i < a; i++) {
        printf("%d ", c[i]);
    }
}