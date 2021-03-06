/*
백준 블로그 https://www.acmicpc.net/blog/view/28 참고
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;

void calc(ll (*mat)[2], ll mul[][2]) {
	ll tmp[2][2] = { {0,0} ,{0,0} };
	for (int i = 0; i < 2;i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += mat[i][k] * mul[k][j];
			}
			tmp[i][j] %= mod;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) mat[i][j] = tmp[i][j];
	}
}

int main() {
	ll n, ans[2][2] = { { 1,0 },{ 0, 1 } };
	ll m[2][2]= { { 1,1 },{ 1,0 } };
	scanf("%lld", &n);
	if (n <= 1) {
		printf("%lld", n);
		return 0;
	}
	n;
	while (n > 0) {
		if (n % 2 == 1) {
			calc(ans, m);
		}
		calc(m, m);
		n /= 2;
	}
	printf("%lld", ans[1][0]);

	return 0;
}