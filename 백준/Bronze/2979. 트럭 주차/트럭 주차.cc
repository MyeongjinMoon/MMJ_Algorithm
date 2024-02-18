#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a[3];
    int d[101] = {0};
    int result = 0;

    cin >> a[0] >> a[1] >> a[2];

    for(int i=0;i<3;i++){
        int e,f;
        cin >> e >> f;
        for(int j=e; j<f;j++){
            d[j]++;
        }
    }
    for(int i = 1; i<101;i++){
        result += a[d[i]-1] * d[i];
    }
    cout << result;
    
    return 0;
}