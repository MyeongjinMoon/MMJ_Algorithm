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
int m, n, k, y, x, ret = 1, ny, nx, t;

void dfs(int y, int x, int d) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
        if (a[ny][nx] > d && !visited[ny][nx]) {
            dfs(ny, nx, d);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int d = 1; d < max_n;d++) {
        fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > d && !visited[i][j]) {
                    dfs(i, j, d);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }

    cout << ret << "\n";

    return 0;
}