#include <cstdio>
using namespace std;

int main()
{
	long long n, arr[91];
	scanf("%lld", &n);
	arr[0] = 0; arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%lld\n", arr[n]);

	return 0;
}