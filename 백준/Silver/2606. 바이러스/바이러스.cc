#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma warning(disable : 4996)

#define MaxSize  1001

typedef struct Queue {
	int arr[MaxSize];
	int front;
	int rear;
} Queue;

void initializeQueue(Queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

int isEmptyQueue(Queue* queue) {
	return queue->front % MaxSize == queue->rear % MaxSize;
}

int isFullQueue(Queue* queue) {
	return (queue->rear + 1) % MaxSize == queue->front % MaxSize;
}

void enqueue(Queue* queue, int data) {
	if (isFullQueue(queue)) {
		printf("queue overflow.");
		return;
	}
	queue->arr[queue->rear] = data;
	queue->rear = (queue->rear + 1) % MaxSize;
}

int dequeue(Queue* queue) {
	if (isEmptyQueue(queue)) {
		printf("queue underflow");
		return -1;
	}
	int data = queue->arr[queue->front];
	queue->front = (queue->front + 1) % MaxSize;
	return data;
}

void BFS(int n, int s, int** graph) {
	Queue queue;
	initializeQueue(&queue);

	int count = 0;

	int* flag = (int*)calloc(sizeof(int), n + 1);
	enqueue(&queue, s);
	flag[s] = true;

	while (isEmptyQueue(&queue) != true) {
		int cur = dequeue(&queue);

		for (int i = 1; i <= n; i++) {
			if (graph[cur][i] && !flag[i]) {
				enqueue(&queue, i);
				count++;
				flag[i] = true;
			}
		}
	}

	printf("%d", count);

	free(flag);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int** graph = (int**)calloc(sizeof(int*), (n + 1));
	for (int i = 0; i < n + 1; i++) {
		graph[i] = (int*)calloc(sizeof(int), n + 1);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a][b] = graph[b][a] = true;
	}

	BFS(n, 1, graph);
}