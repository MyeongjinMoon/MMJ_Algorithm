#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;

    while (scanf("%d", &a) != EOF) {
        ll i = 1, ret = 1;

        while (true) {
            if (i % a == 0) {
                cout << ret << '\n';
                break;
            }
            else {
                i = (i * 10 + 1);
                i %= a;
                ret++;
            }
        }
    }
}