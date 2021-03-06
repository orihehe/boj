/*
처음에 이중포문 부분을 1~2,1~3,1~4,1~5 로 팰린드롬을 찾게 짰는데 그렇게 되면
만약 1~4의 경우 2~3이 먼저 팰린드롬인지 체크가 되어있어야 하는데 체크전이었다.
그래서 1~3 2~4 3~5 로 i를 길이로 두어 dp[j][j+1]를 팰린드롬 체크하였다.
만약 양끝 두 수가 같다면 중앙이 팰린드롬일때 그 수도 팰린드롬이 된다.
*/
#include <cstdio>
using namespace std;

int dp[2001][2001];
int main()
{
	int n,m,arr[2001],x,y;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m); 
	for (int i = 1; i < n; i++) {
		dp[i][i] = 1;  // 길이 1일때 
		if (arr[i] == arr[i + 1])dp[i][i + 1] = 1; // 길이 2일때
	}
	dp[n][n] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j+i <= n; j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1] == 1) {
				dp[j][j + i] = 1;
			}
		}
	}
	while (m--) {
		scanf("%d %d", &x, &y);
		printf("%d\n", dp[x][y]);
	}

	return 0;
}