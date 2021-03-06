#include <cstdio>
#include <algorithm>
using namespace std;
bool check[21];
int n, s, arr[21], tmp[21];
long long k;
int main() {
	long long fac=1;
	scanf("%d %d", &n, &s);
	for (long long i = 2; i < n; i++) {
		fac *= i;
	}
	if (s == 1) {
		scanf("%lld", &k);
		k--;
		for (int i = n; i >= 1; i--) {
			long long nst = i-1;
			for (int j = n; j >=1; j--) {
				if (!check[j]) {
					if (k - fac * nst >= 0) {
						check[j] = true;
						tmp[i] = j;
						k -= fac * nst;
						if (i - 1 == 0) break;
						fac /= (i - 1);
						break;
					}
					nst--;
				}
			}
		}
		for (int i = n; i >= 1; i--) {
			printf("%d ", tmp[i]);
		}
	}
	else if (s == 2) {
		long long tmp1 = 0;
		for (int i = n; i >=1; i--) {
			long long nst = 1;
			scanf("%d", &arr[i]);
			for (int j = 1; j < arr[i]; j++) {
				if (check[j]) {
					nst++;
				}
			}
			check[arr[i]] = true;
			tmp1 += (arr[i] - nst) * fac;
			if (i - 1 == 0) break;
			fac /= (i - 1);
		}
		printf("%lld", tmp1+1);
	}

	return 0;
}