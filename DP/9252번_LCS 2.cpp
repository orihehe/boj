#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b, same="";
	int alen, blen, slen=0;
	cin >> a >> b;
	alen = a.size();
	blen = b.size();
	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			dp[i][j] = max({ dp[i - 1][j],dp[i][j - 1]
				,dp[i - 1][j - 1] + (a[i-1] == b[j-1]) });
		}
	}
	int aidx=alen, bidx=blen;
	while (dp[aidx][bidx]!=0) {
		if (a[aidx-1] == b[bidx-1]) {
			same += a[aidx-1];
			slen++; 
			aidx--;
			bidx--;
		}
		else {
			if (dp[aidx][bidx]==dp[aidx-1][bidx-1]) {
				aidx--;
				bidx--;
			}
			else if (dp[aidx][bidx] == dp[aidx - 1][bidx]) {
				aidx--;
			}
			else if (dp[aidx][bidx] == dp[aidx][bidx - 1]) {
				bidx--;
			}
		}
	}
	reverse(same.begin(), same.end());
	cout << dp[alen][blen] << "\n" << same;

	return 0;
}