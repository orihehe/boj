#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, ncnt=0;
	scanf("%d", &n);
	for (int i = 666; i <= 10000666; i++) {
		int cnt6 = 0, tmp=i;
		while (tmp > 0) {
			if (tmp % 10 == 6) {
				cnt6++;
			}
			else {
				cnt6 = 0;
			}
			if (cnt6 == 3) {
				ncnt++;
			}
			tmp /= 10;
		}
		if (ncnt == n) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}