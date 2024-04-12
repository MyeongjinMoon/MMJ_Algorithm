#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n, k, ret = 1876543210;
int a[50][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	if (k == 1) {

		for (int x = 0; x < n; x++) {

			int max = 0;

			for (int h = 0; h < n; h++) {
				if (h == x)
					continue;

				int temp;

				temp = abs(a[h][0] - a[x][0]) + abs(a[h][1] - a[x][1]);
				if (temp > max)
					max = temp;
			}

			if (max < ret)
				ret = max;
		}
		
	}
	else if (k == 2) {
		for (int x = 0; x < n; x++) {

			for (int y = x + 1; y < n; y++) {

				int max = 0;

				for (int h = 0; h < n; h++) {
					if (h == x || h == y)
						continue;

					int temp, temp1, temp2;

					temp1 = abs(a[h][0] - a[x][0]) + abs(a[h][1] - a[x][1]);
					temp2 = abs(a[h][0] - a[y][0]) + abs(a[h][1] - a[y][1]);

					if (temp1 > temp2)
						temp = temp2;
					else
						temp = temp1;

					if (temp > max)
						max = temp;
				}

				if (max < ret)
					ret = max;
			}
		}
	}
	else if (k == 3) {

		for (int x = 0; x < n; x++) {

			for (int y = x + 1; y < n; y++) {

				for (int z = y + 1; z < n; z++) {

					int max = 0;

					for (int h = 0; h < n; h++) {
						if (h == x || h == y || h == z)
							continue;

						int temp, temp1, temp2, temp3;

						temp1 = abs(a[h][0] - a[x][0]) + abs(a[h][1] - a[x][1]);
						temp2 = abs(a[h][0] - a[y][0]) + abs(a[h][1] - a[y][1]);
						temp3 = abs(a[h][0] - a[z][0]) + abs(a[h][1] - a[z][1]);

						if (temp1 > temp2) {
							if (temp2 > temp3)
								temp = temp3;
							else
								temp = temp2;
						}
						else {
							if (temp1 > temp3)
								temp = temp3;
							else
								temp = temp1;
						}

						if (temp > max)
							max = temp;
					}

					if (max < ret)
						ret = max;
				}
			}
		}
	}

	cout << ret;
	
	return 0;
}