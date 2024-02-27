#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>

/*
따닥따닥 붙어있을 땐 scanf("1%d")로 하나씩 받기
*/

using namespace std;
const int max_n = 101;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int a[max_n][max_n], visited[max_n][max_n];
int m, n, k, y, x, ny, nx, t;
int x1, x2, y_1, y2;

vector<int> ret;

int dfs(int y, int x) {
    visited[y][x] = 1;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] == 1)continue;
        if (a[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> x1 >> y_1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y_1; y < y2; y++) {
                a[y][x] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 1 && visited[i][j] == 0) {
                ret.push_back(dfs(i, j));
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (int i : ret) {
        cout << i << " ";
    }

    return 0;
}