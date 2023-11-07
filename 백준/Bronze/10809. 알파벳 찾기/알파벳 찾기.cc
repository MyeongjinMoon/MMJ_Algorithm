#include <stdio.h>

int main() {
    char a[100];
    int b[26];
    for (int i = 0; i < 26; i++) {
        b[i] = -1;
    }
    int c = 0;

    scanf("%s", a);

    while (a[c] != '\0') {
        if (b[a[c] - 97] == -1) {
            b[a[c] - 97] = c;
        }
        c++;
    }
    for (int i = 0; i < 26; i++) {
        printf("%d ", b[i]);
    }
}