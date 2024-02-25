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

    int n, result = 0;
    vector<ll> a;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a.push_back(k);
    }

    sort(a.begin(), a.end());

    int val;

    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1, sum;
        val = a[i];

        while (left < right) {
            sum = a[left] + a[right];
            if (sum == val) {
                if (left != i && right != i) {
                    result++;
                    break;
                }
                else if (left == i)
                    left++;
                else if (right == i)
                    right--;
            }
            else if (sum < val) left++;
            else right--;
        }
    }
    cout << result;

    return 0;
}