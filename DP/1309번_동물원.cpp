/*
규칙을 찾으려고 그려봤지만 못찾아서 다른 사람 풀이를 찾아봤다.
dp가 제일 어려운거 같다 ㅠㅠ
현재 줄에 사자을 안 채울 경우는 이전 줄의 모든 경우를 더하고
왼쪽에 사자를 넣으려면 이전 경우에서 왼쪽에 넣는 경우를 제외하고 더한다
오른쪽은 반대로
*/
#include <cstdio>
#define mod 9901
using namespace std;

int n, dp[100001][3];
int main()
{
	scanf("%d", &n);
	dp[1][0] = 1;  // 사자 없을 경우
	dp[1][1] = 1;  // 왼쪽 칸에만 있을 경우
	dp[1][2] = 1;  // 오른쪽 칸에만 있을 경우
	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%mod;
	}
	printf("%d", (dp[n][0] + dp[n][1] + dp[n][2]) % mod);

	return 0;
}