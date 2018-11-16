#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = -n+1; i < n; i++) {
		int tmp = n - abs(i);
		for (int j = -n+1; j < n; j++) {
			if (j < 0 && j >= -n + tmp) printf("*");
			else if (j > 0 && j <= n - tmp) printf("*");
			else if (j == 0)printf("*");
			else if (j > 0 && j > n - tmp) break;
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}