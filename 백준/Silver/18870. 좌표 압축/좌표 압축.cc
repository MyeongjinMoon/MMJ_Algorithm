#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Element;

// 비교 함수
int compare(const void *a, const void *b) {
    return ((Element *)a)->value - ((Element *)b)->value;
}

int main() {
    int n;
    scanf("%d", &n);

    Element *arr = (Element *)malloc(sizeof(Element) * n);

    // 수열 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    // 수열 정렬
    qsort(arr, n, sizeof(Element), compare);

    int *result = (int *)malloc(sizeof(int) * n);
    int prevValue = arr[0].value;
    int compressedValue = 0;

    // 압축된 좌표 구하기
    for (int i = 0; i < n; i++) {
        if (arr[i].value != prevValue) {
            compressedValue++;
            prevValue = arr[i].value;
        }
        result[arr[i].index] = compressedValue;
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    // 동적 할당된 메모리 해제
    free(arr);
    free(result);

    return 0;
}
