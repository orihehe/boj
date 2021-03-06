#include <cstdio>
#include <algorithm>
using namespace std;

int arr[200001];
int main()
{
	int n, t, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
	}
	while (m--) {
		scanf("%d", &t);
		int left, right, mid, can = 0;
		left = 1;
		right = n;
		while (left <= right) {
			mid = (left + right) / 2;
			if (t >= arr[mid]) {
				left = mid + 1;
				can = mid;
			}
			else {
				right = mid - 1;
			}
		}
		printf("%d\n", can);
	}

	return 0;
}