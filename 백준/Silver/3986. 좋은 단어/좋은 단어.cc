#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        vector<char> s;
        string a;
        cin >> a;

        for(int j = 0; j < a.size(); j++){
            s.push_back(a[j]);
        }
        if(s.size() % 2 == 1){
            continue;
        }
        int pos = 0;

        while(s.size() != 0){
            if(pos == s.size()){
                result--;
                break;
            }
            if(s[pos] == s[pos + 1] && s.size() > pos + 1){
                s.erase(s.begin() + pos);
                s.erase(s.begin() + pos);
            }
            else if(pos > 0 && s[pos] == s[pos - 1]){
                s.erase(s.begin() + pos);
                s.erase(s.begin() + pos-- - 1);
            }
            else{
                pos++;
            }
        }
        result++;
    }

    cout << result;
    
    return 0;
}