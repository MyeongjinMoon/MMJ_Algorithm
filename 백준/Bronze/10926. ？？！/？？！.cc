#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    char name[54];

    scanf("%s", name);

    for (int i = 0; i < 51; i++) {
        if (name[i] == '\0') {
            name[i] = '?';
            name[i + 1] = '?';
            name[i + 2] = '!';
            name[i + 3] = '\0';
            break;
        }
    }
    printf("%s", name);
}