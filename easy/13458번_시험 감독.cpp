#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[1000000];
int main()
{
	long long n,b,c,cnt=0,p;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	scanf("%lld %lld", &b, &c);
	for (int i = 0; i < n; i++) {
		p = arr[i];
		cnt += 1;
		p -= b;
		if (p > 0) {
			cnt += p / c;
			if (p%c != 0) cnt++;
		}
	}
	printf("%lld", cnt);

	return 0;
}