#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alpha[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string st, pel="";
	int len, i;
	int cnt = 0;
	cin >> st;
	len = st.size();
	for (i = 0; i < len; i++) {
		alpha[st[i] - 'A']++;
	}
	char mid='-';
	for (i = 0; i < 26; i++) {
		if (alpha[i] != 0 && alpha[i] % 2 == 1) {
			cnt++;
			mid = i + 'A';
			alpha[i]--;
			if (cnt > 1) break;
		}
	}
	// 이름 길이 짝수면 홀수 있다면 개수가 2개이상
	// 이름 길이 홀수면 홀수 개수 1개만 허용
	if (cnt > 1) {  
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	string tmp = "";
	for (int i = 0; i < 26; i++) {
		while (alpha[i] > 0) {
			pel += i + 'A';
			alpha[i] -= 2;
		}
	}
	tmp = pel;
	reverse(tmp.begin(), tmp.end());
	if (mid != '-') pel += mid;
	cout << pel << tmp;

	return 0;
}