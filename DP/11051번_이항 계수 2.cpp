// 조합의 성질을 알면 쉽게 푼다
#include <cstdio>
#define mod 10007
using namespace std;

int dp[1001][1001];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	if (n - k < k) k = n - k;
	if (k == 0) {
		printf("1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = i;
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%mod;
		}
	}
	printf("%d", dp[n][k]);

	return 0;
}