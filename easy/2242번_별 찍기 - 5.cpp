#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < n + i; j++) {
			if (j < n - i-1)printf(" ");
			else printf("*");
		}
		printf("\n");
	}

	return 0;
}