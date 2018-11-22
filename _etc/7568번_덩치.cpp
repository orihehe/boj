#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	pair<int, int> p[50];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
	}
	for (int i = 0; i < n; i++) {
		pair<int, int> tmp = p[i];
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (tmp.first < p[j].first && tmp.second < p[j].second) {
				cnt++;
			}
		}
		printf("%d ", cnt);
	}

	return 0;
}