#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n,m, arr[10000],sum,left,right,mid,money;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	scanf("%d", &m);
	left = 0;
	right = arr[n - 1];
	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] <= mid) sum += arr[i];
			else sum += mid;
		}
		if (m < sum) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			money = mid;
		}
	}
	printf("%d\n", money);

	return 0;
}