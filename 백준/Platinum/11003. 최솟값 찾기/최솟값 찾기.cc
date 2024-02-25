#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;

    cin >> n >> l;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<pair<int, int>> win;

    for (int i = 0; i < n; i++) {
        while (!win.empty() && win.front().second <= i - l) {
            win.pop_front();
        }

        while (!win.empty() && win.back().first >= a[i]) {
            win.pop_back();
        }

        win.push_back({ a[i], i });

        cout << win.front().first << " ";
    }

    return 0;
}