#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    char a[5][16];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 16; j++) {
            a[i][j] = '-';
        }
    }

    for (int i = 0; i < 5; i++) {
        scanf("%s", a[i]);
    }

    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 5; i++) {
            if (a[i][j] == '\0' || a[i][j] == '-')
                continue;
            printf("%c", a[i][j]);
        }
    }
}