#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int a[26];
char b[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> b;

	for (int i = 0; i < strlen(b); i++) {
		a[b[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}

	return 0;
}