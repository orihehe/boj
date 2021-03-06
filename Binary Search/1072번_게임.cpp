/*
처음에 형변환을 모두 해주었는데 일부 수에서 제대로 계산이 되지 않았다.
뭐가 문제인지 잘 모르겠다..
형변환을 다 없앤 후엔 제대로 되지 않아 찾아보니
계산을 y/x*100 으로 하지 않고, y*100/x로 해야 됐다.
*/
#include <cstdio>
using namespace std;

int main()
{
	long long x, y, left,right,mid,pers,z=0;
	scanf("%lld %lld", &x, &y);
	pers = y*100 / x ; // 승률
	if (pers >= 99) {
		printf("-1");
		return 0;
	}
	left = 0;
	right = 11000000000;
	while (left <= right) {
		mid = (left + right) / 2;
		if ((y + mid)*100 / (x + mid) > pers) {
			right = mid - 1;
			z = mid;
		}
		else left = mid + 1;
	}
	printf("%lld\n", z);

	return 0;
}