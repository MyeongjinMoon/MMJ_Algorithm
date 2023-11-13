#include<stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
    int n, b = 0;

    scanf("%d", &n);

    int* a = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        int flag = 1;
        scanf("%d", &a[i]);
        for (int j = 2; j < a[i]; j++) {
            if (a[i] % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag && a[i]!=1) {
            b++;
        }
    }
    printf("%d", b);
}