#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define MAX 100001

int* isvisited;

int dx[3] = { 1,-1,2 };

typedef struct Queue {
	int arr[MAX];
	int front, rear;
}Queue;

void initQueue(Queue* q) {
	q->front = q->rear = 0;
}

bool isEmpty(Queue* q) {
	return q->front == q->rear;
}

bool isFull(Queue* q) {
	return q->front == (q->rear + 1);
}

void enqueue(Queue* q, int value) {
	q->arr[q->rear++] = value;
}

int dequeue(Queue* q) {
	return q->arr[q->front++];
}

int bfs(int N, int M) {
	Queue q;
	initQueue(&q);

	enqueue(&q, N);

	isvisited = (int*)calloc(sizeof(int), MAX);
	isvisited[N] = 1;

	while (!isEmpty(&q)) {
		int current = dequeue(&q);

		if (current == M) {
			return isvisited[current];
		}
		
		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 2) {
				nx = dx[i] * current;
			}
			else {
				nx = dx[i] + current;
			}
			if (nx >= 0 && nx < MAX && !isvisited[nx]) {
				isvisited[nx] = isvisited[current] + 1;
				enqueue(&q, nx);
			}
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	printf("%d", bfs(N, M) - 1);
}