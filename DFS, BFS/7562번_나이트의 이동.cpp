#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 500
using namespace std;

int cgo[8] = { 1,1,-1,-1,2,2,-2,-2 };
int rgo[8] = { 2,-2,2,-2,1,-1,1,-1 };
int board[300][300];
int main(void)
{
	int t, n, cur_x, cur_y, to_x, to_y;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%d %d %d %d", &cur_x, &cur_y, &to_x, &to_y);
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + n, MAX);
		}
		if (cur_x == to_x && cur_y == to_y) {
			printf("0\n");
			continue;
		}
		queue<pair<int,int>> q;
		q.push({ cur_x, cur_y });
		board[cur_x][cur_y] = 0;
		bool find = false;
		while (!q.empty() && !find) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = cur.first + cgo[i], ny = cur.second + rgo[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				if (nx == to_x && ny == to_y) { // 목표지점
					find = true;
					board[nx][ny]= board[cur.first][cur.second] + 1;
				}
				else if (board[nx][ny] == MAX) { // 처음 가는 곳
					board[nx][ny] = board[cur.first][cur.second] + 1;
					q.push({ nx,ny });
				}
			}
		}
		printf("%d\n", board[to_x][to_y]);
	}

	return 0;
}
