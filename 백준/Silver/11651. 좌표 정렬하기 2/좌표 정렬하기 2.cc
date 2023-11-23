#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct Point {
	int x;
	int y;
};

int compare(const void* A, const void* B) {
	Point* p1 = (Point*)A;
	Point* p2 = (Point*)B;

	if (p1->y == p2->y) {
		return p1->x - p2->x;
	}
	else {
		return p1->y - p2->y;
	}
}

int main() {
	int n;

	scanf("%d", &n);

	Point* a = (Point*)malloc(sizeof(Point) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}

	qsort(a, n, sizeof(Point), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
}