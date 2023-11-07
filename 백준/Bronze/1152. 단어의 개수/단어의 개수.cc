#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
    char a[1000002];
    int flag = 0, count = 0;

    scanf("%[^\n]s", a);
    
    for (int i = 0; i < strlen(a); i++) {
        if (((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) && flag == 0) {
            flag = 1;
            count++;
        }
        if (a[i] == ' ')
            flag = 0;
    }
    printf("%d", count);
}