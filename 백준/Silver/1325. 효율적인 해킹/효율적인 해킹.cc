#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <map>

using namespace std;

int m, n, a, b;
int visited[10001], dp[10001], mx;
vector<int> v[10001];

int dfs(int here) {
    visited[here] = 1;
    int ret = 1;
    for (int there : v[here]) {
        if (visited[there])
            continue;
        ret += dfs(there);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }
    for (int i = 1; i <= n; i++){
        if (mx == dp[i])
            cout << i << " ";
    }

    return 0;
}