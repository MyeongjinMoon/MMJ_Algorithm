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

/*
문제가 분할정복일 경우 재귀 or Stack으로 풀기.
행위 반복, 매개변수는 같음 = 재귀함수 사용
string(1,a[y][x]); * 1은 문자열 길이 a[y][x]는 변환할 문자
*/

using namespace std;
const int max_n = 101;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int a[max_n][max_n], visited[max_n][max_n];
int m, n, j, k, y, x, ny, nx, t;
int x1, x2, y_1, y2;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ret = 0; int l = 1;

    cin >> n >> m >> j;

    for (int i = 0; i < j; i++) {
        int temp;
        int r = l + m - 1;

        cin >> temp;

        if (l <= temp && r >= temp) continue;
        else {
            if (temp > r) {
                int dif = temp - r;
                ret += dif;
                l += dif;
            }
            else if (temp < l) {
                int dif = temp - l;
                ret -= dif;
                l += dif;
            }
        }
    }
    cout << ret;
    return 0;
}