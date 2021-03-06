/*
괄호가 가능한 모든경우를 체크하고, 스택을 이용하여 식을 우선순위를 고려하여
후위표기식으로 변환 후 계산해줬다.

*/
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

long long n, max_sum = -987654321987654321;
int use[20];
string st;
string pro_st;

void pro() {
	pro_st = "";
	stack<char> sta;
	int len = st.size();
	for (int i = 0; i < len; i++) {
		if (use[i] == 1) {
			sta.push('(');
		}
		if (st[i] >= '0' && st[i] <= '9') {
			pro_st += st[i];
		}
		else {
			if (sta.empty()) sta.push(st[i]);
			else {
				if (st[i] == '*') {
					if (sta.top() == '*') {
						pro_st += '*';
					}
					else {
						sta.push(st[i]);
					}
				}
				else {
					while (!sta.empty()) {
						if (sta.top() == '(') break;
						pro_st += sta.top();
						sta.pop();
					}
					sta.push(st[i]);
				}
			}
		}
		if (use[i] == 2) {
			while (true) {
				pro_st += sta.top();
				sta.pop();
				if (sta.top() == '(') {
					sta.pop();
					break;
				}
			}
		}
	}
	while (!sta.empty()) {
		pro_st += sta.top();
		sta.pop();
	}
}

void func(int cur) {
	if (cur >= n) {
		pro();
		int len = pro_st.size();
		stack<long long> sta;
		for (int i = 0; i < len; i++) {
			if (pro_st[i] >= '0' && pro_st[i] <= '9') {
				sta.push(pro_st[i] - '0');
			}
			else {
				long long a, b;
				b = sta.top(); sta.pop();
				a = sta.top(); sta.pop();
				if (pro_st[i] == '+') {
					sta.push(a + b);
				}
				else if (pro_st[i] == '*') {
					sta.push(a*b);
				}
				else if (pro_st[i] == '-') {
					sta.push(a - b);
				}
			}
		}
		max_sum = max(max_sum, sta.top());
		sta.pop();
	}
	for (int j = 0; j <= 2; j += 2) {
		if (cur + j > n) break;
		if (j == 0) {
			func(cur + 2);
		}
		else {
			use[cur] = 1;
			use[cur + j] = 2;
			func(cur + 2 + j);
			use[cur] = 0;
			use[cur + j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> st;
	func(0);
	cout << max_sum;

	return 0;
}