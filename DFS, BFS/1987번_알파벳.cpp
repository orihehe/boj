/*
처음엔 visited 배열도 만들었는데 생각해보니 이전에 왔던 곳은 이미 나온 알파벳에
체크가 되니 없어도 된다.
alpha배열을 false로 되돌려주면 모든 경우를 탐색할 수 있다. (백트레킹)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

char board[20][21];
bool alpha[26];
int cgo[4] = { 0,0,1,-1 };
int rgo[4] = { 1,-1,0,0 };
int maxlen,R,C;

void dfs(int r, int c, int dist) {
	alpha[board[r][c]-'A'] = true;
	for (int i = 0; i < 4; i++) {
		int rd = r + rgo[i];
		int cd = c + cgo[i];
		if (rd >= R || rd < 0 || cd >= C || cd < 0) 
			continue;
		if (!alpha[board[rd][cd] - 'A']) {
			dfs(rd, cd, dist + 1);
		}
	}
	if (maxlen < dist) maxlen = dist;
	alpha[board[r][c]-'A'] = false;
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", board[i]);
	}
	dfs(0, 0, 1);
	printf("%d", maxlen);

	return 0;
}