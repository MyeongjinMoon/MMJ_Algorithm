#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int n, m;
    int a = 0, b = 0;

    scanf("%d %d", &n, &m);

    if (n == 1)
        n++;

    for (int i = n; i <= m; i++) {
        int flag = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            if (a == 0) {
                a = i;
            }
            b += i;
        }
    }

    if (a == 0) {
        printf("-1");
    }
    else
        printf("%d\n%d", b, a);
}