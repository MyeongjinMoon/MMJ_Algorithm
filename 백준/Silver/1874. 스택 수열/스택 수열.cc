#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> a;
    vector<char> r;
    int cnt = 1;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        while (cnt <= temp) {
            a.push(cnt);
            cnt++;
            r.push_back('+');
        }

        if (a.top() == temp) {
            a.pop();
            r.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << '\n';
    }

    return 0;
}