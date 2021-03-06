//유클리드 호제법
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

int main()
{
	int a,b,c,tmp;
	scanf("%d %d", &a, &b);
	if (b > a) {
		tmp = b;
		b = a;
		a = tmp;
	}
	c = gcd(a, b);
	printf("%d\n", c);
	printf("%d\n", a*b / c);

	return 0;
}