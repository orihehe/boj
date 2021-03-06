#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 1:동, 2:서, 3:북, 4:남
int rgo[5] = { 0,0,0,-1,1 };
int cgo[5] = { 0,1,-1,0,0 };
		// 현재, 오, 왼, 아, 위, 반대
int cube[6] = { 0,0,0,0,0,0 };
int tmp[6];
int map[20][20];
int main() {
	int n, m, x, y, k, dir;
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (k--) {
		scanf("%d", &dir);
		int nr = x + rgo[dir];
		int nc = y + cgo[dir];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m)
			continue;
		memset(tmp, -1, sizeof(tmp));
		if (dir == 1) {
			tmp[0] = cube[2];
			tmp[1] = cube[0];
			tmp[2] = cube[5];
			tmp[3] = cube[3];
			tmp[4] = cube[4];
			tmp[5] = cube[1];
			memcpy(cube, tmp, sizeof(tmp));
		}
		else if (dir == 2) {
			tmp[0] = cube[1];
			tmp[1] = cube[5];
			tmp[2] = cube[0];
			tmp[3] = cube[3];
			tmp[4] = cube[4];
			tmp[5] = cube[2];
			memcpy(cube, tmp, sizeof(tmp));
		}
		else if (dir == 3) {
			tmp[0] = cube[4];
			tmp[1] = cube[1];
			tmp[2] = cube[2];
			tmp[3] = cube[0];
			tmp[4] = cube[5];
			tmp[5] = cube[3];
			memcpy(cube, tmp, sizeof(tmp));
		}
		else if (dir == 4) {
			tmp[0] = cube[3];
			tmp[1] = cube[1];
			tmp[2] = cube[2];
			tmp[3] = cube[5];
			tmp[4] = cube[0];
			tmp[5] = cube[4];
			memcpy(cube, tmp, sizeof(tmp));
		}
		if (map[nr][nc] == 0) {
			map[nr][nc] = cube[5];
		}
		else {
			cube[5] = map[nr][nc];
			map[nr][nc] = 0;
		}
		y = nc; x = nr;
		printf("%d\n", cube[0]);
	}

	return 0;
}