#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int R, C, day;
int swanY, swanX, y, x;
string s;
char a[1501][1501];
int visited[1501][1501], visited_swan[1501][1501];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,-1,0,1 };

queue<pair<int, int>> waterQ, swanQ, swan_tempQ, water_tempQ;

void Qclear(queue<pair<int, int>>& q) {	// Queue를 비우는 함수
	queue<pair<int, int>> empty;
	swap(q, empty);	//pop무한루프보다 더 빠름
}

void water_melting() {
	while (waterQ.size()) {
		tie(y, x) = waterQ.front();
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
				continue;
			if (a[ny][nx] = 'X') {
				visited[ny][nx] = 1;
				water_tempQ.push({ ny,nx });
				a[ny][nx] = '.';
			}
		}
	}
}

int move_swan() {
	while (swanQ.size()) {
		tie(y, x) = swanQ.front();
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])
				continue;
			visited_swan[ny][nx] = 1;
			if (a[ny][nx] == '.')
				swanQ.push({ ny,nx });
			else if (a[ny][nx] == 'X')
				swan_tempQ.push({ ny,nx });
			else if (a[ny][nx] == 'L')
				return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'L') {
				swanY = i, swanX = j;
			}
			if (a[i][j] == '.'||a[i][j]=='L') {
				visited[i][j] = 1, waterQ.push({ i,j });
			}
		}
	}

	swanQ.push({ swanY, swanX });
	visited_swan[swanY][swanX] = 1;
	while (true) {
		if (move_swan())break;
		water_melting();
		waterQ = water_tempQ;
		swanQ = swan_tempQ;
		Qclear(water_tempQ);
		Qclear(swan_tempQ);
		day++;
	}
	cout << day << "\n";

	return 0;
}