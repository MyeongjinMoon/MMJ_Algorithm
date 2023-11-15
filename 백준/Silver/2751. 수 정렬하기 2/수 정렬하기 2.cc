#include<stdio.h>
#include <math.h>
#include <stdlib.h>

#pragma warning(disable:4996)

void divide(int* M, int left, int right);
void merge(int* M, int left, int right, int boundary);

int main() {
	int length;

	scanf("%d", &length);

	int* M = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &M[i]); // 0부터 9999까지의 랜덤한 값
	}

	divide(M, 0, length - 1);

	for (int i = 0; i < length; i++) {
		printf("%d\n", M[i]);
	}
}

void divide(int* M, int left, int right) {
	int boundary = ceil(((float)(left + right) / 2));

	if (right - left > 0)
		divide(M, left, (left + right) / 2);

	if (right - left > 0)
		divide(M, ceil(((float)(left + right) / 2)), right);

	if (right >= boundary)
		merge(M, left, right, boundary);
}

void merge(int* M, int left, int right, int boundary) {
	int* Merge = (int*)malloc(sizeof(int) * ((right - left) + 1));
	int k = 0;

	int i = left;
	while (k < right - left + 1) {
		if (boundary > right) {
			for (; k < right - left + 1;)
				Merge[k++] = M[i++];
			break;
		}
		else if (i >= ceil(((float)(left + right) / 2))) {
			for (; k < right - left + 1;)
				Merge[k++] = M[boundary++];
			break;
		}
		else if (M[i] > M[boundary])
			Merge[k++] = M[boundary++];

		else
			Merge[k++] = M[i++];
	}

	k = 0;

	for (int i = left; i <= right;)
		M[i++] = Merge[k++];

	free(Merge);
}