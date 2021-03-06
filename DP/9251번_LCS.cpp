/*
dp[i][j]는 a문자열 0~(i-1) 까지와 b문자열 0~(j-1)까지의 최장 공통 부분 수열이다
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int alen = a.size(), blen = b.size();
	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			dp[i][j] = max({ dp[i][j - 1],dp[i - 1][j],
				dp[i - 1][j - 1] + (a[i-1] == b[j-1]) });
		}
	}
	cout << dp[alen][blen];

	return 0;
}