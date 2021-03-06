/*
괄호가 가능한 모든경우를 탐색했다.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

long long n, max_sum = -987654321987654321;
int use[20]; // 여는 괄호 1, 닫는 괄호 2
string st;
void func(int cur) {
	if (cur >= n) {
		long long sum, subsum;
		int tmpidx;
		for (int i = 0; i < n; i += 2) {
			subsum = st[i] - '0';
			tmpidx = i;
			if (use[i] == 1) {
				int idx = i + 2;
				while (true) {
					if (st[idx - 1] == '+') {
						subsum += st[idx] - '0';
					}
					else if (st[idx - 1] == '*') {
						subsum *= st[idx] - '0';
					}
					else if (st[idx - 1] == '-') {
						subsum -= st[idx] - '0';
					}
					if (use[idx] == 2) break;
					idx += 2;
				}
				tmpidx = idx;
			}
			if (i == 0) {
				sum = subsum;
			}
			else {
				if (st[i - 1] == '+') {
					sum += subsum;
				}
				else if (st[i - 1] == '*') {
					sum *= subsum;
				}
				else if (st[i - 1] == '-') {
					sum -= subsum;
				}
			}
			i = tmpidx;
		}
		max_sum = max(max_sum, sum);
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