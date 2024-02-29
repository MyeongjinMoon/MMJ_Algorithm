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

using namespace std;
const int max_n = 101;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
//int a[max_n][max_n], visited[max_n][max_n];
int m, n, j, k, y, x, ny, nx, t, c;
int x1, x2, y_1, y2;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<pair<int, int>> ret;
    for (int i = 0; i < n; i++) {
        cin >> m;
        ret.push_back({ m,i });
    }

    sort(ret.begin(), ret.end());

    int ans = -1;
    for (int i = 0; i < n;i++) {
        if (ans < ret[i].second - i)
            ans = ret[i].second - i;
    }
    cout << ans + 1;

    return 0;
}