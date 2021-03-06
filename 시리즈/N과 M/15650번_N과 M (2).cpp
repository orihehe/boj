#include <cstdio>
#include <algorithm>
using namespace std;

bool num[9];
int n, m;
void func(int cur, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (num[i]) printf("%d ", i);
		}
		printf("\n");
	}
	for (int i = cur; i <= n; i++) {
		if (!num[i]) {
			num[i] = true;
			func(i, cnt + 1);
			num[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	func(1, 0);

	return 0;
}