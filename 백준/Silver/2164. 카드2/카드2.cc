#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int N;
queue<int> s;
vector<int> a(N);

int main()
{
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		s.push(i);
	}
	while (s.size() != 1) {
		s.pop();
		s.push(s.front());
		s.pop();
	}
	cout << s.front();
}