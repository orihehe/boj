#include <cstdio>

int n, arr[101], m,a,b,k;
int main(void) {
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &a, &b, &k);
		for (int i = a; i <= b; i++)arr[i]=k;
	}
	for (int i = 1; i <= n; i++) printf("%d ",arr[i]);

	return 0;
}