#include <cstdio>
#include <algorithm>
#define P pair<int,int>
using namespace std;

int main() {
	int n, clock = 0, idx = 0;
	P cow[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &cow[i].first, &cow[i].second);
	}
	sort(cow, cow + n);
	while (idx < n) {
		if (cow[idx].first <= clock) {
			clock += cow[idx].second;
			idx++;
		}
		else {
			clock = cow[idx].first;
		}
	}

	printf("%d", clock);

	return 0;
}