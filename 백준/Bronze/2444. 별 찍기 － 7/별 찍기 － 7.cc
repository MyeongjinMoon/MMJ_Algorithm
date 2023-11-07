#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
    int a;

    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = a-2; i >= 0; i--) {
        for (int j = 0; j < a - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}