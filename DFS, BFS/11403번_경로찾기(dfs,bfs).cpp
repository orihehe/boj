#include <cstdio>
#include <cstring>
using namespace std;

int visited[100], arr[100][100], n, arrive[100][100], i;
void dfs(int start) {
	for(int j = 0; j < n; j++) {
		if (arr[start][j] && !visited[j]) {
			visited[j] = 1;
			dfs(j);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < n; i++) {
		dfs(i);
		for (int k = 0; k < n; k++) {
			visited[k] ? printf("1 ") : printf("0 ");
		}
		printf("\n");
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}