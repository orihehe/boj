#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

pair<int, int> p[8];
pair<int, int> tmp[8];
bool num[8];
int n, m;
void func(int cnt) {
	if (cnt == m) {
		memcpy(tmp, p, sizeof(p));
		sort(tmp, tmp + m);
		for (int i = 0; i < m; i++) {
			printf("%d ", tmp[i].second);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		if (!num[i]) {
			num[i] = true;
			p[cnt] = { cnt,i + 1 };
			func(cnt + 1);
			num[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	func(0);

	return 0;
}