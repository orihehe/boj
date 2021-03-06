#include <cstdio>
using namespace std;

int t, m, n, k, arr[50][50], x, y, cnt;
void dfs(int i,int j) {
	if (i > 0 && arr[i - 1][j] == 1) {
		arr[i - 1][j]++;
		dfs(i - 1, j);
	}
	if (i < m-1  && arr[i + 1][j] == 1) {
		arr[i + 1][j]++;
		dfs(i + 1, j);
	}
	if (j > 0 && arr[i][j - 1] == 1) {
		arr[i][j - 1]++;
		dfs(i, j - 1);
	}
	if (j < n - 1 && arr[i][j + 1] == 1) {
		arr[i][j + 1]++;
		dfs(i, j + 1);
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &m, &n, &k);
		cnt = 0;
		while (k--) {
			scanf("%d %d",&x,&y);
			arr[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					arr[i][j]++;
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}