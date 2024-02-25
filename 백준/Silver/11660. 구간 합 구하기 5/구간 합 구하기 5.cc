#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    int** a = (int**)calloc(sizeof(int*), (n + 1));
    for (int i = 0; i <= n; i++) {
        a[i] = (int*)calloc(sizeof(int), (n + 1));
        if (i != 0) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        int l, m, n, k;
        int result;

        cin >> l >> m >> n >> k;
        
        result = a[n][k] - a[n][m - 1] - a[l - 1][k] + a[l - 1][m - 1];

        cout << result << '\n';
    }
}