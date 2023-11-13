#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

int main() {
    int n;

    scanf("%d", &n);

    int** a = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int) * 2);
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    if (n == 1) {
        printf("0");
        return 0;
    }

    int min_x = 10001, max_x = -10001, min_y = 10001, max_y = -10001;

    for (int i = 0; i < n; i++) {
        if (min_x > a[i][0])
            min_x = a[i][0];
        if (min_y > a[i][1])
            min_y = a[i][1];
        if (max_x < a[i][0])
            max_x = a[i][0];
        if (max_y < a[i][1])
            max_y = a[i][1];
    }
    printf("%lld", (long long)(max_x - min_x) * (long long)(max_y - min_y));
}