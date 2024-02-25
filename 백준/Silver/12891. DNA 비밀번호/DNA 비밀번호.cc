#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int ad[2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, result = 0;;
    string ACGT;
    int check[4];

    cin >> n >> m;

    cin >> ACGT;

    cin >> check[0] >> check[1] >> check[2] >> check[3];

    int left = 0, right = m - 1;
    int a = 0, c = 0, g = 0, t = 0;
    for (int i = left; i <= right; i++) {
        if (ACGT[i] == 'A') {
            a++;
        }
        else if (ACGT[i] == 'C') {
            c++;
        }
        else if (ACGT[i] == 'G') {
            g++;
        }
        else if (ACGT[i] == 'T') {
            t++;
        }
    }
    if (a >= check[0] && c >= check[1] && g >= check[2] && t >= check[3]) {
        result++;
    }
    while (right != n - 1) {
        right++;
        if (ACGT[right] == 'A') {
            a++;
        }
        else if (ACGT[right] == 'C') {
            c++;
        }
        else if (ACGT[right] == 'G') {
            g++;
        }
        else if (ACGT[right] == 'T') {
            t++;
        }
        if (ACGT[left] == 'A') {
            a--;
        }
        else if (ACGT[left] == 'C') {
            c--;
        }
        else if (ACGT[left] == 'G') {
            g--;
        }
        else if (ACGT[left] == 'T') {
            t--;
        }
        left++;
        if (a >= check[0] && c >= check[1] && g >= check[2] && t >= check[3]) {
            result++;
        }
    }

    cout << result;

    return 0;
}