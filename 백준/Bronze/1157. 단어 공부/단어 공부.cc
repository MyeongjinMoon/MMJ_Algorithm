#include<stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
    char a[1000001];
    int b[26] = { 0 };
    int max = -1, flag;
    
    scanf("%s", a);

    int c = strlen(a);

    a[strlen(a)] = '\0';

    for (int i = 0; i < c; i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] += 32;
        }
        b[a[i] - 97]++;
    }
    for (int i = 0; i < 26; i++) {
        if (b[i] > max) {
            max = b[i];
            flag = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (i == flag) {
            continue;
        }
        else {
            if (b[i] == max) {
                printf("?");
                return 0;
            }
        }
    }
    printf("%c", flag + 65);
}