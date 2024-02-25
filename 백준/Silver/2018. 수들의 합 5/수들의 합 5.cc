#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i = 1, j = 1;
    int result = 0, temp = 0;

    cin >> n;


    while (i < n) {
        if (temp <= n) {
            temp += i;
            i++;
        }
        else if(temp > n){
            temp -= j;
            j++;
        }
        if (temp == n) {
            result++;
        }
    }
    
    cout << result + 1;
}