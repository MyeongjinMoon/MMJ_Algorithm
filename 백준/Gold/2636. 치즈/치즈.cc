#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>

/*
따닥따닥 붙어있을 땐 scanf("1%d")로 하나씩 받기
*/

/*
문제가 분할정복일 경우 재귀 or Stack으로 풀기.
행위 반복, 매개변수는 같음 = 재귀함수 사용
string(1,a[y][x]); * 1은 문자열 길이 a[y][x]는 변환할 문자
*/

/*
문자열 custom_operator
 - 문자열은 앞에서부터 아스키코드 값으로 비교하기 때문에 sort할 때 custom_operator
 를 사용해야 함.

bool cmp(string a, string b) {
    if (a.size() == b.size())   //2순위 사이즈 같을경우 내용을 비교
        return a < b;
    return a.size() < b.size(); //1순위 사이즈 비교
}
*/


using namespace std;

const int max_n = 104;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int a[max_n][max_n], visited[max_n][max_n];
int m, n, j, k, y, x, ny, nx, t, c;
int x1, x2, y_1, y2;
int o, A, B, asum, bsum;
string s, prev_;
int ret, cnt, cnt2;

vector<pair<int, int>> v;

void go(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x] == 1) {
        v.push_back({ y,x });
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
            continue;
        go(ny, nx);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
        v.clear();
        go(0, 0);
        cnt2 = v.size();
        for (pair<int, int> b : v) {
            a[b.first][b.second] = 0;
        }
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0)
                    flag = 1; 
            }
        }
        cnt++;
        if (!flag)
            break;
    }
    cout << cnt << '\n' << cnt2;

    return 0;
}