#include <stdio.h>
#include <stdlib.h>

int main() {
	int t;
	int a, b;
	int pos_x, pos_y;
	char dir;

	scanf("%d", &t);

	for (int z = 1; z <= t; z++) {
		scanf("%d %d", &a, &b);

		while (getchar() != '\n') {}

		char** c = (char**)malloc(sizeof(char*) * a);
		for (char i = 0; i < a; i++) {
			c[i] = (char*)malloc(sizeof(char) * b);
			for (int j = 0; j < b; j++) {
				c[i][j] = getchar();
				if (c[i][j] == '<' || c[i][j] == '>' || c[i][j] == '^' || c[i][j] == 'v') {
					pos_x = j;
					pos_y = i;
					if (c[i][j] == '<') {
						dir = '<';
					}
					if (c[i][j] == '>') {
						dir = '>';
					}
					if (c[i][j] == '^') {
						dir = '^';
					}
					if (c[i][j] == 'v') {
						dir = 'v';
					}
				}
			}
			while (getchar() != '\n') {}
		}

		int d;

		scanf("%d", &d);

		char* e = (char*)malloc(sizeof(char) * d);

		while (getchar() != '\n') {}
		scanf("%s", e);

		for (int i = 0; i < d; i++) {

			switch (e[i])
			{
			case 'S':
				if (dir == '^') {
					for (int j = pos_y - 1; j >= 0; j--) {
						if (c[j][pos_x] == '#') {
							break;
						}
						if (c[j][pos_x] == '*') {
							c[j][pos_x] = '.';
							break;
						}
					}
				}
				else if (dir == 'v') {
					for (int j = pos_y + 1; j < a; j++) {
						if (c[j][pos_x] == '#') {
							break;
						}
						if (c[j][pos_x] == '*') {
							c[j][pos_x] = '.';
							break;
						}
					}
				}
				else if (dir == '<') {
					for (int j = pos_x - 1; j >= 0; j--) {
						if (c[pos_y][j] == '#') {
							break;
						}
						if (c[pos_y][j] == '*') {
							c[pos_y][j] = '.';
							break;
						}
					}
				}
				else {
					for (int j = pos_x + 1; j < b; j++) {
						if (c[pos_y][j] == '#') {
							break;
						}
						if (c[pos_y][j] == '*') {
							c[pos_y][j] = '.';
							break;
						}
					}
				}
				break;
			case 'U':
				c[pos_y][pos_x] = '^';
				dir = '^';
				if ((pos_y - 1) >= 0 && c[pos_y - 1][pos_x] == '.') {
					pos_y -= 1;
					c[pos_y][pos_x] = '^';
					c[pos_y + 1][pos_x] = '.';
				}
				break;
			case 'D':
				c[pos_y][pos_x] = 'v';
				dir = 'v';
				if ((pos_y + 1) < a && c[pos_y + 1][pos_x] == '.') {
					pos_y += 1;
					c[pos_y][pos_x] = 'v';
					c[pos_y - 1][pos_x] = '.';
				}
				break;
			case 'R':
				c[pos_y][pos_x] = '>';
				dir = '>';
				if ((pos_x + 1) < b && c[pos_y][pos_x + 1] == '.') {
					pos_x += 1;
					c[pos_y][pos_x] = '>';
					c[pos_y][pos_x - 1] = '.';
				}
				break;
			case 'L':
				c[pos_y][pos_x] = '<';
				dir = '<';
				if ((pos_x - 1) >= 0 && c[pos_y][pos_x - 1] == '.') {
					pos_x -= 1;
					c[pos_y][pos_x] = '<';
					c[pos_y][pos_x + 1] = '.';
				}
				break;
			default:
				break;
			}
		}
		printf("#%d ", z);
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				printf("%c", c[i][j]);
			}
			printf("\n");
		}
	}
}