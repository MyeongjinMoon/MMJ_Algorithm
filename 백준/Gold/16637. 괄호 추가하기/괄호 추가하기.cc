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

vector<int> num;
vector<char> oper_str;
int n, ret = -987654321;
string s;

int oper(char a, int b, int c) {
    if (a == '+')
        return b + c;
    if (a == '-')
        return b - c;
    if (a == '*')
        return b * c;
}

void go(int here, int _num) {
    if (here == num.size() - 1) {
        ret = max(ret, _num);
        return;
    }
    go(here + 1, oper(oper_str[here], _num, num[here + 1]));

    if (here + 2 <= num.size() - 1) {
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(oper_str[here], _num, temp));
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            num.push_back(s[i] - '0');
        else
            oper_str.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret << "\n";

    return 0;
}