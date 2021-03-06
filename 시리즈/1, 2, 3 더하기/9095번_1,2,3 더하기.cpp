// N(x) = N(x-1) + N(x-2) + N(x-3)

#include <cstdio>
using namespace std;

int main()
{
	int arr[11], t, x;
	arr[1] = 1; arr[2] = 2; arr[3] = 4;
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		printf("%d\n", arr[x]);
	}

	return 0;
}