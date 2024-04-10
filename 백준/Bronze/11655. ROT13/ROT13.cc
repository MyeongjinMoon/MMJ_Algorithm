#include<iostream>
#include<string>

using namespace std;

string s;

int main() {
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 13;
			if (s[i] > 'Z') {
				s[i] -= 26;
			}
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] + 13 > 'z') {
				s[i] -= 13;
			}
			else {
				s[i] += 13;
			}
		}
	}

	cout << s;

	return 0;
}