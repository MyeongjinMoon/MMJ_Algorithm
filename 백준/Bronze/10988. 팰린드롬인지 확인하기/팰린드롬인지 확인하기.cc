#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
    char a[101];
    int flag = 1;

    scanf("%s", a);

    if (strlen(a) == 1) {
        printf("1");
        return 0;
    }
    for (int i = 0; i < strlen(a) / 2; i++) {
        if (a[i] != a[strlen(a) - i - 1])
            flag = 0;
    }
    if (flag)
        printf("1");
    else
        printf("0");
}