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

int lcnt, vcnt;

bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> s;
        if (s == "end") break;
        lcnt = vcnt = 0;
        bool flag = 0;
        bool is_include_v = 0;
        int prev = -1;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i];
            if (isVowel(idx))
                lcnt++, vcnt = 0, is_include_v = true;
            else
                vcnt++, lcnt = 0;
            
            if (vcnt == 3 || lcnt == 3)
                flag = 1;

            if (i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o'))
                flag = 1;
            prev = idx;
        }
        if (is_include_v == 0)
            flag = 1;
        if (flag)
            cout << "<" << s << ">" << " is not acceptable.\n";
        else
            cout << "<" << s << ">" << " is acceptable.\n";
    }

    return 0;
}