#include <cstdio>
#include <algorithm>
using namespace std;

bool wrong[100001];
int main() {
	int n, k, b, x, minS, ddd = 0;
	scanf("%d %d %d", &n, &k, &b);
	for (int i = 1; i <= b; i++) {
		scanf("%d", &x);
		wrong[x] = true; //망가진신호등
	}
	for (int i = 1; i <= k; i++) {
		if (wrong[i]) {
			ddd++;
		}
	}
	minS = ddd;
	for (int i = 2; i <= n - k + 1; i++) {
		if (wrong[i - 1]) {
			ddd--;
		}
		if (wrong[i + k - 1]) {
			ddd++;
		}
		if (ddd < minS) minS = ddd;
	}
	printf("%d", minS);

	return 0;
}