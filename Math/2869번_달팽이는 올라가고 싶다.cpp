#include <cstdio>
using namespace std;

int main()
{
	int a, b, v, cha, cnt=1;
	scanf("%d %d %d", &a, &b, &v);
	v -= a;
	cha = a - b;
	if (v%cha > 0) cnt++;
	printf("%d\n", v/cha+cnt);

	return 0;
}