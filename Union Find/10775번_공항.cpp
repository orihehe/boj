/*
1~x까지의 게이트중 하나에 도킹 가능하므로 최대한 수가 큰 게이트에 먼저 도킹하는게 좋다.
parent배열에 x가 주어질 때 도킹 가능한 가장 큰 수의 게이트가 저장된다.
*/

#include <cstdio>
#include <algorithm>
#define MAX 100001
using namespace std;

int parent[MAX];
int find_root(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find_root(parent[v]);
}
void merge(int v1, int v2) {
	parent[v1] = v2;
}

int main() {
	int g, p, x, cnt=0;
	bool fail = false;
	scanf("%d %d", &g, &p);
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}
	while (p--) {
		scanf("%d", &x);
		if (!fail) {
			int tmp = find_root(x);
			if (tmp == 0) { // 도킹실패
				fail = true;
			}
			else {
				cnt++;
				merge(tmp, tmp - 1);
			}
		}
	}
	printf("%d", cnt);

	return 0;
}