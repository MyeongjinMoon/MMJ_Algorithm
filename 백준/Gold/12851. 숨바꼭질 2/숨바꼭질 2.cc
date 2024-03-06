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

const int MAX = 200000;
int visited[MAX + 4];
long long cnt[MAX + 4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (n == m) {
        puts("0");
        puts("1");
        return 0;
    }
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : {now - 1, now + 1, now * 2}) {
            if (0 <= next && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];  //경우의 수는 더하기로 표현(이부분 좀 이해하기 어려움)
                }
                else if (visited[next] == visited[now] + 1) {   //최단 거리일 경우 + 1
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';

    return 0;
}