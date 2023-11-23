#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

/*
qsort 함수는 정렬 대상이 되는 배열의 요소 각각의 크기를 지정해주어야 합니다. 여기서 정렬 대상은 좌표이며, 각 좌표는 x와 y 두 개의 값을 가지고 있습니다. 이를 표현하기 위해서 구조체를 사용한 것입니다.

qsort 함수는 정렬할 때 배열의 요소를 서로 비교하며 위치를 바꾸는데, 이때 비교 연산을 수행하기 위해 정렬 대상인 각 요소의 크기를 알아야 합니다. 구조체를 사용하면 각 좌표가 하나의 단위로 묶여 있기 때문에, 정확한 크기를 지정할 수 있습니다.

2차원 배열을 사용하면 각 행은 단순히 숫자의 배열일 뿐이며, 행 간 비교를 위한 크기 정보가 없습니다. 따라서 qsort 함수에게 어떻게 요소를 비교해야 하는지 알려줄 방법이 없습니다.

요약하자면, qsort 함수에 전달되는 비교 함수가 올바르게 작동하려면 각 요소의 크기를 알아야 하며, 구조체를 사용하는 것은 좌표를 표현하기에 더 자연스럽습니다.
*/
/*
typedef struct Point {
	int x;
	int y;
};

int compare(const void* A, const void* B) {
	Point* p1 = (Point*)A;	// 2차원 배열을 qsort 함수로 사용하기
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
}*/

typedef struct ID {
	int age;
	char a[101];
	int num;
};

int compare(const void* A, const void* B) {
	ID* w1 = (ID*)A;
	ID* w2 = (ID*)B;

	if (w1->age == w2->age) {
		return w1->num - w2->num;
	}
	else {
		return w1->age - w2->age;
	}
}

int main() {
	int n;

	scanf("%d", &n);

	ID* a = (ID*)malloc(sizeof(ID) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &a[i].age, a[i].a);
		a[i].num = i;
	}

	qsort(a, n, sizeof(ID), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", a[i].age, a[i].a);
	}
}