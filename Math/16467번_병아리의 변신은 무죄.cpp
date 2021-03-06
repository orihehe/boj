/*
백준 11444번 피보나치 수6 - https://www.acmicpc.net/problem/11444
위의 문제 푸는방식의 응용이다.
처음 문제를 풀 때 dp로 풀었다. O(N)으로 시간초과
현재 병아리의 수는 어제의 병아리 수 + k+1일 전 병아리 수이다.
왜냐하면 k+1일 전 병아리들이 낳은 알 들이 k일 후 부화하기 때문!
점화식 N(x) = N(x-1) + N(x-k-1) 

피보나치 수의 점화식은 N(x) = N(x-1) + N(x-2)
f(n+1) = f(n)+f(n-1)
f(n) = f(n-1)+f(n-2)
행렬로 나타내면 
|f(n+1)| = |1 1|| f(n) |
| f(n) |   |1 0||f(n-1)| 
f(n), f(n-1) 를 차례로 구하다 보면 이러한 식이 나온다.
|f(n+1)| = |1 1|^n |f(1)|
| f(n) |   |1 0|   |f(0)|
..뭐라고 써있는지 읽기는 힘들지만 나중에 보면 알아볼 수 있겠지..? 
아무튼 저런 식으로 이 문제도 풀면 된다.
저런 비슷한 점화식이 나오는 문제는 n이 크면 다 이런 방법으로 풀 수 있을 거 같다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define vv vector<vector<long long>>
#define mod 100000007
#define ll long long
using namespace std;

// 행렬 곱하기 연산
vv calc(int size, const vv& mat, const vv& mul) {
	vv tmp(size + 1);
	ll tt;
	for (int i = 0; i <= size;i++) {
		for (int j = 0; j <= size; j++) {
			tt = 0;
			for (int k = 0; k <= size; k++) {
				tt += mat[i][k] * mul[k][j];
			}
			tmp[i].push_back(tt %= mod);
		}
	}
	return tmp;
}

int main() {
	int t, k;
	ll n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %lld", &k, &n);
		if (n == 0) {
			printf("1\n");
			continue;
		}
		vv ans, m;
		ans.resize(k + 1);
		m.resize(k + 1);
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				if (i == j)
					ans[i].push_back(1);
				else ans[i].push_back(0);
			}
		}
		for (int i = 0; i <= k; i++) m[0].push_back(0);
		if (k == 0) m[0][0] = 2;
		else {
			m[0][0] = 1; m[0][k] = 1;
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				if (i-1 == j)
					m[i].push_back(1);
				else m[i].push_back(0);
			}
		}
		while (n > 0) {
			if (n % 2 == 1) {
				ans = calc(k, ans, m);
			}
			m = calc(k, m, m);
			n /= 2;
		}
		printf("%lld\n", ans[0][0]);
	}

	return 0;
}