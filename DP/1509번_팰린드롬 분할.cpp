/*
j=0~i, j~i의 문자열이 팰린드롬일때 
0~j-1까지의 팰린드롬 분할의 최솟값 + 1 과 0~i까지의 최소를 비교하여 작은값을 넣는다.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[2500][2500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int len, divi[2500];
	string st;
	cin >> st;
	len = st.size();
	for (int i = 0; i < len - 1; i++) {
		dp[i][i] = 1;  // 길이 1일때 
		if (st[i] == st[i + 1]) dp[i][i + 1] = 1;  // 길이 2일때
	}
	dp[len - 1][len - 1] = 1;
	for (int i = 2; i <= len - 1; i++) {
		for (int j = 0; j + i <= len - 1; j++) {
			if (st[j] == st[j + i] && dp[j + 1][j + i - 1] == 1) {
				dp[j][j + i] = 1;
			}
		}
	}

	divi[0] = 1;
	if (dp[0][1] == 1)divi[1] = 1;
	else divi[1] = 2;
	for (int i = 2; i < len; i++) {
		divi[i] = len;
		for (int j = i; j >= 0; j--) {
			if (dp[j][i] != 0) {	 // 팰린드롬이면
				if (j == 0) divi[i] = min(divi[0], divi[i]);
				else divi[i] = min(divi[j - 1] + 1, divi[i]);
			}
		}
	}
	cout << divi[len - 1] << "\n";


	return 0;
}