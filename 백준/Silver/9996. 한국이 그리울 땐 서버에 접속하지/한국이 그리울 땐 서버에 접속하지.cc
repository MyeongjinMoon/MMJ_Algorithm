#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
vector<string> split(string input, string delimiter) {
vector<string> ret;
long long pos = 0;
string token = "";
while ((pos = input.find(delimiter)) != string::npos) {
token = input.substr(0, pos);
ret.push_back(token);
input.erase(0, pos + delimiter.length());
}
ret.push_back(input);
return ret;
}


int main() {
    int n;
    string p, d = "*";

    cin >> n;
    cin >> p;

    vector<string> a = split(p,d);

    for(int i =0;i<n;i++){
        string s;
        cin >> s;
        if(s.substr(0,a[0].size()) == a[0] && (p.size() - 1) <= s.size()){
            if(s.substr(s.size() - a[1].size(), a[1].size()) == a[1]){
                cout << "DA" << "\n";
            }
            else{
                cout << "NE" << "\n";
            }
        }
        else{
            cout << "NE" << "\n";
        }
    }

    return 0;
}