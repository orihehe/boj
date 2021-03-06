/*
방향이 바뀌었을 때 현재 머리 위치의 방향을 배열에서 안 바꿔 
꼬리가 배열 밖으로 나가 런타임 에러가 났다. ㅠㅠ 
*/

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int board[101][101];
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };
struct snake {
	int r, c;
};

int main() {
	int n, k, l, r, c, cnt = 0, dir;
	snake tail, head; // t - 꼬리좌표 h - 머리좌표
	queue<pair<int, char>> q;
	scanf("%d %d", &n, &k);
	//사과 위치 1로 표시
	while (k--) {
		scanf("%d %d", &r, &c);
		board[r][c] = -1;
	}
	// 뱀 몸통 방향+1으로 표시
	board[1][1] = 2;
	tail = { 1,1 }; head = { 1,1 };
	dir = 1;

	scanf("%d", &l);
	while (l--) {
		int sec;
		char turn;
		scanf("%d %c", &sec, &turn);
		q.push({ sec,turn });
	}

	pair<int, char> tmp = q.front();
	q.pop();
	while (true) {
		if (cnt == tmp.first) {
			if (tmp.second == 'D') { // 오른쪽
				dir = (dir + 1) % 4;
			}
			else if (tmp.second == 'L') { // 왼쪽
				dir = (dir + 3) % 4;
			}
			board[head.r][head.c] = dir + 1; // 방향 바뀐거 저장
			if (!q.empty()) {
				tmp = q.front();
				q.pop();
			}
			else {
				tmp = { -1,'X' };
			}
		}
		int nr = head.r + rgo[dir];
		int nc = head.c + cgo[dir];
		if (nr<1 || nc<1 || nr>n || nc>n) { // 벽에 부딪힘
			break;
		}
		if (board[nr][nc] > 0) { // 내 몸통이랑 부딪힘
			break;
		}
		cnt++;
		if (board[nr][nc] == -1) { // 사과냠냠
			// 방향 그대로, 머리좌표변경 , 꼬리그대로
			head.r = nr;
			head.c = nc;
		}
		else { // 빈칸 꼬리변경, 
			head.r = nr;
			head.c = nc;
			int t_r = tail.r, t_c = tail.c;
			tail.r += rgo[board[t_r][t_c] - 1];
			tail.c += cgo[board[t_r][t_c] - 1];
			board[t_r][t_c] = 0;
		}
		board[nr][nc] = dir + 1; // 몸통 표시
	}
	printf("%d\n", cnt + 1);

	return 0;
}