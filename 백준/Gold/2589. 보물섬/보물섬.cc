#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
#include <memory.h>

/*
따닥따닥 붙어있을 땐 scanf("1%d")로 하나씩 받기
*/

/*
문제가 분할정복일 경우 재귀 or Stack으로 풀기.
행위 반복, 매개변수는 같음 = 재귀함수 사용
string(1,a[y][x]); * 1은 문자열 길이 a[y][x]는 변환할 문자
*/

using namespace std;
const int max_n = 54;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char a[max_n][max_n];
int visited[max_n][max_n];
int m, n, j, k, y, x, ny, nx, t, c;
int x1, x2, y_1, y2;
string s;

int mx;

vector<vector<int>> chickenList;
vector<pair<int, int>> _home, chicken;
void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>>q;
    q.push({ y,x });
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
            if (visited[ny][nx])continue;
            if (a[ny][nx] == 'W')continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
            mx = max(mx, visited[ny][nx]);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'L') bfs(i, j);
        }
    }

    cout << mx - 1 << "\n";

    return 0;
}