#include <cstdio>
#define MAX 1000
using namespace std;


int n, arr[2001], x;
int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		arr[x + MAX]++;
	}
	for (int i = 0; i < 2001; i++) {
		if (arr[i] != 0) printf("%d ", i - MAX);
	}

	return 0;
}