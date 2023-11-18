#include <stdio.h>

int main() {
	for (int TC = 1; TC <= 10; TC++) {
		int Box[100];
		int a, flag = 1;

		scanf("%d", &a);

		for (int i = 0; i < 100; i++) {
			scanf("%d", &Box[i]);
		}

		int min_index, max_index;

		for (int i = 0; i <= a; i++) {
			int min = 101, max = -1;
			for (int j = 0; j < 100; j++) {
				if (min > Box[j]) {
					min = Box[j];
					min_index = j;
				}
				if (max < Box[j]) {
					max = Box[j];
					max_index = j;
				}
			}
			if ((max - min) == 0 || (max - min) == 1) {
				printf("#%d %d\n", TC, max - min);
				flag = 0;
				break;
			}
			if (i == a) {
				printf("#%d %d\n", TC, max - min);
				flag = 0;
			}
			else {
				Box[max_index]--;
				Box[min_index]++;
			}
		}
	}
}