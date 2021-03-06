/*
주어진 동전들의 가치를 coin배열에 저장한다. 
i=동전가치, N(j)는 N(j-i)의 경우의수에 i를 더한것과 같으므로
N(j) +=N(j-i) 이고, 한 동전을 처음 쓸 경우 N(i)++을 해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, coin[101],i,j,dp[100001];
int main()
{
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &coin[i]);
	for (i = coin[0]; i <= k; i += coin[0]) dp[i]++;
	for (i = 1; i < n; i++) {
		for (j = coin[i]; j <= k; j++) {
			if(j==coin[i]) dp[j]++;
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[k]);

	return 0;
}