/*
유클리드 호제법에 대해 처음 알았다.
a>b일때
a%b==0일때 b가 최대공약수, a%b!=0일때 gcd(b,a%b) 성립
최소공배수는 a*b/gcd(a,b)
*/
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
	int t,a,b,tmp;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		if (b > a) {
			tmp = b;
			b = a;
			a = tmp;
		}

		printf("%d\n", a*b/gcd(a,b));
	}

	return 0;
}