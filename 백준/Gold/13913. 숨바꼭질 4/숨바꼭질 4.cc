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
#define prev aaa
#define next aaaa

const int MAX = 200004;
int visited[MAX], prev[MAX], n, k, ret, here, cnt, next;
vector<int> v;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    visited[n] = 1;
    q.push(n);
    while (q.size()) {
        here = q.front();
        q.pop();
        if (here == k) {
            ret = visited[k];
            break;
        }
        for (int next : {here - 1, here + 1, here * 2}) {
            if (next >= MAX || next < 0 || visited[next])continue;
            visited[next] = visited[here] + 1;
            prev[next] = here;
            q.push(next);
        }
    }
    for (int i = k; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret - 1 << '\n';
    reverse(v.begin(), v.end());
    for (int i : v)cout << i << ' ';

    return 0;
}