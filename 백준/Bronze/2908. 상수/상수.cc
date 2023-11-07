#include <stdio.h>

int main() {
    char a[4], b[4];
    int flag;

    scanf("%s %s", a, b);

    for (int i = 2; i >= 0; i--) {
        if (a[i] > b[i]) {
            flag = 0;
            break;
        }
        else if (a[i] < b[i]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        for (int i = 2; i >= 0; i--) {
            printf("%d", b[i] - 48);
        }
    }
    else {
        for (int i = 2; i >= 0; i--) {
            printf("%d", a[i] - 48);
        }
    }
}