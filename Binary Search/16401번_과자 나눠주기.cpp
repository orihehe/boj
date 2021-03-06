// 나무 자르기 문제와 유사
#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, x, arr[1000001], i, l, r, mid, sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	l = 0; r = arr[n - 1];
	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid != 0 && arr[i] / mid > 0)sum += arr[i] / mid;
		}
		if (sum < m) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
			x = mid;
		}
	}
	cout << x;

	return 0;
}