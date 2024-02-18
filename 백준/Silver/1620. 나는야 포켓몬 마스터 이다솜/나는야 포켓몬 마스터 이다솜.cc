#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    unordered_map<string, int> name_to_idx;
    unordered_map<int, string> idx_to_name;
    
    for (int i = 1; i <= N; ++i) {
        string name;
        cin >> name;
        name_to_idx[name] = i;
        idx_to_name[i] = name;
    }
    
    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;
        
        if (isdigit(query[0])) { // If query starts with a digit, it's a number
            int idx = stoi(query);
            cout << idx_to_name[idx] << "\n";
        } else { // Otherwise, it's a name
            cout << name_to_idx[query] << "\n";
        }
    }
    
    return 0;
}
