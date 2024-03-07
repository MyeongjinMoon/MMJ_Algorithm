#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 500000;
int visited[2][MAX];
int n, m, ok, turn = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	 
	queue<int> q;

	cin >> n >> m;
	if (n == m) {
		cout << "0\n";
		return 0;
	}
	visited[0][n] = 1;
	q.push(n);

	while (q.size()) {
		m += turn;
		if (m > MAX)break;
		if (visited[turn % 2][m]) {
			ok = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front(); q.pop();
			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx<0 || nx>MAX || visited[turn % 2][nx])continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if (nx == m) {
					ok = 1; break;
				}
				q.push(nx);
			}
			if (ok)break;
		}
		if (ok)break;
		turn++;
	}

	if (ok)cout << turn << "\n";
	else cout << -1 << "\n";

	return 0;
}