#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int a, b, c = 0, flag = 0;

    scanf("%d %d", &a, &b);

    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            c++;
            if (c == b) {
                flag = 1;
                printf("%d", i);
                break;
            }
        }
    }
    if (!flag) {
        printf("0");
    }
}