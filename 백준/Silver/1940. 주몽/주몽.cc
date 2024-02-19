#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> r;
    cin >> n >> m;
    
    int results = 0;

    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        r.push_back(a);
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((r[i] + r[j]) == m){
                results++;
            }
        }
    }

    cout << results;

    return 0;
}