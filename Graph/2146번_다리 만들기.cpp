#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100][100];
int gox[4] = { 0,0,-1,1 };
int goy[4] = { -1,1,0,0 };
int n, i, j, color = 2;
pair<int, int> bridge[10000];
int bidx = 0;
void dfs(int x, int y) {
	//주변 한면이라도 바다가 있으면 bridge에 넣음
	if ((x > 0 && arr[x - 1][y] == 0) || (x<n - 1 && arr[x + 1][y] == 0) ||
		(y>0 && arr[x][y - 1] == 0) || (y<n - 1 && arr[x][y + 1] == 0)) {
		bridge[bidx++] = make_pair(x, y);
	}
	arr[x][y] = color;
	int nx, ny;
	for (int k = 0; k < 4; k++) {
		nx = x + gox[k];
		ny = y + goy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (arr[nx][ny] == 1) dfs(nx, ny);
	}
}

int main()
{
	int distance = 999;
	pair<int, int> tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] == 1) { // 구별 전
				dfs(i, j);
				color++; // 섬을 수로 구별
			}
		}
	}
	for (i = 0; i < bidx; i++) {
		tmp = bridge[i];
		for (j = 0; j < bidx; j++) {
			// 같은 섬이라면 지나가기
			if (arr[bridge[j].first][bridge[j].second] == arr[tmp.first][tmp.second]) continue;
			int dis = abs(bridge[j].first - tmp.first) + abs(bridge[j].second - tmp.second);
			if (dis < distance)distance = dis;
		}
	}
	printf("%d\n", distance - 1);

	return 0;
}