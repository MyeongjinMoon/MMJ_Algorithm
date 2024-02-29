#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma warning(disable : 4996)

int max = -1;

int n, m;

int deep = 3;

void wall(int** lab, int row, int col) {
	if (deep > 0) {

		for (int i = row; i < n + 1; i++) {
			int j;
			if (i > row)
				j = 1;
			else
				j = col;

			for (; j < m + 2; j++) {
				int lol = lab[i][j];
				if (lab[i][j] == 0) {
					lab[i][j] = 3;
					deep--;
					wall(lab, i, j + 1);
					lab[i][j] = 0;
				}
				else {
					continue;
				}
			}
		}
	}
	else {
		int** virus = (int**)malloc(sizeof(int*) * (n + 2));
		for (int i = 0; i < (n + 2); i++) {
			virus[i] = (int*)malloc(sizeof(int) * (m + 2));
		}
		
		for (int i = 0; i < n + 2; ++i) {
			memcpy(virus[i], lab[i], (m + 1) * sizeof(int));
		}

		while (1) {
			int chg = 0;
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < m + 1; j++) {
					if (virus[i][j] == 0 && (virus[i][j + 1] == 2 || virus[i + 1][j] == 2 || virus[i - 1][j] == 2 || virus[i][j-1] == 2)) {
						chg = 1;
						virus[i][j] = 2;
					}
				}
			}
			if (chg == 0)
				break;
		}
		int count = 0;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (virus[i][j] == 0) {
					count++;
				}
			}
		}
		if (count > max) {
			/*
			printf("\nmax : \n");

			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < m + 1; j++)
					printf("%3d", virus[i][j]);
				printf("\n");
			}
			*/
			
			max = count;
		}
			
		free(virus);
	}
	deep++;
}

int main() {
	
	scanf("%d %d", &n, &m);

	int** lab = (int**)malloc(sizeof(int*) * (n + 2));
	for (int i = 0; i < (n + 2); i++) {
		lab[i] = (int*)malloc(sizeof(int) * (m + 2));
	}

	for (int i = 0; i < n + 2; i++) {
		if (i == (n + 1) || i == 0) {
			for (int j = 0; j < m + 2; j++) {
				lab[i][j] = -1;
			}
		}
		else {
			lab[i][m + 1] = -1;
			lab[i][0] = -1;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			scanf("%d", &lab[i][j]);
		}
	}
	
	/*
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			printf("%3d", lab[i][j]);
		}
		printf("\n");
	}
	*/

	wall(lab, 1, 1);

	printf("%d", max);
}