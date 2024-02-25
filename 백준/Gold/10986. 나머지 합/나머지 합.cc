#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long mod[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    long long s = 0, cnt = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> t;
        s += t;
        mod[s % m]++;
    }

    for (int i = 0; i <= m; i++) {
        cnt += ((mod[i] * (mod[i] - 1)) / 2);
    }

    cout << mod[0] + cnt;

    return 0;
}