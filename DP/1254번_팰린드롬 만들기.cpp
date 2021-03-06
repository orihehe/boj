/*
원래 문자열st의 뒤에 0개이상 문자를 추가하여 팰린드롬을 만드는 데 
가장 길이가 짧게 하려면 st문자열을 두 부분으로 나누어 오른쪽 부분이 가장 긴
팰린드롬일 때를 찾아야 한다. 
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dp[2501][2501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string st;
	int len, pel=0;
	cin >> st;
	len = st.size();
	for (int i = 0; i < len-1; i++) {
		dp[i][i] = true;  // i~i (자신만) 팰린드롬
		if (st[i] == st[i + 1])  // i~i+1 (길이2인 문자열 팰린드롬인지)
			dp[i][i + 1] = true;
	}
	dp[len - 1][len - 1] = true;
	for (int i = 2; i < len; i++) {
		for (int j = 0; j + i < len; j++) {
			if (st[j] == st[j + i] && dp[j + 1][j + i - 1]) {
				dp[j][j + i] = true;
			}
		}
	}
	// 문자열의 오른쪽 부분이 가장 긴 팰린드롬일 때를 찾는다.
	for (int i = 0; i < len; i++) { 
		if (dp[i][len-1]) {
			pel = len-i;
			break;
		}
	}
	printf("%d", len * 2 - pel);

	return 0;
}