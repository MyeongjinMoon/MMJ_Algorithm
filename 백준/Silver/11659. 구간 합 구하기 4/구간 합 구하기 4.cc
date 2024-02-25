#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    
    cin >> n >> m;
    
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (i > 0)
            a.push_back(b + a[i - 1]);
        else
            a.push_back(b);
    }
    for (int i = 0; i < m; i++) {
        int x, z;
        cin >> x >> z;

        if (x == 1) {
            cout << a[z - 1] << '\n';
        }
        else {
            cout << a[z - 1] - a[x - 2] << '\n';
        }
    }
}