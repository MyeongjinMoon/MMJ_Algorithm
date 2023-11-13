#include<stdio.h>

#pragma warning(disable:4996)

int main() {
    int a[3] = { 0 };

    while (1) {
        int b = 0;

        scanf("%d %d %d", &a[0], &a[1], &a[2]);

        if (a[0] == 0 && a[1] == 0 && a[2] == 0)
            break;

        int max_index = 0;
        int max = a[0];

        if (max < a[1]) {
            max_index = 1;
            max = a[1];
        }
        if (max < a[2]) {
            max_index = 2;
            max = a[2];
        }
        for (int i = 0; i < 3; i++) {
            if (max_index == i)
                continue;
            b += a[i];
        }

        if (max < b) {
            if (a[0] == a[1] && a[1] == a[2]) {
                printf("Equilateral\n");
            }
            else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) {
                printf("Isosceles\n");
            }
            else {
                printf("Scalene\n");
            }
        }
        else {
            printf("Invalid\n");
        }
    }
}