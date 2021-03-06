#include <cstdio>
using namespace std;

int n, arr[100][100], x, visited[100][100] = { -1 };
void dfs(int i, int j, int k) {
	if (i > 0 && arr[i - 1][j] > k && visited[i-1][j]!=k) {
		visited[i - 1][j] = k;
		dfs(i - 1, j, k);
	}
	if (i < n - 1 && arr[i + 1][j] > k&& visited[i + 1][j] != k) {
		visited[i + 1][j] = k;
		dfs(i + 1, j, k);
	}
	if (j > 0 && arr[i][j - 1] > k && visited[i][j - 1] != k) {
		visited[i][j - 1] = k;
		dfs(i, j - 1, k);
	}
	if (j < n - 1 && arr[i][j + 1] > k && visited[i][j + 1] != k) {
		visited[i][j + 1] = k;
		dfs(i, j + 1, k);
	}
}

int main()
{
	int cnt, max = 0, maxh=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			arr[i][j] = x;
			if (x > maxh)maxh = x;
		}
	}
	for (int k = 0; k <= maxh; k++) { // 높이별로 dfs
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] != k && arr[i][j] > k) {
					visited[i][j] = k;
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		if (max < cnt) max = cnt;
	}
	printf("%d\n", max);

	return 0;
}