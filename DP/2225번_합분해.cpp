#include <cstdio>
#define mod 1000000000
using namespace std;

int len, dp[201][201];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= 200; i++) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	printf("%d\n", dp[n][k-1]);

	return 0;
}