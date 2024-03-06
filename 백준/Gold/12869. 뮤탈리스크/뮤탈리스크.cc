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
const int max_n = 64;
const int INF = 987654321;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int a[3];
int dp[max_n][max_n][max_n], visited[max_n][max_n][max_n];
int n;
string s;

int _a[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,1,9},
    {3,9,1},
    {1,3,9},
    {1,9,3}
};

struct A {
    int a, b, c;
};

queue<A>q;
int solve(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({ a,b,c });
    while (q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (visited[0][0][0])break;
        for (int i = 0; i < 6; i++) {
            // 배열의 index값 음수 방지
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            if (visited[na][nb][nc])continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({ na,nb,nc });
        }
    }
    return visited[0][0][0] - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(a[0], a[1], a[2]) << "\n";

    return 0;
}