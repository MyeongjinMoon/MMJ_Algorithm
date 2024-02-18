#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int n, k;
    int result;

    cin >> n >> k;

    vector<int> a;

    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        a.push_back(b);
    }

    int sum=0;
    int index = 0;

    for(int i=0;i<k;i++){
        sum += a[i];
    }
    result = sum;
    for(int i=k;i<n;i++){
        sum+=a[i];
        sum-=a[index++];
        if(sum > result){
            result = sum;
        }
    }

    cout << result;
}