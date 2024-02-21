#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned long long ll;

ll go(ll a, ll b, ll c){
    if(b==1)
        return a % c;
    ll ret = go(a, b/2, c);
    ret= (ret * ret) % c;
    if(b%2)
        ret = (ret * a) % c;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    ll result;

    cin >> a >> b >> c;

    result = go(a,b, c);

    cout << result;
    
    return 0;
}