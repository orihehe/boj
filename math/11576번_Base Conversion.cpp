#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

void toB(int origin, int b) {
	if (origin == 0)return;
	toB(origin / b, b);
	printf("%d ", origin%b);
}

int main()
{
	int a, b, to10=0,m,x,tmp;  // to10은 a진법을 10진법으로 
	scanf("%d %d %d", &a, &b, &m);
	tmp = pow(a, m-1);
	while (m--) {
		scanf("%d", &x);
		to10 += x * tmp;
		tmp /= a;
	}
	toB(to10, b);

	return 0;
}