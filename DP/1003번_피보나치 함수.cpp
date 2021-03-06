// N(x) = N(x-1)+N(x-2)

#include <cstdio>
using namespace std;

int main()
{
	int n, arr[2][41], t,x;
	arr[0][0] = 1; arr[1][0] = 0;
	arr[0][1] = 0; arr[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		arr[0][i] = arr[0][i - 1] + arr[0][i - 2];
		arr[1][i] = arr[1][i - 1] + arr[1][i - 2];
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		printf("%d %d\n", arr[0][x], arr[1][x]);
	}

	return 0;
}