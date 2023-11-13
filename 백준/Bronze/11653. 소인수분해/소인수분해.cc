#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int n;
    int a = 2;

    scanf("%d", &n);

    if (n == 1) {
        return 0;
    }
        
    while (n != 1) {
        for (int i = a; i <= n; i++) {
            if (n % i == 0) {
                printf("%d\n", i);
                n /= i;
                a = i;
                break;
            }
        }
    }
}