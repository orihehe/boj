/*
0이 나올 경우 앞에 1이나 2가 있어야만 해석 가능하다. 10, 20
11~26은 한 자리수 2개 또는 두 자리수 1개로 해석 가능하다.
1~9는 한 자리 수로 해석 가능하다.
따라서 1~9를 dp[i]=dp[i-1]로 하고
10~26 을 dp[i]=dp[i]+dp[i-2]로 하면 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int len, dp[5002];
int main()
{
	char st[5001];
	dp[0] = 1; dp[1]=1;
	scanf("%s", st);
	len = strlen(st);
	if (st[0] == '0') {
		printf("0\n");
		return 0;
	}

	for (int i = 1; i < len; i++) {
		if (st[i] != '0') {
			dp[i+1] = dp[i] % 1000000;
		}
		else {
			if (st[i - 1] != '1' && st[i - 1] != '2') {
				dp[len] = 0; break;
			}
		}
		int x = st[i] - '0' + (st[i - 1] - '0') * 10;
		if (x >= 10 && x <= 26) {
			dp[i+1] = (dp[i - 1] + dp[i+1]) % 1000000;
		}
	}

	printf("%d\n", dp[len]);

	return 0;
}