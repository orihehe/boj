// 동전1 문제 + 소수구하기 문제
#include <cstdio>
#include <algorithm>
#define mod 123456789
using namespace std;

int n, i, j, dp[40010];
int sosu[40010];  // 0이면 소수
int main()
{
	scanf("%d", &n);

	sosu[0] = 1;
	for (int i = 2; i <= n / 2 + 1; i++) {
		if (sosu[i]) continue;
		for (int j = 2; j*i <= n; j++) {
			if (sosu[j*i] == 0)
				sosu[j*i] = 1;
		}
	}

	for (i = 2; i <= n; i += 2) dp[i]++; // 소수는 2부터
	for (i = 3; i <= n; i++) {
		if (sosu[i] == 1) continue;
		for (j = i; j <= n; j++) {
			if (j == i) dp[i] = (dp[i] + 1) % mod;
			dp[j] = (dp[j] + dp[j - i])%mod;
		}
	}
	printf("%d", dp[n]);

	return 0;
}