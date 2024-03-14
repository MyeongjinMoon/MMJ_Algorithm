#include<iostream>

using namespace std;
const int INF = 987654321;
int n, m, h, a, b, ret = INF, visited[34][34];

bool check() {	//i번째 출발지점에서 i번째 도착지점으로 갈 수 있는지 확인하는 함수
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][start])start++;	//오른쪽 사다리가 있을 때 오른쪽으로 이동
			else if (visited[j][start - 1])start--;	//왼쪽 사다리가 있을 때 왼쪽으로 이동
		}
		if (start != i)return false;
	}
	return true;
}

void go(int here, int cnt) {
	if (cnt > 3 || cnt >= ret)return;
	if (check()) {
		ret = min(ret, cnt);
		return;
	}
	for (int i = here; i <= h; i++) {	//사다리를 놓는 로직
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
				continue;	//사다리가 이어서 못놓게하는 로직
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b ; visited[a][b] = 1;
	}
	go(1, 0);
	cout << ((ret == INF) ? -1 : ret) << "\n";
	return 0;
}