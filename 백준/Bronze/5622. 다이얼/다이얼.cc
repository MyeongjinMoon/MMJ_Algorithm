#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
    char a[8][5] = { "ABC","DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
    char b[16];
    int t = 0;

    scanf("%s", b);

    for (int i = 0; i < strlen(b); i++) {
        for (int j = 0; j < 8; j++) {
            int flag = 0;
            for (int k = 0; k < strlen(a[j]); k++) {
                if (b[i] == a[j][k]) {
                    t += j;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
    }

    t += strlen(b) * 3;

    printf("%d", t);
}