// 유클리드 호제법
#include <cstdio>
using namespace std;

long long gcd(long long x, long long y) {
	long long tmp;
	while (y > 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}

int main()
{
	long long a, b, t, sum, tmp, n, arr[100];
	scanf("%lld", &t);
	while (t--) {
		sum = 0;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", sum);
	}

	return 0;
}