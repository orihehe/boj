/*
경로에 기물이 있다면 지나가지 못한다고 설명이 되어있지만 본인, 왕 외의
기물이 주어지지않아 뭐지 싶었는데 왕이 경로에 있으면 넘어가지 못하는 경우가 있었다.
*/

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int board[10][9];
bool visited[10][9];
//북동남서
int rgo[8] = { -3,-3,-2,2,3,3,-2,2 };
int cgo[8] = { 2,-2,3,3,2,-2,-3,-3 };
int rgone[4] = { -1,0,1,0 };
int cgone[4] = { 0,1,0,-1 };
int main() {
	int r1, c1, r2, c2, cnt=0, size=1;
	bool meet = false;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	queue<pair<int,int>> q;
	q.push({ r1,c1 });
	visited[r1][c1] = true;
	while (!q.empty()) {
		if (size == 0) {
			size = q.size();
			cnt++;
		}
		pair<int, int> next = q.front();
		if (next.first == r2 && next.second == c2) {
			meet = true;
			break;
		}
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = next.first;
			int nc = next.second;
			if (nr + rgone[i / 2] == r2 && nc + cgone[i / 2] == c2)
				continue;
			if (nr + rgone[i / 2] + rgo[i] / 2 == r2 && nc + cgone[i / 2]+ cgo[i] / 2 == c2)
				continue;
			nr += rgo[i];
			nc += cgo[i];
			if (nc < 0 || nr < 0 || nc >= 9 || nr >= 10)
				continue;
			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({ nr,nc });
			}
		}
		size--;
	}
	if (meet) {
		printf("%d", cnt);
	}
	else printf("-1");

	return 0;
}