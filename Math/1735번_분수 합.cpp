#include <cstdio>
using namespace std;

int gcd(int x, int y) {
	int tmp;
	while (y > 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}

int main() {
	int a, b, c, d, tmp, e, f;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	f = b * d;
	e = a * d + c * b;
	tmp = e > f ? gcd(e, f) : gcd(f, e);
	printf("%d %d", e / tmp, f / tmp);

	return 0;
}