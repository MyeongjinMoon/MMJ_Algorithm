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
int a[max_n][max_n];
int visited[max_n][max_n];
int m, n, l, r, j, k, y, x, ny, nx, t, c;
int x1, x2, y_1, y2;
string s;

int sum;
vector<pair<int,int>>v;

void dfs(int y, int x, vector<pair<int, int>>& v) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx])continue;
        if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
            visited[ny][nx] = 1;
            v.push_back({ ny,nx });
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({ i,j });
                    sum = a[i][j];
                    dfs(i, j, v);
                    if (v.size() == 1)continue;
                    for (pair<int, int>b : v) {
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag)break;
        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}