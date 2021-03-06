/*
땅은 가로, 세로, 대각선으로 연결되어있다.
dfs로 연결된 섬 체크하여 섬 개수를 세었다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int arr[50][50],check[50][50],w, h;
void dfs(int i,int j) {
	if (i < h-1 && j<w-1 && arr[i+1][j+1] && !check[i+1][j+1]) {
		check[i + 1][j + 1] = 1;
		dfs(i + 1, j + 1);
	}
	if (i < h - 1 && arr[i + 1][j] && !check[i + 1][j]) {
		check[i + 1][j] = 1;
		dfs(i + 1, j);
	}
	if (j < w - 1 && arr[i][j + 1] && !check[i][j + 1]) {
		check[i][j + 1] = 1;
		dfs(i, j + 1);
	}
	if (i > 0 && arr[i - 1][j] && !check[i - 1][j]) {
		check[i - 1][j] = 1;
		dfs(i - 1, j);
	}
	if (j > 0 && arr[i][j - 1] && !check[i][j - 1]) {
		check[i][j - 1] = 1;
		dfs(i, j - 1);
	}
	if (i > 0 && j<w - 1 && arr[i - 1][j + 1] && !check[i - 1][j + 1]) {
		check[i - 1][j + 1] = 1;
		dfs(i - 1, j + 1);
	}
	if (i < h - 1 && j > 0 && arr[i + 1][j - 1] && !check[i + 1][j - 1]) {
		check[i + 1][j - 1] = 1;
		dfs(i + 1, j - 1);
	}
	if (i > 0 && j > 0 && arr[i - 1][j - 1] && !check[i - 1][j - 1]) {
		check[i - 1][j - 1] = 1;
		dfs(i - 1, j - 1);
	}
}

int main()
{
	int  cnt;
	scanf("%d %d", &w,&h);
	while (w!=0 || h!=0) {
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &arr[i][j]);
				check[i][j] = 0;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!check[i][j] && arr[i][j] == 1) {
					cnt++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n", cnt);
		scanf("%d %d", &w, &h);
	}

	return 0;
}