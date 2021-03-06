#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
#define P pair<int,int>
using namespace std;

int main() {
	priority_queue<P, vector<P>, greater<P>> q;
	int l, n, x;
	scanf("%d %d", &n, &l);

	pair<int, int> tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		q.push({ x,i });
		while (!q.empty()) {
			tmp = q.top();
			if (tmp.second >= i - l + 1 && tmp.second <= i) {
				printf("%d ", tmp.first);
				break;
			}
			else {
				q.pop();
			}
		}
	}

	return 0;
}