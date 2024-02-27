#include <stdio.h>
#include <stdlib.h>

#define MAX 50

#pragma warning(disable : 4996)

int* result;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point queue[MAX * MAX];
    int front, rear;
} Queue;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int static compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void show(int visited[MAX][MAX], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%4d ", visited[i][j]);
        }
        printf("\n");
    }
}

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front % (MAX * MAX) == q->rear % (MAX * MAX);
}

int isFull(Queue* q) {
    return (q->rear + 1) % (MAX * MAX) == q->front % (MAX * MAX);
}

void enqueue(Queue* q, Point p) {
    if (isFull(q)) {
        printf("queue overflow.");
        return;
    }
    q->queue[q->rear] = p;
    q->rear = (q->rear + 1) % (MAX * MAX);
}

Point dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("queue underflow");
        return { 0,0 };
    }
    return q->queue[q->front++];
}

int bfs(int** map, int N, int M) {
    Queue q;
    initQueue(&q);

    int block = 0;

    int** visited = (int**)calloc(sizeof(int*), N);
    for (int i = 0; i < N; i++) {
        visited[i] = (int*)calloc(sizeof(int), M);
    }

    Point start;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (map[x][y] == 1 && visited[x][y] == 0) {

                start = { x, y };
                enqueue(&q, start);
                visited[x][y] = ++block;

                while (!isEmpty(&q)) {
                    Point current = dequeue(&q);

                    for (int i = 0; i < 4; i++) {
                        int nx = current.x + dx[i];
                        int ny = current.y + dy[i];

                        if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && map[nx][ny] == 1) {
                            Point next = { nx, ny };
                            visited[nx][ny] = visited[current.x][current.y];
                            int view = visited[nx][ny];
                            enqueue(&q, next);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        free(visited[i]);
    }

    return block;
}

int main() {
    int c;
    int N, M, K;

    scanf("%d", &c);

    result = (int*)malloc(sizeof(int) * c);

    for (int i = 0; i < c; i++) {
        scanf("%d %d %d", &M, &N, &K);

        int** map = (int**)calloc(sizeof(int*), N);
        for (int i = 0; i < N; i++) {
            map[i] = (int*)calloc(sizeof(int), M);
        }

        for (int i = 0; i < K; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            map[b][a] = 1;
        }

        result[i] = bfs(map, N, M);

        free(map);
    }

    for (int i = 0; i < c; i++)
        printf("%d\n", result[i]);

    return 0;
}
