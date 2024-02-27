#include <stdio.h>
#include <stdlib.h>

#define MAX 100

#pragma warning(disable : 4996)

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point queue[MAX * MAX];
    int front, rear;
} Queue;

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Point p) {
    q->queue[q->rear++] = p;
}

Point dequeue(Queue* q) {
    return q->queue[q->front++];
}

int bfs() {
    Queue q;
    initQueue(&q);

    Point start = { 0, 0 };
    enqueue(&q, start);

    visited[0][0] = 1;

    while (!isEmpty(&q)) {
        Point current = dequeue(&q);

        if (current.x == M - 1 && current.y == N - 1) {
            return visited[N - 1][M - 1];
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[ny][nx] && map[ny][nx] == 1) {
                Point next = { nx, ny };
                visited[ny][nx] = visited[current.y][current.x] + 1;
                enqueue(&q, next);
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    printf("%d\n", bfs());

    return 0;
}
