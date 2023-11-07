#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
    int a;
    int count = 0;

    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        char b[101];
        int c[26] = { 0 };
        int flag = 1;

        scanf("%s", b);

        for (int i = 0; i < strlen(b); i++) {
            if (c[b[i]-97] == 0) {
                c[b[i]-97] = 1;
            }
            else {
                if (b[i] == b[i - 1]) {
                    continue;
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            count++;
        }
    }
    printf("%d", count);
}