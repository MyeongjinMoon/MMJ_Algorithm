#include <stdio.h>
#include <math.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 1; TC <= t; TC++) {
		int a[10];
		for (int i = 0; i < 10; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 10; j++) {
				if (a[i] < a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		int b = 0;
		for(int i=1;i<9;i++){
			b += a[i];
		}
		printf("#%d %.f\n", TC, round((float)b / 8));
	}
}