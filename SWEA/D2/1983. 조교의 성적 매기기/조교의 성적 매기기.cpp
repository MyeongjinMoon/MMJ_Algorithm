#include <stdio.h>
#include <stdlib.h>

int main(){
	int t;
	scanf("%d", &t);

	for (int TC = 1; TC <= t; TC++) {
		int a, n;

		scanf("%d %d", &a, &n);
		n -= 1;
		
		double* b = (double*)malloc(sizeof(double) * a);
		for (int i = 0; i < a; i++) {
			double c, d, e;
			scanf("%lf %lf %lf", &c, &d, &e);
			b[i] = (double)c * 0.35 + (double)d * 0.45 + (double)e * 0.2;
		}

		for (int i = 0; i < a - 1; i++) {
			for (int j = i + 1; j < a; j++) {
				if (b[i] < b[j]) {
					double temp = b[i];
					b[i] = b[j];
					b[j] = temp;
					if (n == i)
						n = j;
					else if (n == j)

						n = i;
				}
			}
		}
		
		n /= a / 10;

		switch (n)
		{
		case 0: {
			printf("#%d A+\n", TC);
			break;
		}
		case 1: {
			printf("#%d A0\n", TC);
			break;
		}
		case 2: {
			printf("#%d A-\n", TC);
			break;
		}
		case 3: {
			printf("#%d B+\n", TC);
			break;
		}
		case 4: {
			printf("#%d B0\n", TC);
			break;
		}
		case 5: {
			printf("#%d B-\n", TC);
			break;
		}
		case 6: {
			printf("#%d C+\n", TC);
			break;
		}
		case 7: {
			printf("#%d C0\n", TC);
			break;
		}
		case 8: {
			printf("#%d C-\n", TC);
			break;
		}
		case 9: {
			printf("#%d D0\n", TC);
			break;
		}
		default:
			break;
		}
	}

	return 0;
}