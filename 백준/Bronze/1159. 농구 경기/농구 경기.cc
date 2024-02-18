#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    int a;
    int result[26] = {0};
    int flag=0;
    cin >> a;

    for(int i=0;i<a;i++){
        string b;
        cin >> b;
        result[b[0]-97]++;
    }
    for(int i =0;i<26;i++){
        if(result[i] > 4){
            cout << (char)(i + 97);
            flag++;
        }
    }
    if(!flag){
        cout<<"PREDAJA";
    }
}