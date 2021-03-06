/*
visited를 -1로 초기화 하지않고 풀었을 때 경로가 없는 경우에도 dfs함수에 들어가
시간초과가 발생했다.
이미 탐색했지만 경로가 없는 경우가 0이고, 탐색 전은 -1로 하니 통과했다.
현재 위치의 상하좌우에 내리막이 있는 경우
이미 경우의 수가 구해져 있을 땐 그 값을 리턴하고, 없을 때는 계속 dfs 탐색을 한다.
네 방향의 값을 현재 위치에 더한다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[500][500];
int visited[500][500];
int rgo[4] = { 0,0,1,-1 };
int cgo[4] = { 1,-1,0,0 };
int m, n;
int dfs(int r, int c) {
	if (r == m - 1 && c == n - 1) {
		return 1;
	}
	if (visited[r][c] >= 0) {
		return visited[r][c];
	}
	if (visited[r][c] == -1)
		visited[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i];
		int nc = c + cgo[i];
		if (nr < 0 || nc<0 || nr >= m || nc>n) continue;
		if (arr[nr][nc] < arr[r][c]) {
			visited[r][c]+=dfs(nr, nc);
		}
	}
	return visited[r][c];
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(visited, -1, sizeof(visited));
	dfs(0, 0);
	printf("%d", visited[0][0]);

	return 0;
}