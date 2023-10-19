#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MAX 401

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct Point {
	int x, y;
	int dis;
}Point;

typedef struct Stack {
	Point* arr;
	int tail;
}Stack;

void initStack(Stack* s) {
	s->arr = (Point*)malloc(sizeof(Point) * MAX);
	s->tail = 0;
}

bool isFull(Stack* s) {
	return (s->tail == MAX);
}

bool isEmpty(Stack* s) {
	return (s->tail == 0);
}

void push(Stack* s, Point value) {
	s->arr[s->tail++] = value;
}

Point pull(Stack* s) {
	if (s->tail == 0) {
		return {0, 0, 0};
	}
	return s->arr[--s->tail];
}

bool isvisited(char* flag, char value, int dis) {
	for (int i = 1; i <= dis; i++) {
		if (value == flag[i])
			return true;
	}
	return false;
}

int main() {
	int R, C;

	scanf("%d %d", &R, &C);
	char** mtrx = (char**)malloc(sizeof(char*) * R);
	for (int i = 0; i < R; i++) {
		mtrx[i] = (char*)malloc(sizeof(char) * C);
		for (int j = 0; j < C; j++) {
			scanf(" %c", &mtrx[i][j]);
		}
	}

	char* flag = (char*)malloc(sizeof(char) * MAX);

	Stack s;
	int max = 1;
	initStack(&s);

	push(&s, { 0, 0, 1});


	while(!isEmpty(&s)){
		Point current = pull(&s);

		if (current.dis > max)
			max = current.dis;
		
		int x = current.x, y = current.y;
		flag[current.dis] = mtrx[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C && !isvisited(flag, mtrx[nx][ny], current.dis)) {
				push(&s, { nx, ny, current.dis + 1 });
			}
		}
		
	}

	printf("%d", max);
}