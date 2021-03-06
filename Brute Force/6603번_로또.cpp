#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;
bool sel[13];
int n;
void lotto(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < n; i++) {
			if(sel[i])
				printf("%d ", vec[i]);
		}
		printf("\n");
		return;
	}
	sel[idx] = true;
	lotto(idx + 1, cnt + 1);
	if (n - idx > 6 - cnt) { // 남은게 선택해야할 거보다 많으면
		sel[idx] = false;
		lotto(idx + 1, cnt);
	}
	sel[idx] = false;
}

int main()
{
	while (scanf("%d", &n)) {
		if (n == 0) break;
		vec.clear();
		vec.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &vec[i]);
		lotto(0, 0);
		printf("\n"); 
	}

	return 0;
}