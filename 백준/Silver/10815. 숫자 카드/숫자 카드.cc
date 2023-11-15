#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

// 비교 함수
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int binarySearch(int arr[], int low, int high, int target) {
	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == target) {
			return 1; // 숫자가 존재함
		}
		else if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return 0; // 숫자가 존재하지 않음
}

int main() {
	int n, m;

	scanf("%d", &n);

	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	qsort(a, n, sizeof(int), compare);

	scanf("%d", &m);
	
	int target;

	// M개의 숫자 확인
	for (int i = 0; i < m; i++) {
		// 상근이가 가지고 있는지 확인할 숫자 입력
		scanf("%d", &target);

		// 이진 탐색으로 확인
		int result = binarySearch(a, 0, n - 1, target);

		// 결과 출력
		printf("%d ", result);
	}

	return 0;
}