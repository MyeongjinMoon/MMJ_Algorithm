#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma warning(disable : 4996)

int main() {
	char Pelin[51];
	int Ap[26] = { 0 };

	scanf("%s", Pelin);

	int n = 0;
	while (Pelin[n] != '\0') {
		Ap[Pelin[n] - 65]++;
		n++;
	}

	char* gift = (char*)malloc(sizeof(char) * n);
	int odd = -1;

	
	for (int i = 0; i < 26; i++) {

		if (Ap[i] % 2 == 1) {

			if (odd > -1) {
				odd = -2;
				break;
			}
			else {
				odd = i;
			}
		}
	}

	int k = 0;
	int i = 0;

	if (odd > -2) {
		while (i > -1) {
			if (Ap[i] > 0) {
				if (n % 2 == 1 && k == n / 2) {
					gift[k] = odd + 65;
					k++;
					Ap[odd]--;
					i = 25;
				}
				else if (k < n / 2) {
					int j = 0;
					for (; j < Ap[i] / 2; j++) {
						gift[k] = i + 65;
						k++;
					}
					if (k >= n / 2) {
						Ap[i] -= j;
					}
					else {
						Ap[i] -= j;
						i++;
					}
				}
				else {
					for (int j = 0; j < Ap[i]; j++) {
						gift[k] = i + 65;
						k++;
					}
					i--;
				}
			}
			else {
				if (k < n / 2)
					i++;
				else if (k == n / 2)
					i = odd;
				else
					i--;
			}
		}

		for (int i = 0; i < n; i++)
			printf("%c", gift[i]);
	}
	else {
		printf("I'm Sorry Hansoo");
	}	
}