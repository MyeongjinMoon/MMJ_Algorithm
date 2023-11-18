#include<stdio.h>
#include<stdlib.h>

int main() {
	for (int TC = 1; TC <= 10; TC++) {
		int n;
		scanf("%d", &n);

		int a[100][102] = { 0 };

		int c;

		for (int i = 0; i < 100; i++) {
			for (int j = 1; j <= 100; j++) {
				scanf("%d", &a[i][j]);
				if (i == 99 && a[i][j] == 2) {
					c = j;
				}
			}
		}

		int d = 0;	// 0 : 위, 1 : 왼쪽, 2 : 오른쪽
			int flag = 0;

			int x = c;
			int y = 99;
			while (1) {
				if (y == 0) {
					printf("#%d %d\n", TC, x - 1);
					break;
				}
				else if (d == 0 && a[y][x + 1] == 1) {
					d = 2;
					x += 1;
				}
				else if (d == 0 && a[y][x - 1] == 1) {
					d = 1;
					x -= 1;
				}
				else if (d == 0 && a[y - 1][x] == 1) {
					y -= 1;
				}
				else if (d == 2) {
					if (a[y][x + 1] == 1) {
						x += 1;
					}
					else {
						d = 0;
						y -= 1;
					}
				}
				else if (d == 1) {
					if (a[y][x - 1] == 1) {
						x -= 1;
					}
					else {
						d = 0;
						y -= 1;
					}
				}
			}
	}
}