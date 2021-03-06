/*
문자열 2개의 LCS를 구하는 문제 (https://www.acmicpc.net/problem/9251) 에서
문자열 3개로 늘어나 3차원 배열로 하면 되는 문제다.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[101][101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b, c;
	int alen, blen, clen;
	cin >> a >> b >> c;
	alen = a.size();
	blen = b.size();
	clen = c.size();
	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			for (int k = 1; k <= clen; k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max({ dp[i - 1][j][k],dp[i][j - 1][k],
						dp[i][j][k - 1] });
				}
			}
		}
	}
	
	cout << dp[alen][blen][clen];

	return 0;
}