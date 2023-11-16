#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;

	scanf("%d", &T);

	for (int Z = 1; Z <= T; Z++) {
		int n, m, k;
		bool pos;

		scanf("%d %d %d", &n, &m, &k);
		int* a = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}

		int index = 0;
		int time = 0;
		while (1) {
			if (index >= n) {
				pos = true;
				break;
			}
			if (time + m > a[index]) {
				pos = false;
				break;
			}
			else {
				index += k;
				time += m;
			}
		}
		
		
		if (pos)
			printf("#%d Possible\n", Z);
		else
			printf("#%d Impossible\n", Z);
	}
}