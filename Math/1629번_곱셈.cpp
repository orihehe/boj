/*
a^4 = a^2 * a^2
a^5 = a^2 * a^2 * a
*/
#include <cstdio>
using namespace std;

int main() {
	long long a, b, c, ans;
	scanf("%lld %lld %lld", &a, &b, &c);
	ans = 1;

	while (b > 0) {
		if (b % 2 == 1) {
			ans = (ans*a) % c;
		}
		a = (a*a) % c;
		b /= 2;
	}
	printf("%lld", ans);

	return 0;
}