#include <cstdio>

int main()
{
	int n, x, min = 1000001, max = -1000001;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (min > x) min = x;
		if (max < x) max = x;
	}
	printf("%d %d\n", min, max);

	return 0;
}