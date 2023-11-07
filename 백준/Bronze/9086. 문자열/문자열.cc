#include <stdio.h>

#pragma warning(disable:4996)

int main() {
        char a[1001];
        int b;

        scanf("%d", &b);

        for (int j = 0; j < b; j++) {
            int i = 0;
            scanf("%s", a);

            while (a[i] != '\0') {
                i++;
            }
            printf("%c%c\n", a[0], a[i - 1]);
        }
    }