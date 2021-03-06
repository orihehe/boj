/*
처음에 동전가치 첫번째로 동전 개수 배열 초기화한다
i는 동전가치 k는 구하려는 값
j=i~k까지 해서 이 동전을 썼을 때 j-동전 + 1 , 안 썼을 때 최솟값을 구한다.
*/
#include <cstdio>
#include <algorithm>
#define INF 10001
using namespace std;

int n, k, coin[101], i, j, dp[100001];
int main()
{
	scanf("%d %d", &n, &k);
	fill_n(dp, k + 1, INF);
	for (i = 0; i < n; i++) scanf("%d", &coin[i]);
	for (i = coin[0]; i <= k; i += coin[0]) dp[i] = i / coin[0];
	for (i = 1; i < n; i++) {
		for (j = coin[i]; j <= k; j++) {
			if (j == coin[i]) dp[j] = 1; // coin[i] 한개로 가능
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
		}
	}
	if (dp[k] == INF)printf("-1");
	else printf("%d", dp[k]);

	return 0;
}