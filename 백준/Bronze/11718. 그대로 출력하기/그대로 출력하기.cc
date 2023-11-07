#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    char c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}