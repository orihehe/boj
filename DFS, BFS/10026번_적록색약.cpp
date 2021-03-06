#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int rgo[4] = { 0,0,-1,1 };
int cgo[4] = { 1,-1,0,0 };
int n;
char cur_color;
bool visited[100][100];
bool sick;
char pic[101][101];
void dfs(int r, int c) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i];
		int nc = c + cgo[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		if (!sick) {
			if (!visited[nr][nc] && pic[nr][nc] == cur_color) {
				dfs(nr, nc);
			}
		}
		else {
			if (!visited[nr][nc]) {
				if (cur_color == 'B') {
					if(pic[nr][nc] == 'B')
						dfs(nr, nc);
				}
				else {
					if (pic[nr][nc] != 'B')
						dfs(nr, nc);
				}
			}
		}
	}
}

int main()
{
	int non=0, ill=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", pic[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				non++;
				cur_color = pic[i][j];
				dfs(i, j);
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	sick = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				ill++;
				cur_color = pic[i][j];
				dfs(i, j);
			}
		}
	}
	printf("%d %d", non, ill);

	return 0;
}