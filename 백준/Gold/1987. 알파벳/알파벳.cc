#include<iostream>

using namespace std;

int R, C, ret, cnt;
char a[21][21];
int visited[26];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,-1,0,1 };

void go(int y, int x, int cnt) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
		if (visited[(int)a[ny][nx] - 'A'])continue;
		visited[(int)a[ny][nx] - 'A'] = 1;
		go(ny, nx, cnt + 1);
		visited[(int)a[ny][nx] - 'A'] = 0;
	}
	return;
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
		}
	}
	visited[(int)a[0][0] - 'A'] = 1;
	go(0, 0, 1);
	cout << ret;
}