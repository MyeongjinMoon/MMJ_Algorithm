#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define prev aaa

const int MAX = 200004;
int visited[MAX], prev[MAX];
int n, m, ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	queue<int> q;
	cin >> n >> m;
	visited[n] = 1;
	q.push(n);

	while (true) {
		int here = q.front();
		q.pop();
		if (here == m) {
			ret = visited[here];
			break;
		}
		for (int i : {here - 1, here + 1, here * 2}) {
			if (i >= 0 && i <= MAX && !visited[i]) {
				q.push(i);
				visited[i] = visited[here] + 1;
				prev[i] = here;
			}
		}
	}

	vector<int> v;
	for (int i = m; i != n; i = prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);
	cout << ret - 1 << "\n";
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

	return 0;
}