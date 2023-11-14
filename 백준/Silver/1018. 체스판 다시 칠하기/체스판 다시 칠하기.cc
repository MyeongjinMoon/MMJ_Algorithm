#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

int main() {
	int a, b, min = 65;

	char chess_1[8][8], chess_2[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				chess_1[i][j] = 'B';
				chess_2[i][j] = 'W';
			}
			else {
				chess_1[i][j] = 'W';
				chess_2[i][j] = 'B';
			}
		}
	}

	scanf("%d %d", &a, &b);

	char** c = (char**)malloc(sizeof(char*) * a);
	for (int i = 0; i < a; i++) {
		c[i] = (char*)malloc(sizeof(char) * b);
		for (int j = 0; j < b; j++) {
			scanf(" %c", &c[i][j]);
		}
	}

	for (int i = 0; i < a - 7; i++) {
		for (int j = 0; j < b - 7; j++) {
			int count_1 = 0, count_2 = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (c[k][l] != chess_1[k - i][l - j]) {
						count_1++;
					}
					if (c[k][l] != chess_2[k - i][l - j]) {
						count_2++;
					}
				}
			}
			if (min > count_1)
				min = count_1;
			if (min > count_2)
				min = count_2;
		}
	}

	printf("%d", min);
}