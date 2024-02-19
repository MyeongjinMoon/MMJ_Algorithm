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

    int t;
    string a, b;
    

    cin >> t;

    for(int i= 0;i<t;i++){
        int n;
        map<string, int> _m;
        
        cin >> n;
        
        for(int j = 0;j < n;j++){
            cin >> a >> b;
            _m[b]++;
        }

        long long ret = 1;
        for(auto c : _m){
            ret *= ((long long)c.second + 1);
        }
        ret--;
        cout << ret << "\n";
    }
}