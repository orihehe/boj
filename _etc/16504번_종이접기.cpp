// 다 접으면 결국 모든 수를 더한 값이 나온다.
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	long long n, sum = 0, x;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &x);
			sum += x;
		}
	}
	printf("%lld", sum);

	return 0;
}