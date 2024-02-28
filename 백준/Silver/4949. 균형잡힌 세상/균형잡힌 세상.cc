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

const int max_n = 101;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
//int a[max_n][max_n], visited[max_n][max_n];
int a, m, n, j, k, y, x, ny, nx, t, c;
int x1, x2, y_1, y2;
int o, A, B, asum, bsum;
string s, prev_;

bool check(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(')
            stk.push(c);
        else {
            if (!stk.empty())
                stk.pop();
            else
                return false;
        }
    }
    return stk.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        string s;
        getline(cin, s);
        if (s == ".")
            break;
        stack<int> stk;
        bool check = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (stk.size() == 0 || stk.top() == '[') {
                    check = false;
                    break;
                }
                else
                    stk.pop();
            }
            if (s[i] == ']') {
                if (stk.size() == 0 || stk.top() == '(') {
                    check = false;
                    break;
                }
                else
                    stk.pop();
            }
            if (s[i] == '(')
                stk.push(s[i]);
            if (s[i] == '[')
                stk.push(s[i]);
        }
        if (check && stk.size() == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}