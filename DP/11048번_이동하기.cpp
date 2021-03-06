/*
사탕을 먹기위해 움직일 수 있는 방향은 오른쪽, 아래쪽 대각선 오른아래쪽이다.
하지만 이동횟수 제한이 없으므로 오른-아래 / 아래-오른 으로 많이 밟을때 사탕을 
많이 먹을 수 있다. i,j에 i-1,j/i,j-1의 경우중 최댓값을 찾아 +해주어
최종적으로 n,m에는 먹을 수 있는 최대 사탕의 수가 놓이게 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int i, j, n, m, arr[1000][1000];
int main()
{
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 1; i < n; i++) {
		arr[i][0] += arr[i - 1][0];
	}
	for (i = 1; i < m; i++) {
		arr[0][i] += arr[0][i-1];
	}
	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	printf("%d\n", arr[n - 1][m - 1]);

	return 0;
}