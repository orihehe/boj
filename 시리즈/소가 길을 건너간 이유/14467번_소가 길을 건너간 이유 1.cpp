#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, num, loc, cnt = 0;
	int cow[11];
	fill(cow, cow + 11, -1);
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &num, &loc);
		if (cow[num] == -1) {
			cow[num] = loc;
		}
		else {
			if (cow[num] != loc) {
				cnt++;
				cow[num] = loc;
			}
		}
	}
	printf("%d", cnt);

	return 0;
}