#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a, point;
string pa, p_f, p_b;
string s, s_begin, s_end;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a;
    cin >> pa;

    point = pa.find("*");

    p_f = pa.substr(0, point);
    p_b = pa.substr(point + 1);

    for (int i = 0; i < a; i++) {
        cin >> s;

        if ((p_f.size() + p_b.size()) > s.size()) {
            cout << "NE" << "\n";
            continue;
        }

        s_begin = s.substr(0, point);
        s_end = s.substr(s.size() - p_b.size());

        if (s_begin == p_f && s_end == p_b) {
            cout << "DA" << "\n";
        }
        else {
            cout << "NE" << "\n";
        }
    }

    return 0;
}
