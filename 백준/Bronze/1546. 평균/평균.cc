#include <stdio.h>

#pragma warning(disable:4996)

int main() {
    int a, max = -1;
    double avg = 0;
    double b[1000] = { 0 };

    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        scanf("%lf", &b[i]);
        if (b[i] > max)
            max = b[i];
    }

    for (int i = 0; i < a; i++) {
        b[i] = (double)b[i] / max * 100;
        avg += b[i];
    }

    printf("%.9lf", avg / a);
}