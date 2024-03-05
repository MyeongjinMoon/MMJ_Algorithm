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
const int max_n = 1004;
const int INF = 987654321;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char a[max_n][max_n];
int fire_check[max_n][max_n], person_check[max_n][max_n];
int visited[max_n][max_n];
int m, n, l, r, j, k, y, x, ny, nx, t, c;
int x1, x2, y_1, y2;
int sy, sx, ret;
string s;

int sum;
vector<pair<int,int>>v;

bool in(int a, int b) {
    return 0 <= a && a < n && 0 <= b && b < m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, int>> q;

    cin >> n >> m;

    fill(&fire_check[0][0], &fire_check[0][0] + max_n * max_n, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'F') {
                fire_check[i][j] = 1;
                q.push({ i,j });
            }
            else if (a[i][j] == 'J') {
                sy = i;
                sx = j;
            }
        }
    }
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx))
                continue;
            if (fire_check[ny][nx] != INF || a[ny][nx] == '#')
                continue;   //초기값(불이 존재하지 않음)이 아니라면 통과
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    person_check[sy][sx] = 1;
    q.push({ sy,sx });
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (x == m - 1 || y == n - 1 || x == 0 || y == 0) {
            ret = person_check[y][x];   //가장자리 체크
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx))
                continue;
            if (person_check[ny][nx] || a[ny][nx] == '#')
                continue;
            if (fire_check[ny][nx] <= person_check[y][x] +1)
                continue;   //불이 사람보다 빠르거나 같다면 이동 안됨.
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    if (ret != 0)
        cout << ret << "\n";
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}