#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int main() {
    char a[9][3] = { "F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+" };
    int count = 0;
    double score = 0;
    for (int i = 0; i < 20; i++) {
        char b[59];
        fgets(b, sizeof(b), stdin);

        for (int j = 0; j < strlen(b); j++) {
            char c[3];
            if (b[j] == ' ') {   
                if (b[j + 5] == 'F') {
                    count += (b[j + 1] - 48);
                    break;
                }
                else if (b[j + 5] == 'P') {
                    break;
                }
                else {
                    c[0] = b[j + 5];
                    c[1] = b[j + 6];
                    c[2] = '\0';
                    for (int k = 1; k < 9; k++) {
                        if (!strcmp(a[k], c)) {
                            count += (b[j + 1] - 48);
                            score += (b[j + 1] - 48) * ((double)(k + 1) / 2);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    if (count == 0) {
        printf("0.000000");
    }
    else {
        printf("%.6lf", score / count);
    }
}