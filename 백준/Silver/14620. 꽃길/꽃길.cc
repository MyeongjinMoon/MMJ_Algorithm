#include <iostream>

using namespace std;

int n, ret = 987654321;
int dy[4] = { 0,-1,0,1 }, dx[4] = { -1,0,1,0 };
int v[10][10], p[10][10];

int setFlower(int i, int j) {
	v[i][j] = 1;
	int s = p[i][j];
	for (int a = 0; a < 4; a++) {
		int ny = i + dy[a];
		int nx = j + dx[a];
		v[ny][nx] = 1;
		s += p[ny][nx];
	}
	return s;
}
void eraseFlower(int i, int j) {
	v[i][j] = 0;
	v[i - 1][j] = 0;
	v[i][j - 1] = 0;
	v[i + 1][j] = 0;
	v[i][j + 1] = 0;
}

bool check(int y, int x) {
	if (v[y][x])return 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx])
			return 0;
	}
	return 1;
}

void flower(int cnt, int hap) {
	if (cnt == 3) {
		ret = min(ret, hap);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j)) {
				flower(cnt + 1, hap + setFlower(i, j));
				eraseFlower(i, j);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	flower(0, 0);
	cout << ret;
}