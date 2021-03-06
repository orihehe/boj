#include <cstdio>
#include <algorithm>
using namespace std;

int num[9];
int selc[9];
bool use[9];
int n, m;
void func(int cur, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", selc[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!use[i]) {
			use[i] = true;
			selc[cnt] = num[i];
			func(i+1, cnt+1);
			use[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	func(0, 0);

	return 0;
}