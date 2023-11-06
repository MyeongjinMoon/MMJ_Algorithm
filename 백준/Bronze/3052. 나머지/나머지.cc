#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int a, count = 0;
    int c[42] = { 0 };

    for (int i = 0; i < 10; i++) {
        scanf("%d", &a);

        c[a % 42]++;
    }
    for (int i = 0; i < 42; i++) {
        if (c[i] > 0)
            count++;
    }

    printf("%d", count);
}