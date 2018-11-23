#include <cstdio>
#include <algorithm>
using namespace std;

int num[9];
int n, m;
void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		num[cnt] = i;
		func(cnt + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	func(0);

	return 0;
}