#include <iostream>

using namespace std;

int n, k, Max;
int r;
int a[100000];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i < k) {
			r += a[i];
		}
	}
	Max = r;
	for (int i = k; i < n; i++) {
		r += a[i] - a[i - k];
		if (r > Max)
			Max = r;
	}
	cout << Max;
	return 0;
}