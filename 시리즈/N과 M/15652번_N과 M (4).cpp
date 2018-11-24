#include <cstdio>
#include <algorithm>
using namespace std;

int num[9];
int n, m;
void func(int cur, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (int i = cur; i <= n; i++) {
		num[cnt] = i;
		func(i, cnt+1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	func(1, 0);

	return 0;
}