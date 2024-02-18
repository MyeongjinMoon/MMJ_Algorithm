#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    string a;
    getline(cin, a, '\n');
    for(int i = 0 ; i < a.size();i++){
        if(a[i] >= 65 && a[i] <= 90){
            a[i] += 13;
            if(a[i] > 90){
                a[i] -= 26;
            }
        }
        else if(a[i] >= 97 && a[i] <= 122){
            int c = a[i] + 13;
            if(c > 122){
                a[i] = c - 26;
            }
            else{
                a[i] = c;
            }
        }
    }
    cout << a;
}